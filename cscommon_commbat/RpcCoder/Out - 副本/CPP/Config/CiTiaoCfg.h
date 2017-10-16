#ifndef __CITIAO_CONFIG_H
#define __CITIAO_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//词条表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct CiTiaoElement
{
	friend class CiTiaoTable;
	int ID;                      	//词条	词条ID
	string Name;                 	//词条名称	词条名称
	int Type;                    	//显示方案	1普通2复合
	int Attr1;                   	//属性1	属性1
	string MiaoShu1;             	//属性1描述	属性1描述
	int FuHao1;                  	//属性1是否有百分号	1有-1 没有
	int Attr2;                   	//属性2	属性2
	string MiaoShu2;             	//属性2描述	属性2描述
	int FuHao2;                  	//属性2是否有百分号	属性2是否有百分号

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
	CiTiaoElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//词条表脜盲脰脙路芒脳掳脌脿
class CiTiaoTable
{
	friend class TableData;
private:
	CiTiaoTable(){}
	~CiTiaoTable(){}
	map<int, CiTiaoElement>	m_mapElements;
	vector<CiTiaoElement>	m_vecAllElements;
	CiTiaoElement m_emptyItem;
public:
	static CiTiaoTable& Instance()
	{
		static CiTiaoTable sInstance;
		return sInstance;
	}

	CiTiaoElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CiTiaoElement>&	GetAllElement()
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
		return LoadJson("CiTiao.json");
		#else
		string strTableContent;
		if( LoadConfigContent("CiTiao.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CiTiao.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[CiTiao.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("CiTiao.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("CiTiao.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Type"){printf_message("CiTiao.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Attr1"){printf_message("CiTiao.csv中字段[Attr1]位置不对应");assert(false); return false; }
		if(vecLine[4]!="MiaoShu1"){printf_message("CiTiao.csv中字段[MiaoShu1]位置不对应");assert(false); return false; }
		if(vecLine[5]!="FuHao1"){printf_message("CiTiao.csv中字段[FuHao1]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Attr2"){printf_message("CiTiao.csv中字段[Attr2]位置不对应");assert(false); return false; }
		if(vecLine[7]!="MiaoShu2"){printf_message("CiTiao.csv中字段[MiaoShu2]位置不对应");assert(false); return false; }
		if(vecLine[8]!="FuHao2"){printf_message("CiTiao.csv中字段[FuHao2]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			CiTiaoElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Type=atoi(vecLine[2].c_str());
			member.Attr1=atoi(vecLine[3].c_str());
			member.MiaoShu1=vecLine[4];
			member.FuHao1=atoi(vecLine[5].c_str());
			member.Attr2=atoi(vecLine[6].c_str());
			member.MiaoShu2=vecLine[7];
			member.FuHao2=atoi(vecLine[8].c_str());


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
		if(vecLine.size() != 9)
		{
			printf_message("CiTiao.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("CiTiao.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("CiTiao.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Type"){printf_message("CiTiao.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Attr1"){printf_message("CiTiao.csv中字段[Attr1]位置不对应");assert(false); return false; }
		if(vecLine[4]!="MiaoShu1"){printf_message("CiTiao.csv中字段[MiaoShu1]位置不对应");assert(false); return false; }
		if(vecLine[5]!="FuHao1"){printf_message("CiTiao.csv中字段[FuHao1]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Attr2"){printf_message("CiTiao.csv中字段[Attr2]位置不对应");assert(false); return false; }
		if(vecLine[7]!="MiaoShu2"){printf_message("CiTiao.csv中字段[MiaoShu2]位置不对应");assert(false); return false; }
		if(vecLine[8]!="FuHao2"){printf_message("CiTiao.csv中字段[FuHao2]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)9)
			{
				assert(false);
				return false;
			}
			CiTiaoElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Type=atoi(vecLine[2].c_str());
			member.Attr1=atoi(vecLine[3].c_str());
			member.MiaoShu1=vecLine[4];
			member.FuHao1=atoi(vecLine[5].c_str());
			member.Attr2=atoi(vecLine[6].c_str());
			member.MiaoShu2=vecLine[7];
			member.FuHao2=atoi(vecLine[8].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
