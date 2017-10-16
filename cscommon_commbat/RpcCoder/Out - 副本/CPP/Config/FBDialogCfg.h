#ifndef __FBDIALOG_CONFIG_H
#define __FBDIALOG_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//对话表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct FBDialogElement
{
	friend class FBDialogTable;
	int DialogID;                	//编号	对话ID
	int Name1;                   	//对话人1	对话人1（0：玩家 其他id：填写相应表id）
	string Dialog1;              	//对话内容1	对话内容1
	string BanShen;              	//半身像资源	半身像资源（其他的填，玩家自己的不填）
	int Set;                     	//头像位置左右	1 左 2 右
	int Next;                    	//下一段对话	下一段对话
	float Time;                  	//间隔时间	间隔时间

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
	FBDialogElement()
	{
		DialogID = -1;
		m_bIsValidate=false;
	}
};

//对话表脜盲脰脙路芒脳掳脌脿
class FBDialogTable
{
	friend class TableData;
private:
	FBDialogTable(){}
	~FBDialogTable(){}
	map<int, FBDialogElement>	m_mapElements;
	vector<FBDialogElement>	m_vecAllElements;
	FBDialogElement m_emptyItem;
public:
	static FBDialogTable& Instance()
	{
		static FBDialogTable sInstance;
		return sInstance;
	}

	FBDialogElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<FBDialogElement>&	GetAllElement()
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
		return LoadJson("FBDialog.json");
		#else
		string strTableContent;
		if( LoadConfigContent("FBDialog.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("FBDialog.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[FBDialog.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="DialogID"){printf_message("FBDialog.csv中字段[DialogID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name1"){printf_message("FBDialog.csv中字段[Name1]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Dialog1"){printf_message("FBDialog.csv中字段[Dialog1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="BanShen"){printf_message("FBDialog.csv中字段[BanShen]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Set"){printf_message("FBDialog.csv中字段[Set]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Next"){printf_message("FBDialog.csv中字段[Next]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Time"){printf_message("FBDialog.csv中字段[Time]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			FBDialogElement	member;

						member.DialogID=atoi(vecLine[0].c_str());
			member.Name1=atoi(vecLine[1].c_str());
			member.Dialog1=vecLine[2];
			member.BanShen=vecLine[3];
			member.Set=atoi(vecLine[4].c_str());
			member.Next=atoi(vecLine[5].c_str());
			member.Time=atof(vecLine[6].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.DialogID] = member;
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
		if(vecLine.size() != 7)
		{
			printf_message("FBDialog.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="DialogID"){printf_message("FBDialog.csv中字段[DialogID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name1"){printf_message("FBDialog.csv中字段[Name1]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Dialog1"){printf_message("FBDialog.csv中字段[Dialog1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="BanShen"){printf_message("FBDialog.csv中字段[BanShen]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Set"){printf_message("FBDialog.csv中字段[Set]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Next"){printf_message("FBDialog.csv中字段[Next]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Time"){printf_message("FBDialog.csv中字段[Time]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)7)
			{
				assert(false);
				return false;
			}
			FBDialogElement	member;
			member.DialogID=atoi(vecLine[0].c_str());
			member.Name1=atoi(vecLine[1].c_str());
			member.Dialog1=vecLine[2];
			member.BanShen=vecLine[3];
			member.Set=atoi(vecLine[4].c_str());
			member.Next=atoi(vecLine[5].c_str());
			member.Time=atof(vecLine[6].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.DialogID] = member;
		}
		return true;
	}
};

#endif
