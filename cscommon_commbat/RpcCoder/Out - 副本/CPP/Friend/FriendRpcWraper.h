/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperFriend.h
* Author:       甘业清
* Description:  好友RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_FRIEND_H
#define __RPC_WRAPER_FRIEND_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "FriendRpc.pb.h"



//好友类的枚举定义
enum ConstFriendE
{
	MODULE_ID_FRIEND                             = 33,	//好友模块ID
	RPC_CODE_FRIEND_SYNCFRIENDDATA_REQUEST       = 3351,	//好友-->每次打开界面，请求一次数据-->请求
	RPC_CODE_FRIEND_ADDFRIEND_REQUEST            = 3352,	//好友-->增加好友-->请求
	RPC_CODE_FRIEND_DELFRIEND_REQUEST            = 3353,	//好友-->删除好友-->请求
	RPC_CODE_FRIEND_ADDBLACKLIST_REQUEST         = 3354,	//好友-->增加黑名单-->请求
	RPC_CODE_FRIEND_DELBLACKLIST_REQUEST         = 3355,	//好友-->删除黑名单-->请求
	RPC_CODE_FRIEND_ADDCONTACT_REQUEST           = 3356,	//好友-->增加最近联系人-->请求
	RPC_CODE_FRIEND_DELCONTACT_REQUEST           = 3357,	//好友-->删除最近联系人-->请求
	RPC_CODE_FRIEND_SEARCHPLAYER_REQUEST         = 3358,	//好友-->搜索好友-->请求
	RPC_CODE_FRIEND_RECOMMEND_REQUEST            = 3359,	//好友-->推荐玩家-->请求
	RPC_CODE_FRIEND_VIEWUSERSIMPLEINFO_REQUEST   = 3360,	//好友-->查看资料简单数据-->请求
	RPC_CODE_FRIEND_FRIENDONLINEOFFLINE_NOTIFY   = 3361,	//好友-->好友上下线-->通知


};


