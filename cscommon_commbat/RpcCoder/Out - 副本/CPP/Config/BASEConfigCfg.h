#ifndef __BASECONFIG_CONFIG_H
#define __BASECONFIG_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//基础配置脜盲脰脙脢媒戮脻陆谩鹿鹿
struct BASEConfigElement
{
	friend class BASEConfigTable;
	int ID;                      	//编号	等级
	string Name;                 	//说明	字段说明
	int Args1;                   	//参数1	参数1
	int Args2;                   	//参数2	参数2

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
	BASEConfigElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//基础配置脜盲脰脙路芒脳掳脌脿
class BASEConfigTable
{
	friend class TableData;
private:
	BASEConfigTable(){}
	~BASEConfigTable(){}
	map<int, BASEConfigElement>	m_mapElements;
	vector<BASEConfigElement>	m_vecAllElements;
	BASEConfigElement m_emptyItem;
public:
	static BASEConfigTable& Instance()
	{
		static BASEConfigTable sInstance;
		return sInstance;
	}

	BASEConfigElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BASEConfigElement>&	GetAllElement()
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
		return LoadJson("BASEConfig.json");
		#else
		string strTableContent;
		if( LoadConfigContent("BASEConfig.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("BASEConfig.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[BASEConfig.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("BASEConfig.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("BASEConfig.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Args1"){printf_message("BASEConfig.csv中字段[Args1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Args2"){printf_message("BASEConfig.csv中字段[Args2]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			BASEConfigElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Args1=atoi(vecLine[2].c_str());
			member.Args2=atoi(vecLine[3].c_str());


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
			printf_message("BASEConfig.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("BASEConfig.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("BASEConfig.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Args1"){printf_message("BASEConfig.csv中字段[Args1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Args2"){printf_message("BASEConfig.csv中字段[Args2]位置不对应");assert(false); return false; }

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
			BASEConfigElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Args1=atoi(vecLine[2].c_str());
			member.Args2=atoi(vecLine[3].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
