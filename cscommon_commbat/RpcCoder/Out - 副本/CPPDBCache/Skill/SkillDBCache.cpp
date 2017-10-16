/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SkillDBCache.cpp
* Author:       甘业清
* Description:  技能数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "SkillDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataSkill);

//技能实现类构造函数
DataSkill::DataSkill()
{
	m_mapDataWraperVersionName[1] = "SkillSkillDataWraperV1";
	
}

//技能实现类析构函数
DataSkill::~DataSkill()
{

}


//获取模块ID
UINT8 DataSkill::GetModuleId()
{
	return MODULE_ID_SKILL;
}

//获取模块名字
TStr DataSkill::GetModuleName()
{
	return "Skill";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataSkill::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataSkill::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataSkill::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataSkill::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataSkill::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	SkillSkillDataWraperV1* pDataWraper = (SkillSkillDataWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_SKILL_SKILLARRAY:
		if( Index<0 )
		{
			pDataWraper->ClearSkillArray();
			break;
		}
		if (Index >= pDataWraper->SizeSkillArray())
		{
			int Count = Index -pDataWraper->SizeSkillArray() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddSkillArray(SkillSkillObjWraperV1());
		}
		{
			SkillSkillObjWraperV1 tmpSkillArrayWraper;
			tmpSkillArrayWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetSkillArray(Index,tmpSkillArrayWraper);
		}
		break;
	case SYNCID_SKILL_SHORTCUTARRAY:
		if( Index<0 )
		{
			pDataWraper->ClearShortcutArray();
			break;
		}
		if (Index >= pDataWraper->SizeShortcutArray())
		{
			int Count = Index -pDataWraper->SizeShortcutArray() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddShortcutArray(SkillShortcutObjWraperV1());
		}
		{
			SkillShortcutObjWraperV1 tmpShortcutArrayWraper;
			tmpShortcutArrayWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetShortcutArray(Index,tmpShortcutArrayWraper);
		}
		break;
	case SYNCID_SKILL_SHORTCUTID:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetShortcutId(iValue);
		break;
	case SYNCID_SKILL_TALENTSKILL:
		if( Index<0 )
		{
			pDataWraper->ClearTalentSkill();
			break;
		}
		if (Index >= pDataWraper->SizeTalentSkill())
		{
			int Count = Index -pDataWraper->SizeTalentSkill() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddTalentSkill(SkillTalentSlotWraperV1());
		}
		{
			SkillTalentSlotWraperV1 tmpTalentSkillWraper;
			tmpTalentSkillWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetTalentSkill(Index,tmpTalentSkillWraper);
		}
		break;
	case SYNCID_SKILL_TOTALCOSTEXP:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetTotalCostExp(iValue);
		break;
	case SYNCID_SKILL_TALENTLEVEL:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetTalentLevel(iValue);
		break;
	case SYNCID_SKILL_TALENTPOINT:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetTalentPoint(iValue);
		break;
	case SYNCID_SKILL_LIFESKILLARRAY:
		if( Index<0 )
		{
			pDataWraper->ClearLifeSkillArray();
			break;
		}
		if (Index >= pDataWraper->SizeLifeSkillArray())
		{
			int Count = Index -pDataWraper->SizeLifeSkillArray() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddLifeSkillArray(SkillSkillObjWraperV1());
		}
		{
			SkillSkillObjWraperV1 tmpLifeSkillArrayWraper;
			tmpLifeSkillArrayWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetLifeSkillArray(Index,tmpLifeSkillArrayWraper);
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
