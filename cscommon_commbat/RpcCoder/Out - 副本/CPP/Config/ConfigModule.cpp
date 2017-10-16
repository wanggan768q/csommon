/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleConfig.cpp
* Author:       甘业清
* Description:  配置管理类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "ConfigModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleConfig);

//配置管理实现类构造函数
ModuleConfig::ModuleConfig()
{



	
	m_mapSyncDataVersionName[1] = "SyncDataConfigV1";
		
}

//配置管理实现类析构函数
ModuleConfig::~ModuleConfig()
{

}


//获取模块ID
UINT8 ModuleConfig::GetModuleId()
{
	return MODULE_ID_CONFIG;
}

//获取模块名字
TStr ModuleConfig::GetModuleName()
{
	return "Config";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleConfig::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleConfig::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleConfig::GetInitializeOrder()
{
	return MODULE_ID_CONFIG;
}

//获取结束退出顺序
int ModuleConfig::GetFinalizeOrder()
{
	return MODULE_ID_CONFIG;
}

//初始化
bool ModuleConfig::Initialize()
{

	AttackBehaviorTable::Instance().Load();
	BangHuiLvUpTable::Instance().Load();
	BangHuiManagerTable::Instance().Load();
	BangHuiXiuLianTable::Instance().Load();
	BaoShiJiBanTable::Instance().Load();
	BaoShiTable::Instance().Load();
	BaseAITable::Instance().Load();
	BASEConfigTable::Instance().Load();
	BuffPoolTable::Instance().Load();
	BuffTable::Instance().Load();
	CargoRewardTable::Instance().Load();
	CargoTypeTable::Instance().Load();
	CargoTable::Instance().Load();
	ChatMsgTable::Instance().Load();
	ChengJiuTable::Instance().Load();
	CiTanTable::Instance().Load();
	CiTiaoTable::Instance().Load();
	ColorTable::Instance().Load();
	CopyListTable::Instance().Load();
	DialogTable::Instance().Load();
	DropTable::Instance().Load();
	DungeonsTable::Instance().Load();
	EquipTable::Instance().Load();
	ExpandAITable::Instance().Load();
	FaBaoSkillTable::Instance().Load();
	FaBaoStarTable::Instance().Load();
	FaBaoTable::Instance().Load();
	FBDialogTable::Instance().Load();
	FBEventTable::Instance().Load();
	FormulaTable::Instance().Load();
	GatherTable::Instance().Load();
	GuideStepsTable::Instance().Load();
	GuideTable::Instance().Load();
	HeroTable::Instance().Load();
	HuoDongTable::Instance().Load();
	ItemTable::Instance().Load();
	JuLingLimitTable::Instance().Load();
	JuLingTable::Instance().Load();
	LifeSkillsTable::Instance().Load();
	LocationTable::Instance().Load();
	LVAttrTable::Instance().Load();
	LvUpTable::Instance().Load();
	MailIconTable::Instance().Load();
	MailMsgTable::Instance().Load();
	MissionTiaoJianTable::Instance().Load();
	MissionTable::Instance().Load();
	ModelBaseTable::Instance().Load();
	MonsterTable::Instance().Load();
	NpcTable::Instance().Load();
	OneVSOneFlushTopTable::Instance().Load();
	OneVSOneNumRewardTable::Instance().Load();
	OneVSOneTimeTable::Instance().Load();
	OneVSOneTopLVTable::Instance().Load();
	OneVSOneTopRewardTable::Instance().Load();
	PhizTable::Instance().Load();
	ProduceTable::Instance().Load();
	QiangHuaTable::Instance().Load();
	RandomNameTable::Instance().Load();
	RankingTable::Instance().Load();
	ReviveTable::Instance().Load();
	RewardTable::Instance().Load();
	SectionTable::Instance().Load();
	SensitiveWordTable::Instance().Load();
	ShimenTypeTable::Instance().Load();
	SkillConfigTable::Instance().Load();
	SkillLimitTable::Instance().Load();
	SkillTable::Instance().Load();
	SysIconTable::Instance().Load();
	TalentTable::Instance().Load();
	TeamConfigTable::Instance().Load();
	TianFuTable::Instance().Load();
	TrapTable::Instance().Load();
	VitalityTable::Instance().Load();
	WanFaConfigTable::Instance().Load();
	WorldMapTable::Instance().Load();
	YiTiaoLongTable::Instance().Load();
	LocalizationTable::Instance().Load();
	SysTipsTable::Instance().Load();
	PlotTable::Instance().Load();
	

	return true;
}

//结束退出
void ModuleConfig::Finalize()
{

}


//毫秒级Tick回调
void ModuleConfig::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleConfig::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleConfig::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleConfig::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleConfig::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleConfig::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleConfig::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleConfig::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleConfig::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleConfig::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

