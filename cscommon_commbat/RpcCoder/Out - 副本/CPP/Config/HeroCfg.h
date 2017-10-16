#ifndef __HERO_CONFIG_H
#define __HERO_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//英雄脜盲脰脙脢媒戮脻陆谩鹿鹿
struct HeroElement
{
	friend class HeroTable;
	int Hero;                    	//编号	编号
	string Name;                 	//名称	名称
	int ModelID;                 	//模型ID	模型ID
	int Sex;                     	//性别	1男2女
	string HeadID;               	//选人界面头像素材	选人界面头像素材
	string Zhu_HeadID;           	//主界面头像素材	主界面头像素材
	string FB_HeadID;            	//副本头像素材	副本对话头像素材
	string Career_Icon;          	//职业图标	职业图标
	string ZhiYeIcon;            	//职业图标（选人）	职业图标（选人）
	int XingJi;                  	//上手难度星级	上手难度星级
	int AttType;                 	//攻击类型	0物理1法术
	float HeroR;                 	//英雄半径	英雄的模型大小，单位：m
	int Type;                    	//英雄类型（1力量2敏捷3智力4耐力5辅助）	英雄类型（1拳师2战士3射手4医生5法师）
	float SpeedFuben;            	//副本中移动速度	副本中移动速度
	float SpeedZhucheng;         	//主城中移动速度	主城中移动速度
	int Colour;                  	//初始颜色	初始颜色（1白2绿3蓝4紫5橙6红）
	int Star;                    	//初始星级	初始星级
	int Suipian;                 	//升星碎片	升星碎片
	int Num;                     	//合成所需碎片数量	合成所需碎片数量
	string Skill;                	//技能	技能
	int Skill1;                  	//普通攻击1	普通攻击1
	int Skill2;                  	//普通攻击2	普通攻击2
	int Skill3;                  	//普通攻击3	普通攻击3
	int Skill4;                  	//技能1	技能1
	int Skill5;                  	//技能2	技能2
	int Skill6;                  	//技能3	技能3
	int Skill7;                  	//大技能	大技能
	int Skill8;                  	//合体技	合体技
	int Skill9;                  	//被动	被动
	int AllowMove;               	//是否有受击动作	0无，1有
	int STA;                     	//根骨	根骨
	int SPI;                     	//精力	精力
	int STR;                     	//力量	力量
	int INT;                     	//智力	智力
	int AGI;                     	//敏捷	敏捷
	int STALVUP;                 	//根骨等级成长	根骨等级成长
	int SPILVUP;                 	//精力等级成长	精力等级成长
	int STRLVUP;                 	//力量等级成长	力量等级成长
	int INTLVUP;                 	//智力等级成长	智力等级成长
	int AGILVUP;                 	//敏捷等级成长	敏捷等级成长
	string HP;                   	//气血上限	气血上限
	string reHP;                 	//气血恢复速度	气血恢复速度
	string MP;                   	//法力上限	法力上限
	string reMP;                 	//法力恢复速度	法力恢复速度
	string minPA;                	//最小物理攻击	最小物理攻击
	string maxPA;                	//最大物理攻击	最大物理攻击
	string minMA;                	//最小法术攻击	最小法术攻击
	string maxMA;                	//最大法术攻击	最大法术攻击
	string PD;                   	//物理防御	物理防御
	string MD;                   	//法术防御	法术防御
	string igPhi;                	//物理命中	物理命中
	string igMdo;                	//法术命中	法术命中
	string Pdo;                  	//物理躲避	物理躲避
	string Mdo;                  	//法术躲避	法术躲避
	float HitRate;               	//基础命中率	基础命中率
	float CritRate;              	//基础暴击率	基础暴击率

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
	HeroElement()
	{
		Hero = -1;
		m_bIsValidate=false;
	}
};

