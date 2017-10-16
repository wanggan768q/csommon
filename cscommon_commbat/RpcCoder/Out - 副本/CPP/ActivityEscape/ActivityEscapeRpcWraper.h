/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperActivityEscape.h
* Author:       甘业清
* Description:  活动 大逃杀RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_ACTIVITYESCAPE_H
#define __RPC_WRAPER_ACTIVITYESCAPE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "ActivityEscapeRpc.pb.h"



//活动 大逃杀类的枚举定义
enum ConstActivityEscapeE
{
	MODULE_ID_ACTIVITYESCAPE                     = 31,	//活动 大逃杀模块ID
	RPC_CODE_ACTIVITYESCAPE_SIGNUP_REQUEST       = 3151,	//活动 大逃杀-->报名进入-->请求


};


//报名进入回应封装类
class ActivityEscapeRpcSignUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityEscapeRpcSignUpReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ActivityEscapeRpcSignUpReplyWraper(const ActivityEscapeRpcSignUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityEscapeRpcSignUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityEscapeRpcSignUpReply ToPB() const
	{
		ActivityEscapeRpcSignUpReply v;
		v.set_result( m_Result );
		v.mutable_losepeopleid()->Reserve(m_LosePeopleID.size());
		for (int i=0; i<(int)m_LosePeopleID.size(); i++)
		{
			v.add_losepeopleid(m_LosePeopleID[i]);
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
		ActivityEscapeRpcSignUpReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>LosePeopleID(次数已满的人员id) [sint64] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>LosePeopleID：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_LosePeopleID.size(); i++){
			tmpLine.Fmt("<td>%lldL</td>\r\n",m_LosePeopleID[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_LosePeopleID.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityEscapeRpcSignUpReply& v)
	{
		m_Result = v.result();
		m_LosePeopleID.clear();
		m_LosePeopleID.reserve(v.losepeopleid_size());
		for( int i=0; i<v.losepeopleid_size(); i++)
			m_LosePeopleID.push_back(v.losepeopleid(i));

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
	//次数已满的人员id
	vector<INT64> m_LosePeopleID;
public:
	int SizeLosePeopleID()
	{
		return m_LosePeopleID.size();
	}
	const vector<INT64>& GetLosePeopleID() const
	{
		return m_LosePeopleID;
	}
	INT64 GetLosePeopleID(int Index) const
	{
		if(Index<0 || Index>=(int)m_LosePeopleID.size())
		{
			assert(false);
			return INT64();
		}
		return m_LosePeopleID[Index];
	}
	void SetLosePeopleID( const vector<INT64>& v )
	{
		m_LosePeopleID=v;
	}
	void ClearLosePeopleID( )
	{
		m_LosePeopleID.clear();
	}
	void SetLosePeopleID( int Index, INT64 v )
	{
		if(Index<0 || Index>=(int)m_LosePeopleID.size())
		{
			assert(false);
			return;
		}
		m_LosePeopleID[Index] = v;
	}
	void AddLosePeopleID( INT64 v = -1 )
	{
		m_LosePeopleID.push_back(v);
	}

};
//报名进入请求封装类
class ActivityEscapeRpcSignUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityEscapeRpcSignUpAskWraper()
	{
		

	}
	//赋值构造函数
	ActivityEscapeRpcSignUpAskWraper(const ActivityEscapeRpcSignUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityEscapeRpcSignUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityEscapeRpcSignUpAsk ToPB() const
	{
		ActivityEscapeRpcSignUpAsk v;

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
		ActivityEscapeRpcSignUpAsk pb;
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
	void Init(const ActivityEscapeRpcSignUpAsk& v)
	{

	}


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<ActivityEscapeRpcSignUpAskWraper>{ enum{ID=RPC_CODE_ACTIVITYESCAPE_SIGNUP_REQUEST};};
template<> struct MessageIdT<ActivityEscapeRpcSignUpReplyWraper>{ enum{ID=RPC_CODE_ACTIVITYESCAPE_SIGNUP_REQUEST};};


#endif
