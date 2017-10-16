/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     PubWraperClass.h
* Author:       甘业清
* Description:  公共数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __PUB_WRAPER_CLASS_H
#define __PUB_WRAPER_CLASS_H

#include "BASE.h"
#include "PublicStruct.pb.h"
#include "DataWraperInterface.h"



//排行榜数据封装类
class TopPeoValueWraper : public DataWraperInterface 
{
public:
	//构造函数
	TopPeoValueWraper()
	{
		
		m_PlanName = "";
		m_UserId = -1;
		m_LV = -1;
		m_AllRanking = -1;
		m_MyRanking = -1;

	}
	//赋值构造函数
	TopPeoValueWraper(const TopPeoValue& v){ Init(v); }
	//等号重载函数
	void operator = (const TopPeoValue& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TopPeoValue ToPB() const
	{
		TopPeoValue v;
		v.set_planname( m_PlanName );
		v.set_userid( m_UserId );
		v.set_lv( m_LV );
		v.set_allranking( m_AllRanking );
		v.set_myranking( m_MyRanking );

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
		TopPeoValue pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>PlanName(昵称) [string]</li>\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>LV(等级) [sint32]</li>\r\n";
		htmlBuff += "<li>AllRanking(总榜的名次) [sint32]</li>\r\n";
		htmlBuff += "<li>MyRanking(我在这个榜的名次) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>PlanName：\""+m_PlanName+"\"</li>\r\n";
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>LV：%di</li>\r\n",m_LV);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AllRanking：%di</li>\r\n",m_AllRanking);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MyRanking：%di</li>\r\n",m_MyRanking);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TopPeoValue& v)
	{
		m_PlanName = v.planname();
		m_UserId = v.userid();
		m_LV = v.lv();
		m_AllRanking = v.allranking();
		m_MyRanking = v.myranking();

	}

private:
	//昵称
	string m_PlanName;
public:
	void SetPlanName( const string& v)
	{
		m_PlanName=v;
	}
	string GetPlanName()
	{
		return m_PlanName;
	}
	string GetPlanName() const
	{
		return m_PlanName;
	}
private:
	//用户ID
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
	//等级
	INT32 m_LV;
public:
	void SetLV( INT32 v)
	{
		m_LV=v;
	}
	INT32 GetLV()
	{
		return m_LV;
	}
	INT32 GetLV() const
	{
		return m_LV;
	}
private:
	//总榜的名次
	INT32 m_AllRanking;
public:
	void SetAllRanking( INT32 v)
	{
		m_AllRanking=v;
	}
	INT32 GetAllRanking()
	{
		return m_AllRanking;
	}
	INT32 GetAllRanking() const
	{
		return m_AllRanking;
	}
private:
	//我在这个榜的名次
	INT32 m_MyRanking;
public:
	void SetMyRanking( INT32 v)
	{
		m_MyRanking=v;
	}
	INT32 GetMyRanking()
	{
		return m_MyRanking;
	}
	INT32 GetMyRanking() const
	{
		return m_MyRanking;
	}

};
//装备属性对象封装类
class BagAttrFloatObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagAttrFloatObjWraper()
	{
		
		m_AttrId = -1;
		m_AttrValue = -1;
		m_Index = -1;

	}
	//赋值构造函数
	BagAttrFloatObjWraper(const BagAttrFloatObj& v){ Init(v); }
	//等号重载函数
	void operator = (const BagAttrFloatObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagAttrFloatObj ToPB() const
	{
		BagAttrFloatObj v;
		v.set_attrid( m_AttrId );
		v.set_attrvalue( m_AttrValue );
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
		BagAttrFloatObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>AttrId(属性Id) [sint32]</li>\r\n";
		htmlBuff += "<li>AttrValue(属性值) [float]</li>\r\n";
		htmlBuff += "<li>Index(索引) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>AttrId：%di</li>\r\n",m_AttrId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttrValue：%.2ff</li>\r\n",m_AttrValue);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Index：%di</li>\r\n",m_Index);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagAttrFloatObj& v)
	{
		m_AttrId = v.attrid();
		m_AttrValue = v.attrvalue();
		m_Index = v.index();

	}

private:
	//属性Id
	INT32 m_AttrId;
public:
	void SetAttrId( INT32 v)
	{
		m_AttrId=v;
	}
	INT32 GetAttrId()
	{
		return m_AttrId;
	}
	INT32 GetAttrId() const
	{
		return m_AttrId;
	}
private:
	//属性值
	float m_AttrValue;
public:
	void SetAttrValue( float v)
	{
		m_AttrValue=v;
	}
	float GetAttrValue()
	{
		return m_AttrValue;
	}
	float GetAttrValue() const
	{
		return m_AttrValue;
	}
private:
	//索引
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
//键值对封装类
class KeyValue2IntIntWraper : public DataWraperInterface 
{
public:
	//构造函数
	KeyValue2IntIntWraper()
	{
		
		m_Key = -1;
		m_Value = -1;

	}
	//赋值构造函数
	KeyValue2IntIntWraper(const KeyValue2IntInt& v){ Init(v); }
	//等号重载函数
	void operator = (const KeyValue2IntInt& v){ Init(v); }
 	//转化成Protobuffer类型函数
	KeyValue2IntInt ToPB() const
	{
		KeyValue2IntInt v;
		v.set_key( m_Key );
		v.set_value( m_Value );

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
		KeyValue2IntInt pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Key(键) [sint32]</li>\r\n";
		htmlBuff += "<li>Value(值) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Key：%di</li>\r\n",m_Key);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Value：%di</li>\r\n",m_Value);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const KeyValue2IntInt& v)
	{
		m_Key = v.key();
		m_Value = v.value();

	}

private:
	//键
	INT32 m_Key;
public:
	void SetKey( INT32 v)
	{
		m_Key=v;
	}
	INT32 GetKey()
	{
		return m_Key;
	}
	INT32 GetKey() const
	{
		return m_Key;
	}
private:
	//值
	INT32 m_Value;
public:
	void SetValue( INT32 v)
	{
		m_Value=v;
	}
	INT32 GetValue()
	{
		return m_Value;
	}
	INT32 GetValue() const
	{
		return m_Value;
	}

};
//装备宝石对象封装类
class BagGemObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagGemObjWraper()
	{
		
