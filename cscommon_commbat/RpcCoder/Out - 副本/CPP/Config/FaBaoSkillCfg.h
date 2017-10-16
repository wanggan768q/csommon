﻿#ifndef __FABAOSKILL_CONFIG_H
#define __FABAOSKILL_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//法宝技能脜盲脰脙脢媒戮脻陆谩鹿鹿
struct FaBaoSkillElement
{
	friend class FaBaoSkillTable;
	int ID;                      	//编号	法宝技能ID
	string Name;                 	//技能名称	技能名称
	int Lv;                      	//技能等级	技能等级
	string MiaoShu;              	//技能描述	技能描述

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
	FaBaoSkillElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//法宝技能脜盲脰脙路芒脳掳脌脿
class FaBaoSkillTable
{
	friend class TableData;
private:
	FaBaoSkillTable(){}
	~FaBaoSkillTable(){}
	map<int, FaBaoSkillElement>	m_mapElements;
	vector<FaBaoSkillElement>	m_vecAllElements;
	FaBaoSkillElement m_emptyItem;
public:
	static FaBaoSkillTable& Instance()
	{
		static FaBaoSkillTable sInstance;
		return sInstance;
	}

	FaBaoSkillElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<FaBaoSkillElement>&	GetAllElement()
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
		return LoadJson("FaBaoSkill.json");
		#else
		string strTableContent;
		if( LoadConfigContent("FaBaoSkill.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("FaBaoSkill.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[FaBaoSkill.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("FaBaoSkill.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("FaBaoSkill.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Lv"){printf_message("FaBaoSkill.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[3]!="MiaoShu"){printf_message("FaBaoSkill.csv中字段[MiaoShu]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			FaBaoSkillElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Lv=atoi(vecLine[2].c_str());
			member.MiaoShu=vecLine[3];


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
		if(vecLine.size() != 4)
		{
			printf_message("FaBaoSkill.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("FaBaoSkill.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("FaBaoSkill.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Lv"){printf_message("FaBaoSkill.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[3]!="MiaoShu"){printf_message("FaBaoSkill.csv中字段[MiaoShu]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)4)
			{
				assert(false);
				return false;
			}
			FaBaoSkillElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Lv=atoi(vecLine[2].c_str());
			member.MiaoShu=vecLine[3];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
