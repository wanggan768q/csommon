using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//法宝基础配置数据类
public class FaBaoAttributeElement
{
	public int LvID;             	//编号	等级
	public int Num;              	//消耗数量	一次消耗资源数量
	public int Nor;              	//普通增加经验	普通增加经验
	public int Probability1;     	//普通增加经验概率	普通增加经验概率
	public int Small;            	//小暴击增加经验	小暴击增加经验
	public int Probability2;     	//小暴击概率	小暴击概率
	public int Big;              	//暴击增加经验	暴击增加经验
	public int Probability3;     	//暴击概率	暴击概率
	public int Supper;           	//大暴击增加经验	大暴击增加经验
	public int Probability4;     	//大暴击概率	大暴击概率
	public int Exp;              	//升级所需经验	升级所需经验
	public int HP;               	//生命	生命
	public int Pattack;          	//物攻	物攻
	public int Mattack;          	//法攻	法攻
	public int PDefense;         	//物防	物防
	public int MDefense;         	//法防	法防

	public bool IsValidate = false;
	public FaBaoAttributeElement()
	{
		LvID = -1;
	}
};

//法宝基础配置封装类
public class FaBaoAttributeTable
{

	private FaBaoAttributeTable()
	{
		m_mapElements = new Dictionary<int, FaBaoAttributeElement>();
		m_emptyItem = new FaBaoAttributeElement();
		m_vecAllElements = new List<FaBaoAttributeElement>();
	}
	private Dictionary<int, FaBaoAttributeElement> m_mapElements = null;
	private List<FaBaoAttributeElement>	m_vecAllElements = null;
	private FaBaoAttributeElement m_emptyItem = null;
	private static FaBaoAttributeTable sInstance = null;

	public static FaBaoAttributeTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new FaBaoAttributeTable();
			return sInstance;
		}
	}

	public FaBaoAttributeElement GetElement(int key)
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

  public List<FaBaoAttributeElement> GetAllElement(Predicate<FaBaoAttributeElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("FaBaoAttribute.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("FaBaoAttribute.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[FaBaoAttribute.bin]未找到");
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
		if(vecLine.Count != 16)
		{
			Debug.Log("FaBaoAttribute.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="LvID"){Debug.Log("FaBaoAttribute.csv中字段[LvID]位置不对应"); return false; }
		if(vecLine[1]!="Num"){Debug.Log("FaBaoAttribute.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[2]!="Nor"){Debug.Log("FaBaoAttribute.csv中字段[Nor]位置不对应"); return false; }
		if(vecLine[3]!="Probability1"){Debug.Log("FaBaoAttribute.csv中字段[Probability1]位置不对应"); return false; }
		if(vecLine[4]!="Small"){Debug.Log("FaBaoAttribute.csv中字段[Small]位置不对应"); return false; }
		if(vecLine[5]!="Probability2"){Debug.Log("FaBaoAttribute.csv中字段[Probability2]位置不对应"); return false; }
		if(vecLine[6]!="Big"){Debug.Log("FaBaoAttribute.csv中字段[Big]位置不对应"); return false; }
		if(vecLine[7]!="Probability3"){Debug.Log("FaBaoAttribute.csv中字段[Probability3]位置不对应"); return false; }
		if(vecLine[8]!="Supper"){Debug.Log("FaBaoAttribute.csv中字段[Supper]位置不对应"); return false; }
		if(vecLine[9]!="Probability4"){Debug.Log("FaBaoAttribute.csv中字段[Probability4]位置不对应"); return false; }
		if(vecLine[10]!="Exp"){Debug.Log("FaBaoAttribute.csv中字段[Exp]位置不对应"); return false; }
		if(vecLine[11]!="HP"){Debug.Log("FaBaoAttribute.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[12]!="Pattack"){Debug.Log("FaBaoAttribute.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[13]!="Mattack"){Debug.Log("FaBaoAttribute.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[14]!="PDefense"){Debug.Log("FaBaoAttribute.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[15]!="MDefense"){Debug.Log("FaBaoAttribute.csv中字段[MDefense]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			FaBaoAttributeElement member = new FaBaoAttributeElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.LvID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Nor );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Probability1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Small );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Probability2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Big );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Probability3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Supper );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Probability4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Exp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HP );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Pattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Mattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.PDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MDefense );

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
		if(vecLine.Count != 16)
		{
			Debug.Log("FaBaoAttribute.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="LvID"){Debug.Log("FaBaoAttribute.csv中字段[LvID]位置不对应"); return false; }
		if(vecLine[1]!="Num"){Debug.Log("FaBaoAttribute.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[2]!="Nor"){Debug.Log("FaBaoAttribute.csv中字段[Nor]位置不对应"); return false; }
		if(vecLine[3]!="Probability1"){Debug.Log("FaBaoAttribute.csv中字段[Probability1]位置不对应"); return false; }
		if(vecLine[4]!="Small"){Debug.Log("FaBaoAttribute.csv中字段[Small]位置不对应"); return false; }
		if(vecLine[5]!="Probability2"){Debug.Log("FaBaoAttribute.csv中字段[Probability2]位置不对应"); return false; }
		if(vecLine[6]!="Big"){Debug.Log("FaBaoAttribute.csv中字段[Big]位置不对应"); return false; }
		if(vecLine[7]!="Probability3"){Debug.Log("FaBaoAttribute.csv中字段[Probability3]位置不对应"); return false; }
		if(vecLine[8]!="Supper"){Debug.Log("FaBaoAttribute.csv中字段[Supper]位置不对应"); return false; }
		if(vecLine[9]!="Probability4"){Debug.Log("FaBaoAttribute.csv中字段[Probability4]位置不对应"); return false; }
		if(vecLine[10]!="Exp"){Debug.Log("FaBaoAttribute.csv中字段[Exp]位置不对应"); return false; }
		if(vecLine[11]!="HP"){Debug.Log("FaBaoAttribute.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[12]!="Pattack"){Debug.Log("FaBaoAttribute.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[13]!="Mattack"){Debug.Log("FaBaoAttribute.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[14]!="PDefense"){Debug.Log("FaBaoAttribute.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[15]!="MDefense"){Debug.Log("FaBaoAttribute.csv中字段[MDefense]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)16)
			{
				return false;
			}
			FaBaoAttributeElement member = new FaBaoAttributeElement();
			member.LvID=Convert.ToInt32(vecLine[0]);
			member.Num=Convert.ToInt32(vecLine[1]);
			member.Nor=Convert.ToInt32(vecLine[2]);
			member.Probability1=Convert.ToInt32(vecLine[3]);
			member.Small=Convert.ToInt32(vecLine[4]);
			member.Probability2=Convert.ToInt32(vecLine[5]);
			member.Big=Convert.ToInt32(vecLine[6]);
			member.Probability3=Convert.ToInt32(vecLine[7]);
			member.Supper=Convert.ToInt32(vecLine[8]);
			member.Probability4=Convert.ToInt32(vecLine[9]);
			member.Exp=Convert.ToInt32(vecLine[10]);
			member.HP=Convert.ToInt32(vecLine[11]);
			member.Pattack=Convert.ToInt32(vecLine[12]);
			member.Mattack=Convert.ToInt32(vecLine[13]);
			member.PDefense=Convert.ToInt32(vecLine[14]);
			member.MDefense=Convert.ToInt32(vecLine[15]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.LvID] = member;
		}
		return true;
	}
};
