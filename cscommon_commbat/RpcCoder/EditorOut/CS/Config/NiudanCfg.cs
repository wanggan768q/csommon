using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//抽奖配置数据类
public class NiudanElement
{
	public int ID;               	//编号	编号
	public int ItemID;           	//物品ID	物品ID
	public string Name;          	//物品名称	物品名称
	public int Type;             	//类别	类别
	public string Res;           	//资源	资源
	public int Set;              	//所属扭蛋	所属扭蛋（1，普通抽英雄，2钻石抽英雄 3抽装备4普通抽宝石5钻石抽宝石）
	public int Pro;              	//机率	机率
	public string Num;           	//数量	随机抽出数量
	public int Must;             	//是否可能必出	是否可能必出
	public int MustPro;          	//必出时概率	必出时概率
	public int MustNum;          	//必出数量	必出数量

	public bool IsValidate = false;
	public NiudanElement()
	{
		ID = -1;
	}
};

//抽奖配置封装类
public class NiudanTable
{

	private NiudanTable()
	{
		m_mapElements = new Dictionary<int, NiudanElement>();
		m_emptyItem = new NiudanElement();
		m_vecAllElements = new List<NiudanElement>();
	}
	private Dictionary<int, NiudanElement> m_mapElements = null;
	private List<NiudanElement>	m_vecAllElements = null;
	private NiudanElement m_emptyItem = null;
	private static NiudanTable sInstance = null;

	public static NiudanTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new NiudanTable();
			return sInstance;
		}
	}

	public NiudanElement GetElement(int key)
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

  public List<NiudanElement> GetAllElement(Predicate<NiudanElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Niudan.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Niudan.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[Niudan.bin]未找到");
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
		if(vecLine.Count != 11)
		{
			Debug.Log("Niudan.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("Niudan.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="ItemID"){Debug.Log("Niudan.csv中字段[ItemID]位置不对应"); return false; }
		if(vecLine[2]!="Name"){Debug.Log("Niudan.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[3]!="Type"){Debug.Log("Niudan.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[4]!="Res"){Debug.Log("Niudan.csv中字段[Res]位置不对应"); return false; }
		if(vecLine[5]!="Set"){Debug.Log("Niudan.csv中字段[Set]位置不对应"); return false; }
		if(vecLine[6]!="Pro"){Debug.Log("Niudan.csv中字段[Pro]位置不对应"); return false; }
		if(vecLine[7]!="Num"){Debug.Log("Niudan.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[8]!="Must"){Debug.Log("Niudan.csv中字段[Must]位置不对应"); return false; }
		if(vecLine[9]!="MustPro"){Debug.Log("Niudan.csv中字段[MustPro]位置不对应"); return false; }
		if(vecLine[10]!="MustNum"){Debug.Log("Niudan.csv中字段[MustNum]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			NiudanElement member = new NiudanElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ItemID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Res);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Set );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Pro );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Num);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Must );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MustPro );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MustNum );

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
		if(vecLine.Count != 11)
		{
			Debug.Log("Niudan.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("Niudan.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="ItemID"){Debug.Log("Niudan.csv中字段[ItemID]位置不对应"); return false; }
		if(vecLine[2]!="Name"){Debug.Log("Niudan.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[3]!="Type"){Debug.Log("Niudan.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[4]!="Res"){Debug.Log("Niudan.csv中字段[Res]位置不对应"); return false; }
		if(vecLine[5]!="Set"){Debug.Log("Niudan.csv中字段[Set]位置不对应"); return false; }
		if(vecLine[6]!="Pro"){Debug.Log("Niudan.csv中字段[Pro]位置不对应"); return false; }
		if(vecLine[7]!="Num"){Debug.Log("Niudan.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[8]!="Must"){Debug.Log("Niudan.csv中字段[Must]位置不对应"); return false; }
		if(vecLine[9]!="MustPro"){Debug.Log("Niudan.csv中字段[MustPro]位置不对应"); return false; }
		if(vecLine[10]!="MustNum"){Debug.Log("Niudan.csv中字段[MustNum]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)11)
			{
				return false;
			}
			NiudanElement member = new NiudanElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.ItemID=Convert.ToInt32(vecLine[1]);
			member.Name=vecLine[2];
			member.Type=Convert.ToInt32(vecLine[3]);
			member.Res=vecLine[4];
			member.Set=Convert.ToInt32(vecLine[5]);
			member.Pro=Convert.ToInt32(vecLine[6]);
			member.Num=vecLine[7];
			member.Must=Convert.ToInt32(vecLine[8]);
			member.MustPro=Convert.ToInt32(vecLine[9]);
			member.MustNum=Convert.ToInt32(vecLine[10]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
