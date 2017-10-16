/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     TransportDBCache.cpp
* Author:       甘业清
* Description:  货运数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "TransportDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataTransport);

//货运实现类构造函数
DataTransport::DataTransport()
{
	m_mapDataWraperVersionName[1] = "TransportGoodsDataWraperV1";
	
}

//货运实现类析构函数
DataTransport::~DataTransport()
{

}


//获取模块ID
UINT8 DataTransport::GetModuleId()
{
	return MODULE_ID_TRANSPORT;
}

//获取模块名字
TStr DataTransport::GetModuleName()
{
	return "Transport";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataTransport::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataTransport::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataTransport::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataTransport::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataTransport::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	TransportGoodsDataWraperV1* pDataWraper = (TransportGoodsDataWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_TRANSPORT_GOODSARRAY:
		if( Index<0 )
		{
			pDataWraper->ClearGoodsArray();
			break;
		}
		if (Index >= pDataWraper->SizeGoodsArray())
		{
			int Count = Index -pDataWraper->SizeGoodsArray() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddGoodsArray(TransportGoodsObjWraperV1());
		}
		{
			TransportGoodsObjWraperV1 tmpGoodsArrayWraper;
			tmpGoodsArrayWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetGoodsArray(Index,tmpGoodsArrayWraper);
		}
		break;
	case SYNCID_TRANSPORT_ASKNUM:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetAskNum(iValue);
		break;
	case SYNCID_TRANSPORT_HELPNUM:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetHelpNum(iValue);
		break;
	case SYNCID_TRANSPORT_REWARDARRY:
		if( Index<0 )
		{
			pDataWraper->ClearRewardArry();
			break;
		}
		if (Index >= pDataWraper->SizeRewardArry())
		{
			int Count = Index -pDataWraper->SizeRewardArry() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddRewardArry(TransportRewardObjWraperV1());
		}
		{
			TransportRewardObjWraperV1 tmpRewardArryWraper;
			tmpRewardArryWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetRewardArry(Index,tmpRewardArryWraper);
		}
		break;
	case SYNCID_TRANSPORT_REWARDFLAG:
		pDataWraper->SetRewardFlag(*(bool*)pBuffer);
		break;
	case SYNCID_TRANSPORT_PICKTASKFLAG:
		pDataWraper->SetPickTaskFlag(*(bool*)pBuffer);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
