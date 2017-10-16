/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperTask.h
* Author:       甘业清
* Description:  任务RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_TASK_H
#define __RPC_WRAPER_TASK_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "TaskRpc.pb.h"



//任务类的枚举定义
enum ConstTaskE
{
	MODULE_ID_TASK                               = 24,	//任务模块ID
	RPC_CODE_TASK_SYNCDATA_REQUEST               = 2451,	//任务-->数据同步-->请求
	RPC_CODE_TASK_COMPLETETASK_REQUEST           = 2452,	//任务-->完成任务目标-->请求
	RPC_CODE_TASK_SUBMITTASK_REQUEST             = 2453,	//任务-->提交任务-->请求
	RPC_CODE_TASK_UPDATETASK_NOTIFY              = 2454,	//任务-->更新任务-->通知
	RPC_CODE_TASK_ACCEPTTASK_REQUEST             = 2455,	//任务-->接受任务-->请求
	RPC_CODE_TASK_STARTPROFTASK_REQUEST          = 2456,	//任务-->开始师门任务-->请求
	RPC_CODE_TASK_STARTONEDRAGON_REQUEST         = 2457,	//任务-->开始一条龙-->请求
	RPC_CODE_TASK_ADDTASK_NOTIFY                 = 2458,	//任务-->增加任务-->通知
	RPC_CODE_TASK_DELTASK_NOTIFY                 = 2459,	//任务-->删除任务-->通知
	RPC_CODE_TASK_STARTGUILDSPY_REQUEST          = 2460,	//任务-->开始帮会刺探-->请求


};


