#ifndef __LVUP_CONFIG_H
#define __LVUP_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//等级提升脜盲脰脙脢媒戮脻陆谩鹿鹿
struct LvUpElement
{
	friend class LvUpTable;
	int LvID;                    	//编号	等级
	int Exp;                     	//经验	升级所需经验
	int Spirit;                  	//体力	体力上限
	int SkillLvUp;               	//技能1升级消耗金钱	技能1升级消耗金钱
	int SkillLvUpMoney;          	//技能消耗金钱	技能消耗金钱
	int XiuWei;                  	//修为对应消耗经验	修为对应消耗经验

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
	LvUpElement()
	{
		LvID = -1;
		m_bIsValidate=false;
	}
};

//等级提升脜盲脰脙路芒脳掳脌脿
class LvUpTable
{
	friend class TableData;
private:
	LvUpTable(){}
	~LvUpTable(){}
	map<int, LvUpElement>	m_mapElements;
	vector<LvUpElement>	m_vecAllElements;
	LvUpElement m_emptyItem;
public:
	static LvUpTable& Instance()
	{
		static LvUpTable sInstance;
		return sInstance;
	}

	LvUpElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<LvUpElement>&	GetAllElement()
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
		return LoadJson("LvUp.json");
		#else
		string strTableContent;
		if( LoadConfigContent("LvUp.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("LvUp.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[LvUp.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="LvID"){printf_message("LvUp.csv中字段[LvID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Exp"){printf_message("LvUp.csv中字段[Exp]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Spirit"){printf_message("LvUp.csv中字段[Spirit]位置不对应");assert(false); return false; }
		if(vecLine[3]!="SkillLvUp"){printf_message("LvUp.csv中字段[SkillLvUp]位置不对应");assert(false); return false; }
		if(vecLine[4]!="SkillLvUpMoney"){printf_message("LvUp.csv中字段[SkillLvUpMoney]位置不对应");assert(false); return false; }
		if(vecLine[5]!="XiuWei"){printf_message("LvUp.csv中字段[XiuWei]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			LvUpElement	member;

						member.LvID=atoi(vecLine[0].c_str());
			member.Exp=atoi(vecLine[1].c_str());
			member.Spirit=atoi(vecLine[2].c_str());
			member.SkillLvUp=atoi(vecLine[3].c_str());
			member.SkillLvUpMoney=atoi(vecLine[4].c_str());
			member.XiuWei=atoi(vecLine[5].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.LvID] = member;
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
		if(vecLine.size() != 6)
		{
			printf_message("LvUp.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="LvID"){printf_message("LvUp.csv中字段[LvID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Exp"){printf_message("LvUp.csv中字段[Exp]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Spirit"){printf_message("LvUp.csv中字段[Spirit]位置不对应");assert(false); return false; }
		if(vecLine[3]!="SkillLvUp"){printf_message("LvUp.csv中字段[SkillLvUp]位置不对应");assert(false); return false; }
		if(vecLine[4]!="SkillLvUpMoney"){printf_message("LvUp.csv中字段[SkillLvUpMoney]位置不对应");assert(false); return false; }
		if(vecLine[5]!="XiuWei"){printf_message("LvUp.csv中字段[XiuWei]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)6)
			{
				assert(false);
				return false;
			}
			LvUpElement	member;
			member.LvID=atoi(vecLine[0].c_str());
			member.Exp=atoi(vecLine[1].c_str());
			member.Spirit=atoi(vecLine[2].c_str());
			member.SkillLvUp=atoi(vecLine[3].c_str());
			member.SkillLvUpMoney=atoi(vecLine[4].c_str());
			member.XiuWei=atoi(vecLine[5].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.LvID] = member;
		}
		return true;
	}
};

#endif
