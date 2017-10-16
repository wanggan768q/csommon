#ifndef __SYNC_DATA_SHOP_V1_H
#define __SYNC_DATA_SHOP_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "ShopV1DataWraper.h"


//同步数据相关枚举量定义
enum ShopSyncDataItemIdE
{
 	SYNCID_SHOP_SHOPARRAY                       = 2201,  //商店

};


//主同步数据操作类
class SyncDataShopV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataShopV1>
{
public:
			SyncDataShopV1();
	virtual	~SyncDataShopV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataShopData.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataShopData.HtmlDescHeader(); }
public:
	//商店
	void SetShopArray( const vector<ShopShopObjWraperV1>& v );
	void SetShopArray( int Index, const ShopShopObjWraperV1& v );
	vector<ShopShopObjWraperV1> GetShopArray();
	ShopShopObjWraperV1 GetShopArray( int Index );
	void AddShopArray( const ShopShopObjWraperV1& v);
	void SendShopArray( int Index,bool OnlyToClient=true );
	void SendShopArray(bool OnlyToClient=true);
	int  SizeShopArray(){ return m_syncDataShopData.SizeShopArray(); }


private:
	ShopShopDataWraperV1 m_syncDataShopData;

};



#endif
