#ifndef __SECTION_CONFIG_H
#define __SECTION_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//章节表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct SectionElement
{
	friend class SectionTable;
	int SectionID;               	//章节ID	章节ID
	string Name;                 	//章节名称	章节的名字
	int SystemID;                	//从属系统ID	从属于哪个副本系统的ID（1剧情、2活动、3日常、90帮会
	int Team;                    	//可否组队	1可以，0不可以
	string BackGround;           	//章节背景图	章节显示的背景图

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
	SectionElement()
	{
		SectionID = -1;
		m_bIsValidate=false;
	}
};

//章节表脜盲脰脙路芒脳掳脌脿
class SectionTable
{
	friend class TableData;
private:
	SectionTable(){}
	~SectionTable(){}
	map<int, SectionElement>	m_mapElements;
	vector<SectionElement>	m_vecAllElements;
	SectionElement m_emptyItem;
public:
	static SectionTable& Instance()
	{
		static SectionTable sInstance;
		return sInstance;
	}

	SectionElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SectionElement>&	GetAllElement()
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
		return LoadJson("Section.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Section.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Section.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Section.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="SectionID"){printf_message("Section.csv中字段[SectionID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Section.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="SystemID"){printf_message("Section.csv中字段[SystemID]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Team"){printf_message("Section.csv中字段[Team]位置不对应");assert(false); return false; }
		if(vecLine[4]!="BackGround"){printf_message("Section.csv中字段[BackGround]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			SectionElement	member;

						member.SectionID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.SystemID=atoi(vecLine[2].c_str());
			member.Team=atoi(vecLine[3].c_str());
			member.BackGround=vecLine[4];


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.SectionID] = member;
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
			printf_message("Section.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="SectionID"){printf_message("Section.csv中字段[SectionID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Section.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="SystemID"){printf_message("Section.csv中字段[SystemID]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Team"){printf_message("Section.csv中字段[Team]位置不对应");assert(false); return false; }
		if(vecLine[4]!="BackGround"){printf_message("Section.csv中字段[BackGround]位置不对应");assert(false); return false; }

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
			SectionElement	member;
			member.SectionID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.SystemID=atoi(vecLine[2].c_str());
			member.Team=atoi(vecLine[3].c_str());
			member.BackGround=vecLine[4];

			member.SetIsValidate(true);
			m_mapElements[member.SectionID] = member;
		}
		return true;
	}
};

#endif
