/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperOneVSOne.h
* Author:       甘业清
* Description:  一v一RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_ONEVSONE_H
#define __RPC_WRAPER_ONEVSONE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "OneVSOneRpc.pb.h"



//一v一类的枚举定义
enum ConstOneVSOneE
{
	MODULE_ID_ONEVSONE                           = 41,	//一v一模块ID
	RPC_CODE_ONEVSONE_FLUSH_REQUEST              = 4151,	//一v一-->刷新自己的数据-->请求
	RPC_CODE_ONEVSONE_ACT_REQUEST                = 4152,	//一v一-->发起挑战-->请求
	RPC_CODE_ONEVSONE_ACTMESSAGE_NOTIFY          = 4153,	//一v一-->挑战消息-->通知
	RPC_CODE_ONEVSONE_REPLYACT_REQUEST           = 4154,	//一v一-->回应谁的挑战-->请求
	RPC_CODE_ONEVSONE_GETTOP_REQUEST             = 4155,	//一v一-->排行榜数据-->请求
	RPC_CODE_ONEVSONE_ADJUSTMENTSKILL_REQUEST    = 4156,	//一v一-->调整技能-->请求
	RPC_CODE_ONEVSONE_GETSKILL_REQUEST           = 4157,	//一v一-->获取设置的技能-->请求
	RPC_CODE_ONEVSONE_GETACTMESSAGE_REQUEST      = 4158,	//一v一-->获得攻守的信息-->请求
	RPC_CODE_ONEVSONE_ACTRESULTNOTIFY_NOTIFY     = 4159,	//一v一-->战斗结果Notify 叶青给我我就给客户端-->通知


};


//1V1玩家战斗结果信息封装类
class OneVSOneOVOResultInfoWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneOVOResultInfoWraper()
	{
		
		m_UserId = -1;
		m_Damage = 0;
		m_BeHurted = 0;
		m_Healed = 0;
		m_Name = "";
		m_Ranking = 0;
		m_BeforeRanking = -1;
		m_JobID = -1;
		m_HeadICO = "";
		m_LV = -1;
		m_IsWin = 0;

	}
	//赋值构造函数
	OneVSOneOVOResultInfoWraper(const OneVSOneOVOResultInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneOVOResultInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneOVOResultInfo ToPB() const
	{
		OneVSOneOVOResultInfo v;
		v.set_userid( m_UserId );
		v.set_damage( m_Damage );
		v.set_behurted( m_BeHurted );
		v.set_healed( m_Healed );
		v.set_name( m_Name );
		v.set_ranking( m_Ranking );
		v.set_beforeranking( m_BeforeRanking );
		v.set_jobid( m_JobID );
		v.set_headico( m_HeadICO );
		v.set_lv( m_LV );
		v.set_iswin( m_IsWin );

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
		OneVSOneOVOResultInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(USERId) [sint64]</li>\r\n";
		htmlBuff += "<li>Damage(伤害) [sint32]</li>\r\n";
		htmlBuff += "<li>BeHurted(承受伤害) [sint32]</li>\r\n";
		htmlBuff += "<li>Healed(治疗) [sint32]</li>\r\n";
		htmlBuff += "<li>Name(昵称) [string]</li>\r\n";
		htmlBuff += "<li>Ranking(现在的排行名次) [sint32]</li>\r\n";
		htmlBuff += "<li>BeforeRanking(之前的排名) [sint32]</li>\r\n";
		htmlBuff += "<li>JobID(职业ID) [sint32]</li>\r\n";
		htmlBuff += "<li>HeadICO(自定义头像) [string]</li>\r\n";
		htmlBuff += "<li>LV(等级) [sint32]</li>\r\n";
		htmlBuff += "<li>IsWin(是不是赢了1是0不是) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Damage：%di</li>\r\n",m_Damage);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BeHurted：%di</li>\r\n",m_BeHurted);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Healed：%di</li>\r\n",m_Healed);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Name：\""+m_Name+"\"</li>\r\n";
		tmpLine.Fmt("<li>Ranking：%di</li>\r\n",m_Ranking);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BeforeRanking：%di</li>\r\n",m_BeforeRanking);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>JobID：%di</li>\r\n",m_JobID);
		htmlBuff += tmpLine;
		htmlBuff += "<li>HeadICO：\""+m_HeadICO+"\"</li>\r\n";
		tmpLine.Fmt("<li>LV：%di</li>\r\n",m_LV);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsWin：%di</li>\r\n",m_IsWin);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneOVOResultInfo& v)
	{
		m_UserId = v.userid();
		m_Damage = v.damage();
		m_BeHurted = v.behurted();
		m_Healed = v.healed();
		m_Name = v.name();
		m_Ranking = v.ranking();
		m_BeforeRanking = v.beforeranking();
		m_JobID = v.jobid();
		m_HeadICO = v.headico();
		m_LV = v.lv();
		m_IsWin = v.iswin();

	}

private:
	//USERId
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
	//伤害
	INT32 m_Damage;
public:
	void SetDamage( INT32 v)
	{
		m_Damage=v;
	}
	INT32 GetDamage()
	{
		return m_Damage;
	}
	INT32 GetDamage() const
	{
		return m_Damage;
	}
private:
	//承受伤害
	INT32 m_BeHurted;
