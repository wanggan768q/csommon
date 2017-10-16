#ifndef __SYNC_DATA_TEAM_V1_H
#define __SYNC_DATA_TEAM_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "TeamV1DataWraper.h"


//同步数据相关枚举量定义
enum TeamSyncDataItemIdE
{
 	SYNCID_TEAM_TEAMDATA                        = 2607,  //组队数据
 	SYNCID_TEAM_APPLYLIST                       = 2613,  //申请列表

};


//主同步数据操作类
class SyncDataTeamV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataTeamV1>
{
public:
			SyncDataTeamV1();
	virtual	~SyncDataTeamV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataTeamData.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataTeamData.HtmlDescHeader(); }
public:
	//组队数据
	void SetTeamData( const TeamObjWraper& v );
	TeamObjWraper GetTeamData();
	void SendTeamData(bool OnlyToClient=true);
public:
	//申请列表
	void SetApplyList( const vector<TeamApplyUserObjWraper>& v );
	void SetApplyList( int Index, const TeamApplyUserObjWraper& v );
	vector<TeamApplyUserObjWraper> GetApplyList();
	TeamApplyUserObjWraper GetApplyList( int Index );
	void AddApplyList( const TeamApplyUserObjWraper& v);
	void SendApplyList( int Index,bool OnlyToClient=true );
	void SendApplyList(bool OnlyToClient=true);
	int  SizeApplyList(){ return m_syncDataTeamData.SizeApplyList(); }


private:
	TeamTeamDataWraperV1 m_syncDataTeamData;

};



#endif
