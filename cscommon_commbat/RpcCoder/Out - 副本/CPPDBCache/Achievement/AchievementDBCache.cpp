/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     AchievementDBCache.cpp
* Author:       甘业清
* Description:  成就数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "AchievementDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataAchievement);

//成就实现类构造函数
DataAchievement::DataAchievement()
{
	m_mapDataWraperVersionName[1] = "AchievementAchiDataWraperV1";
	
}

//成就实现类析构函数
DataAchievement::~DataAchievement()
{

}


//获取模块ID
UINT8 DataAchievement::GetModuleId()
{
	return MODULE_ID_ACHIEVEMENT;
}

//获取模块名字
TStr DataAchievement::GetModuleName()
{
	return "Achievement";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataAchievement::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataAchievement::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataAchievement::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataAchievement::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataAchievement::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	AchievementAchiDataWraperV1* pDataWraper = (AchievementAchiDataWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_ACHIEVEMENT_ACHIDATA:
		if( Index<0 )
		{
			pDataWraper->ClearAchiData();
			break;
		}
		if (Index >= pDataWraper->SizeAchiData())
		{
			int Count = Index -pDataWraper->SizeAchiData() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddAchiData(AchievementAchiObjWraperV1());
		}
		{
			AchievementAchiObjWraperV1 tmpAchiDataWraper;
			tmpAchiDataWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetAchiData(Index,tmpAchiDataWraper);
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
