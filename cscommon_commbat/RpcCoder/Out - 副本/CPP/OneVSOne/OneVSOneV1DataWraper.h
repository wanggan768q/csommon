/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperOneVSOne.h
* Author:       甘业清
* Description:  一v一同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_ONEVSONE_H
#define __SYNC_WRAPER_ONEVSONE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "OneVSOneV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//一对一的数据封装类
class OneVSOneOneVSOneDateWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<OneVSOneOneVSOneDateWraperV1>
{
public:
	//构造函数
	OneVSOneOneVSOneDateWraperV1()
	{
		SetDataWraper( this );

		m_OneVSOneNum = -1;
		m_SaveTime = -1;
		m_Ranking = 0;

	}
	//赋值构造函数
	OneVSOneOneVSOneDateWraperV1(const OneVSOneOneVSOneDateV1& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneOneVSOneDateV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneOneVSOneDateV1 ToPB() const
	{
		OneVSOneOneVSOneDateV1 v;
		v.mutable_skilldate()->Reserve(m_SkillDate.size());
		for (int i=0; i<(int)m_SkillDate.size(); i++)
		{
			*v.add_skilldate() = m_SkillDate[i].ToPB();
		}
		v.mutable_log()->Reserve(m_Log.size());
		for (int i=0; i<(int)m_Log.size(); i++)
		{
			*v.add_log() = m_Log[i].ToPB();
		}
		v.set_onevsonenum( m_OneVSOneNum );
		v.set_savetime( m_SaveTime );
		v.set_ranking( m_Ranking );
		v.mutable_rankingtimes()->Reserve(m_RankingTimes.size());
		for (int i=0; i<(int)m_RankingTimes.size(); i++)
		{
			*v.add_rankingtimes() = m_RankingTimes[i].ToPB();
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
		OneVSOneOneVSOneDateV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SkillDate(技能数据) [OneSData] Array</li>\r\n";
		htmlBuff += "<li>Log(log日志) [ActMessage] Array</li>\r\n";
		htmlBuff += "<li>OneVSOneNum(一对一的剩余次数) [sint32]</li>\r\n";
		htmlBuff += "<li>SaveTime(格林威治时间服务器用) [sint64]</li>\r\n";
		htmlBuff += "<li>Ranking(排行名次) [sint32]</li>\r\n";
		htmlBuff += "<li>RankingTimes(排行名次 时间段的) [TimeTop] Array</li>\r\n";

		
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
		htmlBuff += "<li>Log：</li>\r\n";
		if( m_Log.size()>0) htmlBuff += m_Log[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_Log.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_Log[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>OneVSOneNum：%di</li>\r\n",m_OneVSOneNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SaveTime：%lldL</li>\r\n",m_SaveTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Ranking：%di</li>\r\n",m_Ranking);
		htmlBuff += tmpLine;
		htmlBuff += "<li>RankingTimes：</li>\r\n";
		if( m_RankingTimes.size()>0) htmlBuff += m_RankingTimes[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_RankingTimes.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_RankingTimes[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneOneVSOneDateV1& v)
	{
		m_SkillDate.clear();
		m_SkillDate.reserve(v.skilldate_size());
		for( int i=0; i<v.skilldate_size(); i++)
			m_SkillDate.push_back(v.skilldate(i));
		m_Log.clear();
		m_Log.reserve(v.log_size());
		for( int i=0; i<v.log_size(); i++)
			m_Log.push_back(v.log(i));
		m_OneVSOneNum = v.onevsonenum();
		m_SaveTime = v.savetime();
		m_Ranking = v.ranking();
		m_RankingTimes.clear();
		m_RankingTimes.reserve(v.rankingtimes_size());
		for( int i=0; i<v.rankingtimes_size(); i++)
			m_RankingTimes.push_back(v.rankingtimes(i));

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
private:
	//log日志
	vector<ActMessageWraper> m_Log;
public:
	int SizeLog()
	{
		return m_Log.size();
	}
	const vector<ActMessageWraper>& GetLog() const
	{
		return m_Log;
	}
	ActMessageWraper GetLog(int Index) const
	{
		if(Index<0 || Index>=(int)m_Log.size())
		{
			assert(false);
			return ActMessageWraper();
		}
		return m_Log[Index];
	}
	void SetLog( const vector<ActMessageWraper>& v )
	{
		m_Log=v;
	}
	void ClearLog( )
	{
		m_Log.clear();
	}
	void SetLog( int Index, const ActMessageWraper& v )
	{
		if(Index<0 || Index>=(int)m_Log.size())
		{
			assert(false);
			return;
		}
		m_Log[Index] = v;
	}
	void AddLog( const ActMessageWraper& v )
	{
		m_Log.push_back(v);
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
	//格林威治时间服务器用
	INT64 m_SaveTime;
public:
	void SetSaveTime( INT64 v)
	{
		m_SaveTime=v;
	}
	INT64 GetSaveTime()
	{
		return m_SaveTime;
	}
	INT64 GetSaveTime() const
	{
		return m_SaveTime;
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
	//排行名次 时间段的
	vector<TimeTopWraper> m_RankingTimes;
public:
	int SizeRankingTimes()
	{
		return m_RankingTimes.size();
	}
	const vector<TimeTopWraper>& GetRankingTimes() const
	{
		return m_RankingTimes;
	}
	TimeTopWraper GetRankingTimes(int Index) const
	{
		if(Index<0 || Index>=(int)m_RankingTimes.size())
		{
			assert(false);
			return TimeTopWraper();
		}
		return m_RankingTimes[Index];
	}
	void SetRankingTimes( const vector<TimeTopWraper>& v )
	{
		m_RankingTimes=v;
	}
	void ClearRankingTimes( )
	{
		m_RankingTimes.clear();
	}
	void SetRankingTimes( int Index, const TimeTopWraper& v )
	{
		if(Index<0 || Index>=(int)m_RankingTimes.size())
		{
			assert(false);
			return;
		}
		m_RankingTimes[Index] = v;
	}
	void AddRankingTimes( const TimeTopWraper& v )
	{
		m_RankingTimes.push_back(v);
	}

};

#endif
