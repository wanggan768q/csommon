/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     TeamDBCache.cpp
* Author:       甘业清
* Description:  组队数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "TeamDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataTeam);

//组队实现类构造函数
DataTeam::DataTeam()
{
	m_mapDataWraperVersionName[1] = "TeamTeamDataWraperV1";
	
}

//组队实现类析构函数
DataTeam::~DataTeam()
{

}


//获取模块ID
UINT8 DataTeam::GetModuleId()
{
	return MODULE_ID_TEAM;
}

//获取模块名字
TStr DataTeam::GetModuleName()
{
	return "Team";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataTeam::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataTeam::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataTeam::GetSavedDataType()
{
	return SAVE_CACHE_DATA;
}

//是否保存数据到数据库中
bool DataTeam::IsSaveModuleDataToDB()
{

	return false;
}

//增量更新通知
bool DataTeam::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	TeamTeamDataWraperV1* pDataWraper = (TeamTeamDataWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_TEAM_TEAMDATA:
		{
			TeamObjWraper tmpTeamDataWraper;
			tmpTeamDataWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetTeamData(tmpTeamDataWraper);
		}
		break;
	case SYNCID_TEAM_APPLYLIST:
		if( Index<0 )
		{
			pDataWraper->ClearApplyList();
			break;
		}
		if (Index >= pDataWraper->SizeApplyList())
		{
			int Count = Index -pDataWraper->SizeApplyList() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddApplyList(TeamApplyUserObjWraper());
		}
		{
			TeamApplyUserObjWraper tmpApplyListWraper;
			tmpApplyListWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetApplyList(Index,tmpApplyListWraper);
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
