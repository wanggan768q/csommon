/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperChat.h
* Author:       甘业清
* Description:  聊天RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_CHAT_H
#define __RPC_WRAPER_CHAT_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "ChatRpc.pb.h"



//聊天类的枚举定义
enum ConstChatE
{
	MODULE_ID_CHAT                               = 36,	//聊天模块ID
	RPC_CODE_CHAT_SENDCHAT_REQUEST               = 3651,	//聊天-->发送聊天-->请求
	RPC_CODE_CHAT_SYNCCHAT_NOTIFY                = 3652,	//聊天-->同步聊天-->通知
	RPC_CODE_CHAT_SYNCPRIVATECHATMSG_NOTIFY      = 3653,	//聊天-->同步私聊留言-->通知
	RPC_CODE_CHAT_SVRCHAT_NOTIFY                 = 3654,	//聊天-->服务器发送聊天-->通知


};


//同步私聊留言通知封装类
class ChatRpcSyncPrivateChatMsgNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ChatRpcSyncPrivateChatMsgNotifyWraper()
	{
		

	}
	//赋值构造函数
	ChatRpcSyncPrivateChatMsgNotifyWraper(const ChatRpcSyncPrivateChatMsgNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatRpcSyncPrivateChatMsgNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatRpcSyncPrivateChatMsgNotify ToPB() const
	{
		ChatRpcSyncPrivateChatMsgNotify v;
		v.mutable_chatdata()->Reserve(m_ChatData.size());
		for (int i=0; i<(int)m_ChatData.size(); i++)
		{
			*v.add_chatdata() = m_ChatData[i].ToPB();
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
		ChatRpcSyncPrivateChatMsgNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ChatData(聊天对象) [ChatObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ChatData：</li>\r\n";
		if( m_ChatData.size()>0) htmlBuff += m_ChatData[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ChatData.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ChatData[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ChatRpcSyncPrivateChatMsgNotify& v)
	{
		m_ChatData.clear();
		m_ChatData.reserve(v.chatdata_size());
		for( int i=0; i<v.chatdata_size(); i++)
			m_ChatData.push_back(v.chatdata(i));

	}

private:
	//聊天对象
	vector<ChatObjWraper> m_ChatData;
public:
	int SizeChatData()
	{
		return m_ChatData.size();
	}
	const vector<ChatObjWraper>& GetChatData() const
	{
		return m_ChatData;
	}
	ChatObjWraper GetChatData(int Index) const
	{
		if(Index<0 || Index>=(int)m_ChatData.size())
		{
			assert(false);
			return ChatObjWraper();
		}
		return m_ChatData[Index];
	}
	void SetChatData( const vector<ChatObjWraper>& v )
	{
		m_ChatData=v;
	}
	void ClearChatData( )
	{
		m_ChatData.clear();
	}
	void SetChatData( int Index, const ChatObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_ChatData.size())
		{
			assert(false);
			return;
		}
		m_ChatData[Index] = v;
	}
	void AddChatData( const ChatObjWraper& v )
	{
		m_ChatData.push_back(v);
	}

};
//服务器发送聊天通知封装类
class ChatRpcSvrChatNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ChatRpcSvrChatNotifyWraper()
	{
		
		m_ChatData = ChatNetDataWraper();

	}
	//赋值构造函数
	ChatRpcSvrChatNotifyWraper(const ChatRpcSvrChatNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatRpcSvrChatNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatRpcSvrChatNotify ToPB() const
	{
		ChatRpcSvrChatNotify v;
		*v.mutable_chatdata()= m_ChatData.ToPB();

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
		ChatRpcSvrChatNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ChatData(聊天对象) [ChatNetData]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ChatData：</li>\r\n";
		htmlBuff += m_ChatData.HtmlDescHeader();
		htmlBuff += m_ChatData.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ChatRpcSvrChatNotify& v)
	{
		m_ChatData = v.chatdata();

	}

private:
	//聊天对象
	ChatNetDataWraper m_ChatData;
public:
	void SetChatData( const ChatNetDataWraper& v)
	{
		m_ChatData=v;
	}
	ChatNetDataWraper GetChatData()
	{
		return m_ChatData;
	}
	ChatNetDataWraper GetChatData() const
	{
		return m_ChatData;
	}

};
//聊天功能1, 帮会求助封装类
class ChatRpcChatFun1Wraper : public DataWraperInterface 
{
public:
	//构造函数
	ChatRpcChatFun1Wraper()
	{
		
		m_TargetUserId = -1;
		m_TemplateId = -1;

	}
	//赋值构造函数
	ChatRpcChatFun1Wraper(const ChatRpcChatFun1& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatRpcChatFun1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatRpcChatFun1 ToPB() const
	{
		ChatRpcChatFun1 v;
		v.set_targetuserid( m_TargetUserId );
		v.set_templateid( m_TemplateId );

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
		ChatRpcChatFun1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TargetUserId(对方UserId) [sint64]</li>\r\n";
		htmlBuff += "<li>TemplateId(物品ID) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TargetUserId：%lldL</li>\r\n",m_TargetUserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ChatRpcChatFun1& v)
	{
		m_TargetUserId = v.targetuserid();
		m_TemplateId = v.templateid();

	}

private:
	//对方UserId
	INT64 m_TargetUserId;
public:
	void SetTargetUserId( INT64 v)
	{
		m_TargetUserId=v;
	}
	INT64 GetTargetUserId()
	{
		return m_TargetUserId;
	}
	INT64 GetTargetUserId() const
	{
		return m_TargetUserId;
	}
private:
	//物品ID
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

};
//发送聊天请求封装类
class ChatRpcSendChatAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ChatRpcSendChatAskWraper()
	{
		
		m_ChatMsg = ChatMsgObjWraper();

	}
	//赋值构造函数
	ChatRpcSendChatAskWraper(const ChatRpcSendChatAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatRpcSendChatAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatRpcSendChatAsk ToPB() const
	{
		ChatRpcSendChatAsk v;
		*v.mutable_chatmsg()= m_ChatMsg.ToPB();

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
		ChatRpcSendChatAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ChatMsg(聊天消息) [ChatMsgObj]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ChatMsg：</li>\r\n";
		htmlBuff += m_ChatMsg.HtmlDescHeader();
		htmlBuff += m_ChatMsg.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ChatRpcSendChatAsk& v)
	{
		m_ChatMsg = v.chatmsg();

	}

private:
	//聊天消息
	ChatMsgObjWraper m_ChatMsg;
public:
	void SetChatMsg( const ChatMsgObjWraper& v)
	{
		m_ChatMsg=v;
	}
	ChatMsgObjWraper GetChatMsg()
	{
		return m_ChatMsg;
	}
	ChatMsgObjWraper GetChatMsg() const
	{
		return m_ChatMsg;
	}

};
//发送聊天回应封装类
class ChatRpcSendChatReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ChatRpcSendChatReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ChatRpcSendChatReplyWraper(const ChatRpcSendChatReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatRpcSendChatReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatRpcSendChatReply ToPB() const
	{
		ChatRpcSendChatReply v;
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
		ChatRpcSendChatReply pb;
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
	void Init(const ChatRpcSendChatReply& v)
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
//同步聊天通知封装类
class ChatRpcSyncChatNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ChatRpcSyncChatNotifyWraper()
	{
		
		m_ChatData = ChatObjWraper();

	}
	//赋值构造函数
	ChatRpcSyncChatNotifyWraper(const ChatRpcSyncChatNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatRpcSyncChatNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatRpcSyncChatNotify ToPB() const
	{
		ChatRpcSyncChatNotify v;
		*v.mutable_chatdata()= m_ChatData.ToPB();

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
		ChatRpcSyncChatNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ChatData(聊天对象) [ChatObj]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ChatData：</li>\r\n";
		htmlBuff += m_ChatData.HtmlDescHeader();
		htmlBuff += m_ChatData.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ChatRpcSyncChatNotify& v)
	{
		m_ChatData = v.chatdata();

	}

private:
	//聊天对象
	ChatObjWraper m_ChatData;
public:
	void SetChatData( const ChatObjWraper& v)
	{
		m_ChatData=v;
	}
	ChatObjWraper GetChatData()
	{
		return m_ChatData;
	}
	ChatObjWraper GetChatData() const
	{
		return m_ChatData;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<ChatRpcSendChatAskWraper>{ enum{ID=RPC_CODE_CHAT_SENDCHAT_REQUEST};};
template<> struct MessageIdT<ChatRpcSendChatReplyWraper>{ enum{ID=RPC_CODE_CHAT_SENDCHAT_REQUEST};};
template<> struct MessageIdT<ChatRpcSyncChatNotifyWraper>{ enum{ID=RPC_CODE_CHAT_SYNCCHAT_NOTIFY};};
template<> struct MessageIdT<ChatRpcSyncPrivateChatMsgNotifyWraper>{ enum{ID=RPC_CODE_CHAT_SYNCPRIVATECHATMSG_NOTIFY};};
template<> struct MessageIdT<ChatRpcSvrChatNotifyWraper>{ enum{ID=RPC_CODE_CHAT_SVRCHAT_NOTIFY};};


#endif