		m_GemId = -1;
		m_Pos = -1;
		m_IsLock = false;
		m_Level = -1;
		m_Type = -1;

	}
	//赋值构造函数
	BagGemObjWraper(const BagGemObj& v){ Init(v); }
	//等号重载函数
	void operator = (const BagGemObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagGemObj ToPB() const
	{
		BagGemObj v;
		v.set_gemid( m_GemId );
		v.set_pos( m_Pos );
		v.set_islock( m_IsLock );
		v.set_level( m_Level );
		v.set_type( m_Type );

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
		BagGemObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GemId(宝石id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>IsLock(锁着， 未打孔) [bool]</li>\r\n";
		htmlBuff += "<li>Level(宝石等级) [sint32]</li>\r\n";
		htmlBuff += "<li>Type(配置的type) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>GemId：%di</li>\r\n",m_GemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsLock：%di</li>\r\n",m_IsLock);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagGemObj& v)
	{
		m_GemId = v.gemid();
		m_Pos = v.pos();
		m_IsLock = v.islock();
		m_Level = v.level();
		m_Type = v.type();

	}

private:
	//宝石id
	INT32 m_GemId;
public:
	void SetGemId( INT32 v)
	{
		m_GemId=v;
	}
	INT32 GetGemId()
	{
		return m_GemId;
	}
	INT32 GetGemId() const
	{
		return m_GemId;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//锁着， 未打孔
	bool m_IsLock;
public:
	void SetIsLock( bool v)
	{
		m_IsLock=v;
	}
	bool GetIsLock()
	{
		return m_IsLock;
	}
	bool GetIsLock() const
	{
		return m_IsLock;
	}
private:
	//宝石等级
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
	//配置的type
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}

};
//装备属性封装类
class BagAttrIntObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagAttrIntObjWraper()
	{
		
		m_AttrId = -1;
		m_AttrValue = -1;
		m_MaxAttrValue = -1;

	}
	//赋值构造函数
	BagAttrIntObjWraper(const BagAttrIntObj& v){ Init(v); }
	//等号重载函数
	void operator = (const BagAttrIntObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagAttrIntObj ToPB() const
	{
		BagAttrIntObj v;
		v.set_attrid( m_AttrId );
		v.set_attrvalue( m_AttrValue );
		v.set_maxattrvalue( m_MaxAttrValue );

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
		BagAttrIntObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>AttrId(属性Id) [sint32]</li>\r\n";
		htmlBuff += "<li>AttrValue(属性值) [sint32]</li>\r\n";
		htmlBuff += "<li>MaxAttrValue(最大属性值) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>AttrId：%di</li>\r\n",m_AttrId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttrValue：%di</li>\r\n",m_AttrValue);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MaxAttrValue：%di</li>\r\n",m_MaxAttrValue);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagAttrIntObj& v)
	{
		m_AttrId = v.attrid();
		m_AttrValue = v.attrvalue();
		m_MaxAttrValue = v.maxattrvalue();

	}

private:
	//属性Id
	INT32 m_AttrId;
public:
	void SetAttrId( INT32 v)
	{
		m_AttrId=v;
	}
	INT32 GetAttrId()
	{
		return m_AttrId;
	}
	INT32 GetAttrId() const
	{
		return m_AttrId;
	}
private:
	//属性值
	INT32 m_AttrValue;
public:
	void SetAttrValue( INT32 v)
	{
		m_AttrValue=v;
	}
	INT32 GetAttrValue()
	{
		return m_AttrValue;
	}
	INT32 GetAttrValue() const
	{
		return m_AttrValue;
	}
private:
	//最大属性值
	INT32 m_MaxAttrValue;
public:
	void SetMaxAttrValue( INT32 v)
	{
		m_MaxAttrValue=v;
	}
	INT32 GetMaxAttrValue()
	{
		return m_MaxAttrValue;
	}
	INT32 GetMaxAttrValue() const
	{
		return m_MaxAttrValue;
	}

};
//帮会战对象封装类
class GuildWarObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildWarObjWraper()
	{
		
		m_Guild_A = -1;
		m_Guild_B = -1;
		m_DungeonId = -1;
		m_Key = "";
		m_Port = -1;
		m_Host = "";

	}
	//赋值构造函数
	GuildWarObjWraper(const GuildWarObj& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildWarObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildWarObj ToPB() const
	{
		GuildWarObj v;
		v.set_guild_a( m_Guild_A );
		v.set_guild_b( m_Guild_B );
		v.set_dungeonid( m_DungeonId );
		v.set_key( m_Key );
		v.set_port( m_Port );
		v.set_host( m_Host );

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
		GuildWarObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Guild_A(A帮派Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Guild_B(B帮派Id) [sint32]</li>\r\n";
		htmlBuff += "<li>DungeonId(副本Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Key(Key) [string]</li>\r\n";
		htmlBuff += "<li>Port(Port) [sint32]</li>\r\n";
		htmlBuff += "<li>Host(Host) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Guild_A：%di</li>\r\n",m_Guild_A);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Guild_B：%di</li>\r\n",m_Guild_B);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DungeonId：%di</li>\r\n",m_DungeonId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Key：\""+m_Key+"\"</li>\r\n";
		tmpLine.Fmt("<li>Port：%di</li>\r\n",m_Port);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Host：\""+m_Host+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildWarObj& v)
	{
		m_Guild_A = v.guild_a();
		m_Guild_B = v.guild_b();
		m_DungeonId = v.dungeonid();
		m_Key = v.key();
		m_Port = v.port();
		m_Host = v.host();

	}

private:
	//A帮派Id
	INT32 m_Guild_A;
public:
	void SetGuild_A( INT32 v)
	{
		m_Guild_A=v;
	}
	INT32 GetGuild_A()
	{
		return m_Guild_A;
	}
	INT32 GetGuild_A() const
	{
		return m_Guild_A;
	}
private:
	//B帮派Id
	INT32 m_Guild_B;
public:
	void SetGuild_B( INT32 v)
	{
		m_Guild_B=v;
	}
	INT32 GetGuild_B()
	{
		return m_Guild_B;
	}
	INT32 GetGuild_B() const
	{
		return m_Guild_B;
	}
private:
	//副本Id
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
	//Key
	string m_Key;
public:
	void SetKey( const string& v)
	{
		m_Key=v;
	}
	string GetKey()
	{
		return m_Key;
	}
	string GetKey() const
	{
		return m_Key;
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

};
//背包装备附加属性封装类
class BagExtraAttrObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagExtraAttrObjWraper()
	{
		
		m_Id = -1;

	}
	//赋值构造函数
	BagExtraAttrObjWraper(const BagExtraAttrObj& v){ Init(v); }
	//等号重载函数
	void operator = (const BagExtraAttrObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagExtraAttrObj ToPB() const
	{
		BagExtraAttrObj v;
		v.mutable_extraattr()->Reserve(m_ExtraAttr.size());
		for (int i=0; i<(int)m_ExtraAttr.size(); i++)
		{
			*v.add_extraattr() = m_ExtraAttr[i].ToPB();
		}
		v.set_id( m_Id );

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
		BagExtraAttrObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ExtraAttr(附加属性) [BagAttrFloatObj] Array</li>\r\n";
		htmlBuff += "<li>Id(词条Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ExtraAttr：</li>\r\n";
		if( m_ExtraAttr.size()>0) htmlBuff += m_ExtraAttr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ExtraAttr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ExtraAttr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagExtraAttrObj& v)
	{
		m_ExtraAttr.clear();
		m_ExtraAttr.reserve(v.extraattr_size());
		for( int i=0; i<v.extraattr_size(); i++)
			m_ExtraAttr.push_back(v.extraattr(i));
		m_Id = v.id();

	}

private:
	//附加属性
	vector<BagAttrFloatObjWraper> m_ExtraAttr;
public:
	int SizeExtraAttr()
	{
		return m_ExtraAttr.size();
	}
	const vector<BagAttrFloatObjWraper>& GetExtraAttr() const
	{
		return m_ExtraAttr;
	}
	BagAttrFloatObjWraper GetExtraAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.size())
		{
			assert(false);
			return BagAttrFloatObjWraper();
		}
		return m_ExtraAttr[Index];
	}
	void SetExtraAttr( const vector<BagAttrFloatObjWraper>& v )
	{
		m_ExtraAttr=v;
	}
	void ClearExtraAttr( )
	{
		m_ExtraAttr.clear();
	}
	void SetExtraAttr( int Index, const BagAttrFloatObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.size())
		{
			assert(false);
			return;
		}
		m_ExtraAttr[Index] = v;
	}
	void AddExtraAttr( const BagAttrFloatObjWraper& v )
	{
		m_ExtraAttr.push_back(v);
	}
private:
	//词条Id
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}

};
//聊天消息对象封装类
class ChatMsgObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	ChatMsgObjWraper()
	{
		
		m_Channel = 0;
		m_Text = "";
		m_Voice = "";
		m_TargetUserId = -1;
		m_URL = "";
		m_ChildChannel = -1;

	}
	//赋值构造函数
	ChatMsgObjWraper(const ChatMsgObj& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatMsgObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatMsgObj ToPB() const
	{
		ChatMsgObj v;
		v.set_channel( m_Channel );
		v.set_text( m_Text );
		v.set_voice( m_Voice );
		v.set_targetuserid( m_TargetUserId );
		v.set_url( m_URL );
		v.set_childchannel( m_ChildChannel );

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
		ChatMsgObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Channel(频道) [sint32]</li>\r\n";
		htmlBuff += "<li>Text(文字) [string]</li>\r\n";
		htmlBuff += "<li>Voice(语音) [bytes]</li>\r\n";
		htmlBuff += "<li>TargetUserId(对方UserId) [sint64]</li>\r\n";
		htmlBuff += "<li>URL(URL) [bytes]</li>\r\n";
		htmlBuff += "<li>ChildChannel(子频道) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Channel：%di</li>\r\n",m_Channel);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Text：\""+m_Text+"\"</li>\r\n";
		htmlBuff += "<li>Voice：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>TargetUserId：%lldL</li>\r\n",m_TargetUserId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>URL：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>ChildChannel：%di</li>\r\n",m_ChildChannel);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ChatMsgObj& v)
	{
		m_Channel = v.channel();
		m_Text = v.text();
		m_Voice = v.voice();
		m_TargetUserId = v.targetuserid();
		m_URL = v.url();
		m_ChildChannel = v.childchannel();

	}

private:
	//频道
	INT32 m_Channel;
public:
	void SetChannel( INT32 v)
	{
		m_Channel=v;
	}
	INT32 GetChannel()
	{
		return m_Channel;
	}
	INT32 GetChannel() const
	{
		return m_Channel;
	}
private:
	//文字
	string m_Text;
public:
	void SetText( const string& v)
	{
		m_Text=v;
	}
	string GetText()
	{
		return m_Text;
	}
	string GetText() const
	{
		return m_Text;
	}
private:
	//语音
	string m_Voice;
public:
	void SetVoice( const string& v)
	{
		m_Voice=v;
	}
	string GetVoice()
	{
		return m_Voice;
	}
	string GetVoice() const
	{
		return m_Voice;
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
	//URL
	string m_URL;
public:
	void SetURL( const string& v)
	{
		m_URL=v;
	}
	string GetURL()
	{
		return m_URL;
	}
	string GetURL() const
	{
		return m_URL;
	}
private:
	//子频道
	INT32 m_ChildChannel;
public:
	void SetChildChannel( INT32 v)
	{
		m_ChildChannel=v;
	}
	INT32 GetChildChannel()
	{
		return m_ChildChannel;
	}
	INT32 GetChildChannel() const
	{
		return m_ChildChannel;
	}

};
//聊天用户信息对象封装类
class ChatUserInfoObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	ChatUserInfoObjWraper()
	{
		
		m_UserId = -1;
		m_UserName = "";
		m_Prof = -1;
		m_Level = -1;

	}
	//赋值构造函数
	ChatUserInfoObjWraper(const ChatUserInfoObj& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatUserInfoObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatUserInfoObj ToPB() const
	{
		ChatUserInfoObj v;
		v.set_userid( m_UserId );
		v.set_username( m_UserName );
		v.set_prof( m_Prof );
		v.set_level( m_Level );

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
		ChatUserInfoObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>UserName(玩家名字) [string]</li>\r\n";
		htmlBuff += "<li>Prof(职业) [sint32]</li>\r\n";
		htmlBuff += "<li>Level(玩家等级) [sint32]</li>\r\n";

		
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
		tmpLine.Fmt("<li>Prof：%di</li>\r\n",m_Prof);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ChatUserInfoObj& v)
	{
		m_UserId = v.userid();
		m_UserName = v.username();
		m_Prof = v.prof();
		m_Level = v.level();

	}

private:
	//用户ID
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
	//玩家名字
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
	//玩家等级
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

};
//超链接作息封装类
class ChatHyperLinkWraper : public DataWraperInterface 
{
public:
	//构造函数
	ChatHyperLinkWraper()
	{
		
		m_Uid = -1;
		m_ConfigID = -1;
		m_Type = -1;
		m_Text = "";
		m_Userid = -1;
		m_FunId = -1;
		m_FunParam = "";

	}
	//赋值构造函数
	ChatHyperLinkWraper(const ChatHyperLink& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatHyperLink& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatHyperLink ToPB() const
	{
		ChatHyperLink v;
		v.set_uid( m_Uid );
		v.set_configid( m_ConfigID );
		v.set_type( m_Type );
		v.set_text( m_Text );
		v.set_userid( m_Userid );
		v.set_funid( m_FunId );
		v.set_funparam( m_FunParam );

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
		ChatHyperLink pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Uid(物品唯一ID) [sint64]</li>\r\n";
		htmlBuff += "<li>ConfigID(配置表ID) [sint32]</li>\r\n";
		htmlBuff += "<li>Type(超链类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Text(描述) [string]</li>\r\n";
		htmlBuff += "<li>Userid(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>FunId(功能Id) [sint32]</li>\r\n";
		htmlBuff += "<li>FunParam(功能参数) [bytes]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Uid：%lldL</li>\r\n",m_Uid);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ConfigID：%di</li>\r\n",m_ConfigID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Text：\""+m_Text+"\"</li>\r\n";
		tmpLine.Fmt("<li>Userid：%lldL</li>\r\n",m_Userid);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>FunId：%di</li>\r\n",m_FunId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>FunParam：\"...\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ChatHyperLink& v)
	{
		m_Uid = v.uid();
		m_ConfigID = v.configid();
		m_Type = v.type();
		m_Text = v.text();
		m_Userid = v.userid();
		m_FunId = v.funid();
		m_FunParam = v.funparam();

	}

private:
	//物品唯一ID
	INT64 m_Uid;
public:
	void SetUid( INT64 v)
	{
		m_Uid=v;
	}
	INT64 GetUid()
	{
		return m_Uid;
	}
	INT64 GetUid() const
	{
		return m_Uid;
	}
private:
	//配置表ID
	INT32 m_ConfigID;
public:
	void SetConfigID( INT32 v)
	{
		m_ConfigID=v;
	}
	INT32 GetConfigID()
	{
		return m_ConfigID;
	}
	INT32 GetConfigID() const
	{
		return m_ConfigID;
	}
private:
	//超链类型
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}
private:
	//描述
	string m_Text;
public:
	void SetText( const string& v)
	{
		m_Text=v;
	}
	string GetText()
	{
		return m_Text;
	}
	string GetText() const
	{
		return m_Text;
	}
private:
	//用户ID
	INT64 m_Userid;
public:
	void SetUserid( INT64 v)
	{
		m_Userid=v;
	}
	INT64 GetUserid()
	{
		return m_Userid;
	}
	INT64 GetUserid() const
	{
		return m_Userid;
	}
private:
	//功能Id
	INT32 m_FunId;
public:
	void SetFunId( INT32 v)
	{
		m_FunId=v;
	}
	INT32 GetFunId()
	{
		return m_FunId;
	}
	INT32 GetFunId() const
	{
		return m_FunId;
	}
private:
	//功能参数
	string m_FunParam;
public:
	void SetFunParam( const string& v)
	{
		m_FunParam=v;
	}
	string GetFunParam()
	{
		return m_FunParam;
	}
	string GetFunParam() const
	{
		return m_FunParam;
	}

};
//附加属性Id封装类
class BagExtraAttrIdObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagExtraAttrIdObjWraper()
	{
		
		m_Id = -1;

	}
	//赋值构造函数
	BagExtraAttrIdObjWraper(const BagExtraAttrIdObj& v){ Init(v); }
	//等号重载函数
	void operator = (const BagExtraAttrIdObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagExtraAttrIdObj ToPB() const
	{
		BagExtraAttrIdObj v;
		v.mutable_attrid()->Reserve(m_AttrId.size());
		for (int i=0; i<(int)m_AttrId.size(); i++)
		{
			v.add_attrid(m_AttrId[i]);
		}
		v.set_id( m_Id );

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
		BagExtraAttrIdObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>AttrId(属性Id) [sint32] Array</li>\r\n";
		htmlBuff += "<li>Id(词条Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>AttrId：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_AttrId.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_AttrId[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_AttrId.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagExtraAttrIdObj& v)
	{
		m_AttrId.clear();
		m_AttrId.reserve(v.attrid_size());
		for( int i=0; i<v.attrid_size(); i++)
			m_AttrId.push_back(v.attrid(i));
		m_Id = v.id();

	}

private:
	//属性Id
	vector<INT32> m_AttrId;
public:
	int SizeAttrId()
	{
		return m_AttrId.size();
	}
	const vector<INT32>& GetAttrId() const
	{
		return m_AttrId;
	}
	INT32 GetAttrId(int Index) const
	{
		if(Index<0 || Index>=(int)m_AttrId.size())
		{
			assert(false);
			return INT32();
		}
		return m_AttrId[Index];
	}
	void SetAttrId( const vector<INT32>& v )
	{
		m_AttrId=v;
	}
	void ClearAttrId( )
	{
		m_AttrId.clear();
	}
	void SetAttrId( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_AttrId.size())
		{
			assert(false);
			return;
		}
		m_AttrId[Index] = v;
	}
	void AddAttrId( INT32 v = -1 )
	{
		m_AttrId.push_back(v);
	}
private:
	//词条Id
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}

};
//排行榜职业数据封装类
class TopJobMessWraper : public DataWraperInterface 
{
public:
	//构造函数
	TopJobMessWraper()
	{
		
		m_JobID = -1;

	}
	//赋值构造函数
	TopJobMessWraper(const TopJobMess& v){ Init(v); }
	//等号重载函数
	void operator = (const TopJobMess& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TopJobMess ToPB() const
	{
		TopJobMess v;
		v.set_jobid( m_JobID );
		v.mutable_top()->Reserve(m_Top.size());
		for (int i=0; i<(int)m_Top.size(); i++)
		{
			*v.add_top() = m_Top[i].ToPB();
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
		TopJobMess pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>JobID(职业-1所有) [sint32]</li>\r\n";
		htmlBuff += "<li>Top(排行榜数据) [TopPeoValue] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>JobID：%di</li>\r\n",m_JobID);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Top：</li>\r\n";
		if( m_Top.size()>0) htmlBuff += m_Top[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_Top.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_Top[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TopJobMess& v)
	{
		m_JobID = v.jobid();
		m_Top.clear();
		m_Top.reserve(v.top_size());
		for( int i=0; i<v.top_size(); i++)
			m_Top.push_back(v.top(i));

	}

private:
	//职业-1所有
	INT32 m_JobID;
public:
	void SetJobID( INT32 v)
	{
		m_JobID=v;
	}
	INT32 GetJobID()
	{
		return m_JobID;
	}
	INT32 GetJobID() const
	{
		return m_JobID;
	}
private:
	//排行榜数据
	vector<TopPeoValueWraper> m_Top;
public:
	int SizeTop()
	{
		return m_Top.size();
	}
	const vector<TopPeoValueWraper>& GetTop() const
	{
		return m_Top;
	}
	TopPeoValueWraper GetTop(int Index) const
	{
		if(Index<0 || Index>=(int)m_Top.size())
		{
			assert(false);
			return TopPeoValueWraper();
		}
		return m_Top[Index];
	}
	void SetTop( const vector<TopPeoValueWraper>& v )
	{
		m_Top=v;
	}
	void ClearTop( )
	{
		m_Top.clear();
	}
	void SetTop( int Index, const TopPeoValueWraper& v )
	{
		if(Index<0 || Index>=(int)m_Top.size())
		{
			assert(false);
			return;
		}
		m_Top[Index] = v;
	}
	void AddTop( const TopPeoValueWraper& v )
	{
		m_Top.push_back(v);
	}

};
//帮会副本对象封装类
class GuildDungeonObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildDungeonObjWraper()
	{
		
		m_DungeonId = -1;
		m_Key = "";
		m_Post = -1;
		m_Host = "";

	}
	//赋值构造函数
	GuildDungeonObjWraper(const GuildDungeonObj& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildDungeonObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildDungeonObj ToPB() const
	{
		GuildDungeonObj v;
		v.set_dungeonid( m_DungeonId );
		v.set_key( m_Key );
		v.set_post( m_Post );
		v.set_host( m_Host );

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
		GuildDungeonObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DungeonId(副本Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Key(Key) [string]</li>\r\n";
		htmlBuff += "<li>Post(Post) [sint32]</li>\r\n";
		htmlBuff += "<li>Host(Host) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>DungeonId：%di</li>\r\n",m_DungeonId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Key：\""+m_Key+"\"</li>\r\n";
		tmpLine.Fmt("<li>Post：%di</li>\r\n",m_Post);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Host：\""+m_Host+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildDungeonObj& v)
	{
		m_DungeonId = v.dungeonid();
		m_Key = v.key();
		m_Post = v.post();
		m_Host = v.host();

	}

private:
	//副本Id
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
	//Key
	string m_Key;
public:
	void SetKey( const string& v)
	{
		m_Key=v;
	}
	string GetKey()
	{
		return m_Key;
	}
	string GetKey() const
	{
		return m_Key;
	}
private:
	//Post
	INT32 m_Post;
public:
	void SetPost( INT32 v)
	{
		m_Post=v;
	}
	INT32 GetPost()
	{
		return m_Post;
	}
	INT32 GetPost() const
	{
		return m_Post;
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

};
//帮会成员对象封装类
class GuildMemberObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildMemberObjWraper()
	{
		
		m_UserId = -1;
		m_UserName = "";
		m_Level = -1;
		m_Prof = -1;
		m_Duty = -1;
		m_CurContribution = -1;
		m_MaxContribution = -1;
		m_LeagueMatchesCount = -1;
		m_OfflineTime = -1;
		m_JoinTime = -1;
		m_IsOnline = true;
		m_IsGuildDungeon = false;

	}
	//赋值构造函数
	GuildMemberObjWraper(const GuildMemberObj& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildMemberObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildMemberObj ToPB() const
	{
		GuildMemberObj v;
		v.set_userid( m_UserId );
		v.set_username( m_UserName );
		v.set_level( m_Level );
		v.set_prof( m_Prof );
		v.set_duty( m_Duty );
		v.set_curcontribution( m_CurContribution );
		v.set_maxcontribution( m_MaxContribution );
		v.set_leaguematchescount( m_LeagueMatchesCount );
		v.set_offlinetime( m_OfflineTime );
		v.set_jointime( m_JoinTime );
		v.mutable_dropitemarray()->Reserve(m_DropItemArray.size());
		for (int i=0; i<(int)m_DropItemArray.size(); i++)
		{
			v.add_dropitemarray(m_DropItemArray[i]);
		}
		v.set_isonline( m_IsOnline );
		v.set_isguilddungeon( m_IsGuildDungeon );

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
		GuildMemberObj pb;
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
		htmlBuff += "<li>Duty(职位) [sint32]</li>\r\n";
		htmlBuff += "<li>CurContribution(当前帮贡) [sint32]</li>\r\n";
		htmlBuff += "<li>MaxContribution(最大帮贡) [sint32]</li>\r\n";
		htmlBuff += "<li>LeagueMatchesCount(联赛次数) [sint32]</li>\r\n";
		htmlBuff += "<li>OfflineTime(离线时间) [sint32]</li>\r\n";
		htmlBuff += "<li>JoinTime(加入时间) [sint32]</li>\r\n";
		htmlBuff += "<li>DropItemArray(掉落包数组) [sint32] Array</li>\r\n";
		htmlBuff += "<li>IsOnline(是否在线) [bool]</li>\r\n";
		htmlBuff += "<li>IsGuildDungeon(是否正在参加帮会副本) [bool]</li>\r\n";

		
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
		tmpLine.Fmt("<li>Duty：%di</li>\r\n",m_Duty);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CurContribution：%di</li>\r\n",m_CurContribution);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MaxContribution：%di</li>\r\n",m_MaxContribution);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>LeagueMatchesCount：%di</li>\r\n",m_LeagueMatchesCount);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>OfflineTime：%di</li>\r\n",m_OfflineTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>JoinTime：%di</li>\r\n",m_JoinTime);
		htmlBuff += tmpLine;
		htmlBuff += "<li>DropItemArray：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_DropItemArray.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_DropItemArray[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_DropItemArray.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>IsOnline：%di</li>\r\n",m_IsOnline);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsGuildDungeon：%di</li>\r\n",m_IsGuildDungeon);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildMemberObj& v)
	{
		m_UserId = v.userid();
		m_UserName = v.username();
		m_Level = v.level();
		m_Prof = v.prof();
		m_Duty = v.duty();
		m_CurContribution = v.curcontribution();
		m_MaxContribution = v.maxcontribution();
		m_LeagueMatchesCount = v.leaguematchescount();
		m_OfflineTime = v.offlinetime();
		m_JoinTime = v.jointime();
		m_DropItemArray.clear();
		m_DropItemArray.reserve(v.dropitemarray_size());
		for( int i=0; i<v.dropitemarray_size(); i++)
			m_DropItemArray.push_back(v.dropitemarray(i));
		m_IsOnline = v.isonline();
		m_IsGuildDungeon = v.isguilddungeon();

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
private:
	//当前帮贡
	INT32 m_CurContribution;
public:
	void SetCurContribution( INT32 v)
	{
		m_CurContribution=v;
	}
	INT32 GetCurContribution()
	{
		return m_CurContribution;
	}
	INT32 GetCurContribution() const
	{
		return m_CurContribution;
	}
private:
	//最大帮贡
	INT32 m_MaxContribution;
public:
	void SetMaxContribution( INT32 v)
	{
		m_MaxContribution=v;
	}
	INT32 GetMaxContribution()
	{
		return m_MaxContribution;
	}
	INT32 GetMaxContribution() const
	{
		return m_MaxContribution;
	}
private:
	//联赛次数
	INT32 m_LeagueMatchesCount;
public:
	void SetLeagueMatchesCount( INT32 v)
	{
		m_LeagueMatchesCount=v;
	}
	INT32 GetLeagueMatchesCount()
	{
		return m_LeagueMatchesCount;
	}
	INT32 GetLeagueMatchesCount() const
	{
		return m_LeagueMatchesCount;
	}
private:
	//离线时间
	INT32 m_OfflineTime;
public:
	void SetOfflineTime( INT32 v)
	{
		m_OfflineTime=v;
	}
	INT32 GetOfflineTime()
	{
		return m_OfflineTime;
	}
	INT32 GetOfflineTime() const
	{
		return m_OfflineTime;
	}
private:
	//加入时间
	INT32 m_JoinTime;
public:
	void SetJoinTime( INT32 v)
	{
		m_JoinTime=v;
	}
	INT32 GetJoinTime()
	{
		return m_JoinTime;
	}
	INT32 GetJoinTime() const
	{
		return m_JoinTime;
	}
private:
	//掉落包数组
	vector<INT32> m_DropItemArray;
public:
	int SizeDropItemArray()
	{
		return m_DropItemArray.size();
	}
	const vector<INT32>& GetDropItemArray() const
	{
		return m_DropItemArray;
	}
	INT32 GetDropItemArray(int Index) const
	{
		if(Index<0 || Index>=(int)m_DropItemArray.size())
		{
			assert(false);
			return INT32();
		}
		return m_DropItemArray[Index];
	}
	void SetDropItemArray( const vector<INT32>& v )
	{
		m_DropItemArray=v;
	}
	void ClearDropItemArray( )
	{
		m_DropItemArray.clear();
	}
	void SetDropItemArray( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_DropItemArray.size())
		{
			assert(false);
			return;
		}
		m_DropItemArray[Index] = v;
	}
	void AddDropItemArray( INT32 v = -1 )
	{
		m_DropItemArray.push_back(v);
	}
private:
	//是否在线
	bool m_IsOnline;
public:
	void SetIsOnline( bool v)
	{
		m_IsOnline=v;
	}
	bool GetIsOnline()
	{
		return m_IsOnline;
	}
	bool GetIsOnline() const
	{
		return m_IsOnline;
	}
private:
	//是否正在参加帮会副本
	bool m_IsGuildDungeon;
public:
	void SetIsGuildDungeon( bool v)
	{
		m_IsGuildDungeon=v;
	}
	bool GetIsGuildDungeon()
	{
		return m_IsGuildDungeon;
	}
	bool GetIsGuildDungeon() const
	{
		return m_IsGuildDungeon;
	}

};
//申请列表数据封装类
class ApplyListRoleInfoObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	ApplyListRoleInfoObjWraper()
	{
		
		m_UserId = -1;
		m_UserName = "";
		m_Level = 1;
		m_Prof = 0;
		m_TalentLevel = 0;
		m_Xiulian = 0;
		m_Military = 0;

	}
	//赋值构造函数
	ApplyListRoleInfoObjWraper(const ApplyListRoleInfoObj& v){ Init(v); }
	//等号重载函数
	void operator = (const ApplyListRoleInfoObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ApplyListRoleInfoObj ToPB() const
	{
		ApplyListRoleInfoObj v;
		v.set_userid( m_UserId );
		v.set_username( m_UserName );
		v.set_level( m_Level );
		v.set_prof( m_Prof );
		v.set_talentlevel( m_TalentLevel );
		v.set_xiulian( m_Xiulian );
		v.set_military( m_Military );

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
		ApplyListRoleInfoObj pb;
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
		htmlBuff += "<li>TalentLevel(修为等级) [sint32]</li>\r\n";
		htmlBuff += "<li>Xiulian(修炼) [sint32]</li>\r\n";
		htmlBuff += "<li>Military(战力) [sint32]</li>\r\n";

		
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
		tmpLine.Fmt("<li>TalentLevel：%di</li>\r\n",m_TalentLevel);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Xiulian：%di</li>\r\n",m_Xiulian);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Military：%di</li>\r\n",m_Military);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ApplyListRoleInfoObj& v)
	{
		m_UserId = v.userid();
		m_UserName = v.username();
		m_Level = v.level();
		m_Prof = v.prof();
		m_TalentLevel = v.talentlevel();
		m_Xiulian = v.xiulian();
		m_Military = v.military();

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
	//修为等级
	INT32 m_TalentLevel;
public:
	void SetTalentLevel( INT32 v)
	{
		m_TalentLevel=v;
	}
	INT32 GetTalentLevel()
	{
		return m_TalentLevel;
	}
	INT32 GetTalentLevel() const
	{
		return m_TalentLevel;
	}
private:
	//修炼
	INT32 m_Xiulian;
public:
	void SetXiulian( INT32 v)
	{
		m_Xiulian=v;
	}
	INT32 GetXiulian()
	{
		return m_Xiulian;
	}
	INT32 GetXiulian() const
	{
		return m_Xiulian;
	}
private:
	//战力
	INT32 m_Military;
public:
	void SetMilitary( INT32 v)
	{
		m_Military=v;
	}
	INT32 GetMilitary()
	{
		return m_Military;
	}
	INT32 GetMilitary() const
	{
		return m_Military;
	}

};
//组队人员对象封装类
class TeamUserObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamUserObjWraper()
	{
		
		m_UserId = -1;
		m_UserName = "";
		m_Level = -1;
		m_IsCaptain = false;
		m_Prof = -1;
		m_HP = -1;
		m_MaxHP = -1;
		m_IsFollowing = false;

	}
	//赋值构造函数
	TeamUserObjWraper(const TeamUserObj& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamUserObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamUserObj ToPB() const
	{
		TeamUserObj v;
		v.set_userid( m_UserId );
		v.set_username( m_UserName );
		v.set_level( m_Level );
		v.set_iscaptain( m_IsCaptain );
		v.set_prof( m_Prof );
		v.set_hp( m_HP );
		v.set_maxhp( m_MaxHP );
		v.set_isfollowing( m_IsFollowing );

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
		TeamUserObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>UserName(用户名字) [string]</li>\r\n";
		htmlBuff += "<li>Level(玩家等级) [sint32]</li>\r\n";
		htmlBuff += "<li>IsCaptain(是否为队长) [bool]</li>\r\n";
		htmlBuff += "<li>Prof(职业) [sint32]</li>\r\n";
		htmlBuff += "<li>HP(HP) [sint32]</li>\r\n";
		htmlBuff += "<li>MaxHP(MaxHP) [sint32]</li>\r\n";
		htmlBuff += "<li>IsFollowing(是否在跟随状态中) [bool]</li>\r\n";

		
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
		tmpLine.Fmt("<li>IsCaptain：%di</li>\r\n",m_IsCaptain);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Prof：%di</li>\r\n",m_Prof);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>HP：%di</li>\r\n",m_HP);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MaxHP：%di</li>\r\n",m_MaxHP);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsFollowing：%di</li>\r\n",m_IsFollowing);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamUserObj& v)
	{
		m_UserId = v.userid();
		m_UserName = v.username();
		m_Level = v.level();
		m_IsCaptain = v.iscaptain();
		m_Prof = v.prof();
		m_HP = v.hp();
		m_MaxHP = v.maxhp();
		m_IsFollowing = v.isfollowing();

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
	//用户名字
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
	//玩家等级
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
	//是否为队长
	bool m_IsCaptain;
public:
	void SetIsCaptain( bool v)
	{
		m_IsCaptain=v;
	}
	bool GetIsCaptain()
	{
		return m_IsCaptain;
	}
	bool GetIsCaptain() const
	{
		return m_IsCaptain;
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
	//HP
	INT32 m_HP;
public:
	void SetHP( INT32 v)
	{
		m_HP=v;
	}
	INT32 GetHP()
	{
		return m_HP;
	}
	INT32 GetHP() const
	{
		return m_HP;
	}
private:
	//MaxHP
	INT32 m_MaxHP;
public:
	void SetMaxHP( INT32 v)
	{
		m_MaxHP=v;
	}
	INT32 GetMaxHP()
	{
		return m_MaxHP;
	}
	INT32 GetMaxHP() const
	{
		return m_MaxHP;
	}
private:
	//是否在跟随状态中
	bool m_IsFollowing;
public:
	void SetIsFollowing( bool v)
	{
		m_IsFollowing=v;
	}
	bool GetIsFollowing()
	{
		return m_IsFollowing;
	}
	bool GetIsFollowing() const
	{
		return m_IsFollowing;
	}

};
//帮会事件对象封装类
class GuildEventObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildEventObjWraper()
	{
		
		m_EventId = -1;
		m_Param1 = "";
		m_Param2 = "";

	}
	//赋值构造函数
	GuildEventObjWraper(const GuildEventObj& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildEventObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildEventObj ToPB() const
	{
		GuildEventObj v;
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
		GuildEventObj pb;
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
	void Init(const GuildEventObj& v)
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
//背包回收格子封装类
class BagRecycleGridObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagRecycleGridObjWraper()
	{
		
		m_ItemId = -1;
		m_TemplateId = -1;
		m_Num = -1;
		m_ItemType = -1;
		m_Pos = -1;

	}
	//赋值构造函数
	BagRecycleGridObjWraper(const BagRecycleGridObj& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRecycleGridObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRecycleGridObj ToPB() const
	{
		BagRecycleGridObj v;
		v.set_itemid( m_ItemId );
		v.set_templateid( m_TemplateId );
		v.set_num( m_Num );
		v.set_itemtype( m_ItemType );
		v.set_pos( m_Pos );

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
		BagRecycleGridObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ItemId(道具id) [sint64]</li>\r\n";
		htmlBuff += "<li>TemplateId(模板id) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(数量) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemType(物品类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ItemId：%lldL</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemType：%di</li>\r\n",m_ItemType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagRecycleGridObj& v)
	{
		m_ItemId = v.itemid();
		m_TemplateId = v.templateid();
		m_Num = v.num();
		m_ItemType = v.itemtype();
		m_Pos = v.pos();

	}

private:
	//道具id
	INT64 m_ItemId;
public:
	void SetItemId( INT64 v)
	{
		m_ItemId=v;
	}
	INT64 GetItemId()
	{
		return m_ItemId;
	}
	INT64 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//模板id
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
private:
	//数量
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}
private:
	//物品类型
	INT32 m_ItemType;
public:
	void SetItemType( INT32 v)
	{
		m_ItemType=v;
	}
	INT32 GetItemType()
	{
		return m_ItemType;
	}
	INT32 GetItemType() const
	{
		return m_ItemType;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}

};
//时间的排行榜封装类
class TimeTopWraper : public DataWraperInterface 
{
public:
	//构造函数
	TimeTopWraper()
	{
		
		m_ID = -1;
		m_Ranking = -1;

	}
	//赋值构造函数
	TimeTopWraper(const TimeTop& v){ Init(v); }
	//等号重载函数
	void operator = (const TimeTop& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TimeTop ToPB() const
	{
		TimeTop v;
		v.set_id( m_ID );
		v.set_ranking( m_Ranking );

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
		TimeTop pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ID(对照OneVSOneTime_排名时间.xlsl的id) [sint64]</li>\r\n";
		htmlBuff += "<li>Ranking(排行名次) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ID：%lldL</li>\r\n",m_ID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Ranking：%di</li>\r\n",m_Ranking);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TimeTop& v)
	{
		m_ID = v.id();
		m_Ranking = v.ranking();

	}

private:
	//对照OneVSOneTime_排名时间.xlsl的id
	INT64 m_ID;
public:
	void SetID( INT64 v)
	{
		m_ID=v;
	}
	INT64 GetID()
	{
		return m_ID;
	}
	INT64 GetID() const
	{
		return m_ID;
	}
private:
	//排行名次
	INT32 m_Ranking;
public:
	void SetRanking( INT32 v)
	{
		m_Ranking=v;
	}
	INT32 GetRanking()
	{
		return m_Ranking;
	}
	INT32 GetRanking() const
	{
		return m_Ranking;
	}

};
//攻守方消息封装类
class ActMessageWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActMessageWraper()
	{
		
		m_ActUserID = -1;
		m_DepUserID = -1;
		m_ActIsCopy = -1;
		m_ActPlanName = "";
		m_DepPlanName = "";
		m_Time = "";
		m_ActRanking = -1;
		m_DepRanking = -1;
		m_WinUserID = -1;
		m_DepIsCopy = -1;
		m_ActJobID = -1;
		m_DepJobID = -1;
		m_ActChangeSource = -1;
		m_DepChangeSource = -1;
		m_ActChangeOver = -1;
		m_DepChangeOver = -1;

	}
	//赋值构造函数
	ActMessageWraper(const ActMessage& v){ Init(v); }
	//等号重载函数
	void operator = (const ActMessage& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActMessage ToPB() const
	{
		ActMessage v;
		v.set_actuserid( m_ActUserID );
		v.set_depuserid( m_DepUserID );
		v.set_actiscopy( m_ActIsCopy );
		v.set_actplanname( m_ActPlanName );
		v.set_depplanname( m_DepPlanName );
		v.set_time( m_Time );
		v.set_actranking( m_ActRanking );
		v.set_depranking( m_DepRanking );
		v.set_winuserid( m_WinUserID );
		v.set_depiscopy( m_DepIsCopy );
		v.set_actjobid( m_ActJobID );
		v.set_depjobid( m_DepJobID );
		v.set_actchangesource( m_ActChangeSource );
		v.set_depchangesource( m_DepChangeSource );
		v.set_actchangeover( m_ActChangeOver );
		v.set_depchangeover( m_DepChangeOver );

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
		ActMessage pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ActUserID(攻击方Userid) [sint64]</li>\r\n";
		htmlBuff += "<li>DepUserID(防守方Userid) [sint64]</li>\r\n";
		htmlBuff += "<li>ActIsCopy(是不是复制人1是) [sint32]</li>\r\n";
		htmlBuff += "<li>ActPlanName(攻击方名字) [string]</li>\r\n";
		htmlBuff += "<li>DepPlanName(防守方名字) [string]</li>\r\n";
		htmlBuff += "<li>Time(时间格林威治) [string]</li>\r\n";
		htmlBuff += "<li>ActRanking(挑战方当前名次) [sint32]</li>\r\n";
		htmlBuff += "<li>DepRanking(防守方的排名) [sint32]</li>\r\n";
		htmlBuff += "<li>WinUserID(胜利者USerID) [sint64]</li>\r\n";
		htmlBuff += "<li>DepIsCopy(是不是复制人1是) [sint32]</li>\r\n";
		htmlBuff += "<li>ActJobID(攻击方职业id) [sint32]</li>\r\n";
		htmlBuff += "<li>DepJobID(防守方职业id) [sint32]</li>\r\n";
		htmlBuff += "<li>ActChangeSource(攻击方原来的排名变化) [sint32]</li>\r\n";
		htmlBuff += "<li>DepChangeSource(防守方之前的排名变化) [sint32]</li>\r\n";
		htmlBuff += "<li>ActChangeOver(攻击方变化后的排名变化) [sint32]</li>\r\n";
		htmlBuff += "<li>DepChangeOver(防守方变换之后的排名变化) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ActUserID：%lldL</li>\r\n",m_ActUserID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DepUserID：%lldL</li>\r\n",m_DepUserID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ActIsCopy：%di</li>\r\n",m_ActIsCopy);
		htmlBuff += tmpLine;
		htmlBuff += "<li>ActPlanName：\""+m_ActPlanName+"\"</li>\r\n";
		htmlBuff += "<li>DepPlanName：\""+m_DepPlanName+"\"</li>\r\n";
		htmlBuff += "<li>Time：\""+m_Time+"\"</li>\r\n";
		tmpLine.Fmt("<li>ActRanking：%di</li>\r\n",m_ActRanking);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DepRanking：%di</li>\r\n",m_DepRanking);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>WinUserID：%lldL</li>\r\n",m_WinUserID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DepIsCopy：%di</li>\r\n",m_DepIsCopy);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ActJobID：%di</li>\r\n",m_ActJobID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DepJobID：%di</li>\r\n",m_DepJobID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ActChangeSource：%di</li>\r\n",m_ActChangeSource);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DepChangeSource：%di</li>\r\n",m_DepChangeSource);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ActChangeOver：%di</li>\r\n",m_ActChangeOver);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DepChangeOver：%di</li>\r\n",m_DepChangeOver);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActMessage& v)
	{
		m_ActUserID = v.actuserid();
		m_DepUserID = v.depuserid();
		m_ActIsCopy = v.actiscopy();
		m_ActPlanName = v.actplanname();
		m_DepPlanName = v.depplanname();
		m_Time = v.time();
		m_ActRanking = v.actranking();
		m_DepRanking = v.depranking();
		m_WinUserID = v.winuserid();
		m_DepIsCopy = v.depiscopy();
		m_ActJobID = v.actjobid();
		m_DepJobID = v.depjobid();
		m_ActChangeSource = v.actchangesource();
		m_DepChangeSource = v.depchangesource();
		m_ActChangeOver = v.actchangeover();
		m_DepChangeOver = v.depchangeover();

	}

private:
	//攻击方Userid
	INT64 m_ActUserID;
public:
	void SetActUserID( INT64 v)
	{
		m_ActUserID=v;
	}
	INT64 GetActUserID()
	{
		return m_ActUserID;
	}
	INT64 GetActUserID() const
	{
		return m_ActUserID;
	}
private:
	//防守方Userid
	INT64 m_DepUserID;
public:
	void SetDepUserID( INT64 v)
	{
		m_DepUserID=v;
	}
	INT64 GetDepUserID()
	{
		return m_DepUserID;
	}
	INT64 GetDepUserID() const
	{
		return m_DepUserID;
	}
private:
	//是不是复制人1是
	INT32 m_ActIsCopy;
public:
	void SetActIsCopy( INT32 v)
	{
		m_ActIsCopy=v;
	}
	INT32 GetActIsCopy()
	{
		return m_ActIsCopy;
	}
	INT32 GetActIsCopy() const
	{
		return m_ActIsCopy;
	}
private:
	//攻击方名字
	string m_ActPlanName;
public:
	void SetActPlanName( const string& v)
	{
		m_ActPlanName=v;
	}
	string GetActPlanName()
	{
		return m_ActPlanName;
	}
	string GetActPlanName() const
	{
		return m_ActPlanName;
	}
private:
	//防守方名字
	string m_DepPlanName;
public:
	void SetDepPlanName( const string& v)
	{
		m_DepPlanName=v;
	}
	string GetDepPlanName()
	{
		return m_DepPlanName;
	}
	string GetDepPlanName() const
	{
		return m_DepPlanName;
	}
private:
	//时间格林威治
	string m_Time;
public:
	void SetTime( const string& v)
	{
		m_Time=v;
	}
	string GetTime()
	{
		return m_Time;
	}
	string GetTime() const
	{
		return m_Time;
	}
private:
	//挑战方当前名次
	INT32 m_ActRanking;
public:
	void SetActRanking( INT32 v)
	{
		m_ActRanking=v;
	}
	INT32 GetActRanking()
	{
		return m_ActRanking;
	}
	INT32 GetActRanking() const
	{
		return m_ActRanking;
	}
private:
	//防守方的排名
	INT32 m_DepRanking;
public:
	void SetDepRanking( INT32 v)
	{
		m_DepRanking=v;
	}
	INT32 GetDepRanking()
	{
		return m_DepRanking;
	}
	INT32 GetDepRanking() const
	{
		return m_DepRanking;
	}
private:
	//胜利者USerID
	INT64 m_WinUserID;
public:
	void SetWinUserID( INT64 v)
	{
		m_WinUserID=v;
	}
	INT64 GetWinUserID()
	{
		return m_WinUserID;
	}
	INT64 GetWinUserID() const
	{
		return m_WinUserID;
	}
private:
	//是不是复制人1是
	INT32 m_DepIsCopy;
public:
	void SetDepIsCopy( INT32 v)
	{
		m_DepIsCopy=v;
	}
	INT32 GetDepIsCopy()
	{
		return m_DepIsCopy;
	}
	INT32 GetDepIsCopy() const
	{
		return m_DepIsCopy;
	}
private:
	//攻击方职业id
	INT32 m_ActJobID;
public:
	void SetActJobID( INT32 v)
	{
		m_ActJobID=v;
	}
	INT32 GetActJobID()
	{
		return m_ActJobID;
	}
	INT32 GetActJobID() const
	{
		return m_ActJobID;
	}
private:
	//防守方职业id
	INT32 m_DepJobID;
public:
	void SetDepJobID( INT32 v)
	{
		m_DepJobID=v;
	}
	INT32 GetDepJobID()
	{
		return m_DepJobID;
	}
	INT32 GetDepJobID() const
	{
		return m_DepJobID;
	}
private:
	//攻击方原来的排名变化
	INT32 m_ActChangeSource;
public:
	void SetActChangeSource( INT32 v)
	{
		m_ActChangeSource=v;
	}
	INT32 GetActChangeSource()
	{
		return m_ActChangeSource;
	}
	INT32 GetActChangeSource() const
	{
		return m_ActChangeSource;
	}
private:
	//防守方之前的排名变化
	INT32 m_DepChangeSource;
public:
	void SetDepChangeSource( INT32 v)
	{
		m_DepChangeSource=v;
	}
	INT32 GetDepChangeSource()
	{
		return m_DepChangeSource;
	}
	INT32 GetDepChangeSource() const
	{
		return m_DepChangeSource;
	}
private:
	//攻击方变化后的排名变化
	INT32 m_ActChangeOver;
public:
	void SetActChangeOver( INT32 v)
	{
		m_ActChangeOver=v;
	}
	INT32 GetActChangeOver()
	{
		return m_ActChangeOver;
	}
	INT32 GetActChangeOver() const
	{
		return m_ActChangeOver;
	}
private:
	//防守方变换之后的排名变化
	INT32 m_DepChangeOver;
public:
	void SetDepChangeOver( INT32 v)
	{
		m_DepChangeOver=v;
	}
	INT32 GetDepChangeOver()
	{
		return m_DepChangeOver;
	}
	INT32 GetDepChangeOver() const
	{
		return m_DepChangeOver;
	}

};
//一对一设定数据保存封装类
class OneSDataWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneSDataWraper()
	{
		
		m_Type = -1;
		m_SkillID = -1;
		m_SkillLv = -1;
		m_Index = -1;

	}
	//赋值构造函数
	OneSDataWraper(const OneSData& v){ Init(v); }
	//等号重载函数
	void operator = (const OneSData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneSData ToPB() const
	{
		OneSData v;
		v.set_type( m_Type );
		v.set_skillid( m_SkillID );
		v.set_skilllv( m_SkillLv );
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
		OneSData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillID(技能id) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillLv(技能等级) [sint32]</li>\r\n";
		htmlBuff += "<li>Index(索引) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillID：%di</li>\r\n",m_SkillID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillLv：%di</li>\r\n",m_SkillLv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Index：%di</li>\r\n",m_Index);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneSData& v)
	{
		m_Type = v.type();
		m_SkillID = v.skillid();
		m_SkillLv = v.skilllv();
		m_Index = v.index();

	}

private:
	//类型
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}
private:
	//技能id
	INT32 m_SkillID;
public:
	void SetSkillID( INT32 v)
	{
		m_SkillID=v;
	}
	INT32 GetSkillID()
	{
		return m_SkillID;
	}
	INT32 GetSkillID() const
	{
		return m_SkillID;
	}
private:
	//技能等级
	INT32 m_SkillLv;
public:
	void SetSkillLv( INT32 v)
	{
		m_SkillLv=v;
	}
	INT32 GetSkillLv()
	{
		return m_SkillLv;
	}
	INT32 GetSkillLv() const
	{
		return m_SkillLv;
	}
private:
	//索引
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
//排行榜数据封装类
class TopMessWraper : public DataWraperInterface 
{
public:
	//构造函数
	TopMessWraper()
	{
		
		m_MyType = -1;

	}
	//赋值构造函数
	TopMessWraper(const TopMess& v){ Init(v); }
	//等号重载函数
	void operator = (const TopMess& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TopMess ToPB() const
	{
		TopMess v;
		v.set_mytype( m_MyType );
		v.mutable_top()->Reserve(m_Top.size());
		for (int i=0; i<(int)m_Top.size(); i++)
		{
			*v.add_top() = m_Top[i].ToPB();
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
		TopMess pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>MyType(大类型1新锐2英武3神武) [sint32]</li>\r\n";
		htmlBuff += "<li>Top(排行榜数据) [TopJobMess] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>MyType：%di</li>\r\n",m_MyType);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Top：</li>\r\n";
		if( m_Top.size()>0) htmlBuff += m_Top[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_Top.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_Top[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TopMess& v)
	{
		m_MyType = v.mytype();
		m_Top.clear();
		m_Top.reserve(v.top_size());
		for( int i=0; i<v.top_size(); i++)
			m_Top.push_back(v.top(i));

	}

private:
	//大类型1新锐2英武3神武
	INT32 m_MyType;
public:
	void SetMyType( INT32 v)
	{
		m_MyType=v;
	}
	INT32 GetMyType()
	{
		return m_MyType;
	}
	INT32 GetMyType() const
	{
		return m_MyType;
	}
private:
	//排行榜数据
	vector<TopJobMessWraper> m_Top;
public:
	int SizeTop()
	{
		return m_Top.size();
	}
	const vector<TopJobMessWraper>& GetTop() const
	{
		return m_Top;
	}
	TopJobMessWraper GetTop(int Index) const
	{
		if(Index<0 || Index>=(int)m_Top.size())
		{
			assert(false);
			return TopJobMessWraper();
		}
		return m_Top[Index];
	}
	void SetTop( const vector<TopJobMessWraper>& v )
	{
		m_Top=v;
	}
	void ClearTop( )
	{
		m_Top.clear();
	}
	void SetTop( int Index, const TopJobMessWraper& v )
	{
		if(Index<0 || Index>=(int)m_Top.size())
		{
			assert(false);
			return;
		}
		m_Top[Index] = v;
	}
	void AddTop( const TopJobMessWraper& v )
	{
		m_Top.push_back(v);
	}

};
//聊天对象封装类
class ChatObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	ChatObjWraper()
	{
		
		m_ChatMsg = ChatMsgObjWraper();
		m_UserInfo = ChatUserInfoObjWraper();

	}
	//赋值构造函数
	ChatObjWraper(const ChatObj& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatObj ToPB() const
	{
		ChatObj v;
		*v.mutable_chatmsg()= m_ChatMsg.ToPB();
		*v.mutable_userinfo()= m_UserInfo.ToPB();

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
		ChatObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ChatMsg(聊天数据) [ChatMsgObj]</li>\r\n";
		htmlBuff += "<li>UserInfo(发言人信息) [ChatUserInfoObj]</li>\r\n";

		
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
		htmlBuff += "<li>UserInfo：</li>\r\n";
		htmlBuff += m_UserInfo.HtmlDescHeader();
		htmlBuff += m_UserInfo.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ChatObj& v)
	{
		m_ChatMsg = v.chatmsg();
		m_UserInfo = v.userinfo();

	}

private:
	//聊天数据
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
private:
	//发言人信息
	ChatUserInfoObjWraper m_UserInfo;
public:
	void SetUserInfo( const ChatUserInfoObjWraper& v)
	{
		m_UserInfo=v;
	}
	ChatUserInfoObjWraper GetUserInfo()
	{
		return m_UserInfo;
	}
	ChatUserInfoObjWraper GetUserInfo() const
	{
		return m_UserInfo;
	}

};
//组队对象封装类
class TeamObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamObjWraper()
	{
		
		m_TeamId = -1;
		m_CaptainUserId = -1;
		m_MemberCount = -1;
		m_TeamTarget = -1;
		m_CaptainProf = -1;
		m_TargetMinLv = -1;
		m_TargetMaxLv = -1;
		m_IsMatching = false;
		m_CaptainLevel = -1;
		m_IsTeamFollow = false;

	}
	//赋值构造函数
	TeamObjWraper(const TeamObj& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamObj ToPB() const
	{
		TeamObj v;
		v.set_teamid( m_TeamId );
		v.set_captainuserid( m_CaptainUserId );
		v.set_membercount( m_MemberCount );
		v.set_teamtarget( m_TeamTarget );
		v.mutable_teammember()->Reserve(m_TeamMember.size());
		for (int i=0; i<(int)m_TeamMember.size(); i++)
		{
			*v.add_teammember() = m_TeamMember[i].ToPB();
		}
		v.set_captainprof( m_CaptainProf );
		v.set_targetminlv( m_TargetMinLv );
		v.set_targetmaxlv( m_TargetMaxLv );
		v.set_ismatching( m_IsMatching );
		v.set_captainlevel( m_CaptainLevel );
		v.set_isteamfollow( m_IsTeamFollow );

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
		TeamObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TeamId(组队Id) [sint32]</li>\r\n";
		htmlBuff += "<li>CaptainUserId(队长用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>MemberCount(队伍人数) [sint32]</li>\r\n";
		htmlBuff += "<li>TeamTarget(队伍目标Id) [sint32]</li>\r\n";
		htmlBuff += "<li>TeamMember(成员) [TeamUserObj] Array</li>\r\n";
		htmlBuff += "<li>CaptainProf(队长职业) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetMinLv(匹配最小等级) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetMaxLv(匹配最大等级) [sint32]</li>\r\n";
		htmlBuff += "<li>IsMatching(是否匹配中) [bool]</li>\r\n";
		htmlBuff += "<li>CaptainLevel(队长等级) [sint32]</li>\r\n";
		htmlBuff += "<li>IsTeamFollow(队长是否开启跟随) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TeamId：%di</li>\r\n",m_TeamId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CaptainUserId：%lldL</li>\r\n",m_CaptainUserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MemberCount：%di</li>\r\n",m_MemberCount);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TeamTarget：%di</li>\r\n",m_TeamTarget);
		htmlBuff += tmpLine;
		htmlBuff += "<li>TeamMember：</li>\r\n";
		if( m_TeamMember.size()>0) htmlBuff += m_TeamMember[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_TeamMember.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_TeamMember[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>CaptainProf：%di</li>\r\n",m_CaptainProf);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetMinLv：%di</li>\r\n",m_TargetMinLv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetMaxLv：%di</li>\r\n",m_TargetMaxLv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsMatching：%di</li>\r\n",m_IsMatching);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CaptainLevel：%di</li>\r\n",m_CaptainLevel);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsTeamFollow：%di</li>\r\n",m_IsTeamFollow);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamObj& v)
	{
		m_TeamId = v.teamid();
		m_CaptainUserId = v.captainuserid();
		m_MemberCount = v.membercount();
		m_TeamTarget = v.teamtarget();
		m_TeamMember.clear();
		m_TeamMember.reserve(v.teammember_size());
		for( int i=0; i<v.teammember_size(); i++)
			m_TeamMember.push_back(v.teammember(i));
		m_CaptainProf = v.captainprof();
		m_TargetMinLv = v.targetminlv();
		m_TargetMaxLv = v.targetmaxlv();
		m_IsMatching = v.ismatching();
		m_CaptainLevel = v.captainlevel();
		m_IsTeamFollow = v.isteamfollow();

	}

private:
	//组队Id
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
	//队长用户Id
	INT64 m_CaptainUserId;
public:
	void SetCaptainUserId( INT64 v)
	{
		m_CaptainUserId=v;
	}
	INT64 GetCaptainUserId()
	{
		return m_CaptainUserId;
	}
	INT64 GetCaptainUserId() const
	{
		return m_CaptainUserId;
	}
private:
	//队伍人数
	INT32 m_MemberCount;
public:
	void SetMemberCount( INT32 v)
	{
		m_MemberCount=v;
	}
	INT32 GetMemberCount()
	{
		return m_MemberCount;
	}
	INT32 GetMemberCount() const
	{
		return m_MemberCount;
	}
private:
	//队伍目标Id
	INT32 m_TeamTarget;
public:
	void SetTeamTarget( INT32 v)
	{
		m_TeamTarget=v;
	}
	INT32 GetTeamTarget()
	{
		return m_TeamTarget;
	}
	INT32 GetTeamTarget() const
	{
		return m_TeamTarget;
	}
private:
	//成员
	vector<TeamUserObjWraper> m_TeamMember;
public:
	int SizeTeamMember()
	{
		return m_TeamMember.size();
	}
	const vector<TeamUserObjWraper>& GetTeamMember() const
	{
		return m_TeamMember;
	}
	TeamUserObjWraper GetTeamMember(int Index) const
	{
		if(Index<0 || Index>=(int)m_TeamMember.size())
		{
			assert(false);
			return TeamUserObjWraper();
		}
		return m_TeamMember[Index];
	}
	void SetTeamMember( const vector<TeamUserObjWraper>& v )
	{
		m_TeamMember=v;
	}
	void ClearTeamMember( )
	{
		m_TeamMember.clear();
	}
	void SetTeamMember( int Index, const TeamUserObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_TeamMember.size())
		{
			assert(false);
			return;
		}
		m_TeamMember[Index] = v;
	}
	void AddTeamMember( const TeamUserObjWraper& v )
	{
		m_TeamMember.push_back(v);
	}
private:
	//队长职业
	INT32 m_CaptainProf;
public:
	void SetCaptainProf( INT32 v)
	{
		m_CaptainProf=v;
	}
	INT32 GetCaptainProf()
	{
		return m_CaptainProf;
	}
	INT32 GetCaptainProf() const
	{
		return m_CaptainProf;
	}
private:
	//匹配最小等级
	INT32 m_TargetMinLv;
public:
	void SetTargetMinLv( INT32 v)
	{
		m_TargetMinLv=v;
	}
	INT32 GetTargetMinLv()
	{
		return m_TargetMinLv;
	}
	INT32 GetTargetMinLv() const
	{
		return m_TargetMinLv;
	}
private:
	//匹配最大等级
	INT32 m_TargetMaxLv;
public:
	void SetTargetMaxLv( INT32 v)
	{
		m_TargetMaxLv=v;
	}
	INT32 GetTargetMaxLv()
	{
		return m_TargetMaxLv;
	}
	INT32 GetTargetMaxLv() const
	{
		return m_TargetMaxLv;
	}
private:
	//是否匹配中
	bool m_IsMatching;
public:
	void SetIsMatching( bool v)
	{
		m_IsMatching=v;
	}
	bool GetIsMatching()
	{
		return m_IsMatching;
	}
	bool GetIsMatching() const
	{
		return m_IsMatching;
	}
private:
	//队长等级
	INT32 m_CaptainLevel;
public:
	void SetCaptainLevel( INT32 v)
	{
		m_CaptainLevel=v;
	}
	INT32 GetCaptainLevel()
	{
		return m_CaptainLevel;
	}
	INT32 GetCaptainLevel() const
	{
		return m_CaptainLevel;
	}
private:
	//队长是否开启跟随
	bool m_IsTeamFollow;
public:
	void SetIsTeamFollow( bool v)
	{
		m_IsTeamFollow=v;
	}
	bool GetIsTeamFollow()
	{
		return m_IsTeamFollow;
	}
	bool GetIsTeamFollow() const
	{
		return m_IsTeamFollow;
	}

};
//聊天网络数据封装类
class ChatNetDataWraper : public DataWraperInterface 
{
public:
	//构造函数
	ChatNetDataWraper()
	{
		
		m_Text = "";
		m_UserInfo = ChatUserInfoObjWraper();
		m_Channel = 0;
		m_ChildChannel = -1;

	}
	//赋值构造函数
	ChatNetDataWraper(const ChatNetData& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatNetData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatNetData ToPB() const
	{
		ChatNetData v;
		v.mutable_hyperlinklist()->Reserve(m_HyperlinkList.size());
		for (int i=0; i<(int)m_HyperlinkList.size(); i++)
		{
			*v.add_hyperlinklist() = m_HyperlinkList[i].ToPB();
		}
		v.set_text( m_Text );
		*v.mutable_userinfo()= m_UserInfo.ToPB();
		v.set_channel( m_Channel );
		v.set_childchannel( m_ChildChannel );

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
		ChatNetData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>HyperlinkList(所有的超链接信息) [ChatHyperLink] Array</li>\r\n";
		htmlBuff += "<li>Text(文本) [string]</li>\r\n";
		htmlBuff += "<li>UserInfo(发言人信息) [ChatUserInfoObj]</li>\r\n";
		htmlBuff += "<li>Channel(频道) [sint32]</li>\r\n";
		htmlBuff += "<li>ChildChannel(子频道) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>HyperlinkList：</li>\r\n";
		if( m_HyperlinkList.size()>0) htmlBuff += m_HyperlinkList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_HyperlinkList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_HyperlinkList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>Text：\""+m_Text+"\"</li>\r\n";
		htmlBuff += "<li>UserInfo：</li>\r\n";
		htmlBuff += m_UserInfo.HtmlDescHeader();
		htmlBuff += m_UserInfo.ToHtml();
		tmpLine.Fmt("<li>Channel：%di</li>\r\n",m_Channel);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ChildChannel：%di</li>\r\n",m_ChildChannel);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ChatNetData& v)
	{
		m_HyperlinkList.clear();
		m_HyperlinkList.reserve(v.hyperlinklist_size());
		for( int i=0; i<v.hyperlinklist_size(); i++)
			m_HyperlinkList.push_back(v.hyperlinklist(i));
		m_Text = v.text();
		m_UserInfo = v.userinfo();
		m_Channel = v.channel();
		m_ChildChannel = v.childchannel();

	}

private:
	//所有的超链接信息
	vector<ChatHyperLinkWraper> m_HyperlinkList;
public:
	int SizeHyperlinkList()
	{
		return m_HyperlinkList.size();
	}
	const vector<ChatHyperLinkWraper>& GetHyperlinkList() const
	{
		return m_HyperlinkList;
	}
	ChatHyperLinkWraper GetHyperlinkList(int Index) const
	{
		if(Index<0 || Index>=(int)m_HyperlinkList.size())
		{
			assert(false);
			return ChatHyperLinkWraper();
		}
		return m_HyperlinkList[Index];
	}
	void SetHyperlinkList( const vector<ChatHyperLinkWraper>& v )
	{
		m_HyperlinkList=v;
	}
	void ClearHyperlinkList( )
	{
		m_HyperlinkList.clear();
	}
	void SetHyperlinkList( int Index, const ChatHyperLinkWraper& v )
	{
		if(Index<0 || Index>=(int)m_HyperlinkList.size())
		{
			assert(false);
			return;
		}
		m_HyperlinkList[Index] = v;
	}
	void AddHyperlinkList( const ChatHyperLinkWraper& v )
	{
		m_HyperlinkList.push_back(v);
	}
private:
	//文本
	string m_Text;
public:
	void SetText( const string& v)
	{
		m_Text=v;
	}
	string GetText()
	{
		return m_Text;
	}
	string GetText() const
	{
		return m_Text;
	}
private:
	//发言人信息
	ChatUserInfoObjWraper m_UserInfo;
public:
	void SetUserInfo( const ChatUserInfoObjWraper& v)
	{
		m_UserInfo=v;
	}
	ChatUserInfoObjWraper GetUserInfo()
	{
		return m_UserInfo;
	}
	ChatUserInfoObjWraper GetUserInfo() const
	{
		return m_UserInfo;
	}
private:
	//频道
	INT32 m_Channel;
public:
	void SetChannel( INT32 v)
	{
		m_Channel=v;
	}
	INT32 GetChannel()
	{
		return m_Channel;
	}
	INT32 GetChannel() const
	{
		return m_Channel;
	}
private:
	//子频道
	INT32 m_ChildChannel;
public:
	void SetChildChannel( INT32 v)
	{
		m_ChildChannel=v;
	}
	INT32 GetChildChannel()
	{
		return m_ChildChannel;
	}
	INT32 GetChildChannel() const
	{
		return m_ChildChannel;
	}

};
//邮件头信息对象封装类
class MailHeadObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailHeadObjWraper()
	{
		
		m_UId = -1;
		m_TiTleString = "";
		m_CreateTime = -1;
		m_Type = -1;
		m_Status = 0;
		m_IsAutoDel = false;
		m_GUId = -1;

	}
	//赋值构造函数
	MailHeadObjWraper(const MailHeadObj& v){ Init(v); }
	//等号重载函数
	void operator = (const MailHeadObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailHeadObj ToPB() const
	{
		MailHeadObj v;
		v.set_uid( m_UId );
		v.set_titlestring( m_TiTleString );
		v.set_createtime( m_CreateTime );
		v.set_type( m_Type );
		v.set_status( m_Status );
		v.set_isautodel( m_IsAutoDel );
		v.set_guid( m_GUId );

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
		MailHeadObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UId(UId) [sint64]</li>\r\n";
		htmlBuff += "<li>TiTleString(标题内容) [string]</li>\r\n";
		htmlBuff += "<li>CreateTime(创建时间) [sint32]</li>\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Status(邮件状态) [sint32]</li>\r\n";
		htmlBuff += "<li>IsAutoDel(需要自动删除) [bool]</li>\r\n";
		htmlBuff += "<li>GUId(GUId) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UId：%lldL</li>\r\n",m_UId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>TiTleString：\""+m_TiTleString+"\"</li>\r\n";
		tmpLine.Fmt("<li>CreateTime：%di</li>\r\n",m_CreateTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Status：%di</li>\r\n",m_Status);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsAutoDel：%di</li>\r\n",m_IsAutoDel);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GUId：%lldL</li>\r\n",m_GUId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MailHeadObj& v)
	{
		m_UId = v.uid();
		m_TiTleString = v.titlestring();
		m_CreateTime = v.createtime();
		m_Type = v.type();
		m_Status = v.status();
		m_IsAutoDel = v.isautodel();
		m_GUId = v.guid();

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
private:
	//标题内容
	string m_TiTleString;
public:
	void SetTiTleString( const string& v)
	{
		m_TiTleString=v;
	}
	string GetTiTleString()
	{
		return m_TiTleString;
	}
	string GetTiTleString() const
	{
		return m_TiTleString;
	}
private:
	//创建时间
	INT32 m_CreateTime;
public:
	void SetCreateTime( INT32 v)
	{
		m_CreateTime=v;
	}
	INT32 GetCreateTime()
	{
		return m_CreateTime;
	}
	INT32 GetCreateTime() const
	{
		return m_CreateTime;
	}
private:
	//类型
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}
private:
	//邮件状态
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}
private:
	//需要自动删除
	bool m_IsAutoDel;
public:
	void SetIsAutoDel( bool v)
	{
		m_IsAutoDel=v;
	}
	bool GetIsAutoDel()
	{
		return m_IsAutoDel;
	}
	bool GetIsAutoDel() const
	{
		return m_IsAutoDel;
	}
private:
	//GUId
	INT64 m_GUId;
public:
	void SetGUId( INT64 v)
	{
		m_GUId=v;
	}
	INT64 GetGUId()
	{
		return m_GUId;
	}
	INT64 GetGUId() const
	{
		return m_GUId;
	}

};
//邮件内容对象封装类
class MailBodyObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailBodyObjWraper()
	{
		
		m_Text = "";
		m_Status = 0;

	}
	//赋值构造函数
	MailBodyObjWraper(const MailBodyObj& v){ Init(v); }
	//等号重载函数
	void operator = (const MailBodyObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailBodyObj ToPB() const
	{
		MailBodyObj v;
		v.set_text( m_Text );
		v.mutable_hyperlinklist()->Reserve(m_HyperlinkList.size());
		for (int i=0; i<(int)m_HyperlinkList.size(); i++)
		{
			*v.add_hyperlinklist() = m_HyperlinkList[i].ToPB();
		}
		v.mutable_itemlist()->Reserve(m_ItemList.size());
		for (int i=0; i<(int)m_ItemList.size(); i++)
		{
			*v.add_itemlist() = m_ItemList[i].ToPB();
		}
		v.set_status( m_Status );

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
		MailBodyObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Text(文本) [string]</li>\r\n";
		htmlBuff += "<li>HyperlinkList(所有的超链接信息) [ChatHyperLink] Array</li>\r\n";
		htmlBuff += "<li>ItemList(物品列表) [KeyValue2IntInt] Array</li>\r\n";
		htmlBuff += "<li>Status(领取状态) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>Text：\""+m_Text+"\"</li>\r\n";
		htmlBuff += "<li>HyperlinkList：</li>\r\n";
		if( m_HyperlinkList.size()>0) htmlBuff += m_HyperlinkList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_HyperlinkList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_HyperlinkList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>ItemList：</li>\r\n";
		if( m_ItemList.size()>0) htmlBuff += m_ItemList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ItemList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ItemList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>Status：%di</li>\r\n",m_Status);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MailBodyObj& v)
	{
		m_Text = v.text();
		m_HyperlinkList.clear();
		m_HyperlinkList.reserve(v.hyperlinklist_size());
		for( int i=0; i<v.hyperlinklist_size(); i++)
			m_HyperlinkList.push_back(v.hyperlinklist(i));
		m_ItemList.clear();
		m_ItemList.reserve(v.itemlist_size());
		for( int i=0; i<v.itemlist_size(); i++)
			m_ItemList.push_back(v.itemlist(i));
		m_Status = v.status();

	}

private:
	//文本
	string m_Text;
public:
	void SetText( const string& v)
	{
		m_Text=v;
	}
	string GetText()
	{
		return m_Text;
	}
	string GetText() const
	{
		return m_Text;
	}
private:
	//所有的超链接信息
	vector<ChatHyperLinkWraper> m_HyperlinkList;
public:
	int SizeHyperlinkList()
	{
		return m_HyperlinkList.size();
	}
	const vector<ChatHyperLinkWraper>& GetHyperlinkList() const
	{
		return m_HyperlinkList;
	}
	ChatHyperLinkWraper GetHyperlinkList(int Index) const
	{
		if(Index<0 || Index>=(int)m_HyperlinkList.size())
		{
			assert(false);
			return ChatHyperLinkWraper();
		}
		return m_HyperlinkList[Index];
	}
	void SetHyperlinkList( const vector<ChatHyperLinkWraper>& v )
	{
		m_HyperlinkList=v;
	}
	void ClearHyperlinkList( )
	{
		m_HyperlinkList.clear();
	}
	void SetHyperlinkList( int Index, const ChatHyperLinkWraper& v )
	{
		if(Index<0 || Index>=(int)m_HyperlinkList.size())
		{
			assert(false);
			return;
		}
		m_HyperlinkList[Index] = v;
	}
	void AddHyperlinkList( const ChatHyperLinkWraper& v )
	{
		m_HyperlinkList.push_back(v);
	}
private:
	//物品列表
	vector<KeyValue2IntIntWraper> m_ItemList;
public:
	int SizeItemList()
	{
		return m_ItemList.size();
	}
	const vector<KeyValue2IntIntWraper>& GetItemList() const
	{
		return m_ItemList;
	}
	KeyValue2IntIntWraper GetItemList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemList.size())
		{
			assert(false);
			return KeyValue2IntIntWraper();
		}
		return m_ItemList[Index];
	}
	void SetItemList( const vector<KeyValue2IntIntWraper>& v )
	{
		m_ItemList=v;
	}
	void ClearItemList( )
	{
		m_ItemList.clear();
	}
	void SetItemList( int Index, const KeyValue2IntIntWraper& v )
	{
		if(Index<0 || Index>=(int)m_ItemList.size())
		{
			assert(false);
			return;
		}
		m_ItemList[Index] = v;
	}
	void AddItemList( const KeyValue2IntIntWraper& v )
	{
		m_ItemList.push_back(v);
	}
private:
	//领取状态
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}

};
//组队申请用户对象封装类
class TeamApplyUserObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamApplyUserObjWraper()
	{
		
		m_UserId = -1;
		m_UserName = "";
		m_Level = -1;
		m_Prof = -1;
		m_TeamId = -1;

	}
	//赋值构造函数
	TeamApplyUserObjWraper(const TeamApplyUserObj& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamApplyUserObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamApplyUserObj ToPB() const
	{
		TeamApplyUserObj v;
		v.set_userid( m_UserId );
		v.set_username( m_UserName );
		v.set_level( m_Level );
		v.set_prof( m_Prof );
		v.set_teamid( m_TeamId );

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
		TeamApplyUserObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(UserId) [sint64]</li>\r\n";
		htmlBuff += "<li>UserName(用户名字) [string]</li>\r\n";
		htmlBuff += "<li>Level(玩家等级) [sint32]</li>\r\n";
		htmlBuff += "<li>Prof(职业) [sint32]</li>\r\n";
		htmlBuff += "<li>TeamId(组队Id) [sint32]</li>\r\n";

		
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
		tmpLine.Fmt("<li>TeamId：%di</li>\r\n",m_TeamId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamApplyUserObj& v)
	{
		m_UserId = v.userid();
		m_UserName = v.username();
		m_Level = v.level();
		m_Prof = v.prof();
		m_TeamId = v.teamid();

	}

private:
	//UserId
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
	//用户名字
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
	//玩家等级
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
	//组队Id
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

};
//英雄战斗信息封装类
class HeroFightInfoWraper : public DataWraperInterface 
{
public:
	//构造函数
	HeroFightInfoWraper()
	{
		
		m_UserId = -1;
		m_ObjId = -1;
		m_Name = "";
		m_DeadTimes = 0;
		m_KilledNum = 0;
		m_TotalDamage = -1;
		m_TotalEndure = -1;
		m_Level = -1;
		m_AssistKilled = -1;
		m_CmapId = -1;

	}
	//赋值构造函数
	HeroFightInfoWraper(const HeroFightInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const HeroFightInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HeroFightInfo ToPB() const
	{
		HeroFightInfo v;
		v.set_userid( m_UserId );
		v.set_objid( m_ObjId );
		v.set_name( m_Name );
		v.set_deadtimes( m_DeadTimes );
		v.set_killednum( m_KilledNum );
		v.set_totaldamage( m_TotalDamage );
		v.set_totalendure( m_TotalEndure );
		v.mutable_intparaarr()->Reserve(m_IntParaArr.size());
		for (int i=0; i<(int)m_IntParaArr.size(); i++)
		{
			v.add_intparaarr(m_IntParaArr[i]);
		}
		v.set_level( m_Level );
		v.set_assistkilled( m_AssistKilled );
		v.set_cmapid( m_CmapId );

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
		HeroFightInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>ObjId(对像ID) [sint32]</li>\r\n";
		htmlBuff += "<li>Name(名字) [string]</li>\r\n";
		htmlBuff += "<li>DeadTimes(死亡次数) [sint32]</li>\r\n";
		htmlBuff += "<li>KilledNum(杀人数) [sint32]</li>\r\n";
		htmlBuff += "<li>TotalDamage(总输出伤害) [sint64]</li>\r\n";
		htmlBuff += "<li>TotalEndure(承受伤害) [sint32]</li>\r\n";
		htmlBuff += "<li>IntParaArr(保留参数) [sint32] Array</li>\r\n";
		htmlBuff += "<li>Level(等级) [sint32]</li>\r\n";
		htmlBuff += "<li>AssistKilled(助攻数) [sint32]</li>\r\n";
		htmlBuff += "<li>CmapId(阵营ID) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Name：\""+m_Name+"\"</li>\r\n";
		tmpLine.Fmt("<li>DeadTimes：%di</li>\r\n",m_DeadTimes);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>KilledNum：%di</li>\r\n",m_KilledNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TotalDamage：%lldL</li>\r\n",m_TotalDamage);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TotalEndure：%di</li>\r\n",m_TotalEndure);
		htmlBuff += tmpLine;
		htmlBuff += "<li>IntParaArr：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_IntParaArr.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_IntParaArr[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_IntParaArr.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AssistKilled：%di</li>\r\n",m_AssistKilled);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CmapId：%di</li>\r\n",m_CmapId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const HeroFightInfo& v)
	{
		m_UserId = v.userid();
		m_ObjId = v.objid();
		m_Name = v.name();
		m_DeadTimes = v.deadtimes();
		m_KilledNum = v.killednum();
		m_TotalDamage = v.totaldamage();
		m_TotalEndure = v.totalendure();
		m_IntParaArr.clear();
		m_IntParaArr.reserve(v.intparaarr_size());
		for( int i=0; i<v.intparaarr_size(); i++)
			m_IntParaArr.push_back(v.intparaarr(i));
		m_Level = v.level();
		m_AssistKilled = v.assistkilled();
		m_CmapId = v.cmapid();

	}

private:
	//用户ID
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
	//对像ID
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//名字
	string m_Name;
public:
	void SetName( const string& v)
	{
		m_Name=v;
	}
	string GetName()
	{
		return m_Name;
	}
	string GetName() const
	{
		return m_Name;
	}
private:
	//死亡次数
	INT32 m_DeadTimes;
public:
	void SetDeadTimes( INT32 v)
	{
		m_DeadTimes=v;
	}
	INT32 GetDeadTimes()
	{
		return m_DeadTimes;
	}
	INT32 GetDeadTimes() const
	{
		return m_DeadTimes;
	}
private:
	//杀人数
	INT32 m_KilledNum;
public:
	void SetKilledNum( INT32 v)
	{
		m_KilledNum=v;
	}
	INT32 GetKilledNum()
	{
		return m_KilledNum;
	}
	INT32 GetKilledNum() const
	{
		return m_KilledNum;
	}
private:
	//总输出伤害
	INT64 m_TotalDamage;
public:
	void SetTotalDamage( INT64 v)
	{
		m_TotalDamage=v;
	}
	INT64 GetTotalDamage()
	{
		return m_TotalDamage;
	}
	INT64 GetTotalDamage() const
	{
		return m_TotalDamage;
	}
private:
	//承受伤害
	INT32 m_TotalEndure;
public:
	void SetTotalEndure( INT32 v)
	{
		m_TotalEndure=v;
	}
	INT32 GetTotalEndure()
	{
		return m_TotalEndure;
	}
	INT32 GetTotalEndure() const
	{
		return m_TotalEndure;
	}
private:
	//保留参数
	vector<INT32> m_IntParaArr;
public:
	int SizeIntParaArr()
	{
		return m_IntParaArr.size();
	}
	const vector<INT32>& GetIntParaArr() const
	{
		return m_IntParaArr;
	}
	INT32 GetIntParaArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_IntParaArr.size())
		{
			assert(false);
			return INT32();
		}
		return m_IntParaArr[Index];
	}
	void SetIntParaArr( const vector<INT32>& v )
	{
		m_IntParaArr=v;
	}
	void ClearIntParaArr( )
	{
		m_IntParaArr.clear();
	}
	void SetIntParaArr( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_IntParaArr.size())
		{
			assert(false);
			return;
		}
		m_IntParaArr[Index] = v;
	}
	void AddIntParaArr( INT32 v = -1 )
	{
		m_IntParaArr.push_back(v);
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
	//助攻数
	INT32 m_AssistKilled;
public:
	void SetAssistKilled( INT32 v)
	{
		m_AssistKilled=v;
	}
	INT32 GetAssistKilled()
	{
		return m_AssistKilled;
	}
	INT32 GetAssistKilled() const
	{
		return m_AssistKilled;
	}
private:
	//阵营ID
	INT32 m_CmapId;
public:
	void SetCmapId( INT32 v)
	{
		m_CmapId=v;
	}
	INT32 GetCmapId()
	{
		return m_CmapId;
	}
	INT32 GetCmapId() const
	{
		return m_CmapId;
	}

};
//帮会列表封装类
class GuildListObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildListObjWraper()
	{
		
		m_Guild = -1;
		m_GuildName = "";
		m_Level = 1;
		m_CurMemberNum = 1;
		m_TotalMilitary = 0;
		m_Announcement = "";

	}
	//赋值构造函数
	GuildListObjWraper(const GuildListObj& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildListObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildListObj ToPB() const
	{
		GuildListObj v;
		v.set_guild( m_Guild );
		v.set_guildname( m_GuildName );
		v.set_level( m_Level );
		v.set_curmembernum( m_CurMemberNum );
		v.set_totalmilitary( m_TotalMilitary );
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
		GuildListObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Guild(帮派Id) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildName(帮派名字) [string]</li>\r\n";
		htmlBuff += "<li>Level(等级) [sint32]</li>\r\n";
		htmlBuff += "<li>CurMemberNum(当前成员数量) [sint32]</li>\r\n";
		htmlBuff += "<li>TotalMilitary(总战力) [sint32]</li>\r\n";
		htmlBuff += "<li>Announcement(公告) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Guild：%di</li>\r\n",m_Guild);
		htmlBuff += tmpLine;
		htmlBuff += "<li>GuildName：\""+m_GuildName+"\"</li>\r\n";
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CurMemberNum：%di</li>\r\n",m_CurMemberNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TotalMilitary：%di</li>\r\n",m_TotalMilitary);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Announcement：\""+m_Announcement+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildListObj& v)
	{
		m_Guild = v.guild();
		m_GuildName = v.guildname();
		m_Level = v.level();
		m_CurMemberNum = v.curmembernum();
		m_TotalMilitary = v.totalmilitary();
		m_Announcement = v.announcement();

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
	//当前成员数量
	INT32 m_CurMemberNum;
public:
	void SetCurMemberNum( INT32 v)
	{
		m_CurMemberNum=v;
	}
	INT32 GetCurMemberNum()
	{
		return m_CurMemberNum;
	}
	INT32 GetCurMemberNum() const
	{
		return m_CurMemberNum;
	}
private:
	//总战力
	INT32 m_TotalMilitary;
public:
	void SetTotalMilitary( INT32 v)
	{
		m_TotalMilitary=v;
	}
	INT32 GetTotalMilitary()
	{
		return m_TotalMilitary;
	}
	INT32 GetTotalMilitary() const
	{
		return m_TotalMilitary;
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
//帮会信息对象封装类
class GuildInfoObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildInfoObjWraper()
	{
		
		m_Guild = -1;
		m_GuildName = "";
		m_Level = 1;
		m_CaptainId = -1;
		m_CaptainName = "";
		m_Funds = -1;
		m_CurMemberNum = 1;
		m_MaintenanceCost = -1;
		m_LeagueMatchesRank = -1;
		m_Announcement = "";
		m_TotalMilitary = -1;
		m_MaxMemberNum = -1;
		m_HallLv = 1;
		m_HallLvupTime = -1;
		m_HouseLv = 1;
		m_HouseLvupTime = -1;
		m_StoreroomLv = 1;
		m_StoreroomLvupTime = -1;
		m_KongfuHallLv = 1;
		m_KongfuHallLvupTime = -1;
		m_CreateTime = -1;
		m_GuildWar = GuildWarObjWraper();

	}
	//赋值构造函数
	GuildInfoObjWraper(const GuildInfoObj& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildInfoObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildInfoObj ToPB() const
	{
		GuildInfoObj v;
		v.set_guild( m_Guild );
		v.set_guildname( m_GuildName );
		v.set_level( m_Level );
		v.set_captainid( m_CaptainId );
		v.set_captainname( m_CaptainName );
		v.set_funds( m_Funds );
		v.set_curmembernum( m_CurMemberNum );
		v.mutable_guildmember()->Reserve(m_GuildMember.size());
		for (int i=0; i<(int)m_GuildMember.size(); i++)
		{
			*v.add_guildmember() = m_GuildMember[i].ToPB();
		}
		v.set_maintenancecost( m_MaintenanceCost );
		v.set_leaguematchesrank( m_LeagueMatchesRank );
		v.set_announcement( m_Announcement );
		v.set_totalmilitary( m_TotalMilitary );
		v.mutable_applylist()->Reserve(m_ApplyList.size());
		for (int i=0; i<(int)m_ApplyList.size(); i++)
		{
			*v.add_applylist() = m_ApplyList[i].ToPB();
		}
		v.set_maxmembernum( m_MaxMemberNum );
		v.set_halllv( m_HallLv );
		v.set_halllvuptime( m_HallLvupTime );
		v.set_houselv( m_HouseLv );
		v.set_houselvuptime( m_HouseLvupTime );
		v.set_storeroomlv( m_StoreroomLv );
		v.set_storeroomlvuptime( m_StoreroomLvupTime );
		v.set_kongfuhalllv( m_KongfuHallLv );
		v.set_kongfuhalllvuptime( m_KongfuHallLvupTime );
		v.set_createtime( m_CreateTime );
		v.mutable_eventlist()->Reserve(m_EventList.size());
		for (int i=0; i<(int)m_EventList.size(); i++)
		{
			*v.add_eventlist() = m_EventList[i].ToPB();
		}
		v.mutable_guilddungeonlist()->Reserve(m_GuildDungeonList.size());
		for (int i=0; i<(int)m_GuildDungeonList.size(); i++)
		{
			*v.add_guilddungeonlist() = m_GuildDungeonList[i].ToPB();
		}
		*v.mutable_guildwar()= m_GuildWar.ToPB();
		v.mutable_guildopenscience()->Reserve(m_GuildOpenScience.size());
		for (int i=0; i<(int)m_GuildOpenScience.size(); i++)
		{
			v.add_guildopenscience(m_GuildOpenScience[i]);
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
		GuildInfoObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Guild(帮派Id) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildName(帮派名字) [string]</li>\r\n";
		htmlBuff += "<li>Level(等级) [sint32]</li>\r\n";
		htmlBuff += "<li>CaptainId(帮主Id) [sint64]</li>\r\n";
		htmlBuff += "<li>CaptainName(帮主名字) [string]</li>\r\n";
		htmlBuff += "<li>Funds(资金) [sint32]</li>\r\n";
		htmlBuff += "<li>CurMemberNum(当前成员数量) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildMember(帮会成员) [GuildMemberObj] Array</li>\r\n";
		htmlBuff += "<li>MaintenanceCost(维护费用) [sint32]</li>\r\n";
		htmlBuff += "<li>LeagueMatchesRank(联赛排名) [sint32]</li>\r\n";
		htmlBuff += "<li>Announcement(公告) [string]</li>\r\n";
		htmlBuff += "<li>TotalMilitary(总战力) [sint32]</li>\r\n";
		htmlBuff += "<li>ApplyList(申请列表) [ApplyListRoleInfoObj] Array</li>\r\n";
		htmlBuff += "<li>MaxMemberNum(最大成员数量) [sint32]</li>\r\n";
		htmlBuff += "<li>HallLv(帮会大厅等级) [sint32]</li>\r\n";
		htmlBuff += "<li>HallLvupTime(帮会大厅升级时间) [sint32]</li>\r\n";
		htmlBuff += "<li>HouseLv(帮会房屋等级) [sint32]</li>\r\n";
		htmlBuff += "<li>HouseLvupTime(帮会房屋升级时间) [sint32]</li>\r\n";
		htmlBuff += "<li>StoreroomLv(帮会库房等级) [sint32]</li>\r\n";
		htmlBuff += "<li>StoreroomLvupTime(帮会库房升级时间) [sint32]</li>\r\n";
		htmlBuff += "<li>KongfuHallLv(练武堂等级) [sint32]</li>\r\n";
		htmlBuff += "<li>KongfuHallLvupTime(练武堂升级时间) [sint32]</li>\r\n";
		htmlBuff += "<li>CreateTime(创建时间) [sint32]</li>\r\n";
		htmlBuff += "<li>EventList(帮会事件) [GuildEventObj] Array</li>\r\n";
		htmlBuff += "<li>GuildDungeonList(帮会副本列表) [GuildDungeonObj] Array</li>\r\n";
		htmlBuff += "<li>GuildWar(帮会战) [GuildWarObj]</li>\r\n";
		htmlBuff += "<li>GuildOpenScience(开启修炼个数) [sint32] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Guild：%di</li>\r\n",m_Guild);
		htmlBuff += tmpLine;
		htmlBuff += "<li>GuildName：\""+m_GuildName+"\"</li>\r\n";
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CaptainId：%lldL</li>\r\n",m_CaptainId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>CaptainName：\""+m_CaptainName+"\"</li>\r\n";
		tmpLine.Fmt("<li>Funds：%di</li>\r\n",m_Funds);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CurMemberNum：%di</li>\r\n",m_CurMemberNum);
		htmlBuff += tmpLine;
		htmlBuff += "<li>GuildMember：</li>\r\n";
		if( m_GuildMember.size()>0) htmlBuff += m_GuildMember[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_GuildMember.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_GuildMember[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>MaintenanceCost：%di</li>\r\n",m_MaintenanceCost);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>LeagueMatchesRank：%di</li>\r\n",m_LeagueMatchesRank);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Announcement：\""+m_Announcement+"\"</li>\r\n";
		tmpLine.Fmt("<li>TotalMilitary：%di</li>\r\n",m_TotalMilitary);
		htmlBuff += tmpLine;
		htmlBuff += "<li>ApplyList：</li>\r\n";
		if( m_ApplyList.size()>0) htmlBuff += m_ApplyList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ApplyList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ApplyList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>MaxMemberNum：%di</li>\r\n",m_MaxMemberNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>HallLv：%di</li>\r\n",m_HallLv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>HallLvupTime：%di</li>\r\n",m_HallLvupTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>HouseLv：%di</li>\r\n",m_HouseLv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>HouseLvupTime：%di</li>\r\n",m_HouseLvupTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>StoreroomLv：%di</li>\r\n",m_StoreroomLv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>StoreroomLvupTime：%di</li>\r\n",m_StoreroomLvupTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>KongfuHallLv：%di</li>\r\n",m_KongfuHallLv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>KongfuHallLvupTime：%di</li>\r\n",m_KongfuHallLvupTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CreateTime：%di</li>\r\n",m_CreateTime);
		htmlBuff += tmpLine;
		htmlBuff += "<li>EventList：</li>\r\n";
		if( m_EventList.size()>0) htmlBuff += m_EventList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_EventList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_EventList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>GuildDungeonList：</li>\r\n";
		if( m_GuildDungeonList.size()>0) htmlBuff += m_GuildDungeonList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_GuildDungeonList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_GuildDungeonList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>GuildWar：</li>\r\n";
		htmlBuff += m_GuildWar.HtmlDescHeader();
		htmlBuff += m_GuildWar.ToHtml();
		htmlBuff += "<li>GuildOpenScience：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_GuildOpenScience.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_GuildOpenScience[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_GuildOpenScience.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GuildInfoObj& v)
	{
		m_Guild = v.guild();
		m_GuildName = v.guildname();
		m_Level = v.level();
		m_CaptainId = v.captainid();
		m_CaptainName = v.captainname();
		m_Funds = v.funds();
		m_CurMemberNum = v.curmembernum();
		m_GuildMember.clear();
		m_GuildMember.reserve(v.guildmember_size());
		for( int i=0; i<v.guildmember_size(); i++)
			m_GuildMember.push_back(v.guildmember(i));
		m_MaintenanceCost = v.maintenancecost();
		m_LeagueMatchesRank = v.leaguematchesrank();
		m_Announcement = v.announcement();
		m_TotalMilitary = v.totalmilitary();
		m_ApplyList.clear();
		m_ApplyList.reserve(v.applylist_size());
		for( int i=0; i<v.applylist_size(); i++)
			m_ApplyList.push_back(v.applylist(i));
		m_MaxMemberNum = v.maxmembernum();
		m_HallLv = v.halllv();
		m_HallLvupTime = v.halllvuptime();
		m_HouseLv = v.houselv();
		m_HouseLvupTime = v.houselvuptime();
		m_StoreroomLv = v.storeroomlv();
		m_StoreroomLvupTime = v.storeroomlvuptime();
		m_KongfuHallLv = v.kongfuhalllv();
		m_KongfuHallLvupTime = v.kongfuhalllvuptime();
		m_CreateTime = v.createtime();
		m_EventList.clear();
		m_EventList.reserve(v.eventlist_size());
		for( int i=0; i<v.eventlist_size(); i++)
			m_EventList.push_back(v.eventlist(i));
		m_GuildDungeonList.clear();
		m_GuildDungeonList.reserve(v.guilddungeonlist_size());
		for( int i=0; i<v.guilddungeonlist_size(); i++)
			m_GuildDungeonList.push_back(v.guilddungeonlist(i));
		m_GuildWar = v.guildwar();
		m_GuildOpenScience.clear();
		m_GuildOpenScience.reserve(v.guildopenscience_size());
		for( int i=0; i<v.guildopenscience_size(); i++)
			m_GuildOpenScience.push_back(v.guildopenscience(i));

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
	//当前成员数量
	INT32 m_CurMemberNum;
public:
	void SetCurMemberNum( INT32 v)
	{
		m_CurMemberNum=v;
	}
	INT32 GetCurMemberNum()
	{
		return m_CurMemberNum;
	}
	INT32 GetCurMemberNum() const
	{
		return m_CurMemberNum;
	}
private:
	//帮会成员
	vector<GuildMemberObjWraper> m_GuildMember;
public:
	int SizeGuildMember()
	{
		return m_GuildMember.size();
	}
	const vector<GuildMemberObjWraper>& GetGuildMember() const
	{
		return m_GuildMember;
	}
	GuildMemberObjWraper GetGuildMember(int Index) const
	{
		if(Index<0 || Index>=(int)m_GuildMember.size())
		{
			assert(false);
			return GuildMemberObjWraper();
		}
		return m_GuildMember[Index];
	}
	void SetGuildMember( const vector<GuildMemberObjWraper>& v )
	{
		m_GuildMember=v;
	}
	void ClearGuildMember( )
	{
		m_GuildMember.clear();
	}
	void SetGuildMember( int Index, const GuildMemberObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_GuildMember.size())
		{
			assert(false);
			return;
		}
		m_GuildMember[Index] = v;
	}
	void AddGuildMember( const GuildMemberObjWraper& v )
	{
		m_GuildMember.push_back(v);
	}
private:
	//维护费用
	INT32 m_MaintenanceCost;
public:
	void SetMaintenanceCost( INT32 v)
	{
		m_MaintenanceCost=v;
	}
	INT32 GetMaintenanceCost()
	{
		return m_MaintenanceCost;
	}
	INT32 GetMaintenanceCost() const
	{
		return m_MaintenanceCost;
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
private:
	//总战力
	INT32 m_TotalMilitary;
public:
	void SetTotalMilitary( INT32 v)
	{
		m_TotalMilitary=v;
	}
	INT32 GetTotalMilitary()
	{
		return m_TotalMilitary;
	}
	INT32 GetTotalMilitary() const
	{
		return m_TotalMilitary;
	}
private:
	//申请列表
	vector<ApplyListRoleInfoObjWraper> m_ApplyList;
public:
	int SizeApplyList()
	{
		return m_ApplyList.size();
	}
	const vector<ApplyListRoleInfoObjWraper>& GetApplyList() const
	{
		return m_ApplyList;
	}
	ApplyListRoleInfoObjWraper GetApplyList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ApplyList.size())
		{
			assert(false);
			return ApplyListRoleInfoObjWraper();
		}
		return m_ApplyList[Index];
	}
	void SetApplyList( const vector<ApplyListRoleInfoObjWraper>& v )
	{
		m_ApplyList=v;
	}
	void ClearApplyList( )
	{
		m_ApplyList.clear();
	}
	void SetApplyList( int Index, const ApplyListRoleInfoObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_ApplyList.size())
		{
			assert(false);
			return;
		}
		m_ApplyList[Index] = v;
	}
	void AddApplyList( const ApplyListRoleInfoObjWraper& v )
	{
		m_ApplyList.push_back(v);
	}
private:
	//最大成员数量
	INT32 m_MaxMemberNum;
public:
	void SetMaxMemberNum( INT32 v)
	{
		m_MaxMemberNum=v;
	}
	INT32 GetMaxMemberNum()
	{
		return m_MaxMemberNum;
	}
	INT32 GetMaxMemberNum() const
	{
		return m_MaxMemberNum;
	}
private:
	//帮会大厅等级
	INT32 m_HallLv;
public:
	void SetHallLv( INT32 v)
	{
		m_HallLv=v;
	}
	INT32 GetHallLv()
	{
		return m_HallLv;
	}
	INT32 GetHallLv() const
	{
		return m_HallLv;
	}
private:
	//帮会大厅升级时间
	INT32 m_HallLvupTime;
public:
	void SetHallLvupTime( INT32 v)
	{
		m_HallLvupTime=v;
	}
	INT32 GetHallLvupTime()
	{
		return m_HallLvupTime;
	}
	INT32 GetHallLvupTime() const
	{
		return m_HallLvupTime;
	}
private:
	//帮会房屋等级
	INT32 m_HouseLv;
public:
	void SetHouseLv( INT32 v)
	{
		m_HouseLv=v;
	}
	INT32 GetHouseLv()
	{
		return m_HouseLv;
	}
	INT32 GetHouseLv() const
	{
		return m_HouseLv;
	}
private:
	//帮会房屋升级时间
	INT32 m_HouseLvupTime;
public:
	void SetHouseLvupTime( INT32 v)
	{
		m_HouseLvupTime=v;
	}
	INT32 GetHouseLvupTime()
	{
		return m_HouseLvupTime;
	}
	INT32 GetHouseLvupTime() const
	{
		return m_HouseLvupTime;
	}
private:
	//帮会库房等级
	INT32 m_StoreroomLv;
public:
	void SetStoreroomLv( INT32 v)
	{
		m_StoreroomLv=v;
	}
	INT32 GetStoreroomLv()
	{
		return m_StoreroomLv;
	}
	INT32 GetStoreroomLv() const
	{
		return m_StoreroomLv;
	}
private:
	//帮会库房升级时间
	INT32 m_StoreroomLvupTime;
public:
	void SetStoreroomLvupTime( INT32 v)
	{
		m_StoreroomLvupTime=v;
	}
	INT32 GetStoreroomLvupTime()
	{
		return m_StoreroomLvupTime;
	}
	INT32 GetStoreroomLvupTime() const
	{
		return m_StoreroomLvupTime;
	}
private:
	//练武堂等级
	INT32 m_KongfuHallLv;
public:
	void SetKongfuHallLv( INT32 v)
	{
		m_KongfuHallLv=v;
	}
	INT32 GetKongfuHallLv()
	{
		return m_KongfuHallLv;
	}
	INT32 GetKongfuHallLv() const
	{
		return m_KongfuHallLv;
	}
private:
	//练武堂升级时间
	INT32 m_KongfuHallLvupTime;
public:
	void SetKongfuHallLvupTime( INT32 v)
	{
		m_KongfuHallLvupTime=v;
	}
	INT32 GetKongfuHallLvupTime()
	{
		return m_KongfuHallLvupTime;
	}
	INT32 GetKongfuHallLvupTime() const
	{
		return m_KongfuHallLvupTime;
	}
private:
	//创建时间
	INT32 m_CreateTime;
public:
	void SetCreateTime( INT32 v)
	{
		m_CreateTime=v;
	}
	INT32 GetCreateTime()
	{
		return m_CreateTime;
	}
	INT32 GetCreateTime() const
	{
		return m_CreateTime;
	}
private:
	//帮会事件
	vector<GuildEventObjWraper> m_EventList;
public:
	int SizeEventList()
	{
		return m_EventList.size();
	}
	const vector<GuildEventObjWraper>& GetEventList() const
	{
		return m_EventList;
	}
	GuildEventObjWraper GetEventList(int Index) const
	{
		if(Index<0 || Index>=(int)m_EventList.size())
		{
			assert(false);
			return GuildEventObjWraper();
		}
		return m_EventList[Index];
	}
	void SetEventList( const vector<GuildEventObjWraper>& v )
	{
		m_EventList=v;
	}
	void ClearEventList( )
	{
		m_EventList.clear();
	}
	void SetEventList( int Index, const GuildEventObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_EventList.size())
		{
			assert(false);
			return;
		}
		m_EventList[Index] = v;
	}
	void AddEventList( const GuildEventObjWraper& v )
	{
		m_EventList.push_back(v);
	}
private:
	//帮会副本列表
	vector<GuildDungeonObjWraper> m_GuildDungeonList;
public:
	int SizeGuildDungeonList()
	{
		return m_GuildDungeonList.size();
	}
	const vector<GuildDungeonObjWraper>& GetGuildDungeonList() const
	{
		return m_GuildDungeonList;
	}
	GuildDungeonObjWraper GetGuildDungeonList(int Index) const
	{
		if(Index<0 || Index>=(int)m_GuildDungeonList.size())
		{
			assert(false);
			return GuildDungeonObjWraper();
		}
		return m_GuildDungeonList[Index];
	}
	void SetGuildDungeonList( const vector<GuildDungeonObjWraper>& v )
	{
		m_GuildDungeonList=v;
	}
	void ClearGuildDungeonList( )
	{
		m_GuildDungeonList.clear();
	}
	void SetGuildDungeonList( int Index, const GuildDungeonObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_GuildDungeonList.size())
		{
			assert(false);
			return;
		}
		m_GuildDungeonList[Index] = v;
	}
	void AddGuildDungeonList( const GuildDungeonObjWraper& v )
	{
		m_GuildDungeonList.push_back(v);
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
private:
	//开启修炼个数
	vector<INT32> m_GuildOpenScience;
public:
	int SizeGuildOpenScience()
	{
		return m_GuildOpenScience.size();
	}
	const vector<INT32>& GetGuildOpenScience() const
	{
		return m_GuildOpenScience;
	}
	INT32 GetGuildOpenScience(int Index) const
	{
		if(Index<0 || Index>=(int)m_GuildOpenScience.size())
		{
			assert(false);
			return INT32();
		}
		return m_GuildOpenScience[Index];
	}
	void SetGuildOpenScience( const vector<INT32>& v )
	{
		m_GuildOpenScience=v;
	}
	void ClearGuildOpenScience( )
	{
		m_GuildOpenScience.clear();
	}
	void SetGuildOpenScience( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_GuildOpenScience.size())
		{
			assert(false);
			return;
		}
		m_GuildOpenScience[Index] = v;
	}
	void AddGuildOpenScience( INT32 v = -1 )
	{
		m_GuildOpenScience.push_back(v);
	}

};
//背包格子对象封装类
class BagGridObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagGridObjWraper()
	{
		
		m_TemplateID = -1;
		m_Num = 0;
		m_ItemType = -1;
		m_Pos = -1;
		m_Value = -1;
		m_Index = -1;
		m_Bind = false;

	}
	//赋值构造函数
	BagGridObjWraper(const BagGridObj& v){ Init(v); }
	//等号重载函数
	void operator = (const BagGridObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagGridObj ToPB() const
	{
		BagGridObj v;
		v.set_templateid( m_TemplateID );
		v.set_num( m_Num );
		v.set_itemtype( m_ItemType );
		v.set_pos( m_Pos );
		v.set_value( m_Value );
		v.set_index( m_Index );
		v.set_bind( m_Bind );

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
		BagGridObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateID(物品的配置Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(物品数量) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemType(物品类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>Value(客户端通用数据) [sint32]</li>\r\n";
		htmlBuff += "<li>Index(ItemId，唯一id) [sint64]</li>\r\n";
		htmlBuff += "<li>Bind(绑定) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateID：%di</li>\r\n",m_TemplateID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemType：%di</li>\r\n",m_ItemType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Value：%di</li>\r\n",m_Value);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Index：%lldL</li>\r\n",m_Index);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Bind：%di</li>\r\n",m_Bind);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagGridObj& v)
	{
		m_TemplateID = v.templateid();
		m_Num = v.num();
		m_ItemType = v.itemtype();
		m_Pos = v.pos();
		m_Value = v.value();
		m_Index = v.index();
		m_Bind = v.bind();

	}

private:
	//物品的配置Id
	INT32 m_TemplateID;
public:
	void SetTemplateID( INT32 v)
	{
		m_TemplateID=v;
	}
	INT32 GetTemplateID()
	{
		return m_TemplateID;
	}
	INT32 GetTemplateID() const
	{
		return m_TemplateID;
	}
private:
	//物品数量
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}
private:
	//物品类型
	INT32 m_ItemType;
public:
	void SetItemType( INT32 v)
	{
		m_ItemType=v;
	}
	INT32 GetItemType()
	{
		return m_ItemType;
	}
	INT32 GetItemType() const
	{
		return m_ItemType;
	}
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//客户端通用数据
	INT32 m_Value;
public:
	void SetValue( INT32 v)
	{
		m_Value=v;
	}
	INT32 GetValue()
	{
		return m_Value;
	}
	INT32 GetValue() const
	{
		return m_Value;
	}
private:
	//ItemId，唯一id
	INT64 m_Index;
public:
	void SetIndex( INT64 v)
	{
		m_Index=v;
	}
	INT64 GetIndex()
	{
		return m_Index;
	}
	INT64 GetIndex() const
	{
		return m_Index;
	}
private:
	//绑定
	bool m_Bind;
public:
	void SetBind( bool v)
	{
		m_Bind=v;
	}
	bool GetBind()
	{
		return m_Bind;
	}
	bool GetBind() const
	{
		return m_Bind;
	}

};
//掉落物品对象封装类
class DropItemObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	DropItemObjWraper()
	{
		