//开始师门任务请求封装类
class TaskRpcStartProfTaskAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcStartProfTaskAskWraper()
	{
		

	}
	//赋值构造函数
	TaskRpcStartProfTaskAskWraper(const TaskRpcStartProfTaskAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcStartProfTaskAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcStartProfTaskAsk ToPB() const
	{
		TaskRpcStartProfTaskAsk v;

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
		TaskRpcStartProfTaskAsk pb;
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
	void Init(const TaskRpcStartProfTaskAsk& v)
	{

	}


};
//开始师门任务回应封装类
class TaskRpcStartProfTaskReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcStartProfTaskReplyWraper()
	{
		
		m_Result = -9999;
		m_TaskId = -1;

	}
	//赋值构造函数
	TaskRpcStartProfTaskReplyWraper(const TaskRpcStartProfTaskReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcStartProfTaskReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcStartProfTaskReply ToPB() const
	{
		TaskRpcStartProfTaskReply v;
		v.set_result( m_Result );
		v.set_taskid( m_TaskId );

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
		TaskRpcStartProfTaskReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TaskId(任务Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TaskId：%di</li>\r\n",m_TaskId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskRpcStartProfTaskReply& v)
	{
		m_Result = v.result();
		m_TaskId = v.taskid();

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

};
//开始帮会刺探回应封装类
class TaskRpcStartGuildSpyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcStartGuildSpyReplyWraper()
	{
		
		m_Result = -9999;
		m_TaskId = -1;

	}
	//赋值构造函数
	TaskRpcStartGuildSpyReplyWraper(const TaskRpcStartGuildSpyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcStartGuildSpyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcStartGuildSpyReply ToPB() const
	{
		TaskRpcStartGuildSpyReply v;
		v.set_result( m_Result );
		v.set_taskid( m_TaskId );

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
		TaskRpcStartGuildSpyReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TaskId(任务Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TaskId：%di</li>\r\n",m_TaskId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskRpcStartGuildSpyReply& v)
	{
		m_Result = v.result();
		m_TaskId = v.taskid();

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

};
//开始一条龙请求封装类
class TaskRpcStartOneDragonAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcStartOneDragonAskWraper()
	{
		

	}
	//赋值构造函数
	TaskRpcStartOneDragonAskWraper(const TaskRpcStartOneDragonAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcStartOneDragonAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcStartOneDragonAsk ToPB() const
	{
		TaskRpcStartOneDragonAsk v;

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
		TaskRpcStartOneDragonAsk pb;
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
	void Init(const TaskRpcStartOneDragonAsk& v)
	{

	}


};
//删除任务通知封装类
class TaskRpcDelTaskNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcDelTaskNotifyWraper()
	{
		
		m_TaskId = -1;
		m_TaskState = -1;

	}
	//赋值构造函数
	TaskRpcDelTaskNotifyWraper(const TaskRpcDelTaskNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcDelTaskNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcDelTaskNotify ToPB() const
	{
		TaskRpcDelTaskNotify v;
		v.set_taskid( m_TaskId );
		v.set_taskstate( m_TaskState );

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
		TaskRpcDelTaskNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TaskId(任务Id) [sint32]</li>\r\n";
		htmlBuff += "<li>TaskState(任务状态) [sint32]</li>\r\n";

		
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

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskRpcDelTaskNotify& v)
	{
		m_TaskId = v.taskid();
		m_TaskState = v.taskstate();

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

};
//开始帮会刺探请求封装类
class TaskRpcStartGuildSpyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcStartGuildSpyAskWraper()
	{
		

	}
	//赋值构造函数
	TaskRpcStartGuildSpyAskWraper(const TaskRpcStartGuildSpyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcStartGuildSpyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcStartGuildSpyAsk ToPB() const
	{
		TaskRpcStartGuildSpyAsk v;

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
		TaskRpcStartGuildSpyAsk pb;
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
	void Init(const TaskRpcStartGuildSpyAsk& v)
	{

	}


};
//开始一条龙回应封装类
class TaskRpcStartOneDragonReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcStartOneDragonReplyWraper()
	{
		
		m_Result = -9999;
		m_TaskId = -1;

	}
	//赋值构造函数
	TaskRpcStartOneDragonReplyWraper(const TaskRpcStartOneDragonReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcStartOneDragonReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcStartOneDragonReply ToPB() const
	{
		TaskRpcStartOneDragonReply v;
		v.set_result( m_Result );
		v.set_taskid( m_TaskId );

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
		TaskRpcStartOneDragonReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TaskId(任务Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TaskId：%di</li>\r\n",m_TaskId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskRpcStartOneDragonReply& v)
	{
		m_Result = v.result();
		m_TaskId = v.taskid();

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

};
//增加任务通知封装类
class TaskRpcAddTaskNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcAddTaskNotifyWraper()
	{
		
		m_TaskId = -1;
		m_TaskState = -1;

	}
	//赋值构造函数
	TaskRpcAddTaskNotifyWraper(const TaskRpcAddTaskNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcAddTaskNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcAddTaskNotify ToPB() const
	{
		TaskRpcAddTaskNotify v;
		v.set_taskid( m_TaskId );
		v.set_taskstate( m_TaskState );

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
		TaskRpcAddTaskNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TaskId(任务Id) [sint32]</li>\r\n";
		htmlBuff += "<li>TaskState(任务状态) [sint32]</li>\r\n";

		
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

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskRpcAddTaskNotify& v)
	{
		m_TaskId = v.taskid();
		m_TaskState = v.taskstate();

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

};
//接受任务回应封装类
class TaskRpcAcceptTaskReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcAcceptTaskReplyWraper()
	{
		
		m_Result = -9999;
		m_TaskId = -1;

	}
	//赋值构造函数
	TaskRpcAcceptTaskReplyWraper(const TaskRpcAcceptTaskReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcAcceptTaskReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcAcceptTaskReply ToPB() const
	{
		TaskRpcAcceptTaskReply v;
		v.set_result( m_Result );
		v.set_taskid( m_TaskId );

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
		TaskRpcAcceptTaskReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TaskId(任务Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TaskId：%di</li>\r\n",m_TaskId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskRpcAcceptTaskReply& v)
	{
		m_Result = v.result();
		m_TaskId = v.taskid();

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

};
//完成任务目标请求封装类
class TaskRpcCompleteTaskAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcCompleteTaskAskWraper()
	{
		
		m_TaskId = -1;
		m_Target = -1;

	}
	//赋值构造函数
	TaskRpcCompleteTaskAskWraper(const TaskRpcCompleteTaskAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcCompleteTaskAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcCompleteTaskAsk ToPB() const
	{
		TaskRpcCompleteTaskAsk v;
		v.set_taskid( m_TaskId );
		v.set_target( m_Target );

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
		TaskRpcCompleteTaskAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TaskId(任务Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Target(目标) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TaskId：%di</li>\r\n",m_TaskId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Target：%di</li>\r\n",m_Target);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskRpcCompleteTaskAsk& v)
	{
		m_TaskId = v.taskid();
		m_Target = v.target();

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
	//目标
	INT32 m_Target;
public:
	void SetTarget( INT32 v)
	{
		m_Target=v;
	}
	INT32 GetTarget()
	{
		return m_Target;
	}
	INT32 GetTarget() const
	{
		return m_Target;
	}

};
//数据同步请求封装类
class TaskRpcSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	TaskRpcSyncDataAskWraper(const TaskRpcSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcSyncDataAsk ToPB() const
	{
		TaskRpcSyncDataAsk v;

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
		TaskRpcSyncDataAsk pb;
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
	void Init(const TaskRpcSyncDataAsk& v)
	{

	}


};
//数据同步回应封装类
class TaskRpcSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcSyncDataReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TaskRpcSyncDataReplyWraper(const TaskRpcSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcSyncDataReply ToPB() const
	{
		TaskRpcSyncDataReply v;
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
		TaskRpcSyncDataReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";

		
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
	void Init(const TaskRpcSyncDataReply& v)
	{
		m_Result = v.result();

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

};
//更新任务通知封装类
class TaskRpcUpdateTaskNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcUpdateTaskNotifyWraper()
	{
		
		m_TaskId = -1;
		m_TaskState = -1;

	}
	//赋值构造函数
	TaskRpcUpdateTaskNotifyWraper(const TaskRpcUpdateTaskNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcUpdateTaskNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcUpdateTaskNotify ToPB() const
	{
		TaskRpcUpdateTaskNotify v;
		v.set_taskid( m_TaskId );
		v.set_taskstate( m_TaskState );
		v.mutable_tasktargetcount()->Reserve(m_TaskTargetCount.size());
		for (int i=0; i<(int)m_TaskTargetCount.size(); i++)
		{
			v.add_tasktargetcount(m_TaskTargetCount[i]);
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
		TaskRpcUpdateTaskNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TaskId(任务Id) [sint32]</li>\r\n";
		htmlBuff += "<li>TaskState(任务状态) [sint32]</li>\r\n";
		htmlBuff += "<li>TaskTargetCount(任务目标数量) [sint32] Array</li>\r\n";

		
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
		htmlBuff += "<li>TaskTargetCount：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_TaskTargetCount.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_TaskTargetCount[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_TaskTargetCount.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskRpcUpdateTaskNotify& v)
	{
		m_TaskId = v.taskid();
		m_TaskState = v.taskstate();
		m_TaskTargetCount.clear();
		m_TaskTargetCount.reserve(v.tasktargetcount_size());
		for( int i=0; i<v.tasktargetcount_size(); i++)
			m_TaskTargetCount.push_back(v.tasktargetcount(i));

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
	//任务目标数量
	vector<INT32> m_TaskTargetCount;
public:
	int SizeTaskTargetCount()
	{
		return m_TaskTargetCount.size();
	}
	const vector<INT32>& GetTaskTargetCount() const
	{
		return m_TaskTargetCount;
	}
	INT32 GetTaskTargetCount(int Index) const
	{
		if(Index<0 || Index>=(int)m_TaskTargetCount.size())
		{
			assert(false);
			return INT32();
		}
		return m_TaskTargetCount[Index];
	}
	void SetTaskTargetCount( const vector<INT32>& v )
	{
		m_TaskTargetCount=v;
	}
	void ClearTaskTargetCount( )
	{
		m_TaskTargetCount.clear();
	}
	void SetTaskTargetCount( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_TaskTargetCount.size())
		{
			assert(false);
			return;
		}
		m_TaskTargetCount[Index] = v;
	}
	void AddTaskTargetCount( INT32 v = -1 )
	{
		m_TaskTargetCount.push_back(v);
	}

};
//接受任务请求封装类
class TaskRpcAcceptTaskAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcAcceptTaskAskWraper()
	{
		
		m_TaskId = -1;

	}
	//赋值构造函数
	TaskRpcAcceptTaskAskWraper(const TaskRpcAcceptTaskAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcAcceptTaskAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcAcceptTaskAsk ToPB() const
	{
		TaskRpcAcceptTaskAsk v;
		v.set_taskid( m_TaskId );

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
		TaskRpcAcceptTaskAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TaskId(任务Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TaskId：%di</li>\r\n",m_TaskId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskRpcAcceptTaskAsk& v)
	{
		m_TaskId = v.taskid();

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

};
//提交任务回应封装类
class TaskRpcSubmitTaskReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcSubmitTaskReplyWraper()
	{
		
		m_Result = -9999;
		m_TaskId = -1;
		m_NextTaskId = -1;

	}
	//赋值构造函数
	TaskRpcSubmitTaskReplyWraper(const TaskRpcSubmitTaskReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcSubmitTaskReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcSubmitTaskReply ToPB() const
	{
		TaskRpcSubmitTaskReply v;
		v.set_result( m_Result );
		v.set_taskid( m_TaskId );
		v.set_nexttaskid( m_NextTaskId );

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
		TaskRpcSubmitTaskReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TaskId(任务Id) [sint32]</li>\r\n";
		htmlBuff += "<li>NextTaskId(下一个任务id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TaskId：%di</li>\r\n",m_TaskId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>NextTaskId：%di</li>\r\n",m_NextTaskId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskRpcSubmitTaskReply& v)
	{
		m_Result = v.result();
		m_TaskId = v.taskid();
		m_NextTaskId = v.nexttaskid();

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
	//下一个任务id
	INT32 m_NextTaskId;
public:
	void SetNextTaskId( INT32 v)
	{
		m_NextTaskId=v;
	}
	INT32 GetNextTaskId()
	{
		return m_NextTaskId;
	}
	INT32 GetNextTaskId() const
	{
		return m_NextTaskId;
	}

};
//完成任务目标回应封装类
class TaskRpcCompleteTaskReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcCompleteTaskReplyWraper()
	{
		
		m_Result = -9999;
		m_TaskId = -1;
		m_Target = -1;

	}
	//赋值构造函数
	TaskRpcCompleteTaskReplyWraper(const TaskRpcCompleteTaskReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcCompleteTaskReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcCompleteTaskReply ToPB() const
	{
		TaskRpcCompleteTaskReply v;
		v.set_result( m_Result );
		v.set_taskid( m_TaskId );
		v.set_target( m_Target );

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
		TaskRpcCompleteTaskReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>TaskId(任务Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Target(目标) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TaskId：%di</li>\r\n",m_TaskId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Target：%di</li>\r\n",m_Target);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskRpcCompleteTaskReply& v)
	{
		m_Result = v.result();
		m_TaskId = v.taskid();
		m_Target = v.target();

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
	//目标
	INT32 m_Target;
public:
	void SetTarget( INT32 v)
	{
		m_Target=v;
	}
	INT32 GetTarget()
	{
		return m_Target;
	}
	INT32 GetTarget() const
	{
		return m_Target;
	}

};
//提交任务请求封装类
class TaskRpcSubmitTaskAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TaskRpcSubmitTaskAskWraper()
	{
		
		m_TaskId = -1;

	}
	//赋值构造函数
	TaskRpcSubmitTaskAskWraper(const TaskRpcSubmitTaskAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TaskRpcSubmitTaskAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TaskRpcSubmitTaskAsk ToPB() const
	{
		TaskRpcSubmitTaskAsk v;
		v.set_taskid( m_TaskId );

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
		TaskRpcSubmitTaskAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TaskId(任务Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TaskId：%di</li>\r\n",m_TaskId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TaskRpcSubmitTaskAsk& v)
	{
		m_TaskId = v.taskid();

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

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<TaskRpcSyncDataAskWraper>{ enum{ID=RPC_CODE_TASK_SYNCDATA_REQUEST};};
template<> struct MessageIdT<TaskRpcSyncDataReplyWraper>{ enum{ID=RPC_CODE_TASK_SYNCDATA_REQUEST};};
template<> struct MessageIdT<TaskRpcCompleteTaskAskWraper>{ enum{ID=RPC_CODE_TASK_COMPLETETASK_REQUEST};};
template<> struct MessageIdT<TaskRpcCompleteTaskReplyWraper>{ enum{ID=RPC_CODE_TASK_COMPLETETASK_REQUEST};};
template<> struct MessageIdT<TaskRpcSubmitTaskAskWraper>{ enum{ID=RPC_CODE_TASK_SUBMITTASK_REQUEST};};
template<> struct MessageIdT<TaskRpcSubmitTaskReplyWraper>{ enum{ID=RPC_CODE_TASK_SUBMITTASK_REQUEST};};
template<> struct MessageIdT<TaskRpcUpdateTaskNotifyWraper>{ enum{ID=RPC_CODE_TASK_UPDATETASK_NOTIFY};};
template<> struct MessageIdT<TaskRpcAcceptTaskAskWraper>{ enum{ID=RPC_CODE_TASK_ACCEPTTASK_REQUEST};};
template<> struct MessageIdT<TaskRpcAcceptTaskReplyWraper>{ enum{ID=RPC_CODE_TASK_ACCEPTTASK_REQUEST};};
template<> struct MessageIdT<TaskRpcStartProfTaskAskWraper>{ enum{ID=RPC_CODE_TASK_STARTPROFTASK_REQUEST};};
template<> struct MessageIdT<TaskRpcStartProfTaskReplyWraper>{ enum{ID=RPC_CODE_TASK_STARTPROFTASK_REQUEST};};
template<> struct MessageIdT<TaskRpcStartOneDragonAskWraper>{ enum{ID=RPC_CODE_TASK_STARTONEDRAGON_REQUEST};};
template<> struct MessageIdT<TaskRpcStartOneDragonReplyWraper>{ enum{ID=RPC_CODE_TASK_STARTONEDRAGON_REQUEST};};
template<> struct MessageIdT<TaskRpcAddTaskNotifyWraper>{ enum{ID=RPC_CODE_TASK_ADDTASK_NOTIFY};};
template<> struct MessageIdT<TaskRpcDelTaskNotifyWraper>{ enum{ID=RPC_CODE_TASK_DELTASK_NOTIFY};};
template<> struct MessageIdT<TaskRpcStartGuildSpyAskWraper>{ enum{ID=RPC_CODE_TASK_STARTGUILDSPY_REQUEST};};
template<> struct MessageIdT<TaskRpcStartGuildSpyReplyWraper>{ enum{ID=RPC_CODE_TASK_STARTGUILDSPY_REQUEST};};


#endif
