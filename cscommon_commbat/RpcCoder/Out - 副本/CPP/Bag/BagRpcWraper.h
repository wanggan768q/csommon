/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperBag.h
* Author:       甘业清
* Description:  背包RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_BAG_H
#define __RPC_WRAPER_BAG_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "BagRpc.pb.h"



//背包类的枚举定义
enum ConstBagE
{
	MODULE_ID_BAG                                = 14,	//背包模块ID
	RPC_CODE_BAG_SYNCDATA_REQUEST                = 1451,	//背包-->同步背包数据-->请求
	RPC_CODE_BAG_SELL_REQUEST                    = 1452,	//背包-->物品出售-->请求
	RPC_CODE_BAG_DECOMPOSE_REQUEST               = 1453,	//背包-->物品分解-->请求
	RPC_CODE_BAG_USE_REQUEST                     = 1454,	//背包-->物品使用-->请求
	RPC_CODE_BAG_EQUIPWEAR_REQUEST               = 1455,	//背包-->装备穿戴-->请求
	RPC_CODE_BAG_EQUIPUNDRESS_REQUEST            = 1456,	//背包-->装备脱下-->请求
	RPC_CODE_BAG_EQUIPENHANCE_REQUEST            = 1457,	//背包-->装备强化-->请求
	RPC_CODE_BAG_EQUIPPOLISHED_REQUEST           = 1458,	//背包-->装备洗炼-->请求
	RPC_CODE_BAG_EQUIPPOLISHEDREPLACE_REQUEST    = 1459,	//背包-->装备洗炼属性替换-->请求
	RPC_CODE_BAG_BAGTIDY_REQUEST                 = 1460,	//背包-->背包整理-->请求
	RPC_CODE_BAG_BAGRECYCLESELL_REQUEST          = 1461,	//背包-->装备回收出售-->请求
	RPC_CODE_BAG_BAGRECYCLEBUY_REQUEST           = 1462,	//背包-->物品回收，购回-->请求
	RPC_CODE_BAG_UNLOCKGRID_REQUEST              = 1463,	//背包-->开启格子-->请求
	RPC_CODE_BAG_SPLIT_REQUEST                   = 1464,	//背包-->物品拆分-->请求
	RPC_CODE_BAG_EQUIPBASEATTRPLISHED_REQUEST    = 1465,	//背包-->装备基础属性洗炼-->请求
	RPC_CODE_BAG_EQUIPBASEATTRPOLISHEDREPLACE_REQUEST= 1466,	//背包-->装备基础属性洗炼替换-->请求
	RPC_CODE_BAG_EQUIPEXATTRMODIFY_REQUEST       = 1467,	//背包-->装备改造-->请求
	RPC_CODE_BAG_EQUIPINLAYGEM_REQUEST           = 1468,	//背包-->宝石镶嵌-->请求
	RPC_CODE_BAG_EQUIPGEMSLOTUNLOCK_REQUEST      = 1469,	//背包-->装备宝石槽位打孔-->请求
	RPC_CODE_BAG_EQUIPENHANCESWAP_REQUEST        = 1470,	//背包-->装备强化转移-->请求
	RPC_CODE_BAG_EQUIPGEMREMOVE_REQUEST          = 1471,	//背包-->装备宝石移除-->请求
	RPC_CODE_BAG_BAGPUTINSTORAGE_REQUEST         = 1472,	//背包-->存入仓库-->请求
	RPC_CODE_BAG_BAGFETCHFROMSTORAGE_REQUEST     = 1473,	//背包-->从仓库取出-->请求
	RPC_CODE_BAG_BAGSTORAGESAVEMONEY_REQUEST     = 1474,	//背包-->仓库存钱-->请求
	RPC_CODE_BAG_BAGSTORAGEDRAWMONEY_REQUEST     = 1475,	//背包-->仓库取钱-->请求
	RPC_CODE_BAG_STORAGETIDY_REQUEST             = 1476,	//背包-->仓库整理-->请求
	RPC_CODE_BAG_TALISMANLVUP_REQUEST            = 1477,	//背包-->法宝铸炼-->请求
	RPC_CODE_BAG_TALISMANINHERIT_REQUEST         = 1478,	//背包-->法宝传承-->请求
	RPC_CODE_BAG_BAGADDNEWITEM_NOTIFY            = 1479,	//背包-->背包获得新物品-->通知
	RPC_CODE_BAG_BAGSETAUTOPICKUP_REQUEST        = 1480,	//背包-->设置自动拾取-->请求
	RPC_CODE_BAG_GETNEWITEM_NOTIFY               = 1481,	//背包-->获得新物品-->通知
	RPC_CODE_BAG_BAGERROR_NOTIFY                 = 1482,	//背包-->背包错误-->通知
	RPC_CODE_BAG_TALISMANREFINDSTAR_REQUEST      = 1483,	//背包-->炼星-->请求
	RPC_CODE_BAG_TALISMANUPSLOTSKILLLEVEL_REQUEST= 1484,	//背包-->升级聚灵槽位技能-->请求
	RPC_CODE_BAG_TALISMANATTRCHANGE_NOTIFY       = 1485,	//背包-->属性变化通知-->通知
	RPC_CODE_BAG_TALISMANGATHERSPRITE_REQUEST    = 1486,	//背包-->宝石聚灵-->请求


};


