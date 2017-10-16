#ifndef __BANGHUILVUP_CONFIG_H
#define __BANGHUILVUP_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//帮会升级脜盲脰脙脢媒戮脻陆谩鹿鹿
struct BangHuiLvUpElement
{
	friend class BangHuiLvUpTable;
	int ID;                      	//编号	成就ID
	string Name;                 	//建筑名称	建筑名称
	int Type;                    	//建筑类型	1大厅2库房3金库4练武堂
	int MAX;                     	//最大等级	最大等级
	int Lv;                      	//等级	等级
	string Res;                  	//建筑图标	建筑图标
	int Money;                   	//升级资金	升级资金
	int Limit1;                  	//限制1	限制1
	int Limit2;                  	//限制1	限制1
	int XiaoHao;                 	//每日消耗	每日消耗
	int Function;                	//功能	1资金上限2成员上限3同时开启技能数量
	int CanShu;                  	//功能参数	功能参数
	int Time;                    	//升级时间	单位分钟
	string FuliTips;             	//福利描述	
	string LvUpTips;             	//升级描述	

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
	BangHuiLvUpElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//帮会升级脜盲脰脙路芒脳掳脌脿
class BangHuiLvUpTable
{
	friend class TableData;
private:
	BangHuiLvUpTable(){}
	~BangHuiLvUpTable(){}
	map<int, BangHuiLvUpElement>	m_mapElements;
	vector<BangHuiLvUpElement>	m_vecAllElements;
	BangHuiLvUpElement m_emptyItem;
public:
	static BangHuiLvUpTable& Instance()
	{
		static BangHuiLvUpTable sInstance;
		return sInstance;
	}

	BangHuiLvUpElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BangHuiLvUpElement>&	GetAllElement()
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
		return LoadJson("BangHuiLvUp.json");
		#else
		string strTableContent;
		if( LoadConfigContent("BangHuiLvUp.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("BangHuiLvUp.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[BangHuiLvUp.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("BangHuiLvUp.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("BangHuiLvUp.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Type"){printf_message("BangHuiLvUp.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[3]!="MAX"){printf_message("BangHuiLvUp.csv中字段[MAX]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Lv"){printf_message("BangHuiLvUp.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Res"){printf_message("BangHuiLvUp.csv中字段[Res]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Money"){printf_message("BangHuiLvUp.csv中字段[Money]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Limit1"){printf_message("BangHuiLvUp.csv中字段[Limit1]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Limit2"){printf_message("BangHuiLvUp.csv中字段[Limit2]位置不对应");assert(false); return false; }
		if(vecLine[9]!="XiaoHao"){printf_message("BangHuiLvUp.csv中字段[XiaoHao]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Function"){printf_message("BangHuiLvUp.csv中字段[Function]位置不对应");assert(false); return false; }
		if(vecLine[11]!="CanShu"){printf_message("BangHuiLvUp.csv中字段[CanShu]位置不对应");assert(false); return false; }
		if(vecLine[12]!="Time"){printf_message("BangHuiLvUp.csv中字段[Time]位置不对应");assert(false); return false; }
		if(vecLine[13]!="FuliTips"){printf_message("BangHuiLvUp.csv中字段[FuliTips]位置不对应");assert(false); return false; }
		if(vecLine[14]!="LvUpTips"){printf_message("BangHuiLvUp.csv中字段[LvUpTips]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			BangHuiLvUpElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Type=atoi(vecLine[2].c_str());
			member.MAX=atoi(vecLine[3].c_str());
			member.Lv=atoi(vecLine[4].c_str());
			member.Res=vecLine[5];
			member.Money=atoi(vecLine[6].c_str());
			member.Limit1=atoi(vecLine[7].c_str());
			member.Limit2=atoi(vecLine[8].c_str());
			member.XiaoHao=atoi(vecLine[9].c_str());
			member.Function=atoi(vecLine[10].c_str());
			member.CanShu=atoi(vecLine[11].c_str());
			member.Time=atoi(vecLine[12].c_str());
			member.FuliTips=vecLine[13];
			member.LvUpTips=vecLine[14];


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
		if(vecLine.size() != 15)
		{
			printf_message("BangHuiLvUp.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("BangHuiLvUp.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("BangHuiLvUp.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Type"){printf_message("BangHuiLvUp.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[3]!="MAX"){printf_message("BangHuiLvUp.csv中字段[MAX]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Lv"){printf_message("BangHuiLvUp.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Res"){printf_message("BangHuiLvUp.csv中字段[Res]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Money"){printf_message("BangHuiLvUp.csv中字段[Money]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Limit1"){printf_message("BangHuiLvUp.csv中字段[Limit1]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Limit2"){printf_message("BangHuiLvUp.csv中字段[Limit2]位置不对应");assert(false); return false; }
		if(vecLine[9]!="XiaoHao"){printf_message("BangHuiLvUp.csv中字段[XiaoHao]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Function"){printf_message("BangHuiLvUp.csv中字段[Function]位置不对应");assert(false); return false; }
		if(vecLine[11]!="CanShu"){printf_message("BangHuiLvUp.csv中字段[CanShu]位置不对应");assert(false); return false; }
		if(vecLine[12]!="Time"){printf_message("BangHuiLvUp.csv中字段[Time]位置不对应");assert(false); return false; }
		if(vecLine[13]!="FuliTips"){printf_message("BangHuiLvUp.csv中字段[FuliTips]位置不对应");assert(false); return false; }
		if(vecLine[14]!="LvUpTips"){printf_message("BangHuiLvUp.csv中字段[LvUpTips]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)15)
			{
				assert(false);
				return false;
			}
			BangHuiLvUpElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Type=atoi(vecLine[2].c_str());
			member.MAX=atoi(vecLine[3].c_str());
			member.Lv=atoi(vecLine[4].c_str());
			member.Res=vecLine[5];
			member.Money=atoi(vecLine[6].c_str());
			member.Limit1=atoi(vecLine[7].c_str());
			member.Limit2=atoi(vecLine[8].c_str());
			member.XiaoHao=atoi(vecLine[9].c_str());
			member.Function=atoi(vecLine[10].c_str());
			member.CanShu=atoi(vecLine[11].c_str());
			member.Time=atoi(vecLine[12].c_str());
			member.FuliTips=vecLine[13];
			member.LvUpTips=vecLine[14];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
