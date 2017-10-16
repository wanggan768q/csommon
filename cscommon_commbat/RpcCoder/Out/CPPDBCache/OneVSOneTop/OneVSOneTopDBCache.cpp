/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     OneVSOneTopDBCache.cpp
* Author:       甘业清
* Description:  排行榜数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "OneVSOneTopDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataOneVSOneTop);

//排行榜实现类构造函数
DataOneVSOneTop::DataOneVSOneTop()
{
	m_mapDataWraperVersionName[1] = "OneVSOneTopOneVSOneDateWraperV1";
	
}

//排行榜实现类析构函数
DataOneVSOneTop::~DataOneVSOneTop()
{

}


//获取模块ID
UINT8 DataOneVSOneTop::GetModuleId()
{
	return MODULE_ID_ONEVSONETOP;
}

//获取模块名字
TStr DataOneVSOneTop::GetModuleName()
{
	return "OneVSOneTop";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataOneVSOneTop::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataOneVSOneTop::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataOneVSOneTop::GetSavedDataType()
{
	return SAVE_MODULE_DATA;
}

//是否保存数据到数据库中
bool DataOneVSOneTop::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataOneVSOneTop::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	OneVSOneTopOneVSOneDateWraperV1* pDataWraper = (OneVSOneTopOneVSOneDateWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_ONEVSONETOP_TOPMESSES:
		if( Index<0 )
		{
			pDataWraper->ClearTopMesses();
			break;
		}
		if (Index >= pDataWraper->SizeTopMesses())
		{
			int Count = Index -pDataWraper->SizeTopMesses() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddTopMesses(TopMessWraper());
		}
		{
			TopMessWraper tmpTopMessesWraper;
			tmpTopMessesWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetTopMesses(Index,tmpTopMessesWraper);
		}
		break;
	case SYNCID_ONEVSONETOP_TIME:
		ReadVarint64FromArray(pBuffer,&lValue);
		pDataWraper->SetTime(lValue);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
