#include "SkillV1Data.h"
#include "SkillModule.h"


SyncDataSkillV1::SyncDataSkillV1()
{
	SetDataWraper( &m_syncDataSkillData );
}

SyncDataSkillV1::~SyncDataSkillV1()
{
}

void SyncDataSkillV1::SendAllMembers(bool OnlyToClient)
{
	SendSkillArray(OnlyToClient);
	SendShortcutArray(OnlyToClient);
	SendShortcutId(OnlyToClient);
	SendTalentSkill(OnlyToClient);
	SendTotalCostExp(OnlyToClient);
	SendTalentLevel(OnlyToClient);
	SendTalentPoint(OnlyToClient);
	SendLifeSkillArray(OnlyToClient);

}



//全部技能
void SyncDataSkillV1::SetSkillArray( const vector<SkillSkillObjWraperV1>& v )
{
	m_syncDataSkillData.SetSkillArray(v);
	OnDataChange();
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_SKILLARRAY);
	SendSkillArray(false);
}
void SyncDataSkillV1::SetSkillArray( int Index, const SkillSkillObjWraperV1& v )
{
	m_syncDataSkillData.SetSkillArray(Index,v);
	OnDataChange();
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_SKILLARRAY,Index);
	SendSkillArray(Index,false);
}
vector<SkillSkillObjWraperV1> SyncDataSkillV1::GetSkillArray()
{
	return m_syncDataSkillData.GetSkillArray();
}
SkillSkillObjWraperV1 SyncDataSkillV1::GetSkillArray( int Index )
{
	return m_syncDataSkillData.GetSkillArray(Index);
}
void SyncDataSkillV1::SendSkillArray(bool OnlyToClient)
{
	SendSkillArray(-1,OnlyToClient);
	for(int i=0; i<m_syncDataSkillData.SizeSkillArray(); i++)
		SendSkillArray(i,OnlyToClient);
}
void SyncDataSkillV1::SendSkillArray( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_SKILL_SKILLARRAY,Index,NULL,0);
		if(ModuleSkill::Instance().NotSyncToClient(SYNCID_SKILL_SKILLARRAY)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_SKILL_SKILLARRAY,Index,NULL,0);
		return;
	}
	const string v= GetSkillArray(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_SKILL_SKILLARRAY,Index,v.data(),v.size());
	if(ModuleSkill::Instance().NotSyncToClient(SYNCID_SKILL_SKILLARRAY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_SKILL_SKILLARRAY,Index,v.data(),v.size());
}
void SyncDataSkillV1::AddSkillArray( const SkillSkillObjWraperV1& v )
{
	m_syncDataSkillData.AddSkillArray(v);
	OnDataChange();
	int Index = m_syncDataSkillData.SizeSkillArray()-1;
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_SKILLARRAY,Index);
	SendSkillArray(Index,false);
}

//快捷栏
void SyncDataSkillV1::SetShortcutArray( const vector<SkillShortcutObjWraperV1>& v )
{
	m_syncDataSkillData.SetShortcutArray(v);
	OnDataChange();
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_SHORTCUTARRAY);
	SendShortcutArray(false);
}
void SyncDataSkillV1::SetShortcutArray( int Index, const SkillShortcutObjWraperV1& v )
{
	m_syncDataSkillData.SetShortcutArray(Index,v);
	OnDataChange();
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_SHORTCUTARRAY,Index);
	SendShortcutArray(Index,false);
}
vector<SkillShortcutObjWraperV1> SyncDataSkillV1::GetShortcutArray()
{
	return m_syncDataSkillData.GetShortcutArray();
}
SkillShortcutObjWraperV1 SyncDataSkillV1::GetShortcutArray( int Index )
{
	return m_syncDataSkillData.GetShortcutArray(Index);
}
void SyncDataSkillV1::SendShortcutArray(bool OnlyToClient)
{
	SendShortcutArray(-1,OnlyToClient);
	for(int i=0; i<m_syncDataSkillData.SizeShortcutArray(); i++)
		SendShortcutArray(i,OnlyToClient);
}
void SyncDataSkillV1::SendShortcutArray( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_SKILL_SHORTCUTARRAY,Index,NULL,0);
		if(ModuleSkill::Instance().NotSyncToClient(SYNCID_SKILL_SHORTCUTARRAY)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_SKILL_SHORTCUTARRAY,Index,NULL,0);
		return;
	}
	const string v= GetShortcutArray(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_SKILL_SHORTCUTARRAY,Index,v.data(),v.size());
	if(ModuleSkill::Instance().NotSyncToClient(SYNCID_SKILL_SHORTCUTARRAY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_SKILL_SHORTCUTARRAY,Index,v.data(),v.size());
}
void SyncDataSkillV1::AddShortcutArray( const SkillShortcutObjWraperV1& v )
{
	m_syncDataSkillData.AddShortcutArray(v);
	OnDataChange();
	int Index = m_syncDataSkillData.SizeShortcutArray()-1;
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_SHORTCUTARRAY,Index);
	SendShortcutArray(Index,false);
}

