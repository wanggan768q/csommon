#ifndef __RANDOMNAME_CONFIG_H
#define __RANDOMNAME_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//随机名字脜盲脰脙脢媒戮脻陆谩鹿鹿
struct RandomNameElement
{
	friend class RandomNameTable;
	int ID;                      	//编号	等级
	string LastName;             	//姓	姓
	string FirstName;            	//名	名
	string Symbol;               	//符号	符号
	int gender;                  	//性别（1男,2女,3通用）	性别（1男,2女,3通用）

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
	RandomNameElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//随机名字脜盲脰脙路芒脳掳脌脿
class RandomNameTable
{
	friend class TableData;
private:
	RandomNameTable(){}
	~RandomNameTable(){}
	map<int, RandomNameElement>	m_mapElements;
	vector<RandomNameElement>	m_vecAllElements;
	RandomNameElement m_emptyItem;
public:
	static RandomNameTable& Instance()
	{
		static RandomNameTable sInstance;
		return sInstance;
	}

	RandomNameElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<RandomNameElement>&	GetAllElement()
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
		return LoadJson("RandomName.json");
		#else
		string strTableContent;
		if( LoadConfigContent("RandomName.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("RandomName.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[RandomName.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("RandomName.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="LastName"){printf_message("RandomName.csv中字段[LastName]位置不对应");assert(false); return false; }
		if(vecLine[2]!="FirstName"){printf_message("RandomName.csv中字段[FirstName]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Symbol"){printf_message("RandomName.csv中字段[Symbol]位置不对应");assert(false); return false; }
		if(vecLine[4]!="gender"){printf_message("RandomName.csv中字段[gender]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			RandomNameElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.LastName=vecLine[1];
			member.FirstName=vecLine[2];
			member.Symbol=vecLine[3];
			member.gender=atoi(vecLine[4].c_str());


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
			printf_message("RandomName.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("RandomName.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="LastName"){printf_message("RandomName.csv中字段[LastName]位置不对应");assert(false); return false; }
		if(vecLine[2]!="FirstName"){printf_message("RandomName.csv中字段[FirstName]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Symbol"){printf_message("RandomName.csv中字段[Symbol]位置不对应");assert(false); return false; }
		if(vecLine[4]!="gender"){printf_message("RandomName.csv中字段[gender]位置不对应");assert(false); return false; }

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
			RandomNameElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.LastName=vecLine[1];
			member.FirstName=vecLine[2];
			member.Symbol=vecLine[3];
			member.gender=atoi(vecLine[4].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
