/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperFight.h
* Author:       甘业清
* Description:  战斗RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_FIGHT_H
#define __RPC_WRAPER_FIGHT_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "FightRpc.pb.h"



//战斗类的枚举定义
enum ConstFightE
{
	MODULE_ID_FIGHT                              = 9,	//战斗模块ID
	RPC_CODE_FIGHT_READY_REQUEST                 = 951,	//战斗-->游戏准备就绪-->请求
	RPC_CODE_FIGHT_ACTION_NOTIFY                 = 952,	//战斗-->动作-->通知
	RPC_CODE_FIGHT_RESULT_NOTIFY                 = 953,	//战斗-->战斗结果-->通知
	RPC_CODE_FIGHT_ENTER_REQUEST                 = 954,	//战斗-->进入副本-->请求
	RPC_CODE_FIGHT_START_NOTIFY                  = 955,	//战斗-->战斗开始-->通知


};


//暴风个人战斗统计信息封装类
class FightStormPlayerInfoWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightStormPlayerInfoWraper()
	{
		
		m_KilledNum = 0;
		m_DeadTimes = 0;
		m_Name = "";
		m_FlagTimes = 0;
		m_Prof = -1;
		m_OutputDamage = -1;
		m_EndureDamage = -1;
		m_TreatDamage = -1;
		m_ObjId = -1;

	}
	//赋值构造函数
	FightStormPlayerInfoWraper(const FightStormPlayerInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const FightStormPlayerInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightStormPlayerInfo ToPB() const
	{
		FightStormPlayerInfo v;
		v.set_killednum( m_KilledNum );
		v.set_deadtimes( m_DeadTimes );
		v.set_name( m_Name );
		v.set_flagtimes( m_FlagTimes );
		v.set_prof( m_Prof );
		v.set_outputdamage( m_OutputDamage );
		v.set_enduredamage( m_EndureDamage );
		v.set_treatdamage( m_TreatDamage );
		v.set_objid( m_ObjId );

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
		FightStormPlayerInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>KilledNum(杀人数) [sint32]</li>\r\n";
		htmlBuff += "<li>DeadTimes(死亡次数) [sint32]</li>\r\n";
		htmlBuff += "<li>Name(名字) [string]</li>\r\n";
		htmlBuff += "<li>FlagTimes(放旗数) [sint32]</li>\r\n";
		htmlBuff += "<li>Prof(职业) [sint32]</li>\r\n";
		htmlBuff += "<li>OutputDamage(总输出伤害) [sint64]</li>\r\n";
		htmlBuff += "<li>EndureDamage(承受伤害) [sint64]</li>\r\n";
		htmlBuff += "<li>TreatDamage(总治疗量) [sint64]</li>\r\n";
		htmlBuff += "<li>ObjId(玩家ObjId) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>KilledNum：%di</li>\r\n",m_KilledNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DeadTimes：%di</li>\r\n",m_DeadTimes);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Name：\""+m_Name+"\"</li>\r\n";
		tmpLine.Fmt("<li>FlagTimes：%di</li>\r\n",m_FlagTimes);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Prof：%di</li>\r\n",m_Prof);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>OutputDamage：%lldL</li>\r\n",m_OutputDamage);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EndureDamage：%lldL</li>\r\n",m_EndureDamage);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TreatDamage：%lldL</li>\r\n",m_TreatDamage);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightStormPlayerInfo& v)
	{
		m_KilledNum = v.killednum();
		m_DeadTimes = v.deadtimes();
		m_Name = v.name();
		m_FlagTimes = v.flagtimes();
		m_Prof = v.prof();
		m_OutputDamage = v.outputdamage();
		m_EndureDamage = v.enduredamage();
		m_TreatDamage = v.treatdamage();
		m_ObjId = v.objid();

	}

private:
	//杀人数
	INT32 m_KilledNum;
public:
	void SetKilledNum( INT32 v)
	{
		m_KilledNum=v;
	}
	INT32 GetKilledNum()
	{
		return m_KilledNum;
	}
	INT32 GetKilledNum() const
	{
		return m_KilledNum;
	}
private:
	//死亡次数
	INT32 m_DeadTimes;
public:
	void SetDeadTimes( INT32 v)
	{
		m_DeadTimes=v;
	}
	INT32 GetDeadTimes()
	{
		return m_DeadTimes;
	}
	INT32 GetDeadTimes() const
	{
		return m_DeadTimes;
	}
private:
	//名字
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
	//放旗数
	INT32 m_FlagTimes;
public:
	void SetFlagTimes( INT32 v)
	{
		m_FlagTimes=v;
	}
	INT32 GetFlagTimes()
	{
		return m_FlagTimes;
	}
	INT32 GetFlagTimes() const
	{
		return m_FlagTimes;
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
	//总输出伤害
	INT64 m_OutputDamage;
public:
	void SetOutputDamage( INT64 v)
	{
		m_OutputDamage=v;
	}
	INT64 GetOutputDamage()
	{
		return m_OutputDamage;
	}
	INT64 GetOutputDamage() const
	{
		return m_OutputDamage;
	}
private:
	//承受伤害
	INT64 m_EndureDamage;
public:
	void SetEndureDamage( INT64 v)
	{
		m_EndureDamage=v;
	}
	INT64 GetEndureDamage()
	{
		return m_EndureDamage;
	}
	INT64 GetEndureDamage() const
	{
		return m_EndureDamage;
	}
private:
	//总治疗量
	INT64 m_TreatDamage;
public:
	void SetTreatDamage( INT64 v)
	{
		m_TreatDamage=v;
	}
	INT64 GetTreatDamage()
	{
		return m_TreatDamage;
	}
	INT64 GetTreatDamage() const
	{
		return m_TreatDamage;
	}
private:
	//玩家ObjId
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}

};
//暴风阵营结果统计信息封装类
class FightStormCampInfoWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightStormCampInfoWraper()
	{
		
		m_CampId = -1;
		m_TotalNum = -1;

	}
	//赋值构造函数
	FightStormCampInfoWraper(const FightStormCampInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const FightStormCampInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightStormCampInfo ToPB() const
	{
		FightStormCampInfo v;
		v.mutable_playerarr()->Reserve(m_PlayerArr.size());
		for (int i=0; i<(int)m_PlayerArr.size(); i++)
		{
			*v.add_playerarr() = m_PlayerArr[i].ToPB();
		}
		v.set_campid( m_CampId );
		v.set_totalnum( m_TotalNum );

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
		FightStormCampInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>PlayerArr(成员信息) [StormPlayerInfo] Array</li>\r\n";
		htmlBuff += "<li>CampId(阵营ID) [sint32]</li>\r\n";
		htmlBuff += "<li>TotalNum(资源总量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>PlayerArr：</li>\r\n";
		if( m_PlayerArr.size()>0) htmlBuff += m_PlayerArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_PlayerArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_PlayerArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>CampId：%di</li>\r\n",m_CampId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TotalNum：%di</li>\r\n",m_TotalNum);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightStormCampInfo& v)
	{
		m_PlayerArr.clear();
		m_PlayerArr.reserve(v.playerarr_size());
		for( int i=0; i<v.playerarr_size(); i++)
			m_PlayerArr.push_back(v.playerarr(i));
		m_CampId = v.campid();
		m_TotalNum = v.totalnum();

	}

private:
	//成员信息
	vector<FightStormPlayerInfoWraper> m_PlayerArr;
public:
	int SizePlayerArr()
	{
		return m_PlayerArr.size();
	}
	const vector<FightStormPlayerInfoWraper>& GetPlayerArr() const
	{
		return m_PlayerArr;
	}
	FightStormPlayerInfoWraper GetPlayerArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_PlayerArr.size())
		{
			assert(false);
			return FightStormPlayerInfoWraper();
		}
		return m_PlayerArr[Index];
	}
	void SetPlayerArr( const vector<FightStormPlayerInfoWraper>& v )
	{
		m_PlayerArr=v;
	}
	void ClearPlayerArr( )
	{
		m_PlayerArr.clear();
	}
	void SetPlayerArr( int Index, const FightStormPlayerInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_PlayerArr.size())
		{
			assert(false);
			return;
		}
		m_PlayerArr[Index] = v;
	}
	void AddPlayerArr( const FightStormPlayerInfoWraper& v )
	{
		m_PlayerArr.push_back(v);
	}
private:
	//阵营ID
	INT32 m_CampId;
public:
	void SetCampId( INT32 v)
	{
		m_CampId=v;
	}
	INT32 GetCampId()
	{
		return m_CampId;
	}
	INT32 GetCampId() const
	{
		return m_CampId;
	}
private:
	//资源总量
	INT32 m_TotalNum;
