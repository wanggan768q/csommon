#ifndef __LOCALIZATION_CONFIG_H
#define __LOCALIZATION_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//本地化脜盲脰脙脢媒戮脻陆谩鹿鹿
struct LocalizationElement
{
	friend class LocalizationTable;
	int id;                      	//id	索引
	string key;                  	//本地化键值	本地化键值
	string cn;                   	//中文	中文
	string en;                   	//英语	英语

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
	LocalizationElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//本地化脜盲脰脙路芒脳掳脌脿
class LocalizationTable
{
	friend class TableData;
private:
	LocalizationTable(){}
	~LocalizationTable(){}
	map<int, LocalizationElement>	m_mapElements;
	vector<LocalizationElement>	m_vecAllElements;
	LocalizationElement m_emptyItem;
public:
	static LocalizationTable& Instance()
	{
		static LocalizationTable sInstance;
		return sInstance;
	}

	LocalizationElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<LocalizationElement>&	GetAllElement()
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
		return LoadJson("Localization.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Localization.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Localization.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Localization.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="id"){printf_message("Localization.csv中字段[id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="key"){printf_message("Localization.csv中字段[key]位置不对应");assert(false); return false; }
		if(vecLine[2]!="cn"){printf_message("Localization.csv中字段[cn]位置不对应");assert(false); return false; }
		if(vecLine[3]!="en"){printf_message("Localization.csv中字段[en]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			LocalizationElement	member;

						member.id=atoi(vecLine[0].c_str());
			member.key=vecLine[1];
			member.cn=vecLine[2];
			member.en=vecLine[3];


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
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
			printf_message("Localization.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Localization.csv中字段[id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="key"){printf_message("Localization.csv中字段[key]位置不对应");assert(false); return false; }
		if(vecLine[2]!="cn"){printf_message("Localization.csv中字段[cn]位置不对应");assert(false); return false; }
		if(vecLine[3]!="en"){printf_message("Localization.csv中字段[en]位置不对应");assert(false); return false; }

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
			LocalizationElement	member;
			member.id=atoi(vecLine[0].c_str());
			member.key=vecLine[1];
			member.cn=vecLine[2];
			member.en=vecLine[3];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
