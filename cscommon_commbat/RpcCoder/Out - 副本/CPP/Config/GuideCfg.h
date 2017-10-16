#ifndef __GUIDE_CONFIG_H
#define __GUIDE_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//引导触发脜盲脰脙脢媒戮脻陆谩鹿鹿
struct GuideElement
{
	friend class GuideTable;
	int ID;                      	//指引触发器id	指引触发器id
	string Name;                 	//指引名字	指引名字
	string GuideTrigger;         	//触发类型	0 任务接取[0,任务ID] 1：任务 完成 [1,任务ID] 2:进入主城[2,0] 3:打开某个界面[3,"view层的名字"] 4:进入副本[4,0]  5：完成对话[5,对话ID] 
	int GuideReset;              	//未完成是否继续 0重置 1不重置	暂代参数
	int GuideLinear;             	//是否是线性	0线性1非线性
	string GuideSteps;           	//引导步骤组	引导步骤组[1,2,3]GuideSteps内的id

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
	GuideElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//引导触发脜盲脰脙路芒脳掳脌脿
class GuideTable
{
	friend class TableData;
private:
	GuideTable(){}
	~GuideTable(){}
	map<int, GuideElement>	m_mapElements;
	vector<GuideElement>	m_vecAllElements;
	GuideElement m_emptyItem;
public:
	static GuideTable& Instance()
	{
		static GuideTable sInstance;
		return sInstance;
	}

	GuideElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<GuideElement>&	GetAllElement()
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
		return LoadJson("Guide.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Guide.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Guide.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Guide.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("Guide.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Guide.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="GuideTrigger"){printf_message("Guide.csv中字段[GuideTrigger]位置不对应");assert(false); return false; }
		if(vecLine[3]!="GuideReset"){printf_message("Guide.csv中字段[GuideReset]位置不对应");assert(false); return false; }
		if(vecLine[4]!="GuideLinear"){printf_message("Guide.csv中字段[GuideLinear]位置不对应");assert(false); return false; }
		if(vecLine[5]!="GuideSteps"){printf_message("Guide.csv中字段[GuideSteps]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			GuideElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.GuideTrigger=vecLine[2];
			member.GuideReset=atoi(vecLine[3].c_str());
			member.GuideLinear=atoi(vecLine[4].c_str());
			member.GuideSteps=vecLine[5];


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
			printf_message("Guide.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("Guide.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Guide.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="GuideTrigger"){printf_message("Guide.csv中字段[GuideTrigger]位置不对应");assert(false); return false; }
		if(vecLine[3]!="GuideReset"){printf_message("Guide.csv中字段[GuideReset]位置不对应");assert(false); return false; }
		if(vecLine[4]!="GuideLinear"){printf_message("Guide.csv中字段[GuideLinear]位置不对应");assert(false); return false; }
		if(vecLine[5]!="GuideSteps"){printf_message("Guide.csv中字段[GuideSteps]位置不对应");assert(false); return false; }

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
			GuideElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.GuideTrigger=vecLine[2];
			member.GuideReset=atoi(vecLine[3].c_str());
			member.GuideLinear=atoi(vecLine[4].c_str());
			member.GuideSteps=vecLine[5];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
