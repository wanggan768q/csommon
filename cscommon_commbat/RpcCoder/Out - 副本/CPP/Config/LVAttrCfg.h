#ifndef __LVATTR_CONFIG_H
#define __LVATTR_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//等级对应属性脜盲脰脙脢媒戮脻陆谩鹿鹿
struct LVAttrElement
{
	friend class LVAttrTable;
	int LV;                      	//编号	等级
	string STA;                  	//根骨	根骨
	string SPI;                  	//精力	精力
	string STR;                  	//力量	力量
	string INT;                  	//智力	智力
	string AGI;                  	//敏捷	敏捷
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
	string igPcr;                	//物理致命	物理致命
	string igMcr;                	//法术致命	法术致命
	string Pcr;                  	//抗物理致命	抗物理致命
	string Mcr;                  	//抗法术致命	抗法术致命
	string igPrd;                	//物理致命伤害	物理致命伤害
	string igMrd;                	//法术致命伤害	法术致命伤害
	string Prd;                  	//抗物理致命伤害	抗物理致命伤害
	string Mrd;                  	//抗法术致命伤害	抗法术致命伤害
	string igBlo;                	//破盾	破盾
	string Blo;                  	//格挡	格挡
	string igBrd;                	//忽视格挡伤害减免	忽视格挡伤害减免
	string Brd;                  	//格挡伤害减免	格挡伤害减免
	string igVEr;                	//强眩晕	强眩晕
	string igSLr;                	//强睡眠	强睡眠
	string igCHr;                	//强混乱	强混乱
	string igABr;                	//强禁食	强禁食
	string igSIr;                	//强沉默	强沉默
	string igGRr;                	//强束缚	强束缚
	string igPEr;                	//强石化	强石化
	string VEr;                  	//眩晕抗性	眩晕抗性
	string SLr;                  	//睡眠抗性	睡眠抗性
	string CHr;                  	//混乱抗性	混乱抗性
	string ABr;                  	//禁食抗性	禁食抗性
	string SIr;                  	//沉默抗性	沉默抗性
	string GRr;                  	//束缚抗性	束缚抗性
	string PEr;                  	//石化抗性	石化抗性
	string igFr;                 	//忽视火抗	忽视火抗
	string igEr;                 	//忽视电抗	忽视电抗
	string igWr;                 	//忽视风抗	忽视风抗
	string igCr;                 	//忽视冰抗	忽视冰抗
	string igPr;                 	//忽视毒抗	忽视毒抗
	string igLr;                 	//忽视光抗	忽视光抗
	string igDr;                 	//忽视暗抗	忽视暗抗
	string Fr;                   	//火抗性	火抗性
	string Er;                   	//电抗性	电抗性
	string Wr;                   	//风抗性	风抗性
	string Cr;                   	//冰抗性	冰抗性
	string Pr;                   	//毒抗性	毒抗性
	string Lr;                   	//光抗性	光抗性
	string Dr;                   	//暗抗性	暗抗性

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
	LVAttrElement()
	{
		LV = -1;
		m_bIsValidate=false;
	}
};

//等级对应属性脜盲脰脙路芒脳掳脌脿
class LVAttrTable
{
	friend class TableData;
private:
	LVAttrTable(){}
	~LVAttrTable(){}
	map<int, LVAttrElement>	m_mapElements;
	vector<LVAttrElement>	m_vecAllElements;
	LVAttrElement m_emptyItem;
public:
	static LVAttrTable& Instance()
	{
		static LVAttrTable sInstance;
		return sInstance;
	}

	LVAttrElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<LVAttrElement>&	GetAllElement()
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
		return LoadJson("LVAttr.json");
		#else
		string strTableContent;
		if( LoadConfigContent("LVAttr.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("LVAttr.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[LVAttr.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="LV"){printf_message("LVAttr.csv中字段[LV]位置不对应");assert(false); return false; }
		if(vecLine[1]!="STA"){printf_message("LVAttr.csv中字段[STA]位置不对应");assert(false); return false; }
		if(vecLine[2]!="SPI"){printf_message("LVAttr.csv中字段[SPI]位置不对应");assert(false); return false; }
		if(vecLine[3]!="STR"){printf_message("LVAttr.csv中字段[STR]位置不对应");assert(false); return false; }
		if(vecLine[4]!="INT"){printf_message("LVAttr.csv中字段[INT]位置不对应");assert(false); return false; }
		if(vecLine[5]!="AGI"){printf_message("LVAttr.csv中字段[AGI]位置不对应");assert(false); return false; }
		if(vecLine[6]!="HP"){printf_message("LVAttr.csv中字段[HP]位置不对应");assert(false); return false; }
		if(vecLine[7]!="reHP"){printf_message("LVAttr.csv中字段[reHP]位置不对应");assert(false); return false; }
		if(vecLine[8]!="MP"){printf_message("LVAttr.csv中字段[MP]位置不对应");assert(false); return false; }
		if(vecLine[9]!="reMP"){printf_message("LVAttr.csv中字段[reMP]位置不对应");assert(false); return false; }
		if(vecLine[10]!="minPA"){printf_message("LVAttr.csv中字段[minPA]位置不对应");assert(false); return false; }
		if(vecLine[11]!="maxPA"){printf_message("LVAttr.csv中字段[maxPA]位置不对应");assert(false); return false; }
		if(vecLine[12]!="minMA"){printf_message("LVAttr.csv中字段[minMA]位置不对应");assert(false); return false; }
		if(vecLine[13]!="maxMA"){printf_message("LVAttr.csv中字段[maxMA]位置不对应");assert(false); return false; }
		if(vecLine[14]!="PD"){printf_message("LVAttr.csv中字段[PD]位置不对应");assert(false); return false; }
		if(vecLine[15]!="MD"){printf_message("LVAttr.csv中字段[MD]位置不对应");assert(false); return false; }
		if(vecLine[16]!="igPhi"){printf_message("LVAttr.csv中字段[igPhi]位置不对应");assert(false); return false; }
		if(vecLine[17]!="igMdo"){printf_message("LVAttr.csv中字段[igMdo]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Pdo"){printf_message("LVAttr.csv中字段[Pdo]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Mdo"){printf_message("LVAttr.csv中字段[Mdo]位置不对应");assert(false); return false; }
		if(vecLine[20]!="igPcr"){printf_message("LVAttr.csv中字段[igPcr]位置不对应");assert(false); return false; }
		if(vecLine[21]!="igMcr"){printf_message("LVAttr.csv中字段[igMcr]位置不对应");assert(false); return false; }
		if(vecLine[22]!="Pcr"){printf_message("LVAttr.csv中字段[Pcr]位置不对应");assert(false); return false; }
		if(vecLine[23]!="Mcr"){printf_message("LVAttr.csv中字段[Mcr]位置不对应");assert(false); return false; }
		if(vecLine[24]!="igPrd"){printf_message("LVAttr.csv中字段[igPrd]位置不对应");assert(false); return false; }
		if(vecLine[25]!="igMrd"){printf_message("LVAttr.csv中字段[igMrd]位置不对应");assert(false); return false; }
		if(vecLine[26]!="Prd"){printf_message("LVAttr.csv中字段[Prd]位置不对应");assert(false); return false; }
		if(vecLine[27]!="Mrd"){printf_message("LVAttr.csv中字段[Mrd]位置不对应");assert(false); return false; }
		if(vecLine[28]!="igBlo"){printf_message("LVAttr.csv中字段[igBlo]位置不对应");assert(false); return false; }
		if(vecLine[29]!="Blo"){printf_message("LVAttr.csv中字段[Blo]位置不对应");assert(false); return false; }
		if(vecLine[30]!="igBrd"){printf_message("LVAttr.csv中字段[igBrd]位置不对应");assert(false); return false; }
		if(vecLine[31]!="Brd"){printf_message("LVAttr.csv中字段[Brd]位置不对应");assert(false); return false; }
		if(vecLine[32]!="igVEr"){printf_message("LVAttr.csv中字段[igVEr]位置不对应");assert(false); return false; }
		if(vecLine[33]!="igSLr"){printf_message("LVAttr.csv中字段[igSLr]位置不对应");assert(false); return false; }
		if(vecLine[34]!="igCHr"){printf_message("LVAttr.csv中字段[igCHr]位置不对应");assert(false); return false; }
		if(vecLine[35]!="igABr"){printf_message("LVAttr.csv中字段[igABr]位置不对应");assert(false); return false; }
		if(vecLine[36]!="igSIr"){printf_message("LVAttr.csv中字段[igSIr]位置不对应");assert(false); return false; }
		if(vecLine[37]!="igGRr"){printf_message("LVAttr.csv中字段[igGRr]位置不对应");assert(false); return false; }
		if(vecLine[38]!="igPEr"){printf_message("LVAttr.csv中字段[igPEr]位置不对应");assert(false); return false; }
		if(vecLine[39]!="VEr"){printf_message("LVAttr.csv中字段[VEr]位置不对应");assert(false); return false; }
		if(vecLine[40]!="SLr"){printf_message("LVAttr.csv中字段[SLr]位置不对应");assert(false); return false; }
		if(vecLine[41]!="CHr"){printf_message("LVAttr.csv中字段[CHr]位置不对应");assert(false); return false; }
		if(vecLine[42]!="ABr"){printf_message("LVAttr.csv中字段[ABr]位置不对应");assert(false); return false; }
		if(vecLine[43]!="SIr"){printf_message("LVAttr.csv中字段[SIr]位置不对应");assert(false); return false; }
		if(vecLine[44]!="GRr"){printf_message("LVAttr.csv中字段[GRr]位置不对应");assert(false); return false; }
		if(vecLine[45]!="PEr"){printf_message("LVAttr.csv中字段[PEr]位置不对应");assert(false); return false; }
		if(vecLine[46]!="igFr"){printf_message("LVAttr.csv中字段[igFr]位置不对应");assert(false); return false; }
		if(vecLine[47]!="igEr"){printf_message("LVAttr.csv中字段[igEr]位置不对应");assert(false); return false; }
		if(vecLine[48]!="igWr"){printf_message("LVAttr.csv中字段[igWr]位置不对应");assert(false); return false; }
		if(vecLine[49]!="igCr"){printf_message("LVAttr.csv中字段[igCr]位置不对应");assert(false); return false; }
		if(vecLine[50]!="igPr"){printf_message("LVAttr.csv中字段[igPr]位置不对应");assert(false); return false; }
		if(vecLine[51]!="igLr"){printf_message("LVAttr.csv中字段[igLr]位置不对应");assert(false); return false; }
		if(vecLine[52]!="igDr"){printf_message("LVAttr.csv中字段[igDr]位置不对应");assert(false); return false; }
		if(vecLine[53]!="Fr"){printf_message("LVAttr.csv中字段[Fr]位置不对应");assert(false); return false; }
		if(vecLine[54]!="Er"){printf_message("LVAttr.csv中字段[Er]位置不对应");assert(false); return false; }
		if(vecLine[55]!="Wr"){printf_message("LVAttr.csv中字段[Wr]位置不对应");assert(false); return false; }
		if(vecLine[56]!="Cr"){printf_message("LVAttr.csv中字段[Cr]位置不对应");assert(false); return false; }
		if(vecLine[57]!="Pr"){printf_message("LVAttr.csv中字段[Pr]位置不对应");assert(false); return false; }
		if(vecLine[58]!="Lr"){printf_message("LVAttr.csv中字段[Lr]位置不对应");assert(false); return false; }
		if(vecLine[59]!="Dr"){printf_message("LVAttr.csv中字段[Dr]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			LVAttrElement	member;

						member.LV=atoi(vecLine[0].c_str());
			member.STA=vecLine[1];
			member.SPI=vecLine[2];
			member.STR=vecLine[3];
			member.INT=vecLine[4];
			member.AGI=vecLine[5];
			member.HP=vecLine[6];
			member.reHP=vecLine[7];
			member.MP=vecLine[8];
			member.reMP=vecLine[9];
			member.minPA=vecLine[10];
			member.maxPA=vecLine[11];
			member.minMA=vecLine[12];
			member.maxMA=vecLine[13];
			member.PD=vecLine[14];
			member.MD=vecLine[15];
			member.igPhi=vecLine[16];
			member.igMdo=vecLine[17];
			member.Pdo=vecLine[18];
			member.Mdo=vecLine[19];
			member.igPcr=vecLine[20];
			member.igMcr=vecLine[21];
			member.Pcr=vecLine[22];
			member.Mcr=vecLine[23];
			member.igPrd=vecLine[24];
			member.igMrd=vecLine[25];
			member.Prd=vecLine[26];
			member.Mrd=vecLine[27];
			member.igBlo=vecLine[28];
			member.Blo=vecLine[29];
			member.igBrd=vecLine[30];
			member.Brd=vecLine[31];
			member.igVEr=vecLine[32];
			member.igSLr=vecLine[33];
			member.igCHr=vecLine[34];
			member.igABr=vecLine[35];
			member.igSIr=vecLine[36];
			member.igGRr=vecLine[37];
			member.igPEr=vecLine[38];
			member.VEr=vecLine[39];
			member.SLr=vecLine[40];
			member.CHr=vecLine[41];
			member.ABr=vecLine[42];
			member.SIr=vecLine[43];
			member.GRr=vecLine[44];
			member.PEr=vecLine[45];
			member.igFr=vecLine[46];
			member.igEr=vecLine[47];
			member.igWr=vecLine[48];
			member.igCr=vecLine[49];
			member.igPr=vecLine[50];
			member.igLr=vecLine[51];
			member.igDr=vecLine[52];
			member.Fr=vecLine[53];
			member.Er=vecLine[54];
			member.Wr=vecLine[55];
			member.Cr=vecLine[56];
			member.Pr=vecLine[57];
			member.Lr=vecLine[58];
			member.Dr=vecLine[59];


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.LV] = member;
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
		if(vecLine.size() != 60)
		{
			printf_message("LVAttr.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="LV"){printf_message("LVAttr.csv中字段[LV]位置不对应");assert(false); return false; }
		if(vecLine[1]!="STA"){printf_message("LVAttr.csv中字段[STA]位置不对应");assert(false); return false; }
		if(vecLine[2]!="SPI"){printf_message("LVAttr.csv中字段[SPI]位置不对应");assert(false); return false; }
		if(vecLine[3]!="STR"){printf_message("LVAttr.csv中字段[STR]位置不对应");assert(false); return false; }
		if(vecLine[4]!="INT"){printf_message("LVAttr.csv中字段[INT]位置不对应");assert(false); return false; }
		if(vecLine[5]!="AGI"){printf_message("LVAttr.csv中字段[AGI]位置不对应");assert(false); return false; }
		if(vecLine[6]!="HP"){printf_message("LVAttr.csv中字段[HP]位置不对应");assert(false); return false; }
		if(vecLine[7]!="reHP"){printf_message("LVAttr.csv中字段[reHP]位置不对应");assert(false); return false; }
		if(vecLine[8]!="MP"){printf_message("LVAttr.csv中字段[MP]位置不对应");assert(false); return false; }
		if(vecLine[9]!="reMP"){printf_message("LVAttr.csv中字段[reMP]位置不对应");assert(false); return false; }
		if(vecLine[10]!="minPA"){printf_message("LVAttr.csv中字段[minPA]位置不对应");assert(false); return false; }
		if(vecLine[11]!="maxPA"){printf_message("LVAttr.csv中字段[maxPA]位置不对应");assert(false); return false; }
		if(vecLine[12]!="minMA"){printf_message("LVAttr.csv中字段[minMA]位置不对应");assert(false); return false; }
		if(vecLine[13]!="maxMA"){printf_message("LVAttr.csv中字段[maxMA]位置不对应");assert(false); return false; }
		if(vecLine[14]!="PD"){printf_message("LVAttr.csv中字段[PD]位置不对应");assert(false); return false; }
		if(vecLine[15]!="MD"){printf_message("LVAttr.csv中字段[MD]位置不对应");assert(false); return false; }
		if(vecLine[16]!="igPhi"){printf_message("LVAttr.csv中字段[igPhi]位置不对应");assert(false); return false; }
		if(vecLine[17]!="igMdo"){printf_message("LVAttr.csv中字段[igMdo]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Pdo"){printf_message("LVAttr.csv中字段[Pdo]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Mdo"){printf_message("LVAttr.csv中字段[Mdo]位置不对应");assert(false); return false; }
		if(vecLine[20]!="igPcr"){printf_message("LVAttr.csv中字段[igPcr]位置不对应");assert(false); return false; }
		if(vecLine[21]!="igMcr"){printf_message("LVAttr.csv中字段[igMcr]位置不对应");assert(false); return false; }
		if(vecLine[22]!="Pcr"){printf_message("LVAttr.csv中字段[Pcr]位置不对应");assert(false); return false; }
		if(vecLine[23]!="Mcr"){printf_message("LVAttr.csv中字段[Mcr]位置不对应");assert(false); return false; }
		if(vecLine[24]!="igPrd"){printf_message("LVAttr.csv中字段[igPrd]位置不对应");assert(false); return false; }
		if(vecLine[25]!="igMrd"){printf_message("LVAttr.csv中字段[igMrd]位置不对应");assert(false); return false; }
		if(vecLine[26]!="Prd"){printf_message("LVAttr.csv中字段[Prd]位置不对应");assert(false); return false; }
		if(vecLine[27]!="Mrd"){printf_message("LVAttr.csv中字段[Mrd]位置不对应");assert(false); return false; }
		if(vecLine[28]!="igBlo"){printf_message("LVAttr.csv中字段[igBlo]位置不对应");assert(false); return false; }
		if(vecLine[29]!="Blo"){printf_message("LVAttr.csv中字段[Blo]位置不对应");assert(false); return false; }
		if(vecLine[30]!="igBrd"){printf_message("LVAttr.csv中字段[igBrd]位置不对应");assert(false); return false; }
		if(vecLine[31]!="Brd"){printf_message("LVAttr.csv中字段[Brd]位置不对应");assert(false); return false; }
		if(vecLine[32]!="igVEr"){printf_message("LVAttr.csv中字段[igVEr]位置不对应");assert(false); return false; }
		if(vecLine[33]!="igSLr"){printf_message("LVAttr.csv中字段[igSLr]位置不对应");assert(false); return false; }
		if(vecLine[34]!="igCHr"){printf_message("LVAttr.csv中字段[igCHr]位置不对应");assert(false); return false; }
		if(vecLine[35]!="igABr"){printf_message("LVAttr.csv中字段[igABr]位置不对应");assert(false); return false; }
		if(vecLine[36]!="igSIr"){printf_message("LVAttr.csv中字段[igSIr]位置不对应");assert(false); return false; }
		if(vecLine[37]!="igGRr"){printf_message("LVAttr.csv中字段[igGRr]位置不对应");assert(false); return false; }
		if(vecLine[38]!="igPEr"){printf_message("LVAttr.csv中字段[igPEr]位置不对应");assert(false); return false; }
		if(vecLine[39]!="VEr"){printf_message("LVAttr.csv中字段[VEr]位置不对应");assert(false); return false; }
		if(vecLine[40]!="SLr"){printf_message("LVAttr.csv中字段[SLr]位置不对应");assert(false); return false; }
		if(vecLine[41]!="CHr"){printf_message("LVAttr.csv中字段[CHr]位置不对应");assert(false); return false; }
		if(vecLine[42]!="ABr"){printf_message("LVAttr.csv中字段[ABr]位置不对应");assert(false); return false; }
		if(vecLine[43]!="SIr"){printf_message("LVAttr.csv中字段[SIr]位置不对应");assert(false); return false; }
		if(vecLine[44]!="GRr"){printf_message("LVAttr.csv中字段[GRr]位置不对应");assert(false); return false; }
		if(vecLine[45]!="PEr"){printf_message("LVAttr.csv中字段[PEr]位置不对应");assert(false); return false; }
		if(vecLine[46]!="igFr"){printf_message("LVAttr.csv中字段[igFr]位置不对应");assert(false); return false; }
		if(vecLine[47]!="igEr"){printf_message("LVAttr.csv中字段[igEr]位置不对应");assert(false); return false; }
		if(vecLine[48]!="igWr"){printf_message("LVAttr.csv中字段[igWr]位置不对应");assert(false); return false; }
		if(vecLine[49]!="igCr"){printf_message("LVAttr.csv中字段[igCr]位置不对应");assert(false); return false; }
		if(vecLine[50]!="igPr"){printf_message("LVAttr.csv中字段[igPr]位置不对应");assert(false); return false; }
		if(vecLine[51]!="igLr"){printf_message("LVAttr.csv中字段[igLr]位置不对应");assert(false); return false; }
		if(vecLine[52]!="igDr"){printf_message("LVAttr.csv中字段[igDr]位置不对应");assert(false); return false; }
		if(vecLine[53]!="Fr"){printf_message("LVAttr.csv中字段[Fr]位置不对应");assert(false); return false; }
		if(vecLine[54]!="Er"){printf_message("LVAttr.csv中字段[Er]位置不对应");assert(false); return false; }
		if(vecLine[55]!="Wr"){printf_message("LVAttr.csv中字段[Wr]位置不对应");assert(false); return false; }
		if(vecLine[56]!="Cr"){printf_message("LVAttr.csv中字段[Cr]位置不对应");assert(false); return false; }
		if(vecLine[57]!="Pr"){printf_message("LVAttr.csv中字段[Pr]位置不对应");assert(false); return false; }
		if(vecLine[58]!="Lr"){printf_message("LVAttr.csv中字段[Lr]位置不对应");assert(false); return false; }
		if(vecLine[59]!="Dr"){printf_message("LVAttr.csv中字段[Dr]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)60)
			{
				assert(false);
				return false;
			}
			LVAttrElement	member;
			member.LV=atoi(vecLine[0].c_str());
			member.STA=vecLine[1];
			member.SPI=vecLine[2];
			member.STR=vecLine[3];
			member.INT=vecLine[4];
			member.AGI=vecLine[5];
			member.HP=vecLine[6];
			member.reHP=vecLine[7];
			member.MP=vecLine[8];
			member.reMP=vecLine[9];
			member.minPA=vecLine[10];
			member.maxPA=vecLine[11];
			member.minMA=vecLine[12];
			member.maxMA=vecLine[13];
			member.PD=vecLine[14];
			member.MD=vecLine[15];
			member.igPhi=vecLine[16];
			member.igMdo=vecLine[17];
			member.Pdo=vecLine[18];
			member.Mdo=vecLine[19];
			member.igPcr=vecLine[20];
			member.igMcr=vecLine[21];
			member.Pcr=vecLine[22];
			member.Mcr=vecLine[23];
			member.igPrd=vecLine[24];
			member.igMrd=vecLine[25];
			member.Prd=vecLine[26];
			member.Mrd=vecLine[27];
			member.igBlo=vecLine[28];
			member.Blo=vecLine[29];
			member.igBrd=vecLine[30];
			member.Brd=vecLine[31];
			member.igVEr=vecLine[32];
			member.igSLr=vecLine[33];
			member.igCHr=vecLine[34];
			member.igABr=vecLine[35];
			member.igSIr=vecLine[36];
			member.igGRr=vecLine[37];
			member.igPEr=vecLine[38];
			member.VEr=vecLine[39];
			member.SLr=vecLine[40];
			member.CHr=vecLine[41];
			member.ABr=vecLine[42];
			member.SIr=vecLine[43];
			member.GRr=vecLine[44];
			member.PEr=vecLine[45];
			member.igFr=vecLine[46];
			member.igEr=vecLine[47];
			member.igWr=vecLine[48];
			member.igCr=vecLine[49];
			member.igPr=vecLine[50];
			member.igLr=vecLine[51];
			member.igDr=vecLine[52];
			member.Fr=vecLine[53];
			member.Er=vecLine[54];
			member.Wr=vecLine[55];
			member.Cr=vecLine[56];
			member.Pr=vecLine[57];
			member.Lr=vecLine[58];
			member.Dr=vecLine[59];

			member.SetIsValidate(true);
			m_mapElements[member.LV] = member;
		}
		return true;
	}
};

#endif
