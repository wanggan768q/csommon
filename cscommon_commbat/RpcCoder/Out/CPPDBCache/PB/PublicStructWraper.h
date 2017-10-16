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

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>AttrValue：%.2ff</li>\r\n",m_AttrValue);

		
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

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Value：%.2ff</li>\r\n",m_Value);

		
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

#endif
