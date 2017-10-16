#ifndef __SYNC_DATA_ONEVSONETOP_V1_H
#define __SYNC_DATA_ONEVSONETOP_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "OneVSOneTopV1DataWraper.h"


//同步数据相关枚举量定义
enum OneVSOneTopSyncDataItemIdE
{
 	SYNCID_ONEVSONETOP_TOPMESSES                = 4201,  //排行榜数据
 	SYNCID_ONEVSONETOP_TIME                     = 4206,  //格林时间

};


//主同步数据操作类
class SyncDataOneVSOneTopV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataOneVSOneTopV1>
{
public:
			SyncDataOneVSOneTopV1();
	virtual	~SyncDataOneVSOneTopV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataOneVSOneDate.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataOneVSOneDate.HtmlDescHeader(); }
public:
	//排行榜数据
	void SetTopMesses( const vector<TopMessWraper>& v );
	void SetTopMesses( int Index, const TopMessWraper& v );
	vector<TopMessWraper> GetTopMesses();
	TopMessWraper GetTopMesses( int Index );
	void AddTopMesses( const TopMessWraper& v);
	void SendTopMesses( int Index,bool OnlyToClient=true );
	void SendTopMesses(bool OnlyToClient=true);
	int  SizeTopMesses(){ return m_syncDataOneVSOneDate.SizeTopMesses(); }
public:
	//格林时间
	void SetTime( const INT64& v );
	INT64 GetTime();
	void SendTime(bool OnlyToClient=true);


private:
	OneVSOneTopOneVSOneDateWraperV1 m_syncDataOneVSOneDate;

};



#endif
