using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//神器配置数据类
public class GodWeaponElement
{
	public int ID;               	//编号	神器ID
	public string Name;          	//神器名称	神器名称
	public string NameJuexing;   	//觉醒后的名称	觉醒后的名称
	public string SourceID;      	//神器的资源	神器的资源
	public string SourceJuexing; 	//觉醒后的资源	觉醒后的资源
	public int Hero;             	//所属英雄ID	所属英雄ID
	public string Attr;          	//所拥有的属性	所拥有的属性
	public int Pattack;          	//物理攻击	物理攻击
	public int Mattack;          	//法术攻击	法术攻击
	public int PDefense;         	//物理防御	物理防御
	public int MDefense;         	//法术防御	法术防御
	public int HP;               	//最大生命	最大生命
	public int Baoji;            	//暴击等级	暴击等级
	public int Bisha;            	//必杀等级	必杀等级
	public int MP;               	//魔法上限	魔法上限
	public int MpHuifu;          	//魔法恢复	魔法恢复
	public int Renxing;          	//韧性等级	韧性等级
	public int Shouhu;           	//守护等级	守护等级
	public int HpHuifu;          	//生命恢复	生命恢复
	public int Attr1;            	//解锁属性1	解锁属性1
	public int Attr2;            	//解锁属性2	解锁属性2
	public int Attr3;            	//解锁属性3	解锁属性3
	public int Attr4;            	//解锁属性4	解锁属性4

	public bool IsValidate = false;
	public GodWeaponElement()
	{
		ID = -1;
	}
};

//神器配置封装类
public class GodWeaponTable
{

	private GodWeaponTable()
	{
		m_mapElements = new Dictionary<int, GodWeaponElement>();
		m_emptyItem = new GodWeaponElement();
		m_vecAllElements = new List<GodWeaponElement>();
	}
	private Dictionary<int, GodWeaponElement> m_mapElements = null;
	private List<GodWeaponElement>	m_vecAllElements = null;
	private GodWeaponElement m_emptyItem = null;
	private static GodWeaponTable sInstance = null;

