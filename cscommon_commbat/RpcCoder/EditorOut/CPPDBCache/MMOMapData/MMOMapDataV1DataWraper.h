/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperMMOMapData.h
* Author:       甘业清
* Description:  45度MMO地图数据同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_MMOMAPDATA_H
#define __SYNC_WRAPER_MMOMAPDATA_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "MMOMapDataV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//MDVector3封装类
class MMOMapDataMDVector3WraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MMOMapDataMDVector3WraperV1()
	{
		
		m_X = 0;
		m_Y = 0;
		m_Z = 0;

	}
	//赋值构造函数
	MMOMapDataMDVector3WraperV1(const MMOMapDataMDVector3V1& v){ Init(v); }
	//等号重载函数
	void operator = (const MMOMapDataMDVector3V1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MMOMapDataMDVector3V1 ToPB() const
	{
		MMOMapDataMDVector3V1 v;
		v.set_x( m_X );
		v.set_y( m_Y );
		v.set_z( m_Z );

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
		MMOMapDataMDVector3V1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>X(X) [float]</li>\r\n";
		htmlBuff += "<li>Y(Y) [float]</li>\r\n";
		htmlBuff += "<li>Z(Z) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Y：%.2ff</li>\r\n",m_Y);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Z：%.2ff</li>\r\n",m_Z);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MMOMapDataMDVector3V1& v)
	{
		m_X = v.x();
		m_Y = v.y();
		m_Z = v.z();

	}

private:
	//X
	float m_X;
public:
	void SetX( float v)
	{
		m_X=v;
	}
	float GetX()
	{
		return m_X;
	}
	float GetX() const
	{
		return m_X;
	}
private:
	//Y
	float m_Y;
public:
	void SetY( float v)
	{
		m_Y=v;
	}
	float GetY()
	{
		return m_Y;
	}
	float GetY() const
	{
		return m_Y;
	}
private:
	//Z
	float m_Z;
public:
	void SetZ( float v)
	{
		m_Z=v;
	}
	float GetZ()
	{
		return m_Z;
	}
	float GetZ() const
	{
		return m_Z;
	}

};
//节点信息封装类
class MMOMapDataNodeInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MMOMapDataNodeInfoWraperV1()
	{
		
		m_RelevanceArea = 0;
		m_PassKillEnemyID = 0;
		m_PassKillEnemyNum = 0;
		m_PassTime = 0;
		m_PassUseItemID = 0;
		m_PassUseItemNum = 0;
		m_PassCollectItemID = 0;
		m_PassCollectItemNum = 0;
		m_PassConditionType = 0;
		m_NodePos1 = MMOMapDataMDVector3WraperV1();
		m_NodePos2 = MMOMapDataMDVector3WraperV1();

	}
	//赋值构造函数
	MMOMapDataNodeInfoWraperV1(const MMOMapDataNodeInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MMOMapDataNodeInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MMOMapDataNodeInfoV1 ToPB() const
	{
		MMOMapDataNodeInfoV1 v;
		v.set_relevancearea( m_RelevanceArea );
		v.set_passkillenemyid( m_PassKillEnemyID );
		v.set_passkillenemynum( m_PassKillEnemyNum );
		v.set_passtime( m_PassTime );
		v.set_passuseitemid( m_PassUseItemID );
		v.set_passuseitemnum( m_PassUseItemNum );
		v.set_passcollectitemid( m_PassCollectItemID );
		v.set_passcollectitemnum( m_PassCollectItemNum );
		v.set_passconditiontype( m_PassConditionType );
		*v.mutable_nodepos1()= m_NodePos1.ToPB();
		*v.mutable_nodepos2()= m_NodePos2.ToPB();

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
		MMOMapDataNodeInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>RelevanceArea(关联坑点区域) [sint32]</li>\r\n";
		htmlBuff += "<li>PassKillEnemyID(敌人ID) [sint32]</li>\r\n";
		htmlBuff += "<li>PassKillEnemyNum(杀掉敌人数量) [sint32]</li>\r\n";
		htmlBuff += "<li>PassTime(通过节点的时间) [sint32]</li>\r\n";
		htmlBuff += "<li>PassUseItemID(使用道具的ID) [sint32]</li>\r\n";
		htmlBuff += "<li>PassUseItemNum(使用道具的数量) [sint32]</li>\r\n";
		htmlBuff += "<li>PassCollectItemID(收集道具的ID) [sint32]</li>\r\n";
		htmlBuff += "<li>PassCollectItemNum(收集道具的数量) [sint32]</li>\r\n";
		htmlBuff += "<li>PassConditionType(通过条件类型) [sint32]</li>\r\n";
		htmlBuff += "<li>NodePos1(节点位置1) [MDVector3]</li>\r\n";
		htmlBuff += "<li>NodePos2(节点位置2) [MDVector3]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>RelevanceArea：%di</li>\r\n",m_RelevanceArea);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PassKillEnemyID：%di</li>\r\n",m_PassKillEnemyID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PassKillEnemyNum：%di</li>\r\n",m_PassKillEnemyNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PassTime：%di</li>\r\n",m_PassTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PassUseItemID：%di</li>\r\n",m_PassUseItemID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PassUseItemNum：%di</li>\r\n",m_PassUseItemNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PassCollectItemID：%di</li>\r\n",m_PassCollectItemID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PassCollectItemNum：%di</li>\r\n",m_PassCollectItemNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PassConditionType：%di</li>\r\n",m_PassConditionType);
		htmlBuff += tmpLine;
		htmlBuff += "<li>NodePos1：</li>\r\n";
		htmlBuff += m_NodePos1.HtmlDescHeader();
		htmlBuff += m_NodePos1.ToHtml();
		htmlBuff += "<li>NodePos2：</li>\r\n";
		htmlBuff += m_NodePos2.HtmlDescHeader();
		htmlBuff += m_NodePos2.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MMOMapDataNodeInfoV1& v)
	{
		m_RelevanceArea = v.relevancearea();
		m_PassKillEnemyID = v.passkillenemyid();
		m_PassKillEnemyNum = v.passkillenemynum();
		m_PassTime = v.passtime();
		m_PassUseItemID = v.passuseitemid();
		m_PassUseItemNum = v.passuseitemnum();
		m_PassCollectItemID = v.passcollectitemid();
		m_PassCollectItemNum = v.passcollectitemnum();
		m_PassConditionType = v.passconditiontype();
		m_NodePos1 = v.nodepos1();
		m_NodePos2 = v.nodepos2();

	}

