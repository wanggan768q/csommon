#ifndef __CARGO_CONFIG_H
#define __CARGO_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//货运货物数据库脜盲脰脙脢媒戮脻陆谩鹿鹿
struct CargoElement
{
	friend class CargoTable;
	int ID;                      	//货物ID	货物ID
	int GoodsId;                 	//货物物品ID	货物物品ID
	string Name;                 	//货物名称	货物名称
	int Number;                  	//货物物品你数量	货物物品你数量
	int Type;                    	//类别	类别

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
	CargoElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//货运货物数据库脜盲脰脙路芒脳掳脌脿
class CargoTable
{
	friend class TableData;
private:
	CargoTable(){}
	~CargoTable(){}
	map<int, CargoElement>	m_mapElements;
	vector<CargoElement>	m_vecAllElements;
	CargoElement m_emptyItem;
public:
	static CargoTable& Instance()
	{
		static CargoTable sInstance;
		return sInstance;
	}

	CargoElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CargoElement>&	GetAllElement()
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
		return LoadJson("Cargo.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Cargo.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Cargo.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Cargo.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("Cargo.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="GoodsId"){printf_message("Cargo.csv中字段[GoodsId]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Name"){printf_message("Cargo.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Number"){printf_message("Cargo.csv中字段[Number]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Type"){printf_message("Cargo.csv中字段[Type]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			CargoElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.GoodsId=atoi(vecLine[1].c_str());
			member.Name=vecLine[2];
			member.Number=atoi(vecLine[3].c_str());
			member.Type=atoi(vecLine[4].c_str());


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
		if(vecLine.size() != 5)
		{
			printf_message("Cargo.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("Cargo.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="GoodsId"){printf_message("Cargo.csv中字段[GoodsId]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Name"){printf_message("Cargo.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Number"){printf_message("Cargo.csv中字段[Number]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Type"){printf_message("Cargo.csv中字段[Type]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)5)
			{
				assert(false);
				return false;
			}
			CargoElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.GoodsId=atoi(vecLine[1].c_str());
			member.Name=vecLine[2];
			member.Number=atoi(vecLine[3].c_str());
			member.Type=atoi(vecLine[4].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