public:
	void SetTotalNum( INT32 v)
	{
		m_TotalNum=v;
	}
	INT32 GetTotalNum()
	{
		return m_TotalNum;
	}
	INT32 GetTotalNum() const
	{
		return m_TotalNum;
	}

};
//攻击目标信息封装类
class FightHitTargetInfoWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightHitTargetInfoWraper()
	{
		
		m_ObjId = -1;
		m_PosInfo = "";
		m_Flag = 0;
		m_EnemyIndex = -1;

	}
	//赋值构造函数
	FightHitTargetInfoWraper(const FightHitTargetInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const FightHitTargetInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightHitTargetInfo ToPB() const
	{
		FightHitTargetInfo v;
		v.set_objid( m_ObjId );
		v.set_posinfo( m_PosInfo );
		v.set_flag( m_Flag );
		v.set_enemyindex( m_EnemyIndex );

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
		FightHitTargetInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(ObjId) [sint32]</li>\r\n";
		htmlBuff += "<li>PosInfo(位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>Flag(标记) [sint32]</li>\r\n";
		htmlBuff += "<li>EnemyIndex(本次攻击敌人计数) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PosInfo：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>Flag：%di</li>\r\n",m_Flag);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EnemyIndex：%di</li>\r\n",m_EnemyIndex);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightHitTargetInfo& v)
	{
		m_ObjId = v.objid();
		m_PosInfo = v.posinfo();
		m_Flag = v.flag();
		m_EnemyIndex = v.enemyindex();

	}

private:
	//ObjId
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//位置信息
	string m_PosInfo;
public:
	void SetPosInfo( const string& v)
	{
		m_PosInfo=v;
	}
	string GetPosInfo()
	{
		return m_PosInfo;
	}
	string GetPosInfo() const
	{
		return m_PosInfo;
	}
private:
	//标记
	INT32 m_Flag;
public:
	void SetFlag( INT32 v)
	{
		m_Flag=v;
	}
	INT32 GetFlag()
	{
		return m_Flag;
	}
	INT32 GetFlag() const
	{
		return m_Flag;
	}
private:
	//本次攻击敌人计数
	INT32 m_EnemyIndex;
public:
	void SetEnemyIndex( INT32 v)
	{
		m_EnemyIndex=v;
	}
	INT32 GetEnemyIndex()
	{
		return m_EnemyIndex;
	}
	INT32 GetEnemyIndex() const
	{
		return m_EnemyIndex;
	}

};
//帮会副本结束封装类
class FightGuildDEndActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightGuildDEndActionWraper()
	{
		
		m_Time = -1;

	}
	//赋值构造函数
	FightGuildDEndActionWraper(const FightGuildDEndAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightGuildDEndAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightGuildDEndAction ToPB() const
	{
		FightGuildDEndAction v;
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
		FightGuildDEndAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Time(剩余时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightGuildDEndAction& v)
	{
		m_Time = v.time();

	}

private:
	//剩余时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}

};
//帮会战开始封装类
class FightGuildFightBeginActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightGuildFightBeginActionWraper()
	{
		
		m_Type = -1;
		m_Time = -1;

	}
	//赋值构造函数
	FightGuildFightBeginActionWraper(const FightGuildFightBeginAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightGuildFightBeginAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightGuildFightBeginAction ToPB() const
	{
		FightGuildFightBeginAction v;
		v.set_type( m_Type );
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
		FightGuildFightBeginAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(剩余时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightGuildFightBeginAction& v)
	{
		m_Type = v.type();
		m_Time = v.time();

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
	//剩余时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}

};
//帮会战结束封装类
class FightGuildFightEndActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightGuildFightEndActionWraper()
	{
		
		m_Time = -1;
		m_VictoryCampId = -1;

	}
	//赋值构造函数
	FightGuildFightEndActionWraper(const FightGuildFightEndAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightGuildFightEndAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightGuildFightEndAction ToPB() const
	{
		FightGuildFightEndAction v;
		v.set_time( m_Time );
		v.set_victorycampid( m_VictoryCampId );

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
		FightGuildFightEndAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Time(剩余时间) [sint32]</li>\r\n";
		htmlBuff += "<li>VictoryCampId(胜利阵营) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>VictoryCampId：%di</li>\r\n",m_VictoryCampId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightGuildFightEndAction& v)
	{
		m_Time = v.time();
		m_VictoryCampId = v.victorycampid();

	}

private:
	//剩余时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}
private:
	//胜利阵营
	INT32 m_VictoryCampId;
public:
	void SetVictoryCampId( INT32 v)
	{
		m_VictoryCampId=v;
	}
	INT32 GetVictoryCampId()
	{
		return m_VictoryCampId;
	}
	INT32 GetVictoryCampId() const
	{
		return m_VictoryCampId;
	}

};
//场景间传送封装类
class FightTransferActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightTransferActionWraper()
	{
		
		m_DungeonId = -1;
		m_DungeonType = -1;
		m_BirthPoint = -1;
		m_FaceDir = 0;

	}
	//赋值构造函数
	FightTransferActionWraper(const FightTransferAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightTransferAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightTransferAction ToPB() const
	{
		FightTransferAction v;
		v.set_dungeonid( m_DungeonId );
		v.set_dungeontype( m_DungeonType );
		v.set_birthpoint( m_BirthPoint );
		v.set_facedir( m_FaceDir );

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
		FightTransferAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DungeonId(场景ID) [sint32]</li>\r\n";
		htmlBuff += "<li>DungeonType(场景类型) [sint32]</li>\r\n";
		htmlBuff += "<li>BirthPoint(出生点) [sint32]</li>\r\n";
		htmlBuff += "<li>FaceDir(朝向) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>DungeonId：%di</li>\r\n",m_DungeonId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DungeonType：%di</li>\r\n",m_DungeonType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BirthPoint：%di</li>\r\n",m_BirthPoint);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>FaceDir：%di</li>\r\n",m_FaceDir);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightTransferAction& v)
	{
		m_DungeonId = v.dungeonid();
		m_DungeonType = v.dungeontype();
		m_BirthPoint = v.birthpoint();
		m_FaceDir = v.facedir();

	}

private:
	//场景ID
	INT32 m_DungeonId;
public:
	void SetDungeonId( INT32 v)
	{
		m_DungeonId=v;
	}
	INT32 GetDungeonId()
	{
		return m_DungeonId;
	}
	INT32 GetDungeonId() const
	{
		return m_DungeonId;
	}
private:
	//场景类型
	INT32 m_DungeonType;
public:
	void SetDungeonType( INT32 v)
	{
		m_DungeonType=v;
	}
	INT32 GetDungeonType()
	{
		return m_DungeonType;
	}
	INT32 GetDungeonType() const
	{
		return m_DungeonType;
	}
private:
	//出生点
	INT32 m_BirthPoint;
public:
	void SetBirthPoint( INT32 v)
	{
		m_BirthPoint=v;
	}
	INT32 GetBirthPoint()
	{
		return m_BirthPoint;
	}
	INT32 GetBirthPoint() const
	{
		return m_BirthPoint;
	}
private:
	//朝向
	INT32 m_FaceDir;
public:
	void SetFaceDir( INT32 v)
	{
		m_FaceDir=v;
	}
	INT32 GetFaceDir()
	{
		return m_FaceDir;
	}
	INT32 GetFaceDir() const
	{
		return m_FaceDir;
	}

};
//英雄战斗信息封装类
class FightHeroFightInfoActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightHeroFightInfoActionWraper()
	{
		
		m_FunctionId = -1;
		m_MyCampId = -1;

	}
	//赋值构造函数
	FightHeroFightInfoActionWraper(const FightHeroFightInfoAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightHeroFightInfoAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightHeroFightInfoAction ToPB() const
	{
		FightHeroFightInfoAction v;
		v.mutable_heroinfoarr()->Reserve(m_HeroInfoArr.size());
		for (int i=0; i<(int)m_HeroInfoArr.size(); i++)
		{
			*v.add_heroinfoarr() = m_HeroInfoArr[i].ToPB();
		}
		v.set_functionid( m_FunctionId );
		v.set_mycampid( m_MyCampId );

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
		FightHeroFightInfoAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>HeroInfoArr(英雄信息列表) [HeroFightInfo] Array</li>\r\n";
		htmlBuff += "<li>FunctionId(副本功能类型) [sint32]</li>\r\n";
		htmlBuff += "<li>MyCampId(自己的阵营ID) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>HeroInfoArr：</li>\r\n";
		if( m_HeroInfoArr.size()>0) htmlBuff += m_HeroInfoArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_HeroInfoArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_HeroInfoArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>FunctionId：%di</li>\r\n",m_FunctionId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MyCampId：%di</li>\r\n",m_MyCampId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightHeroFightInfoAction& v)
	{
		m_HeroInfoArr.clear();
		m_HeroInfoArr.reserve(v.heroinfoarr_size());
		for( int i=0; i<v.heroinfoarr_size(); i++)
			m_HeroInfoArr.push_back(v.heroinfoarr(i));
		m_FunctionId = v.functionid();
		m_MyCampId = v.mycampid();

	}

private:
	//英雄信息列表
	vector<HeroFightInfoWraper> m_HeroInfoArr;
public:
	int SizeHeroInfoArr()
	{
		return m_HeroInfoArr.size();
	}
	const vector<HeroFightInfoWraper>& GetHeroInfoArr() const
	{
		return m_HeroInfoArr;
	}
	HeroFightInfoWraper GetHeroInfoArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_HeroInfoArr.size())
		{
			assert(false);
			return HeroFightInfoWraper();
		}
		return m_HeroInfoArr[Index];
	}
	void SetHeroInfoArr( const vector<HeroFightInfoWraper>& v )
	{
		m_HeroInfoArr=v;
	}
	void ClearHeroInfoArr( )
	{
		m_HeroInfoArr.clear();
	}
	void SetHeroInfoArr( int Index, const HeroFightInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_HeroInfoArr.size())
		{
			assert(false);
			return;
		}
		m_HeroInfoArr[Index] = v;
	}
	void AddHeroInfoArr( const HeroFightInfoWraper& v )
	{
		m_HeroInfoArr.push_back(v);
	}
private:
	//副本功能类型
	INT32 m_FunctionId;
public:
	void SetFunctionId( INT32 v)
	{
		m_FunctionId=v;
	}
	INT32 GetFunctionId()
	{
		return m_FunctionId;
	}
	INT32 GetFunctionId() const
	{
		return m_FunctionId;
	}
private:
	//自己的阵营ID
	INT32 m_MyCampId;
public:
	void SetMyCampId( INT32 v)
	{
		m_MyCampId=v;
	}
	INT32 GetMyCampId()
	{
		return m_MyCampId;
	}
	INT32 GetMyCampId() const
	{
		return m_MyCampId;
	}

};
//大逃杀结果封装类
class FightEscapeResultActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightEscapeResultActionWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	FightEscapeResultActionWraper(const FightEscapeResultAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightEscapeResultAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightEscapeResultAction ToPB() const
	{
		FightEscapeResultAction v;
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
		FightEscapeResultAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(结果) [sint32]</li>\r\n";

		
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
	void Init(const FightEscapeResultAction& v)
	{
		m_Result = v.result();

	}

private:
	//结果
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
//大逃杀开始封装类
class FightEscapeStartActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightEscapeStartActionWraper()
	{
		
		m_Type = -1;
		m_Time = -1;

	}
	//赋值构造函数
	FightEscapeStartActionWraper(const FightEscapeStartAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightEscapeStartAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightEscapeStartAction ToPB() const
	{
		FightEscapeStartAction v;
		v.set_type( m_Type );
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
		FightEscapeStartAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(倒计时或剩余时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightEscapeStartAction& v)
	{
		m_Type = v.type();
		m_Time = v.time();

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
	//倒计时或剩余时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}

};
//暴风战斗开始封装类
class FightStormStartActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightStormStartActionWraper()
	{
		
		m_Type = -1;
		m_Time = -1;

	}
	//赋值构造函数
	FightStormStartActionWraper(const FightStormStartAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightStormStartAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightStormStartAction ToPB() const
	{
		FightStormStartAction v;
		v.set_type( m_Type );
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
		FightStormStartAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(倒计时或剩余时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightStormStartAction& v)
	{
		m_Type = v.type();
		m_Time = v.time();

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
	//倒计时或剩余时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}

};
//帮会副本开始封装类
class FightGuildDBeginActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightGuildDBeginActionWraper()
	{
		
		m_Type = -1;
		m_Time = -1;

	}
	//赋值构造函数
	FightGuildDBeginActionWraper(const FightGuildDBeginAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightGuildDBeginAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightGuildDBeginAction ToPB() const
	{
		FightGuildDBeginAction v;
		v.set_type( m_Type );
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
		FightGuildDBeginAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(剩余时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightGuildDBeginAction& v)
	{
		m_Type = v.type();
		m_Time = v.time();

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
	//剩余时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}

};
//所有人随机放技能封装类
class FightTRandSkillActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightTRandSkillActionWraper()
	{
		

	}
	//赋值构造函数
	FightTRandSkillActionWraper(const FightTRandSkillAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightTRandSkillAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightTRandSkillAction ToPB() const
	{
		FightTRandSkillAction v;

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
		FightTRandSkillAction pb;
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
	void Init(const FightTRandSkillAction& v)
	{

	}


};
//GM加减血量封装类
class FightGMAddHpActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightGMAddHpActionWraper()
	{
		
		m_ObjId = -1;
		m_AddNum = -1;

	}
	//赋值构造函数
	FightGMAddHpActionWraper(const FightGMAddHpAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightGMAddHpAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightGMAddHpAction ToPB() const
	{
		FightGMAddHpAction v;
		v.set_objid( m_ObjId );
		v.set_addnum( m_AddNum );

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
		FightGMAddHpAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(对像ID) [sint32]</li>\r\n";
		htmlBuff += "<li>AddNum(加血量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AddNum：%di</li>\r\n",m_AddNum);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightGMAddHpAction& v)
	{
		m_ObjId = v.objid();
		m_AddNum = v.addnum();

	}

private:
	//对像ID
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//加血量
	INT32 m_AddNum;
public:
	void SetAddNum( INT32 v)
	{
		m_AddNum=v;
	}
	INT32 GetAddNum()
	{
		return m_AddNum;
	}
	INT32 GetAddNum() const
	{
		return m_AddNum;
	}

};
//帮会战阵营血量信息封装类
class FightGuildFightHpActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightGuildFightHpActionWraper()
	{
		
		m_CampId = -1;
		m_MaxHp = 0;
		m_CurHp = 0;

	}
	//赋值构造函数
	FightGuildFightHpActionWraper(const FightGuildFightHpAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightGuildFightHpAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightGuildFightHpAction ToPB() const
	{
		FightGuildFightHpAction v;
		v.set_campid( m_CampId );
		v.set_maxhp( m_MaxHp );
		v.set_curhp( m_CurHp );

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
		FightGuildFightHpAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>CampId(阵营ID) [sint32]</li>\r\n";
		htmlBuff += "<li>MaxHp(最大血量) [sint32]</li>\r\n";
		htmlBuff += "<li>CurHp(当前血量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>CampId：%di</li>\r\n",m_CampId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MaxHp：%di</li>\r\n",m_MaxHp);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CurHp：%di</li>\r\n",m_CurHp);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightGuildFightHpAction& v)
	{
		m_CampId = v.campid();
		m_MaxHp = v.maxhp();
		m_CurHp = v.curhp();

	}

private:
	//阵营ID
	INT32 m_CampId;
public:
	void SetCampId( INT32 v)
	{
		m_CampId=v;
	}
	INT32 GetCampId()
	{
		return m_CampId;
	}
	INT32 GetCampId() const
	{
		return m_CampId;
	}
private:
	//最大血量
	INT32 m_MaxHp;
public:
	void SetMaxHp( INT32 v)
	{
		m_MaxHp=v;
	}
	INT32 GetMaxHp()
	{
		return m_MaxHp;
	}
	INT32 GetMaxHp() const
	{
		return m_MaxHp;
	}
private:
	//当前血量
	INT32 m_CurHp;
public:
	void SetCurHp( INT32 v)
	{
		m_CurHp=v;
	}
	INT32 GetCurHp()
	{
		return m_CurHp;
	}
	INT32 GetCurHp() const
	{
		return m_CurHp;
	}

};
//事件触发封装类
class FightEventTriggerActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightEventTriggerActionWraper()
	{
		
		m_EventId = -1;

	}
	//赋值构造函数
	FightEventTriggerActionWraper(const FightEventTriggerAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightEventTriggerAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightEventTriggerAction ToPB() const
	{
		FightEventTriggerAction v;
		v.set_eventid( m_EventId );

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
		FightEventTriggerAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>EventId(事件配置Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>EventId：%di</li>\r\n",m_EventId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightEventTriggerAction& v)
	{
		m_EventId = v.eventid();

	}

private:
	//事件配置Id
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

};
//视野变化封装类
class FightSightActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightSightActionWraper()
	{
		

	}
	//赋值构造函数
	FightSightActionWraper(const FightSightAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightSightAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightSightAction ToPB() const
	{
		FightSightAction v;
		v.mutable_actionarr()->Reserve(m_ActionArr.size());
		for (int i=0; i<(int)m_ActionArr.size(); i++)
		{
			v.add_actionarr( m_ActionArr[i]);
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
		FightSightAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ActionArr(创建的Action列表) [bytes] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ActionArr(创建的Action列表) [bytes]：</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightSightAction& v)
	{
		m_ActionArr.clear();
		m_ActionArr.reserve(v.actionarr_size());
		for( int i=0; i<v.actionarr_size(); i++)
			m_ActionArr.push_back(v.actionarr(i));

	}

private:
	//创建的Action列表
	vector<string> m_ActionArr;
public:
	int SizeActionArr()
	{
		return m_ActionArr.size();
	}
	const vector<string>& GetActionArr() const
	{
		return m_ActionArr;
	}
	string GetActionArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_ActionArr.size())
		{
			assert(false);
			return string();
		}
		return m_ActionArr[Index];
	}
	void SetActionArr( const vector<string>& v )
	{
		m_ActionArr=v;
	}
	void ClearActionArr( )
	{
		m_ActionArr.clear();
	}
	void SetActionArr( int Index, const string& v )
	{
		if(Index<0 || Index>=(int)m_ActionArr.size())
		{
			assert(false);
			return;
		}
		m_ActionArr[Index] = v;
	}
	void AddActionArr( const string& v )
	{
		m_ActionArr.push_back(v);
	}

};
//1V1结果封装类
class FightOneVSOneResultActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightOneVSOneResultActionWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	FightOneVSOneResultActionWraper(const FightOneVSOneResultAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightOneVSOneResultAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightOneVSOneResultAction ToPB() const
	{
		FightOneVSOneResultAction v;
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
		FightOneVSOneResultAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(结果) [sint32]</li>\r\n";

		
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
	void Init(const FightOneVSOneResultAction& v)
	{
		m_Result = v.result();

	}

private:
	//结果
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
//开始结束封装类
class FightStartEndActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightStartEndActionWraper()
	{
		
		m_Type = 0;
		m_Time = 0;

	}
	//赋值构造函数
	FightStartEndActionWraper(const FightStartEndAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightStartEndAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightStartEndAction ToPB() const
	{
		FightStartEndAction v;
		v.set_type( m_Type );
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
		FightStartEndAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(0:开始, 1:结束) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(秒时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightStartEndAction& v)
	{
		m_Type = v.type();
		m_Time = v.time();

	}

private:
	//0:开始, 1:结束
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
	//秒时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}

};
//生产封装类
class FightProductActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightProductActionWraper()
	{
		
		m_Status = -1;
		m_LifeSkillId = -1;
		m_Player_ObjId = -1;
		m_ProductionId = -1;

	}
	//赋值构造函数
	FightProductActionWraper(const FightProductAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightProductAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightProductAction ToPB() const
	{
		FightProductAction v;
		v.set_status( m_Status );
		v.set_lifeskillid( m_LifeSkillId );
		v.set_player_objid( m_Player_ObjId );
		v.set_productionid( m_ProductionId );

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
		FightProductAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Status(1是开始,2是结束,3是中断) [sint32]</li>\r\n";
		htmlBuff += "<li>LifeSkillId(生活技能表ID) [sint32]</li>\r\n";
		htmlBuff += "<li>Player_ObjId(玩家的ObjId) [sint32]</li>\r\n";
		htmlBuff += "<li>ProductionId(产出物品id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Status：%di</li>\r\n",m_Status);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>LifeSkillId：%di</li>\r\n",m_LifeSkillId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Player_ObjId：%di</li>\r\n",m_Player_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ProductionId：%di</li>\r\n",m_ProductionId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightProductAction& v)
	{
		m_Status = v.status();
		m_LifeSkillId = v.lifeskillid();
		m_Player_ObjId = v.player_objid();
		m_ProductionId = v.productionid();

	}

private:
	//1是开始,2是结束,3是中断
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}
private:
	//生活技能表ID
	INT32 m_LifeSkillId;
public:
	void SetLifeSkillId( INT32 v)
	{
		m_LifeSkillId=v;
	}
	INT32 GetLifeSkillId()
	{
		return m_LifeSkillId;
	}
	INT32 GetLifeSkillId() const
	{
		return m_LifeSkillId;
	}
private:
	//玩家的ObjId
	INT32 m_Player_ObjId;
public:
	void SetPlayer_ObjId( INT32 v)
	{
		m_Player_ObjId=v;
	}
	INT32 GetPlayer_ObjId()
	{
		return m_Player_ObjId;
	}
	INT32 GetPlayer_ObjId() const
	{
		return m_Player_ObjId;
	}
private:
	//产出物品id
	INT32 m_ProductionId;
public:
	void SetProductionId( INT32 v)
	{
		m_ProductionId=v;
	}
	INT32 GetProductionId()
	{
		return m_ProductionId;
	}
	INT32 GetProductionId() const
	{
		return m_ProductionId;
	}

};
//QuitAction封装类
class FightQuitActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightQuitActionWraper()
	{
		
		m_Type = 0;

	}
	//赋值构造函数
	FightQuitActionWraper(const FightQuitAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightQuitAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightQuitAction ToPB() const
	{
		FightQuitAction v;
		v.set_type( m_Type );

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
		FightQuitAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(type类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightQuitAction& v)
	{
		m_Type = v.type();

	}

private:
	//type类型
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

};
//1V1开始封装类
class FightOneVSOneStartActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightOneVSOneStartActionWraper()
	{
		
		m_Type = -1;
		m_Time = -1;

	}
	//赋值构造函数
	FightOneVSOneStartActionWraper(const FightOneVSOneStartAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightOneVSOneStartAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightOneVSOneStartAction ToPB() const
	{
		FightOneVSOneStartAction v;
		v.set_type( m_Type );
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
		FightOneVSOneStartAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(倒计时或剩余时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightOneVSOneStartAction& v)
	{
		m_Type = v.type();
		m_Time = v.time();

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
	//倒计时或剩余时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}

};
//采集物是否播特效封装类
class FightCollectionShowEffectActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightCollectionShowEffectActionWraper()
	{
		
		m_ObjId = -1;
		m_IsShowEffect = false;

	}
	//赋值构造函数
	FightCollectionShowEffectActionWraper(const FightCollectionShowEffectAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightCollectionShowEffectAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightCollectionShowEffectAction ToPB() const
	{
		FightCollectionShowEffectAction v;
		v.set_objid( m_ObjId );
		v.set_isshoweffect( m_IsShowEffect );

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
		FightCollectionShowEffectAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(内核中用到的对像ID) [sint32]</li>\r\n";
		htmlBuff += "<li>IsShowEffect(是否显示特效) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsShowEffect：%di</li>\r\n",m_IsShowEffect);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightCollectionShowEffectAction& v)
	{
		m_ObjId = v.objid();
		m_IsShowEffect = v.isshoweffect();

	}

private:
	//内核中用到的对像ID
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//是否显示特效
	bool m_IsShowEffect;
public:
	void SetIsShowEffect( bool v)
	{
		m_IsShowEffect=v;
	}
	bool GetIsShowEffect()
	{
		return m_IsShowEffect;
	}
	bool GetIsShowEffect() const
	{
		return m_IsShowEffect;
	}

};
//采集封装类
class FightCollectActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightCollectActionWraper()
	{
		
		m_Status = 1;
		m_Player_ObjId = -1;
		m_Collection_ObjId = -1;

	}
	//赋值构造函数
	FightCollectActionWraper(const FightCollectAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightCollectAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightCollectAction ToPB() const
	{
		FightCollectAction v;
		v.set_status( m_Status );
		v.set_player_objid( m_Player_ObjId );
		v.set_collection_objid( m_Collection_ObjId );

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
		FightCollectAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Status(1是开始,2是结束,3是中断) [sint32]</li>\r\n";
		htmlBuff += "<li>Player_ObjId(玩家的ObjId) [sint32]</li>\r\n";
		htmlBuff += "<li>Collection_ObjId(采集物品的ObjId) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Status：%di</li>\r\n",m_Status);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Player_ObjId：%di</li>\r\n",m_Player_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Collection_ObjId：%di</li>\r\n",m_Collection_ObjId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightCollectAction& v)
	{
		m_Status = v.status();
		m_Player_ObjId = v.player_objid();
		m_Collection_ObjId = v.collection_objid();

	}

private:
	//1是开始,2是结束,3是中断
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}
private:
	//玩家的ObjId
	INT32 m_Player_ObjId;
public:
	void SetPlayer_ObjId( INT32 v)
	{
		m_Player_ObjId=v;
	}
	INT32 GetPlayer_ObjId()
	{
		return m_Player_ObjId;
	}
	INT32 GetPlayer_ObjId() const
	{
		return m_Player_ObjId;
	}
private:
	//采集物品的ObjId
	INT32 m_Collection_ObjId;
public:
	void SetCollection_ObjId( INT32 v)
	{
		m_Collection_ObjId=v;
	}
	INT32 GetCollection_ObjId()
	{
		return m_Collection_ObjId;
	}
	INT32 GetCollection_ObjId() const
	{
		return m_Collection_ObjId;
	}

};
//移动控制动作封装类
class FightEffectTranslateActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightEffectTranslateActionWraper()
	{
		
		m_ObjId = -1;
		m_ObjType = -1;
		m_TargetObjId = -1;
		m_TargetPos = "";
		m_Angle = -1;
		m_Speed = -1;
		m_Distance = -1;
		m_PosInfo = "";
		m_Status = 0;
		m_SkillId = -1;
		m_SegementIndex = -1;
		m_SpriteName = "";
		m_BulletType = -1;
		m_IsIrregularityEffect = false;
		m_TranslateType = 0;
		m_Time = -1;

	}
	//赋值构造函数
	FightEffectTranslateActionWraper(const FightEffectTranslateAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightEffectTranslateAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightEffectTranslateAction ToPB() const
	{
		FightEffectTranslateAction v;
		v.set_objid( m_ObjId );
		v.set_objtype( m_ObjType );
		v.set_targetobjid( m_TargetObjId );
		v.set_targetpos( m_TargetPos );
		v.set_angle( m_Angle );
		v.set_speed( m_Speed );
		v.set_distance( m_Distance );
		v.set_posinfo( m_PosInfo );
		v.set_status( m_Status );
		v.set_skillid( m_SkillId );
		v.set_segementindex( m_SegementIndex );
		v.set_spritename( m_SpriteName );
		v.set_bullettype( m_BulletType );
		v.set_isirregularityeffect( m_IsIrregularityEffect );
		v.set_translatetype( m_TranslateType );
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
		FightEffectTranslateAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(对像ID) [sint32]</li>\r\n";
		htmlBuff += "<li>ObjType(对像类型) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetObjId(目标对像ID) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetPos(目标位置) [bytes]</li>\r\n";
		htmlBuff += "<li>Angle(方向角) [sint32]</li>\r\n";
		htmlBuff += "<li>Speed(速度) [sint32]</li>\r\n";
		htmlBuff += "<li>Distance(距离) [sint32]</li>\r\n";
		htmlBuff += "<li>PosInfo(对像自身位置) [bytes]</li>\r\n";
		htmlBuff += "<li>Status(状态) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillId(SkillId) [sint32]</li>\r\n";
		htmlBuff += "<li>SegementIndex(技能段索引) [sint32]</li>\r\n";
		htmlBuff += "<li>SpriteName(spriteName) [string]</li>\r\n";
		htmlBuff += "<li>BulletType(子弹类型) [sint32]</li>\r\n";
		htmlBuff += "<li>IsIrregularityEffect(IsIrregularityEffect) [bool]</li>\r\n";
		htmlBuff += "<li>TranslateType(TranslateType) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(Time) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ObjType：%di</li>\r\n",m_ObjType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetObjId：%di</li>\r\n",m_TargetObjId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>TargetPos：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>Angle：%di</li>\r\n",m_Angle);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Speed：%di</li>\r\n",m_Speed);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Distance：%di</li>\r\n",m_Distance);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PosInfo：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>Status：%di</li>\r\n",m_Status);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SegementIndex：%di</li>\r\n",m_SegementIndex);
		htmlBuff += tmpLine;
		htmlBuff += "<li>SpriteName：\""+m_SpriteName+"\"</li>\r\n";
		tmpLine.Fmt("<li>BulletType：%di</li>\r\n",m_BulletType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsIrregularityEffect：%di</li>\r\n",m_IsIrregularityEffect);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TranslateType：%di</li>\r\n",m_TranslateType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%.2ff</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightEffectTranslateAction& v)
	{
		m_ObjId = v.objid();
		m_ObjType = v.objtype();
		m_TargetObjId = v.targetobjid();
		m_TargetPos = v.targetpos();
		m_Angle = v.angle();
		m_Speed = v.speed();
		m_Distance = v.distance();
		m_PosInfo = v.posinfo();
		m_Status = v.status();
		m_SkillId = v.skillid();
		m_SegementIndex = v.segementindex();
		m_SpriteName = v.spritename();
		m_BulletType = v.bullettype();
		m_IsIrregularityEffect = v.isirregularityeffect();
		m_TranslateType = v.translatetype();
		m_Time = v.time();

	}

private:
	//对像ID
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//对像类型
	INT32 m_ObjType;
public:
	void SetObjType( INT32 v)
	{
		m_ObjType=v;
	}
	INT32 GetObjType()
	{
		return m_ObjType;
	}
	INT32 GetObjType() const
	{
		return m_ObjType;
	}
private:
	//目标对像ID
	INT32 m_TargetObjId;
public:
	void SetTargetObjId( INT32 v)
	{
		m_TargetObjId=v;
	}
	INT32 GetTargetObjId()
	{
		return m_TargetObjId;
	}
	INT32 GetTargetObjId() const
	{
		return m_TargetObjId;
	}
private:
	//目标位置
	string m_TargetPos;
public:
	void SetTargetPos( const string& v)
	{
		m_TargetPos=v;
	}
	string GetTargetPos()
	{
		return m_TargetPos;
	}
	string GetTargetPos() const
	{
		return m_TargetPos;
	}
private:
	//方向角
	INT32 m_Angle;
public:
	void SetAngle( INT32 v)
	{
		m_Angle=v;
	}
	INT32 GetAngle()
	{
		return m_Angle;
	}
	INT32 GetAngle() const
	{
		return m_Angle;
	}
private:
	//速度
	INT32 m_Speed;
public:
	void SetSpeed( INT32 v)
	{
		m_Speed=v;
	}
	INT32 GetSpeed()
	{
		return m_Speed;
	}
	INT32 GetSpeed() const
	{
		return m_Speed;
	}
private:
	//距离
	INT32 m_Distance;
public:
	void SetDistance( INT32 v)
	{
		m_Distance=v;
	}
	INT32 GetDistance()
	{
		return m_Distance;
	}
	INT32 GetDistance() const
	{
		return m_Distance;
	}
private:
	//对像自身位置
	string m_PosInfo;
public:
	void SetPosInfo( const string& v)
	{
		m_PosInfo=v;
	}
	string GetPosInfo()
	{
		return m_PosInfo;
	}
	string GetPosInfo() const
	{
		return m_PosInfo;
	}
private:
	//状态
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}
private:
	//SkillId
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
	//技能段索引
	INT32 m_SegementIndex;
public:
	void SetSegementIndex( INT32 v)
	{
		m_SegementIndex=v;
	}
	INT32 GetSegementIndex()
	{
		return m_SegementIndex;
	}
	INT32 GetSegementIndex() const
	{
		return m_SegementIndex;
	}
private:
	//spriteName
	string m_SpriteName;
public:
	void SetSpriteName( const string& v)
	{
		m_SpriteName=v;
	}
	string GetSpriteName()
	{
		return m_SpriteName;
	}
	string GetSpriteName() const
	{
		return m_SpriteName;
	}
private:
	//子弹类型
	INT32 m_BulletType;
public:
	void SetBulletType( INT32 v)
	{
		m_BulletType=v;
	}
	INT32 GetBulletType()
	{
		return m_BulletType;
	}
	INT32 GetBulletType() const
	{
		return m_BulletType;
	}
private:
	//IsIrregularityEffect
	bool m_IsIrregularityEffect;
public:
	void SetIsIrregularityEffect( bool v)
	{
		m_IsIrregularityEffect=v;
	}
	bool GetIsIrregularityEffect()
	{
		return m_IsIrregularityEffect;
	}
	bool GetIsIrregularityEffect() const
	{
		return m_IsIrregularityEffect;
	}
private:
	//TranslateType
	INT32 m_TranslateType;
public:
	void SetTranslateType( INT32 v)
	{
		m_TranslateType=v;
	}
	INT32 GetTranslateType()
	{
		return m_TranslateType;
	}
	INT32 GetTranslateType() const
	{
		return m_TranslateType;
	}
private:
	//Time
	float m_Time;
public:
	void SetTime( float v)
	{
		m_Time=v;
	}
	float GetTime()
	{
		return m_Time;
	}
	float GetTime() const
	{
		return m_Time;
	}

};
//五行旗杀人特效封装类
class FightStormKillEffectActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightStormKillEffectActionWraper()
	{
		
		m_ObjId = -1;
		m_Num = -1;

	}
	//赋值构造函数
	FightStormKillEffectActionWraper(const FightStormKillEffectAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightStormKillEffectAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightStormKillEffectAction ToPB() const
	{
		FightStormKillEffectAction v;
		v.set_objid( m_ObjId );
		v.set_num( m_Num );

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
		FightStormKillEffectAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(自己) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(杀人数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightStormKillEffectAction& v)
	{
		m_ObjId = v.objid();
		m_Num = v.num();

	}

private:
	//自己
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//杀人数量
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}

};
//使用道具封装类
class FightUseItemActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightUseItemActionWraper()
	{
		
		m_TemplateId = -1;
		m_Status = 1;
		m_Player_ObjId = -1;

	}
	//赋值构造函数
	FightUseItemActionWraper(const FightUseItemAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightUseItemAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightUseItemAction ToPB() const
	{
		FightUseItemAction v;
		v.set_templateid( m_TemplateId );
		v.set_status( m_Status );
		v.set_player_objid( m_Player_ObjId );

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
		FightUseItemAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateId(道具配置Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Status(1是开始,2是结束,3是中断) [sint32]</li>\r\n";
		htmlBuff += "<li>Player_ObjId(玩家的ObjId) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Status：%di</li>\r\n",m_Status);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Player_ObjId：%di</li>\r\n",m_Player_ObjId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightUseItemAction& v)
	{
		m_TemplateId = v.templateid();
		m_Status = v.status();
		m_Player_ObjId = v.player_objid();

	}

private:
	//道具配置Id
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//1是开始,2是结束,3是中断
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}
private:
	//玩家的ObjId
	INT32 m_Player_ObjId;
public:
	void SetPlayer_ObjId( INT32 v)
	{
		m_Player_ObjId=v;
	}
	INT32 GetPlayer_ObjId()
	{
		return m_Player_ObjId;
	}
	INT32 GetPlayer_ObjId() const
	{
		return m_Player_ObjId;
	}

};
//自动战斗封装类
class FightAutoFightActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightAutoFightActionWraper()
	{
		
		m_Type = 0;
		m_ObjId = -1;

	}
	//赋值构造函数
	FightAutoFightActionWraper(const FightAutoFightAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightAutoFightAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightAutoFightAction ToPB() const
	{
		FightAutoFightAction v;
		v.set_type( m_Type );
		v.set_objid( m_ObjId );

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
		FightAutoFightAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>ObjId(内核中用到的对像ID) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightAutoFightAction& v)
	{
		m_Type = v.type();
		m_ObjId = v.objid();

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
	//内核中用到的对像ID
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}

};
//角色复活动作封装类
class FightCharReviveActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightCharReviveActionWraper()
	{
		
		m_ObjId = -1;
		m_PosInfo = "";
		m_CurHp = 0;
		m_Type = -1;
		m_Time = -1;
		m_ManualRevive = 0;
		m_RemainTimes = -1;
		m_NeedMoney = -1;
		m_MaxHP = 0;
		m_TotalTimes = -1;

	}
	//赋值构造函数
	FightCharReviveActionWraper(const FightCharReviveAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightCharReviveAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightCharReviveAction ToPB() const
	{
		FightCharReviveAction v;
		v.set_objid( m_ObjId );
		v.set_posinfo( m_PosInfo );
		v.set_curhp( m_CurHp );
		v.set_type( m_Type );
		v.set_time( m_Time );
		v.set_manualrevive( m_ManualRevive );
		v.set_remaintimes( m_RemainTimes );
		v.set_needmoney( m_NeedMoney );
		v.set_maxhp( m_MaxHP );
		v.set_totaltimes( m_TotalTimes );

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
		FightCharReviveAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";
		htmlBuff += "<li>PosInfo(位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>CurHp(当前血量) [sint32]</li>\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(读条时间) [sint32]</li>\r\n";
		htmlBuff += "<li>ManualRevive(是否需要手动复活) [sint32]</li>\r\n";
		htmlBuff += "<li>RemainTimes(免费复活剩余次数) [sint32]</li>\r\n";
		htmlBuff += "<li>NeedMoney(需要复活的钱) [sint32]</li>\r\n";
		htmlBuff += "<li>MaxHP(最大血量) [sint32]</li>\r\n";
		htmlBuff += "<li>TotalTimes(总复活次数) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PosInfo：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>CurHp：%di</li>\r\n",m_CurHp);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ManualRevive：%di</li>\r\n",m_ManualRevive);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RemainTimes：%di</li>\r\n",m_RemainTimes);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>NeedMoney：%di</li>\r\n",m_NeedMoney);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MaxHP：%di</li>\r\n",m_MaxHP);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TotalTimes：%di</li>\r\n",m_TotalTimes);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightCharReviveAction& v)
	{
		m_ObjId = v.objid();
		m_PosInfo = v.posinfo();
		m_CurHp = v.curhp();
		m_Type = v.type();
		m_Time = v.time();
		m_ManualRevive = v.manualrevive();
		m_RemainTimes = v.remaintimes();
		m_NeedMoney = v.needmoney();
		m_MaxHP = v.maxhp();
		m_TotalTimes = v.totaltimes();

	}

private:
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//位置信息
	string m_PosInfo;
public:
	void SetPosInfo( const string& v)
	{
		m_PosInfo=v;
	}
	string GetPosInfo()
	{
		return m_PosInfo;
	}
	string GetPosInfo() const
	{
		return m_PosInfo;
	}
private:
	//当前血量
	INT32 m_CurHp;
public:
	void SetCurHp( INT32 v)
	{
		m_CurHp=v;
	}
	INT32 GetCurHp()
	{
		return m_CurHp;
	}
	INT32 GetCurHp() const
	{
		return m_CurHp;
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
	//读条时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}
private:
	//是否需要手动复活
	INT32 m_ManualRevive;
public:
	void SetManualRevive( INT32 v)
	{
		m_ManualRevive=v;
	}
	INT32 GetManualRevive()
	{
		return m_ManualRevive;
	}
	INT32 GetManualRevive() const
	{
		return m_ManualRevive;
	}
private:
	//免费复活剩余次数
	INT32 m_RemainTimes;
public:
	void SetRemainTimes( INT32 v)
	{
		m_RemainTimes=v;
	}
	INT32 GetRemainTimes()
	{
		return m_RemainTimes;
	}
	INT32 GetRemainTimes() const
	{
		return m_RemainTimes;
	}
private:
	//需要复活的钱
	INT32 m_NeedMoney;
public:
	void SetNeedMoney( INT32 v)
	{
		m_NeedMoney=v;
	}
	INT32 GetNeedMoney()
	{
		return m_NeedMoney;
	}
	INT32 GetNeedMoney() const
	{
		return m_NeedMoney;
	}
private:
	//最大血量
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
private:
	//总复活次数
	INT32 m_TotalTimes;
public:
	void SetTotalTimes( INT32 v)
	{
		m_TotalTimes=v;
	}
	INT32 GetTotalTimes()
	{
		return m_TotalTimes;
	}
	INT32 GetTotalTimes() const
	{
		return m_TotalTimes;
	}

};
//角色死亡动作封装类
class FightCharDeadActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightCharDeadActionWraper()
	{
		
		m_ObjId = -1;
		m_PosInfo = "";

	}
	//赋值构造函数
	FightCharDeadActionWraper(const FightCharDeadAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightCharDeadAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightCharDeadAction ToPB() const
	{
		FightCharDeadAction v;
		v.set_objid( m_ObjId );
		v.set_posinfo( m_PosInfo );

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
		FightCharDeadAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";
		htmlBuff += "<li>PosInfo(位置信息) [bytes]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PosInfo：\"...\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightCharDeadAction& v)
	{
		m_ObjId = v.objid();
		m_PosInfo = v.posinfo();

	}

private:
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//位置信息
	string m_PosInfo;
public:
	void SetPosInfo( const string& v)
	{
		m_PosInfo=v;
	}
	string GetPosInfo()
	{
		return m_PosInfo;
	}
	string GetPosInfo() const
	{
		return m_PosInfo;
	}

};
//状态机动作封装类
class FightStateActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightStateActionWraper()
	{
		
		m_Type = -1;
		m_ObjId = -1;
		m_PosInfo = "";
		m_TargetPos = "";
		m_IntPara = -1;
		m_LadderObjId = -1;

	}
	//赋值构造函数
	FightStateActionWraper(const FightStateAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightStateAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightStateAction ToPB() const
	{
		FightStateAction v;
		v.set_type( m_Type );
		v.set_objid( m_ObjId );
		v.set_posinfo( m_PosInfo );
		v.set_targetpos( m_TargetPos );
		v.set_intpara( m_IntPara );
		v.set_ladderobjid( m_LadderObjId );

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
		FightStateAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(状态类型) [sint32]</li>\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";
		htmlBuff += "<li>PosInfo(位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>TargetPos(目标位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>IntPara(INT参数) [sint32]</li>\r\n";
		htmlBuff += "<li>LadderObjId(梯子ObjId) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PosInfo：\"...\"</li>\r\n";
		htmlBuff += "<li>TargetPos：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>IntPara：%di</li>\r\n",m_IntPara);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>LadderObjId：%di</li>\r\n",m_LadderObjId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightStateAction& v)
	{
		m_Type = v.type();
		m_ObjId = v.objid();
		m_PosInfo = v.posinfo();
		m_TargetPos = v.targetpos();
		m_IntPara = v.intpara();
		m_LadderObjId = v.ladderobjid();

	}

private:
	//状态类型
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
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//位置信息
	string m_PosInfo;
public:
	void SetPosInfo( const string& v)
	{
		m_PosInfo=v;
	}
	string GetPosInfo()
	{
		return m_PosInfo;
	}
	string GetPosInfo() const
	{
		return m_PosInfo;
	}
private:
	//目标位置信息
	string m_TargetPos;
public:
	void SetTargetPos( const string& v)
	{
		m_TargetPos=v;
	}
	string GetTargetPos()
	{
		return m_TargetPos;
	}
	string GetTargetPos() const
	{
		return m_TargetPos;
	}
private:
	//INT参数
	INT32 m_IntPara;
public:
	void SetIntPara( INT32 v)
	{
		m_IntPara=v;
	}
	INT32 GetIntPara()
	{
		return m_IntPara;
	}
	INT32 GetIntPara() const
	{
		return m_IntPara;
	}
private:
	//梯子ObjId
	INT32 m_LadderObjId;
public:
	void SetLadderObjId( INT32 v)
	{
		m_LadderObjId=v;
	}
	INT32 GetLadderObjId()
	{
		return m_LadderObjId;
	}
	INT32 GetLadderObjId() const
	{
		return m_LadderObjId;
	}

};
//主城状态同步封装类
class FightCityActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightCityActionWraper()
	{
		
		m_Type = -1;
		m_ObjId = -1;
		m_PosInfo = "";
		m_TargetPos = "";
		m_IntPara = -1;

	}
	//赋值构造函数
	FightCityActionWraper(const FightCityAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightCityAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightCityAction ToPB() const
	{
		FightCityAction v;
		v.set_type( m_Type );
		v.set_objid( m_ObjId );
		v.set_posinfo( m_PosInfo );
		v.set_targetpos( m_TargetPos );
		v.set_intpara( m_IntPara );

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
		FightCityAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(状态类型) [sint32]</li>\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";
		htmlBuff += "<li>PosInfo(位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>TargetPos(目标位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>IntPara(INT参数) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PosInfo：\"...\"</li>\r\n";
		htmlBuff += "<li>TargetPos：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>IntPara：%di</li>\r\n",m_IntPara);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightCityAction& v)
	{
		m_Type = v.type();
		m_ObjId = v.objid();
		m_PosInfo = v.posinfo();
		m_TargetPos = v.targetpos();
		m_IntPara = v.intpara();

	}

private:
	//状态类型
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
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//位置信息
	string m_PosInfo;
public:
	void SetPosInfo( const string& v)
	{
		m_PosInfo=v;
	}
	string GetPosInfo()
	{
		return m_PosInfo;
	}
	string GetPosInfo() const
	{
		return m_PosInfo;
	}
private:
	//目标位置信息
	string m_TargetPos;
public:
	void SetTargetPos( const string& v)
	{
		m_TargetPos=v;
	}
	string GetTargetPos()
	{
		return m_TargetPos;
	}
	string GetTargetPos() const
	{
		return m_TargetPos;
	}
private:
	//INT参数
	INT32 m_IntPara;
public:
	void SetIntPara( INT32 v)
	{
		m_IntPara=v;
	}
	INT32 GetIntPara()
	{
		return m_IntPara;
	}
	INT32 GetIntPara() const
	{
		return m_IntPara;
	}

};
//结束技能动作封装类
class FightEndSkillActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightEndSkillActionWraper()
	{
		
		m_ObjId = -1;
		m_SkillId = -1;
		m_PosInfo = "";
		m_ComboSkillId = -1;

	}
	//赋值构造函数
	FightEndSkillActionWraper(const FightEndSkillAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightEndSkillAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightEndSkillAction ToPB() const
	{
		FightEndSkillAction v;
		v.set_objid( m_ObjId );
		v.set_skillid( m_SkillId );
		v.set_posinfo( m_PosInfo );
		v.set_comboskillid( m_ComboSkillId );

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
		FightEndSkillAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillId(技能ID) [sint32]</li>\r\n";
		htmlBuff += "<li>PosInfo(位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>ComboSkillId(连击技能ID) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PosInfo：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>ComboSkillId：%di</li>\r\n",m_ComboSkillId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightEndSkillAction& v)
	{
		m_ObjId = v.objid();
		m_SkillId = v.skillid();
		m_PosInfo = v.posinfo();
		m_ComboSkillId = v.comboskillid();

	}

private:
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
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
	//位置信息
	string m_PosInfo;
public:
	void SetPosInfo( const string& v)
	{
		m_PosInfo=v;
	}
	string GetPosInfo()
	{
		return m_PosInfo;
	}
	string GetPosInfo() const
	{
		return m_PosInfo;
	}
private:
	//连击技能ID
	INT32 m_ComboSkillId;
public:
	void SetComboSkillId( INT32 v)
	{
		m_ComboSkillId=v;
	}
	INT32 GetComboSkillId()
	{
		return m_ComboSkillId;
	}
	INT32 GetComboSkillId() const
	{
		return m_ComboSkillId;
	}

};
//连击技能动作封装类
class FightComboSkillActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightComboSkillActionWraper()
	{
		
		m_ObjId = -1;
		m_SkillId = -1;
		m_Flag = -1;

	}
	//赋值构造函数
	FightComboSkillActionWraper(const FightComboSkillAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightComboSkillAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightComboSkillAction ToPB() const
	{
		FightComboSkillAction v;
		v.set_objid( m_ObjId );
		v.set_skillid( m_SkillId );
		v.set_flag( m_Flag );

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
		FightComboSkillAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillId(技能ID) [sint32]</li>\r\n";
		htmlBuff += "<li>Flag(连击标志) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Flag：%di</li>\r\n",m_Flag);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightComboSkillAction& v)
	{
		m_ObjId = v.objid();
		m_SkillId = v.skillid();
		m_Flag = v.flag();

	}

private:
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
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
	//连击标志
	INT32 m_Flag;
public:
	void SetFlag( INT32 v)
	{
		m_Flag=v;
	}
	INT32 GetFlag()
	{
		return m_Flag;
	}
	INT32 GetFlag() const
	{
		return m_Flag;
	}

};
//使用技能动作封装类
class FightUseSkillActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightUseSkillActionWraper()
	{
		
		m_ObjId = -1;
		m_SkillId = -1;
		m_PosInfo = "";
		m_TargetObjId = -1;
		m_TargetPos = "";
		m_Type = 0;
		m_Time = -1;

	}
	//赋值构造函数
	FightUseSkillActionWraper(const FightUseSkillAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightUseSkillAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightUseSkillAction ToPB() const
	{
		FightUseSkillAction v;
		v.set_objid( m_ObjId );
		v.set_skillid( m_SkillId );
		v.set_posinfo( m_PosInfo );
		v.set_targetobjid( m_TargetObjId );
		v.set_targetpos( m_TargetPos );
		v.set_type( m_Type );
		v.mutable_v3pos()->Reserve(m_V3Pos.size());
		for (int i=0; i<(int)m_V3Pos.size(); i++)
		{
			v.add_v3pos(m_V3Pos[i]);
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
		FightUseSkillAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillId(技能ID) [sint32]</li>\r\n";
		htmlBuff += "<li>PosInfo(位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>TargetObjId(主目标ID) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetPos(目标位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>V3Pos(V3Pos) [float] Array</li>\r\n";
		htmlBuff += "<li>Time(吟唱或引导时间(毫秒)) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PosInfo：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>TargetObjId：%di</li>\r\n",m_TargetObjId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>TargetPos：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		htmlBuff += "<li>V3Pos：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_V3Pos.size(); i++){
			tmpLine.Fmt("<td>%.2ff</td>\r\n",m_V3Pos[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_V3Pos.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightUseSkillAction& v)
	{
		m_ObjId = v.objid();
		m_SkillId = v.skillid();
		m_PosInfo = v.posinfo();
		m_TargetObjId = v.targetobjid();
		m_TargetPos = v.targetpos();
		m_Type = v.type();
		m_V3Pos.clear();
		m_V3Pos.reserve(v.v3pos_size());
		for( int i=0; i<v.v3pos_size(); i++)
			m_V3Pos.push_back(v.v3pos(i));
		m_Time = v.time();

	}

private:
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
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
	//位置信息
	string m_PosInfo;
public:
	void SetPosInfo( const string& v)
	{
		m_PosInfo=v;
	}
	string GetPosInfo()
	{
		return m_PosInfo;
	}
	string GetPosInfo() const
	{
		return m_PosInfo;
	}
private:
	//主目标ID
	INT32 m_TargetObjId;
public:
	void SetTargetObjId( INT32 v)
	{
		m_TargetObjId=v;
	}
	INT32 GetTargetObjId()
	{
		return m_TargetObjId;
	}
	INT32 GetTargetObjId() const
	{
		return m_TargetObjId;
	}
private:
	//目标位置信息
	string m_TargetPos;
public:
	void SetTargetPos( const string& v)
	{
		m_TargetPos=v;
	}
	string GetTargetPos()
	{
		return m_TargetPos;
	}
	string GetTargetPos() const
	{
		return m_TargetPos;
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
	//V3Pos
	vector<float> m_V3Pos;
public:
	int SizeV3Pos()
	{
		return m_V3Pos.size();
	}
	const vector<float>& GetV3Pos() const
	{
		return m_V3Pos;
	}
	float GetV3Pos(int Index) const
	{
		if(Index<0 || Index>=(int)m_V3Pos.size())
		{
			assert(false);
			return float();
		}
		return m_V3Pos[Index];
	}
	void SetV3Pos( const vector<float>& v )
	{
		m_V3Pos=v;
	}
	void ClearV3Pos( )
	{
		m_V3Pos.clear();
	}
	void SetV3Pos( int Index, float v )
	{
		if(Index<0 || Index>=(int)m_V3Pos.size())
		{
			assert(false);
			return;
		}
		m_V3Pos[Index] = v;
	}
	void AddV3Pos( float v = -1 )
	{
		m_V3Pos.push_back(v);
	}
private:
	//吟唱或引导时间(毫秒)
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}

};
//杀戮信息封装类
class FightKillInfoWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightKillInfoWraper()
	{
		
		m_Id = -1;
		m_Count = -1;

	}
	//赋值构造函数
	FightKillInfoWraper(const FightKillInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const FightKillInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightKillInfo ToPB() const
	{
		FightKillInfo v;
		v.set_id( m_Id );
		v.set_count( m_Count );

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
		FightKillInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Id(对方Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Count(数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Count：%di</li>\r\n",m_Count);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightKillInfo& v)
	{
		m_Id = v.id();
		m_Count = v.count();

	}

private:
	//对方Id
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//数量
	INT32 m_Count;
public:
	void SetCount( INT32 v)
	{
		m_Count=v;
	}
	INT32 GetCount()
	{
		return m_Count;
	}
	INT32 GetCount() const
	{
		return m_Count;
	}

};
//奖励列表封装类
class FightPrizeInfoWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightPrizeInfoWraper()
	{
		
		m_Id = -1;
		m_Count = -1;

	}
	//赋值构造函数
	FightPrizeInfoWraper(const FightPrizeInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const FightPrizeInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightPrizeInfo ToPB() const
	{
		FightPrizeInfo v;
		v.set_id( m_Id );
		v.set_count( m_Count );

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
		FightPrizeInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Id(奖励ID) [sint32]</li>\r\n";
		htmlBuff += "<li>Count(奖励数量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Count：%di</li>\r\n",m_Count);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightPrizeInfo& v)
	{
		m_Id = v.id();
		m_Count = v.count();

	}

private:
	//奖励ID
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//奖励数量
	INT32 m_Count;
public:
	void SetCount( INT32 v)
	{
		m_Count=v;
	}
	INT32 GetCount()
	{
		return m_Count;
	}
	INT32 GetCount() const
	{
		return m_Count;
	}

};
//断线动作封装类
class FightOfflineActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightOfflineActionWraper()
	{
		
		m_ObjId = -1;
		m_IsOffline = false;
		m_IsAIDelegate = false;

	}
	//赋值构造函数
	FightOfflineActionWraper(const FightOfflineAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightOfflineAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightOfflineAction ToPB() const
	{
		FightOfflineAction v;
		v.set_objid( m_ObjId );
		v.set_isoffline( m_IsOffline );
		v.set_isaidelegate( m_IsAIDelegate );

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
		FightOfflineAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(obj Id) [sint32]</li>\r\n";
		htmlBuff += "<li>IsOffline(是否下线) [bool]</li>\r\n";
		htmlBuff += "<li>IsAIDelegate(是否AI接管) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsOffline：%di</li>\r\n",m_IsOffline);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsAIDelegate：%di</li>\r\n",m_IsAIDelegate);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightOfflineAction& v)
	{
		m_ObjId = v.objid();
		m_IsOffline = v.isoffline();
		m_IsAIDelegate = v.isaidelegate();

	}

private:
	//obj Id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//是否下线
	bool m_IsOffline;
public:
	void SetIsOffline( bool v)
	{
		m_IsOffline=v;
	}
	bool GetIsOffline()
	{
		return m_IsOffline;
	}
	bool GetIsOffline() const
	{
		return m_IsOffline;
	}
private:
	//是否AI接管
	bool m_IsAIDelegate;
public:
	void SetIsAIDelegate( bool v)
	{
		m_IsAIDelegate=v;
	}
	bool GetIsAIDelegate()
	{
		return m_IsAIDelegate;
	}
	bool GetIsAIDelegate() const
	{
		return m_IsAIDelegate;
	}

};
//攻击动作封装类
class FightCharHitActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightCharHitActionWraper()
	{
		
		m_ObjId = -1;
		m_SkillId = -1;
		m_Seq = -1;
		m_PosInfo = "";
		m_BackDir = 0;
		m_SegmentIndex = -1;
		m_AttackSegment = -1;
		m_IsHitGround = false;

	}
	//赋值构造函数
	FightCharHitActionWraper(const FightCharHitAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightCharHitAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightCharHitAction ToPB() const
	{
		FightCharHitAction v;
		v.set_objid( m_ObjId );
		v.set_skillid( m_SkillId );
		v.mutable_targetlist()->Reserve(m_TargetList.size());
		for (int i=0; i<(int)m_TargetList.size(); i++)
		{
			*v.add_targetlist() = m_TargetList[i].ToPB();
		}
		v.set_seq( m_Seq );
		v.set_posinfo( m_PosInfo );
		v.set_backdir( m_BackDir );
		v.set_segmentindex( m_SegmentIndex );
		v.set_attacksegment( m_AttackSegment );
		v.set_ishitground( m_IsHitGround );

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
		FightCharHitAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillId(技能ID) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetList(目标列表) [HitTargetInfo] Array</li>\r\n";
		htmlBuff += "<li>Seq(技能攻击到人的序列号) [sint32]</li>\r\n";
		htmlBuff += "<li>PosInfo(位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>BackDir(后退方向) [sint32]</li>\r\n";
		htmlBuff += "<li>SegmentIndex(技能动作段索引) [sint32]</li>\r\n";
		htmlBuff += "<li>AttackSegment(攻击段数) [sint32]</li>\r\n";
		htmlBuff += "<li>IsHitGround(受击后目标倒地) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>TargetList：</li>\r\n";
		if( m_TargetList.size()>0) htmlBuff += m_TargetList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_TargetList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_TargetList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>Seq：%di</li>\r\n",m_Seq);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PosInfo：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>BackDir：%di</li>\r\n",m_BackDir);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SegmentIndex：%di</li>\r\n",m_SegmentIndex);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackSegment：%di</li>\r\n",m_AttackSegment);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsHitGround：%di</li>\r\n",m_IsHitGround);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightCharHitAction& v)
	{
		m_ObjId = v.objid();
		m_SkillId = v.skillid();
		m_TargetList.clear();
		m_TargetList.reserve(v.targetlist_size());
		for( int i=0; i<v.targetlist_size(); i++)
			m_TargetList.push_back(v.targetlist(i));
		m_Seq = v.seq();
		m_PosInfo = v.posinfo();
		m_BackDir = v.backdir();
		m_SegmentIndex = v.segmentindex();
		m_AttackSegment = v.attacksegment();
		m_IsHitGround = v.ishitground();

	}

private:
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
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
	//目标列表
	vector<FightHitTargetInfoWraper> m_TargetList;
public:
	int SizeTargetList()
	{
		return m_TargetList.size();
	}
	const vector<FightHitTargetInfoWraper>& GetTargetList() const
	{
		return m_TargetList;
	}
	FightHitTargetInfoWraper GetTargetList(int Index) const
	{
		if(Index<0 || Index>=(int)m_TargetList.size())
		{
			assert(false);
			return FightHitTargetInfoWraper();
		}
		return m_TargetList[Index];
	}
	void SetTargetList( const vector<FightHitTargetInfoWraper>& v )
	{
		m_TargetList=v;
	}
	void ClearTargetList( )
	{
		m_TargetList.clear();
	}
	void SetTargetList( int Index, const FightHitTargetInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_TargetList.size())
		{
			assert(false);
			return;
		}
		m_TargetList[Index] = v;
	}
	void AddTargetList( const FightHitTargetInfoWraper& v )
	{
		m_TargetList.push_back(v);
	}
private:
	//技能攻击到人的序列号
	INT32 m_Seq;
public:
	void SetSeq( INT32 v)
	{
		m_Seq=v;
	}
	INT32 GetSeq()
	{
		return m_Seq;
	}
	INT32 GetSeq() const
	{
		return m_Seq;
	}
private:
	//位置信息
	string m_PosInfo;
public:
	void SetPosInfo( const string& v)
	{
		m_PosInfo=v;
	}
	string GetPosInfo()
	{
		return m_PosInfo;
	}
	string GetPosInfo() const
	{
		return m_PosInfo;
	}
private:
	//后退方向
	INT32 m_BackDir;
public:
	void SetBackDir( INT32 v)
	{
		m_BackDir=v;
	}
	INT32 GetBackDir()
	{
		return m_BackDir;
	}
	INT32 GetBackDir() const
	{
		return m_BackDir;
	}
private:
	//技能动作段索引
	INT32 m_SegmentIndex;
public:
	void SetSegmentIndex( INT32 v)
	{
		m_SegmentIndex=v;
	}
	INT32 GetSegmentIndex()
	{
		return m_SegmentIndex;
	}
	INT32 GetSegmentIndex() const
	{
		return m_SegmentIndex;
	}
private:
	//攻击段数
	INT32 m_AttackSegment;
public:
	void SetAttackSegment( INT32 v)
	{
		m_AttackSegment=v;
	}
	INT32 GetAttackSegment()
	{
		return m_AttackSegment;
	}
	INT32 GetAttackSegment() const
	{
		return m_AttackSegment;
	}
private:
	//受击后目标倒地
	bool m_IsHitGround;
public:
	void SetIsHitGround( bool v)
	{
		m_IsHitGround=v;
	}
	bool GetIsHitGround()
	{
		return m_IsHitGround;
	}
	bool GetIsHitGround() const
	{
		return m_IsHitGround;
	}

};
//BUFF操作动作类封装类
class FightBuffActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightBuffActionWraper()
	{
		
		m_ObjId = -1;
		m_AttackerId = -1;
		m_OpType = -1;
		m_BuffId = -1;
		m_RemainTime = -1;
		m_BuffLv = -1;

	}
	//赋值构造函数
	FightBuffActionWraper(const FightBuffAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightBuffAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightBuffAction ToPB() const
	{
		FightBuffAction v;
		v.set_objid( m_ObjId );
		v.set_attackerid( m_AttackerId );
		v.set_optype( m_OpType );
		v.set_buffid( m_BuffId );
		v.set_remaintime( m_RemainTime );
		v.set_bufflv( m_BuffLv );

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
		FightBuffAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";
		htmlBuff += "<li>AttackerId(攻击者ObjId) [sint32]</li>\r\n";
		htmlBuff += "<li>OpType(操作类型) [sint32]</li>\r\n";
		htmlBuff += "<li>BuffId(BuffId) [sint32]</li>\r\n";
		htmlBuff += "<li>RemainTime(剩余时间) [sint32]</li>\r\n";
		htmlBuff += "<li>BuffLv(Buff等级) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackerId：%di</li>\r\n",m_AttackerId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>OpType：%di</li>\r\n",m_OpType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BuffId：%di</li>\r\n",m_BuffId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RemainTime：%di</li>\r\n",m_RemainTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BuffLv：%di</li>\r\n",m_BuffLv);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightBuffAction& v)
	{
		m_ObjId = v.objid();
		m_AttackerId = v.attackerid();
		m_OpType = v.optype();
		m_BuffId = v.buffid();
		m_RemainTime = v.remaintime();
		m_BuffLv = v.bufflv();

	}

private:
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//攻击者ObjId
	INT32 m_AttackerId;
public:
	void SetAttackerId( INT32 v)
	{
		m_AttackerId=v;
	}
	INT32 GetAttackerId()
	{
		return m_AttackerId;
	}
	INT32 GetAttackerId() const
	{
		return m_AttackerId;
	}
private:
	//操作类型
	INT32 m_OpType;
public:
	void SetOpType( INT32 v)
	{
		m_OpType=v;
	}
	INT32 GetOpType()
	{
		return m_OpType;
	}
	INT32 GetOpType() const
	{
		return m_OpType;
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
	//剩余时间
	INT32 m_RemainTime;
public:
	void SetRemainTime( INT32 v)
	{
		m_RemainTime=v;
	}
	INT32 GetRemainTime()
	{
		return m_RemainTime;
	}
	INT32 GetRemainTime() const
	{
		return m_RemainTime;
	}
private:
	//Buff等级
	INT32 m_BuffLv;
public:
	void SetBuffLv( INT32 v)
	{
		m_BuffLv=v;
	}
	INT32 GetBuffLv()
	{
		return m_BuffLv;
	}
	INT32 GetBuffLv() const
	{
		return m_BuffLv;
	}

};
//狙击动作封装类
class FightSnipeActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightSnipeActionWraper()
	{
		
		m_Type = -1;
		m_ObjId = -1;
		m_TargetPos = "";
		m_CampId = -1;

	}
	//赋值构造函数
	FightSnipeActionWraper(const FightSnipeAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightSnipeAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightSnipeAction ToPB() const
	{
		FightSnipeAction v;
		v.set_type( m_Type );
		v.set_objid( m_ObjId );
		v.set_targetpos( m_TargetPos );
		v.set_campid( m_CampId );

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
		FightSnipeAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(状态类型) [sint32]</li>\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetPos(目标位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>CampId(狙击者阵营ID) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>TargetPos：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>CampId：%di</li>\r\n",m_CampId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightSnipeAction& v)
	{
		m_Type = v.type();
		m_ObjId = v.objid();
		m_TargetPos = v.targetpos();
		m_CampId = v.campid();

	}

private:
	//状态类型
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
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//目标位置信息
	string m_TargetPos;
public:
	void SetTargetPos( const string& v)
	{
		m_TargetPos=v;
	}
	string GetTargetPos()
	{
		return m_TargetPos;
	}
	string GetTargetPos() const
	{
		return m_TargetPos;
	}
private:
	//狙击者阵营ID
	INT32 m_CampId;
public:
	void SetCampId( INT32 v)
	{
		m_CampId=v;
	}
	INT32 GetCampId()
	{
		return m_CampId;
	}
	INT32 GetCampId() const
	{
		return m_CampId;
	}

};
//创建对像动作封装类
class FightCreateActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightCreateActionWraper()
	{
		
		m_UserId = -1;
		m_ConfigId = -1;
		m_ObjId = -1;
		m_PosInfo = "";
		m_ObjType = -1;
		m_CampId = -1;
		m_PosInfo2 = "";
		m_CurState = -1;
		m_CurHp = -1;
		m_Name = "";
		m_Level = -1;
		m_TableType = -1;
		m_IsShowEffect = false;

	}
	//赋值构造函数
	FightCreateActionWraper(const FightCreateAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightCreateAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightCreateAction ToPB() const
	{
		FightCreateAction v;
		v.set_userid( m_UserId );
		v.set_configid( m_ConfigId );
		v.set_objid( m_ObjId );
		v.set_posinfo( m_PosInfo );
		v.set_objtype( m_ObjType );
		v.set_campid( m_CampId );
		v.set_posinfo2( m_PosInfo2 );
		v.mutable_intparalist()->Reserve(m_IntParaList.size());
		for (int i=0; i<(int)m_IntParaList.size(); i++)
		{
			v.add_intparalist(m_IntParaList[i]);
		}
		v.mutable_floatparalist()->Reserve(m_FloatParaList.size());
		for (int i=0; i<(int)m_FloatParaList.size(); i++)
		{
			v.add_floatparalist(m_FloatParaList[i]);
		}
		v.set_curstate( m_CurState );
		v.set_curhp( m_CurHp );
		v.set_name( m_Name );
		v.mutable_equipbuffarr()->Reserve(m_EquipBuffArr.size());
		for (int i=0; i<(int)m_EquipBuffArr.size(); i++)
		{
			*v.add_equipbuffarr() = m_EquipBuffArr[i].ToPB();
		}
		v.mutable_equipskillarr()->Reserve(m_EquipSkillArr.size());
		for (int i=0; i<(int)m_EquipSkillArr.size(); i++)
		{
			*v.add_equipskillarr() = m_EquipSkillArr[i].ToPB();
		}
		v.mutable_attrarr()->Reserve(m_AttrArr.size());
		for (int i=0; i<(int)m_AttrArr.size(); i++)
		{
			*v.add_attrarr() = m_AttrArr[i].ToPB();
		}
		v.set_level( m_Level );
		v.set_tabletype( m_TableType );
		v.set_isshoweffect( m_IsShowEffect );

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
		FightCreateAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>ConfigId(配置文件中的ID) [sint32]</li>\r\n";
		htmlBuff += "<li>ObjId(内核中用到的对像ID) [sint32]</li>\r\n";
		htmlBuff += "<li>PosInfo(位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>ObjType(创建类型 ) [sint32]</li>\r\n";
		htmlBuff += "<li>CampId(阵营ID) [sint32]</li>\r\n";
		htmlBuff += "<li>PosInfo2(位置信息) [bytes]</li>\r\n";
		htmlBuff += "<li>IntParaList(整数参数列表) [sint32] Array</li>\r\n";
		htmlBuff += "<li>FloatParaList(字符串参数列表) [float] Array</li>\r\n";
		htmlBuff += "<li>CurState(当前状态) [sint32]</li>\r\n";
		htmlBuff += "<li>CurHp(当前血量) [sint32]</li>\r\n";
		htmlBuff += "<li>Name(名字) [string]</li>\r\n";
		htmlBuff += "<li>EquipBuffArr(装备的BUFF列表) [EquipSkillBuff2] Array</li>\r\n";
		htmlBuff += "<li>EquipSkillArr(装备的技能) [EquipSkillBuff2] Array</li>\r\n";
		htmlBuff += "<li>AttrArr(属性列表) [KeyValue2] Array</li>\r\n";
		htmlBuff += "<li>Level(等级) [sint32]</li>\r\n";
		htmlBuff += "<li>TableType(TableType) [sint32]</li>\r\n";
		htmlBuff += "<li>IsShowEffect(是否显示特效) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ConfigId：%di</li>\r\n",m_ConfigId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PosInfo：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>ObjType：%di</li>\r\n",m_ObjType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CampId：%di</li>\r\n",m_CampId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PosInfo2：\"...\"</li>\r\n";
		htmlBuff += "<li>IntParaList：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_IntParaList.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_IntParaList[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_IntParaList.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		htmlBuff += "<li>FloatParaList：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_FloatParaList.size(); i++){
			tmpLine.Fmt("<td>%.2ff</td>\r\n",m_FloatParaList[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_FloatParaList.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>CurState：%di</li>\r\n",m_CurState);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CurHp：%di</li>\r\n",m_CurHp);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Name：\""+m_Name+"\"</li>\r\n";
		htmlBuff += "<li>EquipBuffArr：</li>\r\n";
		if( m_EquipBuffArr.size()>0) htmlBuff += m_EquipBuffArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_EquipBuffArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_EquipBuffArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>EquipSkillArr：</li>\r\n";
		if( m_EquipSkillArr.size()>0) htmlBuff += m_EquipSkillArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_EquipSkillArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_EquipSkillArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>AttrArr：</li>\r\n";
		if( m_AttrArr.size()>0) htmlBuff += m_AttrArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_AttrArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_AttrArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TableType：%di</li>\r\n",m_TableType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsShowEffect：%di</li>\r\n",m_IsShowEffect);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightCreateAction& v)
	{
		m_UserId = v.userid();
		m_ConfigId = v.configid();
		m_ObjId = v.objid();
		m_PosInfo = v.posinfo();
		m_ObjType = v.objtype();
		m_CampId = v.campid();
		m_PosInfo2 = v.posinfo2();
		m_IntParaList.clear();
		m_IntParaList.reserve(v.intparalist_size());
		for( int i=0; i<v.intparalist_size(); i++)
			m_IntParaList.push_back(v.intparalist(i));
		m_FloatParaList.clear();
		m_FloatParaList.reserve(v.floatparalist_size());
		for( int i=0; i<v.floatparalist_size(); i++)
			m_FloatParaList.push_back(v.floatparalist(i));
		m_CurState = v.curstate();
		m_CurHp = v.curhp();
		m_Name = v.name();
		m_EquipBuffArr.clear();
		m_EquipBuffArr.reserve(v.equipbuffarr_size());
		for( int i=0; i<v.equipbuffarr_size(); i++)
			m_EquipBuffArr.push_back(v.equipbuffarr(i));
		m_EquipSkillArr.clear();
		m_EquipSkillArr.reserve(v.equipskillarr_size());
		for( int i=0; i<v.equipskillarr_size(); i++)
			m_EquipSkillArr.push_back(v.equipskillarr(i));
		m_AttrArr.clear();
		m_AttrArr.reserve(v.attrarr_size());
		for( int i=0; i<v.attrarr_size(); i++)
			m_AttrArr.push_back(v.attrarr(i));
		m_Level = v.level();
		m_TableType = v.tabletype();
		m_IsShowEffect = v.isshoweffect();

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
	//配置文件中的ID
	INT32 m_ConfigId;
public:
	void SetConfigId( INT32 v)
	{
		m_ConfigId=v;
	}
	INT32 GetConfigId()
	{
		return m_ConfigId;
	}
	INT32 GetConfigId() const
	{
		return m_ConfigId;
	}
private:
	//内核中用到的对像ID
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//位置信息
	string m_PosInfo;
public:
	void SetPosInfo( const string& v)
	{
		m_PosInfo=v;
	}
	string GetPosInfo()
	{
		return m_PosInfo;
	}
	string GetPosInfo() const
	{
		return m_PosInfo;
	}
private:
	//创建类型 
	INT32 m_ObjType;
public:
	void SetObjType( INT32 v)
	{
		m_ObjType=v;
	}
	INT32 GetObjType()
	{
		return m_ObjType;
	}
	INT32 GetObjType() const
	{
		return m_ObjType;
	}
private:
	//阵营ID
	INT32 m_CampId;
public:
	void SetCampId( INT32 v)
	{
		m_CampId=v;
	}
	INT32 GetCampId()
	{
		return m_CampId;
	}
	INT32 GetCampId() const
	{
		return m_CampId;
	}
private:
	//位置信息
	string m_PosInfo2;
public:
	void SetPosInfo2( const string& v)
	{
		m_PosInfo2=v;
	}
	string GetPosInfo2()
	{
		return m_PosInfo2;
	}
	string GetPosInfo2() const
	{
		return m_PosInfo2;
	}
private:
	//整数参数列表
	vector<INT32> m_IntParaList;
public:
	int SizeIntParaList()
	{
		return m_IntParaList.size();
	}
	const vector<INT32>& GetIntParaList() const
	{
		return m_IntParaList;
	}
	INT32 GetIntParaList(int Index) const
	{
		if(Index<0 || Index>=(int)m_IntParaList.size())
		{
			assert(false);
			return INT32();
		}
		return m_IntParaList[Index];
	}
	void SetIntParaList( const vector<INT32>& v )
	{
		m_IntParaList=v;
	}
	void ClearIntParaList( )
	{
		m_IntParaList.clear();
	}
	void SetIntParaList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_IntParaList.size())
		{
			assert(false);
			return;
		}
		m_IntParaList[Index] = v;
	}
	void AddIntParaList( INT32 v = -1 )
	{
		m_IntParaList.push_back(v);
	}
private:
	//字符串参数列表
	vector<float> m_FloatParaList;
public:
	int SizeFloatParaList()
	{
		return m_FloatParaList.size();
	}
	const vector<float>& GetFloatParaList() const
	{
		return m_FloatParaList;
	}
	float GetFloatParaList(int Index) const
	{
		if(Index<0 || Index>=(int)m_FloatParaList.size())
		{
			assert(false);
			return float();
		}
		return m_FloatParaList[Index];
	}
	void SetFloatParaList( const vector<float>& v )
	{
		m_FloatParaList=v;
	}
	void ClearFloatParaList( )
	{
		m_FloatParaList.clear();
	}
	void SetFloatParaList( int Index, float v )
	{
		if(Index<0 || Index>=(int)m_FloatParaList.size())
		{
			assert(false);
			return;
		}
		m_FloatParaList[Index] = v;
	}
	void AddFloatParaList( float v = -1 )
	{
		m_FloatParaList.push_back(v);
	}
private:
	//当前状态
	INT32 m_CurState;
public:
	void SetCurState( INT32 v)
	{
		m_CurState=v;
	}
	INT32 GetCurState()
	{
		return m_CurState;
	}
	INT32 GetCurState() const
	{
		return m_CurState;
	}
private:
	//当前血量
	INT32 m_CurHp;
public:
	void SetCurHp( INT32 v)
	{
		m_CurHp=v;
	}
	INT32 GetCurHp()
	{
		return m_CurHp;
	}
	INT32 GetCurHp() const
	{
		return m_CurHp;
	}
private:
	//名字
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
	//装备的BUFF列表
	vector<EquipSkillBuff2Wraper> m_EquipBuffArr;
public:
	int SizeEquipBuffArr()
	{
		return m_EquipBuffArr.size();
	}
	const vector<EquipSkillBuff2Wraper>& GetEquipBuffArr() const
	{
		return m_EquipBuffArr;
	}
	EquipSkillBuff2Wraper GetEquipBuffArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_EquipBuffArr.size())
		{
			assert(false);
			return EquipSkillBuff2Wraper();
		}
		return m_EquipBuffArr[Index];
	}
	void SetEquipBuffArr( const vector<EquipSkillBuff2Wraper>& v )
	{
		m_EquipBuffArr=v;
	}
	void ClearEquipBuffArr( )
	{
		m_EquipBuffArr.clear();
	}
	void SetEquipBuffArr( int Index, const EquipSkillBuff2Wraper& v )
	{
		if(Index<0 || Index>=(int)m_EquipBuffArr.size())
		{
			assert(false);
			return;
		}
		m_EquipBuffArr[Index] = v;
	}
	void AddEquipBuffArr( const EquipSkillBuff2Wraper& v )
	{
		m_EquipBuffArr.push_back(v);
	}
private:
	//装备的技能
	vector<EquipSkillBuff2Wraper> m_EquipSkillArr;
public:
	int SizeEquipSkillArr()
	{
		return m_EquipSkillArr.size();
	}
	const vector<EquipSkillBuff2Wraper>& GetEquipSkillArr() const
	{
		return m_EquipSkillArr;
	}
	EquipSkillBuff2Wraper GetEquipSkillArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_EquipSkillArr.size())
		{
			assert(false);
			return EquipSkillBuff2Wraper();
		}
		return m_EquipSkillArr[Index];
	}
	void SetEquipSkillArr( const vector<EquipSkillBuff2Wraper>& v )
	{
		m_EquipSkillArr=v;
	}
	void ClearEquipSkillArr( )
	{
		m_EquipSkillArr.clear();
	}
	void SetEquipSkillArr( int Index, const EquipSkillBuff2Wraper& v )
	{
		if(Index<0 || Index>=(int)m_EquipSkillArr.size())
		{
			assert(false);
			return;
		}
		m_EquipSkillArr[Index] = v;
	}
	void AddEquipSkillArr( const EquipSkillBuff2Wraper& v )
	{
		m_EquipSkillArr.push_back(v);
	}
private:
	//属性列表
	vector<KeyValue2Wraper> m_AttrArr;
public:
	int SizeAttrArr()
	{
		return m_AttrArr.size();
	}
	const vector<KeyValue2Wraper>& GetAttrArr() const
	{
		return m_AttrArr;
	}
	KeyValue2Wraper GetAttrArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_AttrArr.size())
		{
			assert(false);
			return KeyValue2Wraper();
		}
		return m_AttrArr[Index];
	}
	void SetAttrArr( const vector<KeyValue2Wraper>& v )
	{
		m_AttrArr=v;
	}
	void ClearAttrArr( )
	{
		m_AttrArr.clear();
	}
	void SetAttrArr( int Index, const KeyValue2Wraper& v )
	{
		if(Index<0 || Index>=(int)m_AttrArr.size())
		{
			assert(false);
			return;
		}
		m_AttrArr[Index] = v;
	}
	void AddAttrArr( const KeyValue2Wraper& v )
	{
		m_AttrArr.push_back(v);
	}
private:
	//等级
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
	//TableType
	INT32 m_TableType;
public:
	void SetTableType( INT32 v)
	{
		m_TableType=v;
	}
	INT32 GetTableType()
	{
		return m_TableType;
	}
	INT32 GetTableType() const
	{
		return m_TableType;
	}
private:
	//是否显示特效
	bool m_IsShowEffect;
public:
	void SetIsShowEffect( bool v)
	{
		m_IsShowEffect=v;
	}
	bool GetIsShowEffect()
	{
		return m_IsShowEffect;
	}
	bool GetIsShowEffect() const
	{
		return m_IsShowEffect;
	}

};
//暴风战斗结果信息封装类
class FightStormResultActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightStormResultActionWraper()
	{
		
		m_IsSvrSend = false;

	}
	//赋值构造函数
	FightStormResultActionWraper(const FightStormResultAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightStormResultAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightStormResultAction ToPB() const
	{
		FightStormResultAction v;
		v.mutable_camparr()->Reserve(m_CampArr.size());
		for (int i=0; i<(int)m_CampArr.size(); i++)
		{
			*v.add_camparr() = m_CampArr[i].ToPB();
		}
		v.set_issvrsend( m_IsSvrSend );

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
		FightStormResultAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>CampArr(阵营列表) [StormCampInfo] Array</li>\r\n";
		htmlBuff += "<li>IsSvrSend(是否为服务器发送) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>CampArr：</li>\r\n";
		if( m_CampArr.size()>0) htmlBuff += m_CampArr[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_CampArr.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_CampArr[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>IsSvrSend：%di</li>\r\n",m_IsSvrSend);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightStormResultAction& v)
	{
		m_CampArr.clear();
		m_CampArr.reserve(v.camparr_size());
		for( int i=0; i<v.camparr_size(); i++)
			m_CampArr.push_back(v.camparr(i));
		m_IsSvrSend = v.issvrsend();

	}

private:
	//阵营列表
	vector<FightStormCampInfoWraper> m_CampArr;
public:
	int SizeCampArr()
	{
		return m_CampArr.size();
	}
	const vector<FightStormCampInfoWraper>& GetCampArr() const
	{
		return m_CampArr;
	}
	FightStormCampInfoWraper GetCampArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_CampArr.size())
		{
			assert(false);
			return FightStormCampInfoWraper();
		}
		return m_CampArr[Index];
	}
	void SetCampArr( const vector<FightStormCampInfoWraper>& v )
	{
		m_CampArr=v;
	}
	void ClearCampArr( )
	{
		m_CampArr.clear();
	}
	void SetCampArr( int Index, const FightStormCampInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_CampArr.size())
		{
			assert(false);
			return;
		}
		m_CampArr[Index] = v;
	}
	void AddCampArr( const FightStormCampInfoWraper& v )
	{
		m_CampArr.push_back(v);
	}
private:
	//是否为服务器发送
	bool m_IsSvrSend;
public:
	void SetIsSvrSend( bool v)
	{
		m_IsSvrSend=v;
	}
	bool GetIsSvrSend()
	{
		return m_IsSvrSend;
	}
	bool GetIsSvrSend() const
	{
		return m_IsSvrSend;
	}

};
//暴风阵营信息封装类
class FightStormCampActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightStormCampActionWraper()
	{
		
		m_CampId = -1;
		m_TotalNum = 0;
		m_Color = -1;
		m_Type = -1;

	}
	//赋值构造函数
	FightStormCampActionWraper(const FightStormCampAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightStormCampAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightStormCampAction ToPB() const
	{
		FightStormCampAction v;
		v.mutable_objarr()->Reserve(m_ObjArr.size());
		for (int i=0; i<(int)m_ObjArr.size(); i++)
		{
			v.add_objarr(m_ObjArr[i]);
		}
		v.set_campid( m_CampId );
		v.set_totalnum( m_TotalNum );
		v.set_color( m_Color );
		v.set_type( m_Type );

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
		FightStormCampAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjArr(阵营人员ObjId列表) [sint32] Array</li>\r\n";
		htmlBuff += "<li>CampId(阵营ID) [sint32]</li>\r\n";
		htmlBuff += "<li>TotalNum(资源总量) [sint32]</li>\r\n";
		htmlBuff += "<li>Color(阵营颜色) [sint32]</li>\r\n";
		htmlBuff += "<li>Type(操作类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ObjArr：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_ObjArr.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_ObjArr[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_ObjArr.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>CampId：%di</li>\r\n",m_CampId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TotalNum：%di</li>\r\n",m_TotalNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Color：%di</li>\r\n",m_Color);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightStormCampAction& v)
	{
		m_ObjArr.clear();
		m_ObjArr.reserve(v.objarr_size());
		for( int i=0; i<v.objarr_size(); i++)
			m_ObjArr.push_back(v.objarr(i));
		m_CampId = v.campid();
		m_TotalNum = v.totalnum();
		m_Color = v.color();
		m_Type = v.type();

	}

private:
	//阵营人员ObjId列表
	vector<INT32> m_ObjArr;
public:
	int SizeObjArr()
	{
		return m_ObjArr.size();
	}
	const vector<INT32>& GetObjArr() const
	{
		return m_ObjArr;
	}
	INT32 GetObjArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_ObjArr.size())
		{
			assert(false);
			return INT32();
		}
		return m_ObjArr[Index];
	}
	void SetObjArr( const vector<INT32>& v )
	{
		m_ObjArr=v;
	}
	void ClearObjArr( )
	{
		m_ObjArr.clear();
	}
	void SetObjArr( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_ObjArr.size())
		{
			assert(false);
			return;
		}
		m_ObjArr[Index] = v;
	}
	void AddObjArr( INT32 v = -1 )
	{
		m_ObjArr.push_back(v);
	}