		m_ConfigId = -1;
		m_UId = -1;
		m_Num = 0;
		m_ItemType = -1;
		m_AttrNum = 0;
		m_MonsterObjId = -1;
		m_PosInfo = "";
		m_CreateTime = 0;
		m_IsPickup = false;
		m_ItemId = -1;
		m_DestroyTime = 0;

	}
	//赋值构造函数
	DropItemObjWraper(const DropItemObj& v){ Init(v); }
	//等号重载函数
	void operator = (const DropItemObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DropItemObj ToPB() const
	{
		DropItemObj v;
		v.set_configid( m_ConfigId );
		v.set_uid( m_UId );
		v.set_num( m_Num );
		v.set_itemtype( m_ItemType );
		v.set_attrnum( m_AttrNum );
		v.set_monsterobjid( m_MonsterObjId );
		v.set_posinfo( m_PosInfo );
		v.set_createtime( m_CreateTime );
		v.set_ispickup( m_IsPickup );
		v.set_itemid( m_ItemId );
		v.set_destroytime( m_DestroyTime );

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
		DropItemObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ConfigId(物品的配置Id) [sint32]</li>\r\n";
		htmlBuff += "<li>UId(下标) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(物品数量) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemType(物品类型) [sint32]</li>\r\n";
		htmlBuff += "<li>AttrNum(属性数量) [sint32]</li>\r\n";
		htmlBuff += "<li>MonsterObjId(怪物ObjId) [sint32]</li>\r\n";
		htmlBuff += "<li>PosInfo(位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>CreateTime(创建时间) [sint32]</li>\r\n";
		htmlBuff += "<li>IsPickup(是否已经拾取) [bool]</li>\r\n";
		htmlBuff += "<li>ItemId(物品唯一Id) [sint64]</li>\r\n";
		htmlBuff += "<li>DestroyTime(销毁时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ConfigId：%di</li>\r\n",m_ConfigId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UId：%di</li>\r\n",m_UId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemType：%di</li>\r\n",m_ItemType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttrNum：%di</li>\r\n",m_AttrNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MonsterObjId：%di</li>\r\n",m_MonsterObjId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PosInfo：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>CreateTime：%di</li>\r\n",m_CreateTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsPickup：%di</li>\r\n",m_IsPickup);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemId：%lldL</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DestroyTime：%di</li>\r\n",m_DestroyTime);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DropItemObj& v)
	{
		m_ConfigId = v.configid();
		m_UId = v.uid();
		m_Num = v.num();
		m_ItemType = v.itemtype();
		m_AttrNum = v.attrnum();
		m_MonsterObjId = v.monsterobjid();
		m_PosInfo = v.posinfo();
		m_CreateTime = v.createtime();
		m_IsPickup = v.ispickup();
		m_ItemId = v.itemid();
		m_DestroyTime = v.destroytime();

	}

private:
	//物品的配置Id
	INT32 m_ConfigId;
public:
	void SetConfigId( INT32 v)
	{
		m_ConfigId=v;
	}
	INT32 GetConfigId()
	{
		return m_ConfigId;
	}
	INT32 GetConfigId() const
	{
		return m_ConfigId;
	}
private:
	//下标
	INT32 m_UId;
public:
	void SetUId( INT32 v)
	{
		m_UId=v;
	}
	INT32 GetUId()
	{
		return m_UId;
	}
	INT32 GetUId() const
	{
		return m_UId;
	}
private:
	//物品数量
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}
private:
	//物品类型
	INT32 m_ItemType;
public:
	void SetItemType( INT32 v)
	{
		m_ItemType=v;
	}
	INT32 GetItemType()
	{
		return m_ItemType;
	}
	INT32 GetItemType() const
	{
		return m_ItemType;
	}
private:
	//属性数量
	INT32 m_AttrNum;
public:
	void SetAttrNum( INT32 v)
	{
		m_AttrNum=v;
	}
	INT32 GetAttrNum()
	{
		return m_AttrNum;
	}
	INT32 GetAttrNum() const
	{
		return m_AttrNum;
	}
private:
	//怪物ObjId
	INT32 m_MonsterObjId;
public:
	void SetMonsterObjId( INT32 v)
	{
		m_MonsterObjId=v;
	}
	INT32 GetMonsterObjId()
	{
		return m_MonsterObjId;
	}
	INT32 GetMonsterObjId() const
	{
		return m_MonsterObjId;
	}
private:
	//位置信息
	string m_PosInfo;
public:
	void SetPosInfo( const string& v)
	{
		m_PosInfo=v;
	}
	string GetPosInfo()
	{
		return m_PosInfo;
	}
	string GetPosInfo() const
	{
		return m_PosInfo;
	}
private:
	//创建时间
	INT32 m_CreateTime;
public:
	void SetCreateTime( INT32 v)
	{
		m_CreateTime=v;
	}
	INT32 GetCreateTime()
	{
		return m_CreateTime;
	}
	INT32 GetCreateTime() const
	{
		return m_CreateTime;
	}
private:
	//是否已经拾取
	bool m_IsPickup;
public:
	void SetIsPickup( bool v)
	{
		m_IsPickup=v;
	}
	bool GetIsPickup()
	{
		return m_IsPickup;
	}
	bool GetIsPickup() const
	{
		return m_IsPickup;
	}
private:
	//物品唯一Id
	INT64 m_ItemId;
public:
	void SetItemId( INT64 v)
	{
		m_ItemId=v;
	}
	INT64 GetItemId()
	{
		return m_ItemId;
	}
	INT64 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//销毁时间
	INT32 m_DestroyTime;
public:
	void SetDestroyTime( INT32 v)
	{
		m_DestroyTime=v;
	}
	INT32 GetDestroyTime()
	{
		return m_DestroyTime;
	}
	INT32 GetDestroyTime() const
	{
		return m_DestroyTime;
	}

};
//背包装备对象封装类
class BagEquipObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	BagEquipObjWraper()
	{
		
		m_ItemID = -1;
		m_PolishedScore = 0;
		m_Index = -1;
		m_BagContainerType = -1;
		m_GridIndex = -1;
		m_TemplateId = -1;
		m_GemSuitId = -1;
		m_EquipScore = 0;
		m_PolishedEquipScore = 0;

	}
	//赋值构造函数
	BagEquipObjWraper(const BagEquipObj& v){ Init(v); }
	//等号重载函数
	void operator = (const BagEquipObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagEquipObj ToPB() const
	{
		BagEquipObj v;
		v.set_itemid( m_ItemID );
		v.mutable_baseattr()->Reserve(m_BaseAttr.size());
		for (int i=0; i<(int)m_BaseAttr.size(); i++)
		{
			*v.add_baseattr() = m_BaseAttr[i].ToPB();
		}
		v.mutable_extraattr()->Reserve(m_ExtraAttr.size());
		for (int i=0; i<(int)m_ExtraAttr.size(); i++)
		{
			*v.add_extraattr() = m_ExtraAttr[i].ToPB();
		}
		v.mutable_enhancelv()->Reserve(m_EnhanceLv.size());
		for (int i=0; i<(int)m_EnhanceLv.size(); i++)
		{
			v.add_enhancelv(m_EnhanceLv[i]);
		}
		v.mutable_equippolishedresult()->Reserve(m_EquipPolishedResult.size());
		for (int i=0; i<(int)m_EquipPolishedResult.size(); i++)
		{
			*v.add_equippolishedresult() = m_EquipPolishedResult[i].ToPB();
		}
		v.set_polishedscore( m_PolishedScore );
		v.set_index( m_Index );
		v.mutable_initbaseattr()->Reserve(m_InitBaseAttr.size());
		for (int i=0; i<(int)m_InitBaseAttr.size(); i++)
		{
			*v.add_initbaseattr() = m_InitBaseAttr[i].ToPB();
		}
		v.set_bagcontainertype( m_BagContainerType );
		v.set_gridindex( m_GridIndex );
		v.mutable_plishedattrid()->Reserve(m_PlishedAttrId.size());
		for (int i=0; i<(int)m_PlishedAttrId.size(); i++)
		{
			*v.add_plishedattrid() = m_PlishedAttrId[i].ToPB();
		}
		v.mutable_gemarray()->Reserve(m_GemArray.size());
		for (int i=0; i<(int)m_GemArray.size(); i++)
		{
			*v.add_gemarray() = m_GemArray[i].ToPB();
		}
		v.mutable_polishedbaseattrresult()->Reserve(m_PolishedBaseAttrResult.size());
		for (int i=0; i<(int)m_PolishedBaseAttrResult.size(); i++)
		{
			*v.add_polishedbaseattrresult() = m_PolishedBaseAttrResult[i].ToPB();
		}
		v.set_templateid( m_TemplateId );
		v.set_gemsuitid( m_GemSuitId );
		v.set_equipscore( m_EquipScore );
		v.set_polishedequipscore( m_PolishedEquipScore );
		v.mutable_baseattrpolishedinitattr()->Reserve(m_BaseAttrPolishedInitAttr.size());
		for (int i=0; i<(int)m_BaseAttrPolishedInitAttr.size(); i++)
		{
			*v.add_baseattrpolishedinitattr() = m_BaseAttrPolishedInitAttr[i].ToPB();
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
		BagEquipObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ItemID(物品实例id, 唯一id) [sint64]</li>\r\n";
		htmlBuff += "<li>BaseAttr(基础属性值(包括附加的加成)) [BagAttrIntObj] Array</li>\r\n";
		htmlBuff += "<li>ExtraAttr(额外属性) [BagExtraAttrObj] Array</li>\r\n";
		htmlBuff += "<li>EnhanceLv(强化等级) [sint32] Array</li>\r\n";
		htmlBuff += "<li>EquipPolishedResult(装备洗炼结果) [BagExtraAttrObj] Array</li>\r\n";
		htmlBuff += "<li>PolishedScore(洗炼积分) [sint32]</li>\r\n";
		htmlBuff += "<li>Index(用于索引道具具体数据) [sint64]</li>\r\n";
		htmlBuff += "<li>InitBaseAttr(初始基础属性) [BagAttrIntObj] Array</li>\r\n";
		htmlBuff += "<li>BagContainerType(物品容器类型) [sint32]</li>\r\n";
		htmlBuff += "<li>GridIndex(装备格子的索引) [sint32]</li>\r\n";
		htmlBuff += "<li>PlishedAttrId(洗炼属性id) [BagExtraAttrIdObj] Array</li>\r\n";
		htmlBuff += "<li>GemArray(宝石数组) [BagGemObj] Array</li>\r\n";
		htmlBuff += "<li>PolishedBaseAttrResult(基础属性洗炼结果) [BagAttrIntObj] Array</li>\r\n";
		htmlBuff += "<li>TemplateId(模板id) [sint32]</li>\r\n";
		htmlBuff += "<li>GemSuitId(宝石组合id) [sint32]</li>\r\n";
		htmlBuff += "<li>EquipScore(装备评分) [sint32]</li>\r\n";
		htmlBuff += "<li>PolishedEquipScore(洗炼装备评分) [sint32]</li>\r\n";
		htmlBuff += "<li>BaseAttrPolishedInitAttr(基础属性洗炼初始属性) [BagAttrIntObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ItemID：%lldL</li>\r\n",m_ItemID);
		htmlBuff += tmpLine;
		htmlBuff += "<li>BaseAttr：</li>\r\n";
		if( m_BaseAttr.size()>0) htmlBuff += m_BaseAttr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_BaseAttr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_BaseAttr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>ExtraAttr：</li>\r\n";
		if( m_ExtraAttr.size()>0) htmlBuff += m_ExtraAttr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ExtraAttr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ExtraAttr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>EnhanceLv：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_EnhanceLv.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_EnhanceLv[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_EnhanceLv.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		htmlBuff += "<li>EquipPolishedResult：</li>\r\n";
		if( m_EquipPolishedResult.size()>0) htmlBuff += m_EquipPolishedResult[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_EquipPolishedResult.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_EquipPolishedResult[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>PolishedScore：%di</li>\r\n",m_PolishedScore);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Index：%lldL</li>\r\n",m_Index);
		htmlBuff += tmpLine;
		htmlBuff += "<li>InitBaseAttr：</li>\r\n";
		if( m_InitBaseAttr.size()>0) htmlBuff += m_InitBaseAttr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_InitBaseAttr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_InitBaseAttr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>BagContainerType：%di</li>\r\n",m_BagContainerType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GridIndex：%di</li>\r\n",m_GridIndex);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PlishedAttrId：</li>\r\n";
		if( m_PlishedAttrId.size()>0) htmlBuff += m_PlishedAttrId[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_PlishedAttrId.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_PlishedAttrId[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>GemArray：</li>\r\n";
		if( m_GemArray.size()>0) htmlBuff += m_GemArray[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_GemArray.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_GemArray[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>PolishedBaseAttrResult：</li>\r\n";
		if( m_PolishedBaseAttrResult.size()>0) htmlBuff += m_PolishedBaseAttrResult[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_PolishedBaseAttrResult.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_PolishedBaseAttrResult[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GemSuitId：%di</li>\r\n",m_GemSuitId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EquipScore：%di</li>\r\n",m_EquipScore);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PolishedEquipScore：%di</li>\r\n",m_PolishedEquipScore);
		htmlBuff += tmpLine;
		htmlBuff += "<li>BaseAttrPolishedInitAttr：</li>\r\n";
		if( m_BaseAttrPolishedInitAttr.size()>0) htmlBuff += m_BaseAttrPolishedInitAttr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_BaseAttrPolishedInitAttr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_BaseAttrPolishedInitAttr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BagEquipObj& v)
	{
		m_ItemID = v.itemid();
		m_BaseAttr.clear();
		m_BaseAttr.reserve(v.baseattr_size());
		for( int i=0; i<v.baseattr_size(); i++)
			m_BaseAttr.push_back(v.baseattr(i));
		m_ExtraAttr.clear();
		m_ExtraAttr.reserve(v.extraattr_size());
		for( int i=0; i<v.extraattr_size(); i++)
			m_ExtraAttr.push_back(v.extraattr(i));
		m_EnhanceLv.clear();
		m_EnhanceLv.reserve(v.enhancelv_size());
		for( int i=0; i<v.enhancelv_size(); i++)
			m_EnhanceLv.push_back(v.enhancelv(i));
		m_EquipPolishedResult.clear();
		m_EquipPolishedResult.reserve(v.equippolishedresult_size());
		for( int i=0; i<v.equippolishedresult_size(); i++)
			m_EquipPolishedResult.push_back(v.equippolishedresult(i));
		m_PolishedScore = v.polishedscore();
		m_Index = v.index();
		m_InitBaseAttr.clear();
		m_InitBaseAttr.reserve(v.initbaseattr_size());
		for( int i=0; i<v.initbaseattr_size(); i++)
			m_InitBaseAttr.push_back(v.initbaseattr(i));
		m_BagContainerType = v.bagcontainertype();
		m_GridIndex = v.gridindex();
		m_PlishedAttrId.clear();
		m_PlishedAttrId.reserve(v.plishedattrid_size());
		for( int i=0; i<v.plishedattrid_size(); i++)
			m_PlishedAttrId.push_back(v.plishedattrid(i));
		m_GemArray.clear();
		m_GemArray.reserve(v.gemarray_size());
		for( int i=0; i<v.gemarray_size(); i++)
			m_GemArray.push_back(v.gemarray(i));
		m_PolishedBaseAttrResult.clear();
		m_PolishedBaseAttrResult.reserve(v.polishedbaseattrresult_size());
		for( int i=0; i<v.polishedbaseattrresult_size(); i++)
			m_PolishedBaseAttrResult.push_back(v.polishedbaseattrresult(i));
		m_TemplateId = v.templateid();
		m_GemSuitId = v.gemsuitid();
		m_EquipScore = v.equipscore();
		m_PolishedEquipScore = v.polishedequipscore();
		m_BaseAttrPolishedInitAttr.clear();
		m_BaseAttrPolishedInitAttr.reserve(v.baseattrpolishedinitattr_size());
		for( int i=0; i<v.baseattrpolishedinitattr_size(); i++)
			m_BaseAttrPolishedInitAttr.push_back(v.baseattrpolishedinitattr(i));

	}

private:
	//物品实例id, 唯一id
	INT64 m_ItemID;
public:
	void SetItemID( INT64 v)
	{
		m_ItemID=v;
	}
	INT64 GetItemID()
	{
		return m_ItemID;
	}
	INT64 GetItemID() const
	{
		return m_ItemID;
	}
private:
	//基础属性值(包括附加的加成)
	vector<BagAttrIntObjWraper> m_BaseAttr;
public:
	int SizeBaseAttr()
	{
		return m_BaseAttr.size();
	}
	const vector<BagAttrIntObjWraper>& GetBaseAttr() const
	{
		return m_BaseAttr;
	}
	BagAttrIntObjWraper GetBaseAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_BaseAttr.size())
		{
			assert(false);
			return BagAttrIntObjWraper();
		}
		return m_BaseAttr[Index];
	}
	void SetBaseAttr( const vector<BagAttrIntObjWraper>& v )
	{
		m_BaseAttr=v;
	}
	void ClearBaseAttr( )
	{
		m_BaseAttr.clear();
	}
	void SetBaseAttr( int Index, const BagAttrIntObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_BaseAttr.size())
		{
			assert(false);
			return;
		}
		m_BaseAttr[Index] = v;
	}
	void AddBaseAttr( const BagAttrIntObjWraper& v )
	{
		m_BaseAttr.push_back(v);
	}
private:
	//额外属性
	vector<BagExtraAttrObjWraper> m_ExtraAttr;
public:
	int SizeExtraAttr()
	{
		return m_ExtraAttr.size();
	}
	const vector<BagExtraAttrObjWraper>& GetExtraAttr() const
	{
		return m_ExtraAttr;
	}
	BagExtraAttrObjWraper GetExtraAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.size())
		{
			assert(false);
			return BagExtraAttrObjWraper();
		}
		return m_ExtraAttr[Index];
	}
	void SetExtraAttr( const vector<BagExtraAttrObjWraper>& v )
	{
		m_ExtraAttr=v;
	}
	void ClearExtraAttr( )
	{
		m_ExtraAttr.clear();
	}
	void SetExtraAttr( int Index, const BagExtraAttrObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.size())
		{
			assert(false);
			return;
		}
		m_ExtraAttr[Index] = v;
	}
	void AddExtraAttr( const BagExtraAttrObjWraper& v )
	{
		m_ExtraAttr.push_back(v);
	}
private:
	//强化等级
	vector<INT32> m_EnhanceLv;
public:
	int SizeEnhanceLv()
	{
		return m_EnhanceLv.size();
	}
	const vector<INT32>& GetEnhanceLv() const
	{
		return m_EnhanceLv;
	}
	INT32 GetEnhanceLv(int Index) const
	{
		if(Index<0 || Index>=(int)m_EnhanceLv.size())
		{
			assert(false);
			return INT32();
		}
		return m_EnhanceLv[Index];
	}
	void SetEnhanceLv( const vector<INT32>& v )
	{
		m_EnhanceLv=v;
	}
	void ClearEnhanceLv( )
	{
		m_EnhanceLv.clear();
	}
	void SetEnhanceLv( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_EnhanceLv.size())
		{
			assert(false);
			return;
		}
		m_EnhanceLv[Index] = v;
	}
	void AddEnhanceLv( INT32 v = -1 )
	{
		m_EnhanceLv.push_back(v);
	}
