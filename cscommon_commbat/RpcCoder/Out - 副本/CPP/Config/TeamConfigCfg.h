#ifndef __TEAMCONFIG_CONFIG_H
#define __TEAMCONFIG_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//组队基础配置脜盲脰脙脢媒戮脻陆谩鹿鹿
struct TeamConfigElement
{
	friend class TeamConfigTable;
	int ID;                      	//编号	等级
	string Name;                 	//说明	字段说明
	int Args1;                   	//参数1	下限等级
	int Args2;                   	//参数2	上限等级
	int Args3;                   	//参数3	等级差
	int Set;                     	//所属层级	所属层级 1普通副本 6 英雄副本
	int ZhanKai;                 	//是否可以展开	是否可以展开

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
	TeamConfigElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//组队基础配置脜盲脰脙路芒脳掳脌脿
class TeamConfigTable
{
	friend class TableData;
private:
	TeamConfigTable(){}
	~TeamConfigTable(){}
	map<int, TeamConfigElement>	m_mapElements;
	vector<TeamConfigElement>	m_vecAllElements;
	TeamConfigElement m_emptyItem;
public:
	static TeamConfigTable& Instance()
	{
		static TeamConfigTable sInstance;
		return sInstance;
	}

	TeamConfigElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<TeamConfigElement>&	GetAllElement()
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
		return LoadJson("TeamConfig.json");
		#else
		string strTableContent;
		if( LoadConfigContent("TeamConfig.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("TeamConfig.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[TeamConfig.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("TeamConfig.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("TeamConfig.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Args1"){printf_message("TeamConfig.csv中字段[Args1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Args2"){printf_message("TeamConfig.csv中字段[Args2]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Args3"){printf_message("TeamConfig.csv中字段[Args3]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Set"){printf_message("TeamConfig.csv中字段[Set]位置不对应");assert(false); return false; }
		if(vecLine[6]!="ZhanKai"){printf_message("TeamConfig.csv中字段[ZhanKai]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			TeamConfigElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Args1=atoi(vecLine[2].c_str());
			member.Args2=atoi(vecLine[3].c_str());
			member.Args3=atoi(vecLine[4].c_str());
			member.Set=atoi(vecLine[5].c_str());
			member.ZhanKai=atoi(vecLine[6].c_str());


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
		if(vecLine.size() != 7)
		{
			printf_message("TeamConfig.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("TeamConfig.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("TeamConfig.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Args1"){printf_message("TeamConfig.csv中字段[Args1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Args2"){printf_message("TeamConfig.csv中字段[Args2]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Args3"){printf_message("TeamConfig.csv中字段[Args3]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Set"){printf_message("TeamConfig.csv中字段[Set]位置不对应");assert(false); return false; }
		if(vecLine[6]!="ZhanKai"){printf_message("TeamConfig.csv中字段[ZhanKai]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)7)
			{
				assert(false);
				return false;
			}
			TeamConfigElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Args1=atoi(vecLine[2].c_str());
			member.Args2=atoi(vecLine[3].c_str());
			member.Args3=atoi(vecLine[4].c_str());
			member.Set=atoi(vecLine[5].c_str());
			member.ZhanKai=atoi(vecLine[6].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
