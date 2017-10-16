/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperActivityPlay.h
* Author:       甘业清
* Description:  活动玩法同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_ACTIVITYPLAY_H
#define __SYNC_WRAPER_ACTIVITYPLAY_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "ActivityPlayV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//活动数据封装类
class ActivityPlayActivityDataWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<ActivityPlayActivityDataWraperV1>
{
public:
	//构造函数
	ActivityPlayActivityDataWraperV1()
	{
		SetDataWraper( this );


	}
	//赋值构造函数
	ActivityPlayActivityDataWraperV1(const ActivityPlayActivityDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityPlayActivityDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityPlayActivityDataV1 ToPB() const
	{
		ActivityPlayActivityDataV1 v;
		v.mutable_thiefdata()->Reserve(m_ThiefData.size());
		for (int i=0; i<(int)m_ThiefData.size(); i++)
		{
			*v.add_thiefdata() = m_ThiefData[i].ToPB();
		}
		v.mutable_subduemonsterdata()->Reserve(m_SubdueMonsterData.size());
		for (int i=0; i<(int)m_SubdueMonsterData.size(); i++)
		{
			*v.add_subduemonsterdata() = m_SubdueMonsterData[i].ToPB();
		}
		v.mutable_worldbossdata()->Reserve(m_WorldBossData.size());
		for (int i=0; i<(int)m_WorldBossData.size(); i++)
		{
			*v.add_worldbossdata() = m_WorldBossData[i].ToPB();
		}
		v.mutable_worldbossrank()->Reserve(m_WorldBossRank.size());
		for (int i=0; i<(int)m_WorldBossRank.size(); i++)
		{
			*v.add_worldbossrank() = m_WorldBossRank[i].ToPB();
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
		ActivityPlayActivityDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ThiefData(江洋大盗数据) [ActivityNpcData] Array</li>\r\n";
		htmlBuff += "<li>SubdueMonsterData(降妖除魔数据) [ActivityNpcData] Array</li>\r\n";
		htmlBuff += "<li>WorldBossData(世界Boss数据) [WorldBossObj] Array</li>\r\n";
		htmlBuff += "<li>WorldBossRank(世界Boss排名) [WorldBossRankObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ThiefData：</li>\r\n";
		if( m_ThiefData.size()>0) htmlBuff += m_ThiefData[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ThiefData.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ThiefData[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>SubdueMonsterData：</li>\r\n";
		if( m_SubdueMonsterData.size()>0) htmlBuff += m_SubdueMonsterData[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_SubdueMonsterData.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_SubdueMonsterData[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>WorldBossData：</li>\r\n";
		if( m_WorldBossData.size()>0) htmlBuff += m_WorldBossData[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_WorldBossData.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_WorldBossData[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>WorldBossRank：</li>\r\n";
		if( m_WorldBossRank.size()>0) htmlBuff += m_WorldBossRank[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_WorldBossRank.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_WorldBossRank[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityPlayActivityDataV1& v)
	{
		m_ThiefData.clear();
		m_ThiefData.reserve(v.thiefdata_size());
		for( int i=0; i<v.thiefdata_size(); i++)
			m_ThiefData.push_back(v.thiefdata(i));
		m_SubdueMonsterData.clear();
		m_SubdueMonsterData.reserve(v.subduemonsterdata_size());
		for( int i=0; i<v.subduemonsterdata_size(); i++)
			m_SubdueMonsterData.push_back(v.subduemonsterdata(i));
		m_WorldBossData.clear();
		m_WorldBossData.reserve(v.worldbossdata_size());
		for( int i=0; i<v.worldbossdata_size(); i++)
			m_WorldBossData.push_back(v.worldbossdata(i));
		m_WorldBossRank.clear();
		m_WorldBossRank.reserve(v.worldbossrank_size());
		for( int i=0; i<v.worldbossrank_size(); i++)
			m_WorldBossRank.push_back(v.worldbossrank(i));

	}

private:
	//江洋大盗数据
	vector<ActivityNpcDataWraper> m_ThiefData;
public:
	int SizeThiefData()
	{
		return m_ThiefData.size();
	}
	const vector<ActivityNpcDataWraper>& GetThiefData() const
	{
		return m_ThiefData;
	}
	ActivityNpcDataWraper GetThiefData(int Index) const
	{
		if(Index<0 || Index>=(int)m_ThiefData.size())
		{
			assert(false);
			return ActivityNpcDataWraper();
		}
		return m_ThiefData[Index];
	}
	void SetThiefData( const vector<ActivityNpcDataWraper>& v )
	{
		m_ThiefData=v;
	}
	void ClearThiefData( )
	{
		m_ThiefData.clear();
	}
	void SetThiefData( int Index, const ActivityNpcDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_ThiefData.size())
		{
			assert(false);
			return;
		}
		m_ThiefData[Index] = v;
	}
	void AddThiefData( const ActivityNpcDataWraper& v )
	{
		m_ThiefData.push_back(v);
	}
private:
	//降妖除魔数据
	vector<ActivityNpcDataWraper> m_SubdueMonsterData;
public:
	int SizeSubdueMonsterData()
	{
		return m_SubdueMonsterData.size();
	}
	const vector<ActivityNpcDataWraper>& GetSubdueMonsterData() const
	{
		return m_SubdueMonsterData;
	}
	ActivityNpcDataWraper GetSubdueMonsterData(int Index) const
	{
		if(Index<0 || Index>=(int)m_SubdueMonsterData.size())
		{
			assert(false);
			return ActivityNpcDataWraper();
		}
		return m_SubdueMonsterData[Index];
	}
	void SetSubdueMonsterData( const vector<ActivityNpcDataWraper>& v )
	{
		m_SubdueMonsterData=v;
	}
	void ClearSubdueMonsterData( )
	{
		m_SubdueMonsterData.clear();
	}
	void SetSubdueMonsterData( int Index, const ActivityNpcDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_SubdueMonsterData.size())
		{
			assert(false);
			return;
		}
		m_SubdueMonsterData[Index] = v;
	}
	void AddSubdueMonsterData( const ActivityNpcDataWraper& v )
	{
		m_SubdueMonsterData.push_back(v);
	}
private:
	//世界Boss数据
	vector<WorldBossObjWraper> m_WorldBossData;
public:
	int SizeWorldBossData()
	{
		return m_WorldBossData.size();
	}
	const vector<WorldBossObjWraper>& GetWorldBossData() const
	{
		return m_WorldBossData;
	}
	WorldBossObjWraper GetWorldBossData(int Index) const
	{
		if(Index<0 || Index>=(int)m_WorldBossData.size())
		{
			assert(false);
			return WorldBossObjWraper();
		}
		return m_WorldBossData[Index];
	}
	void SetWorldBossData( const vector<WorldBossObjWraper>& v )
	{
		m_WorldBossData=v;
	}
	void ClearWorldBossData( )
	{
		m_WorldBossData.clear();
	}
	void SetWorldBossData( int Index, const WorldBossObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_WorldBossData.size())
		{
			assert(false);
			return;
		}
		m_WorldBossData[Index] = v;
	}
	void AddWorldBossData( const WorldBossObjWraper& v )
	{
		m_WorldBossData.push_back(v);
	}
private:
	//世界Boss排名
	vector<WorldBossRankObjWraper> m_WorldBossRank;
public:
	int SizeWorldBossRank()
	{
		return m_WorldBossRank.size();
	}
	const vector<WorldBossRankObjWraper>& GetWorldBossRank() const
	{
		return m_WorldBossRank;
	}
	WorldBossRankObjWraper GetWorldBossRank(int Index) const
	{
		if(Index<0 || Index>=(int)m_WorldBossRank.size())
		{
			assert(false);
			return WorldBossRankObjWraper();
		}
		return m_WorldBossRank[Index];
	}
	void SetWorldBossRank( const vector<WorldBossRankObjWraper>& v )
	{
		m_WorldBossRank=v;
	}
	void ClearWorldBossRank( )
	{
		m_WorldBossRank.clear();
	}
	void SetWorldBossRank( int Index, const WorldBossRankObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_WorldBossRank.size())
		{
			assert(false);
			return;
		}
		m_WorldBossRank[Index] = v;
	}
	void AddWorldBossRank( const WorldBossRankObjWraper& v )
	{
		m_WorldBossRank.push_back(v);
	}

};

#endif
