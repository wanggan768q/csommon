#ifndef __TALENT_CONFIG_H
#define __TALENT_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//天赋技能脜盲脰脙脢媒戮脻陆谩鹿鹿
struct TalentElement
{
	friend class TalentTable;
	int LvID;                    	//天赋技能ID	职业加等级
	string Name;                 	//天赋名称	天赋名称
	string Desc;                 	//描述	天赋效果描述
	int Type;                    	//类型	1被动；2光环被动；3技能效果；4主动技能
	string Parameter;            	//参数	对应类型的参数

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
	TalentElement()
	{
		LvID = -1;
		m_bIsValidate=false;
	}
};

//天赋技能脜盲脰脙路芒脳掳脌脿
class TalentTable
{
	friend class TableData;
private:
	TalentTable(){}
	~TalentTable(){}
	map<int, TalentElement>	m_mapElements;
	vector<TalentElement>	m_vecAllElements;
	TalentElement m_emptyItem;
public:
	static TalentTable& Instance()
	{
		static TalentTable sInstance;
		return sInstance;
	}

	TalentElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<TalentElement>&	GetAllElement()
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
		return LoadJson("Talent.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Talent.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Talent.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Talent.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="LvID"){printf_message("Talent.csv中字段[LvID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Talent.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Desc"){printf_message("Talent.csv中字段[Desc]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("Talent.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Parameter"){printf_message("Talent.csv中字段[Parameter]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			TalentElement	member;

						member.LvID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Desc=vecLine[2];
			member.Type=atoi(vecLine[3].c_str());
			member.Parameter=vecLine[4];


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
		if(vecLine.size() != 5)
		{
			printf_message("Talent.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="LvID"){printf_message("Talent.csv中字段[LvID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Talent.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Desc"){printf_message("Talent.csv中字段[Desc]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("Talent.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Parameter"){printf_message("Talent.csv中字段[Parameter]位置不对应");assert(false); return false; }

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
			TalentElement	member;
			member.LvID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Desc=vecLine[2];
			member.Type=atoi(vecLine[3].c_str());
			member.Parameter=vecLine[4];

			member.SetIsValidate(true);
			m_mapElements[member.LvID] = member;
		}
		return true;
	}
};

#endif
