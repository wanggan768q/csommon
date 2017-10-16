/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperZhanDou.h
* Author:       甘业清
* Description:  战斗同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_ZHANDOU_H
#define __SYNC_WRAPER_ZHANDOU_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "ZhanDouV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//行走数据封装类
class ZhanDouMoveDataWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	ZhanDouMoveDataWraperV1()
	{
		
		m_Dir = -1;

	}
	//赋值构造函数
	ZhanDouMoveDataWraperV1(const ZhanDouMoveDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const ZhanDouMoveDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ZhanDouMoveDataV1 ToPB() const
	{
		ZhanDouMoveDataV1 v;
		v.set_dir( m_Dir );

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
		ZhanDouMoveDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Dir(方向) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Dir：%di</li>\r\n",m_Dir);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ZhanDouMoveDataV1& v)
	{
		m_Dir = v.dir();

	}

private:
	//方向
	INT32 m_Dir;
public:
	void SetDir( INT32 v)
	{
		m_Dir=v;
	}
	INT32 GetDir()
	{
		return m_Dir;
	}
	INT32 GetDir() const
	{
		return m_Dir;
	}

};
//用户数据封装类
class ZhanDouUserDataWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<ZhanDouUserDataWraperV1>
{
public:
	//构造函数
	ZhanDouUserDataWraperV1()
	{
		SetDataWraper( this );


	}
	//赋值构造函数
	ZhanDouUserDataWraperV1(const ZhanDouUserDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const ZhanDouUserDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ZhanDouUserDataV1 ToPB() const
	{
		ZhanDouUserDataV1 v;

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
		ZhanDouUserDataV1 pb;
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
	void Init(const ZhanDouUserDataV1& v)
	{

	}


};

#endif
