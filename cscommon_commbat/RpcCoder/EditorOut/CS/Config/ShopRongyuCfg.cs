using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//荣誉商店配置数据类
public class ShopRongyuElement
{
	public int ID;               	//商品编号	商品编号
	public int ItemID;           	//商品ID	商品ID
	public string Name;          	//名称	名称
	public string Res;           	//物品资源	物品资源
	public int Money;            	//货币类型	货币类型（4，荣誉币）
	public int Price;            	//单价	单价
	public string Num;           	//刷新数量	刷新数量
	public int Set;              	//所属位置	所属位置
	public int Probability ;     	//刷新概率	刷新概率

	public bool IsValidate = false;
	public ShopRongyuElement()
	{
		ID = -1;
	}
};

//荣誉商店配置封装类
public class ShopRongyuTable
{

	private ShopRongyuTable()
	{
		m_mapElements = new Dictionary<int, ShopRongyuElement>();
		m_emptyItem = new ShopRongyuElement();
		m_vecAllElements = new List<ShopRongyuElement>();
	}
	private Dictionary<int, ShopRongyuElement> m_mapElements = null;
	private List<ShopRongyuElement>	m_vecAllElements = null;
	private ShopRongyuElement m_emptyItem = null;
	private static ShopRongyuTable sInstance = null;

	public static ShopRongyuTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ShopRongyuTable();
			return sInstance;
		}
	}

	public ShopRongyuElement GetElement(int key)
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

  public List<ShopRongyuElement> GetAllElement(Predicate<ShopRongyuElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ShopRongyu.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ShopRongyu.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[ShopRongyu.bin]未找到");
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
		if(vecLine.Count != 9)
		{
			Debug.Log("ShopRongyu.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("ShopRongyu.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="ItemID"){Debug.Log("ShopRongyu.csv中字段[ItemID]位置不对应"); return false; }
		if(vecLine[2]!="Name"){Debug.Log("ShopRongyu.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[3]!="Res"){Debug.Log("ShopRongyu.csv中字段[Res]位置不对应"); return false; }
		if(vecLine[4]!="Money"){Debug.Log("ShopRongyu.csv中字段[Money]位置不对应"); return false; }
		if(vecLine[5]!="Price"){Debug.Log("ShopRongyu.csv中字段[Price]位置不对应"); return false; }
		if(vecLine[6]!="Num"){Debug.Log("ShopRongyu.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[7]!="Set"){Debug.Log("ShopRongyu.csv中字段[Set]位置不对应"); return false; }
		if(vecLine[8]!="Probability "){Debug.Log("ShopRongyu.csv中字段[Probability ]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ShopRongyuElement member = new ShopRongyuElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ItemID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.Res);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Money );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Price );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Num);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Set );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Probability  );

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
		if(vecLine.Count != 9)
		{
			Debug.Log("ShopRongyu.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("ShopRongyu.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="ItemID"){Debug.Log("ShopRongyu.csv中字段[ItemID]位置不对应"); return false; }
		if(vecLine[2]!="Name"){Debug.Log("ShopRongyu.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[3]!="Res"){Debug.Log("ShopRongyu.csv中字段[Res]位置不对应"); return false; }
		if(vecLine[4]!="Money"){Debug.Log("ShopRongyu.csv中字段[Money]位置不对应"); return false; }
		if(vecLine[5]!="Price"){Debug.Log("ShopRongyu.csv中字段[Price]位置不对应"); return false; }
		if(vecLine[6]!="Num"){Debug.Log("ShopRongyu.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[7]!="Set"){Debug.Log("ShopRongyu.csv中字段[Set]位置不对应"); return false; }
		if(vecLine[8]!="Probability "){Debug.Log("ShopRongyu.csv中字段[Probability ]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)9)
			{
				return false;
			}
			ShopRongyuElement member = new ShopRongyuElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.ItemID=Convert.ToInt32(vecLine[1]);
			member.Name=vecLine[2];
			member.Res=vecLine[3];
			member.Money=Convert.ToInt32(vecLine[4]);
			member.Price=Convert.ToInt32(vecLine[5]);
			member.Num=vecLine[6];
			member.Set=Convert.ToInt32(vecLine[7]);
			member.Probability =Convert.ToInt32(vecLine[8]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
