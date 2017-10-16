/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     PersistAttrDBCache.cpp
* Author:       甘业清
* Description:  常驻内存属性模块数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "PersistAttrDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataPersistAttr);

//常驻内存属性模块实现类构造函数
DataPersistAttr::DataPersistAttr()
{
	m_mapDataWraperVersionName[1] = "PersistAttrPersistAttrWraperV1";
	
}

//常驻内存属性模块实现类析构函数
DataPersistAttr::~DataPersistAttr()
{

}


//获取模块ID
UINT8 DataPersistAttr::GetModuleId()
{
	return MODULE_ID_PERSISTATTR;
}

//获取模块名字
TStr DataPersistAttr::GetModuleName()
{
	return "PersistAttr";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataPersistAttr::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataPersistAttr::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataPersistAttr::GetSavedDataType()
{
	return SAVE_CACHE_DATA;
}

//是否保存数据到数据库中
bool DataPersistAttr::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataPersistAttr::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	PersistAttrPersistAttrWraperV1* pDataWraper = (PersistAttrPersistAttrWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_PERSISTATTR_USERNAME:
		pDataWraper->SetUserName(string(pBuffer,dataLen));
		break;
	case SYNCID_PERSISTATTR_USERID:
		ReadVarint64FromArray(pBuffer,&lValue);
		pDataWraper->SetUserId(lValue);
		break;
	case SYNCID_PERSISTATTR_PLATNAME:
		pDataWraper->SetPlatName(string(pBuffer,dataLen));
		break;
	case SYNCID_PERSISTATTR_ACCOUNTID:
		ReadVarint64FromArray(pBuffer,&lValue);
		pDataWraper->SetAccountId(lValue);
		break;
	case SYNCID_PERSISTATTR_LEVEL:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetLevel(iValue);
		break;
	case SYNCID_PERSISTATTR_RANK:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetRank(iValue);
		break;
	case SYNCID_PERSISTATTR_FIGHTPOWER:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetFightPower(iValue);
		break;
	case SYNCID_PERSISTATTR_SEC:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetSec(iValue);
		break;
	case SYNCID_PERSISTATTR_PROF:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetProf(iValue);
		break;
	case SYNCID_PERSISTATTR_ONLINESTATE:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetOnlineState(iValue);
		break;
	case SYNCID_PERSISTATTR_TEAMID:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetTeamId(iValue);
		break;
	case SYNCID_PERSISTATTR_SHOPSCORE:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetShopScore(iValue);
		break;
	case SYNCID_PERSISTATTR_DUNGEONID:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetDungeonId(iValue);
		break;
	case SYNCID_PERSISTATTR_SESSIONKEY:
		pDataWraper->SetSessionKey(string(pBuffer,dataLen));
		break;
	case SYNCID_PERSISTATTR_GUILDID:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetGuildId(iValue);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
