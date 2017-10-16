using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备品质表配置数据类
public class EquipColourElement
{
	public int ID;               	//编号	编号ID
	public int EquipID;          	//	装备ID
	public string Name;          	//装备名称	装备名称
	public string Res;           	//装备资源	
	public int Item1;            	//进化消耗道具	进化消耗道具ID
	public int Num1;             	//进化消耗道具数量	进化消耗道具数量
	public int Money;            	//进化消耗金钱	进化消耗金钱
	public int Decompose;        	//分解	是否可分解
	public int DecomposeID;      	//分解道具	分解出的道具
	public int Nummin;           	//分解道具数量下限	分解道具数量下限
	public int Nummax;           	//分解道具数上下限	分解道具数量上限
	public int Price;            	//价格	分解价格
	public int Item2;            	//强化道具	强化道具ID
	public int Num2;             	//强化消耗倍率	强化消耗道具数量的倍率参数，小数点后两位
	public int Item3;            	//升星道具	升星道具ID
	public int Num3;             	//升星消耗倍率	升星消耗道具数量的倍率参数，小数点后两位

	public bool IsValidate = false;
	public EquipColourElement()
	{
		ID = -1;
	}
};

//装备品质表配置封装类
public class EquipColourTable
{

	private EquipColourTable()
	{
		m_mapElements = new Dictionary<int, EquipColourElement>();
		m_emptyItem = new EquipColourElement();
		m_vecAllElements = new List<EquipColourElement>();
	}
	private Dictionary<int, EquipColourElement> m_mapElements = null;
	private List<EquipColourElement>	m_vecAllElements = null;
	private EquipColourElement m_emptyItem = null;
	private static EquipColourTable sInstance = null;

	public static EquipColourTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipColourTable();
			return sInstance;
		}
	}

	public EquipColourElement GetElement(int key)
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

  public List<EquipColourElement> GetAllElement(Predicate<EquipColourElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EquipColour.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EquipColour.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[EquipColour.bin]未找到");
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
			Debug.Log("EquipColour.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("EquipColour.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="EquipID"){Debug.Log("EquipColour.csv中字段[EquipID]位置不对应"); return false; }
		if(vecLine[2]!="Name"){Debug.Log("EquipColour.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[3]!="Res"){Debug.Log("EquipColour.csv中字段[Res]位置不对应"); return false; }
		if(vecLine[4]!="Item1"){Debug.Log("EquipColour.csv中字段[Item1]位置不对应"); return false; }
		if(vecLine[5]!="Num1"){Debug.Log("EquipColour.csv中字段[Num1]位置不对应"); return false; }
		if(vecLine[6]!="Money"){Debug.Log("EquipColour.csv中字段[Money]位置不对应"); return false; }
		if(vecLine[7]!="Decompose"){Debug.Log("EquipColour.csv中字段[Decompose]位置不对应"); return false; }
		if(vecLine[8]!="DecomposeID"){Debug.Log("EquipColour.csv中字段[DecomposeID]位置不对应"); return false; }
		if(vecLine[9]!="Nummin"){Debug.Log("EquipColour.csv中字段[Nummin]位置不对应"); return false; }
		if(vecLine[10]!="Nummax"){Debug.Log("EquipColour.csv中字段[Nummax]位置不对应"); return false; }
		if(vecLine[11]!="Price"){Debug.Log("EquipColour.csv中字段[Price]位置不对应"); return false; }
		if(vecLine[12]!="Item2"){Debug.Log("EquipColour.csv中字段[Item2]位置不对应"); return false; }
		if(vecLine[13]!="Num2"){Debug.Log("EquipColour.csv中字段[Num2]位置不对应"); return false; }
		if(vecLine[14]!="Item3"){Debug.Log("EquipColour.csv中字段[Item3]位置不对应"); return false; }
		if(vecLine[15]!="Num3"){Debug.Log("EquipColour.csv中字段[Num3]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipColourElement member = new EquipColourElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.EquipID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.Res);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Item1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Money );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Decompose );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.DecomposeID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Nummin );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Nummax );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Price );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Item2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Item3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num3 );

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
		if(vecLine.Count != 16)
		{
			Debug.Log("EquipColour.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("EquipColour.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="EquipID"){Debug.Log("EquipColour.csv中字段[EquipID]位置不对应"); return false; }
		if(vecLine[2]!="Name"){Debug.Log("EquipColour.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[3]!="Res"){Debug.Log("EquipColour.csv中字段[Res]位置不对应"); return false; }
		if(vecLine[4]!="Item1"){Debug.Log("EquipColour.csv中字段[Item1]位置不对应"); return false; }
		if(vecLine[5]!="Num1"){Debug.Log("EquipColour.csv中字段[Num1]位置不对应"); return false; }
		if(vecLine[6]!="Money"){Debug.Log("EquipColour.csv中字段[Money]位置不对应"); return false; }
		if(vecLine[7]!="Decompose"){Debug.Log("EquipColour.csv中字段[Decompose]位置不对应"); return false; }
		if(vecLine[8]!="DecomposeID"){Debug.Log("EquipColour.csv中字段[DecomposeID]位置不对应"); return false; }
		if(vecLine[9]!="Nummin"){Debug.Log("EquipColour.csv中字段[Nummin]位置不对应"); return false; }
		if(vecLine[10]!="Nummax"){Debug.Log("EquipColour.csv中字段[Nummax]位置不对应"); return false; }
		if(vecLine[11]!="Price"){Debug.Log("EquipColour.csv中字段[Price]位置不对应"); return false; }
		if(vecLine[12]!="Item2"){Debug.Log("EquipColour.csv中字段[Item2]位置不对应"); return false; }
		if(vecLine[13]!="Num2"){Debug.Log("EquipColour.csv中字段[Num2]位置不对应"); return false; }
		if(vecLine[14]!="Item3"){Debug.Log("EquipColour.csv中字段[Item3]位置不对应"); return false; }
		if(vecLine[15]!="Num3"){Debug.Log("EquipColour.csv中字段[Num3]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)16)
			{
				return false;
			}
			EquipColourElement member = new EquipColourElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.EquipID=Convert.ToInt32(vecLine[1]);
			member.Name=vecLine[2];
			member.Res=vecLine[3];
			member.Item1=Convert.ToInt32(vecLine[4]);
			member.Num1=Convert.ToInt32(vecLine[5]);
			member.Money=Convert.ToInt32(vecLine[6]);
			member.Decompose=Convert.ToInt32(vecLine[7]);
			member.DecomposeID=Convert.ToInt32(vecLine[8]);
			member.Nummin=Convert.ToInt32(vecLine[9]);
			member.Nummax=Convert.ToInt32(vecLine[10]);
			member.Price=Convert.ToInt32(vecLine[11]);
			member.Item2=Convert.ToInt32(vecLine[12]);
			member.Num2=Convert.ToInt32(vecLine[13]);
			member.Item3=Convert.ToInt32(vecLine[14]);
			member.Num3=Convert.ToInt32(vecLine[15]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