//回收格子封装类
class BagRpcSellGridObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcSellGridObjWraper()
	{
		
		m_TemplateId = -1;
		m_Num = -1;
		m_Pos = -1;
		m_ItemId = -1;
		m_ItemType = -1;

	}
	//赋值构造函数
	BagRpcSellGridObjWraper(const BagRpcSellGridObj& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcSellGridObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcSellGridObj ToPB() const
	{
		BagRpcSellGridObj v;
		v.set_templateid( m_TemplateId );
		v.set_num( m_Num );
		v.set_pos( m_Pos );
		v.set_itemid( m_ItemId );
		v.set_itemtype( m_ItemType );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcSellGridObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateId(模板id) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(数量) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemId(ItemId（背包格子的Index）) [sint64]</li>\r\n";
		htmlBuff += "<li>ItemType(物品类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemId：%lldL</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemType：%di</li>\r\n",m_ItemType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcSellGridObj& v)
	{
		m_TemplateId = v.templateid();
		m_Num = v.num();
		m_Pos = v.pos();
		m_ItemId = v.itemid();
		m_ItemType = v.itemtype();

	}

private:
	//模板id
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//数量
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//ItemId（背包格子的Index）
	INT64 m_ItemId;
public:
	void SetItemId( INT64 v)
	{
		m_ItemId=v;
	}
	INT64 GetItemId()
	{
		return m_ItemId;
	}
	INT64 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//物品类型
	INT32 m_ItemType;
public:
	void SetItemType( INT32 v)
	{
		m_ItemType=v;
	}
	INT32 GetItemType()
	{
		return m_ItemType;
	}
	INT32 GetItemType() const
	{
		return m_ItemType;
	}

};
//从仓库取出回应封装类
class BagRpcBagFetchFromStorageReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagFetchFromStorageReplyWraper()
	{
		
		m_Result = -9999;
		m_TemplateId = -1;
		m_Pos = -1;
		m_Num = -1;

	}
	//赋值构造函数
	BagRpcBagFetchFromStorageReplyWraper(const BagRpcBagFetchFromStorageReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagFetchFromStorageReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagFetchFromStorageReply ToPB() const
	{
		BagRpcBagFetchFromStorageReply v;
		v.set_result( m_Result );
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_num( m_Num );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagFetchFromStorageReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TemplateId(物品模板id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(拆分出来的数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagFetchFromStorageReply& v)
	{
		m_Result = v.result();
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_Num = v.num();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//物品模板id
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//拆分出来的数量
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}

};
//从仓库取出请求封装类
class BagRpcBagFetchFromStorageAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagFetchFromStorageAskWraper()
	{
		
		m_TemplateId = -1;
		m_Pos = -1;
		m_Num = -1;

	}
	//赋值构造函数
	BagRpcBagFetchFromStorageAskWraper(const BagRpcBagFetchFromStorageAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagFetchFromStorageAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagFetchFromStorageAsk ToPB() const
	{
		BagRpcBagFetchFromStorageAsk v;
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_num( m_Num );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagFetchFromStorageAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateId(物品模板id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(拆分出来的数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagFetchFromStorageAsk& v)
	{
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_Num = v.num();

	}

private:
	//物品模板id
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//拆分出来的数量
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}

};
//存入仓库回应封装类
class BagRpcBagPutInStorageReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagPutInStorageReplyWraper()
	{
		
		m_Result = -9999;
		m_TemplateId = -1;
		m_Pos = -1;
		m_Num = -1;

	}
	//赋值构造函数
	BagRpcBagPutInStorageReplyWraper(const BagRpcBagPutInStorageReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagPutInStorageReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagPutInStorageReply ToPB() const
	{
		BagRpcBagPutInStorageReply v;
		v.set_result( m_Result );
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_num( m_Num );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagPutInStorageReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TemplateId(物品模板id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(拆分出来的数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagPutInStorageReply& v)
	{
		m_Result = v.result();
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_Num = v.num();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//物品模板id
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//拆分出来的数量
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}

};
//仓库取钱回应封装类
class BagRpcBagStorageDrawMoneyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagStorageDrawMoneyReplyWraper()
	{
		
		m_Result = -9999;
		m_Money = -1;

	}
	//赋值构造函数
	BagRpcBagStorageDrawMoneyReplyWraper(const BagRpcBagStorageDrawMoneyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagStorageDrawMoneyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagStorageDrawMoneyReply ToPB() const
	{
		BagRpcBagStorageDrawMoneyReply v;
		v.set_result( m_Result );
		v.set_money( m_Money );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagStorageDrawMoneyReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Money(钱数) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Money：%di</li>\r\n",m_Money);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagStorageDrawMoneyReply& v)
	{
		m_Result = v.result();
		m_Money = v.money();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//钱数
	INT32 m_Money;
public:
	void SetMoney( INT32 v)
	{
		m_Money=v;
	}
	INT32 GetMoney()
	{
		return m_Money;
	}
	INT32 GetMoney() const
	{
		return m_Money;
	}

};
//仓库整理请求封装类
class BagRpcStorageTidyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcStorageTidyAskWraper()
	{
		

	}
	//赋值构造函数
	BagRpcStorageTidyAskWraper(const BagRpcStorageTidyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcStorageTidyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcStorageTidyAsk ToPB() const
	{
		BagRpcStorageTidyAsk v;

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcStorageTidyAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcStorageTidyAsk& v)
	{

	}


};
//仓库取钱请求封装类
class BagRpcBagStorageDrawMoneyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagStorageDrawMoneyAskWraper()
	{
		
		m_Money = -1;

	}
	//赋值构造函数
	BagRpcBagStorageDrawMoneyAskWraper(const BagRpcBagStorageDrawMoneyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagStorageDrawMoneyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagStorageDrawMoneyAsk ToPB() const
	{
		BagRpcBagStorageDrawMoneyAsk v;
		v.set_money( m_Money );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagStorageDrawMoneyAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Money(钱数) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Money：%di</li>\r\n",m_Money);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagStorageDrawMoneyAsk& v)
	{
		m_Money = v.money();

	}

private:
	//钱数
	INT32 m_Money;
public:
	void SetMoney( INT32 v)
	{
		m_Money=v;
	}
	INT32 GetMoney()
	{
		return m_Money;
	}
	INT32 GetMoney() const
	{
		return m_Money;
	}

};
//仓库存钱请求封装类
class BagRpcBagStorageSaveMoneyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagStorageSaveMoneyAskWraper()
	{
		
		m_Money = -1;

	}
	//赋值构造函数
	BagRpcBagStorageSaveMoneyAskWraper(const BagRpcBagStorageSaveMoneyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagStorageSaveMoneyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagStorageSaveMoneyAsk ToPB() const
	{
		BagRpcBagStorageSaveMoneyAsk v;
		v.set_money( m_Money );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagStorageSaveMoneyAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Money(钱数) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Money：%di</li>\r\n",m_Money);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagStorageSaveMoneyAsk& v)
	{
		m_Money = v.money();

	}

private:
	//钱数
	INT32 m_Money;
public:
	void SetMoney( INT32 v)
	{
		m_Money=v;
	}
	INT32 GetMoney()
	{
		return m_Money;
	}
	INT32 GetMoney() const
	{
		return m_Money;
	}

};
//仓库存钱回应封装类
class BagRpcBagStorageSaveMoneyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagStorageSaveMoneyReplyWraper()
	{
		
		m_Result = -9999;
		m_Money = -1;

	}
	//赋值构造函数
	BagRpcBagStorageSaveMoneyReplyWraper(const BagRpcBagStorageSaveMoneyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagStorageSaveMoneyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagStorageSaveMoneyReply ToPB() const
	{
		BagRpcBagStorageSaveMoneyReply v;
		v.set_result( m_Result );
		v.set_money( m_Money );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagStorageSaveMoneyReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Money(钱数) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Money：%di</li>\r\n",m_Money);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagStorageSaveMoneyReply& v)
	{
		m_Result = v.result();
		m_Money = v.money();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//钱数
	INT32 m_Money;
public:
	void SetMoney( INT32 v)
	{
		m_Money=v;
	}
	INT32 GetMoney()
	{
		return m_Money;
	}
	INT32 GetMoney() const
	{
		return m_Money;
	}

};
//装备宝石槽位打孔请求封装类
class BagRpcEquipGemSlotUnlockAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipGemSlotUnlockAskWraper()
	{
		
		m_TemplateId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;
		m_SlotPos = -1;

	}
	//赋值构造函数
	BagRpcEquipGemSlotUnlockAskWraper(const BagRpcEquipGemSlotUnlockAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipGemSlotUnlockAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipGemSlotUnlockAsk ToPB() const
	{
		BagRpcEquipGemSlotUnlockAsk v;
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );
		v.set_slotpos( m_SlotPos );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipGemSlotUnlockAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateId(TemplateId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";
		htmlBuff += "<li>SlotPos(槽位位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SlotPos：%di</li>\r\n",m_SlotPos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipGemSlotUnlockAsk& v)
	{
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();
		m_SlotPos = v.slotpos();

	}

private:
	//TemplateId
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}
private:
	//槽位位置
	INT32 m_SlotPos;
public:
	void SetSlotPos( INT32 v)
	{
		m_SlotPos=v;
	}
	INT32 GetSlotPos()
	{
		return m_SlotPos;
	}
	INT32 GetSlotPos() const
	{
		return m_SlotPos;
	}

};
//装备宝石槽位打孔回应封装类
class BagRpcEquipGemSlotUnlockReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipGemSlotUnlockReplyWraper()
	{
		
		m_Result = -9999;
		m_TemplateId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;
		m_SlotPos = -1;

	}
	//赋值构造函数
	BagRpcEquipGemSlotUnlockReplyWraper(const BagRpcEquipGemSlotUnlockReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipGemSlotUnlockReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipGemSlotUnlockReply ToPB() const
	{
		BagRpcEquipGemSlotUnlockReply v;
		v.set_result( m_Result );
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );
		v.set_slotpos( m_SlotPos );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipGemSlotUnlockReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TemplateId(TemplateId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";
		htmlBuff += "<li>SlotPos(槽位位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SlotPos：%di</li>\r\n",m_SlotPos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipGemSlotUnlockReply& v)
	{
		m_Result = v.result();
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();
		m_SlotPos = v.slotpos();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//TemplateId
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}
private:
	//槽位位置
	INT32 m_SlotPos;
public:
	void SetSlotPos( INT32 v)
	{
		m_SlotPos=v;
	}
	INT32 GetSlotPos()
	{
		return m_SlotPos;
	}
	INT32 GetSlotPos() const
	{
		return m_SlotPos;
	}

};
//宝石镶嵌请求封装类
class BagRpcEquipInlayGemAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipInlayGemAskWraper()
	{
		
		m_TemplateId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;
		m_SlotPos = -1;
		m_GemId = -1;
		m_GemPos = -1;

	}
	//赋值构造函数
	BagRpcEquipInlayGemAskWraper(const BagRpcEquipInlayGemAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipInlayGemAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipInlayGemAsk ToPB() const
	{
		BagRpcEquipInlayGemAsk v;
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );
		v.set_slotpos( m_SlotPos );
		v.set_gemid( m_GemId );
		v.set_gempos( m_GemPos );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipInlayGemAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateId(TemplateId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";
		htmlBuff += "<li>SlotPos(槽位位置) [sint32]</li>\r\n";
		htmlBuff += "<li>GemId(宝石id) [sint32]</li>\r\n";
		htmlBuff += "<li>GemPos(在背包中的位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SlotPos：%di</li>\r\n",m_SlotPos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GemId：%di</li>\r\n",m_GemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GemPos：%di</li>\r\n",m_GemPos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipInlayGemAsk& v)
	{
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();
		m_SlotPos = v.slotpos();
		m_GemId = v.gemid();
		m_GemPos = v.gempos();

	}

private:
	//TemplateId
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}
private:
	//槽位位置
	INT32 m_SlotPos;
public:
	void SetSlotPos( INT32 v)
	{
		m_SlotPos=v;
	}
	INT32 GetSlotPos()
	{
		return m_SlotPos;
	}
	INT32 GetSlotPos() const
	{
		return m_SlotPos;
	}
private:
	//宝石id
	INT32 m_GemId;
public:
	void SetGemId( INT32 v)
	{
		m_GemId=v;
	}
	INT32 GetGemId()
	{
		return m_GemId;
	}
	INT32 GetGemId() const
	{
		return m_GemId;
	}
private:
	//在背包中的位置
	INT32 m_GemPos;
public:
	void SetGemPos( INT32 v)
	{
		m_GemPos=v;
	}
	INT32 GetGemPos()
	{
		return m_GemPos;
	}
	INT32 GetGemPos() const
	{
		return m_GemPos;
	}

};
//宝石镶嵌回应封装类
class BagRpcEquipInlayGemReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipInlayGemReplyWraper()
	{
		
		m_Result = -9999;
		m_TemplateId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;
		m_SlotPos = -1;
		m_GemId = -1;
		m_GemPos = -1;

	}
	//赋值构造函数
	BagRpcEquipInlayGemReplyWraper(const BagRpcEquipInlayGemReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipInlayGemReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipInlayGemReply ToPB() const
	{
		BagRpcEquipInlayGemReply v;
		v.set_result( m_Result );
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );
		v.set_slotpos( m_SlotPos );
		v.set_gemid( m_GemId );
		v.set_gempos( m_GemPos );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipInlayGemReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TemplateId(TemplateId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";
		htmlBuff += "<li>SlotPos(槽位位置) [sint32]</li>\r\n";
		htmlBuff += "<li>GemId(宝石id) [sint32]</li>\r\n";
		htmlBuff += "<li>GemPos(在背包中的位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SlotPos：%di</li>\r\n",m_SlotPos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GemId：%di</li>\r\n",m_GemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GemPos：%di</li>\r\n",m_GemPos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipInlayGemReply& v)
	{
		m_Result = v.result();
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();
		m_SlotPos = v.slotpos();
		m_GemId = v.gemid();
		m_GemPos = v.gempos();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//TemplateId
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}
private:
	//槽位位置
	INT32 m_SlotPos;
public:
	void SetSlotPos( INT32 v)
	{
		m_SlotPos=v;
	}
	INT32 GetSlotPos()
	{
		return m_SlotPos;
	}
	INT32 GetSlotPos() const
	{
		return m_SlotPos;
	}
private:
	//宝石id
	INT32 m_GemId;
public:
	void SetGemId( INT32 v)
	{
		m_GemId=v;
	}
	INT32 GetGemId()
	{
		return m_GemId;
	}
	INT32 GetGemId() const
	{
		return m_GemId;
	}
private:
	//在背包中的位置
	INT32 m_GemPos;
public:
	void SetGemPos( INT32 v)
	{
		m_GemPos=v;
	}
	INT32 GetGemPos()
	{
		return m_GemPos;
	}
	INT32 GetGemPos() const
	{
		return m_GemPos;
	}

};
//装备强化转移请求封装类
class BagRpcEquipEnhanceSwapAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipEnhanceSwapAskWraper()
	{
		
		m_TemplateId1 = -1;
		m_Pos1 = -1;
		m_TemplateId2 = -1;
		m_Pos2 = -1;
		m_BagContainerType1 = -1;
		m_BagContainerType2 = -1;

	}
	//赋值构造函数
	BagRpcEquipEnhanceSwapAskWraper(const BagRpcEquipEnhanceSwapAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipEnhanceSwapAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipEnhanceSwapAsk ToPB() const
	{
		BagRpcEquipEnhanceSwapAsk v;
		v.set_templateid1( m_TemplateId1 );
		v.set_pos1( m_Pos1 );
		v.set_templateid2( m_TemplateId2 );
		v.set_pos2( m_Pos2 );
		v.set_bagcontainertype1( m_BagContainerType1 );
		v.set_bagcontainertype2( m_BagContainerType2 );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipEnhanceSwapAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateId1(TemplateId1) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos1(道具位置1) [sint32]</li>\r\n";
		htmlBuff += "<li>TemplateId2(TemplateId2) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos2(道具位置2) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType1(背包容器类型1) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType2(背包容器类型2) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateId1：%di</li>\r\n",m_TemplateId1);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos1：%di</li>\r\n",m_Pos1);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId2：%di</li>\r\n",m_TemplateId2);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos2：%di</li>\r\n",m_Pos2);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType1：%di</li>\r\n",m_BagContainerType1);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType2：%di</li>\r\n",m_BagContainerType2);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipEnhanceSwapAsk& v)
	{
		m_TemplateId1 = v.templateid1();
		m_Pos1 = v.pos1();
		m_TemplateId2 = v.templateid2();
		m_Pos2 = v.pos2();
		m_BagContainerType1 = v.bagcontainertype1();
		m_BagContainerType2 = v.bagcontainertype2();

	}

private:
	//TemplateId1
	INT32 m_TemplateId1;
public:
	void SetTemplateId1( INT32 v)
	{
		m_TemplateId1=v;
	}
	INT32 GetTemplateId1()
	{
		return m_TemplateId1;
	}
	INT32 GetTemplateId1() const
	{
		return m_TemplateId1;
	}
private:
	//道具位置1
	INT32 m_Pos1;
public:
	void SetPos1( INT32 v)
	{
		m_Pos1=v;
	}
	INT32 GetPos1()
	{
		return m_Pos1;
	}
	INT32 GetPos1() const
	{
		return m_Pos1;
	}
private:
	//TemplateId2
	INT32 m_TemplateId2;
public:
	void SetTemplateId2( INT32 v)
	{
		m_TemplateId2=v;
	}
	INT32 GetTemplateId2()
	{
		return m_TemplateId2;
	}
	INT32 GetTemplateId2() const
	{
		return m_TemplateId2;
	}
private:
	//道具位置2
	INT32 m_Pos2;
public:
	void SetPos2( INT32 v)
	{
		m_Pos2=v;
	}
	INT32 GetPos2()
	{
		return m_Pos2;
	}
	INT32 GetPos2() const
	{
		return m_Pos2;
	}
private:
	//背包容器类型1
	INT32 m_BagContainerType1;
public:
	void SetBagContainerType1( INT32 v)
	{
		m_BagContainerType1=v;
	}
	INT32 GetBagContainerType1()
	{
		return m_BagContainerType1;
	}
	INT32 GetBagContainerType1() const
	{
		return m_BagContainerType1;
	}
private:
	//背包容器类型2
	INT32 m_BagContainerType2;
public:
	void SetBagContainerType2( INT32 v)
	{
		m_BagContainerType2=v;
	}
	INT32 GetBagContainerType2()
	{
		return m_BagContainerType2;
	}
	INT32 GetBagContainerType2() const
	{
		return m_BagContainerType2;
	}

};
//装备宝石移除回应封装类
class BagRpcEquipGemRemoveReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipGemRemoveReplyWraper()
	{
		
		m_Result = -9999;
		m_TemplateId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;
		m_SlotPos = -1;

	}
	//赋值构造函数
	BagRpcEquipGemRemoveReplyWraper(const BagRpcEquipGemRemoveReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipGemRemoveReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipGemRemoveReply ToPB() const
	{
		BagRpcEquipGemRemoveReply v;
		v.set_result( m_Result );
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );
		v.set_slotpos( m_SlotPos );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipGemRemoveReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TemplateId(TemplateId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";
		htmlBuff += "<li>SlotPos(槽位位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SlotPos：%di</li>\r\n",m_SlotPos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipGemRemoveReply& v)
	{
		m_Result = v.result();
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();
		m_SlotPos = v.slotpos();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//TemplateId
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}
private:
	//槽位位置
	INT32 m_SlotPos;
public:
	void SetSlotPos( INT32 v)
	{
		m_SlotPos=v;
	}
	INT32 GetSlotPos()
	{
		return m_SlotPos;
	}
	INT32 GetSlotPos() const
	{
		return m_SlotPos;
	}

};
//存入仓库请求封装类
class BagRpcBagPutInStorageAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagPutInStorageAskWraper()
	{
		
		m_TemplateId = -1;
		m_Pos = -1;
		m_Num = -1;

	}
	//赋值构造函数
	BagRpcBagPutInStorageAskWraper(const BagRpcBagPutInStorageAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagPutInStorageAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagPutInStorageAsk ToPB() const
	{
		BagRpcBagPutInStorageAsk v;
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_num( m_Num );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagPutInStorageAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateId(物品模板id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(拆分出来的数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagPutInStorageAsk& v)
	{
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_Num = v.num();

	}

private:
	//物品模板id
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//拆分出来的数量
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}

};
//装备强化转移回应封装类
class BagRpcEquipEnhanceSwapReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipEnhanceSwapReplyWraper()
	{
		
		m_Result = -9999;
		m_TemplateId1 = -1;
		m_Pos1 = -1;
		m_TemplateId2 = -1;
		m_Pos2 = -1;
		m_BagContainerType1 = -1;
		m_BagContainerType2 = -1;

	}
	//赋值构造函数
	BagRpcEquipEnhanceSwapReplyWraper(const BagRpcEquipEnhanceSwapReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipEnhanceSwapReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipEnhanceSwapReply ToPB() const
	{
		BagRpcEquipEnhanceSwapReply v;
		v.set_result( m_Result );
		v.set_templateid1( m_TemplateId1 );
		v.set_pos1( m_Pos1 );
		v.set_templateid2( m_TemplateId2 );
		v.set_pos2( m_Pos2 );
		v.set_bagcontainertype1( m_BagContainerType1 );
		v.set_bagcontainertype2( m_BagContainerType2 );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipEnhanceSwapReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TemplateId1(TemplateId1) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos1(道具位置1) [sint32]</li>\r\n";
		htmlBuff += "<li>TemplateId2(TemplateId2) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos2(道具位置2) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType1(背包容器类型1) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType2(背包容器类型2) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId1：%di</li>\r\n",m_TemplateId1);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos1：%di</li>\r\n",m_Pos1);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId2：%di</li>\r\n",m_TemplateId2);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos2：%di</li>\r\n",m_Pos2);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType1：%di</li>\r\n",m_BagContainerType1);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType2：%di</li>\r\n",m_BagContainerType2);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipEnhanceSwapReply& v)
	{
		m_Result = v.result();
		m_TemplateId1 = v.templateid1();
		m_Pos1 = v.pos1();
		m_TemplateId2 = v.templateid2();
		m_Pos2 = v.pos2();
		m_BagContainerType1 = v.bagcontainertype1();
		m_BagContainerType2 = v.bagcontainertype2();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//TemplateId1
	INT32 m_TemplateId1;
public:
	void SetTemplateId1( INT32 v)
	{
		m_TemplateId1=v;
	}
	INT32 GetTemplateId1()
	{
		return m_TemplateId1;
	}
	INT32 GetTemplateId1() const
	{
		return m_TemplateId1;
	}
private:
	//道具位置1
	INT32 m_Pos1;
public:
	void SetPos1( INT32 v)
	{
		m_Pos1=v;
	}
	INT32 GetPos1()
	{
		return m_Pos1;
	}
	INT32 GetPos1() const
	{
		return m_Pos1;
	}
private:
	//TemplateId2
	INT32 m_TemplateId2;
public:
	void SetTemplateId2( INT32 v)
	{
		m_TemplateId2=v;
	}
	INT32 GetTemplateId2()
	{
		return m_TemplateId2;
	}
	INT32 GetTemplateId2() const
	{
		return m_TemplateId2;
	}
private:
	//道具位置2
	INT32 m_Pos2;
public:
	void SetPos2( INT32 v)
	{
		m_Pos2=v;
	}
	INT32 GetPos2()
	{
		return m_Pos2;
	}
	INT32 GetPos2() const
	{
		return m_Pos2;
	}
private:
	//背包容器类型1
	INT32 m_BagContainerType1;
public:
	void SetBagContainerType1( INT32 v)
	{
		m_BagContainerType1=v;
	}
	INT32 GetBagContainerType1()
	{
		return m_BagContainerType1;
	}
	INT32 GetBagContainerType1() const
	{
		return m_BagContainerType1;
	}
private:
	//背包容器类型2
	INT32 m_BagContainerType2;
public:
	void SetBagContainerType2( INT32 v)
	{
		m_BagContainerType2=v;
	}
	INT32 GetBagContainerType2()
	{
		return m_BagContainerType2;
	}
	INT32 GetBagContainerType2() const
	{
		return m_BagContainerType2;
	}

};
//装备宝石移除请求封装类
class BagRpcEquipGemRemoveAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipGemRemoveAskWraper()
	{
		
		m_TemplateId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;
		m_SlotPos = -1;

	}
	//赋值构造函数
	BagRpcEquipGemRemoveAskWraper(const BagRpcEquipGemRemoveAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipGemRemoveAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipGemRemoveAsk ToPB() const
	{
		BagRpcEquipGemRemoveAsk v;
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );
		v.set_slotpos( m_SlotPos );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipGemRemoveAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateId(TemplateId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";
		htmlBuff += "<li>SlotPos(槽位位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SlotPos：%di</li>\r\n",m_SlotPos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipGemRemoveAsk& v)
	{
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();
		m_SlotPos = v.slotpos();

	}

private:
	//TemplateId
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}
private:
	//槽位位置
	INT32 m_SlotPos;
public:
	void SetSlotPos( INT32 v)
	{
		m_SlotPos=v;
	}
	INT32 GetSlotPos()
	{
		return m_SlotPos;
	}
	INT32 GetSlotPos() const
	{
		return m_SlotPos;
	}

};
//炼星请求封装类
class BagRpcTalismanRefindStarAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcTalismanRefindStarAskWraper()
	{
		
		m_FabaoId = -1;

	}
	//赋值构造函数
	BagRpcTalismanRefindStarAskWraper(const BagRpcTalismanRefindStarAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTalismanRefindStarAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTalismanRefindStarAsk ToPB() const
	{
		BagRpcTalismanRefindStarAsk v;
		v.set_fabaoid( m_FabaoId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcTalismanRefindStarAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>FabaoId(法宝实例Id) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>FabaoId：%lldL</li>\r\n",m_FabaoId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcTalismanRefindStarAsk& v)
	{
		m_FabaoId = v.fabaoid();

	}

private:
	//法宝实例Id
	INT64 m_FabaoId;
public:
	void SetFabaoId( INT64 v)
	{
		m_FabaoId=v;
	}
	INT64 GetFabaoId()
	{
		return m_FabaoId;
	}
	INT64 GetFabaoId() const
	{
		return m_FabaoId;
	}

};
//炼星回应封装类
class BagRpcTalismanRefindStarReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcTalismanRefindStarReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BagRpcTalismanRefindStarReplyWraper(const BagRpcTalismanRefindStarReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTalismanRefindStarReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTalismanRefindStarReply ToPB() const
	{
		BagRpcTalismanRefindStarReply v;
		v.set_result( m_Result );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcTalismanRefindStarReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcTalismanRefindStarReply& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//获得新物品通知封装类
class BagRpcGetNewItemNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcGetNewItemNotifyWraper()
	{
		
		m_ModuleId = -1;
		m_PathWayId = -1;
		m_ModuleParam = -1;

	}
	//赋值构造函数
	BagRpcGetNewItemNotifyWraper(const BagRpcGetNewItemNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcGetNewItemNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcGetNewItemNotify ToPB() const
	{
		BagRpcGetNewItemNotify v;
		v.mutable_item()->Reserve(m_Item.size());
		for (int i=0; i<(int)m_Item.size(); i++)
		{
			*v.add_item() = m_Item[i].ToPB();
		}
		v.set_moduleid( m_ModuleId );
		v.set_pathwayid( m_PathWayId );
		v.set_moduleparam( m_ModuleParam );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcGetNewItemNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Item(物品) [KeyValue2IntInt] Array</li>\r\n";
		htmlBuff += "<li>ModuleId(模块Id) [sint32]</li>\r\n";
		htmlBuff += "<li>PathWayId(获得途径Id) [sint32]</li>\r\n";
		htmlBuff += "<li>ModuleParam(模块参数) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>Item：</li>\r\n";
		if( m_Item.size()>0) htmlBuff += m_Item[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_Item.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_Item[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>ModuleId：%di</li>\r\n",m_ModuleId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PathWayId：%di</li>\r\n",m_PathWayId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ModuleParam：%di</li>\r\n",m_ModuleParam);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcGetNewItemNotify& v)
	{
		m_Item.clear();
		m_Item.reserve(v.item_size());
		for( int i=0; i<v.item_size(); i++)
			m_Item.push_back(v.item(i));
		m_ModuleId = v.moduleid();
		m_PathWayId = v.pathwayid();
		m_ModuleParam = v.moduleparam();

	}

private:
	//物品
	vector<KeyValue2IntIntWraper> m_Item;
public:
	int SizeItem()
	{
		return m_Item.size();
	}
	const vector<KeyValue2IntIntWraper>& GetItem() const
	{
		return m_Item;
	}
	KeyValue2IntIntWraper GetItem(int Index) const
	{
		if(Index<0 || Index>=(int)m_Item.size())
		{
			assert(false);
			return KeyValue2IntIntWraper();
		}
		return m_Item[Index];
	}
	void SetItem( const vector<KeyValue2IntIntWraper>& v )
	{
		m_Item=v;
	}
	void ClearItem( )
	{
		m_Item.clear();
	}
	void SetItem( int Index, const KeyValue2IntIntWraper& v )
	{
		if(Index<0 || Index>=(int)m_Item.size())
		{
			assert(false);
			return;
		}
		m_Item[Index] = v;
	}
	void AddItem( const KeyValue2IntIntWraper& v )
	{
		m_Item.push_back(v);
	}
private:
	//模块Id
	INT32 m_ModuleId;
public:
	void SetModuleId( INT32 v)
	{
		m_ModuleId=v;
	}
	INT32 GetModuleId()
	{
		return m_ModuleId;
	}
	INT32 GetModuleId() const
	{
		return m_ModuleId;
	}
private:
	//获得途径Id
	INT32 m_PathWayId;
public:
	void SetPathWayId( INT32 v)
	{
		m_PathWayId=v;
	}
	INT32 GetPathWayId()
	{
		return m_PathWayId;
	}
	INT32 GetPathWayId() const
	{
		return m_PathWayId;
	}
private:
	//模块参数
	INT32 m_ModuleParam;
public:
	void SetModuleParam( INT32 v)
	{
		m_ModuleParam=v;
	}
	INT32 GetModuleParam()
	{
		return m_ModuleParam;
	}
	INT32 GetModuleParam() const
	{
		return m_ModuleParam;
	}

};
//背包错误通知封装类
class BagRpcBagErrorNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagErrorNotifyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BagRpcBagErrorNotifyWraper(const BagRpcBagErrorNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagErrorNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagErrorNotify ToPB() const
	{
		BagRpcBagErrorNotify v;
		v.set_result( m_Result );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagErrorNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagErrorNotify& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//升级聚灵槽位技能请求封装类
class BagRpcTalismanUpSlotSkillLevelAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcTalismanUpSlotSkillLevelAskWraper()
	{
		
		m_FabaoId = -1;
		m_SlotId = -1;

	}
	//赋值构造函数
	BagRpcTalismanUpSlotSkillLevelAskWraper(const BagRpcTalismanUpSlotSkillLevelAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTalismanUpSlotSkillLevelAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTalismanUpSlotSkillLevelAsk ToPB() const
	{
		BagRpcTalismanUpSlotSkillLevelAsk v;
		v.set_fabaoid( m_FabaoId );
		v.set_slotid( m_SlotId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcTalismanUpSlotSkillLevelAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>FabaoId(法宝实例ID) [sint64]</li>\r\n";
		htmlBuff += "<li>SlotId(聚灵槽位Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>FabaoId：%lldL</li>\r\n",m_FabaoId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SlotId：%di</li>\r\n",m_SlotId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcTalismanUpSlotSkillLevelAsk& v)
	{
		m_FabaoId = v.fabaoid();
		m_SlotId = v.slotid();

	}

private:
	//法宝实例ID
	INT64 m_FabaoId;
public:
	void SetFabaoId( INT64 v)
	{
		m_FabaoId=v;
	}
	INT64 GetFabaoId()
	{
		return m_FabaoId;
	}
	INT64 GetFabaoId() const
	{
		return m_FabaoId;
	}
private:
	//聚灵槽位Id
	INT32 m_SlotId;
public:
	void SetSlotId( INT32 v)
	{
		m_SlotId=v;
	}
	INT32 GetSlotId()
	{
		return m_SlotId;
	}
	INT32 GetSlotId() const
	{
		return m_SlotId;
	}

};
//宝石聚灵请求封装类
class BagRpcTalismanGatherSpriteAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcTalismanGatherSpriteAskWraper()
	{
		
		m_FabaoId = -1;
		m_GatherSpriteId = -1;
		m_SlotId = -1;

	}
	//赋值构造函数
	BagRpcTalismanGatherSpriteAskWraper(const BagRpcTalismanGatherSpriteAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTalismanGatherSpriteAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTalismanGatherSpriteAsk ToPB() const
	{
		BagRpcTalismanGatherSpriteAsk v;
		v.set_fabaoid( m_FabaoId );
		v.set_gatherspriteid( m_GatherSpriteId );
		v.set_slotid( m_SlotId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcTalismanGatherSpriteAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>FabaoId(法宝Id) [sint64]</li>\r\n";
		htmlBuff += "<li>GatherSpriteId(聚灵技能Id) [sint32]</li>\r\n";
		htmlBuff += "<li>SlotId(聚灵槽位ID) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>FabaoId：%lldL</li>\r\n",m_FabaoId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GatherSpriteId：%di</li>\r\n",m_GatherSpriteId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SlotId：%di</li>\r\n",m_SlotId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcTalismanGatherSpriteAsk& v)
	{
		m_FabaoId = v.fabaoid();
		m_GatherSpriteId = v.gatherspriteid();
		m_SlotId = v.slotid();

	}

private:
	//法宝Id
	INT64 m_FabaoId;
public:
	void SetFabaoId( INT64 v)
	{
		m_FabaoId=v;
	}
	INT64 GetFabaoId()
	{
		return m_FabaoId;
	}
	INT64 GetFabaoId() const
	{
		return m_FabaoId;
	}
private:
	//聚灵技能Id
	INT32 m_GatherSpriteId;
public:
	void SetGatherSpriteId( INT32 v)
	{
		m_GatherSpriteId=v;
	}
	INT32 GetGatherSpriteId()
	{
		return m_GatherSpriteId;
	}
	INT32 GetGatherSpriteId() const
	{
		return m_GatherSpriteId;
	}
private:
	//聚灵槽位ID
	INT32 m_SlotId;
public:
	void SetSlotId( INT32 v)
	{
		m_SlotId=v;
	}
	INT32 GetSlotId()
	{
		return m_SlotId;
	}
	INT32 GetSlotId() const
	{
		return m_SlotId;
	}

};
//宝石聚灵回应封装类
class BagRpcTalismanGatherSpriteReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcTalismanGatherSpriteReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BagRpcTalismanGatherSpriteReplyWraper(const BagRpcTalismanGatherSpriteReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTalismanGatherSpriteReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTalismanGatherSpriteReply ToPB() const
	{
		BagRpcTalismanGatherSpriteReply v;
		v.set_result( m_Result );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcTalismanGatherSpriteReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcTalismanGatherSpriteReply& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//升级聚灵槽位技能回应封装类
class BagRpcTalismanUpSlotSkillLevelReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcTalismanUpSlotSkillLevelReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BagRpcTalismanUpSlotSkillLevelReplyWraper(const BagRpcTalismanUpSlotSkillLevelReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTalismanUpSlotSkillLevelReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTalismanUpSlotSkillLevelReply ToPB() const
	{
		BagRpcTalismanUpSlotSkillLevelReply v;
		v.set_result( m_Result );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcTalismanUpSlotSkillLevelReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcTalismanUpSlotSkillLevelReply& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//属性变化通知通知封装类
class BagRpcTalismanAttrChangeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcTalismanAttrChangeNotifyWraper()
	{
		

	}
	//赋值构造函数
	BagRpcTalismanAttrChangeNotifyWraper(const BagRpcTalismanAttrChangeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTalismanAttrChangeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTalismanAttrChangeNotify ToPB() const
	{
		BagRpcTalismanAttrChangeNotify v;
		v.mutable_attr()->Reserve(m_Attr.size());
		for (int i=0; i<(int)m_Attr.size(); i++)
		{
			*v.add_attr() = m_Attr[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcTalismanAttrChangeNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Attr(属性值) [KeyValue2IntInt] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>Attr：</li>\r\n";
		if( m_Attr.size()>0) htmlBuff += m_Attr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_Attr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_Attr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcTalismanAttrChangeNotify& v)
	{
		m_Attr.clear();
		m_Attr.reserve(v.attr_size());
		for( int i=0; i<v.attr_size(); i++)
			m_Attr.push_back(v.attr(i));

	}

private:
	//属性值
	vector<KeyValue2IntIntWraper> m_Attr;
public:
	int SizeAttr()
	{
		return m_Attr.size();
	}
	const vector<KeyValue2IntIntWraper>& GetAttr() const
	{
		return m_Attr;
	}
	KeyValue2IntIntWraper GetAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_Attr.size())
		{
			assert(false);
			return KeyValue2IntIntWraper();
		}
		return m_Attr[Index];
	}
	void SetAttr( const vector<KeyValue2IntIntWraper>& v )
	{
		m_Attr=v;
	}
	void ClearAttr( )
	{
		m_Attr.clear();
	}
	void SetAttr( int Index, const KeyValue2IntIntWraper& v )
	{
		if(Index<0 || Index>=(int)m_Attr.size())
		{
			assert(false);
			return;
		}
		m_Attr[Index] = v;
	}
	void AddAttr( const KeyValue2IntIntWraper& v )
	{
		m_Attr.push_back(v);
	}

};
//法宝铸炼回应封装类
class BagRpcTalismanLvupReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcTalismanLvupReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BagRpcTalismanLvupReplyWraper(const BagRpcTalismanLvupReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTalismanLvupReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTalismanLvupReply ToPB() const
	{
		BagRpcTalismanLvupReply v;
		v.set_result( m_Result );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcTalismanLvupReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcTalismanLvupReply& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//法宝传承请求封装类
class BagRpcTalismanInheritAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcTalismanInheritAskWraper()
	{
		
		m_RightSideTalisman = -1;

	}
	//赋值构造函数
	BagRpcTalismanInheritAskWraper(const BagRpcTalismanInheritAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTalismanInheritAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTalismanInheritAsk ToPB() const
	{
		BagRpcTalismanInheritAsk v;
		v.set_rightsidetalisman( m_RightSideTalisman );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcTalismanInheritAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>RightSideTalisman(材料法宝在背包的位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>RightSideTalisman：%di</li>\r\n",m_RightSideTalisman);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcTalismanInheritAsk& v)
	{
		m_RightSideTalisman = v.rightsidetalisman();

	}

private:
	//材料法宝在背包的位置
	INT32 m_RightSideTalisman;
public:
	void SetRightSideTalisman( INT32 v)
	{
		m_RightSideTalisman=v;
	}
	INT32 GetRightSideTalisman()
	{
		return m_RightSideTalisman;
	}
	INT32 GetRightSideTalisman() const
	{
		return m_RightSideTalisman;
	}

};
//仓库整理回应封装类
class BagRpcStorageTidyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcStorageTidyReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BagRpcStorageTidyReplyWraper(const BagRpcStorageTidyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcStorageTidyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcStorageTidyReply ToPB() const
	{
		BagRpcStorageTidyReply v;
		v.set_result( m_Result );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcStorageTidyReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcStorageTidyReply& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//法宝铸炼请求封装类
class BagRpcTalismanLvupAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcTalismanLvupAskWraper()
	{
		

	}
	//赋值构造函数
	BagRpcTalismanLvupAskWraper(const BagRpcTalismanLvupAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTalismanLvupAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTalismanLvupAsk ToPB() const
	{
		BagRpcTalismanLvupAsk v;
		v.mutable_costtalisman()->Reserve(m_CostTalisman.size());
		for (int i=0; i<(int)m_CostTalisman.size(); i++)
		{
			v.add_costtalisman(m_CostTalisman[i]);
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcTalismanLvupAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>CostTalisman(材料法宝在背包中的位置) [sint32] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>CostTalisman：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_CostTalisman.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_CostTalisman[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_CostTalisman.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcTalismanLvupAsk& v)
	{
		m_CostTalisman.clear();
		m_CostTalisman.reserve(v.costtalisman_size());
		for( int i=0; i<v.costtalisman_size(); i++)
			m_CostTalisman.push_back(v.costtalisman(i));

	}

private:
	//材料法宝在背包中的位置
	vector<INT32> m_CostTalisman;
public:
	int SizeCostTalisman()
	{
		return m_CostTalisman.size();
	}
	const vector<INT32>& GetCostTalisman() const
	{
		return m_CostTalisman;
	}
	INT32 GetCostTalisman(int Index) const
	{
		if(Index<0 || Index>=(int)m_CostTalisman.size())
		{
			assert(false);
			return INT32();
		}
		return m_CostTalisman[Index];
	}
	void SetCostTalisman( const vector<INT32>& v )
	{
		m_CostTalisman=v;
	}
	void ClearCostTalisman( )
	{
		m_CostTalisman.clear();
	}
	void SetCostTalisman( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_CostTalisman.size())
		{
			assert(false);
			return;
		}
		m_CostTalisman[Index] = v;
	}
	void AddCostTalisman( INT32 v = -1 )
	{
		m_CostTalisman.push_back(v);
	}

};
//法宝传承回应封装类
class BagRpcTalismanInheritReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcTalismanInheritReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BagRpcTalismanInheritReplyWraper(const BagRpcTalismanInheritReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTalismanInheritReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTalismanInheritReply ToPB() const
	{
		BagRpcTalismanInheritReply v;
		v.set_result( m_Result );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcTalismanInheritReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcTalismanInheritReply& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//设置自动拾取请求封装类
class BagRpcBagSetAutoPickupAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagSetAutoPickupAskWraper()
	{
		

	}
	//赋值构造函数
	BagRpcBagSetAutoPickupAskWraper(const BagRpcBagSetAutoPickupAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagSetAutoPickupAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagSetAutoPickupAsk ToPB() const
	{
		BagRpcBagSetAutoPickupAsk v;
		v.mutable_autopick()->Reserve(m_AutoPick.size());
		for (int i=0; i<(int)m_AutoPick.size(); i++)
		{
			*v.add_autopick() = m_AutoPick[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagSetAutoPickupAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>AutoPick(自动拾取) [KeyValue2IntBool] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>AutoPick：</li>\r\n";
		if( m_AutoPick.size()>0) htmlBuff += m_AutoPick[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_AutoPick.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_AutoPick[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagSetAutoPickupAsk& v)
	{
		m_AutoPick.clear();
		m_AutoPick.reserve(v.autopick_size());
		for( int i=0; i<v.autopick_size(); i++)
			m_AutoPick.push_back(v.autopick(i));

	}

private:
	//自动拾取
	vector<KeyValue2IntBoolWraper> m_AutoPick;
public:
	int SizeAutoPick()
	{
		return m_AutoPick.size();
	}
	const vector<KeyValue2IntBoolWraper>& GetAutoPick() const
	{
		return m_AutoPick;
	}
	KeyValue2IntBoolWraper GetAutoPick(int Index) const
	{
		if(Index<0 || Index>=(int)m_AutoPick.size())
		{
			assert(false);
			return KeyValue2IntBoolWraper();
		}
		return m_AutoPick[Index];
	}
	void SetAutoPick( const vector<KeyValue2IntBoolWraper>& v )
	{
		m_AutoPick=v;
	}
	void ClearAutoPick( )
	{
		m_AutoPick.clear();
	}
	void SetAutoPick( int Index, const KeyValue2IntBoolWraper& v )
	{
		if(Index<0 || Index>=(int)m_AutoPick.size())
		{
			assert(false);
			return;
		}
		m_AutoPick[Index] = v;
	}
	void AddAutoPick( const KeyValue2IntBoolWraper& v )
	{
		m_AutoPick.push_back(v);
	}

};
//设置自动拾取回应封装类
class BagRpcBagSetAutoPickupReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagSetAutoPickupReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BagRpcBagSetAutoPickupReplyWraper(const BagRpcBagSetAutoPickupReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagSetAutoPickupReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagSetAutoPickupReply ToPB() const
	{
		BagRpcBagSetAutoPickupReply v;
		v.set_result( m_Result );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagSetAutoPickupReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagSetAutoPickupReply& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//背包获得新物品通知封装类
class BagRpcBagAddNewItemNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagAddNewItemNotifyWraper()
	{
		

	}
	//赋值构造函数
	BagRpcBagAddNewItemNotifyWraper(const BagRpcBagAddNewItemNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagAddNewItemNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagAddNewItemNotify ToPB() const
	{
		BagRpcBagAddNewItemNotify v;
		v.mutable_newitem()->Reserve(m_NewItem.size());
		for (int i=0; i<(int)m_NewItem.size(); i++)
		{
			*v.add_newitem() = m_NewItem[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagAddNewItemNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>NewItem(物品) [BagGridObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>NewItem：</li>\r\n";
		if( m_NewItem.size()>0) htmlBuff += m_NewItem[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_NewItem.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_NewItem[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagAddNewItemNotify& v)
	{
		m_NewItem.clear();
		m_NewItem.reserve(v.newitem_size());
		for( int i=0; i<v.newitem_size(); i++)
			m_NewItem.push_back(v.newitem(i));

	}

private:
	//物品
	vector<BagGridObjWraper> m_NewItem;
public:
	int SizeNewItem()
	{
		return m_NewItem.size();
	}
	const vector<BagGridObjWraper>& GetNewItem() const
	{
		return m_NewItem;
	}
	BagGridObjWraper GetNewItem(int Index) const
	{
		if(Index<0 || Index>=(int)m_NewItem.size())
		{
			assert(false);
			return BagGridObjWraper();
		}
		return m_NewItem[Index];
	}
	void SetNewItem( const vector<BagGridObjWraper>& v )
	{
		m_NewItem=v;
	}
	void ClearNewItem( )
	{
		m_NewItem.clear();
	}
	void SetNewItem( int Index, const BagGridObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_NewItem.size())
		{
			assert(false);
			return;
		}
		m_NewItem[Index] = v;
	}
	void AddNewItem( const BagGridObjWraper& v )
	{
		m_NewItem.push_back(v);
	}

};
//装备穿戴回应封装类
class BagRpcEquipWearReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipWearReplyWraper()
	{
		
		m_Result = -9999;
		m_ItemId = -1;
		m_BagPos = -1;

	}
	//赋值构造函数
	BagRpcEquipWearReplyWraper(const BagRpcEquipWearReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipWearReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipWearReply ToPB() const
	{
		BagRpcEquipWearReply v;
		v.set_result( m_Result );
		v.set_itemid( m_ItemId );
		v.set_bagpos( m_BagPos );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipWearReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemId(ItemId) [sint32]</li>\r\n";
		htmlBuff += "<li>BagPos(在背包中的位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemId：%di</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagPos：%di</li>\r\n",m_BagPos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipWearReply& v)
	{
		m_Result = v.result();
		m_ItemId = v.itemid();
		m_BagPos = v.bagpos();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//ItemId
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//在背包中的位置
	INT32 m_BagPos;
public:
	void SetBagPos( INT32 v)
	{
		m_BagPos=v;
	}
	INT32 GetBagPos()
	{
		return m_BagPos;
	}
	INT32 GetBagPos() const
	{
		return m_BagPos;
	}

};
//装备脱下请求封装类
class BagRpcEquipUndressAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipUndressAskWraper()
	{
		
		m_ItemId = -1;
		m_EquipPos = -1;

	}
	//赋值构造函数
	BagRpcEquipUndressAskWraper(const BagRpcEquipUndressAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipUndressAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipUndressAsk ToPB() const
	{
		BagRpcEquipUndressAsk v;
		v.set_itemid( m_ItemId );
		v.set_equippos( m_EquipPos );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipUndressAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ItemId(ItemId) [sint32]</li>\r\n";
		htmlBuff += "<li>EquipPos(选择的装备位) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ItemId：%di</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EquipPos：%di</li>\r\n",m_EquipPos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipUndressAsk& v)
	{
		m_ItemId = v.itemid();
		m_EquipPos = v.equippos();

	}

private:
	//ItemId
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//选择的装备位
	INT32 m_EquipPos;
public:
	void SetEquipPos( INT32 v)
	{
		m_EquipPos=v;
	}
	INT32 GetEquipPos()
	{
		return m_EquipPos;
	}
	INT32 GetEquipPos() const
	{
		return m_EquipPos;
	}

};
//物品使用回应封装类
class BagRpcUseReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcUseReplyWraper()
	{
		
		m_Result = -9999;
		m_Pos = -1;
		m_ItemID = -1;

	}
	//赋值构造函数
	BagRpcUseReplyWraper(const BagRpcUseReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcUseReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcUseReply ToPB() const
	{
		BagRpcUseReply v;
		v.set_result( m_Result );
		v.set_pos( m_Pos );
		v.set_itemid( m_ItemID );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcUseReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemID(物品id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemID：%di</li>\r\n",m_ItemID);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcUseReply& v)
	{
		m_Result = v.result();
		m_Pos = v.pos();
		m_ItemID = v.itemid();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//物品id
	INT32 m_ItemID;
public:
	void SetItemID( INT32 v)
	{
		m_ItemID=v;
	}
	INT32 GetItemID()
	{
		return m_ItemID;
	}
	INT32 GetItemID() const
	{
		return m_ItemID;
	}

};
//装备穿戴请求封装类
class BagRpcEquipWearAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipWearAskWraper()
	{
		
		m_ItemId = -1;
		m_BagPos = -1;

	}
	//赋值构造函数
	BagRpcEquipWearAskWraper(const BagRpcEquipWearAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipWearAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipWearAsk ToPB() const
	{
		BagRpcEquipWearAsk v;
		v.set_itemid( m_ItemId );
		v.set_bagpos( m_BagPos );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipWearAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ItemId(ItemId) [sint32]</li>\r\n";
		htmlBuff += "<li>BagPos(在背包中的位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ItemId：%di</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagPos：%di</li>\r\n",m_BagPos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipWearAsk& v)
	{
		m_ItemId = v.itemid();
		m_BagPos = v.bagpos();

	}

private:
	//ItemId
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//在背包中的位置
	INT32 m_BagPos;
public:
	void SetBagPos( INT32 v)
	{
		m_BagPos=v;
	}
	INT32 GetBagPos()
	{
		return m_BagPos;
	}
	INT32 GetBagPos() const
	{
		return m_BagPos;
	}

};
//装备脱下回应封装类
class BagRpcEquipUndressReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipUndressReplyWraper()
	{
		
		m_Result = -9999;
		m_ItemId = -1;
		m_EquipPos = -1;

	}
	//赋值构造函数
	BagRpcEquipUndressReplyWraper(const BagRpcEquipUndressReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipUndressReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipUndressReply ToPB() const
	{
		BagRpcEquipUndressReply v;
		v.set_result( m_Result );
		v.set_itemid( m_ItemId );
		v.set_equippos( m_EquipPos );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipUndressReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemId(ItemId) [sint32]</li>\r\n";
		htmlBuff += "<li>EquipPos(选择的装备位) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemId：%di</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EquipPos：%di</li>\r\n",m_EquipPos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipUndressReply& v)
	{
		m_Result = v.result();
		m_ItemId = v.itemid();
		m_EquipPos = v.equippos();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//ItemId
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//选择的装备位
	INT32 m_EquipPos;
public:
	void SetEquipPos( INT32 v)
	{
		m_EquipPos=v;
	}
	INT32 GetEquipPos()
	{
		return m_EquipPos;
	}
	INT32 GetEquipPos() const
	{
		return m_EquipPos;
	}

};
//装备洗炼请求封装类
class BagRpcEquipPolishedAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipPolishedAskWraper()
	{
		
		m_ItemId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;

	}
	//赋值构造函数
	BagRpcEquipPolishedAskWraper(const BagRpcEquipPolishedAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipPolishedAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipPolishedAsk ToPB() const
	{
		BagRpcEquipPolishedAsk v;
		v.set_itemid( m_ItemId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipPolishedAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ItemId(ItemId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ItemId：%di</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipPolishedAsk& v)
	{
		m_ItemId = v.itemid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();

	}

private:
	//ItemId
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}

};
//装备洗炼回应封装类
class BagRpcEquipPolishedReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipPolishedReplyWraper()
	{
		
		m_Result = -9999;
		m_ItemId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;

	}
	//赋值构造函数
	BagRpcEquipPolishedReplyWraper(const BagRpcEquipPolishedReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipPolishedReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipPolishedReply ToPB() const
	{
		BagRpcEquipPolishedReply v;
		v.set_result( m_Result );
		v.set_itemid( m_ItemId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipPolishedReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemId(ItemId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemId：%di</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipPolishedReply& v)
	{
		m_Result = v.result();
		m_ItemId = v.itemid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//ItemId
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}

};
//装备强化请求封装类
class BagRpcEquipEnhanceAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipEnhanceAskWraper()
	{
		
		m_ItemId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;
		m_Lv = -1;

	}
	//赋值构造函数
	BagRpcEquipEnhanceAskWraper(const BagRpcEquipEnhanceAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipEnhanceAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipEnhanceAsk ToPB() const
	{
		BagRpcEquipEnhanceAsk v;
		v.set_itemid( m_ItemId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );
		v.set_lv( m_Lv );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipEnhanceAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ItemId(ItemId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Lv(需要强化的等级) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ItemId：%di</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Lv：%di</li>\r\n",m_Lv);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipEnhanceAsk& v)
	{
		m_ItemId = v.itemid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();
		m_Lv = v.lv();

	}

private:
	//ItemId
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}
private:
	//需要强化的等级
	INT32 m_Lv;
public:
	void SetLv( INT32 v)
	{
		m_Lv=v;
	}
	INT32 GetLv()
	{
		return m_Lv;
	}
	INT32 GetLv() const
	{
		return m_Lv;
	}

};
//装备强化回应封装类
class BagRpcEquipEnhanceReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipEnhanceReplyWraper()
	{
		
		m_Result = -9999;
		m_ItemId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;
		m_Lv = -1;
		m_IsFirstEnhance = false;

	}
	//赋值构造函数
	BagRpcEquipEnhanceReplyWraper(const BagRpcEquipEnhanceReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipEnhanceReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipEnhanceReply ToPB() const
	{
		BagRpcEquipEnhanceReply v;
		v.set_result( m_Result );
		v.set_itemid( m_ItemId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );
		v.set_lv( m_Lv );
		v.set_isfirstenhance( m_IsFirstEnhance );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipEnhanceReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemId(ItemId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Lv(需要强化的等级) [sint32]</li>\r\n";
		htmlBuff += "<li>IsFirstEnhance(是否第一次强化) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemId：%di</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Lv：%di</li>\r\n",m_Lv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsFirstEnhance：%di</li>\r\n",m_IsFirstEnhance);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipEnhanceReply& v)
	{
		m_Result = v.result();
		m_ItemId = v.itemid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();
		m_Lv = v.lv();
		m_IsFirstEnhance = v.isfirstenhance();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//ItemId
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}
private:
	//需要强化的等级
	INT32 m_Lv;
public:
	void SetLv( INT32 v)
	{
		m_Lv=v;
	}
	INT32 GetLv()
	{
		return m_Lv;
	}
	INT32 GetLv() const
	{
		return m_Lv;
	}
private:
	//是否第一次强化
	bool m_IsFirstEnhance;
public:
	void SetIsFirstEnhance( bool v)
	{
		m_IsFirstEnhance=v;
	}
	bool GetIsFirstEnhance()
	{
		return m_IsFirstEnhance;
	}
	bool GetIsFirstEnhance() const
	{
		return m_IsFirstEnhance;
	}

};
//出售请求封装类
class BagRpcSellAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcSellAskWraper()
	{
		
		m_ItemID = -1;
		m_Pos = -1;
		m_Num = -1;

	}
	//赋值构造函数
	BagRpcSellAskWraper(const BagRpcSellAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcSellAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcSellAsk ToPB() const
	{
		BagRpcSellAsk v;
		v.set_itemid( m_ItemID );
		v.set_pos( m_Pos );
		v.set_num( m_Num );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcSellAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ItemID(物品id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ItemID：%di</li>\r\n",m_ItemID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcSellAsk& v)
	{
		m_ItemID = v.itemid();
		m_Pos = v.pos();
		m_Num = v.num();

	}

private:
	//物品id
	INT32 m_ItemID;
public:
	void SetItemID( INT32 v)
	{
		m_ItemID=v;
	}
	INT32 GetItemID()
	{
		return m_ItemID;
	}
	INT32 GetItemID() const
	{
		return m_ItemID;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//数量
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}

};
//出售回应封装类
class BagRpcSellReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcSellReplyWraper()
	{
		
		m_Result = -9999;
		m_ItemID = -1;
		m_Pos = -1;
		m_Num = -1;

	}
	//赋值构造函数
	BagRpcSellReplyWraper(const BagRpcSellReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcSellReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcSellReply ToPB() const
	{
		BagRpcSellReply v;
		v.set_result( m_Result );
		v.set_itemid( m_ItemID );
		v.set_pos( m_Pos );
		v.set_num( m_Num );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcSellReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemID(物品id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemID：%di</li>\r\n",m_ItemID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcSellReply& v)
	{
		m_Result = v.result();
		m_ItemID = v.itemid();
		m_Pos = v.pos();
		m_Num = v.num();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//物品id
	INT32 m_ItemID;
public:
	void SetItemID( INT32 v)
	{
		m_ItemID=v;
	}
	INT32 GetItemID()
	{
		return m_ItemID;
	}
	INT32 GetItemID() const
	{
		return m_ItemID;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//数量
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}

};
//同步背包数据请求封装类
class BagRpcSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	BagRpcSyncDataAskWraper(const BagRpcSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcSyncDataAsk ToPB() const
	{
		BagRpcSyncDataAsk v;

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcSyncDataAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcSyncDataAsk& v)
	{

	}


};
//同步背包数据回应封装类
class BagRpcSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcSyncDataReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BagRpcSyncDataReplyWraper(const BagRpcSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcSyncDataReply ToPB() const
	{
		BagRpcSyncDataReply v;
		v.set_result( m_Result );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcSyncDataReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcSyncDataReply& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//分解请求封装类
class BagRpcDecomposeAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcDecomposeAskWraper()
	{
		
		m_ItemID = -1;
		m_Pos = -1;

	}
	//赋值构造函数
	BagRpcDecomposeAskWraper(const BagRpcDecomposeAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcDecomposeAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcDecomposeAsk ToPB() const
	{
		BagRpcDecomposeAsk v;
		v.set_itemid( m_ItemID );
		v.set_pos( m_Pos );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcDecomposeAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ItemID(物品id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ItemID：%di</li>\r\n",m_ItemID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcDecomposeAsk& v)
	{
		m_ItemID = v.itemid();
		m_Pos = v.pos();

	}

private:
	//物品id
	INT32 m_ItemID;
public:
	void SetItemID( INT32 v)
	{
		m_ItemID=v;
	}
	INT32 GetItemID()
	{
		return m_ItemID;
	}
	INT32 GetItemID() const
	{
		return m_ItemID;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}

};
//物品使用请求封装类
class BagRpcUseAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcUseAskWraper()
	{
		
		m_ItemID = -1;
		m_Pos = -1;

	}
	//赋值构造函数
	BagRpcUseAskWraper(const BagRpcUseAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcUseAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcUseAsk ToPB() const
	{
		BagRpcUseAsk v;
		v.set_itemid( m_ItemID );
		v.set_pos( m_Pos );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcUseAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ItemID(物品id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ItemID：%di</li>\r\n",m_ItemID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcUseAsk& v)
	{
		m_ItemID = v.itemid();
		m_Pos = v.pos();

	}

private:
	//物品id
	INT32 m_ItemID;
public:
	void SetItemID( INT32 v)
	{
		m_ItemID=v;
	}
	INT32 GetItemID()
	{
		return m_ItemID;
	}
	INT32 GetItemID() const
	{
		return m_ItemID;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}

};
//分解回应封装类
class BagRpcDecomposeReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcDecomposeReplyWraper()
	{
		
		m_Result = -9999;
		m_ItemID = -1;
		m_Pos = -1;

	}
	//赋值构造函数
	BagRpcDecomposeReplyWraper(const BagRpcDecomposeReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcDecomposeReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcDecomposeReply ToPB() const
	{
		BagRpcDecomposeReply v;
		v.set_result( m_Result );
		v.set_itemid( m_ItemID );
		v.set_pos( m_Pos );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcDecomposeReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemID(物品id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemID：%di</li>\r\n",m_ItemID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcDecomposeReply& v)
	{
		m_Result = v.result();
		m_ItemID = v.itemid();
		m_Pos = v.pos();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//物品id
	INT32 m_ItemID;
public:
	void SetItemID( INT32 v)
	{
		m_ItemID=v;
	}
	INT32 GetItemID()
	{
		return m_ItemID;
	}
	INT32 GetItemID() const
	{
		return m_ItemID;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}

};
//物品拆分回应封装类
class BagRpcSplitReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcSplitReplyWraper()
	{
		
		m_Result = -9999;
		m_TemplateId = -1;
		m_Pos = -1;
		m_Num = -1;

	}
	//赋值构造函数
	BagRpcSplitReplyWraper(const BagRpcSplitReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcSplitReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcSplitReply ToPB() const
	{
		BagRpcSplitReply v;
		v.set_result( m_Result );
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_num( m_Num );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcSplitReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TemplateId(物品模板id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(拆分出来的数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcSplitReply& v)
	{
		m_Result = v.result();
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_Num = v.num();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//物品模板id
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//拆分出来的数量
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}

};
//装备基础属性洗炼请求封装类
class BagRpcEquipBaseAttrPlishedAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipBaseAttrPlishedAskWraper()
	{
		
		m_TemplateId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;

	}
	//赋值构造函数
	BagRpcEquipBaseAttrPlishedAskWraper(const BagRpcEquipBaseAttrPlishedAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipBaseAttrPlishedAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipBaseAttrPlishedAsk ToPB() const
	{
		BagRpcEquipBaseAttrPlishedAsk v;
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipBaseAttrPlishedAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateId(TemplateId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipBaseAttrPlishedAsk& v)
	{
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();

	}

private:
	//TemplateId
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}

};
//装备回收出售回应封装类
class BagRpcBagRecycleSellReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagRecycleSellReplyWraper()
	{
		
		m_Result = -9999;
		m_Money = -1;

	}
	//赋值构造函数
	BagRpcBagRecycleSellReplyWraper(const BagRpcBagRecycleSellReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagRecycleSellReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagRecycleSellReply ToPB() const
	{
		BagRpcBagRecycleSellReply v;
		v.set_result( m_Result );
		v.mutable_gridlist()->Reserve(m_GridList.size());
		for (int i=0; i<(int)m_GridList.size(); i++)
		{
			*v.add_gridlist() = m_GridList[i].ToPB();
		}
		v.set_money( m_Money );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagRecycleSellReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>GridList(在回收站中的格子) [BagRecycleGridObj] Array</li>\r\n";
		htmlBuff += "<li>Money(金钱) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>GridList：</li>\r\n";
		if( m_GridList.size()>0) htmlBuff += m_GridList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_GridList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_GridList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>Money：%di</li>\r\n",m_Money);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagRecycleSellReply& v)
	{
		m_Result = v.result();
		m_GridList.clear();
		m_GridList.reserve(v.gridlist_size());
		for( int i=0; i<v.gridlist_size(); i++)
			m_GridList.push_back(v.gridlist(i));
		m_Money = v.money();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//在回收站中的格子
	vector<BagRecycleGridObjWraper> m_GridList;
public:
	int SizeGridList()
	{
		return m_GridList.size();
	}
	const vector<BagRecycleGridObjWraper>& GetGridList() const
	{
		return m_GridList;
	}
	BagRecycleGridObjWraper GetGridList(int Index) const
	{
		if(Index<0 || Index>=(int)m_GridList.size())
		{
			assert(false);
			return BagRecycleGridObjWraper();
		}
		return m_GridList[Index];
	}
	void SetGridList( const vector<BagRecycleGridObjWraper>& v )
	{
		m_GridList=v;
	}
	void ClearGridList( )
	{
		m_GridList.clear();
	}
	void SetGridList( int Index, const BagRecycleGridObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_GridList.size())
		{
			assert(false);
			return;
		}
		m_GridList[Index] = v;
	}
	void AddGridList( const BagRecycleGridObjWraper& v )
	{
		m_GridList.push_back(v);
	}
private:
	//金钱
	INT32 m_Money;
public:
	void SetMoney( INT32 v)
	{
		m_Money=v;
	}
	INT32 GetMoney()
	{
		return m_Money;
	}
	INT32 GetMoney() const
	{
		return m_Money;
	}

};
//物品拆分请求封装类
class BagRpcSplitAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcSplitAskWraper()
	{
		
		m_TemplateId = -1;
		m_Pos = -1;
		m_Num = -1;

	}
	//赋值构造函数
	BagRpcSplitAskWraper(const BagRpcSplitAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcSplitAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcSplitAsk ToPB() const
	{
		BagRpcSplitAsk v;
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_num( m_Num );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcSplitAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateId(物品模板id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(拆分出来的数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcSplitAsk& v)
	{
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_Num = v.num();

	}

private:
	//物品模板id
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//拆分出来的数量
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}

};
//装备基础属性洗炼回应封装类
class BagRpcEquipBaseAttrPlishedReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipBaseAttrPlishedReplyWraper()
	{
		
		m_Result = -9999;
		m_TemplateId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;

	}
	//赋值构造函数
	BagRpcEquipBaseAttrPlishedReplyWraper(const BagRpcEquipBaseAttrPlishedReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipBaseAttrPlishedReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipBaseAttrPlishedReply ToPB() const
	{
		BagRpcEquipBaseAttrPlishedReply v;
		v.set_result( m_Result );
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipBaseAttrPlishedReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TemplateId(TemplateId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipBaseAttrPlishedReply& v)
	{
		m_Result = v.result();
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//TemplateId
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}

};
//装备改造请求封装类
class BagRpcEquipExAttrModifyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipExAttrModifyAskWraper()
	{
		
		m_TemplateId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;

	}
	//赋值构造函数
	BagRpcEquipExAttrModifyAskWraper(const BagRpcEquipExAttrModifyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipExAttrModifyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipExAttrModifyAsk ToPB() const
	{
		BagRpcEquipExAttrModifyAsk v;
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipExAttrModifyAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateId(TemplateId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipExAttrModifyAsk& v)
	{
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();

	}

private:
	//TemplateId
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}

};
//装备改造回应封装类
class BagRpcEquipExAttrModifyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipExAttrModifyReplyWraper()
	{
		
		m_Result = -9999;
		m_TemplateId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;
		m_Index = -1;

	}
	//赋值构造函数
	BagRpcEquipExAttrModifyReplyWraper(const BagRpcEquipExAttrModifyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipExAttrModifyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipExAttrModifyReply ToPB() const
	{
		BagRpcEquipExAttrModifyReply v;
		v.set_result( m_Result );
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );
		v.set_index( m_Index );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipExAttrModifyReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TemplateId(TemplateId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Index(属性Index) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Index：%di</li>\r\n",m_Index);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipExAttrModifyReply& v)
	{
		m_Result = v.result();
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();
		m_Index = v.index();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//TemplateId
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}
private:
	//属性Index
	INT32 m_Index;
public:
	void SetIndex( INT32 v)
	{
		m_Index=v;
	}
	INT32 GetIndex()
	{
		return m_Index;
	}
	INT32 GetIndex() const
	{
		return m_Index;
	}

};
//装备基础属性洗炼替换请求封装类
class BagRpcEquipBaseAttrPolishedReplaceAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipBaseAttrPolishedReplaceAskWraper()
	{
		
		m_TemplateId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;

	}
	//赋值构造函数
	BagRpcEquipBaseAttrPolishedReplaceAskWraper(const BagRpcEquipBaseAttrPolishedReplaceAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipBaseAttrPolishedReplaceAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipBaseAttrPolishedReplaceAsk ToPB() const
	{
		BagRpcEquipBaseAttrPolishedReplaceAsk v;
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipBaseAttrPolishedReplaceAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateId(TemplateId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipBaseAttrPolishedReplaceAsk& v)
	{
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();

	}

private:
	//TemplateId
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}

};
//装备基础属性洗炼替换回应封装类
class BagRpcEquipBaseAttrPolishedReplaceReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipBaseAttrPolishedReplaceReplyWraper()
	{
		
		m_Result = -9999;
		m_TemplateId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;

	}
	//赋值构造函数
	BagRpcEquipBaseAttrPolishedReplaceReplyWraper(const BagRpcEquipBaseAttrPolishedReplaceReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipBaseAttrPolishedReplaceReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipBaseAttrPolishedReplaceReply ToPB() const
	{
		BagRpcEquipBaseAttrPolishedReplaceReply v;
		v.set_result( m_Result );
		v.set_templateid( m_TemplateId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipBaseAttrPolishedReplaceReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TemplateId(TemplateId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipBaseAttrPolishedReplaceReply& v)
	{
		m_Result = v.result();
		m_TemplateId = v.templateid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//TemplateId
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}

};
//背包整理请求封装类
class BagRpcBagTidyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagTidyAskWraper()
	{
		

	}
	//赋值构造函数
	BagRpcBagTidyAskWraper(const BagRpcBagTidyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagTidyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagTidyAsk ToPB() const
	{
		BagRpcBagTidyAsk v;

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagTidyAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagTidyAsk& v)
	{

	}


};
//背包整理回应封装类
class BagRpcBagTidyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagTidyReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BagRpcBagTidyReplyWraper(const BagRpcBagTidyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagTidyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagTidyReply ToPB() const
	{
		BagRpcBagTidyReply v;
		v.set_result( m_Result );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagTidyReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagTidyReply& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//装备洗炼属性替换请求封装类
class BagRpcEquipPolishedReplaceAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipPolishedReplaceAskWraper()
	{
		
		m_ItemId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;

	}
	//赋值构造函数
	BagRpcEquipPolishedReplaceAskWraper(const BagRpcEquipPolishedReplaceAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipPolishedReplaceAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipPolishedReplaceAsk ToPB() const
	{
		BagRpcEquipPolishedReplaceAsk v;
		v.set_itemid( m_ItemId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipPolishedReplaceAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ItemId(ItemId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ItemId：%di</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipPolishedReplaceAsk& v)
	{
		m_ItemId = v.itemid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();

	}

private:
	//ItemId
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}

};
//装备洗炼属性替换回应封装类
class BagRpcEquipPolishedReplaceReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcEquipPolishedReplaceReplyWraper()
	{
		
		m_Result = -9999;
		m_ItemId = -1;
		m_Pos = -1;
		m_BagContainerType = -1;

	}
	//赋值构造函数
	BagRpcEquipPolishedReplaceReplyWraper(const BagRpcEquipPolishedReplaceReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcEquipPolishedReplaceReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcEquipPolishedReplaceReply ToPB() const
	{
		BagRpcEquipPolishedReplaceReply v;
		v.set_result( m_Result );
		v.set_itemid( m_ItemId );
		v.set_pos( m_Pos );
		v.set_bagcontainertype( m_BagContainerType );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcEquipPolishedReplaceReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemId(ItemId) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";
		htmlBuff += "<li>BagContainerType(背包容器类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemId：%di</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcEquipPolishedReplaceReply& v)
	{
		m_Result = v.result();
		m_ItemId = v.itemid();
		m_Pos = v.pos();
		m_BagContainerType = v.bagcontainertype();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//ItemId
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//背包容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}

};
//物品回收，购回请求封装类
class BagRpcBagRecycleBuyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagRecycleBuyAskWraper()
	{
		
		m_GridPos = -1;

	}
	//赋值构造函数
	BagRpcBagRecycleBuyAskWraper(const BagRpcBagRecycleBuyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagRecycleBuyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagRecycleBuyAsk ToPB() const
	{
		BagRpcBagRecycleBuyAsk v;
		v.set_gridpos( m_GridPos );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagRecycleBuyAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GridPos(格子位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>GridPos：%di</li>\r\n",m_GridPos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagRecycleBuyAsk& v)
	{
		m_GridPos = v.gridpos();

	}

private:
	//格子位置
	INT32 m_GridPos;
public:
	void SetGridPos( INT32 v)
	{
		m_GridPos=v;
	}
	INT32 GetGridPos()
	{
		return m_GridPos;
	}
	INT32 GetGridPos() const
	{
		return m_GridPos;
	}

};
//开启格子回应封装类
class BagRpcUnlockGridReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcUnlockGridReplyWraper()
	{
		
		m_Result = -9999;
		m_GridCount = -1;

	}
	//赋值构造函数
	BagRpcUnlockGridReplyWraper(const BagRpcUnlockGridReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcUnlockGridReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcUnlockGridReply ToPB() const
	{
		BagRpcUnlockGridReply v;
		v.set_result( m_Result );
		v.set_gridcount( m_GridCount );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcUnlockGridReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>GridCount(格子数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GridCount：%di</li>\r\n",m_GridCount);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcUnlockGridReply& v)
	{
		m_Result = v.result();
		m_GridCount = v.gridcount();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//格子数量
	INT32 m_GridCount;
public:
	void SetGridCount( INT32 v)
	{
		m_GridCount=v;
	}
	INT32 GetGridCount()
	{
		return m_GridCount;
	}
	INT32 GetGridCount() const
	{
		return m_GridCount;
	}

};
//装备回收出售请求封装类
class BagRpcBagRecycleSellAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagRecycleSellAskWraper()
	{
		

	}
	//赋值构造函数
	BagRpcBagRecycleSellAskWraper(const BagRpcBagRecycleSellAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagRecycleSellAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagRecycleSellAsk ToPB() const
	{
		BagRpcBagRecycleSellAsk v;
		v.mutable_gridlist()->Reserve(m_GridList.size());
		for (int i=0; i<(int)m_GridList.size(); i++)
		{
			*v.add_gridlist() = m_GridList[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagRecycleSellAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GridList(回收，出售的格子) [RpcSellGridObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>GridList：</li>\r\n";
		if( m_GridList.size()>0) htmlBuff += m_GridList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_GridList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_GridList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagRecycleSellAsk& v)
	{
		m_GridList.clear();
		m_GridList.reserve(v.gridlist_size());
		for( int i=0; i<v.gridlist_size(); i++)
			m_GridList.push_back(v.gridlist(i));

	}

private:
	//回收，出售的格子
	vector<BagRpcSellGridObjWraper> m_GridList;
public:
	int SizeGridList()
	{
		return m_GridList.size();
	}
	const vector<BagRpcSellGridObjWraper>& GetGridList() const
	{
		return m_GridList;
	}
	BagRpcSellGridObjWraper GetGridList(int Index) const
	{
		if(Index<0 || Index>=(int)m_GridList.size())
		{
			assert(false);
			return BagRpcSellGridObjWraper();
		}
		return m_GridList[Index];
	}
	void SetGridList( const vector<BagRpcSellGridObjWraper>& v )
	{
		m_GridList=v;
	}
	void ClearGridList( )
	{
		m_GridList.clear();
	}
	void SetGridList( int Index, const BagRpcSellGridObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_GridList.size())
		{
			assert(false);
			return;
		}
		m_GridList[Index] = v;
	}
	void AddGridList( const BagRpcSellGridObjWraper& v )
	{
		m_GridList.push_back(v);
	}

};
//物品回收，购回回应封装类
class BagRpcBagRecycleBuyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcBagRecycleBuyReplyWraper()
	{
		
		m_Result = -9999;
		m_GridPos = -1;

	}
	//赋值构造函数
	BagRpcBagRecycleBuyReplyWraper(const BagRpcBagRecycleBuyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagRecycleBuyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagRecycleBuyReply ToPB() const
	{
		BagRpcBagRecycleBuyReply v;
		v.set_result( m_Result );
		v.set_gridpos( m_GridPos );
		v.mutable_gridlist()->Reserve(m_GridList.size());
		for (int i=0; i<(int)m_GridList.size(); i++)
		{
			*v.add_gridlist() = m_GridList[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcBagRecycleBuyReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>GridPos(格子位置) [sint32]</li>\r\n";
		htmlBuff += "<li>GridList(在回收站中的格子) [BagRecycleGridObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GridPos：%di</li>\r\n",m_GridPos);
		htmlBuff += tmpLine;
		htmlBuff += "<li>GridList：</li>\r\n";
		if( m_GridList.size()>0) htmlBuff += m_GridList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_GridList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_GridList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcBagRecycleBuyReply& v)
	{
		m_Result = v.result();
		m_GridPos = v.gridpos();
		m_GridList.clear();
		m_GridList.reserve(v.gridlist_size());
		for( int i=0; i<v.gridlist_size(); i++)
			m_GridList.push_back(v.gridlist(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//格子位置
	INT32 m_GridPos;
public:
	void SetGridPos( INT32 v)
	{
		m_GridPos=v;
	}
	INT32 GetGridPos()
	{
		return m_GridPos;
	}
	INT32 GetGridPos() const
	{
		return m_GridPos;
	}
private:
	//在回收站中的格子
	vector<BagRecycleGridObjWraper> m_GridList;
public:
	int SizeGridList()
	{
		return m_GridList.size();
	}
	const vector<BagRecycleGridObjWraper>& GetGridList() const
	{
		return m_GridList;
	}
	BagRecycleGridObjWraper GetGridList(int Index) const
	{
		if(Index<0 || Index>=(int)m_GridList.size())
		{
			assert(false);
			return BagRecycleGridObjWraper();
		}
		return m_GridList[Index];
	}
	void SetGridList( const vector<BagRecycleGridObjWraper>& v )
	{
		m_GridList=v;
	}
	void ClearGridList( )
	{
		m_GridList.clear();
	}
	void SetGridList( int Index, const BagRecycleGridObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_GridList.size())
		{
			assert(false);
			return;
		}
		m_GridList[Index] = v;
	}
	void AddGridList( const BagRecycleGridObjWraper& v )
	{
		m_GridList.push_back(v);
	}

};
//开启格子请求封装类
class BagRpcUnlockGridAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRpcUnlockGridAskWraper()
	{
		
		m_GridCount = -1;

	}
	//赋值构造函数
	BagRpcUnlockGridAskWraper(const BagRpcUnlockGridAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcUnlockGridAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcUnlockGridAsk ToPB() const
	{
		BagRpcUnlockGridAsk v;
		v.set_gridcount( m_GridCount );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagRpcUnlockGridAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GridCount(格子数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>GridCount：%di</li>\r\n",m_GridCount);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRpcUnlockGridAsk& v)
	{
		m_GridCount = v.gridcount();

	}

private:
	//格子数量
	INT32 m_GridCount;
public:
	void SetGridCount( INT32 v)
	{
		m_GridCount=v;
	}
	INT32 GetGridCount()
	{
		return m_GridCount;
	}
	INT32 GetGridCount() const
	{
		return m_GridCount;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<BagRpcSyncDataAskWraper>{ enum{ID=RPC_CODE_BAG_SYNCDATA_REQUEST};};
template<> struct MessageIdT<BagRpcSyncDataReplyWraper>{ enum{ID=RPC_CODE_BAG_SYNCDATA_REQUEST};};
template<> struct MessageIdT<BagRpcSellAskWraper>{ enum{ID=RPC_CODE_BAG_SELL_REQUEST};};
template<> struct MessageIdT<BagRpcSellReplyWraper>{ enum{ID=RPC_CODE_BAG_SELL_REQUEST};};
template<> struct MessageIdT<BagRpcDecomposeAskWraper>{ enum{ID=RPC_CODE_BAG_DECOMPOSE_REQUEST};};
template<> struct MessageIdT<BagRpcDecomposeReplyWraper>{ enum{ID=RPC_CODE_BAG_DECOMPOSE_REQUEST};};
template<> struct MessageIdT<BagRpcUseAskWraper>{ enum{ID=RPC_CODE_BAG_USE_REQUEST};};
template<> struct MessageIdT<BagRpcUseReplyWraper>{ enum{ID=RPC_CODE_BAG_USE_REQUEST};};
template<> struct MessageIdT<BagRpcEquipWearAskWraper>{ enum{ID=RPC_CODE_BAG_EQUIPWEAR_REQUEST};};
template<> struct MessageIdT<BagRpcEquipWearReplyWraper>{ enum{ID=RPC_CODE_BAG_EQUIPWEAR_REQUEST};};
template<> struct MessageIdT<BagRpcEquipUndressAskWraper>{ enum{ID=RPC_CODE_BAG_EQUIPUNDRESS_REQUEST};};
template<> struct MessageIdT<BagRpcEquipUndressReplyWraper>{ enum{ID=RPC_CODE_BAG_EQUIPUNDRESS_REQUEST};};
template<> struct MessageIdT<BagRpcEquipEnhanceAskWraper>{ enum{ID=RPC_CODE_BAG_EQUIPENHANCE_REQUEST};};
template<> struct MessageIdT<BagRpcEquipEnhanceReplyWraper>{ enum{ID=RPC_CODE_BAG_EQUIPENHANCE_REQUEST};};
template<> struct MessageIdT<BagRpcEquipPolishedAskWraper>{ enum{ID=RPC_CODE_BAG_EQUIPPOLISHED_REQUEST};};
template<> struct MessageIdT<BagRpcEquipPolishedReplyWraper>{ enum{ID=RPC_CODE_BAG_EQUIPPOLISHED_REQUEST};};
template<> struct MessageIdT<BagRpcEquipPolishedReplaceAskWraper>{ enum{ID=RPC_CODE_BAG_EQUIPPOLISHEDREPLACE_REQUEST};};
template<> struct MessageIdT<BagRpcEquipPolishedReplaceReplyWraper>{ enum{ID=RPC_CODE_BAG_EQUIPPOLISHEDREPLACE_REQUEST};};
template<> struct MessageIdT<BagRpcBagTidyAskWraper>{ enum{ID=RPC_CODE_BAG_BAGTIDY_REQUEST};};
template<> struct MessageIdT<BagRpcBagTidyReplyWraper>{ enum{ID=RPC_CODE_BAG_BAGTIDY_REQUEST};};
template<> struct MessageIdT<BagRpcBagRecycleSellAskWraper>{ enum{ID=RPC_CODE_BAG_BAGRECYCLESELL_REQUEST};};
template<> struct MessageIdT<BagRpcBagRecycleSellReplyWraper>{ enum{ID=RPC_CODE_BAG_BAGRECYCLESELL_REQUEST};};
template<> struct MessageIdT<BagRpcBagRecycleBuyAskWraper>{ enum{ID=RPC_CODE_BAG_BAGRECYCLEBUY_REQUEST};};
template<> struct MessageIdT<BagRpcBagRecycleBuyReplyWraper>{ enum{ID=RPC_CODE_BAG_BAGRECYCLEBUY_REQUEST};};
template<> struct MessageIdT<BagRpcUnlockGridAskWraper>{ enum{ID=RPC_CODE_BAG_UNLOCKGRID_REQUEST};};
template<> struct MessageIdT<BagRpcUnlockGridReplyWraper>{ enum{ID=RPC_CODE_BAG_UNLOCKGRID_REQUEST};};
template<> struct MessageIdT<BagRpcSplitAskWraper>{ enum{ID=RPC_CODE_BAG_SPLIT_REQUEST};};
template<> struct MessageIdT<BagRpcSplitReplyWraper>{ enum{ID=RPC_CODE_BAG_SPLIT_REQUEST};};
template<> struct MessageIdT<BagRpcEquipBaseAttrPlishedAskWraper>{ enum{ID=RPC_CODE_BAG_EQUIPBASEATTRPLISHED_REQUEST};};
template<> struct MessageIdT<BagRpcEquipBaseAttrPlishedReplyWraper>{ enum{ID=RPC_CODE_BAG_EQUIPBASEATTRPLISHED_REQUEST};};
template<> struct MessageIdT<BagRpcEquipBaseAttrPolishedReplaceAskWraper>{ enum{ID=RPC_CODE_BAG_EQUIPBASEATTRPOLISHEDREPLACE_REQUEST};};
template<> struct MessageIdT<BagRpcEquipBaseAttrPolishedReplaceReplyWraper>{ enum{ID=RPC_CODE_BAG_EQUIPBASEATTRPOLISHEDREPLACE_REQUEST};};
template<> struct MessageIdT<BagRpcEquipExAttrModifyAskWraper>{ enum{ID=RPC_CODE_BAG_EQUIPEXATTRMODIFY_REQUEST};};
template<> struct MessageIdT<BagRpcEquipExAttrModifyReplyWraper>{ enum{ID=RPC_CODE_BAG_EQUIPEXATTRMODIFY_REQUEST};};
template<> struct MessageIdT<BagRpcEquipInlayGemAskWraper>{ enum{ID=RPC_CODE_BAG_EQUIPINLAYGEM_REQUEST};};
template<> struct MessageIdT<BagRpcEquipInlayGemReplyWraper>{ enum{ID=RPC_CODE_BAG_EQUIPINLAYGEM_REQUEST};};
template<> struct MessageIdT<BagRpcEquipGemSlotUnlockAskWraper>{ enum{ID=RPC_CODE_BAG_EQUIPGEMSLOTUNLOCK_REQUEST};};
template<> struct MessageIdT<BagRpcEquipGemSlotUnlockReplyWraper>{ enum{ID=RPC_CODE_BAG_EQUIPGEMSLOTUNLOCK_REQUEST};};
template<> struct MessageIdT<BagRpcEquipEnhanceSwapAskWraper>{ enum{ID=RPC_CODE_BAG_EQUIPENHANCESWAP_REQUEST};};
template<> struct MessageIdT<BagRpcEquipEnhanceSwapReplyWraper>{ enum{ID=RPC_CODE_BAG_EQUIPENHANCESWAP_REQUEST};};
template<> struct MessageIdT<BagRpcEquipGemRemoveAskWraper>{ enum{ID=RPC_CODE_BAG_EQUIPGEMREMOVE_REQUEST};};
template<> struct MessageIdT<BagRpcEquipGemRemoveReplyWraper>{ enum{ID=RPC_CODE_BAG_EQUIPGEMREMOVE_REQUEST};};
template<> struct MessageIdT<BagRpcBagPutInStorageAskWraper>{ enum{ID=RPC_CODE_BAG_BAGPUTINSTORAGE_REQUEST};};
template<> struct MessageIdT<BagRpcBagPutInStorageReplyWraper>{ enum{ID=RPC_CODE_BAG_BAGPUTINSTORAGE_REQUEST};};
template<> struct MessageIdT<BagRpcBagFetchFromStorageAskWraper>{ enum{ID=RPC_CODE_BAG_BAGFETCHFROMSTORAGE_REQUEST};};
template<> struct MessageIdT<BagRpcBagFetchFromStorageReplyWraper>{ enum{ID=RPC_CODE_BAG_BAGFETCHFROMSTORAGE_REQUEST};};
template<> struct MessageIdT<BagRpcBagStorageSaveMoneyAskWraper>{ enum{ID=RPC_CODE_BAG_BAGSTORAGESAVEMONEY_REQUEST};};
template<> struct MessageIdT<BagRpcBagStorageSaveMoneyReplyWraper>{ enum{ID=RPC_CODE_BAG_BAGSTORAGESAVEMONEY_REQUEST};};
template<> struct MessageIdT<BagRpcBagStorageDrawMoneyAskWraper>{ enum{ID=RPC_CODE_BAG_BAGSTORAGEDRAWMONEY_REQUEST};};
template<> struct MessageIdT<BagRpcBagStorageDrawMoneyReplyWraper>{ enum{ID=RPC_CODE_BAG_BAGSTORAGEDRAWMONEY_REQUEST};};
template<> struct MessageIdT<BagRpcStorageTidyAskWraper>{ enum{ID=RPC_CODE_BAG_STORAGETIDY_REQUEST};};
template<> struct MessageIdT<BagRpcStorageTidyReplyWraper>{ enum{ID=RPC_CODE_BAG_STORAGETIDY_REQUEST};};
template<> struct MessageIdT<BagRpcTalismanLvupAskWraper>{ enum{ID=RPC_CODE_BAG_TALISMANLVUP_REQUEST};};
template<> struct MessageIdT<BagRpcTalismanLvupReplyWraper>{ enum{ID=RPC_CODE_BAG_TALISMANLVUP_REQUEST};};
template<> struct MessageIdT<BagRpcTalismanInheritAskWraper>{ enum{ID=RPC_CODE_BAG_TALISMANINHERIT_REQUEST};};
template<> struct MessageIdT<BagRpcTalismanInheritReplyWraper>{ enum{ID=RPC_CODE_BAG_TALISMANINHERIT_REQUEST};};
template<> struct MessageIdT<BagRpcBagAddNewItemNotifyWraper>{ enum{ID=RPC_CODE_BAG_BAGADDNEWITEM_NOTIFY};};
template<> struct MessageIdT<BagRpcBagSetAutoPickupAskWraper>{ enum{ID=RPC_CODE_BAG_BAGSETAUTOPICKUP_REQUEST};};
template<> struct MessageIdT<BagRpcBagSetAutoPickupReplyWraper>{ enum{ID=RPC_CODE_BAG_BAGSETAUTOPICKUP_REQUEST};};
template<> struct MessageIdT<BagRpcGetNewItemNotifyWraper>{ enum{ID=RPC_CODE_BAG_GETNEWITEM_NOTIFY};};
template<> struct MessageIdT<BagRpcBagErrorNotifyWraper>{ enum{ID=RPC_CODE_BAG_BAGERROR_NOTIFY};};
template<> struct MessageIdT<BagRpcTalismanRefindStarAskWraper>{ enum{ID=RPC_CODE_BAG_TALISMANREFINDSTAR_REQUEST};};
template<> struct MessageIdT<BagRpcTalismanRefindStarReplyWraper>{ enum{ID=RPC_CODE_BAG_TALISMANREFINDSTAR_REQUEST};};
template<> struct MessageIdT<BagRpcTalismanUpSlotSkillLevelAskWraper>{ enum{ID=RPC_CODE_BAG_TALISMANUPSLOTSKILLLEVEL_REQUEST};};
template<> struct MessageIdT<BagRpcTalismanUpSlotSkillLevelReplyWraper>{ enum{ID=RPC_CODE_BAG_TALISMANUPSLOTSKILLLEVEL_REQUEST};};
template<> struct MessageIdT<BagRpcTalismanAttrChangeNotifyWraper>{ enum{ID=RPC_CODE_BAG_TALISMANATTRCHANGE_NOTIFY};};
template<> struct MessageIdT<BagRpcTalismanGatherSpriteAskWraper>{ enum{ID=RPC_CODE_BAG_TALISMANGATHERSPRITE_REQUEST};};
template<> struct MessageIdT<BagRpcTalismanGatherSpriteReplyWraper>{ enum{ID=RPC_CODE_BAG_TALISMANGATHERSPRITE_REQUEST};};


#endif