private:
	//关联坑点区域
	INT32 m_RelevanceArea;
public:
	void SetRelevanceArea( INT32 v)
	{
		m_RelevanceArea=v;
	}
	INT32 GetRelevanceArea()
	{
		return m_RelevanceArea;
	}
	INT32 GetRelevanceArea() const
	{
		return m_RelevanceArea;
	}
private:
	//敌人ID
	INT32 m_PassKillEnemyID;
public:
	void SetPassKillEnemyID( INT32 v)
	{
		m_PassKillEnemyID=v;
	}
	INT32 GetPassKillEnemyID()
	{
		return m_PassKillEnemyID;
	}
	INT32 GetPassKillEnemyID() const
	{
		return m_PassKillEnemyID;
	}
private:
	//杀掉敌人数量
	INT32 m_PassKillEnemyNum;
public:
	void SetPassKillEnemyNum( INT32 v)
	{
		m_PassKillEnemyNum=v;
	}
	INT32 GetPassKillEnemyNum()
	{
		return m_PassKillEnemyNum;
	}
	INT32 GetPassKillEnemyNum() const
	{
		return m_PassKillEnemyNum;
	}
private:
	//通过节点的时间
	INT32 m_PassTime;
public:
	void SetPassTime( INT32 v)
	{
		m_PassTime=v;
	}
	INT32 GetPassTime()
	{
		return m_PassTime;
	}
	INT32 GetPassTime() const
	{
		return m_PassTime;
	}
private:
	//使用道具的ID
	INT32 m_PassUseItemID;
public:
	void SetPassUseItemID( INT32 v)
	{
		m_PassUseItemID=v;
	}
	INT32 GetPassUseItemID()
	{
		return m_PassUseItemID;
	}
	INT32 GetPassUseItemID() const
	{
		return m_PassUseItemID;
	}
private:
	//使用道具的数量
	INT32 m_PassUseItemNum;
public:
	void SetPassUseItemNum( INT32 v)
	{
		m_PassUseItemNum=v;
	}
	INT32 GetPassUseItemNum()
	{
		return m_PassUseItemNum;
	}
	INT32 GetPassUseItemNum() const
	{
		return m_PassUseItemNum;
	}
private:
	//收集道具的ID
	INT32 m_PassCollectItemID;
public:
	void SetPassCollectItemID( INT32 v)
	{
		m_PassCollectItemID=v;
	}
	INT32 GetPassCollectItemID()
	{
		return m_PassCollectItemID;
	}
	INT32 GetPassCollectItemID() const
	{
		return m_PassCollectItemID;
	}
private:
	//收集道具的数量
	INT32 m_PassCollectItemNum;
public:
	void SetPassCollectItemNum( INT32 v)
	{
		m_PassCollectItemNum=v;
	}
	INT32 GetPassCollectItemNum()
	{
		return m_PassCollectItemNum;
	}
	INT32 GetPassCollectItemNum() const
	{
		return m_PassCollectItemNum;
	}
private:
	//通过条件类型
	INT32 m_PassConditionType;
public:
	void SetPassConditionType( INT32 v)
	{
		m_PassConditionType=v;
	}
	INT32 GetPassConditionType()
	{
		return m_PassConditionType;
	}
	INT32 GetPassConditionType() const
	{
		return m_PassConditionType;
	}
private:
	//节点位置1
	MMOMapDataMDVector3WraperV1 m_NodePos1;
public:
	void SetNodePos1( const MMOMapDataMDVector3WraperV1& v)
	{
		m_NodePos1=v;
	}
	MMOMapDataMDVector3WraperV1 GetNodePos1()
	{
		return m_NodePos1;
	}
	MMOMapDataMDVector3WraperV1 GetNodePos1() const
	{
		return m_NodePos1;
	}
private:
	//节点位置2
	MMOMapDataMDVector3WraperV1 m_NodePos2;
