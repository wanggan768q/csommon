using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//英雄品质配置数据类
public class HeroColourElement
{
	public int HeroColourID;     	//编号	英雄品质ID
	public int StarLV;           	//星级	星级
	public int ID;               	//英雄ID	英雄ID
	public int Money;            	//升星所需金币	升星所需金币
	public int SuiPian;          	//碎片	碎片
	public int Num;              	//升星所需碎片数量	升星所需碎片数量
	public float Str;            	//力量	力量
	public float Dex;            	//敏捷	敏捷
	public float IQ;             	//智力	智力
	public float HP;             	//最大生命	最大生命
	public float Pattack;        	//物理攻击	物理攻击
	public float Mattack;        	//法术攻击	法术攻击
	public float PDefense;       	//物理防御	物理防御
	public float MDefense;       	//法术防御	法术防御

	public bool IsValidate = false;
	public HeroColourElement()
	{
		HeroColourID = -1;
	}
};

//英雄品质配置封装类
public class HeroColourTable
{

	private HeroColourTable()
	{
		m_mapElements = new Dictionary<int, HeroColourElement>();
		m_emptyItem = new HeroColourElement();
		m_vecAllElements = new List<HeroColourElement>();
	}
	private Dictionary<int, HeroColourElement> m_mapElements = null;
	private List<HeroColourElement>	m_vecAllElements = null;
	private HeroColourElement m_emptyItem = null;
	private static HeroColourTable sInstance = null;

	public static HeroColourTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new HeroColourTable();
			return sInstance;
		}
	}

	public HeroColourElement GetElement(int key)
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

  public List<HeroColourElement> GetAllElement(Predicate<HeroColourElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("HeroColour.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("HeroColour.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[HeroColour.bin]未找到");
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
		if(vecLine.Count != 14)
		{
			Debug.Log("HeroColour.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="HeroColourID"){Debug.Log("HeroColour.csv中字段[HeroColourID]位置不对应"); return false; }
		if(vecLine[1]!="StarLV"){Debug.Log("HeroColour.csv中字段[StarLV]位置不对应"); return false; }
		if(vecLine[2]!="ID"){Debug.Log("HeroColour.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[3]!="Money"){Debug.Log("HeroColour.csv中字段[Money]位置不对应"); return false; }
		if(vecLine[4]!="SuiPian"){Debug.Log("HeroColour.csv中字段[SuiPian]位置不对应"); return false; }
		if(vecLine[5]!="Num"){Debug.Log("HeroColour.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[6]!="Str"){Debug.Log("HeroColour.csv中字段[Str]位置不对应"); return false; }
		if(vecLine[7]!="Dex"){Debug.Log("HeroColour.csv中字段[Dex]位置不对应"); return false; }
		if(vecLine[8]!="IQ"){Debug.Log("HeroColour.csv中字段[IQ]位置不对应"); return false; }
		if(vecLine[9]!="HP"){Debug.Log("HeroColour.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[10]!="Pattack"){Debug.Log("HeroColour.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[11]!="Mattack"){Debug.Log("HeroColour.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[12]!="PDefense"){Debug.Log("HeroColour.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[13]!="MDefense"){Debug.Log("HeroColour.csv中字段[MDefense]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			HeroColourElement member = new HeroColourElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HeroColourID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.StarLV );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Money );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.SuiPian );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.Str);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.Dex);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.IQ);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.HP);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.Pattack);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.Mattack);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.PDefense);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.MDefense);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.HeroColourID] = member;
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
		if(vecLine.Count != 14)
		{
			Debug.Log("HeroColour.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="HeroColourID"){Debug.Log("HeroColour.csv中字段[HeroColourID]位置不对应"); return false; }
		if(vecLine[1]!="StarLV"){Debug.Log("HeroColour.csv中字段[StarLV]位置不对应"); return false; }
		if(vecLine[2]!="ID"){Debug.Log("HeroColour.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[3]!="Money"){Debug.Log("HeroColour.csv中字段[Money]位置不对应"); return false; }
		if(vecLine[4]!="SuiPian"){Debug.Log("HeroColour.csv中字段[SuiPian]位置不对应"); return false; }
		if(vecLine[5]!="Num"){Debug.Log("HeroColour.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[6]!="Str"){Debug.Log("HeroColour.csv中字段[Str]位置不对应"); return false; }
		if(vecLine[7]!="Dex"){Debug.Log("HeroColour.csv中字段[Dex]位置不对应"); return false; }
		if(vecLine[8]!="IQ"){Debug.Log("HeroColour.csv中字段[IQ]位置不对应"); return false; }
		if(vecLine[9]!="HP"){Debug.Log("HeroColour.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[10]!="Pattack"){Debug.Log("HeroColour.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[11]!="Mattack"){Debug.Log("HeroColour.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[12]!="PDefense"){Debug.Log("HeroColour.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[13]!="MDefense"){Debug.Log("HeroColour.csv中字段[MDefense]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)14)
			{
				return false;
			}
			HeroColourElement member = new HeroColourElement();
			member.HeroColourID=Convert.ToInt32(vecLine[0]);
			member.StarLV=Convert.ToInt32(vecLine[1]);
			member.ID=Convert.ToInt32(vecLine[2]);
			member.Money=Convert.ToInt32(vecLine[3]);
			member.SuiPian=Convert.ToInt32(vecLine[4]);
			member.Num=Convert.ToInt32(vecLine[5]);
			member.Str=Convert.ToSingle(vecLine[6]);
			member.Dex=Convert.ToSingle(vecLine[7]);
			member.IQ=Convert.ToSingle(vecLine[8]);
			member.HP=Convert.ToSingle(vecLine[9]);
			member.Pattack=Convert.ToSingle(vecLine[10]);
			member.Mattack=Convert.ToSingle(vecLine[11]);
			member.PDefense=Convert.ToSingle(vecLine[12]);
			member.MDefense=Convert.ToSingle(vecLine[13]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.HeroColourID] = member;
		}
		return true;
	}
};
