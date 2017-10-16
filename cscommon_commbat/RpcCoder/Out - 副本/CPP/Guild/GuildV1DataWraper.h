/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperGuild.h
* Author:       甘业清
* Description:  帮派同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_GUILD_H
#define __SYNC_WRAPER_GUILD_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "GuildV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//帮会数据封装类
class GuildGuildListWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<GuildGuildListWraperV1>
{
public:
	//构造函数
	GuildGuildListWraperV1()
	{
		SetDataWraper( this );

		m_GuildData = GuildInfoObjWraper();

	}
	//赋值构造函数
	GuildGuildListWraperV1(const GuildGuildListV1& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildGuildListV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildGuildListV1 ToPB() const
	{
		GuildGuildListV1 v;
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
		GuildGuildListV1 pb;
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
	void Init(const GuildGuildListV1& v)
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

#endif
