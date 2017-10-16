#ifndef __SYNC_DATA_SKILL_V1_H
#define __SYNC_DATA_SKILL_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "SkillV1DataWraper.h"


//同步数据相关枚举量定义
enum SkillSyncDataItemIdE
{
 	SYNCID_SKILL_SKILLARRAY                     = 2901,  //全部技能
 	SYNCID_SKILL_SHORTCUTARRAY                  = 2902,  //快捷栏
 	SYNCID_SKILL_SHORTCUTID                     = 2903,  //方案Id，从0开始
 	SYNCID_SKILL_TALENTSKILL                    = 2904,  //天赋技能
 	SYNCID_SKILL_TOTALCOSTEXP                   = 2905,  //累计技能消耗经验
 	SYNCID_SKILL_TALENTLEVEL                    = 2906,  //修为等级
 	SYNCID_SKILL_TALENTPOINT                    = 2907,  //天赋点
 	SYNCID_SKILL_LIFESKILLARRAY                 = 2908,  //生活技能

};


//主同步数据操作类
class SyncDataSkillV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataSkillV1>
{
public:
			SyncDataSkillV1();
	virtual	~SyncDataSkillV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataSkillData.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataSkillData.HtmlDescHeader(); }
public:
	//全部技能
	void SetSkillArray( const vector<SkillSkillObjWraperV1>& v );
	void SetSkillArray( int Index, const SkillSkillObjWraperV1& v );
	vector<SkillSkillObjWraperV1> GetSkillArray();
	SkillSkillObjWraperV1 GetSkillArray( int Index );
	void AddSkillArray( const SkillSkillObjWraperV1& v);
	void SendSkillArray( int Index,bool OnlyToClient=true );
	void SendSkillArray(bool OnlyToClient=true);
	int  SizeSkillArray(){ return m_syncDataSkillData.SizeSkillArray(); }
public:
	//快捷栏
	void SetShortcutArray( const vector<SkillShortcutObjWraperV1>& v );
	void SetShortcutArray( int Index, const SkillShortcutObjWraperV1& v );
	vector<SkillShortcutObjWraperV1> GetShortcutArray();
	SkillShortcutObjWraperV1 GetShortcutArray( int Index );
	void AddShortcutArray( const SkillShortcutObjWraperV1& v);
	void SendShortcutArray( int Index,bool OnlyToClient=true );
	void SendShortcutArray(bool OnlyToClient=true);
	int  SizeShortcutArray(){ return m_syncDataSkillData.SizeShortcutArray(); }
public:
	//方案Id，从0开始
	void SetShortcutId( const INT32& v );
	INT32 GetShortcutId();
	void SendShortcutId(bool OnlyToClient=true);
public:
	//天赋技能
	void SetTalentSkill( const vector<SkillTalentSlotWraperV1>& v );
	void SetTalentSkill( int Index, const SkillTalentSlotWraperV1& v );
	vector<SkillTalentSlotWraperV1> GetTalentSkill();
	SkillTalentSlotWraperV1 GetTalentSkill( int Index );
	void AddTalentSkill( const SkillTalentSlotWraperV1& v);
	void SendTalentSkill( int Index,bool OnlyToClient=true );
	void SendTalentSkill(bool OnlyToClient=true);
	int  SizeTalentSkill(){ return m_syncDataSkillData.SizeTalentSkill(); }
public:
	//累计技能消耗经验
	void SetTotalCostExp( const INT32& v );
	INT32 GetTotalCostExp();
	void SendTotalCostExp(bool OnlyToClient=true);
public:
	//修为等级
	void SetTalentLevel( const INT32& v );
	INT32 GetTalentLevel();
	void SendTalentLevel(bool OnlyToClient=true);
public:
	//天赋点
	void SetTalentPoint( const INT32& v );
	INT32 GetTalentPoint();
	void SendTalentPoint(bool OnlyToClient=true);
public:
	//生活技能
	void SetLifeSkillArray( const vector<SkillSkillObjWraperV1>& v );
	void SetLifeSkillArray( int Index, const SkillSkillObjWraperV1& v );
	vector<SkillSkillObjWraperV1> GetLifeSkillArray();
	SkillSkillObjWraperV1 GetLifeSkillArray( int Index );
	void AddLifeSkillArray( const SkillSkillObjWraperV1& v);
	void SendLifeSkillArray( int Index,bool OnlyToClient=true );
	void SendLifeSkillArray(bool OnlyToClient=true);
	int  SizeLifeSkillArray(){ return m_syncDataSkillData.SizeLifeSkillArray(); }


private:
	SkillSkillDataWraperV1 m_syncDataSkillData;

};



#endif
