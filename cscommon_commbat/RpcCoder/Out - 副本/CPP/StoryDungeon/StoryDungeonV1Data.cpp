#include "StoryDungeonV1Data.h"
#include "StoryDungeonModule.h"


SyncDataStoryDungeonV1::SyncDataStoryDungeonV1()
{
	SetDataWraper( &m_syncDataStoryDungeon );
}

SyncDataStoryDungeonV1::~SyncDataStoryDungeonV1()
{
}

void SyncDataStoryDungeonV1::SendAllMembers(bool OnlyToClient)
{
	SendStoryDungeon(OnlyToClient);
	SendChallengeNum(OnlyToClient);

}



//剧情副本数据
void SyncDataStoryDungeonV1::SetStoryDungeon( const vector<StoryDungeonStoryDungeonObjWraperV1>& v )
{
	m_syncDataStoryDungeon.SetStoryDungeon(v);
	OnDataChange();
	ModuleStoryDungeon::Instance().NotifySyncValueChanged(m_syncDataStoryDungeon.GetKey(),SYNCID_STORYDUNGEON_STORYDUNGEON);
	SendStoryDungeon(false);
}
void SyncDataStoryDungeonV1::SetStoryDungeon( int Index, const StoryDungeonStoryDungeonObjWraperV1& v )
{
	m_syncDataStoryDungeon.SetStoryDungeon(Index,v);
	OnDataChange();
	ModuleStoryDungeon::Instance().NotifySyncValueChanged(m_syncDataStoryDungeon.GetKey(),SYNCID_STORYDUNGEON_STORYDUNGEON,Index);
	SendStoryDungeon(Index,false);
}
vector<StoryDungeonStoryDungeonObjWraperV1> SyncDataStoryDungeonV1::GetStoryDungeon()
{
	return m_syncDataStoryDungeon.GetStoryDungeon();
}
StoryDungeonStoryDungeonObjWraperV1 SyncDataStoryDungeonV1::GetStoryDungeon( int Index )
{
	return m_syncDataStoryDungeon.GetStoryDungeon(Index);
}
void SyncDataStoryDungeonV1::SendStoryDungeon(bool OnlyToClient)
{
	SendStoryDungeon(-1,OnlyToClient);
	for(int i=0; i<m_syncDataStoryDungeon.SizeStoryDungeon(); i++)
		SendStoryDungeon(i,OnlyToClient);
}
void SyncDataStoryDungeonV1::SendStoryDungeon( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_STORYDUNGEON_STORYDUNGEON,Index,NULL,0);
		if(ModuleStoryDungeon::Instance().NotSyncToClient(SYNCID_STORYDUNGEON_STORYDUNGEON)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_STORYDUNGEON_STORYDUNGEON,Index,NULL,0);
		return;
	}
	const string v= GetStoryDungeon(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_STORYDUNGEON_STORYDUNGEON,Index,v.data(),v.size());
	if(ModuleStoryDungeon::Instance().NotSyncToClient(SYNCID_STORYDUNGEON_STORYDUNGEON)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_STORYDUNGEON_STORYDUNGEON,Index,v.data(),v.size());
}
void SyncDataStoryDungeonV1::AddStoryDungeon( const StoryDungeonStoryDungeonObjWraperV1& v )
{
	m_syncDataStoryDungeon.AddStoryDungeon(v);
	OnDataChange();
	int Index = m_syncDataStoryDungeon.SizeStoryDungeon()-1;
	ModuleStoryDungeon::Instance().NotifySyncValueChanged(m_syncDataStoryDungeon.GetKey(),SYNCID_STORYDUNGEON_STORYDUNGEON,Index);
	SendStoryDungeon(Index,false);
}

//剩余挑战次数
void SyncDataStoryDungeonV1::SetChallengeNum( const INT32& v )
{
	m_syncDataStoryDungeon.SetChallengeNum(v);
	OnDataChange();
	ModuleStoryDungeon::Instance().NotifySyncValueChanged(m_syncDataStoryDungeon.GetKey(),SYNCID_STORYDUNGEON_CHALLENGENUM);
	SendChallengeNum(false);
}
INT32 SyncDataStoryDungeonV1::GetChallengeNum()
{
	return m_syncDataStoryDungeon.GetChallengeNum();
}
void SyncDataStoryDungeonV1::SendChallengeNum(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_STORYDUNGEON_CHALLENGENUM,m_syncDataStoryDungeon.GetChallengeNum());
	if(ModuleStoryDungeon::Instance().NotSyncToClient(SYNCID_STORYDUNGEON_CHALLENGENUM)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_STORYDUNGEON_CHALLENGENUM,m_syncDataStoryDungeon.GetChallengeNum());
}
