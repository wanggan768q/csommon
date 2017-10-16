/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperSkill.h
* Author:       甘业清
* Description:  技能同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_SKILL_H
#define __SYNC_WRAPER_SKILL_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "SkillV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//天赋槽位封装类
class SkillTalentSlotWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	SkillTalentSlotWraperV1()
	{
		
		m_SkillId = -1;
		m_Level = 0;
		m_IsLock = true;

	}
	//赋值构造函数
	SkillTalentSlotWraperV1(const SkillTalentSlotV1& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillTalentSlotV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillTalentSlotV1 ToPB() const
	{
		SkillTalentSlotV1 v;
		v.set_skillid( m_SkillId );
		v.set_level( m_Level );
		v.set_islock( m_IsLock );

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
		SkillTalentSlotV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SkillId(技能Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Level(槽位等级) [sint32]</li>\r\n";
		htmlBuff += "<li>IsLock(是否开启) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsLock：%di</li>\r\n",m_IsLock);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillTalentSlotV1& v)
	{
		m_SkillId = v.skillid();
		m_Level = v.level();
		m_IsLock = v.islock();

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
	//槽位等级
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
	//是否开启
	bool m_IsLock;
public:
	void SetIsLock( bool v)
	{
		m_IsLock=v;
	}
	bool GetIsLock()
	{
		return m_IsLock;
	}
	bool GetIsLock() const
	{
		return m_IsLock;
	}

};
//一个技能方案封装类
class SkillShortcutObjWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	SkillShortcutObjWraperV1()
	{
		
		m_Type = -1;

	}
	//赋值构造函数
	SkillShortcutObjWraperV1(const SkillShortcutObjV1& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillShortcutObjV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillShortcutObjV1 ToPB() const
	{
		SkillShortcutObjV1 v;
		v.mutable_skillid()->Reserve(m_SkillId.size());
		for (int i=0; i<(int)m_SkillId.size(); i++)
		{
			v.add_skillid(m_SkillId[i]);
		}
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
		SkillShortcutObjV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SkillId(技能Id) [sint32] Array</li>\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>SkillId：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_SkillId.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_SkillId[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_SkillId.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillShortcutObjV1& v)
	{
		m_SkillId.clear();
		m_SkillId.reserve(v.skillid_size());
		for( int i=0; i<v.skillid_size(); i++)
			m_SkillId.push_back(v.skillid(i));
		m_Type = v.type();

	}

private:
	//技能Id
	vector<INT32> m_SkillId;
public:
	int SizeSkillId()
	{
		return m_SkillId.size();
	}
	const vector<INT32>& GetSkillId() const
	{
		return m_SkillId;
	}
	INT32 GetSkillId(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillId.size())
		{
			assert(false);
			return INT32();
		}
		return m_SkillId[Index];
	}
	void SetSkillId( const vector<INT32>& v )
	{
		m_SkillId=v;
	}
	void ClearSkillId( )
	{
		m_SkillId.clear();
	}
	void SetSkillId( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_SkillId.size())
		{
			assert(false);
			return;
		}
		m_SkillId[Index] = v;
	}
	void AddSkillId( INT32 v = -1 )
	{
		m_SkillId.push_back(v);
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
//技能对象封装类
class SkillSkillObjWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	SkillSkillObjWraperV1()
	{
		
		m_SkillId = -1;
		m_Lv = 1;
		m_IsLearn = false;

	}
	//赋值构造函数
	SkillSkillObjWraperV1(const SkillSkillObjV1& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillSkillObjV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillSkillObjV1 ToPB() const
	{
		SkillSkillObjV1 v;
		v.set_skillid( m_SkillId );
		v.set_lv( m_Lv );
		v.set_islearn( m_IsLearn );

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
		SkillSkillObjV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SkillId(技能Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Lv(等级) [sint32]</li>\r\n";
		htmlBuff += "<li>IsLearn(是否学习) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Lv：%di</li>\r\n",m_Lv);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsLearn：%di</li>\r\n",m_IsLearn);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillSkillObjV1& v)
	{
		m_SkillId = v.skillid();
		m_Lv = v.lv();
		m_IsLearn = v.islearn();

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
	//等级
	INT32 m_Lv;
public:
	void SetLv( INT32 v)
	{
		m_Lv=v;
	}
	INT32 GetLv()
	{
		return m_Lv;
	}
	INT32 GetLv() const
	{
		return m_Lv;
	}
private:
	//是否学习
	bool m_IsLearn;
public:
	void SetIsLearn( bool v)
	{
		m_IsLearn=v;
	}
	bool GetIsLearn()
	{
		return m_IsLearn;
	}
	bool GetIsLearn() const
	{
		return m_IsLearn;
	}

};
//技能数据封装类
class SkillSkillDataWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<SkillSkillDataWraperV1>
{
public:
	//构造函数
	SkillSkillDataWraperV1()
	{
		SetDataWraper( this );

		m_ShortcutId = -1;
		m_TotalCostExp = 0;
		m_TalentLevel = 0;
		m_TalentPoint = 0;

	}
	//赋值构造函数
	SkillSkillDataWraperV1(const SkillSkillDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillSkillDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillSkillDataV1 ToPB() const
	{
		SkillSkillDataV1 v;
		v.mutable_skillarray()->Reserve(m_SkillArray.size());
		for (int i=0; i<(int)m_SkillArray.size(); i++)
		{
			*v.add_skillarray() = m_SkillArray[i].ToPB();
		}
		v.mutable_shortcutarray()->Reserve(m_ShortcutArray.size());
		for (int i=0; i<(int)m_ShortcutArray.size(); i++)
		{
			*v.add_shortcutarray() = m_ShortcutArray[i].ToPB();
		}
		v.set_shortcutid( m_ShortcutId );
		v.mutable_talentskill()->Reserve(m_TalentSkill.size());
		for (int i=0; i<(int)m_TalentSkill.size(); i++)
		{
			*v.add_talentskill() = m_TalentSkill[i].ToPB();
		}
		v.set_totalcostexp( m_TotalCostExp );
		v.set_talentlevel( m_TalentLevel );
		v.set_talentpoint( m_TalentPoint );
		v.mutable_lifeskillarray()->Reserve(m_LifeSkillArray.size());
		for (int i=0; i<(int)m_LifeSkillArray.size(); i++)
		{
			*v.add_lifeskillarray() = m_LifeSkillArray[i].ToPB();
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
		SkillSkillDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SkillArray(全部技能) [SkillObj] Array</li>\r\n";
		htmlBuff += "<li>ShortcutArray(快捷栏) [ShortcutObj] Array</li>\r\n";
		htmlBuff += "<li>ShortcutId(方案Id，从0开始) [sint32]</li>\r\n";
		htmlBuff += "<li>TalentSkill(天赋技能) [TalentSlot] Array</li>\r\n";
		htmlBuff += "<li>TotalCostExp(累计技能消耗经验) [sint32]</li>\r\n";
		htmlBuff += "<li>TalentLevel(修为等级) [sint32]</li>\r\n";
		htmlBuff += "<li>TalentPoint(天赋点) [sint32]</li>\r\n";
		htmlBuff += "<li>LifeSkillArray(生活技能) [SkillObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>SkillArray：</li>\r\n";
		if( m_SkillArray.size()>0) htmlBuff += m_SkillArray[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_SkillArray.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_SkillArray[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>ShortcutArray：</li>\r\n";
		if( m_ShortcutArray.size()>0) htmlBuff += m_ShortcutArray[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ShortcutArray.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ShortcutArray[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>ShortcutId：%di</li>\r\n",m_ShortcutId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>TalentSkill：</li>\r\n";
		if( m_TalentSkill.size()>0) htmlBuff += m_TalentSkill[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_TalentSkill.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_TalentSkill[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>TotalCostExp：%di</li>\r\n",m_TotalCostExp);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TalentLevel：%di</li>\r\n",m_TalentLevel);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TalentPoint：%di</li>\r\n",m_TalentPoint);
		htmlBuff += tmpLine;
		htmlBuff += "<li>LifeSkillArray：</li>\r\n";
		if( m_LifeSkillArray.size()>0) htmlBuff += m_LifeSkillArray[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_LifeSkillArray.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_LifeSkillArray[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SkillSkillDataV1& v)
	{
		m_SkillArray.clear();
		m_SkillArray.reserve(v.skillarray_size());
		for( int i=0; i<v.skillarray_size(); i++)
			m_SkillArray.push_back(v.skillarray(i));
		m_ShortcutArray.clear();
		m_ShortcutArray.reserve(v.shortcutarray_size());
		for( int i=0; i<v.shortcutarray_size(); i++)
			m_ShortcutArray.push_back(v.shortcutarray(i));
		m_ShortcutId = v.shortcutid();
		m_TalentSkill.clear();
		m_TalentSkill.reserve(v.talentskill_size());
		for( int i=0; i<v.talentskill_size(); i++)
			m_TalentSkill.push_back(v.talentskill(i));
		m_TotalCostExp = v.totalcostexp();
		m_TalentLevel = v.talentlevel();
		m_TalentPoint = v.talentpoint();
		m_LifeSkillArray.clear();
		m_LifeSkillArray.reserve(v.lifeskillarray_size());
		for( int i=0; i<v.lifeskillarray_size(); i++)
			m_LifeSkillArray.push_back(v.lifeskillarray(i));

	}

private:
	//全部技能
	vector<SkillSkillObjWraperV1> m_SkillArray;
public:
	int SizeSkillArray()
	{
		return m_SkillArray.size();
	}
	const vector<SkillSkillObjWraperV1>& GetSkillArray() const
	{
		return m_SkillArray;
	}
	SkillSkillObjWraperV1 GetSkillArray(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillArray.size())
		{
			assert(false);
			return SkillSkillObjWraperV1();
		}
		return m_SkillArray[Index];
	}
	void SetSkillArray( const vector<SkillSkillObjWraperV1>& v )
	{
		m_SkillArray=v;
	}
	void ClearSkillArray( )
	{
		m_SkillArray.clear();
	}
	void SetSkillArray( int Index, const SkillSkillObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_SkillArray.size())
		{
			assert(false);
			return;
		}
		m_SkillArray[Index] = v;
	}
	void AddSkillArray( const SkillSkillObjWraperV1& v )
	{
		m_SkillArray.push_back(v);
	}
private:
	//快捷栏
	vector<SkillShortcutObjWraperV1> m_ShortcutArray;
public:
	int SizeShortcutArray()
	{
		return m_ShortcutArray.size();
	}
	const vector<SkillShortcutObjWraperV1>& GetShortcutArray() const
	{
		return m_ShortcutArray;
	}
	SkillShortcutObjWraperV1 GetShortcutArray(int Index) const
	{
		if(Index<0 || Index>=(int)m_ShortcutArray.size())
		{
			assert(false);
			return SkillShortcutObjWraperV1();
		}
		return m_ShortcutArray[Index];
	}
	void SetShortcutArray( const vector<SkillShortcutObjWraperV1>& v )
	{
		m_ShortcutArray=v;
	}
	void ClearShortcutArray( )
	{
		m_ShortcutArray.clear();
	}
	void SetShortcutArray( int Index, const SkillShortcutObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_ShortcutArray.size())
		{
			assert(false);
			return;
		}
		m_ShortcutArray[Index] = v;
	}
	void AddShortcutArray( const SkillShortcutObjWraperV1& v )
	{
		m_ShortcutArray.push_back(v);
	}
private:
	//方案Id，从0开始
	INT32 m_ShortcutId;
public:
	void SetShortcutId( INT32 v)
	{
		m_ShortcutId=v;
	}
	INT32 GetShortcutId()
	{
		return m_ShortcutId;
	}
	INT32 GetShortcutId() const
	{
		return m_ShortcutId;
	}
private:
	//天赋技能
	vector<SkillTalentSlotWraperV1> m_TalentSkill;
public:
	int SizeTalentSkill()
	{
		return m_TalentSkill.size();
	}
	const vector<SkillTalentSlotWraperV1>& GetTalentSkill() const
	{
		return m_TalentSkill;
	}
	SkillTalentSlotWraperV1 GetTalentSkill(int Index) const
	{
		if(Index<0 || Index>=(int)m_TalentSkill.size())
		{
			assert(false);
			return SkillTalentSlotWraperV1();
		}
		return m_TalentSkill[Index];
	}
	void SetTalentSkill( const vector<SkillTalentSlotWraperV1>& v )
	{
		m_TalentSkill=v;
	}
	void ClearTalentSkill( )
	{
		m_TalentSkill.clear();
	}
	void SetTalentSkill( int Index, const SkillTalentSlotWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_TalentSkill.size())
		{
			assert(false);
			return;
		}
		m_TalentSkill[Index] = v;
	}
	void AddTalentSkill( const SkillTalentSlotWraperV1& v )
	{
		m_TalentSkill.push_back(v);
	}
private:
	//累计技能消耗经验
	INT32 m_TotalCostExp;
public:
	void SetTotalCostExp( INT32 v)
	{
		m_TotalCostExp=v;
	}
	INT32 GetTotalCostExp()
	{
		return m_TotalCostExp;
	}
	INT32 GetTotalCostExp() const
	{
		return m_TotalCostExp;
	}
private:
	//修为等级
	INT32 m_TalentLevel;
public:
	void SetTalentLevel( INT32 v)
	{
		m_TalentLevel=v;
	}
	INT32 GetTalentLevel()
	{
		return m_TalentLevel;
	}
	INT32 GetTalentLevel() const
	{
		return m_TalentLevel;
	}
private:
	//天赋点
	INT32 m_TalentPoint;
public:
	void SetTalentPoint( INT32 v)
	{
		m_TalentPoint=v;
	}
	INT32 GetTalentPoint()
	{
		return m_TalentPoint;
	}
	INT32 GetTalentPoint() const
	{
		return m_TalentPoint;
	}
private:
	//生活技能
	vector<SkillSkillObjWraperV1> m_LifeSkillArray;
public:
	int SizeLifeSkillArray()
	{
		return m_LifeSkillArray.size();
	}
	const vector<SkillSkillObjWraperV1>& GetLifeSkillArray() const
	{
		return m_LifeSkillArray;
	}
	SkillSkillObjWraperV1 GetLifeSkillArray(int Index) const
	{
		if(Index<0 || Index>=(int)m_LifeSkillArray.size())
		{
			assert(false);
			return SkillSkillObjWraperV1();
		}
		return m_LifeSkillArray[Index];
	}
	void SetLifeSkillArray( const vector<SkillSkillObjWraperV1>& v )
	{
		m_LifeSkillArray=v;
	}
	void ClearLifeSkillArray( )
	{
		m_LifeSkillArray.clear();
	}
	void SetLifeSkillArray( int Index, const SkillSkillObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_LifeSkillArray.size())
		{
			assert(false);
			return;
		}
		m_LifeSkillArray[Index] = v;
	}
	void AddLifeSkillArray( const SkillSkillObjWraperV1& v )
	{
		m_LifeSkillArray.push_back(v);
	}

};

#endif