private:
	//阵营ID
	INT32 m_CampId;
public:
	void SetCampId( INT32 v)
	{
		m_CampId=v;
	}
	INT32 GetCampId()
	{
		return m_CampId;
	}
	INT32 GetCampId() const
	{
		return m_CampId;
	}
private:
	//资源总量
	INT32 m_TotalNum;
public:
	void SetTotalNum( INT32 v)
	{
		m_TotalNum=v;
	}
	INT32 GetTotalNum()
	{
		return m_TotalNum;
	}
	INT32 GetTotalNum() const
	{
		return m_TotalNum;
	}
private:
	//阵营颜色
	INT32 m_Color;
public:
	void SetColor( INT32 v)
	{
		m_Color=v;
	}
	INT32 GetColor()
	{
		return m_Color;
	}
	INT32 GetColor() const
	{
		return m_Color;
	}
private:
	//操作类型
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

};
//塔锁定对象动作封装类
class FightTowerLockActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightTowerLockActionWraper()
	{
		
		m_TargetObjId = -1;
		m_ObjId = -1;
		m_Type = 0;

	}
	//赋值构造函数
	FightTowerLockActionWraper(const FightTowerLockAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightTowerLockAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightTowerLockAction ToPB() const
	{
		FightTowerLockAction v;
		v.set_targetobjid( m_TargetObjId );
		v.set_objid( m_ObjId );
		v.set_type( m_Type );

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
		FightTowerLockAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TargetObjId(目标ObjId) [sint32]</li>\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TargetObjId：%di</li>\r\n",m_TargetObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightTowerLockAction& v)
	{
		m_TargetObjId = v.targetobjid();
		m_ObjId = v.objid();
		m_Type = v.type();

	}

private:
	//目标ObjId
	INT32 m_TargetObjId;
public:
	void SetTargetObjId( INT32 v)
	{
		m_TargetObjId=v;
	}
	INT32 GetTargetObjId()
	{
		return m_TargetObjId;
	}
	INT32 GetTargetObjId() const
	{
		return m_TargetObjId;
	}
private:
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
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

};
//节点或副本结束封装类
class FightFinishLevelActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightFinishLevelActionWraper()
	{
		
		m_Result = -1;
		m_Type = 2;
		m_WallObjId = -1;

	}
	//赋值构造函数
	FightFinishLevelActionWraper(const FightFinishLevelAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightFinishLevelAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightFinishLevelAction ToPB() const
	{
		FightFinishLevelAction v;
		v.set_result( m_Result );
		v.set_type( m_Type );
		v.set_wallobjid( m_WallObjId );

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
		FightFinishLevelAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(战局情况) [sint32]</li>\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>WallObjId(节点墙ObjId) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>WallObjId：%di</li>\r\n",m_WallObjId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightFinishLevelAction& v)
	{
		m_Result = v.result();
		m_Type = v.type();
		m_WallObjId = v.wallobjid();

	}

private:
	//战局情况
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
	//节点墙ObjId
	INT32 m_WallObjId;
public:
	void SetWallObjId( INT32 v)
	{
		m_WallObjId=v;
	}
	INT32 GetWallObjId()
	{
		return m_WallObjId;
	}
	INT32 GetWallObjId() const
	{
		return m_WallObjId;
	}

};
//快速杀怪动作封装类
class FightQuickFinishActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightQuickFinishActionWraper()
	{
		
		m_Type = 0;

	}
	//赋值构造函数
	FightQuickFinishActionWraper(const FightQuickFinishAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightQuickFinishAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightQuickFinishAction ToPB() const
	{
		FightQuickFinishAction v;
		v.set_type( m_Type );

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
		FightQuickFinishAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(杀对像类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightQuickFinishAction& v)
	{
		m_Type = v.type();

	}

private:
	//杀对像类型
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

};
//删除对像封装类
class FightRemoveObjActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRemoveObjActionWraper()
	{
		
		m_ObjId = -1;

	}
	//赋值构造函数
	FightRemoveObjActionWraper(const FightRemoveObjAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRemoveObjAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRemoveObjAction ToPB() const
	{
		FightRemoveObjAction v;
		v.set_objid( m_ObjId );

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
		FightRemoveObjAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightRemoveObjAction& v)
	{
		m_ObjId = v.objid();

	}

private:
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}

};
//闪避动作封装类
class FightDodgeActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightDodgeActionWraper()
	{
		
		m_ObjId = -1;
		m_SkillId = -1;
		m_AttackerObjId = -1;
		m_Type = 1;

	}
	//赋值构造函数
	FightDodgeActionWraper(const FightDodgeAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightDodgeAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightDodgeAction ToPB() const
	{
		FightDodgeAction v;
		v.set_objid( m_ObjId );
		v.set_skillid( m_SkillId );
		v.set_attackerobjid( m_AttackerObjId );
		v.set_type( m_Type );

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
		FightDodgeAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillId(技能ID) [sint32]</li>\r\n";
		htmlBuff += "<li>AttackerObjId(攻击者ID) [sint32]</li>\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackerObjId：%di</li>\r\n",m_AttackerObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightDodgeAction& v)
	{
		m_ObjId = v.objid();
		m_SkillId = v.skillid();
		m_AttackerObjId = v.attackerobjid();
		m_Type = v.type();

	}

private:
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
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
	//攻击者ID
	INT32 m_AttackerObjId;
public:
	void SetAttackerObjId( INT32 v)
	{
		m_AttackerObjId=v;
	}
	INT32 GetAttackerObjId()
	{
		return m_AttackerObjId;
	}
	INT32 GetAttackerObjId() const
	{
		return m_AttackerObjId;
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

};
//伤害动作封装类
class FightHurtActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightHurtActionWraper()
	{
		
		m_ObjId = -1;
		m_SkillId = -1;
		m_AttackBack = false;
		m_AttackAir = false;
		m_BackDir = 0;
		m_TargetObjId = -1;
		m_OwnHP = -1;
		m_TargetHP = -1;
		m_OwnHPChange = -1;
		m_TargetHPChange = -1;
		m_IsCrit = false;
		m_TotalDamage = -1;
		m_SegmentIndex = -1;
		m_HurtType = -1;
		m_AttackSegment = -1;
		m_IsHitGround = false;
		m_TargetMaxHP = -1;
		m_EnemyIndex = -1;

	}
	//赋值构造函数
	FightHurtActionWraper(const FightHurtAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightHurtAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightHurtAction ToPB() const
	{
		FightHurtAction v;
		v.set_objid( m_ObjId );
		v.set_skillid( m_SkillId );
		v.set_attackback( m_AttackBack );
		v.set_attackair( m_AttackAir );
		v.set_backdir( m_BackDir );
		v.set_targetobjid( m_TargetObjId );
		v.set_ownhp( m_OwnHP );
		v.set_targethp( m_TargetHP );
		v.set_ownhpchange( m_OwnHPChange );
		v.set_targethpchange( m_TargetHPChange );
		v.set_iscrit( m_IsCrit );
		v.set_totaldamage( m_TotalDamage );
		v.set_segmentindex( m_SegmentIndex );
		v.set_hurttype( m_HurtType );
		v.set_attacksegment( m_AttackSegment );
		v.set_ishitground( m_IsHitGround );
		v.set_targetmaxhp( m_TargetMaxHP );
		v.set_enemyindex( m_EnemyIndex );

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
		FightHurtAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillId(技能ID) [sint32]</li>\r\n";
		htmlBuff += "<li>AttackBack(是否击退) [bool]</li>\r\n";
		htmlBuff += "<li>AttackAir(是否浮空) [bool]</li>\r\n";
		htmlBuff += "<li>BackDir(后退方向) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetObjId(目标ObjId) [sint32]</li>\r\n";
		htmlBuff += "<li>OwnHP(自己的血量) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetHP(目标血量) [sint32]</li>\r\n";
		htmlBuff += "<li>OwnHPChange(自己血量变化) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetHPChange(目标血量变化) [sint32]</li>\r\n";
		htmlBuff += "<li>IsCrit(是否暴击) [bool]</li>\r\n";
		htmlBuff += "<li>TotalDamage(总伤害) [sint32]</li>\r\n";
		htmlBuff += "<li>SegmentIndex(技能动作段索引) [sint32]</li>\r\n";
		htmlBuff += "<li>HurtType(伤害类型) [sint32]</li>\r\n";
		htmlBuff += "<li>AttackSegment(攻击段数) [sint32]</li>\r\n";
		htmlBuff += "<li>IsHitGround(受击后目标倒地) [bool]</li>\r\n";
		htmlBuff += "<li>TargetMaxHP(目标最大血量) [sint32]</li>\r\n";
		htmlBuff += "<li>EnemyIndex(本次攻击敌人计数) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackBack：%di</li>\r\n",m_AttackBack);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackAir：%di</li>\r\n",m_AttackAir);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BackDir：%di</li>\r\n",m_BackDir);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetObjId：%di</li>\r\n",m_TargetObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>OwnHP：%di</li>\r\n",m_OwnHP);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetHP：%di</li>\r\n",m_TargetHP);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>OwnHPChange：%di</li>\r\n",m_OwnHPChange);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetHPChange：%di</li>\r\n",m_TargetHPChange);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsCrit：%di</li>\r\n",m_IsCrit);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TotalDamage：%di</li>\r\n",m_TotalDamage);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SegmentIndex：%di</li>\r\n",m_SegmentIndex);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>HurtType：%di</li>\r\n",m_HurtType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackSegment：%di</li>\r\n",m_AttackSegment);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsHitGround：%di</li>\r\n",m_IsHitGround);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetMaxHP：%di</li>\r\n",m_TargetMaxHP);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EnemyIndex：%di</li>\r\n",m_EnemyIndex);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightHurtAction& v)
	{
		m_ObjId = v.objid();
		m_SkillId = v.skillid();
		m_AttackBack = v.attackback();
		m_AttackAir = v.attackair();
		m_BackDir = v.backdir();
		m_TargetObjId = v.targetobjid();
		m_OwnHP = v.ownhp();
		m_TargetHP = v.targethp();
		m_OwnHPChange = v.ownhpchange();
		m_TargetHPChange = v.targethpchange();
		m_IsCrit = v.iscrit();
		m_TotalDamage = v.totaldamage();
		m_SegmentIndex = v.segmentindex();
		m_HurtType = v.hurttype();
		m_AttackSegment = v.attacksegment();
		m_IsHitGround = v.ishitground();
		m_TargetMaxHP = v.targetmaxhp();
		m_EnemyIndex = v.enemyindex();

	}

