#ifndef __EXPANDAI_CONFIG_H
#define __EXPANDAI_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//扩展AI脜盲脰脙脢媒戮脻陆谩鹿鹿
struct ExpandAIElement
{
	friend class ExpandAITable;
	int expendAiId;              	//扩展AIID	扩展AIID
	string Comment;              	//AI说明	AI具体描述(策划用字段，不会导出)
	int aiGroup;                 	//AI组	AI组，一个怪用一组扩展AI
	int TriggerType;             	//触发器类型	触发器的类型（1.当前血量小于等于某个数额 2.当前血量低于总血量的某个百分比 3.当怪物所在的地图内的玩家挂有某个任务的时候 4.当怪物警戒范围内的玩家使用某个技能的时候 5.当怪物警戒范围内的玩家在聊天窗中打出某几个字的时候 6.当玩家与怪物的距离低于多少米的时候 7.当同屏范围的怪物使用某个技能的时候 8.当怪物的战斗时间长于多少秒后 9.当当前节点进行到多少秒后 10.当玩家血量低于总血量的某个百分比）
	string TriggerParameter;     	//触发器参数	触发器的参数，由类型确定参数
	int times;                   	//触发次数	触发次数(-1无限次数）
	float eventRange;            	//事件范围	事件范围（表示逃跑距离、召唤半径）
	int dialogId;                	//对话ID	对话ID
	int HelpScope;               	//呼叫援护范围	呼叫援护的范围，以发出援护请求的目标点为中心，配置数据为半径做的圆
	string HelpMonster;          	//呼叫援护对象	索引MonsterTable,填入的是MonsterID，可以填入多个，逗号分隔
	int Order;                   	//呼援是否为强制	1是，0否.如果为否，则目标只有处于待机状态下才会相应援护
	int UseSkill;                	//触发指定技能	触发指定的技能
	int JumpAI;                  	//跳转AI	跳转到新的基础AIID上
	int JumpNPC;                 	//跳转NPC	转换为新的NPC
	string SpecialEvent;         	//触发特殊事件	特殊事件直接写入接口名称
	int EventProbability;        	//触发特殊事件概率	触发该特殊事件概率
	int FleeSpeed;               	//逃跑速度	逃跑时的速度，单位m/s

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
	ExpandAIElement()
	{
		expendAiId = -1;
		m_bIsValidate=false;
	}
};

//扩展AI脜盲脰脙路芒脳掳脌脿
class ExpandAITable
{
	friend class TableData;
private:
	ExpandAITable(){}
	~ExpandAITable(){}
	map<int, ExpandAIElement>	m_mapElements;
	vector<ExpandAIElement>	m_vecAllElements;
	ExpandAIElement m_emptyItem;
public:
	static ExpandAITable& Instance()
	{
		static ExpandAITable sInstance;
		return sInstance;
	}

	ExpandAIElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ExpandAIElement>&	GetAllElement()
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
		return LoadJson("ExpandAI.json");
		#else
		string strTableContent;
		if( LoadConfigContent("ExpandAI.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ExpandAI.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[ExpandAI.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="expendAiId"){printf_message("ExpandAI.csv中字段[expendAiId]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Comment"){printf_message("ExpandAI.csv中字段[Comment]位置不对应");assert(false); return false; }
		if(vecLine[2]!="aiGroup"){printf_message("ExpandAI.csv中字段[aiGroup]位置不对应");assert(false); return false; }
		if(vecLine[3]!="TriggerType"){printf_message("ExpandAI.csv中字段[TriggerType]位置不对应");assert(false); return false; }
		if(vecLine[4]!="TriggerParameter"){printf_message("ExpandAI.csv中字段[TriggerParameter]位置不对应");assert(false); return false; }
		if(vecLine[5]!="times"){printf_message("ExpandAI.csv中字段[times]位置不对应");assert(false); return false; }
		if(vecLine[6]!="eventRange"){printf_message("ExpandAI.csv中字段[eventRange]位置不对应");assert(false); return false; }
		if(vecLine[7]!="dialogId"){printf_message("ExpandAI.csv中字段[dialogId]位置不对应");assert(false); return false; }
		if(vecLine[8]!="HelpScope"){printf_message("ExpandAI.csv中字段[HelpScope]位置不对应");assert(false); return false; }
		if(vecLine[9]!="HelpMonster"){printf_message("ExpandAI.csv中字段[HelpMonster]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Order"){printf_message("ExpandAI.csv中字段[Order]位置不对应");assert(false); return false; }
		if(vecLine[11]!="UseSkill"){printf_message("ExpandAI.csv中字段[UseSkill]位置不对应");assert(false); return false; }
		if(vecLine[12]!="JumpAI"){printf_message("ExpandAI.csv中字段[JumpAI]位置不对应");assert(false); return false; }
		if(vecLine[13]!="JumpNPC"){printf_message("ExpandAI.csv中字段[JumpNPC]位置不对应");assert(false); return false; }
		if(vecLine[14]!="SpecialEvent"){printf_message("ExpandAI.csv中字段[SpecialEvent]位置不对应");assert(false); return false; }
		if(vecLine[15]!="EventProbability"){printf_message("ExpandAI.csv中字段[EventProbability]位置不对应");assert(false); return false; }
		if(vecLine[16]!="FleeSpeed"){printf_message("ExpandAI.csv中字段[FleeSpeed]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			ExpandAIElement	member;

						member.expendAiId=atoi(vecLine[0].c_str());
			member.Comment=vecLine[1];
			member.aiGroup=atoi(vecLine[2].c_str());
			member.TriggerType=atoi(vecLine[3].c_str());
			member.TriggerParameter=vecLine[4];
			member.times=atoi(vecLine[5].c_str());
			member.eventRange=atof(vecLine[6].c_str());
			member.dialogId=atoi(vecLine[7].c_str());
			member.HelpScope=atoi(vecLine[8].c_str());
			member.HelpMonster=vecLine[9];
			member.Order=atoi(vecLine[10].c_str());
			member.UseSkill=atoi(vecLine[11].c_str());
			member.JumpAI=atoi(vecLine[12].c_str());
			member.JumpNPC=atoi(vecLine[13].c_str());
			member.SpecialEvent=vecLine[14];
			member.EventProbability=atoi(vecLine[15].c_str());
			member.FleeSpeed=atoi(vecLine[16].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.expendAiId] = member;
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
		if(vecLine.size() != 17)
		{
			printf_message("ExpandAI.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="expendAiId"){printf_message("ExpandAI.csv中字段[expendAiId]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Comment"){printf_message("ExpandAI.csv中字段[Comment]位置不对应");assert(false); return false; }
		if(vecLine[2]!="aiGroup"){printf_message("ExpandAI.csv中字段[aiGroup]位置不对应");assert(false); return false; }
		if(vecLine[3]!="TriggerType"){printf_message("ExpandAI.csv中字段[TriggerType]位置不对应");assert(false); return false; }
		if(vecLine[4]!="TriggerParameter"){printf_message("ExpandAI.csv中字段[TriggerParameter]位置不对应");assert(false); return false; }
		if(vecLine[5]!="times"){printf_message("ExpandAI.csv中字段[times]位置不对应");assert(false); return false; }
		if(vecLine[6]!="eventRange"){printf_message("ExpandAI.csv中字段[eventRange]位置不对应");assert(false); return false; }
		if(vecLine[7]!="dialogId"){printf_message("ExpandAI.csv中字段[dialogId]位置不对应");assert(false); return false; }
		if(vecLine[8]!="HelpScope"){printf_message("ExpandAI.csv中字段[HelpScope]位置不对应");assert(false); return false; }
		if(vecLine[9]!="HelpMonster"){printf_message("ExpandAI.csv中字段[HelpMonster]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Order"){printf_message("ExpandAI.csv中字段[Order]位置不对应");assert(false); return false; }
		if(vecLine[11]!="UseSkill"){printf_message("ExpandAI.csv中字段[UseSkill]位置不对应");assert(false); return false; }
		if(vecLine[12]!="JumpAI"){printf_message("ExpandAI.csv中字段[JumpAI]位置不对应");assert(false); return false; }
		if(vecLine[13]!="JumpNPC"){printf_message("ExpandAI.csv中字段[JumpNPC]位置不对应");assert(false); return false; }
		if(vecLine[14]!="SpecialEvent"){printf_message("ExpandAI.csv中字段[SpecialEvent]位置不对应");assert(false); return false; }
		if(vecLine[15]!="EventProbability"){printf_message("ExpandAI.csv中字段[EventProbability]位置不对应");assert(false); return false; }
		if(vecLine[16]!="FleeSpeed"){printf_message("ExpandAI.csv中字段[FleeSpeed]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)17)
			{
				assert(false);
				return false;
			}
			ExpandAIElement	member;
			member.expendAiId=atoi(vecLine[0].c_str());
			member.Comment=vecLine[1];
			member.aiGroup=atoi(vecLine[2].c_str());
			member.TriggerType=atoi(vecLine[3].c_str());
			member.TriggerParameter=vecLine[4];
			member.times=atoi(vecLine[5].c_str());
			member.eventRange=atof(vecLine[6].c_str());
			member.dialogId=atoi(vecLine[7].c_str());
			member.HelpScope=atoi(vecLine[8].c_str());
			member.HelpMonster=vecLine[9];
			member.Order=atoi(vecLine[10].c_str());
			member.UseSkill=atoi(vecLine[11].c_str());
			member.JumpAI=atoi(vecLine[12].c_str());
			member.JumpNPC=atoi(vecLine[13].c_str());
			member.SpecialEvent=vecLine[14];
			member.EventProbability=atoi(vecLine[15].c_str());
			member.FleeSpeed=atoi(vecLine[16].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.expendAiId] = member;
		}
		return true;
	}
};

#endif
