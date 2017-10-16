#ifndef __MAILICON_CONFIG_H
#define __MAILICON_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//邮件标识脜盲脰脙脢媒戮脻陆谩鹿鹿
struct MailIconElement
{
	friend class MailIconTable;
	int ID;                      	//索引用ID	索引用ID
	string Desc;                 	//描述	策划用备注
	string Unread;               	//未读的资源ID	未读的资源ID
	string Read;                 	//已读资源ID	已读资源ID

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
	MailIconElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//邮件标识脜盲脰脙路芒脳掳脌脿
class MailIconTable
{
	friend class TableData;
private:
	MailIconTable(){}
	~MailIconTable(){}
	map<int, MailIconElement>	m_mapElements;
	vector<MailIconElement>	m_vecAllElements;
	MailIconElement m_emptyItem;
public:
	static MailIconTable& Instance()
	{
		static MailIconTable sInstance;
		return sInstance;
	}

	MailIconElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<MailIconElement>&	GetAllElement()
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
		return LoadJson("MailIcon.json");
		#else
		string strTableContent;
		if( LoadConfigContent("MailIcon.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("MailIcon.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[MailIcon.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("MailIcon.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Desc"){printf_message("MailIcon.csv中字段[Desc]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Unread"){printf_message("MailIcon.csv中字段[Unread]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Read"){printf_message("MailIcon.csv中字段[Read]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			MailIconElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Desc=vecLine[1];
			member.Unread=vecLine[2];
			member.Read=vecLine[3];


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
			printf_message("MailIcon.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("MailIcon.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Desc"){printf_message("MailIcon.csv中字段[Desc]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Unread"){printf_message("MailIcon.csv中字段[Unread]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Read"){printf_message("MailIcon.csv中字段[Read]位置不对应");assert(false); return false; }

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
			MailIconElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Desc=vecLine[1];
			member.Unread=vecLine[2];
			member.Read=vecLine[3];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