public:
	void SetNodePos2( const MMOMapDataMDVector3WraperV1& v)
	{
		m_NodePos2=v;
	}
	MMOMapDataMDVector3WraperV1 GetNodePos2()
	{
		return m_NodePos2;
	}
	MMOMapDataMDVector3WraperV1 GetNodePos2() const
	{
		return m_NodePos2;
	}

};
//失败信息封装类
class MMOMapDataDefeatInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MMOMapDataDefeatInfoWraperV1()
	{
		
		m_DefeatConditionSpared = false;
		m_DefeatConditionTimeOver = false;
		m_DefeatConditionHP = false;
		m_DefeatTime = 0;
		m_DefeatID = 0;
		m_DefeatHP = 0;

	}
	//赋值构造函数
	MMOMapDataDefeatInfoWraperV1(const MMOMapDataDefeatInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MMOMapDataDefeatInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MMOMapDataDefeatInfoV1 ToPB() const
	{
		MMOMapDataDefeatInfoV1 v;
		v.set_defeatconditionspared( m_DefeatConditionSpared );
		v.set_defeatconditiontimeover( m_DefeatConditionTimeOver );
		v.set_defeatconditionhp( m_DefeatConditionHP );
		v.set_defeattime( m_DefeatTime );
		v.set_defeatid( m_DefeatID );
		v.set_defeathp( m_DefeatHP );

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
		MMOMapDataDefeatInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DefeatConditionSpared(所有角色死亡) [bool]</li>\r\n";
		htmlBuff += "<li>DefeatConditionTimeOver(失败条件到时) [bool]</li>\r\n";
		htmlBuff += "<li>DefeatConditionHP(失败条件血量) [bool]</li>\r\n";
		htmlBuff += "<li>DefeatTime(失败条件时间) [sint32]</li>\r\n";
		htmlBuff += "<li>DefeatID(失败条件ID) [sint32]</li>\r\n";
		htmlBuff += "<li>DefeatHP(失败条件血量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>DefeatConditionSpared：%di</li>\r\n",m_DefeatConditionSpared);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DefeatConditionTimeOver：%di</li>\r\n",m_DefeatConditionTimeOver);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DefeatConditionHP：%di</li>\r\n",m_DefeatConditionHP);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DefeatTime：%di</li>\r\n",m_DefeatTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DefeatID：%di</li>\r\n",m_DefeatID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DefeatHP：%di</li>\r\n",m_DefeatHP);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MMOMapDataDefeatInfoV1& v)
	{
		m_DefeatConditionSpared = v.defeatconditionspared();
		m_DefeatConditionTimeOver = v.defeatconditiontimeover();
		m_DefeatConditionHP = v.defeatconditionhp();
		m_DefeatTime = v.defeattime();
		m_DefeatID = v.defeatid();
		m_DefeatHP = v.defeathp();

	}

private:
	//所有角色死亡
	bool m_DefeatConditionSpared;
public:
	void SetDefeatConditionSpared( bool v)
	{
		m_DefeatConditionSpared=v;
	}
	bool GetDefeatConditionSpared()
	{
		return m_DefeatConditionSpared;
	}
	bool GetDefeatConditionSpared() const
	{
		return m_DefeatConditionSpared;
	}
private:
	//失败条件到时
	bool m_DefeatConditionTimeOver;
public:
	void SetDefeatConditionTimeOver( bool v)
	{
		m_DefeatConditionTimeOver=v;
	}
	bool GetDefeatConditionTimeOver()
	{
		return m_DefeatConditionTimeOver;
	}
	bool GetDefeatConditionTimeOver() const
	{
		return m_DefeatConditionTimeOver;
	}
private:
	//失败条件血量
	bool m_DefeatConditionHP;
public:
	void SetDefeatConditionHP( bool v)
	{
		m_DefeatConditionHP=v;
	}
	bool GetDefeatConditionHP()
	{
		return m_DefeatConditionHP;
	}
	bool GetDefeatConditionHP() const
	{
		return m_DefeatConditionHP;
	}
private:
	//失败条件时间
	INT32 m_DefeatTime;
public:
	void SetDefeatTime( INT32 v)
	{
		m_DefeatTime=v;
	}
	INT32 GetDefeatTime()
	{
		return m_DefeatTime;
	}
	INT32 GetDefeatTime() const
	{
		return m_DefeatTime;
	}
private:
	//失败条件ID
	INT32 m_DefeatID;
public:
	void SetDefeatID( INT32 v)
	{
		m_DefeatID=v;
	}
	INT32 GetDefeatID()
	{
		return m_DefeatID;
	}
	INT32 GetDefeatID() const
	{
		return m_DefeatID;
	}
private:
	//失败条件血量
	INT32 m_DefeatHP;
