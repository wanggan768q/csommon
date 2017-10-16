#ifndef __PLOT_CONFIG_H
#define __PLOT_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//剧情表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct PlotElement
{
	friend class PlotTable;
	int ID;                      	//ID	ID
	string FileName;             	//文件名	文件名

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
	PlotElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//剧情表脜盲脰脙路芒脳掳脌脿
class PlotTable
{
	friend class TableData;
private:
	PlotTable(){}
	~PlotTable(){}
	map<int, PlotElement>	m_mapElements;
	vector<PlotElement>	m_vecAllElements;
	PlotElement m_emptyItem;
public:
	static PlotTable& Instance()
	{
		static PlotTable sInstance;
		return sInstance;
	}

	PlotElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<PlotElement>&	GetAllElement()
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
		return LoadJson("Plot.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Plot.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Plot.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Plot.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("Plot.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="FileName"){printf_message("Plot.csv中字段[FileName]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			PlotElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.FileName=vecLine[1];


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
		if(vecLine.size() != 2)
		{
			printf_message("Plot.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("Plot.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="FileName"){printf_message("Plot.csv中字段[FileName]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)2)
			{
				assert(false);
				return false;
			}
			PlotElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.FileName=vecLine[1];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
