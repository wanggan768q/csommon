using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宝石配置数据类
public class BaoShiElement
{
	public int ID;               	//编号	宝石ID
	public string Name;          	//宝石名称	宝石名称
	public string SourceID;      	//宝石的资源	宝石的资源
	public int Type;             	//宝石类别	宝石类别
	public int Lv;               	//宝石等级	宝石等级
	public int Set;              	//镶嵌槽位	镶嵌槽位
	public string Attr;          	//属性类别	属性类别
	public string Num;           	//属性参数	属性参数
	public int HeCheng;          	//合成后的宝石	合成后的宝石

	public bool IsValidate = false;
	public BaoShiElement()
	{
		ID = -1;
	}
};

//宝石配置封装类
public class BaoShiTable
{

	private BaoShiTable()
	{
		m_mapElements = new Dictionary<int, BaoShiElement>();
		m_emptyItem = new BaoShiElement();
		m_vecAllElements = new List<BaoShiElement>();
	}
	private Dictionary<int, BaoShiElement> m_mapElements = null;
	private List<BaoShiElement>	m_vecAllElements = null;
	private BaoShiElement m_emptyItem = null;
	private static BaoShiTable sInstance = null;

	public static BaoShiTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new BaoShiTable();
			return sInstance;
		}
	}

	public BaoShiElement GetElement(int key)
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

  public List<BaoShiElement> GetAllElement(Predicate<BaoShiElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("BaoShi.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("BaoShi.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[BaoShi.bin]未找到");
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
			Debug.Log("BaoShi.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("BaoShi.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("BaoShi.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="SourceID"){Debug.Log("BaoShi.csv中字段[SourceID]位置不对应"); return false; }
		if(vecLine[3]!="Type"){Debug.Log("BaoShi.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[4]!="Lv"){Debug.Log("BaoShi.csv中字段[Lv]位置不对应"); return false; }
		if(vecLine[5]!="Set"){Debug.Log("BaoShi.csv中字段[Set]位置不对应"); return false; }
		if(vecLine[6]!="Attr"){Debug.Log("BaoShi.csv中字段[Attr]位置不对应"); return false; }
		if(vecLine[7]!="Num"){Debug.Log("BaoShi.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[8]!="HeCheng"){Debug.Log("BaoShi.csv中字段[HeCheng]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BaoShiElement member = new BaoShiElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.SourceID);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Lv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Set );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Attr);
			readPos += GameAssist.ReadString( binContent, readPos, out member.Num);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HeCheng );

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
			Debug.Log("BaoShi.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("BaoShi.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("BaoShi.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="SourceID"){Debug.Log("BaoShi.csv中字段[SourceID]位置不对应"); return false; }
		if(vecLine[3]!="Type"){Debug.Log("BaoShi.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[4]!="Lv"){Debug.Log("BaoShi.csv中字段[Lv]位置不对应"); return false; }
		if(vecLine[5]!="Set"){Debug.Log("BaoShi.csv中字段[Set]位置不对应"); return false; }
		if(vecLine[6]!="Attr"){Debug.Log("BaoShi.csv中字段[Attr]位置不对应"); return false; }
		if(vecLine[7]!="Num"){Debug.Log("BaoShi.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[8]!="HeCheng"){Debug.Log("BaoShi.csv中字段[HeCheng]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)9)
			{
				return false;
			}
			BaoShiElement member = new BaoShiElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.Name=vecLine[1];
			member.SourceID=vecLine[2];
			member.Type=Convert.ToInt32(vecLine[3]);
			member.Lv=Convert.ToInt32(vecLine[4]);
			member.Set=Convert.ToInt32(vecLine[5]);
			member.Attr=vecLine[6];
			member.Num=vecLine[7];
			member.HeCheng=Convert.ToInt32(vecLine[8]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