public:
	void SetDefeatHP( INT32 v)
	{
		m_DefeatHP=v;
	}
	INT32 GetDefeatHP()
	{
		return m_DefeatHP;
	}
	INT32 GetDefeatHP() const
	{
		return m_DefeatHP;
	}

};
//坑点信息封装类
class MMOMapDataPointInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MMOMapDataPointInfoWraperV1()
	{
		
		m_SpriteType = 0;
		m_SpriteID = 0;
		m_Area = 0;
		m_PointPos = MMOMapDataMDVector3WraperV1();
		m_PointRot = MMOMapDataMDVector3WraperV1();
		m_RefreshType = 0;
		m_UnlockTime = 0;
		m_EnemyID = 0;
		m_EnemyNum = 0;
		m_RebirthType = 0;
		m_RebirthEnemyID = 0;
		m_RebirthEnemyNum = 0;
		m_AfterDeathTime = 0;
		m_RebirthNum = -1;

	}
	//赋值构造函数
	MMOMapDataPointInfoWraperV1(const MMOMapDataPointInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MMOMapDataPointInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MMOMapDataPointInfoV1 ToPB() const
	{
		MMOMapDataPointInfoV1 v;
		v.set_spritetype( m_SpriteType );
		v.set_spriteid( m_SpriteID );
		v.set_area( m_Area );
		*v.mutable_pointpos()= m_PointPos.ToPB();
		*v.mutable_pointrot()= m_PointRot.ToPB();
		v.set_refreshtype( m_RefreshType );
		v.set_unlocktime( m_UnlockTime );
		v.set_enemyid( m_EnemyID );
		v.set_enemynum( m_EnemyNum );
		v.set_rebirthtype( m_RebirthType );
		v.set_rebirthenemyid( m_RebirthEnemyID );
		v.set_rebirthenemynum( m_RebirthEnemyNum );
		v.set_afterdeathtime( m_AfterDeathTime );
		v.set_rebirthnum( m_RebirthNum );

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
		MMOMapDataPointInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SpriteType(精灵类型) [sint32]</li>\r\n";
		htmlBuff += "<li>SpriteID(精灵ID) [sint32]</li>\r\n";
		htmlBuff += "<li>Area(隶属区域) [sint32]</li>\r\n";
		htmlBuff += "<li>PointPos(坑点位置) [MDVector3]</li>\r\n";
		htmlBuff += "<li>PointRot(坑点朝向) [MDVector3]</li>\r\n";
		htmlBuff += "<li>RefreshType(刷新类型) [sint32]</li>\r\n";
		htmlBuff += "<li>UnlockTime(开启时间) [sint32]</li>\r\n";
		htmlBuff += "<li>EnemyID(杀死敌人的ID) [sint32]</li>\r\n";
		htmlBuff += "<li>EnemyNum(杀死敌人个数) [sint32]</li>\r\n";
		htmlBuff += "<li>RebirthType(重生类型) [sint32]</li>\r\n";
		htmlBuff += "<li>RebirthEnemyID(重生的敌人ID) [sint32]</li>\r\n";
		htmlBuff += "<li>RebirthEnemyNum(重生的敌人数量) [sint32]</li>\r\n";
		htmlBuff += "<li>AfterDeathTime(怪物死亡后的时间) [sint32]</li>\r\n";
		htmlBuff += "<li>RebirthNum(重生次数) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>SpriteType：%di</li>\r\n",m_SpriteType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SpriteID：%di</li>\r\n",m_SpriteID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Area：%di</li>\r\n",m_Area);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PointPos：</li>\r\n";
		htmlBuff += m_PointPos.HtmlDescHeader();
		htmlBuff += m_PointPos.ToHtml();
		htmlBuff += "<li>PointRot：</li>\r\n";
		htmlBuff += m_PointRot.HtmlDescHeader();
		htmlBuff += m_PointRot.ToHtml();
		tmpLine.Fmt("<li>RefreshType：%di</li>\r\n",m_RefreshType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UnlockTime：%di</li>\r\n",m_UnlockTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EnemyID：%di</li>\r\n",m_EnemyID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EnemyNum：%di</li>\r\n",m_EnemyNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RebirthType：%di</li>\r\n",m_RebirthType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RebirthEnemyID：%di</li>\r\n",m_RebirthEnemyID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RebirthEnemyNum：%di</li>\r\n",m_RebirthEnemyNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AfterDeathTime：%di</li>\r\n",m_AfterDeathTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RebirthNum：%di</li>\r\n",m_RebirthNum);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MMOMapDataPointInfoV1& v)
	{
		m_SpriteType = v.spritetype();
		m_SpriteID = v.spriteid();
		m_Area = v.area();
		m_PointPos = v.pointpos();
		m_PointRot = v.pointrot();
		m_RefreshType = v.refreshtype();
		m_UnlockTime = v.unlocktime();
		m_EnemyID = v.enemyid();
		m_EnemyNum = v.enemynum();
		m_RebirthType = v.rebirthtype();
		m_RebirthEnemyID = v.rebirthenemyid();
		m_RebirthEnemyNum = v.rebirthenemynum();
		m_AfterDeathTime = v.afterdeathtime();
		m_RebirthNum = v.rebirthnum();

	}

private:
	//精灵类型
	INT32 m_SpriteType;
public:
	void SetSpriteType( INT32 v)
	{
		m_SpriteType=v;
	}
	INT32 GetSpriteType()
	{
		return m_SpriteType;
	}
	INT32 GetSpriteType() const
	{
		return m_SpriteType;
	}
private:
	//精灵ID
	INT32 m_SpriteID;
public:
	void SetSpriteID( INT32 v)
	{
		m_SpriteID=v;
	}
	INT32 GetSpriteID()
	{
		return m_SpriteID;
	}
	INT32 GetSpriteID() const
	{
		return m_SpriteID;
	}
private:
	//隶属区域
	INT32 m_Area;
public:
	void SetArea( INT32 v)
	{
		m_Area=v;
	}
	INT32 GetArea()
	{
		return m_Area;
	}
	INT32 GetArea() const
	{
		return m_Area;
	}
private:
	//坑点位置
	MMOMapDataMDVector3WraperV1 m_PointPos;
public:
	void SetPointPos( const MMOMapDataMDVector3WraperV1& v)
	{
		m_PointPos=v;
	}
	MMOMapDataMDVector3WraperV1 GetPointPos()
	{
		return m_PointPos;
	}
	MMOMapDataMDVector3WraperV1 GetPointPos() const
	{
		return m_PointPos;
	}
private:
	//坑点朝向
	MMOMapDataMDVector3WraperV1 m_PointRot;
public:
	void SetPointRot( const MMOMapDataMDVector3WraperV1& v)
	{
		m_PointRot=v;
	}
	MMOMapDataMDVector3WraperV1 GetPointRot()
	{
		return m_PointRot;
	}
	MMOMapDataMDVector3WraperV1 GetPointRot() const
	{
		return m_PointRot;
	}
private:
	//刷新类型
	INT32 m_RefreshType;
