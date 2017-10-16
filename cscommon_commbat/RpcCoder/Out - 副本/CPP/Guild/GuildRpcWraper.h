/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperGuild.h
* Author:       甘业清
* Description:  帮派RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_GUILD_H
#define __RPC_WRAPER_GUILD_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "GuildRpc.pb.h"



//帮派类的枚举定义
enum ConstGuildE
{
	MODULE_ID_GUILD                              = 34,	//帮派模块ID
	RPC_CODE_GUILD_SYNCDATA_REQUEST              = 3451,	//帮派-->登陆后，同步一次数据-->请求
	RPC_CODE_GUILD_CREATEGUILD_REQUEST           = 3452,	//帮派-->创建帮会-->请求
	RPC_CODE_GUILD_APPLYGUILD_REQUEST            = 3453,	//帮派-->申请入帮-->请求
	RPC_CODE_GUILD_QUICKAPPLY_REQUEST            = 3454,	//帮派-->快速申请-->请求
	RPC_CODE_GUILD_CHANGEGUILDNAME_REQUEST       = 3455,	//帮派-->修改帮会名字-->请求
	RPC_CODE_GUILD_CHANGEANNOUNCEMENT_REQUEST    = 3456,	//帮派-->修改公告-->请求
	RPC_CODE_GUILD_REQGUILDLIST_REQUEST          = 3457,	//帮派-->请求帮会列表-->请求
	RPC_CODE_GUILD_APPOINTDUTY_REQUEST           = 3458,	//帮派-->任命职位-->请求
	RPC_CODE_GUILD_KICKOUT_REQUEST               = 3459,	//帮派-->踢人-->请求
	RPC_CODE_GUILD_EXITGUILD_REQUEST             = 3460,	//帮派-->退出帮会-->请求
	RPC_CODE_GUILD_BREAKUP_REQUEST               = 3461,	//帮派-->解散帮会-->请求
	RPC_CODE_GUILD_INVITETOJOIN_REQUEST          = 3462,	//帮派-->邀请入帮-->请求
	RPC_CODE_GUILD_BEINVITEDNOTICE_NOTIFY        = 3463,	//帮派-->被邀请提示-->通知
	RPC_CODE_GUILD_BEINVITEDHANDLE_REQUEST       = 3464,	//帮派-->被邀请处理-->请求
	RPC_CODE_GUILD_RESIGNDUTY_REQUEST            = 3465,	//帮派-->辞职-->请求
	RPC_CODE_GUILD_SYNCMYTEAMDATA_NOTIFY         = 3466,	//帮派-->发送我的帮会数据-->通知
	RPC_CODE_GUILD_SYNCNOTICEOFGUILDBASEDATA_NOTIFY= 3467,	//帮派-->同步帮会基础数据-->通知
	RPC_CODE_GUILD_SYNCNOTICEOFGUILDMEMBERCHANGE_NOTIFY= 3468,	//帮派-->同步帮会成员数据变化-->通知
	RPC_CODE_GUILD_SYNCNOTICEOFADDMEMBER_NOTIFY  = 3469,	//帮派-->同步帮会增加成员-->通知
	RPC_CODE_GUILD_SYNCNOTICEOFDELMEMBER_NOTIFY  = 3470,	//帮派-->同步帮会删除成员-->通知
	RPC_CODE_GUILD_SYNCNOTICEOFADDEVENT_NOTIFY   = 3471,	//帮派-->同步帮会增加事件-->通知
	RPC_CODE_GUILD_SYNCNOTICEOFADDAPPLYLIST_NOTIFY= 3472,	//帮派-->同步帮会增加申请列表-->通知
	RPC_CODE_GUILD_SYNCNOTICEOFDELAPPLYLIST_NOTIFY= 3473,	//帮派-->同步帮会删除申请列表-->通知
	RPC_CODE_GUILD_SYNCNOTICEOFCHANGEANNOUNCEMENT_NOTIFY= 3474,	//帮派-->同步帮会公告修改-->通知
	RPC_CODE_GUILD_SYNCNOTICEOFBREAKUP_NOTIFY    = 3475,	//帮派-->通知解散-->通知
	RPC_CODE_GUILD_HALLLVUP_REQUEST              = 3476,	//帮派-->帮会大厅升级-->请求
	RPC_CODE_GUILD_HOUSELVUP_REQUEST             = 3477,	//帮派-->帮会房屋升级-->请求
	RPC_CODE_GUILD_STOREROOMLVUP_REQUEST         = 3478,	//帮派-->帮会库房升级-->请求
	RPC_CODE_GUILD_KONGFUHALLLVUP_REQUEST        = 3479,	//帮派-->帮会练武堂升级-->请求
	RPC_CODE_GUILD_SYNCNOTICEOFHALLLVUP_NOTIFY   = 3480,	//帮派-->同步帮会大厅升级-->通知
	RPC_CODE_GUILD_SYNCNOTICEOFHOUSELVUP_NOTIFY  = 3481,	//帮派-->同步帮会房屋升级-->通知
	RPC_CODE_GUILD_SYNCNOTICEOFSTOREROMMLVUP_NOTIFY= 3482,	//帮派-->同步帮会库房升级-->通知
	RPC_CODE_GUILD_SYNCNOTICEOFKONGFUHALLLVUP_NOTIFY= 3483,	//帮派-->同步练武堂升级-->通知
	RPC_CODE_GUILD_APPLYGUILDHANDLE_REQUEST      = 3484,	//帮派-->申请入帮，帮主处理-->请求
	RPC_CODE_GUILD_CREATEGUILDDUNGEON_REQUEST    = 3485,	//帮派-->创建帮会副本-->请求
	RPC_CODE_GUILD_ENTERGUILDDUNGEON_REQUEST     = 3486,	//帮派-->进入帮会副本-->请求
	RPC_CODE_GUILD_RPCSYNCNOTICEOFCREATEGUILDDUNGEON_NOTIFY= 3487,	//帮派-->同步帮会副本创建-->通知
	RPC_CODE_GUILD_CREATEGUILDWAR_REQUEST        = 3488,	//帮派-->创建帮会战-->请求
	RPC_CODE_GUILD_SYNCNOTICEOFOPENGUILDWAR_NOTIFY= 3489,	//帮派-->同步帮会战是否开启-->通知
	RPC_CODE_GUILD_ENTERGUILDWAR_REQUEST         = 3490,	//帮派-->进入帮会战-->请求
	RPC_CODE_GUILD_OPENSCIENCEATTR_REQUEST       = 3491,	//帮派-->开启帮会修炼项目-->请求
	RPC_CODE_GUILD_GUILDSCIENCELVUP_REQUEST      = 3492,	//帮派-->帮会属性升级-->请求


};


