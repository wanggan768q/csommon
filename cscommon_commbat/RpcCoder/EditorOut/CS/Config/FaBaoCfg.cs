using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//法宝配置数据类
public class FaBaoElement
{
	public int LvID;             	//编号	等级
	public string Name;          	//名称	法宝名称
	public int Exp;              	//消耗	消耗倍率
	public int Item;             	//消耗道具	消耗道具ID
	public string Res;           	//资源	资源
	public int Attributu;        	//属性	属性倍率
	public string Tips;          	//描述	法宝介绍
	public int Tiaojian1;        	//解锁条件1	1、角色等级2、前置法宝达到x级3、拥有x个英雄4、装备强化等阶达到x级5、装备升星等阶达到x级6、通关第x章节所有副本
	public int Canshu1;          	//解锁参数1	
	public int Tiaojian2;        	//解锁条件2	
	public int Canshu2;          	//解锁参数2	
	public int Tiaojian3;        	//解锁条件3	
	public int Canshu3;          	//解锁参数3	
	public int Tiaojian4;        	//解锁条件4	
	public int Canshu4;          	//解锁参数4	
	public int Tiaojian5;        	//解锁条件5	
	public int Canshu5;          	//解锁参数5	

	public bool IsValidate = false;
	public FaBaoElement()
	{
		LvID = -1;
	}
};

//法宝配置封装类
public class FaBaoTable
{

	private FaBaoTable()
	{
		m_mapElements = new Dictionary<int, FaBaoElement>();
		m_emptyItem = new FaBaoElement();
		m_vecAllElements = new List<FaBaoElement>();
	}
	private Dictionary<int, FaBaoElement> m_mapElements = null;
	private List<FaBaoElement>	m_vecAllElements = null;
	private FaBaoElement m_emptyItem = null;
	private static FaBaoTable sInstance = null;

