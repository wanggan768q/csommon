/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperMail.h
* Author:       甘业清
* Description:  邮件RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_MAIL_H
#define __RPC_WRAPER_MAIL_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "MailRpc.pb.h"



//邮件类的枚举定义
enum ConstMailE
{
	MODULE_ID_MAIL                               = 44,	//邮件模块ID
	RPC_CODE_MAIL_MAILHEAD_REQUEST               = 4451,	//邮件-->获得邮件头-->请求
	RPC_CODE_MAIL_OPENMAIL_REQUEST               = 4452,	//邮件-->获得邮件内容-->请求
	RPC_CODE_MAIL_NEWMAIL_NOTIFY                 = 4453,	//邮件-->获得新邮件-->通知
	RPC_CODE_MAIL_DELMAIL_REQUEST                = 4454,	//邮件-->删除邮件-->请求
	RPC_CODE_MAIL_GETREWARD_REQUEST              = 4455,	//邮件-->领取奖励-->请求
	RPC_CODE_MAIL_ONEKEYGETREWARD_REQUEST        = 4456,	//邮件-->一键领取-->请求


};


//领取奖励回应封装类
class MailRpcGetRewardReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcGetRewardReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	MailRpcGetRewardReplyWraper(const MailRpcGetRewardReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcGetRewardReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcGetRewardReply ToPB() const
	{
		MailRpcGetRewardReply v;
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
		MailRpcGetRewardReply pb;
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
	void Init(const MailRpcGetRewardReply& v)
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
//领取奖励请求封装类
class MailRpcGetRewardAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcGetRewardAskWraper()
	{
		
		m_UId = -1;

	}
	//赋值构造函数
	MailRpcGetRewardAskWraper(const MailRpcGetRewardAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcGetRewardAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcGetRewardAsk ToPB() const
	{
		MailRpcGetRewardAsk v;
		v.set_uid( m_UId );

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
		MailRpcGetRewardAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UId(UId) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UId：%lldL</li>\r\n",m_UId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MailRpcGetRewardAsk& v)
	{
		m_UId = v.uid();

	}

private:
	//UId
	INT64 m_UId;
public:
	void SetUId( INT64 v)
	{
		m_UId=v;
	}
	INT64 GetUId()
	{
		return m_UId;
	}
	INT64 GetUId() const
	{
		return m_UId;
	}

};
//获得新邮件通知封装类
class MailRpcNewMailNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcNewMailNotifyWraper()
	{
		

	}
	//赋值构造函数
	MailRpcNewMailNotifyWraper(const MailRpcNewMailNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcNewMailNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcNewMailNotify ToPB() const
	{
		MailRpcNewMailNotify v;
		v.mutable_mailheadlist()->Reserve(m_MailHeadList.size());
		for (int i=0; i<(int)m_MailHeadList.size(); i++)
		{
			*v.add_mailheadlist() = m_MailHeadList[i].ToPB();
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
		MailRpcNewMailNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>MailHeadList(邮件头信息列表) [MailHeadObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>MailHeadList：</li>\r\n";
		if( m_MailHeadList.size()>0) htmlBuff += m_MailHeadList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_MailHeadList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_MailHeadList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MailRpcNewMailNotify& v)
	{
		m_MailHeadList.clear();
		m_MailHeadList.reserve(v.mailheadlist_size());
		for( int i=0; i<v.mailheadlist_size(); i++)
			m_MailHeadList.push_back(v.mailheadlist(i));

	}

private:
	//邮件头信息列表
	vector<MailHeadObjWraper> m_MailHeadList;
public:
	int SizeMailHeadList()
	{
		return m_MailHeadList.size();
	}
	const vector<MailHeadObjWraper>& GetMailHeadList() const
	{
		return m_MailHeadList;
	}
	MailHeadObjWraper GetMailHeadList(int Index) const
	{
		if(Index<0 || Index>=(int)m_MailHeadList.size())
		{
			assert(false);
			return MailHeadObjWraper();
		}
		return m_MailHeadList[Index];
	}
	void SetMailHeadList( const vector<MailHeadObjWraper>& v )
	{
		m_MailHeadList=v;
	}
	void ClearMailHeadList( )
	{
		m_MailHeadList.clear();
	}
	void SetMailHeadList( int Index, const MailHeadObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_MailHeadList.size())
		{
			assert(false);
			return;
		}
		m_MailHeadList[Index] = v;
	}
	void AddMailHeadList( const MailHeadObjWraper& v )
	{
		m_MailHeadList.push_back(v);
	}

};
//一键领取回应封装类
class MailRpcOneKeyGetRewardReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcOneKeyGetRewardReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	MailRpcOneKeyGetRewardReplyWraper(const MailRpcOneKeyGetRewardReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcOneKeyGetRewardReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcOneKeyGetRewardReply ToPB() const
	{
		MailRpcOneKeyGetRewardReply v;
		v.set_result( m_Result );
		v.mutable_uidlist()->Reserve(m_UidList.size());
		for (int i=0; i<(int)m_UidList.size(); i++)
		{
			v.add_uidlist(m_UidList[i]);
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
		MailRpcOneKeyGetRewardReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>UidList(UidList) [sint64] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>UidList：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_UidList.size(); i++){
			tmpLine.Fmt("<td>%lldL</td>\r\n",m_UidList[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_UidList.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MailRpcOneKeyGetRewardReply& v)
	{
		m_Result = v.result();
		m_UidList.clear();
		m_UidList.reserve(v.uidlist_size());
		for( int i=0; i<v.uidlist_size(); i++)
			m_UidList.push_back(v.uidlist(i));

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
	//UidList
	vector<INT64> m_UidList;
public:
	int SizeUidList()
	{
		return m_UidList.size();
	}
	const vector<INT64>& GetUidList() const
	{
		return m_UidList;
	}
	INT64 GetUidList(int Index) const
	{
		if(Index<0 || Index>=(int)m_UidList.size())
		{
			assert(false);
			return INT64();
		}
		return m_UidList[Index];
	}
	void SetUidList( const vector<INT64>& v )
	{
		m_UidList=v;
	}
	void ClearUidList( )
	{
		m_UidList.clear();
	}
	void SetUidList( int Index, INT64 v )
	{
		if(Index<0 || Index>=(int)m_UidList.size())
		{
			assert(false);
			return;
		}
		m_UidList[Index] = v;
	}
	void AddUidList( INT64 v = -1 )
	{
		m_UidList.push_back(v);
	}

};
//一键领取请求封装类
class MailRpcOneKeyGetRewardAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcOneKeyGetRewardAskWraper()
	{
		

	}
	//赋值构造函数
	MailRpcOneKeyGetRewardAskWraper(const MailRpcOneKeyGetRewardAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcOneKeyGetRewardAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcOneKeyGetRewardAsk ToPB() const
	{
		MailRpcOneKeyGetRewardAsk v;

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
		MailRpcOneKeyGetRewardAsk pb;
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
	void Init(const MailRpcOneKeyGetRewardAsk& v)
	{

	}


};
//获得邮件内容回应封装类
class MailRpcOpenMailReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcOpenMailReplyWraper()
	{
		
		m_Result = -9999;
		m_MailBody = MailBodyObjWraper();

	}
	//赋值构造函数
	MailRpcOpenMailReplyWraper(const MailRpcOpenMailReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcOpenMailReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcOpenMailReply ToPB() const
	{
		MailRpcOpenMailReply v;
		v.set_result( m_Result );
		*v.mutable_mailbody()= m_MailBody.ToPB();

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
		MailRpcOpenMailReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>MailBody(邮件内容) [MailBodyObj]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>MailBody：</li>\r\n";
		htmlBuff += m_MailBody.HtmlDescHeader();
		htmlBuff += m_MailBody.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MailRpcOpenMailReply& v)
	{
		m_Result = v.result();
		m_MailBody = v.mailbody();

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
	//邮件内容
	MailBodyObjWraper m_MailBody;
public:
	void SetMailBody( const MailBodyObjWraper& v)
	{
		m_MailBody=v;
	}
	MailBodyObjWraper GetMailBody()
	{
		return m_MailBody;
	}
	MailBodyObjWraper GetMailBody() const
	{
		return m_MailBody;
	}

};
//获得邮件头回应封装类
class MailRpcMailHeadReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcMailHeadReplyWraper()
	{
		
		m_Result = -9999;
		m_MaxCount = 0;

	}
	//赋值构造函数
	MailRpcMailHeadReplyWraper(const MailRpcMailHeadReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcMailHeadReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcMailHeadReply ToPB() const
	{
		MailRpcMailHeadReply v;
		v.set_result( m_Result );
		v.mutable_mailheadlist()->Reserve(m_MailHeadList.size());
		for (int i=0; i<(int)m_MailHeadList.size(); i++)
		{
			*v.add_mailheadlist() = m_MailHeadList[i].ToPB();
		}
		v.set_maxcount( m_MaxCount );

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
		MailRpcMailHeadReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>MailHeadList(邮件头信息列表) [MailHeadObj] Array</li>\r\n";
		htmlBuff += "<li>MaxCount(最大邮件数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>MailHeadList：</li>\r\n";
		if( m_MailHeadList.size()>0) htmlBuff += m_MailHeadList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_MailHeadList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_MailHeadList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>MaxCount：%di</li>\r\n",m_MaxCount);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MailRpcMailHeadReply& v)
	{
		m_Result = v.result();
		m_MailHeadList.clear();
		m_MailHeadList.reserve(v.mailheadlist_size());
		for( int i=0; i<v.mailheadlist_size(); i++)
			m_MailHeadList.push_back(v.mailheadlist(i));
		m_MaxCount = v.maxcount();

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
	//邮件头信息列表
	vector<MailHeadObjWraper> m_MailHeadList;
public:
	int SizeMailHeadList()
	{
		return m_MailHeadList.size();
	}
	const vector<MailHeadObjWraper>& GetMailHeadList() const
	{
		return m_MailHeadList;
	}
	MailHeadObjWraper GetMailHeadList(int Index) const
	{
		if(Index<0 || Index>=(int)m_MailHeadList.size())
		{
			assert(false);
			return MailHeadObjWraper();
		}
		return m_MailHeadList[Index];
	}
	void SetMailHeadList( const vector<MailHeadObjWraper>& v )
	{
		m_MailHeadList=v;
	}
	void ClearMailHeadList( )
	{
		m_MailHeadList.clear();
	}
	void SetMailHeadList( int Index, const MailHeadObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_MailHeadList.size())
		{
			assert(false);
			return;
		}
		m_MailHeadList[Index] = v;
	}
	void AddMailHeadList( const MailHeadObjWraper& v )
	{
		m_MailHeadList.push_back(v);
	}
private:
	//最大邮件数量
	INT32 m_MaxCount;
public:
	void SetMaxCount( INT32 v)
	{
		m_MaxCount=v;
	}
	INT32 GetMaxCount()
	{
		return m_MaxCount;
	}
	INT32 GetMaxCount() const
	{
		return m_MaxCount;
	}

};
//获得邮件头请求封装类
class MailRpcMailHeadAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcMailHeadAskWraper()
	{
		
		m_Count = 0;
		m_UId = -1;

	}
	//赋值构造函数
	MailRpcMailHeadAskWraper(const MailRpcMailHeadAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcMailHeadAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcMailHeadAsk ToPB() const
	{
		MailRpcMailHeadAsk v;
		v.set_count( m_Count );
		v.set_uid( m_UId );

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
		MailRpcMailHeadAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Count(数量) [sint32]</li>\r\n";
		htmlBuff += "<li>UId(UId) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Count：%di</li>\r\n",m_Count);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UId：%lldL</li>\r\n",m_UId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MailRpcMailHeadAsk& v)
	{
		m_Count = v.count();
		m_UId = v.uid();

	}

private:
	//数量
	INT32 m_Count;
public:
	void SetCount( INT32 v)
	{
		m_Count=v;
	}
	INT32 GetCount()
	{
		return m_Count;
	}
	INT32 GetCount() const
	{
		return m_Count;
	}
private:
	//UId
	INT64 m_UId;
public:
	void SetUId( INT64 v)
	{
		m_UId=v;
	}
	INT64 GetUId()
	{
		return m_UId;
	}
	INT64 GetUId() const
	{
		return m_UId;
	}

};
//删除邮件请求封装类
class MailRpcDelMailAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcDelMailAskWraper()
	{
		

	}
	//赋值构造函数
	MailRpcDelMailAskWraper(const MailRpcDelMailAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcDelMailAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcDelMailAsk ToPB() const
	{
		MailRpcDelMailAsk v;
		v.mutable_uidlist()->Reserve(m_UidList.size());
		for (int i=0; i<(int)m_UidList.size(); i++)
		{
			v.add_uidlist(m_UidList[i]);
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
		MailRpcDelMailAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UidList(UidList) [sint64] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>UidList：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_UidList.size(); i++){
			tmpLine.Fmt("<td>%lldL</td>\r\n",m_UidList[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_UidList.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MailRpcDelMailAsk& v)
	{
		m_UidList.clear();
		m_UidList.reserve(v.uidlist_size());
		for( int i=0; i<v.uidlist_size(); i++)
			m_UidList.push_back(v.uidlist(i));

	}

private:
	//UidList
	vector<INT64> m_UidList;
public:
	int SizeUidList()
	{
		return m_UidList.size();
	}
	const vector<INT64>& GetUidList() const
	{
		return m_UidList;
	}
	INT64 GetUidList(int Index) const
	{
		if(Index<0 || Index>=(int)m_UidList.size())
		{
			assert(false);
			return INT64();
		}
		return m_UidList[Index];
	}
	void SetUidList( const vector<INT64>& v )
	{
		m_UidList=v;
	}
	void ClearUidList( )
	{
		m_UidList.clear();
	}
	void SetUidList( int Index, INT64 v )
	{
		if(Index<0 || Index>=(int)m_UidList.size())
		{
			assert(false);
			return;
		}
		m_UidList[Index] = v;
	}
	void AddUidList( INT64 v = -1 )
	{
		m_UidList.push_back(v);
	}

};
//获得邮件内容请求封装类
class MailRpcOpenMailAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcOpenMailAskWraper()
	{
		
		m_UId = -1;

	}
	//赋值构造函数
	MailRpcOpenMailAskWraper(const MailRpcOpenMailAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcOpenMailAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcOpenMailAsk ToPB() const
	{
		MailRpcOpenMailAsk v;
		v.set_uid( m_UId );

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
		MailRpcOpenMailAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UId(UId) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UId：%lldL</li>\r\n",m_UId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MailRpcOpenMailAsk& v)
	{
		m_UId = v.uid();

	}

private:
	//UId
	INT64 m_UId;
public:
	void SetUId( INT64 v)
	{
		m_UId=v;
	}
	INT64 GetUId()
	{
		return m_UId;
	}
	INT64 GetUId() const
	{
		return m_UId;
	}

};
//删除邮件回应封装类
class MailRpcDelMailReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcDelMailReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	MailRpcDelMailReplyWraper(const MailRpcDelMailReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcDelMailReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcDelMailReply ToPB() const
	{
		MailRpcDelMailReply v;
		v.set_result( m_Result );
		v.mutable_uidlist()->Reserve(m_UidList.size());
		for (int i=0; i<(int)m_UidList.size(); i++)
		{
			v.add_uidlist(m_UidList[i]);
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
		MailRpcDelMailReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>UidList(UidList) [sint64] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>UidList：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_UidList.size(); i++){
			tmpLine.Fmt("<td>%lldL</td>\r\n",m_UidList[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_UidList.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MailRpcDelMailReply& v)
	{
		m_Result = v.result();
		m_UidList.clear();
		m_UidList.reserve(v.uidlist_size());
		for( int i=0; i<v.uidlist_size(); i++)
			m_UidList.push_back(v.uidlist(i));

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
	//UidList
	vector<INT64> m_UidList;
public:
	int SizeUidList()
	{
		return m_UidList.size();
	}
	const vector<INT64>& GetUidList() const
	{
		return m_UidList;
	}
	INT64 GetUidList(int Index) const
	{
		if(Index<0 || Index>=(int)m_UidList.size())
		{
			assert(false);
			return INT64();
		}
		return m_UidList[Index];
	}
	void SetUidList( const vector<INT64>& v )
	{
		m_UidList=v;
	}
	void ClearUidList( )
	{
		m_UidList.clear();
	}
	void SetUidList( int Index, INT64 v )
	{
		if(Index<0 || Index>=(int)m_UidList.size())
		{
			assert(false);
			return;
		}
		m_UidList[Index] = v;
	}
	void AddUidList( INT64 v = -1 )
	{
		m_UidList.push_back(v);
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<MailRpcMailHeadAskWraper>{ enum{ID=RPC_CODE_MAIL_MAILHEAD_REQUEST};};
template<> struct MessageIdT<MailRpcMailHeadReplyWraper>{ enum{ID=RPC_CODE_MAIL_MAILHEAD_REQUEST};};
template<> struct MessageIdT<MailRpcOpenMailAskWraper>{ enum{ID=RPC_CODE_MAIL_OPENMAIL_REQUEST};};
template<> struct MessageIdT<MailRpcOpenMailReplyWraper>{ enum{ID=RPC_CODE_MAIL_OPENMAIL_REQUEST};};
template<> struct MessageIdT<MailRpcNewMailNotifyWraper>{ enum{ID=RPC_CODE_MAIL_NEWMAIL_NOTIFY};};
template<> struct MessageIdT<MailRpcDelMailAskWraper>{ enum{ID=RPC_CODE_MAIL_DELMAIL_REQUEST};};
template<> struct MessageIdT<MailRpcDelMailReplyWraper>{ enum{ID=RPC_CODE_MAIL_DELMAIL_REQUEST};};
template<> struct MessageIdT<MailRpcGetRewardAskWraper>{ enum{ID=RPC_CODE_MAIL_GETREWARD_REQUEST};};
template<> struct MessageIdT<MailRpcGetRewardReplyWraper>{ enum{ID=RPC_CODE_MAIL_GETREWARD_REQUEST};};
template<> struct MessageIdT<MailRpcOneKeyGetRewardAskWraper>{ enum{ID=RPC_CODE_MAIL_ONEKEYGETREWARD_REQUEST};};
template<> struct MessageIdT<MailRpcOneKeyGetRewardReplyWraper>{ enum{ID=RPC_CODE_MAIL_ONEKEYGETREWARD_REQUEST};};


#endif
