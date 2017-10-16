using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//英雄天命配置数据类
public class HeroTMElement
{
	public int Hero;             	//编号	编号
	public int Type;             	//英雄类别	英雄类别
	public int LV;               	//天命等级（天命等级默认为0）	天命等级
	public int ID1;              	//星石ID（升到该等级所需的星石）	星石ID
	public int Num1;             	//星石数量	星石数量
	public int ID2;              	//星石ID	星石ID
	public int Num2;             	//星石数量	星石数量
	public int ID3;              	//星石ID	星石ID
	public int Num3;             	//星石数量	星石数量
	public int ID4;              	//星石ID	星石ID
	public int Num4;             	//星石数量	星石数量
	public int ID5;              	//星石ID	星石ID
	public int Num5;             	//星石数量	星石数量
	public int ID6;              	//星石ID	星石ID
	public int Num6;             	//星石数量	星石数量
	public int Pattack;          	//物理攻击	物理攻击
	public int Mattack;          	//法术攻击	法术攻击
	public int PDefense;         	//物理防御	物理防御
	public int MDefense;         	//法术防御	法术防御
	public int HP;               	//最大生命	最大生命

	public bool IsValidate = false;
	public HeroTMElement()
	{
		Hero = -1;
	}
};

//英雄天命配置封装类
public class HeroTMTable
{

	private HeroTMTable()
	{
		m_mapElements = new Dictionary<int, HeroTMElement>();
		m_emptyItem = new HeroTMElement();
		m_vecAllElements = new List<HeroTMElement>();
	}
	private Dictionary<int, HeroTMElement> m_mapElements = null;
	private List<HeroTMElement>	m_vecAllElements = null;
	private HeroTMElement m_emptyItem = null;
	private static HeroTMTable sInstance = null;