//英雄脜盲脰脙路芒脳掳脌脿
class HeroTable
{
	friend class TableData;
private:
	HeroTable(){}
	~HeroTable(){}
	map<int, HeroElement>	m_mapElements;
	vector<HeroElement>	m_vecAllElements;
	HeroElement m_emptyItem;
public:
	static HeroTable& Instance()
	{
		static HeroTable sInstance;
		return sInstance;
	}

	HeroElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<HeroElement>&	GetAllElement()
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
		return LoadJson("Hero.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Hero.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Hero.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Hero.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="Hero"){printf_message("Hero.csv中字段[Hero]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Hero.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="ModelID"){printf_message("Hero.csv中字段[ModelID]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Sex"){printf_message("Hero.csv中字段[Sex]位置不对应");assert(false); return false; }
		if(vecLine[4]!="HeadID"){printf_message("Hero.csv中字段[HeadID]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Zhu_HeadID"){printf_message("Hero.csv中字段[Zhu_HeadID]位置不对应");assert(false); return false; }
		if(vecLine[6]!="FB_HeadID"){printf_message("Hero.csv中字段[FB_HeadID]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Career_Icon"){printf_message("Hero.csv中字段[Career_Icon]位置不对应");assert(false); return false; }
		if(vecLine[8]!="ZhiYeIcon"){printf_message("Hero.csv中字段[ZhiYeIcon]位置不对应");assert(false); return false; }
		if(vecLine[9]!="XingJi"){printf_message("Hero.csv中字段[XingJi]位置不对应");assert(false); return false; }
		if(vecLine[10]!="AttType"){printf_message("Hero.csv中字段[AttType]位置不对应");assert(false); return false; }
		if(vecLine[11]!="HeroR"){printf_message("Hero.csv中字段[HeroR]位置不对应");assert(false); return false; }
		if(vecLine[12]!="Type"){printf_message("Hero.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[13]!="SpeedFuben"){printf_message("Hero.csv中字段[SpeedFuben]位置不对应");assert(false); return false; }
		if(vecLine[14]!="SpeedZhucheng"){printf_message("Hero.csv中字段[SpeedZhucheng]位置不对应");assert(false); return false; }
		if(vecLine[15]!="Colour"){printf_message("Hero.csv中字段[Colour]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Star"){printf_message("Hero.csv中字段[Star]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Suipian"){printf_message("Hero.csv中字段[Suipian]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Num"){printf_message("Hero.csv中字段[Num]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Skill"){printf_message("Hero.csv中字段[Skill]位置不对应");assert(false); return false; }
		if(vecLine[20]!="Skill1"){printf_message("Hero.csv中字段[Skill1]位置不对应");assert(false); return false; }
		if(vecLine[21]!="Skill2"){printf_message("Hero.csv中字段[Skill2]位置不对应");assert(false); return false; }
		if(vecLine[22]!="Skill3"){printf_message("Hero.csv中字段[Skill3]位置不对应");assert(false); return false; }
		if(vecLine[23]!="Skill4"){printf_message("Hero.csv中字段[Skill4]位置不对应");assert(false); return false; }
		if(vecLine[24]!="Skill5"){printf_message("Hero.csv中字段[Skill5]位置不对应");assert(false); return false; }
		if(vecLine[25]!="Skill6"){printf_message("Hero.csv中字段[Skill6]位置不对应");assert(false); return false; }
		if(vecLine[26]!="Skill7"){printf_message("Hero.csv中字段[Skill7]位置不对应");assert(false); return false; }
		if(vecLine[27]!="Skill8"){printf_message("Hero.csv中字段[Skill8]位置不对应");assert(false); return false; }
		if(vecLine[28]!="Skill9"){printf_message("Hero.csv中字段[Skill9]位置不对应");assert(false); return false; }
		if(vecLine[29]!="AllowMove"){printf_message("Hero.csv中字段[AllowMove]位置不对应");assert(false); return false; }
		if(vecLine[30]!="STA"){printf_message("Hero.csv中字段[STA]位置不对应");assert(false); return false; }
		if(vecLine[31]!="SPI"){printf_message("Hero.csv中字段[SPI]位置不对应");assert(false); return false; }
		if(vecLine[32]!="STR"){printf_message("Hero.csv中字段[STR]位置不对应");assert(false); return false; }
		if(vecLine[33]!="INT"){printf_message("Hero.csv中字段[INT]位置不对应");assert(false); return false; }
		if(vecLine[34]!="AGI"){printf_message("Hero.csv中字段[AGI]位置不对应");assert(false); return false; }
		if(vecLine[35]!="STALVUP"){printf_message("Hero.csv中字段[STALVUP]位置不对应");assert(false); return false; }
		if(vecLine[36]!="SPILVUP"){printf_message("Hero.csv中字段[SPILVUP]位置不对应");assert(false); return false; }
		if(vecLine[37]!="STRLVUP"){printf_message("Hero.csv中字段[STRLVUP]位置不对应");assert(false); return false; }
		if(vecLine[38]!="INTLVUP"){printf_message("Hero.csv中字段[INTLVUP]位置不对应");assert(false); return false; }
		if(vecLine[39]!="AGILVUP"){printf_message("Hero.csv中字段[AGILVUP]位置不对应");assert(false); return false; }
		if(vecLine[40]!="HP"){printf_message("Hero.csv中字段[HP]位置不对应");assert(false); return false; }
		if(vecLine[41]!="reHP"){printf_message("Hero.csv中字段[reHP]位置不对应");assert(false); return false; }
		if(vecLine[42]!="MP"){printf_message("Hero.csv中字段[MP]位置不对应");assert(false); return false; }
		if(vecLine[43]!="reMP"){printf_message("Hero.csv中字段[reMP]位置不对应");assert(false); return false; }
		if(vecLine[44]!="minPA"){printf_message("Hero.csv中字段[minPA]位置不对应");assert(false); return false; }
		if(vecLine[45]!="maxPA"){printf_message("Hero.csv中字段[maxPA]位置不对应");assert(false); return false; }
		if(vecLine[46]!="minMA"){printf_message("Hero.csv中字段[minMA]位置不对应");assert(false); return false; }
		if(vecLine[47]!="maxMA"){printf_message("Hero.csv中字段[maxMA]位置不对应");assert(false); return false; }
		if(vecLine[48]!="PD"){printf_message("Hero.csv中字段[PD]位置不对应");assert(false); return false; }
		if(vecLine[49]!="MD"){printf_message("Hero.csv中字段[MD]位置不对应");assert(false); return false; }
		if(vecLine[50]!="igPhi"){printf_message("Hero.csv中字段[igPhi]位置不对应");assert(false); return false; }
		if(vecLine[51]!="igMdo"){printf_message("Hero.csv中字段[igMdo]位置不对应");assert(false); return false; }
		if(vecLine[52]!="Pdo"){printf_message("Hero.csv中字段[Pdo]位置不对应");assert(false); return false; }
		if(vecLine[53]!="Mdo"){printf_message("Hero.csv中字段[Mdo]位置不对应");assert(false); return false; }
		if(vecLine[54]!="HitRate"){printf_message("Hero.csv中字段[HitRate]位置不对应");assert(false); return false; }
		if(vecLine[55]!="CritRate"){printf_message("Hero.csv中字段[CritRate]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			HeroElement	member;

						member.Hero=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.ModelID=atoi(vecLine[2].c_str());
			member.Sex=atoi(vecLine[3].c_str());
			member.HeadID=vecLine[4];
			member.Zhu_HeadID=vecLine[5];
			member.FB_HeadID=vecLine[6];
			member.Career_Icon=vecLine[7];
			member.ZhiYeIcon=vecLine[8];
			member.XingJi=atoi(vecLine[9].c_str());
			member.AttType=atoi(vecLine[10].c_str());
			member.HeroR=atof(vecLine[11].c_str());
			member.Type=atoi(vecLine[12].c_str());
			member.SpeedFuben=atof(vecLine[13].c_str());
			member.SpeedZhucheng=atof(vecLine[14].c_str());
			member.Colour=atoi(vecLine[15].c_str());
			member.Star=atoi(vecLine[16].c_str());
			member.Suipian=atoi(vecLine[17].c_str());
			member.Num=atoi(vecLine[18].c_str());
			member.Skill=vecLine[19];
			member.Skill1=atoi(vecLine[20].c_str());
			member.Skill2=atoi(vecLine[21].c_str());
			member.Skill3=atoi(vecLine[22].c_str());
			member.Skill4=atoi(vecLine[23].c_str());
			member.Skill5=atoi(vecLine[24].c_str());
			member.Skill6=atoi(vecLine[25].c_str());
			member.Skill7=atoi(vecLine[26].c_str());
			member.Skill8=atoi(vecLine[27].c_str());
			member.Skill9=atoi(vecLine[28].c_str());
			member.AllowMove=atoi(vecLine[29].c_str());
			member.STA=atoi(vecLine[30].c_str());
			member.SPI=atoi(vecLine[31].c_str());
			member.STR=atoi(vecLine[32].c_str());
			member.INT=atoi(vecLine[33].c_str());
			member.AGI=atoi(vecLine[34].c_str());
			member.STALVUP=atoi(vecLine[35].c_str());
			member.SPILVUP=atoi(vecLine[36].c_str());
			member.STRLVUP=atoi(vecLine[37].c_str());
			member.INTLVUP=atoi(vecLine[38].c_str());
			member.AGILVUP=atoi(vecLine[39].c_str());
			member.HP=vecLine[40];
			member.reHP=vecLine[41];
			member.MP=vecLine[42];
			member.reMP=vecLine[43];
			member.minPA=vecLine[44];
			member.maxPA=vecLine[45];
			member.minMA=vecLine[46];
			member.maxMA=vecLine[47];
			member.PD=vecLine[48];
			member.MD=vecLine[49];
			member.igPhi=vecLine[50];
			member.igMdo=vecLine[51];
			member.Pdo=vecLine[52];
			member.Mdo=vecLine[53];
			member.HitRate=atof(vecLine[54].c_str());
			member.CritRate=atof(vecLine[55].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.Hero] = member;
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
		if(vecLine.size() != 56)
		{
			printf_message("Hero.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="Hero"){printf_message("Hero.csv中字段[Hero]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Hero.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="ModelID"){printf_message("Hero.csv中字段[ModelID]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Sex"){printf_message("Hero.csv中字段[Sex]位置不对应");assert(false); return false; }
		if(vecLine[4]!="HeadID"){printf_message("Hero.csv中字段[HeadID]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Zhu_HeadID"){printf_message("Hero.csv中字段[Zhu_HeadID]位置不对应");assert(false); return false; }
		if(vecLine[6]!="FB_HeadID"){printf_message("Hero.csv中字段[FB_HeadID]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Career_Icon"){printf_message("Hero.csv中字段[Career_Icon]位置不对应");assert(false); return false; }
		if(vecLine[8]!="ZhiYeIcon"){printf_message("Hero.csv中字段[ZhiYeIcon]位置不对应");assert(false); return false; }
		if(vecLine[9]!="XingJi"){printf_message("Hero.csv中字段[XingJi]位置不对应");assert(false); return false; }
		if(vecLine[10]!="AttType"){printf_message("Hero.csv中字段[AttType]位置不对应");assert(false); return false; }
		if(vecLine[11]!="HeroR"){printf_message("Hero.csv中字段[HeroR]位置不对应");assert(false); return false; }
		if(vecLine[12]!="Type"){printf_message("Hero.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[13]!="SpeedFuben"){printf_message("Hero.csv中字段[SpeedFuben]位置不对应");assert(false); return false; }
		if(vecLine[14]!="SpeedZhucheng"){printf_message("Hero.csv中字段[SpeedZhucheng]位置不对应");assert(false); return false; }
		if(vecLine[15]!="Colour"){printf_message("Hero.csv中字段[Colour]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Star"){printf_message("Hero.csv中字段[Star]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Suipian"){printf_message("Hero.csv中字段[Suipian]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Num"){printf_message("Hero.csv中字段[Num]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Skill"){printf_message("Hero.csv中字段[Skill]位置不对应");assert(false); return false; }
		if(vecLine[20]!="Skill1"){printf_message("Hero.csv中字段[Skill1]位置不对应");assert(false); return false; }
		if(vecLine[21]!="Skill2"){printf_message("Hero.csv中字段[Skill2]位置不对应");assert(false); return false; }
		if(vecLine[22]!="Skill3"){printf_message("Hero.csv中字段[Skill3]位置不对应");assert(false); return false; }
		if(vecLine[23]!="Skill4"){printf_message("Hero.csv中字段[Skill4]位置不对应");assert(false); return false; }
		if(vecLine[24]!="Skill5"){printf_message("Hero.csv中字段[Skill5]位置不对应");assert(false); return false; }
		if(vecLine[25]!="Skill6"){printf_message("Hero.csv中字段[Skill6]位置不对应");assert(false); return false; }
		if(vecLine[26]!="Skill7"){printf_message("Hero.csv中字段[Skill7]位置不对应");assert(false); return false; }
		if(vecLine[27]!="Skill8"){printf_message("Hero.csv中字段[Skill8]位置不对应");assert(false); return false; }
		if(vecLine[28]!="Skill9"){printf_message("Hero.csv中字段[Skill9]位置不对应");assert(false); return false; }
		if(vecLine[29]!="AllowMove"){printf_message("Hero.csv中字段[AllowMove]位置不对应");assert(false); return false; }
		if(vecLine[30]!="STA"){printf_message("Hero.csv中字段[STA]位置不对应");assert(false); return false; }
		if(vecLine[31]!="SPI"){printf_message("Hero.csv中字段[SPI]位置不对应");assert(false); return false; }
		if(vecLine[32]!="STR"){printf_message("Hero.csv中字段[STR]位置不对应");assert(false); return false; }
		if(vecLine[33]!="INT"){printf_message("Hero.csv中字段[INT]位置不对应");assert(false); return false; }
		if(vecLine[34]!="AGI"){printf_message("Hero.csv中字段[AGI]位置不对应");assert(false); return false; }
		if(vecLine[35]!="STALVUP"){printf_message("Hero.csv中字段[STALVUP]位置不对应");assert(false); return false; }
		if(vecLine[36]!="SPILVUP"){printf_message("Hero.csv中字段[SPILVUP]位置不对应");assert(false); return false; }
		if(vecLine[37]!="STRLVUP"){printf_message("Hero.csv中字段[STRLVUP]位置不对应");assert(false); return false; }
		if(vecLine[38]!="INTLVUP"){printf_message("Hero.csv中字段[INTLVUP]位置不对应");assert(false); return false; }
		if(vecLine[39]!="AGILVUP"){printf_message("Hero.csv中字段[AGILVUP]位置不对应");assert(false); return false; }
		if(vecLine[40]!="HP"){printf_message("Hero.csv中字段[HP]位置不对应");assert(false); return false; }
		if(vecLine[41]!="reHP"){printf_message("Hero.csv中字段[reHP]位置不对应");assert(false); return false; }
		if(vecLine[42]!="MP"){printf_message("Hero.csv中字段[MP]位置不对应");assert(false); return false; }
		if(vecLine[43]!="reMP"){printf_message("Hero.csv中字段[reMP]位置不对应");assert(false); return false; }
		if(vecLine[44]!="minPA"){printf_message("Hero.csv中字段[minPA]位置不对应");assert(false); return false; }
		if(vecLine[45]!="maxPA"){printf_message("Hero.csv中字段[maxPA]位置不对应");assert(false); return false; }
		if(vecLine[46]!="minMA"){printf_message("Hero.csv中字段[minMA]位置不对应");assert(false); return false; }
		if(vecLine[47]!="maxMA"){printf_message("Hero.csv中字段[maxMA]位置不对应");assert(false); return false; }
		if(vecLine[48]!="PD"){printf_message("Hero.csv中字段[PD]位置不对应");assert(false); return false; }
		if(vecLine[49]!="MD"){printf_message("Hero.csv中字段[MD]位置不对应");assert(false); return false; }
		if(vecLine[50]!="igPhi"){printf_message("Hero.csv中字段[igPhi]位置不对应");assert(false); return false; }
		if(vecLine[51]!="igMdo"){printf_message("Hero.csv中字段[igMdo]位置不对应");assert(false); return false; }
		if(vecLine[52]!="Pdo"){printf_message("Hero.csv中字段[Pdo]位置不对应");assert(false); return false; }
		if(vecLine[53]!="Mdo"){printf_message("Hero.csv中字段[Mdo]位置不对应");assert(false); return false; }
		if(vecLine[54]!="HitRate"){printf_message("Hero.csv中字段[HitRate]位置不对应");assert(false); return false; }
		if(vecLine[55]!="CritRate"){printf_message("Hero.csv中字段[CritRate]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)56)
			{
				assert(false);
				return false;
			}
			HeroElement	member;
			member.Hero=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.ModelID=atoi(vecLine[2].c_str());
			member.Sex=atoi(vecLine[3].c_str());
			member.HeadID=vecLine[4];
			member.Zhu_HeadID=vecLine[5];
			member.FB_HeadID=vecLine[6];
			member.Career_Icon=vecLine[7];
			member.ZhiYeIcon=vecLine[8];
			member.XingJi=atoi(vecLine[9].c_str());
			member.AttType=atoi(vecLine[10].c_str());
			member.HeroR=atof(vecLine[11].c_str());
			member.Type=atoi(vecLine[12].c_str());
			member.SpeedFuben=atof(vecLine[13].c_str());
			member.SpeedZhucheng=atof(vecLine[14].c_str());
			member.Colour=atoi(vecLine[15].c_str());
			member.Star=atoi(vecLine[16].c_str());
			member.Suipian=atoi(vecLine[17].c_str());
			member.Num=atoi(vecLine[18].c_str());
			member.Skill=vecLine[19];
			member.Skill1=atoi(vecLine[20].c_str());
			member.Skill2=atoi(vecLine[21].c_str());
			member.Skill3=atoi(vecLine[22].c_str());
			member.Skill4=atoi(vecLine[23].c_str());
			member.Skill5=atoi(vecLine[24].c_str());
			member.Skill6=atoi(vecLine[25].c_str());
			member.Skill7=atoi(vecLine[26].c_str());
			member.Skill8=atoi(vecLine[27].c_str());
			member.Skill9=atoi(vecLine[28].c_str());
			member.AllowMove=atoi(vecLine[29].c_str());
			member.STA=atoi(vecLine[30].c_str());
			member.SPI=atoi(vecLine[31].c_str());
			member.STR=atoi(vecLine[32].c_str());
			member.INT=atoi(vecLine[33].c_str());
			member.AGI=atoi(vecLine[34].c_str());
			member.STALVUP=atoi(vecLine[35].c_str());
			member.SPILVUP=atoi(vecLine[36].c_str());
			member.STRLVUP=atoi(vecLine[37].c_str());
			member.INTLVUP=atoi(vecLine[38].c_str());
			member.AGILVUP=atoi(vecLine[39].c_str());
			member.HP=vecLine[40];
			member.reHP=vecLine[41];
			member.MP=vecLine[42];
			member.reMP=vecLine[43];
			member.minPA=vecLine[44];
			member.maxPA=vecLine[45];
			member.minMA=vecLine[46];
			member.maxMA=vecLine[47];
			member.PD=vecLine[48];
			member.MD=vecLine[49];
			member.igPhi=vecLine[50];
			member.igMdo=vecLine[51];
			member.Pdo=vecLine[52];
			member.Mdo=vecLine[53];
			member.HitRate=atof(vecLine[54].c_str());
			member.CritRate=atof(vecLine[55].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.Hero] = member;
		}
		return true;
	}
};

#endif
