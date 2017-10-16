/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperMapData.h
* Author:       甘业清
* Description:  场景数据同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_MAPDATA_H
#define __SYNC_WRAPER_MAPDATA_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "MapDataV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//等高线信息封装类
class MapDataContourLineInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataContourLineInfoWraperV1()
	{
		
		m_Y = -1;

	}
	//赋值构造函数
	MapDataContourLineInfoWraperV1(const MapDataContourLineInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataContourLineInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataContourLineInfoV1 ToPB() const
	{
		MapDataContourLineInfoV1 v;
		v.set_y( m_Y );

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
		MapDataContourLineInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Y(Y) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Y：%.2ff</li>\r\n",m_Y);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataContourLineInfoV1& v)
	{
		m_Y = v.y();

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

};
//怪物坑点数据封装类
class MapDataNodeMonsterInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataNodeMonsterInfoWraperV1()
	{
		
		m_MonsterId = -1;
		m_RandomWeight = -1;

	}
	//赋值构造函数
	MapDataNodeMonsterInfoWraperV1(const MapDataNodeMonsterInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataNodeMonsterInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataNodeMonsterInfoV1 ToPB() const
	{
		MapDataNodeMonsterInfoV1 v;
		v.set_monsterid( m_MonsterId );
		v.set_randomweight( m_RandomWeight );

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
		MapDataNodeMonsterInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>MonsterId(怪物ID) [sint32]</li>\r\n";
		htmlBuff += "<li>RandomWeight(怪物随机权重) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>MonsterId：%di</li>\r\n",m_MonsterId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RandomWeight：%di</li>\r\n",m_RandomWeight);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataNodeMonsterInfoV1& v)
	{
		m_MonsterId = v.monsterid();
		m_RandomWeight = v.randomweight();

	}

private:
	//怪物ID
	INT32 m_MonsterId;
public:
	void SetMonsterId( INT32 v)
	{
		m_MonsterId=v;
	}
	INT32 GetMonsterId()
	{
		return m_MonsterId;
	}
	INT32 GetMonsterId() const
	{
		return m_MonsterId;
	}
private:
	//怪物随机权重
	INT32 m_RandomWeight;
public:
	void SetRandomWeight( INT32 v)
	{
		m_RandomWeight=v;
	}
	INT32 GetRandomWeight()
	{
		return m_RandomWeight;
	}
	INT32 GetRandomWeight() const
	{
		return m_RandomWeight;
	}

};
//MonsterInfo封装类
class MapDataMonsterInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataMonsterInfoWraperV1()
	{
		
		m_MonsterID = 0;
		m_X = 0;
		m_Layer = 0;
		m_RepeatCount = 1;
		m_SpawmTriggerType = 0;
		m_RespawmTriggerType = 0;
		m_PatrolX1 = -1;
		m_PatrolX2 = -1;
		m_SpawnNodeTime = 0;
		m_SpawnKillEnemyID = 0;
		m_SpawnKillEnemyCount = 0;
		m_SpawnAfterDeathTime = 0;
		m_RespawnNodeTime = 0;
		m_RespawnKillEnemyID = 0;
		m_RespawnKillEnemyCount = 0;
		m_RespawnAfterDeathTime = 0;
		m_CreateMonsterType = 0;
		m_Z = 0;
		m_Direction = 1;

	}
	//赋值构造函数
	MapDataMonsterInfoWraperV1(const MapDataMonsterInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataMonsterInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataMonsterInfoV1 ToPB() const
	{
		MapDataMonsterInfoV1 v;
		v.set_monsterid( m_MonsterID );
		v.set_x( m_X );
		v.set_layer( m_Layer );
		v.set_repeatcount( m_RepeatCount );
		v.set_spawmtriggertype( m_SpawmTriggerType );
		v.set_respawmtriggertype( m_RespawmTriggerType );
		v.set_patrolx1( m_PatrolX1 );
		v.set_patrolx2( m_PatrolX2 );
		v.set_spawnnodetime( m_SpawnNodeTime );
		v.set_spawnkillenemyid( m_SpawnKillEnemyID );
		v.set_spawnkillenemycount( m_SpawnKillEnemyCount );
		v.set_spawnafterdeathtime( m_SpawnAfterDeathTime );
		v.set_respawnnodetime( m_RespawnNodeTime );
		v.set_respawnkillenemyid( m_RespawnKillEnemyID );
		v.set_respawnkillenemycount( m_RespawnKillEnemyCount );
		v.set_respawnafterdeathtime( m_RespawnAfterDeathTime );
		v.set_createmonstertype( m_CreateMonsterType );
		v.mutable_nodemonsterinfoarr()->Reserve(m_NodeMonsterInfoArr.size());
		for (int i=0; i<(int)m_NodeMonsterInfoArr.size(); i++)
		{
			*v.add_nodemonsterinfoarr() = m_NodeMonsterInfoArr[i].ToPB();
		}
		v.set_z( m_Z );
		v.set_direction( m_Direction );

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
		MapDataMonsterInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>MonsterID(MonsterID) [sint32]</li>\r\n";
		htmlBuff += "<li>X(X) [float]</li>\r\n";
		htmlBuff += "<li>Layer(Layer) [sint32]</li>\r\n";
		htmlBuff += "<li>RepeatCount(RepeatCount) [sint32]</li>\r\n";
		htmlBuff += "<li>SpawmTriggerType(SpawmTriggerType) [sint32]</li>\r\n";
		htmlBuff += "<li>RespawmTriggerType(RespawmTriggerType) [sint32]</li>\r\n";
		htmlBuff += "<li>PatrolX1(PatrolX1) [float]</li>\r\n";
		htmlBuff += "<li>PatrolX2(PatrolX2) [float]</li>\r\n";
		htmlBuff += "<li>SpawnNodeTime(SpawnNodeTime) [float]</li>\r\n";
		htmlBuff += "<li>SpawnKillEnemyID(SpawnKillEnemyID) [sint32]</li>\r\n";
		htmlBuff += "<li>SpawnKillEnemyCount(SpawnKillEnemyCount) [sint32]</li>\r\n";
		htmlBuff += "<li>SpawnAfterDeathTime(SpawnAfterDeathTime) [float]</li>\r\n";
		htmlBuff += "<li>RespawnNodeTime(RespawnNodeTime) [float]</li>\r\n";
		htmlBuff += "<li>RespawnKillEnemyID(RespawnKillEnemyID) [sint32]</li>\r\n";
		htmlBuff += "<li>RespawnKillEnemyCount(RespawnKillEnemyCount) [sint32]</li>\r\n";
		htmlBuff += "<li>RespawnAfterDeathTime(RespawnAfterDeathTime) [float]</li>\r\n";
		htmlBuff += "<li>CreateMonsterType(出怪类型) [sint32]</li>\r\n";
		htmlBuff += "<li>NodeMonsterInfoArr(坑点中怪物节点列表) [NodeMonsterInfo] Array</li>\r\n";
		htmlBuff += "<li>Z(Z轴) [float]</li>\r\n";
		htmlBuff += "<li>Direction(朝向) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>MonsterID：%di</li>\r\n",m_MonsterID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Layer：%di</li>\r\n",m_Layer);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RepeatCount：%di</li>\r\n",m_RepeatCount);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SpawmTriggerType：%di</li>\r\n",m_SpawmTriggerType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RespawmTriggerType：%di</li>\r\n",m_RespawmTriggerType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PatrolX1：%.2ff</li>\r\n",m_PatrolX1);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PatrolX2：%.2ff</li>\r\n",m_PatrolX2);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SpawnNodeTime：%.2ff</li>\r\n",m_SpawnNodeTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SpawnKillEnemyID：%di</li>\r\n",m_SpawnKillEnemyID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SpawnKillEnemyCount：%di</li>\r\n",m_SpawnKillEnemyCount);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SpawnAfterDeathTime：%.2ff</li>\r\n",m_SpawnAfterDeathTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RespawnNodeTime：%.2ff</li>\r\n",m_RespawnNodeTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RespawnKillEnemyID：%di</li>\r\n",m_RespawnKillEnemyID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RespawnKillEnemyCount：%di</li>\r\n",m_RespawnKillEnemyCount);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RespawnAfterDeathTime：%.2ff</li>\r\n",m_RespawnAfterDeathTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CreateMonsterType：%di</li>\r\n",m_CreateMonsterType);
		htmlBuff += tmpLine;
		htmlBuff += "<li>NodeMonsterInfoArr：</li>\r\n";
		if( m_NodeMonsterInfoArr.size()>0) htmlBuff += m_NodeMonsterInfoArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_NodeMonsterInfoArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_NodeMonsterInfoArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>Z：%.2ff</li>\r\n",m_Z);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Direction：%di</li>\r\n",m_Direction);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataMonsterInfoV1& v)
	{
		m_MonsterID = v.monsterid();
		m_X = v.x();
		m_Layer = v.layer();
		m_RepeatCount = v.repeatcount();
		m_SpawmTriggerType = v.spawmtriggertype();
		m_RespawmTriggerType = v.respawmtriggertype();
		m_PatrolX1 = v.patrolx1();
		m_PatrolX2 = v.patrolx2();
		m_SpawnNodeTime = v.spawnnodetime();
		m_SpawnKillEnemyID = v.spawnkillenemyid();
		m_SpawnKillEnemyCount = v.spawnkillenemycount();
		m_SpawnAfterDeathTime = v.spawnafterdeathtime();
		m_RespawnNodeTime = v.respawnnodetime();
		m_RespawnKillEnemyID = v.respawnkillenemyid();
		m_RespawnKillEnemyCount = v.respawnkillenemycount();
		m_RespawnAfterDeathTime = v.respawnafterdeathtime();
		m_CreateMonsterType = v.createmonstertype();
		m_NodeMonsterInfoArr.clear();
		m_NodeMonsterInfoArr.reserve(v.nodemonsterinfoarr_size());
		for( int i=0; i<v.nodemonsterinfoarr_size(); i++)
			m_NodeMonsterInfoArr.push_back(v.nodemonsterinfoarr(i));
		m_Z = v.z();
		m_Direction = v.direction();

	}

private:
	//MonsterID
	INT32 m_MonsterID;
public:
	void SetMonsterID( INT32 v)
	{
		m_MonsterID=v;
	}
	INT32 GetMonsterID()
	{
		return m_MonsterID;
	}
	INT32 GetMonsterID() const
	{
		return m_MonsterID;
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
	//Layer
	INT32 m_Layer;
public:
	void SetLayer( INT32 v)
	{
		m_Layer=v;
	}
	INT32 GetLayer()
	{
		return m_Layer;
	}
	INT32 GetLayer() const
	{
		return m_Layer;
	}
private:
	//RepeatCount
	INT32 m_RepeatCount;
public:
	void SetRepeatCount( INT32 v)
	{
		m_RepeatCount=v;
	}
	INT32 GetRepeatCount()
	{
		return m_RepeatCount;
	}
	INT32 GetRepeatCount() const
	{
		return m_RepeatCount;
	}
private:
	//SpawmTriggerType
	INT32 m_SpawmTriggerType;
public:
	void SetSpawmTriggerType( INT32 v)
	{
		m_SpawmTriggerType=v;
	}
	INT32 GetSpawmTriggerType()
	{
		return m_SpawmTriggerType;
	}
	INT32 GetSpawmTriggerType() const
	{
		return m_SpawmTriggerType;
	}
private:
	//RespawmTriggerType
	INT32 m_RespawmTriggerType;
public:
	void SetRespawmTriggerType( INT32 v)
	{
		m_RespawmTriggerType=v;
	}
	INT32 GetRespawmTriggerType()
	{
		return m_RespawmTriggerType;
	}
	INT32 GetRespawmTriggerType() const
	{
		return m_RespawmTriggerType;
	}
private:
	//PatrolX1
	float m_PatrolX1;
public:
	void SetPatrolX1( float v)
	{
		m_PatrolX1=v;
	}
	float GetPatrolX1()
	{
		return m_PatrolX1;
	}
	float GetPatrolX1() const
	{
		return m_PatrolX1;
	}
private:
	//PatrolX2
	float m_PatrolX2;
public:
	void SetPatrolX2( float v)
	{
		m_PatrolX2=v;
	}
	float GetPatrolX2()
	{
		return m_PatrolX2;
	}
	float GetPatrolX2() const
	{
		return m_PatrolX2;
	}
private:
	//SpawnNodeTime
	float m_SpawnNodeTime;
public:
	void SetSpawnNodeTime( float v)
	{
		m_SpawnNodeTime=v;
	}
	float GetSpawnNodeTime()
	{
		return m_SpawnNodeTime;
	}
	float GetSpawnNodeTime() const
	{
		return m_SpawnNodeTime;
	}
private:
	//SpawnKillEnemyID
	INT32 m_SpawnKillEnemyID;
public:
	void SetSpawnKillEnemyID( INT32 v)
	{
		m_SpawnKillEnemyID=v;
	}
	INT32 GetSpawnKillEnemyID()
	{
		return m_SpawnKillEnemyID;
	}
	INT32 GetSpawnKillEnemyID() const
	{
		return m_SpawnKillEnemyID;
	}
private:
	//SpawnKillEnemyCount
	INT32 m_SpawnKillEnemyCount;
public:
	void SetSpawnKillEnemyCount( INT32 v)
	{
		m_SpawnKillEnemyCount=v;
	}
	INT32 GetSpawnKillEnemyCount()
	{
		return m_SpawnKillEnemyCount;
	}
	INT32 GetSpawnKillEnemyCount() const
	{
		return m_SpawnKillEnemyCount;
	}
private:
	//SpawnAfterDeathTime
	float m_SpawnAfterDeathTime;
public:
	void SetSpawnAfterDeathTime( float v)
	{
		m_SpawnAfterDeathTime=v;
	}
	float GetSpawnAfterDeathTime()
	{
		return m_SpawnAfterDeathTime;
	}
	float GetSpawnAfterDeathTime() const
	{
		return m_SpawnAfterDeathTime;
	}
private:
	//RespawnNodeTime
	float m_RespawnNodeTime;
public:
	void SetRespawnNodeTime( float v)
	{
		m_RespawnNodeTime=v;
	}
	float GetRespawnNodeTime()
	{
		return m_RespawnNodeTime;
	}
	float GetRespawnNodeTime() const
	{
		return m_RespawnNodeTime;
	}
private:
	//RespawnKillEnemyID
	INT32 m_RespawnKillEnemyID;
public:
	void SetRespawnKillEnemyID( INT32 v)
	{
		m_RespawnKillEnemyID=v;
	}
	INT32 GetRespawnKillEnemyID()
	{
		return m_RespawnKillEnemyID;
	}
	INT32 GetRespawnKillEnemyID() const
	{
		return m_RespawnKillEnemyID;
	}
private:
	//RespawnKillEnemyCount
	INT32 m_RespawnKillEnemyCount;
public:
	void SetRespawnKillEnemyCount( INT32 v)
	{
		m_RespawnKillEnemyCount=v;
	}
	INT32 GetRespawnKillEnemyCount()
	{
		return m_RespawnKillEnemyCount;
	}
	INT32 GetRespawnKillEnemyCount() const
	{
		return m_RespawnKillEnemyCount;
	}
private:
	//RespawnAfterDeathTime
	float m_RespawnAfterDeathTime;
public:
	void SetRespawnAfterDeathTime( float v)
	{
		m_RespawnAfterDeathTime=v;
	}
	float GetRespawnAfterDeathTime()
	{
		return m_RespawnAfterDeathTime;
	}
	float GetRespawnAfterDeathTime() const
	{
		return m_RespawnAfterDeathTime;
	}
private:
	//出怪类型
	INT32 m_CreateMonsterType;
public:
	void SetCreateMonsterType( INT32 v)
	{
		m_CreateMonsterType=v;
	}
	INT32 GetCreateMonsterType()
	{
		return m_CreateMonsterType;
	}
	INT32 GetCreateMonsterType() const
	{
		return m_CreateMonsterType;
	}
private:
	//坑点中怪物节点列表
	vector<MapDataNodeMonsterInfoWraperV1> m_NodeMonsterInfoArr;
public:
	int SizeNodeMonsterInfoArr()
	{
		return m_NodeMonsterInfoArr.size();
	}
	const vector<MapDataNodeMonsterInfoWraperV1>& GetNodeMonsterInfoArr() const
	{
		return m_NodeMonsterInfoArr;
	}
	MapDataNodeMonsterInfoWraperV1 GetNodeMonsterInfoArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_NodeMonsterInfoArr.size())
		{
			assert(false);
			return MapDataNodeMonsterInfoWraperV1();
		}
		return m_NodeMonsterInfoArr[Index];
	}
	void SetNodeMonsterInfoArr( const vector<MapDataNodeMonsterInfoWraperV1>& v )
	{
		m_NodeMonsterInfoArr=v;
	}
	void ClearNodeMonsterInfoArr( )
	{
		m_NodeMonsterInfoArr.clear();
	}
	void SetNodeMonsterInfoArr( int Index, const MapDataNodeMonsterInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_NodeMonsterInfoArr.size())
		{
			assert(false);
			return;
		}
		m_NodeMonsterInfoArr[Index] = v;
	}
	void AddNodeMonsterInfoArr( const MapDataNodeMonsterInfoWraperV1& v )
	{
		m_NodeMonsterInfoArr.push_back(v);
	}
