#ifndef __FABAOSTAR_CONFIG_H
#define __FABAOSTAR_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//法宝炼星表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct FaBaoStarElement
{
	friend class FaBaoStarTable;
	int ID;                      	//编号	法宝ID
	int SuiPian1;                	//2星消耗碎片	3星消耗碎片
	int Money1;                  	//2星消耗金钱	2星消耗金钱
	int Rate1;                   	//2星成长倍率	2星成长倍率
	int SuiPian2;                	//3星消耗碎片	4星消耗碎片
	int Money2;                  	//3星消耗金钱	3星消耗金钱
	int Rate2;                   	//3星成长倍率	3星成长倍率
	int SuiPian3;                	//4星消耗碎片	5星消耗碎片
	int Money3;                  	//4星消耗金钱	4星消耗金钱
	int Rate3;                   	//4星成长倍率	4星成长倍率
	int SuiPian4;                	//5星消耗碎片	6星消耗碎片
	int Money4;                  	//5星消耗金钱	5星消耗金钱
	int Rate4;                   	//5星成长倍率	5星成长倍率
	int SuiPian5;                	//6星消耗碎片	7星消耗碎片
	int Money5;                  	//6星消耗金钱	6星消耗金钱
	int Rate5;                   	//6星成长倍率	6星成长倍率
	int SuiPian6;                	//7星消耗碎片	8星消耗碎片
	int Money6;                  	//7星消耗金钱	7星消耗金钱
	int Rate6;                   	//7星成长倍率	7星成长倍率

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
	FaBaoStarElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//法宝炼星表脜盲脰脙路芒脳掳脌脿
class FaBaoStarTable
{
	friend class TableData;
private:
	FaBaoStarTable(){}
	~FaBaoStarTable(){}
	map<int, FaBaoStarElement>	m_mapElements;
	vector<FaBaoStarElement>	m_vecAllElements;
	FaBaoStarElement m_emptyItem;
public:
	static FaBaoStarTable& Instance()
	{
		static FaBaoStarTable sInstance;
		return sInstance;
	}

	FaBaoStarElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<FaBaoStarElement>&	GetAllElement()
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
		return LoadJson("FaBaoStar.json");
		#else
		string strTableContent;
		if( LoadConfigContent("FaBaoStar.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("FaBaoStar.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[FaBaoStar.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("FaBaoStar.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="SuiPian1"){printf_message("FaBaoStar.csv中字段[SuiPian1]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Money1"){printf_message("FaBaoStar.csv中字段[Money1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Rate1"){printf_message("FaBaoStar.csv中字段[Rate1]位置不对应");assert(false); return false; }
		if(vecLine[4]!="SuiPian2"){printf_message("FaBaoStar.csv中字段[SuiPian2]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Money2"){printf_message("FaBaoStar.csv中字段[Money2]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Rate2"){printf_message("FaBaoStar.csv中字段[Rate2]位置不对应");assert(false); return false; }
		if(vecLine[7]!="SuiPian3"){printf_message("FaBaoStar.csv中字段[SuiPian3]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Money3"){printf_message("FaBaoStar.csv中字段[Money3]位置不对应");assert(false); return false; }
		if(vecLine[9]!="Rate3"){printf_message("FaBaoStar.csv中字段[Rate3]位置不对应");assert(false); return false; }
		if(vecLine[10]!="SuiPian4"){printf_message("FaBaoStar.csv中字段[SuiPian4]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Money4"){printf_message("FaBaoStar.csv中字段[Money4]位置不对应");assert(false); return false; }
		if(vecLine[12]!="Rate4"){printf_message("FaBaoStar.csv中字段[Rate4]位置不对应");assert(false); return false; }
		if(vecLine[13]!="SuiPian5"){printf_message("FaBaoStar.csv中字段[SuiPian5]位置不对应");assert(false); return false; }
		if(vecLine[14]!="Money5"){printf_message("FaBaoStar.csv中字段[Money5]位置不对应");assert(false); return false; }
		if(vecLine[15]!="Rate5"){printf_message("FaBaoStar.csv中字段[Rate5]位置不对应");assert(false); return false; }
		if(vecLine[16]!="SuiPian6"){printf_message("FaBaoStar.csv中字段[SuiPian6]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Money6"){printf_message("FaBaoStar.csv中字段[Money6]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Rate6"){printf_message("FaBaoStar.csv中字段[Rate6]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			FaBaoStarElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.SuiPian1=atoi(vecLine[1].c_str());
			member.Money1=atoi(vecLine[2].c_str());
			member.Rate1=atoi(vecLine[3].c_str());
			member.SuiPian2=atoi(vecLine[4].c_str());
			member.Money2=atoi(vecLine[5].c_str());
			member.Rate2=atoi(vecLine[6].c_str());
			member.SuiPian3=atoi(vecLine[7].c_str());
			member.Money3=atoi(vecLine[8].c_str());
			member.Rate3=atoi(vecLine[9].c_str());
			member.SuiPian4=atoi(vecLine[10].c_str());
			member.Money4=atoi(vecLine[11].c_str());
			member.Rate4=atoi(vecLine[12].c_str());
			member.SuiPian5=atoi(vecLine[13].c_str());
			member.Money5=atoi(vecLine[14].c_str());
			member.Rate5=atoi(vecLine[15].c_str());
			member.SuiPian6=atoi(vecLine[16].c_str());
			member.Money6=atoi(vecLine[17].c_str());
			member.Rate6=atoi(vecLine[18].c_str());


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
		if(vecLine.size() != 19)
		{
			printf_message("FaBaoStar.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("FaBaoStar.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="SuiPian1"){printf_message("FaBaoStar.csv中字段[SuiPian1]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Money1"){printf_message("FaBaoStar.csv中字段[Money1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Rate1"){printf_message("FaBaoStar.csv中字段[Rate1]位置不对应");assert(false); return false; }
		if(vecLine[4]!="SuiPian2"){printf_message("FaBaoStar.csv中字段[SuiPian2]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Money2"){printf_message("FaBaoStar.csv中字段[Money2]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Rate2"){printf_message("FaBaoStar.csv中字段[Rate2]位置不对应");assert(false); return false; }
		if(vecLine[7]!="SuiPian3"){printf_message("FaBaoStar.csv中字段[SuiPian3]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Money3"){printf_message("FaBaoStar.csv中字段[Money3]位置不对应");assert(false); return false; }
		if(vecLine[9]!="Rate3"){printf_message("FaBaoStar.csv中字段[Rate3]位置不对应");assert(false); return false; }
		if(vecLine[10]!="SuiPian4"){printf_message("FaBaoStar.csv中字段[SuiPian4]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Money4"){printf_message("FaBaoStar.csv中字段[Money4]位置不对应");assert(false); return false; }
		if(vecLine[12]!="Rate4"){printf_message("FaBaoStar.csv中字段[Rate4]位置不对应");assert(false); return false; }
		if(vecLine[13]!="SuiPian5"){printf_message("FaBaoStar.csv中字段[SuiPian5]位置不对应");assert(false); return false; }
		if(vecLine[14]!="Money5"){printf_message("FaBaoStar.csv中字段[Money5]位置不对应");assert(false); return false; }
		if(vecLine[15]!="Rate5"){printf_message("FaBaoStar.csv中字段[Rate5]位置不对应");assert(false); return false; }
		if(vecLine[16]!="SuiPian6"){printf_message("FaBaoStar.csv中字段[SuiPian6]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Money6"){printf_message("FaBaoStar.csv中字段[Money6]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Rate6"){printf_message("FaBaoStar.csv中字段[Rate6]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)19)
			{
				assert(false);
				return false;
			}
			FaBaoStarElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.SuiPian1=atoi(vecLine[1].c_str());
			member.Money1=atoi(vecLine[2].c_str());
			member.Rate1=atoi(vecLine[3].c_str());
			member.SuiPian2=atoi(vecLine[4].c_str());
			member.Money2=atoi(vecLine[5].c_str());
			member.Rate2=atoi(vecLine[6].c_str());
			member.SuiPian3=atoi(vecLine[7].c_str());
			member.Money3=atoi(vecLine[8].c_str());
			member.Rate3=atoi(vecLine[9].c_str());
			member.SuiPian4=atoi(vecLine[10].c_str());
			member.Money4=atoi(vecLine[11].c_str());
			member.Rate4=atoi(vecLine[12].c_str());
			member.SuiPian5=atoi(vecLine[13].c_str());
			member.Money5=atoi(vecLine[14].c_str());
			member.Rate5=atoi(vecLine[15].c_str());
			member.SuiPian6=atoi(vecLine[16].c_str());
			member.Money6=atoi(vecLine[17].c_str());
			member.Rate6=atoi(vecLine[18].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