//推荐好友对象封装类
class FriendRpcRecommendObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcRecommendObjWraper()
	{
		
		m_UserId = -1;
		m_UserName = "";
		m_Level = -1;
		m_Prof = -1;

	}
	//赋值构造函数
	FriendRpcRecommendObjWraper(const FriendRpcRecommendObj& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcRecommendObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcRecommendObj ToPB() const
	{
		FriendRpcRecommendObj v;
		v.set_userid( m_UserId );
		v.set_username( m_UserName );
		v.set_level( m_Level );
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
		FriendRpcRecommendObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>UserName(名字) [string]</li>\r\n";
		htmlBuff += "<li>Level(等级) [sint32]</li>\r\n";
		htmlBuff += "<li>Prof(职业) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>UserName：\""+m_UserName+"\"</li>\r\n";
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Prof：%di</li>\r\n",m_Prof);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FriendRpcRecommendObj& v)
	{
		m_UserId = v.userid();
		m_UserName = v.username();
		m_Level = v.level();
		m_Prof = v.prof();

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
	//名字
	string m_UserName;
public:
	void SetUserName( const string& v)
	{
		m_UserName=v;
	}
	string GetUserName()
	{
		return m_UserName;
	}
	string GetUserName() const
	{
		return m_UserName;
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
//删除最近联系人回应封装类
class FriendRpcDelContactReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcDelContactReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	FriendRpcDelContactReplyWraper(const FriendRpcDelContactReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcDelContactReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcDelContactReply ToPB() const
	{
		FriendRpcDelContactReply v;
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
		FriendRpcDelContactReply pb;
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
	void Init(const FriendRpcDelContactReply& v)
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
//搜索好友请求封装类
class FriendRpcSearchPlayerAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcSearchPlayerAskWraper()
	{
		
		m_SearchString = "";

	}
	//赋值构造函数
	FriendRpcSearchPlayerAskWraper(const FriendRpcSearchPlayerAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcSearchPlayerAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcSearchPlayerAsk ToPB() const
	{
		FriendRpcSearchPlayerAsk v;
		v.set_searchstring( m_SearchString );

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
		FriendRpcSearchPlayerAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SearchString(搜索内容) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>SearchString：\""+m_SearchString+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FriendRpcSearchPlayerAsk& v)
	{
		m_SearchString = v.searchstring();

	}

private:
	//搜索内容
	string m_SearchString;
public:
	void SetSearchString( const string& v)
	{
		m_SearchString=v;
	}
	string GetSearchString()
	{
		return m_SearchString;
	}
	string GetSearchString() const
	{
		return m_SearchString;
	}

};
//删除最近联系人请求封装类
class FriendRpcDelContactAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcDelContactAskWraper()
	{
		
		m_UserId = -1;

	}
	//赋值构造函数
	FriendRpcDelContactAskWraper(const FriendRpcDelContactAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcDelContactAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcDelContactAsk ToPB() const
	{
		FriendRpcDelContactAsk v;
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
		FriendRpcDelContactAsk pb;
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
	void Init(const FriendRpcDelContactAsk& v)
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
//增加最近联系人请求封装类
class FriendRpcAddContactAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcAddContactAskWraper()
	{
		
		m_UserId = -1;

	}
	//赋值构造函数
	FriendRpcAddContactAskWraper(const FriendRpcAddContactAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcAddContactAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcAddContactAsk ToPB() const
	{
		FriendRpcAddContactAsk v;
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
		FriendRpcAddContactAsk pb;
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
	void Init(const FriendRpcAddContactAsk& v)
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
//增加最近联系人回应封装类
class FriendRpcAddContactReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcAddContactReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	FriendRpcAddContactReplyWraper(const FriendRpcAddContactReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcAddContactReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcAddContactReply ToPB() const
	{
		FriendRpcAddContactReply v;
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
		FriendRpcAddContactReply pb;
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
	void Init(const FriendRpcAddContactReply& v)
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
//搜索好友回应封装类
class FriendRpcSearchPlayerReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcSearchPlayerReplyWraper()
	{
		
		m_Result = -9999;
		m_UserId = -1;
		m_UserName = "";
		m_Level = -1;
		m_Prof = -1;

	}
	//赋值构造函数
	FriendRpcSearchPlayerReplyWraper(const FriendRpcSearchPlayerReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcSearchPlayerReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcSearchPlayerReply ToPB() const
	{
		FriendRpcSearchPlayerReply v;
		v.set_result( m_Result );
		v.set_userid( m_UserId );
		v.set_username( m_UserName );
		v.set_level( m_Level );
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
		FriendRpcSearchPlayerReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>UserName(名字) [string]</li>\r\n";
		htmlBuff += "<li>Level(等级) [sint32]</li>\r\n";
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
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>UserName：\""+m_UserName+"\"</li>\r\n";
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Prof：%di</li>\r\n",m_Prof);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FriendRpcSearchPlayerReply& v)
	{
		m_Result = v.result();
		m_UserId = v.userid();
		m_UserName = v.username();
		m_Level = v.level();
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
	//名字
	string m_UserName;
public:
	void SetUserName( const string& v)
	{
		m_UserName=v;
	}
	string GetUserName()
	{
		return m_UserName;
	}
	string GetUserName() const
	{
		return m_UserName;
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
//查看资料简单数据请求封装类
class FriendRpcViewUserSimpleInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcViewUserSimpleInfoAskWraper()
	{
		
		m_UserId = -1;

	}
	//赋值构造函数
	FriendRpcViewUserSimpleInfoAskWraper(const FriendRpcViewUserSimpleInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcViewUserSimpleInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcViewUserSimpleInfoAsk ToPB() const
	{
		FriendRpcViewUserSimpleInfoAsk v;
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
		FriendRpcViewUserSimpleInfoAsk pb;
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
	void Init(const FriendRpcViewUserSimpleInfoAsk& v)
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
//查看资料简单数据回应封装类
class FriendRpcViewUserSimpleInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcViewUserSimpleInfoReplyWraper()
	{
		
		m_Result = -9999;
		m_UserId = -1;
		m_UserName = "";
		m_Level = -1;
		m_Prof = -1;
		m_TeamId = -1;
		m_TeamMemberNum = -1;
		m_GuildId = -1;
		m_Signature = "";
		m_Online = false;
		m_GoodFeeling = 0;
		m_GuildName = "";

	}
	//赋值构造函数
	FriendRpcViewUserSimpleInfoReplyWraper(const FriendRpcViewUserSimpleInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcViewUserSimpleInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcViewUserSimpleInfoReply ToPB() const
	{
		FriendRpcViewUserSimpleInfoReply v;
		v.set_result( m_Result );
		v.set_userid( m_UserId );
		v.set_username( m_UserName );
		v.set_level( m_Level );
		v.set_prof( m_Prof );
		v.set_teamid( m_TeamId );
		v.set_teammembernum( m_TeamMemberNum );
		v.set_guildid( m_GuildId );
		v.set_signature( m_Signature );
		v.set_online( m_Online );
		v.set_goodfeeling( m_GoodFeeling );
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
		FriendRpcViewUserSimpleInfoReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>UserName(名字) [string]</li>\r\n";
		htmlBuff += "<li>Level(等级) [sint32]</li>\r\n";
		htmlBuff += "<li>Prof(职业) [sint32]</li>\r\n";
		htmlBuff += "<li>TeamId(队伍Id) [sint32]</li>\r\n";
		htmlBuff += "<li>TeamMemberNum(队伍当前人数) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildId(帮会id) [sint32]</li>\r\n";
		htmlBuff += "<li>Signature(签名) [string]</li>\r\n";
		htmlBuff += "<li>Online(是否在线) [bool]</li>\r\n";
		htmlBuff += "<li>GoodFeeling(好感度) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildName(帮会名字) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>UserName：\""+m_UserName+"\"</li>\r\n";
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Prof：%di</li>\r\n",m_Prof);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TeamId：%di</li>\r\n",m_TeamId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TeamMemberNum：%di</li>\r\n",m_TeamMemberNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GuildId：%di</li>\r\n",m_GuildId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Signature：\""+m_Signature+"\"</li>\r\n";
		tmpLine.Fmt("<li>Online：%di</li>\r\n",m_Online);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GoodFeeling：%di</li>\r\n",m_GoodFeeling);
		htmlBuff += tmpLine;
		htmlBuff += "<li>GuildName：\""+m_GuildName+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FriendRpcViewUserSimpleInfoReply& v)
	{
		m_Result = v.result();
		m_UserId = v.userid();
		m_UserName = v.username();
		m_Level = v.level();
		m_Prof = v.prof();
		m_TeamId = v.teamid();
		m_TeamMemberNum = v.teammembernum();
		m_GuildId = v.guildid();
		m_Signature = v.signature();
		m_Online = v.online();
		m_GoodFeeling = v.goodfeeling();
		m_GuildName = v.guildname();

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
	//名字
	string m_UserName;
public:
	void SetUserName( const string& v)
	{
		m_UserName=v;
	}
	string GetUserName()
	{
		return m_UserName;
	}
	string GetUserName() const
	{
		return m_UserName;
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
private:
	//队伍Id
	INT32 m_TeamId;
public:
	void SetTeamId( INT32 v)
	{
		m_TeamId=v;
	}
	INT32 GetTeamId()
	{
		return m_TeamId;
	}
	INT32 GetTeamId() const
	{
		return m_TeamId;
	}
private:
	//队伍当前人数
	INT32 m_TeamMemberNum;
public:
	void SetTeamMemberNum( INT32 v)
	{
		m_TeamMemberNum=v;
	}
	INT32 GetTeamMemberNum()
	{
		return m_TeamMemberNum;
	}
	INT32 GetTeamMemberNum() const
	{
		return m_TeamMemberNum;
	}
private:
	//帮会id
	INT32 m_GuildId;
public:
	void SetGuildId( INT32 v)
	{
		m_GuildId=v;
	}
	INT32 GetGuildId()
	{
		return m_GuildId;
	}
	INT32 GetGuildId() const
	{
		return m_GuildId;
	}
private:
	//签名
	string m_Signature;
public:
	void SetSignature( const string& v)
	{
		m_Signature=v;
	}
	string GetSignature()
	{
		return m_Signature;
	}
	string GetSignature() const
	{
		return m_Signature;
	}
private:
	//是否在线
	bool m_Online;
public:
	void SetOnline( bool v)
	{
		m_Online=v;
	}
	bool GetOnline()
	{
		return m_Online;
	}
	bool GetOnline() const
	{
		return m_Online;
	}
private:
	//好感度
	INT32 m_GoodFeeling;
public:
	void SetGoodFeeling( INT32 v)
	{
		m_GoodFeeling=v;
	}
	INT32 GetGoodFeeling()
	{
		return m_GoodFeeling;
	}
	INT32 GetGoodFeeling() const
	{
		return m_GoodFeeling;
	}
private:
	//帮会名字
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
//推荐玩家回应封装类
class FriendRpcRecommendReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcRecommendReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	FriendRpcRecommendReplyWraper(const FriendRpcRecommendReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcRecommendReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcRecommendReply ToPB() const
	{
		FriendRpcRecommendReply v;
		v.set_result( m_Result );
		v.mutable_recommendlist()->Reserve(m_RecommendList.size());
		for (int i=0; i<(int)m_RecommendList.size(); i++)
		{
			*v.add_recommendlist() = m_RecommendList[i].ToPB();
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
		FriendRpcRecommendReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>RecommendList(推荐名单) [RpcRecommendObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>RecommendList：</li>\r\n";
		if( m_RecommendList.size()>0) htmlBuff += m_RecommendList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_RecommendList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_RecommendList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FriendRpcRecommendReply& v)
	{
		m_Result = v.result();
		m_RecommendList.clear();
		m_RecommendList.reserve(v.recommendlist_size());
		for( int i=0; i<v.recommendlist_size(); i++)
			m_RecommendList.push_back(v.recommendlist(i));

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
	//推荐名单
	vector<FriendRpcRecommendObjWraper> m_RecommendList;
public:
	int SizeRecommendList()
	{
		return m_RecommendList.size();
	}
	const vector<FriendRpcRecommendObjWraper>& GetRecommendList() const
	{
		return m_RecommendList;
	}
	FriendRpcRecommendObjWraper GetRecommendList(int Index) const
	{
		if(Index<0 || Index>=(int)m_RecommendList.size())
		{
			assert(false);
			return FriendRpcRecommendObjWraper();
		}
		return m_RecommendList[Index];
	}
	void SetRecommendList( const vector<FriendRpcRecommendObjWraper>& v )
	{
		m_RecommendList=v;
	}
	void ClearRecommendList( )
	{
		m_RecommendList.clear();
	}
	void SetRecommendList( int Index, const FriendRpcRecommendObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_RecommendList.size())
		{
			assert(false);
			return;
		}
		m_RecommendList[Index] = v;
	}
	void AddRecommendList( const FriendRpcRecommendObjWraper& v )
	{
		m_RecommendList.push_back(v);
	}

};
//好友上下线通知封装类
class FriendRpcOnlineOfflineNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcOnlineOfflineNotifyWraper()
	{
		
		m_UserId = -1;
		m_UserName = "";
		m_Online = false;

	}
	//赋值构造函数
	FriendRpcOnlineOfflineNotifyWraper(const FriendRpcOnlineOfflineNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcOnlineOfflineNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcOnlineOfflineNotify ToPB() const
	{
		FriendRpcOnlineOfflineNotify v;
		v.set_userid( m_UserId );
		v.set_username( m_UserName );
		v.set_online( m_Online );

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
		FriendRpcOnlineOfflineNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>UserName(名字) [string]</li>\r\n";
		htmlBuff += "<li>Online(是否在线) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>UserName：\""+m_UserName+"\"</li>\r\n";
		tmpLine.Fmt("<li>Online：%di</li>\r\n",m_Online);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FriendRpcOnlineOfflineNotify& v)
	{
		m_UserId = v.userid();
		m_UserName = v.username();
		m_Online = v.online();

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
	//名字
	string m_UserName;
public:
	void SetUserName( const string& v)
	{
		m_UserName=v;
	}
	string GetUserName()
	{
		return m_UserName;
	}
	string GetUserName() const
	{
		return m_UserName;
	}
private:
	//是否在线
	bool m_Online;
public:
	void SetOnline( bool v)
	{
		m_Online=v;
	}
	bool GetOnline()
	{
		return m_Online;
	}
	bool GetOnline() const
	{
		return m_Online;
	}

};
//推荐玩家请求封装类
class FriendRpcRecommendAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcRecommendAskWraper()
	{
		

	}
	//赋值构造函数
	FriendRpcRecommendAskWraper(const FriendRpcRecommendAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcRecommendAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcRecommendAsk ToPB() const
	{
		FriendRpcRecommendAsk v;

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
		FriendRpcRecommendAsk pb;
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
	void Init(const FriendRpcRecommendAsk& v)
	{

	}


};
//每次打开界面，请求一次数据回应封装类
class FriendRpcSyncFriendDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcSyncFriendDataReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	FriendRpcSyncFriendDataReplyWraper(const FriendRpcSyncFriendDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcSyncFriendDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcSyncFriendDataReply ToPB() const
	{
		FriendRpcSyncFriendDataReply v;
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
		FriendRpcSyncFriendDataReply pb;
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
	void Init(const FriendRpcSyncFriendDataReply& v)
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
//增加好友请求封装类
class FriendRpcAddFriendAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcAddFriendAskWraper()
	{
		
		m_UserId = -1;

	}
	//赋值构造函数
	FriendRpcAddFriendAskWraper(const FriendRpcAddFriendAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcAddFriendAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcAddFriendAsk ToPB() const
	{
		FriendRpcAddFriendAsk v;
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
		FriendRpcAddFriendAsk pb;
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
	void Init(const FriendRpcAddFriendAsk& v)
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
//增加好友回应封装类
class FriendRpcAddFriendReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcAddFriendReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	FriendRpcAddFriendReplyWraper(const FriendRpcAddFriendReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcAddFriendReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcAddFriendReply ToPB() const
	{
		FriendRpcAddFriendReply v;
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
		FriendRpcAddFriendReply pb;
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
	void Init(const FriendRpcAddFriendReply& v)
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
//每次打开界面，请求一次数据请求封装类
class FriendRpcSyncFriendDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcSyncFriendDataAskWraper()
	{
		

	}
	//赋值构造函数
	FriendRpcSyncFriendDataAskWraper(const FriendRpcSyncFriendDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcSyncFriendDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcSyncFriendDataAsk ToPB() const
	{
		FriendRpcSyncFriendDataAsk v;

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
		FriendRpcSyncFriendDataAsk pb;
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
	void Init(const FriendRpcSyncFriendDataAsk& v)
	{

	}


};
//增加黑名单回应封装类
class FriendRpcAddBlackListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcAddBlackListReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	FriendRpcAddBlackListReplyWraper(const FriendRpcAddBlackListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcAddBlackListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcAddBlackListReply ToPB() const
	{
		FriendRpcAddBlackListReply v;
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
		FriendRpcAddBlackListReply pb;
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
	void Init(const FriendRpcAddBlackListReply& v)
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
//删除黑名单请求封装类
class FriendRpcDelBlackListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcDelBlackListAskWraper()
	{
		
		m_UserId = -1;

	}
	//赋值构造函数
	FriendRpcDelBlackListAskWraper(const FriendRpcDelBlackListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcDelBlackListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcDelBlackListAsk ToPB() const
	{
		FriendRpcDelBlackListAsk v;
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
		FriendRpcDelBlackListAsk pb;
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
	void Init(const FriendRpcDelBlackListAsk& v)
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
//删除黑名单回应封装类
class FriendRpcDelBlackListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcDelBlackListReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	FriendRpcDelBlackListReplyWraper(const FriendRpcDelBlackListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcDelBlackListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcDelBlackListReply ToPB() const
	{
		FriendRpcDelBlackListReply v;
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
		FriendRpcDelBlackListReply pb;
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
	void Init(const FriendRpcDelBlackListReply& v)
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
//删除好友请求封装类
class FriendRpcDelFriendAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcDelFriendAskWraper()
	{
		

	}
	//赋值构造函数
	FriendRpcDelFriendAskWraper(const FriendRpcDelFriendAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcDelFriendAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcDelFriendAsk ToPB() const
	{
		FriendRpcDelFriendAsk v;
		v.mutable_userid()->Reserve(m_UserId.size());
		for (int i=0; i<(int)m_UserId.size(); i++)
		{
			v.add_userid(m_UserId[i]);
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
		FriendRpcDelFriendAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>UserId：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_UserId.size(); i++){
			tmpLine.Fmt("<td>%lldL</td>\r\n",m_UserId[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_UserId.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FriendRpcDelFriendAsk& v)
	{
		m_UserId.clear();
		m_UserId.reserve(v.userid_size());
		for( int i=0; i<v.userid_size(); i++)
			m_UserId.push_back(v.userid(i));

	}

private:
	//用户Id
	vector<INT64> m_UserId;
public:
	int SizeUserId()
	{
		return m_UserId.size();
	}
	const vector<INT64>& GetUserId() const
	{
		return m_UserId;
	}
	INT64 GetUserId(int Index) const
	{
		if(Index<0 || Index>=(int)m_UserId.size())
		{
			assert(false);
			return INT64();
		}
		return m_UserId[Index];
	}
	void SetUserId( const vector<INT64>& v )
	{
		m_UserId=v;
	}
	void ClearUserId( )
	{
		m_UserId.clear();
	}
	void SetUserId( int Index, INT64 v )
	{
		if(Index<0 || Index>=(int)m_UserId.size())
		{
			assert(false);
			return;
		}
		m_UserId[Index] = v;
	}
	void AddUserId( INT64 v = -1 )
	{
		m_UserId.push_back(v);
	}

};
//删除好友回应封装类
class FriendRpcDelFriendReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcDelFriendReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	FriendRpcDelFriendReplyWraper(const FriendRpcDelFriendReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcDelFriendReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcDelFriendReply ToPB() const
	{
		FriendRpcDelFriendReply v;
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
		FriendRpcDelFriendReply pb;
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
	void Init(const FriendRpcDelFriendReply& v)
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
//增加黑名单请求封装类
class FriendRpcAddBlackListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FriendRpcAddBlackListAskWraper()
	{
		
		m_UserId = -1;

	}
	//赋值构造函数
	FriendRpcAddBlackListAskWraper(const FriendRpcAddBlackListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendRpcAddBlackListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendRpcAddBlackListAsk ToPB() const
	{
		FriendRpcAddBlackListAsk v;
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
		FriendRpcAddBlackListAsk pb;
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
	void Init(const FriendRpcAddBlackListAsk& v)
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

template<typename T> struct MessageIdT;
template<> struct MessageIdT<FriendRpcSyncFriendDataAskWraper>{ enum{ID=RPC_CODE_FRIEND_SYNCFRIENDDATA_REQUEST};};
template<> struct MessageIdT<FriendRpcSyncFriendDataReplyWraper>{ enum{ID=RPC_CODE_FRIEND_SYNCFRIENDDATA_REQUEST};};
template<> struct MessageIdT<FriendRpcAddFriendAskWraper>{ enum{ID=RPC_CODE_FRIEND_ADDFRIEND_REQUEST};};
template<> struct MessageIdT<FriendRpcAddFriendReplyWraper>{ enum{ID=RPC_CODE_FRIEND_ADDFRIEND_REQUEST};};
template<> struct MessageIdT<FriendRpcDelFriendAskWraper>{ enum{ID=RPC_CODE_FRIEND_DELFRIEND_REQUEST};};
template<> struct MessageIdT<FriendRpcDelFriendReplyWraper>{ enum{ID=RPC_CODE_FRIEND_DELFRIEND_REQUEST};};
template<> struct MessageIdT<FriendRpcAddBlackListAskWraper>{ enum{ID=RPC_CODE_FRIEND_ADDBLACKLIST_REQUEST};};
template<> struct MessageIdT<FriendRpcAddBlackListReplyWraper>{ enum{ID=RPC_CODE_FRIEND_ADDBLACKLIST_REQUEST};};
template<> struct MessageIdT<FriendRpcDelBlackListAskWraper>{ enum{ID=RPC_CODE_FRIEND_DELBLACKLIST_REQUEST};};
template<> struct MessageIdT<FriendRpcDelBlackListReplyWraper>{ enum{ID=RPC_CODE_FRIEND_DELBLACKLIST_REQUEST};};
template<> struct MessageIdT<FriendRpcAddContactAskWraper>{ enum{ID=RPC_CODE_FRIEND_ADDCONTACT_REQUEST};};
template<> struct MessageIdT<FriendRpcAddContactReplyWraper>{ enum{ID=RPC_CODE_FRIEND_ADDCONTACT_REQUEST};};
template<> struct MessageIdT<FriendRpcDelContactAskWraper>{ enum{ID=RPC_CODE_FRIEND_DELCONTACT_REQUEST};};
template<> struct MessageIdT<FriendRpcDelContactReplyWraper>{ enum{ID=RPC_CODE_FRIEND_DELCONTACT_REQUEST};};
template<> struct MessageIdT<FriendRpcSearchPlayerAskWraper>{ enum{ID=RPC_CODE_FRIEND_SEARCHPLAYER_REQUEST};};
template<> struct MessageIdT<FriendRpcSearchPlayerReplyWraper>{ enum{ID=RPC_CODE_FRIEND_SEARCHPLAYER_REQUEST};};
template<> struct MessageIdT<FriendRpcRecommendAskWraper>{ enum{ID=RPC_CODE_FRIEND_RECOMMEND_REQUEST};};
template<> struct MessageIdT<FriendRpcRecommendReplyWraper>{ enum{ID=RPC_CODE_FRIEND_RECOMMEND_REQUEST};};
template<> struct MessageIdT<FriendRpcViewUserSimpleInfoAskWraper>{ enum{ID=RPC_CODE_FRIEND_VIEWUSERSIMPLEINFO_REQUEST};};
template<> struct MessageIdT<FriendRpcViewUserSimpleInfoReplyWraper>{ enum{ID=RPC_CODE_FRIEND_VIEWUSERSIMPLEINFO_REQUEST};};
template<> struct MessageIdT<FriendRpcOnlineOfflineNotifyWraper>{ enum{ID=RPC_CODE_FRIEND_FRIENDONLINEOFFLINE_NOTIFY};};


#endif
