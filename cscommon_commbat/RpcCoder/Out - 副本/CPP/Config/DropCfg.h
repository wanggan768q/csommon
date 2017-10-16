#ifndef __DROP_CONFIG_H
#define __DROP_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//掉落表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct DropElement
{
	friend class DropTable;
	int DropID;                  	//掉落ID	掉落索引参数
	string Desc;                 	//描述	策划用备注该掉落列作用
	int DropType;                	//掉落类型	1为概率掉落，2为权重掉落（权重之和为10000）
	int MoneyType1;              	//1金钱类型	索引Money表（11-金币，12-钻石）
	int MoneyMaxValue1;          	//1金钱最大值	金钱掉落随机区间的最大值
	int MoneyMinValue1;          	//1金钱最小值	金钱掉落随机区间的最小值
	int MoneyType2;              	//2金钱类型	索引Money表
	int MoneyMaxValue2;          	//2金钱最大值	金钱掉落随机区间的最大值
	int MoneyMinValue2;          	//2金钱最小值	金钱掉落随机区间的最小值
	int BagType1;                	//1掉落包类型	1为掉落包，2为道具
	int BagParamete1;            	//1掉落包参数	如果DropType为1则为万分比的概率值，如果为2则为权重值
	int Bag1;                    	//1掉落包内容	根据BagType确定是掉落包还是物品ID
	int BagNum1;                 	//1掉落包数量	掉落的数量
	int BagType2;                	//2掉落包类型	1为掉落包，2为道具
	int BagParamete2;            	//2掉落包参数	如果DropType为1则为万分比的概率值，如果为2则为权重值
	int Bag2;                    	//2掉落包内容	根据BagType确定是掉落包还是物品ID
	int BagNum2;                 	//2掉落包数量	掉落的数量
	int BagType3;                	//3掉落包类型	1为掉落包，2为道具
	int BagParamete3;            	//3掉落包参数	如果DropType为1则为万分比的概率值，如果为2则为权重值
	int Bag3;                    	//3掉落包内容	根据BagType确定是掉落包还是物品ID
	int BagNum3;                 	//3掉落包数量	掉落的数量
	int BagType4;                	//4掉落包类型	1为掉落包，2为道具
	int BagParamete4;            	//4掉落包参数	如果DropType为1则为万分比的概率值，如果为2则为权重值
	int Bag4;                    	//4掉落包内容	根据BagType确定是掉落包还是物品ID
	int BagNum4;                 	//4掉落包数量	掉落的数量
	int BagType5;                	//5掉落包类型	1为掉落包，2为道具
	int BagParamete5;            	//5掉落包参数	如果DropType为1则为万分比的概率值，如果为2则为权重值
	int Bag5;                    	//5掉落包内容	根据BagType确定是掉落包还是物品ID
	int BagNum5;                 	//5掉落包数量	掉落的数量

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
	DropElement()
	{
		DropID = -1;
		m_bIsValidate=false;
	}
};

//掉落表脜盲脰脙路芒脳掳脌脿
class DropTable
{
	friend class TableData;
private:
	DropTable(){}
	~DropTable(){}
	map<int, DropElement>	m_mapElements;
	vector<DropElement>	m_vecAllElements;
	DropElement m_emptyItem;
public:
	static DropTable& Instance()
	{
		static DropTable sInstance;
		return sInstance;
	}

	DropElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<DropElement>&	GetAllElement()
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
		return LoadJson("Drop.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Drop.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Drop.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Drop.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="DropID"){printf_message("Drop.csv中字段[DropID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Desc"){printf_message("Drop.csv中字段[Desc]位置不对应");assert(false); return false; }
		if(vecLine[2]!="DropType"){printf_message("Drop.csv中字段[DropType]位置不对应");assert(false); return false; }
		if(vecLine[3]!="MoneyType1"){printf_message("Drop.csv中字段[MoneyType1]位置不对应");assert(false); return false; }
		if(vecLine[4]!="MoneyMaxValue1"){printf_message("Drop.csv中字段[MoneyMaxValue1]位置不对应");assert(false); return false; }
		if(vecLine[5]!="MoneyMinValue1"){printf_message("Drop.csv中字段[MoneyMinValue1]位置不对应");assert(false); return false; }
		if(vecLine[6]!="MoneyType2"){printf_message("Drop.csv中字段[MoneyType2]位置不对应");assert(false); return false; }
		if(vecLine[7]!="MoneyMaxValue2"){printf_message("Drop.csv中字段[MoneyMaxValue2]位置不对应");assert(false); return false; }
		if(vecLine[8]!="MoneyMinValue2"){printf_message("Drop.csv中字段[MoneyMinValue2]位置不对应");assert(false); return false; }
		if(vecLine[9]!="BagType1"){printf_message("Drop.csv中字段[BagType1]位置不对应");assert(false); return false; }
		if(vecLine[10]!="BagParamete1"){printf_message("Drop.csv中字段[BagParamete1]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Bag1"){printf_message("Drop.csv中字段[Bag1]位置不对应");assert(false); return false; }
		if(vecLine[12]!="BagNum1"){printf_message("Drop.csv中字段[BagNum1]位置不对应");assert(false); return false; }
		if(vecLine[13]!="BagType2"){printf_message("Drop.csv中字段[BagType2]位置不对应");assert(false); return false; }
		if(vecLine[14]!="BagParamete2"){printf_message("Drop.csv中字段[BagParamete2]位置不对应");assert(false); return false; }
		if(vecLine[15]!="Bag2"){printf_message("Drop.csv中字段[Bag2]位置不对应");assert(false); return false; }
		if(vecLine[16]!="BagNum2"){printf_message("Drop.csv中字段[BagNum2]位置不对应");assert(false); return false; }
		if(vecLine[17]!="BagType3"){printf_message("Drop.csv中字段[BagType3]位置不对应");assert(false); return false; }
		if(vecLine[18]!="BagParamete3"){printf_message("Drop.csv中字段[BagParamete3]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Bag3"){printf_message("Drop.csv中字段[Bag3]位置不对应");assert(false); return false; }
		if(vecLine[20]!="BagNum3"){printf_message("Drop.csv中字段[BagNum3]位置不对应");assert(false); return false; }
		if(vecLine[21]!="BagType4"){printf_message("Drop.csv中字段[BagType4]位置不对应");assert(false); return false; }
		if(vecLine[22]!="BagParamete4"){printf_message("Drop.csv中字段[BagParamete4]位置不对应");assert(false); return false; }
		if(vecLine[23]!="Bag4"){printf_message("Drop.csv中字段[Bag4]位置不对应");assert(false); return false; }
		if(vecLine[24]!="BagNum4"){printf_message("Drop.csv中字段[BagNum4]位置不对应");assert(false); return false; }
		if(vecLine[25]!="BagType5"){printf_message("Drop.csv中字段[BagType5]位置不对应");assert(false); return false; }
		if(vecLine[26]!="BagParamete5"){printf_message("Drop.csv中字段[BagParamete5]位置不对应");assert(false); return false; }
		if(vecLine[27]!="Bag5"){printf_message("Drop.csv中字段[Bag5]位置不对应");assert(false); return false; }
		if(vecLine[28]!="BagNum5"){printf_message("Drop.csv中字段[BagNum5]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			DropElement	member;

						member.DropID=atoi(vecLine[0].c_str());
			member.Desc=vecLine[1];
			member.DropType=atoi(vecLine[2].c_str());
			member.MoneyType1=atoi(vecLine[3].c_str());
			member.MoneyMaxValue1=atoi(vecLine[4].c_str());
			member.MoneyMinValue1=atoi(vecLine[5].c_str());
			member.MoneyType2=atoi(vecLine[6].c_str());
			member.MoneyMaxValue2=atoi(vecLine[7].c_str());
			member.MoneyMinValue2=atoi(vecLine[8].c_str());
			member.BagType1=atoi(vecLine[9].c_str());
			member.BagParamete1=atoi(vecLine[10].c_str());
			member.Bag1=atoi(vecLine[11].c_str());
			member.BagNum1=atoi(vecLine[12].c_str());
			member.BagType2=atoi(vecLine[13].c_str());
			member.BagParamete2=atoi(vecLine[14].c_str());
			member.Bag2=atoi(vecLine[15].c_str());
			member.BagNum2=atoi(vecLine[16].c_str());
			member.BagType3=atoi(vecLine[17].c_str());
			member.BagParamete3=atoi(vecLine[18].c_str());
			member.Bag3=atoi(vecLine[19].c_str());
			member.BagNum3=atoi(vecLine[20].c_str());
			member.BagType4=atoi(vecLine[21].c_str());
			member.BagParamete4=atoi(vecLine[22].c_str());
			member.Bag4=atoi(vecLine[23].c_str());
			member.BagNum4=atoi(vecLine[24].c_str());
			member.BagType5=atoi(vecLine[25].c_str());
			member.BagParamete5=atoi(vecLine[26].c_str());
			member.Bag5=atoi(vecLine[27].c_str());
			member.BagNum5=atoi(vecLine[28].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.DropID] = member;
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
			printf_message("Drop.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="DropID"){printf_message("Drop.csv中字段[DropID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Desc"){printf_message("Drop.csv中字段[Desc]位置不对应");assert(false); return false; }
		if(vecLine[2]!="DropType"){printf_message("Drop.csv中字段[DropType]位置不对应");assert(false); return false; }
		if(vecLine[3]!="MoneyType1"){printf_message("Drop.csv中字段[MoneyType1]位置不对应");assert(false); return false; }
		if(vecLine[4]!="MoneyMaxValue1"){printf_message("Drop.csv中字段[MoneyMaxValue1]位置不对应");assert(false); return false; }
		if(vecLine[5]!="MoneyMinValue1"){printf_message("Drop.csv中字段[MoneyMinValue1]位置不对应");assert(false); return false; }
		if(vecLine[6]!="MoneyType2"){printf_message("Drop.csv中字段[MoneyType2]位置不对应");assert(false); return false; }
		if(vecLine[7]!="MoneyMaxValue2"){printf_message("Drop.csv中字段[MoneyMaxValue2]位置不对应");assert(false); return false; }
		if(vecLine[8]!="MoneyMinValue2"){printf_message("Drop.csv中字段[MoneyMinValue2]位置不对应");assert(false); return false; }
		if(vecLine[9]!="BagType1"){printf_message("Drop.csv中字段[BagType1]位置不对应");assert(false); return false; }
		if(vecLine[10]!="BagParamete1"){printf_message("Drop.csv中字段[BagParamete1]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Bag1"){printf_message("Drop.csv中字段[Bag1]位置不对应");assert(false); return false; }
		if(vecLine[12]!="BagNum1"){printf_message("Drop.csv中字段[BagNum1]位置不对应");assert(false); return false; }
		if(vecLine[13]!="BagType2"){printf_message("Drop.csv中字段[BagType2]位置不对应");assert(false); return false; }
		if(vecLine[14]!="BagParamete2"){printf_message("Drop.csv中字段[BagParamete2]位置不对应");assert(false); return false; }
		if(vecLine[15]!="Bag2"){printf_message("Drop.csv中字段[Bag2]位置不对应");assert(false); return false; }
		if(vecLine[16]!="BagNum2"){printf_message("Drop.csv中字段[BagNum2]位置不对应");assert(false); return false; }
		if(vecLine[17]!="BagType3"){printf_message("Drop.csv中字段[BagType3]位置不对应");assert(false); return false; }
		if(vecLine[18]!="BagParamete3"){printf_message("Drop.csv中字段[BagParamete3]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Bag3"){printf_message("Drop.csv中字段[Bag3]位置不对应");assert(false); return false; }
		if(vecLine[20]!="BagNum3"){printf_message("Drop.csv中字段[BagNum3]位置不对应");assert(false); return false; }
		if(vecLine[21]!="BagType4"){printf_message("Drop.csv中字段[BagType4]位置不对应");assert(false); return false; }
		if(vecLine[22]!="BagParamete4"){printf_message("Drop.csv中字段[BagParamete4]位置不对应");assert(false); return false; }
		if(vecLine[23]!="Bag4"){printf_message("Drop.csv中字段[Bag4]位置不对应");assert(false); return false; }
		if(vecLine[24]!="BagNum4"){printf_message("Drop.csv中字段[BagNum4]位置不对应");assert(false); return false; }
		if(vecLine[25]!="BagType5"){printf_message("Drop.csv中字段[BagType5]位置不对应");assert(false); return false; }
		if(vecLine[26]!="BagParamete5"){printf_message("Drop.csv中字段[BagParamete5]位置不对应");assert(false); return false; }
		if(vecLine[27]!="Bag5"){printf_message("Drop.csv中字段[Bag5]位置不对应");assert(false); return false; }
		if(vecLine[28]!="BagNum5"){printf_message("Drop.csv中字段[BagNum5]位置不对应");assert(false); return false; }

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
			DropElement	member;
			member.DropID=atoi(vecLine[0].c_str());
			member.Desc=vecLine[1];
			member.DropType=atoi(vecLine[2].c_str());
			member.MoneyType1=atoi(vecLine[3].c_str());
			member.MoneyMaxValue1=atoi(vecLine[4].c_str());
			member.MoneyMinValue1=atoi(vecLine[5].c_str());
			member.MoneyType2=atoi(vecLine[6].c_str());
			member.MoneyMaxValue2=atoi(vecLine[7].c_str());
			member.MoneyMinValue2=atoi(vecLine[8].c_str());
			member.BagType1=atoi(vecLine[9].c_str());
			member.BagParamete1=atoi(vecLine[10].c_str());
			member.Bag1=atoi(vecLine[11].c_str());
			member.BagNum1=atoi(vecLine[12].c_str());
			member.BagType2=atoi(vecLine[13].c_str());
			member.BagParamete2=atoi(vecLine[14].c_str());
			member.Bag2=atoi(vecLine[15].c_str());
			member.BagNum2=atoi(vecLine[16].c_str());
			member.BagType3=atoi(vecLine[17].c_str());
			member.BagParamete3=atoi(vecLine[18].c_str());
			member.Bag3=atoi(vecLine[19].c_str());
			member.BagNum3=atoi(vecLine[20].c_str());
			member.BagType4=atoi(vecLine[21].c_str());
			member.BagParamete4=atoi(vecLine[22].c_str());
			member.Bag4=atoi(vecLine[23].c_str());
			member.BagNum4=atoi(vecLine[24].c_str());
			member.BagType5=atoi(vecLine[25].c_str());
			member.BagParamete5=atoi(vecLine[26].c_str());
			member.Bag5=atoi(vecLine[27].c_str());
			member.BagNum5=atoi(vecLine[28].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.DropID] = member;
		}
		return true;
	}
};

#endif
