/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleBaseAttr.cs
Author:
Description:
Version:	  1.0
History:
  <author>  <time>   <version >   <desc>

***********************************************************/
using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


public class BaseAttrRPC
{
	public const int ModuleId = 13;
	
	public const int RPC_CODE_BASEATTR_SYNCDATA_REQUEST = 1351;
	public const int RPC_CODE_BASEATTR_GETRANKREWARD_REQUEST = 1352;
	public const int RPC_CODE_BASEATTR_UPGRADERANK_REQUEST = 1353;

	
	private static BaseAttrRPC m_Instance = null;
	public static BaseAttrRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BaseAttrRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, BaseAttrData.Instance.UpdateField );
		


		return true;
	}


	/**
	*战队基础数据-->同步玩家数据 RPC请求
	*/
	public void SyncData(ReplyHandler replyCB)
	{
		BaseAttrRpcSyncDataAskWraper askPBWraper = new BaseAttrRpcSyncDataAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BASEATTR_SYNCDATA_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BaseAttrRpcSyncDataReplyWraper replyPBWraper = new BaseAttrRpcSyncDataReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*战队基础数据-->领取官阶奖励 RPC请求
	*/
	public void GetRankReward(ReplyHandler replyCB)
	{
		BaseAttrRpcGetRankRewardAskWraper askPBWraper = new BaseAttrRpcGetRankRewardAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BASEATTR_GETRANKREWARD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BaseAttrRpcGetRankRewardReplyWraper replyPBWraper = new BaseAttrRpcGetRankRewardReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*战队基础数据-->提升官阶 RPC请求
	*/
	public void UpGradeRank(ReplyHandler replyCB)
	{
		BaseAttrRpcUpGradeRankAskWraper askPBWraper = new BaseAttrRpcUpGradeRankAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BASEATTR_UPGRADERANK_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BaseAttrRpcUpGradeRankReplyWraper replyPBWraper = new BaseAttrRpcUpGradeRankReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class BaseAttrData
{
	public enum SyncIdE
	{
 		HEADID                                     = 1301,  //头像id
 		EXP                                        = 1302,  //经验
 		CREATETIME                                 = 1303,  //创建时间
 		LASTLOGINTIME                              = 1304,  //最后登录时间
 		LAST2LOGINDATE                             = 1305,  //倒数第二登录日期
 		LASTLOGOUTTIME                             = 1306,  //最后登出时间
 		MONEY                                      = 1307,  //游戏币
 		DIAMOND                                    = 1308,  //钻石
 		GMDIAMOND                                  = 1309,  //GM钻石
 		STRENGTH                                   = 1310,  //体力
 		FEATS                                      = 1311,  //功勋
 		GOTRANKREWARDTIME                          = 1312,  //领取官阶奖励时间
 		MAXMILITARY                                = 1314,  //历史最大战力
 		MASTERATTRS                                = 1315,  //主公基础属性
 		CURMILITARY                                = 1318,  //当前玩家战力

	}
	
	private static BaseAttrData m_Instance = null;
	public static BaseAttrData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BaseAttrData();
			}
			return m_Instance;

		}
	}
	

	public void UpdateField(int Id, int Index, byte[] buff, int start, int len )
	{
		SyncIdE SyncId = (SyncIdE)Id;
		byte[]  updateBuffer = new byte[len];
		Array.Copy(buff, start, updateBuffer, 0, len);
		int  iValue = 0;
		long lValue = 0;

		switch (SyncId)
		{
			case SyncIdE.HEADID:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.HeadID = iValue;
				break;
			case SyncIdE.EXP:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.Exp = iValue;
				break;
			case SyncIdE.CREATETIME:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.CreateTime = iValue;
				break;
			case SyncIdE.LASTLOGINTIME:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.LastLoginTime = iValue;
				break;
			case SyncIdE.LAST2LOGINDATE:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.Last2LoginDate = iValue;
				break;
			case SyncIdE.LASTLOGOUTTIME:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.LastLogoutTime = iValue;
				break;
			case SyncIdE.MONEY:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.Money = iValue;
				break;
			case SyncIdE.DIAMOND:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.Diamond = iValue;
				break;
			case SyncIdE.GMDIAMOND:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.GMDiamond = iValue;
				break;
			case SyncIdE.STRENGTH:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.Strength = iValue;
				break;
			case SyncIdE.FEATS:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.Feats = iValue;
				break;
			case SyncIdE.GOTRANKREWARDTIME:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.GotRankRewardTime = iValue;
				break;
			case SyncIdE.MAXMILITARY:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.MaxMilitary = iValue;
				break;
			case SyncIdE.MASTERATTRS:
				if(Index < 0){ m_Instance.ClearMasterAttrs(); break; }
				if (Index >= m_Instance.SizeMasterAttrs())
				{
					int Count = Index - m_Instance.SizeMasterAttrs() + 1;
					for (int i = 0; i < Count; i++)
						m_Instance.AddMasterAttrs(-1);
				}
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.SetMasterAttrs(Index, iValue);
				break;
			case SyncIdE.CURMILITARY:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.CurMilitary = iValue;
				break;

			default:
				break;
		}

		try
		{
			if (NotifySyncValueChanged!=null)
				NotifySyncValueChanged(Id, Index);
		}
		catch
		{
			Debug.Log("BaseAttrData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  

	//构造函数
	public BaseAttrData()
	{
		 m_HeadID = -1;
		 m_Exp = -1;
		 m_CreateTime = -1;
		 m_LastLoginTime = -1;
		 m_Last2LoginDate = -1;
		 m_LastLogoutTime = -1;
		 m_Money = -1;
		 m_Diamond = -1;
		 m_GMDiamond = -1;
		 m_Strength = -1;
		 m_Feats = -1;
		 m_GotRankRewardTime = -1;
		 m_MaxMilitary = -1;
		m_MasterAttrs = new List<int>();
		 m_CurMilitary = -1;

	}

 	//转化成Protobuffer类型函数
	public BaseAttrUserDataV1 ToPB()
	{
		BaseAttrUserDataV1 v = new BaseAttrUserDataV1();
		v.HeadID = m_HeadID;
		v.Exp = m_Exp;
		v.CreateTime = m_CreateTime;
		v.LastLoginTime = m_LastLoginTime;
		v.Last2LoginDate = m_Last2LoginDate;
		v.LastLogoutTime = m_LastLogoutTime;
		v.Money = m_Money;
		v.Diamond = m_Diamond;
		v.GMDiamond = m_GMDiamond;
		v.Strength = m_Strength;
		v.Feats = m_Feats;
		v.GotRankRewardTime = m_GotRankRewardTime;
		v.MaxMilitary = m_MaxMilitary;
		for (int i=0; i<(int)m_MasterAttrs.Count; i++)
			v.MasterAttrs.Add( m_MasterAttrs[i]);
		v.CurMilitary = m_CurMilitary;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BaseAttrUserDataV1 v)
	{
		m_HeadID = v.HeadID;
		m_Exp = v.Exp;
		m_CreateTime = v.CreateTime;
		m_LastLoginTime = v.LastLoginTime;
		m_Last2LoginDate = v.Last2LoginDate;
		m_LastLogoutTime = v.LastLogoutTime;
		m_Money = v.Money;
		m_Diamond = v.Diamond;
		m_GMDiamond = v.GMDiamond;
		m_Strength = v.Strength;
		m_Feats = v.Feats;
		m_GotRankRewardTime = v.GotRankRewardTime;
		m_MaxMilitary = v.MaxMilitary;
		m_MasterAttrs.Clear();
		for( int i=0; i<v.MasterAttrs.Count; i++)
			m_MasterAttrs.Add(v.MasterAttrs[i]);
		m_CurMilitary = v.CurMilitary;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BaseAttrUserDataV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BaseAttrUserDataV1 pb = ProtoBuf.Serializer.Deserialize<BaseAttrUserDataV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//头像id
	public int m_HeadID;
	public int HeadID
	{
		get { return m_HeadID;}
		set { m_HeadID = value; }
	}
	//经验
	public int m_Exp;
	public int Exp
	{
		get { return m_Exp;}
		set { m_Exp = value; }
	}
	//创建时间
	public int m_CreateTime;
	public int CreateTime
	{
		get { return m_CreateTime;}
		set { m_CreateTime = value; }
	}
	//最后登录时间
	public int m_LastLoginTime;
	public int LastLoginTime
	{
		get { return m_LastLoginTime;}
		set { m_LastLoginTime = value; }
	}
	//倒数第二登录日期
	public int m_Last2LoginDate;
	public int Last2LoginDate
	{
		get { return m_Last2LoginDate;}
		set { m_Last2LoginDate = value; }
	}
	//最后登出时间
	public int m_LastLogoutTime;
	public int LastLogoutTime
	{
		get { return m_LastLogoutTime;}
		set { m_LastLogoutTime = value; }
	}
	//游戏币
	public int m_Money;
	public int Money
	{
		get { return m_Money;}
		set { m_Money = value; }
	}
	//钻石
	public int m_Diamond;
	public int Diamond
	{
		get { return m_Diamond;}
		set { m_Diamond = value; }
	}
	//GM钻石
	public int m_GMDiamond;
	public int GMDiamond
	{
		get { return m_GMDiamond;}
		set { m_GMDiamond = value; }
	}
	//体力
	public int m_Strength;
	public int Strength
	{
		get { return m_Strength;}
		set { m_Strength = value; }
	}
	//功勋
	public int m_Feats;
	public int Feats
	{
		get { return m_Feats;}
		set { m_Feats = value; }
	}
	//领取官阶奖励时间
	public int m_GotRankRewardTime;
	public int GotRankRewardTime
	{
		get { return m_GotRankRewardTime;}
		set { m_GotRankRewardTime = value; }
	}
	//历史最大战力
	public int m_MaxMilitary;
	public int MaxMilitary
	{
		get { return m_MaxMilitary;}
		set { m_MaxMilitary = value; }
	}
	//主公基础属性
	public List<int> m_MasterAttrs;
	public int SizeMasterAttrs()
	{
		return m_MasterAttrs.Count;
	}
	public List<int> GetMasterAttrs()
	{
		return m_MasterAttrs;
	}
	public int GetMasterAttrs(int Index)
	{
		if(Index<0 || Index>=(int)m_MasterAttrs.Count)
			return -1;
		return m_MasterAttrs[Index];
	}
	public void SetMasterAttrs( List<int> v )
	{
		m_MasterAttrs=v;
	}
	public void SetMasterAttrs( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_MasterAttrs.Count)
			return;
		m_MasterAttrs[Index] = v;
	}
	public void AddMasterAttrs( int v=-1 )
	{
		m_MasterAttrs.Add(v);
	}
	public void ClearMasterAttrs( )
	{
		m_MasterAttrs.Clear();
	}
	//当前玩家战力
	public int m_CurMilitary;
	public int CurMilitary
	{
		get { return m_CurMilitary;}
		set { m_CurMilitary = value; }
	}



}
