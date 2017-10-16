#ifndef __ATTACKBEHAVIOR_CONFIG_H
#define __ATTACKBEHAVIOR_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//攻击行为脜盲脰脙脢媒戮脻陆谩鹿鹿
struct AttackBehaviorElement
{
	friend class AttackBehaviorTable;
	int Id;                      	//编号	编号
	int AttackerType;            	//攻击者类型	1我2他3小怪4boss5机关
	int HitterType;              	//受击者类型	1我2他3小怪4boss5机关
	int SkillType;               	//技能类型	1普攻2技能
	int AttackFlash;             	//闪白	1是 0否
	int ShakeCamera;             	//震屏	1是 0否
	int HitIdleAnim;             	//是否待机受击动作	1是 0否
	int HitMoveAnim;             	//是否移动受击动作	1是 0否
	int HitAnim;                 	//是否攻击受击动作	1是 0否
	int AttackBack;              	//是否击退	1是 0否
	int AttackAir;               	//是否浮空	1是 0否
	int AttackWaggle;            	//是否晃动	1是 0否
	int AttackTumble;            	//是否倒地	1是 0否

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
	AttackBehaviorElement()
	{
		Id = -1;
		m_bIsValidate=false;
	}
};

//攻击行为脜盲脰脙路芒脳掳脌脿
class AttackBehaviorTable
{
	friend class TableData;
private:
	AttackBehaviorTable(){}
	~AttackBehaviorTable(){}
	map<int, AttackBehaviorElement>	m_mapElements;
	vector<AttackBehaviorElement>	m_vecAllElements;
	AttackBehaviorElement m_emptyItem;
public:
	static AttackBehaviorTable& Instance()
	{
		static AttackBehaviorTable sInstance;
		return sInstance;
	}

	AttackBehaviorElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<AttackBehaviorElement>&	GetAllElement()
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
		return LoadJson("AttackBehavior.json");
		#else
		string strTableContent;
		if( LoadConfigContent("AttackBehavior.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("AttackBehavior.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[AttackBehavior.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="Id"){printf_message("AttackBehavior.csv中字段[Id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="AttackerType"){printf_message("AttackBehavior.csv中字段[AttackerType]位置不对应");assert(false); return false; }
		if(vecLine[2]!="HitterType"){printf_message("AttackBehavior.csv中字段[HitterType]位置不对应");assert(false); return false; }
		if(vecLine[3]!="SkillType"){printf_message("AttackBehavior.csv中字段[SkillType]位置不对应");assert(false); return false; }
		if(vecLine[4]!="AttackFlash"){printf_message("AttackBehavior.csv中字段[AttackFlash]位置不对应");assert(false); return false; }
		if(vecLine[5]!="ShakeCamera"){printf_message("AttackBehavior.csv中字段[ShakeCamera]位置不对应");assert(false); return false; }
		if(vecLine[6]!="HitIdleAnim"){printf_message("AttackBehavior.csv中字段[HitIdleAnim]位置不对应");assert(false); return false; }
		if(vecLine[7]!="HitMoveAnim"){printf_message("AttackBehavior.csv中字段[HitMoveAnim]位置不对应");assert(false); return false; }
		if(vecLine[8]!="HitAnim"){printf_message("AttackBehavior.csv中字段[HitAnim]位置不对应");assert(false); return false; }
		if(vecLine[9]!="AttackBack"){printf_message("AttackBehavior.csv中字段[AttackBack]位置不对应");assert(false); return false; }
		if(vecLine[10]!="AttackAir"){printf_message("AttackBehavior.csv中字段[AttackAir]位置不对应");assert(false); return false; }
		if(vecLine[11]!="AttackWaggle"){printf_message("AttackBehavior.csv中字段[AttackWaggle]位置不对应");assert(false); return false; }
		if(vecLine[12]!="AttackTumble"){printf_message("AttackBehavior.csv中字段[AttackTumble]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			AttackBehaviorElement	member;

						member.Id=atoi(vecLine[0].c_str());
			member.AttackerType=atoi(vecLine[1].c_str());
			member.HitterType=atoi(vecLine[2].c_str());
			member.SkillType=atoi(vecLine[3].c_str());
			member.AttackFlash=atoi(vecLine[4].c_str());
			member.ShakeCamera=atoi(vecLine[5].c_str());
			member.HitIdleAnim=atoi(vecLine[6].c_str());
			member.HitMoveAnim=atoi(vecLine[7].c_str());
			member.HitAnim=atoi(vecLine[8].c_str());
			member.AttackBack=atoi(vecLine[9].c_str());
			member.AttackAir=atoi(vecLine[10].c_str());
			member.AttackWaggle=atoi(vecLine[11].c_str());
			member.AttackTumble=atoi(vecLine[12].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.Id] = member;
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
		if(vecLine.size() != 13)
		{
			printf_message("AttackBehavior.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="Id"){printf_message("AttackBehavior.csv中字段[Id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="AttackerType"){printf_message("AttackBehavior.csv中字段[AttackerType]位置不对应");assert(false); return false; }
		if(vecLine[2]!="HitterType"){printf_message("AttackBehavior.csv中字段[HitterType]位置不对应");assert(false); return false; }
		if(vecLine[3]!="SkillType"){printf_message("AttackBehavior.csv中字段[SkillType]位置不对应");assert(false); return false; }
		if(vecLine[4]!="AttackFlash"){printf_message("AttackBehavior.csv中字段[AttackFlash]位置不对应");assert(false); return false; }
		if(vecLine[5]!="ShakeCamera"){printf_message("AttackBehavior.csv中字段[ShakeCamera]位置不对应");assert(false); return false; }
		if(vecLine[6]!="HitIdleAnim"){printf_message("AttackBehavior.csv中字段[HitIdleAnim]位置不对应");assert(false); return false; }
		if(vecLine[7]!="HitMoveAnim"){printf_message("AttackBehavior.csv中字段[HitMoveAnim]位置不对应");assert(false); return false; }
		if(vecLine[8]!="HitAnim"){printf_message("AttackBehavior.csv中字段[HitAnim]位置不对应");assert(false); return false; }
		if(vecLine[9]!="AttackBack"){printf_message("AttackBehavior.csv中字段[AttackBack]位置不对应");assert(false); return false; }
		if(vecLine[10]!="AttackAir"){printf_message("AttackBehavior.csv中字段[AttackAir]位置不对应");assert(false); return false; }
		if(vecLine[11]!="AttackWaggle"){printf_message("AttackBehavior.csv中字段[AttackWaggle]位置不对应");assert(false); return false; }
		if(vecLine[12]!="AttackTumble"){printf_message("AttackBehavior.csv中字段[AttackTumble]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)13)
			{
				assert(false);
				return false;
			}
			AttackBehaviorElement	member;
			member.Id=atoi(vecLine[0].c_str());
			member.AttackerType=atoi(vecLine[1].c_str());
			member.HitterType=atoi(vecLine[2].c_str());
			member.SkillType=atoi(vecLine[3].c_str());
			member.AttackFlash=atoi(vecLine[4].c_str());
			member.ShakeCamera=atoi(vecLine[5].c_str());
			member.HitIdleAnim=atoi(vecLine[6].c_str());
			member.HitMoveAnim=atoi(vecLine[7].c_str());
			member.HitAnim=atoi(vecLine[8].c_str());
			member.AttackBack=atoi(vecLine[9].c_str());
			member.AttackAir=atoi(vecLine[10].c_str());
			member.AttackWaggle=atoi(vecLine[11].c_str());
			member.AttackTumble=atoi(vecLine[12].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.Id] = member;
		}
		return true;
	}
};

#endif
