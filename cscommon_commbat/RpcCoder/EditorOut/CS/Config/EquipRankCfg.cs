using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备强化等阶配置数据类
public class EquipRankElement
{
	public int RankID;           	//编号	等阶等级
	public int Grade;            	//等级	等阶所需强化等级
	public int Pattack;          	//物理攻击	物理攻击
	public int Mattack;          	//法术攻击	法术攻击
	public int PDefense;         	//物理防御	物理防御
	public int MDefense;         	//法术防御	法术防御
	public int HP;               	//最大生命	最大生命

	public bool IsValidate = false;
	public EquipRankElement()
	{
		RankID = -1;
	}
};

//装备强化等阶配置封装类
public class EquipRankTable
{

	private EquipRankTable()
	{
		m_mapElements = new Dictionary<int, EquipRankElement>();
		m_emptyItem = new EquipRankElement();
		m_vecAllElements = new List<EquipRankElement>();
	}
	private Dictionary<int, EquipRankElement> m_mapElements = null;
	private List<EquipRankElement>	m_vecAllElements = null;
	private EquipRankElement m_emptyItem = null;
	private static EquipRankTable sInstance = null;

	public static EquipRankTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipRankTable();
			return sInstance;
		}
	}

	public EquipRankElement GetElement(int key)
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

  public List<EquipRankElement> GetAllElement(Predicate<EquipRankElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EquipRank.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EquipRank.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[EquipRank.bin]未找到");
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
		if(vecLine.Count != 7)
		{
			Debug.Log("EquipRank.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="RankID"){Debug.Log("EquipRank.csv中字段[RankID]位置不对应"); return false; }
		if(vecLine[1]!="Grade"){Debug.Log("EquipRank.csv中字段[Grade]位置不对应"); return false; }
		if(vecLine[2]!="Pattack"){Debug.Log("EquipRank.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[3]!="Mattack"){Debug.Log("EquipRank.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[4]!="PDefense"){Debug.Log("EquipRank.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[5]!="MDefense"){Debug.Log("EquipRank.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[6]!="HP"){Debug.Log("EquipRank.csv中字段[HP]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipRankElement member = new EquipRankElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.RankID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Grade );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Pattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Mattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.PDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HP );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.RankID] = member;
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
		if(vecLine.Count != 7)
		{
			Debug.Log("EquipRank.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="RankID"){Debug.Log("EquipRank.csv中字段[RankID]位置不对应"); return false; }
		if(vecLine[1]!="Grade"){Debug.Log("EquipRank.csv中字段[Grade]位置不对应"); return false; }
		if(vecLine[2]!="Pattack"){Debug.Log("EquipRank.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[3]!="Mattack"){Debug.Log("EquipRank.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[4]!="PDefense"){Debug.Log("EquipRank.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[5]!="MDefense"){Debug.Log("EquipRank.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[6]!="HP"){Debug.Log("EquipRank.csv中字段[HP]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			EquipRankElement member = new EquipRankElement();
			member.RankID=Convert.ToInt32(vecLine[0]);
			member.Grade=Convert.ToInt32(vecLine[1]);
			member.Pattack=Convert.ToInt32(vecLine[2]);
			member.Mattack=Convert.ToInt32(vecLine[3]);
			member.PDefense=Convert.ToInt32(vecLine[4]);
			member.MDefense=Convert.ToInt32(vecLine[5]);
			member.HP=Convert.ToInt32(vecLine[6]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.RankID] = member;
		}
		return true;
	}
};
