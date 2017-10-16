/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperTask.h
* Author:       甘业清
* Description:  任务同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_TASK_H
#define __SYNC_WRAPER_TASK_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "TaskV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//任务目标对象封装类
class TaskTaskTargetObjWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	TaskTaskTargetObjWraperV1()
	{
		
		m_TargetType = -1;
		m_TargetId = -1;
		m_CurNum = -1;
		m_TotalNum = -1;
		m_Id = -1;

	}
	//赋值构造函数
	TaskTaskTargetObjWraperV1(const TaskTaskTargetObjV1& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskTaskTargetObjV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskTaskTargetObjV1 ToPB() const
	{
		TaskTaskTargetObjV1 v;
		v.set_targettype( m_TargetType );
		v.set_targetid( m_TargetId );
		v.set_curnum( m_CurNum );
		v.set_totalnum( m_TotalNum );
		v.set_id( m_Id );

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
		TaskTaskTargetObjV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TargetType(目标类型) [sint32]</li>\r\n";
		htmlBuff += "<li>TargetId(目标Id) [sint32]</li>\r\n";
		htmlBuff += "<li>CurNum(当前数量) [sint32]</li>\r\n";
		htmlBuff += "<li>TotalNum(总数量) [sint32]</li>\r\n";
		htmlBuff += "<li>Id(第几个目标) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TargetType：%di</li>\r\n",m_TargetType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TargetId：%di</li>\r\n",m_TargetId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CurNum：%di</li>\r\n",m_CurNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TotalNum：%di</li>\r\n",m_TotalNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskTaskTargetObjV1& v)
	{
		m_TargetType = v.targettype();
		m_TargetId = v.targetid();
		m_CurNum = v.curnum();
		m_TotalNum = v.totalnum();
		m_Id = v.id();

	}

private:
	//目标类型
	INT32 m_TargetType;
public:
	void SetTargetType( INT32 v)
	{
		m_TargetType=v;
	}
	INT32 GetTargetType()
	{
		return m_TargetType;
	}
	INT32 GetTargetType() const
	{
		return m_TargetType;
	}
private:
	//目标Id
	INT32 m_TargetId;
public:
	void SetTargetId( INT32 v)
	{
		m_TargetId=v;
	}
	INT32 GetTargetId()
	{
		return m_TargetId;
	}
	INT32 GetTargetId() const
	{
		return m_TargetId;
	}
private:
	//当前数量
	INT32 m_CurNum;
public:
	void SetCurNum( INT32 v)
	{
		m_CurNum=v;
	}
	INT32 GetCurNum()
	{
		return m_CurNum;
	}
	INT32 GetCurNum() const
	{
		return m_CurNum;
	}
private:
	//总数量
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
	//第几个目标
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

};
//未接任务对象封装类
class TaskUnacceptedTaskObjWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	TaskUnacceptedTaskObjWraperV1()
	{
		
		m_TaskId = -1;
		m_TaskType = -1;

	}
	//赋值构造函数
	TaskUnacceptedTaskObjWraperV1(const TaskUnacceptedTaskObjV1& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskUnacceptedTaskObjV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskUnacceptedTaskObjV1 ToPB() const
	{
		TaskUnacceptedTaskObjV1 v;
		v.set_taskid( m_TaskId );
		v.set_tasktype( m_TaskType );

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
		TaskUnacceptedTaskObjV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TaskId(任务Id) [sint32]</li>\r\n";
		htmlBuff += "<li>TaskType(任务类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TaskId：%di</li>\r\n",m_TaskId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TaskType：%di</li>\r\n",m_TaskType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskUnacceptedTaskObjV1& v)
	{
		m_TaskId = v.taskid();
		m_TaskType = v.tasktype();

	}

private:
	//任务Id
	INT32 m_TaskId;
public:
	void SetTaskId( INT32 v)
	{
		m_TaskId=v;
	}
	INT32 GetTaskId()
	{
		return m_TaskId;
	}
	INT32 GetTaskId() const
	{
		return m_TaskId;
	}
private:
	//任务类型
	INT32 m_TaskType;
public:
	void SetTaskType( INT32 v)
	{
		m_TaskType=v;
	}
	INT32 GetTaskType()
	{
		return m_TaskType;
	}
	INT32 GetTaskType() const
	{
		return m_TaskType;
	}

};
//主线任务对象封装类
class TaskTaskObjWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	TaskTaskObjWraperV1()
	{
		
		m_TaskId = -1;
		m_TaskState = -1;
		m_TaskType = -1;
		m_IsOrder = true;
		m_IsAutoSubmit = false;
		m_CollectionId = -1;
		m_DungeonId = -1;
		m_Guild = -1;
		m_ObjId = -1;

	}
	//赋值构造函数
	TaskTaskObjWraperV1(const TaskTaskObjV1& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskTaskObjV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskTaskObjV1 ToPB() const
	{
		TaskTaskObjV1 v;
		v.set_taskid( m_TaskId );
		v.set_taskstate( m_TaskState );
		v.mutable_tasktarget()->Reserve(m_TaskTarget.size());
		for (int i=0; i<(int)m_TaskTarget.size(); i++)
		{
			*v.add_tasktarget() = m_TaskTarget[i].ToPB();
		}
		v.set_tasktype( m_TaskType );
		v.set_isorder( m_IsOrder );
		v.set_isautosubmit( m_IsAutoSubmit );
		v.set_collectionid( m_CollectionId );
		v.set_dungeonid( m_DungeonId );
		v.set_guild( m_Guild );
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
		TaskTaskObjV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TaskId(任务Id) [sint32]</li>\r\n";
		htmlBuff += "<li>TaskState(任务状态) [sint32]</li>\r\n";
		htmlBuff += "<li>TaskTarget(任务目标) [TaskTargetObj] Array</li>\r\n";
		htmlBuff += "<li>TaskType(任务类型) [sint32]</li>\r\n";
		htmlBuff += "<li>IsOrder(顺序完成目标) [bool]</li>\r\n";
		htmlBuff += "<li>IsAutoSubmit(是否自动提交) [bool]</li>\r\n";
		htmlBuff += "<li>CollectionId(采集物Id) [sint32]</li>\r\n";
		htmlBuff += "<li>DungeonId(任务条件所在副本Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Guild(帮派Id) [sint32]</li>\r\n";
		htmlBuff += "<li>ObjId(ObjId) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TaskId：%di</li>\r\n",m_TaskId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TaskState：%di</li>\r\n",m_TaskState);
		htmlBuff += tmpLine;
		htmlBuff += "<li>TaskTarget：</li>\r\n";
		if( m_TaskTarget.size()>0) htmlBuff += m_TaskTarget[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_TaskTarget.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_TaskTarget[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>TaskType：%di</li>\r\n",m_TaskType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsOrder：%di</li>\r\n",m_IsOrder);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsAutoSubmit：%di</li>\r\n",m_IsAutoSubmit);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CollectionId：%di</li>\r\n",m_CollectionId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DungeonId：%di</li>\r\n",m_DungeonId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Guild：%di</li>\r\n",m_Guild);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ObjId：%di</li>\r\n",m_ObjId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskTaskObjV1& v)
	{
		m_TaskId = v.taskid();
		m_TaskState = v.taskstate();
		m_TaskTarget.clear();
		m_TaskTarget.reserve(v.tasktarget_size());
		for( int i=0; i<v.tasktarget_size(); i++)
			m_TaskTarget.push_back(v.tasktarget(i));
		m_TaskType = v.tasktype();
		m_IsOrder = v.isorder();
		m_IsAutoSubmit = v.isautosubmit();
		m_CollectionId = v.collectionid();
		m_DungeonId = v.dungeonid();
		m_Guild = v.guild();
		m_ObjId = v.objid();

	}

private:
	//任务Id
	INT32 m_TaskId;
public:
	void SetTaskId( INT32 v)
	{
		m_TaskId=v;
	}
	INT32 GetTaskId()
	{
		return m_TaskId;
	}
	INT32 GetTaskId() const
	{
		return m_TaskId;
	}
private:
	//任务状态
	INT32 m_TaskState;
public:
	void SetTaskState( INT32 v)
	{
		m_TaskState=v;
	}
	INT32 GetTaskState()
	{
		return m_TaskState;
	}
	INT32 GetTaskState() const
	{
		return m_TaskState;
	}
private:
	//任务目标
	vector<TaskTaskTargetObjWraperV1> m_TaskTarget;
public:
	int SizeTaskTarget()
	{
		return m_TaskTarget.size();
	}
	const vector<TaskTaskTargetObjWraperV1>& GetTaskTarget() const
	{
		return m_TaskTarget;
	}
	TaskTaskTargetObjWraperV1 GetTaskTarget(int Index) const
	{
		if(Index<0 || Index>=(int)m_TaskTarget.size())
		{
			assert(false);
			return TaskTaskTargetObjWraperV1();
		}
		return m_TaskTarget[Index];
	}
	void SetTaskTarget( const vector<TaskTaskTargetObjWraperV1>& v )
	{
		m_TaskTarget=v;
	}
	void ClearTaskTarget( )
	{
		m_TaskTarget.clear();
	}
	void SetTaskTarget( int Index, const TaskTaskTargetObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_TaskTarget.size())
		{
			assert(false);
			return;
		}
		m_TaskTarget[Index] = v;
	}
	void AddTaskTarget( const TaskTaskTargetObjWraperV1& v )
	{
		m_TaskTarget.push_back(v);
	}
private:
	//任务类型
	INT32 m_TaskType;
public:
	void SetTaskType( INT32 v)
	{
		m_TaskType=v;
	}
	INT32 GetTaskType()
	{
		return m_TaskType;
	}
	INT32 GetTaskType() const
	{
		return m_TaskType;
	}
private:
	//顺序完成目标
	bool m_IsOrder;
public:
	void SetIsOrder( bool v)
	{
		m_IsOrder=v;
	}
	bool GetIsOrder()
	{
		return m_IsOrder;
	}
	bool GetIsOrder() const
	{
		return m_IsOrder;
	}
private:
	//是否自动提交
	bool m_IsAutoSubmit;
public:
	void SetIsAutoSubmit( bool v)
	{
		m_IsAutoSubmit=v;
	}
	bool GetIsAutoSubmit()
	{
		return m_IsAutoSubmit;
	}
	bool GetIsAutoSubmit() const
	{
		return m_IsAutoSubmit;
	}
private:
	//采集物Id
	INT32 m_CollectionId;
public:
	void SetCollectionId( INT32 v)
	{
		m_CollectionId=v;
	}
	INT32 GetCollectionId()
	{
		return m_CollectionId;
	}
	INT32 GetCollectionId() const
	{
		return m_CollectionId;
	}
private:
	//任务条件所在副本Id
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
	//帮派Id
	INT32 m_Guild;
public:
	void SetGuild( INT32 v)
	{
		m_Guild=v;
	}
	INT32 GetGuild()
	{
		return m_Guild;
	}
	INT32 GetGuild() const
	{
		return m_Guild;
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

};
//任务数据封装类
class TaskTaskDataWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<TaskTaskDataWraperV1>
{
public:
	//构造函数
	TaskTaskDataWraperV1()
	{
		SetDataWraper( this );

		m_ProfTaskId = 0;
		m_ProfTaskCompCount = 0;
		m_OneDragonRingNum = 0;
		m_OneDragonComplateCount = 0;
		m_OneDragonDungeonId = -1;
		m_GuildSpyComplateCount = 0;

	}
	//赋值构造函数
	TaskTaskDataWraperV1(const TaskTaskDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskTaskDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskTaskDataV1 ToPB() const
	{
		TaskTaskDataV1 v;
		v.mutable_alltaskarray()->Reserve(m_AllTaskArray.size());
		for (int i=0; i<(int)m_AllTaskArray.size(); i++)
		{
			*v.add_alltaskarray() = m_AllTaskArray[i].ToPB();
		}
		v.mutable_unacceptedtaskarray()->Reserve(m_UnacceptedTaskArray.size());
		for (int i=0; i<(int)m_UnacceptedTaskArray.size(); i++)
		{
			*v.add_unacceptedtaskarray() = m_UnacceptedTaskArray[i].ToPB();
		}
		v.set_proftaskid( m_ProfTaskId );
		v.set_proftaskcompcount( m_ProfTaskCompCount );
		v.mutable_onedragontaskid()->Reserve(m_OneDragonTaskId.size());
		for (int i=0; i<(int)m_OneDragonTaskId.size(); i++)
		{
			v.add_onedragontaskid(m_OneDragonTaskId[i]);
		}
		v.set_onedragonringnum( m_OneDragonRingNum );
		v.set_onedragoncomplatecount( m_OneDragonComplateCount );
		v.set_onedragondungeonid( m_OneDragonDungeonId );
		v.set_guildspycomplatecount( m_GuildSpyComplateCount );

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
		TaskTaskDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>AllTaskArray(全部任务数组) [TaskObj] Array</li>\r\n";
		htmlBuff += "<li>UnacceptedTaskArray(可接任务) [UnacceptedTaskObj] Array</li>\r\n";
		htmlBuff += "<li>ProfTaskId(师门任务环数) [sint32]</li>\r\n";
		htmlBuff += "<li>ProfTaskCompCount(师门任务完成次数) [sint32]</li>\r\n";
		htmlBuff += "<li>OneDragonTaskId(使用过的一条龙任务Id) [sint32] Array</li>\r\n";
		htmlBuff += "<li>OneDragonRingNum(一条龙环数) [sint32]</li>\r\n";
		htmlBuff += "<li>OneDragonComplateCount(一条龙完成次数) [sint32]</li>\r\n";
		htmlBuff += "<li>OneDragonDungeonId(一条龙副本Id) [sint32]</li>\r\n";
		htmlBuff += "<li>GuildSpyComplateCount(帮会刺探完成次数) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>AllTaskArray：</li>\r\n";
		if( m_AllTaskArray.size()>0) htmlBuff += m_AllTaskArray[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_AllTaskArray.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_AllTaskArray[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>UnacceptedTaskArray：</li>\r\n";
		if( m_UnacceptedTaskArray.size()>0) htmlBuff += m_UnacceptedTaskArray[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_UnacceptedTaskArray.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_UnacceptedTaskArray[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>ProfTaskId：%di</li>\r\n",m_ProfTaskId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ProfTaskCompCount：%di</li>\r\n",m_ProfTaskCompCount);
		htmlBuff += tmpLine;
		htmlBuff += "<li>OneDragonTaskId：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_OneDragonTaskId.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_OneDragonTaskId[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_OneDragonTaskId.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>OneDragonRingNum：%di</li>\r\n",m_OneDragonRingNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>OneDragonComplateCount：%di</li>\r\n",m_OneDragonComplateCount);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>OneDragonDungeonId：%di</li>\r\n",m_OneDragonDungeonId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GuildSpyComplateCount：%di</li>\r\n",m_GuildSpyComplateCount);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskTaskDataV1& v)
	{
		m_AllTaskArray.clear();
		m_AllTaskArray.reserve(v.alltaskarray_size());
		for( int i=0; i<v.alltaskarray_size(); i++)
			m_AllTaskArray.push_back(v.alltaskarray(i));
		m_UnacceptedTaskArray.clear();
		m_UnacceptedTaskArray.reserve(v.unacceptedtaskarray_size());
		for( int i=0; i<v.unacceptedtaskarray_size(); i++)
			m_UnacceptedTaskArray.push_back(v.unacceptedtaskarray(i));
		m_ProfTaskId = v.proftaskid();
		m_ProfTaskCompCount = v.proftaskcompcount();
		m_OneDragonTaskId.clear();
		m_OneDragonTaskId.reserve(v.onedragontaskid_size());
		for( int i=0; i<v.onedragontaskid_size(); i++)
			m_OneDragonTaskId.push_back(v.onedragontaskid(i));
		m_OneDragonRingNum = v.onedragonringnum();
		m_OneDragonComplateCount = v.onedragoncomplatecount();
		m_OneDragonDungeonId = v.onedragondungeonid();
		m_GuildSpyComplateCount = v.guildspycomplatecount();

	}

private:
	//全部任务数组
	vector<TaskTaskObjWraperV1> m_AllTaskArray;
public:
	int SizeAllTaskArray()
	{
		return m_AllTaskArray.size();
	}
	const vector<TaskTaskObjWraperV1>& GetAllTaskArray() const
	{
		return m_AllTaskArray;
	}
	TaskTaskObjWraperV1 GetAllTaskArray(int Index) const
	{
		if(Index<0 || Index>=(int)m_AllTaskArray.size())
		{
			assert(false);
			return TaskTaskObjWraperV1();
		}
		return m_AllTaskArray[Index];
	}
	void SetAllTaskArray( const vector<TaskTaskObjWraperV1>& v )
	{
		m_AllTaskArray=v;
	}
	void ClearAllTaskArray( )
	{
		m_AllTaskArray.clear();
	}
	void SetAllTaskArray( int Index, const TaskTaskObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_AllTaskArray.size())
		{
			assert(false);
			return;
		}
		m_AllTaskArray[Index] = v;
	}
	void AddAllTaskArray( const TaskTaskObjWraperV1& v )
	{
		m_AllTaskArray.push_back(v);
	}
private:
	//可接任务
	vector<TaskUnacceptedTaskObjWraperV1> m_UnacceptedTaskArray;
public:
	int SizeUnacceptedTaskArray()
	{
		return m_UnacceptedTaskArray.size();
	}
	const vector<TaskUnacceptedTaskObjWraperV1>& GetUnacceptedTaskArray() const
	{
		return m_UnacceptedTaskArray;
	}
	TaskUnacceptedTaskObjWraperV1 GetUnacceptedTaskArray(int Index) const
	{
		if(Index<0 || Index>=(int)m_UnacceptedTaskArray.size())
		{
			assert(false);
			return TaskUnacceptedTaskObjWraperV1();
		}
		return m_UnacceptedTaskArray[Index];
	}
	void SetUnacceptedTaskArray( const vector<TaskUnacceptedTaskObjWraperV1>& v )
	{
		m_UnacceptedTaskArray=v;
	}
	void ClearUnacceptedTaskArray( )
	{
		m_UnacceptedTaskArray.clear();
	}
	void SetUnacceptedTaskArray( int Index, const TaskUnacceptedTaskObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_UnacceptedTaskArray.size())
		{
			assert(false);
			return;
		}
		m_UnacceptedTaskArray[Index] = v;
	}
	void AddUnacceptedTaskArray( const TaskUnacceptedTaskObjWraperV1& v )
	{
		m_UnacceptedTaskArray.push_back(v);
	}
private:
	//师门任务环数
	INT32 m_ProfTaskId;
public:
	void SetProfTaskId( INT32 v)
	{
		m_ProfTaskId=v;
	}
	INT32 GetProfTaskId()
	{
		return m_ProfTaskId;
	}
	INT32 GetProfTaskId() const
	{
		return m_ProfTaskId;
	}
private:
	//师门任务完成次数
	INT32 m_ProfTaskCompCount;
public:
	void SetProfTaskCompCount( INT32 v)
	{
		m_ProfTaskCompCount=v;
	}
	INT32 GetProfTaskCompCount()
	{
		return m_ProfTaskCompCount;
	}
	INT32 GetProfTaskCompCount() const
	{
		return m_ProfTaskCompCount;
	}
private:
	//使用过的一条龙任务Id
	vector<INT32> m_OneDragonTaskId;
public:
	int SizeOneDragonTaskId()
	{
		return m_OneDragonTaskId.size();
	}
	const vector<INT32>& GetOneDragonTaskId() const
	{
		return m_OneDragonTaskId;
	}
	INT32 GetOneDragonTaskId(int Index) const
	{
		if(Index<0 || Index>=(int)m_OneDragonTaskId.size())
		{
			assert(false);
			return INT32();
		}
		return m_OneDragonTaskId[Index];
	}
	void SetOneDragonTaskId( const vector<INT32>& v )
	{
		m_OneDragonTaskId=v;
	}
	void ClearOneDragonTaskId( )
	{
		m_OneDragonTaskId.clear();
	}
	void SetOneDragonTaskId( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_OneDragonTaskId.size())
		{
			assert(false);
			return;
		}
		m_OneDragonTaskId[Index] = v;
	}
	void AddOneDragonTaskId( INT32 v = -1 )
	{
		m_OneDragonTaskId.push_back(v);
	}
private:
	//一条龙环数
	INT32 m_OneDragonRingNum;
public:
	void SetOneDragonRingNum( INT32 v)
	{
		m_OneDragonRingNum=v;
	}
	INT32 GetOneDragonRingNum()
	{
		return m_OneDragonRingNum;
	}
	INT32 GetOneDragonRingNum() const
	{
		return m_OneDragonRingNum;
	}
private:
	//一条龙完成次数
	INT32 m_OneDragonComplateCount;
public:
	void SetOneDragonComplateCount( INT32 v)
	{
		m_OneDragonComplateCount=v;
	}
	INT32 GetOneDragonComplateCount()
	{
		return m_OneDragonComplateCount;
	}
	INT32 GetOneDragonComplateCount() const
	{
		return m_OneDragonComplateCount;
	}
private:
	//一条龙副本Id
	INT32 m_OneDragonDungeonId;
public:
	void SetOneDragonDungeonId( INT32 v)
	{
		m_OneDragonDungeonId=v;
	}
	INT32 GetOneDragonDungeonId()
	{
		return m_OneDragonDungeonId;
	}
	INT32 GetOneDragonDungeonId() const
	{
		return m_OneDragonDungeonId;
	}
private:
	//帮会刺探完成次数
	INT32 m_GuildSpyComplateCount;
public:
	void SetGuildSpyComplateCount( INT32 v)
	{
		m_GuildSpyComplateCount=v;
	}
	INT32 GetGuildSpyComplateCount()
	{
		return m_GuildSpyComplateCount;
	}
	INT32 GetGuildSpyComplateCount() const
	{
		return m_GuildSpyComplateCount;
	}

};

#endif