	public static GodWeaponTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new GodWeaponTable();
			return sInstance;
		}
	}

	public GodWeaponElement GetElement(int key)
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

  public List<GodWeaponElement> GetAllElement(Predicate<GodWeaponElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("GodWeapon.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("GodWeapon.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[GodWeapon.bin]未找到");
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
			Debug.Log("GodWeapon.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("GodWeapon.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("GodWeapon.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="NameJuexing"){Debug.Log("GodWeapon.csv中字段[NameJuexing]位置不对应"); return false; }
		if(vecLine[3]!="SourceID"){Debug.Log("GodWeapon.csv中字段[SourceID]位置不对应"); return false; }
		if(vecLine[4]!="SourceJuexing"){Debug.Log("GodWeapon.csv中字段[SourceJuexing]位置不对应"); return false; }
		if(vecLine[5]!="Hero"){Debug.Log("GodWeapon.csv中字段[Hero]位置不对应"); return false; }
		if(vecLine[6]!="Attr"){Debug.Log("GodWeapon.csv中字段[Attr]位置不对应"); return false; }
		if(vecLine[7]!="Pattack"){Debug.Log("GodWeapon.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[8]!="Mattack"){Debug.Log("GodWeapon.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[9]!="PDefense"){Debug.Log("GodWeapon.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[10]!="MDefense"){Debug.Log("GodWeapon.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[11]!="HP"){Debug.Log("GodWeapon.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[12]!="Baoji"){Debug.Log("GodWeapon.csv中字段[Baoji]位置不对应"); return false; }
		if(vecLine[13]!="Bisha"){Debug.Log("GodWeapon.csv中字段[Bisha]位置不对应"); return false; }
		if(vecLine[14]!="MP"){Debug.Log("GodWeapon.csv中字段[MP]位置不对应"); return false; }
		if(vecLine[15]!="MpHuifu"){Debug.Log("GodWeapon.csv中字段[MpHuifu]位置不对应"); return false; }
		if(vecLine[16]!="Renxing"){Debug.Log("GodWeapon.csv中字段[Renxing]位置不对应"); return false; }
		if(vecLine[17]!="Shouhu"){Debug.Log("GodWeapon.csv中字段[Shouhu]位置不对应"); return false; }
		if(vecLine[18]!="HpHuifu"){Debug.Log("GodWeapon.csv中字段[HpHuifu]位置不对应"); return false; }
		if(vecLine[19]!="Attr1"){Debug.Log("GodWeapon.csv中字段[Attr1]位置不对应"); return false; }
		if(vecLine[20]!="Attr2"){Debug.Log("GodWeapon.csv中字段[Attr2]位置不对应"); return false; }
		if(vecLine[21]!="Attr3"){Debug.Log("GodWeapon.csv中字段[Attr3]位置不对应"); return false; }
		if(vecLine[22]!="Attr4"){Debug.Log("GodWeapon.csv中字段[Attr4]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			GodWeaponElement member = new GodWeaponElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.NameJuexing);
			readPos += GameAssist.ReadString( binContent, readPos, out member.SourceID);
			readPos += GameAssist.ReadString( binContent, readPos, out member.SourceJuexing);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Hero );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Attr);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Pattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Mattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.PDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HP );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Baoji );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Bisha );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MP );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MpHuifu );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Renxing );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Shouhu );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HpHuifu );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Attr1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Attr2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Attr3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Attr4 );

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
		if(vecLine.Count != 23)
		{
			Debug.Log("GodWeapon.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("GodWeapon.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("GodWeapon.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="NameJuexing"){Debug.Log("GodWeapon.csv中字段[NameJuexing]位置不对应"); return false; }
		if(vecLine[3]!="SourceID"){Debug.Log("GodWeapon.csv中字段[SourceID]位置不对应"); return false; }
		if(vecLine[4]!="SourceJuexing"){Debug.Log("GodWeapon.csv中字段[SourceJuexing]位置不对应"); return false; }
		if(vecLine[5]!="Hero"){Debug.Log("GodWeapon.csv中字段[Hero]位置不对应"); return false; }
		if(vecLine[6]!="Attr"){Debug.Log("GodWeapon.csv中字段[Attr]位置不对应"); return false; }
		if(vecLine[7]!="Pattack"){Debug.Log("GodWeapon.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[8]!="Mattack"){Debug.Log("GodWeapon.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[9]!="PDefense"){Debug.Log("GodWeapon.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[10]!="MDefense"){Debug.Log("GodWeapon.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[11]!="HP"){Debug.Log("GodWeapon.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[12]!="Baoji"){Debug.Log("GodWeapon.csv中字段[Baoji]位置不对应"); return false; }
		if(vecLine[13]!="Bisha"){Debug.Log("GodWeapon.csv中字段[Bisha]位置不对应"); return false; }
		if(vecLine[14]!="MP"){Debug.Log("GodWeapon.csv中字段[MP]位置不对应"); return false; }
		if(vecLine[15]!="MpHuifu"){Debug.Log("GodWeapon.csv中字段[MpHuifu]位置不对应"); return false; }
		if(vecLine[16]!="Renxing"){Debug.Log("GodWeapon.csv中字段[Renxing]位置不对应"); return false; }
		if(vecLine[17]!="Shouhu"){Debug.Log("GodWeapon.csv中字段[Shouhu]位置不对应"); return false; }
		if(vecLine[18]!="HpHuifu"){Debug.Log("GodWeapon.csv中字段[HpHuifu]位置不对应"); return false; }
		if(vecLine[19]!="Attr1"){Debug.Log("GodWeapon.csv中字段[Attr1]位置不对应"); return false; }
		if(vecLine[20]!="Attr2"){Debug.Log("GodWeapon.csv中字段[Attr2]位置不对应"); return false; }
		if(vecLine[21]!="Attr3"){Debug.Log("GodWeapon.csv中字段[Attr3]位置不对应"); return false; }
		if(vecLine[22]!="Attr4"){Debug.Log("GodWeapon.csv中字段[Attr4]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)23)
			{
				return false;
			}
			GodWeaponElement member = new GodWeaponElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.Name=vecLine[1];
			member.NameJuexing=vecLine[2];
			member.SourceID=vecLine[3];
			member.SourceJuexing=vecLine[4];
			member.Hero=Convert.ToInt32(vecLine[5]);
			member.Attr=vecLine[6];
			member.Pattack=Convert.ToInt32(vecLine[7]);
			member.Mattack=Convert.ToInt32(vecLine[8]);
			member.PDefense=Convert.ToInt32(vecLine[9]);
			member.MDefense=Convert.ToInt32(vecLine[10]);
			member.HP=Convert.ToInt32(vecLine[11]);
			member.Baoji=Convert.ToInt32(vecLine[12]);
			member.Bisha=Convert.ToInt32(vecLine[13]);
			member.MP=Convert.ToInt32(vecLine[14]);
			member.MpHuifu=Convert.ToInt32(vecLine[15]);
			member.Renxing=Convert.ToInt32(vecLine[16]);
			member.Shouhu=Convert.ToInt32(vecLine[17]);
			member.HpHuifu=Convert.ToInt32(vecLine[18]);
			member.Attr1=Convert.ToInt32(vecLine[19]);
			member.Attr2=Convert.ToInt32(vecLine[20]);
			member.Attr3=Convert.ToInt32(vecLine[21]);
			member.Attr4=Convert.ToInt32(vecLine[22]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
