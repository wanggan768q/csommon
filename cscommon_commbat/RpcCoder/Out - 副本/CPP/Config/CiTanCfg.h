#ifndef __CITAN_CONFIG_H
#define __CITAN_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//帮会刺探表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct CiTanElement
{
	friend class CiTanTable;
	int ID;                      	//玩家等级	玩家等级
	int Reward;                  	//奖励ID	奖励ID
	int SpecialRewardId;         	//特殊奖励	特殊奖励的掉落列ID
	int Num;                     	//数量	奖励数量
	int SpecialRewardPro;        	//特殊奖励概率	特殊奖励概率

private:
	bool m_bIsValidate;
	void SetIsValidate(bool isValid)
	{
		m_bIsValidate=isValid;
	}
public:
	bool IsValidate()
	{
		return m_bIsValidate;
	}
	CiTanElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//帮会刺探表脜盲脰脙路芒脳掳脌脿
class CiTanTable
{
	friend class TableData;
private:
	CiTanTable(){}
	~CiTanTable(){}
	map<int, CiTanElement>	m_mapElements;
	vector<CiTanElement>	m_vecAllElements;
	CiTanElement m_emptyItem;
public:
	static CiTanTable& Instance()
	{
		static CiTanTable sInstance;
		return sInstance;
	}

	CiTanElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CiTanElement>&	GetAllElement()
	{
		if(!m_vecAllElements.empty()) 
			return m_vecAllElements;
		m_vecAllElements.reserve(m_mapElements.size());
		for(auto iter=m_mapElements.begin(); iter != m_mapElements.end(); ++iter)
		{
			if(iter->second.IsValidate()) 
				m_vecAllElements.push_back(iter->second);
		}
		return m_vecAllElements;
	}
	bool Load()
	{
		#ifdef CONFIG_JSON
		return LoadJson("CiTan.json");
		#else
		string strTableContent;
		if( LoadConfigContent("CiTan.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CiTan.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[CiTan.bin]脦麓脮脪碌陆");
			assert(false);
			return false;
		}
		return LoadBin(strTableContent);
		#endif

		
	}

	bool LoadJson(const std::string& jsonFile)
	{
		boost::property_tree::ptree parse;
		boost::property_tree::json_parser::read_json(std::string(CONFIG_PATH) + jsonFile, parse);
		boost::property_tree::ptree sms_array = parse.get_child("data");

		vector<string> vecLine;

				if(vecLine[0]!="ID"){printf_message("CiTan.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Reward"){printf_message("CiTan.csv中字段[Reward]位置不对应");assert(false); return false; }
		if(vecLine[2]!="SpecialRewardId"){printf_message("CiTan.csv中字段[SpecialRewardId]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Num"){printf_message("CiTan.csv中字段[Num]位置不对应");assert(false); return false; }
		if(vecLine[4]!="SpecialRewardPro"){printf_message("CiTan.csv中字段[SpecialRewardPro]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			CiTanElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Reward=atoi(vecLine[1].c_str());
			member.SpecialRewardId=atoi(vecLine[2].c_str());
			member.Num=atoi(vecLine[3].c_str());
			member.SpecialRewardPro=atoi(vecLine[4].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}

		return true;
	}

	bool LoadCsv(string strContent)
	{
		m_vecAllElements.clear();
		m_mapElements.clear();
		int contentOffset = 0;
		vector<string> vecLine;
		vecLine = ReadCsvLine( strContent, contentOffset );
		if(vecLine.size() != 5)
		{
			printf_message("CiTan.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("CiTan.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Reward"){printf_message("CiTan.csv中字段[Reward]位置不对应");assert(false); return false; }
		if(vecLine[2]!="SpecialRewardId"){printf_message("CiTan.csv中字段[SpecialRewardId]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Num"){printf_message("CiTan.csv中字段[Num]位置不对应");assert(false); return false; }
		if(vecLine[4]!="SpecialRewardPro"){printf_message("CiTan.csv中字段[SpecialRewardPro]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)5)
			{
				assert(false);
				return false;
			}
			CiTanElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Reward=atoi(vecLine[1].c_str());
			member.SpecialRewardId=atoi(vecLine[2].c_str());
			member.Num=atoi(vecLine[3].c_str());
			member.SpecialRewardPro=atoi(vecLine[4].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
