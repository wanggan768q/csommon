#ifndef __NPC_CONFIG_H
#define __NPC_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//Npc基础表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct NpcElement
{
	friend class NpcTable;
	int NpcID;                   	//NpcID	编号
	int ModelID;                 	//模型ID	索引模型
	float ModelScaling;          	//模型缩放	模型缩放比例，包含模型的所有东西进行缩放
	string Name;                 	//NPC名称	NPC名称
	string Title;                	//NPC称号	NPC称号
	string HeadIcon;             	//头像	NPC头像
	int Level;                   	//等级	NPC的等级
	float NpcR;                  	//半径	怪物模型的大小,单位：m
	int DialogID;                	//对话ID	触发的对话ID
	int FunctionID;              	//功能ID	调用哪个功能（1_PVE,2_PVP,3_武器店，4_装备店,5_药店，6_帮会副本,7师门8一条龙9江洋大盗10降妖除魔11帮会货运12大逃杀,21帮会刺探99跨场景传送）
	string DungeonsID;           	//场景ID	决定传送到哪个场景
	string Dialog;               	//默认对话	默认对话
	float banjing;               	//模型半径	触发重叠光效的距离

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
	NpcElement()
	{
		NpcID = -1;
		m_bIsValidate=false;
	}
};

//Npc基础表脜盲脰脙路芒脳掳脌脿
class NpcTable
{
	friend class TableData;
private:
	NpcTable(){}
	~NpcTable(){}
	map<int, NpcElement>	m_mapElements;
	vector<NpcElement>	m_vecAllElements;
	NpcElement m_emptyItem;
public:
	static NpcTable& Instance()
	{
		static NpcTable sInstance;
		return sInstance;
	}

	NpcElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<NpcElement>&	GetAllElement()
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
		return LoadJson("Npc.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Npc.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Npc.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Npc.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="NpcID"){printf_message("Npc.csv中字段[NpcID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="ModelID"){printf_message("Npc.csv中字段[ModelID]位置不对应");assert(false); return false; }
		if(vecLine[2]!="ModelScaling"){printf_message("Npc.csv中字段[ModelScaling]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Name"){printf_message("Npc.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Title"){printf_message("Npc.csv中字段[Title]位置不对应");assert(false); return false; }
		if(vecLine[5]!="HeadIcon"){printf_message("Npc.csv中字段[HeadIcon]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Level"){printf_message("Npc.csv中字段[Level]位置不对应");assert(false); return false; }
		if(vecLine[7]!="NpcR"){printf_message("Npc.csv中字段[NpcR]位置不对应");assert(false); return false; }
		if(vecLine[8]!="DialogID"){printf_message("Npc.csv中字段[DialogID]位置不对应");assert(false); return false; }
		if(vecLine[9]!="FunctionID"){printf_message("Npc.csv中字段[FunctionID]位置不对应");assert(false); return false; }
		if(vecLine[10]!="DungeonsID"){printf_message("Npc.csv中字段[DungeonsID]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Dialog"){printf_message("Npc.csv中字段[Dialog]位置不对应");assert(false); return false; }
		if(vecLine[12]!="banjing"){printf_message("Npc.csv中字段[banjing]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			NpcElement	member;

						member.NpcID=atoi(vecLine[0].c_str());
			member.ModelID=atoi(vecLine[1].c_str());
			member.ModelScaling=atof(vecLine[2].c_str());
			member.Name=vecLine[3];
			member.Title=vecLine[4];
			member.HeadIcon=vecLine[5];
			member.Level=atoi(vecLine[6].c_str());
			member.NpcR=atof(vecLine[7].c_str());
			member.DialogID=atoi(vecLine[8].c_str());
			member.FunctionID=atoi(vecLine[9].c_str());
			member.DungeonsID=vecLine[10];
			member.Dialog=vecLine[11];
			member.banjing=atof(vecLine[12].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.NpcID] = member;
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
			printf_message("Npc.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="NpcID"){printf_message("Npc.csv中字段[NpcID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="ModelID"){printf_message("Npc.csv中字段[ModelID]位置不对应");assert(false); return false; }
		if(vecLine[2]!="ModelScaling"){printf_message("Npc.csv中字段[ModelScaling]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Name"){printf_message("Npc.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[4]!="Title"){printf_message("Npc.csv中字段[Title]位置不对应");assert(false); return false; }
		if(vecLine[5]!="HeadIcon"){printf_message("Npc.csv中字段[HeadIcon]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Level"){printf_message("Npc.csv中字段[Level]位置不对应");assert(false); return false; }
		if(vecLine[7]!="NpcR"){printf_message("Npc.csv中字段[NpcR]位置不对应");assert(false); return false; }
		if(vecLine[8]!="DialogID"){printf_message("Npc.csv中字段[DialogID]位置不对应");assert(false); return false; }
		if(vecLine[9]!="FunctionID"){printf_message("Npc.csv中字段[FunctionID]位置不对应");assert(false); return false; }
		if(vecLine[10]!="DungeonsID"){printf_message("Npc.csv中字段[DungeonsID]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Dialog"){printf_message("Npc.csv中字段[Dialog]位置不对应");assert(false); return false; }
		if(vecLine[12]!="banjing"){printf_message("Npc.csv中字段[banjing]位置不对应");assert(false); return false; }

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
			NpcElement	member;
			member.NpcID=atoi(vecLine[0].c_str());
			member.ModelID=atoi(vecLine[1].c_str());
			member.ModelScaling=atof(vecLine[2].c_str());
			member.Name=vecLine[3];
			member.Title=vecLine[4];
			member.HeadIcon=vecLine[5];
			member.Level=atoi(vecLine[6].c_str());
			member.NpcR=atof(vecLine[7].c_str());
			member.DialogID=atoi(vecLine[8].c_str());
			member.FunctionID=atoi(vecLine[9].c_str());
			member.DungeonsID=vecLine[10];
			member.Dialog=vecLine[11];
			member.banjing=atof(vecLine[12].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.NpcID] = member;
		}
		return true;
	}
};

#endif
