/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     TaskDBCache.cpp
* Author:       甘业清
* Description:  任务数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "TaskDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataTask);

//任务实现类构造函数
DataTask::DataTask()
{
	m_mapDataWraperVersionName[1] = "TaskTaskDataWraperV1";
	
}

//任务实现类析构函数
DataTask::~DataTask()
{

}


//获取模块ID
UINT8 DataTask::GetModuleId()
{
	return MODULE_ID_TASK;
}

//获取模块名字
TStr DataTask::GetModuleName()
{
	return "Task";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataTask::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataTask::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataTask::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataTask::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataTask::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	TaskTaskDataWraperV1* pDataWraper = (TaskTaskDataWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_TASK_ALLTASKARRAY:
		if( Index<0 )
		{
			pDataWraper->ClearAllTaskArray();
			break;
		}
		if (Index >= pDataWraper->SizeAllTaskArray())
		{
			int Count = Index -pDataWraper->SizeAllTaskArray() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddAllTaskArray(TaskTaskObjWraperV1());
		}
		{
			TaskTaskObjWraperV1 tmpAllTaskArrayWraper;
			tmpAllTaskArrayWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetAllTaskArray(Index,tmpAllTaskArrayWraper);
		}
		break;
	case SYNCID_TASK_UNACCEPTEDTASKARRAY:
		if( Index<0 )
		{
			pDataWraper->ClearUnacceptedTaskArray();
			break;
		}
		if (Index >= pDataWraper->SizeUnacceptedTaskArray())
		{
			int Count = Index -pDataWraper->SizeUnacceptedTaskArray() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddUnacceptedTaskArray(TaskUnacceptedTaskObjWraperV1());
		}
		{
			TaskUnacceptedTaskObjWraperV1 tmpUnacceptedTaskArrayWraper;
			tmpUnacceptedTaskArrayWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetUnacceptedTaskArray(Index,tmpUnacceptedTaskArrayWraper);
		}
		break;
	case SYNCID_TASK_PROFTASKID:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetProfTaskId(iValue);
		break;
	case SYNCID_TASK_PROFTASKCOMPCOUNT:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetProfTaskCompCount(iValue);
		break;
	case SYNCID_TASK_ONEDRAGONTASKID:
		if( Index<0 )
		{
			pDataWraper->ClearOneDragonTaskId();
			break;
		}
		if (Index >= pDataWraper->SizeOneDragonTaskId())
		{
			int Count = Index -pDataWraper->SizeOneDragonTaskId() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddOneDragonTaskId(-1);
		}
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetOneDragonTaskId(Index,iValue);
		break;
	case SYNCID_TASK_ONEDRAGONRINGNUM:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetOneDragonRingNum(iValue);
		break;
	case SYNCID_TASK_ONEDRAGONCOMPLATECOUNT:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetOneDragonComplateCount(iValue);
		break;
	case SYNCID_TASK_ONEDRAGONDUNGEONID:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetOneDragonDungeonId(iValue);
		break;
	case SYNCID_TASK_GUILDSPYCOMPLATECOUNT:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetGuildSpyComplateCount(iValue);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
