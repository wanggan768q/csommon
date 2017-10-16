#ifndef __SKILLLIMIT_CONFIG_H
#define __SKILLLIMIT_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//技能限制脜盲脰脙脢媒戮脻陆谩鹿鹿
struct SkillLimitElement
{
	friend class SkillLimitTable;
	int LimitID;                 	//限制ID	限制ID
	int RoleLv;                  	//角色等级	激活技能的角色等级限制
	int Book;                    	//激活所需技能书	激活所需技能书
	int SkillLimit;              	//前置技能限制	前置技能限制
	int LvUpLimitSkillLv;        	//升级技能所需前置技能等级	前置技能等级+x=当前技能等级
	int LvUpRoleLv;              	//升级技能所需角色等级	技能每升1级所需人物等级提升等级

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
	SkillLimitElement()
	{
		LimitID = -1;
		m_bIsValidate=false;
	}
};

//技能限制脜盲脰脙路芒脳掳脌脿
class SkillLimitTable
{
	friend class TableData;
private:
	SkillLimitTable(){}
	~SkillLimitTable(){}
	map<int, SkillLimitElement>	m_mapElements;
	vector<SkillLimitElement>	m_vecAllElements;
	SkillLimitElement m_emptyItem;
public:
	static SkillLimitTable& Instance()
	{
		static SkillLimitTable sInstance;
		return sInstance;
	}

	SkillLimitElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SkillLimitElement>&	GetAllElement()
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
		return LoadJson("SkillLimit.json");
		#else
		string strTableContent;
		if( LoadConfigContent("SkillLimit.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("SkillLimit.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[SkillLimit.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="LimitID"){printf_message("SkillLimit.csv中字段[LimitID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="RoleLv"){printf_message("SkillLimit.csv中字段[RoleLv]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Book"){printf_message("SkillLimit.csv中字段[Book]位置不对应");assert(false); return false; }
		if(vecLine[3]!="SkillLimit"){printf_message("SkillLimit.csv中字段[SkillLimit]位置不对应");assert(false); return false; }
		if(vecLine[4]!="LvUpLimitSkillLv"){printf_message("SkillLimit.csv中字段[LvUpLimitSkillLv]位置不对应");assert(false); return false; }
		if(vecLine[5]!="LvUpRoleLv"){printf_message("SkillLimit.csv中字段[LvUpRoleLv]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			SkillLimitElement	member;

						member.LimitID=atoi(vecLine[0].c_str());
			member.RoleLv=atoi(vecLine[1].c_str());
			member.Book=atoi(vecLine[2].c_str());
			member.SkillLimit=atoi(vecLine[3].c_str());
			member.LvUpLimitSkillLv=atoi(vecLine[4].c_str());
			member.LvUpRoleLv=atoi(vecLine[5].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.LimitID] = member;
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
			printf_message("SkillLimit.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="LimitID"){printf_message("SkillLimit.csv中字段[LimitID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="RoleLv"){printf_message("SkillLimit.csv中字段[RoleLv]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Book"){printf_message("SkillLimit.csv中字段[Book]位置不对应");assert(false); return false; }
		if(vecLine[3]!="SkillLimit"){printf_message("SkillLimit.csv中字段[SkillLimit]位置不对应");assert(false); return false; }
		if(vecLine[4]!="LvUpLimitSkillLv"){printf_message("SkillLimit.csv中字段[LvUpLimitSkillLv]位置不对应");assert(false); return false; }
		if(vecLine[5]!="LvUpRoleLv"){printf_message("SkillLimit.csv中字段[LvUpRoleLv]位置不对应");assert(false); return false; }

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
			SkillLimitElement	member;
			member.LimitID=atoi(vecLine[0].c_str());
			member.RoleLv=atoi(vecLine[1].c_str());
			member.Book=atoi(vecLine[2].c_str());
			member.SkillLimit=atoi(vecLine[3].c_str());
			member.LvUpLimitSkillLv=atoi(vecLine[4].c_str());
			member.LvUpRoleLv=atoi(vecLine[5].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.LimitID] = member;
		}
		return true;
	}
};

#endif
