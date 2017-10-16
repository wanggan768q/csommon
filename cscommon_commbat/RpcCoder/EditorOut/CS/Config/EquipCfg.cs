using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备配置数据类
public class EquipElement
{
	public int EquipID;          	//编号	装备ID
	public int Type;             	//类型	装备类型（1武器2胸甲3头盔4戒指5玉佩6腰带7护腿8鞋子）
	public string Attribute;     	//属性	对应属性
	public int Colour;           	//初始品质	初始品质

	public bool IsValidate = false;
	public EquipElement()
	{
		EquipID = -1;
	}
};

//装备配置封装类
public class EquipTable
{

	private EquipTable()
	{
		m_mapElements = new Dictionary<int, EquipElement>();
		m_emptyItem = new EquipElement();
		m_vecAllElements = new List<EquipElement>();
	}
	private Dictionary<int, EquipElement> m_mapElements = null;
	private List<EquipElement>	m_vecAllElements = null;
	private EquipElement m_emptyItem = null;
	private static EquipTable sInstance = null;

	public static EquipTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipTable();
			return sInstance;
		}
	}

	public EquipElement GetElement(int key)
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

  public List<EquipElement> GetAllElement(Predicate<EquipElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Equip.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Equip.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[Equip.bin]未找到");
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
			Debug.Log("Equip.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="EquipID"){Debug.Log("Equip.csv中字段[EquipID]位置不对应"); return false; }
		if(vecLine[1]!="Type"){Debug.Log("Equip.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[2]!="Attribute"){Debug.Log("Equip.csv中字段[Attribute]位置不对应"); return false; }
		if(vecLine[3]!="Colour"){Debug.Log("Equip.csv中字段[Colour]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipElement member = new EquipElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.EquipID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Attribute);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Colour );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.EquipID] = member;
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
			Debug.Log("Equip.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="EquipID"){Debug.Log("Equip.csv中字段[EquipID]位置不对应"); return false; }
		if(vecLine[1]!="Type"){Debug.Log("Equip.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[2]!="Attribute"){Debug.Log("Equip.csv中字段[Attribute]位置不对应"); return false; }
		if(vecLine[3]!="Colour"){Debug.Log("Equip.csv中字段[Colour]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)4)
			{
				return false;
			}
			EquipElement member = new EquipElement();
			member.EquipID=Convert.ToInt32(vecLine[0]);
			member.Type=Convert.ToInt32(vecLine[1]);
			member.Attribute=vecLine[2];
			member.Colour=Convert.ToInt32(vecLine[3]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.EquipID] = member;
		}
		return true;
	}
};
