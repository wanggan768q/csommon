/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperOneVSOneTop.h
* Author:       甘业清
* Description:  排行榜同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_ONEVSONETOP_H
#define __SYNC_WRAPER_ONEVSONETOP_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "OneVSOneTopV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//一对一的数据封装类
class OneVSOneTopOneVSOneDateWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<OneVSOneTopOneVSOneDateWraperV1>
{
public:
	//构造函数
	OneVSOneTopOneVSOneDateWraperV1()
	{
		SetDataWraper( this );

		m_Time = -1;

	}
	//赋值构造函数
	OneVSOneTopOneVSOneDateWraperV1(const OneVSOneTopOneVSOneDateV1& v){ Init(v); }
	//等号重载函数
	void operator = (const OneVSOneTopOneVSOneDateV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OneVSOneTopOneVSOneDateV1 ToPB() const
	{
		OneVSOneTopOneVSOneDateV1 v;
		v.mutable_topmesses()->Reserve(m_TopMesses.size());
		for (int i=0; i<(int)m_TopMesses.size(); i++)
		{
			*v.add_topmesses() = m_TopMesses[i].ToPB();
		}
		v.set_time( m_Time );

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
		OneVSOneTopOneVSOneDateV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TopMesses(排行榜数据) [TopMess] Array</li>\r\n";
		htmlBuff += "<li>Time(格林时间) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>TopMesses：</li>\r\n";
		if( m_TopMesses.size()>0) htmlBuff += m_TopMesses[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_TopMesses.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_TopMesses[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>Time：%lldL</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const OneVSOneTopOneVSOneDateV1& v)
	{
		m_TopMesses.clear();
		m_TopMesses.reserve(v.topmesses_size());
		for( int i=0; i<v.topmesses_size(); i++)
			m_TopMesses.push_back(v.topmesses(i));
		m_Time = v.time();

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
private:
	//格林时间
	INT64 m_Time;
public:
	void SetTime( INT64 v)
	{
		m_Time=v;
	}
	INT64 GetTime()
	{
		return m_Time;
	}
	INT64 GetTime() const
	{
		return m_Time;
	}

};

#endif
