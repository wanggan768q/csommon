#ifndef __BAOSHIJIBAN_CONFIG_H
#define __BAOSHIJIBAN_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//宝石羁绊脜盲脰脙脢媒戮脻陆谩鹿鹿
struct BaoShiJiBanElement
{
	friend class BaoShiJiBanTable;
	int ID;                      	//编号	羁绊ID
	string Name;                 	//羁绊名称	羁绊名称
	int Set;                     	//所属装备类型	所属装备类型
	int Lv;                      	//羁绊等级	羁绊等级
	int KongShu;                 	//激活孔数	激活孔数
	string BaoShi;               	//激活所需宝石	激活所需宝石
	string Attr;                 	//属性类别	属性类别
	string Num;                  	//属性参数	属性参数

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
	BaoShiJiBanElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//宝石羁绊脜盲脰脙路芒脳掳脌脿
class BaoShiJiBanTable
{
	friend class TableData;
private:
	BaoShiJiBanTable(){}
	~BaoShiJiBanTable(){}
	map<int, BaoShiJiBanElement>	m_mapElements;
	vector<BaoShiJiBanElement>	m_vecAllElements;
	BaoShiJiBanElement m_emptyItem;
public:
	static BaoShiJiBanTable& Instance()
	{
		static BaoShiJiBanTable sInstance;
		return sInstance;
	}

	BaoShiJiBanElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BaoShiJiBanElement>&	GetAllElement()
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
		return LoadJson("BaoShiJiBan.json");
		#else
		string strTableContent;
		if( LoadConfigContent("BaoShiJiBan.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("BaoShiJiBan.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[BaoShiJiBan.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("BaoShiJiBan.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("BaoShiJiBan.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Set"){printf_message("BaoShiJiBan.csv中字段[Set]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Lv"){printf_message("BaoShiJiBan.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[4]!="KongShu"){printf_message("BaoShiJiBan.csv中字段[KongShu]位置不对应");assert(false); return false; }
		if(vecLine[5]!="BaoShi"){printf_message("BaoShiJiBan.csv中字段[BaoShi]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Attr"){printf_message("BaoShiJiBan.csv中字段[Attr]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Num"){printf_message("BaoShiJiBan.csv中字段[Num]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			BaoShiJiBanElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Set=atoi(vecLine[2].c_str());
			member.Lv=atoi(vecLine[3].c_str());
			member.KongShu=atoi(vecLine[4].c_str());
			member.BaoShi=vecLine[5];
			member.Attr=vecLine[6];
			member.Num=vecLine[7];


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
		if(vecLine.size() != 8)
		{
			printf_message("BaoShiJiBan.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("BaoShiJiBan.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("BaoShiJiBan.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Set"){printf_message("BaoShiJiBan.csv中字段[Set]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Lv"){printf_message("BaoShiJiBan.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[4]!="KongShu"){printf_message("BaoShiJiBan.csv中字段[KongShu]位置不对应");assert(false); return false; }
		if(vecLine[5]!="BaoShi"){printf_message("BaoShiJiBan.csv中字段[BaoShi]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Attr"){printf_message("BaoShiJiBan.csv中字段[Attr]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Num"){printf_message("BaoShiJiBan.csv中字段[Num]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)8)
			{
				assert(false);
				return false;
			}
			BaoShiJiBanElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Set=atoi(vecLine[2].c_str());
			member.Lv=atoi(vecLine[3].c_str());
			member.KongShu=atoi(vecLine[4].c_str());
			member.BaoShi=vecLine[5];
			member.Attr=vecLine[6];
			member.Num=vecLine[7];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
