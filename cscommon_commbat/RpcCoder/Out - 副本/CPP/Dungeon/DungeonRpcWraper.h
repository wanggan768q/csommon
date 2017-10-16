/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperDungeon.h
* Author:       甘业清
* Description:  进出副本模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_DUNGEON_H
#define __RPC_WRAPER_DUNGEON_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "DungeonRpc.pb.h"



//进出副本模块类的枚举定义
enum ConstDungeonE
{
	MODULE_ID_DUNGEON                            = 12,	//进出副本模块模块ID
	RPC_CODE_DUNGEON_ENTER_REQUEST               = 1251,	//进出副本模块-->进入-->请求
	RPC_CODE_DUNGEON_OPEN_NOTIFY                 = 1252,	//进出副本模块-->打开副本通知-->通知
	RPC_CODE_DUNGEON_TRYENTER_REQUEST            = 1253,	//进出副本模块-->能否进入-->请求
	RPC_CODE_DUNGEON_TRANSFER_NOTIFY             = 1254,	//进出副本模块-->传送-->通知


};


//能否进入回应封装类
class DungeonRpcTryEnterReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcTryEnterReplyWraper()
	{
		
		m_Result = -9999;
		m_DungeonId = -1;
		m_BirthPoint = -1;
		m_FaceDir = -1;
		m_GuildId = -1;

	}
	//赋值构造函数
	DungeonRpcTryEnterReplyWraper(const DungeonRpcTryEnterReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcTryEnterReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcTryEnterReply ToPB() const
	{
		DungeonRpcTryEnterReply v;
		v.set_result( m_Result );
		v.set_dungeonid( m_DungeonId );
		v.set_birthpoint( m_BirthPoint );
		v.set_facedir( m_FaceDir );
		v.set_guildid( m_GuildId );

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
		DungeonRpcTryEnterReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>DungeonId(副本ID) [sint32]</li>\r\n";
		htmlBuff += "<li>BirthPoint(出生点) [sint32]</li>\r\n";
		htmlBuff += "<li>FaceDir(朝向) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildId(帮会Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DungeonId：%di</li>\r\n",m_DungeonId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BirthPoint：%di</li>\r\n",m_BirthPoint);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>FaceDir：%di</li>\r\n",m_FaceDir);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GuildId：%di</li>\r\n",m_GuildId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DungeonRpcTryEnterReply& v)
	{
		m_Result = v.result();
		m_DungeonId = v.dungeonid();
		m_BirthPoint = v.birthpoint();
		m_FaceDir = v.facedir();
		m_GuildId = v.guildid();

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
	//副本ID
	INT32 m_DungeonId;
public:
	void SetDungeonId( INT32 v)
	{
		m_DungeonId=v;
	}
	INT32 GetDungeonId()
	{
		return m_DungeonId;
	}
	INT32 GetDungeonId() const
	{
		return m_DungeonId;
	}
private:
	//出生点
	INT32 m_BirthPoint;
public:
	void SetBirthPoint( INT32 v)
	{
		m_BirthPoint=v;
	}
	INT32 GetBirthPoint()
	{
		return m_BirthPoint;
	}
	INT32 GetBirthPoint() const
	{
		return m_BirthPoint;
	}
private:
	//朝向
	INT32 m_FaceDir;
public:
	void SetFaceDir( INT32 v)
	{
		m_FaceDir=v;
	}
	INT32 GetFaceDir()
	{
		return m_FaceDir;
	}
	INT32 GetFaceDir() const
	{
		return m_FaceDir;
	}
private:
	//帮会Id
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

};
//传送通知封装类
class DungeonRpcTransferNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcTransferNotifyWraper()
	{
		
		m_DungeonId = -1;

	}
	//赋值构造函数
	DungeonRpcTransferNotifyWraper(const DungeonRpcTransferNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcTransferNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcTransferNotify ToPB() const
	{
		DungeonRpcTransferNotify v;
		v.set_dungeonid( m_DungeonId );

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
		DungeonRpcTransferNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DungeonId(副本ID) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>DungeonId：%di</li>\r\n",m_DungeonId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DungeonRpcTransferNotify& v)
	{
		m_DungeonId = v.dungeonid();

	}

private:
	//副本ID
	INT32 m_DungeonId;
public:
	void SetDungeonId( INT32 v)
	{
		m_DungeonId=v;
	}
	INT32 GetDungeonId()
	{
		return m_DungeonId;
	}
	INT32 GetDungeonId() const
	{
		return m_DungeonId;
	}

};
//能否进入请求封装类
class DungeonRpcTryEnterAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcTryEnterAskWraper()
	{
		
		m_DungeonId = -1;
		m_BirthPoint = -1;
		m_FaceDir = -1;
		m_GuildId = -1;

	}
	//赋值构造函数
	DungeonRpcTryEnterAskWraper(const DungeonRpcTryEnterAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcTryEnterAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcTryEnterAsk ToPB() const
	{
		DungeonRpcTryEnterAsk v;
		v.set_dungeonid( m_DungeonId );
		v.set_birthpoint( m_BirthPoint );
		v.set_facedir( m_FaceDir );
		v.set_guildid( m_GuildId );

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
		DungeonRpcTryEnterAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DungeonId(副本ID) [sint32]</li>\r\n";
		htmlBuff += "<li>BirthPoint(出生点) [sint32]</li>\r\n";
		htmlBuff += "<li>FaceDir(朝向) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildId(帮会Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>DungeonId：%di</li>\r\n",m_DungeonId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BirthPoint：%di</li>\r\n",m_BirthPoint);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>FaceDir：%di</li>\r\n",m_FaceDir);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GuildId：%di</li>\r\n",m_GuildId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DungeonRpcTryEnterAsk& v)
	{
		m_DungeonId = v.dungeonid();
		m_BirthPoint = v.birthpoint();
		m_FaceDir = v.facedir();
		m_GuildId = v.guildid();

	}

private:
	//副本ID
	INT32 m_DungeonId;
public:
	void SetDungeonId( INT32 v)
	{
		m_DungeonId=v;
	}
	INT32 GetDungeonId()
	{
		return m_DungeonId;
	}
	INT32 GetDungeonId() const
	{
		return m_DungeonId;
	}
private:
	//出生点
	INT32 m_BirthPoint;
public:
	void SetBirthPoint( INT32 v)
	{
		m_BirthPoint=v;
	}
	INT32 GetBirthPoint()
	{
		return m_BirthPoint;
	}
	INT32 GetBirthPoint() const
	{
		return m_BirthPoint;
	}
private:
	//朝向
	INT32 m_FaceDir;
public:
	void SetFaceDir( INT32 v)
	{
		m_FaceDir=v;
	}
	INT32 GetFaceDir()
	{
		return m_FaceDir;
	}
	INT32 GetFaceDir() const
	{
		return m_FaceDir;
	}
private:
	//帮会Id
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

};
//进入请求封装类
class DungeonRpcEnterAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcEnterAskWraper()
	{
		
		m_DungeonId = -1;
		m_DungeonType = -1;
		m_BirthPoint = -1;
		m_FaceDir = -1;
		m_GuildId = -1;

	}
	//赋值构造函数
	DungeonRpcEnterAskWraper(const DungeonRpcEnterAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcEnterAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcEnterAsk ToPB() const
	{
		DungeonRpcEnterAsk v;
		v.set_dungeonid( m_DungeonId );
		v.set_dungeontype( m_DungeonType );
		v.set_birthpoint( m_BirthPoint );
		v.set_facedir( m_FaceDir );
		v.set_guildid( m_GuildId );

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
		DungeonRpcEnterAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DungeonId(副本ID) [sint32]</li>\r\n";
		htmlBuff += "<li>DungeonType(副本类型) [sint32]</li>\r\n";
		htmlBuff += "<li>BirthPoint(出生点) [sint32]</li>\r\n";
		htmlBuff += "<li>FaceDir(朝向) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildId(帮会Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>DungeonId：%di</li>\r\n",m_DungeonId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DungeonType：%di</li>\r\n",m_DungeonType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BirthPoint：%di</li>\r\n",m_BirthPoint);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>FaceDir：%di</li>\r\n",m_FaceDir);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GuildId：%di</li>\r\n",m_GuildId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DungeonRpcEnterAsk& v)
	{
		m_DungeonId = v.dungeonid();
		m_DungeonType = v.dungeontype();
		m_BirthPoint = v.birthpoint();
		m_FaceDir = v.facedir();
		m_GuildId = v.guildid();

	}

private:
	//副本ID
	INT32 m_DungeonId;
public:
	void SetDungeonId( INT32 v)
	{
		m_DungeonId=v;
	}
	INT32 GetDungeonId()
	{
		return m_DungeonId;
	}
	INT32 GetDungeonId() const
	{
		return m_DungeonId;
	}
private:
	//副本类型
	INT32 m_DungeonType;
public:
	void SetDungeonType( INT32 v)
	{
		m_DungeonType=v;
	}
	INT32 GetDungeonType()
	{
		return m_DungeonType;
	}
	INT32 GetDungeonType() const
	{
		return m_DungeonType;
	}
private:
	//出生点
	INT32 m_BirthPoint;
public:
	void SetBirthPoint( INT32 v)
	{
		m_BirthPoint=v;
	}
	INT32 GetBirthPoint()
	{
		return m_BirthPoint;
	}
	INT32 GetBirthPoint() const
	{
		return m_BirthPoint;
	}
private:
	//朝向
	INT32 m_FaceDir;
public:
	void SetFaceDir( INT32 v)
	{
		m_FaceDir=v;
	}
	INT32 GetFaceDir()
	{
		return m_FaceDir;
	}
	INT32 GetFaceDir() const
	{
		return m_FaceDir;
	}
private:
	//帮会Id
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

};
//进入回应封装类
class DungeonRpcEnterReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcEnterReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	DungeonRpcEnterReplyWraper(const DungeonRpcEnterReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcEnterReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcEnterReply ToPB() const
	{
		DungeonRpcEnterReply v;
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
		DungeonRpcEnterReply pb;
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
	void Init(const DungeonRpcEnterReply& v)
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
//打开副本通知通知封装类
class DungeonRpcOpenNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcOpenNotifyWraper()
	{
		
		m_DungeonKey = "";
		m_Host = "";
		m_Port = -1;
		m_DungeonId = -1;
		m_DungeonType = -1;
		m_GuildId = -1;

	}
	//赋值构造函数
	DungeonRpcOpenNotifyWraper(const DungeonRpcOpenNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcOpenNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcOpenNotify ToPB() const
	{
		DungeonRpcOpenNotify v;
		v.set_dungeonkey( m_DungeonKey );
		v.set_host( m_Host );
		v.set_port( m_Port );
		v.set_dungeonid( m_DungeonId );
		v.set_dungeontype( m_DungeonType );
		v.set_guildid( m_GuildId );

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
		DungeonRpcOpenNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DungeonKey(Key) [string]</li>\r\n";
		htmlBuff += "<li>Host(Host) [string]</li>\r\n";
		htmlBuff += "<li>Port(Port) [sint32]</li>\r\n";
		htmlBuff += "<li>DungeonId(副本ID) [sint32]</li>\r\n";
		htmlBuff += "<li>DungeonType(副本类型) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildId(帮会Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>DungeonKey：\""+m_DungeonKey+"\"</li>\r\n";
		htmlBuff += "<li>Host：\""+m_Host+"\"</li>\r\n";
		tmpLine.Fmt("<li>Port：%di</li>\r\n",m_Port);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DungeonId：%di</li>\r\n",m_DungeonId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DungeonType：%di</li>\r\n",m_DungeonType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GuildId：%di</li>\r\n",m_GuildId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DungeonRpcOpenNotify& v)
	{
		m_DungeonKey = v.dungeonkey();
		m_Host = v.host();
		m_Port = v.port();
		m_DungeonId = v.dungeonid();
		m_DungeonType = v.dungeontype();
		m_GuildId = v.guildid();

	}

private:
	//Key
	string m_DungeonKey;
public:
	void SetDungeonKey( const string& v)
	{
		m_DungeonKey=v;
	}
	string GetDungeonKey()
	{
		return m_DungeonKey;
	}
	string GetDungeonKey() const
	{
		return m_DungeonKey;
	}
private:
	//Host
	string m_Host;
public:
	void SetHost( const string& v)
	{
		m_Host=v;
	}
	string GetHost()
	{
		return m_Host;
	}
	string GetHost() const
	{
		return m_Host;
	}
private:
	//Port
	INT32 m_Port;
public:
	void SetPort( INT32 v)
	{
		m_Port=v;
	}
	INT32 GetPort()
	{
		return m_Port;
	}
	INT32 GetPort() const
	{
		return m_Port;
	}
private:
	//副本ID
	INT32 m_DungeonId;
public:
	void SetDungeonId( INT32 v)
	{
		m_DungeonId=v;
	}
	INT32 GetDungeonId()
	{
		return m_DungeonId;
	}
	INT32 GetDungeonId() const
	{
		return m_DungeonId;
	}
private:
	//副本类型
	INT32 m_DungeonType;
public:
	void SetDungeonType( INT32 v)
	{
		m_DungeonType=v;
	}
	INT32 GetDungeonType()
	{
		return m_DungeonType;
	}
	INT32 GetDungeonType() const
	{
		return m_DungeonType;
	}
private:
	//帮会Id
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

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<DungeonRpcEnterAskWraper>{ enum{ID=RPC_CODE_DUNGEON_ENTER_REQUEST};};
template<> struct MessageIdT<DungeonRpcEnterReplyWraper>{ enum{ID=RPC_CODE_DUNGEON_ENTER_REQUEST};};
template<> struct MessageIdT<DungeonRpcOpenNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_OPEN_NOTIFY};};
template<> struct MessageIdT<DungeonRpcTryEnterAskWraper>{ enum{ID=RPC_CODE_DUNGEON_TRYENTER_REQUEST};};
template<> struct MessageIdT<DungeonRpcTryEnterReplyWraper>{ enum{ID=RPC_CODE_DUNGEON_TRYENTER_REQUEST};};
template<> struct MessageIdT<DungeonRpcTransferNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_TRANSFER_NOTIFY};};


#endif
