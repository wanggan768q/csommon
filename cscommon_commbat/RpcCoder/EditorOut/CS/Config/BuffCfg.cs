using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//技能效果表配置数据类
public class BuffElement
{
	public int BuffID;           	//BuffID	编号
	public string Name;          	//名字	BUFF的名字，主要策划识别用
	public string Describe;      	//描述	BUFF描述
	public int IconShow;         	//是否显示ICON	1显示2不显示
	public string IconName;      	//Icon	Icon路径配置
	public int DieEfficient;     	//死亡是否存续	Buff在角色死亡后能否继续存在（1是0否）
	public string TriggerPos;    	//触发位置	状态触发时播放特效的位置
	public string TriggerEffects;	//触发特效	状态触发时播放的特效
	public string SustainPos;    	//持续位置	状态持续时播放特效的位置
	public string SustainEffects;	//持续特效	状态持续时播放的特效
	public string AblityID;      	//动作文件	动作的索引目录
	public int Type;             	//BUFF类	定义的类别（同类覆盖，不同共存）
	public string ImmuneType;    	//抵抗的类	免疫该类的BUFF,可多项，逗号隔开
	public int Duration;         	//持续时间	BUFF的持续时间
	public int Interval;         	//作用间隔	BUFF的作用间隔
	public int RestoreHealth;    	//生命恢复	生命值恢复的速度(n/s)
	public int RestorePower;     	//能量恢复	能量恢复的速度(n/s)
	public int UseSkill;         	//能否释放技能	能为1，不能为0
	public int Speed;            	//移动速度	当前的移动速度（万分比）
	public int HitFrequency;     	//攻击速度	当前的攻击速度（万分比）
	public int Attribute1Type;   	//属性1类型	增加的属性类型
	public int Attribute1Value;  	//属性1参数	增加的属性具体数值
	public int Attribute2Type;   	//属性2类型	增加的属性类型
	public int Attribute2Value;  	//属性2参数	增加的属性具体数值

	public bool IsValidate = false;
	public BuffElement()
	{
		BuffID = -1;
	}
};

//技能效果表配置封装类
public class BuffTable
{

	private BuffTable()
	{
		m_mapElements = new Dictionary<int, BuffElement>();
		m_emptyItem = new BuffElement();
		m_vecAllElements = new List<BuffElement>();
	}
	private Dictionary<int, BuffElement> m_mapElements = null;
	private List<BuffElement>	m_vecAllElements = null;
	private BuffElement m_emptyItem = null;
	private static BuffTable sInstance = null;

