/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     OnlineDataDBCache.cpp
* Author:       甘业清
* Description:  在线数据数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "OnlineDataDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataOnlineData);

//在线数据实现类构造函数
DataOnlineData::DataOnlineData()
{
	m_mapDataWraperVersionName[1] = "OnlineDataOnlineDataWraperV1";
	
}

//在线数据实现类析构函数
DataOnlineData::~DataOnlineData()
{

}


//获取模块ID
UINT8 DataOnlineData::GetModuleId()
{
	return MODULE_ID_ONLINEDATA;
}

//获取模块名字
TStr DataOnlineData::GetModuleName()
{
	return "OnlineData";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataOnlineData::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataOnlineData::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataOnlineData::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataOnlineData::IsSaveModuleDataToDB()
{

	return false;
}

//增量更新通知
bool DataOnlineData::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	OnlineDataOnlineDataWraperV1* pDataWraper = (OnlineDataOnlineDataWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_ONLINEDATA_BAGRECYCLEBIN:
		if( Index<0 )
		{
			pDataWraper->ClearBagRecycleBin();
			break;
		}
		if (Index >= pDataWraper->SizeBagRecycleBin())
		{
			int Count = Index -pDataWraper->SizeBagRecycleBin() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddBagRecycleBin(BagRecycleGridObjWraper());
		}
		{
			BagRecycleGridObjWraper tmpBagRecycleBinWraper;
			tmpBagRecycleBinWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetBagRecycleBin(Index,tmpBagRecycleBinWraper);
		}
		break;
	case SYNCID_ONLINEDATA_ROLEATTR:
		if( Index<0 )
		{
			pDataWraper->ClearRoleAttr();
			break;
		}
		if (Index >= pDataWraper->SizeRoleAttr())
		{
			int Count = Index -pDataWraper->SizeRoleAttr() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddRoleAttr(OnlineDataRoleAttrObjWraperV1());
		}
		{
			OnlineDataRoleAttrObjWraperV1 tmpRoleAttrWraper;
			tmpRoleAttrWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetRoleAttr(Index,tmpRoleAttrWraper);
		}
		break;
	case SYNCID_ONLINEDATA_RECOMMENDFRIENDOFFSET:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetRecommendFriendOffset(iValue);
		break;
	case SYNCID_ONLINEDATA_RECOMMENDFRIENDFLUSHTIME:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetRecommendFriendFlushTime(iValue);
		break;
	case SYNCID_ONLINEDATA_RECOMMENDFRIENDLASTLIST:
		if( Index<0 )
		{
			pDataWraper->ClearRecommendFriendLastList();
			break;
		}
		if (Index >= pDataWraper->SizeRecommendFriendLastList())
		{
			int Count = Index -pDataWraper->SizeRecommendFriendLastList() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddRecommendFriendLastList(-1);
		}
		ReadVarint64FromArray(pBuffer,&lValue);
		pDataWraper->SetRecommendFriendLastList(Index,lValue);
		break;
	case SYNCID_ONLINEDATA_FOLLOWMEUSERID:
		if( Index<0 )
		{
			pDataWraper->ClearFollowmeUserId();
			break;
		}
		if (Index >= pDataWraper->SizeFollowmeUserId())
		{
			int Count = Index -pDataWraper->SizeFollowmeUserId() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddFollowmeUserId(-1);
		}
		ReadVarint64FromArray(pBuffer,&lValue);
		pDataWraper->SetFollowmeUserId(Index,lValue);
		break;
	case SYNCID_ONLINEDATA_FOLLOWWHO:
		ReadVarint64FromArray(pBuffer,&lValue);
		pDataWraper->SetFollowWho(lValue);
		break;
	case SYNCID_ONLINEDATA_THIEFOBJID:
		ReadVarint64FromArray(pBuffer,&lValue);
		pDataWraper->SetThiefObjId(lValue);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
