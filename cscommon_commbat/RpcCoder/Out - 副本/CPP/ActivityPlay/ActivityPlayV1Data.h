#ifndef __SYNC_DATA_ACTIVITYPLAY_V1_H
#define __SYNC_DATA_ACTIVITYPLAY_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "ActivityPlayV1DataWraper.h"


//同步数据相关枚举量定义
enum ActivityPlaySyncDataItemIdE
{
 	SYNCID_ACTIVITYPLAY_THIEFDATA               = 3801,  //江洋大盗数据
 	SYNCID_ACTIVITYPLAY_SUBDUEMONSTERDATA       = 3802,  //降妖除魔数据
 	SYNCID_ACTIVITYPLAY_WORLDBOSSDATA           = 3803,  //世界Boss数据
 	SYNCID_ACTIVITYPLAY_WORLDBOSSRANK           = 3804,  //世界Boss排名

};


//主同步数据操作类
class SyncDataActivityPlayV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataActivityPlayV1>
{
public:
			SyncDataActivityPlayV1();
	virtual	~SyncDataActivityPlayV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataActivityData.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataActivityData.HtmlDescHeader(); }
public:
	//江洋大盗数据
	void SetThiefData( const vector<ActivityNpcDataWraper>& v );
	void SetThiefData( int Index, const ActivityNpcDataWraper& v );
	vector<ActivityNpcDataWraper> GetThiefData();
	ActivityNpcDataWraper GetThiefData( int Index );
	void AddThiefData( const ActivityNpcDataWraper& v);
	void SendThiefData( int Index,bool OnlyToClient=true );
	void SendThiefData(bool OnlyToClient=true);
	int  SizeThiefData(){ return m_syncDataActivityData.SizeThiefData(); }
public:
	//降妖除魔数据
	void SetSubdueMonsterData( const vector<ActivityNpcDataWraper>& v );
	void SetSubdueMonsterData( int Index, const ActivityNpcDataWraper& v );
	vector<ActivityNpcDataWraper> GetSubdueMonsterData();
	ActivityNpcDataWraper GetSubdueMonsterData( int Index );
	void AddSubdueMonsterData( const ActivityNpcDataWraper& v);
	void SendSubdueMonsterData( int Index,bool OnlyToClient=true );
	void SendSubdueMonsterData(bool OnlyToClient=true);
	int  SizeSubdueMonsterData(){ return m_syncDataActivityData.SizeSubdueMonsterData(); }
public:
	//世界Boss数据
	void SetWorldBossData( const vector<WorldBossObjWraper>& v );
	void SetWorldBossData( int Index, const WorldBossObjWraper& v );
	vector<WorldBossObjWraper> GetWorldBossData();
	WorldBossObjWraper GetWorldBossData( int Index );
	void AddWorldBossData( const WorldBossObjWraper& v);
	void SendWorldBossData( int Index,bool OnlyToClient=true );
	void SendWorldBossData(bool OnlyToClient=true);
	int  SizeWorldBossData(){ return m_syncDataActivityData.SizeWorldBossData(); }
public:
	//世界Boss排名
	void SetWorldBossRank( const vector<WorldBossRankObjWraper>& v );
	void SetWorldBossRank( int Index, const WorldBossRankObjWraper& v );
	vector<WorldBossRankObjWraper> GetWorldBossRank();
	WorldBossRankObjWraper GetWorldBossRank( int Index );
	void AddWorldBossRank( const WorldBossRankObjWraper& v);
	void SendWorldBossRank( int Index,bool OnlyToClient=true );
	void SendWorldBossRank(bool OnlyToClient=true);
	int  SizeWorldBossRank(){ return m_syncDataActivityData.SizeWorldBossRank(); }


private:
	ActivityPlayActivityDataWraperV1 m_syncDataActivityData;

};



#endif
