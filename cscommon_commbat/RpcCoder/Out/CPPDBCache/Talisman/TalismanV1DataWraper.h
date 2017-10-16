/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperTalisman.h
* Author:       甘业清
* Description:  法宝同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_TALISMAN_H
#define __SYNC_WRAPER_TALISMAN_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "TalismanV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//法宝信息封装类
class TalismanFabaoInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	TalismanFabaoInfoWraperV1()
	{
		
		m_ID = -1;
		m_Lv = 1;
		m_IsActived = 0;
		m_Exp = 0;
		m_HitType = -1;

	}
	//赋值构造函数
	TalismanFabaoInfoWraperV1(const TalismanFabaoInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const TalismanFabaoInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TalismanFabaoInfoV1 ToPB() const
	{
		TalismanFabaoInfoV1 v;
		v.set_id( m_ID );
		v.set_lv( m_Lv );
		v.set_isactived( m_IsActived );
		v.mutable_activedcondid()->Reserve(m_ActivedCondID.size());
		for (int i=0; i<(int)m_ActivedCondID.size(); i++)
		{
			v.add_activedcondid(m_ActivedCondID[i]);
		}
		v.set_exp( m_Exp );
		v.set_hittype( m_HitType );

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
		TalismanFabaoInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ID(ID) [sint32]</li>\r\n";
		htmlBuff += "<li>Lv(LV) [sint32]</li>\r\n";
		htmlBuff += "<li>IsActived(是否激活) [sint32]</li>\r\n";
		htmlBuff += "<li>ActivedCondID(已激活的条件ID) [sint32] Array</li>\r\n";
		htmlBuff += "<li>Exp(经验) [sint32]</li>\r\n";
		htmlBuff += "<li>HitType(爆击类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ID：%di</li>\r\n",m_ID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Lv：%di</li>\r\n",m_Lv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsActived：%di</li>\r\n",m_IsActived);
		htmlBuff += tmpLine;
		htmlBuff += "<li>ActivedCondID：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_ActivedCondID.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_ActivedCondID[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_ActivedCondID.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>Exp：%di</li>\r\n",m_Exp);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>HitType：%di</li>\r\n",m_HitType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TalismanFabaoInfoV1& v)
	{
		m_ID = v.id();
		m_Lv = v.lv();
		m_IsActived = v.isactived();
		m_ActivedCondID.clear();
		m_ActivedCondID.reserve(v.activedcondid_size());
		for( int i=0; i<v.activedcondid_size(); i++)
			m_ActivedCondID.push_back(v.activedcondid(i));
		m_Exp = v.exp();
		m_HitType = v.hittype();

	}

private:
	//ID
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}
private:
	//LV
	INT32 m_Lv;
public:
	void SetLv( INT32 v)
	{
		m_Lv=v;
	}
	INT32 GetLv()
	{
		return m_Lv;
	}
	INT32 GetLv() const
	{
		return m_Lv;
	}
private:
	//是否激活
	INT32 m_IsActived;
public:
	void SetIsActived( INT32 v)
	{
		m_IsActived=v;
	}
	INT32 GetIsActived()
	{
		return m_IsActived;
	}
	INT32 GetIsActived() const
	{
		return m_IsActived;
	}
private:
	//已激活的条件ID
	vector<INT32> m_ActivedCondID;
public:
	int SizeActivedCondID()
	{
		return m_ActivedCondID.size();
	}
	const vector<INT32>& GetActivedCondID() const
	{
		return m_ActivedCondID;
	}
	INT32 GetActivedCondID(int Index) const
	{
		if(Index<0 || Index>=(int)m_ActivedCondID.size())
		{
			assert(false);
			return INT32();
		}
		return m_ActivedCondID[Index];
	}
	void SetActivedCondID( const vector<INT32>& v )
	{
		m_ActivedCondID=v;
	}
	void ClearActivedCondID( )
	{
		m_ActivedCondID.clear();
	}
	void SetActivedCondID( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_ActivedCondID.size())
		{
			assert(false);
			return;
		}
		m_ActivedCondID[Index] = v;
	}
	void AddActivedCondID( INT32 v = -1 )
	{
		m_ActivedCondID.push_back(v);
	}
private:
	//经验
	INT32 m_Exp;
public:
	void SetExp( INT32 v)
	{
		m_Exp=v;
	}
	INT32 GetExp()
	{
		return m_Exp;
	}
	INT32 GetExp() const
	{
		return m_Exp;
	}
private:
	//爆击类型
	INT32 m_HitType;
public:
	void SetHitType( INT32 v)
	{
		m_HitType=v;
	}
	INT32 GetHitType()
	{
		return m_HitType;
	}
	INT32 GetHitType() const
	{
		return m_HitType;
	}

};
//法宝数据封装类
class TalismanDataFabaoWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<TalismanDataFabaoWraperV1>
{
public:
	//构造函数
	TalismanDataFabaoWraperV1()
	{
		SetDataWraper( this );


	}
	//赋值构造函数
	TalismanDataFabaoWraperV1(const TalismanDataFabaoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const TalismanDataFabaoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TalismanDataFabaoV1 ToPB() const
	{
		TalismanDataFabaoV1 v;
		v.mutable_fabaoarr()->Reserve(m_FabaoArr.size());
		for (int i=0; i<(int)m_FabaoArr.size(); i++)
		{
			*v.add_fabaoarr() = m_FabaoArr[i].ToPB();
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
		TalismanDataFabaoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>FabaoArr(法宝列表) [FabaoInfo] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>FabaoArr：</li>\r\n";
		if( m_FabaoArr.size()>0) htmlBuff += m_FabaoArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_FabaoArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_FabaoArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TalismanDataFabaoV1& v)
	{
		m_FabaoArr.clear();
		m_FabaoArr.reserve(v.fabaoarr_size());
		for( int i=0; i<v.fabaoarr_size(); i++)
			m_FabaoArr.push_back(v.fabaoarr(i));

	}

private:
	//法宝列表
	vector<TalismanFabaoInfoWraperV1> m_FabaoArr;
public:
	int SizeFabaoArr()
	{
		return m_FabaoArr.size();
	}
	const vector<TalismanFabaoInfoWraperV1>& GetFabaoArr() const
	{
		return m_FabaoArr;
	}
	TalismanFabaoInfoWraperV1 GetFabaoArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_FabaoArr.size())
		{
			assert(false);
			return TalismanFabaoInfoWraperV1();
		}
		return m_FabaoArr[Index];
	}
	void SetFabaoArr( const vector<TalismanFabaoInfoWraperV1>& v )
	{
		m_FabaoArr=v;
	}
	void ClearFabaoArr( )
	{
		m_FabaoArr.clear();
	}
	void SetFabaoArr( int Index, const TalismanFabaoInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_FabaoArr.size())
		{
			assert(false);
			return;
		}
		m_FabaoArr[Index] = v;
	}
	void AddFabaoArr( const TalismanFabaoInfoWraperV1& v )
	{
		m_FabaoArr.push_back(v);
	}

};

#endif
