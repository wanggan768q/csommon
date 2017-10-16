#ifndef __LOCATION_CONFIG_H
#define __LOCATION_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//坐标脜盲脰脙脢媒戮脻陆谩鹿鹿
struct LocationElement
{
	friend class LocationTable;
	int ID;                      	//坐标ID	坐标ID
	float PosX;                  	//坐标	坐标
	int Dungeons;                	//场景ID	场景ID
	int Layer;                   	//层	层

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
	LocationElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//坐标脜盲脰脙路芒脳掳脌脿
class LocationTable
{
	friend class TableData;
private:
	LocationTable(){}
	~LocationTable(){}
	map<int, LocationElement>	m_mapElements;
	vector<LocationElement>	m_vecAllElements;
	LocationElement m_emptyItem;
public:
	static LocationTable& Instance()
	{
		static LocationTable sInstance;
		return sInstance;
	}

	LocationElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<LocationElement>&	GetAllElement()
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
		return LoadJson("Location.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Location.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Location.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Location.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("Location.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="PosX"){printf_message("Location.csv中字段[PosX]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Dungeons"){printf_message("Location.csv中字段[Dungeons]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Layer"){printf_message("Location.csv中字段[Layer]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			LocationElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.PosX=atof(vecLine[1].c_str());
			member.Dungeons=atoi(vecLine[2].c_str());
			member.Layer=atoi(vecLine[3].c_str());


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
		if(vecLine.size() != 4)
		{
			printf_message("Location.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("Location.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="PosX"){printf_message("Location.csv中字段[PosX]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Dungeons"){printf_message("Location.csv中字段[Dungeons]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Layer"){printf_message("Location.csv中字段[Layer]位置不对应");assert(false); return false; }

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
			LocationElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.PosX=atof(vecLine[1].c_str());
			member.Dungeons=atoi(vecLine[2].c_str());
			member.Layer=atoi(vecLine[3].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
