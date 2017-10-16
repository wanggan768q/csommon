using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//碎片商店配置数据类
public class ShopSuipianElement
{
	public int ID;               	//商品编号	商品编号
	public int ItemID;           	//商品ID	商品ID
	public string Name;          	//名称	名称
	public string Res;           	//物品资源	物品资源
	public int Money;            	//货币类型	货币类型（6，觉醒碎片）
	public int Price;            	//单价	单价
	public int Set;              	//所属位置	所属位置

	public bool IsValidate = false;
	public ShopSuipianElement()
	{
		ID = -1;
	}
};

//碎片商店配置封装类
public class ShopSuipianTable
{

	private ShopSuipianTable()
	{
		m_mapElements = new Dictionary<int, ShopSuipianElement>();
		m_emptyItem = new ShopSuipianElement();
		m_vecAllElements = new List<ShopSuipianElement>();
	}
	private Dictionary<int, ShopSuipianElement> m_mapElements = null;
	private List<ShopSuipianElement>	m_vecAllElements = null;
	private ShopSuipianElement m_emptyItem = null;
	private static ShopSuipianTable sInstance = null;

	public static ShopSuipianTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ShopSuipianTable();
			return sInstance;
		}
	}

	public ShopSuipianElement GetElement(int key)
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

  public List<ShopSuipianElement> GetAllElement(Predicate<ShopSuipianElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ShopSuipian.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ShopSuipian.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[ShopSuipian.bin]未找到");
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
			Debug.Log("ShopSuipian.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("ShopSuipian.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="ItemID"){Debug.Log("ShopSuipian.csv中字段[ItemID]位置不对应"); return false; }
		if(vecLine[2]!="Name"){Debug.Log("ShopSuipian.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[3]!="Res"){Debug.Log("ShopSuipian.csv中字段[Res]位置不对应"); return false; }
		if(vecLine[4]!="Money"){Debug.Log("ShopSuipian.csv中字段[Money]位置不对应"); return false; }
		if(vecLine[5]!="Price"){Debug.Log("ShopSuipian.csv中字段[Price]位置不对应"); return false; }
		if(vecLine[6]!="Set"){Debug.Log("ShopSuipian.csv中字段[Set]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ShopSuipianElement member = new ShopSuipianElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ItemID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.Res);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Money );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Price );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Set );

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
		if(vecLine.Count != 7)
		{
			Debug.Log("ShopSuipian.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("ShopSuipian.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="ItemID"){Debug.Log("ShopSuipian.csv中字段[ItemID]位置不对应"); return false; }
		if(vecLine[2]!="Name"){Debug.Log("ShopSuipian.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[3]!="Res"){Debug.Log("ShopSuipian.csv中字段[Res]位置不对应"); return false; }
		if(vecLine[4]!="Money"){Debug.Log("ShopSuipian.csv中字段[Money]位置不对应"); return false; }
		if(vecLine[5]!="Price"){Debug.Log("ShopSuipian.csv中字段[Price]位置不对应"); return false; }
		if(vecLine[6]!="Set"){Debug.Log("ShopSuipian.csv中字段[Set]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			ShopSuipianElement member = new ShopSuipianElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.ItemID=Convert.ToInt32(vecLine[1]);
			member.Name=vecLine[2];
			member.Res=vecLine[3];
			member.Money=Convert.ToInt32(vecLine[4]);
			member.Price=Convert.ToInt32(vecLine[5]);
			member.Set=Convert.ToInt32(vecLine[6]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
