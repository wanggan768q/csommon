/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperTeam.h
* Author:       甘业清
* Description:  组队同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_TEAM_H
#define __SYNC_WRAPER_TEAM_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "TeamV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//组队对象封装类
class TeamTeamDataWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<TeamTeamDataWraperV1>
{
public:
	//构造函数
	TeamTeamDataWraperV1()
	{
		SetDataWraper( this );

		m_TeamData = TeamObjWraper();

	}
	//赋值构造函数
	TeamTeamDataWraperV1(const TeamTeamDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamTeamDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamTeamDataV1 ToPB() const
	{
		TeamTeamDataV1 v;
		*v.mutable_teamdata()= m_TeamData.ToPB();
		v.mutable_applylist()->Reserve(m_ApplyList.size());
		for (int i=0; i<(int)m_ApplyList.size(); i++)
		{
			*v.add_applylist() = m_ApplyList[i].ToPB();
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
		TeamTeamDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TeamData(组队数据) [TeamObj]</li>\r\n";
		htmlBuff += "<li>ApplyList(申请列表) [TeamApplyUserObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>TeamData：</li>\r\n";
		htmlBuff += m_TeamData.HtmlDescHeader();
		htmlBuff += m_TeamData.ToHtml();
		htmlBuff += "<li>ApplyList：</li>\r\n";
		if( m_ApplyList.size()>0) htmlBuff += m_ApplyList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ApplyList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ApplyList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TeamTeamDataV1& v)
	{
		m_TeamData = v.teamdata();
		m_ApplyList.clear();
		m_ApplyList.reserve(v.applylist_size());
		for( int i=0; i<v.applylist_size(); i++)
			m_ApplyList.push_back(v.applylist(i));

	}

private:
	//组队数据
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
private:
	//申请列表
	vector<TeamApplyUserObjWraper> m_ApplyList;
public:
	int SizeApplyList()
	{
		return m_ApplyList.size();
	}
	const vector<TeamApplyUserObjWraper>& GetApplyList() const
	{
		return m_ApplyList;
	}
	TeamApplyUserObjWraper GetApplyList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ApplyList.size())
		{
			assert(false);
			return TeamApplyUserObjWraper();
		}
		return m_ApplyList[Index];
	}
	void SetApplyList( const vector<TeamApplyUserObjWraper>& v )
	{
		m_ApplyList=v;
	}
	void ClearApplyList( )
	{
		m_ApplyList.clear();
	}
	void SetApplyList( int Index, const TeamApplyUserObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_ApplyList.size())
		{
			assert(false);
			return;
		}
		m_ApplyList[Index] = v;
	}
	void AddApplyList( const TeamApplyUserObjWraper& v )
	{
		m_ApplyList.push_back(v);
	}

};

#endif
