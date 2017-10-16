/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     BagDBCache.h
* Author:       甘业清
* Description:  背包数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __DATA_BAG_H
#define __DATA_BAG_H


#include "ModuleData.h"
#include "BagV1DataWraper.h"


//同步数据相关枚举量定义
enum DataWraperItemIdE
{
	MODULE_ID_BAG = 14,
 	SYNCID_BAG_GRIDARRAY                        = 1401,  //背包格子数组
 	SYNCID_BAG_EQUIPALLDATA                     = 1404,  //装备全部数据
 	SYNCID_BAG_WEAREQUIPCONTAINER               = 1405,  //穿戴装备容器
 	SYNCID_BAG_STORAGEBAGGRID                   = 1407,  //仓库
 	SYNCID_BAG_STORAGEBANK                      = 1408,  //仓库金钱
 	SYNCID_BAG_TALISMANDATA                     = 1409,  //法宝数据
 	SYNCID_BAG_TALISMANFOREVERATTR              = 1410,  //装备过的法宝，可获得永久属性加成
 	SYNCID_BAG_AUTOPICKUP                       = 1411,  //自动拾取设置
 	SYNCID_BAG_USEITEMDAY                       = 1415,  //每天使用的道具
 	SYNCID_BAG_USEITEMWEEK                      = 1416,  //每周使用的道具

};


//背包数据类
class DataBag : public ModuleData
{
	DECLARE_INSTANCE(DataBag);
public:
	friend class			ModuleDataMgr;

public:
	//背包实现类构造函数
	DataBag();
	
	//背包实现类析构函数
	virtual					~DataBag();

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