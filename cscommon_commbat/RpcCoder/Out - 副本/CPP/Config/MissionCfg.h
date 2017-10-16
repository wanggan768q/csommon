#ifndef __MISSION_CONFIG_H
#define __MISSION_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//任务基础表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct MissionElement
{
	friend class MissionTable;
	int MissionID;               	//编号	任务ID
	string Name;                 	//任务名称	任务名称
	int Type;                    	//任务分类	1日常2主线3活动4师门任务5帮会
	string Title;                	//任务标签	任务标签
	int Lv;                      	//任务等级	任务等级
	int Reward;                  	//奖励	奖励
	int TiaoJian;                	//条件	条件
	int JieNpc;                  	//接任务NPC	接任务NPC
	int JiaoNpc;                 	//交任务NPC	交任务NPC
	int Dialog1;                 	//接任务对话	接任务对话
	string Dialog2;              	//接任务面板显示	接任务面板显示
	string Dialog3;              	//交任务面板对话	交任务面板对话
	int IngDialog;               	//未完成时对白	未完成时对白
	string Tips;                 	//任务描述	任务描述
	int Time;                    	//限时	限时
	int Index;                   	//下个任务ID	下个任务ID
	int QianZhi;                 	//前置任务	前置任务
	int Monster;                 	//关联怪物	关联怪物
	int Plant;                   	//关联种植物	关联种植物
	int Npc;                     	//关联NPC	关联NPC
	int FuBen;                   	//关联副本	关联副本
	int FuBenLimit;              	//进入副本限制	1条件 2 条件2 3条件3
	int Target;                  	//任务目标方案	1顺序 2 并列 3 只完成最后目标
	int ZiDong;                  	//自动完成	自动完成
	int TiJiao;                  	//是否自动提交	是否自动提交

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
	MissionElement()
	{
		MissionID = -1;
		m_bIsValidate=false;
	}
};

//任务基础表脜盲脰脙路芒脳掳脌脿
class MissionTable
{
	friend class TableData;
private:
	MissionTable(){}
	~MissionTable(){}
	map<int, MissionElement>	m_mapElements;
	vector<MissionElement>	m_vecAllElements;
	MissionElement m_emptyItem;
public:
	static MissionTable& Instance()
	{
		static MissionTable sInstance;
		return sInstance;
	}

	MissionElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<MissionElement>&	GetAllElement()
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
		return LoadJson("Mission.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Mission.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Mission.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Mission.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="MissionID"){printf_message("Mission.csv中字段[MissionID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Mission.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Type"){printf_message("Mission.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Title"){printf_message("Mission.csv中字段[Title]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Lv"){printf_message("Mission.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Reward"){printf_message("Mission.csv中字段[Reward]位置不对应");assert(false); return false; }
		if(vecLine[6]!="TiaoJian"){printf_message("Mission.csv中字段[TiaoJian]位置不对应");assert(false); return false; }
		if(vecLine[7]!="JieNpc"){printf_message("Mission.csv中字段[JieNpc]位置不对应");assert(false); return false; }
		if(vecLine[8]!="JiaoNpc"){printf_message("Mission.csv中字段[JiaoNpc]位置不对应");assert(false); return false; }
		if(vecLine[9]!="Dialog1"){printf_message("Mission.csv中字段[Dialog1]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Dialog2"){printf_message("Mission.csv中字段[Dialog2]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Dialog3"){printf_message("Mission.csv中字段[Dialog3]位置不对应");assert(false); return false; }
		if(vecLine[12]!="IngDialog"){printf_message("Mission.csv中字段[IngDialog]位置不对应");assert(false); return false; }
		if(vecLine[13]!="Tips"){printf_message("Mission.csv中字段[Tips]位置不对应");assert(false); return false; }
		if(vecLine[14]!="Time"){printf_message("Mission.csv中字段[Time]位置不对应");assert(false); return false; }
		if(vecLine[15]!="Index"){printf_message("Mission.csv中字段[Index]位置不对应");assert(false); return false; }
		if(vecLine[16]!="QianZhi"){printf_message("Mission.csv中字段[QianZhi]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Monster"){printf_message("Mission.csv中字段[Monster]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Plant"){printf_message("Mission.csv中字段[Plant]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Npc"){printf_message("Mission.csv中字段[Npc]位置不对应");assert(false); return false; }
		if(vecLine[20]!="FuBen"){printf_message("Mission.csv中字段[FuBen]位置不对应");assert(false); return false; }
		if(vecLine[21]!="FuBenLimit"){printf_message("Mission.csv中字段[FuBenLimit]位置不对应");assert(false); return false; }
		if(vecLine[22]!="Target"){printf_message("Mission.csv中字段[Target]位置不对应");assert(false); return false; }
		if(vecLine[23]!="ZiDong"){printf_message("Mission.csv中字段[ZiDong]位置不对应");assert(false); return false; }
		if(vecLine[24]!="TiJiao"){printf_message("Mission.csv中字段[TiJiao]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			MissionElement	member;

						member.MissionID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Type=atoi(vecLine[2].c_str());
			member.Title=vecLine[3];
			member.Lv=atoi(vecLine[4].c_str());
			member.Reward=atoi(vecLine[5].c_str());
			member.TiaoJian=atoi(vecLine[6].c_str());
			member.JieNpc=atoi(vecLine[7].c_str());
			member.JiaoNpc=atoi(vecLine[8].c_str());
			member.Dialog1=atoi(vecLine[9].c_str());
			member.Dialog2=vecLine[10];
			member.Dialog3=vecLine[11];
			member.IngDialog=atoi(vecLine[12].c_str());
			member.Tips=vecLine[13];
			member.Time=atoi(vecLine[14].c_str());
			member.Index=atoi(vecLine[15].c_str());
			member.QianZhi=atoi(vecLine[16].c_str());
			member.Monster=atoi(vecLine[17].c_str());
			member.Plant=atoi(vecLine[18].c_str());
			member.Npc=atoi(vecLine[19].c_str());
			member.FuBen=atoi(vecLine[20].c_str());
			member.FuBenLimit=atoi(vecLine[21].c_str());
			member.Target=atoi(vecLine[22].c_str());
			member.ZiDong=atoi(vecLine[23].c_str());
			member.TiJiao=atoi(vecLine[24].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.MissionID] = member;
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
		if(vecLine.size() != 25)
		{
			printf_message("Mission.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="MissionID"){printf_message("Mission.csv中字段[MissionID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Mission.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Type"){printf_message("Mission.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Title"){printf_message("Mission.csv中字段[Title]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Lv"){printf_message("Mission.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Reward"){printf_message("Mission.csv中字段[Reward]位置不对应");assert(false); return false; }
		if(vecLine[6]!="TiaoJian"){printf_message("Mission.csv中字段[TiaoJian]位置不对应");assert(false); return false; }
		if(vecLine[7]!="JieNpc"){printf_message("Mission.csv中字段[JieNpc]位置不对应");assert(false); return false; }
		if(vecLine[8]!="JiaoNpc"){printf_message("Mission.csv中字段[JiaoNpc]位置不对应");assert(false); return false; }
		if(vecLine[9]!="Dialog1"){printf_message("Mission.csv中字段[Dialog1]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Dialog2"){printf_message("Mission.csv中字段[Dialog2]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Dialog3"){printf_message("Mission.csv中字段[Dialog3]位置不对应");assert(false); return false; }
		if(vecLine[12]!="IngDialog"){printf_message("Mission.csv中字段[IngDialog]位置不对应");assert(false); return false; }
		if(vecLine[13]!="Tips"){printf_message("Mission.csv中字段[Tips]位置不对应");assert(false); return false; }
		if(vecLine[14]!="Time"){printf_message("Mission.csv中字段[Time]位置不对应");assert(false); return false; }
		if(vecLine[15]!="Index"){printf_message("Mission.csv中字段[Index]位置不对应");assert(false); return false; }
		if(vecLine[16]!="QianZhi"){printf_message("Mission.csv中字段[QianZhi]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Monster"){printf_message("Mission.csv中字段[Monster]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Plant"){printf_message("Mission.csv中字段[Plant]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Npc"){printf_message("Mission.csv中字段[Npc]位置不对应");assert(false); return false; }
		if(vecLine[20]!="FuBen"){printf_message("Mission.csv中字段[FuBen]位置不对应");assert(false); return false; }
		if(vecLine[21]!="FuBenLimit"){printf_message("Mission.csv中字段[FuBenLimit]位置不对应");assert(false); return false; }
		if(vecLine[22]!="Target"){printf_message("Mission.csv中字段[Target]位置不对应");assert(false); return false; }
		if(vecLine[23]!="ZiDong"){printf_message("Mission.csv中字段[ZiDong]位置不对应");assert(false); return false; }
		if(vecLine[24]!="TiJiao"){printf_message("Mission.csv中字段[TiJiao]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)25)
			{
				assert(false);
				return false;
			}
			MissionElement	member;
			member.MissionID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Type=atoi(vecLine[2].c_str());
			member.Title=vecLine[3];
			member.Lv=atoi(vecLine[4].c_str());
			member.Reward=atoi(vecLine[5].c_str());
			member.TiaoJian=atoi(vecLine[6].c_str());
			member.JieNpc=atoi(vecLine[7].c_str());
			member.JiaoNpc=atoi(vecLine[8].c_str());
			member.Dialog1=atoi(vecLine[9].c_str());
			member.Dialog2=vecLine[10];
			member.Dialog3=vecLine[11];
			member.IngDialog=atoi(vecLine[12].c_str());
			member.Tips=vecLine[13];
			member.Time=atoi(vecLine[14].c_str());
			member.Index=atoi(vecLine[15].c_str());
			member.QianZhi=atoi(vecLine[16].c_str());
			member.Monster=atoi(vecLine[17].c_str());
			member.Plant=atoi(vecLine[18].c_str());
			member.Npc=atoi(vecLine[19].c_str());
			member.FuBen=atoi(vecLine[20].c_str());
			member.FuBenLimit=atoi(vecLine[21].c_str());
			member.Target=atoi(vecLine[22].c_str());
			member.ZiDong=atoi(vecLine[23].c_str());
			member.TiJiao=atoi(vecLine[24].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.MissionID] = member;
		}
		return true;
	}
};

#endif
