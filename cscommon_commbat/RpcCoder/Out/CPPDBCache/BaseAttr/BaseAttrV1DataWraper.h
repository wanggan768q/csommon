/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperBaseAttr.h
* Author:       甘业清
* Description:  战队基础数据同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_BASEATTR_H
#define __SYNC_WRAPER_BASEATTR_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "BaseAttrV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//图标开启信息封装类
class BaseAttrIconOpenInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrIconOpenInfoWraperV1()
	{
		
		m_IconId = -1;
		m_IsOpen = false;
		m_IsShow = false;
		m_IsNew = false;

	}
	//赋值构造函数
	BaseAttrIconOpenInfoWraperV1(const BaseAttrIconOpenInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrIconOpenInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrIconOpenInfoV1 ToPB() const
	{
		BaseAttrIconOpenInfoV1 v;
		v.set_iconid( m_IconId );
		v.set_isopen( m_IsOpen );
		v.set_isshow( m_IsShow );
		v.set_isnew( m_IsNew );

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
		BaseAttrIconOpenInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>IconId(图标ID) [sint32]</li>\r\n";
		htmlBuff += "<li>IsOpen(功能是否打开) [bool]</li>\r\n";
		htmlBuff += "<li>IsShow(是否显示) [bool]</li>\r\n";
		htmlBuff += "<li>IsNew(是否为新) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>IconId：%di</li>\r\n",m_IconId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsOpen：%di</li>\r\n",m_IsOpen);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsShow：%di</li>\r\n",m_IsShow);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsNew：%di</li>\r\n",m_IsNew);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrIconOpenInfoV1& v)
	{
		m_IconId = v.iconid();
		m_IsOpen = v.isopen();
		m_IsShow = v.isshow();
		m_IsNew = v.isnew();

	}

private:
	//图标ID
	INT32 m_IconId;
public:
	void SetIconId( INT32 v)
	{
		m_IconId=v;
	}
	INT32 GetIconId()
	{
		return m_IconId;
	}
	INT32 GetIconId() const
	{
		return m_IconId;
	}
private:
	//功能是否打开
	bool m_IsOpen;
public:
	void SetIsOpen( bool v)
	{
		m_IsOpen=v;
	}
	bool GetIsOpen()
	{
		return m_IsOpen;
	}
	bool GetIsOpen() const
	{
		return m_IsOpen;
	}
private:
	//是否显示
	bool m_IsShow;
public:
	void SetIsShow( bool v)
	{
		m_IsShow=v;
	}
	bool GetIsShow()
	{
		return m_IsShow;
	}
	bool GetIsShow() const
	{
		return m_IsShow;
	}
private:
	//是否为新
	bool m_IsNew;
public:
	void SetIsNew( bool v)
	{
		m_IsNew=v;
	}
	bool GetIsNew()
	{
		return m_IsNew;
	}
	bool GetIsNew() const
	{
		return m_IsNew;
	}

};
//活力值信息封装类
class BaseAttrEnergyInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrEnergyInfoWraperV1()
	{
		
		m_EnergyId = -1;
		m_EnergyValue = 0;
		m_ReceivedEnergy = 0;

	}
	//赋值构造函数
	BaseAttrEnergyInfoWraperV1(const BaseAttrEnergyInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrEnergyInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrEnergyInfoV1 ToPB() const
	{
		BaseAttrEnergyInfoV1 v;
		v.set_energyid( m_EnergyId );
		v.set_energyvalue( m_EnergyValue );
		v.set_receivedenergy( m_ReceivedEnergy );

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
		BaseAttrEnergyInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>EnergyId(活力ID，表id) [sint32]</li>\r\n";
		htmlBuff += "<li>EnergyValue(活力值) [sint32]</li>\r\n";
		htmlBuff += "<li>ReceivedEnergy(已获得活力值) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>EnergyId：%di</li>\r\n",m_EnergyId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EnergyValue：%di</li>\r\n",m_EnergyValue);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ReceivedEnergy：%di</li>\r\n",m_ReceivedEnergy);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrEnergyInfoV1& v)
	{
		m_EnergyId = v.energyid();
		m_EnergyValue = v.energyvalue();
		m_ReceivedEnergy = v.receivedenergy();

	}

private:
	//活力ID，表id
	INT32 m_EnergyId;
public:
	void SetEnergyId( INT32 v)
	{
		m_EnergyId=v;
	}
	INT32 GetEnergyId()
	{
		return m_EnergyId;
	}
	INT32 GetEnergyId() const
	{
		return m_EnergyId;
	}
private:
	//活力值
	INT32 m_EnergyValue;
public:
	void SetEnergyValue( INT32 v)
	{
		m_EnergyValue=v;
	}
	INT32 GetEnergyValue()
	{
		return m_EnergyValue;
	}
	INT32 GetEnergyValue() const
	{
		return m_EnergyValue;
	}
private:
	//已获得活力值
	INT32 m_ReceivedEnergy;
