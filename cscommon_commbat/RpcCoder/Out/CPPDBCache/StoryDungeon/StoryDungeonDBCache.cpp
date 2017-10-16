/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     StoryDungeonDBCache.cpp
* Author:       甘业清
* Description:  剧情副本数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "StoryDungeonDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataStoryDungeon);

//剧情副本实现类构造函数
DataStoryDungeon::DataStoryDungeon()
{
	m_mapDataWraperVersionName[1] = "StoryDungeonStoryDungeonWraperV1";
	
}

//剧情副本实现类析构函数
DataStoryDungeon::~DataStoryDungeon()
{

}


//获取模块ID
UINT8 DataStoryDungeon::GetModuleId()
{
	return MODULE_ID_STORYDUNGEON;
}

//获取模块名字
TStr DataStoryDungeon::GetModuleName()
{
	return "StoryDungeon";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataStoryDungeon::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataStoryDungeon::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataStoryDungeon::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataStoryDungeon::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataStoryDungeon::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	StoryDungeonStoryDungeonWraperV1* pDataWraper = (StoryDungeonStoryDungeonWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_STORYDUNGEON_STORYDUNGEON:
		if( Index<0 )
		{
			pDataWraper->ClearStoryDungeon();
			break;
		}
		if (Index >= pDataWraper->SizeStoryDungeon())
		{
			int Count = Index -pDataWraper->SizeStoryDungeon() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddStoryDungeon(StoryDungeonStoryDungeonObjWraperV1());
		}
		{
			StoryDungeonStoryDungeonObjWraperV1 tmpStoryDungeonWraper;
			tmpStoryDungeonWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetStoryDungeon(Index,tmpStoryDungeonWraper);
		}
		break;
	case SYNCID_STORYDUNGEON_CHALLENGENUM:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetChallengeNum(iValue);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
