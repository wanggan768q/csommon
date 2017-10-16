#ifndef __SYSTIPS_CONFIG_H
#define __SYSTIPS_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//系统各种提示表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct SysTipsElement
{
	friend class SysTipsTable;
	int ID;                      	//id	索引
	string CN;                   	//中文	中文
	string EN;                   	//英语	英语

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
	SysTipsElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//系统各种提示表脜盲脰脙路芒脳掳脌脿
class SysTipsTable
{
	friend class TableData;
private:
	SysTipsTable(){}
	~SysTipsTable(){}
	map<int, SysTipsElement>	m_mapElements;
	vector<SysTipsElement>	m_vecAllElements;
	SysTipsElement m_emptyItem;
public:
	static SysTipsTable& Instance()
	{
		static SysTipsTable sInstance;
		return sInstance;
	}

	SysTipsElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SysTipsElement>&	GetAllElement()
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
		return LoadJson("SysTips.json");
		#else
		string strTableContent;
		if( LoadConfigContent("SysTips.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("SysTips.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[SysTips.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("SysTips.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="CN"){printf_message("SysTips.csv中字段[CN]位置不对应");assert(false); return false; }
		if(vecLine[2]!="EN"){printf_message("SysTips.csv中字段[EN]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			SysTipsElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.CN=vecLine[1];
			member.EN=vecLine[2];


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
		if(vecLine.size() != 3)
		{
			printf_message("SysTips.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("SysTips.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="CN"){printf_message("SysTips.csv中字段[CN]位置不对应");assert(false); return false; }
		if(vecLine[2]!="EN"){printf_message("SysTips.csv中字段[EN]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)3)
			{
				assert(false);
				return false;
			}
			SysTipsElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.CN=vecLine[1];
			member.EN=vecLine[2];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