public:
	void SetReceivedEnergy( INT32 v)
	{
		m_ReceivedEnergy=v;
	}
	INT32 GetReceivedEnergy()
	{
		return m_ReceivedEnergy;
	}
	INT32 GetReceivedEnergy() const
	{
		return m_ReceivedEnergy;
	}

};
//修炼信息封装类
class BaseAttrScienceInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrScienceInfoWraperV1()
	{
		
		m_ScienceId = -1;
		m_ScienceCurExp = 0;
		m_ScienceLv = -1;
		m_ScienceCurMoney = 0;

	}
	//赋值构造函数
	BaseAttrScienceInfoWraperV1(const BaseAttrScienceInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrScienceInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrScienceInfoV1 ToPB() const
	{
		BaseAttrScienceInfoV1 v;
		v.set_scienceid( m_ScienceId );
		v.set_sciencecurexp( m_ScienceCurExp );
		v.set_sciencelv( m_ScienceLv );
		v.set_sciencecurmoney( m_ScienceCurMoney );

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
		BaseAttrScienceInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ScienceId(修炼属性Id) [sint32]</li>\r\n";
		htmlBuff += "<li>ScienceCurExp(修炼经验) [sint32]</li>\r\n";
		htmlBuff += "<li>ScienceLv(帮会修炼技能等级) [sint32]</li>\r\n";
		htmlBuff += "<li>ScienceCurMoney(未升级钱所消耗金币) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ScienceId：%di</li>\r\n",m_ScienceId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ScienceCurExp：%di</li>\r\n",m_ScienceCurExp);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ScienceLv：%di</li>\r\n",m_ScienceLv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ScienceCurMoney：%di</li>\r\n",m_ScienceCurMoney);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrScienceInfoV1& v)
	{
		m_ScienceId = v.scienceid();
		m_ScienceCurExp = v.sciencecurexp();
		m_ScienceLv = v.sciencelv();
		m_ScienceCurMoney = v.sciencecurmoney();

	}

private:
	//修炼属性Id
	INT32 m_ScienceId;
public:
	void SetScienceId( INT32 v)
	{
		m_ScienceId=v;
	}
	INT32 GetScienceId()
	{
		return m_ScienceId;
	}
	INT32 GetScienceId() const
	{
		return m_ScienceId;
	}
private:
	//修炼经验
	INT32 m_ScienceCurExp;
public:
	void SetScienceCurExp( INT32 v)
	{
		m_ScienceCurExp=v;
	}
	INT32 GetScienceCurExp()
	{
		return m_ScienceCurExp;
	}
	INT32 GetScienceCurExp() const
	{
		return m_ScienceCurExp;
	}
private:
	//帮会修炼技能等级
	INT32 m_ScienceLv;
public:
	void SetScienceLv( INT32 v)
	{
		m_ScienceLv=v;
	}
	INT32 GetScienceLv()
	{
		return m_ScienceLv;
	}
	INT32 GetScienceLv() const
	{
		return m_ScienceLv;
	}
private:
	//未升级钱所消耗金币
	INT32 m_ScienceCurMoney;
public:
	void SetScienceCurMoney( INT32 v)
	{
		m_ScienceCurMoney=v;
	}
	INT32 GetScienceCurMoney()
	{
		return m_ScienceCurMoney;
	}
	INT32 GetScienceCurMoney() const
	{
		return m_ScienceCurMoney;
	}

};
//技能CD信息封装类
class BaseAttrSkillCdInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrSkillCdInfoWraperV1()
	{
		
		m_SkillId = -1;
		m_EndTime = -1;

	}
	//赋值构造函数
	BaseAttrSkillCdInfoWraperV1(const BaseAttrSkillCdInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrSkillCdInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrSkillCdInfoV1 ToPB() const
	{
		BaseAttrSkillCdInfoV1 v;
		v.set_skillid( m_SkillId );
		v.set_endtime( m_EndTime );

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
		BaseAttrSkillCdInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SkillId(技能ID) [sint32]</li>\r\n";
		htmlBuff += "<li>EndTime(结束时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EndTime：%di</li>\r\n",m_EndTime);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrSkillCdInfoV1& v)
	{
		m_SkillId = v.skillid();
		m_EndTime = v.endtime();

	}

private:
	//技能ID
	INT32 m_SkillId;
public:
	void SetSkillId( INT32 v)
	{
		m_SkillId=v;
	}
	INT32 GetSkillId()
	{
		return m_SkillId;
	}
	INT32 GetSkillId() const
	{
		return m_SkillId;
	}
private:
	//结束时间
	INT32 m_EndTime;
public:
	void SetEndTime( INT32 v)
	{
		m_EndTime=v;
	}
	INT32 GetEndTime()
	{
		return m_EndTime;
	}
	INT32 GetEndTime() const
	{
		return m_EndTime;
	}

};
//BuffCD信息封装类
class BaseAttrBuffCdInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrBuffCdInfoWraperV1()
	{
		
		m_BuffId = -1;
		m_EndTime = -1;

	}
	//赋值构造函数
	BaseAttrBuffCdInfoWraperV1(const BaseAttrBuffCdInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrBuffCdInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrBuffCdInfoV1 ToPB() const
	{
		BaseAttrBuffCdInfoV1 v;
		v.set_buffid( m_BuffId );
		v.set_endtime( m_EndTime );

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
		BaseAttrBuffCdInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>BuffId(BuffId) [sint32]</li>\r\n";
		htmlBuff += "<li>EndTime(结束时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>BuffId：%di</li>\r\n",m_BuffId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EndTime：%di</li>\r\n",m_EndTime);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrBuffCdInfoV1& v)
	{
		m_BuffId = v.buffid();
		m_EndTime = v.endtime();

	}

private:
	//BuffId
	INT32 m_BuffId;
public:
	void SetBuffId( INT32 v)
	{
		m_BuffId=v;
	}
	INT32 GetBuffId()
	{
		return m_BuffId;
	}
	INT32 GetBuffId() const
	{
		return m_BuffId;
	}
private:
	//结束时间
	INT32 m_EndTime;
public:
	void SetEndTime( INT32 v)
	{
		m_EndTime=v;
	}
	INT32 GetEndTime()
	{
		return m_EndTime;
	}
	INT32 GetEndTime() const
	{
		return m_EndTime;
	}

};
//场景信息封装类
class BaseAttrSceneInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrSceneInfoWraperV1()
	{
		
		m_RelateUserId = -1;
		m_ReviveNeedMoney = -1;
		m_ReviveNeedMoneyType = 0;
		m_DungeonKey = "";

	}
	//赋值构造函数
	BaseAttrSceneInfoWraperV1(const BaseAttrSceneInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrSceneInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrSceneInfoV1 ToPB() const
	{
		BaseAttrSceneInfoV1 v;
		v.set_relateuserid( m_RelateUserId );
		v.set_reviveneedmoney( m_ReviveNeedMoney );
		v.set_reviveneedmoneytype( m_ReviveNeedMoneyType );
		v.set_dungeonkey( m_DungeonKey );

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
		BaseAttrSceneInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>RelateUserId(关系的用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>ReviveNeedMoney(复活需要的钱数) [sint32]</li>\r\n";
		htmlBuff += "<li>ReviveNeedMoneyType(复活需要的货币类型) [sint32]</li>\r\n";
		htmlBuff += "<li>DungeonKey(DungeonKey) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>RelateUserId：%lldL</li>\r\n",m_RelateUserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ReviveNeedMoney：%di</li>\r\n",m_ReviveNeedMoney);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ReviveNeedMoneyType：%di</li>\r\n",m_ReviveNeedMoneyType);
		htmlBuff += tmpLine;
		htmlBuff += "<li>DungeonKey：\""+m_DungeonKey+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrSceneInfoV1& v)
	{
		m_RelateUserId = v.relateuserid();
		m_ReviveNeedMoney = v.reviveneedmoney();
		m_ReviveNeedMoneyType = v.reviveneedmoneytype();
		m_DungeonKey = v.dungeonkey();

	}

private:
	//关系的用户ID
	INT64 m_RelateUserId;
public:
	void SetRelateUserId( INT64 v)
	{
		m_RelateUserId=v;
	}
	INT64 GetRelateUserId()
	{
		return m_RelateUserId;
	}
	INT64 GetRelateUserId() const
	{
		return m_RelateUserId;
	}
private:
	//复活需要的钱数
	INT32 m_ReviveNeedMoney;
public:
	void SetReviveNeedMoney( INT32 v)
	{
		m_ReviveNeedMoney=v;
	}
	INT32 GetReviveNeedMoney()
	{
		return m_ReviveNeedMoney;
	}
	INT32 GetReviveNeedMoney() const
	{
		return m_ReviveNeedMoney;
	}
private:
	//复活需要的货币类型
	INT32 m_ReviveNeedMoneyType;
public:
	void SetReviveNeedMoneyType( INT32 v)
	{
		m_ReviveNeedMoneyType=v;
	}
	INT32 GetReviveNeedMoneyType()
	{
		return m_ReviveNeedMoneyType;
	}
	INT32 GetReviveNeedMoneyType() const
	{
		return m_ReviveNeedMoneyType;
	}
private:
	//DungeonKey
	string m_DungeonKey;
public:
	void SetDungeonKey( const string& v)
	{
		m_DungeonKey=v;
	}
	string GetDungeonKey()
	{
		return m_DungeonKey;
	}
	string GetDungeonKey() const
	{
		return m_DungeonKey;
	}

};
//玩家基础数据封装类
class BaseAttrUserDataWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<BaseAttrUserDataWraperV1>
{
public:
	//构造函数
	BaseAttrUserDataWraperV1()
	{
		SetDataWraper( this );

		m_HeadID = -1;
		m_Exp = -1;
		m_CreateTime = -1;
		m_LastLoginTime = -1;
		m_Last2LoginDate = -1;
		m_LastLogoutTime = -1;
		m_Money = 0;
		m_Diamond = 0;
		m_Strength = -1;
		m_Feats = -1;
		m_GotRankRewardTime = -1;
		m_MaxMilitary = -1;
		m_CurMilitary = -1;
		m_UserName = "";
		m_UserId = -1;
		m_PlatName = "";
		m_AccountId = -1;
		m_Level = -1;
		m_Rank = -1;
		m_FightPower = -1;
		m_Sec = -1;
		m_Military = -1;
		m_TeamId = -1;
		m_Prof = -1;
		m_DungeonRemainCount = -1;
		m_MapId = -1;
		m_PosX = -1;
		m_PosY = -1;
		m_PosZ = -1;
		m_Ry = -1;
		m_CurrentScene = BaseAttrSceneInfoWraperV1();
		m_GuildId = -1;
		m_ExitGuildTime = -1;
		m_CurGuildContribution = 0;
		m_MaxGuildContribution = 0;
		m_BindMoney = 0;
		m_Gem = 0;
		m_ServerTime = -1;
		m_ThiefRewardNum = 0;
		m_SubdueMonsterRewardNum = 0;
		m_WorldBossRemainTimes = 0;
		m_WorldBossHurt = 0;
		m_TotalEnergyValue = 0;
		m_PKState = -1;
		m_ScienceTotalMoney = 0;

	}
	//赋值构造函数
	BaseAttrUserDataWraperV1(const BaseAttrUserDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrUserDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrUserDataV1 ToPB() const
	{
		BaseAttrUserDataV1 v;
		v.set_headid( m_HeadID );
		v.set_exp( m_Exp );
		v.set_createtime( m_CreateTime );
		v.set_lastlogintime( m_LastLoginTime );
		v.set_last2logindate( m_Last2LoginDate );
		v.set_lastlogouttime( m_LastLogoutTime );
		v.set_money( m_Money );
		v.set_diamond( m_Diamond );
		v.set_strength( m_Strength );
		v.set_feats( m_Feats );
		v.set_gotrankrewardtime( m_GotRankRewardTime );
		v.set_maxmilitary( m_MaxMilitary );
		v.mutable_masterattrs()->Reserve(m_MasterAttrs.size());
		for (int i=0; i<(int)m_MasterAttrs.size(); i++)
		{
			v.add_masterattrs(m_MasterAttrs[i]);
		}
		v.set_curmilitary( m_CurMilitary );
		v.set_username( m_UserName );
		v.set_userid( m_UserId );
		v.set_platname( m_PlatName );
		v.set_accountid( m_AccountId );
		v.set_level( m_Level );
		v.set_rank( m_Rank );
		v.set_fightpower( m_FightPower );
		v.set_sec( m_Sec );
		v.set_military( m_Military );
		v.set_teamid( m_TeamId );
		v.set_prof( m_Prof );
		v.set_dungeonremaincount( m_DungeonRemainCount );
		v.set_mapid( m_MapId );
		v.set_posx( m_PosX );
		v.set_posy( m_PosY );
		v.set_posz( m_PosZ );
		v.set_ry( m_Ry );
		v.mutable_skillcdarr()->Reserve(m_SkillCdArr.size());
		for (int i=0; i<(int)m_SkillCdArr.size(); i++)
		{
			*v.add_skillcdarr() = m_SkillCdArr[i].ToPB();
		}
		v.mutable_buffcdarr()->Reserve(m_BuffCdArr.size());
		for (int i=0; i<(int)m_BuffCdArr.size(); i++)
		{
			*v.add_buffcdarr() = m_BuffCdArr[i].ToPB();
		}
		*v.mutable_currentscene()= m_CurrentScene.ToPB();
		v.set_guildid( m_GuildId );
		v.set_exitguildtime( m_ExitGuildTime );
		v.mutable_applyguildid()->Reserve(m_ApplyGuildId.size());
		for (int i=0; i<(int)m_ApplyGuildId.size(); i++)
		{
			v.add_applyguildid(m_ApplyGuildId[i]);
		}
		v.set_curguildcontribution( m_CurGuildContribution );
		v.set_maxguildcontribution( m_MaxGuildContribution );
		v.set_bindmoney( m_BindMoney );
		v.set_gem( m_Gem );
		v.set_servertime( m_ServerTime );
		v.mutable_newbieguide()->Reserve(m_NewbieGuide.size());
		for (int i=0; i<(int)m_NewbieGuide.size(); i++)
		{
			*v.add_newbieguide() = m_NewbieGuide[i].ToPB();
		}
		v.set_thiefrewardnum( m_ThiefRewardNum );
		v.set_subduemonsterrewardnum( m_SubdueMonsterRewardNum );
		v.set_worldbossremaintimes( m_WorldBossRemainTimes );
		v.set_worldbosshurt( m_WorldBossHurt );
		v.mutable_functionopenlist()->Reserve(m_FunctionOpenList.size());
		for (int i=0; i<(int)m_FunctionOpenList.size(); i++)
		{
			*v.add_functionopenlist() = m_FunctionOpenList[i].ToPB();
		}
		v.set_totalenergyvalue( m_TotalEnergyValue );
		v.mutable_energyarray()->Reserve(m_EnergyArray.size());
		for (int i=0; i<(int)m_EnergyArray.size(); i++)
		{
			*v.add_energyarray() = m_EnergyArray[i].ToPB();
		}
		v.set_pkstate( m_PKState );
		v.mutable_pkprotect()->Reserve(m_PKProtect.size());
		for (int i=0; i<(int)m_PKProtect.size(); i++)
		{
			*v.add_pkprotect() = m_PKProtect[i].ToPB();
		}
		v.mutable_guildscienarray()->Reserve(m_GuildScienArray.size());
		for (int i=0; i<(int)m_GuildScienArray.size(); i++)
		{
			*v.add_guildscienarray() = m_GuildScienArray[i].ToPB();
		}
		v.set_sciencetotalmoney( m_ScienceTotalMoney );

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
		BaseAttrUserDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>HeadID(头像id) [sint32]</li>\r\n";
		htmlBuff += "<li>Exp(经验) [sint32]</li>\r\n";
		htmlBuff += "<li>CreateTime(创建时间) [sint32]</li>\r\n";
		htmlBuff += "<li>LastLoginTime(最后登录时间) [sint32]</li>\r\n";
		htmlBuff += "<li>Last2LoginDate(倒数第二登录日期) [sint32]</li>\r\n";
		htmlBuff += "<li>LastLogoutTime(最后登出时间) [sint32]</li>\r\n";
		htmlBuff += "<li>Money(游戏币) [sint32]</li>\r\n";
		htmlBuff += "<li>Diamond(钻石) [sint32]</li>\r\n";
		htmlBuff += "<li>Strength(体力) [sint32]</li>\r\n";
		htmlBuff += "<li>Feats(功勋) [sint32]</li>\r\n";
		htmlBuff += "<li>GotRankRewardTime(领取官阶奖励时间) [sint32]</li>\r\n";
		htmlBuff += "<li>MaxMilitary(历史最大战力) [sint32]</li>\r\n";
		htmlBuff += "<li>MasterAttrs(主公基础属性) [sint32] Array</li>\r\n";
		htmlBuff += "<li>CurMilitary(当前玩家战力) [sint32]</li>\r\n";
		htmlBuff += "<li>UserName(玩家名字) [string]</li>\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>PlatName(游戏中心账号名) [string]</li>\r\n";
		htmlBuff += "<li>AccountId(游戏中心账号ID) [sint64]</li>\r\n";
		htmlBuff += "<li>Level(玩家等级) [sint32]</li>\r\n";
		htmlBuff += "<li>Rank(官阶) [sint32]</li>\r\n";
		htmlBuff += "<li>FightPower(战力) [sint32]</li>\r\n";
		htmlBuff += "<li>Sec(用户累加的数据) [sint32]</li>\r\n";
		htmlBuff += "<li>Military(当前战力) [sint32]</li>\r\n";
		htmlBuff += "<li>TeamId(队伍Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Prof(职业) [sint32]</li>\r\n";
		htmlBuff += "<li>DungeonRemainCount(副本剩余次数) [sint32]</li>\r\n";
		htmlBuff += "<li>MapId(地图Id) [sint32]</li>\r\n";
		htmlBuff += "<li>PosX(X坐标) [float]</li>\r\n";
		htmlBuff += "<li>PosY(Y坐标) [float]</li>\r\n";
		htmlBuff += "<li>PosZ(Z坐标) [float]</li>\r\n";
		htmlBuff += "<li>Ry(位置方向) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillCdArr(技能CD列表) [SkillCdInfo] Array</li>\r\n";
		htmlBuff += "<li>BuffCdArr(BuffCD列表) [BuffCdInfo] Array</li>\r\n";
		htmlBuff += "<li>CurrentScene(当前所在场景) [SceneInfo]</li>\r\n";
		htmlBuff += "<li>GuildId(帮会Id) [sint32]</li>\r\n";
		htmlBuff += "<li>ExitGuildTime(退出帮会时间) [sint32]</li>\r\n";
		htmlBuff += "<li>ApplyGuildId(申请过的帮会) [sint32] Array</li>\r\n";
		htmlBuff += "<li>CurGuildContribution(当前帮贡) [sint32]</li>\r\n";
		htmlBuff += "<li>MaxGuildContribution(最大帮贡) [sint32]</li>\r\n";
		htmlBuff += "<li>BindMoney(绑银) [sint32]</li>\r\n";
		htmlBuff += "<li>Gem(宝石) [sint32]</li>\r\n";
		htmlBuff += "<li>ServerTime(服务器时间) [sint32]</li>\r\n";
		htmlBuff += "<li>NewbieGuide(新手引导) [KeyValue2IntInt] Array</li>\r\n";
		htmlBuff += "<li>ThiefRewardNum(江洋大盗奖励次数) [sint32]</li>\r\n";
		htmlBuff += "<li>SubdueMonsterRewardNum(降妖奖励次数) [sint32]</li>\r\n";
		htmlBuff += "<li>WorldBossRemainTimes(世界Boss剩余次数) [sint32]</li>\r\n";
		htmlBuff += "<li>WorldBossHurt(世界Boss伤害) [sint32]</li>\r\n";
		htmlBuff += "<li>FunctionOpenList(功能开启列表) [IconOpenInfo] Array</li>\r\n";
		htmlBuff += "<li>TotalEnergyValue(总活力值) [sint32]</li>\r\n";
		htmlBuff += "<li>EnergyArray(活力值信息容器) [EnergyInfo] Array</li>\r\n";
		htmlBuff += "<li>PKState(PK状态) [sint32]</li>\r\n";
		htmlBuff += "<li>PKProtect(PK保护列表) [KeyValue2IntBool] Array</li>\r\n";
		htmlBuff += "<li>GuildScienArray(帮会修炼) [ScienceInfo] Array</li>\r\n";
		htmlBuff += "<li>ScienceTotalMoney(修炼升级消耗总金币) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>HeadID：%di</li>\r\n",m_HeadID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Exp：%di</li>\r\n",m_Exp);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CreateTime：%di</li>\r\n",m_CreateTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>LastLoginTime：%di</li>\r\n",m_LastLoginTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Last2LoginDate：%di</li>\r\n",m_Last2LoginDate);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>LastLogoutTime：%di</li>\r\n",m_LastLogoutTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Money：%di</li>\r\n",m_Money);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Diamond：%di</li>\r\n",m_Diamond);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Strength：%di</li>\r\n",m_Strength);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Feats：%di</li>\r\n",m_Feats);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GotRankRewardTime：%di</li>\r\n",m_GotRankRewardTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MaxMilitary：%di</li>\r\n",m_MaxMilitary);
		htmlBuff += tmpLine;
		htmlBuff += "<li>MasterAttrs：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_MasterAttrs.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_MasterAttrs[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_MasterAttrs.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>CurMilitary：%di</li>\r\n",m_CurMilitary);
		htmlBuff += tmpLine;
		htmlBuff += "<li>UserName：\""+m_UserName+"\"</li>\r\n";
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PlatName：\""+m_PlatName+"\"</li>\r\n";
		tmpLine.Fmt("<li>AccountId：%lldL</li>\r\n",m_AccountId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Rank：%di</li>\r\n",m_Rank);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>FightPower：%di</li>\r\n",m_FightPower);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Sec：%di</li>\r\n",m_Sec);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Military：%di</li>\r\n",m_Military);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TeamId：%di</li>\r\n",m_TeamId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Prof：%di</li>\r\n",m_Prof);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DungeonRemainCount：%di</li>\r\n",m_DungeonRemainCount);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MapId：%di</li>\r\n",m_MapId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PosX：%.2ff</li>\r\n",m_PosX);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PosY：%.2ff</li>\r\n",m_PosY);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PosZ：%.2ff</li>\r\n",m_PosZ);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Ry：%di</li>\r\n",m_Ry);
		htmlBuff += tmpLine;
		htmlBuff += "<li>SkillCdArr：</li>\r\n";
		if( m_SkillCdArr.size()>0) htmlBuff += m_SkillCdArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_SkillCdArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_SkillCdArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>BuffCdArr：</li>\r\n";
		if( m_BuffCdArr.size()>0) htmlBuff += m_BuffCdArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_BuffCdArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_BuffCdArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>CurrentScene：</li>\r\n";
		htmlBuff += m_CurrentScene.HtmlDescHeader();
		htmlBuff += m_CurrentScene.ToHtml();
		tmpLine.Fmt("<li>GuildId：%di</li>\r\n",m_GuildId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ExitGuildTime：%di</li>\r\n",m_ExitGuildTime);
		htmlBuff += tmpLine;
		htmlBuff += "<li>ApplyGuildId：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_ApplyGuildId.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_ApplyGuildId[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_ApplyGuildId.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>CurGuildContribution：%di</li>\r\n",m_CurGuildContribution);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MaxGuildContribution：%di</li>\r\n",m_MaxGuildContribution);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BindMoney：%di</li>\r\n",m_BindMoney);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Gem：%di</li>\r\n",m_Gem);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ServerTime：%di</li>\r\n",m_ServerTime);
		htmlBuff += tmpLine;
		htmlBuff += "<li>NewbieGuide：</li>\r\n";
		if( m_NewbieGuide.size()>0) htmlBuff += m_NewbieGuide[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_NewbieGuide.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_NewbieGuide[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>ThiefRewardNum：%di</li>\r\n",m_ThiefRewardNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SubdueMonsterRewardNum：%di</li>\r\n",m_SubdueMonsterRewardNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>WorldBossRemainTimes：%di</li>\r\n",m_WorldBossRemainTimes);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>WorldBossHurt：%di</li>\r\n",m_WorldBossHurt);
		htmlBuff += tmpLine;
		htmlBuff += "<li>FunctionOpenList：</li>\r\n";
		if( m_FunctionOpenList.size()>0) htmlBuff += m_FunctionOpenList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_FunctionOpenList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_FunctionOpenList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>TotalEnergyValue：%di</li>\r\n",m_TotalEnergyValue);
		htmlBuff += tmpLine;
		htmlBuff += "<li>EnergyArray：</li>\r\n";
		if( m_EnergyArray.size()>0) htmlBuff += m_EnergyArray[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_EnergyArray.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_EnergyArray[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>PKState：%di</li>\r\n",m_PKState);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PKProtect：</li>\r\n";
		if( m_PKProtect.size()>0) htmlBuff += m_PKProtect[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_PKProtect.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_PKProtect[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>GuildScienArray：</li>\r\n";
		if( m_GuildScienArray.size()>0) htmlBuff += m_GuildScienArray[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_GuildScienArray.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_GuildScienArray[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>ScienceTotalMoney：%di</li>\r\n",m_ScienceTotalMoney);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrUserDataV1& v)
	{
		m_HeadID = v.headid();
		m_Exp = v.exp();
		m_CreateTime = v.createtime();
		m_LastLoginTime = v.lastlogintime();
		m_Last2LoginDate = v.last2logindate();
		m_LastLogoutTime = v.lastlogouttime();
		m_Money = v.money();
		m_Diamond = v.diamond();
		m_Strength = v.strength();
		m_Feats = v.feats();
		m_GotRankRewardTime = v.gotrankrewardtime();
		m_MaxMilitary = v.maxmilitary();
		m_MasterAttrs.clear();
		m_MasterAttrs.reserve(v.masterattrs_size());
		for( int i=0; i<v.masterattrs_size(); i++)
			m_MasterAttrs.push_back(v.masterattrs(i));
		m_CurMilitary = v.curmilitary();
		m_UserName = v.username();
		m_UserId = v.userid();
		m_PlatName = v.platname();
		m_AccountId = v.accountid();
		m_Level = v.level();
		m_Rank = v.rank();
		m_FightPower = v.fightpower();
		m_Sec = v.sec();
		m_Military = v.military();
		m_TeamId = v.teamid();
		m_Prof = v.prof();
		m_DungeonRemainCount = v.dungeonremaincount();
		m_MapId = v.mapid();
		m_PosX = v.posx();
		m_PosY = v.posy();
		m_PosZ = v.posz();
		m_Ry = v.ry();
		m_SkillCdArr.clear();
		m_SkillCdArr.reserve(v.skillcdarr_size());
		for( int i=0; i<v.skillcdarr_size(); i++)
			m_SkillCdArr.push_back(v.skillcdarr(i));
		m_BuffCdArr.clear();
		m_BuffCdArr.reserve(v.buffcdarr_size());
		for( int i=0; i<v.buffcdarr_size(); i++)
			m_BuffCdArr.push_back(v.buffcdarr(i));
		m_CurrentScene = v.currentscene();
		m_GuildId = v.guildid();
		m_ExitGuildTime = v.exitguildtime();
		m_ApplyGuildId.clear();
		m_ApplyGuildId.reserve(v.applyguildid_size());
		for( int i=0; i<v.applyguildid_size(); i++)
			m_ApplyGuildId.push_back(v.applyguildid(i));
		m_CurGuildContribution = v.curguildcontribution();
		m_MaxGuildContribution = v.maxguildcontribution();
		m_BindMoney = v.bindmoney();
		m_Gem = v.gem();
		m_ServerTime = v.servertime();
		m_NewbieGuide.clear();
		m_NewbieGuide.reserve(v.newbieguide_size());
		for( int i=0; i<v.newbieguide_size(); i++)
			m_NewbieGuide.push_back(v.newbieguide(i));
		m_ThiefRewardNum = v.thiefrewardnum();
		m_SubdueMonsterRewardNum = v.subduemonsterrewardnum();
		m_WorldBossRemainTimes = v.worldbossremaintimes();
		m_WorldBossHurt = v.worldbosshurt();
		m_FunctionOpenList.clear();
		m_FunctionOpenList.reserve(v.functionopenlist_size());
		for( int i=0; i<v.functionopenlist_size(); i++)
			m_FunctionOpenList.push_back(v.functionopenlist(i));
		m_TotalEnergyValue = v.totalenergyvalue();
		m_EnergyArray.clear();
		m_EnergyArray.reserve(v.energyarray_size());
		for( int i=0; i<v.energyarray_size(); i++)
			m_EnergyArray.push_back(v.energyarray(i));
		m_PKState = v.pkstate();
		m_PKProtect.clear();
		m_PKProtect.reserve(v.pkprotect_size());
		for( int i=0; i<v.pkprotect_size(); i++)
			m_PKProtect.push_back(v.pkprotect(i));
		m_GuildScienArray.clear();
		m_GuildScienArray.reserve(v.guildscienarray_size());
		for( int i=0; i<v.guildscienarray_size(); i++)
			m_GuildScienArray.push_back(v.guildscienarray(i));
		m_ScienceTotalMoney = v.sciencetotalmoney();

	}

private:
	//头像id
	INT32 m_HeadID;
public:
	void SetHeadID( INT32 v)
	{
		m_HeadID=v;
	}
	INT32 GetHeadID()
	{
		return m_HeadID;
	}
	INT32 GetHeadID() const
	{
		return m_HeadID;
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
	//创建时间
	INT32 m_CreateTime;
public:
	void SetCreateTime( INT32 v)
	{
		m_CreateTime=v;
	}
	INT32 GetCreateTime()
	{
		return m_CreateTime;
	}
	INT32 GetCreateTime() const
	{
		return m_CreateTime;
	}
private:
	//最后登录时间
	INT32 m_LastLoginTime;
public:
	void SetLastLoginTime( INT32 v)
	{
		m_LastLoginTime=v;
	}
	INT32 GetLastLoginTime()
	{
		return m_LastLoginTime;
	}
	INT32 GetLastLoginTime() const
	{
		return m_LastLoginTime;
	}
private:
	//倒数第二登录日期
	INT32 m_Last2LoginDate;
public:
	void SetLast2LoginDate( INT32 v)
	{
		m_Last2LoginDate=v;
	}
	INT32 GetLast2LoginDate()
	{
		return m_Last2LoginDate;
	}
	INT32 GetLast2LoginDate() const
	{
		return m_Last2LoginDate;
	}
private:
	//最后登出时间
	INT32 m_LastLogoutTime;
public:
	void SetLastLogoutTime( INT32 v)
	{
		m_LastLogoutTime=v;
	}
	INT32 GetLastLogoutTime()
	{
		return m_LastLogoutTime;
	}
	INT32 GetLastLogoutTime() const
	{
		return m_LastLogoutTime;
	}
private:
	//游戏币
	INT32 m_Money;
public:
	void SetMoney( INT32 v)
	{
		m_Money=v;
	}
	INT32 GetMoney()
	{
		return m_Money;
	}
	INT32 GetMoney() const
	{
		return m_Money;
	}
private:
	//钻石
	INT32 m_Diamond;
public:
	void SetDiamond( INT32 v)
	{
		m_Diamond=v;
	}
	INT32 GetDiamond()
	{
		return m_Diamond;
	}
	INT32 GetDiamond() const
	{
		return m_Diamond;
	}
private:
	//体力
	INT32 m_Strength;
public:
	void SetStrength( INT32 v)
	{
		m_Strength=v;
	}
	INT32 GetStrength()
	{
		return m_Strength;
	}
	INT32 GetStrength() const
	{
		return m_Strength;
	}
private:
	//功勋
	INT32 m_Feats;
public:
	void SetFeats( INT32 v)
	{
		m_Feats=v;
	}
	INT32 GetFeats()
	{
		return m_Feats;
	}
	INT32 GetFeats() const
	{
		return m_Feats;
	}
private:
	//领取官阶奖励时间
	INT32 m_GotRankRewardTime;
public:
	void SetGotRankRewardTime( INT32 v)
	{
		m_GotRankRewardTime=v;
	}
	INT32 GetGotRankRewardTime()
	{
		return m_GotRankRewardTime;
	}
	INT32 GetGotRankRewardTime() const
	{
		return m_GotRankRewardTime;
	}
private:
	//历史最大战力
	INT32 m_MaxMilitary;
public:
	void SetMaxMilitary( INT32 v)
	{
		m_MaxMilitary=v;
	}
	INT32 GetMaxMilitary()
	{
		return m_MaxMilitary;
	}
	INT32 GetMaxMilitary() const
	{
		return m_MaxMilitary;
	}
private:
	//主公基础属性
	vector<INT32> m_MasterAttrs;
public:
	int SizeMasterAttrs()
	{
		return m_MasterAttrs.size();
	}
	const vector<INT32>& GetMasterAttrs() const
	{
		return m_MasterAttrs;
	}
	INT32 GetMasterAttrs(int Index) const
	{
		if(Index<0 || Index>=(int)m_MasterAttrs.size())
		{
			assert(false);
			return INT32();
		}
		return m_MasterAttrs[Index];
	}
	void SetMasterAttrs( const vector<INT32>& v )
	{
		m_MasterAttrs=v;
	}
	void ClearMasterAttrs( )
	{
		m_MasterAttrs.clear();
	}
	void SetMasterAttrs( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_MasterAttrs.size())
		{
			assert(false);
			return;
		}
		m_MasterAttrs[Index] = v;
	}
	void AddMasterAttrs( INT32 v = -1 )
	{
		m_MasterAttrs.push_back(v);
	}
private:
	//当前玩家战力
	INT32 m_CurMilitary;
public:
	void SetCurMilitary( INT32 v)
	{
		m_CurMilitary=v;
	}
	INT32 GetCurMilitary()
	{
		return m_CurMilitary;
	}
	INT32 GetCurMilitary() const
	{
		return m_CurMilitary;
	}
private:
	//玩家名字
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
	//游戏中心账号名
	string m_PlatName;
public:
	void SetPlatName( const string& v)
	{
		m_PlatName=v;
	}
	string GetPlatName()
	{
		return m_PlatName;
	}
	string GetPlatName() const
	{
		return m_PlatName;
	}
private:
	//游戏中心账号ID
	INT64 m_AccountId;
public:
	void SetAccountId( INT64 v)
	{
		m_AccountId=v;
	}
	INT64 GetAccountId()
	{
		return m_AccountId;
	}
	INT64 GetAccountId() const
	{
		return m_AccountId;
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
	//官阶
	INT32 m_Rank;
public:
	void SetRank( INT32 v)
	{
		m_Rank=v;
	}
	INT32 GetRank()
	{
		return m_Rank;
	}
	INT32 GetRank() const
	{
		return m_Rank;
	}
private:
	//战力
	INT32 m_FightPower;
public:
	void SetFightPower( INT32 v)
	{
		m_FightPower=v;
	}
	INT32 GetFightPower()
	{
		return m_FightPower;
	}
	INT32 GetFightPower() const
	{
		return m_FightPower;
	}
private:
	//用户累加的数据
	INT32 m_Sec;
public:
	void SetSec( INT32 v)
	{
		m_Sec=v;
	}
	INT32 GetSec()
	{
		return m_Sec;
	}
	INT32 GetSec() const
	{
		return m_Sec;
	}
private:
	//当前战力
	INT32 m_Military;
public:
	void SetMilitary( INT32 v)
	{
		m_Military=v;
	}
	INT32 GetMilitary()
	{
		return m_Military;
	}
	INT32 GetMilitary() const
	{
		return m_Military;
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
	//副本剩余次数
	INT32 m_DungeonRemainCount;
public:
	void SetDungeonRemainCount( INT32 v)
	{
		m_DungeonRemainCount=v;
	}
	INT32 GetDungeonRemainCount()
	{
		return m_DungeonRemainCount;
	}
	INT32 GetDungeonRemainCount() const
	{
		return m_DungeonRemainCount;
	}
private:
	//地图Id
	INT32 m_MapId;
public:
	void SetMapId( INT32 v)
	{
		m_MapId=v;
	}
	INT32 GetMapId()
	{
		return m_MapId;
	}
	INT32 GetMapId() const
	{
		return m_MapId;
	}
private:
	//X坐标
	float m_PosX;
public:
	void SetPosX( float v)
	{
		m_PosX=v;
	}
	float GetPosX()
	{
		return m_PosX;
	}
	float GetPosX() const
	{
		return m_PosX;
	}
private:
	//Y坐标
	float m_PosY;
public:
	void SetPosY( float v)
	{
		m_PosY=v;
	}
	float GetPosY()
	{
		return m_PosY;
	}
	float GetPosY() const
	{
		return m_PosY;
	}
private:
	//Z坐标
	float m_PosZ;
public:
	void SetPosZ( float v)
	{
		m_PosZ=v;
	}
	float GetPosZ()
	{
		return m_PosZ;
	}
	float GetPosZ() const
	{
		return m_PosZ;
	}
private:
	//位置方向
	INT32 m_Ry;
public:
	void SetRy( INT32 v)
	{
		m_Ry=v;
	}
	INT32 GetRy()
	{
		return m_Ry;
	}
	INT32 GetRy() const
	{
		return m_Ry;
	}
private:
	//技能CD列表
	vector<BaseAttrSkillCdInfoWraperV1> m_SkillCdArr;
public:
	int SizeSkillCdArr()
	{
		return m_SkillCdArr.size();
	}
	const vector<BaseAttrSkillCdInfoWraperV1>& GetSkillCdArr() const
	{
		return m_SkillCdArr;
	}
	BaseAttrSkillCdInfoWraperV1 GetSkillCdArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillCdArr.size())
		{
			assert(false);
			return BaseAttrSkillCdInfoWraperV1();
		}
		return m_SkillCdArr[Index];
	}
	void SetSkillCdArr( const vector<BaseAttrSkillCdInfoWraperV1>& v )
	{
		m_SkillCdArr=v;
	}
	void ClearSkillCdArr( )
	{
		m_SkillCdArr.clear();
	}
	void SetSkillCdArr( int Index, const BaseAttrSkillCdInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_SkillCdArr.size())
		{
			assert(false);
			return;
		}
		m_SkillCdArr[Index] = v;
	}
	void AddSkillCdArr( const BaseAttrSkillCdInfoWraperV1& v )
	{
		m_SkillCdArr.push_back(v);
	}
private:
	//BuffCD列表
	vector<BaseAttrBuffCdInfoWraperV1> m_BuffCdArr;
public:
	int SizeBuffCdArr()
	{
		return m_BuffCdArr.size();
	}
	const vector<BaseAttrBuffCdInfoWraperV1>& GetBuffCdArr() const
	{
		return m_BuffCdArr;
	}
	BaseAttrBuffCdInfoWraperV1 GetBuffCdArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_BuffCdArr.size())
		{
			assert(false);
			return BaseAttrBuffCdInfoWraperV1();
		}
		return m_BuffCdArr[Index];
	}
	void SetBuffCdArr( const vector<BaseAttrBuffCdInfoWraperV1>& v )
	{
		m_BuffCdArr=v;
	}
	void ClearBuffCdArr( )
	{
		m_BuffCdArr.clear();
	}
	void SetBuffCdArr( int Index, const BaseAttrBuffCdInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_BuffCdArr.size())
		{
			assert(false);
			return;
		}
		m_BuffCdArr[Index] = v;
	}
	void AddBuffCdArr( const BaseAttrBuffCdInfoWraperV1& v )
	{
		m_BuffCdArr.push_back(v);
	}
private:
	//当前所在场景
	BaseAttrSceneInfoWraperV1 m_CurrentScene;
public:
	void SetCurrentScene( const BaseAttrSceneInfoWraperV1& v)
	{
		m_CurrentScene=v;
	}
	BaseAttrSceneInfoWraperV1 GetCurrentScene()
	{
		return m_CurrentScene;
	}
	BaseAttrSceneInfoWraperV1 GetCurrentScene() const
	{
		return m_CurrentScene;
	}
private:
	//帮会Id
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
	//退出帮会时间
	INT32 m_ExitGuildTime;
public:
	void SetExitGuildTime( INT32 v)
	{
		m_ExitGuildTime=v;
	}
	INT32 GetExitGuildTime()
	{
		return m_ExitGuildTime;
	}
	INT32 GetExitGuildTime() const
	{
		return m_ExitGuildTime;
	}
private:
	//申请过的帮会
	vector<INT32> m_ApplyGuildId;
public:
	int SizeApplyGuildId()
	{
		return m_ApplyGuildId.size();
	}
	const vector<INT32>& GetApplyGuildId() const
	{
		return m_ApplyGuildId;
	}
	INT32 GetApplyGuildId(int Index) const
	{
		if(Index<0 || Index>=(int)m_ApplyGuildId.size())
		{
			assert(false);
			return INT32();
		}
		return m_ApplyGuildId[Index];
	}
	void SetApplyGuildId( const vector<INT32>& v )
	{
		m_ApplyGuildId=v;
	}
	void ClearApplyGuildId( )
	{
		m_ApplyGuildId.clear();
	}
	void SetApplyGuildId( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_ApplyGuildId.size())
		{
			assert(false);
			return;
		}
		m_ApplyGuildId[Index] = v;
	}
	void AddApplyGuildId( INT32 v = -1 )
	{
		m_ApplyGuildId.push_back(v);
	}
private:
	//当前帮贡
	INT32 m_CurGuildContribution;
public:
	void SetCurGuildContribution( INT32 v)
	{
		m_CurGuildContribution=v;
	}
	INT32 GetCurGuildContribution()
	{
		return m_CurGuildContribution;
	}
	INT32 GetCurGuildContribution() const
	{
		return m_CurGuildContribution;
	}
private:
	//最大帮贡
	INT32 m_MaxGuildContribution;
public:
	void SetMaxGuildContribution( INT32 v)
	{
		m_MaxGuildContribution=v;
	}
	INT32 GetMaxGuildContribution()
	{
		return m_MaxGuildContribution;
	}
	INT32 GetMaxGuildContribution() const
	{
		return m_MaxGuildContribution;
	}
private:
	//绑银
	INT32 m_BindMoney;
public:
	void SetBindMoney( INT32 v)
	{
		m_BindMoney=v;
	}
	INT32 GetBindMoney()
	{
		return m_BindMoney;
	}
	INT32 GetBindMoney() const
	{
		return m_BindMoney;
	}
private:
	//宝石
	INT32 m_Gem;
public:
	void SetGem( INT32 v)
	{
		m_Gem=v;
	}
	INT32 GetGem()
	{
		return m_Gem;
	}
	INT32 GetGem() const
	{
		return m_Gem;
	}
private:
	//服务器时间
	INT32 m_ServerTime;
public:
	void SetServerTime( INT32 v)
	{
		m_ServerTime=v;
	}
	INT32 GetServerTime()
	{
		return m_ServerTime;
	}
	INT32 GetServerTime() const
	{
		return m_ServerTime;
	}
private:
	//新手引导
	vector<KeyValue2IntIntWraper> m_NewbieGuide;
public:
	int SizeNewbieGuide()
	{
		return m_NewbieGuide.size();
	}
	const vector<KeyValue2IntIntWraper>& GetNewbieGuide() const
	{
		return m_NewbieGuide;
	}
	KeyValue2IntIntWraper GetNewbieGuide(int Index) const
	{
		if(Index<0 || Index>=(int)m_NewbieGuide.size())
		{
			assert(false);
			return KeyValue2IntIntWraper();
		}
		return m_NewbieGuide[Index];
	}
	void SetNewbieGuide( const vector<KeyValue2IntIntWraper>& v )
	{
		m_NewbieGuide=v;
	}
	void ClearNewbieGuide( )
	{
		m_NewbieGuide.clear();
	}
	void SetNewbieGuide( int Index, const KeyValue2IntIntWraper& v )
	{
		if(Index<0 || Index>=(int)m_NewbieGuide.size())
		{
			assert(false);
			return;
		}
		m_NewbieGuide[Index] = v;
	}
	void AddNewbieGuide( const KeyValue2IntIntWraper& v )
	{
		m_NewbieGuide.push_back(v);
	}
private:
	//江洋大盗奖励次数
	INT32 m_ThiefRewardNum;
public:
	void SetThiefRewardNum( INT32 v)
	{
		m_ThiefRewardNum=v;
	}
	INT32 GetThiefRewardNum()
	{
		return m_ThiefRewardNum;
	}
	INT32 GetThiefRewardNum() const
	{
		return m_ThiefRewardNum;
	}
private:
	//降妖奖励次数
	INT32 m_SubdueMonsterRewardNum;
public:
	void SetSubdueMonsterRewardNum( INT32 v)
	{
		m_SubdueMonsterRewardNum=v;
	}
	INT32 GetSubdueMonsterRewardNum()
	{
		return m_SubdueMonsterRewardNum;
	}
	INT32 GetSubdueMonsterRewardNum() const
	{
		return m_SubdueMonsterRewardNum;
	}
private:
	//世界Boss剩余次数
	INT32 m_WorldBossRemainTimes;
public:
	void SetWorldBossRemainTimes( INT32 v)
	{
		m_WorldBossRemainTimes=v;
	}
	INT32 GetWorldBossRemainTimes()
	{
		return m_WorldBossRemainTimes;
	}
	INT32 GetWorldBossRemainTimes() const
	{
		return m_WorldBossRemainTimes;
	}
private:
	//世界Boss伤害
	INT32 m_WorldBossHurt;
public:
	void SetWorldBossHurt( INT32 v)
	{
		m_WorldBossHurt=v;
	}
	INT32 GetWorldBossHurt()
	{
		return m_WorldBossHurt;
	}
	INT32 GetWorldBossHurt() const
	{
		return m_WorldBossHurt;
	}
private:
	//功能开启列表
	vector<BaseAttrIconOpenInfoWraperV1> m_FunctionOpenList;
public:
	int SizeFunctionOpenList()
	{
		return m_FunctionOpenList.size();
	}
	const vector<BaseAttrIconOpenInfoWraperV1>& GetFunctionOpenList() const
	{
		return m_FunctionOpenList;
	}
	BaseAttrIconOpenInfoWraperV1 GetFunctionOpenList(int Index) const
	{
		if(Index<0 || Index>=(int)m_FunctionOpenList.size())
		{
			assert(false);
			return BaseAttrIconOpenInfoWraperV1();
		}
		return m_FunctionOpenList[Index];
	}
	void SetFunctionOpenList( const vector<BaseAttrIconOpenInfoWraperV1>& v )
	{
		m_FunctionOpenList=v;
	}
	void ClearFunctionOpenList( )
	{
		m_FunctionOpenList.clear();
	}
	void SetFunctionOpenList( int Index, const BaseAttrIconOpenInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_FunctionOpenList.size())
		{
			assert(false);
			return;
		}
		m_FunctionOpenList[Index] = v;
	}
	void AddFunctionOpenList( const BaseAttrIconOpenInfoWraperV1& v )
	{
		m_FunctionOpenList.push_back(v);
	}
private:
	//总活力值
	INT32 m_TotalEnergyValue;
public:
	void SetTotalEnergyValue( INT32 v)
	{
		m_TotalEnergyValue=v;
	}
	INT32 GetTotalEnergyValue()
	{
		return m_TotalEnergyValue;
	}
	INT32 GetTotalEnergyValue() const
	{
		return m_TotalEnergyValue;
	}
private:
	//活力值信息容器
	vector<BaseAttrEnergyInfoWraperV1> m_EnergyArray;
public:
	int SizeEnergyArray()
	{
		return m_EnergyArray.size();
	}
	const vector<BaseAttrEnergyInfoWraperV1>& GetEnergyArray() const
	{
		return m_EnergyArray;
	}
	BaseAttrEnergyInfoWraperV1 GetEnergyArray(int Index) const
	{
		if(Index<0 || Index>=(int)m_EnergyArray.size())
		{
			assert(false);
			return BaseAttrEnergyInfoWraperV1();
		}
		return m_EnergyArray[Index];
	}
	void SetEnergyArray( const vector<BaseAttrEnergyInfoWraperV1>& v )
	{
		m_EnergyArray=v;
	}
	void ClearEnergyArray( )
	{
		m_EnergyArray.clear();
	}
	void SetEnergyArray( int Index, const BaseAttrEnergyInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_EnergyArray.size())
		{
			assert(false);
			return;
		}
		m_EnergyArray[Index] = v;
	}
	void AddEnergyArray( const BaseAttrEnergyInfoWraperV1& v )
	{
		m_EnergyArray.push_back(v);
	}
