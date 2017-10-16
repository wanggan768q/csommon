using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备强化配置数据类
public class EquipStrengthenElement
{
	public int RankID;           	//编号	强化等级
	public int Num;              	//强化消耗道具数量	强化消耗道具数量
	public int Money;            	//强化消耗金币	强化消耗金币
	public int Chance;           	//强化成功概率	强化成功概率

	public bool IsValidate = false;
	public EquipStrengthenElement()
	{
		RankID = -1;
	}
};

//装备强化配置封装类
public class EquipStrengthenTable
{

	private EquipStrengthenTable()
	{
		m_mapElements = new Dictionary<int, EquipStrengthenElement>();
		m_emptyItem = new EquipStrengthenElement();
		m_vecAllElements = new List<EquipStrengthenElement>();
	}
	private Dictionary<int, EquipStrengthenElement> m_mapElements = null;
	private List<EquipStrengthenElement>	m_vecAllElements = null;
	private EquipStrengthenElement m_emptyItem = null;
	private static EquipStrengthenTable sInstance = null;

	public static EquipStrengthenTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipStrengthenTable();
			return sInstance;
		}
	}

	public EquipStrengthenElement GetElement(int key)
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

  public List<EquipStrengthenElement> GetAllElement(Predicate<EquipStrengthenElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EquipStrengthen.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EquipStrengthen.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[EquipStrengthen.bin]未找到");
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
		if(vecLine.Count != 4)
		{
			Debug.Log("EquipStrengthen.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="RankID"){Debug.Log("EquipStrengthen.csv中字段[RankID]位置不对应"); return false; }
		if(vecLine[1]!="Num"){Debug.Log("EquipStrengthen.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[2]!="Money"){Debug.Log("EquipStrengthen.csv中字段[Money]位置不对应"); return false; }
		if(vecLine[3]!="Chance"){Debug.Log("EquipStrengthen.csv中字段[Chance]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipStrengthenElement member = new EquipStrengthenElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.RankID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Money );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Chance );

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
		if(vecLine.Count != 4)
		{
			Debug.Log("EquipStrengthen.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="RankID"){Debug.Log("EquipStrengthen.csv中字段[RankID]位置不对应"); return false; }
		if(vecLine[1]!="Num"){Debug.Log("EquipStrengthen.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[2]!="Money"){Debug.Log("EquipStrengthen.csv中字段[Money]位置不对应"); return false; }
		if(vecLine[3]!="Chance"){Debug.Log("EquipStrengthen.csv中字段[Chance]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)4)
			{
				return false;
			}
			EquipStrengthenElement member = new EquipStrengthenElement();
			member.RankID=Convert.ToInt32(vecLine[0]);
			member.Num=Convert.ToInt32(vecLine[1]);
			member.Money=Convert.ToInt32(vecLine[2]);
			member.Chance=Convert.ToInt32(vecLine[3]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.RankID] = member;
		}
		return true;
	}
};
