#ifndef __SYNC_DATA_TALISMAN_V1_H
#define __SYNC_DATA_TALISMAN_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "TalismanV1DataWraper.h"


//同步数据相关枚举量定义
enum TalismanSyncDataItemIdE
{
 	SYNCID_TALISMAN_FABAOARR                    = 1801,  //法宝列表

};


//主同步数据操作类
class SyncDataTalismanV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataTalismanV1>
{
public:
			SyncDataTalismanV1();
	virtual	~SyncDataTalismanV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataDataFabao.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataDataFabao.HtmlDescHeader(); }
public:
	//法宝列表
	void SetFabaoArr( const vector<TalismanFabaoInfoWraperV1>& v );
	void SetFabaoArr( int Index, const TalismanFabaoInfoWraperV1& v );
	vector<TalismanFabaoInfoWraperV1> GetFabaoArr();
	TalismanFabaoInfoWraperV1 GetFabaoArr( int Index );
	void AddFabaoArr( const TalismanFabaoInfoWraperV1& v);
	void SendFabaoArr( int Index,bool OnlyToClient=true );
	void SendFabaoArr(bool OnlyToClient=true);
	int  SizeFabaoArr(){ return m_syncDataDataFabao.SizeFabaoArr(); }


private:
	TalismanDataFabaoWraperV1 m_syncDataDataFabao;

};



#endif