private:
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
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
	//是否击退
	bool m_AttackBack;
public:
	void SetAttackBack( bool v)
	{
		m_AttackBack=v;
	}
	bool GetAttackBack()
	{
		return m_AttackBack;
	}
	bool GetAttackBack() const
	{
		return m_AttackBack;
	}
private:
	//是否浮空
	bool m_AttackAir;
public:
	void SetAttackAir( bool v)
	{
		m_AttackAir=v;
	}
	bool GetAttackAir()
	{
		return m_AttackAir;
	}
	bool GetAttackAir() const
	{
		return m_AttackAir;
	}
private:
	//后退方向
	INT32 m_BackDir;
public:
	void SetBackDir( INT32 v)
	{
		m_BackDir=v;
	}
	INT32 GetBackDir()
	{
		return m_BackDir;
	}
	INT32 GetBackDir() const
	{
		return m_BackDir;
	}
private:
	//目标ObjId
	INT32 m_TargetObjId;
public:
	void SetTargetObjId( INT32 v)
	{
		m_TargetObjId=v;
	}
	INT32 GetTargetObjId()
	{
		return m_TargetObjId;
	}
	INT32 GetTargetObjId() const
	{
		return m_TargetObjId;
	}
private:
	//自己的血量
	INT32 m_OwnHP;