private:
	//PK状态
	INT32 m_PKState;
public:
	void SetPKState( INT32 v)
	{
		m_PKState=v;
	}
	INT32 GetPKState()
	{
		return m_PKState;
	}
	INT32 GetPKState() const
	{
		return m_PKState;
	}
private:
	//PK保护列表
	vector<KeyValue2IntBoolWraper> m_PKProtect;
public:
	int SizePKProtect()
	{
		return m_PKProtect.size();
	}
	const vector<KeyValue2IntBoolWraper>& GetPKProtect() const
	{
		return m_PKProtect;
	}
	KeyValue2IntBoolWraper GetPKProtect(int Index) const
	{
		if(Index<0 || Index>=(int)m_PKProtect.size())
		{
			assert(false);
			return KeyValue2IntBoolWraper();
		}
		return m_PKProtect[Index];
	}
	void SetPKProtect( const vector<KeyValue2IntBoolWraper>& v )
	{
		m_PKProtect=v;
	}
	void ClearPKProtect( )
	{
		m_PKProtect.clear();
	}
	void SetPKProtect( int Index, const KeyValue2IntBoolWraper& v )
	{
		if(Index<0 || Index>=(int)m_PKProtect.size())
		{
			assert(false);
			return;
		}
		m_PKProtect[Index] = v;
	}
	void AddPKProtect( const KeyValue2IntBoolWraper& v )
	{
		m_PKProtect.push_back(v);
	}
