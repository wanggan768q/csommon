#ifndef __TRAP_CONFIG_H
#define __TRAP_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//陷阱表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct TrapElement
{
	friend class TrapTable;
	int TrapID;                  	//陷阱ID	陷阱ID
	string AblityID;             	//陷阱表现	索引陷阱资源
	int TriggerType;             	//触发器类型	触发器的类型
	string TriggerParameter1;    	//触发器参数1	触发器参数1
	string TriggerParameter2;    	//触发器参数2	触发器参数2
	int Times;                   	//可触发次数	陷阱可触发的次数
	int BuffID;                  	//BUFFID	陷进触发后造成的效果

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
	TrapElement()
	{
		TrapID = -1;
		m_bIsValidate=false;
	}
};

//陷阱表脜盲脰脙路芒脳掳脌脿
class TrapTable
{
	friend class TableData;
private:
	TrapTable(){}
	~TrapTable(){}
	map<int, TrapElement>	m_mapElements;
	vector<TrapElement>	m_vecAllElements;
	TrapElement m_emptyItem;
public:
	static TrapTable& Instance()
	{
		static TrapTable sInstance;
		return sInstance;
	}

	TrapElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<TrapElement>&	GetAllElement()
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
		return LoadJson("Trap.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Trap.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Trap.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Trap.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="TrapID"){printf_message("Trap.csv中字段[TrapID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="AblityID"){printf_message("Trap.csv中字段[AblityID]位置不对应");assert(false); return false; }
		if(vecLine[2]!="TriggerType"){printf_message("Trap.csv中字段[TriggerType]位置不对应");assert(false); return false; }
		if(vecLine[3]!="TriggerParameter1"){printf_message("Trap.csv中字段[TriggerParameter1]位置不对应");assert(false); return false; }
		if(vecLine[4]!="TriggerParameter2"){printf_message("Trap.csv中字段[TriggerParameter2]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Times"){printf_message("Trap.csv中字段[Times]位置不对应");assert(false); return false; }
		if(vecLine[6]!="BuffID"){printf_message("Trap.csv中字段[BuffID]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			TrapElement	member;

						member.TrapID=atoi(vecLine[0].c_str());
			member.AblityID=vecLine[1];
			member.TriggerType=atoi(vecLine[2].c_str());
			member.TriggerParameter1=vecLine[3];
			member.TriggerParameter2=vecLine[4];
			member.Times=atoi(vecLine[5].c_str());
			member.BuffID=atoi(vecLine[6].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.TrapID] = member;
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
		if(vecLine.size() != 7)
		{
			printf_message("Trap.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="TrapID"){printf_message("Trap.csv中字段[TrapID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="AblityID"){printf_message("Trap.csv中字段[AblityID]位置不对应");assert(false); return false; }
		if(vecLine[2]!="TriggerType"){printf_message("Trap.csv中字段[TriggerType]位置不对应");assert(false); return false; }
		if(vecLine[3]!="TriggerParameter1"){printf_message("Trap.csv中字段[TriggerParameter1]位置不对应");assert(false); return false; }
		if(vecLine[4]!="TriggerParameter2"){printf_message("Trap.csv中字段[TriggerParameter2]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Times"){printf_message("Trap.csv中字段[Times]位置不对应");assert(false); return false; }
		if(vecLine[6]!="BuffID"){printf_message("Trap.csv中字段[BuffID]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)7)
			{
				assert(false);
				return false;
			}
			TrapElement	member;
			member.TrapID=atoi(vecLine[0].c_str());
			member.AblityID=vecLine[1];
			member.TriggerType=atoi(vecLine[2].c_str());
			member.TriggerParameter1=vecLine[3];
			member.TriggerParameter2=vecLine[4];
			member.Times=atoi(vecLine[5].c_str());
			member.BuffID=atoi(vecLine[6].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.TrapID] = member;
		}
		return true;
	}
};

#endif