private:
	//装备洗炼结果
	vector<BagExtraAttrObjWraper> m_EquipPolishedResult;
public:
	int SizeEquipPolishedResult()
	{
		return m_EquipPolishedResult.size();
	}
	const vector<BagExtraAttrObjWraper>& GetEquipPolishedResult() const
	{
		return m_EquipPolishedResult;
	}
	BagExtraAttrObjWraper GetEquipPolishedResult(int Index) const
	{
		if(Index<0 || Index>=(int)m_EquipPolishedResult.size())
		{
			assert(false);
			return BagExtraAttrObjWraper();
		}
		return m_EquipPolishedResult[Index];
	}
	void SetEquipPolishedResult( const vector<BagExtraAttrObjWraper>& v )
	{
		m_EquipPolishedResult=v;
	}
	void ClearEquipPolishedResult( )
	{
		m_EquipPolishedResult.clear();
	}
	void SetEquipPolishedResult( int Index, const BagExtraAttrObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_EquipPolishedResult.size())
		{
			assert(false);
			return;
		}
		m_EquipPolishedResult[Index] = v;
	}
	void AddEquipPolishedResult( const BagExtraAttrObjWraper& v )
	{
		m_EquipPolishedResult.push_back(v);
	}
private:
	//洗炼积分
	INT32 m_PolishedScore;
