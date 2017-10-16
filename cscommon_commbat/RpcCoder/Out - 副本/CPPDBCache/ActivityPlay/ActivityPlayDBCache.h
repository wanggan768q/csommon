/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ActivityPlayDBCache.h
* Author:       甘业清
* Description:  活动玩法数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __DATA_ACTIVITYPLAY_H
#define __DATA_ACTIVITYPLAY_H


#include "ModuleData.h"
#include "ActivityPlayV1DataWraper.h"


//同步数据相关枚举量定义
enum DataWraperItemIdE
{
	MODULE_ID_ACTIVITYPLAY = 38,
 	SYNCID_ACTIVITYPLAY_THIEFDATA               = 3801,  //江洋大盗数据
 	SYNCID_ACTIVITYPLAY_SUBDUEMONSTERDATA       = 3802,  //降妖除魔数据
 	SYNCID_ACTIVITYPLAY_WORLDBOSSDATA           = 3803,  //世界Boss数据
 	SYNCID_ACTIVITYPLAY_WORLDBOSSRANK           = 3804,  //世界Boss排名

};


//活动玩法数据类
class DataActivityPlay : public ModuleData
{
	DECLARE_INSTANCE(DataActivityPlay);
public:
	friend class			ModuleDataMgr;

public:
	//活动玩法实现类构造函数
	DataActivityPlay();
	
	//活动玩法实现类析构函数
	virtual					~DataActivityPlay();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//获取模块同步(保存)数据版本及类名
	virtual map<INT32,TStr>	GetDataWraperVersionName();
	
	//模块数据保存类型
	virtual SavedDataTypeE	GetSavedDataType();

	//是否保存数据到数据库中
	virtual bool			IsSaveModuleDataToDB();

	//模块同步(保存)数据升级函数
	virtual bool			UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur );
	
	//增量更新通知
	virtual bool			OnIncrementUpdate( INT64 key, int syncId, int IndexPos, const char* pBuffer, int dataLen );


private:
	 map<INT32,TStr>		m_mapDataWraperVersionName;
};

#endif