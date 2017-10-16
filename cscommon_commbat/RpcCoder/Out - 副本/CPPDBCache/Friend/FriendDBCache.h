/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     FriendDBCache.h
* Author:       甘业清
* Description:  好友数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __DATA_FRIEND_H
#define __DATA_FRIEND_H


#include "ModuleData.h"
#include "FriendV1DataWraper.h"


//同步数据相关枚举量定义
enum DataWraperItemIdE
{
	MODULE_ID_FRIEND = 33,
 	SYNCID_FRIEND_FRIENDLIST                    = 3301,  //好友列表
 	SYNCID_FRIEND_BLACKLIST                     = 3302,  //黑名单
 	SYNCID_FRIEND_CONTACTSLIST                  = 3303,  //最近联系人
 	SYNCID_FRIEND_STRANGERFRIENDLIST            = 3304,  //加过我的人

};


//好友数据类
class DataFriend : public ModuleData
{
	DECLARE_INSTANCE(DataFriend);
public:
	friend class			ModuleDataMgr;

public:
	//好友实现类构造函数
	DataFriend();
	
	//好友实现类析构函数
	virtual					~DataFriend();

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