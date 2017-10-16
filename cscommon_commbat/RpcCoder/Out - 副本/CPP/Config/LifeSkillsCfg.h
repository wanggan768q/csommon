#ifndef __LIFESKILLS_CONFIG_H
#define __LIFESKILLS_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//生活技能表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct LifeSkillsElement
{
	friend class LifeSkillsTable;
	int ID;                      	//编号	编号
	int LifeSkills;              	//生活技能	生活技能（1采集2种植3钓鱼4饲养5炼药6烹饪）
	int LvID;                    	//等级	等级
	int Exp;                     	//消耗帮贡	升级所需帮贡
	int Money;                   	//消耗银票	升级所需银票
	string SourceIcon;           	//技能图片	技能图片
	string ButtonName;           	//按钮名字	按钮名字
	string LifeSkillsName;       	//生活技能名字	生活技能名字
	string describe;             	//描述	描述

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
	LifeSkillsElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//生活技能表脜盲脰脙路芒脳掳脌脿
class LifeSkillsTable
{
	friend class TableData;
private:
	LifeSkillsTable(){}
	~LifeSkillsTable(){}
	map<int, LifeSkillsElement>	m_mapElements;
	vector<LifeSkillsElement>	m_vecAllElements;
	LifeSkillsElement m_emptyItem;
public:
	static LifeSkillsTable& Instance()
	{
		static LifeSkillsTable sInstance;
		return sInstance;
	}

	LifeSkillsElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<LifeSkillsElement>&	GetAllElement()
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
		return LoadJson("LifeSkills.json");
		#else
		string strTableContent;
		if( LoadConfigContent("LifeSkills.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("LifeSkills.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[LifeSkills.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("LifeSkills.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="LifeSkills"){printf_message("LifeSkills.csv中字段[LifeSkills]位置不对应");assert(false); return false; }
		if(vecLine[2]!="LvID"){printf_message("LifeSkills.csv中字段[LvID]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Exp"){printf_message("LifeSkills.csv中字段[Exp]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Money"){printf_message("LifeSkills.csv中字段[Money]位置不对应");assert(false); return false; }
		if(vecLine[5]!="SourceIcon"){printf_message("LifeSkills.csv中字段[SourceIcon]位置不对应");assert(false); return false; }
		if(vecLine[6]!="ButtonName"){printf_message("LifeSkills.csv中字段[ButtonName]位置不对应");assert(false); return false; }
		if(vecLine[7]!="LifeSkillsName"){printf_message("LifeSkills.csv中字段[LifeSkillsName]位置不对应");assert(false); return false; }
		if(vecLine[8]!="describe"){printf_message("LifeSkills.csv中字段[describe]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			LifeSkillsElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.LifeSkills=atoi(vecLine[1].c_str());
			member.LvID=atoi(vecLine[2].c_str());
			member.Exp=atoi(vecLine[3].c_str());
			member.Money=atoi(vecLine[4].c_str());
			member.SourceIcon=vecLine[5];
			member.ButtonName=vecLine[6];
			member.LifeSkillsName=vecLine[7];
			member.describe=vecLine[8];


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
			printf_message("LifeSkills.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("LifeSkills.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="LifeSkills"){printf_message("LifeSkills.csv中字段[LifeSkills]位置不对应");assert(false); return false; }
		if(vecLine[2]!="LvID"){printf_message("LifeSkills.csv中字段[LvID]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Exp"){printf_message("LifeSkills.csv中字段[Exp]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Money"){printf_message("LifeSkills.csv中字段[Money]位置不对应");assert(false); return false; }
		if(vecLine[5]!="SourceIcon"){printf_message("LifeSkills.csv中字段[SourceIcon]位置不对应");assert(false); return false; }
		if(vecLine[6]!="ButtonName"){printf_message("LifeSkills.csv中字段[ButtonName]位置不对应");assert(false); return false; }
		if(vecLine[7]!="LifeSkillsName"){printf_message("LifeSkills.csv中字段[LifeSkillsName]位置不对应");assert(false); return false; }
		if(vecLine[8]!="describe"){printf_message("LifeSkills.csv中字段[describe]位置不对应");assert(false); return false; }

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
			LifeSkillsElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.LifeSkills=atoi(vecLine[1].c_str());
			member.LvID=atoi(vecLine[2].c_str());
			member.Exp=atoi(vecLine[3].c_str());
			member.Money=atoi(vecLine[4].c_str());
			member.SourceIcon=vecLine[5];
			member.ButtonName=vecLine[6];
			member.LifeSkillsName=vecLine[7];
			member.describe=vecLine[8];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
