#ifndef __SKILLCONFIG_CONFIG_H
#define __SKILLCONFIG_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//技能特殊配置脜盲脰脙脢媒戮脻陆谩鹿鹿
struct SkillConfigElement
{
	friend class SkillConfigTable;
	int ID;                      	//编号	等级
	string Name;                 	//说明	字段说明
	string Args1;                	//参数1	参数1
	string Args2;                	//参数2	参数2
	string Args3;                	//参数3	参数3
	string Args4;                	//参数4	参数4
	string Args5;                	//参数5	参数5
	string Args6;                	//参数6	参数6
	string Args7;                	//参数7	参数7
	string JieShi;               	//参数解释	参数解释

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
	SkillConfigElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//技能特殊配置脜盲脰脙路芒脳掳脌脿
class SkillConfigTable
{
	friend class TableData;
private:
	SkillConfigTable(){}
	~SkillConfigTable(){}
	map<int, SkillConfigElement>	m_mapElements;
	vector<SkillConfigElement>	m_vecAllElements;
	SkillConfigElement m_emptyItem;
public:
	static SkillConfigTable& Instance()
	{
		static SkillConfigTable sInstance;
		return sInstance;
	}

	SkillConfigElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SkillConfigElement>&	GetAllElement()
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
		return LoadJson("SkillConfig.json");
		#else
		string strTableContent;
		if( LoadConfigContent("SkillConfig.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("SkillConfig.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[SkillConfig.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("SkillConfig.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("SkillConfig.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Args1"){printf_message("SkillConfig.csv中字段[Args1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Args2"){printf_message("SkillConfig.csv中字段[Args2]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Args3"){printf_message("SkillConfig.csv中字段[Args3]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Args4"){printf_message("SkillConfig.csv中字段[Args4]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Args5"){printf_message("SkillConfig.csv中字段[Args5]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Args6"){printf_message("SkillConfig.csv中字段[Args6]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Args7"){printf_message("SkillConfig.csv中字段[Args7]位置不对应");assert(false); return false; }
		if(vecLine[9]!="JieShi"){printf_message("SkillConfig.csv中字段[JieShi]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			SkillConfigElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Args1=vecLine[2];
			member.Args2=vecLine[3];
			member.Args3=vecLine[4];
			member.Args4=vecLine[5];
			member.Args5=vecLine[6];
			member.Args6=vecLine[7];
			member.Args7=vecLine[8];
			member.JieShi=vecLine[9];


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
		if(vecLine.size() != 10)
		{
			printf_message("SkillConfig.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("SkillConfig.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("SkillConfig.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Args1"){printf_message("SkillConfig.csv中字段[Args1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Args2"){printf_message("SkillConfig.csv中字段[Args2]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Args3"){printf_message("SkillConfig.csv中字段[Args3]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Args4"){printf_message("SkillConfig.csv中字段[Args4]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Args5"){printf_message("SkillConfig.csv中字段[Args5]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Args6"){printf_message("SkillConfig.csv中字段[Args6]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Args7"){printf_message("SkillConfig.csv中字段[Args7]位置不对应");assert(false); return false; }
		if(vecLine[9]!="JieShi"){printf_message("SkillConfig.csv中字段[JieShi]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)10)
			{
				assert(false);
				return false;
			}
			SkillConfigElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Args1=vecLine[2];
			member.Args2=vecLine[3];
			member.Args3=vecLine[4];
			member.Args4=vecLine[5];
			member.Args5=vecLine[6];
			member.Args6=vecLine[7];
			member.Args7=vecLine[8];
			member.JieShi=vecLine[9];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
