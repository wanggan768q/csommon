#ifndef __YITIAOLONG_CONFIG_H
#define __YITIAOLONG_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//一条龙活动表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct YiTiaoLongElement
{
	friend class YiTiaoLongTable;
	int ID;                      	//完成次数	完成的副本次数
	float ExpReward;             	//经验	针对boss掉落经验的倍率
	string SpecialRewardId;      	//特殊奖励	特殊奖励的掉落列ID
	string Num;                  	//数量	奖励数量
	string SpecialRewardPro;     	//特殊奖励概率	特殊奖励概率

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
	YiTiaoLongElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//一条龙活动表脜盲脰脙路芒脳掳脌脿
class YiTiaoLongTable
{
	friend class TableData;
private:
	YiTiaoLongTable(){}
	~YiTiaoLongTable(){}
	map<int, YiTiaoLongElement>	m_mapElements;
	vector<YiTiaoLongElement>	m_vecAllElements;
	YiTiaoLongElement m_emptyItem;
public:
	static YiTiaoLongTable& Instance()
	{
		static YiTiaoLongTable sInstance;
		return sInstance;
	}

	YiTiaoLongElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<YiTiaoLongElement>&	GetAllElement()
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
		return LoadJson("YiTiaoLong.json");
		#else
		string strTableContent;
		if( LoadConfigContent("YiTiaoLong.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("YiTiaoLong.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[YiTiaoLong.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("YiTiaoLong.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="ExpReward"){printf_message("YiTiaoLong.csv中字段[ExpReward]位置不对应");assert(false); return false; }
		if(vecLine[2]!="SpecialRewardId"){printf_message("YiTiaoLong.csv中字段[SpecialRewardId]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Num"){printf_message("YiTiaoLong.csv中字段[Num]位置不对应");assert(false); return false; }
		if(vecLine[4]!="SpecialRewardPro"){printf_message("YiTiaoLong.csv中字段[SpecialRewardPro]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			YiTiaoLongElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.ExpReward=atof(vecLine[1].c_str());
			member.SpecialRewardId=vecLine[2];
			member.Num=vecLine[3];
			member.SpecialRewardPro=vecLine[4];


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
			printf_message("YiTiaoLong.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("YiTiaoLong.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="ExpReward"){printf_message("YiTiaoLong.csv中字段[ExpReward]位置不对应");assert(false); return false; }
		if(vecLine[2]!="SpecialRewardId"){printf_message("YiTiaoLong.csv中字段[SpecialRewardId]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Num"){printf_message("YiTiaoLong.csv中字段[Num]位置不对应");assert(false); return false; }
		if(vecLine[4]!="SpecialRewardPro"){printf_message("YiTiaoLong.csv中字段[SpecialRewardPro]位置不对应");assert(false); return false; }

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
			YiTiaoLongElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.ExpReward=atof(vecLine[1].c_str());
			member.SpecialRewardId=vecLine[2];
			member.Num=vecLine[3];
			member.SpecialRewardPro=vecLine[4];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