private:
	//Z轴
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
private:
	//朝向
	INT32 m_Direction;
public:
	void SetDirection( INT32 v)
	{
		m_Direction=v;
	}
	INT32 GetDirection()
	{
		return m_Direction;
	}
	INT32 GetDirection() const
	{
		return m_Direction;
	}

};
//Vector2封装类
class MapDataVector2WraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataVector2WraperV1()
	{
		
		m_X1 = 0;
		m_X2 = 0;
		m_Z1 = 0;
		m_Z2 = 0;
		m_OrgAngle = 0;
		m_FinAngle = 0;
		m_Radius = 0;

	}
	//赋值构造函数
	MapDataVector2WraperV1(const MapDataVector2V1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataVector2V1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataVector2V1 ToPB() const
	{
		MapDataVector2V1 v;
		v.set_x1( m_X1 );
		v.set_x2( m_X2 );
		v.set_z1( m_Z1 );
		v.set_z2( m_Z2 );
		v.set_organgle( m_OrgAngle );
		v.set_finangle( m_FinAngle );
		v.set_radius( m_Radius );
		v.mutable_contourlinearr()->Reserve(m_ContourLineArr.size());
		for (int i=0; i<(int)m_ContourLineArr.size(); i++)
		{
			*v.add_contourlinearr() = m_ContourLineArr[i].ToPB();
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
		MapDataVector2V1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>X1(X1) [float]</li>\r\n";
		htmlBuff += "<li>X2(X2) [float]</li>\r\n";
		htmlBuff += "<li>Z1(Z1) [float]</li>\r\n";
		htmlBuff += "<li>Z2(Z2) [float]</li>\r\n";
		htmlBuff += "<li>OrgAngle(起始角度) [float]</li>\r\n";
		htmlBuff += "<li>FinAngle(终点角度) [float]</li>\r\n";
		htmlBuff += "<li>Radius(半径) [float]</li>\r\n";
		htmlBuff += "<li>ContourLineArr(等高线信息) [ContourLineInfo] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>X1：%.2ff</li>\r\n",m_X1);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>X2：%.2ff</li>\r\n",m_X2);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Z1：%.2ff</li>\r\n",m_Z1);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Z2：%.2ff</li>\r\n",m_Z2);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>OrgAngle：%.2ff</li>\r\n",m_OrgAngle);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>FinAngle：%.2ff</li>\r\n",m_FinAngle);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Radius：%.2ff</li>\r\n",m_Radius);
		htmlBuff += tmpLine;
		htmlBuff += "<li>ContourLineArr：</li>\r\n";
		if( m_ContourLineArr.size()>0) htmlBuff += m_ContourLineArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ContourLineArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ContourLineArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataVector2V1& v)
	{
		m_X1 = v.x1();
		m_X2 = v.x2();
		m_Z1 = v.z1();
		m_Z2 = v.z2();
		m_OrgAngle = v.organgle();
		m_FinAngle = v.finangle();
		m_Radius = v.radius();
		m_ContourLineArr.clear();
		m_ContourLineArr.reserve(v.contourlinearr_size());
		for( int i=0; i<v.contourlinearr_size(); i++)
			m_ContourLineArr.push_back(v.contourlinearr(i));

	}

private:
	//X1
	float m_X1;
public:
	void SetX1( float v)
	{
		m_X1=v;
	}
	float GetX1()
	{
		return m_X1;
	}
	float GetX1() const
	{
		return m_X1;
	}
private:
	//X2
	float m_X2;
public:
	void SetX2( float v)
	{
		m_X2=v;
	}
	float GetX2()
	{
		return m_X2;
	}
	float GetX2() const
	{
		return m_X2;
	}
private:
	//Z1
	float m_Z1;
public:
	void SetZ1( float v)
	{
		m_Z1=v;
	}
	float GetZ1()
	{
		return m_Z1;
	}
	float GetZ1() const
	{
		return m_Z1;
	}
private:
	//Z2
	float m_Z2;
public:
	void SetZ2( float v)
	{
		m_Z2=v;
	}
	float GetZ2()
	{
		return m_Z2;
	}
	float GetZ2() const
	{
		return m_Z2;
	}
private:
	//起始角度
	float m_OrgAngle;
public:
	void SetOrgAngle( float v)
	{
		m_OrgAngle=v;
	}
	float GetOrgAngle()
	{
		return m_OrgAngle;
	}
	float GetOrgAngle() const
	{
		return m_OrgAngle;
	}
private:
	//终点角度
	float m_FinAngle;
public:
	void SetFinAngle( float v)
	{
		m_FinAngle=v;
	}
	float GetFinAngle()
	{
		return m_FinAngle;
	}
	float GetFinAngle() const
	{
		return m_FinAngle;
	}
private:
	//半径
	float m_Radius;
public:
	void SetRadius( float v)
	{
		m_Radius=v;
	}
	float GetRadius()
	{
		return m_Radius;
	}
	float GetRadius() const
	{
		return m_Radius;
	}
