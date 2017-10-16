#ifndef __CHENGJIU_CONFIG_H
#define __CHENGJIU_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//成就表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct ChengJiuElement
{
	friend class ChengJiuTable;
	int ChengJiuID;              	//编号	成就ID
	string Name;                 	//成就名称	成就名称
	string Res;                  	//成就图标	成就图标
	int Type;                    	//成就分类	成就分类（1成长 2 活动 3社交）
	string MiaoShu;              	//成就描述	成就描述
	int ReWard;                  	//奖励类型	1 银两 2元宝 3 道具 
	int Num;                     	//奖励参数	奖励参数
	int Item;                    	//奖励道具	奖励道具
	int TiaoJian;                	//解锁条件	1等级2装备强化
	int CanShu;                  	//条件参数	条件参数

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
	ChengJiuElement()
	{
		ChengJiuID = -1;
		m_bIsValidate=false;
	}
};

//成就表脜盲脰脙路芒脳掳脌脿
class ChengJiuTable
{
	friend class TableData;
private:
	ChengJiuTable(){}
	~ChengJiuTable(){}
	map<int, ChengJiuElement>	m_mapElements;
	vector<ChengJiuElement>	m_vecAllElements;
	ChengJiuElement m_emptyItem;
public:
	static ChengJiuTable& Instance()
	{
		static ChengJiuTable sInstance;
		return sInstance;
	}

	ChengJiuElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ChengJiuElement>&	GetAllElement()
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
		return LoadJson("ChengJiu.json");
		#else
		string strTableContent;
		if( LoadConfigContent("ChengJiu.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ChengJiu.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[ChengJiu.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ChengJiuID"){printf_message("ChengJiu.csv中字段[ChengJiuID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("ChengJiu.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Res"){printf_message("ChengJiu.csv中字段[Res]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("ChengJiu.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="MiaoShu"){printf_message("ChengJiu.csv中字段[MiaoShu]位置不对应");assert(false); return false; }
		if(vecLine[5]!="ReWard"){printf_message("ChengJiu.csv中字段[ReWard]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Num"){printf_message("ChengJiu.csv中字段[Num]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Item"){printf_message("ChengJiu.csv中字段[Item]位置不对应");assert(false); return false; }
		if(vecLine[8]!="TiaoJian"){printf_message("ChengJiu.csv中字段[TiaoJian]位置不对应");assert(false); return false; }
		if(vecLine[9]!="CanShu"){printf_message("ChengJiu.csv中字段[CanShu]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			ChengJiuElement	member;

						member.ChengJiuID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Res=vecLine[2];
			member.Type=atoi(vecLine[3].c_str());
			member.MiaoShu=vecLine[4];
			member.ReWard=atoi(vecLine[5].c_str());
			member.Num=atoi(vecLine[6].c_str());
			member.Item=atoi(vecLine[7].c_str());
			member.TiaoJian=atoi(vecLine[8].c_str());
			member.CanShu=atoi(vecLine[9].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.ChengJiuID] = member;
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
		if(vecLine.size() != 10)
		{
			printf_message("ChengJiu.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ChengJiuID"){printf_message("ChengJiu.csv中字段[ChengJiuID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("ChengJiu.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Res"){printf_message("ChengJiu.csv中字段[Res]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("ChengJiu.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="MiaoShu"){printf_message("ChengJiu.csv中字段[MiaoShu]位置不对应");assert(false); return false; }
		if(vecLine[5]!="ReWard"){printf_message("ChengJiu.csv中字段[ReWard]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Num"){printf_message("ChengJiu.csv中字段[Num]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Item"){printf_message("ChengJiu.csv中字段[Item]位置不对应");assert(false); return false; }
		if(vecLine[8]!="TiaoJian"){printf_message("ChengJiu.csv中字段[TiaoJian]位置不对应");assert(false); return false; }
		if(vecLine[9]!="CanShu"){printf_message("ChengJiu.csv中字段[CanShu]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)10)
			{
				assert(false);
				return false;
			}
			ChengJiuElement	member;
			member.ChengJiuID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Res=vecLine[2];
			member.Type=atoi(vecLine[3].c_str());
			member.MiaoShu=vecLine[4];
			member.ReWard=atoi(vecLine[5].c_str());
			member.Num=atoi(vecLine[6].c_str());
			member.Item=atoi(vecLine[7].c_str());
			member.TiaoJian=atoi(vecLine[8].c_str());
			member.CanShu=atoi(vecLine[9].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ChengJiuID] = member;
		}
		return true;
	}
};

#endif
