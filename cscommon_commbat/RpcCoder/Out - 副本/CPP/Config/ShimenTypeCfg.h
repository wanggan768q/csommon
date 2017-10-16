#ifndef __SHIMENTYPE_CONFIG_H
#define __SHIMENTYPE_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//师门任务类别表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct ShimenTypeElement
{
	friend class ShimenTypeTable;
	int ID;                      	//编号	仅仅是序号
	int Lvl;                     	//等级	玩家等级
	int Res;                     	//环数	每轮的环数
	int TypePro1;                	//类别1	类别1的权重概率
	string Type1;                	//类别1	类别1任务列表
	int TypePro2;                	//类别2	类别2的权重概率
	string Type2;                	//类别2	类别2任务列表
	int TypePro3;                	//类别3	类别3的权重概率
	string Type3;                	//类别3	类别3任务列表
	int TypePro4;                	//类别4	类别4的权重概率
	string Type4;                	//类别4	类别4任务列表
	int ExpReward;               	//经验	经验奖励
	int MoneyReward;             	//金钱	金钱奖励
	int SpecialRewardId;         	//特殊奖励	特殊奖励的掉落列ID
	int SpecialRewardPro;        	//特殊奖励概率	特殊奖励概率万分比

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
	ShimenTypeElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//师门任务类别表脜盲脰脙路芒脳掳脌脿
class ShimenTypeTable
{
	friend class TableData;
private:
	ShimenTypeTable(){}
	~ShimenTypeTable(){}
	map<int, ShimenTypeElement>	m_mapElements;
	vector<ShimenTypeElement>	m_vecAllElements;
	ShimenTypeElement m_emptyItem;
public:
	static ShimenTypeTable& Instance()
	{
		static ShimenTypeTable sInstance;
		return sInstance;
	}

	ShimenTypeElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ShimenTypeElement>&	GetAllElement()
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
		return LoadJson("ShimenType.json");
		#else
		string strTableContent;
		if( LoadConfigContent("ShimenType.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ShimenType.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[ShimenType.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("ShimenType.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Lvl"){printf_message("ShimenType.csv中字段[Lvl]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Res"){printf_message("ShimenType.csv中字段[Res]位置不对应");assert(false); return false; }
		if(vecLine[3]!="TypePro1"){printf_message("ShimenType.csv中字段[TypePro1]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Type1"){printf_message("ShimenType.csv中字段[Type1]位置不对应");assert(false); return false; }
		if(vecLine[5]!="TypePro2"){printf_message("ShimenType.csv中字段[TypePro2]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Type2"){printf_message("ShimenType.csv中字段[Type2]位置不对应");assert(false); return false; }
		if(vecLine[7]!="TypePro3"){printf_message("ShimenType.csv中字段[TypePro3]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Type3"){printf_message("ShimenType.csv中字段[Type3]位置不对应");assert(false); return false; }
		if(vecLine[9]!="TypePro4"){printf_message("ShimenType.csv中字段[TypePro4]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Type4"){printf_message("ShimenType.csv中字段[Type4]位置不对应");assert(false); return false; }
		if(vecLine[11]!="ExpReward"){printf_message("ShimenType.csv中字段[ExpReward]位置不对应");assert(false); return false; }
		if(vecLine[12]!="MoneyReward"){printf_message("ShimenType.csv中字段[MoneyReward]位置不对应");assert(false); return false; }
		if(vecLine[13]!="SpecialRewardId"){printf_message("ShimenType.csv中字段[SpecialRewardId]位置不对应");assert(false); return false; }
		if(vecLine[14]!="SpecialRewardPro"){printf_message("ShimenType.csv中字段[SpecialRewardPro]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			ShimenTypeElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Lvl=atoi(vecLine[1].c_str());
			member.Res=atoi(vecLine[2].c_str());
			member.TypePro1=atoi(vecLine[3].c_str());
			member.Type1=vecLine[4];
			member.TypePro2=atoi(vecLine[5].c_str());
			member.Type2=vecLine[6];
			member.TypePro3=atoi(vecLine[7].c_str());
			member.Type3=vecLine[8];
			member.TypePro4=atoi(vecLine[9].c_str());
			member.Type4=vecLine[10];
			member.ExpReward=atoi(vecLine[11].c_str());
			member.MoneyReward=atoi(vecLine[12].c_str());
			member.SpecialRewardId=atoi(vecLine[13].c_str());
			member.SpecialRewardPro=atoi(vecLine[14].c_str());


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
		if(vecLine.size() != 15)
		{
			printf_message("ShimenType.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("ShimenType.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Lvl"){printf_message("ShimenType.csv中字段[Lvl]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Res"){printf_message("ShimenType.csv中字段[Res]位置不对应");assert(false); return false; }
		if(vecLine[3]!="TypePro1"){printf_message("ShimenType.csv中字段[TypePro1]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Type1"){printf_message("ShimenType.csv中字段[Type1]位置不对应");assert(false); return false; }
		if(vecLine[5]!="TypePro2"){printf_message("ShimenType.csv中字段[TypePro2]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Type2"){printf_message("ShimenType.csv中字段[Type2]位置不对应");assert(false); return false; }
		if(vecLine[7]!="TypePro3"){printf_message("ShimenType.csv中字段[TypePro3]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Type3"){printf_message("ShimenType.csv中字段[Type3]位置不对应");assert(false); return false; }
		if(vecLine[9]!="TypePro4"){printf_message("ShimenType.csv中字段[TypePro4]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Type4"){printf_message("ShimenType.csv中字段[Type4]位置不对应");assert(false); return false; }
		if(vecLine[11]!="ExpReward"){printf_message("ShimenType.csv中字段[ExpReward]位置不对应");assert(false); return false; }
		if(vecLine[12]!="MoneyReward"){printf_message("ShimenType.csv中字段[MoneyReward]位置不对应");assert(false); return false; }
		if(vecLine[13]!="SpecialRewardId"){printf_message("ShimenType.csv中字段[SpecialRewardId]位置不对应");assert(false); return false; }
		if(vecLine[14]!="SpecialRewardPro"){printf_message("ShimenType.csv中字段[SpecialRewardPro]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)15)
			{
				assert(false);
				return false;
			}
			ShimenTypeElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Lvl=atoi(vecLine[1].c_str());
			member.Res=atoi(vecLine[2].c_str());
			member.TypePro1=atoi(vecLine[3].c_str());
			member.Type1=vecLine[4];
			member.TypePro2=atoi(vecLine[5].c_str());
			member.Type2=vecLine[6];
			member.TypePro3=atoi(vecLine[7].c_str());
			member.Type3=vecLine[8];
			member.TypePro4=atoi(vecLine[9].c_str());
			member.Type4=vecLine[10];
			member.ExpReward=atoi(vecLine[11].c_str());
			member.MoneyReward=atoi(vecLine[12].c_str());
			member.SpecialRewardId=atoi(vecLine[13].c_str());
			member.SpecialRewardPro=atoi(vecLine[14].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
