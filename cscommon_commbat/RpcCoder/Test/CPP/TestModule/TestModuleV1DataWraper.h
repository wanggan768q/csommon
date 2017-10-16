/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperTestModule.h
* Author:       甘业清
* Description:  TestModule同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_TESTMODULE_H
#define __SYNC_WRAPER_TESTMODULE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "TestModuleV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//NewDataStruct封装类
class TestModuleDataWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	TestModuleDataWraperV1()
	{
		
		m_Field = -1;

	}
	//赋值构造函数
	TestModuleDataWraperV1(const TestModuleDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const TestModuleDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TestModuleDataV1 ToPB() const
	{
		TestModuleDataV1 v;
		v.set_field( m_Field );

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
		TestModuleDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Field(Field) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Field：%di</li>\r\n",m_Field);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TestModuleDataV1& v)
	{
		m_Field = v.field();

	}

private:
	//Field
	INT32 m_Field;
public:
	void SetField( INT32 v)
	{
		m_Field=v;
	}
	INT32 GetField()
	{
		return m_Field;
	}
	INT32 GetField() const
	{
		return m_Field;
	}

};
//Useless封装类
class TestModuleUselessWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<TestModuleUselessWraperV1>
{
public:
	//构造函数
	TestModuleUselessWraperV1()
	{
		SetDataWraper( this );


	}
	//赋值构造函数
	TestModuleUselessWraperV1(const TestModuleUselessV1& v){ Init(v); }
	//等号重载函数
	void operator = (const TestModuleUselessV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TestModuleUselessV1 ToPB() const
	{
		TestModuleUselessV1 v;

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
		TestModuleUselessV1 pb;
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
	void Init(const TestModuleUselessV1& v)
	{

	}


};

#endif
