/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperOnlineData.h
* Author:       甘业清
* Description:  在线数据同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_ONLINEDATA_H
#define __SYNC_WRAPER_ONLINEDATA_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "OnlineDataV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//角色属性对象封装类
class OnlineDataRoleAttrObjWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	OnlineDataRoleAttrObjWraperV1()
	{
		
		m_Id = -1;
		m_Value = -1;

	}
	//赋值构造函数
	OnlineDataRoleAttrObjWraperV1(const OnlineDataRoleAttrObjV1& v){ Init(v); }
	//等号重载函数
	void operator = (const OnlineDataRoleAttrObjV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OnlineDataRoleAttrObjV1 ToPB() const
	{
		OnlineDataRoleAttrObjV1 v;
		v.set_id( m_Id );
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
		OnlineDataRoleAttrObjV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Id(属性Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Value(值) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Value：%.2ff</li>\r\n",m_Value);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OnlineDataRoleAttrObjV1& v)
	{
		m_Id = v.id();
		m_Value = v.value();

	}

private:
	//属性Id
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
//在线数据封装类
class OnlineDataOnlineDataWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<OnlineDataOnlineDataWraperV1>
{
public:
	//构造函数
	OnlineDataOnlineDataWraperV1()
	{
		SetDataWraper( this );

		m_RecommendFriendOffset = 0;
		m_RecommendFriendFlushTime = -1;
		m_FollowWho = -1;
		m_ThiefObjId = -1;

	}
	//赋值构造函数
	OnlineDataOnlineDataWraperV1(const OnlineDataOnlineDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const OnlineDataOnlineDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OnlineDataOnlineDataV1 ToPB() const
	{
		OnlineDataOnlineDataV1 v;
		v.mutable_bagrecyclebin()->Reserve(m_BagRecycleBin.size());
		for (int i=0; i<(int)m_BagRecycleBin.size(); i++)
		{
			*v.add_bagrecyclebin() = m_BagRecycleBin[i].ToPB();
		}
		v.mutable_roleattr()->Reserve(m_RoleAttr.size());
		for (int i=0; i<(int)m_RoleAttr.size(); i++)
		{
			*v.add_roleattr() = m_RoleAttr[i].ToPB();
		}
		v.set_recommendfriendoffset( m_RecommendFriendOffset );
		v.set_recommendfriendflushtime( m_RecommendFriendFlushTime );
		v.mutable_recommendfriendlastlist()->Reserve(m_RecommendFriendLastList.size());
		for (int i=0; i<(int)m_RecommendFriendLastList.size(); i++)
		{
			v.add_recommendfriendlastlist(m_RecommendFriendLastList[i]);
		}
		v.mutable_followmeuserid()->Reserve(m_FollowmeUserId.size());
		for (int i=0; i<(int)m_FollowmeUserId.size(); i++)
		{
			v.add_followmeuserid(m_FollowmeUserId[i]);
		}
		v.set_followwho( m_FollowWho );
		v.set_thiefobjid( m_ThiefObjId );

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
		OnlineDataOnlineDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>BagRecycleBin(回收站) [BagRecycleGridObj] Array</li>\r\n";
		htmlBuff += "<li>RoleAttr(角色属性) [RoleAttrObj] Array</li>\r\n";
		htmlBuff += "<li>RecommendFriendOffset(推荐好友偏移) [sint32]</li>\r\n";
		htmlBuff += "<li>RecommendFriendFlushTime(推荐好友刷新时间) [sint32]</li>\r\n";
		htmlBuff += "<li>RecommendFriendLastList(上次推荐的好友) [sint64] Array</li>\r\n";
		htmlBuff += "<li>FollowmeUserId(跟随我的人) [sint64] Array</li>\r\n";
		htmlBuff += "<li>FollowWho(跟随谁) [sint64]</li>\r\n";
		htmlBuff += "<li>ThiefObjId(江洋大盗) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>BagRecycleBin：</li>\r\n";
		if( m_BagRecycleBin.size()>0) htmlBuff += m_BagRecycleBin[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_BagRecycleBin.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_BagRecycleBin[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>RoleAttr：</li>\r\n";
		if( m_RoleAttr.size()>0) htmlBuff += m_RoleAttr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_RoleAttr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_RoleAttr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>RecommendFriendOffset：%di</li>\r\n",m_RecommendFriendOffset);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RecommendFriendFlushTime：%di</li>\r\n",m_RecommendFriendFlushTime);
		htmlBuff += tmpLine;
		htmlBuff += "<li>RecommendFriendLastList：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_RecommendFriendLastList.size(); i++){
			tmpLine.Fmt("<td>%lldL</td>\r\n",m_RecommendFriendLastList[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_RecommendFriendLastList.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		htmlBuff += "<li>FollowmeUserId：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_FollowmeUserId.size(); i++){
			tmpLine.Fmt("<td>%lldL</td>\r\n",m_FollowmeUserId[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_FollowmeUserId.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>FollowWho：%lldL</li>\r\n",m_FollowWho);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ThiefObjId：%lldL</li>\r\n",m_ThiefObjId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OnlineDataOnlineDataV1& v)
	{
		m_BagRecycleBin.clear();
		m_BagRecycleBin.reserve(v.bagrecyclebin_size());
		for( int i=0; i<v.bagrecyclebin_size(); i++)
			m_BagRecycleBin.push_back(v.bagrecyclebin(i));
		m_RoleAttr.clear();
		m_RoleAttr.reserve(v.roleattr_size());
		for( int i=0; i<v.roleattr_size(); i++)
			m_RoleAttr.push_back(v.roleattr(i));
		m_RecommendFriendOffset = v.recommendfriendoffset();
		m_RecommendFriendFlushTime = v.recommendfriendflushtime();
		m_RecommendFriendLastList.clear();
		m_RecommendFriendLastList.reserve(v.recommendfriendlastlist_size());
		for( int i=0; i<v.recommendfriendlastlist_size(); i++)
			m_RecommendFriendLastList.push_back(v.recommendfriendlastlist(i));
		m_FollowmeUserId.clear();
		m_FollowmeUserId.reserve(v.followmeuserid_size());
		for( int i=0; i<v.followmeuserid_size(); i++)
			m_FollowmeUserId.push_back(v.followmeuserid(i));
		m_FollowWho = v.followwho();
		m_ThiefObjId = v.thiefobjid();

	}

private:
	//回收站
	vector<BagRecycleGridObjWraper> m_BagRecycleBin;
public:
	int SizeBagRecycleBin()
	{
		return m_BagRecycleBin.size();
	}
	const vector<BagRecycleGridObjWraper>& GetBagRecycleBin() const
	{
		return m_BagRecycleBin;
	}
	BagRecycleGridObjWraper GetBagRecycleBin(int Index) const
	{
		if(Index<0 || Index>=(int)m_BagRecycleBin.size())
		{
			assert(false);
			return BagRecycleGridObjWraper();
		}
		return m_BagRecycleBin[Index];
	}
	void SetBagRecycleBin( const vector<BagRecycleGridObjWraper>& v )
	{
		m_BagRecycleBin=v;
	}
	void ClearBagRecycleBin( )
	{
		m_BagRecycleBin.clear();
	}
	void SetBagRecycleBin( int Index, const BagRecycleGridObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_BagRecycleBin.size())
		{
			assert(false);
			return;
		}
		m_BagRecycleBin[Index] = v;
	}
	void AddBagRecycleBin( const BagRecycleGridObjWraper& v )
	{
		m_BagRecycleBin.push_back(v);
	}
private:
	//角色属性
	vector<OnlineDataRoleAttrObjWraperV1> m_RoleAttr;
public:
	int SizeRoleAttr()
	{
		return m_RoleAttr.size();
	}
	const vector<OnlineDataRoleAttrObjWraperV1>& GetRoleAttr() const
	{
		return m_RoleAttr;
	}
	OnlineDataRoleAttrObjWraperV1 GetRoleAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_RoleAttr.size())
		{
			assert(false);
			return OnlineDataRoleAttrObjWraperV1();
		}
		return m_RoleAttr[Index];
	}
	void SetRoleAttr( const vector<OnlineDataRoleAttrObjWraperV1>& v )
	{
		m_RoleAttr=v;
	}
	void ClearRoleAttr( )
	{
		m_RoleAttr.clear();
	}
	void SetRoleAttr( int Index, const OnlineDataRoleAttrObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_RoleAttr.size())
		{
			assert(false);
			return;
		}
		m_RoleAttr[Index] = v;
	}
	void AddRoleAttr( const OnlineDataRoleAttrObjWraperV1& v )
	{
		m_RoleAttr.push_back(v);
	}
private:
	//推荐好友偏移
	INT32 m_RecommendFriendOffset;
public:
	void SetRecommendFriendOffset( INT32 v)
	{
		m_RecommendFriendOffset=v;
	}
	INT32 GetRecommendFriendOffset()
	{
		return m_RecommendFriendOffset;
	}
	INT32 GetRecommendFriendOffset() const
	{
		return m_RecommendFriendOffset;
	}
private:
	//推荐好友刷新时间
	INT32 m_RecommendFriendFlushTime;
public:
	void SetRecommendFriendFlushTime( INT32 v)
	{
		m_RecommendFriendFlushTime=v;
	}
	INT32 GetRecommendFriendFlushTime()
	{
		return m_RecommendFriendFlushTime;
	}
	INT32 GetRecommendFriendFlushTime() const
	{
		return m_RecommendFriendFlushTime;
	}
private:
	//上次推荐的好友
	vector<INT64> m_RecommendFriendLastList;
public:
	int SizeRecommendFriendLastList()
	{
		return m_RecommendFriendLastList.size();
	}
	const vector<INT64>& GetRecommendFriendLastList() const
	{
		return m_RecommendFriendLastList;
	}
	INT64 GetRecommendFriendLastList(int Index) const
	{
		if(Index<0 || Index>=(int)m_RecommendFriendLastList.size())
		{
			assert(false);
			return INT64();
		}
		return m_RecommendFriendLastList[Index];
	}
	void SetRecommendFriendLastList( const vector<INT64>& v )
	{
		m_RecommendFriendLastList=v;
	}
	void ClearRecommendFriendLastList( )
	{
		m_RecommendFriendLastList.clear();
	}
	void SetRecommendFriendLastList( int Index, INT64 v )
	{
		if(Index<0 || Index>=(int)m_RecommendFriendLastList.size())
		{
			assert(false);
			return;
		}
		m_RecommendFriendLastList[Index] = v;
	}
	void AddRecommendFriendLastList( INT64 v = -1 )
	{
		m_RecommendFriendLastList.push_back(v);
	}
private:
	//跟随我的人
	vector<INT64> m_FollowmeUserId;
public:
	int SizeFollowmeUserId()
	{
		return m_FollowmeUserId.size();
	}
	const vector<INT64>& GetFollowmeUserId() const
	{
		return m_FollowmeUserId;
	}
	INT64 GetFollowmeUserId(int Index) const
	{
		if(Index<0 || Index>=(int)m_FollowmeUserId.size())
		{
			assert(false);
			return INT64();
		}
		return m_FollowmeUserId[Index];
	}
	void SetFollowmeUserId( const vector<INT64>& v )
	{
		m_FollowmeUserId=v;
	}
	void ClearFollowmeUserId( )
	{
		m_FollowmeUserId.clear();
	}
	void SetFollowmeUserId( int Index, INT64 v )
	{
		if(Index<0 || Index>=(int)m_FollowmeUserId.size())
		{
			assert(false);
			return;
		}
		m_FollowmeUserId[Index] = v;
	}
	void AddFollowmeUserId( INT64 v = -1 )
	{
		m_FollowmeUserId.push_back(v);
	}
private:
	//跟随谁
	INT64 m_FollowWho;
public:
	void SetFollowWho( INT64 v)
	{
		m_FollowWho=v;
	}
	INT64 GetFollowWho()
	{
		return m_FollowWho;
	}
	INT64 GetFollowWho() const
	{
		return m_FollowWho;
	}
private:
	//江洋大盗
	INT64 m_ThiefObjId;
public:
	void SetThiefObjId( INT64 v)
	{
		m_ThiefObjId=v;
	}
	INT64 GetThiefObjId()
	{
		return m_ThiefObjId;
	}
	INT64 GetThiefObjId() const
	{
		return m_ThiefObjId;
	}

};

#endif