private:
	//等高线信息
	vector<MapDataContourLineInfoWraperV1> m_ContourLineArr;
public:
	int SizeContourLineArr()
	{
		return m_ContourLineArr.size();
	}
	const vector<MapDataContourLineInfoWraperV1>& GetContourLineArr() const
	{
		return m_ContourLineArr;
	}
	MapDataContourLineInfoWraperV1 GetContourLineArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_ContourLineArr.size())
		{
			assert(false);
			return MapDataContourLineInfoWraperV1();
		}
		return m_ContourLineArr[Index];
	}
	void SetContourLineArr( const vector<MapDataContourLineInfoWraperV1>& v )
	{
		m_ContourLineArr=v;
	}
	void ClearContourLineArr( )
	{
		m_ContourLineArr.clear();
	}
	void SetContourLineArr( int Index, const MapDataContourLineInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_ContourLineArr.size())
		{
			assert(false);
			return;
		}
		m_ContourLineArr[Index] = v;
	}
	void AddContourLineArr( const MapDataContourLineInfoWraperV1& v )
	{
		m_ContourLineArr.push_back(v);
	}

};
//事件信息封装类
class MapDataEventInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataEventInfoWraperV1()
	{
		
		m_X1 = 0;
		m_Z1 = 0;
		m_X2 = 0;
		m_Z2 = 0;
		m_Type = 0;
		m_EventId = 0;
		m_Layer = 0;

	}
	//赋值构造函数
	MapDataEventInfoWraperV1(const MapDataEventInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataEventInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataEventInfoV1 ToPB() const
	{
		MapDataEventInfoV1 v;
		v.set_x1( m_X1 );
		v.set_z1( m_Z1 );
		v.set_x2( m_X2 );
		v.set_z2( m_Z2 );
		v.set_type( m_Type );
		v.set_eventid( m_EventId );
		v.set_layer( m_Layer );

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
		MapDataEventInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>X1(X1坐标) [float]</li>\r\n";
		htmlBuff += "<li>Z1(Z1坐标) [float]</li>\r\n";
		htmlBuff += "<li>X2(X2坐标) [float]</li>\r\n";
		htmlBuff += "<li>Z2(Z2坐标) [float]</li>\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>EventId(事件Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Layer(层信息) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>X1：%.2ff</li>\r\n",m_X1);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Z1：%.2ff</li>\r\n",m_Z1);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>X2：%.2ff</li>\r\n",m_X2);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Z2：%.2ff</li>\r\n",m_Z2);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EventId：%di</li>\r\n",m_EventId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Layer：%di</li>\r\n",m_Layer);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataEventInfoV1& v)
	{
		m_X1 = v.x1();
		m_Z1 = v.z1();
		m_X2 = v.x2();
		m_Z2 = v.z2();
		m_Type = v.type();
		m_EventId = v.eventid();
		m_Layer = v.layer();

	}

private:
	//X1坐标
	float m_X1;
public:
	void SetX1( float v)
	{
		m_X1=v;
	}
	float GetX1()
	{
		return m_X1;
	}
	float GetX1() const
	{
		return m_X1;
	}
private:
	//Z1坐标
	float m_Z1;
public:
	void SetZ1( float v)
	{
		m_Z1=v;
	}
	float GetZ1()
	{
		return m_Z1;
	}
	float GetZ1() const
	{
		return m_Z1;
	}
private:
	//X2坐标
	float m_X2;
public:
	void SetX2( float v)
	{
		m_X2=v;
	}
	float GetX2()
	{
		return m_X2;
	}
	float GetX2() const
	{
		return m_X2;
	}
private:
	//Z2坐标
	float m_Z2;
public:
	void SetZ2( float v)
	{
		m_Z2=v;
	}
	float GetZ2()
	{
		return m_Z2;
	}
	float GetZ2() const
	{
		return m_Z2;
	}
private:
	//类型
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}
private:
	//事件Id
	INT32 m_EventId;
public:
	void SetEventId( INT32 v)
	{
		m_EventId=v;
	}
	INT32 GetEventId()
	{
		return m_EventId;
	}
	INT32 GetEventId() const
	{
		return m_EventId;
	}
private:
	//层信息
	INT32 m_Layer;
public:
	void SetLayer( INT32 v)
	{
		m_Layer=v;
	}
	INT32 GetLayer()
	{
		return m_Layer;
	}
	INT32 GetLayer() const
	{
		return m_Layer;
	}

};
//NodeInfo封装类
class MapDataNodeInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataNodeInfoWraperV1()
	{
		
		m_X = 0;
		m_Layer = 0;
		m_PassCondition = 0;
		m_KillEnemyID = 0;
		m_KillEnemyCount = 0;
		m_TimeLimit = 0;
		m_NodeType = 0;
		m_NodeArrowDisplayType = 0;

	}
	//赋值构造函数
	MapDataNodeInfoWraperV1(const MapDataNodeInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataNodeInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataNodeInfoV1 ToPB() const
	{
		MapDataNodeInfoV1 v;
		v.set_x( m_X );
		v.set_layer( m_Layer );
		v.set_passcondition( m_PassCondition );
		v.set_killenemyid( m_KillEnemyID );
		v.set_killenemycount( m_KillEnemyCount );
		v.mutable_monsterarr()->Reserve(m_MonsterArr.size());
		for (int i=0; i<(int)m_MonsterArr.size(); i++)
		{
			*v.add_monsterarr() = m_MonsterArr[i].ToPB();
		}
		v.set_timelimit( m_TimeLimit );
		v.set_nodetype( m_NodeType );
		v.set_nodearrowdisplaytype( m_NodeArrowDisplayType );

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
		MapDataNodeInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>X(X) [float]</li>\r\n";
		htmlBuff += "<li>Layer(Layer) [sint32]</li>\r\n";
		htmlBuff += "<li>PassCondition(PassCondition) [sint32]</li>\r\n";
		htmlBuff += "<li>KillEnemyID(KillEnemyID) [sint32]</li>\r\n";
		htmlBuff += "<li>KillEnemyCount(KillEnemyCount) [sint32]</li>\r\n";
		htmlBuff += "<li>MonsterArr(MonsterArr) [MonsterInfo] Array</li>\r\n";
		htmlBuff += "<li>TimeLimit(TimeLimit) [float]</li>\r\n";
		htmlBuff += "<li>NodeType(NodeType) [sint32]</li>\r\n";
		htmlBuff += "<li>NodeArrowDisplayType(节点箭头显示模式) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Layer：%di</li>\r\n",m_Layer);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PassCondition：%di</li>\r\n",m_PassCondition);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>KillEnemyID：%di</li>\r\n",m_KillEnemyID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>KillEnemyCount：%di</li>\r\n",m_KillEnemyCount);
		htmlBuff += tmpLine;
		htmlBuff += "<li>MonsterArr：</li>\r\n";
		if( m_MonsterArr.size()>0) htmlBuff += m_MonsterArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_MonsterArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_MonsterArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>TimeLimit：%.2ff</li>\r\n",m_TimeLimit);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>NodeType：%di</li>\r\n",m_NodeType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>NodeArrowDisplayType：%di</li>\r\n",m_NodeArrowDisplayType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataNodeInfoV1& v)
	{
		m_X = v.x();
		m_Layer = v.layer();
		m_PassCondition = v.passcondition();
		m_KillEnemyID = v.killenemyid();
		m_KillEnemyCount = v.killenemycount();
		m_MonsterArr.clear();
		m_MonsterArr.reserve(v.monsterarr_size());
		for( int i=0; i<v.monsterarr_size(); i++)
			m_MonsterArr.push_back(v.monsterarr(i));
		m_TimeLimit = v.timelimit();
		m_NodeType = v.nodetype();
		m_NodeArrowDisplayType = v.nodearrowdisplaytype();

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
	//Layer
	INT32 m_Layer;
public:
	void SetLayer( INT32 v)
	{
		m_Layer=v;
	}
	INT32 GetLayer()
	{
		return m_Layer;
	}
	INT32 GetLayer() const
	{
		return m_Layer;
	}
private:
	//PassCondition
	INT32 m_PassCondition;
public:
	void SetPassCondition( INT32 v)
	{
		m_PassCondition=v;
	}
	INT32 GetPassCondition()
	{
		return m_PassCondition;
	}
	INT32 GetPassCondition() const
	{
		return m_PassCondition;
	}
private:
	//KillEnemyID
	INT32 m_KillEnemyID;
public:
	void SetKillEnemyID( INT32 v)
	{
		m_KillEnemyID=v;
	}
	INT32 GetKillEnemyID()
	{
		return m_KillEnemyID;
	}
	INT32 GetKillEnemyID() const
	{
		return m_KillEnemyID;
	}
private:
	//KillEnemyCount
	INT32 m_KillEnemyCount;
public:
	void SetKillEnemyCount( INT32 v)
	{
		m_KillEnemyCount=v;
	}
	INT32 GetKillEnemyCount()
	{
		return m_KillEnemyCount;
	}
	INT32 GetKillEnemyCount() const
	{
		return m_KillEnemyCount;
	}
private:
	//MonsterArr
	vector<MapDataMonsterInfoWraperV1> m_MonsterArr;
public:
	int SizeMonsterArr()
	{
		return m_MonsterArr.size();
	}
	const vector<MapDataMonsterInfoWraperV1>& GetMonsterArr() const
	{
		return m_MonsterArr;
	}
	MapDataMonsterInfoWraperV1 GetMonsterArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_MonsterArr.size())
		{
			assert(false);
			return MapDataMonsterInfoWraperV1();
		}
		return m_MonsterArr[Index];
	}
	void SetMonsterArr( const vector<MapDataMonsterInfoWraperV1>& v )
	{
		m_MonsterArr=v;
	}
	void ClearMonsterArr( )
	{
		m_MonsterArr.clear();
	}
	void SetMonsterArr( int Index, const MapDataMonsterInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_MonsterArr.size())
		{
			assert(false);
			return;
		}
		m_MonsterArr[Index] = v;
	}
	void AddMonsterArr( const MapDataMonsterInfoWraperV1& v )
	{
		m_MonsterArr.push_back(v);
	}
private:
	//TimeLimit
	float m_TimeLimit;
public:
	void SetTimeLimit( float v)
	{
		m_TimeLimit=v;
	}
	float GetTimeLimit()
	{
		return m_TimeLimit;
	}
	float GetTimeLimit() const
	{
		return m_TimeLimit;
	}
private:
	//NodeType
	INT32 m_NodeType;
public:
	void SetNodeType( INT32 v)
	{
		m_NodeType=v;
	}
	INT32 GetNodeType()
	{
		return m_NodeType;
	}
	INT32 GetNodeType() const
	{
		return m_NodeType;
	}
private:
	//节点箭头显示模式
	INT32 m_NodeArrowDisplayType;
