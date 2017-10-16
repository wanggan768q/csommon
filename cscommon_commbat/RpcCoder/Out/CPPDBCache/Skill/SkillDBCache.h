/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SkillDBCache.h
* Author:       甘业清
* Description:  技能数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __DATA_SKILL_H
#define __DATA_SKILL_H


#include "ModuleData.h"
#include "SkillV1DataWraper.h"


//同步数据相关枚举量定义
enum DataWraperItemIdE
{
	MODULE_ID_SKILL = 29,
 	SYNCID_SKILL_SKILLARRAY                     = 2901,  //全部技能
 	SYNCID_SKILL_SHORTCUTARRAY                  = 2902,  //快捷栏
 	SYNCID_SKILL_SHORTCUTID                     = 2903,  //方案Id，从0开始
 	SYNCID_SKILL_TALENTSKILL                    = 2904,  //天赋技能
 	SYNCID_SKILL_TOTALCOSTEXP                   = 2905,  //累计技能消耗经验
 	SYNCID_SKILL_TALENTLEVEL                    = 2906,  //修为等级
 	SYNCID_SKILL_TALENTPOINT                    = 2907,  //天赋点
 	SYNCID_SKILL_LIFESKILLARRAY                 = 2908,  //生活技能

};


//技能数据类
class DataSkill : public ModuleData
{
	DECLARE_INSTANCE(DataSkill);
public:
	friend class			ModuleDataMgr;

public:
	//技能实现类构造函数
	DataSkill();
	
	//技能实现类析构函数
	virtual					~DataSkill();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//获取模块同步(保存)数据版本及类名
	virtual map<INT32,TStr>	GetDataWraperVersionName();
	
	//模块数据保存类型
	virtual SavedDataTypeE	GetSavedDataType();

	//是否保存数据到数据库中
	virtual bool			IsSaveModuleDataToDB();

	//模块同步(保存)数据升级函数
	virtual bool			UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur );
	
	//增量更新通知
	virtual bool			OnIncrementUpdate( INT64 key, int syncId, int IndexPos, const char* pBuffer, int dataLen );


private:
	 map<INT32,TStr>		m_mapDataWraperVersionName;
};

#endif