//方案Id，从0开始
void SyncDataSkillV1::SetShortcutId( const INT32& v )
{
	m_syncDataSkillData.SetShortcutId(v);
	OnDataChange();
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_SHORTCUTID);
	SendShortcutId(false);
}
INT32 SyncDataSkillV1::GetShortcutId()
{
	return m_syncDataSkillData.GetShortcutId();
}
void SyncDataSkillV1::SendShortcutId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_SKILL_SHORTCUTID,m_syncDataSkillData.GetShortcutId());
	if(ModuleSkill::Instance().NotSyncToClient(SYNCID_SKILL_SHORTCUTID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_SKILL_SHORTCUTID,m_syncDataSkillData.GetShortcutId());
}

//天赋技能
void SyncDataSkillV1::SetTalentSkill( const vector<SkillTalentSlotWraperV1>& v )
{
	m_syncDataSkillData.SetTalentSkill(v);
	OnDataChange();
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_TALENTSKILL);
	SendTalentSkill(false);
}
void SyncDataSkillV1::SetTalentSkill( int Index, const SkillTalentSlotWraperV1& v )
{
	m_syncDataSkillData.SetTalentSkill(Index,v);
	OnDataChange();
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_TALENTSKILL,Index);
	SendTalentSkill(Index,false);
}
vector<SkillTalentSlotWraperV1> SyncDataSkillV1::GetTalentSkill()
{
	return m_syncDataSkillData.GetTalentSkill();
}
SkillTalentSlotWraperV1 SyncDataSkillV1::GetTalentSkill( int Index )
{
	return m_syncDataSkillData.GetTalentSkill(Index);
}
void SyncDataSkillV1::SendTalentSkill(bool OnlyToClient)
{
	SendTalentSkill(-1,OnlyToClient);
	for(int i=0; i<m_syncDataSkillData.SizeTalentSkill(); i++)
		SendTalentSkill(i,OnlyToClient);
}
void SyncDataSkillV1::SendTalentSkill( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_SKILL_TALENTSKILL,Index,NULL,0);
		if(ModuleSkill::Instance().NotSyncToClient(SYNCID_SKILL_TALENTSKILL)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_SKILL_TALENTSKILL,Index,NULL,0);
		return;
	}
	const string v= GetTalentSkill(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_SKILL_TALENTSKILL,Index,v.data(),v.size());
	if(ModuleSkill::Instance().NotSyncToClient(SYNCID_SKILL_TALENTSKILL)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_SKILL_TALENTSKILL,Index,v.data(),v.size());
}
void SyncDataSkillV1::AddTalentSkill( const SkillTalentSlotWraperV1& v )
{
	m_syncDataSkillData.AddTalentSkill(v);
	OnDataChange();
	int Index = m_syncDataSkillData.SizeTalentSkill()-1;
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_TALENTSKILL,Index);
	SendTalentSkill(Index,false);
}

//累计技能消耗经验
void SyncDataSkillV1::SetTotalCostExp( const INT32& v )
{
	m_syncDataSkillData.SetTotalCostExp(v);
	OnDataChange();
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_TOTALCOSTEXP);
	SendTotalCostExp(false);
}
INT32 SyncDataSkillV1::GetTotalCostExp()
{
	return m_syncDataSkillData.GetTotalCostExp();
}
void SyncDataSkillV1::SendTotalCostExp(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_SKILL_TOTALCOSTEXP,m_syncDataSkillData.GetTotalCostExp());
	if(ModuleSkill::Instance().NotSyncToClient(SYNCID_SKILL_TOTALCOSTEXP)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_SKILL_TOTALCOSTEXP,m_syncDataSkillData.GetTotalCostExp());
}

