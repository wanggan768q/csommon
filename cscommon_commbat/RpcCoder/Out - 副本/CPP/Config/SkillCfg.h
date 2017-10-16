#ifndef __SKILL_CONFIG_H
#define __SKILL_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//技能基础表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct SkillElement
{
	friend class SkillTable;
	int SkillID;                 	//技能ID	编号
	string Name;                 	//技能名称	技能名称
	string SourceIcon;           	//技能图标	技能图标
	int Hero;                    	//所属英雄	所属英雄
	int Type;                    	//技能类型	技能类型（1普攻、2技能、3瞄准、4绝技、5被动属性（只要激活就加属性） 6被动 ）
	int SkillType;               	//施法类型	1 瞬发 2 吟唱 3引导 4蓄力
	string FenDuan;              	//蓄力分段	蓄力分段
	string XuLiStart;            	//蓄力开始动作	蓄力开始动作
	string XuLiXunHuan;          	//蓄力循环动作	蓄力循环动作
	string XuLiSkill;            	//蓄力技能	蓄力技能
	int YinChangTime;            	//吟唱时间	吟唱时间
	string YinChangSkill;        	//吟唱动作	吟唱动作
	int YinDaoTime;              	//引导时间	引导时间
	string YinDaoSkill;          	//引导动作	引导动作
	int HitType;                 	//技能伤害类型	1伤害2 恢复
	string SkillMana;            	//技能耗蓝	技能对蓝的消耗（基础消耗+等级*等级消耗系数）
	int CD;                      	//技能CD	技能的CD时常，单位为s
	float AttackRange;           	//技能攻击范围	技能攻击范围
	int HitRange;                	//技能伤害范围	技能伤害范围
	string Tips;                 	//技能描述	技能描述
	int Set;                     	//所属界面位置	绝技101 技能201 被动301 进阶被动401 修炼501 生活601
	int LVMAX;                   	//最高等级	技能最高等级
	int LvUp;                    	//升级消耗参数	升级消耗参数
	int LvUpMoney;               	//升级消耗金钱	升级消耗金钱
	int Attributes;              	//技能属性	技能属性（1物理2魔法）
	int Limit;                   	//技能限制	技能限制
	int UnderAttack;             	//受击状态	受击状态
	string AblityID;             	//技能文件	索引角色动作
	int FriendNum;               	//友方目标个数	友方目标个数
	string FriendBuffID;         	//友方BuffID	索引BUFF表，格式为{段数:BuffId1,BuffId2...}{段数:BuffId1,BuffId2...}…
	string BuffID;               	//敌方BuffID	索引BUFF表，格式为{段数:BuffId1,BuffId2...}{段数:BuffId1,BuffId2...}…
	string BuffRate;             	//敌方Buff概率	敌方Buff触发概率，格式为{段数:BuffId1概率,BuffId2概率...}{段数:BuffId1概率,BuffId2概率...}…
	string AttBuffEle;           	//buff对应攻方属性	对应属性编号，-1为无对应，格式为{段数:BuffId1属性,BuffId2属性...}{段数:BuffId1属性,BuffId2属性...}…
	string DefBuffEle;           	//buff对应守方属性	对应属性编号，-1为无对应，，格式为{段数:BuffId1属性,BuffId2属性...}{段数:BuffId1属性,BuffId2属性...}…
	string TrapID;               	//陷阱ID	索引陷阱表，格式为{段数:陷阱Id1,陷阱Id2...}{段数:陷阱Id1,陷阱Id2...}…
	float HatredCoefficient;     	//仇恨系数	技能所造成伤害的绝对值 * 仇恨系数 = 仇恨值
	float SkillHatred;           	//技能仇恨	释放该技能造成的固定仇恨值
	int DamageRuduce;            	//伤害衰减率	多目标的伤害衰减（造成伤害*（1-伤害衰减率）=实际伤害）
	string DamageNum;            	//基础伤害	技能基础攻击力+(技能等级增加的攻击力*等级)
	int AttSpcialEle;            	//元素伤害对应攻方属性	对应属性编号，-1为无对应，1701火，1702电，1703风,1704冰,1705毒,1706光,1707暗
	int DefSpcialEle;            	//元素伤害对应守方属性	对应属性编号，-1为无对应，1701火，1702电，1703风,1704冰,1705毒,1706光,1707暗
	string SpcialDamageNum;      	//元素伤害数值	基础属性伤害值
	int SkillDistance;           	//攻击距离	技能攻击距离
	int TargetOpt;               	//选中需求	是否需要选中释放
	int TargetNum;               	//伤害目标个数	技能可以造成伤害的最大目标数量
	string ParameterType;        	//被动参数类型	被动技能调用的参数类型
	string ParameterNum;         	//被动参数数额	被动技能参数类型对应的数额
	int TargetGroup;             	//目标阵营	1友，2敌，3全部 4全体队员
	string DamageAmend;          	//伤害修正	伤害参数修正，用于特殊技能参数
	int IsFanXiang;              	//是否有反向位移	1 有 -1 没有
	int IsYiDong;                	//是否可以操作移动	1可以 -1不可以
	int HandleType;              	//特殊技能类型	1攻击到的单位内生命最大单位 2 生命最小单位 3攻击目标数量大于3 4 己方血量最少 5 职业为医生、法师 6 目标生命大于自身生命 7隐身单位 8 血量低于50% 9 战士重斩 11战士冲锋 12战士先祖召唤 14猎人鹰击长空 15法师烈焰吐息 16法师炎爆术 101致命链接 102捆绑 103血量低于百分比
	int Special;                 	//特殊ID	特殊ID
	int TargetArea;              	//是否选择施法目标区域	1 有 -1 没有
	int DaoDi;                   	//落地后是否倒地	1是-1否
	int HitBack;                 	//击退方向类型	1面朝方向2扩散
	int ZiDong;                  	//是否可以自动释放	是否可以自动释放

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
	SkillElement()
	{
		SkillID = -1;
		m_bIsValidate=false;
	}
};