public:
	void SetOwnHP( INT32 v)
	{
		m_OwnHP=v;
	}
	INT32 GetOwnHP()
	{
		return m_OwnHP;
	}
	INT32 GetOwnHP() const
	{
		return m_OwnHP;
	}
private:
	//目标血量
	INT32 m_TargetHP;
public:
	void SetTargetHP( INT32 v)
	{
		m_TargetHP=v;
	}
	INT32 GetTargetHP()
	{
		return m_TargetHP;
	}
	INT32 GetTargetHP() const
	{
		return m_TargetHP;
	}
private:
	//自己血量变化
	INT32 m_OwnHPChange;
public:
	void SetOwnHPChange( INT32 v)
	{
		m_OwnHPChange=v;
	}
	INT32 GetOwnHPChange()
	{
		return m_OwnHPChange;
	}
	INT32 GetOwnHPChange() const
	{
		return m_OwnHPChange;
	}
private:
	//目标血量变化
	INT32 m_TargetHPChange;
public:
	void SetTargetHPChange( INT32 v)
	{
		m_TargetHPChange=v;
	}
	INT32 GetTargetHPChange()
	{
		return m_TargetHPChange;
	}
	INT32 GetTargetHPChange() const
	{
		return m_TargetHPChange;
	}
private:
	//是否暴击
	bool m_IsCrit;
