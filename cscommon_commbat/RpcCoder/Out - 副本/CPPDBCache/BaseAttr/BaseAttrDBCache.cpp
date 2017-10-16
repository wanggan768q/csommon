/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     BaseAttrDBCache.cpp
* Author:       甘业清
* Description:  战队基础数据数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "BaseAttrDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataBaseAttr);

//战队基础数据实现类构造函数
DataBaseAttr::DataBaseAttr()
{
	m_mapDataWraperVersionName[1] = "BaseAttrUserDataWraperV1";
	
}

//战队基础数据实现类析构函数
DataBaseAttr::~DataBaseAttr()
{

}


//获取模块ID
UINT8 DataBaseAttr::GetModuleId()
{
	return MODULE_ID_BASEATTR;
}

//获取模块名字
TStr DataBaseAttr::GetModuleName()
{
	return "BaseAttr";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataBaseAttr::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataBaseAttr::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataBaseAttr::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataBaseAttr::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataBaseAttr::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	BaseAttrUserDataWraperV1* pDataWraper = (BaseAttrUserDataWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_BASEATTR_HEADID:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetHeadID(iValue);
		break;
	case SYNCID_BASEATTR_EXP:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetExp(iValue);
		break;
	case SYNCID_BASEATTR_CREATETIME:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetCreateTime(iValue);
		break;
	case SYNCID_BASEATTR_LASTLOGINTIME:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetLastLoginTime(iValue);
		break;
	case SYNCID_BASEATTR_LAST2LOGINDATE:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetLast2LoginDate(iValue);
		break;
	case SYNCID_BASEATTR_LASTLOGOUTTIME:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetLastLogoutTime(iValue);
		break;
	case SYNCID_BASEATTR_MONEY:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetMoney(iValue);
		break;
	case SYNCID_BASEATTR_DIAMOND:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetDiamond(iValue);
		break;
	case SYNCID_BASEATTR_STRENGTH:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetStrength(iValue);
		break;
	case SYNCID_BASEATTR_FEATS:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetFeats(iValue);
		break;
	case SYNCID_BASEATTR_GOTRANKREWARDTIME:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetGotRankRewardTime(iValue);
		break;
	case SYNCID_BASEATTR_MAXMILITARY:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetMaxMilitary(iValue);
		break;
	case SYNCID_BASEATTR_MASTERATTRS:
		if( Index<0 )
		{
			pDataWraper->ClearMasterAttrs();
			break;
		}
		if (Index >= pDataWraper->SizeMasterAttrs())
		{
			int Count = Index -pDataWraper->SizeMasterAttrs() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddMasterAttrs(-1);
		}
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetMasterAttrs(Index,iValue);
		break;
	case SYNCID_BASEATTR_CURMILITARY:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetCurMilitary(iValue);
		break;
	case SYNCID_BASEATTR_USERNAME:
		pDataWraper->SetUserName(string(pBuffer,dataLen));
		break;
	case SYNCID_BASEATTR_USERID:
		ReadVarint64FromArray(pBuffer,&lValue);
		pDataWraper->SetUserId(lValue);
		break;
	case SYNCID_BASEATTR_PLATNAME:
		pDataWraper->SetPlatName(string(pBuffer,dataLen));
		break;
	case SYNCID_BASEATTR_ACCOUNTID:
		ReadVarint64FromArray(pBuffer,&lValue);
		pDataWraper->SetAccountId(lValue);
		break;
	case SYNCID_BASEATTR_LEVEL:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetLevel(iValue);
		break;
	case SYNCID_BASEATTR_RANK:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetRank(iValue);
		break;
	case SYNCID_BASEATTR_FIGHTPOWER:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetFightPower(iValue);
		break;
	case SYNCID_BASEATTR_SEC:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetSec(iValue);
		break;
	case SYNCID_BASEATTR_MILITARY:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetMilitary(iValue);
		break;
	case SYNCID_BASEATTR_TEAMID:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetTeamId(iValue);
		break;
	case SYNCID_BASEATTR_PROF:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetProf(iValue);
		break;
	case SYNCID_BASEATTR_DUNGEONREMAINCOUNT:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetDungeonRemainCount(iValue);
		break;
	case SYNCID_BASEATTR_MAPID:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetMapId(iValue);
		break;
	case SYNCID_BASEATTR_POSX:
		pDataWraper->SetPosX(*(float*)pBuffer);
		break;
	case SYNCID_BASEATTR_POSY:
		pDataWraper->SetPosY(*(float*)pBuffer);
		break;
	case SYNCID_BASEATTR_POSZ:
		pDataWraper->SetPosZ(*(float*)pBuffer);
		break;
	case SYNCID_BASEATTR_RY:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetRy(iValue);
		break;
	case SYNCID_BASEATTR_SKILLCDARR:
		if( Index<0 )
		{
			pDataWraper->ClearSkillCdArr();
			break;
		}
		if (Index >= pDataWraper->SizeSkillCdArr())
		{
			int Count = Index -pDataWraper->SizeSkillCdArr() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddSkillCdArr(BaseAttrSkillCdInfoWraperV1());
		}
		{
			BaseAttrSkillCdInfoWraperV1 tmpSkillCdArrWraper;
			tmpSkillCdArrWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetSkillCdArr(Index,tmpSkillCdArrWraper);
		}
		break;
	case SYNCID_BASEATTR_BUFFCDARR:
		if( Index<0 )
		{
			pDataWraper->ClearBuffCdArr();
			break;
		}
		if (Index >= pDataWraper->SizeBuffCdArr())
		{
			int Count = Index -pDataWraper->SizeBuffCdArr() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddBuffCdArr(BaseAttrBuffCdInfoWraperV1());
		}
		{
			BaseAttrBuffCdInfoWraperV1 tmpBuffCdArrWraper;
			tmpBuffCdArrWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetBuffCdArr(Index,tmpBuffCdArrWraper);
		}
		break;
	case SYNCID_BASEATTR_CURRENTSCENE:
		{
			BaseAttrSceneInfoWraperV1 tmpCurrentSceneWraper;
			tmpCurrentSceneWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetCurrentScene(tmpCurrentSceneWraper);
		}
		break;
	case SYNCID_BASEATTR_GUILDID:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetGuildId(iValue);
		break;
	case SYNCID_BASEATTR_EXITGUILDTIME:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetExitGuildTime(iValue);
		break;
	case SYNCID_BASEATTR_APPLYGUILDID:
		if( Index<0 )
		{
			pDataWraper->ClearApplyGuildId();
			break;
		}
		if (Index >= pDataWraper->SizeApplyGuildId())
		{
			int Count = Index -pDataWraper->SizeApplyGuildId() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddApplyGuildId(-1);
		}
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetApplyGuildId(Index,iValue);
		break;
	case SYNCID_BASEATTR_CURGUILDCONTRIBUTION:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetCurGuildContribution(iValue);
		break;
	case SYNCID_BASEATTR_MAXGUILDCONTRIBUTION:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetMaxGuildContribution(iValue);
		break;
	case SYNCID_BASEATTR_BINDMONEY:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetBindMoney(iValue);
		break;
	case SYNCID_BASEATTR_GEM:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetGem(iValue);
		break;
	case SYNCID_BASEATTR_SERVERTIME:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetServerTime(iValue);
		break;
	case SYNCID_BASEATTR_NEWBIEGUIDE:
		if( Index<0 )
		{
			pDataWraper->ClearNewbieGuide();
			break;
		}
		if (Index >= pDataWraper->SizeNewbieGuide())
		{
			int Count = Index -pDataWraper->SizeNewbieGuide() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddNewbieGuide(KeyValue2IntIntWraper());
		}
		{
			KeyValue2IntIntWraper tmpNewbieGuideWraper;
			tmpNewbieGuideWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetNewbieGuide(Index,tmpNewbieGuideWraper);
		}
		break;
	case SYNCID_BASEATTR_THIEFREWARDNUM:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetThiefRewardNum(iValue);
		break;
	case SYNCID_BASEATTR_SUBDUEMONSTERREWARDNUM:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetSubdueMonsterRewardNum(iValue);
		break;
	case SYNCID_BASEATTR_WORLDBOSSREMAINTIMES:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetWorldBossRemainTimes(iValue);
		break;
	case SYNCID_BASEATTR_WORLDBOSSHURT:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetWorldBossHurt(iValue);
		break;
	case SYNCID_BASEATTR_FUNCTIONOPENLIST:
		if( Index<0 )
		{
			pDataWraper->ClearFunctionOpenList();
			break;
		}
		if (Index >= pDataWraper->SizeFunctionOpenList())
		{
			int Count = Index -pDataWraper->SizeFunctionOpenList() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddFunctionOpenList(BaseAttrIconOpenInfoWraperV1());
		}
		{
			BaseAttrIconOpenInfoWraperV1 tmpFunctionOpenListWraper;
			tmpFunctionOpenListWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetFunctionOpenList(Index,tmpFunctionOpenListWraper);
		}
		break;
	case SYNCID_BASEATTR_TOTALENERGYVALUE:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetTotalEnergyValue(iValue);
		break;
	case SYNCID_BASEATTR_ENERGYARRAY:
		if( Index<0 )
		{
			pDataWraper->ClearEnergyArray();
			break;
		}
		if (Index >= pDataWraper->SizeEnergyArray())
		{
			int Count = Index -pDataWraper->SizeEnergyArray() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddEnergyArray(BaseAttrEnergyInfoWraperV1());
		}
		{
			BaseAttrEnergyInfoWraperV1 tmpEnergyArrayWraper;
			tmpEnergyArrayWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetEnergyArray(Index,tmpEnergyArrayWraper);
		}
		break;
	case SYNCID_BASEATTR_PKSTATE:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetPKState(iValue);
		break;
	case SYNCID_BASEATTR_PKPROTECT:
		if( Index<0 )
		{
			pDataWraper->ClearPKProtect();
			break;
		}
		if (Index >= pDataWraper->SizePKProtect())
		{
			int Count = Index -pDataWraper->SizePKProtect() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddPKProtect(KeyValue2IntBoolWraper());
		}
		{
			KeyValue2IntBoolWraper tmpPKProtectWraper;
			tmpPKProtectWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetPKProtect(Index,tmpPKProtectWraper);
		}
		break;
	case SYNCID_BASEATTR_GUILDSCIENARRAY:
		if( Index<0 )
		{
			pDataWraper->ClearGuildScienArray();
			break;
		}
		if (Index >= pDataWraper->SizeGuildScienArray())
		{
			int Count = Index -pDataWraper->SizeGuildScienArray() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddGuildScienArray(BaseAttrScienceInfoWraperV1());
		}
		{
			BaseAttrScienceInfoWraperV1 tmpGuildScienArrayWraper;
			tmpGuildScienArrayWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetGuildScienArray(Index,tmpGuildScienArrayWraper);
		}
		break;
	case SYNCID_BASEATTR_SCIENCETOTALMONEY:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetScienceTotalMoney(iValue);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
