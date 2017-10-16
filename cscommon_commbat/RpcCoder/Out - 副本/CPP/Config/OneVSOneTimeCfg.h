#ifndef __ONEVSONETIME_CONFIG_H
#define __ONEVSONETIME_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//排名时间脜盲脰脙脢媒戮脻陆谩鹿鹿
struct OneVSOneTimeElement
{
	friend class OneVSOneTimeTable;
	int ID;                      	//编号	等级
	int Monty;                   	//月份	每月-1为忽略月份
	int Day;                     	//日期	每天就是-1 0是周日6是周六
	int Hour;                    	//小时	小时
	int Min;                     	//分钟	分钟

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
	OneVSOneTimeElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//排名时间脜盲脰脙路芒脳掳脌脿
class OneVSOneTimeTable
{
	friend class TableData;
private:
	OneVSOneTimeTable(){}
	~OneVSOneTimeTable(){}
	map<int, OneVSOneTimeElement>	m_mapElements;
	vector<OneVSOneTimeElement>	m_vecAllElements;
	OneVSOneTimeElement m_emptyItem;
public:
	static OneVSOneTimeTable& Instance()
	{
		static OneVSOneTimeTable sInstance;
		return sInstance;
	}

	OneVSOneTimeElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<OneVSOneTimeElement>&	GetAllElement()
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
		return LoadJson("OneVSOneTime.json");
		#else
		string strTableContent;
		if( LoadConfigContent("OneVSOneTime.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("OneVSOneTime.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[OneVSOneTime.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("OneVSOneTime.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Monty"){printf_message("OneVSOneTime.csv中字段[Monty]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Day"){printf_message("OneVSOneTime.csv中字段[Day]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Hour"){printf_message("OneVSOneTime.csv中字段[Hour]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Min"){printf_message("OneVSOneTime.csv中字段[Min]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			OneVSOneTimeElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Monty=atoi(vecLine[1].c_str());
			member.Day=atoi(vecLine[2].c_str());
			member.Hour=atoi(vecLine[3].c_str());
			member.Min=atoi(vecLine[4].c_str());


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
			printf_message("OneVSOneTime.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("OneVSOneTime.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Monty"){printf_message("OneVSOneTime.csv中字段[Monty]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Day"){printf_message("OneVSOneTime.csv中字段[Day]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Hour"){printf_message("OneVSOneTime.csv中字段[Hour]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Min"){printf_message("OneVSOneTime.csv中字段[Min]位置不对应");assert(false); return false; }

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
			OneVSOneTimeElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Monty=atoi(vecLine[1].c_str());
			member.Day=atoi(vecLine[2].c_str());
			member.Hour=atoi(vecLine[3].c_str());
			member.Min=atoi(vecLine[4].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
