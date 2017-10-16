#ifndef __REVIVE_CONFIG_H
#define __REVIVE_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//复活表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct ReviveElement
{
	friend class ReviveTable;
	int ID;                      	//编号	等级
	string Name;                 	//说明	显示内容
	string Desc;                 	//描述	描述
	int Type;                    	//复活类型	1 手动复活 2 自动复活 3 原地+回城 4 不能复活
	int Set;                     	//复活点	1 主城 2 当前场景复活点 3 原地 4随机当前场景地点 5大逃杀复活
	int HoldTime;                	//等待操作时间	等待操作时间
	int Time;                    	//等待复活时间	等待复活时间
	int MoneyType;               	//消耗金钱	消耗金钱（对应货币表）
	int XiaoHao;                 	//复活消耗	复活消耗
	int FreeTimes;               	//免费次数	免费次数：-1永久免费 0无免费 N固定次数
	int BuffID;                  	//BUFFID	复活后的状态
	int TeamSharing;             	//TeamSharing	是否共享复活

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
	ReviveElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//复活表脜盲脰脙路芒脳掳脌脿
class ReviveTable
{
	friend class TableData;
private:
	ReviveTable(){}
	~ReviveTable(){}
	map<int, ReviveElement>	m_mapElements;
	vector<ReviveElement>	m_vecAllElements;
	ReviveElement m_emptyItem;
public:
	static ReviveTable& Instance()
	{
		static ReviveTable sInstance;
		return sInstance;
	}

	ReviveElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ReviveElement>&	GetAllElement()
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
		return LoadJson("Revive.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Revive.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Revive.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Revive.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("Revive.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Revive.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Desc"){printf_message("Revive.csv中字段[Desc]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("Revive.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Set"){printf_message("Revive.csv中字段[Set]位置不对应");assert(false); return false; }
		if(vecLine[5]!="HoldTime"){printf_message("Revive.csv中字段[HoldTime]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Time"){printf_message("Revive.csv中字段[Time]位置不对应");assert(false); return false; }
		if(vecLine[7]!="MoneyType"){printf_message("Revive.csv中字段[MoneyType]位置不对应");assert(false); return false; }
		if(vecLine[8]!="XiaoHao"){printf_message("Revive.csv中字段[XiaoHao]位置不对应");assert(false); return false; }
		if(vecLine[9]!="FreeTimes"){printf_message("Revive.csv中字段[FreeTimes]位置不对应");assert(false); return false; }
		if(vecLine[10]!="BuffID"){printf_message("Revive.csv中字段[BuffID]位置不对应");assert(false); return false; }
		if(vecLine[11]!="TeamSharing"){printf_message("Revive.csv中字段[TeamSharing]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			ReviveElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Desc=vecLine[2];
			member.Type=atoi(vecLine[3].c_str());
			member.Set=atoi(vecLine[4].c_str());
			member.HoldTime=atoi(vecLine[5].c_str());
			member.Time=atoi(vecLine[6].c_str());
			member.MoneyType=atoi(vecLine[7].c_str());
			member.XiaoHao=atoi(vecLine[8].c_str());
			member.FreeTimes=atoi(vecLine[9].c_str());
			member.BuffID=atoi(vecLine[10].c_str());
			member.TeamSharing=atoi(vecLine[11].c_str());


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
		if(vecLine.size() != 12)
		{
			printf_message("Revive.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("Revive.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Revive.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Desc"){printf_message("Revive.csv中字段[Desc]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("Revive.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Set"){printf_message("Revive.csv中字段[Set]位置不对应");assert(false); return false; }
		if(vecLine[5]!="HoldTime"){printf_message("Revive.csv中字段[HoldTime]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Time"){printf_message("Revive.csv中字段[Time]位置不对应");assert(false); return false; }
		if(vecLine[7]!="MoneyType"){printf_message("Revive.csv中字段[MoneyType]位置不对应");assert(false); return false; }
		if(vecLine[8]!="XiaoHao"){printf_message("Revive.csv中字段[XiaoHao]位置不对应");assert(false); return false; }
		if(vecLine[9]!="FreeTimes"){printf_message("Revive.csv中字段[FreeTimes]位置不对应");assert(false); return false; }
		if(vecLine[10]!="BuffID"){printf_message("Revive.csv中字段[BuffID]位置不对应");assert(false); return false; }
		if(vecLine[11]!="TeamSharing"){printf_message("Revive.csv中字段[TeamSharing]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)12)
			{
				assert(false);
				return false;
			}
			ReviveElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Desc=vecLine[2];
			member.Type=atoi(vecLine[3].c_str());
			member.Set=atoi(vecLine[4].c_str());
			member.HoldTime=atoi(vecLine[5].c_str());
			member.Time=atoi(vecLine[6].c_str());
			member.MoneyType=atoi(vecLine[7].c_str());
			member.XiaoHao=atoi(vecLine[8].c_str());
			member.FreeTimes=atoi(vecLine[9].c_str());
			member.BuffID=atoi(vecLine[10].c_str());
			member.TeamSharing=atoi(vecLine[11].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
