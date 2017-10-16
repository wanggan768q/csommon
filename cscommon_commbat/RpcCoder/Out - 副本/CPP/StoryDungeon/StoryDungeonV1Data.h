#ifndef __SYNC_DATA_STORYDUNGEON_V1_H
#define __SYNC_DATA_STORYDUNGEON_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "StoryDungeonV1DataWraper.h"


//同步数据相关枚举量定义
enum StoryDungeonSyncDataItemIdE
{
 	SYNCID_STORYDUNGEON_STORYDUNGEON            = 4301,  //剧情副本数据
 	SYNCID_STORYDUNGEON_CHALLENGENUM            = 4302,  //剩余挑战次数

};


//主同步数据操作类
class SyncDataStoryDungeonV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataStoryDungeonV1>
{
public:
			SyncDataStoryDungeonV1();
	virtual	~SyncDataStoryDungeonV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataStoryDungeon.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataStoryDungeon.HtmlDescHeader(); }
public:
	//剧情副本数据
	void SetStoryDungeon( const vector<StoryDungeonStoryDungeonObjWraperV1>& v );
	void SetStoryDungeon( int Index, const StoryDungeonStoryDungeonObjWraperV1& v );
	vector<StoryDungeonStoryDungeonObjWraperV1> GetStoryDungeon();
	StoryDungeonStoryDungeonObjWraperV1 GetStoryDungeon( int Index );
	void AddStoryDungeon( const StoryDungeonStoryDungeonObjWraperV1& v);
	void SendStoryDungeon( int Index,bool OnlyToClient=true );
	void SendStoryDungeon(bool OnlyToClient=true);
	int  SizeStoryDungeon(){ return m_syncDataStoryDungeon.SizeStoryDungeon(); }
public:
	//剩余挑战次数
	void SetChallengeNum( const INT32& v );
	INT32 GetChallengeNum();
	void SendChallengeNum(bool OnlyToClient=true);


private:
	StoryDungeonStoryDungeonWraperV1 m_syncDataStoryDungeon;

};



#endif
