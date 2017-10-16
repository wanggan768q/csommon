#ifndef __$TEMPLATE$_CONFIG_H
#define __$TEMPLATE$_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//$CNName$ÅäÖÃÊý¾Ý½á¹¹
struct $Template$Element
{
	friend class $Template$Table;
$FieldDefine$
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
	$Template$Element()
	{
		$InitPrimaryField$
		m_bIsValidate=false;
	}
};

//$CNName$ÅäÖÃ·â×°Àà
class $Template$Table
{
	friend class TableData;
private:
	$Template$Table(){}
	~$Template$Table(){}
	map<$PrimaryType$, $Template$Element>	m_mapElements;
	vector<$Template$Element>	m_vecAllElements;
	$Template$Element m_emptyItem;
public:
	static $Template$Table& Instance()
	{
		static $Template$Table sInstance;
		return sInstance;
	}

	$Template$Element GetElement($PrimaryType$ key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement($PrimaryType$ key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<$Template$Element>&	GetAllElement()
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
		return LoadJson("$Template$.json");
		#else
		string strTableContent;
		if( LoadConfigContent("$Template$.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("$Template$.bin", strTableContent ) )
		{
			printf_message("ÅäÖÃÎÄ¼þ[$Template$.bin]Î´ÕÒµ½");
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

		$CheckColName$

		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			$Template$Element	member;

			$ReadCsvColValue$

			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.$PrimaryKey$] = member;
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
		if(vecLine.size() != $ColCount$)
		{
			printf_message("$Template$.csvÖÐÁÐÊýÁ¿ÓëÉú³ÉµÄ´úÂë²»Æ¥Åä!");
			assert(false);
			return false;
		}
$CheckColName$
		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)$ColCount$)
			{
				assert(false);
				return false;
			}
			$Template$Element	member;
$ReadCsvColValue$
			member.SetIsValidate(true);
			m_mapElements[member.$PrimaryKey$] = member;
		}
		return true;
	}
};

#endif