	public static HeroTMTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new HeroTMTable();
			return sInstance;
		}
	}

	public HeroTMElement GetElement(int key)
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

  public List<HeroTMElement> GetAllElement(Predicate<HeroTMElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("HeroTM.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("HeroTM.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[HeroTM.bin]未找到");
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
		if(vecLine.Count != 20)
		{
			Debug.Log("HeroTM.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="Hero"){Debug.Log("HeroTM.csv中字段[Hero]位置不对应"); return false; }
		if(vecLine[1]!="Type"){Debug.Log("HeroTM.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[2]!="LV"){Debug.Log("HeroTM.csv中字段[LV]位置不对应"); return false; }
		if(vecLine[3]!="ID1"){Debug.Log("HeroTM.csv中字段[ID1]位置不对应"); return false; }
		if(vecLine[4]!="Num1"){Debug.Log("HeroTM.csv中字段[Num1]位置不对应"); return false; }
		if(vecLine[5]!="ID2"){Debug.Log("HeroTM.csv中字段[ID2]位置不对应"); return false; }
		if(vecLine[6]!="Num2"){Debug.Log("HeroTM.csv中字段[Num2]位置不对应"); return false; }
		if(vecLine[7]!="ID3"){Debug.Log("HeroTM.csv中字段[ID3]位置不对应"); return false; }
		if(vecLine[8]!="Num3"){Debug.Log("HeroTM.csv中字段[Num3]位置不对应"); return false; }
		if(vecLine[9]!="ID4"){Debug.Log("HeroTM.csv中字段[ID4]位置不对应"); return false; }
		if(vecLine[10]!="Num4"){Debug.Log("HeroTM.csv中字段[Num4]位置不对应"); return false; }
		if(vecLine[11]!="ID5"){Debug.Log("HeroTM.csv中字段[ID5]位置不对应"); return false; }
		if(vecLine[12]!="Num5"){Debug.Log("HeroTM.csv中字段[Num5]位置不对应"); return false; }
		if(vecLine[13]!="ID6"){Debug.Log("HeroTM.csv中字段[ID6]位置不对应"); return false; }
		if(vecLine[14]!="Num6"){Debug.Log("HeroTM.csv中字段[Num6]位置不对应"); return false; }
		if(vecLine[15]!="Pattack"){Debug.Log("HeroTM.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[16]!="Mattack"){Debug.Log("HeroTM.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[17]!="PDefense"){Debug.Log("HeroTM.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[18]!="MDefense"){Debug.Log("HeroTM.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[19]!="HP"){Debug.Log("HeroTM.csv中字段[HP]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			HeroTMElement member = new HeroTMElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Hero );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.LV );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID5 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num5 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID6 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num6 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Pattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Mattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.PDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HP );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.Hero] = member;
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
		if(vecLine.Count != 20)
		{
			Debug.Log("HeroTM.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="Hero"){Debug.Log("HeroTM.csv中字段[Hero]位置不对应"); return false; }
		if(vecLine[1]!="Type"){Debug.Log("HeroTM.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[2]!="LV"){Debug.Log("HeroTM.csv中字段[LV]位置不对应"); return false; }
		if(vecLine[3]!="ID1"){Debug.Log("HeroTM.csv中字段[ID1]位置不对应"); return false; }
		if(vecLine[4]!="Num1"){Debug.Log("HeroTM.csv中字段[Num1]位置不对应"); return false; }
		if(vecLine[5]!="ID2"){Debug.Log("HeroTM.csv中字段[ID2]位置不对应"); return false; }
		if(vecLine[6]!="Num2"){Debug.Log("HeroTM.csv中字段[Num2]位置不对应"); return false; }
		if(vecLine[7]!="ID3"){Debug.Log("HeroTM.csv中字段[ID3]位置不对应"); return false; }
		if(vecLine[8]!="Num3"){Debug.Log("HeroTM.csv中字段[Num3]位置不对应"); return false; }
		if(vecLine[9]!="ID4"){Debug.Log("HeroTM.csv中字段[ID4]位置不对应"); return false; }
		if(vecLine[10]!="Num4"){Debug.Log("HeroTM.csv中字段[Num4]位置不对应"); return false; }
		if(vecLine[11]!="ID5"){Debug.Log("HeroTM.csv中字段[ID5]位置不对应"); return false; }
		if(vecLine[12]!="Num5"){Debug.Log("HeroTM.csv中字段[Num5]位置不对应"); return false; }
		if(vecLine[13]!="ID6"){Debug.Log("HeroTM.csv中字段[ID6]位置不对应"); return false; }
		if(vecLine[14]!="Num6"){Debug.Log("HeroTM.csv中字段[Num6]位置不对应"); return false; }
		if(vecLine[15]!="Pattack"){Debug.Log("HeroTM.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[16]!="Mattack"){Debug.Log("HeroTM.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[17]!="PDefense"){Debug.Log("HeroTM.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[18]!="MDefense"){Debug.Log("HeroTM.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[19]!="HP"){Debug.Log("HeroTM.csv中字段[HP]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)20)
			{
				return false;
			}
			HeroTMElement member = new HeroTMElement();
			member.Hero=Convert.ToInt32(vecLine[0]);
			member.Type=Convert.ToInt32(vecLine[1]);
			member.LV=Convert.ToInt32(vecLine[2]);
			member.ID1=Convert.ToInt32(vecLine[3]);
			member.Num1=Convert.ToInt32(vecLine[4]);
			member.ID2=Convert.ToInt32(vecLine[5]);
			member.Num2=Convert.ToInt32(vecLine[6]);
			member.ID3=Convert.ToInt32(vecLine[7]);
			member.Num3=Convert.ToInt32(vecLine[8]);
			member.ID4=Convert.ToInt32(vecLine[9]);
			member.Num4=Convert.ToInt32(vecLine[10]);
			member.ID5=Convert.ToInt32(vecLine[11]);
			member.Num5=Convert.ToInt32(vecLine[12]);
			member.ID6=Convert.ToInt32(vecLine[13]);
			member.Num6=Convert.ToInt32(vecLine[14]);
			member.Pattack=Convert.ToInt32(vecLine[15]);
			member.Mattack=Convert.ToInt32(vecLine[16]);
			member.PDefense=Convert.ToInt32(vecLine[17]);
			member.MDefense=Convert.ToInt32(vecLine[18]);
			member.HP=Convert.ToInt32(vecLine[19]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.Hero] = member;
		}
		return true;
	}
};
