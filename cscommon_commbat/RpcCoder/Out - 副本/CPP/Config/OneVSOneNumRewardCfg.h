#ifndef __ONEVSONENUMREWARD_CONFIG_H
#define __ONEVSONENUMREWARD_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//每次挑战的奖励脜盲脰脙脢媒戮脻陆谩鹿鹿
struct OneVSOneNumRewardElement
{
	friend class OneVSOneNumRewardTable;
	int ID;                      	//编号	等级
	int LV;                      	//等级	等级
	int StartNum;                	//起始次数	次数
	int EndNum;                  	//结束次数	结束次数
	int Score;                   	//分数	分数
	int Experience;              	//经验	经验
	int ItemID;                  	//物品id	物品id
	int ItemNum;                 	//物品数量	物品数量

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
	OneVSOneNumRewardElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//每次挑战的奖励脜盲脰脙路芒脳掳脌脿
class OneVSOneNumRewardTable
{
	friend class TableData;
private:
	OneVSOneNumRewardTable(){}
	~OneVSOneNumRewardTable(){}
	map<int, OneVSOneNumRewardElement>	m_mapElements;
	vector<OneVSOneNumRewardElement>	m_vecAllElements;
	OneVSOneNumRewardElement m_emptyItem;
public:
	static OneVSOneNumRewardTable& Instance()
	{
		static OneVSOneNumRewardTable sInstance;
		return sInstance;
	}

	OneVSOneNumRewardElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<OneVSOneNumRewardElement>&	GetAllElement()
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
		return LoadJson("OneVSOneNumReward.json");
		#else
		string strTableContent;
		if( LoadConfigContent("OneVSOneNumReward.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("OneVSOneNumReward.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[OneVSOneNumReward.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("OneVSOneNumReward.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="LV"){printf_message("OneVSOneNumReward.csv中字段[LV]位置不对应");assert(false); return false; }
		if(vecLine[2]!="StartNum"){printf_message("OneVSOneNumReward.csv中字段[StartNum]位置不对应");assert(false); return false; }
		if(vecLine[3]!="EndNum"){printf_message("OneVSOneNumReward.csv中字段[EndNum]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Score"){printf_message("OneVSOneNumReward.csv中字段[Score]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Experience"){printf_message("OneVSOneNumReward.csv中字段[Experience]位置不对应");assert(false); return false; }
		if(vecLine[6]!="ItemID"){printf_message("OneVSOneNumReward.csv中字段[ItemID]位置不对应");assert(false); return false; }
		if(vecLine[7]!="ItemNum"){printf_message("OneVSOneNumReward.csv中字段[ItemNum]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			OneVSOneNumRewardElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.LV=atoi(vecLine[1].c_str());
			member.StartNum=atoi(vecLine[2].c_str());
			member.EndNum=atoi(vecLine[3].c_str());
			member.Score=atoi(vecLine[4].c_str());
			member.Experience=atoi(vecLine[5].c_str());
			member.ItemID=atoi(vecLine[6].c_str());
			member.ItemNum=atoi(vecLine[7].c_str());


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
		if(vecLine.size() != 8)
		{
			printf_message("OneVSOneNumReward.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("OneVSOneNumReward.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="LV"){printf_message("OneVSOneNumReward.csv中字段[LV]位置不对应");assert(false); return false; }
		if(vecLine[2]!="StartNum"){printf_message("OneVSOneNumReward.csv中字段[StartNum]位置不对应");assert(false); return false; }
		if(vecLine[3]!="EndNum"){printf_message("OneVSOneNumReward.csv中字段[EndNum]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Score"){printf_message("OneVSOneNumReward.csv中字段[Score]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Experience"){printf_message("OneVSOneNumReward.csv中字段[Experience]位置不对应");assert(false); return false; }
		if(vecLine[6]!="ItemID"){printf_message("OneVSOneNumReward.csv中字段[ItemID]位置不对应");assert(false); return false; }
		if(vecLine[7]!="ItemNum"){printf_message("OneVSOneNumReward.csv中字段[ItemNum]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)8)
			{
				assert(false);
				return false;
			}
			OneVSOneNumRewardElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.LV=atoi(vecLine[1].c_str());
			member.StartNum=atoi(vecLine[2].c_str());
			member.EndNum=atoi(vecLine[3].c_str());
			member.Score=atoi(vecLine[4].c_str());
			member.Experience=atoi(vecLine[5].c_str());
			member.ItemID=atoi(vecLine[6].c_str());
			member.ItemNum=atoi(vecLine[7].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
