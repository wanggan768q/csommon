#ifndef __WORLDMAP_CONFIG_H
#define __WORLDMAP_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//世界地图表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct WorldMapElement
{
	friend class WorldMapTable;
	int ID;                      	//世界地图ID	世界地图ID
	string Name;                 	//世界地图名称	世界地图的名字
	int DungeonID;               	//对应副本表的id	对应副本表的id
	string PosName;              	//对应unity的按钮名字	对应unity的按钮名字
	string BtnRes;               	//按钮资源	按钮资源
	string NameRes;              	//名字资源	名字资源或者名字，待定名字，以后可能修改

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
	WorldMapElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//世界地图表脜盲脰脙路芒脳掳脌脿
class WorldMapTable
{
	friend class TableData;
private:
	WorldMapTable(){}
	~WorldMapTable(){}
	map<int, WorldMapElement>	m_mapElements;
	vector<WorldMapElement>	m_vecAllElements;
	WorldMapElement m_emptyItem;
public:
	static WorldMapTable& Instance()
	{
		static WorldMapTable sInstance;
		return sInstance;
	}

	WorldMapElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<WorldMapElement>&	GetAllElement()
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
		return LoadJson("WorldMap.json");
		#else
		string strTableContent;
		if( LoadConfigContent("WorldMap.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("WorldMap.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[WorldMap.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("WorldMap.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("WorldMap.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="DungeonID"){printf_message("WorldMap.csv中字段[DungeonID]位置不对应");assert(false); return false; }
		if(vecLine[3]!="PosName"){printf_message("WorldMap.csv中字段[PosName]位置不对应");assert(false); return false; }
		if(vecLine[4]!="BtnRes"){printf_message("WorldMap.csv中字段[BtnRes]位置不对应");assert(false); return false; }
		if(vecLine[5]!="NameRes"){printf_message("WorldMap.csv中字段[NameRes]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			WorldMapElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.DungeonID=atoi(vecLine[2].c_str());
			member.PosName=vecLine[3];
			member.BtnRes=vecLine[4];
			member.NameRes=vecLine[5];


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
		if(vecLine.size() != 6)
		{
			printf_message("WorldMap.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("WorldMap.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("WorldMap.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="DungeonID"){printf_message("WorldMap.csv中字段[DungeonID]位置不对应");assert(false); return false; }
		if(vecLine[3]!="PosName"){printf_message("WorldMap.csv中字段[PosName]位置不对应");assert(false); return false; }
		if(vecLine[4]!="BtnRes"){printf_message("WorldMap.csv中字段[BtnRes]位置不对应");assert(false); return false; }
		if(vecLine[5]!="NameRes"){printf_message("WorldMap.csv中字段[NameRes]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)6)
			{
				assert(false);
				return false;
			}
			WorldMapElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.DungeonID=atoi(vecLine[2].c_str());
			member.PosName=vecLine[3];
			member.BtnRes=vecLine[4];
			member.NameRes=vecLine[5];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
