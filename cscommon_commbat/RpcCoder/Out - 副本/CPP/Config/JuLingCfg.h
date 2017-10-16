#ifndef __JULING_CONFIG_H
#define __JULING_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//聚灵表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct JuLingElement
{
	friend class JuLingTable;
	int ID;                      	//编号	聚灵技能ID
	int ItemID;                  	//道具ID	道具ID
	int SkillID;                 	//被动技能ID	被动技能ID
	int Type;                    	//技能类型	1攻击2防御3敏捷4上古
	int Lv;                      	//等级	等级
	int NextID;                  	//下一级ID	下一级ID
	int Money;                   	//升级消耗金钱	升级消耗金钱
	int ItemNum;                 	//升级消耗道具数量	升级消耗道具数量

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
	JuLingElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//聚灵表脜盲脰脙路芒脳掳脌脿
class JuLingTable
{
	friend class TableData;
private:
	JuLingTable(){}
	~JuLingTable(){}
	map<int, JuLingElement>	m_mapElements;
	vector<JuLingElement>	m_vecAllElements;
	JuLingElement m_emptyItem;
public:
	static JuLingTable& Instance()
	{
		static JuLingTable sInstance;
		return sInstance;
	}

	JuLingElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<JuLingElement>&	GetAllElement()
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
		return LoadJson("JuLing.json");
		#else
		string strTableContent;
		if( LoadConfigContent("JuLing.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("JuLing.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[JuLing.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("JuLing.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="ItemID"){printf_message("JuLing.csv中字段[ItemID]位置不对应");assert(false); return false; }
		if(vecLine[2]!="SkillID"){printf_message("JuLing.csv中字段[SkillID]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("JuLing.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Lv"){printf_message("JuLing.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[5]!="NextID"){printf_message("JuLing.csv中字段[NextID]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Money"){printf_message("JuLing.csv中字段[Money]位置不对应");assert(false); return false; }
		if(vecLine[7]!="ItemNum"){printf_message("JuLing.csv中字段[ItemNum]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			JuLingElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.ItemID=atoi(vecLine[1].c_str());
			member.SkillID=atoi(vecLine[2].c_str());
			member.Type=atoi(vecLine[3].c_str());
			member.Lv=atoi(vecLine[4].c_str());
			member.NextID=atoi(vecLine[5].c_str());
			member.Money=atoi(vecLine[6].c_str());
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
			printf_message("JuLing.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("JuLing.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="ItemID"){printf_message("JuLing.csv中字段[ItemID]位置不对应");assert(false); return false; }
		if(vecLine[2]!="SkillID"){printf_message("JuLing.csv中字段[SkillID]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("JuLing.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Lv"){printf_message("JuLing.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[5]!="NextID"){printf_message("JuLing.csv中字段[NextID]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Money"){printf_message("JuLing.csv中字段[Money]位置不对应");assert(false); return false; }
		if(vecLine[7]!="ItemNum"){printf_message("JuLing.csv中字段[ItemNum]位置不对应");assert(false); return false; }

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
			JuLingElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.ItemID=atoi(vecLine[1].c_str());
			member.SkillID=atoi(vecLine[2].c_str());
			member.Type=atoi(vecLine[3].c_str());
			member.Lv=atoi(vecLine[4].c_str());
			member.NextID=atoi(vecLine[5].c_str());
			member.Money=atoi(vecLine[6].c_str());
			member.ItemNum=atoi(vecLine[7].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