public:
	void SetRefreshType( INT32 v)
	{
		m_RefreshType=v;
	}
	INT32 GetRefreshType()
	{
		return m_RefreshType;
	}
	INT32 GetRefreshType() const
	{
		return m_RefreshType;
	}
private:
	//开启时间
	INT32 m_UnlockTime;
public:
	void SetUnlockTime( INT32 v)
	{
		m_UnlockTime=v;
	}
	INT32 GetUnlockTime()
	{
		return m_UnlockTime;
	}
	INT32 GetUnlockTime() const
	{
		return m_UnlockTime;
	}
private:
	//杀死敌人的ID
	INT32 m_EnemyID;
public:
	void SetEnemyID( INT32 v)
	{
		m_EnemyID=v;
	}
	INT32 GetEnemyID()
	{
		return m_EnemyID;
	}
	INT32 GetEnemyID() const
	{
		return m_EnemyID;
	}
private:
	//杀死敌人个数
	INT32 m_EnemyNum;
public:
	void SetEnemyNum( INT32 v)
	{
		m_EnemyNum=v;
	}
	INT32 GetEnemyNum()
	{
		return m_EnemyNum;
	}
	INT32 GetEnemyNum() const
	{
		return m_EnemyNum;
	}
private:
	//重生类型
	INT32 m_RebirthType;
public:
	void SetRebirthType( INT32 v)
	{
		m_RebirthType=v;
	}
	INT32 GetRebirthType()
	{
		return m_RebirthType;
	}
	INT32 GetRebirthType() const
	{
		return m_RebirthType;
	}
private:
	//重生的敌人ID
	INT32 m_RebirthEnemyID;
public:
	void SetRebirthEnemyID( INT32 v)
	{
		m_RebirthEnemyID=v;
	}
	INT32 GetRebirthEnemyID()
	{
		return m_RebirthEnemyID;
	}
	INT32 GetRebirthEnemyID() const
	{
		return m_RebirthEnemyID;
	}
private:
	//重生的敌人数量
	INT32 m_RebirthEnemyNum;
public:
	void SetRebirthEnemyNum( INT32 v)
	{
		m_RebirthEnemyNum=v;
	}
	INT32 GetRebirthEnemyNum()
	{
		return m_RebirthEnemyNum;
	}
	INT32 GetRebirthEnemyNum() const
	{
		return m_RebirthEnemyNum;
	}
private:
	//怪物死亡后的时间
	INT32 m_AfterDeathTime;
public:
	void SetAfterDeathTime( INT32 v)
	{
		m_AfterDeathTime=v;
	}
	INT32 GetAfterDeathTime()
	{
		return m_AfterDeathTime;
	}
	INT32 GetAfterDeathTime() const
	{
		return m_AfterDeathTime;
	}
private:
	//重生次数
	INT32 m_RebirthNum;
