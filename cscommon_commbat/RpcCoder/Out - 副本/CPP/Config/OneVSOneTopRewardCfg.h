#ifndef __ONEVSONETOPREWARD_CONFIG_H
#define __ONEVSONETOPREWARD_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//排名奖励脜盲脰脙脢媒戮脻陆谩鹿鹿
struct OneVSOneTopRewardElement
{
	friend class OneVSOneTopRewardTable;
	int ID;                      	//编号	等级
	int StartTop;                	//起始名词	起始名词
	int EndTop;                  	//结束名次	结束名次
	int Type;                    	//分组类别	分组类别0总榜其他序号对应分组表中的ID
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
	OneVSOneTopRewardElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//排名奖励脜盲脰脙路芒脳掳脌脿
class OneVSOneTopRewardTable
{
	friend class TableData;
private:
	OneVSOneTopRewardTable(){}
	~OneVSOneTopRewardTable(){}
	map<int, OneVSOneTopRewardElement>	m_mapElements;
	vector<OneVSOneTopRewardElement>	m_vecAllElements;
	OneVSOneTopRewardElement m_emptyItem;
public:
	static OneVSOneTopRewardTable& Instance()
	{
		static OneVSOneTopRewardTable sInstance;
		return sInstance;
	}

	OneVSOneTopRewardElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<OneVSOneTopRewardElement>&	GetAllElement()
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
		return LoadJson("OneVSOneTopReward.json");
		#else
		string strTableContent;
		if( LoadConfigContent("OneVSOneTopReward.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("OneVSOneTopReward.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[OneVSOneTopReward.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("OneVSOneTopReward.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="StartTop"){printf_message("OneVSOneTopReward.csv中字段[StartTop]位置不对应");assert(false); return false; }
		if(vecLine[2]!="EndTop"){printf_message("OneVSOneTopReward.csv中字段[EndTop]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("OneVSOneTopReward.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Score"){printf_message("OneVSOneTopReward.csv中字段[Score]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Experience"){printf_message("OneVSOneTopReward.csv中字段[Experience]位置不对应");assert(false); return false; }
		if(vecLine[6]!="ItemID"){printf_message("OneVSOneTopReward.csv中字段[ItemID]位置不对应");assert(false); return false; }
		if(vecLine[7]!="ItemNum"){printf_message("OneVSOneTopReward.csv中字段[ItemNum]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			OneVSOneTopRewardElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.StartTop=atoi(vecLine[1].c_str());
			member.EndTop=atoi(vecLine[2].c_str());
			member.Type=atoi(vecLine[3].c_str());
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
			printf_message("OneVSOneTopReward.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("OneVSOneTopReward.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="StartTop"){printf_message("OneVSOneTopReward.csv中字段[StartTop]位置不对应");assert(false); return false; }
		if(vecLine[2]!="EndTop"){printf_message("OneVSOneTopReward.csv中字段[EndTop]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("OneVSOneTopReward.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Score"){printf_message("OneVSOneTopReward.csv中字段[Score]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Experience"){printf_message("OneVSOneTopReward.csv中字段[Experience]位置不对应");assert(false); return false; }
		if(vecLine[6]!="ItemID"){printf_message("OneVSOneTopReward.csv中字段[ItemID]位置不对应");assert(false); return false; }
		if(vecLine[7]!="ItemNum"){printf_message("OneVSOneTopReward.csv中字段[ItemNum]位置不对应");assert(false); return false; }

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
			OneVSOneTopRewardElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.StartTop=atoi(vecLine[1].c_str());
			member.EndTop=atoi(vecLine[2].c_str());
			member.Type=atoi(vecLine[3].c_str());
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
