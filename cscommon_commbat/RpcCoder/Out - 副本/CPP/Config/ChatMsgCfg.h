#ifndef __CHATMSG_CONFIG_H
#define __CHATMSG_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//聊天信息表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct ChatMsgElement
{
	friend class ChatMsgTable;
	int ID;                      	//信息的ID	信息的ID
	int Type;                    	//频道类型	1系统频道2世界频道3当前频道4门派频道5帮派频道6队伍频道7组队频道8邮件文本
	int TabId;                   	//频道页签	频道页签
	int ShowType;                	//信息发送者	1页签加文字2角色气泡
	string Comment;              	//模板注释	模板注释
	string Msg;                  	//文本信息	文本信息

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
	ChatMsgElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//聊天信息表脜盲脰脙路芒脳掳脌脿
class ChatMsgTable
{
	friend class TableData;
private:
	ChatMsgTable(){}
	~ChatMsgTable(){}
	map<int, ChatMsgElement>	m_mapElements;
	vector<ChatMsgElement>	m_vecAllElements;
	ChatMsgElement m_emptyItem;
public:
	static ChatMsgTable& Instance()
	{
		static ChatMsgTable sInstance;
		return sInstance;
	}

	ChatMsgElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ChatMsgElement>&	GetAllElement()
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
		return LoadJson("ChatMsg.json");
		#else
		string strTableContent;
		if( LoadConfigContent("ChatMsg.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ChatMsg.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[ChatMsg.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("ChatMsg.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Type"){printf_message("ChatMsg.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[2]!="TabId"){printf_message("ChatMsg.csv中字段[TabId]位置不对应");assert(false); return false; }
		if(vecLine[3]!="ShowType"){printf_message("ChatMsg.csv中字段[ShowType]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Comment"){printf_message("ChatMsg.csv中字段[Comment]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Msg"){printf_message("ChatMsg.csv中字段[Msg]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			ChatMsgElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Type=atoi(vecLine[1].c_str());
			member.TabId=atoi(vecLine[2].c_str());
			member.ShowType=atoi(vecLine[3].c_str());
			member.Comment=vecLine[4];
			member.Msg=vecLine[5];


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
			printf_message("ChatMsg.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("ChatMsg.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Type"){printf_message("ChatMsg.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[2]!="TabId"){printf_message("ChatMsg.csv中字段[TabId]位置不对应");assert(false); return false; }
		if(vecLine[3]!="ShowType"){printf_message("ChatMsg.csv中字段[ShowType]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Comment"){printf_message("ChatMsg.csv中字段[Comment]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Msg"){printf_message("ChatMsg.csv中字段[Msg]位置不对应");assert(false); return false; }

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
			ChatMsgElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Type=atoi(vecLine[1].c_str());
			member.TabId=atoi(vecLine[2].c_str());
			member.ShowType=atoi(vecLine[3].c_str());
			member.Comment=vecLine[4];
			member.Msg=vecLine[5];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
