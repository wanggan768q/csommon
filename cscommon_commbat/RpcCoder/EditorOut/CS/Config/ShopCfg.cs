using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//商店配置数据类
public class ShopElement
{
	public int ID;               	//商店ID	商店ID
	public string Name;          	//名称	名称
	public string Time;          	//刷新时间	刷新时间
	public int Refresh;          	//刷新消耗	刷新消耗（钻石）
	public int RefreshPlus;      	//刷新递增	每次刷新递增

	public bool IsValidate = false;
	public ShopElement()
	{
		ID = -1;
	}
};

//商店配置封装类
public class ShopTable
{

	private ShopTable()
	{
		m_mapElements = new Dictionary<int, ShopElement>();
		m_emptyItem = new ShopElement();
		m_vecAllElements = new List<ShopElement>();
	}
	private Dictionary<int, ShopElement> m_mapElements = null;
	private List<ShopElement>	m_vecAllElements = null;
	private ShopElement m_emptyItem = null;
	private static ShopTable sInstance = null;

	public static ShopTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ShopTable();
			return sInstance;
		}
	}

	public ShopElement GetElement(int key)
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

  public List<ShopElement> GetAllElement(Predicate<ShopElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Shop.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Shop.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[Shop.bin]未找到");
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
		if(vecLine.Count != 5)
		{
			Debug.Log("Shop.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("Shop.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("Shop.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="Time"){Debug.Log("Shop.csv中字段[Time]位置不对应"); return false; }
		if(vecLine[3]!="Refresh"){Debug.Log("Shop.csv中字段[Refresh]位置不对应"); return false; }
		if(vecLine[4]!="RefreshPlus"){Debug.Log("Shop.csv中字段[RefreshPlus]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ShopElement member = new ShopElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.Time);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Refresh );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.RefreshPlus );

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
		if(vecLine.Count != 5)
		{
			Debug.Log("Shop.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("Shop.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("Shop.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="Time"){Debug.Log("Shop.csv中字段[Time]位置不对应"); return false; }
		if(vecLine[3]!="Refresh"){Debug.Log("Shop.csv中字段[Refresh]位置不对应"); return false; }
		if(vecLine[4]!="RefreshPlus"){Debug.Log("Shop.csv中字段[RefreshPlus]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)5)
			{
				return false;
			}
			ShopElement member = new ShopElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.Name=vecLine[1];
			member.Time=vecLine[2];
			member.Refresh=Convert.ToInt32(vecLine[3]);
			member.RefreshPlus=Convert.ToInt32(vecLine[4]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
