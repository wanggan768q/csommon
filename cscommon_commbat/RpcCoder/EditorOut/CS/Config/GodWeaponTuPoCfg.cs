using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//神器觉醒突破配置数据类
public class GodWeaponTuPoElement
{
	public int ID;               	//编号	神器ID
	public int ShenQiID;         	//神器ID	神器ID
	public int TuPo;             	//品质突破	品质突破
	public int HP;               	//最大生命	最大生命
	public int Pattack;          	//物理攻击	物理攻击
	public int Mattack;          	//法术攻击	法术攻击
	public int PDefense;         	//物理防御	物理防御
	public int MDefense;         	//法术防御	法术防御
	public int JueXing;          	//觉醒所需专属道具	觉醒所需专属道具
	public int Num;              	//所需道具数量	所需道具数量

	public bool IsValidate = false;
	public GodWeaponTuPoElement()
	{
		ID = -1;
	}
};

//神器觉醒突破配置封装类
public class GodWeaponTuPoTable
{

	private GodWeaponTuPoTable()
	{
		m_mapElements = new Dictionary<int, GodWeaponTuPoElement>();
		m_emptyItem = new GodWeaponTuPoElement();
		m_vecAllElements = new List<GodWeaponTuPoElement>();
	}
	private Dictionary<int, GodWeaponTuPoElement> m_mapElements = null;
	private List<GodWeaponTuPoElement>	m_vecAllElements = null;
	private GodWeaponTuPoElement m_emptyItem = null;
	private static GodWeaponTuPoTable sInstance = null;

	public static GodWeaponTuPoTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new GodWeaponTuPoTable();
			return sInstance;
		}
	}

	public GodWeaponTuPoElement GetElement(int key)
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

  public List<GodWeaponTuPoElement> GetAllElement(Predicate<GodWeaponTuPoElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("GodWeaponTuPo.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("GodWeaponTuPo.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[GodWeaponTuPo.bin]未找到");
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
		if(vecLine.Count != 10)
		{
			Debug.Log("GodWeaponTuPo.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("GodWeaponTuPo.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="ShenQiID"){Debug.Log("GodWeaponTuPo.csv中字段[ShenQiID]位置不对应"); return false; }
		if(vecLine[2]!="TuPo"){Debug.Log("GodWeaponTuPo.csv中字段[TuPo]位置不对应"); return false; }
		if(vecLine[3]!="HP"){Debug.Log("GodWeaponTuPo.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[4]!="Pattack"){Debug.Log("GodWeaponTuPo.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[5]!="Mattack"){Debug.Log("GodWeaponTuPo.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[6]!="PDefense"){Debug.Log("GodWeaponTuPo.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[7]!="MDefense"){Debug.Log("GodWeaponTuPo.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[8]!="JueXing"){Debug.Log("GodWeaponTuPo.csv中字段[JueXing]位置不对应"); return false; }
		if(vecLine[9]!="Num"){Debug.Log("GodWeaponTuPo.csv中字段[Num]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			GodWeaponTuPoElement member = new GodWeaponTuPoElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ShenQiID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.TuPo );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HP );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Pattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Mattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.PDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.JueXing );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num );

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
		if(vecLine.Count != 10)
		{
			Debug.Log("GodWeaponTuPo.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("GodWeaponTuPo.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="ShenQiID"){Debug.Log("GodWeaponTuPo.csv中字段[ShenQiID]位置不对应"); return false; }
		if(vecLine[2]!="TuPo"){Debug.Log("GodWeaponTuPo.csv中字段[TuPo]位置不对应"); return false; }
		if(vecLine[3]!="HP"){Debug.Log("GodWeaponTuPo.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[4]!="Pattack"){Debug.Log("GodWeaponTuPo.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[5]!="Mattack"){Debug.Log("GodWeaponTuPo.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[6]!="PDefense"){Debug.Log("GodWeaponTuPo.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[7]!="MDefense"){Debug.Log("GodWeaponTuPo.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[8]!="JueXing"){Debug.Log("GodWeaponTuPo.csv中字段[JueXing]位置不对应"); return false; }
		if(vecLine[9]!="Num"){Debug.Log("GodWeaponTuPo.csv中字段[Num]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)10)
			{
				return false;
			}
			GodWeaponTuPoElement member = new GodWeaponTuPoElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.ShenQiID=Convert.ToInt32(vecLine[1]);
			member.TuPo=Convert.ToInt32(vecLine[2]);
			member.HP=Convert.ToInt32(vecLine[3]);
			member.Pattack=Convert.ToInt32(vecLine[4]);
			member.Mattack=Convert.ToInt32(vecLine[5]);
			member.PDefense=Convert.ToInt32(vecLine[6]);
			member.MDefense=Convert.ToInt32(vecLine[7]);
			member.JueXing=Convert.ToInt32(vecLine[8]);
			member.Num=Convert.ToInt32(vecLine[9]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
