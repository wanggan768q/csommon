#ifndef __GATHER_CONFIG_H
#define __GATHER_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//采集物脜盲脰脙脢媒戮脻陆谩鹿鹿
struct GatherElement
{
	friend class GatherTable;
	int GatherID;                	//ID	排序ID
	string Name;                 	//采集物名称	采集物的名字
	string Title;                	//采集物称号	采集物的称号
	int Type;                    	//采集物类型	1_草药，2_矿石，3_鱼塘
	int ModelID;                 	//模型ID	引用模型表数据
	float ModelScaling;          	//模型缩放	采集物模型缩放
	int Condition;               	//采集条件	-1_永久，1_任务，2_活动，3_状态
	int Item;                    	//产出物	索引ItemID
	int Duration;                	//采集时长	采集该采集物一个所消耗时长，单位s
	int Break;                   	//可否被打断	1可以，-1不可以
	int Times;                   	//采集次数	-1_无限，可采集几次填几次
	int Relive;                  	//复活间隔	消失后再次刷新所需时间，单位s
	float GatherR;               	//触发半径	可以触发采集动作的范围，单位:m
	int ChangJing;               	//场景ID	场景ID
	int Skill;                   	//动作ID	动作ID

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
	GatherElement()
	{
		GatherID = -1;
		m_bIsValidate=false;
	}
};

//采集物脜盲脰脙路芒脳掳脌脿
class GatherTable
{
	friend class TableData;
private:
	GatherTable(){}
	~GatherTable(){}
	map<int, GatherElement>	m_mapElements;
	vector<GatherElement>	m_vecAllElements;
	GatherElement m_emptyItem;
public:
	static GatherTable& Instance()
	{
		static GatherTable sInstance;
		return sInstance;
	}

	GatherElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<GatherElement>&	GetAllElement()
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
		return LoadJson("Gather.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Gather.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Gather.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Gather.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="GatherID"){printf_message("Gather.csv中字段[GatherID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Gather.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Title"){printf_message("Gather.csv中字段[Title]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("Gather.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="ModelID"){printf_message("Gather.csv中字段[ModelID]位置不对应");assert(false); return false; }
		if(vecLine[5]!="ModelScaling"){printf_message("Gather.csv中字段[ModelScaling]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Condition"){printf_message("Gather.csv中字段[Condition]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Item"){printf_message("Gather.csv中字段[Item]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Duration"){printf_message("Gather.csv中字段[Duration]位置不对应");assert(false); return false; }
		if(vecLine[9]!="Break"){printf_message("Gather.csv中字段[Break]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Times"){printf_message("Gather.csv中字段[Times]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Relive"){printf_message("Gather.csv中字段[Relive]位置不对应");assert(false); return false; }
		if(vecLine[12]!="GatherR"){printf_message("Gather.csv中字段[GatherR]位置不对应");assert(false); return false; }
		if(vecLine[13]!="ChangJing"){printf_message("Gather.csv中字段[ChangJing]位置不对应");assert(false); return false; }
		if(vecLine[14]!="Skill"){printf_message("Gather.csv中字段[Skill]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			GatherElement	member;

						member.GatherID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Title=vecLine[2];
			member.Type=atoi(vecLine[3].c_str());
			member.ModelID=atoi(vecLine[4].c_str());
			member.ModelScaling=atof(vecLine[5].c_str());
			member.Condition=atoi(vecLine[6].c_str());
			member.Item=atoi(vecLine[7].c_str());
			member.Duration=atoi(vecLine[8].c_str());
			member.Break=atoi(vecLine[9].c_str());
			member.Times=atoi(vecLine[10].c_str());
			member.Relive=atoi(vecLine[11].c_str());
			member.GatherR=atof(vecLine[12].c_str());
			member.ChangJing=atoi(vecLine[13].c_str());
			member.Skill=atoi(vecLine[14].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.GatherID] = member;
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
			printf_message("Gather.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="GatherID"){printf_message("Gather.csv中字段[GatherID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Gather.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Title"){printf_message("Gather.csv中字段[Title]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("Gather.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="ModelID"){printf_message("Gather.csv中字段[ModelID]位置不对应");assert(false); return false; }
		if(vecLine[5]!="ModelScaling"){printf_message("Gather.csv中字段[ModelScaling]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Condition"){printf_message("Gather.csv中字段[Condition]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Item"){printf_message("Gather.csv中字段[Item]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Duration"){printf_message("Gather.csv中字段[Duration]位置不对应");assert(false); return false; }
		if(vecLine[9]!="Break"){printf_message("Gather.csv中字段[Break]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Times"){printf_message("Gather.csv中字段[Times]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Relive"){printf_message("Gather.csv中字段[Relive]位置不对应");assert(false); return false; }
		if(vecLine[12]!="GatherR"){printf_message("Gather.csv中字段[GatherR]位置不对应");assert(false); return false; }
		if(vecLine[13]!="ChangJing"){printf_message("Gather.csv中字段[ChangJing]位置不对应");assert(false); return false; }
		if(vecLine[14]!="Skill"){printf_message("Gather.csv中字段[Skill]位置不对应");assert(false); return false; }

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
			GatherElement	member;
			member.GatherID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Title=vecLine[2];
			member.Type=atoi(vecLine[3].c_str());
			member.ModelID=atoi(vecLine[4].c_str());
			member.ModelScaling=atof(vecLine[5].c_str());
			member.Condition=atoi(vecLine[6].c_str());
			member.Item=atoi(vecLine[7].c_str());
			member.Duration=atoi(vecLine[8].c_str());
			member.Break=atoi(vecLine[9].c_str());
			member.Times=atoi(vecLine[10].c_str());
			member.Relive=atoi(vecLine[11].c_str());
			member.GatherR=atof(vecLine[12].c_str());
			member.ChangJing=atoi(vecLine[13].c_str());
			member.Skill=atoi(vecLine[14].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.GatherID] = member;
		}
		return true;
	}
};

#endif