public:
	void SetNodeArrowDisplayType( INT32 v)
	{
		m_NodeArrowDisplayType=v;
	}
	INT32 GetNodeArrowDisplayType()
	{
		return m_NodeArrowDisplayType;
	}
	INT32 GetNodeArrowDisplayType() const
	{
		return m_NodeArrowDisplayType;
	}

};
//领地封装类
class MapDataTerritorialInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataTerritorialInfoWraperV1()
	{
		
		m_Layer = 0;
		m_Area = MapDataVector2WraperV1();
		m_X = 0;
		m_ID = 0;
		m_ModelName = "";

	}
	//赋值构造函数
	MapDataTerritorialInfoWraperV1(const MapDataTerritorialInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataTerritorialInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataTerritorialInfoV1 ToPB() const
	{
		MapDataTerritorialInfoV1 v;
		v.set_layer( m_Layer );
		*v.mutable_area()= m_Area.ToPB();
		v.set_x( m_X );
		v.set_id( m_ID );
		v.set_modelname( m_ModelName );

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
		MapDataTerritorialInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Layer(层) [sint32]</li>\r\n";
		htmlBuff += "<li>Area(区域) [Vector2]</li>\r\n";
		htmlBuff += "<li>X(X) [float]</li>\r\n";
		htmlBuff += "<li>ID(ID) [sint32]</li>\r\n";
		htmlBuff += "<li>ModelName(ModelName) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Layer：%di</li>\r\n",m_Layer);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Area：</li>\r\n";
		htmlBuff += m_Area.HtmlDescHeader();
		htmlBuff += m_Area.ToHtml();
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ID：%di</li>\r\n",m_ID);
		htmlBuff += tmpLine;
		htmlBuff += "<li>ModelName：\""+m_ModelName+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataTerritorialInfoV1& v)
	{
		m_Layer = v.layer();
		m_Area = v.area();
		m_X = v.x();
		m_ID = v.id();
		m_ModelName = v.modelname();

	}

private:
	//层
	INT32 m_Layer;
public:
	void SetLayer( INT32 v)
	{
		m_Layer=v;
	}
	INT32 GetLayer()
	{
		return m_Layer;
	}
	INT32 GetLayer() const
	{
		return m_Layer;
	}
private:
	//区域
	MapDataVector2WraperV1 m_Area;
public:
	void SetArea( const MapDataVector2WraperV1& v)
	{
		m_Area=v;
	}
	MapDataVector2WraperV1 GetArea()
	{
		return m_Area;
	}
	MapDataVector2WraperV1 GetArea() const
	{
		return m_Area;
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
	//ID
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}
private:
	//ModelName
	string m_ModelName;
