using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//武圣配置数据类
public class WuShengElement
{
	public int ID;               	//编号	物品ID
	public int LvLimit;          	//官阶名称	等级上限
	public int EXP;              	//经验参数1	经验参数2
	public float CanShu;         	//经验参数1	经验参数2
	public float Pattack;        	//物理攻击	物理攻击
	public float Mattack;        	//法术攻击	法术攻击
	public float PDefense;       	//物理防御	物理防御
	public float MDefense;       	//法术防御	法术防御
	public float HP;             	//最大生命	最大生命

	public bool IsValidate = false;
	public WuShengElement()
	{
		ID = -1;
	}
};

//武圣配置封装类
public class WuShengTable
{

	private WuShengTable()
	{
		m_mapElements = new Dictionary<int, WuShengElement>();
		m_emptyItem = new WuShengElement();
		m_vecAllElements = new List<WuShengElement>();
	}
	private Dictionary<int, WuShengElement> m_mapElements = null;
	private List<WuShengElement>	m_vecAllElements = null;
	private WuShengElement m_emptyItem = null;
	private static WuShengTable sInstance = null;

	public static WuShengTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new WuShengTable();
			return sInstance;
		}
	}

	public WuShengElement GetElement(int key)
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

  public List<WuShengElement> GetAllElement(Predicate<WuShengElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("WuSheng.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("WuSheng.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[WuSheng.bin]未找到");
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
			Debug.Log("WuSheng.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("WuSheng.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="LvLimit"){Debug.Log("WuSheng.csv中字段[LvLimit]位置不对应"); return false; }
		if(vecLine[2]!="EXP"){Debug.Log("WuSheng.csv中字段[EXP]位置不对应"); return false; }
		if(vecLine[3]!="CanShu"){Debug.Log("WuSheng.csv中字段[CanShu]位置不对应"); return false; }
		if(vecLine[4]!="Pattack"){Debug.Log("WuSheng.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[5]!="Mattack"){Debug.Log("WuSheng.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[6]!="PDefense"){Debug.Log("WuSheng.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[7]!="MDefense"){Debug.Log("WuSheng.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[8]!="HP"){Debug.Log("WuSheng.csv中字段[HP]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			WuShengElement member = new WuShengElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.LvLimit );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.EXP );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.CanShu);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.Pattack);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.Mattack);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.PDefense);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.MDefense);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.HP);

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
			Debug.Log("WuSheng.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("WuSheng.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="LvLimit"){Debug.Log("WuSheng.csv中字段[LvLimit]位置不对应"); return false; }
		if(vecLine[2]!="EXP"){Debug.Log("WuSheng.csv中字段[EXP]位置不对应"); return false; }
		if(vecLine[3]!="CanShu"){Debug.Log("WuSheng.csv中字段[CanShu]位置不对应"); return false; }
		if(vecLine[4]!="Pattack"){Debug.Log("WuSheng.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[5]!="Mattack"){Debug.Log("WuSheng.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[6]!="PDefense"){Debug.Log("WuSheng.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[7]!="MDefense"){Debug.Log("WuSheng.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[8]!="HP"){Debug.Log("WuSheng.csv中字段[HP]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)9)
			{
				return false;
			}
			WuShengElement member = new WuShengElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.LvLimit=Convert.ToInt32(vecLine[1]);
			member.EXP=Convert.ToInt32(vecLine[2]);
			member.CanShu=Convert.ToSingle(vecLine[3]);
			member.Pattack=Convert.ToSingle(vecLine[4]);
			member.Mattack=Convert.ToSingle(vecLine[5]);
			member.PDefense=Convert.ToSingle(vecLine[6]);
			member.MDefense=Convert.ToSingle(vecLine[7]);
			member.HP=Convert.ToSingle(vecLine[8]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
