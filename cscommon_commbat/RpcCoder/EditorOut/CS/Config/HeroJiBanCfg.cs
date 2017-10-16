using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//英雄羁绊配置数据类
public class HeroJiBanElement
{
	public int JBID;             	//编号	羁绊ID
	public string Name;          	//羁绊名称	羁绊名称
	public int Hero;             	//所属英雄	Rank的资源id
	public string Des;           	//描述	描述
	public int Type;             	//羁绊类别	羁绊类别（1英雄羁绊2神器羁绊）
	public string Cond;          	//解锁参数	解锁参数
	public int Attr;             	//属性	增加属性类型（1物理攻击百分比2法术攻击百分比3最大生命百分比4物理防御百分比5法术防御百分比6暴击率7必杀伤害8伤害减免）
	public float Num;            	//增加属性百分比	增加属性百分比

	public bool IsValidate = false;
	public HeroJiBanElement()
	{
		JBID = -1;
	}
};

//英雄羁绊配置封装类
public class HeroJiBanTable
{

	private HeroJiBanTable()
	{
		m_mapElements = new Dictionary<int, HeroJiBanElement>();
		m_emptyItem = new HeroJiBanElement();
		m_vecAllElements = new List<HeroJiBanElement>();
	}
	private Dictionary<int, HeroJiBanElement> m_mapElements = null;
	private List<HeroJiBanElement>	m_vecAllElements = null;
	private HeroJiBanElement m_emptyItem = null;
	private static HeroJiBanTable sInstance = null;

	public static HeroJiBanTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new HeroJiBanTable();
			return sInstance;
		}
	}

	public HeroJiBanElement GetElement(int key)
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

  public List<HeroJiBanElement> GetAllElement(Predicate<HeroJiBanElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("HeroJiBan.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("HeroJiBan.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[HeroJiBan.bin]未找到");
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
			Debug.Log("HeroJiBan.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="JBID"){Debug.Log("HeroJiBan.csv中字段[JBID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("HeroJiBan.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="Hero"){Debug.Log("HeroJiBan.csv中字段[Hero]位置不对应"); return false; }
		if(vecLine[3]!="Des"){Debug.Log("HeroJiBan.csv中字段[Des]位置不对应"); return false; }
		if(vecLine[4]!="Type"){Debug.Log("HeroJiBan.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[5]!="Cond"){Debug.Log("HeroJiBan.csv中字段[Cond]位置不对应"); return false; }
		if(vecLine[6]!="Attr"){Debug.Log("HeroJiBan.csv中字段[Attr]位置不对应"); return false; }
		if(vecLine[7]!="Num"){Debug.Log("HeroJiBan.csv中字段[Num]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			HeroJiBanElement member = new HeroJiBanElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.JBID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Hero );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Des);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Cond);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Attr );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.Num);

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
		if(vecLine.Count != 8)
		{
			Debug.Log("HeroJiBan.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="JBID"){Debug.Log("HeroJiBan.csv中字段[JBID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("HeroJiBan.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="Hero"){Debug.Log("HeroJiBan.csv中字段[Hero]位置不对应"); return false; }
		if(vecLine[3]!="Des"){Debug.Log("HeroJiBan.csv中字段[Des]位置不对应"); return false; }
		if(vecLine[4]!="Type"){Debug.Log("HeroJiBan.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[5]!="Cond"){Debug.Log("HeroJiBan.csv中字段[Cond]位置不对应"); return false; }
		if(vecLine[6]!="Attr"){Debug.Log("HeroJiBan.csv中字段[Attr]位置不对应"); return false; }
		if(vecLine[7]!="Num"){Debug.Log("HeroJiBan.csv中字段[Num]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)8)
			{
				return false;
			}
			HeroJiBanElement member = new HeroJiBanElement();
			member.JBID=Convert.ToInt32(vecLine[0]);
			member.Name=vecLine[1];
			member.Hero=Convert.ToInt32(vecLine[2]);
			member.Des=vecLine[3];
			member.Type=Convert.ToInt32(vecLine[4]);
			member.Cond=vecLine[5];
			member.Attr=Convert.ToInt32(vecLine[6]);
			member.Num=Convert.ToSingle(vecLine[7]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.JBID] = member;
		}
		return true;
	}
};
