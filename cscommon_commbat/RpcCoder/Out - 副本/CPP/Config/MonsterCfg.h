#ifndef __MONSTER_CONFIG_H
#define __MONSTER_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//怪物基本表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct MonsterElement
{
	friend class MonsterTable;
	int MonsterID;               	//NpcID	编号
	int ModelID;                 	//模型ID	索引模型
	float ModelScaling;          	//模型缩放	模型缩放比例，包含模型的所有东西进行缩放
	int AttType;                 	//攻击类型	0物理1法术
	string Name;                 	//NPC名称	NPC名称
	string HeadIcon;             	//怪物头像	怪物的头像文件
	string Title;                	//NPC称号	NPC称号
	int Level;                   	//等级	NPC的等级
	int Group;                   	//组ID	区分组别ID,用来识别一类型的怪物
	int Type;                    	//怪物类型	1、小怪2boss3塔4范围塔
	int BaseAI;                  	//AIID	索引基础AIID
	float MonsterR;              	//怪物半径	怪物半径
	int PingPong;                	//受击抖动	Boss受击抖动(-1不抖动1抖动)
	int MonsterExp;              	//怪物经验	击杀该怪物可获得的经验值
	int DropID;                  	//掉落ID	索引掉落表
	int Skill1;                  	//普攻1	普攻1
	int Skill2;                  	//普攻2	普攻2
	int Skill3;                  	//普攻3	普攻3
	int Skill4;                  	//普攻4	普攻4
	int Skill5;                  	//技能1	技能1
	int Skill6;                  	//技能2	技能2
	int Skill7;                  	//技能3	技能3
	int Skill8;                  	//技能4	技能4
	int Skill9;                  	//技能5	技能5
	string Skill;                	//技能集合	技能总和
	float movSP;                 	//移动速度	移动的速度，单位：m/s
	float attSP;                 	//攻击速度	普通攻击的速度（暂没用
	int AllowMove;               	//是否有受击动作	0无，1有
	int HP;                      	//气血上限	气血上限
	int reHP;                    	//气血恢复速度	气血恢复速度
	int MP;                      	//法力上限	法力上限
	int reMP;                    	//法力恢复速度	法力恢复速度
	int minPA;                   	//最小物理攻击	最小物理攻击
	int maxPA;                   	//最大物理攻击	最大物理攻击
	int minMA;                   	//最小法术攻击	最小法术攻击
	int maxMA;                   	//最大法术攻击	最大法术攻击
	int PD;                      	//物理防御	物理防御
	int MD;                      	//法术防御	法术防御
	int igPhi;                   	//物理命中	物理命中
	int igMdo;                   	//法术命中	法术命中
	int Pdo;                     	//物理躲避	物理躲避
	int Mdo;                     	//法术躲避	法术躲避
	float HitRate;               	//基础命中率	基础命中率
	float CritRate;              	//基础暴击率	基础暴击率
	float igPcr;                 	//物理致命	物理致命
	float igMcr;                 	//法术致命	法术致命
	float Pcr;                   	//抗物理致命	抗物理致命
	float Mcr;                   	//抗法术致命	抗法术致命
	float igPrd;                 	//物理致命伤害	物理致命伤害
	float igMrd;                 	//法术致命伤害	法术致命伤害
	float Prd;                   	//抗物理致命伤害	抗物理致命伤害
	float Mrd;                   	//抗法术致命伤害	抗法术致命伤害
	float igBlo;                 	//破盾	破盾
	float Blo;                   	//格挡	格挡
	float igBrd;                 	//忽视格挡伤害减免	忽视格挡伤害减免
	float Brd;                   	//格挡伤害减免	格挡伤害减免
	float igVEr;                 	//强眩晕	强眩晕
	float igSLr;                 	//强睡眠	强睡眠
	float igCHr;                 	//强混乱	强混乱
	float igABr;                 	//强禁食	强禁食
	float igSIr;                 	//强沉默	强沉默
	float igGRr;                 	//强束缚	强束缚
	float igPEr;                 	//强石化	强石化
	float VEr;                   	//眩晕抗性	眩晕抗性
	float SLr;                   	//睡眠抗性	睡眠抗性
	float CHr;                   	//混乱抗性	混乱抗性
	float ABr;                   	//禁食抗性	禁食抗性
	float SIr;                   	//沉默抗性	沉默抗性
	float GRr;                   	//束缚抗性	束缚抗性
	float PEr;                   	//石化抗性	石化抗性
	float igFr;                  	//忽视火抗	忽视火抗
	float igEr;                  	//忽视电抗	忽视电抗
	float igWr;                  	//忽视风抗	忽视风抗
	float igCr;                  	//忽视冰抗	忽视冰抗
	float igPr;                  	//忽视毒抗	忽视毒抗
	float igLr;                  	//忽视光抗	忽视光抗
	float igDr;                  	//忽视暗抗	忽视暗抗
	float Fr;                    	//火抗性	火抗性
	float Er;                    	//电抗性	电抗性
	float Wr;                    	//风抗性	风抗性
	float Cr;                    	//冰抗性	冰抗性
	float Pr;                    	//毒抗性	毒抗性
	float Lr;                    	//光抗性	光抗性
	float Dr;                    	//暗抗性	暗抗性

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
	MonsterElement()
	{
		MonsterID = -1;
		m_bIsValidate=false;
	}
};

