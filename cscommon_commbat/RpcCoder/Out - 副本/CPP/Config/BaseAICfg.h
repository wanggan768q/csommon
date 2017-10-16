#ifndef __BASEAI_CONFIG_H
#define __BASEAI_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//基础AI脜盲脰脙脢媒戮脻陆谩鹿鹿
struct BaseAIElement
{
	friend class BaseAITable;
	int baseAiId;                	//基础AIID	基础AIID
	string Comment;              	//AI说明	AI具体描述(策划用字段，不会导出)
	int canMove;                 	//可否移动	是否可移动（-1不可，1可移动）
	int attackType;              	//攻击类型	攻击类型：-1不主动攻击，1主动攻击
	int aiCd;                    	//CD时间	AI的CD时间（毫秒）
	int MaxInterval;             	//最大攻击间隔	攻击间隔时间随机范围的最大值，单位毫秒
	int MinInterval;             	//最小攻击间隔	攻击间隔时间随机范围的最小值，单位毫秒
	int SkillInterval;           	//技能释放间隔	非普攻技能的释放间隔（单位，毫秒）
	int MoveProbability;         	//移动概率	间隔期内移动的概率，万分比
	int noAttack;                	//不可被攻击	是否不可被攻击：-1可被攻击，1不可攻击
	int patrolRate;              	//巡逻概率	巡逻概率：-1不巡逻，1--100概率
	int followPortal;            	//跟随传送	是否跟随目标进行传送(-1不跟随,1跟随)
	int counterAttack;           	//可否还击	1还击-1不还击
	int SkillPriority;           	//技能选取优先级	1伤害，2距离，3伤害范围
	int GuardType;               	//警戒方式	1仅身前，2身前身后都有
	int GuardScope;              	//警戒范围	以角色为原点做出的直线长度，单位m
	int ReturnSpeed;             	//回归速度	BUFFID,如果-1则没有回归
	int RaidScope;               	//追击范围	出生点为起始点，单位m
	int BloodReturn;             	//脱战回血速度	n/s
	int InterveneSkill;          	//应援技能	技能ID
	int ExpandAI;                	//拓展AI	拓展AI组ID

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
	BaseAIElement()
	{
		baseAiId = -1;
		m_bIsValidate=false;
	}
};

//基础AI脜盲脰脙路芒脳掳脌脿
class BaseAITable
{
	friend class TableData;
private:
	BaseAITable(){}
	~BaseAITable(){}
	map<int, BaseAIElement>	m_mapElements;
	vector<BaseAIElement>	m_vecAllElements;
	BaseAIElement m_emptyItem;
public:
	static BaseAITable& Instance()
	{
		static BaseAITable sInstance;
		return sInstance;
	}

	BaseAIElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BaseAIElement>&	GetAllElement()
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
		return LoadJson("BaseAI.json");
		#else
		string strTableContent;
		if( LoadConfigContent("BaseAI.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("BaseAI.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[BaseAI.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="baseAiId"){printf_message("BaseAI.csv中字段[baseAiId]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Comment"){printf_message("BaseAI.csv中字段[Comment]位置不对应");assert(false); return false; }
		if(vecLine[2]!="canMove"){printf_message("BaseAI.csv中字段[canMove]位置不对应");assert(false); return false; }
		if(vecLine[3]!="attackType"){printf_message("BaseAI.csv中字段[attackType]位置不对应");assert(false); return false; }
		if(vecLine[4]!="aiCd"){printf_message("BaseAI.csv中字段[aiCd]位置不对应");assert(false); return false; }
		if(vecLine[5]!="MaxInterval"){printf_message("BaseAI.csv中字段[MaxInterval]位置不对应");assert(false); return false; }
		if(vecLine[6]!="MinInterval"){printf_message("BaseAI.csv中字段[MinInterval]位置不对应");assert(false); return false; }
		if(vecLine[7]!="SkillInterval"){printf_message("BaseAI.csv中字段[SkillInterval]位置不对应");assert(false); return false; }
		if(vecLine[8]!="MoveProbability"){printf_message("BaseAI.csv中字段[MoveProbability]位置不对应");assert(false); return false; }
		if(vecLine[9]!="noAttack"){printf_message("BaseAI.csv中字段[noAttack]位置不对应");assert(false); return false; }
		if(vecLine[10]!="patrolRate"){printf_message("BaseAI.csv中字段[patrolRate]位置不对应");assert(false); return false; }
		if(vecLine[11]!="followPortal"){printf_message("BaseAI.csv中字段[followPortal]位置不对应");assert(false); return false; }
		if(vecLine[12]!="counterAttack"){printf_message("BaseAI.csv中字段[counterAttack]位置不对应");assert(false); return false; }
		if(vecLine[13]!="SkillPriority"){printf_message("BaseAI.csv中字段[SkillPriority]位置不对应");assert(false); return false; }
		if(vecLine[14]!="GuardType"){printf_message("BaseAI.csv中字段[GuardType]位置不对应");assert(false); return false; }
		if(vecLine[15]!="GuardScope"){printf_message("BaseAI.csv中字段[GuardScope]位置不对应");assert(false); return false; }
		if(vecLine[16]!="ReturnSpeed"){printf_message("BaseAI.csv中字段[ReturnSpeed]位置不对应");assert(false); return false; }
		if(vecLine[17]!="RaidScope"){printf_message("BaseAI.csv中字段[RaidScope]位置不对应");assert(false); return false; }
		if(vecLine[18]!="BloodReturn"){printf_message("BaseAI.csv中字段[BloodReturn]位置不对应");assert(false); return false; }
		if(vecLine[19]!="InterveneSkill"){printf_message("BaseAI.csv中字段[InterveneSkill]位置不对应");assert(false); return false; }
		if(vecLine[20]!="ExpandAI"){printf_message("BaseAI.csv中字段[ExpandAI]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			BaseAIElement	member;

						member.baseAiId=atoi(vecLine[0].c_str());
			member.Comment=vecLine[1];
			member.canMove=atoi(vecLine[2].c_str());
			member.attackType=atoi(vecLine[3].c_str());
			member.aiCd=atoi(vecLine[4].c_str());
			member.MaxInterval=atoi(vecLine[5].c_str());
			member.MinInterval=atoi(vecLine[6].c_str());
			member.SkillInterval=atoi(vecLine[7].c_str());
			member.MoveProbability=atoi(vecLine[8].c_str());
			member.noAttack=atoi(vecLine[9].c_str());
			member.patrolRate=atoi(vecLine[10].c_str());
			member.followPortal=atoi(vecLine[11].c_str());
			member.counterAttack=atoi(vecLine[12].c_str());
			member.SkillPriority=atoi(vecLine[13].c_str());
			member.GuardType=atoi(vecLine[14].c_str());
			member.GuardScope=atoi(vecLine[15].c_str());
			member.ReturnSpeed=atoi(vecLine[16].c_str());
			member.RaidScope=atoi(vecLine[17].c_str());
			member.BloodReturn=atoi(vecLine[18].c_str());
			member.InterveneSkill=atoi(vecLine[19].c_str());
			member.ExpandAI=atoi(vecLine[20].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.baseAiId] = member;
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
		if(vecLine.size() != 21)
		{
			printf_message("BaseAI.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="baseAiId"){printf_message("BaseAI.csv中字段[baseAiId]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Comment"){printf_message("BaseAI.csv中字段[Comment]位置不对应");assert(false); return false; }
		if(vecLine[2]!="canMove"){printf_message("BaseAI.csv中字段[canMove]位置不对应");assert(false); return false; }
		if(vecLine[3]!="attackType"){printf_message("BaseAI.csv中字段[attackType]位置不对应");assert(false); return false; }
		if(vecLine[4]!="aiCd"){printf_message("BaseAI.csv中字段[aiCd]位置不对应");assert(false); return false; }
		if(vecLine[5]!="MaxInterval"){printf_message("BaseAI.csv中字段[MaxInterval]位置不对应");assert(false); return false; }
		if(vecLine[6]!="MinInterval"){printf_message("BaseAI.csv中字段[MinInterval]位置不对应");assert(false); return false; }
		if(vecLine[7]!="SkillInterval"){printf_message("BaseAI.csv中字段[SkillInterval]位置不对应");assert(false); return false; }
		if(vecLine[8]!="MoveProbability"){printf_message("BaseAI.csv中字段[MoveProbability]位置不对应");assert(false); return false; }
		if(vecLine[9]!="noAttack"){printf_message("BaseAI.csv中字段[noAttack]位置不对应");assert(false); return false; }
		if(vecLine[10]!="patrolRate"){printf_message("BaseAI.csv中字段[patrolRate]位置不对应");assert(false); return false; }
		if(vecLine[11]!="followPortal"){printf_message("BaseAI.csv中字段[followPortal]位置不对应");assert(false); return false; }
		if(vecLine[12]!="counterAttack"){printf_message("BaseAI.csv中字段[counterAttack]位置不对应");assert(false); return false; }
		if(vecLine[13]!="SkillPriority"){printf_message("BaseAI.csv中字段[SkillPriority]位置不对应");assert(false); return false; }
		if(vecLine[14]!="GuardType"){printf_message("BaseAI.csv中字段[GuardType]位置不对应");assert(false); return false; }
		if(vecLine[15]!="GuardScope"){printf_message("BaseAI.csv中字段[GuardScope]位置不对应");assert(false); return false; }
		if(vecLine[16]!="ReturnSpeed"){printf_message("BaseAI.csv中字段[ReturnSpeed]位置不对应");assert(false); return false; }
		if(vecLine[17]!="RaidScope"){printf_message("BaseAI.csv中字段[RaidScope]位置不对应");assert(false); return false; }
		if(vecLine[18]!="BloodReturn"){printf_message("BaseAI.csv中字段[BloodReturn]位置不对应");assert(false); return false; }
		if(vecLine[19]!="InterveneSkill"){printf_message("BaseAI.csv中字段[InterveneSkill]位置不对应");assert(false); return false; }
		if(vecLine[20]!="ExpandAI"){printf_message("BaseAI.csv中字段[ExpandAI]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)21)
			{
				assert(false);
				return false;
			}
			BaseAIElement	member;
			member.baseAiId=atoi(vecLine[0].c_str());
			member.Comment=vecLine[1];
			member.canMove=atoi(vecLine[2].c_str());
			member.attackType=atoi(vecLine[3].c_str());
			member.aiCd=atoi(vecLine[4].c_str());
			member.MaxInterval=atoi(vecLine[5].c_str());
			member.MinInterval=atoi(vecLine[6].c_str());
			member.SkillInterval=atoi(vecLine[7].c_str());
			member.MoveProbability=atoi(vecLine[8].c_str());
			member.noAttack=atoi(vecLine[9].c_str());
			member.patrolRate=atoi(vecLine[10].c_str());
			member.followPortal=atoi(vecLine[11].c_str());
			member.counterAttack=atoi(vecLine[12].c_str());
			member.SkillPriority=atoi(vecLine[13].c_str());
			member.GuardType=atoi(vecLine[14].c_str());
			member.GuardScope=atoi(vecLine[15].c_str());
			member.ReturnSpeed=atoi(vecLine[16].c_str());
			member.RaidScope=atoi(vecLine[17].c_str());
			member.BloodReturn=atoi(vecLine[18].c_str());
			member.InterveneSkill=atoi(vecLine[19].c_str());
			member.ExpandAI=atoi(vecLine[20].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.baseAiId] = member;
		}
		return true;
	}
};

#endif
