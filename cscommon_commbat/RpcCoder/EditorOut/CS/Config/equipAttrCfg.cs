using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备属性配置数据类
public class equipAttrElement
{
	public int AttrID;           	//编号	属性ID
	public int Type;             	//对应属性类别	对应属性类别（1物理攻击2法术攻击3物理防御4法术防御5最大生命6魔法上限7暴击等级8必杀等级9魔法恢复10韧性等级11守护等级12生命恢复）
	public int CanShu1;          	//进化1	参数A（AX+CY+B，x强化等级，y升星等级），两个个小数点
	public int CanShu2;          	//进化1	参数B，两个小数点
	public int CanShu3;          	//进化1	参数C，两个小数点
	public int CanShu4;          	//进化2	参数A
	public int CanShu5;          	//进化2	参数B
	public int CanShu6;          	//进化2	参数C
	public int CanShu7;          	//进化3	参数A
	public int CanShu8;          	//进化3	参数B
	public int CanShu9;          	//进化3	参数C
	public int CanShu10;         	//进化4	参数A
	public int CanShu11;         	//进化4	参数B
	public int CanShu12;         	//进化4	参数C
	public int CanShu13;         	//进化5	参数A
	public int CanShu14;         	//进化5	参数B
	public int CanShu15;         	//进化5	参数C
	public int CanShu16;         	//进化6	参数A
	public int CanShu17;         	//进化6	参数B
	public int CanShu18;         	//进化6	参数C
	public int CanShu19;         	//进化7	参数A
	public int CanShu20;         	//进化7	参数B
	public int CanShu21;         	//进化7	参数C

	public bool IsValidate = false;
	public equipAttrElement()
	{
		AttrID = -1;
	}
};

//装备属性配置封装类
public class equipAttrTable
{

	private equipAttrTable()
	{
		m_mapElements = new Dictionary<int, equipAttrElement>();
		m_emptyItem = new equipAttrElement();
		m_vecAllElements = new List<equipAttrElement>();
	}
	private Dictionary<int, equipAttrElement> m_mapElements = null;
	private List<equipAttrElement>	m_vecAllElements = null;
	private equipAttrElement m_emptyItem = null;
	private static equipAttrTable sInstance = null;

	public static equipAttrTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new equipAttrTable();
			return sInstance;
		}
	}

	public equipAttrElement GetElement(int key)
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

  public List<equipAttrElement> GetAllElement(Predicate<equipAttrElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("equipAttr.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("equipAttr.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[equipAttr.bin]未找到");
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
		if(vecLine.Count != 23)
		{
			Debug.Log("equipAttr.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="AttrID"){Debug.Log("equipAttr.csv中字段[AttrID]位置不对应"); return false; }
		if(vecLine[1]!="Type"){Debug.Log("equipAttr.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[2]!="CanShu1"){Debug.Log("equipAttr.csv中字段[CanShu1]位置不对应"); return false; }
		if(vecLine[3]!="CanShu2"){Debug.Log("equipAttr.csv中字段[CanShu2]位置不对应"); return false; }
		if(vecLine[4]!="CanShu3"){Debug.Log("equipAttr.csv中字段[CanShu3]位置不对应"); return false; }
		if(vecLine[5]!="CanShu4"){Debug.Log("equipAttr.csv中字段[CanShu4]位置不对应"); return false; }
		if(vecLine[6]!="CanShu5"){Debug.Log("equipAttr.csv中字段[CanShu5]位置不对应"); return false; }
		if(vecLine[7]!="CanShu6"){Debug.Log("equipAttr.csv中字段[CanShu6]位置不对应"); return false; }
		if(vecLine[8]!="CanShu7"){Debug.Log("equipAttr.csv中字段[CanShu7]位置不对应"); return false; }
		if(vecLine[9]!="CanShu8"){Debug.Log("equipAttr.csv中字段[CanShu8]位置不对应"); return false; }
		if(vecLine[10]!="CanShu9"){Debug.Log("equipAttr.csv中字段[CanShu9]位置不对应"); return false; }
		if(vecLine[11]!="CanShu10"){Debug.Log("equipAttr.csv中字段[CanShu10]位置不对应"); return false; }
		if(vecLine[12]!="CanShu11"){Debug.Log("equipAttr.csv中字段[CanShu11]位置不对应"); return false; }
		if(vecLine[13]!="CanShu12"){Debug.Log("equipAttr.csv中字段[CanShu12]位置不对应"); return false; }
		if(vecLine[14]!="CanShu13"){Debug.Log("equipAttr.csv中字段[CanShu13]位置不对应"); return false; }
		if(vecLine[15]!="CanShu14"){Debug.Log("equipAttr.csv中字段[CanShu14]位置不对应"); return false; }
		if(vecLine[16]!="CanShu15"){Debug.Log("equipAttr.csv中字段[CanShu15]位置不对应"); return false; }
		if(vecLine[17]!="CanShu16"){Debug.Log("equipAttr.csv中字段[CanShu16]位置不对应"); return false; }
		if(vecLine[18]!="CanShu17"){Debug.Log("equipAttr.csv中字段[CanShu17]位置不对应"); return false; }
		if(vecLine[19]!="CanShu18"){Debug.Log("equipAttr.csv中字段[CanShu18]位置不对应"); return false; }
		if(vecLine[20]!="CanShu19"){Debug.Log("equipAttr.csv中字段[CanShu19]位置不对应"); return false; }
		if(vecLine[21]!="CanShu20"){Debug.Log("equipAttr.csv中字段[CanShu20]位置不对应"); return false; }
		if(vecLine[22]!="CanShu21"){Debug.Log("equipAttr.csv中字段[CanShu21]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			equipAttrElement member = new equipAttrElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.AttrID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu5 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu6 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu7 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu8 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu9 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu10 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu11 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu12 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu13 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu14 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu15 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu16 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu17 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu18 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu19 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu20 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CanShu21 );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.AttrID] = member;
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
		if(vecLine.Count != 23)
		{
			Debug.Log("equipAttr.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="AttrID"){Debug.Log("equipAttr.csv中字段[AttrID]位置不对应"); return false; }
		if(vecLine[1]!="Type"){Debug.Log("equipAttr.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[2]!="CanShu1"){Debug.Log("equipAttr.csv中字段[CanShu1]位置不对应"); return false; }
		if(vecLine[3]!="CanShu2"){Debug.Log("equipAttr.csv中字段[CanShu2]位置不对应"); return false; }
		if(vecLine[4]!="CanShu3"){Debug.Log("equipAttr.csv中字段[CanShu3]位置不对应"); return false; }
		if(vecLine[5]!="CanShu4"){Debug.Log("equipAttr.csv中字段[CanShu4]位置不对应"); return false; }
		if(vecLine[6]!="CanShu5"){Debug.Log("equipAttr.csv中字段[CanShu5]位置不对应"); return false; }
		if(vecLine[7]!="CanShu6"){Debug.Log("equipAttr.csv中字段[CanShu6]位置不对应"); return false; }
		if(vecLine[8]!="CanShu7"){Debug.Log("equipAttr.csv中字段[CanShu7]位置不对应"); return false; }
		if(vecLine[9]!="CanShu8"){Debug.Log("equipAttr.csv中字段[CanShu8]位置不对应"); return false; }
		if(vecLine[10]!="CanShu9"){Debug.Log("equipAttr.csv中字段[CanShu9]位置不对应"); return false; }
		if(vecLine[11]!="CanShu10"){Debug.Log("equipAttr.csv中字段[CanShu10]位置不对应"); return false; }
		if(vecLine[12]!="CanShu11"){Debug.Log("equipAttr.csv中字段[CanShu11]位置不对应"); return false; }
		if(vecLine[13]!="CanShu12"){Debug.Log("equipAttr.csv中字段[CanShu12]位置不对应"); return false; }
		if(vecLine[14]!="CanShu13"){Debug.Log("equipAttr.csv中字段[CanShu13]位置不对应"); return false; }
		if(vecLine[15]!="CanShu14"){Debug.Log("equipAttr.csv中字段[CanShu14]位置不对应"); return false; }
		if(vecLine[16]!="CanShu15"){Debug.Log("equipAttr.csv中字段[CanShu15]位置不对应"); return false; }
		if(vecLine[17]!="CanShu16"){Debug.Log("equipAttr.csv中字段[CanShu16]位置不对应"); return false; }
		if(vecLine[18]!="CanShu17"){Debug.Log("equipAttr.csv中字段[CanShu17]位置不对应"); return false; }
		if(vecLine[19]!="CanShu18"){Debug.Log("equipAttr.csv中字段[CanShu18]位置不对应"); return false; }
		if(vecLine[20]!="CanShu19"){Debug.Log("equipAttr.csv中字段[CanShu19]位置不对应"); return false; }
		if(vecLine[21]!="CanShu20"){Debug.Log("equipAttr.csv中字段[CanShu20]位置不对应"); return false; }
		if(vecLine[22]!="CanShu21"){Debug.Log("equipAttr.csv中字段[CanShu21]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)23)
			{
				return false;
			}
			equipAttrElement member = new equipAttrElement();
			member.AttrID=Convert.ToInt32(vecLine[0]);
			member.Type=Convert.ToInt32(vecLine[1]);
			member.CanShu1=Convert.ToInt32(vecLine[2]);
			member.CanShu2=Convert.ToInt32(vecLine[3]);
			member.CanShu3=Convert.ToInt32(vecLine[4]);
			member.CanShu4=Convert.ToInt32(vecLine[5]);
			member.CanShu5=Convert.ToInt32(vecLine[6]);
			member.CanShu6=Convert.ToInt32(vecLine[7]);
			member.CanShu7=Convert.ToInt32(vecLine[8]);
			member.CanShu8=Convert.ToInt32(vecLine[9]);
			member.CanShu9=Convert.ToInt32(vecLine[10]);
			member.CanShu10=Convert.ToInt32(vecLine[11]);
			member.CanShu11=Convert.ToInt32(vecLine[12]);
			member.CanShu12=Convert.ToInt32(vecLine[13]);
			member.CanShu13=Convert.ToInt32(vecLine[14]);
			member.CanShu14=Convert.ToInt32(vecLine[15]);
			member.CanShu15=Convert.ToInt32(vecLine[16]);
			member.CanShu16=Convert.ToInt32(vecLine[17]);
			member.CanShu17=Convert.ToInt32(vecLine[18]);
			member.CanShu18=Convert.ToInt32(vecLine[19]);
			member.CanShu19=Convert.ToInt32(vecLine[20]);
			member.CanShu20=Convert.ToInt32(vecLine[21]);
			member.CanShu21=Convert.ToInt32(vecLine[22]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.AttrID] = member;
		}
		return true;
	}
};