public:
	void SetModelName( const string& v)
	{
		m_ModelName=v;
	}
	string GetModelName()
	{
		return m_ModelName;
	}
	string GetModelName() const
	{
		return m_ModelName;
	}

};
//采集物封装类
class MapDataGatherInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataGatherInfoWraperV1()
	{
		
		m_GatherId = 0;
		m_X = 0;
		m_Layer = 0;
		m_Z = 0;
		m_Direction = 1;

	}
	//赋值构造函数
	MapDataGatherInfoWraperV1(const MapDataGatherInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataGatherInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataGatherInfoV1 ToPB() const
	{
		MapDataGatherInfoV1 v;
		v.set_gatherid( m_GatherId );
		v.set_x( m_X );
		v.set_layer( m_Layer );
		v.set_z( m_Z );
		v.set_direction( m_Direction );

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
		MapDataGatherInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GatherId(采集物ID) [sint32]</li>\r\n";
		htmlBuff += "<li>X(X) [float]</li>\r\n";
		htmlBuff += "<li>Layer(层) [sint32]</li>\r\n";
		htmlBuff += "<li>Z(Z) [float]</li>\r\n";
		htmlBuff += "<li>Direction(朝向) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>GatherId：%di</li>\r\n",m_GatherId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Layer：%di</li>\r\n",m_Layer);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Z：%.2ff</li>\r\n",m_Z);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Direction：%di</li>\r\n",m_Direction);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataGatherInfoV1& v)
	{
		m_GatherId = v.gatherid();
		m_X = v.x();
		m_Layer = v.layer();
		m_Z = v.z();
		m_Direction = v.direction();

	}

private:
	//采集物ID
	INT32 m_GatherId;
public:
	void SetGatherId( INT32 v)
	{
		m_GatherId=v;
	}
	INT32 GetGatherId()
	{
		return m_GatherId;
	}
	INT32 GetGatherId() const
	{
		return m_GatherId;
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
	//层
	INT32 m_Layer;
public:
	void SetLayer( INT32 v)
	{
		m_Layer=v;
	}
	INT32 GetLayer()
	{
		return m_Layer;
	}
	INT32 GetLayer() const
	{
		return m_Layer;
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
private:
	//朝向
	INT32 m_Direction;
public:
	void SetDirection( INT32 v)
	{
		m_Direction=v;
	}
	INT32 GetDirection()
	{
		return m_Direction;
	}
	INT32 GetDirection() const
	{
		return m_Direction;
	}

};
//基础配置封装类
class MapDataBaseConfigWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataBaseConfigWraperV1()
	{
		
		m_MapType = 0;

	}
	//赋值构造函数
	MapDataBaseConfigWraperV1(const MapDataBaseConfigV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataBaseConfigV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataBaseConfigV1 ToPB() const
	{
		MapDataBaseConfigV1 v;
		v.set_maptype( m_MapType );

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
		MapDataBaseConfigV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>MapType(地图类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>MapType：%di</li>\r\n",m_MapType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataBaseConfigV1& v)
	{
		m_MapType = v.maptype();

	}

private:
	//地图类型
	INT32 m_MapType;
public:
	void SetMapType( INT32 v)
	{
		m_MapType=v;
	}
	INT32 GetMapType()
	{
		return m_MapType;
	}
	INT32 GetMapType() const
	{
		return m_MapType;
	}

};
//DefeatInfo封装类
class MapDataDefeatInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataDefeatInfoWraperV1()
	{
		
		m_Condition = 0;
		m_TimeLimit = 0;

	}
	//赋值构造函数
	MapDataDefeatInfoWraperV1(const MapDataDefeatInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataDefeatInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataDefeatInfoV1 ToPB() const
	{
		MapDataDefeatInfoV1 v;
		v.set_condition( m_Condition );
		v.set_timelimit( m_TimeLimit );

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
		MapDataDefeatInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Condition(Condition) [sint32]</li>\r\n";
		htmlBuff += "<li>TimeLimit(TimeLimit) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Condition：%di</li>\r\n",m_Condition);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TimeLimit：%.2ff</li>\r\n",m_TimeLimit);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataDefeatInfoV1& v)
	{
		m_Condition = v.condition();
		m_TimeLimit = v.timelimit();

	}

private:
	//Condition
	INT32 m_Condition;
public:
	void SetCondition( INT32 v)
	{
		m_Condition=v;
	}
	INT32 GetCondition()
	{
		return m_Condition;
	}
	INT32 GetCondition() const
	{
		return m_Condition;
	}
private:
	//TimeLimit
	float m_TimeLimit;
public:
	void SetTimeLimit( float v)
	{
		m_TimeLimit=v;
	}
	float GetTimeLimit()
	{
		return m_TimeLimit;
	}
	float GetTimeLimit() const
	{
		return m_TimeLimit;
	}

};
//SpawnInfo封装类
class MapDataSpawnInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataSpawnInfoWraperV1()
	{
		
		m_X = 0;
		m_Layer = 0;
		m_SpawnDirection = 1;
		m_Z = 0;
		m_Radius = 0;
		m_Angle = 0;

	}
	//赋值构造函数
	MapDataSpawnInfoWraperV1(const MapDataSpawnInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataSpawnInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataSpawnInfoV1 ToPB() const
	{
		MapDataSpawnInfoV1 v;
		v.set_x( m_X );
		v.set_layer( m_Layer );
		v.set_spawndirection( m_SpawnDirection );
		v.set_z( m_Z );
		v.set_radius( m_Radius );
		v.set_angle( m_Angle );

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
		MapDataSpawnInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>X(X) [float]</li>\r\n";
		htmlBuff += "<li>Layer(Layer) [sint32]</li>\r\n";
		htmlBuff += "<li>SpawnDirection(出生时的朝向) [sint32]</li>\r\n";
		htmlBuff += "<li>Z(Z轴) [float]</li>\r\n";
		htmlBuff += "<li>Radius(半径) [float]</li>\r\n";
		htmlBuff += "<li>Angle(角度) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Layer：%di</li>\r\n",m_Layer);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SpawnDirection：%di</li>\r\n",m_SpawnDirection);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Z：%.2ff</li>\r\n",m_Z);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Radius：%.2ff</li>\r\n",m_Radius);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Angle：%.2ff</li>\r\n",m_Angle);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataSpawnInfoV1& v)
	{
		m_X = v.x();
		m_Layer = v.layer();
		m_SpawnDirection = v.spawndirection();
		m_Z = v.z();
		m_Radius = v.radius();
		m_Angle = v.angle();

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
	//Layer
	INT32 m_Layer;
public:
	void SetLayer( INT32 v)
	{
		m_Layer=v;
	}
	INT32 GetLayer()
	{
		return m_Layer;
	}
	INT32 GetLayer() const
	{
		return m_Layer;
	}
private:
	//出生时的朝向
	INT32 m_SpawnDirection;
public:
	void SetSpawnDirection( INT32 v)
	{
		m_SpawnDirection=v;
	}
	INT32 GetSpawnDirection()
	{
		return m_SpawnDirection;
	}
	INT32 GetSpawnDirection() const
	{
		return m_SpawnDirection;
	}
private:
	//Z轴
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
private:
	//半径
	float m_Radius;
public:
	void SetRadius( float v)
	{
		m_Radius=v;
	}
	float GetRadius()
	{
		return m_Radius;
	}
	float GetRadius() const
	{
		return m_Radius;
	}
private:
	//角度
	float m_Angle;
public:
	void SetAngle( float v)
	{
		m_Angle=v;
	}
	float GetAngle()
	{
		return m_Angle;
	}
	float GetAngle() const
	{
		return m_Angle;
	}

};
//层数据封装类
class MapDataLayerInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataLayerInfoWraperV1()
	{
		
		m_ClientHight = 0;
		m_X = 0;
		m_Z = 0;
		m_Y = 0;
		m_MinHeightLimit = 0;
		m_MaxHeightLimit = 0;

	}
	//赋值构造函数
	MapDataLayerInfoWraperV1(const MapDataLayerInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataLayerInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataLayerInfoV1 ToPB() const
	{
		MapDataLayerInfoV1 v;
		v.mutable_walkarea()->Reserve(m_WalkArea.size());
		for (int i=0; i<(int)m_WalkArea.size(); i++)
		{
			*v.add_walkarea() = m_WalkArea[i].ToPB();
		}
		v.mutable_lostarea()->Reserve(m_LostArea.size());
		for (int i=0; i<(int)m_LostArea.size(); i++)
		{
			*v.add_lostarea() = m_LostArea[i].ToPB();
		}
		v.set_clienthight( m_ClientHight );
		v.set_x( m_X );
		v.set_z( m_Z );
		v.set_y( m_Y );
		v.set_minheightlimit( m_MinHeightLimit );
		v.set_maxheightlimit( m_MaxHeightLimit );

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
		MapDataLayerInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>WalkArea(可行走区) [Vector2] Array</li>\r\n";
		htmlBuff += "<li>LostArea(可掉落区) [Vector2] Array</li>\r\n";
		htmlBuff += "<li>ClientHight(ClientHight) [float]</li>\r\n";
		htmlBuff += "<li>X(X轴) [float]</li>\r\n";
		htmlBuff += "<li>Z(Z轴) [float]</li>\r\n";
		htmlBuff += "<li>Y(Y轴) [float]</li>\r\n";
		htmlBuff += "<li>MinHeightLimit(最小高度限制) [float]</li>\r\n";
		htmlBuff += "<li>MaxHeightLimit(最大高度限制) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>WalkArea：</li>\r\n";
		if( m_WalkArea.size()>0) htmlBuff += m_WalkArea[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_WalkArea.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_WalkArea[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>LostArea：</li>\r\n";
		if( m_LostArea.size()>0) htmlBuff += m_LostArea[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_LostArea.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_LostArea[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>ClientHight：%.2ff</li>\r\n",m_ClientHight);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Z：%.2ff</li>\r\n",m_Z);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Y：%.2ff</li>\r\n",m_Y);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MinHeightLimit：%.2ff</li>\r\n",m_MinHeightLimit);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MaxHeightLimit：%.2ff</li>\r\n",m_MaxHeightLimit);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataLayerInfoV1& v)
	{
		m_WalkArea.clear();
		m_WalkArea.reserve(v.walkarea_size());
		for( int i=0; i<v.walkarea_size(); i++)
			m_WalkArea.push_back(v.walkarea(i));
		m_LostArea.clear();
		m_LostArea.reserve(v.lostarea_size());
		for( int i=0; i<v.lostarea_size(); i++)
			m_LostArea.push_back(v.lostarea(i));
		m_ClientHight = v.clienthight();
		m_X = v.x();
		m_Z = v.z();
		m_Y = v.y();
		m_MinHeightLimit = v.minheightlimit();
		m_MaxHeightLimit = v.maxheightlimit();

	}

private:
	//可行走区
	vector<MapDataVector2WraperV1> m_WalkArea;
public:
	int SizeWalkArea()
	{
		return m_WalkArea.size();
	}
	const vector<MapDataVector2WraperV1>& GetWalkArea() const
	{
		return m_WalkArea;
	}
	MapDataVector2WraperV1 GetWalkArea(int Index) const
	{
		if(Index<0 || Index>=(int)m_WalkArea.size())
		{
			assert(false);
			return MapDataVector2WraperV1();
		}
		return m_WalkArea[Index];
	}
	void SetWalkArea( const vector<MapDataVector2WraperV1>& v )
	{
		m_WalkArea=v;
	}
	void ClearWalkArea( )
	{
		m_WalkArea.clear();
	}
	void SetWalkArea( int Index, const MapDataVector2WraperV1& v )
	{
		if(Index<0 || Index>=(int)m_WalkArea.size())
		{
			assert(false);
			return;
		}
		m_WalkArea[Index] = v;
	}
	void AddWalkArea( const MapDataVector2WraperV1& v )
	{
		m_WalkArea.push_back(v);
	}
private:
	//可掉落区
	vector<MapDataVector2WraperV1> m_LostArea;
public:
	int SizeLostArea()
	{
		return m_LostArea.size();
	}
	const vector<MapDataVector2WraperV1>& GetLostArea() const
	{
		return m_LostArea;
	}
	MapDataVector2WraperV1 GetLostArea(int Index) const
	{
		if(Index<0 || Index>=(int)m_LostArea.size())
		{
			assert(false);
			return MapDataVector2WraperV1();
		}
		return m_LostArea[Index];
	}
	void SetLostArea( const vector<MapDataVector2WraperV1>& v )
	{
		m_LostArea=v;
	}
	void ClearLostArea( )
	{
		m_LostArea.clear();
	}
	void SetLostArea( int Index, const MapDataVector2WraperV1& v )
	{
		if(Index<0 || Index>=(int)m_LostArea.size())
		{
			assert(false);
			return;
		}
		m_LostArea[Index] = v;
	}
	void AddLostArea( const MapDataVector2WraperV1& v )
	{
		m_LostArea.push_back(v);
	}
private:
	//ClientHight
	float m_ClientHight;
public:
	void SetClientHight( float v)
	{
		m_ClientHight=v;
	}
	float GetClientHight()
	{
		return m_ClientHight;
	}
	float GetClientHight() const
	{
		return m_ClientHight;
	}
private:
	//X轴
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
	//Z轴
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
private:
	//Y轴
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
	//最小高度限制
	float m_MinHeightLimit;
public:
	void SetMinHeightLimit( float v)
	{
		m_MinHeightLimit=v;
	}
	float GetMinHeightLimit()
	{
		return m_MinHeightLimit;
	}
	float GetMinHeightLimit() const
	{
		return m_MinHeightLimit;
	}
private:
	//最大高度限制
	float m_MaxHeightLimit;
public:
	void SetMaxHeightLimit( float v)
	{
		m_MaxHeightLimit=v;
	}
	float GetMaxHeightLimit()
	{
		return m_MaxHeightLimit;
	}
	float GetMaxHeightLimit() const
	{
		return m_MaxHeightLimit;
	}

};
//PerfectInfo封装类
class MapDataPerfectInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataPerfectInfoWraperV1()
	{
		
		m_Condition = -1;
		m_DeathCountNum = 0;
		m_KillEnemyID = 0;
		m_KillEnemyCount = 0;
		m_HpPercent = 0;
		m_TimeLimit = 0;

	}
	//赋值构造函数
	MapDataPerfectInfoWraperV1(const MapDataPerfectInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataPerfectInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataPerfectInfoV1 ToPB() const
	{
		MapDataPerfectInfoV1 v;
		v.set_condition( m_Condition );
		v.set_deathcountnum( m_DeathCountNum );
		v.set_killenemyid( m_KillEnemyID );
		v.set_killenemycount( m_KillEnemyCount );
		v.set_hppercent( m_HpPercent );
		v.set_timelimit( m_TimeLimit );

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
		MapDataPerfectInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Condition(Condition) [sint32]</li>\r\n";
		htmlBuff += "<li>DeathCountNum(DeathCountNum) [sint32]</li>\r\n";
		htmlBuff += "<li>KillEnemyID(KillEnemyID) [sint32]</li>\r\n";
		htmlBuff += "<li>KillEnemyCount(KillEnemyCount) [sint32]</li>\r\n";
		htmlBuff += "<li>HpPercent(HpPercent) [sint32]</li>\r\n";
		htmlBuff += "<li>TimeLimit(TimeLimit) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Condition：%di</li>\r\n",m_Condition);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DeathCountNum：%di</li>\r\n",m_DeathCountNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>KillEnemyID：%di</li>\r\n",m_KillEnemyID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>KillEnemyCount：%di</li>\r\n",m_KillEnemyCount);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>HpPercent：%di</li>\r\n",m_HpPercent);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TimeLimit：%.2ff</li>\r\n",m_TimeLimit);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataPerfectInfoV1& v)
	{
		m_Condition = v.condition();
		m_DeathCountNum = v.deathcountnum();
		m_KillEnemyID = v.killenemyid();
		m_KillEnemyCount = v.killenemycount();
		m_HpPercent = v.hppercent();
		m_TimeLimit = v.timelimit();

	}

private:
	//Condition
	INT32 m_Condition;
public:
	void SetCondition( INT32 v)
	{
		m_Condition=v;
	}
	INT32 GetCondition()
	{
		return m_Condition;
	}
	INT32 GetCondition() const
	{
		return m_Condition;
	}
private:
	//DeathCountNum
	INT32 m_DeathCountNum;
public:
	void SetDeathCountNum( INT32 v)
	{
		m_DeathCountNum=v;
	}
	INT32 GetDeathCountNum()
	{
		return m_DeathCountNum;
	}
	INT32 GetDeathCountNum() const
	{
		return m_DeathCountNum;
	}
private:
	//KillEnemyID
	INT32 m_KillEnemyID;
public:
	void SetKillEnemyID( INT32 v)
	{
		m_KillEnemyID=v;
	}
	INT32 GetKillEnemyID()
	{
		return m_KillEnemyID;
	}
	INT32 GetKillEnemyID() const
	{
		return m_KillEnemyID;
	}
private:
	//KillEnemyCount
	INT32 m_KillEnemyCount;
public:
	void SetKillEnemyCount( INT32 v)
	{
		m_KillEnemyCount=v;
	}
	INT32 GetKillEnemyCount()
	{
		return m_KillEnemyCount;
	}
	INT32 GetKillEnemyCount() const
	{
		return m_KillEnemyCount;
	}
private:
	//HpPercent
	INT32 m_HpPercent;
public:
	void SetHpPercent( INT32 v)
	{
		m_HpPercent=v;
	}
	INT32 GetHpPercent()
	{
		return m_HpPercent;
	}
	INT32 GetHpPercent() const
	{
		return m_HpPercent;
	}
private:
	//TimeLimit
	float m_TimeLimit;
public:
	void SetTimeLimit( float v)
	{
		m_TimeLimit=v;
	}
	float GetTimeLimit()
	{
		return m_TimeLimit;
	}
	float GetTimeLimit() const
	{
		return m_TimeLimit;
	}

};
//NpcInfo封装类
class MapDataNpcInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataNpcInfoWraperV1()
	{
		
		m_NpcID = 0;
		m_X = 0;
		m_Layer = 0;
		m_Z = 0;
		m_Direction = 1;
		m_Angle = 0;
		m_Radius = 0;

	}
	//赋值构造函数
	MapDataNpcInfoWraperV1(const MapDataNpcInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataNpcInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataNpcInfoV1 ToPB() const
	{
		MapDataNpcInfoV1 v;
		v.set_npcid( m_NpcID );
		v.set_x( m_X );
		v.set_layer( m_Layer );
		v.set_z( m_Z );
		v.set_direction( m_Direction );
		v.set_angle( m_Angle );
		v.set_radius( m_Radius );

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
		MapDataNpcInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>NpcID(NpcID) [sint32]</li>\r\n";
		htmlBuff += "<li>X(X) [float]</li>\r\n";
		htmlBuff += "<li>Layer(Layer) [sint32]</li>\r\n";
		htmlBuff += "<li>Z(Z轴) [float]</li>\r\n";
		htmlBuff += "<li>Direction(朝向) [sint32]</li>\r\n";
		htmlBuff += "<li>Angle(角度) [float]</li>\r\n";
		htmlBuff += "<li>Radius(半径) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>NpcID：%di</li>\r\n",m_NpcID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Layer：%di</li>\r\n",m_Layer);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Z：%.2ff</li>\r\n",m_Z);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Direction：%di</li>\r\n",m_Direction);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Angle：%.2ff</li>\r\n",m_Angle);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Radius：%.2ff</li>\r\n",m_Radius);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataNpcInfoV1& v)
	{
		m_NpcID = v.npcid();
		m_X = v.x();
		m_Layer = v.layer();
		m_Z = v.z();
		m_Direction = v.direction();
		m_Angle = v.angle();
		m_Radius = v.radius();

	}

private:
	//NpcID
	INT32 m_NpcID;
public:
	void SetNpcID( INT32 v)
	{
		m_NpcID=v;
	}
	INT32 GetNpcID()
	{
		return m_NpcID;
	}
	INT32 GetNpcID() const
	{
		return m_NpcID;
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
	//Layer
	INT32 m_Layer;
public:
	void SetLayer( INT32 v)
	{
		m_Layer=v;
	}
	INT32 GetLayer()
	{
		return m_Layer;
	}
	INT32 GetLayer() const
	{
		return m_Layer;
	}
private:
	//Z轴
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
private:
	//朝向
	INT32 m_Direction;
public:
	void SetDirection( INT32 v)
	{
		m_Direction=v;
	}
	INT32 GetDirection()
	{
		return m_Direction;
	}
	INT32 GetDirection() const
	{
		return m_Direction;
	}
private:
	//角度
	float m_Angle;
public:
	void SetAngle( float v)
	{
		m_Angle=v;
	}
	float GetAngle()
	{
		return m_Angle;
	}
	float GetAngle() const
	{
		return m_Angle;
	}
private:
	//半径
	float m_Radius;
public:
	void SetRadius( float v)
	{
		m_Radius=v;
	}
	float GetRadius()
	{
		return m_Radius;
	}
	float GetRadius() const
	{
		return m_Radius;
	}

};
//TrapInfo封装类
class MapDataTrapInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataTrapInfoWraperV1()
	{
		
		m_TrapID = 0;
		m_X = 0;
		m_Y = 0;
		m_Direction = 1;
		m_Z = 0;

	}
	//赋值构造函数
	MapDataTrapInfoWraperV1(const MapDataTrapInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataTrapInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataTrapInfoV1 ToPB() const
	{
		MapDataTrapInfoV1 v;
		v.set_trapid( m_TrapID );
		v.set_x( m_X );
		v.set_y( m_Y );
		v.set_direction( m_Direction );
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
		MapDataTrapInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TrapID(TrapID) [sint32]</li>\r\n";
		htmlBuff += "<li>X(X) [float]</li>\r\n";
		htmlBuff += "<li>Y(Y) [float]</li>\r\n";
		htmlBuff += "<li>Direction(朝向) [sint32]</li>\r\n";
		htmlBuff += "<li>Z(Z轴) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TrapID：%di</li>\r\n",m_TrapID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Y：%.2ff</li>\r\n",m_Y);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Direction：%di</li>\r\n",m_Direction);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Z：%.2ff</li>\r\n",m_Z);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataTrapInfoV1& v)
	{
		m_TrapID = v.trapid();
		m_X = v.x();
		m_Y = v.y();
		m_Direction = v.direction();
		m_Z = v.z();

	}

private:
	//TrapID
	INT32 m_TrapID;
public:
	void SetTrapID( INT32 v)
	{
		m_TrapID=v;
	}
	INT32 GetTrapID()
	{
		return m_TrapID;
	}
	INT32 GetTrapID() const
	{
		return m_TrapID;
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
	//朝向
	INT32 m_Direction;
public:
	void SetDirection( INT32 v)
	{
		m_Direction=v;
	}
	INT32 GetDirection()
	{
		return m_Direction;
	}
	INT32 GetDirection() const
	{
		return m_Direction;
	}
private:
	//Z轴
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
//PortalInfo封装类
class MapDataPortalInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataPortalInfoWraperV1()
	{
		
		m_SourceX = 0;
		m_SourceLayer = 0;
		m_TargetX = -1;
		m_TargetLayer = -1;
		m_UseCount = 1;
		m_Channel = false;
		m_PortalType = 0;
		m_TargetDungeonId = 0;
		m_TargetSpawnIndex = 0;
		m_TargetDirection = 0;
		m_SourceZ = 0;
		m_TargetZ = 0;
		m_SourceAngle = 0;
		m_TargetAngle = 0;
		m_SourceRadius = 0;
		m_TargetRadius = 0;

	}
	//赋值构造函数
	MapDataPortalInfoWraperV1(const MapDataPortalInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataPortalInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataPortalInfoV1 ToPB() const
	{
		MapDataPortalInfoV1 v;
		v.set_sourcex( m_SourceX );
		v.set_sourcelayer( m_SourceLayer );
		v.set_targetx( m_TargetX );
		v.set_targetlayer( m_TargetLayer );
		v.set_usecount( m_UseCount );
		v.set_channel( m_Channel );
		v.set_portaltype( m_PortalType );
		v.set_targetdungeonid( m_TargetDungeonId );
		v.set_targetspawnindex( m_TargetSpawnIndex );
		v.set_targetdirection( m_TargetDirection );
		v.set_sourcez( m_SourceZ );
		v.set_targetz( m_TargetZ );
		v.set_sourceangle( m_SourceAngle );
		v.set_targetangle( m_TargetAngle );
		v.set_sourceradius( m_SourceRadius );
		v.set_targetradius( m_TargetRadius );

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
		MapDataPortalInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SourceX(SourceX) [float]</li>\r\n";
		htmlBuff += "<li>SourceLayer(SourceLayer) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetX(TargetX) [float]</li>\r\n";
		htmlBuff += "<li>TargetLayer(TargetLayer) [sint32]</li>\r\n";
		htmlBuff += "<li>UseCount(UseCount) [sint32]</li>\r\n";
		htmlBuff += "<li>Channel(Channel) [bool]</li>\r\n";
		htmlBuff += "<li>PortalType(PortalType) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetDungeonId(目标副本id) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetSpawnIndex(目标出生点索引) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetDirection(传送目标点朝向) [sint32]</li>\r\n";
		htmlBuff += "<li>SourceZ(源Z轴) [float]</li>\r\n";
		htmlBuff += "<li>TargetZ(目标Z轴) [float]</li>\r\n";
		htmlBuff += "<li>SourceAngle(源角度) [float]</li>\r\n";
		htmlBuff += "<li>TargetAngle(目标角度) [float]</li>\r\n";
		htmlBuff += "<li>SourceRadius(源半径) [float]</li>\r\n";
		htmlBuff += "<li>TargetRadius(目标半径) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>SourceX：%.2ff</li>\r\n",m_SourceX);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SourceLayer：%di</li>\r\n",m_SourceLayer);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetX：%.2ff</li>\r\n",m_TargetX);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetLayer：%di</li>\r\n",m_TargetLayer);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UseCount：%di</li>\r\n",m_UseCount);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Channel：%di</li>\r\n",m_Channel);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PortalType：%di</li>\r\n",m_PortalType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetDungeonId：%di</li>\r\n",m_TargetDungeonId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetSpawnIndex：%di</li>\r\n",m_TargetSpawnIndex);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetDirection：%di</li>\r\n",m_TargetDirection);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SourceZ：%.2ff</li>\r\n",m_SourceZ);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetZ：%.2ff</li>\r\n",m_TargetZ);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SourceAngle：%.2ff</li>\r\n",m_SourceAngle);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetAngle：%.2ff</li>\r\n",m_TargetAngle);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SourceRadius：%.2ff</li>\r\n",m_SourceRadius);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetRadius：%.2ff</li>\r\n",m_TargetRadius);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataPortalInfoV1& v)
	{
		m_SourceX = v.sourcex();
		m_SourceLayer = v.sourcelayer();
		m_TargetX = v.targetx();
		m_TargetLayer = v.targetlayer();
		m_UseCount = v.usecount();
		m_Channel = v.channel();
		m_PortalType = v.portaltype();
		m_TargetDungeonId = v.targetdungeonid();
		m_TargetSpawnIndex = v.targetspawnindex();
		m_TargetDirection = v.targetdirection();
		m_SourceZ = v.sourcez();
		m_TargetZ = v.targetz();
		m_SourceAngle = v.sourceangle();
		m_TargetAngle = v.targetangle();
		m_SourceRadius = v.sourceradius();
		m_TargetRadius = v.targetradius();

	}

private:
	//SourceX
	float m_SourceX;
public:
	void SetSourceX( float v)
	{
		m_SourceX=v;
	}
	float GetSourceX()
	{
		return m_SourceX;
	}
	float GetSourceX() const
	{
		return m_SourceX;
	}
private:
	//SourceLayer
	INT32 m_SourceLayer;
public:
	void SetSourceLayer( INT32 v)
	{
		m_SourceLayer=v;
	}
	INT32 GetSourceLayer()
	{
		return m_SourceLayer;
	}
	INT32 GetSourceLayer() const
	{
		return m_SourceLayer;
	}
private:
	//TargetX
	float m_TargetX;
public:
	void SetTargetX( float v)
	{
		m_TargetX=v;
	}
	float GetTargetX()
	{
		return m_TargetX;
	}
	float GetTargetX() const
	{
		return m_TargetX;
	}
private:
	//TargetLayer
	INT32 m_TargetLayer;
public:
	void SetTargetLayer( INT32 v)
	{
		m_TargetLayer=v;
	}
	INT32 GetTargetLayer()
	{
		return m_TargetLayer;
	}
	INT32 GetTargetLayer() const
	{
		return m_TargetLayer;
	}
private:
	//UseCount
	INT32 m_UseCount;
public:
	void SetUseCount( INT32 v)
	{
		m_UseCount=v;
	}
	INT32 GetUseCount()
	{
		return m_UseCount;
	}
	INT32 GetUseCount() const
	{
		return m_UseCount;
	}
private:
	//Channel
	bool m_Channel;
public:
	void SetChannel( bool v)
	{
		m_Channel=v;
	}
	bool GetChannel()
	{
		return m_Channel;
	}
	bool GetChannel() const
	{
		return m_Channel;
	}
private:
	//PortalType
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
private:
	//目标副本id
	INT32 m_TargetDungeonId;
public:
	void SetTargetDungeonId( INT32 v)
	{
		m_TargetDungeonId=v;
	}
	INT32 GetTargetDungeonId()
	{
		return m_TargetDungeonId;
	}
	INT32 GetTargetDungeonId() const
	{
		return m_TargetDungeonId;
	}
private:
	//目标出生点索引
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
	//传送目标点朝向
	INT32 m_TargetDirection;
public:
	void SetTargetDirection( INT32 v)
	{
		m_TargetDirection=v;
	}
	INT32 GetTargetDirection()
	{
		return m_TargetDirection;
	}
	INT32 GetTargetDirection() const
	{
		return m_TargetDirection;
	}
private:
	//源Z轴
	float m_SourceZ;
public:
	void SetSourceZ( float v)
	{
		m_SourceZ=v;
	}
	float GetSourceZ()
	{
		return m_SourceZ;
	}
	float GetSourceZ() const
	{
		return m_SourceZ;
	}
private:
	//目标Z轴
	float m_TargetZ;
public:
	void SetTargetZ( float v)
	{
		m_TargetZ=v;
	}
	float GetTargetZ()
	{
		return m_TargetZ;
	}
	float GetTargetZ() const
	{
		return m_TargetZ;
	}
private:
	//源角度
	float m_SourceAngle;
public:
	void SetSourceAngle( float v)
	{
		m_SourceAngle=v;
	}
	float GetSourceAngle()
	{
		return m_SourceAngle;
	}
	float GetSourceAngle() const
	{
		return m_SourceAngle;
	}
private:
	//目标角度
	float m_TargetAngle;
public:
	void SetTargetAngle( float v)
	{
		m_TargetAngle=v;
	}
	float GetTargetAngle()
	{
		return m_TargetAngle;
	}
	float GetTargetAngle() const
	{
		return m_TargetAngle;
	}
private:
	//源半径
	float m_SourceRadius;
public:
	void SetSourceRadius( float v)
	{
		m_SourceRadius=v;
	}
	float GetSourceRadius()
	{
		return m_SourceRadius;
	}
	float GetSourceRadius() const
	{
		return m_SourceRadius;
	}
private:
	//目标半径
	float m_TargetRadius;
public:
	void SetTargetRadius( float v)
	{
		m_TargetRadius=v;
	}
	float GetTargetRadius()
	{
		return m_TargetRadius;
	}
	float GetTargetRadius() const
	{
		return m_TargetRadius;
	}

};
//场景信息封装类
class MapDataInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	MapDataInfoWraperV1()
	{
		
		m_Defeat = MapDataDefeatInfoWraperV1();
		m_Name = "";
		m_StormFlag = MapDataTerritorialInfoWraperV1();
		m_BaseConfig = MapDataBaseConfigWraperV1();

	}
	//赋值构造函数
	MapDataInfoWraperV1(const MapDataInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataInfoV1 ToPB() const
	{
		MapDataInfoV1 v;
		v.mutable_layerarr()->Reserve(m_LayerArr.size());
		for (int i=0; i<(int)m_LayerArr.size(); i++)
		{
			*v.add_layerarr() = m_LayerArr[i].ToPB();
		}
		v.mutable_spawnarr()->Reserve(m_SpawnArr.size());
		for (int i=0; i<(int)m_SpawnArr.size(); i++)
		{
			*v.add_spawnarr() = m_SpawnArr[i].ToPB();
		}
		*v.mutable_defeat()= m_Defeat.ToPB();
		v.mutable_perfectarr()->Reserve(m_PerfectArr.size());
		for (int i=0; i<(int)m_PerfectArr.size(); i++)
		{
			*v.add_perfectarr() = m_PerfectArr[i].ToPB();
		}
		v.mutable_portalarr()->Reserve(m_PortalArr.size());
		for (int i=0; i<(int)m_PortalArr.size(); i++)
		{
			*v.add_portalarr() = m_PortalArr[i].ToPB();
		}
		v.mutable_traparr()->Reserve(m_TrapArr.size());
		for (int i=0; i<(int)m_TrapArr.size(); i++)
		{
			*v.add_traparr() = m_TrapArr[i].ToPB();
		}
		v.mutable_npcarr()->Reserve(m_NpcArr.size());
		for (int i=0; i<(int)m_NpcArr.size(); i++)
		{
			*v.add_npcarr() = m_NpcArr[i].ToPB();
		}
		v.mutable_nodearr()->Reserve(m_NodeArr.size());
		for (int i=0; i<(int)m_NodeArr.size(); i++)
		{
			*v.add_nodearr() = m_NodeArr[i].ToPB();
		}
		v.set_name( m_Name );
		v.mutable_stormbasearr()->Reserve(m_StormBaseArr.size());
		for (int i=0; i<(int)m_StormBaseArr.size(); i++)
		{
			*v.add_stormbasearr() = m_StormBaseArr[i].ToPB();
		}
		*v.mutable_stormflag()= m_StormFlag.ToPB();
		*v.mutable_baseconfig()= m_BaseConfig.ToPB();
		v.mutable_gatherarr()->Reserve(m_GatherArr.size());
		for (int i=0; i<(int)m_GatherArr.size(); i++)
		{
			*v.add_gatherarr() = m_GatherArr[i].ToPB();
		}
		v.mutable_eventarr()->Reserve(m_EventArr.size());
		for (int i=0; i<(int)m_EventArr.size(); i++)
		{
			*v.add_eventarr() = m_EventArr[i].ToPB();
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
		MapDataInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>LayerArr(层) [LayerInfo] Array</li>\r\n";
		htmlBuff += "<li>SpawnArr(SpawnArr) [SpawnInfo] Array</li>\r\n";
		htmlBuff += "<li>Defeat(Defeat) [DefeatInfo]</li>\r\n";
		htmlBuff += "<li>PerfectArr(PerfectArr) [PerfectInfo] Array</li>\r\n";
		htmlBuff += "<li>PortalArr(PortalArr) [PortalInfo] Array</li>\r\n";
		htmlBuff += "<li>TrapArr(TrapArr) [TrapInfo] Array</li>\r\n";
		htmlBuff += "<li>NpcArr(NpcArr) [NpcInfo] Array</li>\r\n";
		htmlBuff += "<li>NodeArr(NodeArr) [NodeInfo] Array</li>\r\n";
		htmlBuff += "<li>Name(Name) [string]</li>\r\n";
		htmlBuff += "<li>StormBaseArr(领地) [TerritorialInfo] Array</li>\r\n";
		htmlBuff += "<li>StormFlag(旗子) [TerritorialInfo]</li>\r\n";
		htmlBuff += "<li>BaseConfig(基础配置) [BaseConfig]</li>\r\n";
		htmlBuff += "<li>GatherArr(采集物数据) [GatherInfo] Array</li>\r\n";
		htmlBuff += "<li>EventArr(事件信息) [EventInfo] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>LayerArr：</li>\r\n";
		if( m_LayerArr.size()>0) htmlBuff += m_LayerArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_LayerArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_LayerArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>SpawnArr：</li>\r\n";
		if( m_SpawnArr.size()>0) htmlBuff += m_SpawnArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_SpawnArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_SpawnArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>Defeat：</li>\r\n";
		htmlBuff += m_Defeat.HtmlDescHeader();
		htmlBuff += m_Defeat.ToHtml();
		htmlBuff += "<li>PerfectArr：</li>\r\n";
		if( m_PerfectArr.size()>0) htmlBuff += m_PerfectArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_PerfectArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_PerfectArr[i].ToHtml().c_str() +"</td></tr>";
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
		htmlBuff += "<li>TrapArr：</li>\r\n";
		if( m_TrapArr.size()>0) htmlBuff += m_TrapArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_TrapArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_TrapArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>NpcArr：</li>\r\n";
		if( m_NpcArr.size()>0) htmlBuff += m_NpcArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_NpcArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_NpcArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>NodeArr：</li>\r\n";
		if( m_NodeArr.size()>0) htmlBuff += m_NodeArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_NodeArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_NodeArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>Name：\""+m_Name+"\"</li>\r\n";
		htmlBuff += "<li>StormBaseArr：</li>\r\n";
		if( m_StormBaseArr.size()>0) htmlBuff += m_StormBaseArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_StormBaseArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_StormBaseArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>StormFlag：</li>\r\n";
		htmlBuff += m_StormFlag.HtmlDescHeader();
		htmlBuff += m_StormFlag.ToHtml();
		htmlBuff += "<li>BaseConfig：</li>\r\n";
		htmlBuff += m_BaseConfig.HtmlDescHeader();
		htmlBuff += m_BaseConfig.ToHtml();
		htmlBuff += "<li>GatherArr：</li>\r\n";
		if( m_GatherArr.size()>0) htmlBuff += m_GatherArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_GatherArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_GatherArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>EventArr：</li>\r\n";
		if( m_EventArr.size()>0) htmlBuff += m_EventArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_EventArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_EventArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataInfoV1& v)
	{
		m_LayerArr.clear();
		m_LayerArr.reserve(v.layerarr_size());
		for( int i=0; i<v.layerarr_size(); i++)
			m_LayerArr.push_back(v.layerarr(i));
		m_SpawnArr.clear();
		m_SpawnArr.reserve(v.spawnarr_size());
		for( int i=0; i<v.spawnarr_size(); i++)
			m_SpawnArr.push_back(v.spawnarr(i));
		m_Defeat = v.defeat();
		m_PerfectArr.clear();
		m_PerfectArr.reserve(v.perfectarr_size());
		for( int i=0; i<v.perfectarr_size(); i++)
			m_PerfectArr.push_back(v.perfectarr(i));
		m_PortalArr.clear();
		m_PortalArr.reserve(v.portalarr_size());
		for( int i=0; i<v.portalarr_size(); i++)
			m_PortalArr.push_back(v.portalarr(i));
		m_TrapArr.clear();
		m_TrapArr.reserve(v.traparr_size());
		for( int i=0; i<v.traparr_size(); i++)
			m_TrapArr.push_back(v.traparr(i));
		m_NpcArr.clear();
		m_NpcArr.reserve(v.npcarr_size());
		for( int i=0; i<v.npcarr_size(); i++)
			m_NpcArr.push_back(v.npcarr(i));
		m_NodeArr.clear();
		m_NodeArr.reserve(v.nodearr_size());
		for( int i=0; i<v.nodearr_size(); i++)
			m_NodeArr.push_back(v.nodearr(i));
		m_Name = v.name();
		m_StormBaseArr.clear();
		m_StormBaseArr.reserve(v.stormbasearr_size());
		for( int i=0; i<v.stormbasearr_size(); i++)
			m_StormBaseArr.push_back(v.stormbasearr(i));
		m_StormFlag = v.stormflag();
		m_BaseConfig = v.baseconfig();
		m_GatherArr.clear();
		m_GatherArr.reserve(v.gatherarr_size());
		for( int i=0; i<v.gatherarr_size(); i++)
			m_GatherArr.push_back(v.gatherarr(i));
		m_EventArr.clear();
		m_EventArr.reserve(v.eventarr_size());
		for( int i=0; i<v.eventarr_size(); i++)
			m_EventArr.push_back(v.eventarr(i));

	}

private:
	//层
	vector<MapDataLayerInfoWraperV1> m_LayerArr;
public:
	int SizeLayerArr()
	{
		return m_LayerArr.size();
	}
	const vector<MapDataLayerInfoWraperV1>& GetLayerArr() const
	{
		return m_LayerArr;
	}
	MapDataLayerInfoWraperV1 GetLayerArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_LayerArr.size())
		{
			assert(false);
			return MapDataLayerInfoWraperV1();
		}
		return m_LayerArr[Index];
	}
	void SetLayerArr( const vector<MapDataLayerInfoWraperV1>& v )
	{
		m_LayerArr=v;
	}
	void ClearLayerArr( )
	{
		m_LayerArr.clear();
	}
	void SetLayerArr( int Index, const MapDataLayerInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_LayerArr.size())
		{
			assert(false);
			return;
		}
		m_LayerArr[Index] = v;
	}
	void AddLayerArr( const MapDataLayerInfoWraperV1& v )
	{
		m_LayerArr.push_back(v);
	}
