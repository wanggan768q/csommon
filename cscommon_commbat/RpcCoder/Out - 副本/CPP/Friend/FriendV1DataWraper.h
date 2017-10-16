/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperFriend.h
* Author:       甘业清
* Description:  好友同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_FRIEND_H
#define __SYNC_WRAPER_FRIEND_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "FriendV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//好友对象封装类
class FriendFriendObjWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	FriendFriendObjWraperV1()
	{
		
		m_UserId = -1;
		m_UserName = "";
		m_Level = -1;
		m_Prof = -1;
		m_Signature = "";
		m_TeamId = -1;
		m_TeamMemberNum = 0;
		m_Online = false;
		m_GoodFeeling = 0;
		m_GuildId = -1;
		m_GuildName = "";

	}
	//赋值构造函数
	FriendFriendObjWraperV1(const FriendFriendObjV1& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendFriendObjV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendFriendObjV1 ToPB() const
	{
		FriendFriendObjV1 v;
		v.set_userid( m_UserId );
		v.set_username( m_UserName );
		v.set_level( m_Level );
		v.set_prof( m_Prof );
		v.set_signature( m_Signature );
		v.set_teamid( m_TeamId );
		v.set_teammembernum( m_TeamMemberNum );
		v.set_online( m_Online );
		v.set_goodfeeling( m_GoodFeeling );
		v.set_guildid( m_GuildId );
		v.set_guildname( m_GuildName );

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
		FriendFriendObjV1 pb;
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
		htmlBuff += "<li>Signature(签名) [string]</li>\r\n";
		htmlBuff += "<li>TeamId(队伍Id) [sint32]</li>\r\n";
		htmlBuff += "<li>TeamMemberNum(队伍当前人数) [sint32]</li>\r\n";
		htmlBuff += "<li>Online(是否在线) [bool]</li>\r\n";
		htmlBuff += "<li>GoodFeeling(好感度) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildId(帮会id) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildName(帮会名字) [string]</li>\r\n";

		
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
		htmlBuff += "<li>Signature：\""+m_Signature+"\"</li>\r\n";
		tmpLine.Fmt("<li>TeamId：%di</li>\r\n",m_TeamId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TeamMemberNum：%di</li>\r\n",m_TeamMemberNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Online：%di</li>\r\n",m_Online);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GoodFeeling：%di</li>\r\n",m_GoodFeeling);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GuildId：%di</li>\r\n",m_GuildId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>GuildName：\""+m_GuildName+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FriendFriendObjV1& v)
	{
		m_UserId = v.userid();
		m_UserName = v.username();
		m_Level = v.level();
		m_Prof = v.prof();
		m_Signature = v.signature();
		m_TeamId = v.teamid();
		m_TeamMemberNum = v.teammembernum();
		m_Online = v.online();
		m_GoodFeeling = v.goodfeeling();
		m_GuildId = v.guildid();
		m_GuildName = v.guildname();

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
	//签名
	string m_Signature;
public:
	void SetSignature( const string& v)
	{
		m_Signature=v;
	}
	string GetSignature()
	{
		return m_Signature;
	}
	string GetSignature() const
	{
		return m_Signature;
	}
private:
	//队伍Id
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
	//队伍当前人数
	INT32 m_TeamMemberNum;
public:
	void SetTeamMemberNum( INT32 v)
	{
		m_TeamMemberNum=v;
	}
	INT32 GetTeamMemberNum()
	{
		return m_TeamMemberNum;
	}
	INT32 GetTeamMemberNum() const
	{
		return m_TeamMemberNum;
	}
private:
	//是否在线
	bool m_Online;
public:
	void SetOnline( bool v)
	{
		m_Online=v;
	}
	bool GetOnline()
	{
		return m_Online;
	}
	bool GetOnline() const
	{
		return m_Online;
	}
private:
	//好感度
	INT32 m_GoodFeeling;
public:
	void SetGoodFeeling( INT32 v)
	{
		m_GoodFeeling=v;
	}
	INT32 GetGoodFeeling()
	{
		return m_GoodFeeling;
	}
	INT32 GetGoodFeeling() const
	{
		return m_GoodFeeling;
	}
private:
	//帮会id
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
private:
	//帮会名字
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

};
//好友数据封装类
class FriendFriendDataWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<FriendFriendDataWraperV1>
{
public:
	//构造函数
	FriendFriendDataWraperV1()
	{
		SetDataWraper( this );


	}
	//赋值构造函数
	FriendFriendDataWraperV1(const FriendFriendDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendFriendDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendFriendDataV1 ToPB() const
	{
		FriendFriendDataV1 v;
		v.mutable_friendlist()->Reserve(m_FriendList.size());
		for (int i=0; i<(int)m_FriendList.size(); i++)
		{
			*v.add_friendlist() = m_FriendList[i].ToPB();
		}
		v.mutable_blacklist()->Reserve(m_BlackList.size());
		for (int i=0; i<(int)m_BlackList.size(); i++)
		{
			*v.add_blacklist() = m_BlackList[i].ToPB();
		}
		v.mutable_contactslist()->Reserve(m_ContactsList.size());
		for (int i=0; i<(int)m_ContactsList.size(); i++)
		{
			*v.add_contactslist() = m_ContactsList[i].ToPB();
		}
		v.mutable_strangerfriendlist()->Reserve(m_StrangerFriendList.size());
		for (int i=0; i<(int)m_StrangerFriendList.size(); i++)
		{
			v.add_strangerfriendlist(m_StrangerFriendList[i]);
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
		FriendFriendDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>FriendList(好友列表) [FriendObj] Array</li>\r\n";
		htmlBuff += "<li>BlackList(黑名单) [FriendObj] Array</li>\r\n";
		htmlBuff += "<li>ContactsList(最近联系人) [FriendObj] Array</li>\r\n";
		htmlBuff += "<li>StrangerFriendList(加过我的人) [sint64] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>FriendList：</li>\r\n";
		if( m_FriendList.size()>0) htmlBuff += m_FriendList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_FriendList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_FriendList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>BlackList：</li>\r\n";
		if( m_BlackList.size()>0) htmlBuff += m_BlackList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_BlackList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_BlackList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>ContactsList：</li>\r\n";
		if( m_ContactsList.size()>0) htmlBuff += m_ContactsList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ContactsList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ContactsList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>StrangerFriendList：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_StrangerFriendList.size(); i++){
			tmpLine.Fmt("<td>%lldL</td>\r\n",m_StrangerFriendList[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_StrangerFriendList.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FriendFriendDataV1& v)
	{
		m_FriendList.clear();
		m_FriendList.reserve(v.friendlist_size());
		for( int i=0; i<v.friendlist_size(); i++)
			m_FriendList.push_back(v.friendlist(i));
		m_BlackList.clear();
		m_BlackList.reserve(v.blacklist_size());
		for( int i=0; i<v.blacklist_size(); i++)
			m_BlackList.push_back(v.blacklist(i));
		m_ContactsList.clear();
		m_ContactsList.reserve(v.contactslist_size());
		for( int i=0; i<v.contactslist_size(); i++)
			m_ContactsList.push_back(v.contactslist(i));
		m_StrangerFriendList.clear();
		m_StrangerFriendList.reserve(v.strangerfriendlist_size());
		for( int i=0; i<v.strangerfriendlist_size(); i++)
			m_StrangerFriendList.push_back(v.strangerfriendlist(i));

	}

private:
	//好友列表
	vector<FriendFriendObjWraperV1> m_FriendList;
public:
	int SizeFriendList()
	{
		return m_FriendList.size();
	}
	const vector<FriendFriendObjWraperV1>& GetFriendList() const
	{
		return m_FriendList;
	}
	FriendFriendObjWraperV1 GetFriendList(int Index) const
	{
		if(Index<0 || Index>=(int)m_FriendList.size())
		{
			assert(false);
			return FriendFriendObjWraperV1();
		}
		return m_FriendList[Index];
	}
	void SetFriendList( const vector<FriendFriendObjWraperV1>& v )
	{
		m_FriendList=v;
	}
	void ClearFriendList( )
	{
		m_FriendList.clear();
	}
	void SetFriendList( int Index, const FriendFriendObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_FriendList.size())
		{
			assert(false);
			return;
		}
		m_FriendList[Index] = v;
	}
	void AddFriendList( const FriendFriendObjWraperV1& v )
	{
		m_FriendList.push_back(v);
	}
private:
	//黑名单
	vector<FriendFriendObjWraperV1> m_BlackList;
public:
	int SizeBlackList()
	{
		return m_BlackList.size();
	}
	const vector<FriendFriendObjWraperV1>& GetBlackList() const
	{
		return m_BlackList;
	}
	FriendFriendObjWraperV1 GetBlackList(int Index) const
	{
		if(Index<0 || Index>=(int)m_BlackList.size())
		{
			assert(false);
			return FriendFriendObjWraperV1();
		}
		return m_BlackList[Index];
	}
	void SetBlackList( const vector<FriendFriendObjWraperV1>& v )
	{
		m_BlackList=v;
	}
	void ClearBlackList( )
	{
		m_BlackList.clear();
	}
	void SetBlackList( int Index, const FriendFriendObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_BlackList.size())
		{
			assert(false);
			return;
		}
		m_BlackList[Index] = v;
	}
	void AddBlackList( const FriendFriendObjWraperV1& v )
	{
		m_BlackList.push_back(v);
	}
private:
	//最近联系人
	vector<FriendFriendObjWraperV1> m_ContactsList;
public:
	int SizeContactsList()
	{
		return m_ContactsList.size();
	}
	const vector<FriendFriendObjWraperV1>& GetContactsList() const
	{
		return m_ContactsList;
	}
	FriendFriendObjWraperV1 GetContactsList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ContactsList.size())
		{
			assert(false);
			return FriendFriendObjWraperV1();
		}
		return m_ContactsList[Index];
	}
	void SetContactsList( const vector<FriendFriendObjWraperV1>& v )
	{
		m_ContactsList=v;
	}
	void ClearContactsList( )
	{
		m_ContactsList.clear();
	}
	void SetContactsList( int Index, const FriendFriendObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_ContactsList.size())
		{
			assert(false);
			return;
		}
		m_ContactsList[Index] = v;
	}
	void AddContactsList( const FriendFriendObjWraperV1& v )
	{
		m_ContactsList.push_back(v);
	}
private:
	//加过我的人
	vector<INT64> m_StrangerFriendList;
public:
	int SizeStrangerFriendList()
	{
		return m_StrangerFriendList.size();
	}
	const vector<INT64>& GetStrangerFriendList() const
	{
		return m_StrangerFriendList;
	}
	INT64 GetStrangerFriendList(int Index) const
	{
		if(Index<0 || Index>=(int)m_StrangerFriendList.size())
		{
			assert(false);
			return INT64();
		}
		return m_StrangerFriendList[Index];
	}
	void SetStrangerFriendList( const vector<INT64>& v )
	{
		m_StrangerFriendList=v;
	}
	void ClearStrangerFriendList( )
	{
		m_StrangerFriendList.clear();
	}
	void SetStrangerFriendList( int Index, INT64 v )
	{
		if(Index<0 || Index>=(int)m_StrangerFriendList.size())
		{
			assert(false);
			return;
		}
		m_StrangerFriendList[Index] = v;
	}
	void AddStrangerFriendList( INT64 v = -1 )
	{
		m_StrangerFriendList.push_back(v);
	}

};

#endif
