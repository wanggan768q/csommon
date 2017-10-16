/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     FriendDBCache.cpp
* Author:       甘业清
* Description:  好友数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "FriendDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataFriend);

//好友实现类构造函数
DataFriend::DataFriend()
{
	m_mapDataWraperVersionName[1] = "FriendFriendDataWraperV1";
	
}

//好友实现类析构函数
DataFriend::~DataFriend()
{

}


//获取模块ID
UINT8 DataFriend::GetModuleId()
{
	return MODULE_ID_FRIEND;
}

//获取模块名字
TStr DataFriend::GetModuleName()
{
	return "Friend";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataFriend::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataFriend::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataFriend::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataFriend::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataFriend::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	FriendFriendDataWraperV1* pDataWraper = (FriendFriendDataWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_FRIEND_FRIENDLIST:
		if( Index<0 )
		{
			pDataWraper->ClearFriendList();
			break;
		}
		if (Index >= pDataWraper->SizeFriendList())
		{
			int Count = Index -pDataWraper->SizeFriendList() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddFriendList(FriendFriendObjWraperV1());
		}
		{
			FriendFriendObjWraperV1 tmpFriendListWraper;
			tmpFriendListWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetFriendList(Index,tmpFriendListWraper);
		}
		break;
	case SYNCID_FRIEND_BLACKLIST:
		if( Index<0 )
		{
			pDataWraper->ClearBlackList();
			break;
		}
		if (Index >= pDataWraper->SizeBlackList())
		{
			int Count = Index -pDataWraper->SizeBlackList() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddBlackList(FriendFriendObjWraperV1());
		}
		{
			FriendFriendObjWraperV1 tmpBlackListWraper;
			tmpBlackListWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetBlackList(Index,tmpBlackListWraper);
		}
		break;
	case SYNCID_FRIEND_CONTACTSLIST:
		if( Index<0 )
		{
			pDataWraper->ClearContactsList();
			break;
		}
		if (Index >= pDataWraper->SizeContactsList())
		{
			int Count = Index -pDataWraper->SizeContactsList() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddContactsList(FriendFriendObjWraperV1());
		}
		{
			FriendFriendObjWraperV1 tmpContactsListWraper;
			tmpContactsListWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetContactsList(Index,tmpContactsListWraper);
		}
		break;
	case SYNCID_FRIEND_STRANGERFRIENDLIST:
		if( Index<0 )
		{
			pDataWraper->ClearStrangerFriendList();
			break;
		}
		if (Index >= pDataWraper->SizeStrangerFriendList())
		{
			int Count = Index -pDataWraper->SizeStrangerFriendList() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddStrangerFriendList(-1);
		}
		ReadVarint64FromArray(pBuffer,&lValue);
		pDataWraper->SetStrangerFriendList(Index,lValue);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