public:
	void SetPolishedScore( INT32 v)
	{
		m_PolishedScore=v;
	}
	INT32 GetPolishedScore()
	{
		return m_PolishedScore;
	}
	INT32 GetPolishedScore() const
	{
		return m_PolishedScore;
	}
private:
	//用于索引道具具体数据
	INT64 m_Index;
public:
	void SetIndex( INT64 v)
	{
		m_Index=v;
	}
	INT64 GetIndex()
	{
		return m_Index;
	}
	INT64 GetIndex() const
	{
		return m_Index;
	}
private:
	//初始基础属性
	vector<BagAttrIntObjWraper> m_InitBaseAttr;
public:
	int SizeInitBaseAttr()
	{
		return m_InitBaseAttr.size();
	}
	const vector<BagAttrIntObjWraper>& GetInitBaseAttr() const
	{
		return m_InitBaseAttr;
	}
	BagAttrIntObjWraper GetInitBaseAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_InitBaseAttr.size())
		{
			assert(false);
			return BagAttrIntObjWraper();
		}
		return m_InitBaseAttr[Index];
	}
	void SetInitBaseAttr( const vector<BagAttrIntObjWraper>& v )
	{
		m_InitBaseAttr=v;
	}
	void ClearInitBaseAttr( )
	{
		m_InitBaseAttr.clear();
	}
	void SetInitBaseAttr( int Index, const BagAttrIntObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_InitBaseAttr.size())
		{
			assert(false);
			return;
		}
		m_InitBaseAttr[Index] = v;
	}
	void AddInitBaseAttr( const BagAttrIntObjWraper& v )
	{
		m_InitBaseAttr.push_back(v);
	}
