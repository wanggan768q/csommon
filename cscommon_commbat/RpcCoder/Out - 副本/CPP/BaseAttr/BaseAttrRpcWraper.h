/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperBaseAttr.h
* Author:       甘业清
* Description:  战队基础数据RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_BASEATTR_H
#define __RPC_WRAPER_BASEATTR_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "BaseAttrRpc.pb.h"



//战队基础数据类的枚举定义
enum ConstBaseAttrE
{
	MODULE_ID_BASEATTR                           = 13,	//战队基础数据模块ID
	RPC_CODE_BASEATTR_SYNCDATA_REQUEST           = 1351,	//战队基础数据-->同步玩家数据-->请求
	RPC_CODE_BASEATTR_GETRANKREWARD_REQUEST      = 1352,	//战队基础数据-->领取官阶奖励-->请求
	RPC_CODE_BASEATTR_UPGRADERANK_REQUEST        = 1353,	//战队基础数据-->提升官阶-->请求
	RPC_CODE_BASEATTR_CHOOSEROLE_REQUEST         = 1354,	//战队基础数据-->选人-->请求
	RPC_CODE_BASEATTR_LEVELUP_REQUEST            = 1355,	//战队基础数据-->升级-->请求
	RPC_CODE_BASEATTR_GETTIMER_REQUEST           = 1356,	//战队基础数据-->获取时间-->请求
	RPC_CODE_BASEATTR_REVIVE_REQUEST             = 1357,	//战队基础数据-->复活-->请求
	RPC_CODE_BASEATTR_QUERYEQUIP_REQUEST         = 1358,	//战队基础数据-->查询装备数据-->请求
	RPC_CODE_BASEATTR_UPDATENEWBIEGUIDE_REQUEST  = 1359,	//战队基础数据-->更新新手引导-->请求
	RPC_CODE_BASEATTR_SYSTIPS_NOTIFY             = 1360,	//战队基础数据-->系统提示-->通知
	RPC_CODE_BASEATTR_CHANGPKSTATE_REQUEST       = 1361,	//战队基础数据-->修改PK状态-->请求
	RPC_CODE_BASEATTR_CHANGEPKPROTECT_REQUEST    = 1362,	//战队基础数据-->修改PK保护-->请求


};


