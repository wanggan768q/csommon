/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperTeam.h
* Author:       甘业清
* Description:  组队RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_TEAM_H
#define __RPC_WRAPER_TEAM_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "TeamRpc.pb.h"



//组队类的枚举定义
enum ConstTeamE
{
	MODULE_ID_TEAM                               = 26,	//组队模块ID
	RPC_CODE_TEAM_CREATETEAM_REQUEST             = 2651,	//组队-->创建队伍-->请求
	RPC_CODE_TEAM_APPLYFORTEAM_REQUEST           = 2652,	//组队-->申请入队-->请求
	RPC_CODE_TEAM_QUITTEAM_NOTIFY                = 2653,	//组队-->离开队伍-->通知
	RPC_CODE_TEAM_BREAKUP_REQUEST                = 2654,	//组队-->解散队伍-->请求
	RPC_CODE_TEAM_INVITETOTEAM_REQUEST           = 2655,	//组队-->邀请入队-->请求
	RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST       = 2656,	//组队-->更改队伍目标-->请求
	RPC_CODE_TEAM_BEINVITEDNOTICE_NOTIFY         = 2657,	//组队-->被邀请入队通知-->通知
	RPC_CODE_TEAM_BEINVITEHANDLE_REQUEST         = 2658,	//组队-->被邀请处理-->请求
	RPC_CODE_TEAM_NEARBYTEAM_REQUEST             = 2659,	//组队-->附近队伍-->请求
	RPC_CODE_TEAM_APPLYNOTICECAPTAIN_NOTIFY      = 2660,	//组队-->申请入队通知,所有人都可以看,但只有队长才能同意-->通知
	RPC_CODE_TEAM_APPLYHANDLEAGREE_REQUEST       = 2661,	//组队-->申请入队,队长同意入队-->请求
	RPC_CODE_TEAM_UPDATEMYTEAMNOTICE_NOTIFY      = 2662,	//组队-->更新我的队伍通知-->通知
	RPC_CODE_TEAM_LEAVETEAMNOTICE_NOTIFY         = 2663,	//组队-->离开队伍通知-->通知
	RPC_CODE_TEAM_BREAKUPNOTICE_NOTIFY           = 2664,	//组队-->解散队伍通知-->通知
	RPC_CODE_TEAM_REQMYTEAMDATA_NOTIFY           = 2665,	//组队-->请求我的队伍数据-->通知
	RPC_CODE_TEAM_DELETEFROMAPPLYLIST_NOTIFY     = 2666,	//组队-->申请列表处理后删除申请的玩家-->通知
	RPC_CODE_TEAM_APPOINTCAPTAIN_REQUEST         = 2667,	//组队-->任命队长-->请求
	RPC_CODE_TEAM_CAPTAINCHANGENOTICE_NOTIFY     = 2668,	//组队-->队长换人通知-->通知
	RPC_CODE_TEAM_TEAMMEMBERHPCHANGENOTICE_NOTIFY= 2669,	//组队-->队员血量变化通知-->通知
	RPC_CODE_TEAM_INVITEHANDLENOTICE_NOTIFY      = 2670,	//组队-->邀请组队的人收到被邀请人的处理通知-->通知
	RPC_CODE_TEAM_NEARBYROLELIST_REQUEST         = 2671,	//组队-->附加玩家列表，邀请时使用-->请求
	RPC_CODE_TEAM_KICKROLE_REQUEST               = 2672,	//组队-->队长踢人-->请求
	RPC_CODE_TEAM_BEINGKICKEDNOTICE_NOTIFY       = 2673,	//组队-->被踢通知-->通知
	RPC_CODE_TEAM_ADDNEWMEMBERNOTICE_NOTIFY      = 2674,	//组队-->队员增加新成员通知-->通知
	RPC_CODE_TEAM_CAPTAINAUTOMATCH_REQUEST       = 2675,	//组队-->队长自己匹配-->请求
	RPC_CODE_TEAM_NORMALAUTOMATCH_REQUEST        = 2676,	//组队-->非队长匹配-->请求
	RPC_CODE_TEAM_FOLLOW_REQUEST                 = 2677,	//组队-->跟随-->请求
	RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST         = 2678,	//组队-->清空申请列表-->请求


};