public:
	void SetRebirthNum( INT32 v)
	{
		m_RebirthNum=v;
	}
	INT32 GetRebirthNum()
	{
		return m_RebirthNum;
	}
	INT32 GetRebirthNum() const
	{
		return m_RebirthNum;
	}

};
//基础数据封装类
class MMOMapDataBaseDataWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MMOMapDataBaseDataWraperV1()
	{
		
		m_DataName = "";

	}
	//赋值构造函数
	MMOMapDataBaseDataWraperV1(const MMOMapDataBaseDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MMOMapDataBaseDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MMOMapDataBaseDataV1 ToPB() const
	{
		MMOMapDataBaseDataV1 v;
		v.set_dataname( m_DataName );

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
		MMOMapDataBaseDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DataName(地图文件名称) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>DataName：\""+m_DataName+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MMOMapDataBaseDataV1& v)
	{
		m_DataName = v.dataname();

	}

private:
	//地图文件名称
	string m_DataName;
public:
	void SetDataName( const string& v)
	{
		m_DataName=v;
	}
	string GetDataName()
	{
		return m_DataName;
	}
	string GetDataName() const
	{
		return m_DataName;
	}

};
//出生点封装类
class MMOMapDataSpawnInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MMOMapDataSpawnInfoWraperV1()
	{
		
		m_SpawnPos = MMOMapDataMDVector3WraperV1();
		m_SpawnRot = MMOMapDataMDVector3WraperV1();
		m_SpawnIndex = 0;

	}
	//赋值构造函数
	MMOMapDataSpawnInfoWraperV1(const MMOMapDataSpawnInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MMOMapDataSpawnInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MMOMapDataSpawnInfoV1 ToPB() const
	{
		MMOMapDataSpawnInfoV1 v;
		*v.mutable_spawnpos()= m_SpawnPos.ToPB();
		*v.mutable_spawnrot()= m_SpawnRot.ToPB();
		v.set_spawnindex( m_SpawnIndex );

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
		MMOMapDataSpawnInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SpawnPos(出生点的位置) [MDVector3]</li>\r\n";
		htmlBuff += "<li>SpawnRot(出生后的朝向) [MDVector3]</li>\r\n";
		htmlBuff += "<li>SpawnIndex(出生点编号) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>SpawnPos：</li>\r\n";
		htmlBuff += m_SpawnPos.HtmlDescHeader();
		htmlBuff += m_SpawnPos.ToHtml();
		htmlBuff += "<li>SpawnRot：</li>\r\n";
		htmlBuff += m_SpawnRot.HtmlDescHeader();
		htmlBuff += m_SpawnRot.ToHtml();
		tmpLine.Fmt("<li>SpawnIndex：%di</li>\r\n",m_SpawnIndex);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MMOMapDataSpawnInfoV1& v)
	{
		m_SpawnPos = v.spawnpos();
		m_SpawnRot = v.spawnrot();
		m_SpawnIndex = v.spawnindex();

	}

private:
	//出生点的位置
	MMOMapDataMDVector3WraperV1 m_SpawnPos;
public:
	void SetSpawnPos( const MMOMapDataMDVector3WraperV1& v)
	{
		m_SpawnPos=v;
	}
	MMOMapDataMDVector3WraperV1 GetSpawnPos()
	{
		return m_SpawnPos;
	}
	MMOMapDataMDVector3WraperV1 GetSpawnPos() const
	{
		return m_SpawnPos;
	}
private:
	//出生后的朝向
	MMOMapDataMDVector3WraperV1 m_SpawnRot;
public:
	void SetSpawnRot( const MMOMapDataMDVector3WraperV1& v)
	{
		m_SpawnRot=v;
	}
	MMOMapDataMDVector3WraperV1 GetSpawnRot()
	{
		return m_SpawnRot;
	}
	MMOMapDataMDVector3WraperV1 GetSpawnRot() const
	{
		return m_SpawnRot;
	}
private:
	//出生点编号
	INT32 m_SpawnIndex;
public:
	void SetSpawnIndex( INT32 v)
	{
		m_SpawnIndex=v;
	}
	INT32 GetSpawnIndex()
	{
		return m_SpawnIndex;
	}
	INT32 GetSpawnIndex() const
	{
		return m_SpawnIndex;
	}

};
//传送门信息封装类
class MMOMapDataPortalInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MMOMapDataPortalInfoWraperV1()
	{
		
		m_SourcePos = MMOMapDataMDVector3WraperV1();
		m_TargetPos = MMOMapDataMDVector3WraperV1();
		m_TargetRot = MMOMapDataMDVector3WraperV1();
		m_TargetDungeonID = 0;
		m_TargetSpawnIndex = 0;
		m_PortalType = 0;

	}
	//赋值构造函数
	MMOMapDataPortalInfoWraperV1(const MMOMapDataPortalInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MMOMapDataPortalInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MMOMapDataPortalInfoV1 ToPB() const
	{
		MMOMapDataPortalInfoV1 v;
		*v.mutable_sourcepos()= m_SourcePos.ToPB();
		*v.mutable_targetpos()= m_TargetPos.ToPB();
		*v.mutable_targetrot()= m_TargetRot.ToPB();
		v.set_targetdungeonid( m_TargetDungeonID );
		v.set_targetspawnindex( m_TargetSpawnIndex );
		v.set_portaltype( m_PortalType );

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
		MMOMapDataPortalInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SourcePos(起点位置) [MDVector3]</li>\r\n";
		htmlBuff += "<li>TargetPos(目标的位置) [MDVector3]</li>\r\n";
		htmlBuff += "<li>TargetRot(传送后的) [MDVector3]</li>\r\n";
		htmlBuff += "<li>TargetDungeonID(目标场景ID) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetSpawnIndex(目标场景的出生点索引) [sint32]</li>\r\n";
		htmlBuff += "<li>PortalType(传送类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>SourcePos：</li>\r\n";
		htmlBuff += m_SourcePos.HtmlDescHeader();
		htmlBuff += m_SourcePos.ToHtml();
		htmlBuff += "<li>TargetPos：</li>\r\n";
		htmlBuff += m_TargetPos.HtmlDescHeader();
		htmlBuff += m_TargetPos.ToHtml();
		htmlBuff += "<li>TargetRot：</li>\r\n";
		htmlBuff += m_TargetRot.HtmlDescHeader();
		htmlBuff += m_TargetRot.ToHtml();
		tmpLine.Fmt("<li>TargetDungeonID：%di</li>\r\n",m_TargetDungeonID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetSpawnIndex：%di</li>\r\n",m_TargetSpawnIndex);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PortalType：%di</li>\r\n",m_PortalType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MMOMapDataPortalInfoV1& v)
	{
		m_SourcePos = v.sourcepos();
		m_TargetPos = v.targetpos();
		m_TargetRot = v.targetrot();
		m_TargetDungeonID = v.targetdungeonid();
		m_TargetSpawnIndex = v.targetspawnindex();
		m_PortalType = v.portaltype();

	}

private:
	//起点位置
	MMOMapDataMDVector3WraperV1 m_SourcePos;
public:
	void SetSourcePos( const MMOMapDataMDVector3WraperV1& v)
	{
		m_SourcePos=v;
	}
	MMOMapDataMDVector3WraperV1 GetSourcePos()
	{
		return m_SourcePos;
	}
	MMOMapDataMDVector3WraperV1 GetSourcePos() const
	{
		return m_SourcePos;
	}
private:
	//目标的位置
	MMOMapDataMDVector3WraperV1 m_TargetPos;
public:
	void SetTargetPos( const MMOMapDataMDVector3WraperV1& v)
	{
		m_TargetPos=v;
	}
	MMOMapDataMDVector3WraperV1 GetTargetPos()
	{
		return m_TargetPos;
	}
	MMOMapDataMDVector3WraperV1 GetTargetPos() const
	{
		return m_TargetPos;
	}
private:
	//传送后的
	MMOMapDataMDVector3WraperV1 m_TargetRot;
public:
	void SetTargetRot( const MMOMapDataMDVector3WraperV1& v)
	{
		m_TargetRot=v;
	}
	MMOMapDataMDVector3WraperV1 GetTargetRot()
	{
		return m_TargetRot;
	}
	MMOMapDataMDVector3WraperV1 GetTargetRot() const
	{
		return m_TargetRot;
	}
private:
	//目标场景ID
	INT32 m_TargetDungeonID;
public:
	void SetTargetDungeonID( INT32 v)
	{
		m_TargetDungeonID=v;
	}
	INT32 GetTargetDungeonID()
	{
		return m_TargetDungeonID;
	}
	INT32 GetTargetDungeonID() const
	{
		return m_TargetDungeonID;
	}
private:
	//目标场景的出生点索引
	INT32 m_TargetSpawnIndex;
public:
	void SetTargetSpawnIndex( INT32 v)
	{
		m_TargetSpawnIndex=v;
	}
	INT32 GetTargetSpawnIndex()
	{
		return m_TargetSpawnIndex;
	}
	INT32 GetTargetSpawnIndex() const
	{
		return m_TargetSpawnIndex;
	}
private:
	//传送类型
	INT32 m_PortalType;
public:
	void SetPortalType( INT32 v)
	{
		m_PortalType=v;
	}
	INT32 GetPortalType()
	{
		return m_PortalType;
	}
	INT32 GetPortalType() const
	{
		return m_PortalType;
	}

};
//信息封装类
class MMOMapDataInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MMOMapDataInfoWraperV1()
	{
		
		m_BaseInfo = MMOMapDataBaseDataWraperV1();
		m_DefeatInfo = MMOMapDataDefeatInfoWraperV1();

	}
	//赋值构造函数
	MMOMapDataInfoWraperV1(const MMOMapDataInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MMOMapDataInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MMOMapDataInfoV1 ToPB() const
	{
		MMOMapDataInfoV1 v;
		*v.mutable_baseinfo()= m_BaseInfo.ToPB();
		v.mutable_spawnarr()->Reserve(m_SpawnArr.size());
		for (int i=0; i<(int)m_SpawnArr.size(); i++)
		{
			*v.add_spawnarr() = m_SpawnArr[i].ToPB();
		}
		v.mutable_portalarr()->Reserve(m_PortalArr.size());
		for (int i=0; i<(int)m_PortalArr.size(); i++)
		{
			*v.add_portalarr() = m_PortalArr[i].ToPB();
		}
		*v.mutable_defeatinfo()= m_DefeatInfo.ToPB();
		v.mutable_nodearr()->Reserve(m_NodeArr.size());
		for (int i=0; i<(int)m_NodeArr.size(); i++)
		{
			*v.add_nodearr() = m_NodeArr[i].ToPB();
		}
		v.mutable_pointarr()->Reserve(m_PointArr.size());
		for (int i=0; i<(int)m_PointArr.size(); i++)
		{
			*v.add_pointarr() = m_PointArr[i].ToPB();
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
		MMOMapDataInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>BaseInfo(基础信息) [BaseData]</li>\r\n";
		htmlBuff += "<li>SpawnArr(出生点信息) [SpawnInfo] Array</li>\r\n";
		htmlBuff += "<li>PortalArr(传送信息) [PortalInfo] Array</li>\r\n";
		htmlBuff += "<li>DefeatInfo(失败条件) [DefeatInfo]</li>\r\n";
		htmlBuff += "<li>NodeArr(节点信息) [NodeInfo] Array</li>\r\n";
		htmlBuff += "<li>PointArr(坑点信息) [PointInfo] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>BaseInfo：</li>\r\n";
		htmlBuff += m_BaseInfo.HtmlDescHeader();
		htmlBuff += m_BaseInfo.ToHtml();
		htmlBuff += "<li>SpawnArr：</li>\r\n";
		if( m_SpawnArr.size()>0) htmlBuff += m_SpawnArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_SpawnArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_SpawnArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>PortalArr：</li>\r\n";
		if( m_PortalArr.size()>0) htmlBuff += m_PortalArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_PortalArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_PortalArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>DefeatInfo：</li>\r\n";
		htmlBuff += m_DefeatInfo.HtmlDescHeader();
		htmlBuff += m_DefeatInfo.ToHtml();
		htmlBuff += "<li>NodeArr：</li>\r\n";
		if( m_NodeArr.size()>0) htmlBuff += m_NodeArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_NodeArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_NodeArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>PointArr：</li>\r\n";
		if( m_PointArr.size()>0) htmlBuff += m_PointArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_PointArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_PointArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MMOMapDataInfoV1& v)
	{
		m_BaseInfo = v.baseinfo();
		m_SpawnArr.clear();
		m_SpawnArr.reserve(v.spawnarr_size());
		for( int i=0; i<v.spawnarr_size(); i++)
			m_SpawnArr.push_back(v.spawnarr(i));
		m_PortalArr.clear();
		m_PortalArr.reserve(v.portalarr_size());
		for( int i=0; i<v.portalarr_size(); i++)
			m_PortalArr.push_back(v.portalarr(i));
		m_DefeatInfo = v.defeatinfo();
		m_NodeArr.clear();
		m_NodeArr.reserve(v.nodearr_size());
		for( int i=0; i<v.nodearr_size(); i++)
			m_NodeArr.push_back(v.nodearr(i));
		m_PointArr.clear();
		m_PointArr.reserve(v.pointarr_size());
		for( int i=0; i<v.pointarr_size(); i++)
			m_PointArr.push_back(v.pointarr(i));

	}

private:
	//基础信息
	MMOMapDataBaseDataWraperV1 m_BaseInfo;
public:
	void SetBaseInfo( const MMOMapDataBaseDataWraperV1& v)
	{
		m_BaseInfo=v;
	}
	MMOMapDataBaseDataWraperV1 GetBaseInfo()
	{
		return m_BaseInfo;
	}
	MMOMapDataBaseDataWraperV1 GetBaseInfo() const
	{
		return m_BaseInfo;
	}
private:
	//出生点信息
	vector<MMOMapDataSpawnInfoWraperV1> m_SpawnArr;
public:
	int SizeSpawnArr()
	{
		return m_SpawnArr.size();
	}
	const vector<MMOMapDataSpawnInfoWraperV1>& GetSpawnArr() const
	{
		return m_SpawnArr;
	}
	MMOMapDataSpawnInfoWraperV1 GetSpawnArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_SpawnArr.size())
		{
			assert(false);
			return MMOMapDataSpawnInfoWraperV1();
		}
		return m_SpawnArr[Index];
	}
	void SetSpawnArr( const vector<MMOMapDataSpawnInfoWraperV1>& v )
	{
		m_SpawnArr=v;
	}
	void ClearSpawnArr( )
	{
		m_SpawnArr.clear();
	}
	void SetSpawnArr( int Index, const MMOMapDataSpawnInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_SpawnArr.size())
		{
			assert(false);
			return;
		}
		m_SpawnArr[Index] = v;
	}
	void AddSpawnArr( const MMOMapDataSpawnInfoWraperV1& v )
	{
		m_SpawnArr.push_back(v);
	}
