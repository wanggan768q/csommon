/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     TransportDBCache.h
* Author:       甘业清
* Description:  货运数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __DATA_TRANSPORT_H
#define __DATA_TRANSPORT_H


#include "ModuleData.h"
#include "TransportV1DataWraper.h"


//同步数据相关枚举量定义
enum DataWraperItemIdE
{
	MODULE_ID_TRANSPORT = 40,
 	SYNCID_TRANSPORT_GOODSARRAY                 = 4001,  //货物容器
 	SYNCID_TRANSPORT_ASKNUM                     = 4002,  //请求数量
 	SYNCID_TRANSPORT_HELPNUM                    = 4003,  //帮助次数
 	SYNCID_TRANSPORT_REWARDARRY                 = 4004,  //起航奖励
 	SYNCID_TRANSPORT_REWARDFLAG                 = 4006,  //奖励是否领取标识
 	SYNCID_TRANSPORT_PICKTASKFLAG               = 4007,  //是否接取任务

};


//货运数据类
class DataTransport : public ModuleData
{
	DECLARE_INSTANCE(DataTransport);
public:
	friend class			ModuleDataMgr;

public:
	//货运实现类构造函数
	DataTransport();
	
	//货运实现类析构函数
	virtual					~DataTransport();

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