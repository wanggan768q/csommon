#ifndef __FORMULA_CONFIG_H
#define __FORMULA_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//战斗公式脜盲脰脙脢媒戮脻陆谩鹿鹿
struct FormulaElement
{
	friend class FormulaTable;
	int FormulaID;               	//公式ID	公式ID
	string Describe;             	//描述	描述
	string VarsName;             	//变量名	变量名
	string Formula;              	//公式	公式

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
	FormulaElement()
	{
		FormulaID = -1;
		m_bIsValidate=false;
	}
};

//战斗公式脜盲脰脙路芒脳掳脌脿
class FormulaTable
{
	friend class TableData;
private:
	FormulaTable(){}
	~FormulaTable(){}
	map<int, FormulaElement>	m_mapElements;
	vector<FormulaElement>	m_vecAllElements;
	FormulaElement m_emptyItem;
public:
	static FormulaTable& Instance()
	{
		static FormulaTable sInstance;
		return sInstance;
	}

	FormulaElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<FormulaElement>&	GetAllElement()
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
		return LoadJson("Formula.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Formula.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Formula.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Formula.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="FormulaID"){printf_message("Formula.csv中字段[FormulaID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Describe"){printf_message("Formula.csv中字段[Describe]位置不对应");assert(false); return false; }
		if(vecLine[2]!="VarsName"){printf_message("Formula.csv中字段[VarsName]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Formula"){printf_message("Formula.csv中字段[Formula]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			FormulaElement	member;

						member.FormulaID=atoi(vecLine[0].c_str());
			member.Describe=vecLine[1];
			member.VarsName=vecLine[2];
			member.Formula=vecLine[3];


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.FormulaID] = member;
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
			printf_message("Formula.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="FormulaID"){printf_message("Formula.csv中字段[FormulaID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Describe"){printf_message("Formula.csv中字段[Describe]位置不对应");assert(false); return false; }
		if(vecLine[2]!="VarsName"){printf_message("Formula.csv中字段[VarsName]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Formula"){printf_message("Formula.csv中字段[Formula]位置不对应");assert(false); return false; }

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
			FormulaElement	member;
			member.FormulaID=atoi(vecLine[0].c_str());
			member.Describe=vecLine[1];
			member.VarsName=vecLine[2];
			member.Formula=vecLine[3];

			member.SetIsValidate(true);
			m_mapElements[member.FormulaID] = member;
		}
		return true;
	}
};

#endif
