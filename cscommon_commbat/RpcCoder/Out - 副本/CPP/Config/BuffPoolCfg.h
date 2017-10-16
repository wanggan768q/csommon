#ifndef __BUFFPOOL_CONFIG_H
#define __BUFFPOOL_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//BUFF池脜盲脰脙脢媒戮脻陆谩鹿鹿
struct BuffPoolElement
{
	friend class BuffPoolTable;
	int ID;                      	//池子id	池子id
	string POS;                  	//位置信息	x,z,layer
	float TriggerRange;          	//触发区大小	触发区大小（以自身为原点的直径范围，米）
	int RefreshType;             	//刷新类型	刷新类型(1固定时间刷新，2上一个消失之后时间刷新）
	int RefreshCD;               	//刷新时间CD	刷新时间CD，单位毫秒
	int GroupID;                 	//组ID	组ID
	int GroupMaxRefreshCount;    	//组内随机最大刷新个数	组内随机最大刷新个数
	string BuffIDList;           	//BUFF列表	BUFF列表
	string Res;                  	//显示资源	显示资源

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
	BuffPoolElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//BUFF池脜盲脰脙路芒脳掳脌脿
class BuffPoolTable
{
	friend class TableData;
private:
	BuffPoolTable(){}
	~BuffPoolTable(){}
	map<int, BuffPoolElement>	m_mapElements;
	vector<BuffPoolElement>	m_vecAllElements;
	BuffPoolElement m_emptyItem;
public:
	static BuffPoolTable& Instance()
	{
		static BuffPoolTable sInstance;
		return sInstance;
	}

	BuffPoolElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BuffPoolElement>&	GetAllElement()
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
		return LoadJson("BuffPool.json");
		#else
		string strTableContent;
		if( LoadConfigContent("BuffPool.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("BuffPool.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[BuffPool.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("BuffPool.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="POS"){printf_message("BuffPool.csv中字段[POS]位置不对应");assert(false); return false; }
		if(vecLine[2]!="TriggerRange"){printf_message("BuffPool.csv中字段[TriggerRange]位置不对应");assert(false); return false; }
		if(vecLine[3]!="RefreshType"){printf_message("BuffPool.csv中字段[RefreshType]位置不对应");assert(false); return false; }
		if(vecLine[4]!="RefreshCD"){printf_message("BuffPool.csv中字段[RefreshCD]位置不对应");assert(false); return false; }
		if(vecLine[5]!="GroupID"){printf_message("BuffPool.csv中字段[GroupID]位置不对应");assert(false); return false; }
		if(vecLine[6]!="GroupMaxRefreshCount"){printf_message("BuffPool.csv中字段[GroupMaxRefreshCount]位置不对应");assert(false); return false; }
		if(vecLine[7]!="BuffIDList"){printf_message("BuffPool.csv中字段[BuffIDList]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Res"){printf_message("BuffPool.csv中字段[Res]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			BuffPoolElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.POS=vecLine[1];
			member.TriggerRange=atof(vecLine[2].c_str());
			member.RefreshType=atoi(vecLine[3].c_str());
			member.RefreshCD=atoi(vecLine[4].c_str());
			member.GroupID=atoi(vecLine[5].c_str());
			member.GroupMaxRefreshCount=atoi(vecLine[6].c_str());
			member.BuffIDList=vecLine[7];
			member.Res=vecLine[8];


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
		if(vecLine.size() != 9)
		{
			printf_message("BuffPool.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("BuffPool.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="POS"){printf_message("BuffPool.csv中字段[POS]位置不对应");assert(false); return false; }
		if(vecLine[2]!="TriggerRange"){printf_message("BuffPool.csv中字段[TriggerRange]位置不对应");assert(false); return false; }
		if(vecLine[3]!="RefreshType"){printf_message("BuffPool.csv中字段[RefreshType]位置不对应");assert(false); return false; }
		if(vecLine[4]!="RefreshCD"){printf_message("BuffPool.csv中字段[RefreshCD]位置不对应");assert(false); return false; }
		if(vecLine[5]!="GroupID"){printf_message("BuffPool.csv中字段[GroupID]位置不对应");assert(false); return false; }
		if(vecLine[6]!="GroupMaxRefreshCount"){printf_message("BuffPool.csv中字段[GroupMaxRefreshCount]位置不对应");assert(false); return false; }
		if(vecLine[7]!="BuffIDList"){printf_message("BuffPool.csv中字段[BuffIDList]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Res"){printf_message("BuffPool.csv中字段[Res]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)9)
			{
				assert(false);
				return false;
			}
			BuffPoolElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.POS=vecLine[1];
			member.TriggerRange=atof(vecLine[2].c_str());
			member.RefreshType=atoi(vecLine[3].c_str());
			member.RefreshCD=atoi(vecLine[4].c_str());
			member.GroupID=atoi(vecLine[5].c_str());
			member.GroupMaxRefreshCount=atoi(vecLine[6].c_str());
			member.BuffIDList=vecLine[7];
			member.Res=vecLine[8];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