//技能基础表脜盲脰脙路芒脳掳脌脿
class SkillTable
{
	friend class TableData;
private:
	SkillTable(){}
	~SkillTable(){}
	map<int, SkillElement>	m_mapElements;
	vector<SkillElement>	m_vecAllElements;
	SkillElement m_emptyItem;
public:
	static SkillTable& Instance()
	{
		static SkillTable sInstance;
		return sInstance;
	}

	SkillElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SkillElement>&	GetAllElement()
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
		return LoadJson("Skill.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Skill.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Skill.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Skill.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="SkillID"){printf_message("Skill.csv中字段[SkillID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Skill.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="SourceIcon"){printf_message("Skill.csv中字段[SourceIcon]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Hero"){printf_message("Skill.csv中字段[Hero]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Type"){printf_message("Skill.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[5]!="SkillType"){printf_message("Skill.csv中字段[SkillType]位置不对应");assert(false); return false; }
		if(vecLine[6]!="FenDuan"){printf_message("Skill.csv中字段[FenDuan]位置不对应");assert(false); return false; }
		if(vecLine[7]!="XuLiStart"){printf_message("Skill.csv中字段[XuLiStart]位置不对应");assert(false); return false; }
		if(vecLine[8]!="XuLiXunHuan"){printf_message("Skill.csv中字段[XuLiXunHuan]位置不对应");assert(false); return false; }
		if(vecLine[9]!="XuLiSkill"){printf_message("Skill.csv中字段[XuLiSkill]位置不对应");assert(false); return false; }
		if(vecLine[10]!="YinChangTime"){printf_message("Skill.csv中字段[YinChangTime]位置不对应");assert(false); return false; }
		if(vecLine[11]!="YinChangSkill"){printf_message("Skill.csv中字段[YinChangSkill]位置不对应");assert(false); return false; }
		if(vecLine[12]!="YinDaoTime"){printf_message("Skill.csv中字段[YinDaoTime]位置不对应");assert(false); return false; }
		if(vecLine[13]!="YinDaoSkill"){printf_message("Skill.csv中字段[YinDaoSkill]位置不对应");assert(false); return false; }
		if(vecLine[14]!="HitType"){printf_message("Skill.csv中字段[HitType]位置不对应");assert(false); return false; }
		if(vecLine[15]!="SkillMana"){printf_message("Skill.csv中字段[SkillMana]位置不对应");assert(false); return false; }
		if(vecLine[16]!="CD"){printf_message("Skill.csv中字段[CD]位置不对应");assert(false); return false; }
		if(vecLine[17]!="AttackRange"){printf_message("Skill.csv中字段[AttackRange]位置不对应");assert(false); return false; }
		if(vecLine[18]!="HitRange"){printf_message("Skill.csv中字段[HitRange]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Tips"){printf_message("Skill.csv中字段[Tips]位置不对应");assert(false); return false; }
		if(vecLine[20]!="Set"){printf_message("Skill.csv中字段[Set]位置不对应");assert(false); return false; }
		if(vecLine[21]!="LVMAX"){printf_message("Skill.csv中字段[LVMAX]位置不对应");assert(false); return false; }
		if(vecLine[22]!="LvUp"){printf_message("Skill.csv中字段[LvUp]位置不对应");assert(false); return false; }
		if(vecLine[23]!="LvUpMoney"){printf_message("Skill.csv中字段[LvUpMoney]位置不对应");assert(false); return false; }
		if(vecLine[24]!="Attributes"){printf_message("Skill.csv中字段[Attributes]位置不对应");assert(false); return false; }
		if(vecLine[25]!="Limit"){printf_message("Skill.csv中字段[Limit]位置不对应");assert(false); return false; }
		if(vecLine[26]!="UnderAttack"){printf_message("Skill.csv中字段[UnderAttack]位置不对应");assert(false); return false; }
		if(vecLine[27]!="AblityID"){printf_message("Skill.csv中字段[AblityID]位置不对应");assert(false); return false; }
		if(vecLine[28]!="FriendNum"){printf_message("Skill.csv中字段[FriendNum]位置不对应");assert(false); return false; }
		if(vecLine[29]!="FriendBuffID"){printf_message("Skill.csv中字段[FriendBuffID]位置不对应");assert(false); return false; }
		if(vecLine[30]!="BuffID"){printf_message("Skill.csv中字段[BuffID]位置不对应");assert(false); return false; }
		if(vecLine[31]!="BuffRate"){printf_message("Skill.csv中字段[BuffRate]位置不对应");assert(false); return false; }
		if(vecLine[32]!="AttBuffEle"){printf_message("Skill.csv中字段[AttBuffEle]位置不对应");assert(false); return false; }
		if(vecLine[33]!="DefBuffEle"){printf_message("Skill.csv中字段[DefBuffEle]位置不对应");assert(false); return false; }
		if(vecLine[34]!="TrapID"){printf_message("Skill.csv中字段[TrapID]位置不对应");assert(false); return false; }
		if(vecLine[35]!="HatredCoefficient"){printf_message("Skill.csv中字段[HatredCoefficient]位置不对应");assert(false); return false; }
		if(vecLine[36]!="SkillHatred"){printf_message("Skill.csv中字段[SkillHatred]位置不对应");assert(false); return false; }
		if(vecLine[37]!="DamageRuduce"){printf_message("Skill.csv中字段[DamageRuduce]位置不对应");assert(false); return false; }
		if(vecLine[38]!="DamageNum"){printf_message("Skill.csv中字段[DamageNum]位置不对应");assert(false); return false; }
		if(vecLine[39]!="AttSpcialEle"){printf_message("Skill.csv中字段[AttSpcialEle]位置不对应");assert(false); return false; }
		if(vecLine[40]!="DefSpcialEle"){printf_message("Skill.csv中字段[DefSpcialEle]位置不对应");assert(false); return false; }
		if(vecLine[41]!="SpcialDamageNum"){printf_message("Skill.csv中字段[SpcialDamageNum]位置不对应");assert(false); return false; }
		if(vecLine[42]!="SkillDistance"){printf_message("Skill.csv中字段[SkillDistance]位置不对应");assert(false); return false; }
		if(vecLine[43]!="TargetOpt"){printf_message("Skill.csv中字段[TargetOpt]位置不对应");assert(false); return false; }
		if(vecLine[44]!="TargetNum"){printf_message("Skill.csv中字段[TargetNum]位置不对应");assert(false); return false; }
		if(vecLine[45]!="ParameterType"){printf_message("Skill.csv中字段[ParameterType]位置不对应");assert(false); return false; }
		if(vecLine[46]!="ParameterNum"){printf_message("Skill.csv中字段[ParameterNum]位置不对应");assert(false); return false; }
		if(vecLine[47]!="TargetGroup"){printf_message("Skill.csv中字段[TargetGroup]位置不对应");assert(false); return false; }
		if(vecLine[48]!="DamageAmend"){printf_message("Skill.csv中字段[DamageAmend]位置不对应");assert(false); return false; }
		if(vecLine[49]!="IsFanXiang"){printf_message("Skill.csv中字段[IsFanXiang]位置不对应");assert(false); return false; }
		if(vecLine[50]!="IsYiDong"){printf_message("Skill.csv中字段[IsYiDong]位置不对应");assert(false); return false; }
		if(vecLine[51]!="HandleType"){printf_message("Skill.csv中字段[HandleType]位置不对应");assert(false); return false; }
		if(vecLine[52]!="Special"){printf_message("Skill.csv中字段[Special]位置不对应");assert(false); return false; }
		if(vecLine[53]!="TargetArea"){printf_message("Skill.csv中字段[TargetArea]位置不对应");assert(false); return false; }
		if(vecLine[54]!="DaoDi"){printf_message("Skill.csv中字段[DaoDi]位置不对应");assert(false); return false; }
		if(vecLine[55]!="HitBack"){printf_message("Skill.csv中字段[HitBack]位置不对应");assert(false); return false; }
		if(vecLine[56]!="ZiDong"){printf_message("Skill.csv中字段[ZiDong]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			SkillElement	member;

						member.SkillID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.SourceIcon=vecLine[2];
			member.Hero=atoi(vecLine[3].c_str());
			member.Type=atoi(vecLine[4].c_str());
			member.SkillType=atoi(vecLine[5].c_str());
			member.FenDuan=vecLine[6];
			member.XuLiStart=vecLine[7];
			member.XuLiXunHuan=vecLine[8];
			member.XuLiSkill=vecLine[9];
			member.YinChangTime=atoi(vecLine[10].c_str());
			member.YinChangSkill=vecLine[11];
			member.YinDaoTime=atoi(vecLine[12].c_str());
			member.YinDaoSkill=vecLine[13];
			member.HitType=atoi(vecLine[14].c_str());
			member.SkillMana=vecLine[15];
			member.CD=atoi(vecLine[16].c_str());
			member.AttackRange=atof(vecLine[17].c_str());
			member.HitRange=atoi(vecLine[18].c_str());
			member.Tips=vecLine[19];
			member.Set=atoi(vecLine[20].c_str());
			member.LVMAX=atoi(vecLine[21].c_str());
			member.LvUp=atoi(vecLine[22].c_str());
			member.LvUpMoney=atoi(vecLine[23].c_str());
			member.Attributes=atoi(vecLine[24].c_str());
			member.Limit=atoi(vecLine[25].c_str());
			member.UnderAttack=atoi(vecLine[26].c_str());
			member.AblityID=vecLine[27];
			member.FriendNum=atoi(vecLine[28].c_str());
			member.FriendBuffID=vecLine[29];
			member.BuffID=vecLine[30];
			member.BuffRate=vecLine[31];
			member.AttBuffEle=vecLine[32];
			member.DefBuffEle=vecLine[33];
			member.TrapID=vecLine[34];
			member.HatredCoefficient=atof(vecLine[35].c_str());
			member.SkillHatred=atof(vecLine[36].c_str());
			member.DamageRuduce=atoi(vecLine[37].c_str());
			member.DamageNum=vecLine[38];
			member.AttSpcialEle=atoi(vecLine[39].c_str());
			member.DefSpcialEle=atoi(vecLine[40].c_str());
			member.SpcialDamageNum=vecLine[41];
			member.SkillDistance=atoi(vecLine[42].c_str());
			member.TargetOpt=atoi(vecLine[43].c_str());
			member.TargetNum=atoi(vecLine[44].c_str());
			member.ParameterType=vecLine[45];
			member.ParameterNum=vecLine[46];
			member.TargetGroup=atoi(vecLine[47].c_str());
			member.DamageAmend=vecLine[48];
			member.IsFanXiang=atoi(vecLine[49].c_str());
			member.IsYiDong=atoi(vecLine[50].c_str());
			member.HandleType=atoi(vecLine[51].c_str());
			member.Special=atoi(vecLine[52].c_str());
			member.TargetArea=atoi(vecLine[53].c_str());
			member.DaoDi=atoi(vecLine[54].c_str());
			member.HitBack=atoi(vecLine[55].c_str());
			member.ZiDong=atoi(vecLine[56].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.SkillID] = member;
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
		if(vecLine.size() != 57)
		{
			printf_message("Skill.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="SkillID"){printf_message("Skill.csv中字段[SkillID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Skill.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="SourceIcon"){printf_message("Skill.csv中字段[SourceIcon]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Hero"){printf_message("Skill.csv中字段[Hero]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Type"){printf_message("Skill.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[5]!="SkillType"){printf_message("Skill.csv中字段[SkillType]位置不对应");assert(false); return false; }
		if(vecLine[6]!="FenDuan"){printf_message("Skill.csv中字段[FenDuan]位置不对应");assert(false); return false; }
		if(vecLine[7]!="XuLiStart"){printf_message("Skill.csv中字段[XuLiStart]位置不对应");assert(false); return false; }
		if(vecLine[8]!="XuLiXunHuan"){printf_message("Skill.csv中字段[XuLiXunHuan]位置不对应");assert(false); return false; }
		if(vecLine[9]!="XuLiSkill"){printf_message("Skill.csv中字段[XuLiSkill]位置不对应");assert(false); return false; }
		if(vecLine[10]!="YinChangTime"){printf_message("Skill.csv中字段[YinChangTime]位置不对应");assert(false); return false; }
		if(vecLine[11]!="YinChangSkill"){printf_message("Skill.csv中字段[YinChangSkill]位置不对应");assert(false); return false; }
		if(vecLine[12]!="YinDaoTime"){printf_message("Skill.csv中字段[YinDaoTime]位置不对应");assert(false); return false; }
		if(vecLine[13]!="YinDaoSkill"){printf_message("Skill.csv中字段[YinDaoSkill]位置不对应");assert(false); return false; }
		if(vecLine[14]!="HitType"){printf_message("Skill.csv中字段[HitType]位置不对应");assert(false); return false; }
		if(vecLine[15]!="SkillMana"){printf_message("Skill.csv中字段[SkillMana]位置不对应");assert(false); return false; }
		if(vecLine[16]!="CD"){printf_message("Skill.csv中字段[CD]位置不对应");assert(false); return false; }
		if(vecLine[17]!="AttackRange"){printf_message("Skill.csv中字段[AttackRange]位置不对应");assert(false); return false; }
		if(vecLine[18]!="HitRange"){printf_message("Skill.csv中字段[HitRange]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Tips"){printf_message("Skill.csv中字段[Tips]位置不对应");assert(false); return false; }
		if(vecLine[20]!="Set"){printf_message("Skill.csv中字段[Set]位置不对应");assert(false); return false; }
		if(vecLine[21]!="LVMAX"){printf_message("Skill.csv中字段[LVMAX]位置不对应");assert(false); return false; }
		if(vecLine[22]!="LvUp"){printf_message("Skill.csv中字段[LvUp]位置不对应");assert(false); return false; }
		if(vecLine[23]!="LvUpMoney"){printf_message("Skill.csv中字段[LvUpMoney]位置不对应");assert(false); return false; }
		if(vecLine[24]!="Attributes"){printf_message("Skill.csv中字段[Attributes]位置不对应");assert(false); return false; }
		if(vecLine[25]!="Limit"){printf_message("Skill.csv中字段[Limit]位置不对应");assert(false); return false; }
		if(vecLine[26]!="UnderAttack"){printf_message("Skill.csv中字段[UnderAttack]位置不对应");assert(false); return false; }
		if(vecLine[27]!="AblityID"){printf_message("Skill.csv中字段[AblityID]位置不对应");assert(false); return false; }
		if(vecLine[28]!="FriendNum"){printf_message("Skill.csv中字段[FriendNum]位置不对应");assert(false); return false; }
		if(vecLine[29]!="FriendBuffID"){printf_message("Skill.csv中字段[FriendBuffID]位置不对应");assert(false); return false; }
		if(vecLine[30]!="BuffID"){printf_message("Skill.csv中字段[BuffID]位置不对应");assert(false); return false; }
		if(vecLine[31]!="BuffRate"){printf_message("Skill.csv中字段[BuffRate]位置不对应");assert(false); return false; }
		if(vecLine[32]!="AttBuffEle"){printf_message("Skill.csv中字段[AttBuffEle]位置不对应");assert(false); return false; }
		if(vecLine[33]!="DefBuffEle"){printf_message("Skill.csv中字段[DefBuffEle]位置不对应");assert(false); return false; }
		if(vecLine[34]!="TrapID"){printf_message("Skill.csv中字段[TrapID]位置不对应");assert(false); return false; }
		if(vecLine[35]!="HatredCoefficient"){printf_message("Skill.csv中字段[HatredCoefficient]位置不对应");assert(false); return false; }
		if(vecLine[36]!="SkillHatred"){printf_message("Skill.csv中字段[SkillHatred]位置不对应");assert(false); return false; }
		if(vecLine[37]!="DamageRuduce"){printf_message("Skill.csv中字段[DamageRuduce]位置不对应");assert(false); return false; }
		if(vecLine[38]!="DamageNum"){printf_message("Skill.csv中字段[DamageNum]位置不对应");assert(false); return false; }
		if(vecLine[39]!="AttSpcialEle"){printf_message("Skill.csv中字段[AttSpcialEle]位置不对应");assert(false); return false; }
		if(vecLine[40]!="DefSpcialEle"){printf_message("Skill.csv中字段[DefSpcialEle]位置不对应");assert(false); return false; }
		if(vecLine[41]!="SpcialDamageNum"){printf_message("Skill.csv中字段[SpcialDamageNum]位置不对应");assert(false); return false; }
		if(vecLine[42]!="SkillDistance"){printf_message("Skill.csv中字段[SkillDistance]位置不对应");assert(false); return false; }
		if(vecLine[43]!="TargetOpt"){printf_message("Skill.csv中字段[TargetOpt]位置不对应");assert(false); return false; }
		if(vecLine[44]!="TargetNum"){printf_message("Skill.csv中字段[TargetNum]位置不对应");assert(false); return false; }
		if(vecLine[45]!="ParameterType"){printf_message("Skill.csv中字段[ParameterType]位置不对应");assert(false); return false; }
		if(vecLine[46]!="ParameterNum"){printf_message("Skill.csv中字段[ParameterNum]位置不对应");assert(false); return false; }
		if(vecLine[47]!="TargetGroup"){printf_message("Skill.csv中字段[TargetGroup]位置不对应");assert(false); return false; }
		if(vecLine[48]!="DamageAmend"){printf_message("Skill.csv中字段[DamageAmend]位置不对应");assert(false); return false; }
		if(vecLine[49]!="IsFanXiang"){printf_message("Skill.csv中字段[IsFanXiang]位置不对应");assert(false); return false; }
		if(vecLine[50]!="IsYiDong"){printf_message("Skill.csv中字段[IsYiDong]位置不对应");assert(false); return false; }
		if(vecLine[51]!="HandleType"){printf_message("Skill.csv中字段[HandleType]位置不对应");assert(false); return false; }
		if(vecLine[52]!="Special"){printf_message("Skill.csv中字段[Special]位置不对应");assert(false); return false; }
		if(vecLine[53]!="TargetArea"){printf_message("Skill.csv中字段[TargetArea]位置不对应");assert(false); return false; }
		if(vecLine[54]!="DaoDi"){printf_message("Skill.csv中字段[DaoDi]位置不对应");assert(false); return false; }
		if(vecLine[55]!="HitBack"){printf_message("Skill.csv中字段[HitBack]位置不对应");assert(false); return false; }
		if(vecLine[56]!="ZiDong"){printf_message("Skill.csv中字段[ZiDong]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)57)
			{
				assert(false);
				return false;
			}
			SkillElement	member;
			member.SkillID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.SourceIcon=vecLine[2];
			member.Hero=atoi(vecLine[3].c_str());
			member.Type=atoi(vecLine[4].c_str());
			member.SkillType=atoi(vecLine[5].c_str());
			member.FenDuan=vecLine[6];
			member.XuLiStart=vecLine[7];
			member.XuLiXunHuan=vecLine[8];
			member.XuLiSkill=vecLine[9];
			member.YinChangTime=atoi(vecLine[10].c_str());
			member.YinChangSkill=vecLine[11];
			member.YinDaoTime=atoi(vecLine[12].c_str());
			member.YinDaoSkill=vecLine[13];
			member.HitType=atoi(vecLine[14].c_str());
			member.SkillMana=vecLine[15];
			member.CD=atoi(vecLine[16].c_str());
			member.AttackRange=atof(vecLine[17].c_str());
			member.HitRange=atoi(vecLine[18].c_str());
			member.Tips=vecLine[19];
			member.Set=atoi(vecLine[20].c_str());
			member.LVMAX=atoi(vecLine[21].c_str());
			member.LvUp=atoi(vecLine[22].c_str());
			member.LvUpMoney=atoi(vecLine[23].c_str());
			member.Attributes=atoi(vecLine[24].c_str());
			member.Limit=atoi(vecLine[25].c_str());
			member.UnderAttack=atoi(vecLine[26].c_str());
			member.AblityID=vecLine[27];
			member.FriendNum=atoi(vecLine[28].c_str());
			member.FriendBuffID=vecLine[29];
			member.BuffID=vecLine[30];
			member.BuffRate=vecLine[31];
			member.AttBuffEle=vecLine[32];
			member.DefBuffEle=vecLine[33];
			member.TrapID=vecLine[34];
			member.HatredCoefficient=atof(vecLine[35].c_str());
			member.SkillHatred=atof(vecLine[36].c_str());
			member.DamageRuduce=atoi(vecLine[37].c_str());
			member.DamageNum=vecLine[38];
			member.AttSpcialEle=atoi(vecLine[39].c_str());
			member.DefSpcialEle=atoi(vecLine[40].c_str());
			member.SpcialDamageNum=vecLine[41];
			member.SkillDistance=atoi(vecLine[42].c_str());
			member.TargetOpt=atoi(vecLine[43].c_str());
			member.TargetNum=atoi(vecLine[44].c_str());
			member.ParameterType=vecLine[45];
			member.ParameterNum=vecLine[46];
			member.TargetGroup=atoi(vecLine[47].c_str());
			member.DamageAmend=vecLine[48];
			member.IsFanXiang=atoi(vecLine[49].c_str());
			member.IsYiDong=atoi(vecLine[50].c_str());
			member.HandleType=atoi(vecLine[51].c_str());
			member.Special=atoi(vecLine[52].c_str());
			member.TargetArea=atoi(vecLine[53].c_str());
			member.DaoDi=atoi(vecLine[54].c_str());
			member.HitBack=atoi(vecLine[55].c_str());
			member.ZiDong=atoi(vecLine[56].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.SkillID] = member;
		}
		return true;
	}
};

#endif