//修为等级
void SyncDataSkillV1::SetTalentLevel( const INT32& v )
{
	m_syncDataSkillData.SetTalentLevel(v);
	OnDataChange();
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_TALENTLEVEL);
	SendTalentLevel(false);
}
INT32 SyncDataSkillV1::GetTalentLevel()
{
	return m_syncDataSkillData.GetTalentLevel();
}
void SyncDataSkillV1::SendTalentLevel(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_SKILL_TALENTLEVEL,m_syncDataSkillData.GetTalentLevel());
	if(ModuleSkill::Instance().NotSyncToClient(SYNCID_SKILL_TALENTLEVEL)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_SKILL_TALENTLEVEL,m_syncDataSkillData.GetTalentLevel());
}

//天赋点
void SyncDataSkillV1::SetTalentPoint( const INT32& v )
{
	m_syncDataSkillData.SetTalentPoint(v);
	OnDataChange();
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_TALENTPOINT);
	SendTalentPoint(false);
}
INT32 SyncDataSkillV1::GetTalentPoint()
{
	return m_syncDataSkillData.GetTalentPoint();
}
void SyncDataSkillV1::SendTalentPoint(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_SKILL_TALENTPOINT,m_syncDataSkillData.GetTalentPoint());
	if(ModuleSkill::Instance().NotSyncToClient(SYNCID_SKILL_TALENTPOINT)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_SKILL_TALENTPOINT,m_syncDataSkillData.GetTalentPoint());
}

//生活技能
void SyncDataSkillV1::SetLifeSkillArray( const vector<SkillSkillObjWraperV1>& v )
{
	m_syncDataSkillData.SetLifeSkillArray(v);
	OnDataChange();
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_LIFESKILLARRAY);
	SendLifeSkillArray(false);
}
void SyncDataSkillV1::SetLifeSkillArray( int Index, const SkillSkillObjWraperV1& v )
{
	m_syncDataSkillData.SetLifeSkillArray(Index,v);
	OnDataChange();
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_LIFESKILLARRAY,Index);
	SendLifeSkillArray(Index,false);
}
vector<SkillSkillObjWraperV1> SyncDataSkillV1::GetLifeSkillArray()
{
	return m_syncDataSkillData.GetLifeSkillArray();
}
SkillSkillObjWraperV1 SyncDataSkillV1::GetLifeSkillArray( int Index )
{
	return m_syncDataSkillData.GetLifeSkillArray(Index);
}
void SyncDataSkillV1::SendLifeSkillArray(bool OnlyToClient)
{
	SendLifeSkillArray(-1,OnlyToClient);
	for(int i=0; i<m_syncDataSkillData.SizeLifeSkillArray(); i++)
		SendLifeSkillArray(i,OnlyToClient);
}
void SyncDataSkillV1::SendLifeSkillArray( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_SKILL_LIFESKILLARRAY,Index,NULL,0);
		if(ModuleSkill::Instance().NotSyncToClient(SYNCID_SKILL_LIFESKILLARRAY)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_SKILL_LIFESKILLARRAY,Index,NULL,0);
		return;
	}
	const string v= GetLifeSkillArray(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_SKILL_LIFESKILLARRAY,Index,v.data(),v.size());
	if(ModuleSkill::Instance().NotSyncToClient(SYNCID_SKILL_LIFESKILLARRAY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_SKILL_LIFESKILLARRAY,Index,v.data(),v.size());
}
void SyncDataSkillV1::AddLifeSkillArray( const SkillSkillObjWraperV1& v )
{
	m_syncDataSkillData.AddLifeSkillArray(v);
	OnDataChange();
	int Index = m_syncDataSkillData.SizeLifeSkillArray()-1;
	ModuleSkill::Instance().NotifySyncValueChanged(m_syncDataSkillData.GetKey(),SYNCID_SKILL_LIFESKILLARRAY,Index);
	SendLifeSkillArray(Index,false);
}
