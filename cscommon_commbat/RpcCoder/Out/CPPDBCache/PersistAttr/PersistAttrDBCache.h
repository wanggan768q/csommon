/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     PersistAttrDBCache.h
* Author:       甘业清
* Description:  常驻内存属性模块数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __DATA_PERSISTATTR_H
#define __DATA_PERSISTATTR_H


#include "ModuleData.h"
#include "PersistAttrV1DataWraper.h"


//同步数据相关枚举量定义
enum DataWraperItemIdE
{
	MODULE_ID_PERSISTATTR = 10,
 	SYNCID_PERSISTATTR_USERNAME                 = 1001,  //战队名字
 	SYNCID_PERSISTATTR_USERID                   = 1003,  //用户ID
 	SYNCID_PERSISTATTR_PLATNAME                 = 1004,  //游戏中心账号名
 	SYNCID_PERSISTATTR_ACCOUNTID                = 1021,  //游戏中心账号ID
 	SYNCID_PERSISTATTR_LEVEL                    = 1030,  //战队等级
 	SYNCID_PERSISTATTR_RANK                     = 1031,  //官阶
 	SYNCID_PERSISTATTR_FIGHTPOWER               = 1032,  //战力
 	SYNCID_PERSISTATTR_SEC                      = 1033,  //登录时间秒
 	SYNCID_PERSISTATTR_PROF                     = 1035,  //职业
 	SYNCID_PERSISTATTR_ONLINESTATE              = 1036,  //在线状态
 	SYNCID_PERSISTATTR_TEAMID                   = 1037,  //组队id
 	SYNCID_PERSISTATTR_SHOPSCORE                = 1039,  //几分商城
 	SYNCID_PERSISTATTR_DUNGEONID                = 1042,  //当前场景Id
 	SYNCID_PERSISTATTR_SESSIONKEY               = 1043,  //SessionKey
 	SYNCID_PERSISTATTR_GUILDID                  = 1044,  //帮会Id

};


//常驻内存属性模块数据类
class DataPersistAttr : public ModuleData
{
	DECLARE_INSTANCE(DataPersistAttr);
public:
	friend class			ModuleDataMgr;

public:
	//常驻内存属性模块实现类构造函数
	DataPersistAttr();
	
	//常驻内存属性模块实现类析构函数
	virtual					~DataPersistAttr();

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