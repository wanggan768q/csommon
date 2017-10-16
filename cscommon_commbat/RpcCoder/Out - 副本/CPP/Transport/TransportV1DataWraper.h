/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperTransport.h
* Author:       甘业清
* Description:  货运同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_TRANSPORT_H
#define __SYNC_WRAPER_TRANSPORT_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "TransportV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//奖励对象封装类
class TransportRewardObjWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	TransportRewardObjWraperV1()
	{
		
		m_RewardId = -1;
		m_LV = -1;
		m_GoodType = -1;

	}
	//赋值构造函数
	TransportRewardObjWraperV1(const TransportRewardObjV1& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportRewardObjV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportRewardObjV1 ToPB() const
	{
		TransportRewardObjV1 v;
		v.set_rewardid( m_RewardId );
		v.set_lv( m_LV );
		v.set_goodtype( m_GoodType );

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
		TransportRewardObjV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>RewardId(索引) [sint32]</li>\r\n";
		htmlBuff += "<li>LV(玩家等级) [sint32]</li>\r\n";
		htmlBuff += "<li>GoodType(货物类别) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>RewardId：%di</li>\r\n",m_RewardId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>LV：%di</li>\r\n",m_LV);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GoodType：%di</li>\r\n",m_GoodType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TransportRewardObjV1& v)
	{
		m_RewardId = v.rewardid();
		m_LV = v.lv();
		m_GoodType = v.goodtype();

	}

private:
	//索引
	INT32 m_RewardId;
public:
	void SetRewardId( INT32 v)
	{
		m_RewardId=v;
	}
	INT32 GetRewardId()
	{
		return m_RewardId;
	}
	INT32 GetRewardId() const
	{
		return m_RewardId;
	}
private:
	//玩家等级
	INT32 m_LV;
public:
	void SetLV( INT32 v)
	{
		m_LV=v;
	}
	INT32 GetLV()
	{
		return m_LV;
	}
	INT32 GetLV() const
	{
		return m_LV;
	}
private:
	//货物类别
	INT32 m_GoodType;
public:
	void SetGoodType( INT32 v)
	{
		m_GoodType=v;
	}
	INT32 GetGoodType()
	{
		return m_GoodType;
	}
	INT32 GetGoodType() const
	{
		return m_GoodType;
	}

};
//货物对象封装类
class TransportGoodsObjWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	TransportGoodsObjWraperV1()
	{
		
		m_GoodId = -1;
		m_TemplateId = -1;
		m_ItemNum = -1;
		m_CateGory = -1;
		m_IsHelp = false;

	}
	//赋值构造函数
	TransportGoodsObjWraperV1(const TransportGoodsObjV1& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportGoodsObjV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportGoodsObjV1 ToPB() const
	{
		TransportGoodsObjV1 v;
		v.set_goodid( m_GoodId );
		v.set_templateid( m_TemplateId );
		v.set_itemnum( m_ItemNum );
		v.set_category( m_CateGory );
		v.set_ishelp( m_IsHelp );

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
		TransportGoodsObjV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GoodId(货物id) [sint32]</li>\r\n";
		htmlBuff += "<li>TemplateId(物品配置id) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemNum(物品数量) [sint32]</li>\r\n";
		htmlBuff += "<li>CateGory(类别id) [sint32]</li>\r\n";
		htmlBuff += "<li>IsHelp(是否请求帮助) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>GoodId：%di</li>\r\n",m_GoodId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemNum：%di</li>\r\n",m_ItemNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CateGory：%di</li>\r\n",m_CateGory);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsHelp：%di</li>\r\n",m_IsHelp);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TransportGoodsObjV1& v)
	{
		m_GoodId = v.goodid();
		m_TemplateId = v.templateid();
		m_ItemNum = v.itemnum();
		m_CateGory = v.category();
		m_IsHelp = v.ishelp();

	}

private:
	//货物id
	INT32 m_GoodId;
public:
	void SetGoodId( INT32 v)
	{
		m_GoodId=v;
	}
	INT32 GetGoodId()
	{
		return m_GoodId;
	}
	INT32 GetGoodId() const
	{
		return m_GoodId;
	}
private:
	//物品配置id
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
	//物品数量
	INT32 m_ItemNum;
public:
	void SetItemNum( INT32 v)
	{
		m_ItemNum=v;
	}
	INT32 GetItemNum()
	{
		return m_ItemNum;
	}
	INT32 GetItemNum() const
	{
		return m_ItemNum;
	}
private:
	//类别id
	INT32 m_CateGory;
public:
	void SetCateGory( INT32 v)
	{
		m_CateGory=v;
	}
	INT32 GetCateGory()
	{
		return m_CateGory;
	}
	INT32 GetCateGory() const
	{
		return m_CateGory;
	}
private:
	//是否请求帮助
	bool m_IsHelp;
public:
	void SetIsHelp( bool v)
	{
		m_IsHelp=v;
	}
	bool GetIsHelp()
	{
		return m_IsHelp;
	}
	bool GetIsHelp() const
	{
		return m_IsHelp;
	}

};
//货运数据封装类
class TransportGoodsDataWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<TransportGoodsDataWraperV1>
{
public:
	//构造函数
	TransportGoodsDataWraperV1()
	{
		SetDataWraper( this );

		m_AskNum = -1;
		m_HelpNum = -1;
		m_RewardFlag = false;
		m_PickTaskFlag = false;

	}
	//赋值构造函数
	TransportGoodsDataWraperV1(const TransportGoodsDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportGoodsDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportGoodsDataV1 ToPB() const
	{
		TransportGoodsDataV1 v;
		v.mutable_goodsarray()->Reserve(m_GoodsArray.size());
		for (int i=0; i<(int)m_GoodsArray.size(); i++)
		{
			*v.add_goodsarray() = m_GoodsArray[i].ToPB();
		}
		v.set_asknum( m_AskNum );
		v.set_helpnum( m_HelpNum );
		v.mutable_rewardarry()->Reserve(m_RewardArry.size());
		for (int i=0; i<(int)m_RewardArry.size(); i++)
		{
			*v.add_rewardarry() = m_RewardArry[i].ToPB();
		}
		v.set_rewardflag( m_RewardFlag );
		v.set_picktaskflag( m_PickTaskFlag );

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
		TransportGoodsDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GoodsArray(货物容器) [GoodsObj] Array</li>\r\n";
		htmlBuff += "<li>AskNum(请求数量) [sint32]</li>\r\n";
		htmlBuff += "<li>HelpNum(帮助次数) [sint32]</li>\r\n";
		htmlBuff += "<li>RewardArry(起航奖励) [RewardObj] Array</li>\r\n";
		htmlBuff += "<li>RewardFlag(奖励是否领取标识) [bool]</li>\r\n";
		htmlBuff += "<li>PickTaskFlag(是否接取任务) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>GoodsArray：</li>\r\n";
		if( m_GoodsArray.size()>0) htmlBuff += m_GoodsArray[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_GoodsArray.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_GoodsArray[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>AskNum：%di</li>\r\n",m_AskNum);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>HelpNum：%di</li>\r\n",m_HelpNum);
		htmlBuff += tmpLine;
		htmlBuff += "<li>RewardArry：</li>\r\n";
		if( m_RewardArry.size()>0) htmlBuff += m_RewardArry[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_RewardArry.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_RewardArry[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>RewardFlag：%di</li>\r\n",m_RewardFlag);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>PickTaskFlag：%di</li>\r\n",m_PickTaskFlag);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TransportGoodsDataV1& v)
	{
		m_GoodsArray.clear();
		m_GoodsArray.reserve(v.goodsarray_size());
		for( int i=0; i<v.goodsarray_size(); i++)
			m_GoodsArray.push_back(v.goodsarray(i));
		m_AskNum = v.asknum();
		m_HelpNum = v.helpnum();
		m_RewardArry.clear();
		m_RewardArry.reserve(v.rewardarry_size());
		for( int i=0; i<v.rewardarry_size(); i++)
			m_RewardArry.push_back(v.rewardarry(i));
		m_RewardFlag = v.rewardflag();
		m_PickTaskFlag = v.picktaskflag();

	}

private:
	//货物容器
	vector<TransportGoodsObjWraperV1> m_GoodsArray;
public:
	int SizeGoodsArray()
	{
		return m_GoodsArray.size();
	}
	const vector<TransportGoodsObjWraperV1>& GetGoodsArray() const
	{
		return m_GoodsArray;
	}
	TransportGoodsObjWraperV1 GetGoodsArray(int Index) const
	{
		if(Index<0 || Index>=(int)m_GoodsArray.size())
		{
			assert(false);
			return TransportGoodsObjWraperV1();
		}
		return m_GoodsArray[Index];
	}
	void SetGoodsArray( const vector<TransportGoodsObjWraperV1>& v )
	{
		m_GoodsArray=v;
	}
	void ClearGoodsArray( )
	{
		m_GoodsArray.clear();
	}
	void SetGoodsArray( int Index, const TransportGoodsObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_GoodsArray.size())
		{
			assert(false);
			return;
		}
		m_GoodsArray[Index] = v;
	}
	void AddGoodsArray( const TransportGoodsObjWraperV1& v )
	{
		m_GoodsArray.push_back(v);
	}
private:
	//请求数量
	INT32 m_AskNum;
public:
	void SetAskNum( INT32 v)
	{
		m_AskNum=v;
	}
	INT32 GetAskNum()
	{
		return m_AskNum;
	}
	INT32 GetAskNum() const
	{
		return m_AskNum;
	}
private:
	//帮助次数
	INT32 m_HelpNum;
public:
	void SetHelpNum( INT32 v)
	{
		m_HelpNum=v;
	}
	INT32 GetHelpNum()
	{
		return m_HelpNum;
	}
	INT32 GetHelpNum() const
	{
		return m_HelpNum;
	}
private:
	//起航奖励
	vector<TransportRewardObjWraperV1> m_RewardArry;
public:
	int SizeRewardArry()
	{
		return m_RewardArry.size();
	}
	const vector<TransportRewardObjWraperV1>& GetRewardArry() const
	{
		return m_RewardArry;
	}
	TransportRewardObjWraperV1 GetRewardArry(int Index) const
	{
		if(Index<0 || Index>=(int)m_RewardArry.size())
		{
			assert(false);
			return TransportRewardObjWraperV1();
		}
		return m_RewardArry[Index];
	}
	void SetRewardArry( const vector<TransportRewardObjWraperV1>& v )
	{
		m_RewardArry=v;
	}
	void ClearRewardArry( )
	{
		m_RewardArry.clear();
	}
	void SetRewardArry( int Index, const TransportRewardObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_RewardArry.size())
		{
			assert(false);
			return;
		}
		m_RewardArry[Index] = v;
	}
	void AddRewardArry( const TransportRewardObjWraperV1& v )
	{
		m_RewardArry.push_back(v);
	}
private:
	//奖励是否领取标识
	bool m_RewardFlag;
public:
	void SetRewardFlag( bool v)
	{
		m_RewardFlag=v;
	}
	bool GetRewardFlag()
	{
		return m_RewardFlag;
	}
	bool GetRewardFlag() const
	{
		return m_RewardFlag;
	}
private:
	//是否接取任务
	bool m_PickTaskFlag;
public:
	void SetPickTaskFlag( bool v)
	{
		m_PickTaskFlag=v;
	}
	bool GetPickTaskFlag()
	{
		return m_PickTaskFlag;
	}
	bool GetPickTaskFlag() const
	{
		return m_PickTaskFlag;
	}

};

#endif