//背包格子封装类
class BaseAttrRpcGridInfoWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcGridInfoWraper()
	{
		
		m_TemplateID = -1;
		m_Num = 0;
		m_ItemType = -1;
		m_Pos = -1;
		m_Value = -1;
		m_Index = -1;
		m_Bind = false;

	}
	//赋值构造函数
	BaseAttrRpcGridInfoWraper(const BaseAttrRpcGridInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcGridInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcGridInfo ToPB() const
	{
		BaseAttrRpcGridInfo v;
		v.set_templateid( m_TemplateID );
		v.set_num( m_Num );
		v.set_itemtype( m_ItemType );
		v.set_pos( m_Pos );
		v.set_value( m_Value );
		v.set_index( m_Index );
		v.set_bind( m_Bind );

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
		BaseAttrRpcGridInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateID(物品的配置Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(物品数量) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemType(物品类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>Value(客户端通用数据) [sint32]</li>\r\n";
		htmlBuff += "<li>Index(实例id，唯一id) [sint64]</li>\r\n";
		htmlBuff += "<li>Bind(绑定) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateID：%di</li>\r\n",m_TemplateID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemType：%di</li>\r\n",m_ItemType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Value：%di</li>\r\n",m_Value);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Index：%lldL</li>\r\n",m_Index);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Bind：%di</li>\r\n",m_Bind);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrRpcGridInfo& v)
	{
		m_TemplateID = v.templateid();
		m_Num = v.num();
		m_ItemType = v.itemtype();
		m_Pos = v.pos();
		m_Value = v.value();
		m_Index = v.index();
		m_Bind = v.bind();

	}

private:
	//物品的配置Id
	INT32 m_TemplateID;
public:
	void SetTemplateID( INT32 v)
	{
		m_TemplateID=v;
	}
	INT32 GetTemplateID()
	{
		return m_TemplateID;
	}
	INT32 GetTemplateID() const
	{
		return m_TemplateID;
	}
private:
	//物品数量
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
	//客户端通用数据
	INT32 m_Value;
public:
	void SetValue( INT32 v)
	{
		m_Value=v;
	}
	INT32 GetValue()
	{
		return m_Value;
	}
	INT32 GetValue() const
	{
		return m_Value;
	}
private:
	//实例id，唯一id
	INT64 m_Index;
public:
	void SetIndex( INT64 v)
	{
		m_Index=v;
	}
	INT64 GetIndex()
	{
		return m_Index;
	}
	INT64 GetIndex() const
	{
		return m_Index;
	}
private:
	//绑定
	bool m_Bind;
public:
	void SetBind( bool v)
	{
		m_Bind=v;
	}
	bool GetBind()
	{
		return m_Bind;
	}
	bool GetBind() const
	{
		return m_Bind;
	}

};
//更新新手引导请求封装类
class BaseAttrRpcUpdateNewbieGuideAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcUpdateNewbieGuideAskWraper()
	{
		
		m_GroupId = -1;
		m_Step = -1;

	}
	//赋值构造函数
	BaseAttrRpcUpdateNewbieGuideAskWraper(const BaseAttrRpcUpdateNewbieGuideAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcUpdateNewbieGuideAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcUpdateNewbieGuideAsk ToPB() const
	{
		BaseAttrRpcUpdateNewbieGuideAsk v;
		v.set_groupid( m_GroupId );
		v.set_step( m_Step );

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
		BaseAttrRpcUpdateNewbieGuideAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GroupId(组Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Step(步骤) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>GroupId：%di</li>\r\n",m_GroupId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Step：%di</li>\r\n",m_Step);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrRpcUpdateNewbieGuideAsk& v)
	{
		m_GroupId = v.groupid();
		m_Step = v.step();

	}

private:
	//组Id
	INT32 m_GroupId;
public:
	void SetGroupId( INT32 v)
	{
		m_GroupId=v;
	}
	INT32 GetGroupId()
	{
		return m_GroupId;
	}
	INT32 GetGroupId() const
	{
		return m_GroupId;
	}
private:
	//步骤
	INT32 m_Step;
public:
	void SetStep( INT32 v)
	{
		m_Step=v;
	}
	INT32 GetStep()
	{
		return m_Step;
	}
	INT32 GetStep() const
	{
		return m_Step;
	}

};
//更新新手引导回应封装类
class BaseAttrRpcUpdateNewbieGuideReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcUpdateNewbieGuideReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BaseAttrRpcUpdateNewbieGuideReplyWraper(const BaseAttrRpcUpdateNewbieGuideReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcUpdateNewbieGuideReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcUpdateNewbieGuideReply ToPB() const
	{
		BaseAttrRpcUpdateNewbieGuideReply v;
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
		BaseAttrRpcUpdateNewbieGuideReply pb;
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
	void Init(const BaseAttrRpcUpdateNewbieGuideReply& v)
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
//复活请求封装类
class BaseAttrRpcReviveAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcReviveAskWraper()
	{
		

	}
	//赋值构造函数
	BaseAttrRpcReviveAskWraper(const BaseAttrRpcReviveAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcReviveAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcReviveAsk ToPB() const
	{
		BaseAttrRpcReviveAsk v;

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
		BaseAttrRpcReviveAsk pb;
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
	void Init(const BaseAttrRpcReviveAsk& v)
	{

	}


};
//复活回应封装类
class BaseAttrRpcReviveReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcReviveReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BaseAttrRpcReviveReplyWraper(const BaseAttrRpcReviveReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcReviveReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcReviveReply ToPB() const
	{
		BaseAttrRpcReviveReply v;
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
		BaseAttrRpcReviveReply pb;
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
	void Init(const BaseAttrRpcReviveReply& v)
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
//查询装备数据请求封装类
class BaseAttrRpcQueryEquipAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcQueryEquipAskWraper()
	{
		
		m_UserId = -1;
		m_Pos = -1;
		m_TemplateID = -1;
		m_Index = -1;

	}
	//赋值构造函数
	BaseAttrRpcQueryEquipAskWraper(const BaseAttrRpcQueryEquipAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcQueryEquipAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcQueryEquipAsk ToPB() const
	{
		BaseAttrRpcQueryEquipAsk v;
		v.set_userid( m_UserId );
		v.set_pos( m_Pos );
		v.set_templateid( m_TemplateID );
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
		BaseAttrRpcQueryEquipAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>TemplateID(物品的配置Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Index(实例id，唯一id) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateID：%di</li>\r\n",m_TemplateID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Index：%lldL</li>\r\n",m_Index);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrRpcQueryEquipAsk& v)
	{
		m_UserId = v.userid();
		m_Pos = v.pos();
		m_TemplateID = v.templateid();
		m_Index = v.index();

	}

private:
	//用户ID
	INT64 m_UserId;
public:
	void SetUserId( INT64 v)
	{
		m_UserId=v;
	}
	INT64 GetUserId()
	{
		return m_UserId;
	}
	INT64 GetUserId() const
	{
		return m_UserId;
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
	//物品的配置Id
	INT32 m_TemplateID;
public:
	void SetTemplateID( INT32 v)
	{
		m_TemplateID=v;
	}
	INT32 GetTemplateID()
	{
		return m_TemplateID;
	}
	INT32 GetTemplateID() const
	{
		return m_TemplateID;
	}
private:
	//实例id，唯一id
	INT64 m_Index;
public:
	void SetIndex( INT64 v)
	{
		m_Index=v;
	}
	INT64 GetIndex()
	{
		return m_Index;
	}
	INT64 GetIndex() const
	{
		return m_Index;
	}

};
//查询装备数据回应封装类
class BaseAttrRpcQueryEquipReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcQueryEquipReplyWraper()
	{
		
		m_Result = -9999;
		m_EquipData = BagEquipObjWraper();
		m_GridData = BaseAttrRpcGridInfoWraper();

	}
	//赋值构造函数
	BaseAttrRpcQueryEquipReplyWraper(const BaseAttrRpcQueryEquipReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcQueryEquipReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcQueryEquipReply ToPB() const
	{
		BaseAttrRpcQueryEquipReply v;
		v.set_result( m_Result );
		*v.mutable_equipdata()= m_EquipData.ToPB();
		*v.mutable_griddata()= m_GridData.ToPB();

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
		BaseAttrRpcQueryEquipReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>EquipData(装备数据) [BagEquipObj]</li>\r\n";
		htmlBuff += "<li>GridData(背包格子) [RpcGridInfo]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>EquipData：</li>\r\n";
		htmlBuff += m_EquipData.HtmlDescHeader();
		htmlBuff += m_EquipData.ToHtml();
		htmlBuff += "<li>GridData：</li>\r\n";
		htmlBuff += m_GridData.HtmlDescHeader();
		htmlBuff += m_GridData.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrRpcQueryEquipReply& v)
	{
		m_Result = v.result();
		m_EquipData = v.equipdata();
		m_GridData = v.griddata();

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
	//装备数据
	BagEquipObjWraper m_EquipData;
public:
	void SetEquipData( const BagEquipObjWraper& v)
	{
		m_EquipData=v;
	}
	BagEquipObjWraper GetEquipData()
	{
		return m_EquipData;
	}
	BagEquipObjWraper GetEquipData() const
	{
		return m_EquipData;
	}
private:
	//背包格子
	BaseAttrRpcGridInfoWraper m_GridData;
public:
	void SetGridData( const BaseAttrRpcGridInfoWraper& v)
	{
		m_GridData=v;
	}
	BaseAttrRpcGridInfoWraper GetGridData()
	{
		return m_GridData;
	}
	BaseAttrRpcGridInfoWraper GetGridData() const
	{
		return m_GridData;
	}

};
//修改PK保护请求封装类
class BaseAttrRpcChangePKProtectAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcChangePKProtectAskWraper()
	{
		

	}
	//赋值构造函数
	BaseAttrRpcChangePKProtectAskWraper(const BaseAttrRpcChangePKProtectAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcChangePKProtectAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcChangePKProtectAsk ToPB() const
	{
		BaseAttrRpcChangePKProtectAsk v;
		v.mutable_protectlist()->Reserve(m_ProtectList.size());
		for (int i=0; i<(int)m_ProtectList.size(); i++)
		{
			*v.add_protectlist() = m_ProtectList[i].ToPB();
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
		BaseAttrRpcChangePKProtectAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ProtectList(保护列表) [KeyValue2IntBool] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ProtectList：</li>\r\n";
		if( m_ProtectList.size()>0) htmlBuff += m_ProtectList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ProtectList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ProtectList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrRpcChangePKProtectAsk& v)
	{
		m_ProtectList.clear();
		m_ProtectList.reserve(v.protectlist_size());
		for( int i=0; i<v.protectlist_size(); i++)
			m_ProtectList.push_back(v.protectlist(i));

	}

private:
	//保护列表
	vector<KeyValue2IntBoolWraper> m_ProtectList;
public:
	int SizeProtectList()
	{
		return m_ProtectList.size();
	}
	const vector<KeyValue2IntBoolWraper>& GetProtectList() const
	{
		return m_ProtectList;
	}
	KeyValue2IntBoolWraper GetProtectList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ProtectList.size())
		{
			assert(false);
			return KeyValue2IntBoolWraper();
		}
		return m_ProtectList[Index];
	}
	void SetProtectList( const vector<KeyValue2IntBoolWraper>& v )
	{
		m_ProtectList=v;
	}
	void ClearProtectList( )
	{
		m_ProtectList.clear();
	}
	void SetProtectList( int Index, const KeyValue2IntBoolWraper& v )
	{
		if(Index<0 || Index>=(int)m_ProtectList.size())
		{
			assert(false);
			return;
		}
		m_ProtectList[Index] = v;
	}
	void AddProtectList( const KeyValue2IntBoolWraper& v )
	{
		m_ProtectList.push_back(v);
	}

};
//修改PK保护回应封装类
class BaseAttrRpcChangePKProtectReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcChangePKProtectReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BaseAttrRpcChangePKProtectReplyWraper(const BaseAttrRpcChangePKProtectReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcChangePKProtectReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcChangePKProtectReply ToPB() const
	{
		BaseAttrRpcChangePKProtectReply v;
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
		BaseAttrRpcChangePKProtectReply pb;
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
	void Init(const BaseAttrRpcChangePKProtectReply& v)
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
//修改PK状态回应封装类
class BaseAttrRpcChangPKStateReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcChangPKStateReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BaseAttrRpcChangPKStateReplyWraper(const BaseAttrRpcChangPKStateReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcChangPKStateReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcChangPKStateReply ToPB() const
	{
		BaseAttrRpcChangPKStateReply v;
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
		BaseAttrRpcChangPKStateReply pb;
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
	void Init(const BaseAttrRpcChangPKStateReply& v)
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
//系统提示通知封装类
class BaseAttrRpcSysTipsNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcSysTipsNotifyWraper()
	{
		
		m_Id = -1;

	}
	//赋值构造函数
	BaseAttrRpcSysTipsNotifyWraper(const BaseAttrRpcSysTipsNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcSysTipsNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcSysTipsNotify ToPB() const
	{
		BaseAttrRpcSysTipsNotify v;
		v.set_id( m_Id );

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
		BaseAttrRpcSysTipsNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Id(配置Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrRpcSysTipsNotify& v)
	{
		m_Id = v.id();

	}

private:
	//配置Id
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}

};
//修改PK状态请求封装类
class BaseAttrRpcChangPKStateAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcChangPKStateAskWraper()
	{
		
		m_ChangState = -1;

	}
	//赋值构造函数
	BaseAttrRpcChangPKStateAskWraper(const BaseAttrRpcChangPKStateAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcChangPKStateAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcChangPKStateAsk ToPB() const
	{
		BaseAttrRpcChangPKStateAsk v;
		v.set_changstate( m_ChangState );

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
		BaseAttrRpcChangPKStateAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ChangState(PK状态) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ChangState：%di</li>\r\n",m_ChangState);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrRpcChangPKStateAsk& v)
	{
		m_ChangState = v.changstate();

	}

private:
	//PK状态
	INT32 m_ChangState;
public:
	void SetChangState( INT32 v)
	{
		m_ChangState=v;
	}
	INT32 GetChangState()
	{
		return m_ChangState;
	}
	INT32 GetChangState() const
	{
		return m_ChangState;
	}

};
//获取时间回应封装类
class BaseAttrRpcGetTimerReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcGetTimerReplyWraper()
	{
		
		m_Result = -9999;
		m_Timer = -1;

	}
	//赋值构造函数
	BaseAttrRpcGetTimerReplyWraper(const BaseAttrRpcGetTimerReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcGetTimerReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcGetTimerReply ToPB() const
	{
		BaseAttrRpcGetTimerReply v;
		v.set_result( m_Result );
		v.set_timer( m_Timer );

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
		BaseAttrRpcGetTimerReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Timer(时间) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Timer：%lldL</li>\r\n",m_Timer);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrRpcGetTimerReply& v)
	{
		m_Result = v.result();
		m_Timer = v.timer();

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
	//时间
	INT64 m_Timer;
public:
	void SetTimer( INT64 v)
	{
		m_Timer=v;
	}
	INT64 GetTimer()
	{
		return m_Timer;
	}
	INT64 GetTimer() const
	{
		return m_Timer;
	}

};
//领取官阶奖励回应封装类
class BaseAttrRpcGetRankRewardReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcGetRankRewardReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BaseAttrRpcGetRankRewardReplyWraper(const BaseAttrRpcGetRankRewardReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcGetRankRewardReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcGetRankRewardReply ToPB() const
	{
		BaseAttrRpcGetRankRewardReply v;
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
		BaseAttrRpcGetRankRewardReply pb;
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
	void Init(const BaseAttrRpcGetRankRewardReply& v)
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
//提升官阶请求封装类
class BaseAttrRpcUpGradeRankAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcUpGradeRankAskWraper()
	{
		

	}
	//赋值构造函数
	BaseAttrRpcUpGradeRankAskWraper(const BaseAttrRpcUpGradeRankAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcUpGradeRankAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcUpGradeRankAsk ToPB() const
	{
		BaseAttrRpcUpGradeRankAsk v;

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
		BaseAttrRpcUpGradeRankAsk pb;
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
	void Init(const BaseAttrRpcUpGradeRankAsk& v)
	{

	}


};
//提升官阶回应封装类
class BaseAttrRpcUpGradeRankReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcUpGradeRankReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BaseAttrRpcUpGradeRankReplyWraper(const BaseAttrRpcUpGradeRankReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcUpGradeRankReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcUpGradeRankReply ToPB() const
	{
		BaseAttrRpcUpGradeRankReply v;
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
		BaseAttrRpcUpGradeRankReply pb;
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
	void Init(const BaseAttrRpcUpGradeRankReply& v)
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
//领取官阶奖励请求封装类
class BaseAttrRpcGetRankRewardAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcGetRankRewardAskWraper()
	{
		

	}
	//赋值构造函数
	BaseAttrRpcGetRankRewardAskWraper(const BaseAttrRpcGetRankRewardAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcGetRankRewardAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcGetRankRewardAsk ToPB() const
	{
		BaseAttrRpcGetRankRewardAsk v;

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
		BaseAttrRpcGetRankRewardAsk pb;
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
	void Init(const BaseAttrRpcGetRankRewardAsk& v)
	{

	}


};
//同步玩家数据请求封装类
class BaseAttrRpcSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	BaseAttrRpcSyncDataAskWraper(const BaseAttrRpcSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcSyncDataAsk ToPB() const
	{
		BaseAttrRpcSyncDataAsk v;

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
		BaseAttrRpcSyncDataAsk pb;
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
	void Init(const BaseAttrRpcSyncDataAsk& v)
	{

	}


};
//同步玩家数据回应封装类
class BaseAttrRpcSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcSyncDataReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BaseAttrRpcSyncDataReplyWraper(const BaseAttrRpcSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcSyncDataReply ToPB() const
	{
		BaseAttrRpcSyncDataReply v;
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
		BaseAttrRpcSyncDataReply pb;
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
	void Init(const BaseAttrRpcSyncDataReply& v)
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
//选人请求封装类
class BaseAttrRpcChooseRoleAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcChooseRoleAskWraper()
	{
		
		m_Prof = -1;

	}
	//赋值构造函数
	BaseAttrRpcChooseRoleAskWraper(const BaseAttrRpcChooseRoleAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcChooseRoleAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcChooseRoleAsk ToPB() const
	{
		BaseAttrRpcChooseRoleAsk v;
		v.set_prof( m_Prof );

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
		BaseAttrRpcChooseRoleAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Prof(职业) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Prof：%di</li>\r\n",m_Prof);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrRpcChooseRoleAsk& v)
	{
		m_Prof = v.prof();

	}

private:
	//职业
	INT32 m_Prof;
public:
	void SetProf( INT32 v)
	{
		m_Prof=v;
	}
	INT32 GetProf()
	{
		return m_Prof;
	}
	INT32 GetProf() const
	{
		return m_Prof;
	}

};
//获取时间请求封装类
class BaseAttrRpcGetTimerAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcGetTimerAskWraper()
	{
		

	}
	//赋值构造函数
	BaseAttrRpcGetTimerAskWraper(const BaseAttrRpcGetTimerAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcGetTimerAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcGetTimerAsk ToPB() const
	{
		BaseAttrRpcGetTimerAsk v;

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
		BaseAttrRpcGetTimerAsk pb;
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
	void Init(const BaseAttrRpcGetTimerAsk& v)
	{

	}


};
//选人回应封装类
class BaseAttrRpcChooseRoleReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcChooseRoleReplyWraper()
	{
		
		m_Result = -9999;
		m_Prof = -1;

	}
	//赋值构造函数
	BaseAttrRpcChooseRoleReplyWraper(const BaseAttrRpcChooseRoleReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcChooseRoleReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcChooseRoleReply ToPB() const
	{
		BaseAttrRpcChooseRoleReply v;
		v.set_result( m_Result );
		v.set_prof( m_Prof );

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
		BaseAttrRpcChooseRoleReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Prof(职业) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Prof：%di</li>\r\n",m_Prof);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrRpcChooseRoleReply& v)
	{
		m_Result = v.result();
		m_Prof = v.prof();

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
	//职业
	INT32 m_Prof;
public:
	void SetProf( INT32 v)
	{
		m_Prof=v;
	}
	INT32 GetProf()
	{
		return m_Prof;
	}
	INT32 GetProf() const
	{
		return m_Prof;
	}

};
//升级请求封装类
class BaseAttrRpcLevelUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcLevelUpAskWraper()
	{
		

	}
	//赋值构造函数
	BaseAttrRpcLevelUpAskWraper(const BaseAttrRpcLevelUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcLevelUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcLevelUpAsk ToPB() const
	{
		BaseAttrRpcLevelUpAsk v;

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
		BaseAttrRpcLevelUpAsk pb;
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
	void Init(const BaseAttrRpcLevelUpAsk& v)
	{

	}


};
//升级回应封装类
class BaseAttrRpcLevelUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcLevelUpReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BaseAttrRpcLevelUpReplyWraper(const BaseAttrRpcLevelUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcLevelUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcLevelUpReply ToPB() const
	{
		BaseAttrRpcLevelUpReply v;
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
		BaseAttrRpcLevelUpReply pb;
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
	void Init(const BaseAttrRpcLevelUpReply& v)
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

template<typename T> struct MessageIdT;
template<> struct MessageIdT<BaseAttrRpcSyncDataAskWraper>{ enum{ID=RPC_CODE_BASEATTR_SYNCDATA_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcSyncDataReplyWraper>{ enum{ID=RPC_CODE_BASEATTR_SYNCDATA_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcGetRankRewardAskWraper>{ enum{ID=RPC_CODE_BASEATTR_GETRANKREWARD_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcGetRankRewardReplyWraper>{ enum{ID=RPC_CODE_BASEATTR_GETRANKREWARD_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcUpGradeRankAskWraper>{ enum{ID=RPC_CODE_BASEATTR_UPGRADERANK_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcUpGradeRankReplyWraper>{ enum{ID=RPC_CODE_BASEATTR_UPGRADERANK_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcChooseRoleAskWraper>{ enum{ID=RPC_CODE_BASEATTR_CHOOSEROLE_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcChooseRoleReplyWraper>{ enum{ID=RPC_CODE_BASEATTR_CHOOSEROLE_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcLevelUpAskWraper>{ enum{ID=RPC_CODE_BASEATTR_LEVELUP_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcLevelUpReplyWraper>{ enum{ID=RPC_CODE_BASEATTR_LEVELUP_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcGetTimerAskWraper>{ enum{ID=RPC_CODE_BASEATTR_GETTIMER_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcGetTimerReplyWraper>{ enum{ID=RPC_CODE_BASEATTR_GETTIMER_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcReviveAskWraper>{ enum{ID=RPC_CODE_BASEATTR_REVIVE_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcReviveReplyWraper>{ enum{ID=RPC_CODE_BASEATTR_REVIVE_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcQueryEquipAskWraper>{ enum{ID=RPC_CODE_BASEATTR_QUERYEQUIP_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcQueryEquipReplyWraper>{ enum{ID=RPC_CODE_BASEATTR_QUERYEQUIP_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcUpdateNewbieGuideAskWraper>{ enum{ID=RPC_CODE_BASEATTR_UPDATENEWBIEGUIDE_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcUpdateNewbieGuideReplyWraper>{ enum{ID=RPC_CODE_BASEATTR_UPDATENEWBIEGUIDE_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcSysTipsNotifyWraper>{ enum{ID=RPC_CODE_BASEATTR_SYSTIPS_NOTIFY};};
template<> struct MessageIdT<BaseAttrRpcChangPKStateAskWraper>{ enum{ID=RPC_CODE_BASEATTR_CHANGPKSTATE_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcChangPKStateReplyWraper>{ enum{ID=RPC_CODE_BASEATTR_CHANGPKSTATE_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcChangePKProtectAskWraper>{ enum{ID=RPC_CODE_BASEATTR_CHANGEPKPROTECT_REQUEST};};
template<> struct MessageIdT<BaseAttrRpcChangePKProtectReplyWraper>{ enum{ID=RPC_CODE_BASEATTR_CHANGEPKPROTECT_REQUEST};};


#endif
