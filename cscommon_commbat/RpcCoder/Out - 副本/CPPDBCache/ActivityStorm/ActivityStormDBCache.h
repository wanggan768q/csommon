/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ActivityStormDBCache.h
* Author:       甘业清
* Description:  活动 风暴数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __DATA_ACTIVITYSTORM_H
#define __DATA_ACTIVITYSTORM_H


#include "ModuleData.h"
#include "ActivityStormV1DataWraper.h"


//同步数据相关枚举量定义
enum DataWraperItemIdE
{
	MODULE_ID_ACTIVITYSTORM = 30,
 	SYNCID_ACTIVITYSTORM_TYPE                   = 3001,  //类型
 	SYNCID_ACTIVITYSTORM_TIME                   = 3002,  //倒计时时间
 	SYNCID_ACTIVITYSTORM_ACTID                  = 3003,  //战斗id 需要确认时候带回
 	SYNCID_ACTIVITYSTORM_LVD                    = 3004,  //等级段

};


//活动 风暴数据类
class DataActivityStorm : public ModuleData
{
	DECLARE_INSTANCE(DataActivityStorm);
public:
	friend class			ModuleDataMgr;

public:
	//活动 风暴实现类构造函数
	DataActivityStorm();
	
	//活动 风暴实现类析构函数
	virtual					~DataActivityStorm();

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