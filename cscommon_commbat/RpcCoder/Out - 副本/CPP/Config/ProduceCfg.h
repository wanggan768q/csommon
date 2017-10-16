#ifndef __PRODUCE_CONFIG_H
#define __PRODUCE_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//生活技能产出表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct ProduceElement
{
	friend class ProduceTable;
	int ID;                      	//编号	编号
	int ProduceID;               	//生产道具ID	生产道具ID
	int LifeSkills;              	//所属生活技能类型	所属生活技能类型（1采集2种植3钓鱼4饲养5炼药6烹饪）
	int UnlockLevel ;            	//解锁等级	解锁等级
	int EnergyConsumption;       	//活力消耗	活力消耗
	int Type;                    	//获取类型	获取类型（1采集2配方制作）
	string Data;                 	//数据	采集类为坐标，生产类为材料道具ID
	int Time;                    	//生产时间	生产时间
	int Capacity1;               	//产出数量	产出数量
	int ZSSpecific;              	//战士特有产出	战士特有产出
	int Capacity2;               	//产出数量	产出数量
	int Probability1;            	//概率	概率
	int FSSpecific;              	//法师特有产出	法师特有产出
	int Capacity3;               	//产出数量	产出数量
	int Probability2;            	//概率	概率
	int GJSpecific;              	//弓手特有产出	弓手特有产出
	int Capacity4;               	//产出数量	产出数量
	int Probability3;            	//概率	概率
	int QSSpecific;              	//拳师特有产出	拳师特有产出
	int Capacity5;               	//产出数量	产出数量
	int Probability4;            	//概率	概率
	int MSSpecific;              	//牧师特有产出	牧师特有产出
	int Capacity6;               	//产出数量	产出数量
	int Probability5;            	//概率	概率

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
	ProduceElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//生活技能产出表脜盲脰脙路芒脳掳脌脿
class ProduceTable
{
	friend class TableData;
private:
	ProduceTable(){}
	~ProduceTable(){}
	map<int, ProduceElement>	m_mapElements;
	vector<ProduceElement>	m_vecAllElements;
	ProduceElement m_emptyItem;
public:
	static ProduceTable& Instance()
	{
		static ProduceTable sInstance;
		return sInstance;
	}

	ProduceElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ProduceElement>&	GetAllElement()
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
		return LoadJson("Produce.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Produce.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Produce.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Produce.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("Produce.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="ProduceID"){printf_message("Produce.csv中字段[ProduceID]位置不对应");assert(false); return false; }
		if(vecLine[2]!="LifeSkills"){printf_message("Produce.csv中字段[LifeSkills]位置不对应");assert(false); return false; }
		if(vecLine[3]!="UnlockLevel "){printf_message("Produce.csv中字段[UnlockLevel ]位置不对应");assert(false); return false; }
		if(vecLine[4]!="EnergyConsumption"){printf_message("Produce.csv中字段[EnergyConsumption]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Type"){printf_message("Produce.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Data"){printf_message("Produce.csv中字段[Data]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Time"){printf_message("Produce.csv中字段[Time]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Capacity1"){printf_message("Produce.csv中字段[Capacity1]位置不对应");assert(false); return false; }
		if(vecLine[9]!="ZSSpecific"){printf_message("Produce.csv中字段[ZSSpecific]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Capacity2"){printf_message("Produce.csv中字段[Capacity2]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Probability1"){printf_message("Produce.csv中字段[Probability1]位置不对应");assert(false); return false; }
		if(vecLine[12]!="FSSpecific"){printf_message("Produce.csv中字段[FSSpecific]位置不对应");assert(false); return false; }
		if(vecLine[13]!="Capacity3"){printf_message("Produce.csv中字段[Capacity3]位置不对应");assert(false); return false; }
		if(vecLine[14]!="Probability2"){printf_message("Produce.csv中字段[Probability2]位置不对应");assert(false); return false; }
		if(vecLine[15]!="GJSpecific"){printf_message("Produce.csv中字段[GJSpecific]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Capacity4"){printf_message("Produce.csv中字段[Capacity4]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Probability3"){printf_message("Produce.csv中字段[Probability3]位置不对应");assert(false); return false; }
		if(vecLine[18]!="QSSpecific"){printf_message("Produce.csv中字段[QSSpecific]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Capacity5"){printf_message("Produce.csv中字段[Capacity5]位置不对应");assert(false); return false; }
		if(vecLine[20]!="Probability4"){printf_message("Produce.csv中字段[Probability4]位置不对应");assert(false); return false; }
		if(vecLine[21]!="MSSpecific"){printf_message("Produce.csv中字段[MSSpecific]位置不对应");assert(false); return false; }
		if(vecLine[22]!="Capacity6"){printf_message("Produce.csv中字段[Capacity6]位置不对应");assert(false); return false; }
		if(vecLine[23]!="Probability5"){printf_message("Produce.csv中字段[Probability5]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			ProduceElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.ProduceID=atoi(vecLine[1].c_str());
			member.LifeSkills=atoi(vecLine[2].c_str());
			member.UnlockLevel =atoi(vecLine[3].c_str());
			member.EnergyConsumption=atoi(vecLine[4].c_str());
			member.Type=atoi(vecLine[5].c_str());
			member.Data=vecLine[6];
			member.Time=atoi(vecLine[7].c_str());
			member.Capacity1=atoi(vecLine[8].c_str());
			member.ZSSpecific=atoi(vecLine[9].c_str());
			member.Capacity2=atoi(vecLine[10].c_str());
			member.Probability1=atoi(vecLine[11].c_str());
			member.FSSpecific=atoi(vecLine[12].c_str());
			member.Capacity3=atoi(vecLine[13].c_str());
			member.Probability2=atoi(vecLine[14].c_str());
			member.GJSpecific=atoi(vecLine[15].c_str());
			member.Capacity4=atoi(vecLine[16].c_str());
			member.Probability3=atoi(vecLine[17].c_str());
			member.QSSpecific=atoi(vecLine[18].c_str());
			member.Capacity5=atoi(vecLine[19].c_str());
			member.Probability4=atoi(vecLine[20].c_str());
			member.MSSpecific=atoi(vecLine[21].c_str());
			member.Capacity6=atoi(vecLine[22].c_str());
			member.Probability5=atoi(vecLine[23].c_str());


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
		if(vecLine.size() != 24)
		{
			printf_message("Produce.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("Produce.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="ProduceID"){printf_message("Produce.csv中字段[ProduceID]位置不对应");assert(false); return false; }
		if(vecLine[2]!="LifeSkills"){printf_message("Produce.csv中字段[LifeSkills]位置不对应");assert(false); return false; }
		if(vecLine[3]!="UnlockLevel "){printf_message("Produce.csv中字段[UnlockLevel ]位置不对应");assert(false); return false; }
		if(vecLine[4]!="EnergyConsumption"){printf_message("Produce.csv中字段[EnergyConsumption]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Type"){printf_message("Produce.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Data"){printf_message("Produce.csv中字段[Data]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Time"){printf_message("Produce.csv中字段[Time]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Capacity1"){printf_message("Produce.csv中字段[Capacity1]位置不对应");assert(false); return false; }
		if(vecLine[9]!="ZSSpecific"){printf_message("Produce.csv中字段[ZSSpecific]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Capacity2"){printf_message("Produce.csv中字段[Capacity2]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Probability1"){printf_message("Produce.csv中字段[Probability1]位置不对应");assert(false); return false; }
		if(vecLine[12]!="FSSpecific"){printf_message("Produce.csv中字段[FSSpecific]位置不对应");assert(false); return false; }
		if(vecLine[13]!="Capacity3"){printf_message("Produce.csv中字段[Capacity3]位置不对应");assert(false); return false; }
		if(vecLine[14]!="Probability2"){printf_message("Produce.csv中字段[Probability2]位置不对应");assert(false); return false; }
		if(vecLine[15]!="GJSpecific"){printf_message("Produce.csv中字段[GJSpecific]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Capacity4"){printf_message("Produce.csv中字段[Capacity4]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Probability3"){printf_message("Produce.csv中字段[Probability3]位置不对应");assert(false); return false; }
		if(vecLine[18]!="QSSpecific"){printf_message("Produce.csv中字段[QSSpecific]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Capacity5"){printf_message("Produce.csv中字段[Capacity5]位置不对应");assert(false); return false; }
		if(vecLine[20]!="Probability4"){printf_message("Produce.csv中字段[Probability4]位置不对应");assert(false); return false; }
		if(vecLine[21]!="MSSpecific"){printf_message("Produce.csv中字段[MSSpecific]位置不对应");assert(false); return false; }
		if(vecLine[22]!="Capacity6"){printf_message("Produce.csv中字段[Capacity6]位置不对应");assert(false); return false; }
		if(vecLine[23]!="Probability5"){printf_message("Produce.csv中字段[Probability5]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)24)
			{
				assert(false);
				return false;
			}
			ProduceElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.ProduceID=atoi(vecLine[1].c_str());
			member.LifeSkills=atoi(vecLine[2].c_str());
			member.UnlockLevel =atoi(vecLine[3].c_str());
			member.EnergyConsumption=atoi(vecLine[4].c_str());
			member.Type=atoi(vecLine[5].c_str());
			member.Data=vecLine[6];
			member.Time=atoi(vecLine[7].c_str());
			member.Capacity1=atoi(vecLine[8].c_str());
			member.ZSSpecific=atoi(vecLine[9].c_str());
			member.Capacity2=atoi(vecLine[10].c_str());
			member.Probability1=atoi(vecLine[11].c_str());
			member.FSSpecific=atoi(vecLine[12].c_str());
			member.Capacity3=atoi(vecLine[13].c_str());
			member.Probability2=atoi(vecLine[14].c_str());
			member.GJSpecific=atoi(vecLine[15].c_str());
			member.Capacity4=atoi(vecLine[16].c_str());
			member.Probability3=atoi(vecLine[17].c_str());
			member.QSSpecific=atoi(vecLine[18].c_str());
			member.Capacity5=atoi(vecLine[19].c_str());
			member.Probability4=atoi(vecLine[20].c_str());
			member.MSSpecific=atoi(vecLine[21].c_str());
			member.Capacity6=atoi(vecLine[22].c_str());
			member.Probability5=atoi(vecLine[23].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
