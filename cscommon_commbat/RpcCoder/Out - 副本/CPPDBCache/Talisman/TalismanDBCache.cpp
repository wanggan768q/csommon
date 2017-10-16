/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     TalismanDBCache.cpp
* Author:       甘业清
* Description:  法宝数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "TalismanDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataTalisman);

//法宝实现类构造函数
DataTalisman::DataTalisman()
{
	m_mapDataWraperVersionName[1] = "TalismanDataFabaoWraperV1";
	
}

//法宝实现类析构函数
DataTalisman::~DataTalisman()
{

}


//获取模块ID
UINT8 DataTalisman::GetModuleId()
{
	return MODULE_ID_TALISMAN;
}

//获取模块名字
TStr DataTalisman::GetModuleName()
{
	return "Talisman";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataTalisman::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataTalisman::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataTalisman::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataTalisman::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataTalisman::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	TalismanDataFabaoWraperV1* pDataWraper = (TalismanDataFabaoWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_TALISMAN_FABAOARR:
		if( Index<0 )
		{
			pDataWraper->ClearFabaoArr();
			break;
		}
		if (Index >= pDataWraper->SizeFabaoArr())
		{
			int Count = Index -pDataWraper->SizeFabaoArr() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddFabaoArr(TalismanFabaoInfoWraperV1());
		}
		{
			TalismanFabaoInfoWraperV1 tmpFabaoArrWraper;
			tmpFabaoArrWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetFabaoArr(Index,tmpFabaoArrWraper);
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
