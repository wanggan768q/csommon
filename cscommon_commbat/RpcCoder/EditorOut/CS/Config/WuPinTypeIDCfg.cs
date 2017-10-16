using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//物品类型配置数据类
public class WuPinTypeIDElement
{
	public int ID;               	//编号	编号
	public int ZiDuan;           	//类型分段	类型分段
	public string Type;          	//物品类型	物品类型

	public bool IsValidate = false;
	public WuPinTypeIDElement()
	{
		ID = -1;
	}
};

//物品类型配置封装类
public class WuPinTypeIDTable
{

	private WuPinTypeIDTable()
	{
		m_mapElements = new Dictionary<int, WuPinTypeIDElement>();
		m_emptyItem = new WuPinTypeIDElement();
		m_vecAllElements = new List<WuPinTypeIDElement>();
	}
	private Dictionary<int, WuPinTypeIDElement> m_mapElements = null;
	private List<WuPinTypeIDElement>	m_vecAllElements = null;
	private WuPinTypeIDElement m_emptyItem = null;
	private static WuPinTypeIDTable sInstance = null;

	public static WuPinTypeIDTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new WuPinTypeIDTable();
			return sInstance;
		}
	}

	public WuPinTypeIDElement GetElement(int key)
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

  public List<WuPinTypeIDElement> GetAllElement(Predicate<WuPinTypeIDElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("WuPinTypeID.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("WuPinTypeID.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[WuPinTypeID.bin]未找到");
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
		if(vecLine.Count != 3)
		{
			Debug.Log("WuPinTypeID.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("WuPinTypeID.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="ZiDuan"){Debug.Log("WuPinTypeID.csv中字段[ZiDuan]位置不对应"); return false; }
		if(vecLine[2]!="Type"){Debug.Log("WuPinTypeID.csv中字段[Type]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			WuPinTypeIDElement member = new WuPinTypeIDElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ZiDuan );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Type);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
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
		if(vecLine.Count != 3)
		{
			Debug.Log("WuPinTypeID.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("WuPinTypeID.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="ZiDuan"){Debug.Log("WuPinTypeID.csv中字段[ZiDuan]位置不对应"); return false; }
		if(vecLine[2]!="Type"){Debug.Log("WuPinTypeID.csv中字段[Type]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)3)
			{
				return false;
			}
			WuPinTypeIDElement member = new WuPinTypeIDElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.ZiDuan=Convert.ToInt32(vecLine[1]);
			member.Type=vecLine[2];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
