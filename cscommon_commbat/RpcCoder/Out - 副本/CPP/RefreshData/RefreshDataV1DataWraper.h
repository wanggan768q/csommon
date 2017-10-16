/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperRefreshData.h
* Author:       甘业清
* Description:  刷新数据同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_REFRESHDATA_H
#define __SYNC_WRAPER_REFRESHDATA_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "RefreshDataV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//刷新数据封装类
class RefreshDataRefreshDataWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<RefreshDataRefreshDataWraperV1>
{
public:
	//构造函数
	RefreshDataRefreshDataWraperV1()
	{
		SetDataWraper( this );

		m_LastRefreshTime = 0;

	}
	//赋值构造函数
	RefreshDataRefreshDataWraperV1(const RefreshDataRefreshDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const RefreshDataRefreshDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RefreshDataRefreshDataV1 ToPB() const
	{
		RefreshDataRefreshDataV1 v;
		v.set_lastrefreshtime( m_LastRefreshTime );

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
		RefreshDataRefreshDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>LastRefreshTime(上次刷新) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>LastRefreshTime：%di</li>\r\n",m_LastRefreshTime);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const RefreshDataRefreshDataV1& v)
	{
		m_LastRefreshTime = v.lastrefreshtime();

	}

private:
	//上次刷新
	INT32 m_LastRefreshTime;
public:
	void SetLastRefreshTime( INT32 v)
	{
		m_LastRefreshTime=v;
	}
	INT32 GetLastRefreshTime()
	{
		return m_LastRefreshTime;
	}
	INT32 GetLastRefreshTime() const
	{
		return m_LastRefreshTime;
	}

};

#endif