private:
	//SpawnArr
	vector<MapDataSpawnInfoWraperV1> m_SpawnArr;
public:
	int SizeSpawnArr()
	{
		return m_SpawnArr.size();
	}
	const vector<MapDataSpawnInfoWraperV1>& GetSpawnArr() const
	{
		return m_SpawnArr;
	}
	MapDataSpawnInfoWraperV1 GetSpawnArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_SpawnArr.size())
		{
			assert(false);
			return MapDataSpawnInfoWraperV1();
		}
		return m_SpawnArr[Index];
	}
	void SetSpawnArr( const vector<MapDataSpawnInfoWraperV1>& v )
	{
		m_SpawnArr=v;
	}
	void ClearSpawnArr( )
	{
		m_SpawnArr.clear();
	}
	void SetSpawnArr( int Index, const MapDataSpawnInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_SpawnArr.size())
		{
			assert(false);
			return;
		}
		m_SpawnArr[Index] = v;
	}
	void AddSpawnArr( const MapDataSpawnInfoWraperV1& v )
	{
		m_SpawnArr.push_back(v);
	}
private:
	//Defeat
	MapDataDefeatInfoWraperV1 m_Defeat;
public:
	void SetDefeat( const MapDataDefeatInfoWraperV1& v)
	{
		m_Defeat=v;
	}
	MapDataDefeatInfoWraperV1 GetDefeat()
	{
		return m_Defeat;
	}
	MapDataDefeatInfoWraperV1 GetDefeat() const
	{
		return m_Defeat;
	}
