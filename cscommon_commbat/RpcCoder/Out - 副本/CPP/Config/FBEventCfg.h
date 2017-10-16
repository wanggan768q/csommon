#ifndef __FBEVENT_CONFIG_H
#define __FBEVENT_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//副本事件脜盲脰脙脢媒戮脻陆谩鹿鹿
struct FBEventElement
{
	friend class FBEventTable;
	int ID;                      	//事件id	事件id
	int TriggerType1;            	//触发类型1	1：时间，2：区域
	int TriggerArgs1;            	//触发参数1	触发参数1
	int TriggerType2;            	//触发类型2	触发类型2
	int TriggerArgs2;            	//触发参数2	触发参数2
	int ContinueTime;            	//持续时间	持续时间
	int EventType;               	//触发事件类型	1：对话，2：AI行为
	int EventArgs;               	//触发事件参数	触发事件参数(ai行为 1.开启AI 2.停止AI)
	int EventTimes;              	//可触发次数	可触发次数
	int Next;                    	//下一个事件id	下一个事件id

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
	FBEventElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//副本事件脜盲脰脙路芒脳掳脌脿
class FBEventTable
{
	friend class TableData;
private:
	FBEventTable(){}
	~FBEventTable(){}
	map<int, FBEventElement>	m_mapElements;
	vector<FBEventElement>	m_vecAllElements;
	FBEventElement m_emptyItem;
public:
	static FBEventTable& Instance()
	{
		static FBEventTable sInstance;
		return sInstance;
	}

	FBEventElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<FBEventElement>&	GetAllElement()
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
		return LoadJson("FBEvent.json");
		#else
		string strTableContent;
		if( LoadConfigContent("FBEvent.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("FBEvent.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[FBEvent.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("FBEvent.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="TriggerType1"){printf_message("FBEvent.csv中字段[TriggerType1]位置不对应");assert(false); return false; }
		if(vecLine[2]!="TriggerArgs1"){printf_message("FBEvent.csv中字段[TriggerArgs1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="TriggerType2"){printf_message("FBEvent.csv中字段[TriggerType2]位置不对应");assert(false); return false; }
		if(vecLine[4]!="TriggerArgs2"){printf_message("FBEvent.csv中字段[TriggerArgs2]位置不对应");assert(false); return false; }
		if(vecLine[5]!="ContinueTime"){printf_message("FBEvent.csv中字段[ContinueTime]位置不对应");assert(false); return false; }
		if(vecLine[6]!="EventType"){printf_message("FBEvent.csv中字段[EventType]位置不对应");assert(false); return false; }
		if(vecLine[7]!="EventArgs"){printf_message("FBEvent.csv中字段[EventArgs]位置不对应");assert(false); return false; }
		if(vecLine[8]!="EventTimes"){printf_message("FBEvent.csv中字段[EventTimes]位置不对应");assert(false); return false; }
		if(vecLine[9]!="Next"){printf_message("FBEvent.csv中字段[Next]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			FBEventElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.TriggerType1=atoi(vecLine[1].c_str());
			member.TriggerArgs1=atoi(vecLine[2].c_str());
			member.TriggerType2=atoi(vecLine[3].c_str());
			member.TriggerArgs2=atoi(vecLine[4].c_str());
			member.ContinueTime=atoi(vecLine[5].c_str());
			member.EventType=atoi(vecLine[6].c_str());
			member.EventArgs=atoi(vecLine[7].c_str());
			member.EventTimes=atoi(vecLine[8].c_str());
			member.Next=atoi(vecLine[9].c_str());


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
		if(vecLine.size() != 10)
		{
			printf_message("FBEvent.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("FBEvent.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="TriggerType1"){printf_message("FBEvent.csv中字段[TriggerType1]位置不对应");assert(false); return false; }
		if(vecLine[2]!="TriggerArgs1"){printf_message("FBEvent.csv中字段[TriggerArgs1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="TriggerType2"){printf_message("FBEvent.csv中字段[TriggerType2]位置不对应");assert(false); return false; }
		if(vecLine[4]!="TriggerArgs2"){printf_message("FBEvent.csv中字段[TriggerArgs2]位置不对应");assert(false); return false; }
		if(vecLine[5]!="ContinueTime"){printf_message("FBEvent.csv中字段[ContinueTime]位置不对应");assert(false); return false; }
		if(vecLine[6]!="EventType"){printf_message("FBEvent.csv中字段[EventType]位置不对应");assert(false); return false; }
		if(vecLine[7]!="EventArgs"){printf_message("FBEvent.csv中字段[EventArgs]位置不对应");assert(false); return false; }
		if(vecLine[8]!="EventTimes"){printf_message("FBEvent.csv中字段[EventTimes]位置不对应");assert(false); return false; }
		if(vecLine[9]!="Next"){printf_message("FBEvent.csv中字段[Next]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)10)
			{
				assert(false);
				return false;
			}
			FBEventElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.TriggerType1=atoi(vecLine[1].c_str());
			member.TriggerArgs1=atoi(vecLine[2].c_str());
			member.TriggerType2=atoi(vecLine[3].c_str());
			member.TriggerArgs2=atoi(vecLine[4].c_str());
			member.ContinueTime=atoi(vecLine[5].c_str());
			member.EventType=atoi(vecLine[6].c_str());
			member.EventArgs=atoi(vecLine[7].c_str());
			member.EventTimes=atoi(vecLine[8].c_str());
			member.Next=atoi(vecLine[9].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
