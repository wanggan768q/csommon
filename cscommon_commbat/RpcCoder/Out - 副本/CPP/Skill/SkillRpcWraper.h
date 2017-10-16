/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperSkill.h
* Author:       甘业清
* Description:  技能RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_SKILL_H
#define __RPC_WRAPER_SKILL_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "SkillRpc.pb.h"



//技能类的枚举定义
enum ConstSkillE
{
	MODULE_ID_SKILL                              = 29,	//技能模块ID
	RPC_CODE_SKILL_SYNCDATA_REQUEST              = 2951,	//技能-->数据同步-->请求
	RPC_CODE_SKILL_LEARN_REQUEST                 = 2952,	//技能-->学习-->请求
	RPC_CODE_SKILL_LVUP_REQUEST                  = 2953,	//技能-->升级-->请求
	RPC_CODE_SKILL_CHANGESHORTCUT_REQUEST        = 2954,	//技能-->修改快捷栏-->请求
	RPC_CODE_SKILL_USESHORTCUT_REQUEST           = 2955,	//技能-->使用技能方案-->请求
	RPC_CODE_SKILL_ONEKEYLVUP_REQUEST            = 2956,	//技能-->一键升级-->请求
	RPC_CODE_SKILL_TALENTLVUP_REQUEST            = 2957,	//技能-->天赋槽位升级-->请求
	RPC_CODE_SKILL_TALENTCHANGESKILL_REQUEST     = 2958,	//技能-->天赋槽位切换技能-->请求
	RPC_CODE_SKILL_TALENTRESET_REQUEST           = 2959,	//技能-->天赋重置-->请求
	RPC_CODE_SKILL_LIFESKILLUP_REQUEST           = 2960,	//技能-->升级生活技能-->请求


};


//天赋升级对象封装类
class SkillRpcTalentLvObjWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcTalentLvObjWraper()
	{
		
		m_Index = 0;
		m_Level = 0;

	}
	//赋值构造函数
	SkillRpcTalentLvObjWraper(const SkillRpcTalentLvObj& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcTalentLvObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcTalentLvObj ToPB() const
	{
		SkillRpcTalentLvObj v;
		v.set_index( m_Index );
		v.set_level( m_Level );

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
		SkillRpcTalentLvObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Index(槽位索引) [sint32]</li>\r\n";
		htmlBuff += "<li>Level(槽位最终的等级) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Index：%di</li>\r\n",m_Index);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillRpcTalentLvObj& v)
	{
		m_Index = v.index();
		m_Level = v.level();

	}

private:
	//槽位索引
	INT32 m_Index;
public:
	void SetIndex( INT32 v)
	{
		m_Index=v;
	}
	INT32 GetIndex()
	{
		return m_Index;
	}
	INT32 GetIndex() const
	{
		return m_Index;
	}
