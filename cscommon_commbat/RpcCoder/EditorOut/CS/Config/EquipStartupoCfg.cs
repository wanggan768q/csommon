using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备升星突破配置数据类
public class EquipStartupoElement
{
	public int TupoID;           	//编号	突破ID
	public int Grade;            	//突破所需等级	突破所需等级
	public int Item;             	//强化突破消耗道具	强化突破消耗道具ID
	public int Num;              	//强化突破消耗道具数量	强化突破消耗道具数量
	public int Pattack;          	//物理攻击	物理攻击
	public int Mattack;          	//法术攻击	法术攻击
	public int PDefense;         	//物理防御	物理防御
	public int MDefense;         	//法术防御	法术防御
	public int HP;               	//最大生命	最大生命
	public int Baoji;            	//暴击等级	暴击等级
	public int Bisha;            	//必杀等级	必杀等级
	public int MP;               	//魔法上限	魔法上限
	public int MpHuifu;          	//魔法恢复	魔法恢复
	public int Renxing;          	//韧性等级	韧性等级
	public int Shouhu;           	//守护等级	守护等级
	public int HpHuifu;          	//生命恢复	生命恢复

	public bool IsValidate = false;
	public EquipStartupoElement()
	{
		TupoID = -1;
	}
};

//装备升星突破配置封装类
public class EquipStartupoTable
{

	private EquipStartupoTable()
	{
		m_mapElements = new Dictionary<int, EquipStartupoElement>();
		m_emptyItem = new EquipStartupoElement();
		m_vecAllElements = new List<EquipStartupoElement>();
	}
	private Dictionary<int, EquipStartupoElement> m_mapElements = null;
	private List<EquipStartupoElement>	m_vecAllElements = null;
	private EquipStartupoElement m_emptyItem = null;
	private static EquipStartupoTable sInstance = null;

	public static EquipStartupoTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipStartupoTable();
			return sInstance;
		}
	}

	public EquipStartupoElement GetElement(int key)
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

  public List<EquipStartupoElement> GetAllElement(Predicate<EquipStartupoElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EquipStartupo.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EquipStartupo.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[EquipStartupo.bin]未找到");
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
		if(vecLine.Count != 16)
		{
			Debug.Log("EquipStartupo.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="TupoID"){Debug.Log("EquipStartupo.csv中字段[TupoID]位置不对应"); return false; }
		if(vecLine[1]!="Grade"){Debug.Log("EquipStartupo.csv中字段[Grade]位置不对应"); return false; }
		if(vecLine[2]!="Item"){Debug.Log("EquipStartupo.csv中字段[Item]位置不对应"); return false; }
		if(vecLine[3]!="Num"){Debug.Log("EquipStartupo.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[4]!="Pattack"){Debug.Log("EquipStartupo.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[5]!="Mattack"){Debug.Log("EquipStartupo.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[6]!="PDefense"){Debug.Log("EquipStartupo.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[7]!="MDefense"){Debug.Log("EquipStartupo.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[8]!="HP"){Debug.Log("EquipStartupo.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[9]!="Baoji"){Debug.Log("EquipStartupo.csv中字段[Baoji]位置不对应"); return false; }
		if(vecLine[10]!="Bisha"){Debug.Log("EquipStartupo.csv中字段[Bisha]位置不对应"); return false; }
		if(vecLine[11]!="MP"){Debug.Log("EquipStartupo.csv中字段[MP]位置不对应"); return false; }
		if(vecLine[12]!="MpHuifu"){Debug.Log("EquipStartupo.csv中字段[MpHuifu]位置不对应"); return false; }
		if(vecLine[13]!="Renxing"){Debug.Log("EquipStartupo.csv中字段[Renxing]位置不对应"); return false; }
		if(vecLine[14]!="Shouhu"){Debug.Log("EquipStartupo.csv中字段[Shouhu]位置不对应"); return false; }
		if(vecLine[15]!="HpHuifu"){Debug.Log("EquipStartupo.csv中字段[HpHuifu]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipStartupoElement member = new EquipStartupoElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.TupoID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Grade );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Item );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Pattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Mattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.PDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HP );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Baoji );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Bisha );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MP );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MpHuifu );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Renxing );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Shouhu );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HpHuifu );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.TupoID] = member;
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
		if(vecLine.Count != 16)
		{
			Debug.Log("EquipStartupo.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="TupoID"){Debug.Log("EquipStartupo.csv中字段[TupoID]位置不对应"); return false; }
		if(vecLine[1]!="Grade"){Debug.Log("EquipStartupo.csv中字段[Grade]位置不对应"); return false; }
		if(vecLine[2]!="Item"){Debug.Log("EquipStartupo.csv中字段[Item]位置不对应"); return false; }
		if(vecLine[3]!="Num"){Debug.Log("EquipStartupo.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[4]!="Pattack"){Debug.Log("EquipStartupo.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[5]!="Mattack"){Debug.Log("EquipStartupo.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[6]!="PDefense"){Debug.Log("EquipStartupo.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[7]!="MDefense"){Debug.Log("EquipStartupo.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[8]!="HP"){Debug.Log("EquipStartupo.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[9]!="Baoji"){Debug.Log("EquipStartupo.csv中字段[Baoji]位置不对应"); return false; }
		if(vecLine[10]!="Bisha"){Debug.Log("EquipStartupo.csv中字段[Bisha]位置不对应"); return false; }
		if(vecLine[11]!="MP"){Debug.Log("EquipStartupo.csv中字段[MP]位置不对应"); return false; }
		if(vecLine[12]!="MpHuifu"){Debug.Log("EquipStartupo.csv中字段[MpHuifu]位置不对应"); return false; }
		if(vecLine[13]!="Renxing"){Debug.Log("EquipStartupo.csv中字段[Renxing]位置不对应"); return false; }
		if(vecLine[14]!="Shouhu"){Debug.Log("EquipStartupo.csv中字段[Shouhu]位置不对应"); return false; }
		if(vecLine[15]!="HpHuifu"){Debug.Log("EquipStartupo.csv中字段[HpHuifu]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)16)
			{
				return false;
			}
			EquipStartupoElement member = new EquipStartupoElement();
			member.TupoID=Convert.ToInt32(vecLine[0]);
			member.Grade=Convert.ToInt32(vecLine[1]);
			member.Item=Convert.ToInt32(vecLine[2]);
			member.Num=Convert.ToInt32(vecLine[3]);
			member.Pattack=Convert.ToInt32(vecLine[4]);
			member.Mattack=Convert.ToInt32(vecLine[5]);
			member.PDefense=Convert.ToInt32(vecLine[6]);
			member.MDefense=Convert.ToInt32(vecLine[7]);
			member.HP=Convert.ToInt32(vecLine[8]);
			member.Baoji=Convert.ToInt32(vecLine[9]);
			member.Bisha=Convert.ToInt32(vecLine[10]);
			member.MP=Convert.ToInt32(vecLine[11]);
			member.MpHuifu=Convert.ToInt32(vecLine[12]);
			member.Renxing=Convert.ToInt32(vecLine[13]);
			member.Shouhu=Convert.ToInt32(vecLine[14]);
			member.HpHuifu=Convert.ToInt32(vecLine[15]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.TupoID] = member;
		}
		return true;
	}
};
