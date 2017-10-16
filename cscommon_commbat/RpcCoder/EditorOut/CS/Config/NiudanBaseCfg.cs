using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//抽奖基础配置数据类
public class NiudanBaseElement
{
	public int ID;               	//编号	编号
	public int NiudanID;         	//扭蛋ID	扭蛋ID
	public string Name;          	//物品名称	物品名称
	public int XiaoHao;          	//类别	类别（1金币2钻石）
	public int Num;              	//单次消耗数量	单次消耗数量
	public int ManyNum;          	//多次消耗数量	多次消耗数量
	public int Many;             	//多次消耗的次数	多次消耗的次数
	public int Free;             	//每天免费次数	每天免费次数
	public int Count;            	//第几次必出	第几次必出

	public bool IsValidate = false;
	public NiudanBaseElement()
	{
		ID = -1;
	}
};

//抽奖基础配置封装类
public class NiudanBaseTable
{

	private NiudanBaseTable()
	{
		m_mapElements = new Dictionary<int, NiudanBaseElement>();
		m_emptyItem = new NiudanBaseElement();
		m_vecAllElements = new List<NiudanBaseElement>();
	}
	private Dictionary<int, NiudanBaseElement> m_mapElements = null;
	private List<NiudanBaseElement>	m_vecAllElements = null;
	private NiudanBaseElement m_emptyItem = null;
	private static NiudanBaseTable sInstance = null;

	public static NiudanBaseTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new NiudanBaseTable();
			return sInstance;
		}
	}

	public NiudanBaseElement GetElement(int key)
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

  public List<NiudanBaseElement> GetAllElement(Predicate<NiudanBaseElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("NiudanBase.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("NiudanBase.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[NiudanBase.bin]未找到");
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
			Debug.Log("NiudanBase.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("NiudanBase.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="NiudanID"){Debug.Log("NiudanBase.csv中字段[NiudanID]位置不对应"); return false; }
		if(vecLine[2]!="Name"){Debug.Log("NiudanBase.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[3]!="XiaoHao"){Debug.Log("NiudanBase.csv中字段[XiaoHao]位置不对应"); return false; }
		if(vecLine[4]!="Num"){Debug.Log("NiudanBase.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[5]!="ManyNum"){Debug.Log("NiudanBase.csv中字段[ManyNum]位置不对应"); return false; }
		if(vecLine[6]!="Many"){Debug.Log("NiudanBase.csv中字段[Many]位置不对应"); return false; }
		if(vecLine[7]!="Free"){Debug.Log("NiudanBase.csv中字段[Free]位置不对应"); return false; }
		if(vecLine[8]!="Count"){Debug.Log("NiudanBase.csv中字段[Count]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			NiudanBaseElement member = new NiudanBaseElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.NiudanID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.XiaoHao );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ManyNum );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Many );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Free );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Count );

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
			Debug.Log("NiudanBase.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("NiudanBase.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="NiudanID"){Debug.Log("NiudanBase.csv中字段[NiudanID]位置不对应"); return false; }
		if(vecLine[2]!="Name"){Debug.Log("NiudanBase.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[3]!="XiaoHao"){Debug.Log("NiudanBase.csv中字段[XiaoHao]位置不对应"); return false; }
		if(vecLine[4]!="Num"){Debug.Log("NiudanBase.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[5]!="ManyNum"){Debug.Log("NiudanBase.csv中字段[ManyNum]位置不对应"); return false; }
		if(vecLine[6]!="Many"){Debug.Log("NiudanBase.csv中字段[Many]位置不对应"); return false; }
		if(vecLine[7]!="Free"){Debug.Log("NiudanBase.csv中字段[Free]位置不对应"); return false; }
		if(vecLine[8]!="Count"){Debug.Log("NiudanBase.csv中字段[Count]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)9)
			{
				return false;
			}
			NiudanBaseElement member = new NiudanBaseElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.NiudanID=Convert.ToInt32(vecLine[1]);
			member.Name=vecLine[2];
			member.XiaoHao=Convert.ToInt32(vecLine[3]);
			member.Num=Convert.ToInt32(vecLine[4]);
			member.ManyNum=Convert.ToInt32(vecLine[5]);
			member.Many=Convert.ToInt32(vecLine[6]);
			member.Free=Convert.ToInt32(vecLine[7]);
			member.Count=Convert.ToInt32(vecLine[8]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
