#ifndef __CARGOREWARD_CONFIG_H
#define __CARGOREWARD_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//货运奖励脜盲脰脙脢媒戮脻陆谩鹿鹿
struct CargoRewardElement
{
	friend class CargoRewardTable;
	int ID;                      	//ID	ID
	int Type;                    	//类别	类别
	int Lvl;                     	//等级	等级
	int EXP;                     	//单项填充经验	单项填充经验
	int Contribution;            	//单项填充贡献	单项填充贡献
	int Money;                   	//单项填充金钱	单项填充金钱
	string MEXP;                 	//总共填充经验	总共填充经验
	string MContribution;        	//总共填充贡献	总共填充贡献
	string MMoney;               	//总共填充金钱	总共填充金钱

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
	CargoRewardElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//货运奖励脜盲脰脙路芒脳掳脌脿
class CargoRewardTable
{
	friend class TableData;
private:
	CargoRewardTable(){}
	~CargoRewardTable(){}
	map<int, CargoRewardElement>	m_mapElements;
	vector<CargoRewardElement>	m_vecAllElements;
	CargoRewardElement m_emptyItem;
public:
	static CargoRewardTable& Instance()
	{
		static CargoRewardTable sInstance;
		return sInstance;
	}

	CargoRewardElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CargoRewardElement>&	GetAllElement()
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
		return LoadJson("CargoReward.json");
		#else
		string strTableContent;
		if( LoadConfigContent("CargoReward.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CargoReward.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[CargoReward.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("CargoReward.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Type"){printf_message("CargoReward.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Lvl"){printf_message("CargoReward.csv中字段[Lvl]位置不对应");assert(false); return false; }
		if(vecLine[3]!="EXP"){printf_message("CargoReward.csv中字段[EXP]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Contribution"){printf_message("CargoReward.csv中字段[Contribution]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Money"){printf_message("CargoReward.csv中字段[Money]位置不对应");assert(false); return false; }
		if(vecLine[6]!="MEXP"){printf_message("CargoReward.csv中字段[MEXP]位置不对应");assert(false); return false; }
		if(vecLine[7]!="MContribution"){printf_message("CargoReward.csv中字段[MContribution]位置不对应");assert(false); return false; }
		if(vecLine[8]!="MMoney"){printf_message("CargoReward.csv中字段[MMoney]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			CargoRewardElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Type=atoi(vecLine[1].c_str());
			member.Lvl=atoi(vecLine[2].c_str());
			member.EXP=atoi(vecLine[3].c_str());
			member.Contribution=atoi(vecLine[4].c_str());
			member.Money=atoi(vecLine[5].c_str());
			member.MEXP=vecLine[6];
			member.MContribution=vecLine[7];
			member.MMoney=vecLine[8];


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
		if(vecLine.size() != 9)
		{
			printf_message("CargoReward.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("CargoReward.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Type"){printf_message("CargoReward.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Lvl"){printf_message("CargoReward.csv中字段[Lvl]位置不对应");assert(false); return false; }
		if(vecLine[3]!="EXP"){printf_message("CargoReward.csv中字段[EXP]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Contribution"){printf_message("CargoReward.csv中字段[Contribution]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Money"){printf_message("CargoReward.csv中字段[Money]位置不对应");assert(false); return false; }
		if(vecLine[6]!="MEXP"){printf_message("CargoReward.csv中字段[MEXP]位置不对应");assert(false); return false; }
		if(vecLine[7]!="MContribution"){printf_message("CargoReward.csv中字段[MContribution]位置不对应");assert(false); return false; }
		if(vecLine[8]!="MMoney"){printf_message("CargoReward.csv中字段[MMoney]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)9)
			{
				assert(false);
				return false;
			}
			CargoRewardElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Type=atoi(vecLine[1].c_str());
			member.Lvl=atoi(vecLine[2].c_str());
			member.EXP=atoi(vecLine[3].c_str());
			member.Contribution=atoi(vecLine[4].c_str());
			member.Money=atoi(vecLine[5].c_str());
			member.MEXP=vecLine[6];
			member.MContribution=vecLine[7];
			member.MMoney=vecLine[8];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
