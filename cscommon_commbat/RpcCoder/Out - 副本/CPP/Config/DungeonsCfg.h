#ifndef __DUNGEONS_CONFIG_H
#define __DUNGEONS_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//副本表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct DungeonsElement
{
	friend class DungeonsTable;
	int DungeonsID;              	//副本ID	副本ID
	int FunctionID;              	//所属章节	副本所属的章节ID（1-普通剧情，2-英雄剧情，3-PVP，98-大逃杀，99-夺旗，91-1v1）
	int Type;                    	//副本类型	1PVE，2PVP，3主城，4野外,5世界副本,6帮会
	string SceneResource;        	//美术场景资源	美术场景资源
	string MonsterConfigure;     	//怪物配置链接	怪物配置链接
	string Name;                 	//副本名称	副本的名字
	string Music;                	//场景音乐	场景音乐
	string Describe;             	//副本描述	副本描述
	int RewardShow;              	//奖励显示	显示用的奖励
	string MonsterIcon;          	//怪物头像	副本列表内的图片
	int FBTime;                  	//挑战时间	挑战时间
	int ExitTime;                	//退出等待时间	退出等待时间
	int Close;                   	//中途退出	是否显示退出按钮
	int CloseType;               	//关闭类型	退出特殊操作类型（前后端特用1特殊，0忽略）
	string ShowMap;              	//地图显示	地图上显示的图标
	string MapResource;          	//小地图配置	小地图文件配置，如果为空则没有小地图,主城
	string MapLayer;             	//地图层	小地图层数据，名字加“,”隔开
	string MapSkewing;           	//小地图偏移	格式X,Y,向量偏移
	int MapRatio;                	//小地图缩放	填入的为像素，即1m=N像素
	string PKType;               	//容许的PK模式	1和平、2全体、3工会、4组队、5善恶
	int LimitLevel;              	//进入等级	容许进入该场景的等级
	string ResetTime;            	//重置时间	副本次数重置时间
	string OpenTime;             	//开放时间	副本的开放时间
	int Team;                    	//是否组队进入	是否组队进入（0不组队进 1组队进 2进入时退队 ）
	int TeamMembers;             	//组队进入最少人数	组队进入最少人数
	int ChallengeTimes;          	//可挑战次数	副本可免费挑战的次数
	int BuyTimes;                	//最大可购买次数	副本最大可购买次数
	int Reward1Star;             	//1星奖励	1星奖励
	int Reward2Star;             	//2星奖励	2星奖励
	int Reward3Star;             	//3星奖励	3星奖励
	int StarLevel;               	//起始等级	副本动态变化的起始等级，如果为-1则副本不进行动态变化
	int FinalLevel;              	//结束等级	副本动态变化的结束等级，如果为-1则副本不进行动态变化
	int Relive;                  	//复活方式	复活表的ID
	int AutoMode;                	//自动战斗方式	-1.不自动自动战斗，1.本层自动战斗（有范围配置），2.全图自动战斗
	int AutoScope;               	//索敌范围	单层自动战斗时配置范围，单位m
	int Mission;                 	//关联任务	关联任务

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
	DungeonsElement()
	{
		DungeonsID = -1;
		m_bIsValidate=false;
	}
};

//副本表脜盲脰脙路芒脳掳脌脿
class DungeonsTable
{
	friend class TableData;
private:
	DungeonsTable(){}
	~DungeonsTable(){}
	map<int, DungeonsElement>	m_mapElements;
	vector<DungeonsElement>	m_vecAllElements;
	DungeonsElement m_emptyItem;
public:
	static DungeonsTable& Instance()
	{
		static DungeonsTable sInstance;
		return sInstance;
	}

	DungeonsElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<DungeonsElement>&	GetAllElement()
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
		return LoadJson("Dungeons.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Dungeons.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Dungeons.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Dungeons.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="DungeonsID"){printf_message("Dungeons.csv中字段[DungeonsID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="FunctionID"){printf_message("Dungeons.csv中字段[FunctionID]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Type"){printf_message("Dungeons.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[3]!="SceneResource"){printf_message("Dungeons.csv中字段[SceneResource]位置不对应");assert(false); return false; }
		if(vecLine[4]!="MonsterConfigure"){printf_message("Dungeons.csv中字段[MonsterConfigure]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Name"){printf_message("Dungeons.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Music"){printf_message("Dungeons.csv中字段[Music]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Describe"){printf_message("Dungeons.csv中字段[Describe]位置不对应");assert(false); return false; }
		if(vecLine[8]!="RewardShow"){printf_message("Dungeons.csv中字段[RewardShow]位置不对应");assert(false); return false; }
		if(vecLine[9]!="MonsterIcon"){printf_message("Dungeons.csv中字段[MonsterIcon]位置不对应");assert(false); return false; }
		if(vecLine[10]!="FBTime"){printf_message("Dungeons.csv中字段[FBTime]位置不对应");assert(false); return false; }
		if(vecLine[11]!="ExitTime"){printf_message("Dungeons.csv中字段[ExitTime]位置不对应");assert(false); return false; }
		if(vecLine[12]!="Close"){printf_message("Dungeons.csv中字段[Close]位置不对应");assert(false); return false; }
		if(vecLine[13]!="CloseType"){printf_message("Dungeons.csv中字段[CloseType]位置不对应");assert(false); return false; }
		if(vecLine[14]!="ShowMap"){printf_message("Dungeons.csv中字段[ShowMap]位置不对应");assert(false); return false; }
		if(vecLine[15]!="MapResource"){printf_message("Dungeons.csv中字段[MapResource]位置不对应");assert(false); return false; }
		if(vecLine[16]!="MapLayer"){printf_message("Dungeons.csv中字段[MapLayer]位置不对应");assert(false); return false; }
		if(vecLine[17]!="MapSkewing"){printf_message("Dungeons.csv中字段[MapSkewing]位置不对应");assert(false); return false; }
		if(vecLine[18]!="MapRatio"){printf_message("Dungeons.csv中字段[MapRatio]位置不对应");assert(false); return false; }
		if(vecLine[19]!="PKType"){printf_message("Dungeons.csv中字段[PKType]位置不对应");assert(false); return false; }
		if(vecLine[20]!="LimitLevel"){printf_message("Dungeons.csv中字段[LimitLevel]位置不对应");assert(false); return false; }
		if(vecLine[21]!="ResetTime"){printf_message("Dungeons.csv中字段[ResetTime]位置不对应");assert(false); return false; }
		if(vecLine[22]!="OpenTime"){printf_message("Dungeons.csv中字段[OpenTime]位置不对应");assert(false); return false; }
		if(vecLine[23]!="Team"){printf_message("Dungeons.csv中字段[Team]位置不对应");assert(false); return false; }
		if(vecLine[24]!="TeamMembers"){printf_message("Dungeons.csv中字段[TeamMembers]位置不对应");assert(false); return false; }
		if(vecLine[25]!="ChallengeTimes"){printf_message("Dungeons.csv中字段[ChallengeTimes]位置不对应");assert(false); return false; }
		if(vecLine[26]!="BuyTimes"){printf_message("Dungeons.csv中字段[BuyTimes]位置不对应");assert(false); return false; }
		if(vecLine[27]!="Reward1Star"){printf_message("Dungeons.csv中字段[Reward1Star]位置不对应");assert(false); return false; }
		if(vecLine[28]!="Reward2Star"){printf_message("Dungeons.csv中字段[Reward2Star]位置不对应");assert(false); return false; }
		if(vecLine[29]!="Reward3Star"){printf_message("Dungeons.csv中字段[Reward3Star]位置不对应");assert(false); return false; }
		if(vecLine[30]!="StarLevel"){printf_message("Dungeons.csv中字段[StarLevel]位置不对应");assert(false); return false; }
		if(vecLine[31]!="FinalLevel"){printf_message("Dungeons.csv中字段[FinalLevel]位置不对应");assert(false); return false; }
		if(vecLine[32]!="Relive"){printf_message("Dungeons.csv中字段[Relive]位置不对应");assert(false); return false; }
		if(vecLine[33]!="AutoMode"){printf_message("Dungeons.csv中字段[AutoMode]位置不对应");assert(false); return false; }
		if(vecLine[34]!="AutoScope"){printf_message("Dungeons.csv中字段[AutoScope]位置不对应");assert(false); return false; }
		if(vecLine[35]!="Mission"){printf_message("Dungeons.csv中字段[Mission]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			DungeonsElement	member;

						member.DungeonsID=atoi(vecLine[0].c_str());
			member.FunctionID=atoi(vecLine[1].c_str());
			member.Type=atoi(vecLine[2].c_str());
			member.SceneResource=vecLine[3];
			member.MonsterConfigure=vecLine[4];
			member.Name=vecLine[5];
			member.Music=vecLine[6];
			member.Describe=vecLine[7];
			member.RewardShow=atoi(vecLine[8].c_str());
			member.MonsterIcon=vecLine[9];
			member.FBTime=atoi(vecLine[10].c_str());
			member.ExitTime=atoi(vecLine[11].c_str());
			member.Close=atoi(vecLine[12].c_str());
			member.CloseType=atoi(vecLine[13].c_str());
			member.ShowMap=vecLine[14];
			member.MapResource=vecLine[15];
			member.MapLayer=vecLine[16];
			member.MapSkewing=vecLine[17];
			member.MapRatio=atoi(vecLine[18].c_str());
			member.PKType=vecLine[19];
			member.LimitLevel=atoi(vecLine[20].c_str());
			member.ResetTime=vecLine[21];
			member.OpenTime=vecLine[22];
			member.Team=atoi(vecLine[23].c_str());
			member.TeamMembers=atoi(vecLine[24].c_str());
			member.ChallengeTimes=atoi(vecLine[25].c_str());
			member.BuyTimes=atoi(vecLine[26].c_str());
			member.Reward1Star=atoi(vecLine[27].c_str());
			member.Reward2Star=atoi(vecLine[28].c_str());
			member.Reward3Star=atoi(vecLine[29].c_str());
			member.StarLevel=atoi(vecLine[30].c_str());
			member.FinalLevel=atoi(vecLine[31].c_str());
			member.Relive=atoi(vecLine[32].c_str());
			member.AutoMode=atoi(vecLine[33].c_str());
			member.AutoScope=atoi(vecLine[34].c_str());
			member.Mission=atoi(vecLine[35].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.DungeonsID] = member;
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
		if(vecLine.size() != 36)
		{
			printf_message("Dungeons.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="DungeonsID"){printf_message("Dungeons.csv中字段[DungeonsID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="FunctionID"){printf_message("Dungeons.csv中字段[FunctionID]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Type"){printf_message("Dungeons.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[3]!="SceneResource"){printf_message("Dungeons.csv中字段[SceneResource]位置不对应");assert(false); return false; }
		if(vecLine[4]!="MonsterConfigure"){printf_message("Dungeons.csv中字段[MonsterConfigure]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Name"){printf_message("Dungeons.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Music"){printf_message("Dungeons.csv中字段[Music]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Describe"){printf_message("Dungeons.csv中字段[Describe]位置不对应");assert(false); return false; }
		if(vecLine[8]!="RewardShow"){printf_message("Dungeons.csv中字段[RewardShow]位置不对应");assert(false); return false; }
		if(vecLine[9]!="MonsterIcon"){printf_message("Dungeons.csv中字段[MonsterIcon]位置不对应");assert(false); return false; }
		if(vecLine[10]!="FBTime"){printf_message("Dungeons.csv中字段[FBTime]位置不对应");assert(false); return false; }
		if(vecLine[11]!="ExitTime"){printf_message("Dungeons.csv中字段[ExitTime]位置不对应");assert(false); return false; }
		if(vecLine[12]!="Close"){printf_message("Dungeons.csv中字段[Close]位置不对应");assert(false); return false; }
		if(vecLine[13]!="CloseType"){printf_message("Dungeons.csv中字段[CloseType]位置不对应");assert(false); return false; }
		if(vecLine[14]!="ShowMap"){printf_message("Dungeons.csv中字段[ShowMap]位置不对应");assert(false); return false; }
		if(vecLine[15]!="MapResource"){printf_message("Dungeons.csv中字段[MapResource]位置不对应");assert(false); return false; }
		if(vecLine[16]!="MapLayer"){printf_message("Dungeons.csv中字段[MapLayer]位置不对应");assert(false); return false; }
		if(vecLine[17]!="MapSkewing"){printf_message("Dungeons.csv中字段[MapSkewing]位置不对应");assert(false); return false; }
		if(vecLine[18]!="MapRatio"){printf_message("Dungeons.csv中字段[MapRatio]位置不对应");assert(false); return false; }
		if(vecLine[19]!="PKType"){printf_message("Dungeons.csv中字段[PKType]位置不对应");assert(false); return false; }
		if(vecLine[20]!="LimitLevel"){printf_message("Dungeons.csv中字段[LimitLevel]位置不对应");assert(false); return false; }
		if(vecLine[21]!="ResetTime"){printf_message("Dungeons.csv中字段[ResetTime]位置不对应");assert(false); return false; }
		if(vecLine[22]!="OpenTime"){printf_message("Dungeons.csv中字段[OpenTime]位置不对应");assert(false); return false; }
		if(vecLine[23]!="Team"){printf_message("Dungeons.csv中字段[Team]位置不对应");assert(false); return false; }
		if(vecLine[24]!="TeamMembers"){printf_message("Dungeons.csv中字段[TeamMembers]位置不对应");assert(false); return false; }
		if(vecLine[25]!="ChallengeTimes"){printf_message("Dungeons.csv中字段[ChallengeTimes]位置不对应");assert(false); return false; }
		if(vecLine[26]!="BuyTimes"){printf_message("Dungeons.csv中字段[BuyTimes]位置不对应");assert(false); return false; }
		if(vecLine[27]!="Reward1Star"){printf_message("Dungeons.csv中字段[Reward1Star]位置不对应");assert(false); return false; }
		if(vecLine[28]!="Reward2Star"){printf_message("Dungeons.csv中字段[Reward2Star]位置不对应");assert(false); return false; }
		if(vecLine[29]!="Reward3Star"){printf_message("Dungeons.csv中字段[Reward3Star]位置不对应");assert(false); return false; }
		if(vecLine[30]!="StarLevel"){printf_message("Dungeons.csv中字段[StarLevel]位置不对应");assert(false); return false; }
		if(vecLine[31]!="FinalLevel"){printf_message("Dungeons.csv中字段[FinalLevel]位置不对应");assert(false); return false; }
		if(vecLine[32]!="Relive"){printf_message("Dungeons.csv中字段[Relive]位置不对应");assert(false); return false; }
		if(vecLine[33]!="AutoMode"){printf_message("Dungeons.csv中字段[AutoMode]位置不对应");assert(false); return false; }
		if(vecLine[34]!="AutoScope"){printf_message("Dungeons.csv中字段[AutoScope]位置不对应");assert(false); return false; }
		if(vecLine[35]!="Mission"){printf_message("Dungeons.csv中字段[Mission]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)36)
			{
				assert(false);
				return false;
			}
			DungeonsElement	member;
			member.DungeonsID=atoi(vecLine[0].c_str());
			member.FunctionID=atoi(vecLine[1].c_str());
			member.Type=atoi(vecLine[2].c_str());
			member.SceneResource=vecLine[3];
			member.MonsterConfigure=vecLine[4];
			member.Name=vecLine[5];
			member.Music=vecLine[6];
			member.Describe=vecLine[7];
			member.RewardShow=atoi(vecLine[8].c_str());
			member.MonsterIcon=vecLine[9];
			member.FBTime=atoi(vecLine[10].c_str());
			member.ExitTime=atoi(vecLine[11].c_str());
			member.Close=atoi(vecLine[12].c_str());
			member.CloseType=atoi(vecLine[13].c_str());
			member.ShowMap=vecLine[14];
			member.MapResource=vecLine[15];
			member.MapLayer=vecLine[16];
			member.MapSkewing=vecLine[17];
			member.MapRatio=atoi(vecLine[18].c_str());
			member.PKType=vecLine[19];
			member.LimitLevel=atoi(vecLine[20].c_str());
			member.ResetTime=vecLine[21];
			member.OpenTime=vecLine[22];
			member.Team=atoi(vecLine[23].c_str());
			member.TeamMembers=atoi(vecLine[24].c_str());
			member.ChallengeTimes=atoi(vecLine[25].c_str());
			member.BuyTimes=atoi(vecLine[26].c_str());
			member.Reward1Star=atoi(vecLine[27].c_str());
			member.Reward2Star=atoi(vecLine[28].c_str());
			member.Reward3Star=atoi(vecLine[29].c_str());
			member.StarLevel=atoi(vecLine[30].c_str());
			member.FinalLevel=atoi(vecLine[31].c_str());
			member.Relive=atoi(vecLine[32].c_str());
			member.AutoMode=atoi(vecLine[33].c_str());
			member.AutoScope=atoi(vecLine[34].c_str());
			member.Mission=atoi(vecLine[35].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.DungeonsID] = member;
		}
		return true;
	}
};

#endif
