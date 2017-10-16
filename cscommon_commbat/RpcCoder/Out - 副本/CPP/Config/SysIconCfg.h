#ifndef __SYSICON_CONFIG_H
#define __SYSICON_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//主界面图标配置脜盲脰脙脢媒戮脻陆谩鹿鹿
struct SysIconElement
{
	friend class SysIconTable;
	int ID;                      	//图标的ID	图标的ID
	string Name;                 	//对应功能名称	对应功能名称
	string Desc;                 	//功能描述策划用	功能描述策划用
	int Type;                    	//图标位于的类别区域	图标位于的类别区域
	int Order;                   	//位置权重	位置权重
	string Icon;                 	//对应图标资源	对应图标资源
	int ShowLv;                  	//图标显示等级	图标显示等级
	int ShowTaskRe;              	//图标显示需要接取的任务	图标显示需要接取的任务
	int ShowTaskCo;              	//图标显示需要完成的任务	图标显示需要完成的任务
	int OpenLv;                  	//图标开启等级	图标开启等级
	int OpenTaskRe;              	//图标开启需要接取的任务	图标开启需要接取的任务
	int OpenTaskCo;              	//图标开启需要完成的任务	图标开启需要完成的任务
	int Prompt;                  	//功能开启是否需要提示	功能开启是否需要提示

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
	SysIconElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//主界面图标配置脜盲脰脙路芒脳掳脌脿
class SysIconTable
{
	friend class TableData;
private:
	SysIconTable(){}
	~SysIconTable(){}
	map<int, SysIconElement>	m_mapElements;
	vector<SysIconElement>	m_vecAllElements;
	SysIconElement m_emptyItem;
public:
	static SysIconTable& Instance()
	{
		static SysIconTable sInstance;
		return sInstance;
	}

	SysIconElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SysIconElement>&	GetAllElement()
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
		return LoadJson("SysIcon.json");
		#else
		string strTableContent;
		if( LoadConfigContent("SysIcon.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("SysIcon.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[SysIcon.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("SysIcon.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("SysIcon.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Desc"){printf_message("SysIcon.csv中字段[Desc]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("SysIcon.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Order"){printf_message("SysIcon.csv中字段[Order]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Icon"){printf_message("SysIcon.csv中字段[Icon]位置不对应");assert(false); return false; }
		if(vecLine[6]!="ShowLv"){printf_message("SysIcon.csv中字段[ShowLv]位置不对应");assert(false); return false; }
		if(vecLine[7]!="ShowTaskRe"){printf_message("SysIcon.csv中字段[ShowTaskRe]位置不对应");assert(false); return false; }
		if(vecLine[8]!="ShowTaskCo"){printf_message("SysIcon.csv中字段[ShowTaskCo]位置不对应");assert(false); return false; }
		if(vecLine[9]!="OpenLv"){printf_message("SysIcon.csv中字段[OpenLv]位置不对应");assert(false); return false; }
		if(vecLine[10]!="OpenTaskRe"){printf_message("SysIcon.csv中字段[OpenTaskRe]位置不对应");assert(false); return false; }
		if(vecLine[11]!="OpenTaskCo"){printf_message("SysIcon.csv中字段[OpenTaskCo]位置不对应");assert(false); return false; }
		if(vecLine[12]!="Prompt"){printf_message("SysIcon.csv中字段[Prompt]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			SysIconElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Desc=vecLine[2];
			member.Type=atoi(vecLine[3].c_str());
			member.Order=atoi(vecLine[4].c_str());
			member.Icon=vecLine[5];
			member.ShowLv=atoi(vecLine[6].c_str());
			member.ShowTaskRe=atoi(vecLine[7].c_str());
			member.ShowTaskCo=atoi(vecLine[8].c_str());
			member.OpenLv=atoi(vecLine[9].c_str());
			member.OpenTaskRe=atoi(vecLine[10].c_str());
			member.OpenTaskCo=atoi(vecLine[11].c_str());
			member.Prompt=atoi(vecLine[12].c_str());


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
		if(vecLine.size() != 13)
		{
			printf_message("SysIcon.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("SysIcon.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("SysIcon.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Desc"){printf_message("SysIcon.csv中字段[Desc]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("SysIcon.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Order"){printf_message("SysIcon.csv中字段[Order]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Icon"){printf_message("SysIcon.csv中字段[Icon]位置不对应");assert(false); return false; }
		if(vecLine[6]!="ShowLv"){printf_message("SysIcon.csv中字段[ShowLv]位置不对应");assert(false); return false; }
		if(vecLine[7]!="ShowTaskRe"){printf_message("SysIcon.csv中字段[ShowTaskRe]位置不对应");assert(false); return false; }
		if(vecLine[8]!="ShowTaskCo"){printf_message("SysIcon.csv中字段[ShowTaskCo]位置不对应");assert(false); return false; }
		if(vecLine[9]!="OpenLv"){printf_message("SysIcon.csv中字段[OpenLv]位置不对应");assert(false); return false; }
		if(vecLine[10]!="OpenTaskRe"){printf_message("SysIcon.csv中字段[OpenTaskRe]位置不对应");assert(false); return false; }
		if(vecLine[11]!="OpenTaskCo"){printf_message("SysIcon.csv中字段[OpenTaskCo]位置不对应");assert(false); return false; }
		if(vecLine[12]!="Prompt"){printf_message("SysIcon.csv中字段[Prompt]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)13)
			{
				assert(false);
				return false;
			}
			SysIconElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Desc=vecLine[2];
			member.Type=atoi(vecLine[3].c_str());
			member.Order=atoi(vecLine[4].c_str());
			member.Icon=vecLine[5];
			member.ShowLv=atoi(vecLine[6].c_str());
			member.ShowTaskRe=atoi(vecLine[7].c_str());
			member.ShowTaskCo=atoi(vecLine[8].c_str());
			member.OpenLv=atoi(vecLine[9].c_str());
			member.OpenTaskRe=atoi(vecLine[10].c_str());
			member.OpenTaskCo=atoi(vecLine[11].c_str());
			member.Prompt=atoi(vecLine[12].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