public:
	void SetIsCrit( bool v)
	{
		m_IsCrit=v;
	}
	bool GetIsCrit()
	{
		return m_IsCrit;
	}
	bool GetIsCrit() const
	{
		return m_IsCrit;
	}
private:
	//总伤害
	INT32 m_TotalDamage;
public:
	void SetTotalDamage( INT32 v)
	{
		m_TotalDamage=v;
	}
	INT32 GetTotalDamage()
	{
		return m_TotalDamage;
	}
	INT32 GetTotalDamage() const
	{
		return m_TotalDamage;
	}
private:
	//技能动作段索引
	INT32 m_SegmentIndex;
public:
	void SetSegmentIndex( INT32 v)
	{
		m_SegmentIndex=v;
	}
	INT32 GetSegmentIndex()
	{
		return m_SegmentIndex;
	}
	INT32 GetSegmentIndex() const
	{
		return m_SegmentIndex;
	}
private:
	//伤害类型
	INT32 m_HurtType;
public:
	void SetHurtType( INT32 v)
	{
		m_HurtType=v;
	}
	INT32 GetHurtType()
	{
		return m_HurtType;
	}
	INT32 GetHurtType() const
	{
		return m_HurtType;
	}
private:
	//攻击段数
	INT32 m_AttackSegment;
