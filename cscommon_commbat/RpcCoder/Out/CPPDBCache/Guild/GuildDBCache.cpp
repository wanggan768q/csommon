/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     GuildDBCache.cpp
* Author:       甘业清
* Description:  帮派数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "GuildDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataGuild);

//帮派实现类构造函数
DataGuild::DataGuild()
{
	m_mapDataWraperVersionName[1] = "GuildGuildListWraperV1";
	
}

//帮派实现类析构函数
DataGuild::~DataGuild()
{

}


//获取模块ID
UINT8 DataGuild::GetModuleId()
{
	return MODULE_ID_GUILD;
}

//获取模块名字
TStr DataGuild::GetModuleName()
{
	return "Guild";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataGuild::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataGuild::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataGuild::GetSavedDataType()
{
	return SAVE_CACHE_DATA;
}

//是否保存数据到数据库中
bool DataGuild::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataGuild::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	GuildGuildListWraperV1* pDataWraper = (GuildGuildListWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_GUILD_GUILDDATA:
		{
			GuildInfoObjWraper tmpGuildDataWraper;
			tmpGuildDataWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetGuildData(tmpGuildDataWraper);
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
