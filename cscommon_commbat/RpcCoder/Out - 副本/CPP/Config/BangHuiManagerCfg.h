#ifndef __BANGHUIMANAGER_CONFIG_H
#define __BANGHUIMANAGER_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//帮会权限脜盲脰脙脢媒戮脻陆谩鹿鹿
struct BangHuiManagerElement
{
	friend class BangHuiManagerTable;
	int Type;                    	//职位类型	1帮主 2 副帮主 3 左长老 4 右长老 5 青龙堂主 6白虎堂主 7朱雀堂主 8玄武堂主 9精英 10帮众
	string Name;                 	//职位名称	职位名称
	int RenMing;                 	//任命关系	最低为1，向下递减任命
	int PiZhun;                  	//批准申请	1可以-1 不可以
	int YaoQing;                 	//邀请其他人	1可以-1不可以
	int TiChu;                   	//踢出其他成员	1可以-1不可以
	int IsRenMing;               	//是否可以任命	1可以-1不可以
	int CiZhi;                   	//是否可以辞职	1可以-1不可以
	int Num;                     	//职位数量	职位数量

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
	BangHuiManagerElement()
	{
		Type = -1;
		m_bIsValidate=false;
	}
};

//帮会权限脜盲脰脙路芒脳掳脌脿
class BangHuiManagerTable
{
	friend class TableData;
private:
	BangHuiManagerTable(){}
	~BangHuiManagerTable(){}
	map<int, BangHuiManagerElement>	m_mapElements;
	vector<BangHuiManagerElement>	m_vecAllElements;
	BangHuiManagerElement m_emptyItem;
public:
	static BangHuiManagerTable& Instance()
	{
		static BangHuiManagerTable sInstance;
		return sInstance;
	}

	BangHuiManagerElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BangHuiManagerElement>&	GetAllElement()
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
		return LoadJson("BangHuiManager.json");
		#else
		string strTableContent;
		if( LoadConfigContent("BangHuiManager.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("BangHuiManager.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[BangHuiManager.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="Type"){printf_message("BangHuiManager.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("BangHuiManager.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="RenMing"){printf_message("BangHuiManager.csv中字段[RenMing]位置不对应");assert(false); return false; }
		if(vecLine[3]!="PiZhun"){printf_message("BangHuiManager.csv中字段[PiZhun]位置不对应");assert(false); return false; }
		if(vecLine[4]!="YaoQing"){printf_message("BangHuiManager.csv中字段[YaoQing]位置不对应");assert(false); return false; }
		if(vecLine[5]!="TiChu"){printf_message("BangHuiManager.csv中字段[TiChu]位置不对应");assert(false); return false; }
		if(vecLine[6]!="IsRenMing"){printf_message("BangHuiManager.csv中字段[IsRenMing]位置不对应");assert(false); return false; }
		if(vecLine[7]!="CiZhi"){printf_message("BangHuiManager.csv中字段[CiZhi]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Num"){printf_message("BangHuiManager.csv中字段[Num]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			BangHuiManagerElement	member;

						member.Type=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.RenMing=atoi(vecLine[2].c_str());
			member.PiZhun=atoi(vecLine[3].c_str());
			member.YaoQing=atoi(vecLine[4].c_str());
			member.TiChu=atoi(vecLine[5].c_str());
			member.IsRenMing=atoi(vecLine[6].c_str());
			member.CiZhi=atoi(vecLine[7].c_str());
			member.Num=atoi(vecLine[8].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.Type] = member;
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
			printf_message("BangHuiManager.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="Type"){printf_message("BangHuiManager.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("BangHuiManager.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="RenMing"){printf_message("BangHuiManager.csv中字段[RenMing]位置不对应");assert(false); return false; }
		if(vecLine[3]!="PiZhun"){printf_message("BangHuiManager.csv中字段[PiZhun]位置不对应");assert(false); return false; }
		if(vecLine[4]!="YaoQing"){printf_message("BangHuiManager.csv中字段[YaoQing]位置不对应");assert(false); return false; }
		if(vecLine[5]!="TiChu"){printf_message("BangHuiManager.csv中字段[TiChu]位置不对应");assert(false); return false; }
		if(vecLine[6]!="IsRenMing"){printf_message("BangHuiManager.csv中字段[IsRenMing]位置不对应");assert(false); return false; }
		if(vecLine[7]!="CiZhi"){printf_message("BangHuiManager.csv中字段[CiZhi]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Num"){printf_message("BangHuiManager.csv中字段[Num]位置不对应");assert(false); return false; }

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
			BangHuiManagerElement	member;
			member.Type=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.RenMing=atoi(vecLine[2].c_str());
			member.PiZhun=atoi(vecLine[3].c_str());
			member.YaoQing=atoi(vecLine[4].c_str());
			member.TiChu=atoi(vecLine[5].c_str());
			member.IsRenMing=atoi(vecLine[6].c_str());
			member.CiZhi=atoi(vecLine[7].c_str());
			member.Num=atoi(vecLine[8].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.Type] = member;
		}
		return true;
	}
};

#endif