public:
	void SetAttackSegment( INT32 v)
	{
		m_AttackSegment=v;
	}
	INT32 GetAttackSegment()
	{
		return m_AttackSegment;
	}
	INT32 GetAttackSegment() const
	{
		return m_AttackSegment;
	}
private:
	//受击后目标倒地
	bool m_IsHitGround;
public:
	void SetIsHitGround( bool v)
	{
		m_IsHitGround=v;
	}
	bool GetIsHitGround()
	{
		return m_IsHitGround;
	}
	bool GetIsHitGround() const
	{
		return m_IsHitGround;
	}
private:
	//目标最大血量
	INT32 m_TargetMaxHP;
public:
	void SetTargetMaxHP( INT32 v)
	{
		m_TargetMaxHP=v;
	}
	INT32 GetTargetMaxHP()
	{
		return m_TargetMaxHP;
	}
	INT32 GetTargetMaxHP() const
	{
		return m_TargetMaxHP;
	}
private:
	//本次攻击敌人计数
	INT32 m_EnemyIndex;
public:
	void SetEnemyIndex( INT32 v)
	{
		m_EnemyIndex=v;
	}
	INT32 GetEnemyIndex()
	{
		return m_EnemyIndex;
	}
	INT32 GetEnemyIndex() const
	{
		return m_EnemyIndex;
	}

};
//暴风旗信息封装类
class FightStormFlagActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightStormFlagActionWraper()
	{
		
		m_Type = 1;
		m_Time = -1;
		m_FlagObjId = -1;
		m_ObjId1 = -1;
		m_ObjId2 = -1;
		m_Result = -1;

	}
	//赋值构造函数
	FightStormFlagActionWraper(const FightStormFlagAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightStormFlagAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightStormFlagAction ToPB() const
	{
		FightStormFlagAction v;
		v.set_type( m_Type );
		v.set_time( m_Time );
		v.set_flagobjid( m_FlagObjId );
		v.set_objid1( m_ObjId1 );
		v.set_objid2( m_ObjId2 );
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
		FightStormFlagAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(动作类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(时间) [sint32]</li>\r\n";
		htmlBuff += "<li>FlagObjId(旗ObjId) [sint32]</li>\r\n";
		htmlBuff += "<li>ObjId1(ObjId1) [sint32]</li>\r\n";
		htmlBuff += "<li>ObjId2(ObjId2) [sint32]</li>\r\n";
		htmlBuff += "<li>Result(操作旗子结果) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>FlagObjId：%di</li>\r\n",m_FlagObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ObjId1：%di</li>\r\n",m_ObjId1);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ObjId2：%di</li>\r\n",m_ObjId2);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightStormFlagAction& v)
	{
		m_Type = v.type();
		m_Time = v.time();
		m_FlagObjId = v.flagobjid();
		m_ObjId1 = v.objid1();
		m_ObjId2 = v.objid2();
		m_Result = v.result();

	}

private:
	//动作类型
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
	//时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}
private:
	//旗ObjId
	INT32 m_FlagObjId;
public:
	void SetFlagObjId( INT32 v)
	{
		m_FlagObjId=v;
	}
	INT32 GetFlagObjId()
	{
		return m_FlagObjId;
	}
	INT32 GetFlagObjId() const
	{
		return m_FlagObjId;
	}
private:
	//ObjId1
	INT32 m_ObjId1;
public:
	void SetObjId1( INT32 v)
	{
		m_ObjId1=v;
	}
	INT32 GetObjId1()
	{
		return m_ObjId1;
	}
	INT32 GetObjId1() const
	{
		return m_ObjId1;
	}
private:
	//ObjId2
	INT32 m_ObjId2;
public:
	void SetObjId2( INT32 v)
	{
		m_ObjId2=v;
	}
	INT32 GetObjId2()
	{
		return m_ObjId2;
	}
	INT32 GetObjId2() const
	{
		return m_ObjId2;
	}
private:
	//操作旗子结果
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
//暴风资源信息封装类
class FightStormResActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightStormResActionWraper()
	{
		
		m_BaseId = -1;
		m_CampId = -1;
		m_UpdateNum = -1;
		m_TotalNum = -1;

	}
	//赋值构造函数
	FightStormResActionWraper(const FightStormResAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightStormResAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightStormResAction ToPB() const
	{
		FightStormResAction v;
		v.set_baseid( m_BaseId );
		v.set_campid( m_CampId );
		v.set_updatenum( m_UpdateNum );
		v.set_totalnum( m_TotalNum );

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
		FightStormResAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>BaseId(基地ID) [sint32]</li>\r\n";
		htmlBuff += "<li>CampId(归属阵营ID) [sint32]</li>\r\n";
		htmlBuff += "<li>UpdateNum(资源更新量) [sint32]</li>\r\n";
		htmlBuff += "<li>TotalNum(资源总量) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>BaseId：%di</li>\r\n",m_BaseId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CampId：%di</li>\r\n",m_CampId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UpdateNum：%di</li>\r\n",m_UpdateNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TotalNum：%di</li>\r\n",m_TotalNum);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightStormResAction& v)
	{
		m_BaseId = v.baseid();
		m_CampId = v.campid();
		m_UpdateNum = v.updatenum();
		m_TotalNum = v.totalnum();

	}

private:
	//基地ID
	INT32 m_BaseId;
public:
	void SetBaseId( INT32 v)
	{
		m_BaseId=v;
	}
	INT32 GetBaseId()
	{
		return m_BaseId;
	}
	INT32 GetBaseId() const
	{
		return m_BaseId;
	}
private:
	//归属阵营ID
	INT32 m_CampId;
public:
	void SetCampId( INT32 v)
	{
		m_CampId=v;
	}
	INT32 GetCampId()
	{
		return m_CampId;
	}
	INT32 GetCampId() const
	{
		return m_CampId;
	}
private:
	//资源更新量
	INT32 m_UpdateNum;
public:
	void SetUpdateNum( INT32 v)
	{
		m_UpdateNum=v;
	}
	INT32 GetUpdateNum()
	{
		return m_UpdateNum;
	}
	INT32 GetUpdateNum() const
	{
		return m_UpdateNum;
	}
private:
	//资源总量
	INT32 m_TotalNum;
public:
	void SetTotalNum( INT32 v)
	{
		m_TotalNum=v;
	}
	INT32 GetTotalNum()
	{
		return m_TotalNum;
	}
	INT32 GetTotalNum() const
	{
		return m_TotalNum;
	}

};
//暴风基地信息封装类
class FightStormBaseActionWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightStormBaseActionWraper()
	{
		
		m_Type = -1;
		m_Mark = -1;
		m_CampId = -1;
		m_ObjId = -1;
		m_ID = -1;
		m_Name = "";

	}
	//赋值构造函数
	FightStormBaseActionWraper(const FightStormBaseAction& v){ Init(v); }
	//等号重载函数
	void operator = (const FightStormBaseAction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightStormBaseAction ToPB() const
	{
		FightStormBaseAction v;
		v.set_type( m_Type );
		v.set_mark( m_Mark );
		v.set_campid( m_CampId );
		v.set_objid( m_ObjId );
		v.set_id( m_ID );
		v.set_name( m_Name );

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
		FightStormBaseAction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Mark(标记位置) [sint32]</li>\r\n";
		htmlBuff += "<li>CampId(归属阵营ID) [sint32]</li>\r\n";
		htmlBuff += "<li>ObjId(obj id) [sint32]</li>\r\n";
		htmlBuff += "<li>ID(ID) [sint32]</li>\r\n";
		htmlBuff += "<li>Name(Name) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Mark：%di</li>\r\n",m_Mark);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CampId：%di</li>\r\n",m_CampId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ID：%di</li>\r\n",m_ID);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Name：\""+m_Name+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightStormBaseAction& v)
	{
		m_Type = v.type();
		m_Mark = v.mark();
		m_CampId = v.campid();
		m_ObjId = v.objid();
		m_ID = v.id();
		m_Name = v.name();

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
	//标记位置
	INT32 m_Mark;
public:
	void SetMark( INT32 v)
	{
		m_Mark=v;
	}
	INT32 GetMark()
	{
		return m_Mark;
	}
	INT32 GetMark() const
	{
		return m_Mark;
	}
private:
	//归属阵营ID
	INT32 m_CampId;
public:
	void SetCampId( INT32 v)
	{
		m_CampId=v;
	}
	INT32 GetCampId()
	{
		return m_CampId;
	}
	INT32 GetCampId() const
	{
		return m_CampId;
	}
private:
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
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

};
//战斗结果通知封装类
class FightRpcResultNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcResultNotifyWraper()
	{
		
		m_Result = -1;
		m_DengeonId = -1;
		m_Star = -1;
		m_FightTime = -1;
		m_FirstStarLight = -1;
		m_SecondStarLight = -1;
		m_ThirdStarLight = -1;

	}
	//赋值构造函数
	FightRpcResultNotifyWraper(const FightRpcResultNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcResultNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcResultNotify ToPB() const
	{
		FightRpcResultNotify v;
		v.set_result( m_Result );
		v.set_dengeonid( m_DengeonId );
		v.set_star( m_Star );
		v.set_fighttime( m_FightTime );
		v.mutable_prizelist()->Reserve(m_PrizeList.size());
		for (int i=0; i<(int)m_PrizeList.size(); i++)
		{
			*v.add_prizelist() = m_PrizeList[i].ToPB();
		}
		v.mutable_killlist()->Reserve(m_KillList.size());
		for (int i=0; i<(int)m_KillList.size(); i++)
		{
			*v.add_killlist() = m_KillList[i].ToPB();
		}
		v.set_firststarlight( m_FirstStarLight );
		v.set_secondstarlight( m_SecondStarLight );
		v.set_thirdstarlight( m_ThirdStarLight );

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
		FightRpcResultNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(结果) [sint32]</li>\r\n";
		htmlBuff += "<li>DengeonId(副本Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Star(星级) [sint32]</li>\r\n";
		htmlBuff += "<li>FightTime(战斗时间) [sint32]</li>\r\n";
		htmlBuff += "<li>PrizeList(奖励列表) [PrizeInfo] Array</li>\r\n";
		htmlBuff += "<li>KillList(杀戮列表) [KillInfo] Array</li>\r\n";
		htmlBuff += "<li>FirstStarLight(第一颗星是否亮了) [sint32]</li>\r\n";
		htmlBuff += "<li>SecondStarLight(第二颗星是否亮了) [sint32]</li>\r\n";
		htmlBuff += "<li>ThirdStarLight(第三颗星是否亮了) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DengeonId：%di</li>\r\n",m_DengeonId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Star：%di</li>\r\n",m_Star);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>FightTime：%di</li>\r\n",m_FightTime);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PrizeList：</li>\r\n";
		if( m_PrizeList.size()>0) htmlBuff += m_PrizeList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_PrizeList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_PrizeList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>KillList：</li>\r\n";
		if( m_KillList.size()>0) htmlBuff += m_KillList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_KillList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_KillList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>FirstStarLight：%di</li>\r\n",m_FirstStarLight);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SecondStarLight：%di</li>\r\n",m_SecondStarLight);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ThirdStarLight：%di</li>\r\n",m_ThirdStarLight);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightRpcResultNotify& v)
	{
		m_Result = v.result();
		m_DengeonId = v.dengeonid();
		m_Star = v.star();
		m_FightTime = v.fighttime();
		m_PrizeList.clear();
		m_PrizeList.reserve(v.prizelist_size());
		for( int i=0; i<v.prizelist_size(); i++)
			m_PrizeList.push_back(v.prizelist(i));
		m_KillList.clear();
		m_KillList.reserve(v.killlist_size());
		for( int i=0; i<v.killlist_size(); i++)
			m_KillList.push_back(v.killlist(i));
		m_FirstStarLight = v.firststarlight();
		m_SecondStarLight = v.secondstarlight();
		m_ThirdStarLight = v.thirdstarlight();

	}

private:
	//结果
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
	//副本Id
	INT32 m_DengeonId;
public:
	void SetDengeonId( INT32 v)
	{
		m_DengeonId=v;
	}
	INT32 GetDengeonId()
	{
		return m_DengeonId;
	}
	INT32 GetDengeonId() const
	{
		return m_DengeonId;
	}
private:
	//星级
	INT32 m_Star;
public:
	void SetStar( INT32 v)
	{
		m_Star=v;
	}
	INT32 GetStar()
	{
		return m_Star;
	}
	INT32 GetStar() const
	{
		return m_Star;
	}
private:
	//战斗时间
	INT32 m_FightTime;
public:
	void SetFightTime( INT32 v)
	{
		m_FightTime=v;
	}
	INT32 GetFightTime()
	{
		return m_FightTime;
	}
	INT32 GetFightTime() const
	{
		return m_FightTime;
	}
private:
	//奖励列表
	vector<FightPrizeInfoWraper> m_PrizeList;
public:
	int SizePrizeList()
	{
		return m_PrizeList.size();
	}
	const vector<FightPrizeInfoWraper>& GetPrizeList() const
	{
		return m_PrizeList;
	}
	FightPrizeInfoWraper GetPrizeList(int Index) const
	{
		if(Index<0 || Index>=(int)m_PrizeList.size())
		{
			assert(false);
			return FightPrizeInfoWraper();
		}
		return m_PrizeList[Index];
	}
	void SetPrizeList( const vector<FightPrizeInfoWraper>& v )
	{
		m_PrizeList=v;
	}
	void ClearPrizeList( )
	{
		m_PrizeList.clear();
	}
	void SetPrizeList( int Index, const FightPrizeInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_PrizeList.size())
		{
			assert(false);
			return;
		}
		m_PrizeList[Index] = v;
	}
	void AddPrizeList( const FightPrizeInfoWraper& v )
	{
		m_PrizeList.push_back(v);
	}