	public static FaBaoTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new FaBaoTable();
			return sInstance;
		}
	}

	public FaBaoElement GetElement(int key)
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

  public List<FaBaoElement> GetAllElement(Predicate<FaBaoElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("FaBao.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("FaBao.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[FaBao.bin]未找到");
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
		if(vecLine.Count != 17)
		{
			Debug.Log("FaBao.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="LvID"){Debug.Log("FaBao.csv中字段[LvID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("FaBao.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="Exp"){Debug.Log("FaBao.csv中字段[Exp]位置不对应"); return false; }
		if(vecLine[3]!="Item"){Debug.Log("FaBao.csv中字段[Item]位置不对应"); return false; }
		if(vecLine[4]!="Res"){Debug.Log("FaBao.csv中字段[Res]位置不对应"); return false; }
		if(vecLine[5]!="Attributu"){Debug.Log("FaBao.csv中字段[Attributu]位置不对应"); return false; }
		if(vecLine[6]!="Tips"){Debug.Log("FaBao.csv中字段[Tips]位置不对应"); return false; }
		if(vecLine[7]!="Tiaojian1"){Debug.Log("FaBao.csv中字段[Tiaojian1]位置不对应"); return false; }
		if(vecLine[8]!="Canshu1"){Debug.Log("FaBao.csv中字段[Canshu1]位置不对应"); return false; }
		if(vecLine[9]!="Tiaojian2"){Debug.Log("FaBao.csv中字段[Tiaojian2]位置不对应"); return false; }
		if(vecLine[10]!="Canshu2"){Debug.Log("FaBao.csv中字段[Canshu2]位置不对应"); return false; }
		if(vecLine[11]!="Tiaojian3"){Debug.Log("FaBao.csv中字段[Tiaojian3]位置不对应"); return false; }
		if(vecLine[12]!="Canshu3"){Debug.Log("FaBao.csv中字段[Canshu3]位置不对应"); return false; }
		if(vecLine[13]!="Tiaojian4"){Debug.Log("FaBao.csv中字段[Tiaojian4]位置不对应"); return false; }
		if(vecLine[14]!="Canshu4"){Debug.Log("FaBao.csv中字段[Canshu4]位置不对应"); return false; }
		if(vecLine[15]!="Tiaojian5"){Debug.Log("FaBao.csv中字段[Tiaojian5]位置不对应"); return false; }
		if(vecLine[16]!="Canshu5"){Debug.Log("FaBao.csv中字段[Canshu5]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			FaBaoElement member = new FaBaoElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.LvID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Exp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Item );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Res);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Attributu );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Tips);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Tiaojian1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Canshu1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Tiaojian2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Canshu2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Tiaojian3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Canshu3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Tiaojian4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Canshu4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Tiaojian5 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Canshu5 );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.LvID] = member;
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
		if(vecLine.Count != 17)
		{
			Debug.Log("FaBao.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="LvID"){Debug.Log("FaBao.csv中字段[LvID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("FaBao.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="Exp"){Debug.Log("FaBao.csv中字段[Exp]位置不对应"); return false; }
		if(vecLine[3]!="Item"){Debug.Log("FaBao.csv中字段[Item]位置不对应"); return false; }
		if(vecLine[4]!="Res"){Debug.Log("FaBao.csv中字段[Res]位置不对应"); return false; }
		if(vecLine[5]!="Attributu"){Debug.Log("FaBao.csv中字段[Attributu]位置不对应"); return false; }
		if(vecLine[6]!="Tips"){Debug.Log("FaBao.csv中字段[Tips]位置不对应"); return false; }
		if(vecLine[7]!="Tiaojian1"){Debug.Log("FaBao.csv中字段[Tiaojian1]位置不对应"); return false; }
		if(vecLine[8]!="Canshu1"){Debug.Log("FaBao.csv中字段[Canshu1]位置不对应"); return false; }
		if(vecLine[9]!="Tiaojian2"){Debug.Log("FaBao.csv中字段[Tiaojian2]位置不对应"); return false; }
		if(vecLine[10]!="Canshu2"){Debug.Log("FaBao.csv中字段[Canshu2]位置不对应"); return false; }
		if(vecLine[11]!="Tiaojian3"){Debug.Log("FaBao.csv中字段[Tiaojian3]位置不对应"); return false; }
		if(vecLine[12]!="Canshu3"){Debug.Log("FaBao.csv中字段[Canshu3]位置不对应"); return false; }
		if(vecLine[13]!="Tiaojian4"){Debug.Log("FaBao.csv中字段[Tiaojian4]位置不对应"); return false; }
		if(vecLine[14]!="Canshu4"){Debug.Log("FaBao.csv中字段[Canshu4]位置不对应"); return false; }
		if(vecLine[15]!="Tiaojian5"){Debug.Log("FaBao.csv中字段[Tiaojian5]位置不对应"); return false; }
		if(vecLine[16]!="Canshu5"){Debug.Log("FaBao.csv中字段[Canshu5]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)17)
			{
				return false;
			}
			FaBaoElement member = new FaBaoElement();
			member.LvID=Convert.ToInt32(vecLine[0]);
			member.Name=vecLine[1];
			member.Exp=Convert.ToInt32(vecLine[2]);
			member.Item=Convert.ToInt32(vecLine[3]);
			member.Res=vecLine[4];
			member.Attributu=Convert.ToInt32(vecLine[5]);
			member.Tips=vecLine[6];
			member.Tiaojian1=Convert.ToInt32(vecLine[7]);
			member.Canshu1=Convert.ToInt32(vecLine[8]);
			member.Tiaojian2=Convert.ToInt32(vecLine[9]);
			member.Canshu2=Convert.ToInt32(vecLine[10]);
			member.Tiaojian3=Convert.ToInt32(vecLine[11]);
			member.Canshu3=Convert.ToInt32(vecLine[12]);
			member.Tiaojian4=Convert.ToInt32(vecLine[13]);
			member.Canshu4=Convert.ToInt32(vecLine[14]);
			member.Tiaojian5=Convert.ToInt32(vecLine[15]);
			member.Canshu5=Convert.ToInt32(vecLine[16]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.LvID] = member;
		}
		return true;
	}
};
