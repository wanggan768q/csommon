#ifndef __SYNC_DATA_ACHIEVEMENT_V1_H
#define __SYNC_DATA_ACHIEVEMENT_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "AchievementV1DataWraper.h"


//同步数据相关枚举量定义
enum AchievementSyncDataItemIdE
{
 	SYNCID_ACHIEVEMENT_ACHIDATA                 = 201,  //成就数据

};


//主同步数据操作类
class SyncDataAchievementV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataAchievementV1>
{
public:
			SyncDataAchievementV1();
	virtual	~SyncDataAchievementV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataAchiData.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataAchiData.HtmlDescHeader(); }
public:
	//成就数据
	void SetAchiData( const vector<AchievementAchiObjWraperV1>& v );
	void SetAchiData( int Index, const AchievementAchiObjWraperV1& v );
	vector<AchievementAchiObjWraperV1> GetAchiData();
	AchievementAchiObjWraperV1 GetAchiData( int Index );
	void AddAchiData( const AchievementAchiObjWraperV1& v);
	void SendAchiData( int Index,bool OnlyToClient=true );
	void SendAchiData(bool OnlyToClient=true);
	int  SizeAchiData(){ return m_syncDataAchiData.SizeAchiData(); }


private:
	AchievementAchiDataWraperV1 m_syncDataAchiData;

};



#endif
