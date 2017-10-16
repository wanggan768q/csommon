/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     DungeonDBCache.h
* Author:       甘业清
* Description:  进出副本模块数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __DATA_DUNGEON_H
#define __DATA_DUNGEON_H


#include "ModuleData.h"
#include "DungeonV1DataWraper.h"


//同步数据相关枚举量定义
enum DataWraperItemIdE
{
	MODULE_ID_DUNGEON = 12,
 	SYNCID_DUNGEON_DUNGEONKEY                   = 1201,  //Key
 	SYNCID_DUNGEON_DUNGEONID                    = 1202,  //副本ID
 	SYNCID_DUNGEON_DUNGEONTYPE                  = 1203,  //副本类型
 	SYNCID_DUNGEON_KEYID                        = 1204,  //KeyId
 	SYNCID_DUNGEON_HOST                         = 1205,  //Host
 	SYNCID_DUNGEON_PORT                         = 1206,  //Port
 	SYNCID_DUNGEON_GUILD                        = 1207,  //帮派Id

};


//进出副本模块数据类
class DataDungeon : public ModuleData
{
	DECLARE_INSTANCE(DataDungeon);
public:
	friend class			ModuleDataMgr;

public:
	//进出副本模块实现类构造函数
	DataDungeon();
	
	//进出副本模块实现类析构函数
	virtual					~DataDungeon();

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