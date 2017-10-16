using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//星石配置数据类
public class XingshiElement
{
	public int ID;               	//编号	星石ID
	public string Name;          	//星石名称	星石名称
	public int XingShiType;      	//类型	星石类型（装备的星石位置）
	public int Colour;           	//颜色	等级
	public string Res;           	//资源	资源
	public int Attr1;            	//属性1	属性1类别
	public int Num1;             	//属性1值	属性1值
	public int Attr2;            	//属性2	属性2类别
	public int Num2;             	//属性2	属性2值
	public int Price;            	//价格	价格
	public int AddNum;           	//累加上限	最大叠加数
	public int Exp;              	//附魔经验	附魔提供经验
	public int Max;              	//附魔等级上限	附魔等级上限
	public int Limit;            	//穿戴等级限制	穿戴等级限制

	public bool IsValidate = false;
	public XingshiElement()
	{
		ID = -1;
	}
};

//星石配置封装类
public class XingshiTable
{

	private XingshiTable()
	{
		m_mapElements = new Dictionary<int, XingshiElement>();
		m_emptyItem = new XingshiElement();
		m_vecAllElements = new List<XingshiElement>();
	}
	private Dictionary<int, XingshiElement> m_mapElements = null;
	private List<XingshiElement>	m_vecAllElements = null;
	private XingshiElement m_emptyItem = null;
	private static XingshiTable sInstance = null;

	public static XingshiTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new XingshiTable();
			return sInstance;
		}
	}

	public XingshiElement GetElement(int key)
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

  public List<XingshiElement> GetAllElement(Predicate<XingshiElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Xingshi.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Xingshi.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[Xingshi.bin]未找到");
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
			Debug.Log("Xingshi.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("Xingshi.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("Xingshi.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="XingShiType"){Debug.Log("Xingshi.csv中字段[XingShiType]位置不对应"); return false; }
		if(vecLine[3]!="Colour"){Debug.Log("Xingshi.csv中字段[Colour]位置不对应"); return false; }
		if(vecLine[4]!="Res"){Debug.Log("Xingshi.csv中字段[Res]位置不对应"); return false; }
		if(vecLine[5]!="Attr1"){Debug.Log("Xingshi.csv中字段[Attr1]位置不对应"); return false; }
		if(vecLine[6]!="Num1"){Debug.Log("Xingshi.csv中字段[Num1]位置不对应"); return false; }
		if(vecLine[7]!="Attr2"){Debug.Log("Xingshi.csv中字段[Attr2]位置不对应"); return false; }
		if(vecLine[8]!="Num2"){Debug.Log("Xingshi.csv中字段[Num2]位置不对应"); return false; }
		if(vecLine[9]!="Price"){Debug.Log("Xingshi.csv中字段[Price]位置不对应"); return false; }
		if(vecLine[10]!="AddNum"){Debug.Log("Xingshi.csv中字段[AddNum]位置不对应"); return false; }
		if(vecLine[11]!="Exp"){Debug.Log("Xingshi.csv中字段[Exp]位置不对应"); return false; }
		if(vecLine[12]!="Max"){Debug.Log("Xingshi.csv中字段[Max]位置不对应"); return false; }
		if(vecLine[13]!="Limit"){Debug.Log("Xingshi.csv中字段[Limit]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			XingshiElement member = new XingshiElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.XingShiType );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Colour );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Res);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Attr1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Attr2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Price );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.AddNum );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Exp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Max );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Limit );

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
		if(vecLine.Count != 14)
		{
			Debug.Log("Xingshi.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("Xingshi.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("Xingshi.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="XingShiType"){Debug.Log("Xingshi.csv中字段[XingShiType]位置不对应"); return false; }
		if(vecLine[3]!="Colour"){Debug.Log("Xingshi.csv中字段[Colour]位置不对应"); return false; }
		if(vecLine[4]!="Res"){Debug.Log("Xingshi.csv中字段[Res]位置不对应"); return false; }
		if(vecLine[5]!="Attr1"){Debug.Log("Xingshi.csv中字段[Attr1]位置不对应"); return false; }
		if(vecLine[6]!="Num1"){Debug.Log("Xingshi.csv中字段[Num1]位置不对应"); return false; }
		if(vecLine[7]!="Attr2"){Debug.Log("Xingshi.csv中字段[Attr2]位置不对应"); return false; }
		if(vecLine[8]!="Num2"){Debug.Log("Xingshi.csv中字段[Num2]位置不对应"); return false; }
		if(vecLine[9]!="Price"){Debug.Log("Xingshi.csv中字段[Price]位置不对应"); return false; }
		if(vecLine[10]!="AddNum"){Debug.Log("Xingshi.csv中字段[AddNum]位置不对应"); return false; }
		if(vecLine[11]!="Exp"){Debug.Log("Xingshi.csv中字段[Exp]位置不对应"); return false; }
		if(vecLine[12]!="Max"){Debug.Log("Xingshi.csv中字段[Max]位置不对应"); return false; }
		if(vecLine[13]!="Limit"){Debug.Log("Xingshi.csv中字段[Limit]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)14)
			{
				return false;
			}
			XingshiElement member = new XingshiElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.Name=vecLine[1];
			member.XingShiType=Convert.ToInt32(vecLine[2]);
			member.Colour=Convert.ToInt32(vecLine[3]);
			member.Res=vecLine[4];
			member.Attr1=Convert.ToInt32(vecLine[5]);
			member.Num1=Convert.ToInt32(vecLine[6]);
			member.Attr2=Convert.ToInt32(vecLine[7]);
			member.Num2=Convert.ToInt32(vecLine[8]);
			member.Price=Convert.ToInt32(vecLine[9]);
			member.AddNum=Convert.ToInt32(vecLine[10]);
			member.Exp=Convert.ToInt32(vecLine[11]);
			member.Max=Convert.ToInt32(vecLine[12]);
			member.Limit=Convert.ToInt32(vecLine[13]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
