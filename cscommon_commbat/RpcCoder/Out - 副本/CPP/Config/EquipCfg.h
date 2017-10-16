#ifndef __EQUIP_CONFIG_H
#define __EQUIP_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//装备脜盲脰脙脢媒戮脻陆谩鹿鹿
struct EquipElement
{
	friend class EquipTable;
	int EquipID;                 	//编号	装备ID
	int Type;                    	//类型	装备类型（1武器2衣服3头盔4腰带5手套6鞋子7玉佩8副手9戒指10手镯）
	string Name;                 	//装备名称	装备名称
	int LV;                      	//装备等级	装备等级
	string ZhiYe;                	//所属职业	所属职业
	string Res;                  	//装备资源	装备资源
	int Colour;                  	//初始品质	初始品质（2白色2绿色3蓝色4紫色5橙色6红色）
	int XiangQian;               	//可镶嵌槽位	
	int DaKong;                  	//打孔道具	打孔道具
	int XiLian;                  	//洗炼道具	洗炼道具
	int XiaoHao;                 	//消耗数量	消耗数量
	int JiChuXiLian;             	//基础洗炼	基础洗炼
	int XiLianXiaoHao;           	//基础洗炼消耗	基础洗炼消耗
	int ISGaiZao;                	//是否能改造	1可以-1不可以
	int GaiZao;                  	//装备改造	装备改造
	int GaiZaoXiaoHao;           	//改造消耗	改造消耗
	string Attribute;            	//属性	对应属性（1物理攻击2法术攻击3HP上限4物理防御5法术防御6暴击等级7必杀等级8破盾等级9格挡10格挡减免）
	string Num1;                 	//基础属性阈值1	基础属性阈值1
	string Num2;                 	//基础属性阈值2	基础属性阈值2
	string Num3;                 	//基础属性阈值3	基础属性阈值3
	string Num4;                 	//基础属性阈值4	基础属性阈值4
	float JinHua;                	//每增加一条属性增加倍率	每增加一条属性增加倍率
	string FuJia;                	//附加属性库	附加属性库
	int MAX;                     	//最大附加条数	最大附加条数
	string GuDing;               	//固定附加	固定附加（白0，绿3，蓝4，紫5，橙5，红）
	string FuJiaNum;             	//随机附加数量权值	随机附加数量权值
	int Decompose;               	//分解	是否可分解
	int DecomposeID;             	//分解道具	分解出的道具
	int Nummin;                  	//分解道具数量下限	分解道具数量
	int Price;                   	//价格	分解价格
	int DelPrice;                	//回收价格	回收价格
	int BuyPrick;                	//取回价格	取回价格
	int  Valuabl;                	//是否为珍贵物品	是否为珍贵物品
	int ModelId;                 	//模型ID	模型ID
	string EffectID;             	//模型动画	模型动画

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
	EquipElement()
	{
		EquipID = -1;
		m_bIsValidate=false;
	}
};

//装备脜盲脰脙路芒脳掳脌脿
class EquipTable
{
	friend class TableData;
private:
	EquipTable(){}
	~EquipTable(){}
	map<int, EquipElement>	m_mapElements;
	vector<EquipElement>	m_vecAllElements;
	EquipElement m_emptyItem;
public:
	static EquipTable& Instance()
	{
		static EquipTable sInstance;
		return sInstance;
	}

	EquipElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<EquipElement>&	GetAllElement()
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
		return LoadJson("Equip.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Equip.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Equip.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Equip.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="EquipID"){printf_message("Equip.csv中字段[EquipID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Type"){printf_message("Equip.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Name"){printf_message("Equip.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[3]!="LV"){printf_message("Equip.csv中字段[LV]位置不对应");assert(false); return false; }
		if(vecLine[4]!="ZhiYe"){printf_message("Equip.csv中字段[ZhiYe]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Res"){printf_message("Equip.csv中字段[Res]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Colour"){printf_message("Equip.csv中字段[Colour]位置不对应");assert(false); return false; }
		if(vecLine[7]!="XiangQian"){printf_message("Equip.csv中字段[XiangQian]位置不对应");assert(false); return false; }
		if(vecLine[8]!="DaKong"){printf_message("Equip.csv中字段[DaKong]位置不对应");assert(false); return false; }
		if(vecLine[9]!="XiLian"){printf_message("Equip.csv中字段[XiLian]位置不对应");assert(false); return false; }
		if(vecLine[10]!="XiaoHao"){printf_message("Equip.csv中字段[XiaoHao]位置不对应");assert(false); return false; }
		if(vecLine[11]!="JiChuXiLian"){printf_message("Equip.csv中字段[JiChuXiLian]位置不对应");assert(false); return false; }
		if(vecLine[12]!="XiLianXiaoHao"){printf_message("Equip.csv中字段[XiLianXiaoHao]位置不对应");assert(false); return false; }
		if(vecLine[13]!="ISGaiZao"){printf_message("Equip.csv中字段[ISGaiZao]位置不对应");assert(false); return false; }
		if(vecLine[14]!="GaiZao"){printf_message("Equip.csv中字段[GaiZao]位置不对应");assert(false); return false; }
		if(vecLine[15]!="GaiZaoXiaoHao"){printf_message("Equip.csv中字段[GaiZaoXiaoHao]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Attribute"){printf_message("Equip.csv中字段[Attribute]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Num1"){printf_message("Equip.csv中字段[Num1]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Num2"){printf_message("Equip.csv中字段[Num2]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Num3"){printf_message("Equip.csv中字段[Num3]位置不对应");assert(false); return false; }
		if(vecLine[20]!="Num4"){printf_message("Equip.csv中字段[Num4]位置不对应");assert(false); return false; }
		if(vecLine[21]!="JinHua"){printf_message("Equip.csv中字段[JinHua]位置不对应");assert(false); return false; }
		if(vecLine[22]!="FuJia"){printf_message("Equip.csv中字段[FuJia]位置不对应");assert(false); return false; }
		if(vecLine[23]!="MAX"){printf_message("Equip.csv中字段[MAX]位置不对应");assert(false); return false; }
		if(vecLine[24]!="GuDing"){printf_message("Equip.csv中字段[GuDing]位置不对应");assert(false); return false; }
		if(vecLine[25]!="FuJiaNum"){printf_message("Equip.csv中字段[FuJiaNum]位置不对应");assert(false); return false; }
		if(vecLine[26]!="Decompose"){printf_message("Equip.csv中字段[Decompose]位置不对应");assert(false); return false; }
		if(vecLine[27]!="DecomposeID"){printf_message("Equip.csv中字段[DecomposeID]位置不对应");assert(false); return false; }
		if(vecLine[28]!="Nummin"){printf_message("Equip.csv中字段[Nummin]位置不对应");assert(false); return false; }
		if(vecLine[29]!="Price"){printf_message("Equip.csv中字段[Price]位置不对应");assert(false); return false; }
		if(vecLine[30]!="DelPrice"){printf_message("Equip.csv中字段[DelPrice]位置不对应");assert(false); return false; }
		if(vecLine[31]!="BuyPrick"){printf_message("Equip.csv中字段[BuyPrick]位置不对应");assert(false); return false; }
		if(vecLine[32]!=" Valuabl"){printf_message("Equip.csv中字段[ Valuabl]位置不对应");assert(false); return false; }
		if(vecLine[33]!="ModelId"){printf_message("Equip.csv中字段[ModelId]位置不对应");assert(false); return false; }
		if(vecLine[34]!="EffectID"){printf_message("Equip.csv中字段[EffectID]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			EquipElement	member;

						member.EquipID=atoi(vecLine[0].c_str());
			member.Type=atoi(vecLine[1].c_str());
			member.Name=vecLine[2];
			member.LV=atoi(vecLine[3].c_str());
			member.ZhiYe=vecLine[4];
			member.Res=vecLine[5];
			member.Colour=atoi(vecLine[6].c_str());
			member.XiangQian=atoi(vecLine[7].c_str());
			member.DaKong=atoi(vecLine[8].c_str());
			member.XiLian=atoi(vecLine[9].c_str());
			member.XiaoHao=atoi(vecLine[10].c_str());
			member.JiChuXiLian=atoi(vecLine[11].c_str());
			member.XiLianXiaoHao=atoi(vecLine[12].c_str());
			member.ISGaiZao=atoi(vecLine[13].c_str());
			member.GaiZao=atoi(vecLine[14].c_str());
			member.GaiZaoXiaoHao=atoi(vecLine[15].c_str());
			member.Attribute=vecLine[16];
			member.Num1=vecLine[17];
			member.Num2=vecLine[18];
			member.Num3=vecLine[19];
			member.Num4=vecLine[20];
			member.JinHua=atof(vecLine[21].c_str());
			member.FuJia=vecLine[22];
			member.MAX=atoi(vecLine[23].c_str());
			member.GuDing=vecLine[24];
			member.FuJiaNum=vecLine[25];
			member.Decompose=atoi(vecLine[26].c_str());
			member.DecomposeID=atoi(vecLine[27].c_str());
			member.Nummin=atoi(vecLine[28].c_str());
			member.Price=atoi(vecLine[29].c_str());
			member.DelPrice=atoi(vecLine[30].c_str());
			member.BuyPrick=atoi(vecLine[31].c_str());
			member. Valuabl=atoi(vecLine[32].c_str());
			member.ModelId=atoi(vecLine[33].c_str());
			member.EffectID=vecLine[34];


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.EquipID] = member;
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
		if(vecLine.size() != 35)
		{
			printf_message("Equip.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="EquipID"){printf_message("Equip.csv中字段[EquipID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Type"){printf_message("Equip.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Name"){printf_message("Equip.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[3]!="LV"){printf_message("Equip.csv中字段[LV]位置不对应");assert(false); return false; }
		if(vecLine[4]!="ZhiYe"){printf_message("Equip.csv中字段[ZhiYe]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Res"){printf_message("Equip.csv中字段[Res]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Colour"){printf_message("Equip.csv中字段[Colour]位置不对应");assert(false); return false; }
		if(vecLine[7]!="XiangQian"){printf_message("Equip.csv中字段[XiangQian]位置不对应");assert(false); return false; }
		if(vecLine[8]!="DaKong"){printf_message("Equip.csv中字段[DaKong]位置不对应");assert(false); return false; }
		if(vecLine[9]!="XiLian"){printf_message("Equip.csv中字段[XiLian]位置不对应");assert(false); return false; }
		if(vecLine[10]!="XiaoHao"){printf_message("Equip.csv中字段[XiaoHao]位置不对应");assert(false); return false; }
		if(vecLine[11]!="JiChuXiLian"){printf_message("Equip.csv中字段[JiChuXiLian]位置不对应");assert(false); return false; }
		if(vecLine[12]!="XiLianXiaoHao"){printf_message("Equip.csv中字段[XiLianXiaoHao]位置不对应");assert(false); return false; }
		if(vecLine[13]!="ISGaiZao"){printf_message("Equip.csv中字段[ISGaiZao]位置不对应");assert(false); return false; }
		if(vecLine[14]!="GaiZao"){printf_message("Equip.csv中字段[GaiZao]位置不对应");assert(false); return false; }
		if(vecLine[15]!="GaiZaoXiaoHao"){printf_message("Equip.csv中字段[GaiZaoXiaoHao]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Attribute"){printf_message("Equip.csv中字段[Attribute]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Num1"){printf_message("Equip.csv中字段[Num1]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Num2"){printf_message("Equip.csv中字段[Num2]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Num3"){printf_message("Equip.csv中字段[Num3]位置不对应");assert(false); return false; }
		if(vecLine[20]!="Num4"){printf_message("Equip.csv中字段[Num4]位置不对应");assert(false); return false; }
		if(vecLine[21]!="JinHua"){printf_message("Equip.csv中字段[JinHua]位置不对应");assert(false); return false; }
		if(vecLine[22]!="FuJia"){printf_message("Equip.csv中字段[FuJia]位置不对应");assert(false); return false; }
		if(vecLine[23]!="MAX"){printf_message("Equip.csv中字段[MAX]位置不对应");assert(false); return false; }
		if(vecLine[24]!="GuDing"){printf_message("Equip.csv中字段[GuDing]位置不对应");assert(false); return false; }
		if(vecLine[25]!="FuJiaNum"){printf_message("Equip.csv中字段[FuJiaNum]位置不对应");assert(false); return false; }
		if(vecLine[26]!="Decompose"){printf_message("Equip.csv中字段[Decompose]位置不对应");assert(false); return false; }
		if(vecLine[27]!="DecomposeID"){printf_message("Equip.csv中字段[DecomposeID]位置不对应");assert(false); return false; }
		if(vecLine[28]!="Nummin"){printf_message("Equip.csv中字段[Nummin]位置不对应");assert(false); return false; }
		if(vecLine[29]!="Price"){printf_message("Equip.csv中字段[Price]位置不对应");assert(false); return false; }
		if(vecLine[30]!="DelPrice"){printf_message("Equip.csv中字段[DelPrice]位置不对应");assert(false); return false; }
		if(vecLine[31]!="BuyPrick"){printf_message("Equip.csv中字段[BuyPrick]位置不对应");assert(false); return false; }
		if(vecLine[32]!=" Valuabl"){printf_message("Equip.csv中字段[ Valuabl]位置不对应");assert(false); return false; }
		if(vecLine[33]!="ModelId"){printf_message("Equip.csv中字段[ModelId]位置不对应");assert(false); return false; }
		if(vecLine[34]!="EffectID"){printf_message("Equip.csv中字段[EffectID]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)35)
			{
				assert(false);
				return false;
			}
			EquipElement	member;
			member.EquipID=atoi(vecLine[0].c_str());
			member.Type=atoi(vecLine[1].c_str());
			member.Name=vecLine[2];
			member.LV=atoi(vecLine[3].c_str());
			member.ZhiYe=vecLine[4];
			member.Res=vecLine[5];
			member.Colour=atoi(vecLine[6].c_str());
			member.XiangQian=atoi(vecLine[7].c_str());
			member.DaKong=atoi(vecLine[8].c_str());
			member.XiLian=atoi(vecLine[9].c_str());
			member.XiaoHao=atoi(vecLine[10].c_str());
			member.JiChuXiLian=atoi(vecLine[11].c_str());
			member.XiLianXiaoHao=atoi(vecLine[12].c_str());
			member.ISGaiZao=atoi(vecLine[13].c_str());
			member.GaiZao=atoi(vecLine[14].c_str());
			member.GaiZaoXiaoHao=atoi(vecLine[15].c_str());
			member.Attribute=vecLine[16];
			member.Num1=vecLine[17];
			member.Num2=vecLine[18];
			member.Num3=vecLine[19];
			member.Num4=vecLine[20];
			member.JinHua=atof(vecLine[21].c_str());
			member.FuJia=vecLine[22];
			member.MAX=atoi(vecLine[23].c_str());
			member.GuDing=vecLine[24];
			member.FuJiaNum=vecLine[25];
			member.Decompose=atoi(vecLine[26].c_str());
			member.DecomposeID=atoi(vecLine[27].c_str());
			member.Nummin=atoi(vecLine[28].c_str());
			member.Price=atoi(vecLine[29].c_str());
			member.DelPrice=atoi(vecLine[30].c_str());
			member.BuyPrick=atoi(vecLine[31].c_str());
			member. Valuabl=atoi(vecLine[32].c_str());
			member.ModelId=atoi(vecLine[33].c_str());
			member.EffectID=vecLine[34];

			member.SetIsValidate(true);
			m_mapElements[member.EquipID] = member;
		}
		return true;
	}
};

#endif
