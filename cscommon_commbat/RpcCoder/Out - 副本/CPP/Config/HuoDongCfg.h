#ifndef __HUODONG_CONFIG_H
#define __HUODONG_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//活动日常脜盲脰脙脢媒戮脻陆谩鹿鹿
struct HuoDongElement
{
	friend class HuoDongTable;
	int ID;                      	//活动ID	编号
	string Name;                 	//活动名称	活动名称
	string Tips;                 	//活动描述	活动描述
	string SourceIcon;           	//活动图标	活动图标
	int CiShu;                   	//挑战次数	挑战次数
	int Next;                    	//是否可继续挑战	1可以 -1不可以
	int LV;                      	//挑战等级	挑战等级
	int Type;                    	//任务形式	1单人任务 2组队任务 3 单人/组队
	int Title;                   	//活动标签	1日常 2节日
	int HuoLi;                   	//单次挑战活力值	单次挑战活力值
	string Day;                  	//开放日期	1周一2周二3周三4周四5周五6周六7星期天8全天
	string StartTime;            	//挑战开始时间	挑战开始时间
	string EndTime;              	//挑战结束时间	挑战结束时间
	int Reward;                  	//活动奖励	活动奖励
	int In;                      	//入口ID	入口ID
	int NPC;                     	//关联NPC	关联NPC
	int Team;                    	//相关组队ID	相关组队ID
	string XunLu;                	//自动寻路导航	自动寻路导航
	int TimeLimit;               	//时间限制	1有限制-1无限制
	int Prompt;                  	//功能开启是否需要提示	功能开启是否需要提示
	int DanCi;                   	//单次获得活力	单次获得活力
	int DailyLimit;              	//每日活力上限	每日活力上限

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
	HuoDongElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//活动日常脜盲脰脙路芒脳掳脌脿
class HuoDongTable
{
	friend class TableData;
private:
	HuoDongTable(){}
	~HuoDongTable(){}
	map<int, HuoDongElement>	m_mapElements;
	vector<HuoDongElement>	m_vecAllElements;
	HuoDongElement m_emptyItem;
public:
	static HuoDongTable& Instance()
	{
		static HuoDongTable sInstance;
		return sInstance;
	}

	HuoDongElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<HuoDongElement>&	GetAllElement()
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
		return LoadJson("HuoDong.json");
		#else
		string strTableContent;
		if( LoadConfigContent("HuoDong.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("HuoDong.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[HuoDong.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("HuoDong.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("HuoDong.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Tips"){printf_message("HuoDong.csv中字段[Tips]位置不对应");assert(false); return false; }
		if(vecLine[3]!="SourceIcon"){printf_message("HuoDong.csv中字段[SourceIcon]位置不对应");assert(false); return false; }
		if(vecLine[4]!="CiShu"){printf_message("HuoDong.csv中字段[CiShu]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Next"){printf_message("HuoDong.csv中字段[Next]位置不对应");assert(false); return false; }
		if(vecLine[6]!="LV"){printf_message("HuoDong.csv中字段[LV]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Type"){printf_message("HuoDong.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Title"){printf_message("HuoDong.csv中字段[Title]位置不对应");assert(false); return false; }
		if(vecLine[9]!="HuoLi"){printf_message("HuoDong.csv中字段[HuoLi]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Day"){printf_message("HuoDong.csv中字段[Day]位置不对应");assert(false); return false; }
		if(vecLine[11]!="StartTime"){printf_message("HuoDong.csv中字段[StartTime]位置不对应");assert(false); return false; }
		if(vecLine[12]!="EndTime"){printf_message("HuoDong.csv中字段[EndTime]位置不对应");assert(false); return false; }
		if(vecLine[13]!="Reward"){printf_message("HuoDong.csv中字段[Reward]位置不对应");assert(false); return false; }
		if(vecLine[14]!="In"){printf_message("HuoDong.csv中字段[In]位置不对应");assert(false); return false; }
		if(vecLine[15]!="NPC"){printf_message("HuoDong.csv中字段[NPC]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Team"){printf_message("HuoDong.csv中字段[Team]位置不对应");assert(false); return false; }
		if(vecLine[17]!="XunLu"){printf_message("HuoDong.csv中字段[XunLu]位置不对应");assert(false); return false; }
		if(vecLine[18]!="TimeLimit"){printf_message("HuoDong.csv中字段[TimeLimit]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Prompt"){printf_message("HuoDong.csv中字段[Prompt]位置不对应");assert(false); return false; }
		if(vecLine[20]!="DanCi"){printf_message("HuoDong.csv中字段[DanCi]位置不对应");assert(false); return false; }
		if(vecLine[21]!="DailyLimit"){printf_message("HuoDong.csv中字段[DailyLimit]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			HuoDongElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Tips=vecLine[2];
			member.SourceIcon=vecLine[3];
			member.CiShu=atoi(vecLine[4].c_str());
			member.Next=atoi(vecLine[5].c_str());
			member.LV=atoi(vecLine[6].c_str());
			member.Type=atoi(vecLine[7].c_str());
			member.Title=atoi(vecLine[8].c_str());
			member.HuoLi=atoi(vecLine[9].c_str());
			member.Day=vecLine[10];
			member.StartTime=vecLine[11];
			member.EndTime=vecLine[12];
			member.Reward=atoi(vecLine[13].c_str());
			member.In=atoi(vecLine[14].c_str());
			member.NPC=atoi(vecLine[15].c_str());
			member.Team=atoi(vecLine[16].c_str());
			member.XunLu=vecLine[17];
			member.TimeLimit=atoi(vecLine[18].c_str());
			member.Prompt=atoi(vecLine[19].c_str());
			member.DanCi=atoi(vecLine[20].c_str());
			member.DailyLimit=atoi(vecLine[21].c_str());


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
		if(vecLine.size() != 22)
		{
			printf_message("HuoDong.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("HuoDong.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("HuoDong.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Tips"){printf_message("HuoDong.csv中字段[Tips]位置不对应");assert(false); return false; }
		if(vecLine[3]!="SourceIcon"){printf_message("HuoDong.csv中字段[SourceIcon]位置不对应");assert(false); return false; }
		if(vecLine[4]!="CiShu"){printf_message("HuoDong.csv中字段[CiShu]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Next"){printf_message("HuoDong.csv中字段[Next]位置不对应");assert(false); return false; }
		if(vecLine[6]!="LV"){printf_message("HuoDong.csv中字段[LV]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Type"){printf_message("HuoDong.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Title"){printf_message("HuoDong.csv中字段[Title]位置不对应");assert(false); return false; }
		if(vecLine[9]!="HuoLi"){printf_message("HuoDong.csv中字段[HuoLi]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Day"){printf_message("HuoDong.csv中字段[Day]位置不对应");assert(false); return false; }
		if(vecLine[11]!="StartTime"){printf_message("HuoDong.csv中字段[StartTime]位置不对应");assert(false); return false; }
		if(vecLine[12]!="EndTime"){printf_message("HuoDong.csv中字段[EndTime]位置不对应");assert(false); return false; }
		if(vecLine[13]!="Reward"){printf_message("HuoDong.csv中字段[Reward]位置不对应");assert(false); return false; }
		if(vecLine[14]!="In"){printf_message("HuoDong.csv中字段[In]位置不对应");assert(false); return false; }
		if(vecLine[15]!="NPC"){printf_message("HuoDong.csv中字段[NPC]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Team"){printf_message("HuoDong.csv中字段[Team]位置不对应");assert(false); return false; }
		if(vecLine[17]!="XunLu"){printf_message("HuoDong.csv中字段[XunLu]位置不对应");assert(false); return false; }
		if(vecLine[18]!="TimeLimit"){printf_message("HuoDong.csv中字段[TimeLimit]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Prompt"){printf_message("HuoDong.csv中字段[Prompt]位置不对应");assert(false); return false; }
		if(vecLine[20]!="DanCi"){printf_message("HuoDong.csv中字段[DanCi]位置不对应");assert(false); return false; }
		if(vecLine[21]!="DailyLimit"){printf_message("HuoDong.csv中字段[DailyLimit]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)22)
			{
				assert(false);
				return false;
			}
			HuoDongElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Tips=vecLine[2];
			member.SourceIcon=vecLine[3];
			member.CiShu=atoi(vecLine[4].c_str());
			member.Next=atoi(vecLine[5].c_str());
			member.LV=atoi(vecLine[6].c_str());
			member.Type=atoi(vecLine[7].c_str());
			member.Title=atoi(vecLine[8].c_str());
			member.HuoLi=atoi(vecLine[9].c_str());
			member.Day=vecLine[10];
			member.StartTime=vecLine[11];
			member.EndTime=vecLine[12];
			member.Reward=atoi(vecLine[13].c_str());
			member.In=atoi(vecLine[14].c_str());
			member.NPC=atoi(vecLine[15].c_str());
			member.Team=atoi(vecLine[16].c_str());
			member.XunLu=vecLine[17];
			member.TimeLimit=atoi(vecLine[18].c_str());
			member.Prompt=atoi(vecLine[19].c_str());
			member.DanCi=atoi(vecLine[20].c_str());
			member.DailyLimit=atoi(vecLine[21].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