private:
	//杀戮列表
	vector<FightKillInfoWraper> m_KillList;
public:
	int SizeKillList()
	{
		return m_KillList.size();
	}
	const vector<FightKillInfoWraper>& GetKillList() const
	{
		return m_KillList;
	}
	FightKillInfoWraper GetKillList(int Index) const
	{
		if(Index<0 || Index>=(int)m_KillList.size())
		{
			assert(false);
			return FightKillInfoWraper();
		}
		return m_KillList[Index];
	}
	void SetKillList( const vector<FightKillInfoWraper>& v )
	{
		m_KillList=v;
	}
	void ClearKillList( )
	{
		m_KillList.clear();
	}
	void SetKillList( int Index, const FightKillInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_KillList.size())
		{
			assert(false);
			return;
		}
		m_KillList[Index] = v;
	}
	void AddKillList( const FightKillInfoWraper& v )
	{
		m_KillList.push_back(v);
	}
private:
	//第一颗星是否亮了
	INT32 m_FirstStarLight;
public:
	void SetFirstStarLight( INT32 v)
	{
		m_FirstStarLight=v;
	}
	INT32 GetFirstStarLight()
	{
		return m_FirstStarLight;
	}
	INT32 GetFirstStarLight() const
	{
		return m_FirstStarLight;
	}
private:
	//第二颗星是否亮了
	INT32 m_SecondStarLight;
public:
	void SetSecondStarLight( INT32 v)
	{
		m_SecondStarLight=v;
	}
	INT32 GetSecondStarLight()
	{
		return m_SecondStarLight;
	}
	INT32 GetSecondStarLight() const
	{
		return m_SecondStarLight;
	}
private:
	//第三颗星是否亮了
	INT32 m_ThirdStarLight;
public:
	void SetThirdStarLight( INT32 v)
	{
		m_ThirdStarLight=v;
	}
	INT32 GetThirdStarLight()
	{
		return m_ThirdStarLight;
	}
	INT32 GetThirdStarLight() const
	{
		return m_ThirdStarLight;
	}

};
//动作通知封装类
class FightRpcActionNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcActionNotifyWraper()
	{
		
		m_Data = "";
		m_Frame = -1;

	}
	//赋值构造函数
	FightRpcActionNotifyWraper(const FightRpcActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcActionNotify ToPB() const
	{
		FightRpcActionNotify v;
		v.set_data( m_Data );
		v.set_frame( m_Frame );

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
		FightRpcActionNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Data(动作数据) [bytes]</li>\r\n";
		htmlBuff += "<li>Frame(当前帧号) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>Data：\"...\"</li>\r\n";
		tmpLine.Fmt("<li>Frame：%di</li>\r\n",m_Frame);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightRpcActionNotify& v)
	{
		m_Data = v.data();
		m_Frame = v.frame();

	}

private:
	//动作数据
	string m_Data;
public:
	void SetData( const string& v)
	{
		m_Data=v;
	}
	string GetData()
	{
		return m_Data;
	}
	string GetData() const
	{
		return m_Data;
	}
private:
	//当前帧号
	INT32 m_Frame;
public:
	void SetFrame( INT32 v)
	{
		m_Frame=v;
	}
	INT32 GetFrame()
	{
		return m_Frame;
	}
	INT32 GetFrame() const
	{
		return m_Frame;
	}

};
//准备就绪回应封装类
class FightRpcReadyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcReadyReplyWraper()
	{
		
		m_Result = -9999;
		m_Tick = -1;
		m_RandNum = -1;
		m_IdHelper = -1;

	}
	//赋值构造函数
	FightRpcReadyReplyWraper(const FightRpcReadyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcReadyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcReadyReply ToPB() const
	{
		FightRpcReadyReply v;
		v.set_result( m_Result );
		v.set_tick( m_Tick );
		v.set_randnum( m_RandNum );
		v.set_idhelper( m_IdHelper );
		v.mutable_actionarr()->Reserve(m_ActionArr.size());
		for (int i=0; i<(int)m_ActionArr.size(); i++)
		{
			v.add_actionarr( m_ActionArr[i]);
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
		FightRpcReadyReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Tick(当前Tick) [sint32]</li>\r\n";
		htmlBuff += "<li>RandNum(当前随机数) [sint32]</li>\r\n";
		htmlBuff += "<li>IdHelper(ID管理器的值) [sint32]</li>\r\n";
		htmlBuff += "<li>ActionArr(创建的Action列表) [bytes] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Tick：%di</li>\r\n",m_Tick);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RandNum：%di</li>\r\n",m_RandNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IdHelper：%di</li>\r\n",m_IdHelper);
		htmlBuff += tmpLine;
		htmlBuff += "<li>ActionArr(创建的Action列表) [bytes]：</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightRpcReadyReply& v)
	{
		m_Result = v.result();
		m_Tick = v.tick();
		m_RandNum = v.randnum();
		m_IdHelper = v.idhelper();
		m_ActionArr.clear();
		m_ActionArr.reserve(v.actionarr_size());
		for( int i=0; i<v.actionarr_size(); i++)
			m_ActionArr.push_back(v.actionarr(i));

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
	//当前Tick
	INT32 m_Tick;
public:
	void SetTick( INT32 v)
	{
		m_Tick=v;
	}
	INT32 GetTick()
	{
		return m_Tick;
	}
	INT32 GetTick() const
	{
		return m_Tick;
	}
private:
	//当前随机数
	INT32 m_RandNum;
public:
	void SetRandNum( INT32 v)
	{
		m_RandNum=v;
	}
	INT32 GetRandNum()
	{
		return m_RandNum;
	}
	INT32 GetRandNum() const
	{
		return m_RandNum;
	}
private:
	//ID管理器的值
	INT32 m_IdHelper;
public:
	void SetIdHelper( INT32 v)
	{
		m_IdHelper=v;
	}
	INT32 GetIdHelper()
	{
		return m_IdHelper;
	}
	INT32 GetIdHelper() const
	{
		return m_IdHelper;
	}
private:
	//创建的Action列表
	vector<string> m_ActionArr;
public:
	int SizeActionArr()
	{
		return m_ActionArr.size();
	}
	const vector<string>& GetActionArr() const
	{
		return m_ActionArr;
	}
	string GetActionArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_ActionArr.size())
		{
			assert(false);
			return string();
		}
		return m_ActionArr[Index];
	}
	void SetActionArr( const vector<string>& v )
	{
		m_ActionArr=v;
	}
	void ClearActionArr( )
	{
		m_ActionArr.clear();
	}
	void SetActionArr( int Index, const string& v )
	{
		if(Index<0 || Index>=(int)m_ActionArr.size())
		{
			assert(false);
			return;
		}
		m_ActionArr[Index] = v;
	}
	void AddActionArr( const string& v )
	{
		m_ActionArr.push_back(v);
	}

};
//战斗开始通知封装类
class FightRpcStartNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcStartNotifyWraper()
	{
		

	}
	//赋值构造函数
	FightRpcStartNotifyWraper(const FightRpcStartNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcStartNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcStartNotify ToPB() const
	{
		FightRpcStartNotify v;

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
		FightRpcStartNotify pb;
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
	void Init(const FightRpcStartNotify& v)
	{

	}


};
//进入副本回应封装类
class FightRpcEnterReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcEnterReplyWraper()
	{
		
		m_Result = -9999;
		m_Tick = -1;
		m_RandNum = -1;
		m_IdHelper = -1;

	}
	//赋值构造函数
	FightRpcEnterReplyWraper(const FightRpcEnterReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcEnterReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcEnterReply ToPB() const
	{
		FightRpcEnterReply v;
		v.set_result( m_Result );
		v.set_tick( m_Tick );
		v.set_randnum( m_RandNum );
		v.set_idhelper( m_IdHelper );
		v.mutable_actionarr()->Reserve(m_ActionArr.size());
		for (int i=0; i<(int)m_ActionArr.size(); i++)
		{
			v.add_actionarr( m_ActionArr[i]);
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
		FightRpcEnterReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Tick(当前Tick) [sint32]</li>\r\n";
		htmlBuff += "<li>RandNum(当前随机数) [sint32]</li>\r\n";
		htmlBuff += "<li>IdHelper(ID管理器的值) [sint32]</li>\r\n";
		htmlBuff += "<li>ActionArr(创建的Action列表) [bytes] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Tick：%di</li>\r\n",m_Tick);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RandNum：%di</li>\r\n",m_RandNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IdHelper：%di</li>\r\n",m_IdHelper);
		htmlBuff += tmpLine;
		htmlBuff += "<li>ActionArr(创建的Action列表) [bytes]：</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightRpcEnterReply& v)
	{
		m_Result = v.result();
		m_Tick = v.tick();
		m_RandNum = v.randnum();
		m_IdHelper = v.idhelper();
		m_ActionArr.clear();
		m_ActionArr.reserve(v.actionarr_size());
		for( int i=0; i<v.actionarr_size(); i++)
			m_ActionArr.push_back(v.actionarr(i));

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
	//当前Tick
	INT32 m_Tick;
public:
	void SetTick( INT32 v)
	{
		m_Tick=v;
	}
	INT32 GetTick()
	{
		return m_Tick;
	}
	INT32 GetTick() const
	{
		return m_Tick;
	}
private:
	//当前随机数
	INT32 m_RandNum;
public:
	void SetRandNum( INT32 v)
	{
		m_RandNum=v;
	}
	INT32 GetRandNum()
	{
		return m_RandNum;
	}
	INT32 GetRandNum() const
	{
		return m_RandNum;
	}
private:
	//ID管理器的值
	INT32 m_IdHelper;
public:
	void SetIdHelper( INT32 v)
	{
		m_IdHelper=v;
	}
	INT32 GetIdHelper()
	{
		return m_IdHelper;
	}
	INT32 GetIdHelper() const
	{
		return m_IdHelper;
	}
private:
	//创建的Action列表
	vector<string> m_ActionArr;
public:
	int SizeActionArr()
	{
		return m_ActionArr.size();
	}
	const vector<string>& GetActionArr() const
	{
		return m_ActionArr;
	}
	string GetActionArr(int Index) const
	{
		if(Index<0 || Index>=(int)m_ActionArr.size())
		{
			assert(false);
			return string();
		}
		return m_ActionArr[Index];
	}
	void SetActionArr( const vector<string>& v )
	{
		m_ActionArr=v;
	}
	void ClearActionArr( )
	{
		m_ActionArr.clear();
	}
	void SetActionArr( int Index, const string& v )
	{
		if(Index<0 || Index>=(int)m_ActionArr.size())
		{
			assert(false);
			return;
		}
		m_ActionArr[Index] = v;
	}
	void AddActionArr( const string& v )
	{
		m_ActionArr.push_back(v);
	}

};
//进入副本请求封装类
class FightRpcEnterAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcEnterAskWraper()
	{
		
		m_UserId = -1;
		m_DungeonKey = "";
		m_SessionKey = "";

	}
	//赋值构造函数
	FightRpcEnterAskWraper(const FightRpcEnterAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcEnterAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcEnterAsk ToPB() const
	{
		FightRpcEnterAsk v;
		v.set_userid( m_UserId );
		v.set_dungeonkey( m_DungeonKey );
		v.set_sessionkey( m_SessionKey );

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
		FightRpcEnterAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户id) [sint64]</li>\r\n";
		htmlBuff += "<li>DungeonKey(副本钥匙) [string]</li>\r\n";
		htmlBuff += "<li>SessionKey(SessionKey) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>DungeonKey：\""+m_DungeonKey+"\"</li>\r\n";
		htmlBuff += "<li>SessionKey：\""+m_SessionKey+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const FightRpcEnterAsk& v)
	{
		m_UserId = v.userid();
		m_DungeonKey = v.dungeonkey();
		m_SessionKey = v.sessionkey();

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
	//副本钥匙
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
private:
	//SessionKey
	string m_SessionKey;
public:
	void SetSessionKey( const string& v)
	{
		m_SessionKey=v;
	}
	string GetSessionKey()
	{
		return m_SessionKey;
	}
	string GetSessionKey() const
	{
		return m_SessionKey;
	}

};
//准备就绪请求封装类
class FightRpcReadyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcReadyAskWraper()
	{
		

	}
	//赋值构造函数
	FightRpcReadyAskWraper(const FightRpcReadyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcReadyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcReadyAsk ToPB() const
	{
		FightRpcReadyAsk v;

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
		FightRpcReadyAsk pb;
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
	void Init(const FightRpcReadyAsk& v)
	{

	}


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<FightRpcReadyAskWraper>{ enum{ID=RPC_CODE_FIGHT_READY_REQUEST};};
template<> struct MessageIdT<FightRpcReadyReplyWraper>{ enum{ID=RPC_CODE_FIGHT_READY_REQUEST};};
template<> struct MessageIdT<FightRpcActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_ACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcResultNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_RESULT_NOTIFY};};
template<> struct MessageIdT<FightRpcEnterAskWraper>{ enum{ID=RPC_CODE_FIGHT_ENTER_REQUEST};};
template<> struct MessageIdT<FightRpcEnterReplyWraper>{ enum{ID=RPC_CODE_FIGHT_ENTER_REQUEST};};
template<> struct MessageIdT<FightRpcStartNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_START_NOTIFY};};


#endif