private:
	//物品容器类型
	INT32 m_BagContainerType;
public:
	void SetBagContainerType( INT32 v)
	{
		m_BagContainerType=v;
	}
	INT32 GetBagContainerType()
	{
		return m_BagContainerType;
	}
	INT32 GetBagContainerType() const
	{
		return m_BagContainerType;
	}
private:
	//装备格子的索引
	INT32 m_GridIndex;
public:
	void SetGridIndex( INT32 v)
	{
		m_GridIndex=v;
	}
	INT32 GetGridIndex()
	{
		return m_GridIndex;
	}
	INT32 GetGridIndex() const
	{
		return m_GridIndex;
	}
private:
	//洗炼属性id
	vector<BagExtraAttrIdObjWraper> m_PlishedAttrId;
public:
	int SizePlishedAttrId()
	{
		return m_PlishedAttrId.size();
	}
	const vector<BagExtraAttrIdObjWraper>& GetPlishedAttrId() const
	{
		return m_PlishedAttrId;
	}
	BagExtraAttrIdObjWraper GetPlishedAttrId(int Index) const
	{
		if(Index<0 || Index>=(int)m_PlishedAttrId.size())
		{
			assert(false);
			return BagExtraAttrIdObjWraper();
		}
		return m_PlishedAttrId[Index];
	}
	void SetPlishedAttrId( const vector<BagExtraAttrIdObjWraper>& v )
	{
		m_PlishedAttrId=v;
	}
	void ClearPlishedAttrId( )
	{
		m_PlishedAttrId.clear();
	}
	void SetPlishedAttrId( int Index, const BagExtraAttrIdObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_PlishedAttrId.size())
		{
			assert(false);
			return;
		}
		m_PlishedAttrId[Index] = v;
	}
	void AddPlishedAttrId( const BagExtraAttrIdObjWraper& v )
	{
		m_PlishedAttrId.push_back(v);
	}