//附近队伍对象封装类
class TeamRpcNearbyTeamObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcNearbyTeamObjWraper()
	{
		
		m_TeamId = -1;
		m_CaptainUserId = -1;
		m_CaptainUserName = "";
		m_CaptainLevel = -1;
		m_MemberCount = -1;
		m_CaptainProf = -1;
		m_TeamTarget = -1;
		m_TargetMinLv = -1;
		m_TargetMaxLv = -1;

	}
	//赋值构造函数
	TeamRpcNearbyTeamObjWraper(const TeamRpcNearbyTeamObj& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcNearbyTeamObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcNearbyTeamObj ToPB() const
	{
		TeamRpcNearbyTeamObj v;
		v.set_teamid( m_TeamId );
		v.set_captainuserid( m_CaptainUserId );
		v.set_captainusername( m_CaptainUserName );
		v.set_captainlevel( m_CaptainLevel );
		v.set_membercount( m_MemberCount );
		v.set_captainprof( m_CaptainProf );
		v.set_teamtarget( m_TeamTarget );
		v.set_targetminlv( m_TargetMinLv );
		v.set_targetmaxlv( m_TargetMaxLv );

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
		TeamRpcNearbyTeamObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TeamId(组队Id) [sint32]</li>\r\n";
		htmlBuff += "<li>CaptainUserId(队长用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>CaptainUserName(队长名字) [string]</li>\r\n";
		htmlBuff += "<li>CaptainLevel(队长等级) [sint32]</li>\r\n";
		htmlBuff += "<li>MemberCount(队伍人数) [sint32]</li>\r\n";
		htmlBuff += "<li>CaptainProf(队长职业) [sint32]</li>\r\n";
		htmlBuff += "<li>TeamTarget(队伍目标) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetMinLv(目标最小等级) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetMaxLv(目标最大等级) [sint32]</li>\r\n";

		
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
		htmlBuff += "<li>CaptainUserName：\""+m_CaptainUserName+"\"</li>\r\n";
		tmpLine.Fmt("<li>CaptainLevel：%di</li>\r\n",m_CaptainLevel);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MemberCount：%di</li>\r\n",m_MemberCount);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CaptainProf：%di</li>\r\n",m_CaptainProf);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TeamTarget：%di</li>\r\n",m_TeamTarget);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetMinLv：%di</li>\r\n",m_TargetMinLv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetMaxLv：%di</li>\r\n",m_TargetMaxLv);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcNearbyTeamObj& v)
	{
		m_TeamId = v.teamid();
		m_CaptainUserId = v.captainuserid();
		m_CaptainUserName = v.captainusername();
		m_CaptainLevel = v.captainlevel();
		m_MemberCount = v.membercount();
		m_CaptainProf = v.captainprof();
		m_TeamTarget = v.teamtarget();
		m_TargetMinLv = v.targetminlv();
		m_TargetMaxLv = v.targetmaxlv();

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
	//队长名字
	string m_CaptainUserName;
public:
	void SetCaptainUserName( const string& v)
	{
		m_CaptainUserName=v;
	}
	string GetCaptainUserName()
	{
		return m_CaptainUserName;
	}
	string GetCaptainUserName() const
	{
		return m_CaptainUserName;
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
	//队伍目标
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
	//目标最小等级
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
	//目标最大等级
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

};
//附近玩家信息封装类
class TeamRpcNearbyRoleObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcNearbyRoleObjWraper()
	{
		
		m_UserId = -1;
		m_UserName = "";
		m_Level = -1;
		m_Prof = -1;

	}
	//赋值构造函数
	TeamRpcNearbyRoleObjWraper(const TeamRpcNearbyRoleObj& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcNearbyRoleObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcNearbyRoleObj ToPB() const
	{
		TeamRpcNearbyRoleObj v;
		v.set_userid( m_UserId );
		v.set_username( m_UserName );
		v.set_level( m_Level );
		v.set_prof( m_Prof );

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
		TeamRpcNearbyRoleObj pb;
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
		htmlBuff += "<li>Prof(职业) [sint32]</li>\r\n";

		
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

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcNearbyRoleObj& v)
	{
		m_UserId = v.userid();
		m_UserName = v.username();
		m_Level = v.level();
		m_Prof = v.prof();

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

};
//队长踢人请求封装类
class TeamRpcKickRoleAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcKickRoleAskWraper()
	{
		
		m_UserId = -1;

	}
	//赋值构造函数
	TeamRpcKickRoleAskWraper(const TeamRpcKickRoleAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcKickRoleAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcKickRoleAsk ToPB() const
	{
		TeamRpcKickRoleAsk v;
		v.set_userid( m_UserId );

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
		TeamRpcKickRoleAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcKickRoleAsk& v)
	{
		m_UserId = v.userid();

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

};
//附加玩家列表，邀请时使用回应封装类
class TeamRpcNearbyRoleListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcNearbyRoleListReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TeamRpcNearbyRoleListReplyWraper(const TeamRpcNearbyRoleListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcNearbyRoleListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcNearbyRoleListReply ToPB() const
	{
		TeamRpcNearbyRoleListReply v;
		v.set_result( m_Result );
		v.mutable_nearbyrolelist()->Reserve(m_NearbyRoleList.size());
		for (int i=0; i<(int)m_NearbyRoleList.size(); i++)
		{
			*v.add_nearbyrolelist() = m_NearbyRoleList[i].ToPB();
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
		TeamRpcNearbyRoleListReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>NearbyRoleList(附近玩家列表) [RpcNearbyRoleObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>NearbyRoleList：</li>\r\n";
		if( m_NearbyRoleList.size()>0) htmlBuff += m_NearbyRoleList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_NearbyRoleList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_NearbyRoleList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcNearbyRoleListReply& v)
	{
		m_Result = v.result();
		m_NearbyRoleList.clear();
		m_NearbyRoleList.reserve(v.nearbyrolelist_size());
		for( int i=0; i<v.nearbyrolelist_size(); i++)
			m_NearbyRoleList.push_back(v.nearbyrolelist(i));

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
	//附近玩家列表
	vector<TeamRpcNearbyRoleObjWraper> m_NearbyRoleList;
public:
	int SizeNearbyRoleList()
	{
		return m_NearbyRoleList.size();
	}
	const vector<TeamRpcNearbyRoleObjWraper>& GetNearbyRoleList() const
	{
		return m_NearbyRoleList;
	}
	TeamRpcNearbyRoleObjWraper GetNearbyRoleList(int Index) const
	{
		if(Index<0 || Index>=(int)m_NearbyRoleList.size())
		{
			assert(false);
			return TeamRpcNearbyRoleObjWraper();
		}
		return m_NearbyRoleList[Index];
	}
	void SetNearbyRoleList( const vector<TeamRpcNearbyRoleObjWraper>& v )
	{
		m_NearbyRoleList=v;
	}
	void ClearNearbyRoleList( )
	{
		m_NearbyRoleList.clear();
	}
	void SetNearbyRoleList( int Index, const TeamRpcNearbyRoleObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_NearbyRoleList.size())
		{
			assert(false);
			return;
		}
		m_NearbyRoleList[Index] = v;
	}
	void AddNearbyRoleList( const TeamRpcNearbyRoleObjWraper& v )
	{
		m_NearbyRoleList.push_back(v);
	}

};
//任命队长请求封装类
class TeamRpcAppointCaptainAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcAppointCaptainAskWraper()
	{
		
		m_UserId = -1;

	}
	//赋值构造函数
	TeamRpcAppointCaptainAskWraper(const TeamRpcAppointCaptainAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcAppointCaptainAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcAppointCaptainAsk ToPB() const
	{
		TeamRpcAppointCaptainAsk v;
		v.set_userid( m_UserId );

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
		TeamRpcAppointCaptainAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(被任命的人) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcAppointCaptainAsk& v)
	{
		m_UserId = v.userid();

	}

private:
	//被任命的人
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

};
//队长踢人回应封装类
class TeamRpcKickRoleReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcKickRoleReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TeamRpcKickRoleReplyWraper(const TeamRpcKickRoleReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcKickRoleReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcKickRoleReply ToPB() const
	{
		TeamRpcKickRoleReply v;
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
		TeamRpcKickRoleReply pb;
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
	void Init(const TeamRpcKickRoleReply& v)
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
//附加玩家列表，邀请时使用请求封装类
class TeamRpcNearbyRoleListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcNearbyRoleListAskWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcNearbyRoleListAskWraper(const TeamRpcNearbyRoleListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcNearbyRoleListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcNearbyRoleListAsk ToPB() const
	{
		TeamRpcNearbyRoleListAsk v;

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
		TeamRpcNearbyRoleListAsk pb;
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
	void Init(const TeamRpcNearbyRoleListAsk& v)
	{

	}


};
//队员血量变化通知通知封装类
class TeamRpcTeamMemberHPChangeNoticeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcTeamMemberHPChangeNoticeNotifyWraper()
	{
		
		m_UserId = -1;
		m_HP = -1;
		m_MaxHP = -1;

	}
	//赋值构造函数
	TeamRpcTeamMemberHPChangeNoticeNotifyWraper(const TeamRpcTeamMemberHPChangeNoticeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcTeamMemberHPChangeNoticeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcTeamMemberHPChangeNoticeNotify ToPB() const
	{
		TeamRpcTeamMemberHPChangeNoticeNotify v;
		v.set_userid( m_UserId );
		v.set_hp( m_HP );
		v.set_maxhp( m_MaxHP );

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
		TeamRpcTeamMemberHPChangeNoticeNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户id) [sint64]</li>\r\n";
		htmlBuff += "<li>HP(HP) [sint32]</li>\r\n";
		htmlBuff += "<li>MaxHP(MaxHP) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>HP：%di</li>\r\n",m_HP);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MaxHP：%di</li>\r\n",m_MaxHP);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcTeamMemberHPChangeNoticeNotify& v)
	{
		m_UserId = v.userid();
		m_HP = v.hp();
		m_MaxHP = v.maxhp();

	}

private:
	//用户id
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

};
//队长换人通知通知封装类
class TeamRpcCaptainChangeNoticeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcCaptainChangeNoticeNotifyWraper()
	{
		
		m_UserId = -1;
		m_UserName = "";

	}
	//赋值构造函数
	TeamRpcCaptainChangeNoticeNotifyWraper(const TeamRpcCaptainChangeNoticeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcCaptainChangeNoticeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcCaptainChangeNoticeNotify ToPB() const
	{
		TeamRpcCaptainChangeNoticeNotify v;
		v.set_userid( m_UserId );
		v.set_username( m_UserName );

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
		TeamRpcCaptainChangeNoticeNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(被任命的人) [sint64]</li>\r\n";
		htmlBuff += "<li>UserName(被任命的人) [string]</li>\r\n";

		
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

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcCaptainChangeNoticeNotify& v)
	{
		m_UserId = v.userid();
		m_UserName = v.username();

	}

private:
	//被任命的人
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
	//被任命的人
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

};
//任命队长回应封装类
class TeamRpcAppointCaptainReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcAppointCaptainReplyWraper()
	{
		
		m_Result = -9999;
		m_UserId = -1;

	}
	//赋值构造函数
	TeamRpcAppointCaptainReplyWraper(const TeamRpcAppointCaptainReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcAppointCaptainReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcAppointCaptainReply ToPB() const
	{
		TeamRpcAppointCaptainReply v;
		v.set_result( m_Result );
		v.set_userid( m_UserId );

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
		TeamRpcAppointCaptainReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(被任命的人) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcAppointCaptainReply& v)
	{
		m_Result = v.result();
		m_UserId = v.userid();

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
	//被任命的人
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

};
//邀请组队的人收到被邀请人的处理通知通知封装类
class TeamRpcInviteHandleNoticeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcInviteHandleNoticeNotifyWraper()
	{
		
		m_Result = 0;

	}
	//赋值构造函数
	TeamRpcInviteHandleNoticeNotifyWraper(const TeamRpcInviteHandleNoticeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcInviteHandleNoticeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcInviteHandleNoticeNotify ToPB() const
	{
		TeamRpcInviteHandleNoticeNotify v;
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
		TeamRpcInviteHandleNoticeNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果(0是拒绝，1是同意)) [sint32]</li>\r\n";

		
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
	void Init(const TeamRpcInviteHandleNoticeNotify& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果(0是拒绝，1是同意)
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
//被踢通知通知封装类
class TeamRpcBeingKickedNoticeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcBeingKickedNoticeNotifyWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcBeingKickedNoticeNotifyWraper(const TeamRpcBeingKickedNoticeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcBeingKickedNoticeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcBeingKickedNoticeNotify ToPB() const
	{
		TeamRpcBeingKickedNoticeNotify v;

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
		TeamRpcBeingKickedNoticeNotify pb;
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
	void Init(const TeamRpcBeingKickedNoticeNotify& v)
	{

	}


};
//跟随请求封装类
class TeamRpcFollowAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcFollowAskWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcFollowAskWraper(const TeamRpcFollowAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcFollowAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcFollowAsk ToPB() const
	{
		TeamRpcFollowAsk v;

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
		TeamRpcFollowAsk pb;
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
	void Init(const TeamRpcFollowAsk& v)
	{

	}


};
//非队长匹配回应封装类
class TeamRpcNormalAutoMatchReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcNormalAutoMatchReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TeamRpcNormalAutoMatchReplyWraper(const TeamRpcNormalAutoMatchReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcNormalAutoMatchReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcNormalAutoMatchReply ToPB() const
	{
		TeamRpcNormalAutoMatchReply v;
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
		TeamRpcNormalAutoMatchReply pb;
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
	void Init(const TeamRpcNormalAutoMatchReply& v)
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
//跟随回应封装类
class TeamRpcFollowReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcFollowReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TeamRpcFollowReplyWraper(const TeamRpcFollowReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcFollowReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcFollowReply ToPB() const
	{
		TeamRpcFollowReply v;
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
		TeamRpcFollowReply pb;
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
	void Init(const TeamRpcFollowReply& v)
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
//清空申请列表回应封装类
class TeamRpcClearApplyListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcClearApplyListReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TeamRpcClearApplyListReplyWraper(const TeamRpcClearApplyListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcClearApplyListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcClearApplyListReply ToPB() const
	{
		TeamRpcClearApplyListReply v;
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
		TeamRpcClearApplyListReply pb;
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
	void Init(const TeamRpcClearApplyListReply& v)
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
//清空申请列表请求封装类
class TeamRpcClearApplyListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcClearApplyListAskWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcClearApplyListAskWraper(const TeamRpcClearApplyListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcClearApplyListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcClearApplyListAsk ToPB() const
	{
		TeamRpcClearApplyListAsk v;

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
		TeamRpcClearApplyListAsk pb;
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
	void Init(const TeamRpcClearApplyListAsk& v)
	{

	}


};
//非队长匹配请求封装类
class TeamRpcNormalAutoMatchAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcNormalAutoMatchAskWraper()
	{
		
		m_Oper = -1;
		m_Target = -1;

	}
	//赋值构造函数
	TeamRpcNormalAutoMatchAskWraper(const TeamRpcNormalAutoMatchAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcNormalAutoMatchAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcNormalAutoMatchAsk ToPB() const
	{
		TeamRpcNormalAutoMatchAsk v;
		v.set_oper( m_Oper );
		v.set_target( m_Target );

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
		TeamRpcNormalAutoMatchAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Oper(0是开始，1是结束) [sint32]</li>\r\n";
		htmlBuff += "<li>Target(目标) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Oper：%di</li>\r\n",m_Oper);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Target：%di</li>\r\n",m_Target);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcNormalAutoMatchAsk& v)
	{
		m_Oper = v.oper();
		m_Target = v.target();

	}

private:
	//0是开始，1是结束
	INT32 m_Oper;
public:
	void SetOper( INT32 v)
	{
		m_Oper=v;
	}
	INT32 GetOper()
	{
		return m_Oper;
	}
	INT32 GetOper() const
	{
		return m_Oper;
	}
private:
	//目标
	INT32 m_Target;
public:
	void SetTarget( INT32 v)
	{
		m_Target=v;
	}
	INT32 GetTarget()
	{
		return m_Target;
	}
	INT32 GetTarget() const
	{
		return m_Target;
	}

};
//解散队伍回应封装类
class TeamRpcBreakUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcBreakUpReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TeamRpcBreakUpReplyWraper(const TeamRpcBreakUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcBreakUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcBreakUpReply ToPB() const
	{
		TeamRpcBreakUpReply v;
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
		TeamRpcBreakUpReply pb;
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
	void Init(const TeamRpcBreakUpReply& v)
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
//解散队伍请求封装类
class TeamRpcBreakUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcBreakUpAskWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcBreakUpAskWraper(const TeamRpcBreakUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcBreakUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcBreakUpAsk ToPB() const
	{
		TeamRpcBreakUpAsk v;

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
		TeamRpcBreakUpAsk pb;
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
	void Init(const TeamRpcBreakUpAsk& v)
	{

	}


};
//队员增加新成员通知通知封装类
class TeamRpcAddNewMemberNoticeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcAddNewMemberNoticeNotifyWraper()
	{
		
		m_UserId = -1;
		m_UserName = "";

	}
	//赋值构造函数
	TeamRpcAddNewMemberNoticeNotifyWraper(const TeamRpcAddNewMemberNoticeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcAddNewMemberNoticeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcAddNewMemberNoticeNotify ToPB() const
	{
		TeamRpcAddNewMemberNoticeNotify v;
		v.set_userid( m_UserId );
		v.set_username( m_UserName );

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
		TeamRpcAddNewMemberNoticeNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>UserName(用户名字) [string]</li>\r\n";

		
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

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcAddNewMemberNoticeNotify& v)
	{
		m_UserId = v.userid();
		m_UserName = v.username();

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

};
//队长自己匹配回应封装类
class TeamRpcCaptainAutoMatchReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcCaptainAutoMatchReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TeamRpcCaptainAutoMatchReplyWraper(const TeamRpcCaptainAutoMatchReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcCaptainAutoMatchReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcCaptainAutoMatchReply ToPB() const
	{
		TeamRpcCaptainAutoMatchReply v;
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
		TeamRpcCaptainAutoMatchReply pb;
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
	void Init(const TeamRpcCaptainAutoMatchReply& v)
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
//队长自己匹配请求封装类
class TeamRpcCaptainAutoMatchAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcCaptainAutoMatchAskWraper()
	{
		
		m_Oper = -1;

	}
	//赋值构造函数
	TeamRpcCaptainAutoMatchAskWraper(const TeamRpcCaptainAutoMatchAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcCaptainAutoMatchAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcCaptainAutoMatchAsk ToPB() const
	{
		TeamRpcCaptainAutoMatchAsk v;
		v.set_oper( m_Oper );

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
		TeamRpcCaptainAutoMatchAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Oper(0是开始，1是结束) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Oper：%di</li>\r\n",m_Oper);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcCaptainAutoMatchAsk& v)
	{
		m_Oper = v.oper();

	}

private:
	//0是开始，1是结束
	INT32 m_Oper;
public:
	void SetOper( INT32 v)
	{
		m_Oper=v;
	}
	INT32 GetOper()
	{
		return m_Oper;
	}
	INT32 GetOper() const
	{
		return m_Oper;
	}

};
//申请列表处理后删除申请的玩家通知封装类
class TeamRpcDeleteFromApplyListNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcDeleteFromApplyListNotifyWraper()
	{
		
		m_UserId = -1;

	}
	//赋值构造函数
	TeamRpcDeleteFromApplyListNotifyWraper(const TeamRpcDeleteFromApplyListNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcDeleteFromApplyListNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcDeleteFromApplyListNotify ToPB() const
	{
		TeamRpcDeleteFromApplyListNotify v;
		v.set_userid( m_UserId );

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
		TeamRpcDeleteFromApplyListNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(离开的玩家Id) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcDeleteFromApplyListNotify& v)
	{
		m_UserId = v.userid();

	}

private:
	//离开的玩家Id
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

};
//更改队伍目标请求封装类
class TeamRpcChangeTeamTargetAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcChangeTeamTargetAskWraper()
	{
		
		m_TargetId = -1;
		m_TargetMinLv = -1;
		m_TargetMaxLv = -1;

	}
	//赋值构造函数
	TeamRpcChangeTeamTargetAskWraper(const TeamRpcChangeTeamTargetAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcChangeTeamTargetAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcChangeTeamTargetAsk ToPB() const
	{
		TeamRpcChangeTeamTargetAsk v;
		v.set_targetid( m_TargetId );
		v.set_targetminlv( m_TargetMinLv );
		v.set_targetmaxlv( m_TargetMaxLv );

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
		TeamRpcChangeTeamTargetAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TargetId(目标id) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetMinLv(目标最小等级) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetMaxLv(目标最大等级) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TargetId：%di</li>\r\n",m_TargetId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetMinLv：%di</li>\r\n",m_TargetMinLv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetMaxLv：%di</li>\r\n",m_TargetMaxLv);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcChangeTeamTargetAsk& v)
	{
		m_TargetId = v.targetid();
		m_TargetMinLv = v.targetminlv();
		m_TargetMaxLv = v.targetmaxlv();

	}

private:
	//目标id
	INT32 m_TargetId;
public:
	void SetTargetId( INT32 v)
	{
		m_TargetId=v;
	}
	INT32 GetTargetId()
	{
		return m_TargetId;
	}
	INT32 GetTargetId() const
	{
		return m_TargetId;
	}
private:
	//目标最小等级
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
	//目标最大等级
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

};
//邀请入队回应封装类
class TeamRpcInviteToTeamReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcInviteToTeamReplyWraper()
	{
		
		m_Result = -9999;
		m_UserId = -1;

	}
	//赋值构造函数
	TeamRpcInviteToTeamReplyWraper(const TeamRpcInviteToTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcInviteToTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcInviteToTeamReply ToPB() const
	{
		TeamRpcInviteToTeamReply v;
		v.set_result( m_Result );
		v.set_userid( m_UserId );

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
		TeamRpcInviteToTeamReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(邀请的对方Id) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcInviteToTeamReply& v)
	{
		m_Result = v.result();
		m_UserId = v.userid();

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
	//邀请的对方Id
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

};
//更改队伍目标回应封装类
class TeamRpcChangeTeamTargetReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcChangeTeamTargetReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TeamRpcChangeTeamTargetReplyWraper(const TeamRpcChangeTeamTargetReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcChangeTeamTargetReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcChangeTeamTargetReply ToPB() const
	{
		TeamRpcChangeTeamTargetReply v;
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
		TeamRpcChangeTeamTargetReply pb;
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
	void Init(const TeamRpcChangeTeamTargetReply& v)
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
//被邀请处理请求封装类
class TeamRpcBeInviteHandleAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcBeInviteHandleAskWraper()
	{
		
		m_TeamId = -1;
		m_UserId = -1;
		m_Handle = -1;

	}
	//赋值构造函数
	TeamRpcBeInviteHandleAskWraper(const TeamRpcBeInviteHandleAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcBeInviteHandleAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcBeInviteHandleAsk ToPB() const
	{
		TeamRpcBeInviteHandleAsk v;
		v.set_teamid( m_TeamId );
		v.set_userid( m_UserId );
		v.set_handle( m_Handle );

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
		TeamRpcBeInviteHandleAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TeamId(队伍Id) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(邀请人的用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>Handle(处理方式（0拒绝 1同意）) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TeamId：%di</li>\r\n",m_TeamId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Handle：%di</li>\r\n",m_Handle);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcBeInviteHandleAsk& v)
	{
		m_TeamId = v.teamid();
		m_UserId = v.userid();
		m_Handle = v.handle();

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
	//邀请人的用户Id
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
	//处理方式（0拒绝 1同意）
	INT32 m_Handle;
public:
	void SetHandle( INT32 v)
	{
		m_Handle=v;
	}
	INT32 GetHandle()
	{
		return m_Handle;
	}
	INT32 GetHandle() const
	{
		return m_Handle;
	}

};
//被邀请入队通知通知封装类
class TeamRpcBeInvitedNoticeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcBeInvitedNoticeNotifyWraper()
	{
		
		m_TeamId = -1;
		m_UserId = -1;
		m_UserName = "";
		m_CaptainUserName = "";

	}
	//赋值构造函数
	TeamRpcBeInvitedNoticeNotifyWraper(const TeamRpcBeInvitedNoticeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcBeInvitedNoticeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcBeInvitedNoticeNotify ToPB() const
	{
		TeamRpcBeInvitedNoticeNotify v;
		v.set_teamid( m_TeamId );
		v.set_userid( m_UserId );
		v.set_username( m_UserName );
		v.set_captainusername( m_CaptainUserName );

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
		TeamRpcBeInvitedNoticeNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TeamId(队伍Id) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(邀请人的用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>UserName(邀请人的名字) [string]</li>\r\n";
		htmlBuff += "<li>CaptainUserName(队长名字) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TeamId：%di</li>\r\n",m_TeamId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>UserName：\""+m_UserName+"\"</li>\r\n";
		htmlBuff += "<li>CaptainUserName：\""+m_CaptainUserName+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcBeInvitedNoticeNotify& v)
	{
		m_TeamId = v.teamid();
		m_UserId = v.userid();
		m_UserName = v.username();
		m_CaptainUserName = v.captainusername();

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
	//邀请人的用户Id
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
	//邀请人的名字
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
	//队长名字
	string m_CaptainUserName;
public:
	void SetCaptainUserName( const string& v)
	{
		m_CaptainUserName=v;
	}
	string GetCaptainUserName()
	{
		return m_CaptainUserName;
	}
	string GetCaptainUserName() const
	{
		return m_CaptainUserName;
	}

};
//邀请入队请求封装类
class TeamRpcInviteToTeamAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcInviteToTeamAskWraper()
	{
		
		m_UserId = -1;

	}
	//赋值构造函数
	TeamRpcInviteToTeamAskWraper(const TeamRpcInviteToTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcInviteToTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcInviteToTeamAsk ToPB() const
	{
		TeamRpcInviteToTeamAsk v;
		v.set_userid( m_UserId );

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
		TeamRpcInviteToTeamAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(邀请的对方Id) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcInviteToTeamAsk& v)
	{
		m_UserId = v.userid();

	}

private:
	//邀请的对方Id
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

};
//创建队伍请求封装类
class TeamRpcCreateTeamAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcCreateTeamAskWraper()
	{
		
		m_TargetId = -1;
		m_TargetMinLv = -1;
		m_TargetMaxLv = -1;

	}
	//赋值构造函数
	TeamRpcCreateTeamAskWraper(const TeamRpcCreateTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcCreateTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcCreateTeamAsk ToPB() const
	{
		TeamRpcCreateTeamAsk v;
		v.set_targetid( m_TargetId );
		v.set_targetminlv( m_TargetMinLv );
		v.set_targetmaxlv( m_TargetMaxLv );

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
		TeamRpcCreateTeamAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TargetId(目标id) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetMinLv(目标最小等级) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetMaxLv(目标最大等级) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TargetId：%di</li>\r\n",m_TargetId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetMinLv：%di</li>\r\n",m_TargetMinLv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetMaxLv：%di</li>\r\n",m_TargetMaxLv);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcCreateTeamAsk& v)
	{
		m_TargetId = v.targetid();
		m_TargetMinLv = v.targetminlv();
		m_TargetMaxLv = v.targetmaxlv();

	}

private:
	//目标id
	INT32 m_TargetId;
public:
	void SetTargetId( INT32 v)
	{
		m_TargetId=v;
	}
	INT32 GetTargetId()
	{
		return m_TargetId;
	}
	INT32 GetTargetId() const
	{
		return m_TargetId;
	}
private:
	//目标最小等级
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
	//目标最大等级
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

};
//创建队伍回应封装类
class TeamRpcCreateTeamReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcCreateTeamReplyWraper()
	{
		
		m_Result = -9999;
		m_TeamData = TeamObjWraper();

	}
	//赋值构造函数
	TeamRpcCreateTeamReplyWraper(const TeamRpcCreateTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcCreateTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcCreateTeamReply ToPB() const
	{
		TeamRpcCreateTeamReply v;
		v.set_result( m_Result );
		*v.mutable_teamdata()= m_TeamData.ToPB();

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
		TeamRpcCreateTeamReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TeamData(队伍数据) [TeamObj]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>TeamData：</li>\r\n";
		htmlBuff += m_TeamData.HtmlDescHeader();
		htmlBuff += m_TeamData.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcCreateTeamReply& v)
	{
		m_Result = v.result();
		m_TeamData = v.teamdata();

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
	//队伍数据
	TeamObjWraper m_TeamData;
public:
	void SetTeamData( const TeamObjWraper& v)
	{
		m_TeamData=v;
	}
	TeamObjWraper GetTeamData()
	{
		return m_TeamData;
	}
	TeamObjWraper GetTeamData() const
	{
		return m_TeamData;
	}

};
//申请入队回应封装类
class TeamRpcApplyForTeamReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcApplyForTeamReplyWraper()
	{
		
		m_Result = -9999;
		m_TeamId = -1;

	}
	//赋值构造函数
	TeamRpcApplyForTeamReplyWraper(const TeamRpcApplyForTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcApplyForTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcApplyForTeamReply ToPB() const
	{
		TeamRpcApplyForTeamReply v;
		v.set_result( m_Result );
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
		TeamRpcApplyForTeamReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TeamId(队伍Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TeamId：%di</li>\r\n",m_TeamId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcApplyForTeamReply& v)
	{
		m_Result = v.result();
		m_TeamId = v.teamid();

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

};
//申请入队请求封装类
class TeamRpcApplyForTeamAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcApplyForTeamAskWraper()
	{
		
		m_TeamId = -1;

	}
	//赋值构造函数
	TeamRpcApplyForTeamAskWraper(const TeamRpcApplyForTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcApplyForTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcApplyForTeamAsk ToPB() const
	{
		TeamRpcApplyForTeamAsk v;
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
		TeamRpcApplyForTeamAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TeamId(队伍Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TeamId：%di</li>\r\n",m_TeamId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcApplyForTeamAsk& v)
	{
		m_TeamId = v.teamid();

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

};
//离开队伍通知封装类
class TeamRpcQuitTeamNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcQuitTeamNotifyWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcQuitTeamNotifyWraper(const TeamRpcQuitTeamNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcQuitTeamNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcQuitTeamNotify ToPB() const
	{
		TeamRpcQuitTeamNotify v;

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
		TeamRpcQuitTeamNotify pb;
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
	void Init(const TeamRpcQuitTeamNotify& v)
	{

	}


};
//更新我的队伍通知通知封装类
class TeamRpcUpdateMyTeamNoticeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcUpdateMyTeamNoticeNotifyWraper()
	{
		
		m_MyTeamData = TeamObjWraper();

	}
	//赋值构造函数
	TeamRpcUpdateMyTeamNoticeNotifyWraper(const TeamRpcUpdateMyTeamNoticeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcUpdateMyTeamNoticeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcUpdateMyTeamNoticeNotify ToPB() const
	{
		TeamRpcUpdateMyTeamNoticeNotify v;
		*v.mutable_myteamdata()= m_MyTeamData.ToPB();

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
		TeamRpcUpdateMyTeamNoticeNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>MyTeamData(组队数据) [TeamObj]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>MyTeamData：</li>\r\n";
		htmlBuff += m_MyTeamData.HtmlDescHeader();
		htmlBuff += m_MyTeamData.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcUpdateMyTeamNoticeNotify& v)
	{
		m_MyTeamData = v.myteamdata();

	}

private:
	//组队数据
	TeamObjWraper m_MyTeamData;
public:
	void SetMyTeamData( const TeamObjWraper& v)
	{
		m_MyTeamData=v;
	}
	TeamObjWraper GetMyTeamData()
	{
		return m_MyTeamData;
	}
	TeamObjWraper GetMyTeamData() const
	{
		return m_MyTeamData;
	}

};
//离开队伍通知通知封装类
class TeamRpcLeaveTeamNoticeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcLeaveTeamNoticeNotifyWraper()
	{
		
		m_UserId = -1;
		m_UserName = "";

	}
	//赋值构造函数
	TeamRpcLeaveTeamNoticeNotifyWraper(const TeamRpcLeaveTeamNoticeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcLeaveTeamNoticeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcLeaveTeamNoticeNotify ToPB() const
	{
		TeamRpcLeaveTeamNoticeNotify v;
		v.set_userid( m_UserId );
		v.set_username( m_UserName );

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
		TeamRpcLeaveTeamNoticeNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(离开的玩家Id) [sint32]</li>\r\n";
		htmlBuff += "<li>UserName(离开的玩家名字) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%di</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>UserName：\""+m_UserName+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcLeaveTeamNoticeNotify& v)
	{
		m_UserId = v.userid();
		m_UserName = v.username();

	}

private:
	//离开的玩家Id
	INT32 m_UserId;
public:
	void SetUserId( INT32 v)
	{
		m_UserId=v;
	}
	INT32 GetUserId()
	{
		return m_UserId;
	}
	INT32 GetUserId() const
	{
		return m_UserId;
	}
private:
	//离开的玩家名字
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

};
//请求我的队伍数据通知封装类
class TeamRpcReqMyTeamDataNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcReqMyTeamDataNotifyWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcReqMyTeamDataNotifyWraper(const TeamRpcReqMyTeamDataNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcReqMyTeamDataNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcReqMyTeamDataNotify ToPB() const
	{
		TeamRpcReqMyTeamDataNotify v;

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
		TeamRpcReqMyTeamDataNotify pb;
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
	void Init(const TeamRpcReqMyTeamDataNotify& v)
	{

	}


};
//解散队伍通知通知封装类
class TeamRpcBreakUpNoticeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcBreakUpNoticeNotifyWraper()
	{
		
		m_UserId = -1;
		m_UserName = "";

	}
	//赋值构造函数
	TeamRpcBreakUpNoticeNotifyWraper(const TeamRpcBreakUpNoticeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcBreakUpNoticeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcBreakUpNoticeNotify ToPB() const
	{
		TeamRpcBreakUpNoticeNotify v;
		v.set_userid( m_UserId );
		v.set_username( m_UserName );

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
		TeamRpcBreakUpNoticeNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>UserName(用户名字) [string]</li>\r\n";

		
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

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcBreakUpNoticeNotify& v)
	{
		m_UserId = v.userid();
		m_UserName = v.username();

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

};
//申请入队,队长同意入队回应封装类
class TeamRpcApplyHandleAgreeReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcApplyHandleAgreeReplyWraper()
	{
		
		m_Result = -9999;
		m_UserId = -1;
		m_TeamId = -1;
		m_Handle = -1;

	}
	//赋值构造函数
	TeamRpcApplyHandleAgreeReplyWraper(const TeamRpcApplyHandleAgreeReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcApplyHandleAgreeReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcApplyHandleAgreeReply ToPB() const
	{
		TeamRpcApplyHandleAgreeReply v;
		v.set_result( m_Result );
		v.set_userid( m_UserId );
		v.set_teamid( m_TeamId );
		v.set_handle( m_Handle );

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
		TeamRpcApplyHandleAgreeReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(申请人的UserId) [sint64]</li>\r\n";
		htmlBuff += "<li>TeamId(申请人申请的队伍Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Handle(处理方式（0拒绝 1同意）) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TeamId：%di</li>\r\n",m_TeamId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Handle：%di</li>\r\n",m_Handle);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcApplyHandleAgreeReply& v)
	{
		m_Result = v.result();
		m_UserId = v.userid();
		m_TeamId = v.teamid();
		m_Handle = v.handle();

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
	//申请人的UserId
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
	//申请人申请的队伍Id
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
	//处理方式（0拒绝 1同意）
	INT32 m_Handle;
public:
	void SetHandle( INT32 v)
	{
		m_Handle=v;
	}
	INT32 GetHandle()
	{
		return m_Handle;
	}
	INT32 GetHandle() const
	{
		return m_Handle;
	}

};
//附近队伍请求封装类
class TeamRpcNearbyTeamAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcNearbyTeamAskWraper()
	{
		
		m_TargetId = -1;

	}
	//赋值构造函数
	TeamRpcNearbyTeamAskWraper(const TeamRpcNearbyTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcNearbyTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcNearbyTeamAsk ToPB() const
	{
		TeamRpcNearbyTeamAsk v;
		v.set_targetid( m_TargetId );

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
		TeamRpcNearbyTeamAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TargetId(目标id,-1是附近队伍) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TargetId：%di</li>\r\n",m_TargetId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcNearbyTeamAsk& v)
	{
		m_TargetId = v.targetid();

	}

private:
	//目标id,-1是附近队伍
	INT32 m_TargetId;
public:
	void SetTargetId( INT32 v)
	{
		m_TargetId=v;
	}
	INT32 GetTargetId()
	{
		return m_TargetId;
	}
	INT32 GetTargetId() const
	{
		return m_TargetId;
	}

};
//被邀请处理回应封装类
class TeamRpcBeInviteHandleReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcBeInviteHandleReplyWraper()
	{
		
		m_Result = -9999;
		m_TeamId = -1;
		m_UserId = -1;
		m_Handle = -1;
		m_IsCapatain = false;

	}
	//赋值构造函数
	TeamRpcBeInviteHandleReplyWraper(const TeamRpcBeInviteHandleReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcBeInviteHandleReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcBeInviteHandleReply ToPB() const
	{
		TeamRpcBeInviteHandleReply v;
		v.set_result( m_Result );
		v.set_teamid( m_TeamId );
		v.set_userid( m_UserId );
		v.set_handle( m_Handle );
		v.set_iscapatain( m_IsCapatain );

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
		TeamRpcBeInviteHandleReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TeamId(队伍Id) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(邀请人的用户Id) [sint64]</li>\r\n";
		htmlBuff += "<li>Handle(处理方式（0拒绝 1同意）) [sint32]</li>\r\n";
		htmlBuff += "<li>IsCapatain(邀请人是否为队长) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TeamId：%di</li>\r\n",m_TeamId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Handle：%di</li>\r\n",m_Handle);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsCapatain：%di</li>\r\n",m_IsCapatain);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcBeInviteHandleReply& v)
	{
		m_Result = v.result();
		m_TeamId = v.teamid();
		m_UserId = v.userid();
		m_Handle = v.handle();
		m_IsCapatain = v.iscapatain();

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
	//邀请人的用户Id
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
	//处理方式（0拒绝 1同意）
	INT32 m_Handle;
public:
	void SetHandle( INT32 v)
	{
		m_Handle=v;
	}
	INT32 GetHandle()
	{
		return m_Handle;
	}
	INT32 GetHandle() const
	{
		return m_Handle;
	}
private:
	//邀请人是否为队长
	bool m_IsCapatain;
public:
	void SetIsCapatain( bool v)
	{
		m_IsCapatain=v;
	}
	bool GetIsCapatain()
	{
		return m_IsCapatain;
	}
	bool GetIsCapatain() const
	{
		return m_IsCapatain;
	}

};
//附近队伍回应封装类
class TeamRpcNearbyTeamReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcNearbyTeamReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TeamRpcNearbyTeamReplyWraper(const TeamRpcNearbyTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcNearbyTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcNearbyTeamReply ToPB() const
	{
		TeamRpcNearbyTeamReply v;
		v.set_result( m_Result );
		v.mutable_teams()->Reserve(m_Teams.size());
		for (int i=0; i<(int)m_Teams.size(); i++)
		{
			*v.add_teams() = m_Teams[i].ToPB();
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
		TeamRpcNearbyTeamReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Teams(队伍) [RpcNearbyTeamObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Teams：</li>\r\n";
		if( m_Teams.size()>0) htmlBuff += m_Teams[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_Teams.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_Teams[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcNearbyTeamReply& v)
	{
		m_Result = v.result();
		m_Teams.clear();
		m_Teams.reserve(v.teams_size());
		for( int i=0; i<v.teams_size(); i++)
			m_Teams.push_back(v.teams(i));

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
	//队伍
	vector<TeamRpcNearbyTeamObjWraper> m_Teams;
public:
	int SizeTeams()
	{
		return m_Teams.size();
	}
	const vector<TeamRpcNearbyTeamObjWraper>& GetTeams() const
	{
		return m_Teams;
	}
	TeamRpcNearbyTeamObjWraper GetTeams(int Index) const
	{
		if(Index<0 || Index>=(int)m_Teams.size())
		{
			assert(false);
			return TeamRpcNearbyTeamObjWraper();
		}
		return m_Teams[Index];
	}
	void SetTeams( const vector<TeamRpcNearbyTeamObjWraper>& v )
	{
		m_Teams=v;
	}
	void ClearTeams( )
	{
		m_Teams.clear();
	}
	void SetTeams( int Index, const TeamRpcNearbyTeamObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_Teams.size())
		{
			assert(false);
			return;
		}
		m_Teams[Index] = v;
	}
	void AddTeams( const TeamRpcNearbyTeamObjWraper& v )
	{
		m_Teams.push_back(v);
	}

};
//申请入队,队长同意入队请求封装类
class TeamRpcApplyHandleAgreeAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcApplyHandleAgreeAskWraper()
	{
		
		m_UserId = -1;
		m_TeamId = -1;
		m_Handle = -1;

	}
	//赋值构造函数
	TeamRpcApplyHandleAgreeAskWraper(const TeamRpcApplyHandleAgreeAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcApplyHandleAgreeAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcApplyHandleAgreeAsk ToPB() const
	{
		TeamRpcApplyHandleAgreeAsk v;
		v.set_userid( m_UserId );
		v.set_teamid( m_TeamId );
		v.set_handle( m_Handle );

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
		TeamRpcApplyHandleAgreeAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(申请人的UserId) [sint64]</li>\r\n";
		htmlBuff += "<li>TeamId(申请人申请的队伍Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Handle(处理方式（0拒绝 1同意）) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TeamId：%di</li>\r\n",m_TeamId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Handle：%di</li>\r\n",m_Handle);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcApplyHandleAgreeAsk& v)
	{
		m_UserId = v.userid();
		m_TeamId = v.teamid();
		m_Handle = v.handle();

	}

private:
	//申请人的UserId
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
	//申请人申请的队伍Id
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
	//处理方式（0拒绝 1同意）
	INT32 m_Handle;
public:
	void SetHandle( INT32 v)
	{
		m_Handle=v;
	}
	INT32 GetHandle()
	{
		return m_Handle;
	}
	INT32 GetHandle() const
	{
		return m_Handle;
	}

};
//有人申请入队,队长收到通知通知封装类
class TeamRpcApplyNoticeCaptainNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcApplyNoticeCaptainNotifyWraper()
	{
		
		m_ApplyUser = TeamApplyUserObjWraper();

	}
	//赋值构造函数
	TeamRpcApplyNoticeCaptainNotifyWraper(const TeamRpcApplyNoticeCaptainNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcApplyNoticeCaptainNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcApplyNoticeCaptainNotify ToPB() const
	{
		TeamRpcApplyNoticeCaptainNotify v;
		*v.mutable_applyuser()= m_ApplyUser.ToPB();

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
		TeamRpcApplyNoticeCaptainNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ApplyUser(申请列表) [TeamApplyUserObj]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ApplyUser：</li>\r\n";
		htmlBuff += m_ApplyUser.HtmlDescHeader();
		htmlBuff += m_ApplyUser.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamRpcApplyNoticeCaptainNotify& v)
	{
		m_ApplyUser = v.applyuser();

	}

private:
	//申请列表
	TeamApplyUserObjWraper m_ApplyUser;
public:
	void SetApplyUser( const TeamApplyUserObjWraper& v)
	{
		m_ApplyUser=v;
	}
	TeamApplyUserObjWraper GetApplyUser()
	{
		return m_ApplyUser;
	}
	TeamApplyUserObjWraper GetApplyUser() const
	{
		return m_ApplyUser;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<TeamRpcCreateTeamAskWraper>{ enum{ID=RPC_CODE_TEAM_CREATETEAM_REQUEST};};
template<> struct MessageIdT<TeamRpcCreateTeamReplyWraper>{ enum{ID=RPC_CODE_TEAM_CREATETEAM_REQUEST};};
template<> struct MessageIdT<TeamRpcApplyForTeamAskWraper>{ enum{ID=RPC_CODE_TEAM_APPLYFORTEAM_REQUEST};};
template<> struct MessageIdT<TeamRpcApplyForTeamReplyWraper>{ enum{ID=RPC_CODE_TEAM_APPLYFORTEAM_REQUEST};};
template<> struct MessageIdT<TeamRpcQuitTeamNotifyWraper>{ enum{ID=RPC_CODE_TEAM_QUITTEAM_NOTIFY};};
template<> struct MessageIdT<TeamRpcBreakUpAskWraper>{ enum{ID=RPC_CODE_TEAM_BREAKUP_REQUEST};};
template<> struct MessageIdT<TeamRpcBreakUpReplyWraper>{ enum{ID=RPC_CODE_TEAM_BREAKUP_REQUEST};};
template<> struct MessageIdT<TeamRpcInviteToTeamAskWraper>{ enum{ID=RPC_CODE_TEAM_INVITETOTEAM_REQUEST};};
template<> struct MessageIdT<TeamRpcInviteToTeamReplyWraper>{ enum{ID=RPC_CODE_TEAM_INVITETOTEAM_REQUEST};};
template<> struct MessageIdT<TeamRpcChangeTeamTargetAskWraper>{ enum{ID=RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST};};
template<> struct MessageIdT<TeamRpcChangeTeamTargetReplyWraper>{ enum{ID=RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST};};
template<> struct MessageIdT<TeamRpcBeInvitedNoticeNotifyWraper>{ enum{ID=RPC_CODE_TEAM_BEINVITEDNOTICE_NOTIFY};};
template<> struct MessageIdT<TeamRpcBeInviteHandleAskWraper>{ enum{ID=RPC_CODE_TEAM_BEINVITEHANDLE_REQUEST};};
template<> struct MessageIdT<TeamRpcBeInviteHandleReplyWraper>{ enum{ID=RPC_CODE_TEAM_BEINVITEHANDLE_REQUEST};};
template<> struct MessageIdT<TeamRpcNearbyTeamAskWraper>{ enum{ID=RPC_CODE_TEAM_NEARBYTEAM_REQUEST};};
template<> struct MessageIdT<TeamRpcNearbyTeamReplyWraper>{ enum{ID=RPC_CODE_TEAM_NEARBYTEAM_REQUEST};};
template<> struct MessageIdT<TeamRpcApplyNoticeCaptainNotifyWraper>{ enum{ID=RPC_CODE_TEAM_APPLYNOTICECAPTAIN_NOTIFY};};
template<> struct MessageIdT<TeamRpcApplyHandleAgreeAskWraper>{ enum{ID=RPC_CODE_TEAM_APPLYHANDLEAGREE_REQUEST};};
template<> struct MessageIdT<TeamRpcApplyHandleAgreeReplyWraper>{ enum{ID=RPC_CODE_TEAM_APPLYHANDLEAGREE_REQUEST};};
template<> struct MessageIdT<TeamRpcUpdateMyTeamNoticeNotifyWraper>{ enum{ID=RPC_CODE_TEAM_UPDATEMYTEAMNOTICE_NOTIFY};};
template<> struct MessageIdT<TeamRpcLeaveTeamNoticeNotifyWraper>{ enum{ID=RPC_CODE_TEAM_LEAVETEAMNOTICE_NOTIFY};};
template<> struct MessageIdT<TeamRpcBreakUpNoticeNotifyWraper>{ enum{ID=RPC_CODE_TEAM_BREAKUPNOTICE_NOTIFY};};
template<> struct MessageIdT<TeamRpcReqMyTeamDataNotifyWraper>{ enum{ID=RPC_CODE_TEAM_REQMYTEAMDATA_NOTIFY};};
template<> struct MessageIdT<TeamRpcDeleteFromApplyListNotifyWraper>{ enum{ID=RPC_CODE_TEAM_DELETEFROMAPPLYLIST_NOTIFY};};
template<> struct MessageIdT<TeamRpcAppointCaptainAskWraper>{ enum{ID=RPC_CODE_TEAM_APPOINTCAPTAIN_REQUEST};};
template<> struct MessageIdT<TeamRpcAppointCaptainReplyWraper>{ enum{ID=RPC_CODE_TEAM_APPOINTCAPTAIN_REQUEST};};
template<> struct MessageIdT<TeamRpcCaptainChangeNoticeNotifyWraper>{ enum{ID=RPC_CODE_TEAM_CAPTAINCHANGENOTICE_NOTIFY};};
template<> struct MessageIdT<TeamRpcTeamMemberHPChangeNoticeNotifyWraper>{ enum{ID=RPC_CODE_TEAM_TEAMMEMBERHPCHANGENOTICE_NOTIFY};};
template<> struct MessageIdT<TeamRpcInviteHandleNoticeNotifyWraper>{ enum{ID=RPC_CODE_TEAM_INVITEHANDLENOTICE_NOTIFY};};
template<> struct MessageIdT<TeamRpcNearbyRoleListAskWraper>{ enum{ID=RPC_CODE_TEAM_NEARBYROLELIST_REQUEST};};
template<> struct MessageIdT<TeamRpcNearbyRoleListReplyWraper>{ enum{ID=RPC_CODE_TEAM_NEARBYROLELIST_REQUEST};};
template<> struct MessageIdT<TeamRpcKickRoleAskWraper>{ enum{ID=RPC_CODE_TEAM_KICKROLE_REQUEST};};
template<> struct MessageIdT<TeamRpcKickRoleReplyWraper>{ enum{ID=RPC_CODE_TEAM_KICKROLE_REQUEST};};
template<> struct MessageIdT<TeamRpcBeingKickedNoticeNotifyWraper>{ enum{ID=RPC_CODE_TEAM_BEINGKICKEDNOTICE_NOTIFY};};
template<> struct MessageIdT<TeamRpcAddNewMemberNoticeNotifyWraper>{ enum{ID=RPC_CODE_TEAM_ADDNEWMEMBERNOTICE_NOTIFY};};
template<> struct MessageIdT<TeamRpcCaptainAutoMatchAskWraper>{ enum{ID=RPC_CODE_TEAM_CAPTAINAUTOMATCH_REQUEST};};
template<> struct MessageIdT<TeamRpcCaptainAutoMatchReplyWraper>{ enum{ID=RPC_CODE_TEAM_CAPTAINAUTOMATCH_REQUEST};};
template<> struct MessageIdT<TeamRpcNormalAutoMatchAskWraper>{ enum{ID=RPC_CODE_TEAM_NORMALAUTOMATCH_REQUEST};};
template<> struct MessageIdT<TeamRpcNormalAutoMatchReplyWraper>{ enum{ID=RPC_CODE_TEAM_NORMALAUTOMATCH_REQUEST};};
template<> struct MessageIdT<TeamRpcFollowAskWraper>{ enum{ID=RPC_CODE_TEAM_FOLLOW_REQUEST};};
template<> struct MessageIdT<TeamRpcFollowReplyWraper>{ enum{ID=RPC_CODE_TEAM_FOLLOW_REQUEST};};
template<> struct MessageIdT<TeamRpcClearApplyListAskWraper>{ enum{ID=RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST};};
template<> struct MessageIdT<TeamRpcClearApplyListReplyWraper>{ enum{ID=RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST};};


#endif
