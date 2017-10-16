#ifndef __SYNC_DATA_FRIEND_V1_H
#define __SYNC_DATA_FRIEND_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "FriendV1DataWraper.h"


//同步数据相关枚举量定义
enum FriendSyncDataItemIdE
{
 	SYNCID_FRIEND_FRIENDLIST                    = 3301,  //好友列表
 	SYNCID_FRIEND_BLACKLIST                     = 3302,  //黑名单
 	SYNCID_FRIEND_CONTACTSLIST                  = 3303,  //最近联系人
 	SYNCID_FRIEND_STRANGERFRIENDLIST            = 3304,  //加过我的人

};


//主同步数据操作类
class SyncDataFriendV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataFriendV1>
{
public:
			SyncDataFriendV1();
	virtual	~SyncDataFriendV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataFriendData.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataFriendData.HtmlDescHeader(); }
public:
	//好友列表
	void SetFriendList( const vector<FriendFriendObjWraperV1>& v );
	void SetFriendList( int Index, const FriendFriendObjWraperV1& v );
	vector<FriendFriendObjWraperV1> GetFriendList();
	FriendFriendObjWraperV1 GetFriendList( int Index );
	void AddFriendList( const FriendFriendObjWraperV1& v);
	void SendFriendList( int Index,bool OnlyToClient=true );
	void SendFriendList(bool OnlyToClient=true);
	int  SizeFriendList(){ return m_syncDataFriendData.SizeFriendList(); }
public:
	//黑名单
	void SetBlackList( const vector<FriendFriendObjWraperV1>& v );
	void SetBlackList( int Index, const FriendFriendObjWraperV1& v );
	vector<FriendFriendObjWraperV1> GetBlackList();
	FriendFriendObjWraperV1 GetBlackList( int Index );
	void AddBlackList( const FriendFriendObjWraperV1& v);
	void SendBlackList( int Index,bool OnlyToClient=true );
	void SendBlackList(bool OnlyToClient=true);
	int  SizeBlackList(){ return m_syncDataFriendData.SizeBlackList(); }
public:
	//最近联系人
	void SetContactsList( const vector<FriendFriendObjWraperV1>& v );
	void SetContactsList( int Index, const FriendFriendObjWraperV1& v );
	vector<FriendFriendObjWraperV1> GetContactsList();
	FriendFriendObjWraperV1 GetContactsList( int Index );
	void AddContactsList( const FriendFriendObjWraperV1& v);
	void SendContactsList( int Index,bool OnlyToClient=true );
	void SendContactsList(bool OnlyToClient=true);
	int  SizeContactsList(){ return m_syncDataFriendData.SizeContactsList(); }
public:
	//加过我的人
	void SetStrangerFriendList( const vector<INT64>& v );
	void SetStrangerFriendList( int Index, const INT64& v );
	vector<INT64> GetStrangerFriendList();
	INT64 GetStrangerFriendList( int Index );
	void AddStrangerFriendList( INT64 v=-1 );
	void SendStrangerFriendList( int Index,bool OnlyToClient=true );
	void SendStrangerFriendList(bool OnlyToClient=true);
	int  SizeStrangerFriendList(){ return m_syncDataFriendData.SizeStrangerFriendList(); }


private:
	FriendFriendDataWraperV1 m_syncDataFriendData;

};



#endif
