/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RefreshDataDBCache.h
* Author:       甘业清
* Description:  刷新数据数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __DATA_REFRESHDATA_H
#define __DATA_REFRESHDATA_H


#include "ModuleData.h"
#include "RefreshDataV1DataWraper.h"


//同步数据相关枚举量定义
enum DataWraperItemIdE
{
	MODULE_ID_REFRESHDATA = 39,
 	SYNCID_REFRESHDATA_LASTREFRESHTIME          = 3901,  //上次刷新

};


//刷新数据数据类
class DataRefreshData : public ModuleData
{
	DECLARE_INSTANCE(DataRefreshData);
public:
	friend class			ModuleDataMgr;

public:
	//刷新数据实现类构造函数
	DataRefreshData();
	
	//刷新数据实现类析构函数
	virtual					~DataRefreshData();

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