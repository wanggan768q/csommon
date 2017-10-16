#ifndef __RANKING_CONFIG_H
#define __RANKING_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//排行榜脜盲脰脙脢媒戮脻陆谩鹿鹿
struct RankingElement
{
	friend class RankingTable;
	int ID;                      	//编号	编号
	string SmallLabel;           	//小分类标签	小分类标签
	int LargeLabel;              	//所属大分类	所属大分类（1个人信息2属性3帮会）
	int Type;                    	//标签类型	标签类型（1横2竖）

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
	RankingElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//排行榜脜盲脰脙路芒脳掳脌脿
class RankingTable
{
	friend class TableData;
private:
	RankingTable(){}
	~RankingTable(){}
	map<int, RankingElement>	m_mapElements;
	vector<RankingElement>	m_vecAllElements;
	RankingElement m_emptyItem;
public:
	static RankingTable& Instance()
	{
		static RankingTable sInstance;
		return sInstance;
	}

	RankingElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<RankingElement>&	GetAllElement()
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
		return LoadJson("Ranking.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Ranking.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Ranking.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Ranking.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("Ranking.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="SmallLabel"){printf_message("Ranking.csv中字段[SmallLabel]位置不对应");assert(false); return false; }
		if(vecLine[2]!="LargeLabel"){printf_message("Ranking.csv中字段[LargeLabel]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("Ranking.csv中字段[Type]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			RankingElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.SmallLabel=vecLine[1];
			member.LargeLabel=atoi(vecLine[2].c_str());
			member.Type=atoi(vecLine[3].c_str());


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
			printf_message("Ranking.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("Ranking.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="SmallLabel"){printf_message("Ranking.csv中字段[SmallLabel]位置不对应");assert(false); return false; }
		if(vecLine[2]!="LargeLabel"){printf_message("Ranking.csv中字段[LargeLabel]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("Ranking.csv中字段[Type]位置不对应");assert(false); return false; }

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
			RankingElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.SmallLabel=vecLine[1];
			member.LargeLabel=atoi(vecLine[2].c_str());
			member.Type=atoi(vecLine[3].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
