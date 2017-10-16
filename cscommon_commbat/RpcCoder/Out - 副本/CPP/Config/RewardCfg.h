#ifndef __REWARD_CONFIG_H
#define __REWARD_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//奖励表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct RewardElement
{
	friend class RewardTable;
	int RewardID;                	//奖励ID	奖励ID
	int Item1;                   	//道具1	道具1
	int ItemNum1;                	//道具1数量	道具1数量
	int Item2;                   	//道具2	道具2
	int ItemNum2;                	//道具2数量	道具2数量
	int Item3;                   	//道具3	道具3
	int ItemNum3;                	//道具3数量	道具3数量
	int Item4;                   	//道具4	道具4
	int ItemNum4;                	//道具4数量	道具4数量
	int Item5;                   	//道具5	道具5
	int ItemNum5;                	//道具5数量	道具5数量

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
	RewardElement()
	{
		RewardID = -1;
		m_bIsValidate=false;
	}
};

//奖励表脜盲脰脙路芒脳掳脌脿
class RewardTable
{
	friend class TableData;
private:
	RewardTable(){}
	~RewardTable(){}
	map<int, RewardElement>	m_mapElements;
	vector<RewardElement>	m_vecAllElements;
	RewardElement m_emptyItem;
public:
	static RewardTable& Instance()
	{
		static RewardTable sInstance;
		return sInstance;
	}

	RewardElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<RewardElement>&	GetAllElement()
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
		return LoadJson("Reward.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Reward.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Reward.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Reward.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="RewardID"){printf_message("Reward.csv中字段[RewardID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Item1"){printf_message("Reward.csv中字段[Item1]位置不对应");assert(false); return false; }
		if(vecLine[2]!="ItemNum1"){printf_message("Reward.csv中字段[ItemNum1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Item2"){printf_message("Reward.csv中字段[Item2]位置不对应");assert(false); return false; }
		if(vecLine[4]!="ItemNum2"){printf_message("Reward.csv中字段[ItemNum2]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Item3"){printf_message("Reward.csv中字段[Item3]位置不对应");assert(false); return false; }
		if(vecLine[6]!="ItemNum3"){printf_message("Reward.csv中字段[ItemNum3]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Item4"){printf_message("Reward.csv中字段[Item4]位置不对应");assert(false); return false; }
		if(vecLine[8]!="ItemNum4"){printf_message("Reward.csv中字段[ItemNum4]位置不对应");assert(false); return false; }
		if(vecLine[9]!="Item5"){printf_message("Reward.csv中字段[Item5]位置不对应");assert(false); return false; }
		if(vecLine[10]!="ItemNum5"){printf_message("Reward.csv中字段[ItemNum5]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			RewardElement	member;

						member.RewardID=atoi(vecLine[0].c_str());
			member.Item1=atoi(vecLine[1].c_str());
			member.ItemNum1=atoi(vecLine[2].c_str());
			member.Item2=atoi(vecLine[3].c_str());
			member.ItemNum2=atoi(vecLine[4].c_str());
			member.Item3=atoi(vecLine[5].c_str());
			member.ItemNum3=atoi(vecLine[6].c_str());
			member.Item4=atoi(vecLine[7].c_str());
			member.ItemNum4=atoi(vecLine[8].c_str());
			member.Item5=atoi(vecLine[9].c_str());
			member.ItemNum5=atoi(vecLine[10].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.RewardID] = member;
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
		if(vecLine.size() != 11)
		{
			printf_message("Reward.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="RewardID"){printf_message("Reward.csv中字段[RewardID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Item1"){printf_message("Reward.csv中字段[Item1]位置不对应");assert(false); return false; }
		if(vecLine[2]!="ItemNum1"){printf_message("Reward.csv中字段[ItemNum1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Item2"){printf_message("Reward.csv中字段[Item2]位置不对应");assert(false); return false; }
		if(vecLine[4]!="ItemNum2"){printf_message("Reward.csv中字段[ItemNum2]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Item3"){printf_message("Reward.csv中字段[Item3]位置不对应");assert(false); return false; }
		if(vecLine[6]!="ItemNum3"){printf_message("Reward.csv中字段[ItemNum3]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Item4"){printf_message("Reward.csv中字段[Item4]位置不对应");assert(false); return false; }
		if(vecLine[8]!="ItemNum4"){printf_message("Reward.csv中字段[ItemNum4]位置不对应");assert(false); return false; }
		if(vecLine[9]!="Item5"){printf_message("Reward.csv中字段[Item5]位置不对应");assert(false); return false; }
		if(vecLine[10]!="ItemNum5"){printf_message("Reward.csv中字段[ItemNum5]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)11)
			{
				assert(false);
				return false;
			}
			RewardElement	member;
			member.RewardID=atoi(vecLine[0].c_str());
			member.Item1=atoi(vecLine[1].c_str());
			member.ItemNum1=atoi(vecLine[2].c_str());
			member.Item2=atoi(vecLine[3].c_str());
			member.ItemNum2=atoi(vecLine[4].c_str());
			member.Item3=atoi(vecLine[5].c_str());
			member.ItemNum3=atoi(vecLine[6].c_str());
			member.Item4=atoi(vecLine[7].c_str());
			member.ItemNum4=atoi(vecLine[8].c_str());
			member.Item5=atoi(vecLine[9].c_str());
			member.ItemNum5=atoi(vecLine[10].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.RewardID] = member;
		}
		return true;
	}
};

#endif
