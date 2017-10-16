using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宝石阵配置数据类
public class BaoShiZhenElement
{
	public int JBID;             	//编号	宝石阵ID
	public string Name;          	//宝石阵名称	宝石阵名称
	public string Cond;          	//解锁参数	解锁参数
	public int Type;             	//宝石阵类型	宝石阵类型
	public int Lv;               	//宝石阵等级	宝石阵等级
	public int Attr;             	//属性	增加属性类型（1物理攻击百分比2法术攻击百分比3最大生命百分比4物理防御百分比5法术防御百分比6暴击率7必杀伤害8伤害减免）
	public int Num;              	//属性数值	属性数值

	public bool IsValidate = false;
	public BaoShiZhenElement()
	{
		JBID = -1;
	}
};

//宝石阵配置封装类
public class BaoShiZhenTable
{

	private BaoShiZhenTable()
	{
		m_mapElements = new Dictionary<int, BaoShiZhenElement>();
		m_emptyItem = new BaoShiZhenElement();
		m_vecAllElements = new List<BaoShiZhenElement>();
	}
	private Dictionary<int, BaoShiZhenElement> m_mapElements = null;
	private List<BaoShiZhenElement>	m_vecAllElements = null;
	private BaoShiZhenElement m_emptyItem = null;
	private static BaoShiZhenTable sInstance = null;

	public static BaoShiZhenTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new BaoShiZhenTable();
			return sInstance;
		}
	}

	public BaoShiZhenElement GetElement(int key)
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

  public List<BaoShiZhenElement> GetAllElement(Predicate<BaoShiZhenElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("BaoShiZhen.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("BaoShiZhen.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[BaoShiZhen.bin]未找到");
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
			Debug.Log("BaoShiZhen.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="JBID"){Debug.Log("BaoShiZhen.csv中字段[JBID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("BaoShiZhen.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="Cond"){Debug.Log("BaoShiZhen.csv中字段[Cond]位置不对应"); return false; }
		if(vecLine[3]!="Type"){Debug.Log("BaoShiZhen.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[4]!="Lv"){Debug.Log("BaoShiZhen.csv中字段[Lv]位置不对应"); return false; }
		if(vecLine[5]!="Attr"){Debug.Log("BaoShiZhen.csv中字段[Attr]位置不对应"); return false; }
		if(vecLine[6]!="Num"){Debug.Log("BaoShiZhen.csv中字段[Num]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BaoShiZhenElement member = new BaoShiZhenElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.JBID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.Cond);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Lv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Attr );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.JBID] = member;
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
			Debug.Log("BaoShiZhen.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="JBID"){Debug.Log("BaoShiZhen.csv中字段[JBID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("BaoShiZhen.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="Cond"){Debug.Log("BaoShiZhen.csv中字段[Cond]位置不对应"); return false; }
		if(vecLine[3]!="Type"){Debug.Log("BaoShiZhen.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[4]!="Lv"){Debug.Log("BaoShiZhen.csv中字段[Lv]位置不对应"); return false; }
		if(vecLine[5]!="Attr"){Debug.Log("BaoShiZhen.csv中字段[Attr]位置不对应"); return false; }
		if(vecLine[6]!="Num"){Debug.Log("BaoShiZhen.csv中字段[Num]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			BaoShiZhenElement member = new BaoShiZhenElement();
			member.JBID=Convert.ToInt32(vecLine[0]);
			member.Name=vecLine[1];
			member.Cond=vecLine[2];
			member.Type=Convert.ToInt32(vecLine[3]);
			member.Lv=Convert.ToInt32(vecLine[4]);
			member.Attr=Convert.ToInt32(vecLine[5]);
			member.Num=Convert.ToInt32(vecLine[6]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.JBID] = member;
		}
		return true;
	}
};
