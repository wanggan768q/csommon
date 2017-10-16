﻿#ifndef __TIANFU_CONFIG_H
#define __TIANFU_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//天赋表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct TianFuElement
{
	friend class TianFuTable;
	int ID;                      	//编号	ID
	int Hero;                    	//所属英雄	所属英雄
	int Set;                     	//所属天赋段	1 40-69 2 70-89 3 90-109 4 110-129
	string Name;                 	//名称	名称
	string MiaoShu;              	//描述	描述

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
	TianFuElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//天赋表脜盲脰脙路芒脳掳脌脿
class TianFuTable
{
	friend class TableData;
private:
	TianFuTable(){}
	~TianFuTable(){}
	map<int, TianFuElement>	m_mapElements;
	vector<TianFuElement>	m_vecAllElements;
	TianFuElement m_emptyItem;
public:
	static TianFuTable& Instance()
	{
		static TianFuTable sInstance;
		return sInstance;
	}

	TianFuElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<TianFuElement>&	GetAllElement()
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
		return LoadJson("TianFu.json");
		#else
		string strTableContent;
		if( LoadConfigContent("TianFu.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("TianFu.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[TianFu.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("TianFu.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Hero"){printf_message("TianFu.csv中字段[Hero]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Set"){printf_message("TianFu.csv中字段[Set]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Name"){printf_message("TianFu.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[4]!="MiaoShu"){printf_message("TianFu.csv中字段[MiaoShu]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			TianFuElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Hero=atoi(vecLine[1].c_str());
			member.Set=atoi(vecLine[2].c_str());
			member.Name=vecLine[3];
			member.MiaoShu=vecLine[4];


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
			printf_message("TianFu.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("TianFu.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Hero"){printf_message("TianFu.csv中字段[Hero]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Set"){printf_message("TianFu.csv中字段[Set]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Name"){printf_message("TianFu.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[4]!="MiaoShu"){printf_message("TianFu.csv中字段[MiaoShu]位置不对应");assert(false); return false; }

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
			TianFuElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Hero=atoi(vecLine[1].c_str());
			member.Set=atoi(vecLine[2].c_str());
			member.Name=vecLine[3];
			member.MiaoShu=vecLine[4];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