private:
	//帮会修炼
	vector<BaseAttrScienceInfoWraperV1> m_GuildScienArray;
public:
	int SizeGuildScienArray()
	{
		return m_GuildScienArray.size();
	}
	const vector<BaseAttrScienceInfoWraperV1>& GetGuildScienArray() const
	{
		return m_GuildScienArray;
	}
	BaseAttrScienceInfoWraperV1 GetGuildScienArray(int Index) const
	{
		if(Index<0 || Index>=(int)m_GuildScienArray.size())
		{
			assert(false);
			return BaseAttrScienceInfoWraperV1();
		}
		return m_GuildScienArray[Index];
	}
	void SetGuildScienArray( const vector<BaseAttrScienceInfoWraperV1>& v )
	{
		m_GuildScienArray=v;
	}
	void ClearGuildScienArray( )
	{
		m_GuildScienArray.clear();
	}
	void SetGuildScienArray( int Index, const BaseAttrScienceInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_GuildScienArray.size())
		{
			assert(false);
			return;
		}
		m_GuildScienArray[Index] = v;
	}
	void AddGuildScienArray( const BaseAttrScienceInfoWraperV1& v )
	{
		m_GuildScienArray.push_back(v);
	}
private:
	//修炼升级消耗总金币
	INT32 m_ScienceTotalMoney;
public:
	void SetScienceTotalMoney( INT32 v)
	{
		m_ScienceTotalMoney=v;
	}
	INT32 GetScienceTotalMoney()
	{
		return m_ScienceTotalMoney;
	}
	INT32 GetScienceTotalMoney() const
	{
		return m_ScienceTotalMoney;
	}

};

#endif
