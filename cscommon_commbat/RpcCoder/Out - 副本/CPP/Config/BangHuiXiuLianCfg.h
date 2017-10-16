#ifndef __BANGHUIXIULIAN_CONFIG_H
#define __BANGHUIXIULIAN_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//帮会修炼脜盲脰脙脢媒戮脻陆谩鹿鹿
struct BangHuiXiuLianElement
{
	friend class BangHuiXiuLianTable;
	int ID;                      	//编号	属性等级
	int Type;                    	//属性类型	属性类型
	int Lv;                      	//属性等级	属性等级
	int JieMian;                 	//所属界面	1基础属性2元素伤害3元素抗性4控制强化5控制抗性
	int Exp;                     	//所需经验	所需经验
	int CanShu;                  	//对应提升参数	对应提升参数

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
	BangHuiXiuLianElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//帮会修炼脜盲脰脙路芒脳掳脌脿
class BangHuiXiuLianTable
{
	friend class TableData;
private:
	BangHuiXiuLianTable(){}
	~BangHuiXiuLianTable(){}
	map<int, BangHuiXiuLianElement>	m_mapElements;
	vector<BangHuiXiuLianElement>	m_vecAllElements;
	BangHuiXiuLianElement m_emptyItem;
public:
	static BangHuiXiuLianTable& Instance()
	{
		static BangHuiXiuLianTable sInstance;
		return sInstance;
	}

	BangHuiXiuLianElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BangHuiXiuLianElement>&	GetAllElement()
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
		return LoadJson("BangHuiXiuLian.json");
		#else
		string strTableContent;
		if( LoadConfigContent("BangHuiXiuLian.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("BangHuiXiuLian.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[BangHuiXiuLian.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("BangHuiXiuLian.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Type"){printf_message("BangHuiXiuLian.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Lv"){printf_message("BangHuiXiuLian.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[3]!="JieMian"){printf_message("BangHuiXiuLian.csv中字段[JieMian]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Exp"){printf_message("BangHuiXiuLian.csv中字段[Exp]位置不对应");assert(false); return false; }
		if(vecLine[5]!="CanShu"){printf_message("BangHuiXiuLian.csv中字段[CanShu]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			BangHuiXiuLianElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Type=atoi(vecLine[1].c_str());
			member.Lv=atoi(vecLine[2].c_str());
			member.JieMian=atoi(vecLine[3].c_str());
			member.Exp=atoi(vecLine[4].c_str());
			member.CanShu=atoi(vecLine[5].c_str());


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
			printf_message("BangHuiXiuLian.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("BangHuiXiuLian.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Type"){printf_message("BangHuiXiuLian.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Lv"){printf_message("BangHuiXiuLian.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[3]!="JieMian"){printf_message("BangHuiXiuLian.csv中字段[JieMian]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Exp"){printf_message("BangHuiXiuLian.csv中字段[Exp]位置不对应");assert(false); return false; }
		if(vecLine[5]!="CanShu"){printf_message("BangHuiXiuLian.csv中字段[CanShu]位置不对应");assert(false); return false; }

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
			BangHuiXiuLianElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Type=atoi(vecLine[1].c_str());
			member.Lv=atoi(vecLine[2].c_str());
			member.JieMian=atoi(vecLine[3].c_str());
			member.Exp=atoi(vecLine[4].c_str());
			member.CanShu=atoi(vecLine[5].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
