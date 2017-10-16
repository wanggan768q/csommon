#ifndef __FABAO_CONFIG_H
#define __FABAO_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//法宝表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct FaBaoElement
{
	friend class FaBaoTable;
	int ID;                      	//编号	法宝ID
	string Name;                 	//法宝名称	法宝名称
	string Res;                  	//法宝图标	法宝图标
	string MiaoShu;              	//法宝描述	法宝描述
	int Model;                   	//法宝模型	法宝模型
	int Type;                    	//法宝类型	法宝类型
	int Max;                     	//最大等级	最大等级
	int Next;                    	//下一级	下一级ID
	int Star;                    	//炼星ID	炼星ID
	int SuiPian;                 	//法宝碎片	ItemID
	int PinZhi;                  	//法宝品质	法宝品质
	int Lv;                      	//法宝等级	法宝等级
	int Attr1;                   	//属性1类别	属性1类别
	int Num1;                    	//属性1初始数值	属性1初始数值
	int Attr2;                   	//属性2类别	属性2类别
	int Num2;                    	//属性2初始数值	属性2初始数值
	int Attr3;                   	//属性3类别	属性3类别
	int Num3;                    	//属性3初始数值	属性3初始数值
	int Exp;                     	//拥有经验	拥有经验
	int ExpMax;                  	//升级所需经验	升级所需经验
	int SkILL;                   	//法宝技能	法宝技能
	int Attr4;                   	//收集属性1	收集属性1
	int Num4;                    	//收集属性1数值	收集属性1数值
	int Attr5;                   	//收集属性2	收集属性2
	int Num5;                    	//收集属性2数值	收集属性2数值
	int Attr6;                   	//收集属性3	收集属性3
	int Num6;                    	//收集属性3数值	收集属性3数值
	int Sell;                    	//回收价格	回收价格
	int JuLing;                  	//初始聚灵技能	初始聚灵技能

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
	FaBaoElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//法宝表脜盲脰脙路芒脳掳脌脿
class FaBaoTable
{
	friend class TableData;
private:
	FaBaoTable(){}
	~FaBaoTable(){}
	map<int, FaBaoElement>	m_mapElements;
	vector<FaBaoElement>	m_vecAllElements;
	FaBaoElement m_emptyItem;
public:
	static FaBaoTable& Instance()
	{
		static FaBaoTable sInstance;
		return sInstance;
	}

	FaBaoElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<FaBaoElement>&	GetAllElement()
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
		return LoadJson("FaBao.json");
		#else
		string strTableContent;
		if( LoadConfigContent("FaBao.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("FaBao.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[FaBao.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("FaBao.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("FaBao.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Res"){printf_message("FaBao.csv中字段[Res]位置不对应");assert(false); return false; }
		if(vecLine[3]!="MiaoShu"){printf_message("FaBao.csv中字段[MiaoShu]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Model"){printf_message("FaBao.csv中字段[Model]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Type"){printf_message("FaBao.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Max"){printf_message("FaBao.csv中字段[Max]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Next"){printf_message("FaBao.csv中字段[Next]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Star"){printf_message("FaBao.csv中字段[Star]位置不对应");assert(false); return false; }
		if(vecLine[9]!="SuiPian"){printf_message("FaBao.csv中字段[SuiPian]位置不对应");assert(false); return false; }
		if(vecLine[10]!="PinZhi"){printf_message("FaBao.csv中字段[PinZhi]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Lv"){printf_message("FaBao.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[12]!="Attr1"){printf_message("FaBao.csv中字段[Attr1]位置不对应");assert(false); return false; }
		if(vecLine[13]!="Num1"){printf_message("FaBao.csv中字段[Num1]位置不对应");assert(false); return false; }
		if(vecLine[14]!="Attr2"){printf_message("FaBao.csv中字段[Attr2]位置不对应");assert(false); return false; }
		if(vecLine[15]!="Num2"){printf_message("FaBao.csv中字段[Num2]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Attr3"){printf_message("FaBao.csv中字段[Attr3]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Num3"){printf_message("FaBao.csv中字段[Num3]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Exp"){printf_message("FaBao.csv中字段[Exp]位置不对应");assert(false); return false; }
		if(vecLine[19]!="ExpMax"){printf_message("FaBao.csv中字段[ExpMax]位置不对应");assert(false); return false; }
		if(vecLine[20]!="SkILL"){printf_message("FaBao.csv中字段[SkILL]位置不对应");assert(false); return false; }
		if(vecLine[21]!="Attr4"){printf_message("FaBao.csv中字段[Attr4]位置不对应");assert(false); return false; }
		if(vecLine[22]!="Num4"){printf_message("FaBao.csv中字段[Num4]位置不对应");assert(false); return false; }
		if(vecLine[23]!="Attr5"){printf_message("FaBao.csv中字段[Attr5]位置不对应");assert(false); return false; }
		if(vecLine[24]!="Num5"){printf_message("FaBao.csv中字段[Num5]位置不对应");assert(false); return false; }
		if(vecLine[25]!="Attr6"){printf_message("FaBao.csv中字段[Attr6]位置不对应");assert(false); return false; }
		if(vecLine[26]!="Num6"){printf_message("FaBao.csv中字段[Num6]位置不对应");assert(false); return false; }
		if(vecLine[27]!="Sell"){printf_message("FaBao.csv中字段[Sell]位置不对应");assert(false); return false; }
		if(vecLine[28]!="JuLing"){printf_message("FaBao.csv中字段[JuLing]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			FaBaoElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Res=vecLine[2];
			member.MiaoShu=vecLine[3];
			member.Model=atoi(vecLine[4].c_str());
			member.Type=atoi(vecLine[5].c_str());
			member.Max=atoi(vecLine[6].c_str());
			member.Next=atoi(vecLine[7].c_str());
			member.Star=atoi(vecLine[8].c_str());
			member.SuiPian=atoi(vecLine[9].c_str());
			member.PinZhi=atoi(vecLine[10].c_str());
			member.Lv=atoi(vecLine[11].c_str());
			member.Attr1=atoi(vecLine[12].c_str());
			member.Num1=atoi(vecLine[13].c_str());
			member.Attr2=atoi(vecLine[14].c_str());
			member.Num2=atoi(vecLine[15].c_str());
			member.Attr3=atoi(vecLine[16].c_str());
			member.Num3=atoi(vecLine[17].c_str());
			member.Exp=atoi(vecLine[18].c_str());
			member.ExpMax=atoi(vecLine[19].c_str());
			member.SkILL=atoi(vecLine[20].c_str());
			member.Attr4=atoi(vecLine[21].c_str());
			member.Num4=atoi(vecLine[22].c_str());
			member.Attr5=atoi(vecLine[23].c_str());
			member.Num5=atoi(vecLine[24].c_str());
			member.Attr6=atoi(vecLine[25].c_str());
			member.Num6=atoi(vecLine[26].c_str());
			member.Sell=atoi(vecLine[27].c_str());
			member.JuLing=atoi(vecLine[28].c_str());


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
		if(vecLine.size() != 29)
		{
			printf_message("FaBao.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("FaBao.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("FaBao.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Res"){printf_message("FaBao.csv中字段[Res]位置不对应");assert(false); return false; }
		if(vecLine[3]!="MiaoShu"){printf_message("FaBao.csv中字段[MiaoShu]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Model"){printf_message("FaBao.csv中字段[Model]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Type"){printf_message("FaBao.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Max"){printf_message("FaBao.csv中字段[Max]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Next"){printf_message("FaBao.csv中字段[Next]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Star"){printf_message("FaBao.csv中字段[Star]位置不对应");assert(false); return false; }
		if(vecLine[9]!="SuiPian"){printf_message("FaBao.csv中字段[SuiPian]位置不对应");assert(false); return false; }
		if(vecLine[10]!="PinZhi"){printf_message("FaBao.csv中字段[PinZhi]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Lv"){printf_message("FaBao.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[12]!="Attr1"){printf_message("FaBao.csv中字段[Attr1]位置不对应");assert(false); return false; }
		if(vecLine[13]!="Num1"){printf_message("FaBao.csv中字段[Num1]位置不对应");assert(false); return false; }
		if(vecLine[14]!="Attr2"){printf_message("FaBao.csv中字段[Attr2]位置不对应");assert(false); return false; }
		if(vecLine[15]!="Num2"){printf_message("FaBao.csv中字段[Num2]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Attr3"){printf_message("FaBao.csv中字段[Attr3]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Num3"){printf_message("FaBao.csv中字段[Num3]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Exp"){printf_message("FaBao.csv中字段[Exp]位置不对应");assert(false); return false; }
		if(vecLine[19]!="ExpMax"){printf_message("FaBao.csv中字段[ExpMax]位置不对应");assert(false); return false; }
		if(vecLine[20]!="SkILL"){printf_message("FaBao.csv中字段[SkILL]位置不对应");assert(false); return false; }
		if(vecLine[21]!="Attr4"){printf_message("FaBao.csv中字段[Attr4]位置不对应");assert(false); return false; }
		if(vecLine[22]!="Num4"){printf_message("FaBao.csv中字段[Num4]位置不对应");assert(false); return false; }
		if(vecLine[23]!="Attr5"){printf_message("FaBao.csv中字段[Attr5]位置不对应");assert(false); return false; }
		if(vecLine[24]!="Num5"){printf_message("FaBao.csv中字段[Num5]位置不对应");assert(false); return false; }
		if(vecLine[25]!="Attr6"){printf_message("FaBao.csv中字段[Attr6]位置不对应");assert(false); return false; }
		if(vecLine[26]!="Num6"){printf_message("FaBao.csv中字段[Num6]位置不对应");assert(false); return false; }
		if(vecLine[27]!="Sell"){printf_message("FaBao.csv中字段[Sell]位置不对应");assert(false); return false; }
		if(vecLine[28]!="JuLing"){printf_message("FaBao.csv中字段[JuLing]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)29)
			{
				assert(false);
				return false;
			}
			FaBaoElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Res=vecLine[2];
			member.MiaoShu=vecLine[3];
			member.Model=atoi(vecLine[4].c_str());
			member.Type=atoi(vecLine[5].c_str());
			member.Max=atoi(vecLine[6].c_str());
			member.Next=atoi(vecLine[7].c_str());
			member.Star=atoi(vecLine[8].c_str());
			member.SuiPian=atoi(vecLine[9].c_str());
			member.PinZhi=atoi(vecLine[10].c_str());
			member.Lv=atoi(vecLine[11].c_str());
			member.Attr1=atoi(vecLine[12].c_str());
			member.Num1=atoi(vecLine[13].c_str());
			member.Attr2=atoi(vecLine[14].c_str());
			member.Num2=atoi(vecLine[15].c_str());
			member.Attr3=atoi(vecLine[16].c_str());
			member.Num3=atoi(vecLine[17].c_str());
			member.Exp=atoi(vecLine[18].c_str());
			member.ExpMax=atoi(vecLine[19].c_str());
			member.SkILL=atoi(vecLine[20].c_str());
			member.Attr4=atoi(vecLine[21].c_str());
			member.Num4=atoi(vecLine[22].c_str());
			member.Attr5=atoi(vecLine[23].c_str());
			member.Num5=atoi(vecLine[24].c_str());
			member.Attr6=atoi(vecLine[25].c_str());
			member.Num6=atoi(vecLine[26].c_str());
			member.Sell=atoi(vecLine[27].c_str());
			member.JuLing=atoi(vecLine[28].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
