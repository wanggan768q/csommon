#ifndef __SYNC_DATA_ONLINEDATA_V1_H
#define __SYNC_DATA_ONLINEDATA_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "OnlineDataV1DataWraper.h"


//同步数据相关枚举量定义
enum OnlineDataSyncDataItemIdE
{
 	SYNCID_ONLINEDATA_BAGRECYCLEBIN             = 2801,  //回收站
 	SYNCID_ONLINEDATA_ROLEATTR                  = 2802,  //角色属性
 	SYNCID_ONLINEDATA_RECOMMENDFRIENDOFFSET     = 2804,  //推荐好友偏移
 	SYNCID_ONLINEDATA_RECOMMENDFRIENDFLUSHTIME  = 2805,  //推荐好友刷新时间
 	SYNCID_ONLINEDATA_RECOMMENDFRIENDLASTLIST   = 2806,  //上次推荐的好友
 	SYNCID_ONLINEDATA_FOLLOWMEUSERID            = 2807,  //跟随我的人
 	SYNCID_ONLINEDATA_FOLLOWWHO                 = 2809,  //跟随谁
 	SYNCID_ONLINEDATA_THIEFOBJID                = 2810,  //江洋大盗

};


//主同步数据操作类
class SyncDataOnlineDataV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataOnlineDataV1>
{
public:
			SyncDataOnlineDataV1();
	virtual	~SyncDataOnlineDataV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataOnlineData.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataOnlineData.HtmlDescHeader(); }
public:
	//回收站
	void SetBagRecycleBin( const vector<BagRecycleGridObjWraper>& v );
	void SetBagRecycleBin( int Index, const BagRecycleGridObjWraper& v );
	vector<BagRecycleGridObjWraper> GetBagRecycleBin();
	BagRecycleGridObjWraper GetBagRecycleBin( int Index );
	void AddBagRecycleBin( const BagRecycleGridObjWraper& v);
	void SendBagRecycleBin( int Index,bool OnlyToClient=true );
	void SendBagRecycleBin(bool OnlyToClient=true);
	int  SizeBagRecycleBin(){ return m_syncDataOnlineData.SizeBagRecycleBin(); }
public:
	//角色属性
	void SetRoleAttr( const vector<OnlineDataRoleAttrObjWraperV1>& v );
	void SetRoleAttr( int Index, const OnlineDataRoleAttrObjWraperV1& v );
	vector<OnlineDataRoleAttrObjWraperV1> GetRoleAttr();
	OnlineDataRoleAttrObjWraperV1 GetRoleAttr( int Index );
	void AddRoleAttr( const OnlineDataRoleAttrObjWraperV1& v);
	void SendRoleAttr( int Index,bool OnlyToClient=true );
	void SendRoleAttr(bool OnlyToClient=true);
	int  SizeRoleAttr(){ return m_syncDataOnlineData.SizeRoleAttr(); }
public:
	//推荐好友偏移
	void SetRecommendFriendOffset( const INT32& v );
	INT32 GetRecommendFriendOffset();
	void SendRecommendFriendOffset(bool OnlyToClient=true);
public:
	//推荐好友刷新时间
	void SetRecommendFriendFlushTime( const INT32& v );
	INT32 GetRecommendFriendFlushTime();
	void SendRecommendFriendFlushTime(bool OnlyToClient=true);
public:
	//上次推荐的好友
	void SetRecommendFriendLastList( const vector<INT64>& v );
	void SetRecommendFriendLastList( int Index, const INT64& v );
	vector<INT64> GetRecommendFriendLastList();
	INT64 GetRecommendFriendLastList( int Index );
	void AddRecommendFriendLastList( INT64 v=-1 );
	void SendRecommendFriendLastList( int Index,bool OnlyToClient=true );
	void SendRecommendFriendLastList(bool OnlyToClient=true);
	int  SizeRecommendFriendLastList(){ return m_syncDataOnlineData.SizeRecommendFriendLastList(); }
public:
	//跟随我的人
	void SetFollowmeUserId( const vector<INT64>& v );
	void SetFollowmeUserId( int Index, const INT64& v );
	vector<INT64> GetFollowmeUserId();
	INT64 GetFollowmeUserId( int Index );
	void AddFollowmeUserId( INT64 v=-1 );
	void SendFollowmeUserId( int Index,bool OnlyToClient=true );
	void SendFollowmeUserId(bool OnlyToClient=true);
	int  SizeFollowmeUserId(){ return m_syncDataOnlineData.SizeFollowmeUserId(); }
public:
	//跟随谁
	void SetFollowWho( const INT64& v );
	INT64 GetFollowWho();
	void SendFollowWho(bool OnlyToClient=true);
public:
	//江洋大盗
	void SetThiefObjId( const INT64& v );
	INT64 GetThiefObjId();
	void SendThiefObjId(bool OnlyToClient=true);


private:
	OnlineDataOnlineDataWraperV1 m_syncDataOnlineData;

};



#endif
