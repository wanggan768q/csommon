#ifndef __SENSITIVEWORD_CONFIG_H
#define __SENSITIVEWORD_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//敏感字库脜盲脰脙脢媒戮脻陆谩鹿鹿
struct SensitiveWordElement
{
	friend class SensitiveWordTable;
	int ID;                      	//ID	ID
	string Word;                 	//敏感字	敏感字

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
	SensitiveWordElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//敏感字库脜盲脰脙路芒脳掳脌脿
class SensitiveWordTable
{
	friend class TableData;
private:
	SensitiveWordTable(){}
	~SensitiveWordTable(){}
	map<int, SensitiveWordElement>	m_mapElements;
	vector<SensitiveWordElement>	m_vecAllElements;
	SensitiveWordElement m_emptyItem;
public:
	static SensitiveWordTable& Instance()
	{
		static SensitiveWordTable sInstance;
		return sInstance;
	}

	SensitiveWordElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SensitiveWordElement>&	GetAllElement()
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
		return LoadJson("SensitiveWord.json");
		#else
		string strTableContent;
		if( LoadConfigContent("SensitiveWord.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("SensitiveWord.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[SensitiveWord.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("SensitiveWord.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Word"){printf_message("SensitiveWord.csv中字段[Word]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			SensitiveWordElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Word=vecLine[1];


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
		if(vecLine.size() != 2)
		{
			printf_message("SensitiveWord.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("SensitiveWord.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Word"){printf_message("SensitiveWord.csv中字段[Word]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)2)
			{
				assert(false);
				return false;
			}
			SensitiveWordElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Word=vecLine[1];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