private:
	//传送信息
	vector<MMOMapDataPortalInfoWraperV1> m_PortalArr;
public:
	int SizePortalArr()
	{
		return m_PortalArr.size();
	}
	const vector<MMOMapDataPortalInfoWraperV1>& GetPortalArr() const
	{
		return m_PortalArr;
	}
	MMOMapDataPortalInfoWraperV1 GetPortalArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_PortalArr.size())
		{
			assert(false);
			return MMOMapDataPortalInfoWraperV1();
		}
		return m_PortalArr[Index];
	}
	void SetPortalArr( const vector<MMOMapDataPortalInfoWraperV1>& v )
	{
		m_PortalArr=v;
	}
	void ClearPortalArr( )
	{
		m_PortalArr.clear();
	}
	void SetPortalArr( int Index, const MMOMapDataPortalInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_PortalArr.size())
		{
			assert(false);
			return;
		}
		m_PortalArr[Index] = v;
	}
	void AddPortalArr( const MMOMapDataPortalInfoWraperV1& v )
	{
		m_PortalArr.push_back(v);
	}
private:
	//失败条件
	MMOMapDataDefeatInfoWraperV1 m_DefeatInfo;
public:
	void SetDefeatInfo( const MMOMapDataDefeatInfoWraperV1& v)
	{
		m_DefeatInfo=v;
	}
	MMOMapDataDefeatInfoWraperV1 GetDefeatInfo()
	{
		return m_DefeatInfo;
	}
	MMOMapDataDefeatInfoWraperV1 GetDefeatInfo() const
	{
		return m_DefeatInfo;
	}