private:
	//宝石数组
	vector<BagGemObjWraper> m_GemArray;
public:
	int SizeGemArray()
	{
		return m_GemArray.size();
	}
	const vector<BagGemObjWraper>& GetGemArray() const
	{
		return m_GemArray;
	}
	BagGemObjWraper GetGemArray(int Index) const
	{
		if(Index<0 || Index>=(int)m_GemArray.size())
		{
			assert(false);
			return BagGemObjWraper();
		}
		return m_GemArray[Index];
	}
	void SetGemArray( const vector<BagGemObjWraper>& v )
	{
		m_GemArray=v;
	}
	void ClearGemArray( )
	{
		m_GemArray.clear();
	}
	void SetGemArray( int Index, const BagGemObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_GemArray.size())
		{
			assert(false);
			return;
		}
		m_GemArray[Index] = v;
	}
	void AddGemArray( const BagGemObjWraper& v )
	{
		m_GemArray.push_back(v);
	}
private:
	//基础属性洗炼结果
	vector<BagAttrIntObjWraper> m_PolishedBaseAttrResult;
public:
	int SizePolishedBaseAttrResult()
	{
		return m_PolishedBaseAttrResult.size();
	}
	const vector<BagAttrIntObjWraper>& GetPolishedBaseAttrResult() const
	{
		return m_PolishedBaseAttrResult;
	}
	BagAttrIntObjWraper GetPolishedBaseAttrResult(int Index) const
	{
		if(Index<0 || Index>=(int)m_PolishedBaseAttrResult.size())
		{
			assert(false);
			return BagAttrIntObjWraper();
		}
		return m_PolishedBaseAttrResult[Index];
	}
	void SetPolishedBaseAttrResult( const vector<BagAttrIntObjWraper>& v )
	{
		m_PolishedBaseAttrResult=v;
	}
	void ClearPolishedBaseAttrResult( )
	{
		m_PolishedBaseAttrResult.clear();
	}
	void SetPolishedBaseAttrResult( int Index, const BagAttrIntObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_PolishedBaseAttrResult.size())
		{
			assert(false);
			return;
		}
		m_PolishedBaseAttrResult[Index] = v;
	}
	void AddPolishedBaseAttrResult( const BagAttrIntObjWraper& v )
	{
		m_PolishedBaseAttrResult.push_back(v);
	}
