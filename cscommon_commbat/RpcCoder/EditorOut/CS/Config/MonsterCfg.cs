using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//怪物基本表配置数据类
public class MonsterElement
{
	public int MonsterID;        	//NpcID	编号
	public string ModelID;       	//模型ID	索引模型
	public float ModelScaling;   	//模型缩放	模型缩放比例，包含模型的所有东西进行缩放
	public string Name;          	//NPC名称	NPC名称
	public string Title;         	//NPC称号	NPC称号
	public int Level;            	//等级	NPC的等级
	public int BaseAI;           	//AIID	索引基础AIID
	public int Skill1;           	//普攻1	普攻1
	public int Skill2;           	//普攻2	普攻2
	public int Skill3;           	//普攻3	普攻3
	public int Skill4;           	//普攻4	普攻4
	public int Skill5;           	//技能1	技能1
	public int Skill6;           	//技能2	技能2
	public int Skill7;           	//技能3	技能3
	public int Skill8;           	//技能4	技能4
	public int Skill9;           	//技能5	技能5
	public int MaxHP;            	//最大生命	生命值
	public int PhysicalAtk;      	//物理攻击	物理攻击力
	public int MagicalAtk;       	//法术攻击	法术攻击力
	public int PhysicalDef;      	//物理防御	物理防御力，根据公式计算减伤比例
	public int MagicalDef;       	//法术防御	法术防御力，根据公式计算减伤比例
	public int CritLevel;        	//暴击等级	攻击时触发暴击的几率，根据公式计算暴击的几率
	public int CritDef;          	//韧性等级	减少被暴击的几率
	public int CritDamage;       	//必杀等级	暴击伤害
	public int CritReduce;       	//守护等级	降低受到敌人的暴击伤害
	public int Regain;           	//生命恢复	待机生命恢复量
	public float MoveSpeed;      	//移动速度	移动的速度
	public float AttackRate;     	//攻击速度	普通攻击的速度

	public bool IsValidate = false;
	public MonsterElement()
	{
		MonsterID = -1;
	}
};

//怪物基本表配置封装类
public class MonsterTable
{

	private MonsterTable()
	{
		m_mapElements = new Dictionary<int, MonsterElement>();
		m_emptyItem = new MonsterElement();
		m_vecAllElements = new List<MonsterElement>();
	}
	private Dictionary<int, MonsterElement> m_mapElements = null;
	private List<MonsterElement>	m_vecAllElements = null;
	private MonsterElement m_emptyItem = null;
	private static MonsterTable sInstance = null;

