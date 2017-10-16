#ifndef __QIANGHUA_CONFIG_H
#define __QIANGHUA_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//装备强化脜盲脰脙脢媒戮脻陆谩鹿鹿
struct QiangHuaElement
{
	friend class QiangHuaTable;
	int LVID;                    	//编号	等级ID
	string Num;                  	//阈值范围	阈值范围
	string GaiLv;                	//取值概率	取值概率
	int Item;                    	//消耗道具	消耗道具
	int ItemNum;                 	//消耗数量	消耗数量
	int ZhuanYi;                 	//转移消耗	转移消耗元宝

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
	QiangHuaElement()
	{
		LVID = -1;
		m_bIsValidate=false;
	}
};

//装备强化脜盲脰脙路芒脳掳脌脿
class QiangHuaTable
{
	friend class TableData;
private:
	QiangHuaTable(){}
	~QiangHuaTable(){}
	map<int, QiangHuaElement>	m_mapElements;
	vector<QiangHuaElement>	m_vecAllElements;
	QiangHuaElement m_emptyItem;
public:
	static QiangHuaTable& Instance()
	{
		static QiangHuaTable sInstance;
		return sInstance;
	}

	QiangHuaElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<QiangHuaElement>&	GetAllElement()
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
		return LoadJson("QiangHua.json");
		#else
		string strTableContent;
		if( LoadConfigContent("QiangHua.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("QiangHua.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[QiangHua.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="LVID"){printf_message("QiangHua.csv中字段[LVID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Num"){printf_message("QiangHua.csv中字段[Num]位置不对应");assert(false); return false; }
		if(vecLine[2]!="GaiLv"){printf_message("QiangHua.csv中字段[GaiLv]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Item"){printf_message("QiangHua.csv中字段[Item]位置不对应");assert(false); return false; }
		if(vecLine[4]!="ItemNum"){printf_message("QiangHua.csv中字段[ItemNum]位置不对应");assert(false); return false; }
		if(vecLine[5]!="ZhuanYi"){printf_message("QiangHua.csv中字段[ZhuanYi]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			QiangHuaElement	member;

						member.LVID=atoi(vecLine[0].c_str());
			member.Num=vecLine[1];
			member.GaiLv=vecLine[2];
			member.Item=atoi(vecLine[3].c_str());
			member.ItemNum=atoi(vecLine[4].c_str());
			member.ZhuanYi=atoi(vecLine[5].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.LVID] = member;
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
			printf_message("QiangHua.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="LVID"){printf_message("QiangHua.csv中字段[LVID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Num"){printf_message("QiangHua.csv中字段[Num]位置不对应");assert(false); return false; }
		if(vecLine[2]!="GaiLv"){printf_message("QiangHua.csv中字段[GaiLv]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Item"){printf_message("QiangHua.csv中字段[Item]位置不对应");assert(false); return false; }
		if(vecLine[4]!="ItemNum"){printf_message("QiangHua.csv中字段[ItemNum]位置不对应");assert(false); return false; }
		if(vecLine[5]!="ZhuanYi"){printf_message("QiangHua.csv中字段[ZhuanYi]位置不对应");assert(false); return false; }

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
			QiangHuaElement	member;
			member.LVID=atoi(vecLine[0].c_str());
			member.Num=vecLine[1];
			member.GaiLv=vecLine[2];
			member.Item=atoi(vecLine[3].c_str());
			member.ItemNum=atoi(vecLine[4].c_str());
			member.ZhuanYi=atoi(vecLine[5].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.LVID] = member;
		}
		return true;
	}
};

#endif