//怪物基本表脜盲脰脙路芒脳掳脌脿
class MonsterTable
{
	friend class TableData;
private:
	MonsterTable(){}
	~MonsterTable(){}
	map<int, MonsterElement>	m_mapElements;
	vector<MonsterElement>	m_vecAllElements;
	MonsterElement m_emptyItem;
public:
	static MonsterTable& Instance()
	{
		static MonsterTable sInstance;
		return sInstance;
	}

	MonsterElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<MonsterElement>&	GetAllElement()
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
		return LoadJson("Monster.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Monster.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Monster.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Monster.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="MonsterID"){printf_message("Monster.csv中字段[MonsterID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="ModelID"){printf_message("Monster.csv中字段[ModelID]位置不对应");assert(false); return false; }
		if(vecLine[2]!="ModelScaling"){printf_message("Monster.csv中字段[ModelScaling]位置不对应");assert(false); return false; }
		if(vecLine[3]!="AttType"){printf_message("Monster.csv中字段[AttType]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Name"){printf_message("Monster.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[5]!="HeadIcon"){printf_message("Monster.csv中字段[HeadIcon]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Title"){printf_message("Monster.csv中字段[Title]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Level"){printf_message("Monster.csv中字段[Level]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Group"){printf_message("Monster.csv中字段[Group]位置不对应");assert(false); return false; }
		if(vecLine[9]!="Type"){printf_message("Monster.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[10]!="BaseAI"){printf_message("Monster.csv中字段[BaseAI]位置不对应");assert(false); return false; }
		if(vecLine[11]!="MonsterR"){printf_message("Monster.csv中字段[MonsterR]位置不对应");assert(false); return false; }
		if(vecLine[12]!="PingPong"){printf_message("Monster.csv中字段[PingPong]位置不对应");assert(false); return false; }
		if(vecLine[13]!="MonsterExp"){printf_message("Monster.csv中字段[MonsterExp]位置不对应");assert(false); return false; }
		if(vecLine[14]!="DropID"){printf_message("Monster.csv中字段[DropID]位置不对应");assert(false); return false; }
		if(vecLine[15]!="Skill1"){printf_message("Monster.csv中字段[Skill1]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Skill2"){printf_message("Monster.csv中字段[Skill2]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Skill3"){printf_message("Monster.csv中字段[Skill3]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Skill4"){printf_message("Monster.csv中字段[Skill4]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Skill5"){printf_message("Monster.csv中字段[Skill5]位置不对应");assert(false); return false; }
		if(vecLine[20]!="Skill6"){printf_message("Monster.csv中字段[Skill6]位置不对应");assert(false); return false; }
		if(vecLine[21]!="Skill7"){printf_message("Monster.csv中字段[Skill7]位置不对应");assert(false); return false; }
		if(vecLine[22]!="Skill8"){printf_message("Monster.csv中字段[Skill8]位置不对应");assert(false); return false; }
		if(vecLine[23]!="Skill9"){printf_message("Monster.csv中字段[Skill9]位置不对应");assert(false); return false; }
		if(vecLine[24]!="Skill"){printf_message("Monster.csv中字段[Skill]位置不对应");assert(false); return false; }
		if(vecLine[25]!="movSP"){printf_message("Monster.csv中字段[movSP]位置不对应");assert(false); return false; }
		if(vecLine[26]!="attSP"){printf_message("Monster.csv中字段[attSP]位置不对应");assert(false); return false; }
		if(vecLine[27]!="AllowMove"){printf_message("Monster.csv中字段[AllowMove]位置不对应");assert(false); return false; }
		if(vecLine[28]!="HP"){printf_message("Monster.csv中字段[HP]位置不对应");assert(false); return false; }
		if(vecLine[29]!="reHP"){printf_message("Monster.csv中字段[reHP]位置不对应");assert(false); return false; }
		if(vecLine[30]!="MP"){printf_message("Monster.csv中字段[MP]位置不对应");assert(false); return false; }
		if(vecLine[31]!="reMP"){printf_message("Monster.csv中字段[reMP]位置不对应");assert(false); return false; }
		if(vecLine[32]!="minPA"){printf_message("Monster.csv中字段[minPA]位置不对应");assert(false); return false; }
		if(vecLine[33]!="maxPA"){printf_message("Monster.csv中字段[maxPA]位置不对应");assert(false); return false; }
		if(vecLine[34]!="minMA"){printf_message("Monster.csv中字段[minMA]位置不对应");assert(false); return false; }
		if(vecLine[35]!="maxMA"){printf_message("Monster.csv中字段[maxMA]位置不对应");assert(false); return false; }
		if(vecLine[36]!="PD"){printf_message("Monster.csv中字段[PD]位置不对应");assert(false); return false; }
		if(vecLine[37]!="MD"){printf_message("Monster.csv中字段[MD]位置不对应");assert(false); return false; }
		if(vecLine[38]!="igPhi"){printf_message("Monster.csv中字段[igPhi]位置不对应");assert(false); return false; }
		if(vecLine[39]!="igMdo"){printf_message("Monster.csv中字段[igMdo]位置不对应");assert(false); return false; }
		if(vecLine[40]!="Pdo"){printf_message("Monster.csv中字段[Pdo]位置不对应");assert(false); return false; }
		if(vecLine[41]!="Mdo"){printf_message("Monster.csv中字段[Mdo]位置不对应");assert(false); return false; }
		if(vecLine[42]!="HitRate"){printf_message("Monster.csv中字段[HitRate]位置不对应");assert(false); return false; }
		if(vecLine[43]!="CritRate"){printf_message("Monster.csv中字段[CritRate]位置不对应");assert(false); return false; }
		if(vecLine[44]!="igPcr"){printf_message("Monster.csv中字段[igPcr]位置不对应");assert(false); return false; }
		if(vecLine[45]!="igMcr"){printf_message("Monster.csv中字段[igMcr]位置不对应");assert(false); return false; }
		if(vecLine[46]!="Pcr"){printf_message("Monster.csv中字段[Pcr]位置不对应");assert(false); return false; }
		if(vecLine[47]!="Mcr"){printf_message("Monster.csv中字段[Mcr]位置不对应");assert(false); return false; }
		if(vecLine[48]!="igPrd"){printf_message("Monster.csv中字段[igPrd]位置不对应");assert(false); return false; }
		if(vecLine[49]!="igMrd"){printf_message("Monster.csv中字段[igMrd]位置不对应");assert(false); return false; }
		if(vecLine[50]!="Prd"){printf_message("Monster.csv中字段[Prd]位置不对应");assert(false); return false; }
		if(vecLine[51]!="Mrd"){printf_message("Monster.csv中字段[Mrd]位置不对应");assert(false); return false; }
		if(vecLine[52]!="igBlo"){printf_message("Monster.csv中字段[igBlo]位置不对应");assert(false); return false; }
		if(vecLine[53]!="Blo"){printf_message("Monster.csv中字段[Blo]位置不对应");assert(false); return false; }
		if(vecLine[54]!="igBrd"){printf_message("Monster.csv中字段[igBrd]位置不对应");assert(false); return false; }
		if(vecLine[55]!="Brd"){printf_message("Monster.csv中字段[Brd]位置不对应");assert(false); return false; }
		if(vecLine[56]!="igVEr"){printf_message("Monster.csv中字段[igVEr]位置不对应");assert(false); return false; }
		if(vecLine[57]!="igSLr"){printf_message("Monster.csv中字段[igSLr]位置不对应");assert(false); return false; }
		if(vecLine[58]!="igCHr"){printf_message("Monster.csv中字段[igCHr]位置不对应");assert(false); return false; }
		if(vecLine[59]!="igABr"){printf_message("Monster.csv中字段[igABr]位置不对应");assert(false); return false; }
		if(vecLine[60]!="igSIr"){printf_message("Monster.csv中字段[igSIr]位置不对应");assert(false); return false; }
		if(vecLine[61]!="igGRr"){printf_message("Monster.csv中字段[igGRr]位置不对应");assert(false); return false; }
		if(vecLine[62]!="igPEr"){printf_message("Monster.csv中字段[igPEr]位置不对应");assert(false); return false; }
		if(vecLine[63]!="VEr"){printf_message("Monster.csv中字段[VEr]位置不对应");assert(false); return false; }
		if(vecLine[64]!="SLr"){printf_message("Monster.csv中字段[SLr]位置不对应");assert(false); return false; }
		if(vecLine[65]!="CHr"){printf_message("Monster.csv中字段[CHr]位置不对应");assert(false); return false; }
		if(vecLine[66]!="ABr"){printf_message("Monster.csv中字段[ABr]位置不对应");assert(false); return false; }
		if(vecLine[67]!="SIr"){printf_message("Monster.csv中字段[SIr]位置不对应");assert(false); return false; }
		if(vecLine[68]!="GRr"){printf_message("Monster.csv中字段[GRr]位置不对应");assert(false); return false; }
		if(vecLine[69]!="PEr"){printf_message("Monster.csv中字段[PEr]位置不对应");assert(false); return false; }
		if(vecLine[70]!="igFr"){printf_message("Monster.csv中字段[igFr]位置不对应");assert(false); return false; }
		if(vecLine[71]!="igEr"){printf_message("Monster.csv中字段[igEr]位置不对应");assert(false); return false; }
		if(vecLine[72]!="igWr"){printf_message("Monster.csv中字段[igWr]位置不对应");assert(false); return false; }
		if(vecLine[73]!="igCr"){printf_message("Monster.csv中字段[igCr]位置不对应");assert(false); return false; }
		if(vecLine[74]!="igPr"){printf_message("Monster.csv中字段[igPr]位置不对应");assert(false); return false; }
		if(vecLine[75]!="igLr"){printf_message("Monster.csv中字段[igLr]位置不对应");assert(false); return false; }
		if(vecLine[76]!="igDr"){printf_message("Monster.csv中字段[igDr]位置不对应");assert(false); return false; }
		if(vecLine[77]!="Fr"){printf_message("Monster.csv中字段[Fr]位置不对应");assert(false); return false; }
		if(vecLine[78]!="Er"){printf_message("Monster.csv中字段[Er]位置不对应");assert(false); return false; }
		if(vecLine[79]!="Wr"){printf_message("Monster.csv中字段[Wr]位置不对应");assert(false); return false; }
		if(vecLine[80]!="Cr"){printf_message("Monster.csv中字段[Cr]位置不对应");assert(false); return false; }
		if(vecLine[81]!="Pr"){printf_message("Monster.csv中字段[Pr]位置不对应");assert(false); return false; }
		if(vecLine[82]!="Lr"){printf_message("Monster.csv中字段[Lr]位置不对应");assert(false); return false; }
		if(vecLine[83]!="Dr"){printf_message("Monster.csv中字段[Dr]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			MonsterElement	member;

						member.MonsterID=atoi(vecLine[0].c_str());
			member.ModelID=atoi(vecLine[1].c_str());
			member.ModelScaling=atof(vecLine[2].c_str());
			member.AttType=atoi(vecLine[3].c_str());
			member.Name=vecLine[4];
			member.HeadIcon=vecLine[5];
			member.Title=vecLine[6];
			member.Level=atoi(vecLine[7].c_str());
			member.Group=atoi(vecLine[8].c_str());
			member.Type=atoi(vecLine[9].c_str());
			member.BaseAI=atoi(vecLine[10].c_str());
			member.MonsterR=atof(vecLine[11].c_str());
			member.PingPong=atoi(vecLine[12].c_str());
			member.MonsterExp=atoi(vecLine[13].c_str());
			member.DropID=atoi(vecLine[14].c_str());
			member.Skill1=atoi(vecLine[15].c_str());
			member.Skill2=atoi(vecLine[16].c_str());
			member.Skill3=atoi(vecLine[17].c_str());
			member.Skill4=atoi(vecLine[18].c_str());
			member.Skill5=atoi(vecLine[19].c_str());
			member.Skill6=atoi(vecLine[20].c_str());
			member.Skill7=atoi(vecLine[21].c_str());
			member.Skill8=atoi(vecLine[22].c_str());
			member.Skill9=atoi(vecLine[23].c_str());
			member.Skill=vecLine[24];
			member.movSP=atof(vecLine[25].c_str());
			member.attSP=atof(vecLine[26].c_str());
			member.AllowMove=atoi(vecLine[27].c_str());
			member.HP=atoi(vecLine[28].c_str());
			member.reHP=atoi(vecLine[29].c_str());
			member.MP=atoi(vecLine[30].c_str());
			member.reMP=atoi(vecLine[31].c_str());
			member.minPA=atoi(vecLine[32].c_str());
			member.maxPA=atoi(vecLine[33].c_str());
			member.minMA=atoi(vecLine[34].c_str());
			member.maxMA=atoi(vecLine[35].c_str());
			member.PD=atoi(vecLine[36].c_str());
			member.MD=atoi(vecLine[37].c_str());
			member.igPhi=atoi(vecLine[38].c_str());
			member.igMdo=atoi(vecLine[39].c_str());
			member.Pdo=atoi(vecLine[40].c_str());
			member.Mdo=atoi(vecLine[41].c_str());
			member.HitRate=atof(vecLine[42].c_str());
			member.CritRate=atof(vecLine[43].c_str());
			member.igPcr=atof(vecLine[44].c_str());
			member.igMcr=atof(vecLine[45].c_str());
			member.Pcr=atof(vecLine[46].c_str());
			member.Mcr=atof(vecLine[47].c_str());
			member.igPrd=atof(vecLine[48].c_str());
			member.igMrd=atof(vecLine[49].c_str());
			member.Prd=atof(vecLine[50].c_str());
			member.Mrd=atof(vecLine[51].c_str());
			member.igBlo=atof(vecLine[52].c_str());
			member.Blo=atof(vecLine[53].c_str());
			member.igBrd=atof(vecLine[54].c_str());
			member.Brd=atof(vecLine[55].c_str());
			member.igVEr=atof(vecLine[56].c_str());
			member.igSLr=atof(vecLine[57].c_str());
			member.igCHr=atof(vecLine[58].c_str());
			member.igABr=atof(vecLine[59].c_str());
			member.igSIr=atof(vecLine[60].c_str());
			member.igGRr=atof(vecLine[61].c_str());
			member.igPEr=atof(vecLine[62].c_str());
			member.VEr=atof(vecLine[63].c_str());
			member.SLr=atof(vecLine[64].c_str());
			member.CHr=atof(vecLine[65].c_str());
			member.ABr=atof(vecLine[66].c_str());
			member.SIr=atof(vecLine[67].c_str());
			member.GRr=atof(vecLine[68].c_str());
			member.PEr=atof(vecLine[69].c_str());
			member.igFr=atof(vecLine[70].c_str());
			member.igEr=atof(vecLine[71].c_str());
			member.igWr=atof(vecLine[72].c_str());
			member.igCr=atof(vecLine[73].c_str());
			member.igPr=atof(vecLine[74].c_str());
			member.igLr=atof(vecLine[75].c_str());
			member.igDr=atof(vecLine[76].c_str());
			member.Fr=atof(vecLine[77].c_str());
			member.Er=atof(vecLine[78].c_str());
			member.Wr=atof(vecLine[79].c_str());
			member.Cr=atof(vecLine[80].c_str());
			member.Pr=atof(vecLine[81].c_str());
			member.Lr=atof(vecLine[82].c_str());
			member.Dr=atof(vecLine[83].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.MonsterID] = member;
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
		if(vecLine.size() != 84)
		{
			printf_message("Monster.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="MonsterID"){printf_message("Monster.csv中字段[MonsterID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="ModelID"){printf_message("Monster.csv中字段[ModelID]位置不对应");assert(false); return false; }
		if(vecLine[2]!="ModelScaling"){printf_message("Monster.csv中字段[ModelScaling]位置不对应");assert(false); return false; }
		if(vecLine[3]!="AttType"){printf_message("Monster.csv中字段[AttType]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Name"){printf_message("Monster.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[5]!="HeadIcon"){printf_message("Monster.csv中字段[HeadIcon]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Title"){printf_message("Monster.csv中字段[Title]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Level"){printf_message("Monster.csv中字段[Level]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Group"){printf_message("Monster.csv中字段[Group]位置不对应");assert(false); return false; }
		if(vecLine[9]!="Type"){printf_message("Monster.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[10]!="BaseAI"){printf_message("Monster.csv中字段[BaseAI]位置不对应");assert(false); return false; }
		if(vecLine[11]!="MonsterR"){printf_message("Monster.csv中字段[MonsterR]位置不对应");assert(false); return false; }
		if(vecLine[12]!="PingPong"){printf_message("Monster.csv中字段[PingPong]位置不对应");assert(false); return false; }
		if(vecLine[13]!="MonsterExp"){printf_message("Monster.csv中字段[MonsterExp]位置不对应");assert(false); return false; }
		if(vecLine[14]!="DropID"){printf_message("Monster.csv中字段[DropID]位置不对应");assert(false); return false; }
		if(vecLine[15]!="Skill1"){printf_message("Monster.csv中字段[Skill1]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Skill2"){printf_message("Monster.csv中字段[Skill2]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Skill3"){printf_message("Monster.csv中字段[Skill3]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Skill4"){printf_message("Monster.csv中字段[Skill4]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Skill5"){printf_message("Monster.csv中字段[Skill5]位置不对应");assert(false); return false; }
		if(vecLine[20]!="Skill6"){printf_message("Monster.csv中字段[Skill6]位置不对应");assert(false); return false; }
		if(vecLine[21]!="Skill7"){printf_message("Monster.csv中字段[Skill7]位置不对应");assert(false); return false; }
		if(vecLine[22]!="Skill8"){printf_message("Monster.csv中字段[Skill8]位置不对应");assert(false); return false; }
		if(vecLine[23]!="Skill9"){printf_message("Monster.csv中字段[Skill9]位置不对应");assert(false); return false; }
		if(vecLine[24]!="Skill"){printf_message("Monster.csv中字段[Skill]位置不对应");assert(false); return false; }
		if(vecLine[25]!="movSP"){printf_message("Monster.csv中字段[movSP]位置不对应");assert(false); return false; }
		if(vecLine[26]!="attSP"){printf_message("Monster.csv中字段[attSP]位置不对应");assert(false); return false; }
		if(vecLine[27]!="AllowMove"){printf_message("Monster.csv中字段[AllowMove]位置不对应");assert(false); return false; }
		if(vecLine[28]!="HP"){printf_message("Monster.csv中字段[HP]位置不对应");assert(false); return false; }
		if(vecLine[29]!="reHP"){printf_message("Monster.csv中字段[reHP]位置不对应");assert(false); return false; }
		if(vecLine[30]!="MP"){printf_message("Monster.csv中字段[MP]位置不对应");assert(false); return false; }
		if(vecLine[31]!="reMP"){printf_message("Monster.csv中字段[reMP]位置不对应");assert(false); return false; }
		if(vecLine[32]!="minPA"){printf_message("Monster.csv中字段[minPA]位置不对应");assert(false); return false; }
		if(vecLine[33]!="maxPA"){printf_message("Monster.csv中字段[maxPA]位置不对应");assert(false); return false; }
		if(vecLine[34]!="minMA"){printf_message("Monster.csv中字段[minMA]位置不对应");assert(false); return false; }
		if(vecLine[35]!="maxMA"){printf_message("Monster.csv中字段[maxMA]位置不对应");assert(false); return false; }
		if(vecLine[36]!="PD"){printf_message("Monster.csv中字段[PD]位置不对应");assert(false); return false; }
		if(vecLine[37]!="MD"){printf_message("Monster.csv中字段[MD]位置不对应");assert(false); return false; }
		if(vecLine[38]!="igPhi"){printf_message("Monster.csv中字段[igPhi]位置不对应");assert(false); return false; }
		if(vecLine[39]!="igMdo"){printf_message("Monster.csv中字段[igMdo]位置不对应");assert(false); return false; }
		if(vecLine[40]!="Pdo"){printf_message("Monster.csv中字段[Pdo]位置不对应");assert(false); return false; }
		if(vecLine[41]!="Mdo"){printf_message("Monster.csv中字段[Mdo]位置不对应");assert(false); return false; }
		if(vecLine[42]!="HitRate"){printf_message("Monster.csv中字段[HitRate]位置不对应");assert(false); return false; }
		if(vecLine[43]!="CritRate"){printf_message("Monster.csv中字段[CritRate]位置不对应");assert(false); return false; }
		if(vecLine[44]!="igPcr"){printf_message("Monster.csv中字段[igPcr]位置不对应");assert(false); return false; }
		if(vecLine[45]!="igMcr"){printf_message("Monster.csv中字段[igMcr]位置不对应");assert(false); return false; }
		if(vecLine[46]!="Pcr"){printf_message("Monster.csv中字段[Pcr]位置不对应");assert(false); return false; }
		if(vecLine[47]!="Mcr"){printf_message("Monster.csv中字段[Mcr]位置不对应");assert(false); return false; }
		if(vecLine[48]!="igPrd"){printf_message("Monster.csv中字段[igPrd]位置不对应");assert(false); return false; }
		if(vecLine[49]!="igMrd"){printf_message("Monster.csv中字段[igMrd]位置不对应");assert(false); return false; }
		if(vecLine[50]!="Prd"){printf_message("Monster.csv中字段[Prd]位置不对应");assert(false); return false; }
		if(vecLine[51]!="Mrd"){printf_message("Monster.csv中字段[Mrd]位置不对应");assert(false); return false; }
		if(vecLine[52]!="igBlo"){printf_message("Monster.csv中字段[igBlo]位置不对应");assert(false); return false; }
		if(vecLine[53]!="Blo"){printf_message("Monster.csv中字段[Blo]位置不对应");assert(false); return false; }
		if(vecLine[54]!="igBrd"){printf_message("Monster.csv中字段[igBrd]位置不对应");assert(false); return false; }
		if(vecLine[55]!="Brd"){printf_message("Monster.csv中字段[Brd]位置不对应");assert(false); return false; }
		if(vecLine[56]!="igVEr"){printf_message("Monster.csv中字段[igVEr]位置不对应");assert(false); return false; }
		if(vecLine[57]!="igSLr"){printf_message("Monster.csv中字段[igSLr]位置不对应");assert(false); return false; }
		if(vecLine[58]!="igCHr"){printf_message("Monster.csv中字段[igCHr]位置不对应");assert(false); return false; }
		if(vecLine[59]!="igABr"){printf_message("Monster.csv中字段[igABr]位置不对应");assert(false); return false; }
		if(vecLine[60]!="igSIr"){printf_message("Monster.csv中字段[igSIr]位置不对应");assert(false); return false; }
		if(vecLine[61]!="igGRr"){printf_message("Monster.csv中字段[igGRr]位置不对应");assert(false); return false; }
		if(vecLine[62]!="igPEr"){printf_message("Monster.csv中字段[igPEr]位置不对应");assert(false); return false; }
		if(vecLine[63]!="VEr"){printf_message("Monster.csv中字段[VEr]位置不对应");assert(false); return false; }
		if(vecLine[64]!="SLr"){printf_message("Monster.csv中字段[SLr]位置不对应");assert(false); return false; }
		if(vecLine[65]!="CHr"){printf_message("Monster.csv中字段[CHr]位置不对应");assert(false); return false; }
		if(vecLine[66]!="ABr"){printf_message("Monster.csv中字段[ABr]位置不对应");assert(false); return false; }
		if(vecLine[67]!="SIr"){printf_message("Monster.csv中字段[SIr]位置不对应");assert(false); return false; }
		if(vecLine[68]!="GRr"){printf_message("Monster.csv中字段[GRr]位置不对应");assert(false); return false; }
		if(vecLine[69]!="PEr"){printf_message("Monster.csv中字段[PEr]位置不对应");assert(false); return false; }
		if(vecLine[70]!="igFr"){printf_message("Monster.csv中字段[igFr]位置不对应");assert(false); return false; }
		if(vecLine[71]!="igEr"){printf_message("Monster.csv中字段[igEr]位置不对应");assert(false); return false; }
		if(vecLine[72]!="igWr"){printf_message("Monster.csv中字段[igWr]位置不对应");assert(false); return false; }
		if(vecLine[73]!="igCr"){printf_message("Monster.csv中字段[igCr]位置不对应");assert(false); return false; }
		if(vecLine[74]!="igPr"){printf_message("Monster.csv中字段[igPr]位置不对应");assert(false); return false; }
		if(vecLine[75]!="igLr"){printf_message("Monster.csv中字段[igLr]位置不对应");assert(false); return false; }
		if(vecLine[76]!="igDr"){printf_message("Monster.csv中字段[igDr]位置不对应");assert(false); return false; }
		if(vecLine[77]!="Fr"){printf_message("Monster.csv中字段[Fr]位置不对应");assert(false); return false; }
		if(vecLine[78]!="Er"){printf_message("Monster.csv中字段[Er]位置不对应");assert(false); return false; }
		if(vecLine[79]!="Wr"){printf_message("Monster.csv中字段[Wr]位置不对应");assert(false); return false; }
		if(vecLine[80]!="Cr"){printf_message("Monster.csv中字段[Cr]位置不对应");assert(false); return false; }
		if(vecLine[81]!="Pr"){printf_message("Monster.csv中字段[Pr]位置不对应");assert(false); return false; }
		if(vecLine[82]!="Lr"){printf_message("Monster.csv中字段[Lr]位置不对应");assert(false); return false; }
		if(vecLine[83]!="Dr"){printf_message("Monster.csv中字段[Dr]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)84)
			{
				assert(false);
				return false;
			}
			MonsterElement	member;
			member.MonsterID=atoi(vecLine[0].c_str());
			member.ModelID=atoi(vecLine[1].c_str());
			member.ModelScaling=atof(vecLine[2].c_str());
			member.AttType=atoi(vecLine[3].c_str());
			member.Name=vecLine[4];
			member.HeadIcon=vecLine[5];
			member.Title=vecLine[6];
			member.Level=atoi(vecLine[7].c_str());
			member.Group=atoi(vecLine[8].c_str());
			member.Type=atoi(vecLine[9].c_str());
			member.BaseAI=atoi(vecLine[10].c_str());
			member.MonsterR=atof(vecLine[11].c_str());
			member.PingPong=atoi(vecLine[12].c_str());
			member.MonsterExp=atoi(vecLine[13].c_str());
			member.DropID=atoi(vecLine[14].c_str());
			member.Skill1=atoi(vecLine[15].c_str());
			member.Skill2=atoi(vecLine[16].c_str());
			member.Skill3=atoi(vecLine[17].c_str());
			member.Skill4=atoi(vecLine[18].c_str());
			member.Skill5=atoi(vecLine[19].c_str());
			member.Skill6=atoi(vecLine[20].c_str());
			member.Skill7=atoi(vecLine[21].c_str());
			member.Skill8=atoi(vecLine[22].c_str());
			member.Skill9=atoi(vecLine[23].c_str());
			member.Skill=vecLine[24];
			member.movSP=atof(vecLine[25].c_str());
			member.attSP=atof(vecLine[26].c_str());
			member.AllowMove=atoi(vecLine[27].c_str());
			member.HP=atoi(vecLine[28].c_str());
			member.reHP=atoi(vecLine[29].c_str());
			member.MP=atoi(vecLine[30].c_str());
			member.reMP=atoi(vecLine[31].c_str());
			member.minPA=atoi(vecLine[32].c_str());
			member.maxPA=atoi(vecLine[33].c_str());
			member.minMA=atoi(vecLine[34].c_str());
			member.maxMA=atoi(vecLine[35].c_str());
			member.PD=atoi(vecLine[36].c_str());
			member.MD=atoi(vecLine[37].c_str());
			member.igPhi=atoi(vecLine[38].c_str());
			member.igMdo=atoi(vecLine[39].c_str());
			member.Pdo=atoi(vecLine[40].c_str());
			member.Mdo=atoi(vecLine[41].c_str());
			member.HitRate=atof(vecLine[42].c_str());
			member.CritRate=atof(vecLine[43].c_str());
			member.igPcr=atof(vecLine[44].c_str());
			member.igMcr=atof(vecLine[45].c_str());
			member.Pcr=atof(vecLine[46].c_str());
			member.Mcr=atof(vecLine[47].c_str());
			member.igPrd=atof(vecLine[48].c_str());
			member.igMrd=atof(vecLine[49].c_str());
			member.Prd=atof(vecLine[50].c_str());
			member.Mrd=atof(vecLine[51].c_str());
			member.igBlo=atof(vecLine[52].c_str());
			member.Blo=atof(vecLine[53].c_str());
			member.igBrd=atof(vecLine[54].c_str());
			member.Brd=atof(vecLine[55].c_str());
			member.igVEr=atof(vecLine[56].c_str());
			member.igSLr=atof(vecLine[57].c_str());
			member.igCHr=atof(vecLine[58].c_str());
			member.igABr=atof(vecLine[59].c_str());
			member.igSIr=atof(vecLine[60].c_str());
			member.igGRr=atof(vecLine[61].c_str());
			member.igPEr=atof(vecLine[62].c_str());
			member.VEr=atof(vecLine[63].c_str());
			member.SLr=atof(vecLine[64].c_str());
			member.CHr=atof(vecLine[65].c_str());
			member.ABr=atof(vecLine[66].c_str());
			member.SIr=atof(vecLine[67].c_str());
			member.GRr=atof(vecLine[68].c_str());
			member.PEr=atof(vecLine[69].c_str());
			member.igFr=atof(vecLine[70].c_str());
			member.igEr=atof(vecLine[71].c_str());
			member.igWr=atof(vecLine[72].c_str());
			member.igCr=atof(vecLine[73].c_str());
			member.igPr=atof(vecLine[74].c_str());
			member.igLr=atof(vecLine[75].c_str());
			member.igDr=atof(vecLine[76].c_str());
			member.Fr=atof(vecLine[77].c_str());
			member.Er=atof(vecLine[78].c_str());
			member.Wr=atof(vecLine[79].c_str());
			member.Cr=atof(vecLine[80].c_str());
			member.Pr=atof(vecLine[81].c_str());
			member.Lr=atof(vecLine[82].c_str());
			member.Dr=atof(vecLine[83].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.MonsterID] = member;
		}
		return true;
	}
};

#endif