	public static MonsterTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new MonsterTable();
			return sInstance;
		}
	}

	public MonsterElement GetElement(int key)
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

  public List<MonsterElement> GetAllElement(Predicate<MonsterElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Monster.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Monster.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[Monster.bin]未找到");
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
		if(vecLine.Count != 28)
		{
			Debug.Log("Monster.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="MonsterID"){Debug.Log("Monster.csv中字段[MonsterID]位置不对应"); return false; }
		if(vecLine[1]!="ModelID"){Debug.Log("Monster.csv中字段[ModelID]位置不对应"); return false; }
		if(vecLine[2]!="ModelScaling"){Debug.Log("Monster.csv中字段[ModelScaling]位置不对应"); return false; }
		if(vecLine[3]!="Name"){Debug.Log("Monster.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[4]!="Title"){Debug.Log("Monster.csv中字段[Title]位置不对应"); return false; }
		if(vecLine[5]!="Level"){Debug.Log("Monster.csv中字段[Level]位置不对应"); return false; }
		if(vecLine[6]!="BaseAI"){Debug.Log("Monster.csv中字段[BaseAI]位置不对应"); return false; }
		if(vecLine[7]!="Skill1"){Debug.Log("Monster.csv中字段[Skill1]位置不对应"); return false; }
		if(vecLine[8]!="Skill2"){Debug.Log("Monster.csv中字段[Skill2]位置不对应"); return false; }
		if(vecLine[9]!="Skill3"){Debug.Log("Monster.csv中字段[Skill3]位置不对应"); return false; }
		if(vecLine[10]!="Skill4"){Debug.Log("Monster.csv中字段[Skill4]位置不对应"); return false; }
		if(vecLine[11]!="Skill5"){Debug.Log("Monster.csv中字段[Skill5]位置不对应"); return false; }
		if(vecLine[12]!="Skill6"){Debug.Log("Monster.csv中字段[Skill6]位置不对应"); return false; }
		if(vecLine[13]!="Skill7"){Debug.Log("Monster.csv中字段[Skill7]位置不对应"); return false; }
		if(vecLine[14]!="Skill8"){Debug.Log("Monster.csv中字段[Skill8]位置不对应"); return false; }
		if(vecLine[15]!="Skill9"){Debug.Log("Monster.csv中字段[Skill9]位置不对应"); return false; }
		if(vecLine[16]!="MaxHP"){Debug.Log("Monster.csv中字段[MaxHP]位置不对应"); return false; }
		if(vecLine[17]!="PhysicalAtk"){Debug.Log("Monster.csv中字段[PhysicalAtk]位置不对应"); return false; }
		if(vecLine[18]!="MagicalAtk"){Debug.Log("Monster.csv中字段[MagicalAtk]位置不对应"); return false; }
		if(vecLine[19]!="PhysicalDef"){Debug.Log("Monster.csv中字段[PhysicalDef]位置不对应"); return false; }
		if(vecLine[20]!="MagicalDef"){Debug.Log("Monster.csv中字段[MagicalDef]位置不对应"); return false; }
		if(vecLine[21]!="CritLevel"){Debug.Log("Monster.csv中字段[CritLevel]位置不对应"); return false; }
		if(vecLine[22]!="CritDef"){Debug.Log("Monster.csv中字段[CritDef]位置不对应"); return false; }
		if(vecLine[23]!="CritDamage"){Debug.Log("Monster.csv中字段[CritDamage]位置不对应"); return false; }
		if(vecLine[24]!="CritReduce"){Debug.Log("Monster.csv中字段[CritReduce]位置不对应"); return false; }
		if(vecLine[25]!="Regain"){Debug.Log("Monster.csv中字段[Regain]位置不对应"); return false; }
		if(vecLine[26]!="MoveSpeed"){Debug.Log("Monster.csv中字段[MoveSpeed]位置不对应"); return false; }
		if(vecLine[27]!="AttackRate"){Debug.Log("Monster.csv中字段[AttackRate]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			MonsterElement member = new MonsterElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MonsterID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.ModelID);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.ModelScaling);
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.Title);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.BaseAI );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill5 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill6 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill7 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill8 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill9 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MaxHP );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.PhysicalAtk );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MagicalAtk );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.PhysicalDef );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MagicalDef );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CritLevel );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CritDef );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CritDamage );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CritReduce );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Regain );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.MoveSpeed);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.AttackRate);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.MonsterID] = member;
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
		if(vecLine.Count != 28)
		{
			Debug.Log("Monster.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="MonsterID"){Debug.Log("Monster.csv中字段[MonsterID]位置不对应"); return false; }
		if(vecLine[1]!="ModelID"){Debug.Log("Monster.csv中字段[ModelID]位置不对应"); return false; }
		if(vecLine[2]!="ModelScaling"){Debug.Log("Monster.csv中字段[ModelScaling]位置不对应"); return false; }
		if(vecLine[3]!="Name"){Debug.Log("Monster.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[4]!="Title"){Debug.Log("Monster.csv中字段[Title]位置不对应"); return false; }
		if(vecLine[5]!="Level"){Debug.Log("Monster.csv中字段[Level]位置不对应"); return false; }
		if(vecLine[6]!="BaseAI"){Debug.Log("Monster.csv中字段[BaseAI]位置不对应"); return false; }
		if(vecLine[7]!="Skill1"){Debug.Log("Monster.csv中字段[Skill1]位置不对应"); return false; }
		if(vecLine[8]!="Skill2"){Debug.Log("Monster.csv中字段[Skill2]位置不对应"); return false; }
		if(vecLine[9]!="Skill3"){Debug.Log("Monster.csv中字段[Skill3]位置不对应"); return false; }
		if(vecLine[10]!="Skill4"){Debug.Log("Monster.csv中字段[Skill4]位置不对应"); return false; }
		if(vecLine[11]!="Skill5"){Debug.Log("Monster.csv中字段[Skill5]位置不对应"); return false; }
		if(vecLine[12]!="Skill6"){Debug.Log("Monster.csv中字段[Skill6]位置不对应"); return false; }
		if(vecLine[13]!="Skill7"){Debug.Log("Monster.csv中字段[Skill7]位置不对应"); return false; }
		if(vecLine[14]!="Skill8"){Debug.Log("Monster.csv中字段[Skill8]位置不对应"); return false; }
		if(vecLine[15]!="Skill9"){Debug.Log("Monster.csv中字段[Skill9]位置不对应"); return false; }
		if(vecLine[16]!="MaxHP"){Debug.Log("Monster.csv中字段[MaxHP]位置不对应"); return false; }
		if(vecLine[17]!="PhysicalAtk"){Debug.Log("Monster.csv中字段[PhysicalAtk]位置不对应"); return false; }
		if(vecLine[18]!="MagicalAtk"){Debug.Log("Monster.csv中字段[MagicalAtk]位置不对应"); return false; }
		if(vecLine[19]!="PhysicalDef"){Debug.Log("Monster.csv中字段[PhysicalDef]位置不对应"); return false; }
		if(vecLine[20]!="MagicalDef"){Debug.Log("Monster.csv中字段[MagicalDef]位置不对应"); return false; }
		if(vecLine[21]!="CritLevel"){Debug.Log("Monster.csv中字段[CritLevel]位置不对应"); return false; }
		if(vecLine[22]!="CritDef"){Debug.Log("Monster.csv中字段[CritDef]位置不对应"); return false; }
		if(vecLine[23]!="CritDamage"){Debug.Log("Monster.csv中字段[CritDamage]位置不对应"); return false; }
		if(vecLine[24]!="CritReduce"){Debug.Log("Monster.csv中字段[CritReduce]位置不对应"); return false; }
		if(vecLine[25]!="Regain"){Debug.Log("Monster.csv中字段[Regain]位置不对应"); return false; }
		if(vecLine[26]!="MoveSpeed"){Debug.Log("Monster.csv中字段[MoveSpeed]位置不对应"); return false; }
		if(vecLine[27]!="AttackRate"){Debug.Log("Monster.csv中字段[AttackRate]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)28)
			{
				return false;
			}
			MonsterElement member = new MonsterElement();
			member.MonsterID=Convert.ToInt32(vecLine[0]);
			member.ModelID=vecLine[1];
			member.ModelScaling=Convert.ToSingle(vecLine[2]);
			member.Name=vecLine[3];
			member.Title=vecLine[4];
			member.Level=Convert.ToInt32(vecLine[5]);
			member.BaseAI=Convert.ToInt32(vecLine[6]);
			member.Skill1=Convert.ToInt32(vecLine[7]);
			member.Skill2=Convert.ToInt32(vecLine[8]);
			member.Skill3=Convert.ToInt32(vecLine[9]);
			member.Skill4=Convert.ToInt32(vecLine[10]);
			member.Skill5=Convert.ToInt32(vecLine[11]);
			member.Skill6=Convert.ToInt32(vecLine[12]);
			member.Skill7=Convert.ToInt32(vecLine[13]);
			member.Skill8=Convert.ToInt32(vecLine[14]);
			member.Skill9=Convert.ToInt32(vecLine[15]);
			member.MaxHP=Convert.ToInt32(vecLine[16]);
			member.PhysicalAtk=Convert.ToInt32(vecLine[17]);
			member.MagicalAtk=Convert.ToInt32(vecLine[18]);
			member.PhysicalDef=Convert.ToInt32(vecLine[19]);
			member.MagicalDef=Convert.ToInt32(vecLine[20]);
			member.CritLevel=Convert.ToInt32(vecLine[21]);
			member.CritDef=Convert.ToInt32(vecLine[22]);
			member.CritDamage=Convert.ToInt32(vecLine[23]);
			member.CritReduce=Convert.ToInt32(vecLine[24]);
			member.Regain=Convert.ToInt32(vecLine[25]);
			member.MoveSpeed=Convert.ToSingle(vecLine[26]);
			member.AttackRate=Convert.ToSingle(vecLine[27]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.MonsterID] = member;
		}
		return true;
	}
};
