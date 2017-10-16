/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ActivityPlayDBCache.cpp
* Author:       甘业清
* Description:  活动玩法数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "ActivityPlayDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataActivityPlay);

//活动玩法实现类构造函数
DataActivityPlay::DataActivityPlay()
{
	m_mapDataWraperVersionName[1] = "ActivityPlayActivityDataWraperV1";
	
}

//活动玩法实现类析构函数
DataActivityPlay::~DataActivityPlay()
{

}


//获取模块ID
UINT8 DataActivityPlay::GetModuleId()
{
	return MODULE_ID_ACTIVITYPLAY;
}

//获取模块名字
TStr DataActivityPlay::GetModuleName()
{
	return "ActivityPlay";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataActivityPlay::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataActivityPlay::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataActivityPlay::GetSavedDataType()
{
	return SAVE_CACHE_DATA;
}

//是否保存数据到数据库中
bool DataActivityPlay::IsSaveModuleDataToDB()
{

	return false;
}

//增量更新通知
bool DataActivityPlay::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	ActivityPlayActivityDataWraperV1* pDataWraper = (ActivityPlayActivityDataWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_ACTIVITYPLAY_THIEFDATA:
		if( Index<0 )
		{
			pDataWraper->ClearThiefData();
			break;
		}
		if (Index >= pDataWraper->SizeThiefData())
		{
			int Count = Index -pDataWraper->SizeThiefData() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddThiefData(ActivityNpcDataWraper());
		}
		{
			ActivityNpcDataWraper tmpThiefDataWraper;
			tmpThiefDataWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetThiefData(Index,tmpThiefDataWraper);
		}
		break;
	case SYNCID_ACTIVITYPLAY_SUBDUEMONSTERDATA:
		if( Index<0 )
		{
			pDataWraper->ClearSubdueMonsterData();
			break;
		}
		if (Index >= pDataWraper->SizeSubdueMonsterData())
		{
			int Count = Index -pDataWraper->SizeSubdueMonsterData() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddSubdueMonsterData(ActivityNpcDataWraper());
		}
		{
			ActivityNpcDataWraper tmpSubdueMonsterDataWraper;
			tmpSubdueMonsterDataWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetSubdueMonsterData(Index,tmpSubdueMonsterDataWraper);
		}
		break;
	case SYNCID_ACTIVITYPLAY_WORLDBOSSDATA:
		if( Index<0 )
		{
			pDataWraper->ClearWorldBossData();
			break;
		}
		if (Index >= pDataWraper->SizeWorldBossData())
		{
			int Count = Index -pDataWraper->SizeWorldBossData() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddWorldBossData(WorldBossObjWraper());
		}
		{
			WorldBossObjWraper tmpWorldBossDataWraper;
			tmpWorldBossDataWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetWorldBossData(Index,tmpWorldBossDataWraper);
		}
		break;
	case SYNCID_ACTIVITYPLAY_WORLDBOSSRANK:
		if( Index<0 )
		{
			pDataWraper->ClearWorldBossRank();
			break;
		}
		if (Index >= pDataWraper->SizeWorldBossRank())
		{
			int Count = Index -pDataWraper->SizeWorldBossRank() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddWorldBossRank(WorldBossRankObjWraper());
		}
		{
			WorldBossRankObjWraper tmpWorldBossRankWraper;
			tmpWorldBossRankWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetWorldBossRank(Index,tmpWorldBossRankWraper);
		}
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
