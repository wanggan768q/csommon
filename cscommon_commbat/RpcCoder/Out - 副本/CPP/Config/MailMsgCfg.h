#ifndef __MAILMSG_CONFIG_H
#define __MAILMSG_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//邮件信息脜盲脰脙脢媒戮脻陆谩鹿鹿
struct MailMsgElement
{
	friend class MailMsgTable;
	int ID;                      	//索引用ID	索引用ID
	int MailType;                	//邮件类型	1自动删除2手动删除
	int IconType;                	//邮件图标类型	邮件图标类型
	string MailTitle;            	//邮件标题	邮件标题
	int MailText;                	//邮件文本	邮件文本

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
	MailMsgElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//邮件信息脜盲脰脙路芒脳掳脌脿
class MailMsgTable
{
	friend class TableData;
private:
	MailMsgTable(){}
	~MailMsgTable(){}
	map<int, MailMsgElement>	m_mapElements;
	vector<MailMsgElement>	m_vecAllElements;
	MailMsgElement m_emptyItem;
public:
	static MailMsgTable& Instance()
	{
		static MailMsgTable sInstance;
		return sInstance;
	}

	MailMsgElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<MailMsgElement>&	GetAllElement()
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
		return LoadJson("MailMsg.json");
		#else
		string strTableContent;
		if( LoadConfigContent("MailMsg.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("MailMsg.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[MailMsg.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("MailMsg.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="MailType"){printf_message("MailMsg.csv中字段[MailType]位置不对应");assert(false); return false; }
		if(vecLine[2]!="IconType"){printf_message("MailMsg.csv中字段[IconType]位置不对应");assert(false); return false; }
		if(vecLine[3]!="MailTitle"){printf_message("MailMsg.csv中字段[MailTitle]位置不对应");assert(false); return false; }
		if(vecLine[4]!="MailText"){printf_message("MailMsg.csv中字段[MailText]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			MailMsgElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.MailType=atoi(vecLine[1].c_str());
			member.IconType=atoi(vecLine[2].c_str());
			member.MailTitle=vecLine[3];
			member.MailText=atoi(vecLine[4].c_str());


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
			printf_message("MailMsg.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("MailMsg.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="MailType"){printf_message("MailMsg.csv中字段[MailType]位置不对应");assert(false); return false; }
		if(vecLine[2]!="IconType"){printf_message("MailMsg.csv中字段[IconType]位置不对应");assert(false); return false; }
		if(vecLine[3]!="MailTitle"){printf_message("MailMsg.csv中字段[MailTitle]位置不对应");assert(false); return false; }
		if(vecLine[4]!="MailText"){printf_message("MailMsg.csv中字段[MailText]位置不对应");assert(false); return false; }

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
			MailMsgElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.MailType=atoi(vecLine[1].c_str());
			member.IconType=atoi(vecLine[2].c_str());
			member.MailTitle=vecLine[3];
			member.MailText=atoi(vecLine[4].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
