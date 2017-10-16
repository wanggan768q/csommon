/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     OnlineDataDBCache.h
* Author:       甘业清
* Description:  在线数据数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __DATA_ONLINEDATA_H
#define __DATA_ONLINEDATA_H


#include "ModuleData.h"
#include "OnlineDataV1DataWraper.h"


//同步数据相关枚举量定义
enum DataWraperItemIdE
{
	MODULE_ID_ONLINEDATA = 28,
 	SYNCID_ONLINEDATA_BAGRECYCLEBIN             = 2801,  //回收站
 	SYNCID_ONLINEDATA_ROLEATTR                  = 2802,  //角色属性
 	SYNCID_ONLINEDATA_RECOMMENDFRIENDOFFSET     = 2804,  //推荐好友偏移
 	SYNCID_ONLINEDATA_RECOMMENDFRIENDFLUSHTIME  = 2805,  //推荐好友刷新时间
 	SYNCID_ONLINEDATA_RECOMMENDFRIENDLASTLIST   = 2806,  //上次推荐的好友
 	SYNCID_ONLINEDATA_FOLLOWMEUSERID            = 2807,  //跟随我的人
 	SYNCID_ONLINEDATA_FOLLOWWHO                 = 2809,  //跟随谁
 	SYNCID_ONLINEDATA_THIEFOBJID                = 2810,  //江洋大盗

};


//在线数据数据类
class DataOnlineData : public ModuleData
{
	DECLARE_INSTANCE(DataOnlineData);
public:
	friend class			ModuleDataMgr;

public:
	//在线数据实现类构造函数
	DataOnlineData();
	
	//在线数据实现类析构函数
	virtual					~DataOnlineData();

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