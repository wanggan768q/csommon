#ifndef __SYNC_DATA_ONEVSONE_V1_H
#define __SYNC_DATA_ONEVSONE_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "OneVSOneV1DataWraper.h"


//同步数据相关枚举量定义
enum OneVSOneSyncDataItemIdE
{
 	SYNCID_ONEVSONE_SKILLDATE                   = 4104,  //技能数据
 	SYNCID_ONEVSONE_LOG                         = 4105,  //log日志
 	SYNCID_ONEVSONE_ONEVSONENUM                 = 4106,  //一对一的剩余次数
 	SYNCID_ONEVSONE_SAVETIME                    = 4107,  //格林威治时间服务器用
 	SYNCID_ONEVSONE_RANKING                     = 4108,  //排行名次
 	SYNCID_ONEVSONE_RANKINGTIMES                = 4110,  //排行名次 时间段的

};


//主同步数据操作类
class SyncDataOneVSOneV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataOneVSOneV1>
{
public:
			SyncDataOneVSOneV1();
	virtual	~SyncDataOneVSOneV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataOneVSOneDate.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataOneVSOneDate.HtmlDescHeader(); }
public:
	//技能数据
	void SetSkillDate( const vector<OneSDataWraper>& v );
	void SetSkillDate( int Index, const OneSDataWraper& v );
	vector<OneSDataWraper> GetSkillDate();
	OneSDataWraper GetSkillDate( int Index );
	void AddSkillDate( const OneSDataWraper& v);
	void SendSkillDate( int Index,bool OnlyToClient=true );
	void SendSkillDate(bool OnlyToClient=true);
	int  SizeSkillDate(){ return m_syncDataOneVSOneDate.SizeSkillDate(); }
public:
	//log日志
	void SetLog( const vector<ActMessageWraper>& v );
	void SetLog( int Index, const ActMessageWraper& v );
	vector<ActMessageWraper> GetLog();
	ActMessageWraper GetLog( int Index );
	void AddLog( const ActMessageWraper& v);
	void SendLog( int Index,bool OnlyToClient=true );
	void SendLog(bool OnlyToClient=true);
	int  SizeLog(){ return m_syncDataOneVSOneDate.SizeLog(); }
public:
	//一对一的剩余次数
	void SetOneVSOneNum( const INT32& v );
	INT32 GetOneVSOneNum();
	void SendOneVSOneNum(bool OnlyToClient=true);
public:
	//格林威治时间服务器用
	void SetSaveTime( const INT64& v );
	INT64 GetSaveTime();
	void SendSaveTime(bool OnlyToClient=true);
public:
	//排行名次
	void SetRanking( const INT32& v );
	INT32 GetRanking();
	void SendRanking(bool OnlyToClient=true);
public:
	//排行名次 时间段的
	void SetRankingTimes( const vector<TimeTopWraper>& v );
	void SetRankingTimes( int Index, const TimeTopWraper& v );
	vector<TimeTopWraper> GetRankingTimes();
	TimeTopWraper GetRankingTimes( int Index );
	void AddRankingTimes( const TimeTopWraper& v);
	void SendRankingTimes( int Index,bool OnlyToClient=true );
	void SendRankingTimes(bool OnlyToClient=true);
	int  SizeRankingTimes(){ return m_syncDataOneVSOneDate.SizeRankingTimes(); }


private:
	OneVSOneOneVSOneDateWraperV1 m_syncDataOneVSOneDate;

};



#endif
