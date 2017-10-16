using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备升星等阶配置数据类
public class EquipStarRankElement
{
	public int StarRankID;       	//编号	等阶等级
	public int Rank;             	//阶层	等阶所需星阶
	public int Grade;            	//星级	等阶所需星级
	public int Pattack;          	//物理攻击	物理攻击
	public int Mattack;          	//法术攻击	法术攻击
	public int PDefense;         	//物理防御	物理防御
	public int MDefense;         	//法术防御	法术防御
	public int HP;               	//最大生命	最大生命

	public bool IsValidate = false;
	public EquipStarRankElement()
	{
		StarRankID = -1;
	}
};

//装备升星等阶配置封装类
public class EquipStarRankTable
{

	private EquipStarRankTable()
	{
		m_mapElements = new Dictionary<int, EquipStarRankElement>();
		m_emptyItem = new EquipStarRankElement();
		m_vecAllElements = new List<EquipStarRankElement>();
	}
	private Dictionary<int, EquipStarRankElement> m_mapElements = null;
	private List<EquipStarRankElement>	m_vecAllElements = null;
	private EquipStarRankElement m_emptyItem = null;
	private static EquipStarRankTable sInstance = null;

	public static EquipStarRankTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipStarRankTable();
			return sInstance;
		}
	}

	public EquipStarRankElement GetElement(int key)
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

  public List<EquipStarRankElement> GetAllElement(Predicate<EquipStarRankElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EquipStarRank.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EquipStarRank.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[EquipStarRank.bin]未找到");
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
		if(vecLine.Count != 8)
		{
			Debug.Log("EquipStarRank.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="StarRankID"){Debug.Log("EquipStarRank.csv中字段[StarRankID]位置不对应"); return false; }
		if(vecLine[1]!="Rank"){Debug.Log("EquipStarRank.csv中字段[Rank]位置不对应"); return false; }
		if(vecLine[2]!="Grade"){Debug.Log("EquipStarRank.csv中字段[Grade]位置不对应"); return false; }
		if(vecLine[3]!="Pattack"){Debug.Log("EquipStarRank.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[4]!="Mattack"){Debug.Log("EquipStarRank.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[5]!="PDefense"){Debug.Log("EquipStarRank.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[6]!="MDefense"){Debug.Log("EquipStarRank.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[7]!="HP"){Debug.Log("EquipStarRank.csv中字段[HP]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipStarRankElement member = new EquipStarRankElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.StarRankID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Rank );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Grade );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Pattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Mattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.PDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HP );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.StarRankID] = member;
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
		if(vecLine.Count != 8)
		{
			Debug.Log("EquipStarRank.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="StarRankID"){Debug.Log("EquipStarRank.csv中字段[StarRankID]位置不对应"); return false; }
		if(vecLine[1]!="Rank"){Debug.Log("EquipStarRank.csv中字段[Rank]位置不对应"); return false; }
		if(vecLine[2]!="Grade"){Debug.Log("EquipStarRank.csv中字段[Grade]位置不对应"); return false; }
		if(vecLine[3]!="Pattack"){Debug.Log("EquipStarRank.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[4]!="Mattack"){Debug.Log("EquipStarRank.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[5]!="PDefense"){Debug.Log("EquipStarRank.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[6]!="MDefense"){Debug.Log("EquipStarRank.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[7]!="HP"){Debug.Log("EquipStarRank.csv中字段[HP]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)8)
			{
				return false;
			}
			EquipStarRankElement member = new EquipStarRankElement();
			member.StarRankID=Convert.ToInt32(vecLine[0]);
			member.Rank=Convert.ToInt32(vecLine[1]);
			member.Grade=Convert.ToInt32(vecLine[2]);
			member.Pattack=Convert.ToInt32(vecLine[3]);
			member.Mattack=Convert.ToInt32(vecLine[4]);
			member.PDefense=Convert.ToInt32(vecLine[5]);
			member.MDefense=Convert.ToInt32(vecLine[6]);
			member.HP=Convert.ToInt32(vecLine[7]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.StarRankID] = member;
		}
		return true;
	}
};
