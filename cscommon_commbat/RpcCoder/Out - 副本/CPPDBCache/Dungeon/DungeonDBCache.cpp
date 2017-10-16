/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     DungeonDBCache.cpp
* Author:       甘业清
* Description:  进出副本模块数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "DungeonDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataDungeon);

//进出副本模块实现类构造函数
DataDungeon::DataDungeon()
{
	m_mapDataWraperVersionName[1] = "DungeonDungeonInfoWraperV1";
	
}

//进出副本模块实现类析构函数
DataDungeon::~DataDungeon()
{

}


//获取模块ID
UINT8 DataDungeon::GetModuleId()
{
	return MODULE_ID_DUNGEON;
}

//获取模块名字
TStr DataDungeon::GetModuleName()
{
	return "Dungeon";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataDungeon::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataDungeon::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataDungeon::GetSavedDataType()
{
	return SAVE_CACHE_DATA;
}

//是否保存数据到数据库中
bool DataDungeon::IsSaveModuleDataToDB()
{

	return false;
}

//增量更新通知
bool DataDungeon::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	DungeonDungeonInfoWraperV1* pDataWraper = (DungeonDungeonInfoWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_DUNGEON_DUNGEONKEY:
		pDataWraper->SetDungeonKey(string(pBuffer,dataLen));
		break;
	case SYNCID_DUNGEON_DUNGEONID:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetDungeonId(iValue);
		break;
	case SYNCID_DUNGEON_DUNGEONTYPE:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetDungeonType(iValue);
		break;
	case SYNCID_DUNGEON_KEYID:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetKeyId(iValue);
		break;
	case SYNCID_DUNGEON_HOST:
		pDataWraper->SetHost(string(pBuffer,dataLen));
		break;
	case SYNCID_DUNGEON_PORT:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetPort(iValue);
		break;
	case SYNCID_DUNGEON_GUILD:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetGuild(iValue);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