//帮会库房升级回应封装类
class GuildRpcStoreroomLvUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcStoreroomLvUpReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcStoreroomLvUpReplyWraper(const GuildRpcStoreroomLvUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcStoreroomLvUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcStoreroomLvUpReply ToPB() const
	{
		GuildRpcStoreroomLvUpReply v;
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
		GuildRpcStoreroomLvUpReply pb;
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
	void Init(const GuildRpcStoreroomLvUpReply& v)
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
//帮会练武堂升级请求封装类
class GuildRpcKongfuHallLvUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcKongfuHallLvUpAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcKongfuHallLvUpAskWraper(const GuildRpcKongfuHallLvUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcKongfuHallLvUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcKongfuHallLvUpAsk ToPB() const
	{
		GuildRpcKongfuHallLvUpAsk v;

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
		GuildRpcKongfuHallLvUpAsk pb;
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
	void Init(const GuildRpcKongfuHallLvUpAsk& v)
	{

	}


};
//帮会房屋升级回应封装类
class GuildRpcHouseLvUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcHouseLvUpReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcHouseLvUpReplyWraper(const GuildRpcHouseLvUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcHouseLvUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcHouseLvUpReply ToPB() const
	{
		GuildRpcHouseLvUpReply v;
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
		GuildRpcHouseLvUpReply pb;
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
	void Init(const GuildRpcHouseLvUpReply& v)
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
//帮会库房升级请求封装类
class GuildRpcStoreroomLvUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcStoreroomLvUpAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcStoreroomLvUpAskWraper(const GuildRpcStoreroomLvUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcStoreroomLvUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcStoreroomLvUpAsk ToPB() const
	{
		GuildRpcStoreroomLvUpAsk v;

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
		GuildRpcStoreroomLvUpAsk pb;
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
	void Init(const GuildRpcStoreroomLvUpAsk& v)
	{

	}


};
//同步帮会房屋升级通知封装类
class GuildRpcSyncNoticeOfHouseLvUpNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncNoticeOfHouseLvUpNotifyWraper()
	{
		
		m_Lv = -1;
		m_Time = -1;

	}
	//赋值构造函数
	GuildRpcSyncNoticeOfHouseLvUpNotifyWraper(const GuildRpcSyncNoticeOfHouseLvUpNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncNoticeOfHouseLvUpNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncNoticeOfHouseLvUpNotify ToPB() const
	{
		GuildRpcSyncNoticeOfHouseLvUpNotify v;
		v.set_lv( m_Lv );
		v.set_time( m_Time );

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
		GuildRpcSyncNoticeOfHouseLvUpNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Lv(当前等级) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(开始时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Lv：%di</li>\r\n",m_Lv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncNoticeOfHouseLvUpNotify& v)
	{
		m_Lv = v.lv();
		m_Time = v.time();

	}

private:
	//当前等级
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
	//开始时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}

};
//同步帮会库房升级通知封装类
class GuildRpcSyncNoticeOfStorerommLvUpNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncNoticeOfStorerommLvUpNotifyWraper()
	{
		
		m_Lv = -1;
		m_Time = -1;

	}
	//赋值构造函数
	GuildRpcSyncNoticeOfStorerommLvUpNotifyWraper(const GuildRpcSyncNoticeOfStorerommLvUpNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncNoticeOfStorerommLvUpNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncNoticeOfStorerommLvUpNotify ToPB() const
	{
		GuildRpcSyncNoticeOfStorerommLvUpNotify v;
		v.set_lv( m_Lv );
		v.set_time( m_Time );

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
		GuildRpcSyncNoticeOfStorerommLvUpNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Lv(当前等级) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(开始时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Lv：%di</li>\r\n",m_Lv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncNoticeOfStorerommLvUpNotify& v)
	{
		m_Lv = v.lv();
		m_Time = v.time();

	}

private:
	//当前等级
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
	//开始时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}

};
//帮会练武堂升级回应封装类
class GuildRpcKongfuHallLvUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcKongfuHallLvUpReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcKongfuHallLvUpReplyWraper(const GuildRpcKongfuHallLvUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcKongfuHallLvUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcKongfuHallLvUpReply ToPB() const
	{
		GuildRpcKongfuHallLvUpReply v;
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
		GuildRpcKongfuHallLvUpReply pb;
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
	void Init(const GuildRpcKongfuHallLvUpReply& v)
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
//同步帮会大厅升级通知封装类
class GuildRpcSyncNoticeOfHallLvUpNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncNoticeOfHallLvUpNotifyWraper()
	{
		
		m_Lv = -1;
		m_Time = -1;

	}
	//赋值构造函数
	GuildRpcSyncNoticeOfHallLvUpNotifyWraper(const GuildRpcSyncNoticeOfHallLvUpNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncNoticeOfHallLvUpNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncNoticeOfHallLvUpNotify ToPB() const
	{
		GuildRpcSyncNoticeOfHallLvUpNotify v;
		v.set_lv( m_Lv );
		v.set_time( m_Time );

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
		GuildRpcSyncNoticeOfHallLvUpNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Lv(当前等级) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(开始时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Lv：%di</li>\r\n",m_Lv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncNoticeOfHallLvUpNotify& v)
	{
		m_Lv = v.lv();
		m_Time = v.time();

	}

private:
	//当前等级
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
	//开始时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}

};
//帮会房屋升级请求封装类
class GuildRpcHouseLvUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcHouseLvUpAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcHouseLvUpAskWraper(const GuildRpcHouseLvUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcHouseLvUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcHouseLvUpAsk ToPB() const
	{
		GuildRpcHouseLvUpAsk v;

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
		GuildRpcHouseLvUpAsk pb;
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
	void Init(const GuildRpcHouseLvUpAsk& v)
	{

	}


};
//同步帮会增加申请列表通知封装类
class GuildRpcSyncNoticeOfAddApplyListNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncNoticeOfAddApplyListNotifyWraper()
	{
		
		m_ApplyPlayer = ApplyListRoleInfoObjWraper();

	}
	//赋值构造函数
	GuildRpcSyncNoticeOfAddApplyListNotifyWraper(const GuildRpcSyncNoticeOfAddApplyListNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncNoticeOfAddApplyListNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncNoticeOfAddApplyListNotify ToPB() const
	{
		GuildRpcSyncNoticeOfAddApplyListNotify v;
		*v.mutable_applyplayer()= m_ApplyPlayer.ToPB();

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
		GuildRpcSyncNoticeOfAddApplyListNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ApplyPlayer(申请玩家) [ApplyListRoleInfoObj]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ApplyPlayer：</li>\r\n";
		htmlBuff += m_ApplyPlayer.HtmlDescHeader();
		htmlBuff += m_ApplyPlayer.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncNoticeOfAddApplyListNotify& v)
	{
		m_ApplyPlayer = v.applyplayer();

	}

private:
	//申请玩家
	ApplyListRoleInfoObjWraper m_ApplyPlayer;
public:
	void SetApplyPlayer( const ApplyListRoleInfoObjWraper& v)
	{
		m_ApplyPlayer=v;
	}
	ApplyListRoleInfoObjWraper GetApplyPlayer()
	{
		return m_ApplyPlayer;
	}
	ApplyListRoleInfoObjWraper GetApplyPlayer() const
	{
		return m_ApplyPlayer;
	}

};
//同步帮会删除申请列表通知封装类
class GuildRpcSyncNoticeOfDelApplyListNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncNoticeOfDelApplyListNotifyWraper()
	{
		
		m_UserId = -1;

	}
	//赋值构造函数
	GuildRpcSyncNoticeOfDelApplyListNotifyWraper(const GuildRpcSyncNoticeOfDelApplyListNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncNoticeOfDelApplyListNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncNoticeOfDelApplyListNotify ToPB() const
	{
		GuildRpcSyncNoticeOfDelApplyListNotify v;
		v.set_userid( m_UserId );

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
		GuildRpcSyncNoticeOfDelApplyListNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncNoticeOfDelApplyListNotify& v)
	{
		m_UserId = v.userid();

	}

private:
	//用户Id
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

};
//同步帮会删除成员通知封装类
class GuildRpcSyncNoticeOfDelMemberNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncNoticeOfDelMemberNotifyWraper()
	{
		
		m_UserId = -1;

	}
	//赋值构造函数
	GuildRpcSyncNoticeOfDelMemberNotifyWraper(const GuildRpcSyncNoticeOfDelMemberNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncNoticeOfDelMemberNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncNoticeOfDelMemberNotify ToPB() const
	{
		GuildRpcSyncNoticeOfDelMemberNotify v;
		v.set_userid( m_UserId );

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
		GuildRpcSyncNoticeOfDelMemberNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncNoticeOfDelMemberNotify& v)
	{
		m_UserId = v.userid();

	}

private:
	//用户Id
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

};
//同步帮会增加事件通知封装类
class GuildRpcSyncNoticeOfAddEventNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncNoticeOfAddEventNotifyWraper()
	{
		
		m_EventId = -1;
		m_Param1 = "";
		m_Param2 = "";

	}
	//赋值构造函数
	GuildRpcSyncNoticeOfAddEventNotifyWraper(const GuildRpcSyncNoticeOfAddEventNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncNoticeOfAddEventNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncNoticeOfAddEventNotify ToPB() const
	{
		GuildRpcSyncNoticeOfAddEventNotify v;
		v.set_eventid( m_EventId );
		v.set_param1( m_Param1 );
		v.set_param2( m_Param2 );

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
		GuildRpcSyncNoticeOfAddEventNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>EventId(事件Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Param1(参数1) [string]</li>\r\n";
		htmlBuff += "<li>Param2(参数2) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>EventId：%di</li>\r\n",m_EventId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Param1：\""+m_Param1+"\"</li>\r\n";
		htmlBuff += "<li>Param2：\""+m_Param2+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncNoticeOfAddEventNotify& v)
	{
		m_EventId = v.eventid();
		m_Param1 = v.param1();
		m_Param2 = v.param2();

	}

private:
	//事件Id
	INT32 m_EventId;
public:
	void SetEventId( INT32 v)
	{
		m_EventId=v;
	}
	INT32 GetEventId()
	{
		return m_EventId;
	}
	INT32 GetEventId() const
	{
		return m_EventId;
	}
private:
	//参数1
	string m_Param1;
public:
	void SetParam1( const string& v)
	{
		m_Param1=v;
	}
	string GetParam1()
	{
		return m_Param1;
	}
	string GetParam1() const
	{
		return m_Param1;
	}
private:
	//参数2
	string m_Param2;
public:
	void SetParam2( const string& v)
	{
		m_Param2=v;
	}
	string GetParam2()
	{
		return m_Param2;
	}
	string GetParam2() const
	{
		return m_Param2;
	}

};
//帮会大厅升级请求封装类
class GuildRpcHallLvUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcHallLvUpAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcHallLvUpAskWraper(const GuildRpcHallLvUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcHallLvUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcHallLvUpAsk ToPB() const
	{
		GuildRpcHallLvUpAsk v;

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
		GuildRpcHallLvUpAsk pb;
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
	void Init(const GuildRpcHallLvUpAsk& v)
	{

	}


};
//帮会大厅升级回应封装类
class GuildRpcHallLvUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcHallLvUpReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcHallLvUpReplyWraper(const GuildRpcHallLvUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcHallLvUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcHallLvUpReply ToPB() const
	{
		GuildRpcHallLvUpReply v;
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
		GuildRpcHallLvUpReply pb;
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
	void Init(const GuildRpcHallLvUpReply& v)
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
//同步帮会公告修改通知封装类
class GuildRpcSyncNoticeOfChangeAnnouncementNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncNoticeOfChangeAnnouncementNotifyWraper()
	{
		
		m_Announcement = "";

	}
	//赋值构造函数
	GuildRpcSyncNoticeOfChangeAnnouncementNotifyWraper(const GuildRpcSyncNoticeOfChangeAnnouncementNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncNoticeOfChangeAnnouncementNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncNoticeOfChangeAnnouncementNotify ToPB() const
	{
		GuildRpcSyncNoticeOfChangeAnnouncementNotify v;
		v.set_announcement( m_Announcement );

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
		GuildRpcSyncNoticeOfChangeAnnouncementNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Announcement(公告) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>Announcement：\""+m_Announcement+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncNoticeOfChangeAnnouncementNotify& v)
	{
		m_Announcement = v.announcement();

	}

private:
	//公告
	string m_Announcement;
public:
	void SetAnnouncement( const string& v)
	{
		m_Announcement=v;
	}
	string GetAnnouncement()
	{
		return m_Announcement;
	}
	string GetAnnouncement() const
	{
		return m_Announcement;
	}

};
//通知解散通知封装类
class GuildRpcSyncNoticeOfBreakupNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncNoticeOfBreakupNotifyWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcSyncNoticeOfBreakupNotifyWraper(const GuildRpcSyncNoticeOfBreakupNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncNoticeOfBreakupNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncNoticeOfBreakupNotify ToPB() const
	{
		GuildRpcSyncNoticeOfBreakupNotify v;

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
		GuildRpcSyncNoticeOfBreakupNotify pb;
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
	void Init(const GuildRpcSyncNoticeOfBreakupNotify& v)
	{

	}


};
//进入帮会战请求封装类
class GuildRpcEnterGuildWarAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcEnterGuildWarAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcEnterGuildWarAskWraper(const GuildRpcEnterGuildWarAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcEnterGuildWarAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcEnterGuildWarAsk ToPB() const
	{
		GuildRpcEnterGuildWarAsk v;

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
		GuildRpcEnterGuildWarAsk pb;
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
	void Init(const GuildRpcEnterGuildWarAsk& v)
	{

	}


};
//进入帮会战回应封装类
class GuildRpcEnterGuildWarReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcEnterGuildWarReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcEnterGuildWarReplyWraper(const GuildRpcEnterGuildWarReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcEnterGuildWarReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcEnterGuildWarReply ToPB() const
	{
		GuildRpcEnterGuildWarReply v;
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
		GuildRpcEnterGuildWarReply pb;
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
	void Init(const GuildRpcEnterGuildWarReply& v)
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
//创建帮会战回应封装类
class GuildRpcCreateGuildWarReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcCreateGuildWarReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcCreateGuildWarReplyWraper(const GuildRpcCreateGuildWarReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcCreateGuildWarReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcCreateGuildWarReply ToPB() const
	{
		GuildRpcCreateGuildWarReply v;
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
		GuildRpcCreateGuildWarReply pb;
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
	void Init(const GuildRpcCreateGuildWarReply& v)
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
//同步帮会战是否开启通知封装类
class GuildRpcSyncNoticeOfOpenGuildWarNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncNoticeOfOpenGuildWarNotifyWraper()
	{
		
		m_GuildWar = GuildWarObjWraper();

	}
	//赋值构造函数
	GuildRpcSyncNoticeOfOpenGuildWarNotifyWraper(const GuildRpcSyncNoticeOfOpenGuildWarNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncNoticeOfOpenGuildWarNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncNoticeOfOpenGuildWarNotify ToPB() const
	{
		GuildRpcSyncNoticeOfOpenGuildWarNotify v;
		*v.mutable_guildwar()= m_GuildWar.ToPB();

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
		GuildRpcSyncNoticeOfOpenGuildWarNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GuildWar(帮会战) [GuildWarObj]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>GuildWar：</li>\r\n";
		htmlBuff += m_GuildWar.HtmlDescHeader();
		htmlBuff += m_GuildWar.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncNoticeOfOpenGuildWarNotify& v)
	{
		m_GuildWar = v.guildwar();

	}

private:
	//帮会战
	GuildWarObjWraper m_GuildWar;
public:
	void SetGuildWar( const GuildWarObjWraper& v)
	{
		m_GuildWar=v;
	}
	GuildWarObjWraper GetGuildWar()
	{
		return m_GuildWar;
	}
	GuildWarObjWraper GetGuildWar() const
	{
		return m_GuildWar;
	}

};
//帮会属性升级请求封装类
class GuildRpcGuildScienceLvUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcGuildScienceLvUpAskWraper()
	{
		
		m_ScienceId = -1;
		m_IsKeyUpLv = false;

	}
	//赋值构造函数
	GuildRpcGuildScienceLvUpAskWraper(const GuildRpcGuildScienceLvUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcGuildScienceLvUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcGuildScienceLvUpAsk ToPB() const
	{
		GuildRpcGuildScienceLvUpAsk v;
		v.set_scienceid( m_ScienceId );
		v.set_iskeyuplv( m_IsKeyUpLv );

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
		GuildRpcGuildScienceLvUpAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ScienceId(修炼id) [sint32]</li>\r\n";
		htmlBuff += "<li>IsKeyUpLv(是否一键升级) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ScienceId：%di</li>\r\n",m_ScienceId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsKeyUpLv：%di</li>\r\n",m_IsKeyUpLv);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcGuildScienceLvUpAsk& v)
	{
		m_ScienceId = v.scienceid();
		m_IsKeyUpLv = v.iskeyuplv();

	}

private:
	//修炼id
	INT32 m_ScienceId;
public:
	void SetScienceId( INT32 v)
	{
		m_ScienceId=v;
	}
	INT32 GetScienceId()
	{
		return m_ScienceId;
	}
	INT32 GetScienceId() const
	{
		return m_ScienceId;
	}
private:
	//是否一键升级
	bool m_IsKeyUpLv;
public:
	void SetIsKeyUpLv( bool v)
	{
		m_IsKeyUpLv=v;
	}
	bool GetIsKeyUpLv()
	{
		return m_IsKeyUpLv;
	}
	bool GetIsKeyUpLv() const
	{
		return m_IsKeyUpLv;
	}

};
//帮会属性升级回应封装类
class GuildRpcGuildScienceLvUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcGuildScienceLvUpReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcGuildScienceLvUpReplyWraper(const GuildRpcGuildScienceLvUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcGuildScienceLvUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcGuildScienceLvUpReply ToPB() const
	{
		GuildRpcGuildScienceLvUpReply v;
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
		GuildRpcGuildScienceLvUpReply pb;
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
	void Init(const GuildRpcGuildScienceLvUpReply& v)
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
//开启帮会修炼项目请求封装类
class GuildRpcOpenScienceAttrAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcOpenScienceAttrAskWraper()
	{
		
		m_ScienceId = -1;

	}
	//赋值构造函数
	GuildRpcOpenScienceAttrAskWraper(const GuildRpcOpenScienceAttrAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcOpenScienceAttrAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcOpenScienceAttrAsk ToPB() const
	{
		GuildRpcOpenScienceAttrAsk v;
		v.set_scienceid( m_ScienceId );

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
		GuildRpcOpenScienceAttrAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ScienceId(修炼属性id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ScienceId：%di</li>\r\n",m_ScienceId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcOpenScienceAttrAsk& v)
	{
		m_ScienceId = v.scienceid();

	}

private:
	//修炼属性id
	INT32 m_ScienceId;
public:
	void SetScienceId( INT32 v)
	{
		m_ScienceId=v;
	}
	INT32 GetScienceId()
	{
		return m_ScienceId;
	}
	INT32 GetScienceId() const
	{
		return m_ScienceId;
	}

};
//开启帮会修炼项目回应封装类
class GuildRpcOpenScienceAttrReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcOpenScienceAttrReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcOpenScienceAttrReplyWraper(const GuildRpcOpenScienceAttrReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcOpenScienceAttrReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcOpenScienceAttrReply ToPB() const
	{
		GuildRpcOpenScienceAttrReply v;
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
		GuildRpcOpenScienceAttrReply pb;
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
	void Init(const GuildRpcOpenScienceAttrReply& v)
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
//创建帮会战请求封装类
class GuildRpcCreateGuildWarAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcCreateGuildWarAskWraper()
	{
		
		m_Guild = -1;

	}
	//赋值构造函数
	GuildRpcCreateGuildWarAskWraper(const GuildRpcCreateGuildWarAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcCreateGuildWarAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcCreateGuildWarAsk ToPB() const
	{
		GuildRpcCreateGuildWarAsk v;
		v.set_guild( m_Guild );

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
		GuildRpcCreateGuildWarAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Guild(对方的帮会) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Guild：%di</li>\r\n",m_Guild);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcCreateGuildWarAsk& v)
	{
		m_Guild = v.guild();

	}

private:
	//对方的帮会
	INT32 m_Guild;
public:
	void SetGuild( INT32 v)
	{
		m_Guild=v;
	}
	INT32 GetGuild()
	{
		return m_Guild;
	}
	INT32 GetGuild() const
	{
		return m_Guild;
	}

};
//申请入帮，帮主处理回应封装类
class GuildRpcApplyGuildHandleReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcApplyGuildHandleReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcApplyGuildHandleReplyWraper(const GuildRpcApplyGuildHandleReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcApplyGuildHandleReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcApplyGuildHandleReply ToPB() const
	{
		GuildRpcApplyGuildHandleReply v;
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
		GuildRpcApplyGuildHandleReply pb;
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
	void Init(const GuildRpcApplyGuildHandleReply& v)
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
//创建帮会副本请求封装类
class GuildRpcCreateGuildDungeonAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcCreateGuildDungeonAskWraper()
	{
		
		m_DungeonNum = -1;

	}
	//赋值构造函数
	GuildRpcCreateGuildDungeonAskWraper(const GuildRpcCreateGuildDungeonAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcCreateGuildDungeonAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcCreateGuildDungeonAsk ToPB() const
	{
		GuildRpcCreateGuildDungeonAsk v;
		v.set_dungeonnum( m_DungeonNum );

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
		GuildRpcCreateGuildDungeonAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DungeonNum(副本数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>DungeonNum：%di</li>\r\n",m_DungeonNum);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcCreateGuildDungeonAsk& v)
	{
		m_DungeonNum = v.dungeonnum();

	}

private:
	//副本数量
	INT32 m_DungeonNum;
public:
	void SetDungeonNum( INT32 v)
	{
		m_DungeonNum=v;
	}
	INT32 GetDungeonNum()
	{
		return m_DungeonNum;
	}
	INT32 GetDungeonNum() const
	{
		return m_DungeonNum;
	}

};
//同步练武堂升级通知封装类
class GuildRpcSyncNoticeOfKongfuHallLvUpNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncNoticeOfKongfuHallLvUpNotifyWraper()
	{
		
		m_Lv = -1;
		m_Time = -1;

	}
	//赋值构造函数
	GuildRpcSyncNoticeOfKongfuHallLvUpNotifyWraper(const GuildRpcSyncNoticeOfKongfuHallLvUpNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncNoticeOfKongfuHallLvUpNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncNoticeOfKongfuHallLvUpNotify ToPB() const
	{
		GuildRpcSyncNoticeOfKongfuHallLvUpNotify v;
		v.set_lv( m_Lv );
		v.set_time( m_Time );

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
		GuildRpcSyncNoticeOfKongfuHallLvUpNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Lv(当前等级) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(开始时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Lv：%di</li>\r\n",m_Lv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncNoticeOfKongfuHallLvUpNotify& v)
	{
		m_Lv = v.lv();
		m_Time = v.time();

	}

private:
	//当前等级
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
	//开始时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}

};
//申请入帮，帮主处理请求封装类
class GuildRpcApplyGuildHandleAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcApplyGuildHandleAskWraper()
	{
		
		m_UserId = -1;
		m_Oper = 0;

	}
	//赋值构造函数
	GuildRpcApplyGuildHandleAskWraper(const GuildRpcApplyGuildHandleAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcApplyGuildHandleAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcApplyGuildHandleAsk ToPB() const
	{
		GuildRpcApplyGuildHandleAsk v;
		v.set_userid( m_UserId );
		v.set_oper( m_Oper );

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
		GuildRpcApplyGuildHandleAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>Oper(0是同意1是拒绝) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Oper：%di</li>\r\n",m_Oper);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcApplyGuildHandleAsk& v)
	{
		m_UserId = v.userid();
		m_Oper = v.oper();

	}

private:
	//用户Id
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
	//0是同意1是拒绝
	INT32 m_Oper;
public:
	void SetOper( INT32 v)
	{
		m_Oper=v;
	}
	INT32 GetOper()
	{
		return m_Oper;
	}
	INT32 GetOper() const
	{
		return m_Oper;
	}

};
//进入帮会副本回应封装类
class GuildRpcEnterGuildDungeonReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcEnterGuildDungeonReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcEnterGuildDungeonReplyWraper(const GuildRpcEnterGuildDungeonReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcEnterGuildDungeonReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcEnterGuildDungeonReply ToPB() const
	{
		GuildRpcEnterGuildDungeonReply v;
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
		GuildRpcEnterGuildDungeonReply pb;
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
	void Init(const GuildRpcEnterGuildDungeonReply& v)
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
//同步帮会副本创建通知封装类
class GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotifyWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotifyWraper(const GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotify ToPB() const
	{
		GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotify v;
		v.mutable_dungeonlist()->Reserve(m_DungeonList.size());
		for (int i=0; i<(int)m_DungeonList.size(); i++)
		{
			*v.add_dungeonlist() = m_DungeonList[i].ToPB();
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
		GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DungeonList(副本列表) [GuildDungeonObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>DungeonList：</li>\r\n";
		if( m_DungeonList.size()>0) htmlBuff += m_DungeonList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_DungeonList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_DungeonList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotify& v)
	{
		m_DungeonList.clear();
		m_DungeonList.reserve(v.dungeonlist_size());
		for( int i=0; i<v.dungeonlist_size(); i++)
			m_DungeonList.push_back(v.dungeonlist(i));

	}

private:
	//副本列表
	vector<GuildDungeonObjWraper> m_DungeonList;
public:
	int SizeDungeonList()
	{
		return m_DungeonList.size();
	}
	const vector<GuildDungeonObjWraper>& GetDungeonList() const
	{
		return m_DungeonList;
	}
	GuildDungeonObjWraper GetDungeonList(int Index) const
	{
		if(Index<0 || Index>=(int)m_DungeonList.size())
		{
			assert(false);
			return GuildDungeonObjWraper();
		}
		return m_DungeonList[Index];
	}
	void SetDungeonList( const vector<GuildDungeonObjWraper>& v )
	{
		m_DungeonList=v;
	}
	void ClearDungeonList( )
	{
		m_DungeonList.clear();
	}
	void SetDungeonList( int Index, const GuildDungeonObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_DungeonList.size())
		{
			assert(false);
			return;
		}
		m_DungeonList[Index] = v;
	}
	void AddDungeonList( const GuildDungeonObjWraper& v )
	{
		m_DungeonList.push_back(v);
	}

};
//创建帮会副本回应封装类
class GuildRpcCreateGuildDungeonReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcCreateGuildDungeonReplyWraper()
	{
		
		m_Result = -9999;
		m_DungeonNum = -1;

	}
	//赋值构造函数
	GuildRpcCreateGuildDungeonReplyWraper(const GuildRpcCreateGuildDungeonReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcCreateGuildDungeonReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcCreateGuildDungeonReply ToPB() const
	{
		GuildRpcCreateGuildDungeonReply v;
		v.set_result( m_Result );
		v.set_dungeonnum( m_DungeonNum );

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
		GuildRpcCreateGuildDungeonReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>DungeonNum(创建成功的副本数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DungeonNum：%di</li>\r\n",m_DungeonNum);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcCreateGuildDungeonReply& v)
	{
		m_Result = v.result();
		m_DungeonNum = v.dungeonnum();

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
	//创建成功的副本数量
	INT32 m_DungeonNum;
public:
	void SetDungeonNum( INT32 v)
	{
		m_DungeonNum=v;
	}
	INT32 GetDungeonNum()
	{
		return m_DungeonNum;
	}
	INT32 GetDungeonNum() const
	{
		return m_DungeonNum;
	}

};
//进入帮会副本请求封装类
class GuildRpcEnterGuildDungeonAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcEnterGuildDungeonAskWraper()
	{
		
		m_Index = -1;

	}
	//赋值构造函数
	GuildRpcEnterGuildDungeonAskWraper(const GuildRpcEnterGuildDungeonAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcEnterGuildDungeonAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcEnterGuildDungeonAsk ToPB() const
	{
		GuildRpcEnterGuildDungeonAsk v;
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
		GuildRpcEnterGuildDungeonAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Index(帮会副本下标) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Index：%di</li>\r\n",m_Index);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcEnterGuildDungeonAsk& v)
	{
		m_Index = v.index();

	}

private:
	//帮会副本下标
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
//修改公告请求封装类
class GuildRpcChangeAnnouncementAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcChangeAnnouncementAskWraper()
	{
		
		m_Announcement = "";

	}
	//赋值构造函数
	GuildRpcChangeAnnouncementAskWraper(const GuildRpcChangeAnnouncementAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcChangeAnnouncementAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcChangeAnnouncementAsk ToPB() const
	{
		GuildRpcChangeAnnouncementAsk v;
		v.set_announcement( m_Announcement );

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
		GuildRpcChangeAnnouncementAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Announcement(公告) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>Announcement：\""+m_Announcement+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcChangeAnnouncementAsk& v)
	{
		m_Announcement = v.announcement();

	}

private:
	//公告
	string m_Announcement;
public:
	void SetAnnouncement( const string& v)
	{
		m_Announcement=v;
	}
	string GetAnnouncement()
	{
		return m_Announcement;
	}
	string GetAnnouncement() const
	{
		return m_Announcement;
	}

};
//修改公告回应封装类
class GuildRpcChangeAnnouncementReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcChangeAnnouncementReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcChangeAnnouncementReplyWraper(const GuildRpcChangeAnnouncementReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcChangeAnnouncementReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcChangeAnnouncementReply ToPB() const
	{
		GuildRpcChangeAnnouncementReply v;
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
		GuildRpcChangeAnnouncementReply pb;
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
	void Init(const GuildRpcChangeAnnouncementReply& v)
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
//修改帮会名字请求封装类
class GuildRpcChangeGuildNameAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcChangeGuildNameAskWraper()
	{
		
		m_GuildName = "";

	}
	//赋值构造函数
	GuildRpcChangeGuildNameAskWraper(const GuildRpcChangeGuildNameAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcChangeGuildNameAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcChangeGuildNameAsk ToPB() const
	{
		GuildRpcChangeGuildNameAsk v;
		v.set_guildname( m_GuildName );

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
		GuildRpcChangeGuildNameAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GuildName(帮派名字) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>GuildName：\""+m_GuildName+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcChangeGuildNameAsk& v)
	{
		m_GuildName = v.guildname();

	}

private:
	//帮派名字
	string m_GuildName;
public:
	void SetGuildName( const string& v)
	{
		m_GuildName=v;
	}
	string GetGuildName()
	{
		return m_GuildName;
	}
	string GetGuildName() const
	{
		return m_GuildName;
	}

};
//修改帮会名字回应封装类
class GuildRpcChangeGuildNameReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcChangeGuildNameReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcChangeGuildNameReplyWraper(const GuildRpcChangeGuildNameReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcChangeGuildNameReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcChangeGuildNameReply ToPB() const
	{
		GuildRpcChangeGuildNameReply v;
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
		GuildRpcChangeGuildNameReply pb;
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
	void Init(const GuildRpcChangeGuildNameReply& v)
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
//任命职位请求封装类
class GuildRpcAppointDutyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAppointDutyAskWraper()
	{
		
		m_UserId = -1;
		m_Duty = -1;

	}
	//赋值构造函数
	GuildRpcAppointDutyAskWraper(const GuildRpcAppointDutyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAppointDutyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAppointDutyAsk ToPB() const
	{
		GuildRpcAppointDutyAsk v;
		v.set_userid( m_UserId );
		v.set_duty( m_Duty );

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
		GuildRpcAppointDutyAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>Duty(职位) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Duty：%di</li>\r\n",m_Duty);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcAppointDutyAsk& v)
	{
		m_UserId = v.userid();
		m_Duty = v.duty();

	}

private:
	//用户Id
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
	//职位
	INT32 m_Duty;
public:
	void SetDuty( INT32 v)
	{
		m_Duty=v;
	}
	INT32 GetDuty()
	{
		return m_Duty;
	}
	INT32 GetDuty() const
	{
		return m_Duty;
	}

};
//任命职位回应封装类
class GuildRpcAppointDutyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAppointDutyReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcAppointDutyReplyWraper(const GuildRpcAppointDutyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAppointDutyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAppointDutyReply ToPB() const
	{
		GuildRpcAppointDutyReply v;
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
		GuildRpcAppointDutyReply pb;
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
	void Init(const GuildRpcAppointDutyReply& v)
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
//请求帮会列表请求封装类
class GuildRpcReqGuildListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcReqGuildListAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcReqGuildListAskWraper(const GuildRpcReqGuildListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcReqGuildListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcReqGuildListAsk ToPB() const
	{
		GuildRpcReqGuildListAsk v;

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
		GuildRpcReqGuildListAsk pb;
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
	void Init(const GuildRpcReqGuildListAsk& v)
	{

	}


};
//请求帮会列表回应封装类
class GuildRpcReqGuildListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcReqGuildListReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcReqGuildListReplyWraper(const GuildRpcReqGuildListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcReqGuildListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcReqGuildListReply ToPB() const
	{
		GuildRpcReqGuildListReply v;
		v.set_result( m_Result );
		v.mutable_guildlist()->Reserve(m_GuildList.size());
		for (int i=0; i<(int)m_GuildList.size(); i++)
		{
			*v.add_guildlist() = m_GuildList[i].ToPB();
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
		GuildRpcReqGuildListReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildList(帮会列表) [GuildListObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>GuildList：</li>\r\n";
		if( m_GuildList.size()>0) htmlBuff += m_GuildList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_GuildList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_GuildList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcReqGuildListReply& v)
	{
		m_Result = v.result();
		m_GuildList.clear();
		m_GuildList.reserve(v.guildlist_size());
		for( int i=0; i<v.guildlist_size(); i++)
			m_GuildList.push_back(v.guildlist(i));

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
	//帮会列表
	vector<GuildListObjWraper> m_GuildList;
public:
	int SizeGuildList()
	{
		return m_GuildList.size();
	}
	const vector<GuildListObjWraper>& GetGuildList() const
	{
		return m_GuildList;
	}
	GuildListObjWraper GetGuildList(int Index) const
	{
		if(Index<0 || Index>=(int)m_GuildList.size())
		{
			assert(false);
			return GuildListObjWraper();
		}
		return m_GuildList[Index];
	}
	void SetGuildList( const vector<GuildListObjWraper>& v )
	{
		m_GuildList=v;
	}
	void ClearGuildList( )
	{
		m_GuildList.clear();
	}
	void SetGuildList( int Index, const GuildListObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_GuildList.size())
		{
			assert(false);
			return;
		}
		m_GuildList[Index] = v;
	}
	void AddGuildList( const GuildListObjWraper& v )
	{
		m_GuildList.push_back(v);
	}

};
//快速申请回应封装类
class GuildRpcQuickApplyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcQuickApplyReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcQuickApplyReplyWraper(const GuildRpcQuickApplyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcQuickApplyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcQuickApplyReply ToPB() const
	{
		GuildRpcQuickApplyReply v;
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
		GuildRpcQuickApplyReply pb;
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
	void Init(const GuildRpcQuickApplyReply& v)
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
//登陆后，同步一次数据回应封装类
class GuildRpcSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncDataReplyWraper()
	{
		
		m_Result = -9999;
		m_GuildData = GuildInfoObjWraper();

	}
	//赋值构造函数
	GuildRpcSyncDataReplyWraper(const GuildRpcSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncDataReply ToPB() const
	{
		GuildRpcSyncDataReply v;
		v.set_result( m_Result );
		*v.mutable_guilddata()= m_GuildData.ToPB();

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
		GuildRpcSyncDataReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildData(帮会数据) [GuildInfoObj]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>GuildData：</li>\r\n";
		htmlBuff += m_GuildData.HtmlDescHeader();
		htmlBuff += m_GuildData.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncDataReply& v)
	{
		m_Result = v.result();
		m_GuildData = v.guilddata();

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
	//帮会数据
	GuildInfoObjWraper m_GuildData;
public:
	void SetGuildData( const GuildInfoObjWraper& v)
	{
		m_GuildData=v;
	}
	GuildInfoObjWraper GetGuildData()
	{
		return m_GuildData;
	}
	GuildInfoObjWraper GetGuildData() const
	{
		return m_GuildData;
	}

};
//创建帮会请求封装类
class GuildRpcCreateGuildAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcCreateGuildAskWraper()
	{
		
		m_GuildName = "";
		m_Announcement = "";

	}
	//赋值构造函数
	GuildRpcCreateGuildAskWraper(const GuildRpcCreateGuildAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcCreateGuildAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcCreateGuildAsk ToPB() const
	{
		GuildRpcCreateGuildAsk v;
		v.set_guildname( m_GuildName );
		v.set_announcement( m_Announcement );

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
		GuildRpcCreateGuildAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GuildName(帮派名字) [string]</li>\r\n";
		htmlBuff += "<li>Announcement(公告) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>GuildName：\""+m_GuildName+"\"</li>\r\n";
		htmlBuff += "<li>Announcement：\""+m_Announcement+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcCreateGuildAsk& v)
	{
		m_GuildName = v.guildname();
		m_Announcement = v.announcement();

	}

private:
	//帮派名字
	string m_GuildName;
public:
	void SetGuildName( const string& v)
	{
		m_GuildName=v;
	}
	string GetGuildName()
	{
		return m_GuildName;
	}
	string GetGuildName() const
	{
		return m_GuildName;
	}
private:
	//公告
	string m_Announcement;
public:
	void SetAnnouncement( const string& v)
	{
		m_Announcement=v;
	}
	string GetAnnouncement()
	{
		return m_Announcement;
	}
	string GetAnnouncement() const
	{
		return m_Announcement;
	}

};
//登陆后，同步一次数据请求封装类
class GuildRpcSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcSyncDataAskWraper(const GuildRpcSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncDataAsk ToPB() const
	{
		GuildRpcSyncDataAsk v;

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
		GuildRpcSyncDataAsk pb;
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
	void Init(const GuildRpcSyncDataAsk& v)
	{

	}


};
//申请入帮回应封装类
class GuildRpcApplyGuildReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcApplyGuildReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcApplyGuildReplyWraper(const GuildRpcApplyGuildReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcApplyGuildReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcApplyGuildReply ToPB() const
	{
		GuildRpcApplyGuildReply v;
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
		GuildRpcApplyGuildReply pb;
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
	void Init(const GuildRpcApplyGuildReply& v)
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
//快速申请请求封装类
class GuildRpcQuickApplyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcQuickApplyAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcQuickApplyAskWraper(const GuildRpcQuickApplyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcQuickApplyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcQuickApplyAsk ToPB() const
	{
		GuildRpcQuickApplyAsk v;

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
		GuildRpcQuickApplyAsk pb;
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
	void Init(const GuildRpcQuickApplyAsk& v)
	{

	}


};
//创建帮会回应封装类
class GuildRpcCreateGuildReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcCreateGuildReplyWraper()
	{
		
		m_Result = -9999;
		m_GuildData = GuildInfoObjWraper();

	}
	//赋值构造函数
	GuildRpcCreateGuildReplyWraper(const GuildRpcCreateGuildReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcCreateGuildReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcCreateGuildReply ToPB() const
	{
		GuildRpcCreateGuildReply v;
		v.set_result( m_Result );
		*v.mutable_guilddata()= m_GuildData.ToPB();

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
		GuildRpcCreateGuildReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildData(帮会数据) [GuildInfoObj]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>GuildData：</li>\r\n";
		htmlBuff += m_GuildData.HtmlDescHeader();
		htmlBuff += m_GuildData.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcCreateGuildReply& v)
	{
		m_Result = v.result();
		m_GuildData = v.guilddata();

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
	//帮会数据
	GuildInfoObjWraper m_GuildData;
public:
	void SetGuildData( const GuildInfoObjWraper& v)
	{
		m_GuildData=v;
	}
	GuildInfoObjWraper GetGuildData()
	{
		return m_GuildData;
	}
	GuildInfoObjWraper GetGuildData() const
	{
		return m_GuildData;
	}

};
//申请入帮请求封装类
class GuildRpcApplyGuildAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcApplyGuildAskWraper()
	{
		
		m_Guild = -1;
		m_Oper = 0;

	}
	//赋值构造函数
	GuildRpcApplyGuildAskWraper(const GuildRpcApplyGuildAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcApplyGuildAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcApplyGuildAsk ToPB() const
	{
		GuildRpcApplyGuildAsk v;
		v.set_guild( m_Guild );
		v.set_oper( m_Oper );

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
		GuildRpcApplyGuildAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Guild(帮派Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Oper(0是申请1是取消) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Guild：%di</li>\r\n",m_Guild);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Oper：%di</li>\r\n",m_Oper);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcApplyGuildAsk& v)
	{
		m_Guild = v.guild();
		m_Oper = v.oper();

	}

private:
	//帮派Id
	INT32 m_Guild;
public:
	void SetGuild( INT32 v)
	{
		m_Guild=v;
	}
	INT32 GetGuild()
	{
		return m_Guild;
	}
	INT32 GetGuild() const
	{
		return m_Guild;
	}
private:
	//0是申请1是取消
	INT32 m_Oper;
public:
	void SetOper( INT32 v)
	{
		m_Oper=v;
	}
	INT32 GetOper()
	{
		return m_Oper;
	}
	INT32 GetOper() const
	{
		return m_Oper;
	}

};
//辞职请求封装类
class GuildRpcResignDutyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcResignDutyAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcResignDutyAskWraper(const GuildRpcResignDutyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcResignDutyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcResignDutyAsk ToPB() const
	{
		GuildRpcResignDutyAsk v;

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
		GuildRpcResignDutyAsk pb;
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
	void Init(const GuildRpcResignDutyAsk& v)
	{

	}


};
//辞职回应封装类
class GuildRpcResignDutyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcResignDutyReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcResignDutyReplyWraper(const GuildRpcResignDutyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcResignDutyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcResignDutyReply ToPB() const
	{
		GuildRpcResignDutyReply v;
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
		GuildRpcResignDutyReply pb;
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
	void Init(const GuildRpcResignDutyReply& v)
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
//被邀请处理请求封装类
class GuildRpcBeInvitedHandleAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcBeInvitedHandleAskWraper()
	{
		
		m_Guild = -1;
		m_Oper = 0;

	}
	//赋值构造函数
	GuildRpcBeInvitedHandleAskWraper(const GuildRpcBeInvitedHandleAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcBeInvitedHandleAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcBeInvitedHandleAsk ToPB() const
	{
		GuildRpcBeInvitedHandleAsk v;
		v.set_guild( m_Guild );
		v.set_oper( m_Oper );

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
		GuildRpcBeInvitedHandleAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Guild(帮派Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Oper(0是同意1是拒绝) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Guild：%di</li>\r\n",m_Guild);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Oper：%di</li>\r\n",m_Oper);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcBeInvitedHandleAsk& v)
	{
		m_Guild = v.guild();
		m_Oper = v.oper();

	}

private:
	//帮派Id
	INT32 m_Guild;
public:
	void SetGuild( INT32 v)
	{
		m_Guild=v;
	}
	INT32 GetGuild()
	{
		return m_Guild;
	}
	INT32 GetGuild() const
	{
		return m_Guild;
	}
private:
	//0是同意1是拒绝
	INT32 m_Oper;
public:
	void SetOper( INT32 v)
	{
		m_Oper=v;
	}
	INT32 GetOper()
	{
		return m_Oper;
	}
	INT32 GetOper() const
	{
		return m_Oper;
	}

};
//被邀请处理回应封装类
class GuildRpcBeInvitedHandleReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcBeInvitedHandleReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcBeInvitedHandleReplyWraper(const GuildRpcBeInvitedHandleReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcBeInvitedHandleReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcBeInvitedHandleReply ToPB() const
	{
		GuildRpcBeInvitedHandleReply v;
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
		GuildRpcBeInvitedHandleReply pb;
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
	void Init(const GuildRpcBeInvitedHandleReply& v)
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
//同步帮会成员数据变化通知封装类
class GuildRpcSyncNoticeOfGuildMemberChangeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncNoticeOfGuildMemberChangeNotifyWraper()
	{
		
		m_GuildMember = GuildMemberObjWraper();

	}
	//赋值构造函数
	GuildRpcSyncNoticeOfGuildMemberChangeNotifyWraper(const GuildRpcSyncNoticeOfGuildMemberChangeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncNoticeOfGuildMemberChangeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncNoticeOfGuildMemberChangeNotify ToPB() const
	{
		GuildRpcSyncNoticeOfGuildMemberChangeNotify v;
		*v.mutable_guildmember()= m_GuildMember.ToPB();

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
		GuildRpcSyncNoticeOfGuildMemberChangeNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GuildMember(帮会成员) [GuildMemberObj]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>GuildMember：</li>\r\n";
		htmlBuff += m_GuildMember.HtmlDescHeader();
		htmlBuff += m_GuildMember.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncNoticeOfGuildMemberChangeNotify& v)
	{
		m_GuildMember = v.guildmember();

	}

private:
	//帮会成员
	GuildMemberObjWraper m_GuildMember;
public:
	void SetGuildMember( const GuildMemberObjWraper& v)
	{
		m_GuildMember=v;
	}
	GuildMemberObjWraper GetGuildMember()
	{
		return m_GuildMember;
	}
	GuildMemberObjWraper GetGuildMember() const
	{
		return m_GuildMember;
	}

};
//同步帮会增加成员通知封装类
class GuildRpcSyncNoticeOfAddMemberNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncNoticeOfAddMemberNotifyWraper()
	{
		
		m_GuildMember = GuildMemberObjWraper();

	}
	//赋值构造函数
	GuildRpcSyncNoticeOfAddMemberNotifyWraper(const GuildRpcSyncNoticeOfAddMemberNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncNoticeOfAddMemberNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncNoticeOfAddMemberNotify ToPB() const
	{
		GuildRpcSyncNoticeOfAddMemberNotify v;
		*v.mutable_guildmember()= m_GuildMember.ToPB();

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
		GuildRpcSyncNoticeOfAddMemberNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GuildMember(帮会成员) [GuildMemberObj]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>GuildMember：</li>\r\n";
		htmlBuff += m_GuildMember.HtmlDescHeader();
		htmlBuff += m_GuildMember.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncNoticeOfAddMemberNotify& v)
	{
		m_GuildMember = v.guildmember();

	}

private:
	//帮会成员
	GuildMemberObjWraper m_GuildMember;
public:
	void SetGuildMember( const GuildMemberObjWraper& v)
	{
		m_GuildMember=v;
	}
	GuildMemberObjWraper GetGuildMember()
	{
		return m_GuildMember;
	}
	GuildMemberObjWraper GetGuildMember() const
	{
		return m_GuildMember;
	}

};
//发送我的帮会数据通知封装类
class GuildRpcSyncMyTeamDataNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncMyTeamDataNotifyWraper()
	{
		
		m_GuildData = GuildInfoObjWraper();

	}
	//赋值构造函数
	GuildRpcSyncMyTeamDataNotifyWraper(const GuildRpcSyncMyTeamDataNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncMyTeamDataNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncMyTeamDataNotify ToPB() const
	{
		GuildRpcSyncMyTeamDataNotify v;
		*v.mutable_guilddata()= m_GuildData.ToPB();

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
		GuildRpcSyncMyTeamDataNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GuildData(帮会数据) [GuildInfoObj]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>GuildData：</li>\r\n";
		htmlBuff += m_GuildData.HtmlDescHeader();
		htmlBuff += m_GuildData.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncMyTeamDataNotify& v)
	{
		m_GuildData = v.guilddata();

	}

private:
	//帮会数据
	GuildInfoObjWraper m_GuildData;
public:
	void SetGuildData( const GuildInfoObjWraper& v)
	{
		m_GuildData=v;
	}
	GuildInfoObjWraper GetGuildData()
	{
		return m_GuildData;
	}
	GuildInfoObjWraper GetGuildData() const
	{
		return m_GuildData;
	}

};
//同步帮会基础数据通知封装类
class GuildRpcSyncNoticeOfGuildBaseDataNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSyncNoticeOfGuildBaseDataNotifyWraper()
	{
		
		m_GuildName = "";
		m_Level = 1;
		m_CaptainId = -1;
		m_CaptainName = "";
		m_Funds = -1;
		m_LeagueMatchesRank = -1;

	}
	//赋值构造函数
	GuildRpcSyncNoticeOfGuildBaseDataNotifyWraper(const GuildRpcSyncNoticeOfGuildBaseDataNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSyncNoticeOfGuildBaseDataNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSyncNoticeOfGuildBaseDataNotify ToPB() const
	{
		GuildRpcSyncNoticeOfGuildBaseDataNotify v;
		v.set_guildname( m_GuildName );
		v.set_level( m_Level );
		v.set_captainid( m_CaptainId );
		v.set_captainname( m_CaptainName );
		v.set_funds( m_Funds );
		v.set_leaguematchesrank( m_LeagueMatchesRank );

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
		GuildRpcSyncNoticeOfGuildBaseDataNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GuildName(帮派名字) [string]</li>\r\n";
		htmlBuff += "<li>Level(等级) [sint32]</li>\r\n";
		htmlBuff += "<li>CaptainId(帮主Id) [sint64]</li>\r\n";
		htmlBuff += "<li>CaptainName(帮主名字) [string]</li>\r\n";
		htmlBuff += "<li>Funds(资金) [sint32]</li>\r\n";
		htmlBuff += "<li>LeagueMatchesRank(联赛排名) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>GuildName：\""+m_GuildName+"\"</li>\r\n";
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CaptainId：%lldL</li>\r\n",m_CaptainId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>CaptainName：\""+m_CaptainName+"\"</li>\r\n";
		tmpLine.Fmt("<li>Funds：%di</li>\r\n",m_Funds);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>LeagueMatchesRank：%di</li>\r\n",m_LeagueMatchesRank);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcSyncNoticeOfGuildBaseDataNotify& v)
	{
		m_GuildName = v.guildname();
		m_Level = v.level();
		m_CaptainId = v.captainid();
		m_CaptainName = v.captainname();
		m_Funds = v.funds();
		m_LeagueMatchesRank = v.leaguematchesrank();

	}

private:
	//帮派名字
	string m_GuildName;
public:
	void SetGuildName( const string& v)
	{
		m_GuildName=v;
	}
	string GetGuildName()
	{
		return m_GuildName;
	}
	string GetGuildName() const
	{
		return m_GuildName;
	}
private:
	//等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//帮主Id
	INT64 m_CaptainId;
public:
	void SetCaptainId( INT64 v)
	{
		m_CaptainId=v;
	}
	INT64 GetCaptainId()
	{
		return m_CaptainId;
	}
	INT64 GetCaptainId() const
	{
		return m_CaptainId;
	}
private:
	//帮主名字
	string m_CaptainName;
public:
	void SetCaptainName( const string& v)
	{
		m_CaptainName=v;
	}
	string GetCaptainName()
	{
		return m_CaptainName;
	}
	string GetCaptainName() const
	{
		return m_CaptainName;
	}
private:
	//资金
	INT32 m_Funds;
public:
	void SetFunds( INT32 v)
	{
		m_Funds=v;
	}
	INT32 GetFunds()
	{
		return m_Funds;
	}
	INT32 GetFunds() const
	{
		return m_Funds;
	}
private:
	//联赛排名
	INT32 m_LeagueMatchesRank;
public:
	void SetLeagueMatchesRank( INT32 v)
	{
		m_LeagueMatchesRank=v;
	}
	INT32 GetLeagueMatchesRank()
	{
		return m_LeagueMatchesRank;
	}
	INT32 GetLeagueMatchesRank() const
	{
		return m_LeagueMatchesRank;
	}

};
//被邀请提示通知封装类
class GuildRpcBeInvitedNoticeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcBeInvitedNoticeNotifyWraper()
	{
		
		m_UserId = -1;
		m_Guild = -1;
		m_GuildName = "";

	}
	//赋值构造函数
	GuildRpcBeInvitedNoticeNotifyWraper(const GuildRpcBeInvitedNoticeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcBeInvitedNoticeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcBeInvitedNoticeNotify ToPB() const
	{
		GuildRpcBeInvitedNoticeNotify v;
		v.set_userid( m_UserId );
		v.set_guild( m_Guild );
		v.set_guildname( m_GuildName );

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
		GuildRpcBeInvitedNoticeNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>Guild(帮派Id) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildName(帮派名字) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Guild：%di</li>\r\n",m_Guild);
		htmlBuff += tmpLine;
		htmlBuff += "<li>GuildName：\""+m_GuildName+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcBeInvitedNoticeNotify& v)
	{
		m_UserId = v.userid();
		m_Guild = v.guild();
		m_GuildName = v.guildname();

	}

private:
	//用户Id
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
	//帮派Id
	INT32 m_Guild;
public:
	void SetGuild( INT32 v)
	{
		m_Guild=v;
	}
	INT32 GetGuild()
	{
		return m_Guild;
	}
	INT32 GetGuild() const
	{
		return m_Guild;
	}
private:
	//帮派名字
	string m_GuildName;
public:
	void SetGuildName( const string& v)
	{
		m_GuildName=v;
	}
	string GetGuildName()
	{
		return m_GuildName;
	}
	string GetGuildName() const
	{
		return m_GuildName;
	}

};
//退出帮会请求封装类
class GuildRpcExitGuildAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcExitGuildAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcExitGuildAskWraper(const GuildRpcExitGuildAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcExitGuildAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcExitGuildAsk ToPB() const
	{
		GuildRpcExitGuildAsk v;

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
		GuildRpcExitGuildAsk pb;
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
	void Init(const GuildRpcExitGuildAsk& v)
	{

	}


};
//退出帮会回应封装类
class GuildRpcExitGuildReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcExitGuildReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcExitGuildReplyWraper(const GuildRpcExitGuildReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcExitGuildReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcExitGuildReply ToPB() const
	{
		GuildRpcExitGuildReply v;
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
		GuildRpcExitGuildReply pb;
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
	void Init(const GuildRpcExitGuildReply& v)
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
//踢人请求封装类
class GuildRpcKickoutAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcKickoutAskWraper()
	{
		
		m_UserId = -1;

	}
	//赋值构造函数
	GuildRpcKickoutAskWraper(const GuildRpcKickoutAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcKickoutAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcKickoutAsk ToPB() const
	{
		GuildRpcKickoutAsk v;
		v.set_userid( m_UserId );

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
		GuildRpcKickoutAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcKickoutAsk& v)
	{
		m_UserId = v.userid();

	}

private:
	//用户Id
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

};
//踢人回应封装类
class GuildRpcKickoutReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcKickoutReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcKickoutReplyWraper(const GuildRpcKickoutReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcKickoutReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcKickoutReply ToPB() const
	{
		GuildRpcKickoutReply v;
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
		GuildRpcKickoutReply pb;
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
	void Init(const GuildRpcKickoutReply& v)
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
//邀请入帮请求封装类
class GuildRpcInviteToJoinAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcInviteToJoinAskWraper()
	{
		
		m_UserId = -1;

	}
	//赋值构造函数
	GuildRpcInviteToJoinAskWraper(const GuildRpcInviteToJoinAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcInviteToJoinAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcInviteToJoinAsk ToPB() const
	{
		GuildRpcInviteToJoinAsk v;
		v.set_userid( m_UserId );

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
		GuildRpcInviteToJoinAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildRpcInviteToJoinAsk& v)
	{
		m_UserId = v.userid();

	}

private:
	//用户Id
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

};
//邀请入帮回应封装类
class GuildRpcInviteToJoinReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcInviteToJoinReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcInviteToJoinReplyWraper(const GuildRpcInviteToJoinReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcInviteToJoinReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcInviteToJoinReply ToPB() const
	{
		GuildRpcInviteToJoinReply v;
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
		GuildRpcInviteToJoinReply pb;
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
	void Init(const GuildRpcInviteToJoinReply& v)
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
//解散帮会请求封装类
class GuildRpcBreakUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcBreakUpAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcBreakUpAskWraper(const GuildRpcBreakUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcBreakUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcBreakUpAsk ToPB() const
	{
		GuildRpcBreakUpAsk v;

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
		GuildRpcBreakUpAsk pb;
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
	void Init(const GuildRpcBreakUpAsk& v)
	{

	}


};
//解散帮会回应封装类
class GuildRpcBreakUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcBreakUpReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	GuildRpcBreakUpReplyWraper(const GuildRpcBreakUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcBreakUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcBreakUpReply ToPB() const
	{
		GuildRpcBreakUpReply v;
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
		GuildRpcBreakUpReply pb;
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
	void Init(const GuildRpcBreakUpReply& v)
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
template<> struct MessageIdT<GuildRpcSyncDataAskWraper>{ enum{ID=RPC_CODE_GUILD_SYNCDATA_REQUEST};};
template<> struct MessageIdT<GuildRpcSyncDataReplyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCDATA_REQUEST};};
template<> struct MessageIdT<GuildRpcCreateGuildAskWraper>{ enum{ID=RPC_CODE_GUILD_CREATEGUILD_REQUEST};};
template<> struct MessageIdT<GuildRpcCreateGuildReplyWraper>{ enum{ID=RPC_CODE_GUILD_CREATEGUILD_REQUEST};};
template<> struct MessageIdT<GuildRpcApplyGuildAskWraper>{ enum{ID=RPC_CODE_GUILD_APPLYGUILD_REQUEST};};
template<> struct MessageIdT<GuildRpcApplyGuildReplyWraper>{ enum{ID=RPC_CODE_GUILD_APPLYGUILD_REQUEST};};
template<> struct MessageIdT<GuildRpcQuickApplyAskWraper>{ enum{ID=RPC_CODE_GUILD_QUICKAPPLY_REQUEST};};
template<> struct MessageIdT<GuildRpcQuickApplyReplyWraper>{ enum{ID=RPC_CODE_GUILD_QUICKAPPLY_REQUEST};};
template<> struct MessageIdT<GuildRpcChangeGuildNameAskWraper>{ enum{ID=RPC_CODE_GUILD_CHANGEGUILDNAME_REQUEST};};
template<> struct MessageIdT<GuildRpcChangeGuildNameReplyWraper>{ enum{ID=RPC_CODE_GUILD_CHANGEGUILDNAME_REQUEST};};
template<> struct MessageIdT<GuildRpcChangeAnnouncementAskWraper>{ enum{ID=RPC_CODE_GUILD_CHANGEANNOUNCEMENT_REQUEST};};
template<> struct MessageIdT<GuildRpcChangeAnnouncementReplyWraper>{ enum{ID=RPC_CODE_GUILD_CHANGEANNOUNCEMENT_REQUEST};};
template<> struct MessageIdT<GuildRpcReqGuildListAskWraper>{ enum{ID=RPC_CODE_GUILD_REQGUILDLIST_REQUEST};};
template<> struct MessageIdT<GuildRpcReqGuildListReplyWraper>{ enum{ID=RPC_CODE_GUILD_REQGUILDLIST_REQUEST};};
template<> struct MessageIdT<GuildRpcAppointDutyAskWraper>{ enum{ID=RPC_CODE_GUILD_APPOINTDUTY_REQUEST};};
template<> struct MessageIdT<GuildRpcAppointDutyReplyWraper>{ enum{ID=RPC_CODE_GUILD_APPOINTDUTY_REQUEST};};
template<> struct MessageIdT<GuildRpcKickoutAskWraper>{ enum{ID=RPC_CODE_GUILD_KICKOUT_REQUEST};};
template<> struct MessageIdT<GuildRpcKickoutReplyWraper>{ enum{ID=RPC_CODE_GUILD_KICKOUT_REQUEST};};
template<> struct MessageIdT<GuildRpcExitGuildAskWraper>{ enum{ID=RPC_CODE_GUILD_EXITGUILD_REQUEST};};
template<> struct MessageIdT<GuildRpcExitGuildReplyWraper>{ enum{ID=RPC_CODE_GUILD_EXITGUILD_REQUEST};};
template<> struct MessageIdT<GuildRpcBreakUpAskWraper>{ enum{ID=RPC_CODE_GUILD_BREAKUP_REQUEST};};
template<> struct MessageIdT<GuildRpcBreakUpReplyWraper>{ enum{ID=RPC_CODE_GUILD_BREAKUP_REQUEST};};
template<> struct MessageIdT<GuildRpcInviteToJoinAskWraper>{ enum{ID=RPC_CODE_GUILD_INVITETOJOIN_REQUEST};};
template<> struct MessageIdT<GuildRpcInviteToJoinReplyWraper>{ enum{ID=RPC_CODE_GUILD_INVITETOJOIN_REQUEST};};
template<> struct MessageIdT<GuildRpcBeInvitedNoticeNotifyWraper>{ enum{ID=RPC_CODE_GUILD_BEINVITEDNOTICE_NOTIFY};};
template<> struct MessageIdT<GuildRpcBeInvitedHandleAskWraper>{ enum{ID=RPC_CODE_GUILD_BEINVITEDHANDLE_REQUEST};};
template<> struct MessageIdT<GuildRpcBeInvitedHandleReplyWraper>{ enum{ID=RPC_CODE_GUILD_BEINVITEDHANDLE_REQUEST};};
template<> struct MessageIdT<GuildRpcResignDutyAskWraper>{ enum{ID=RPC_CODE_GUILD_RESIGNDUTY_REQUEST};};
template<> struct MessageIdT<GuildRpcResignDutyReplyWraper>{ enum{ID=RPC_CODE_GUILD_RESIGNDUTY_REQUEST};};
template<> struct MessageIdT<GuildRpcSyncMyTeamDataNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCMYTEAMDATA_NOTIFY};};
template<> struct MessageIdT<GuildRpcSyncNoticeOfGuildBaseDataNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCNOTICEOFGUILDBASEDATA_NOTIFY};};
template<> struct MessageIdT<GuildRpcSyncNoticeOfGuildMemberChangeNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCNOTICEOFGUILDMEMBERCHANGE_NOTIFY};};
template<> struct MessageIdT<GuildRpcSyncNoticeOfAddMemberNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCNOTICEOFADDMEMBER_NOTIFY};};
template<> struct MessageIdT<GuildRpcSyncNoticeOfDelMemberNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCNOTICEOFDELMEMBER_NOTIFY};};
template<> struct MessageIdT<GuildRpcSyncNoticeOfAddEventNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCNOTICEOFADDEVENT_NOTIFY};};
template<> struct MessageIdT<GuildRpcSyncNoticeOfAddApplyListNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCNOTICEOFADDAPPLYLIST_NOTIFY};};
template<> struct MessageIdT<GuildRpcSyncNoticeOfDelApplyListNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCNOTICEOFDELAPPLYLIST_NOTIFY};};
template<> struct MessageIdT<GuildRpcSyncNoticeOfChangeAnnouncementNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCNOTICEOFCHANGEANNOUNCEMENT_NOTIFY};};
template<> struct MessageIdT<GuildRpcSyncNoticeOfBreakupNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCNOTICEOFBREAKUP_NOTIFY};};
template<> struct MessageIdT<GuildRpcHallLvUpAskWraper>{ enum{ID=RPC_CODE_GUILD_HALLLVUP_REQUEST};};
template<> struct MessageIdT<GuildRpcHallLvUpReplyWraper>{ enum{ID=RPC_CODE_GUILD_HALLLVUP_REQUEST};};
template<> struct MessageIdT<GuildRpcHouseLvUpAskWraper>{ enum{ID=RPC_CODE_GUILD_HOUSELVUP_REQUEST};};
template<> struct MessageIdT<GuildRpcHouseLvUpReplyWraper>{ enum{ID=RPC_CODE_GUILD_HOUSELVUP_REQUEST};};
template<> struct MessageIdT<GuildRpcStoreroomLvUpAskWraper>{ enum{ID=RPC_CODE_GUILD_STOREROOMLVUP_REQUEST};};
template<> struct MessageIdT<GuildRpcStoreroomLvUpReplyWraper>{ enum{ID=RPC_CODE_GUILD_STOREROOMLVUP_REQUEST};};
template<> struct MessageIdT<GuildRpcKongfuHallLvUpAskWraper>{ enum{ID=RPC_CODE_GUILD_KONGFUHALLLVUP_REQUEST};};
template<> struct MessageIdT<GuildRpcKongfuHallLvUpReplyWraper>{ enum{ID=RPC_CODE_GUILD_KONGFUHALLLVUP_REQUEST};};
template<> struct MessageIdT<GuildRpcSyncNoticeOfHallLvUpNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCNOTICEOFHALLLVUP_NOTIFY};};
template<> struct MessageIdT<GuildRpcSyncNoticeOfHouseLvUpNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCNOTICEOFHOUSELVUP_NOTIFY};};
template<> struct MessageIdT<GuildRpcSyncNoticeOfStorerommLvUpNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCNOTICEOFSTOREROMMLVUP_NOTIFY};};
template<> struct MessageIdT<GuildRpcSyncNoticeOfKongfuHallLvUpNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCNOTICEOFKONGFUHALLLVUP_NOTIFY};};
template<> struct MessageIdT<GuildRpcApplyGuildHandleAskWraper>{ enum{ID=RPC_CODE_GUILD_APPLYGUILDHANDLE_REQUEST};};
template<> struct MessageIdT<GuildRpcApplyGuildHandleReplyWraper>{ enum{ID=RPC_CODE_GUILD_APPLYGUILDHANDLE_REQUEST};};
template<> struct MessageIdT<GuildRpcCreateGuildDungeonAskWraper>{ enum{ID=RPC_CODE_GUILD_CREATEGUILDDUNGEON_REQUEST};};
template<> struct MessageIdT<GuildRpcCreateGuildDungeonReplyWraper>{ enum{ID=RPC_CODE_GUILD_CREATEGUILDDUNGEON_REQUEST};};
template<> struct MessageIdT<GuildRpcEnterGuildDungeonAskWraper>{ enum{ID=RPC_CODE_GUILD_ENTERGUILDDUNGEON_REQUEST};};
template<> struct MessageIdT<GuildRpcEnterGuildDungeonReplyWraper>{ enum{ID=RPC_CODE_GUILD_ENTERGUILDDUNGEON_REQUEST};};
template<> struct MessageIdT<GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotifyWraper>{ enum{ID=RPC_CODE_GUILD_RPCSYNCNOTICEOFCREATEGUILDDUNGEON_NOTIFY};};
template<> struct MessageIdT<GuildRpcCreateGuildWarAskWraper>{ enum{ID=RPC_CODE_GUILD_CREATEGUILDWAR_REQUEST};};
template<> struct MessageIdT<GuildRpcCreateGuildWarReplyWraper>{ enum{ID=RPC_CODE_GUILD_CREATEGUILDWAR_REQUEST};};
template<> struct MessageIdT<GuildRpcSyncNoticeOfOpenGuildWarNotifyWraper>{ enum{ID=RPC_CODE_GUILD_SYNCNOTICEOFOPENGUILDWAR_NOTIFY};};
template<> struct MessageIdT<GuildRpcEnterGuildWarAskWraper>{ enum{ID=RPC_CODE_GUILD_ENTERGUILDWAR_REQUEST};};
template<> struct MessageIdT<GuildRpcEnterGuildWarReplyWraper>{ enum{ID=RPC_CODE_GUILD_ENTERGUILDWAR_REQUEST};};
template<> struct MessageIdT<GuildRpcOpenScienceAttrAskWraper>{ enum{ID=RPC_CODE_GUILD_OPENSCIENCEATTR_REQUEST};};
template<> struct MessageIdT<GuildRpcOpenScienceAttrReplyWraper>{ enum{ID=RPC_CODE_GUILD_OPENSCIENCEATTR_REQUEST};};
template<> struct MessageIdT<GuildRpcGuildScienceLvUpAskWraper>{ enum{ID=RPC_CODE_GUILD_GUILDSCIENCELVUP_REQUEST};};
template<> struct MessageIdT<GuildRpcGuildScienceLvUpReplyWraper>{ enum{ID=RPC_CODE_GUILD_GUILDSCIENCELVUP_REQUEST};};


#endif