private:
	//槽位最终的等级
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

};
//天赋槽位切换技能请求封装类
class SkillRpcTalentChangeSkillAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcTalentChangeSkillAskWraper()
	{
		
		m_Index = -1;
		m_SkillId = -1;

	}
	//赋值构造函数
	SkillRpcTalentChangeSkillAskWraper(const SkillRpcTalentChangeSkillAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcTalentChangeSkillAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcTalentChangeSkillAsk ToPB() const
	{
		SkillRpcTalentChangeSkillAsk v;
		v.set_index( m_Index );
		v.set_skillid( m_SkillId );

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
		SkillRpcTalentChangeSkillAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Index(槽位索引) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillId(技能id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Index：%di</li>\r\n",m_Index);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillRpcTalentChangeSkillAsk& v)
	{
		m_Index = v.index();
		m_SkillId = v.skillid();

	}

private:
	//槽位索引
	INT32 m_Index;
public:
	void SetIndex( INT32 v)
	{
		m_Index=v;
	}
	INT32 GetIndex()
	{
		return m_Index;
	}
	INT32 GetIndex() const
	{
		return m_Index;
	}
private:
	//技能id
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

};
//天赋槽位切换技能回应封装类
class SkillRpcTalentChangeSkillReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcTalentChangeSkillReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	SkillRpcTalentChangeSkillReplyWraper(const SkillRpcTalentChangeSkillReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcTalentChangeSkillReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcTalentChangeSkillReply ToPB() const
	{
		SkillRpcTalentChangeSkillReply v;
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
		SkillRpcTalentChangeSkillReply pb;
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
	void Init(const SkillRpcTalentChangeSkillReply& v)
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
//一键升级请求封装类
class SkillRpcOneKeyLvUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcOneKeyLvUpAskWraper()
	{
		
		m_SkillId = -1;

	}
	//赋值构造函数
	SkillRpcOneKeyLvUpAskWraper(const SkillRpcOneKeyLvUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcOneKeyLvUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcOneKeyLvUpAsk ToPB() const
	{
		SkillRpcOneKeyLvUpAsk v;
		v.set_skillid( m_SkillId );

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
		SkillRpcOneKeyLvUpAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SkillId(技能Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillRpcOneKeyLvUpAsk& v)
	{
		m_SkillId = v.skillid();

	}

private:
	//技能Id
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

};
//一键升级回应封装类
class SkillRpcOneKeyLvUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcOneKeyLvUpReplyWraper()
	{
		
		m_Result = -9999;
		m_SkillId = -1;

	}
	//赋值构造函数
	SkillRpcOneKeyLvUpReplyWraper(const SkillRpcOneKeyLvUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcOneKeyLvUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcOneKeyLvUpReply ToPB() const
	{
		SkillRpcOneKeyLvUpReply v;
		v.set_result( m_Result );
		v.set_skillid( m_SkillId );

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
		SkillRpcOneKeyLvUpReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillId(技能Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillRpcOneKeyLvUpReply& v)
	{
		m_Result = v.result();
		m_SkillId = v.skillid();

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
	//技能Id
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

};
//天赋重置请求封装类
class SkillRpcTalentResetAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcTalentResetAskWraper()
	{
		

	}
	//赋值构造函数
	SkillRpcTalentResetAskWraper(const SkillRpcTalentResetAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcTalentResetAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcTalentResetAsk ToPB() const
	{
		SkillRpcTalentResetAsk v;

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
		SkillRpcTalentResetAsk pb;
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
	void Init(const SkillRpcTalentResetAsk& v)
	{

	}


};
//升级生活技能请求封装类
class SkillRpcLifeSkillUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcLifeSkillUpAskWraper()
	{
		
		m_LifeSkillId = -1;

	}
	//赋值构造函数
	SkillRpcLifeSkillUpAskWraper(const SkillRpcLifeSkillUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcLifeSkillUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcLifeSkillUpAsk ToPB() const
	{
		SkillRpcLifeSkillUpAsk v;
		v.set_lifeskillid( m_LifeSkillId );

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
		SkillRpcLifeSkillUpAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>LifeSkillId(生活技能表id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>LifeSkillId：%di</li>\r\n",m_LifeSkillId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillRpcLifeSkillUpAsk& v)
	{
		m_LifeSkillId = v.lifeskillid();

	}

private:
	//生活技能表id
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

};
//升级生活技能回应封装类
class SkillRpcLifeSkillUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcLifeSkillUpReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	SkillRpcLifeSkillUpReplyWraper(const SkillRpcLifeSkillUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcLifeSkillUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcLifeSkillUpReply ToPB() const
	{
		SkillRpcLifeSkillUpReply v;
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
		SkillRpcLifeSkillUpReply pb;
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
	void Init(const SkillRpcLifeSkillUpReply& v)
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
//天赋槽位升级回应封装类
class SkillRpcTalentLvUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcTalentLvUpReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	SkillRpcTalentLvUpReplyWraper(const SkillRpcTalentLvUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcTalentLvUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcTalentLvUpReply ToPB() const
	{
		SkillRpcTalentLvUpReply v;
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
		SkillRpcTalentLvUpReply pb;
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
	void Init(const SkillRpcTalentLvUpReply& v)
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
//天赋重置回应封装类
class SkillRpcTalentResetReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcTalentResetReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	SkillRpcTalentResetReplyWraper(const SkillRpcTalentResetReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcTalentResetReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcTalentResetReply ToPB() const
	{
		SkillRpcTalentResetReply v;
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
		SkillRpcTalentResetReply pb;
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
	void Init(const SkillRpcTalentResetReply& v)
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
//天赋槽位升级请求封装类
class SkillRpcTalentLvUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcTalentLvUpAskWraper()
	{
		

	}
	//赋值构造函数
	SkillRpcTalentLvUpAskWraper(const SkillRpcTalentLvUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcTalentLvUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcTalentLvUpAsk ToPB() const
	{
		SkillRpcTalentLvUpAsk v;
		v.mutable_talent()->Reserve(m_Talent.size());
		for (int i=0; i<(int)m_Talent.size(); i++)
		{
			*v.add_talent() = m_Talent[i].ToPB();
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
		SkillRpcTalentLvUpAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Talent(天赋) [RpcTalentLvObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>Talent：</li>\r\n";
		if( m_Talent.size()>0) htmlBuff += m_Talent[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_Talent.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_Talent[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillRpcTalentLvUpAsk& v)
	{
		m_Talent.clear();
		m_Talent.reserve(v.talent_size());
		for( int i=0; i<v.talent_size(); i++)
			m_Talent.push_back(v.talent(i));

	}

private:
	//天赋
	vector<SkillRpcTalentLvObjWraper> m_Talent;
public:
	int SizeTalent()
	{
		return m_Talent.size();
	}
	const vector<SkillRpcTalentLvObjWraper>& GetTalent() const
	{
		return m_Talent;
	}
	SkillRpcTalentLvObjWraper GetTalent(int Index) const
	{
		if(Index<0 || Index>=(int)m_Talent.size())
		{
			assert(false);
			return SkillRpcTalentLvObjWraper();
		}
		return m_Talent[Index];
	}
	void SetTalent( const vector<SkillRpcTalentLvObjWraper>& v )
	{
		m_Talent=v;
	}
	void ClearTalent( )
	{
		m_Talent.clear();
	}
	void SetTalent( int Index, const SkillRpcTalentLvObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_Talent.size())
		{
			assert(false);
			return;
		}
		m_Talent[Index] = v;
	}
	void AddTalent( const SkillRpcTalentLvObjWraper& v )
	{
		m_Talent.push_back(v);
	}

};
//使用技能方案回应封装类
class SkillRpcUseShortcutReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcUseShortcutReplyWraper()
	{
		
		m_Result = -9999;
		m_Id = -1;

	}
	//赋值构造函数
	SkillRpcUseShortcutReplyWraper(const SkillRpcUseShortcutReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcUseShortcutReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcUseShortcutReply ToPB() const
	{
		SkillRpcUseShortcutReply v;
		v.set_result( m_Result );
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
		SkillRpcUseShortcutReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Id(方案1=0) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillRpcUseShortcutReply& v)
	{
		m_Result = v.result();
		m_Id = v.id();

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
	//方案1=0
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
//数据同步请求封装类
class SkillRpcSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	SkillRpcSyncDataAskWraper(const SkillRpcSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcSyncDataAsk ToPB() const
	{
		SkillRpcSyncDataAsk v;

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
		SkillRpcSyncDataAsk pb;
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
	void Init(const SkillRpcSyncDataAsk& v)
	{

	}


};
//数据同步回应封装类
class SkillRpcSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcSyncDataReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	SkillRpcSyncDataReplyWraper(const SkillRpcSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcSyncDataReply ToPB() const
	{
		SkillRpcSyncDataReply v;
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
		SkillRpcSyncDataReply pb;
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
	void Init(const SkillRpcSyncDataReply& v)
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
//学习请求封装类
class SkillRpcLearnAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcLearnAskWraper()
	{
		
		m_SkillId = -1;

	}
	//赋值构造函数
	SkillRpcLearnAskWraper(const SkillRpcLearnAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcLearnAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcLearnAsk ToPB() const
	{
		SkillRpcLearnAsk v;
		v.set_skillid( m_SkillId );

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
		SkillRpcLearnAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SkillId(技能Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillRpcLearnAsk& v)
	{
		m_SkillId = v.skillid();

	}

private:
	//技能Id
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

};
//修改快捷栏请求封装类
class SkillRpcChangeShortcutAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcChangeShortcutAskWraper()
	{
		
		m_SkillId = -1;
		m_Pos = -1;
		m_Id = -1;

	}
	//赋值构造函数
	SkillRpcChangeShortcutAskWraper(const SkillRpcChangeShortcutAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcChangeShortcutAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcChangeShortcutAsk ToPB() const
	{
		SkillRpcChangeShortcutAsk v;
		v.set_skillid( m_SkillId );
		v.set_pos( m_Pos );
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
		SkillRpcChangeShortcutAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SkillId(技能Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>Id(方案1=0) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillRpcChangeShortcutAsk& v)
	{
		m_SkillId = v.skillid();
		m_Pos = v.pos();
		m_Id = v.id();

	}

private:
	//技能Id
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
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//方案1=0
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
//修改快捷栏回应封装类
class SkillRpcChangeShortcutReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcChangeShortcutReplyWraper()
	{
		
		m_Result = -9999;
		m_SkillId = -1;
		m_Pos = -1;
		m_Id = -1;

	}
	//赋值构造函数
	SkillRpcChangeShortcutReplyWraper(const SkillRpcChangeShortcutReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcChangeShortcutReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcChangeShortcutReply ToPB() const
	{
		SkillRpcChangeShortcutReply v;
		v.set_result( m_Result );
		v.set_skillid( m_SkillId );
		v.set_pos( m_Pos );
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
		SkillRpcChangeShortcutReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillId(技能Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(位置) [sint32]</li>\r\n";
		htmlBuff += "<li>Id(方案1=0) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillRpcChangeShortcutReply& v)
	{
		m_Result = v.result();
		m_SkillId = v.skillid();
		m_Pos = v.pos();
		m_Id = v.id();

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
	//技能Id
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
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//方案1=0
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
//使用技能方案请求封装类
class SkillRpcUseShortcutAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcUseShortcutAskWraper()
	{
		
		m_Id = -1;

	}
	//赋值构造函数
	SkillRpcUseShortcutAskWraper(const SkillRpcUseShortcutAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcUseShortcutAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcUseShortcutAsk ToPB() const
	{
		SkillRpcUseShortcutAsk v;
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
		SkillRpcUseShortcutAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Id(方案1=0) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillRpcUseShortcutAsk& v)
	{
		m_Id = v.id();

	}

private:
	//方案1=0
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
//学习回应封装类
class SkillRpcLearnReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcLearnReplyWraper()
	{
		
		m_Result = -9999;
		m_SkillId = -1;

	}
	//赋值构造函数
	SkillRpcLearnReplyWraper(const SkillRpcLearnReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcLearnReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcLearnReply ToPB() const
	{
		SkillRpcLearnReply v;
		v.set_result( m_Result );
		v.set_skillid( m_SkillId );

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
		SkillRpcLearnReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillId(技能Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillRpcLearnReply& v)
	{
		m_Result = v.result();
		m_SkillId = v.skillid();

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
	//技能Id
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

};
//升级请求封装类
class SkillRpcLvUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcLvUpAskWraper()
	{
		
		m_SkillId = -1;

	}
	//赋值构造函数
	SkillRpcLvUpAskWraper(const SkillRpcLvUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcLvUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcLvUpAsk ToPB() const
	{
		SkillRpcLvUpAsk v;
		v.set_skillid( m_SkillId );

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
		SkillRpcLvUpAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SkillId(技能Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillRpcLvUpAsk& v)
	{
		m_SkillId = v.skillid();

	}

private:
	//技能Id
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

};
//升级回应封装类
class SkillRpcLvUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcLvUpReplyWraper()
	{
		
		m_Result = -9999;
		m_SkillId = -1;

	}
	//赋值构造函数
	SkillRpcLvUpReplyWraper(const SkillRpcLvUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcLvUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcLvUpReply ToPB() const
	{
		SkillRpcLvUpReply v;
		v.set_result( m_Result );
		v.set_skillid( m_SkillId );

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
		SkillRpcLvUpReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillId(技能Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillRpcLvUpReply& v)
	{
		m_Result = v.result();
		m_SkillId = v.skillid();

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
	//技能Id
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

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<SkillRpcSyncDataAskWraper>{ enum{ID=RPC_CODE_SKILL_SYNCDATA_REQUEST};};
template<> struct MessageIdT<SkillRpcSyncDataReplyWraper>{ enum{ID=RPC_CODE_SKILL_SYNCDATA_REQUEST};};
template<> struct MessageIdT<SkillRpcLearnAskWraper>{ enum{ID=RPC_CODE_SKILL_LEARN_REQUEST};};
template<> struct MessageIdT<SkillRpcLearnReplyWraper>{ enum{ID=RPC_CODE_SKILL_LEARN_REQUEST};};
template<> struct MessageIdT<SkillRpcLvUpAskWraper>{ enum{ID=RPC_CODE_SKILL_LVUP_REQUEST};};
template<> struct MessageIdT<SkillRpcLvUpReplyWraper>{ enum{ID=RPC_CODE_SKILL_LVUP_REQUEST};};
template<> struct MessageIdT<SkillRpcChangeShortcutAskWraper>{ enum{ID=RPC_CODE_SKILL_CHANGESHORTCUT_REQUEST};};
template<> struct MessageIdT<SkillRpcChangeShortcutReplyWraper>{ enum{ID=RPC_CODE_SKILL_CHANGESHORTCUT_REQUEST};};
template<> struct MessageIdT<SkillRpcUseShortcutAskWraper>{ enum{ID=RPC_CODE_SKILL_USESHORTCUT_REQUEST};};
template<> struct MessageIdT<SkillRpcUseShortcutReplyWraper>{ enum{ID=RPC_CODE_SKILL_USESHORTCUT_REQUEST};};
template<> struct MessageIdT<SkillRpcOneKeyLvUpAskWraper>{ enum{ID=RPC_CODE_SKILL_ONEKEYLVUP_REQUEST};};
template<> struct MessageIdT<SkillRpcOneKeyLvUpReplyWraper>{ enum{ID=RPC_CODE_SKILL_ONEKEYLVUP_REQUEST};};
template<> struct MessageIdT<SkillRpcTalentLvUpAskWraper>{ enum{ID=RPC_CODE_SKILL_TALENTLVUP_REQUEST};};
template<> struct MessageIdT<SkillRpcTalentLvUpReplyWraper>{ enum{ID=RPC_CODE_SKILL_TALENTLVUP_REQUEST};};
template<> struct MessageIdT<SkillRpcTalentChangeSkillAskWraper>{ enum{ID=RPC_CODE_SKILL_TALENTCHANGESKILL_REQUEST};};
template<> struct MessageIdT<SkillRpcTalentChangeSkillReplyWraper>{ enum{ID=RPC_CODE_SKILL_TALENTCHANGESKILL_REQUEST};};
template<> struct MessageIdT<SkillRpcTalentResetAskWraper>{ enum{ID=RPC_CODE_SKILL_TALENTRESET_REQUEST};};
template<> struct MessageIdT<SkillRpcTalentResetReplyWraper>{ enum{ID=RPC_CODE_SKILL_TALENTRESET_REQUEST};};
template<> struct MessageIdT<SkillRpcLifeSkillUpAskWraper>{ enum{ID=RPC_CODE_SKILL_LIFESKILLUP_REQUEST};};
template<> struct MessageIdT<SkillRpcLifeSkillUpReplyWraper>{ enum{ID=RPC_CODE_SKILL_LIFESKILLUP_REQUEST};};


#endif
