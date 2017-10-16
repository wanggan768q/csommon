#ifndef __MISSIONTIAOJIAN_CONFIG_H
#define __MISSIONTIAOJIAN_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//任务条件脜盲脰脙脢媒戮脻陆谩鹿鹿
struct MissionTiaoJianElement
{
	friend class MissionTiaoJianTable;
	int ID;                      	//编号	条件ID
	int TiaoJian1;               	//目标1类型	1送信2杀怪3收集物品4使用物品5杀怪收集6采集7杀boss8达到特定等级
	int CanShu1;                 	//目标1	目标1
	int Num1;                    	//目标1数量	目标1数量
	string DaoHang1;             	//目标导航1	目标导航1
	string XunLu1;               	//寻路1	寻路1
	int TiaoJian2;               	//目标2类型	目标2类型
	int CanShu2;                 	//目标2	目标2
	int Num2;                    	//目标2数量	目标2数量
	string DaoHang2;             	//目标导航2	目标导航2
	string XunLu2;               	//寻路1	寻路1
	int TiaoJian3;               	//目标3类型	目标3类型
	int CanShu3;                 	//目标3	目标3
	int Num3;                    	//目标3数量	目标3数量
	string DaoHang3;             	//目标导航3	目标导航3
	string XunLu3;               	//寻路1	寻路1
	string Finish;               	//完成导航	完成导航
	string FinishXianShi;        	//完成导航显示文字	完成导航显示文字

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
	MissionTiaoJianElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//任务条件脜盲脰脙路芒脳掳脌脿
class MissionTiaoJianTable
{
	friend class TableData;
private:
	MissionTiaoJianTable(){}
	~MissionTiaoJianTable(){}
	map<int, MissionTiaoJianElement>	m_mapElements;
	vector<MissionTiaoJianElement>	m_vecAllElements;
	MissionTiaoJianElement m_emptyItem;
public:
	static MissionTiaoJianTable& Instance()
	{
		static MissionTiaoJianTable sInstance;
		return sInstance;
	}

	MissionTiaoJianElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<MissionTiaoJianElement>&	GetAllElement()
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
		return LoadJson("MissionTiaoJian.json");
		#else
		string strTableContent;
		if( LoadConfigContent("MissionTiaoJian.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("MissionTiaoJian.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[MissionTiaoJian.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("MissionTiaoJian.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="TiaoJian1"){printf_message("MissionTiaoJian.csv中字段[TiaoJian1]位置不对应");assert(false); return false; }
		if(vecLine[2]!="CanShu1"){printf_message("MissionTiaoJian.csv中字段[CanShu1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Num1"){printf_message("MissionTiaoJian.csv中字段[Num1]位置不对应");assert(false); return false; }
		if(vecLine[4]!="DaoHang1"){printf_message("MissionTiaoJian.csv中字段[DaoHang1]位置不对应");assert(false); return false; }
		if(vecLine[5]!="XunLu1"){printf_message("MissionTiaoJian.csv中字段[XunLu1]位置不对应");assert(false); return false; }
		if(vecLine[6]!="TiaoJian2"){printf_message("MissionTiaoJian.csv中字段[TiaoJian2]位置不对应");assert(false); return false; }
		if(vecLine[7]!="CanShu2"){printf_message("MissionTiaoJian.csv中字段[CanShu2]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Num2"){printf_message("MissionTiaoJian.csv中字段[Num2]位置不对应");assert(false); return false; }
		if(vecLine[9]!="DaoHang2"){printf_message("MissionTiaoJian.csv中字段[DaoHang2]位置不对应");assert(false); return false; }
		if(vecLine[10]!="XunLu2"){printf_message("MissionTiaoJian.csv中字段[XunLu2]位置不对应");assert(false); return false; }
		if(vecLine[11]!="TiaoJian3"){printf_message("MissionTiaoJian.csv中字段[TiaoJian3]位置不对应");assert(false); return false; }
		if(vecLine[12]!="CanShu3"){printf_message("MissionTiaoJian.csv中字段[CanShu3]位置不对应");assert(false); return false; }
		if(vecLine[13]!="Num3"){printf_message("MissionTiaoJian.csv中字段[Num3]位置不对应");assert(false); return false; }
		if(vecLine[14]!="DaoHang3"){printf_message("MissionTiaoJian.csv中字段[DaoHang3]位置不对应");assert(false); return false; }
		if(vecLine[15]!="XunLu3"){printf_message("MissionTiaoJian.csv中字段[XunLu3]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Finish"){printf_message("MissionTiaoJian.csv中字段[Finish]位置不对应");assert(false); return false; }
		if(vecLine[17]!="FinishXianShi"){printf_message("MissionTiaoJian.csv中字段[FinishXianShi]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			MissionTiaoJianElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.TiaoJian1=atoi(vecLine[1].c_str());
			member.CanShu1=atoi(vecLine[2].c_str());
			member.Num1=atoi(vecLine[3].c_str());
			member.DaoHang1=vecLine[4];
			member.XunLu1=vecLine[5];
			member.TiaoJian2=atoi(vecLine[6].c_str());
			member.CanShu2=atoi(vecLine[7].c_str());
			member.Num2=atoi(vecLine[8].c_str());
			member.DaoHang2=vecLine[9];
			member.XunLu2=vecLine[10];
			member.TiaoJian3=atoi(vecLine[11].c_str());
			member.CanShu3=atoi(vecLine[12].c_str());
			member.Num3=atoi(vecLine[13].c_str());
			member.DaoHang3=vecLine[14];
			member.XunLu3=vecLine[15];
			member.Finish=vecLine[16];
			member.FinishXianShi=vecLine[17];


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
		if(vecLine.size() != 18)
		{
			printf_message("MissionTiaoJian.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("MissionTiaoJian.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="TiaoJian1"){printf_message("MissionTiaoJian.csv中字段[TiaoJian1]位置不对应");assert(false); return false; }
		if(vecLine[2]!="CanShu1"){printf_message("MissionTiaoJian.csv中字段[CanShu1]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Num1"){printf_message("MissionTiaoJian.csv中字段[Num1]位置不对应");assert(false); return false; }
		if(vecLine[4]!="DaoHang1"){printf_message("MissionTiaoJian.csv中字段[DaoHang1]位置不对应");assert(false); return false; }
		if(vecLine[5]!="XunLu1"){printf_message("MissionTiaoJian.csv中字段[XunLu1]位置不对应");assert(false); return false; }
		if(vecLine[6]!="TiaoJian2"){printf_message("MissionTiaoJian.csv中字段[TiaoJian2]位置不对应");assert(false); return false; }
		if(vecLine[7]!="CanShu2"){printf_message("MissionTiaoJian.csv中字段[CanShu2]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Num2"){printf_message("MissionTiaoJian.csv中字段[Num2]位置不对应");assert(false); return false; }
		if(vecLine[9]!="DaoHang2"){printf_message("MissionTiaoJian.csv中字段[DaoHang2]位置不对应");assert(false); return false; }
		if(vecLine[10]!="XunLu2"){printf_message("MissionTiaoJian.csv中字段[XunLu2]位置不对应");assert(false); return false; }
		if(vecLine[11]!="TiaoJian3"){printf_message("MissionTiaoJian.csv中字段[TiaoJian3]位置不对应");assert(false); return false; }
		if(vecLine[12]!="CanShu3"){printf_message("MissionTiaoJian.csv中字段[CanShu3]位置不对应");assert(false); return false; }
		if(vecLine[13]!="Num3"){printf_message("MissionTiaoJian.csv中字段[Num3]位置不对应");assert(false); return false; }
		if(vecLine[14]!="DaoHang3"){printf_message("MissionTiaoJian.csv中字段[DaoHang3]位置不对应");assert(false); return false; }
		if(vecLine[15]!="XunLu3"){printf_message("MissionTiaoJian.csv中字段[XunLu3]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Finish"){printf_message("MissionTiaoJian.csv中字段[Finish]位置不对应");assert(false); return false; }
		if(vecLine[17]!="FinishXianShi"){printf_message("MissionTiaoJian.csv中字段[FinishXianShi]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)18)
			{
				assert(false);
				return false;
			}
			MissionTiaoJianElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.TiaoJian1=atoi(vecLine[1].c_str());
			member.CanShu1=atoi(vecLine[2].c_str());
			member.Num1=atoi(vecLine[3].c_str());
			member.DaoHang1=vecLine[4];
			member.XunLu1=vecLine[5];
			member.TiaoJian2=atoi(vecLine[6].c_str());
			member.CanShu2=atoi(vecLine[7].c_str());
			member.Num2=atoi(vecLine[8].c_str());
			member.DaoHang2=vecLine[9];
			member.XunLu2=vecLine[10];
			member.TiaoJian3=atoi(vecLine[11].c_str());
			member.CanShu3=atoi(vecLine[12].c_str());
			member.Num3=atoi(vecLine[13].c_str());
			member.DaoHang3=vecLine[14];
			member.XunLu3=vecLine[15];
			member.Finish=vecLine[16];
			member.FinishXianShi=vecLine[17];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
