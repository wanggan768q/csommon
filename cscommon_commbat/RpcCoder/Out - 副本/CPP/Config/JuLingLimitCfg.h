#ifndef __JULINGLIMIT_CONFIG_H
#define __JULINGLIMIT_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//聚灵限制表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct JuLingLimitElement
{
	friend class JuLingLimitTable;
	int ID;                      	//编号	炼星等级
	int ShangGu;                 	//上古技能数量	上古技能数量
	int PuTong;                  	//普通数量	普通数量
	int Max;                     	//等级上限	等级上限

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
	JuLingLimitElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//聚灵限制表脜盲脰脙路芒脳掳脌脿
class JuLingLimitTable
{
	friend class TableData;
private:
	JuLingLimitTable(){}
	~JuLingLimitTable(){}
	map<int, JuLingLimitElement>	m_mapElements;
	vector<JuLingLimitElement>	m_vecAllElements;
	JuLingLimitElement m_emptyItem;
public:
	static JuLingLimitTable& Instance()
	{
		static JuLingLimitTable sInstance;
		return sInstance;
	}

	JuLingLimitElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<JuLingLimitElement>&	GetAllElement()
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
		return LoadJson("JuLingLimit.json");
		#else
		string strTableContent;
		if( LoadConfigContent("JuLingLimit.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("JuLingLimit.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[JuLingLimit.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("JuLingLimit.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="ShangGu"){printf_message("JuLingLimit.csv中字段[ShangGu]位置不对应");assert(false); return false; }
		if(vecLine[2]!="PuTong"){printf_message("JuLingLimit.csv中字段[PuTong]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Max"){printf_message("JuLingLimit.csv中字段[Max]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			JuLingLimitElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.ShangGu=atoi(vecLine[1].c_str());
			member.PuTong=atoi(vecLine[2].c_str());
			member.Max=atoi(vecLine[3].c_str());


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
		if(vecLine.size() != 4)
		{
			printf_message("JuLingLimit.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("JuLingLimit.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="ShangGu"){printf_message("JuLingLimit.csv中字段[ShangGu]位置不对应");assert(false); return false; }
		if(vecLine[2]!="PuTong"){printf_message("JuLingLimit.csv中字段[PuTong]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Max"){printf_message("JuLingLimit.csv中字段[Max]位置不对应");assert(false); return false; }

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
			JuLingLimitElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.ShangGu=atoi(vecLine[1].c_str());
			member.PuTong=atoi(vecLine[2].c_str());
			member.Max=atoi(vecLine[3].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
