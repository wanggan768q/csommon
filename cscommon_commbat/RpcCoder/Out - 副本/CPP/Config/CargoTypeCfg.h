#ifndef __CARGOTYPE_CONFIG_H
#define __CARGOTYPE_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//货运货物类别表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct CargoTypeElement
{
	friend class CargoTypeTable;
	int Type;                    	//货物类别	货物类别
	int MinNum;                  	//类别数量最小值	类别数量最小值
	int MaxNum;                  	//类别数量最大值	类别数量最大值
	int Weight;                  	//权重	权重

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
	CargoTypeElement()
	{
		Type = -1;
		m_bIsValidate=false;
	}
};

//货运货物类别表脜盲脰脙路芒脳掳脌脿
class CargoTypeTable
{
	friend class TableData;
private:
	CargoTypeTable(){}
	~CargoTypeTable(){}
	map<int, CargoTypeElement>	m_mapElements;
	vector<CargoTypeElement>	m_vecAllElements;
	CargoTypeElement m_emptyItem;
public:
	static CargoTypeTable& Instance()
	{
		static CargoTypeTable sInstance;
		return sInstance;
	}

	CargoTypeElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CargoTypeElement>&	GetAllElement()
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
		return LoadJson("CargoType.json");
		#else
		string strTableContent;
		if( LoadConfigContent("CargoType.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CargoType.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[CargoType.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="Type"){printf_message("CargoType.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[1]!="MinNum"){printf_message("CargoType.csv中字段[MinNum]位置不对应");assert(false); return false; }
		if(vecLine[2]!="MaxNum"){printf_message("CargoType.csv中字段[MaxNum]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Weight"){printf_message("CargoType.csv中字段[Weight]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			CargoTypeElement	member;

						member.Type=atoi(vecLine[0].c_str());
			member.MinNum=atoi(vecLine[1].c_str());
			member.MaxNum=atoi(vecLine[2].c_str());
			member.Weight=atoi(vecLine[3].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.Type] = member;
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
		if(vecLine.size() != 4)
		{
			printf_message("CargoType.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="Type"){printf_message("CargoType.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[1]!="MinNum"){printf_message("CargoType.csv中字段[MinNum]位置不对应");assert(false); return false; }
		if(vecLine[2]!="MaxNum"){printf_message("CargoType.csv中字段[MaxNum]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Weight"){printf_message("CargoType.csv中字段[Weight]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)4)
			{
				assert(false);
				return false;
			}
			CargoTypeElement	member;
			member.Type=atoi(vecLine[0].c_str());
			member.MinNum=atoi(vecLine[1].c_str());
			member.MaxNum=atoi(vecLine[2].c_str());
			member.Weight=atoi(vecLine[3].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.Type] = member;
		}
		return true;
	}
};

#endif