private:
	//节点信息
	vector<MMOMapDataNodeInfoWraperV1> m_NodeArr;
public:
	int SizeNodeArr()
	{
		return m_NodeArr.size();
	}
	const vector<MMOMapDataNodeInfoWraperV1>& GetNodeArr() const
	{
		return m_NodeArr;
	}
	MMOMapDataNodeInfoWraperV1 GetNodeArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_NodeArr.size())
		{
			assert(false);
			return MMOMapDataNodeInfoWraperV1();
		}
		return m_NodeArr[Index];
	}
	void SetNodeArr( const vector<MMOMapDataNodeInfoWraperV1>& v )
	{
		m_NodeArr=v;
	}
	void ClearNodeArr( )
	{
		m_NodeArr.clear();
	}
	void SetNodeArr( int Index, const MMOMapDataNodeInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_NodeArr.size())
		{
			assert(false);
			return;
		}
		m_NodeArr[Index] = v;
	}
	void AddNodeArr( const MMOMapDataNodeInfoWraperV1& v )
	{
		m_NodeArr.push_back(v);
	}
private:
	//坑点信息
	vector<MMOMapDataPointInfoWraperV1> m_PointArr;
public:
	int SizePointArr()
	{
		return m_PointArr.size();
	}
	const vector<MMOMapDataPointInfoWraperV1>& GetPointArr() const
	{
		return m_PointArr;
	}
	MMOMapDataPointInfoWraperV1 GetPointArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_PointArr.size())
		{
			assert(false);
			return MMOMapDataPointInfoWraperV1();
		}
		return m_PointArr[Index];
	}
	void SetPointArr( const vector<MMOMapDataPointInfoWraperV1>& v )
	{
		m_PointArr=v;
	}
	void ClearPointArr( )
	{
		m_PointArr.clear();
	}
	void SetPointArr( int Index, const MMOMapDataPointInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_PointArr.size())
		{
			assert(false);
			return;
		}
		m_PointArr[Index] = v;
	}
	void AddPointArr( const MMOMapDataPointInfoWraperV1& v )
	{
		m_PointArr.push_back(v);
	}

};
//无用封装类
class MMOMapDataUselessWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<MMOMapDataUselessWraperV1>
{
public:
	//构造函数
	MMOMapDataUselessWraperV1()
	{
		SetDataWraper( this );


	}
	//赋值构造函数
	MMOMapDataUselessWraperV1(const MMOMapDataUselessV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MMOMapDataUselessV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MMOMapDataUselessV1 ToPB() const
	{
		MMOMapDataUselessV1 v;

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
		MMOMapDataUselessV1 pb;
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
	void Init(const MMOMapDataUselessV1& v)
	{

	}


};

#endif