private:
	//PerfectArr
	vector<MapDataPerfectInfoWraperV1> m_PerfectArr;
public:
	int SizePerfectArr()
	{
		return m_PerfectArr.size();
	}
	const vector<MapDataPerfectInfoWraperV1>& GetPerfectArr() const
	{
		return m_PerfectArr;
	}
	MapDataPerfectInfoWraperV1 GetPerfectArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_PerfectArr.size())
		{
			assert(false);
			return MapDataPerfectInfoWraperV1();
		}
		return m_PerfectArr[Index];
	}
	void SetPerfectArr( const vector<MapDataPerfectInfoWraperV1>& v )
	{
		m_PerfectArr=v;
	}
	void ClearPerfectArr( )
	{
		m_PerfectArr.clear();
	}
	void SetPerfectArr( int Index, const MapDataPerfectInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_PerfectArr.size())
		{
			assert(false);
			return;
		}
		m_PerfectArr[Index] = v;
	}
	void AddPerfectArr( const MapDataPerfectInfoWraperV1& v )
	{
		m_PerfectArr.push_back(v);
	}
private:
	//PortalArr
	vector<MapDataPortalInfoWraperV1> m_PortalArr;
public:
	int SizePortalArr()
	{
		return m_PortalArr.size();
	}
	const vector<MapDataPortalInfoWraperV1>& GetPortalArr() const
	{
		return m_PortalArr;
	}
	MapDataPortalInfoWraperV1 GetPortalArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_PortalArr.size())
		{
			assert(false);
			return MapDataPortalInfoWraperV1();
		}
		return m_PortalArr[Index];
	}
	void SetPortalArr( const vector<MapDataPortalInfoWraperV1>& v )
	{
		m_PortalArr=v;
	}
	void ClearPortalArr( )
	{
		m_PortalArr.clear();
	}
	void SetPortalArr( int Index, const MapDataPortalInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_PortalArr.size())
		{
			assert(false);
			return;
		}
		m_PortalArr[Index] = v;
	}
	void AddPortalArr( const MapDataPortalInfoWraperV1& v )
	{
		m_PortalArr.push_back(v);
	}
