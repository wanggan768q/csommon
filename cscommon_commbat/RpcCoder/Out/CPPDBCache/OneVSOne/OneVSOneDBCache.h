/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     OneVSOneDBCache.h
* Author:       甘业清
* Description:  一v一数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __DATA_ONEVSONE_H
#define __DATA_ONEVSONE_H


#include "ModuleData.h"
#include "OneVSOneV1DataWraper.h"


//同步数据相关枚举量定义
enum DataWraperItemIdE
{
	MODULE_ID_ONEVSONE = 41,
 	SYNCID_ONEVSONE_SKILLDATE                   = 4104,  //技能数据
 	SYNCID_ONEVSONE_LOG                         = 4105,  //log日志
 	SYNCID_ONEVSONE_ONEVSONENUM                 = 4106,  //一对一的剩余次数
 	SYNCID_ONEVSONE_SAVETIME                    = 4107,  //格林威治时间服务器用
 	SYNCID_ONEVSONE_RANKING                     = 4108,  //排行名次
 	SYNCID_ONEVSONE_RANKINGTIMES                = 4110,  //排行名次 时间段的

};


//一v一数据类
class DataOneVSOne : public ModuleData
{
	DECLARE_INSTANCE(DataOneVSOne);
public:
	friend class			ModuleDataMgr;

public:
	//一v一实现类构造函数
	DataOneVSOne();
	
	//一v一实现类析构函数
	virtual					~DataOneVSOne();

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