public:
	void SetBeHurted( INT32 v)
	{
		m_BeHurted=v;
	}
	INT32 GetBeHurted()
	{
		return m_BeHurted;
	}
	INT32 GetBeHurted() const
	{
		return m_BeHurted;
	}
private:
	//治疗
	INT32 m_Healed;
public:
	void SetHealed( INT32 v)
	{
		m_Healed=v;
	}
	INT32 GetHealed()
	{
		return m_Healed;
	}
	INT32 GetHealed() const
	{
		return m_Healed;
	}
private:
	//昵称
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
	//现在的排行名次
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
private:
	//之前的排名
	INT32 m_BeforeRanking;
public:
	void SetBeforeRanking( INT32 v)
	{
		m_BeforeRanking=v;
	}
	INT32 GetBeforeRanking()
	{
		return m_BeforeRanking;
	}
	INT32 GetBeforeRanking() const
	{
		return m_BeforeRanking;
	}
private:
	//职业ID
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
	//自定义头像
	string m_HeadICO;
public:
	void SetHeadICO( const string& v)
	{
		m_HeadICO=v;
	}
	string GetHeadICO()
	{
		return m_HeadICO;
	}
	string GetHeadICO() const
	{
		return m_HeadICO;
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
	//是不是赢了1是0不是
	INT32 m_IsWin;
public:
	void SetIsWin( INT32 v)
	{
		m_IsWin=v;
	}
	INT32 GetIsWin()
	{
		return m_IsWin;
	}
	INT32 GetIsWin() const
	{
		return m_IsWin;
	}

};
//挑战的人封装类
class OneVSOneActPeoWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneActPeoWraper()
	{
		
		m_PlanName = "";
		m_Ranking = -1;
		m_FightingCapacity = -1;
		m_UserId = -1;
		m_MardID = -1;
		m_LV = -1;
		m_HeadPath = "";

	}
	//赋值构造函数
	OneVSOneActPeoWraper(const OneVSOneActPeo& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneActPeo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneActPeo ToPB() const
	{
		OneVSOneActPeo v;
		v.set_planname( m_PlanName );
		v.set_ranking( m_Ranking );
		v.set_fightingcapacity( m_FightingCapacity );
		v.set_userid( m_UserId );
		v.set_mardid( m_MardID );
		v.set_lv( m_LV );
		v.set_headpath( m_HeadPath );

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
		OneVSOneActPeo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>PlanName(昵称) [string]</li>\r\n";
		htmlBuff += "<li>Ranking(排行名次) [sint32]</li>\r\n";
		htmlBuff += "<li>FightingCapacity(战斗力) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>MardID(职业id) [sint32]</li>\r\n";
		htmlBuff += "<li>LV(等级) [sint32]</li>\r\n";
		htmlBuff += "<li>HeadPath(头像路径 防止个性化) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>PlanName：\""+m_PlanName+"\"</li>\r\n";
		tmpLine.Fmt("<li>Ranking：%di</li>\r\n",m_Ranking);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>FightingCapacity：%di</li>\r\n",m_FightingCapacity);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MardID：%di</li>\r\n",m_MardID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>LV：%di</li>\r\n",m_LV);
		htmlBuff += tmpLine;
		htmlBuff += "<li>HeadPath：\""+m_HeadPath+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneActPeo& v)
	{
		m_PlanName = v.planname();
		m_Ranking = v.ranking();
		m_FightingCapacity = v.fightingcapacity();
		m_UserId = v.userid();
		m_MardID = v.mardid();
		m_LV = v.lv();
		m_HeadPath = v.headpath();

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
private:
	//战斗力
	INT32 m_FightingCapacity;
public:
	void SetFightingCapacity( INT32 v)
	{
		m_FightingCapacity=v;
	}
	INT32 GetFightingCapacity()
	{
		return m_FightingCapacity;
	}
	INT32 GetFightingCapacity() const
	{
		return m_FightingCapacity;
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
	//职业id
	INT32 m_MardID;
public:
	void SetMardID( INT32 v)
	{
		m_MardID=v;
	}
	INT32 GetMardID()
	{
		return m_MardID;
	}
	INT32 GetMardID() const
	{
		return m_MardID;
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
	//头像路径 防止个性化
	string m_HeadPath;
public:
	void SetHeadPath( const string& v)
	{
		m_HeadPath=v;
	}
	string GetHeadPath()
	{
		return m_HeadPath;
	}
	string GetHeadPath() const
	{
		return m_HeadPath;
	}

};
//获取设置的技能回应封装类
class OneVSOneRpcGetSkillReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcGetSkillReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	OneVSOneRpcGetSkillReplyWraper(const OneVSOneRpcGetSkillReply& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcGetSkillReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcGetSkillReply ToPB() const
	{
		OneVSOneRpcGetSkillReply v;
		v.set_result( m_Result );
		v.mutable_skilldate()->Reserve(m_SkillDate.size());
		for (int i=0; i<(int)m_SkillDate.size(); i++)
		{
			*v.add_skilldate() = m_SkillDate[i].ToPB();
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
		OneVSOneRpcGetSkillReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillDate(技能数据) [OneSData] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>SkillDate：</li>\r\n";
		if( m_SkillDate.size()>0) htmlBuff += m_SkillDate[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_SkillDate.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_SkillDate[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneRpcGetSkillReply& v)
	{
		m_Result = v.result();
		m_SkillDate.clear();
		m_SkillDate.reserve(v.skilldate_size());
		for( int i=0; i<v.skilldate_size(); i++)
			m_SkillDate.push_back(v.skilldate(i));

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
	//技能数据
	vector<OneSDataWraper> m_SkillDate;
public:
	int SizeSkillDate()
	{
		return m_SkillDate.size();
	}
	const vector<OneSDataWraper>& GetSkillDate() const
	{
		return m_SkillDate;
	}
	OneSDataWraper GetSkillDate(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillDate.size())
		{
			assert(false);
			return OneSDataWraper();
		}
		return m_SkillDate[Index];
	}
	void SetSkillDate( const vector<OneSDataWraper>& v )
	{
		m_SkillDate=v;
	}
	void ClearSkillDate( )
	{
		m_SkillDate.clear();
	}
	void SetSkillDate( int Index, const OneSDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_SkillDate.size())
		{
			assert(false);
			return;
		}
		m_SkillDate[Index] = v;
	}
	void AddSkillDate( const OneSDataWraper& v )
	{
		m_SkillDate.push_back(v);
	}

};
//获得攻守的信息请求封装类
class OneVSOneRpcGetActMessageAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcGetActMessageAskWraper()
	{
		

	}
	//赋值构造函数
	OneVSOneRpcGetActMessageAskWraper(const OneVSOneRpcGetActMessageAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcGetActMessageAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcGetActMessageAsk ToPB() const
	{
		OneVSOneRpcGetActMessageAsk v;

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
		OneVSOneRpcGetActMessageAsk pb;
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
	void Init(const OneVSOneRpcGetActMessageAsk& v)
	{

	}


};
//调整技能回应封装类
class OneVSOneRpcAdjustmentSkillReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcAdjustmentSkillReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	OneVSOneRpcAdjustmentSkillReplyWraper(const OneVSOneRpcAdjustmentSkillReply& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcAdjustmentSkillReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcAdjustmentSkillReply ToPB() const
	{
		OneVSOneRpcAdjustmentSkillReply v;
		v.set_result( m_Result );
		v.mutable_skilldate()->Reserve(m_SkillDate.size());
		for (int i=0; i<(int)m_SkillDate.size(); i++)
		{
			*v.add_skilldate() = m_SkillDate[i].ToPB();
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
		OneVSOneRpcAdjustmentSkillReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillDate(技能数据) [OneSData] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>SkillDate：</li>\r\n";
		if( m_SkillDate.size()>0) htmlBuff += m_SkillDate[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_SkillDate.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_SkillDate[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneRpcAdjustmentSkillReply& v)
	{
		m_Result = v.result();
		m_SkillDate.clear();
		m_SkillDate.reserve(v.skilldate_size());
		for( int i=0; i<v.skilldate_size(); i++)
			m_SkillDate.push_back(v.skilldate(i));

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
	//技能数据
	vector<OneSDataWraper> m_SkillDate;
public:
	int SizeSkillDate()
	{
		return m_SkillDate.size();
	}
	const vector<OneSDataWraper>& GetSkillDate() const
	{
		return m_SkillDate;
	}
	OneSDataWraper GetSkillDate(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillDate.size())
		{
			assert(false);
			return OneSDataWraper();
		}
		return m_SkillDate[Index];
	}
	void SetSkillDate( const vector<OneSDataWraper>& v )
	{
		m_SkillDate=v;
	}
	void ClearSkillDate( )
	{
		m_SkillDate.clear();
	}
	void SetSkillDate( int Index, const OneSDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_SkillDate.size())
		{
			assert(false);
			return;
		}
		m_SkillDate[Index] = v;
	}
	void AddSkillDate( const OneSDataWraper& v )
	{
		m_SkillDate.push_back(v);
	}

};
//获取设置的技能请求封装类
class OneVSOneRpcGetSkillAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcGetSkillAskWraper()
	{
		

	}
	//赋值构造函数
	OneVSOneRpcGetSkillAskWraper(const OneVSOneRpcGetSkillAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcGetSkillAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcGetSkillAsk ToPB() const
	{
		OneVSOneRpcGetSkillAsk v;

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
		OneVSOneRpcGetSkillAsk pb;
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
	void Init(const OneVSOneRpcGetSkillAsk& v)
	{

	}


};
//战斗结果Notify 叶青给我我就给客户端通知封装类
class OneVSOneRpcACTResultNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcACTResultNotifyNotifyWraper()
	{
		
		m_IsChanllengorWon = 0;
		m_Chanllengor = OneVSOneOVOResultInfoWraper();
		m_BeAttacked = OneVSOneOVOResultInfoWraper();

	}
	//赋值构造函数
	OneVSOneRpcACTResultNotifyNotifyWraper(const OneVSOneRpcACTResultNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcACTResultNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcACTResultNotifyNotify ToPB() const
	{
		OneVSOneRpcACTResultNotifyNotify v;
		v.set_ischanllengorwon( m_IsChanllengorWon );
		*v.mutable_chanllengor()= m_Chanllengor.ToPB();
		*v.mutable_beattacked()= m_BeAttacked.ToPB();

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
		OneVSOneRpcACTResultNotifyNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>IsChanllengorWon(挑战方是否赢了) [sint32]</li>\r\n";
		htmlBuff += "<li>Chanllengor(攻击者信息) [OVOResultInfo]</li>\r\n";
		htmlBuff += "<li>BeAttacked(被攻击者信息) [OVOResultInfo]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>IsChanllengorWon：%di</li>\r\n",m_IsChanllengorWon);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Chanllengor：</li>\r\n";
		htmlBuff += m_Chanllengor.HtmlDescHeader();
		htmlBuff += m_Chanllengor.ToHtml();
		htmlBuff += "<li>BeAttacked：</li>\r\n";
		htmlBuff += m_BeAttacked.HtmlDescHeader();
		htmlBuff += m_BeAttacked.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneRpcACTResultNotifyNotify& v)
	{
		m_IsChanllengorWon = v.ischanllengorwon();
		m_Chanllengor = v.chanllengor();
		m_BeAttacked = v.beattacked();

	}

private:
	//挑战方是否赢了
	INT32 m_IsChanllengorWon;
public:
	void SetIsChanllengorWon( INT32 v)
	{
		m_IsChanllengorWon=v;
	}
	INT32 GetIsChanllengorWon()
	{
		return m_IsChanllengorWon;
	}
	INT32 GetIsChanllengorWon() const
	{
		return m_IsChanllengorWon;
	}
private:
	//攻击者信息
	OneVSOneOVOResultInfoWraper m_Chanllengor;
public:
	void SetChanllengor( const OneVSOneOVOResultInfoWraper& v)
	{
		m_Chanllengor=v;
	}
	OneVSOneOVOResultInfoWraper GetChanllengor()
	{
		return m_Chanllengor;
	}
	OneVSOneOVOResultInfoWraper GetChanllengor() const
	{
		return m_Chanllengor;
	}
private:
	//被攻击者信息
	OneVSOneOVOResultInfoWraper m_BeAttacked;
public:
	void SetBeAttacked( const OneVSOneOVOResultInfoWraper& v)
	{
		m_BeAttacked=v;
	}
	OneVSOneOVOResultInfoWraper GetBeAttacked()
	{
		return m_BeAttacked;
	}
	OneVSOneOVOResultInfoWraper GetBeAttacked() const
	{
		return m_BeAttacked;
	}

};
//刷新自己的数据请求封装类
class OneVSOneRpcFlushAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcFlushAskWraper()
	{
		
		m_IsOpen = 0;

	}
	//赋值构造函数
	OneVSOneRpcFlushAskWraper(const OneVSOneRpcFlushAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcFlushAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcFlushAsk ToPB() const
	{
		OneVSOneRpcFlushAsk v;
		v.set_isopen( m_IsOpen );

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
		OneVSOneRpcFlushAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>IsOpen(是不是打开界面) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>IsOpen：%di</li>\r\n",m_IsOpen);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneRpcFlushAsk& v)
	{
		m_IsOpen = v.isopen();

	}

private:
	//是不是打开界面
	INT32 m_IsOpen;
public:
	void SetIsOpen( INT32 v)
	{
		m_IsOpen=v;
	}
	INT32 GetIsOpen()
	{
		return m_IsOpen;
	}
	INT32 GetIsOpen() const
	{
		return m_IsOpen;
	}

};
//获得攻守的信息回应封装类
class OneVSOneRpcGetActMessageReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcGetActMessageReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	OneVSOneRpcGetActMessageReplyWraper(const OneVSOneRpcGetActMessageReply& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcGetActMessageReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcGetActMessageReply ToPB() const
	{
		OneVSOneRpcGetActMessageReply v;
		v.set_result( m_Result );
		v.mutable_actmessages()->Reserve(m_ActMessages.size());
		for (int i=0; i<(int)m_ActMessages.size(); i++)
		{
			*v.add_actmessages() = m_ActMessages[i].ToPB();
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
		OneVSOneRpcGetActMessageReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ActMessages(消息记录) [ActMessage] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>ActMessages：</li>\r\n";
		if( m_ActMessages.size()>0) htmlBuff += m_ActMessages[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ActMessages.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ActMessages[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneRpcGetActMessageReply& v)
	{
		m_Result = v.result();
		m_ActMessages.clear();
		m_ActMessages.reserve(v.actmessages_size());
		for( int i=0; i<v.actmessages_size(); i++)
			m_ActMessages.push_back(v.actmessages(i));

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
	//消息记录
	vector<ActMessageWraper> m_ActMessages;
public:
	int SizeActMessages()
	{
		return m_ActMessages.size();
	}
	const vector<ActMessageWraper>& GetActMessages() const
	{
		return m_ActMessages;
	}
	ActMessageWraper GetActMessages(int Index) const
	{
		if(Index<0 || Index>=(int)m_ActMessages.size())
		{
			assert(false);
			return ActMessageWraper();
		}
		return m_ActMessages[Index];
	}
	void SetActMessages( const vector<ActMessageWraper>& v )
	{
		m_ActMessages=v;
	}
	void ClearActMessages( )
	{
		m_ActMessages.clear();
	}
	void SetActMessages( int Index, const ActMessageWraper& v )
	{
		if(Index<0 || Index>=(int)m_ActMessages.size())
		{
			assert(false);
			return;
		}
		m_ActMessages[Index] = v;
	}
	void AddActMessages( const ActMessageWraper& v )
	{
		m_ActMessages.push_back(v);
	}

};
//调整技能请求封装类
class OneVSOneRpcAdjustmentSkillAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcAdjustmentSkillAskWraper()
	{
		

	}
	//赋值构造函数
	OneVSOneRpcAdjustmentSkillAskWraper(const OneVSOneRpcAdjustmentSkillAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcAdjustmentSkillAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcAdjustmentSkillAsk ToPB() const
	{
		OneVSOneRpcAdjustmentSkillAsk v;
		v.mutable_skilldate()->Reserve(m_SkillDate.size());
		for (int i=0; i<(int)m_SkillDate.size(); i++)
		{
			*v.add_skilldate() = m_SkillDate[i].ToPB();
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
		OneVSOneRpcAdjustmentSkillAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SkillDate(技能数据) [OneSData] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>SkillDate：</li>\r\n";
		if( m_SkillDate.size()>0) htmlBuff += m_SkillDate[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_SkillDate.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_SkillDate[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneRpcAdjustmentSkillAsk& v)
	{
		m_SkillDate.clear();
		m_SkillDate.reserve(v.skilldate_size());
		for( int i=0; i<v.skilldate_size(); i++)
			m_SkillDate.push_back(v.skilldate(i));

	}

private:
	//技能数据
	vector<OneSDataWraper> m_SkillDate;
public:
	int SizeSkillDate()
	{
		return m_SkillDate.size();
	}
	const vector<OneSDataWraper>& GetSkillDate() const
	{
		return m_SkillDate;
	}
	OneSDataWraper GetSkillDate(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillDate.size())
		{
			assert(false);
			return OneSDataWraper();
		}
		return m_SkillDate[Index];
	}
	void SetSkillDate( const vector<OneSDataWraper>& v )
	{
		m_SkillDate=v;
	}
	void ClearSkillDate( )
	{
		m_SkillDate.clear();
	}
	void SetSkillDate( int Index, const OneSDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_SkillDate.size())
		{
			assert(false);
			return;
		}
		m_SkillDate[Index] = v;
	}
	void AddSkillDate( const OneSDataWraper& v )
	{
		m_SkillDate.push_back(v);
	}

};
//发起挑战回应封装类
class OneVSOneRpcActReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcActReplyWraper()
	{
		
		m_Result = -9999;
		m_UserId = -1;
		m_PlanName = "";
		m_OneVSOneNum = -1;
		m_Ranking = -1;
		m_IsCopy = 0;

	}
	//赋值构造函数
	OneVSOneRpcActReplyWraper(const OneVSOneRpcActReply& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcActReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcActReply ToPB() const
	{
		OneVSOneRpcActReply v;
		v.set_result( m_Result );
		v.set_userid( m_UserId );
		v.set_planname( m_PlanName );
		v.set_onevsonenum( m_OneVSOneNum );
		v.set_ranking( m_Ranking );
		v.set_iscopy( m_IsCopy );

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
		OneVSOneRpcActReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>PlanName(昵称) [string]</li>\r\n";
		htmlBuff += "<li>OneVSOneNum(一对一的剩余次数) [sint32]</li>\r\n";
		htmlBuff += "<li>Ranking(排行名次) [sint32]</li>\r\n";
		htmlBuff += "<li>IsCopy(对方是不是复制人1是0不是) [sint32]</li>\r\n";

		
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
		htmlBuff += "<li>PlanName：\""+m_PlanName+"\"</li>\r\n";
		tmpLine.Fmt("<li>OneVSOneNum：%di</li>\r\n",m_OneVSOneNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Ranking：%di</li>\r\n",m_Ranking);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsCopy：%di</li>\r\n",m_IsCopy);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneRpcActReply& v)
	{
		m_Result = v.result();
		m_UserId = v.userid();
		m_PlanName = v.planname();
		m_OneVSOneNum = v.onevsonenum();
		m_Ranking = v.ranking();
		m_IsCopy = v.iscopy();

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
	//一对一的剩余次数
	INT32 m_OneVSOneNum;
public:
	void SetOneVSOneNum( INT32 v)
	{
		m_OneVSOneNum=v;
	}
	INT32 GetOneVSOneNum()
	{
		return m_OneVSOneNum;
	}
	INT32 GetOneVSOneNum() const
	{
		return m_OneVSOneNum;
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
private:
	//对方是不是复制人1是0不是
	INT32 m_IsCopy;
public:
	void SetIsCopy( INT32 v)
	{
		m_IsCopy=v;
	}
	INT32 GetIsCopy()
	{
		return m_IsCopy;
	}
	INT32 GetIsCopy() const
	{
		return m_IsCopy;
	}

};
//挑战消息通知封装类
class OneVSOneRpcActMessageNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcActMessageNotifyWraper()
	{
		
		m_UserId = -1;
		m_PlanName = "";

	}
	//赋值构造函数
	OneVSOneRpcActMessageNotifyWraper(const OneVSOneRpcActMessageNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcActMessageNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcActMessageNotify ToPB() const
	{
		OneVSOneRpcActMessageNotify v;
		v.set_userid( m_UserId );
		v.set_planname( m_PlanName );

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
		OneVSOneRpcActMessageNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>PlanName(昵称) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PlanName：\""+m_PlanName+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneRpcActMessageNotify& v)
	{
		m_UserId = v.userid();
		m_PlanName = v.planname();

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

};
//刷新自己的数据回应封装类
class OneVSOneRpcFlushReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcFlushReplyWraper()
	{
		
		m_Result = -9999;
		m_Ranking = -1;
		m_FightingCapacity = -1;
		m_OneVSOneNum = -1;
		m_IsOpen = 0;
		m_LockTime = -1;

	}
	//赋值构造函数
	OneVSOneRpcFlushReplyWraper(const OneVSOneRpcFlushReply& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcFlushReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcFlushReply ToPB() const
	{
		OneVSOneRpcFlushReply v;
		v.set_result( m_Result );
		v.set_ranking( m_Ranking );
		v.set_fightingcapacity( m_FightingCapacity );
		v.set_onevsonenum( m_OneVSOneNum );
		v.mutable_timerankings()->Reserve(m_TimeRankings.size());
		for (int i=0; i<(int)m_TimeRankings.size(); i++)
		{
			*v.add_timerankings() = m_TimeRankings[i].ToPB();
		}
		v.mutable_actpeos()->Reserve(m_ActPeos.size());
		for (int i=0; i<(int)m_ActPeos.size(); i++)
		{
			*v.add_actpeos() = m_ActPeos[i].ToPB();
		}
		v.set_isopen( m_IsOpen );
		v.set_locktime( m_LockTime );

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
		OneVSOneRpcFlushReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Ranking(排行名次) [sint32]</li>\r\n";
		htmlBuff += "<li>FightingCapacity(战斗力) [sint32]</li>\r\n";
		htmlBuff += "<li>OneVSOneNum(一对一的剩余次数) [sint32]</li>\r\n";
		htmlBuff += "<li>TimeRankings(时间名次) [TimeTop] Array</li>\r\n";
		htmlBuff += "<li>ActPeos(挑战的人) [ActPeo] Array</li>\r\n";
		htmlBuff += "<li>IsOpen(是不是打开界面) [sint32]</li>\r\n";
		htmlBuff += "<li>LockTime(锁定时间 秒 小于等于0 忽略) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Ranking：%di</li>\r\n",m_Ranking);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>FightingCapacity：%di</li>\r\n",m_FightingCapacity);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>OneVSOneNum：%di</li>\r\n",m_OneVSOneNum);
		htmlBuff += tmpLine;
		htmlBuff += "<li>TimeRankings：</li>\r\n";
		if( m_TimeRankings.size()>0) htmlBuff += m_TimeRankings[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_TimeRankings.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_TimeRankings[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>ActPeos：</li>\r\n";
		if( m_ActPeos.size()>0) htmlBuff += m_ActPeos[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ActPeos.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ActPeos[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>IsOpen：%di</li>\r\n",m_IsOpen);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>LockTime：%di</li>\r\n",m_LockTime);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneRpcFlushReply& v)
	{
		m_Result = v.result();
		m_Ranking = v.ranking();
		m_FightingCapacity = v.fightingcapacity();
		m_OneVSOneNum = v.onevsonenum();
		m_TimeRankings.clear();
		m_TimeRankings.reserve(v.timerankings_size());
		for( int i=0; i<v.timerankings_size(); i++)
			m_TimeRankings.push_back(v.timerankings(i));
		m_ActPeos.clear();
		m_ActPeos.reserve(v.actpeos_size());
		for( int i=0; i<v.actpeos_size(); i++)
			m_ActPeos.push_back(v.actpeos(i));
		m_IsOpen = v.isopen();
		m_LockTime = v.locktime();

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
private:
	//战斗力
	INT32 m_FightingCapacity;
public:
	void SetFightingCapacity( INT32 v)
	{
		m_FightingCapacity=v;
	}
	INT32 GetFightingCapacity()
	{
		return m_FightingCapacity;
	}
	INT32 GetFightingCapacity() const
	{
		return m_FightingCapacity;
	}
private:
	//一对一的剩余次数
	INT32 m_OneVSOneNum;
public:
	void SetOneVSOneNum( INT32 v)
	{
		m_OneVSOneNum=v;
	}
	INT32 GetOneVSOneNum()
	{
		return m_OneVSOneNum;
	}
	INT32 GetOneVSOneNum() const
	{
		return m_OneVSOneNum;
	}
private:
	//时间名次
	vector<TimeTopWraper> m_TimeRankings;
public:
	int SizeTimeRankings()
	{
		return m_TimeRankings.size();
	}
	const vector<TimeTopWraper>& GetTimeRankings() const
	{
		return m_TimeRankings;
	}
	TimeTopWraper GetTimeRankings(int Index) const
	{
		if(Index<0 || Index>=(int)m_TimeRankings.size())
		{
			assert(false);
			return TimeTopWraper();
		}
		return m_TimeRankings[Index];
	}
	void SetTimeRankings( const vector<TimeTopWraper>& v )
	{
		m_TimeRankings=v;
	}
	void ClearTimeRankings( )
	{
		m_TimeRankings.clear();
	}
	void SetTimeRankings( int Index, const TimeTopWraper& v )
	{
		if(Index<0 || Index>=(int)m_TimeRankings.size())
		{
			assert(false);
			return;
		}
		m_TimeRankings[Index] = v;
	}
	void AddTimeRankings( const TimeTopWraper& v )
	{
		m_TimeRankings.push_back(v);
	}
private:
	//挑战的人
	vector<OneVSOneActPeoWraper> m_ActPeos;
public:
	int SizeActPeos()
	{
		return m_ActPeos.size();
	}
	const vector<OneVSOneActPeoWraper>& GetActPeos() const
	{
		return m_ActPeos;
	}
	OneVSOneActPeoWraper GetActPeos(int Index) const
	{
		if(Index<0 || Index>=(int)m_ActPeos.size())
		{
			assert(false);
			return OneVSOneActPeoWraper();
		}
		return m_ActPeos[Index];
	}
	void SetActPeos( const vector<OneVSOneActPeoWraper>& v )
	{
		m_ActPeos=v;
	}
	void ClearActPeos( )
	{
		m_ActPeos.clear();
	}
	void SetActPeos( int Index, const OneVSOneActPeoWraper& v )
	{
		if(Index<0 || Index>=(int)m_ActPeos.size())
		{
			assert(false);
			return;
		}
		m_ActPeos[Index] = v;
	}
	void AddActPeos( const OneVSOneActPeoWraper& v )
	{
		m_ActPeos.push_back(v);
	}
private:
	//是不是打开界面
	INT32 m_IsOpen;
public:
	void SetIsOpen( INT32 v)
	{
		m_IsOpen=v;
	}
	INT32 GetIsOpen()
	{
		return m_IsOpen;
	}
	INT32 GetIsOpen() const
	{
		return m_IsOpen;
	}
private:
	//锁定时间 秒 小于等于0 忽略
	INT32 m_LockTime;
public:
	void SetLockTime( INT32 v)
	{
		m_LockTime=v;
	}
	INT32 GetLockTime()
	{
		return m_LockTime;
	}
	INT32 GetLockTime() const
	{
		return m_LockTime;
	}

};
//发起挑战请求封装类
class OneVSOneRpcActAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcActAskWraper()
	{
		
		m_UserId = -1;
		m_Ranking = -1;

	}
	//赋值构造函数
	OneVSOneRpcActAskWraper(const OneVSOneRpcActAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcActAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcActAsk ToPB() const
	{
		OneVSOneRpcActAsk v;
		v.set_userid( m_UserId );
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
		OneVSOneRpcActAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>Ranking(排行名次) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Ranking：%di</li>\r\n",m_Ranking);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneRpcActAsk& v)
	{
		m_UserId = v.userid();
		m_Ranking = v.ranking();

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
//排行榜数据请求封装类
class OneVSOneRpcGetTopAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcGetTopAskWraper()
	{
		

	}
	//赋值构造函数
	OneVSOneRpcGetTopAskWraper(const OneVSOneRpcGetTopAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcGetTopAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcGetTopAsk ToPB() const
	{
		OneVSOneRpcGetTopAsk v;

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
		OneVSOneRpcGetTopAsk pb;
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
	void Init(const OneVSOneRpcGetTopAsk& v)
	{

	}


};
//排行榜数据回应封装类
class OneVSOneRpcGetTopReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcGetTopReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	OneVSOneRpcGetTopReplyWraper(const OneVSOneRpcGetTopReply& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcGetTopReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcGetTopReply ToPB() const
	{
		OneVSOneRpcGetTopReply v;
		v.set_result( m_Result );
		v.mutable_topmesses()->Reserve(m_TopMesses.size());
		for (int i=0; i<(int)m_TopMesses.size(); i++)
		{
			*v.add_topmesses() = m_TopMesses[i].ToPB();
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
		OneVSOneRpcGetTopReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TopMesses(排行榜数据) [TopMess] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>TopMesses：</li>\r\n";
		if( m_TopMesses.size()>0) htmlBuff += m_TopMesses[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_TopMesses.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_TopMesses[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneRpcGetTopReply& v)
	{
		m_Result = v.result();
		m_TopMesses.clear();
		m_TopMesses.reserve(v.topmesses_size());
		for( int i=0; i<v.topmesses_size(); i++)
			m_TopMesses.push_back(v.topmesses(i));

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
	//排行榜数据
	vector<TopMessWraper> m_TopMesses;
public:
	int SizeTopMesses()
	{
		return m_TopMesses.size();
	}
	const vector<TopMessWraper>& GetTopMesses() const
	{
		return m_TopMesses;
	}
	TopMessWraper GetTopMesses(int Index) const
	{
		if(Index<0 || Index>=(int)m_TopMesses.size())
		{
			assert(false);
			return TopMessWraper();
		}
		return m_TopMesses[Index];
	}
	void SetTopMesses( const vector<TopMessWraper>& v )
	{
		m_TopMesses=v;
	}
	void ClearTopMesses( )
	{
		m_TopMesses.clear();
	}
	void SetTopMesses( int Index, const TopMessWraper& v )
	{
		if(Index<0 || Index>=(int)m_TopMesses.size())
		{
			assert(false);
			return;
		}
		m_TopMesses[Index] = v;
	}
	void AddTopMesses( const TopMessWraper& v )
	{
		m_TopMesses.push_back(v);
	}

};
//回应谁的挑战请求封装类
class OneVSOneRpcReplyActAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcReplyActAskWraper()
	{
		
		m_UserId = -1;
		m_IsOK = -1;

	}
	//赋值构造函数
	OneVSOneRpcReplyActAskWraper(const OneVSOneRpcReplyActAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcReplyActAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcReplyActAsk ToPB() const
	{
		OneVSOneRpcReplyActAsk v;
		v.set_userid( m_UserId );
		v.set_isok( m_IsOK );

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
		OneVSOneRpcReplyActAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>IsOK(是不是同意了 1是 其他不是) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsOK：%di</li>\r\n",m_IsOK);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneRpcReplyActAsk& v)
	{
		m_UserId = v.userid();
		m_IsOK = v.isok();

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
	//是不是同意了 1是 其他不是
	INT32 m_IsOK;
public:
	void SetIsOK( INT32 v)
	{
		m_IsOK=v;
	}
	INT32 GetIsOK()
	{
		return m_IsOK;
	}
	INT32 GetIsOK() const
	{
		return m_IsOK;
	}

};
//回应谁的挑战回应封装类
class OneVSOneRpcReplyActReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	OneVSOneRpcReplyActReplyWraper()
	{
		
		m_Result = -9999;
		m_UserId = -1;
		m_IsOK = -1;
		m_PlanName = "";

	}
	//赋值构造函数
	OneVSOneRpcReplyActReplyWraper(const OneVSOneRpcReplyActReply& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneRpcReplyActReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneRpcReplyActReply ToPB() const
	{
		OneVSOneRpcReplyActReply v;
		v.set_result( m_Result );
		v.set_userid( m_UserId );
		v.set_isok( m_IsOK );
		v.set_planname( m_PlanName );

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
		OneVSOneRpcReplyActReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>IsOK(是不是同意了 1是 其他不是) [sint32]</li>\r\n";
		htmlBuff += "<li>PlanName(昵称) [string]</li>\r\n";

		
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
		tmpLine.Fmt("<li>IsOK：%di</li>\r\n",m_IsOK);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PlanName：\""+m_PlanName+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneRpcReplyActReply& v)
	{
		m_Result = v.result();
		m_UserId = v.userid();
		m_IsOK = v.isok();
		m_PlanName = v.planname();

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
	//是不是同意了 1是 其他不是
	INT32 m_IsOK;
public:
	void SetIsOK( INT32 v)
	{
		m_IsOK=v;
	}
	INT32 GetIsOK()
	{
		return m_IsOK;
	}
	INT32 GetIsOK() const
	{
		return m_IsOK;
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

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<OneVSOneRpcFlushAskWraper>{ enum{ID=RPC_CODE_ONEVSONE_FLUSH_REQUEST};};
template<> struct MessageIdT<OneVSOneRpcFlushReplyWraper>{ enum{ID=RPC_CODE_ONEVSONE_FLUSH_REQUEST};};
template<> struct MessageIdT<OneVSOneRpcActAskWraper>{ enum{ID=RPC_CODE_ONEVSONE_ACT_REQUEST};};
template<> struct MessageIdT<OneVSOneRpcActReplyWraper>{ enum{ID=RPC_CODE_ONEVSONE_ACT_REQUEST};};
template<> struct MessageIdT<OneVSOneRpcActMessageNotifyWraper>{ enum{ID=RPC_CODE_ONEVSONE_ACTMESSAGE_NOTIFY};};
template<> struct MessageIdT<OneVSOneRpcReplyActAskWraper>{ enum{ID=RPC_CODE_ONEVSONE_REPLYACT_REQUEST};};
template<> struct MessageIdT<OneVSOneRpcReplyActReplyWraper>{ enum{ID=RPC_CODE_ONEVSONE_REPLYACT_REQUEST};};
template<> struct MessageIdT<OneVSOneRpcGetTopAskWraper>{ enum{ID=RPC_CODE_ONEVSONE_GETTOP_REQUEST};};
template<> struct MessageIdT<OneVSOneRpcGetTopReplyWraper>{ enum{ID=RPC_CODE_ONEVSONE_GETTOP_REQUEST};};
template<> struct MessageIdT<OneVSOneRpcAdjustmentSkillAskWraper>{ enum{ID=RPC_CODE_ONEVSONE_ADJUSTMENTSKILL_REQUEST};};
template<> struct MessageIdT<OneVSOneRpcAdjustmentSkillReplyWraper>{ enum{ID=RPC_CODE_ONEVSONE_ADJUSTMENTSKILL_REQUEST};};
template<> struct MessageIdT<OneVSOneRpcGetSkillAskWraper>{ enum{ID=RPC_CODE_ONEVSONE_GETSKILL_REQUEST};};
template<> struct MessageIdT<OneVSOneRpcGetSkillReplyWraper>{ enum{ID=RPC_CODE_ONEVSONE_GETSKILL_REQUEST};};
template<> struct MessageIdT<OneVSOneRpcGetActMessageAskWraper>{ enum{ID=RPC_CODE_ONEVSONE_GETACTMESSAGE_REQUEST};};
template<> struct MessageIdT<OneVSOneRpcGetActMessageReplyWraper>{ enum{ID=RPC_CODE_ONEVSONE_GETACTMESSAGE_REQUEST};};
template<> struct MessageIdT<OneVSOneRpcACTResultNotifyNotifyWraper>{ enum{ID=RPC_CODE_ONEVSONE_ACTRESULTNOTIFY_NOTIFY};};


#endif