private:
	//TrapArr
	vector<MapDataTrapInfoWraperV1> m_TrapArr;
public:
	int SizeTrapArr()
	{
		return m_TrapArr.size();
	}
	const vector<MapDataTrapInfoWraperV1>& GetTrapArr() const
	{
		return m_TrapArr;
	}
	MapDataTrapInfoWraperV1 GetTrapArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_TrapArr.size())
		{
			assert(false);
			return MapDataTrapInfoWraperV1();
		}
		return m_TrapArr[Index];
	}
	void SetTrapArr( const vector<MapDataTrapInfoWraperV1>& v )
	{
		m_TrapArr=v;
	}
	void ClearTrapArr( )
	{
		m_TrapArr.clear();
	}
	void SetTrapArr( int Index, const MapDataTrapInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_TrapArr.size())
		{
			assert(false);
			return;
		}
		m_TrapArr[Index] = v;
	}
	void AddTrapArr( const MapDataTrapInfoWraperV1& v )
	{
		m_TrapArr.push_back(v);
	}
private:
	//NpcArr
	vector<MapDataNpcInfoWraperV1> m_NpcArr;
public:
	int SizeNpcArr()
	{
		return m_NpcArr.size();
	}
	const vector<MapDataNpcInfoWraperV1>& GetNpcArr() const
	{
		return m_NpcArr;
	}
	MapDataNpcInfoWraperV1 GetNpcArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_NpcArr.size())
		{
			assert(false);
			return MapDataNpcInfoWraperV1();
		}
		return m_NpcArr[Index];
	}
	void SetNpcArr( const vector<MapDataNpcInfoWraperV1>& v )
	{
		m_NpcArr=v;
	}
	void ClearNpcArr( )
	{
		m_NpcArr.clear();
	}
	void SetNpcArr( int Index, const MapDataNpcInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_NpcArr.size())
		{
			assert(false);
			return;
		}
		m_NpcArr[Index] = v;
	}
	void AddNpcArr( const MapDataNpcInfoWraperV1& v )
	{
		m_NpcArr.push_back(v);
	}
private:
	//NodeArr
	vector<MapDataNodeInfoWraperV1> m_NodeArr;
public:
	int SizeNodeArr()
	{
		return m_NodeArr.size();
	}
	const vector<MapDataNodeInfoWraperV1>& GetNodeArr() const
	{
		return m_NodeArr;
	}
	MapDataNodeInfoWraperV1 GetNodeArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_NodeArr.size())
		{
			assert(false);
			return MapDataNodeInfoWraperV1();
		}
		return m_NodeArr[Index];
	}
	void SetNodeArr( const vector<MapDataNodeInfoWraperV1>& v )
	{
		m_NodeArr=v;
	}
	void ClearNodeArr( )
	{
		m_NodeArr.clear();
	}
	void SetNodeArr( int Index, const MapDataNodeInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_NodeArr.size())
		{
			assert(false);
			return;
		}
		m_NodeArr[Index] = v;
	}
	void AddNodeArr( const MapDataNodeInfoWraperV1& v )
	{
		m_NodeArr.push_back(v);
	}
private:
	//Name
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
	//领地
	vector<MapDataTerritorialInfoWraperV1> m_StormBaseArr;
public:
	int SizeStormBaseArr()
	{
		return m_StormBaseArr.size();
	}
	const vector<MapDataTerritorialInfoWraperV1>& GetStormBaseArr() const
	{
		return m_StormBaseArr;
	}
	MapDataTerritorialInfoWraperV1 GetStormBaseArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_StormBaseArr.size())
		{
			assert(false);
			return MapDataTerritorialInfoWraperV1();
		}
		return m_StormBaseArr[Index];
	}
	void SetStormBaseArr( const vector<MapDataTerritorialInfoWraperV1>& v )
	{
		m_StormBaseArr=v;
	}
	void ClearStormBaseArr( )
	{
		m_StormBaseArr.clear();
	}
	void SetStormBaseArr( int Index, const MapDataTerritorialInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_StormBaseArr.size())
		{
			assert(false);
			return;
		}
		m_StormBaseArr[Index] = v;
	}
	void AddStormBaseArr( const MapDataTerritorialInfoWraperV1& v )
	{
		m_StormBaseArr.push_back(v);
	}
private:
	//旗子
	MapDataTerritorialInfoWraperV1 m_StormFlag;
public:
	void SetStormFlag( const MapDataTerritorialInfoWraperV1& v)
	{
		m_StormFlag=v;
	}
	MapDataTerritorialInfoWraperV1 GetStormFlag()
	{
		return m_StormFlag;
	}
	MapDataTerritorialInfoWraperV1 GetStormFlag() const
	{
		return m_StormFlag;
	}
private:
	//基础配置
	MapDataBaseConfigWraperV1 m_BaseConfig;
public:
	void SetBaseConfig( const MapDataBaseConfigWraperV1& v)
	{
		m_BaseConfig=v;
	}
	MapDataBaseConfigWraperV1 GetBaseConfig()
	{
		return m_BaseConfig;
	}
	MapDataBaseConfigWraperV1 GetBaseConfig() const
	{
		return m_BaseConfig;
	}
private:
	//采集物数据
	vector<MapDataGatherInfoWraperV1> m_GatherArr;
public:
	int SizeGatherArr()
	{
		return m_GatherArr.size();
	}
	const vector<MapDataGatherInfoWraperV1>& GetGatherArr() const
	{
		return m_GatherArr;
	}
	MapDataGatherInfoWraperV1 GetGatherArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_GatherArr.size())
		{
			assert(false);
			return MapDataGatherInfoWraperV1();
		}
		return m_GatherArr[Index];
	}
	void SetGatherArr( const vector<MapDataGatherInfoWraperV1>& v )
	{
		m_GatherArr=v;
	}
	void ClearGatherArr( )
	{
		m_GatherArr.clear();
	}
	void SetGatherArr( int Index, const MapDataGatherInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_GatherArr.size())
		{
			assert(false);
			return;
		}
		m_GatherArr[Index] = v;
	}
	void AddGatherArr( const MapDataGatherInfoWraperV1& v )
	{
		m_GatherArr.push_back(v);
	}
private:
	//事件信息
	vector<MapDataEventInfoWraperV1> m_EventArr;
public:
	int SizeEventArr()
	{
		return m_EventArr.size();
	}
	const vector<MapDataEventInfoWraperV1>& GetEventArr() const
	{
		return m_EventArr;
	}
	MapDataEventInfoWraperV1 GetEventArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_EventArr.size())
		{
			assert(false);
			return MapDataEventInfoWraperV1();
		}
		return m_EventArr[Index];
	}
	void SetEventArr( const vector<MapDataEventInfoWraperV1>& v )
	{
		m_EventArr=v;
	}
	void ClearEventArr( )
	{
		m_EventArr.clear();
	}
	void SetEventArr( int Index, const MapDataEventInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_EventArr.size())
		{
			assert(false);
			return;
		}
		m_EventArr[Index] = v;
	}
	void AddEventArr( const MapDataEventInfoWraperV1& v )
	{
		m_EventArr.push_back(v);
	}

};
//无用封装类
class MapDataUselessWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<MapDataUselessWraperV1>
{
public:
	//构造函数
	MapDataUselessWraperV1()
	{
		SetDataWraper( this );

		m_X1 = -1;

	}
	//赋值构造函数
	MapDataUselessWraperV1(const MapDataUselessV1& v){ Init(v); }
	//等号重载函数
	void operator = (const MapDataUselessV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MapDataUselessV1 ToPB() const
	{
		MapDataUselessV1 v;
		v.set_x1( m_X1 );

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
		MapDataUselessV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>X1(X1) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>X1：%di</li>\r\n",m_X1);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const MapDataUselessV1& v)
	{
		m_X1 = v.x1();

	}

private:
	//X1
	INT32 m_X1;
public:
	void SetX1( INT32 v)
	{
		m_X1=v;
	}
	INT32 GetX1()
	{
		return m_X1;
	}
	INT32 GetX1() const
	{
		return m_X1;
	}

};

#endif
