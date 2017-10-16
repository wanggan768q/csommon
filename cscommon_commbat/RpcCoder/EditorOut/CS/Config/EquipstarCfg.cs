using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备升星配置数据类
public class EquipstarElement
{
	public int StarRankID;       	//编号	星级
	public int Num;              	//升星消耗道具数量	升星消耗道具数量
	public int Money;            	//消耗金钱	消耗金钱
	public int Chance;           	//升星概率	升星成功概率

	public bool IsValidate = false;
	public EquipstarElement()
	{
		StarRankID = -1;
	}
};

//装备升星配置封装类
public class EquipstarTable
{

	private EquipstarTable()
	{
		m_mapElements = new Dictionary<int, EquipstarElement>();
		m_emptyItem = new EquipstarElement();
		m_vecAllElements = new List<EquipstarElement>();
	}
	private Dictionary<int, EquipstarElement> m_mapElements = null;
	private List<EquipstarElement>	m_vecAllElements = null;
	private EquipstarElement m_emptyItem = null;
	private static EquipstarTable sInstance = null;

	public static EquipstarTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipstarTable();
			return sInstance;
		}
	}

	public EquipstarElement GetElement(int key)
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

  public List<EquipstarElement> GetAllElement(Predicate<EquipstarElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Equipstar.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Equipstar.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[Equipstar.bin]未找到");
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
			Debug.Log("Equipstar.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="StarRankID"){Debug.Log("Equipstar.csv中字段[StarRankID]位置不对应"); return false; }
		if(vecLine[1]!="Num"){Debug.Log("Equipstar.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[2]!="Money"){Debug.Log("Equipstar.csv中字段[Money]位置不对应"); return false; }
		if(vecLine[3]!="Chance"){Debug.Log("Equipstar.csv中字段[Chance]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipstarElement member = new EquipstarElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.StarRankID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Money );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Chance );

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
		if(vecLine.Count != 4)
		{
			Debug.Log("Equipstar.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="StarRankID"){Debug.Log("Equipstar.csv中字段[StarRankID]位置不对应"); return false; }
		if(vecLine[1]!="Num"){Debug.Log("Equipstar.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[2]!="Money"){Debug.Log("Equipstar.csv中字段[Money]位置不对应"); return false; }
		if(vecLine[3]!="Chance"){Debug.Log("Equipstar.csv中字段[Chance]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)4)
			{
				return false;
			}
			EquipstarElement member = new EquipstarElement();
			member.StarRankID=Convert.ToInt32(vecLine[0]);
			member.Num=Convert.ToInt32(vecLine[1]);
			member.Money=Convert.ToInt32(vecLine[2]);
			member.Chance=Convert.ToInt32(vecLine[3]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.StarRankID] = member;
		}
		return true;
	}
};
