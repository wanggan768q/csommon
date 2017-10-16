#ifndef __COLOR_CONFIG_H
#define __COLOR_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//文本颜色表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct ColorElement
{
	friend class ColorTable;
	int ID;                      	//ID	ID
	int Type;                    	//类型	类型1.富文本（聊天超链接）2.装备名称3 其他
	string Color;                	//色值	色值（例：#0A246A）
	string Res;                  	//图标	图标
	string Desc;                 	//描述	ID对应内容的描述

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
	ColorElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//文本颜色表脜盲脰脙路芒脳掳脌脿
class ColorTable
{
	friend class TableData;
private:
	ColorTable(){}
	~ColorTable(){}
	map<int, ColorElement>	m_mapElements;
	vector<ColorElement>	m_vecAllElements;
	ColorElement m_emptyItem;
public:
	static ColorTable& Instance()
	{
		static ColorTable sInstance;
		return sInstance;
	}

	ColorElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ColorElement>&	GetAllElement()
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
		return LoadJson("Color.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Color.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Color.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Color.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("Color.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Type"){printf_message("Color.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Color"){printf_message("Color.csv中字段[Color]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Res"){printf_message("Color.csv中字段[Res]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Desc"){printf_message("Color.csv中字段[Desc]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			ColorElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Type=atoi(vecLine[1].c_str());
			member.Color=vecLine[2];
			member.Res=vecLine[3];
			member.Desc=vecLine[4];


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
			printf_message("Color.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("Color.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Type"){printf_message("Color.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Color"){printf_message("Color.csv中字段[Color]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Res"){printf_message("Color.csv中字段[Res]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Desc"){printf_message("Color.csv中字段[Desc]位置不对应");assert(false); return false; }

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
			ColorElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Type=atoi(vecLine[1].c_str());
			member.Color=vecLine[2];
			member.Res=vecLine[3];
			member.Desc=vecLine[4];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
