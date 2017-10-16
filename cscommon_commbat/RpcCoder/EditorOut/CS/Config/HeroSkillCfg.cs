using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//英雄技能配置数据类
public class HeroSkillElement
{
	public int SkillID;          	//技能ID	编号
	public string Name;          	//技能名称	技能名称
	public string SourceIcon;    	//技能图标	技能图标
	public int Type;             	//技能类型	技能类型（1普攻2主动技能3大技能觉醒4合体技5被动）
	public string SkillMana;     	//技能耗蓝	技能对蓝的消耗（基础消耗+等级*等级消耗系数）
	public int CD;               	//技能CD	技能的CD时常，单位为s
	public string Tips;          	//技能描述	技能描述
	public int Lv;               	//是否可升级	是否可升级
	public int LvUp;             	//升级消耗参数	升级消耗参数
	public int Attributes;       	//技能属性	技能属性（1物理2魔法）
	public string JieSuo;        	//解锁条件	解锁条件（类型5对应神器ID，查看神器是否觉醒；类型6查看是否已上阵/拥有对应英雄；用,分割英雄）
	public int UnderAttack;      	//受击状态	
	public string AblityID;      	//技能文件	索引角色动作
	public int FriendNum;        	//友方目标个数	友方目标个数
	public int FriendBuffID;     	//友方BuffID	索引BUFF表
	public int BuffID;           	//敌方BuffID	索引BUFF表
	public int TrapID;           	//陷阱ID	索引陷阱表
	public int DamageRuduce;     	//伤害衰减率	多目标的伤害衰减（造成伤害*（1-伤害衰减率）=实际伤害）
	public string DamageNum;     	//基础伤害	技能造成的伤害
	public int SkillDistance;    	//攻击距离	技能攻击距离
	public int TargetOpt;        	//选中需求	是否需要选中释放
	public int TargetNum;        	//伤害目标个数	技能可以造成伤害的最大目标数量
	public int ParameterType;    	//被动参数类型	被动技能调用的参数类型
	public string ParameterNum;  	//被动参数数额	被动技能参数类型对应的数额
	public int TargetGroup;      	//目标阵营	1友，2敌，3全部
	public string DamageAmend;   	//伤害修正	伤害参数修正，用于特殊技能参数

	public bool IsValidate = false;
	public HeroSkillElement()
	{
		SkillID = -1;
	}
};

//英雄技能配置封装类
public class HeroSkillTable
{

	private HeroSkillTable()
	{
		m_mapElements = new Dictionary<int, HeroSkillElement>();
		m_emptyItem = new HeroSkillElement();
		m_vecAllElements = new List<HeroSkillElement>();
	}
	private Dictionary<int, HeroSkillElement> m_mapElements = null;
	private List<HeroSkillElement>	m_vecAllElements = null;
	private HeroSkillElement m_emptyItem = null;
	private static HeroSkillTable sInstance = null;