	public static BuffTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new BuffTable();
			return sInstance;
		}
	}

	public BuffElement GetElement(int key)
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

  public List<BuffElement> GetAllElement(Predicate<BuffElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Buff.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Buff.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[Buff.bin]未找到");
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
		if(vecLine.Count != 24)
		{
			Debug.Log("Buff.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="BuffID"){Debug.Log("Buff.csv中字段[BuffID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("Buff.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="Describe"){Debug.Log("Buff.csv中字段[Describe]位置不对应"); return false; }
		if(vecLine[3]!="IconShow"){Debug.Log("Buff.csv中字段[IconShow]位置不对应"); return false; }
		if(vecLine[4]!="IconName"){Debug.Log("Buff.csv中字段[IconName]位置不对应"); return false; }
		if(vecLine[5]!="DieEfficient"){Debug.Log("Buff.csv中字段[DieEfficient]位置不对应"); return false; }
		if(vecLine[6]!="TriggerPos"){Debug.Log("Buff.csv中字段[TriggerPos]位置不对应"); return false; }
		if(vecLine[7]!="TriggerEffects"){Debug.Log("Buff.csv中字段[TriggerEffects]位置不对应"); return false; }
		if(vecLine[8]!="SustainPos"){Debug.Log("Buff.csv中字段[SustainPos]位置不对应"); return false; }
		if(vecLine[9]!="SustainEffects"){Debug.Log("Buff.csv中字段[SustainEffects]位置不对应"); return false; }
		if(vecLine[10]!="AblityID"){Debug.Log("Buff.csv中字段[AblityID]位置不对应"); return false; }
		if(vecLine[11]!="Type"){Debug.Log("Buff.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[12]!="ImmuneType"){Debug.Log("Buff.csv中字段[ImmuneType]位置不对应"); return false; }
		if(vecLine[13]!="Duration"){Debug.Log("Buff.csv中字段[Duration]位置不对应"); return false; }
		if(vecLine[14]!="Interval"){Debug.Log("Buff.csv中字段[Interval]位置不对应"); return false; }
		if(vecLine[15]!="RestoreHealth"){Debug.Log("Buff.csv中字段[RestoreHealth]位置不对应"); return false; }
		if(vecLine[16]!="RestorePower"){Debug.Log("Buff.csv中字段[RestorePower]位置不对应"); return false; }
		if(vecLine[17]!="UseSkill"){Debug.Log("Buff.csv中字段[UseSkill]位置不对应"); return false; }
		if(vecLine[18]!="Speed"){Debug.Log("Buff.csv中字段[Speed]位置不对应"); return false; }
		if(vecLine[19]!="HitFrequency"){Debug.Log("Buff.csv中字段[HitFrequency]位置不对应"); return false; }
		if(vecLine[20]!="Attribute1Type"){Debug.Log("Buff.csv中字段[Attribute1Type]位置不对应"); return false; }
		if(vecLine[21]!="Attribute1Value"){Debug.Log("Buff.csv中字段[Attribute1Value]位置不对应"); return false; }
		if(vecLine[22]!="Attribute2Type"){Debug.Log("Buff.csv中字段[Attribute2Type]位置不对应"); return false; }
		if(vecLine[23]!="Attribute2Value"){Debug.Log("Buff.csv中字段[Attribute2Value]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BuffElement member = new BuffElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.BuffID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.Describe);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.IconShow );
			readPos += GameAssist.ReadString( binContent, readPos, out member.IconName);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.DieEfficient );
			readPos += GameAssist.ReadString( binContent, readPos, out member.TriggerPos);
			readPos += GameAssist.ReadString( binContent, readPos, out member.TriggerEffects);
			readPos += GameAssist.ReadString( binContent, readPos, out member.SustainPos);
			readPos += GameAssist.ReadString( binContent, readPos, out member.SustainEffects);
			readPos += GameAssist.ReadString( binContent, readPos, out member.AblityID);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.ImmuneType);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Duration );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Interval );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.RestoreHealth );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.RestorePower );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.UseSkill );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Speed );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HitFrequency );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Attribute1Type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Attribute1Value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Attribute2Type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Attribute2Value );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.BuffID] = member;
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
		if(vecLine.Count != 24)
		{
			Debug.Log("Buff.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="BuffID"){Debug.Log("Buff.csv中字段[BuffID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("Buff.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="Describe"){Debug.Log("Buff.csv中字段[Describe]位置不对应"); return false; }
		if(vecLine[3]!="IconShow"){Debug.Log("Buff.csv中字段[IconShow]位置不对应"); return false; }
		if(vecLine[4]!="IconName"){Debug.Log("Buff.csv中字段[IconName]位置不对应"); return false; }
		if(vecLine[5]!="DieEfficient"){Debug.Log("Buff.csv中字段[DieEfficient]位置不对应"); return false; }
		if(vecLine[6]!="TriggerPos"){Debug.Log("Buff.csv中字段[TriggerPos]位置不对应"); return false; }
		if(vecLine[7]!="TriggerEffects"){Debug.Log("Buff.csv中字段[TriggerEffects]位置不对应"); return false; }
		if(vecLine[8]!="SustainPos"){Debug.Log("Buff.csv中字段[SustainPos]位置不对应"); return false; }
		if(vecLine[9]!="SustainEffects"){Debug.Log("Buff.csv中字段[SustainEffects]位置不对应"); return false; }
		if(vecLine[10]!="AblityID"){Debug.Log("Buff.csv中字段[AblityID]位置不对应"); return false; }
		if(vecLine[11]!="Type"){Debug.Log("Buff.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[12]!="ImmuneType"){Debug.Log("Buff.csv中字段[ImmuneType]位置不对应"); return false; }
		if(vecLine[13]!="Duration"){Debug.Log("Buff.csv中字段[Duration]位置不对应"); return false; }
		if(vecLine[14]!="Interval"){Debug.Log("Buff.csv中字段[Interval]位置不对应"); return false; }
		if(vecLine[15]!="RestoreHealth"){Debug.Log("Buff.csv中字段[RestoreHealth]位置不对应"); return false; }
		if(vecLine[16]!="RestorePower"){Debug.Log("Buff.csv中字段[RestorePower]位置不对应"); return false; }
		if(vecLine[17]!="UseSkill"){Debug.Log("Buff.csv中字段[UseSkill]位置不对应"); return false; }
		if(vecLine[18]!="Speed"){Debug.Log("Buff.csv中字段[Speed]位置不对应"); return false; }
		if(vecLine[19]!="HitFrequency"){Debug.Log("Buff.csv中字段[HitFrequency]位置不对应"); return false; }
		if(vecLine[20]!="Attribute1Type"){Debug.Log("Buff.csv中字段[Attribute1Type]位置不对应"); return false; }
		if(vecLine[21]!="Attribute1Value"){Debug.Log("Buff.csv中字段[Attribute1Value]位置不对应"); return false; }
		if(vecLine[22]!="Attribute2Type"){Debug.Log("Buff.csv中字段[Attribute2Type]位置不对应"); return false; }
		if(vecLine[23]!="Attribute2Value"){Debug.Log("Buff.csv中字段[Attribute2Value]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)24)
			{
				return false;
			}
			BuffElement member = new BuffElement();
			member.BuffID=Convert.ToInt32(vecLine[0]);
			member.Name=vecLine[1];
			member.Describe=vecLine[2];
			member.IconShow=Convert.ToInt32(vecLine[3]);
			member.IconName=vecLine[4];
			member.DieEfficient=Convert.ToInt32(vecLine[5]);
			member.TriggerPos=vecLine[6];
			member.TriggerEffects=vecLine[7];
			member.SustainPos=vecLine[8];
			member.SustainEffects=vecLine[9];
			member.AblityID=vecLine[10];
			member.Type=Convert.ToInt32(vecLine[11]);
			member.ImmuneType=vecLine[12];
			member.Duration=Convert.ToInt32(vecLine[13]);
			member.Interval=Convert.ToInt32(vecLine[14]);
			member.RestoreHealth=Convert.ToInt32(vecLine[15]);
			member.RestorePower=Convert.ToInt32(vecLine[16]);
			member.UseSkill=Convert.ToInt32(vecLine[17]);
			member.Speed=Convert.ToInt32(vecLine[18]);
			member.HitFrequency=Convert.ToInt32(vecLine[19]);
			member.Attribute1Type=Convert.ToInt32(vecLine[20]);
			member.Attribute1Value=Convert.ToInt32(vecLine[21]);
			member.Attribute2Type=Convert.ToInt32(vecLine[22]);
			member.Attribute2Value=Convert.ToInt32(vecLine[23]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.BuffID] = member;
		}
		return true;
	}
};
