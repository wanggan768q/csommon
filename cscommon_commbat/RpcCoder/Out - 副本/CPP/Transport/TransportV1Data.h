#ifndef __SYNC_DATA_TRANSPORT_V1_H
#define __SYNC_DATA_TRANSPORT_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "TransportV1DataWraper.h"


//同步数据相关枚举量定义
enum TransportSyncDataItemIdE
{
 	SYNCID_TRANSPORT_GOODSARRAY                 = 4001,  //货物容器
 	SYNCID_TRANSPORT_ASKNUM                     = 4002,  //请求数量
 	SYNCID_TRANSPORT_HELPNUM                    = 4003,  //帮助次数
 	SYNCID_TRANSPORT_REWARDARRY                 = 4004,  //起航奖励
 	SYNCID_TRANSPORT_REWARDFLAG                 = 4006,  //奖励是否领取标识
 	SYNCID_TRANSPORT_PICKTASKFLAG               = 4007,  //是否接取任务

};


//主同步数据操作类
class SyncDataTransportV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataTransportV1>
{
public:
			SyncDataTransportV1();
	virtual	~SyncDataTransportV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataGoodsData.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataGoodsData.HtmlDescHeader(); }
public:
	//货物容器
	void SetGoodsArray( const vector<TransportGoodsObjWraperV1>& v );
	void SetGoodsArray( int Index, const TransportGoodsObjWraperV1& v );
	vector<TransportGoodsObjWraperV1> GetGoodsArray();
	TransportGoodsObjWraperV1 GetGoodsArray( int Index );
	void AddGoodsArray( const TransportGoodsObjWraperV1& v);
	void SendGoodsArray( int Index,bool OnlyToClient=true );
	void SendGoodsArray(bool OnlyToClient=true);
	int  SizeGoodsArray(){ return m_syncDataGoodsData.SizeGoodsArray(); }
public:
	//请求数量
	void SetAskNum( const INT32& v );
	INT32 GetAskNum();
	void SendAskNum(bool OnlyToClient=true);
public:
	//帮助次数
	void SetHelpNum( const INT32& v );
	INT32 GetHelpNum();
	void SendHelpNum(bool OnlyToClient=true);
public:
	//起航奖励
	void SetRewardArry( const vector<TransportRewardObjWraperV1>& v );
	void SetRewardArry( int Index, const TransportRewardObjWraperV1& v );
	vector<TransportRewardObjWraperV1> GetRewardArry();
	TransportRewardObjWraperV1 GetRewardArry( int Index );
	void AddRewardArry( const TransportRewardObjWraperV1& v);
	void SendRewardArry( int Index,bool OnlyToClient=true );
	void SendRewardArry(bool OnlyToClient=true);
	int  SizeRewardArry(){ return m_syncDataGoodsData.SizeRewardArry(); }
public:
	//奖励是否领取标识
	void SetRewardFlag( const bool& v );
	bool GetRewardFlag();
	void SendRewardFlag(bool OnlyToClient=true);
public:
	//是否接取任务
	void SetPickTaskFlag( const bool& v );
	bool GetPickTaskFlag();
	void SendPickTaskFlag(bool OnlyToClient=true);


private:
	TransportGoodsDataWraperV1 m_syncDataGoodsData;

};



#endif
