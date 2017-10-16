/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleConfig.h
* Author:       甘业清
* Description:  配置管理类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
*               ★服务器后台RPC函数
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __MODULE_CONFIG_H
#define __MODULE_CONFIG_H


#include "ModuleBase.h"
#include "ConfigRpcWraper.h"

#include "AttackBehaviorCfg.h"
#include "BangHuiLvUpCfg.h"
#include "BangHuiManagerCfg.h"
#include "BangHuiXiuLianCfg.h"
#include "BaoShiJiBanCfg.h"
#include "BaoShiCfg.h"
#include "BaseAICfg.h"
#include "BASEConfigCfg.h"
#include "BuffPoolCfg.h"
#include "BuffCfg.h"
#include "CargoRewardCfg.h"
#include "CargoTypeCfg.h"
#include "CargoCfg.h"
#include "ChatMsgCfg.h"
#include "ChengJiuCfg.h"
#include "CiTanCfg.h"
#include "CiTiaoCfg.h"
#include "ColorCfg.h"
#include "CopyListCfg.h"
#include "DialogCfg.h"
#include "DropCfg.h"
#include "DungeonsCfg.h"
#include "EquipCfg.h"
#include "ExpandAICfg.h"
#include "FaBaoSkillCfg.h"
#include "FaBaoStarCfg.h"
#include "FaBaoCfg.h"
#include "FBDialogCfg.h"
#include "FBEventCfg.h"
#include "FormulaCfg.h"
#include "GatherCfg.h"
#include "GuideStepsCfg.h"
#include "GuideCfg.h"
#include "HeroCfg.h"
#include "HuoDongCfg.h"
#include "ItemCfg.h"
#include "JuLingLimitCfg.h"
#include "JuLingCfg.h"
#include "LifeSkillsCfg.h"
#include "LocationCfg.h"
#include "LVAttrCfg.h"
#include "LvUpCfg.h"
#include "MailIconCfg.h"
#include "MailMsgCfg.h"
#include "MissionTiaoJianCfg.h"
#include "MissionCfg.h"
#include "ModelBaseCfg.h"
#include "MonsterCfg.h"
#include "NpcCfg.h"
#include "OneVSOneFlushTopCfg.h"
#include "OneVSOneNumRewardCfg.h"
#include "OneVSOneTimeCfg.h"
#include "OneVSOneTopLVCfg.h"
#include "OneVSOneTopRewardCfg.h"
#include "PhizCfg.h"
#include "ProduceCfg.h"
#include "QiangHuaCfg.h"
#include "RandomNameCfg.h"
#include "RankingCfg.h"
#include "ReviveCfg.h"
#include "RewardCfg.h"
#include "SectionCfg.h"
#include "SensitiveWordCfg.h"
#include "ShimenTypeCfg.h"
#include "SkillConfigCfg.h"
#include "SkillLimitCfg.h"
#include "SkillCfg.h"
#include "SysIconCfg.h"
#include "TalentCfg.h"
#include "TeamConfigCfg.h"
#include "TianFuCfg.h"
#include "TrapCfg.h"
#include "VitalityCfg.h"
#include "WanFaConfigCfg.h"
#include "WorldMapCfg.h"
#include "YiTiaoLongCfg.h"
#include "LocalizationCfg.h"
#include "SysTipsCfg.h"
#include "PlotCfg.h"



//配置管理实现类
class ModuleConfig : public ModuleBase
{
	DECLARE_INSTANCE(ModuleConfig);
public:
	friend class			ModuleMgr;

public:
	//配置管理实现类构造函数
	ModuleConfig();
	
	//配置管理实现类析构函数
	virtual					~ModuleConfig();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//获取模块同步(保存)数据版本及类名
	virtual map<INT32,TStr>	GetModuleDataVersionName();
	
	//模块数据保存类型
	virtual SavedDataTypeE	GetSavedDataType();

	//获取初始化顺序
	virtual int				GetInitializeOrder();
	
	//获取结束退出顺序
	virtual int				GetFinalizeOrder();
	
	//初始化
	virtual bool			Initialize();
	
	//结束退出
	virtual void			Finalize();

	//毫秒级Tick回调
	virtual void			OnTick( INT64 currentMiliSecond );
	
	//秒级Tick回调
	virtual void			OnSecondTick( time_t currentSecond );
	
	//分钟改变回调
	virtual void			OnMinuteChange( time_t currentSecond);
	
	//小时改变回调
	virtual void			OnHourChange( time_t currentSecond );
	
	//天改变回调
	virtual void			OnDayChange( time_t currentSecond );

	//创建用户回调
	virtual void			OnUserCreate( INT64 userId, const TStr& userName );
	
	//用户上线回调
	virtual void			OnUserOnline( INT64 userId, time_t lastLogoutTime );
	
	//用户下线回调
	virtual void			OnUserOffline( INT64 userId );

	//是否要同步数据到客户端
	virtual bool			NotSyncToClient( UINT16 usSyncId );
	
	//同步数据修改后回调
	virtual void			NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex=-1);

public:


private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif