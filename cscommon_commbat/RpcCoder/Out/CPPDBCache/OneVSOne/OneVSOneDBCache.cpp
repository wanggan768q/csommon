/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     OneVSOneDBCache.cpp
* Author:       甘业清
* Description:  一v一数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "OneVSOneDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataOneVSOne);

//一v一实现类构造函数
DataOneVSOne::DataOneVSOne()
{
	m_mapDataWraperVersionName[1] = "OneVSOneOneVSOneDateWraperV1";
	
}

//一v一实现类析构函数
DataOneVSOne::~DataOneVSOne()
{

}


//获取模块ID
UINT8 DataOneVSOne::GetModuleId()
{
	return MODULE_ID_ONEVSONE;
}

//获取模块名字
TStr DataOneVSOne::GetModuleName()
{
	return "OneVSOne";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataOneVSOne::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataOneVSOne::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataOneVSOne::GetSavedDataType()
{
	return SAVE_MODULE_DATA;
}

//是否保存数据到数据库中
bool DataOneVSOne::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataOneVSOne::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	OneVSOneOneVSOneDateWraperV1* pDataWraper = (OneVSOneOneVSOneDateWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_ONEVSONE_SKILLDATE:
		if( Index<0 )
		{
			pDataWraper->ClearSkillDate();
			break;
		}
		if (Index >= pDataWraper->SizeSkillDate())
		{
			int Count = Index -pDataWraper->SizeSkillDate() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddSkillDate(OneSDataWraper());
		}
		{
			OneSDataWraper tmpSkillDateWraper;
			tmpSkillDateWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetSkillDate(Index,tmpSkillDateWraper);
		}
		break;
	case SYNCID_ONEVSONE_LOG:
		if( Index<0 )
		{
			pDataWraper->ClearLog();
			break;
		}
		if (Index >= pDataWraper->SizeLog())
		{
			int Count = Index -pDataWraper->SizeLog() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddLog(ActMessageWraper());
		}
		{
			ActMessageWraper tmpLogWraper;
			tmpLogWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetLog(Index,tmpLogWraper);
		}
		break;
	case SYNCID_ONEVSONE_ONEVSONENUM:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetOneVSOneNum(iValue);
		break;
	case SYNCID_ONEVSONE_SAVETIME:
		ReadVarint64FromArray(pBuffer,&lValue);
		pDataWraper->SetSaveTime(lValue);
		break;
	case SYNCID_ONEVSONE_RANKING:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetRanking(iValue);
		break;
	case SYNCID_ONEVSONE_RANKINGTIMES:
		if( Index<0 )
		{
			pDataWraper->ClearRankingTimes();
			break;
		}
		if (Index >= pDataWraper->SizeRankingTimes())
		{
			int Count = Index -pDataWraper->SizeRankingTimes() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddRankingTimes(TimeTopWraper());
		}
		{
			TimeTopWraper tmpRankingTimesWraper;
			tmpRankingTimesWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetRankingTimes(Index,tmpRankingTimesWraper);
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