private:
	//模板id
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
private:
	//宝石组合id
	INT32 m_GemSuitId;
public:
	void SetGemSuitId( INT32 v)
	{
		m_GemSuitId=v;
	}
	INT32 GetGemSuitId()
	{
		return m_GemSuitId;
	}
	INT32 GetGemSuitId() const
	{
		return m_GemSuitId;
	}
private:
	//装备评分
	INT32 m_EquipScore;
public:
	void SetEquipScore( INT32 v)
	{
		m_EquipScore=v;
	}
	INT32 GetEquipScore()
	{
		return m_EquipScore;
	}
	INT32 GetEquipScore() const
	{
		return m_EquipScore;
	}
private:
	//洗炼装备评分
	INT32 m_PolishedEquipScore;
public:
	void SetPolishedEquipScore( INT32 v)
	{
		m_PolishedEquipScore=v;
	}
	INT32 GetPolishedEquipScore()
	{
		return m_PolishedEquipScore;
	}
	INT32 GetPolishedEquipScore() const
	{
		return m_PolishedEquipScore;
	}
private:
	//基础属性洗炼初始属性
	vector<BagAttrIntObjWraper> m_BaseAttrPolishedInitAttr;
public:
	int SizeBaseAttrPolishedInitAttr()
	{
		return m_BaseAttrPolishedInitAttr.size();
	}
	const vector<BagAttrIntObjWraper>& GetBaseAttrPolishedInitAttr() const
	{
		return m_BaseAttrPolishedInitAttr;
	}
	BagAttrIntObjWraper GetBaseAttrPolishedInitAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_BaseAttrPolishedInitAttr.size())
		{
			assert(false);
			return BagAttrIntObjWraper();
		}
		return m_BaseAttrPolishedInitAttr[Index];
	}
	void SetBaseAttrPolishedInitAttr( const vector<BagAttrIntObjWraper>& v )
	{
		m_BaseAttrPolishedInitAttr=v;
	}
	void ClearBaseAttrPolishedInitAttr( )
	{
		m_BaseAttrPolishedInitAttr.clear();
	}
	void SetBaseAttrPolishedInitAttr( int Index, const BagAttrIntObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_BaseAttrPolishedInitAttr.size())
		{
			assert(false);
			return;
		}
		m_BaseAttrPolishedInitAttr[Index] = v;
	}
	void AddBaseAttrPolishedInitAttr( const BagAttrIntObjWraper& v )
	{
		m_BaseAttrPolishedInitAttr.push_back(v);
	}

};
//世界Boss对象封装类
class WorldBossObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldBossObjWraper()
	{
		
		m_DungeonId = -1;
		m_MonsterId = -1;
		m_CurHP = -1;
		m_IsDead = false;
		m_Level = 1;

	}
	//赋值构造函数
	WorldBossObjWraper(const WorldBossObj& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldBossObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldBossObj ToPB() const
	{
		WorldBossObj v;
		v.set_dungeonid( m_DungeonId );
		v.set_monsterid( m_MonsterId );
		v.set_curhp( m_CurHP );
		v.set_isdead( m_IsDead );
		v.set_level( m_Level );

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
		WorldBossObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DungeonId(副本Id) [sint32]</li>\r\n";
		htmlBuff += "<li>MonsterId(怪物配置Id) [sint32]</li>\r\n";
		htmlBuff += "<li>CurHP(当前血量) [sint32]</li>\r\n";
		htmlBuff += "<li>IsDead(是否死亡) [bool]</li>\r\n";
		htmlBuff += "<li>Level(Boss等级) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>DungeonId：%di</li>\r\n",m_DungeonId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MonsterId：%di</li>\r\n",m_MonsterId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CurHP：%di</li>\r\n",m_CurHP);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsDead：%di</li>\r\n",m_IsDead);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const WorldBossObj& v)
	{
		m_DungeonId = v.dungeonid();
		m_MonsterId = v.monsterid();
		m_CurHP = v.curhp();
		m_IsDead = v.isdead();
		m_Level = v.level();

	}

private:
	//副本Id
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
	//怪物配置Id
	INT32 m_MonsterId;
public:
	void SetMonsterId( INT32 v)
	{
		m_MonsterId=v;
	}
	INT32 GetMonsterId()
	{
		return m_MonsterId;
	}
	INT32 GetMonsterId() const
	{
		return m_MonsterId;
	}
private:
	//当前血量
	INT32 m_CurHP;
public:
	void SetCurHP( INT32 v)
	{
		m_CurHP=v;
	}
	INT32 GetCurHP()
	{
		return m_CurHP;
	}
	INT32 GetCurHP() const
	{
		return m_CurHP;
	}
private:
	//是否死亡
	bool m_IsDead;
public:
	void SetIsDead( bool v)
	{
		m_IsDead=v;
	}
	bool GetIsDead()
	{
		return m_IsDead;
	}
	bool GetIsDead() const
	{
		return m_IsDead;
	}
private:
	//Boss等级
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

};
//世界Boss排行封装类
class WorldBossRankObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldBossRankObjWraper()
	{
		
		m_Rank = 0;
		m_UserId = -1;
		m_UserName = "";
		m_Level = 0;
		m_Hurt = 0;

	}
	//赋值构造函数
	WorldBossRankObjWraper(const WorldBossRankObj& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldBossRankObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldBossRankObj ToPB() const
	{
		WorldBossRankObj v;
		v.set_rank( m_Rank );
		v.set_userid( m_UserId );
		v.set_username( m_UserName );
		v.set_level( m_Level );
		v.set_hurt( m_Hurt );

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
		WorldBossRankObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Rank(排名) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>UserName(玩家名字) [string]</li>\r\n";
		htmlBuff += "<li>Level(玩家等级) [sint32]</li>\r\n";
		htmlBuff += "<li>Hurt(伤害) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Rank：%di</li>\r\n",m_Rank);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>UserName：\""+m_UserName+"\"</li>\r\n";
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Hurt：%di</li>\r\n",m_Hurt);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const WorldBossRankObj& v)
	{
		m_Rank = v.rank();
		m_UserId = v.userid();
		m_UserName = v.username();
		m_Level = v.level();
		m_Hurt = v.hurt();

	}

private:
	//排名
	INT32 m_Rank;
public:
	void SetRank( INT32 v)
	{
		m_Rank=v;
	}
	INT32 GetRank()
	{
		return m_Rank;
	}
	INT32 GetRank() const
	{
		return m_Rank;
	}
private:
	//用户ID
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
	//玩家名字
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
	//玩家等级
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
	//伤害
	INT32 m_Hurt;
public:
	void SetHurt( INT32 v)
	{
		m_Hurt=v;
	}
	INT32 GetHurt()
	{
		return m_Hurt;
	}
	INT32 GetHurt() const
	{
		return m_Hurt;
	}

};
//键值对封装类
class KeyValue2Wraper : public DataWraperInterface 
{
public:
	//构造函数
	KeyValue2Wraper()
	{
		
		m_Key = -1;
		m_Value = -1;

	}
	//赋值构造函数
	KeyValue2Wraper(const KeyValue2& v){ Init(v); }
	//等号重载函数
	void operator = (const KeyValue2& v){ Init(v); }
 	//转化成Protobuffer类型函数
	KeyValue2 ToPB() const
	{
		KeyValue2 v;
		v.set_key( m_Key );
		v.set_value( m_Value );

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
		KeyValue2 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Key(键) [sint32]</li>\r\n";
		htmlBuff += "<li>Value(值) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Key：%di</li>\r\n",m_Key);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Value：%.2ff</li>\r\n",m_Value);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const KeyValue2& v)
	{
		m_Key = v.key();
		m_Value = v.value();

	}

private:
	//键
	INT32 m_Key;
public:
	void SetKey( INT32 v)
	{
		m_Key=v;
	}
	INT32 GetKey()
	{
		return m_Key;
	}
	INT32 GetKey() const
	{
		return m_Key;
	}
private:
	//值
	float m_Value;
public:
	void SetValue( float v)
	{
		m_Value=v;
	}
	float GetValue()
	{
		return m_Value;
	}
	float GetValue() const
	{
		return m_Value;
	}

};
//键值对封装类
class KeyValue2IntBoolWraper : public DataWraperInterface 
{
public:
	//构造函数
	KeyValue2IntBoolWraper()
	{
		
		m_Key = -1;
		m_Value = false;

	}
	//赋值构造函数
	KeyValue2IntBoolWraper(const KeyValue2IntBool& v){ Init(v); }
	//等号重载函数
	void operator = (const KeyValue2IntBool& v){ Init(v); }
 	//转化成Protobuffer类型函数
	KeyValue2IntBool ToPB() const
	{
		KeyValue2IntBool v;
		v.set_key( m_Key );
		v.set_value( m_Value );

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
		KeyValue2IntBool pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Key(键) [sint32]</li>\r\n";
		htmlBuff += "<li>Value(值) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Key：%di</li>\r\n",m_Key);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Value：%di</li>\r\n",m_Value);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const KeyValue2IntBool& v)
	{
		m_Key = v.key();
		m_Value = v.value();

	}

private:
	//键
	INT32 m_Key;
public:
	void SetKey( INT32 v)
	{
		m_Key=v;
	}
	INT32 GetKey()
	{
		return m_Key;
	}
	INT32 GetKey() const
	{
		return m_Key;
	}
private:
	//值
	bool m_Value;
public:
	void SetValue( bool v)
	{
		m_Value=v;
	}
	bool GetValue()
	{
		return m_Value;
	}
	bool GetValue() const
	{
		return m_Value;
	}

};
//装备技能或BUFF信息封装类
class EquipSkillBuff2Wraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipSkillBuff2Wraper()
	{
		
		m_Id = -1;
		m_LV = -1;
		m_Cd = -1;

	}
	//赋值构造函数
	EquipSkillBuff2Wraper(const EquipSkillBuff2& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipSkillBuff2& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipSkillBuff2 ToPB() const
	{
		EquipSkillBuff2 v;
		v.set_id( m_Id );
		v.set_lv( m_LV );
		v.set_cd( m_Cd );

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
		EquipSkillBuff2 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Id(ID) [sint32]</li>\r\n";
		htmlBuff += "<li>LV(等级) [sint32]</li>\r\n";
		htmlBuff += "<li>Cd(CD) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>LV：%di</li>\r\n",m_LV);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Cd：%di</li>\r\n",m_Cd);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const EquipSkillBuff2& v)
	{
		m_Id = v.id();
		m_LV = v.lv();
		m_Cd = v.cd();

	}

private:
	//ID
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//等级
	INT32 m_LV;
public:
	void SetLV( INT32 v)
	{
		m_LV=v;
	}
	INT32 GetLV()
	{
		return m_LV;
	}
	INT32 GetLV() const
	{
		return m_LV;
	}
private:
	//CD
	INT32 m_Cd;
public:
	void SetCd( INT32 v)
	{
		m_Cd=v;
	}
	INT32 GetCd()
	{
		return m_Cd;
	}
	INT32 GetCd() const
	{
		return m_Cd;
	}

};
//活动NPC数据封装类
class ActivityNpcDataWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityNpcDataWraper()
	{
		
		m_DungeonId = -1;
		m_PosInfo = "";
		m_NPCId = -1;
		m_ObjId = -1;

	}
	//赋值构造函数
	ActivityNpcDataWraper(const ActivityNpcData& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityNpcData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityNpcData ToPB() const
	{
		ActivityNpcData v;
		v.set_dungeonid( m_DungeonId );
		v.set_posinfo( m_PosInfo );
		v.set_npcid( m_NPCId );
		v.set_objid( m_ObjId );

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
		ActivityNpcData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DungeonId(DungeonId) [sint32]</li>\r\n";
		htmlBuff += "<li>PosInfo(位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>NPCId(NPCId) [sint32]</li>\r\n";
		htmlBuff += "<li>ObjId(ObjId) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>DungeonId：%di</li>\r\n",m_DungeonId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PosInfo：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>NPCId：%di</li>\r\n",m_NPCId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityNpcData& v)
	{
		m_DungeonId = v.dungeonid();
		m_PosInfo = v.posinfo();
		m_NPCId = v.npcid();
		m_ObjId = v.objid();

	}

private:
	//DungeonId
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
	//位置信息
	string m_PosInfo;
public:
	void SetPosInfo( const string& v)
	{
		m_PosInfo=v;
	}
	string GetPosInfo()
	{
		return m_PosInfo;
	}
	string GetPosInfo() const
	{
		return m_PosInfo;
	}
private:
	//NPCId
	INT32 m_NPCId;
public:
	void SetNPCId( INT32 v)
	{
		m_NPCId=v;
	}
	INT32 GetNPCId()
	{
		return m_NPCId;
	}
	INT32 GetNPCId() const
	{
		return m_NPCId;
	}
private:
	//ObjId
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}

};

#endif