	public static HeroSkillTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new HeroSkillTable();
			return sInstance;
		}
	}

	public HeroSkillElement GetElement(int key)
	{
		if( m_mapElements.ContainsKey(key) )
			return m_mapElements[key];
		return m_emptyItem;
	}

	public int GetElementCount()
	{
		return m_mapElements.Count;
	}
	public bool HasElement(int key)
	{
		return m_mapElements.ContainsKey(key);
	}

  public List<HeroSkillElement> GetAllElement(Predicate<HeroSkillElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("HeroSkill.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("HeroSkill.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[HeroSkill.bin]未找到");
			return false;
		}
		return LoadBin(binTableContent);
	}


	public bool LoadBin(byte[] binContent)
	{
		m_mapElements.Clear();
		m_vecAllElements.Clear();
		int nCol, nRow;
		int readPos = 0;
		readPos += GameAssist.ReadInt32Variant( binContent, readPos, out nCol );
		readPos += GameAssist.ReadInt32Variant( binContent, readPos, out nRow );
		List<string> vecLine = new List<string>(nCol);
		List<int> vecHeadType = new List<int>(nCol);
        string tmpStr;
        int tmpInt;
		for( int i=0; i<nCol; i++ )
		{
            readPos += GameAssist.ReadString(binContent, readPos, out tmpStr);
            readPos += GameAssist.ReadInt32Variant(binContent, readPos, out tmpInt);
            vecLine.Add(tmpStr);
            vecHeadType.Add(tmpInt);
		}
		if(vecLine.Count != 26)
		{
			Debug.Log("HeroSkill.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="SkillID"){Debug.Log("HeroSkill.csv中字段[SkillID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("HeroSkill.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="SourceIcon"){Debug.Log("HeroSkill.csv中字段[SourceIcon]位置不对应"); return false; }
		if(vecLine[3]!="Type"){Debug.Log("HeroSkill.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[4]!="SkillMana"){Debug.Log("HeroSkill.csv中字段[SkillMana]位置不对应"); return false; }
		if(vecLine[5]!="CD"){Debug.Log("HeroSkill.csv中字段[CD]位置不对应"); return false; }
		if(vecLine[6]!="Tips"){Debug.Log("HeroSkill.csv中字段[Tips]位置不对应"); return false; }
		if(vecLine[7]!="Lv"){Debug.Log("HeroSkill.csv中字段[Lv]位置不对应"); return false; }
		if(vecLine[8]!="LvUp"){Debug.Log("HeroSkill.csv中字段[LvUp]位置不对应"); return false; }
		if(vecLine[9]!="Attributes"){Debug.Log("HeroSkill.csv中字段[Attributes]位置不对应"); return false; }
		if(vecLine[10]!="JieSuo"){Debug.Log("HeroSkill.csv中字段[JieSuo]位置不对应"); return false; }
		if(vecLine[11]!="UnderAttack"){Debug.Log("HeroSkill.csv中字段[UnderAttack]位置不对应"); return false; }
		if(vecLine[12]!="AblityID"){Debug.Log("HeroSkill.csv中字段[AblityID]位置不对应"); return false; }
		if(vecLine[13]!="FriendNum"){Debug.Log("HeroSkill.csv中字段[FriendNum]位置不对应"); return false; }
		if(vecLine[14]!="FriendBuffID"){Debug.Log("HeroSkill.csv中字段[FriendBuffID]位置不对应"); return false; }
		if(vecLine[15]!="BuffID"){Debug.Log("HeroSkill.csv中字段[BuffID]位置不对应"); return false; }
		if(vecLine[16]!="TrapID"){Debug.Log("HeroSkill.csv中字段[TrapID]位置不对应"); return false; }
		if(vecLine[17]!="DamageRuduce"){Debug.Log("HeroSkill.csv中字段[DamageRuduce]位置不对应"); return false; }
		if(vecLine[18]!="DamageNum"){Debug.Log("HeroSkill.csv中字段[DamageNum]位置不对应"); return false; }
		if(vecLine[19]!="SkillDistance"){Debug.Log("HeroSkill.csv中字段[SkillDistance]位置不对应"); return false; }
		if(vecLine[20]!="TargetOpt"){Debug.Log("HeroSkill.csv中字段[TargetOpt]位置不对应"); return false; }
		if(vecLine[21]!="TargetNum"){Debug.Log("HeroSkill.csv中字段[TargetNum]位置不对应"); return false; }
		if(vecLine[22]!="ParameterType"){Debug.Log("HeroSkill.csv中字段[ParameterType]位置不对应"); return false; }
		if(vecLine[23]!="ParameterNum"){Debug.Log("HeroSkill.csv中字段[ParameterNum]位置不对应"); return false; }
		if(vecLine[24]!="TargetGroup"){Debug.Log("HeroSkill.csv中字段[TargetGroup]位置不对应"); return false; }
		if(vecLine[25]!="DamageAmend"){Debug.Log("HeroSkill.csv中字段[DamageAmend]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			HeroSkillElement member = new HeroSkillElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.SkillID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.SourceIcon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.SkillMana);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CD );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Tips);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Lv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.LvUp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Attributes );
			readPos += GameAssist.ReadString( binContent, readPos, out member.JieSuo);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.UnderAttack );
			readPos += GameAssist.ReadString( binContent, readPos, out member.AblityID);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.FriendNum );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.FriendBuffID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.BuffID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.TrapID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.DamageRuduce );
			readPos += GameAssist.ReadString( binContent, readPos, out member.DamageNum);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.SkillDistance );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.TargetOpt );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.TargetNum );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ParameterType );
			readPos += GameAssist.ReadString( binContent, readPos, out member.ParameterNum);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.TargetGroup );
			readPos += GameAssist.ReadString( binContent, readPos, out member.DamageAmend);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.SkillID] = member;
		}
		return true;
	}
	public bool LoadCsv(string strContent)
	{
		if( strContent.Length == 0 )
			return false;
		m_mapElements.Clear();
		m_vecAllElements.Clear();
		int contentOffset = 0;
		List<string> vecLine;
		vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
		if(vecLine.Count != 26)
		{
			Debug.Log("HeroSkill.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="SkillID"){Debug.Log("HeroSkill.csv中字段[SkillID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("HeroSkill.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="SourceIcon"){Debug.Log("HeroSkill.csv中字段[SourceIcon]位置不对应"); return false; }
		if(vecLine[3]!="Type"){Debug.Log("HeroSkill.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[4]!="SkillMana"){Debug.Log("HeroSkill.csv中字段[SkillMana]位置不对应"); return false; }
		if(vecLine[5]!="CD"){Debug.Log("HeroSkill.csv中字段[CD]位置不对应"); return false; }
		if(vecLine[6]!="Tips"){Debug.Log("HeroSkill.csv中字段[Tips]位置不对应"); return false; }
		if(vecLine[7]!="Lv"){Debug.Log("HeroSkill.csv中字段[Lv]位置不对应"); return false; }
		if(vecLine[8]!="LvUp"){Debug.Log("HeroSkill.csv中字段[LvUp]位置不对应"); return false; }
		if(vecLine[9]!="Attributes"){Debug.Log("HeroSkill.csv中字段[Attributes]位置不对应"); return false; }
		if(vecLine[10]!="JieSuo"){Debug.Log("HeroSkill.csv中字段[JieSuo]位置不对应"); return false; }
		if(vecLine[11]!="UnderAttack"){Debug.Log("HeroSkill.csv中字段[UnderAttack]位置不对应"); return false; }
		if(vecLine[12]!="AblityID"){Debug.Log("HeroSkill.csv中字段[AblityID]位置不对应"); return false; }
		if(vecLine[13]!="FriendNum"){Debug.Log("HeroSkill.csv中字段[FriendNum]位置不对应"); return false; }
		if(vecLine[14]!="FriendBuffID"){Debug.Log("HeroSkill.csv中字段[FriendBuffID]位置不对应"); return false; }
		if(vecLine[15]!="BuffID"){Debug.Log("HeroSkill.csv中字段[BuffID]位置不对应"); return false; }
		if(vecLine[16]!="TrapID"){Debug.Log("HeroSkill.csv中字段[TrapID]位置不对应"); return false; }
		if(vecLine[17]!="DamageRuduce"){Debug.Log("HeroSkill.csv中字段[DamageRuduce]位置不对应"); return false; }
		if(vecLine[18]!="DamageNum"){Debug.Log("HeroSkill.csv中字段[DamageNum]位置不对应"); return false; }
		if(vecLine[19]!="SkillDistance"){Debug.Log("HeroSkill.csv中字段[SkillDistance]位置不对应"); return false; }
		if(vecLine[20]!="TargetOpt"){Debug.Log("HeroSkill.csv中字段[TargetOpt]位置不对应"); return false; }
		if(vecLine[21]!="TargetNum"){Debug.Log("HeroSkill.csv中字段[TargetNum]位置不对应"); return false; }
		if(vecLine[22]!="ParameterType"){Debug.Log("HeroSkill.csv中字段[ParameterType]位置不对应"); return false; }
		if(vecLine[23]!="ParameterNum"){Debug.Log("HeroSkill.csv中字段[ParameterNum]位置不对应"); return false; }
		if(vecLine[24]!="TargetGroup"){Debug.Log("HeroSkill.csv中字段[TargetGroup]位置不对应"); return false; }
		if(vecLine[25]!="DamageAmend"){Debug.Log("HeroSkill.csv中字段[DamageAmend]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)26)
			{
				return false;
			}
			HeroSkillElement member = new HeroSkillElement();
			member.SkillID=Convert.ToInt32(vecLine[0]);
			member.Name=vecLine[1];
			member.SourceIcon=vecLine[2];
			member.Type=Convert.ToInt32(vecLine[3]);
			member.SkillMana=vecLine[4];
			member.CD=Convert.ToInt32(vecLine[5]);
			member.Tips=vecLine[6];
			member.Lv=Convert.ToInt32(vecLine[7]);
			member.LvUp=Convert.ToInt32(vecLine[8]);
			member.Attributes=Convert.ToInt32(vecLine[9]);
			member.JieSuo=vecLine[10];
			member.UnderAttack=Convert.ToInt32(vecLine[11]);
			member.AblityID=vecLine[12];
			member.FriendNum=Convert.ToInt32(vecLine[13]);
			member.FriendBuffID=Convert.ToInt32(vecLine[14]);
			member.BuffID=Convert.ToInt32(vecLine[15]);
			member.TrapID=Convert.ToInt32(vecLine[16]);
			member.DamageRuduce=Convert.ToInt32(vecLine[17]);
			member.DamageNum=vecLine[18];
			member.SkillDistance=Convert.ToInt32(vecLine[19]);
			member.TargetOpt=Convert.ToInt32(vecLine[20]);
			member.TargetNum=Convert.ToInt32(vecLine[21]);
			member.ParameterType=Convert.ToInt32(vecLine[22]);
			member.ParameterNum=vecLine[23];
			member.TargetGroup=Convert.ToInt32(vecLine[24]);
			member.DamageAmend=vecLine[25];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.SkillID] = member;
		}
		return true;
	}
};
