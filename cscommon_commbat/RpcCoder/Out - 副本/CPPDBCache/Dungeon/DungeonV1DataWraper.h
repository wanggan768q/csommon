/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperDungeon.h
* Author:       甘业清
* Description:  进出副本模块同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_DUNGEON_H
#define __SYNC_WRAPER_DUNGEON_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DungeonV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//副本相关信息封装类
class DungeonDungeonInfoWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<DungeonDungeonInfoWraperV1>
{
public:
	//构造函数
	DungeonDungeonInfoWraperV1()
	{
		SetDataWraper( this );

		m_DungeonKey = "";
		m_DungeonId = -1;
		m_DungeonType = -1;
		m_KeyId = -1;
		m_Host = "";
		m_Port = -1;
		m_Guild = -1;

	}
	//赋值构造函数
	DungeonDungeonInfoWraperV1(const DungeonDungeonInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonDungeonInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonDungeonInfoV1 ToPB() const
	{
		DungeonDungeonInfoV1 v;
		v.set_dungeonkey( m_DungeonKey );
		v.set_dungeonid( m_DungeonId );
		v.set_dungeontype( m_DungeonType );
		v.set_keyid( m_KeyId );
		v.set_host( m_Host );
		v.set_port( m_Port );
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
		DungeonDungeonInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DungeonKey(Key) [string]</li>\r\n";
		htmlBuff += "<li>DungeonId(副本ID) [sint32]</li>\r\n";
		htmlBuff += "<li>DungeonType(副本类型) [sint32]</li>\r\n";
		htmlBuff += "<li>KeyId(KeyId) [sint32]</li>\r\n";
		htmlBuff += "<li>Host(Host) [string]</li>\r\n";
		htmlBuff += "<li>Port(Port) [sint32]</li>\r\n";
		htmlBuff += "<li>Guild(帮派Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>DungeonKey：\""+m_DungeonKey+"\"</li>\r\n";
		tmpLine.Fmt("<li>DungeonId：%di</li>\r\n",m_DungeonId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DungeonType：%di</li>\r\n",m_DungeonType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>KeyId：%di</li>\r\n",m_KeyId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Host：\""+m_Host+"\"</li>\r\n";
		tmpLine.Fmt("<li>Port：%di</li>\r\n",m_Port);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Guild：%di</li>\r\n",m_Guild);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DungeonDungeonInfoV1& v)
	{
		m_DungeonKey = v.dungeonkey();
		m_DungeonId = v.dungeonid();
		m_DungeonType = v.dungeontype();
		m_KeyId = v.keyid();
		m_Host = v.host();
		m_Port = v.port();
		m_Guild = v.guild();

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
	//KeyId
	INT32 m_KeyId;
public:
	void SetKeyId( INT32 v)
	{
		m_KeyId=v;
	}
	INT32 GetKeyId()
	{
		return m_KeyId;
	}
	INT32 GetKeyId() const
	{
		return m_KeyId;
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

};

#endif
