using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//星石附魔配置数据类
public class XingShiFuMoElement
{
	public int LV;               	//附魔等级	附魔等级
	public int Exp;              	//升级所需经验	升级所需经验
	public int Money;            	//金币	金币
	public int Dem;              	//钻石	钻石
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

	public bool IsValidate = false;
	public XingShiFuMoElement()
	{
		LV = -1;
	}
};

//星石附魔配置封装类
public class XingShiFuMoTable
{

	private XingShiFuMoTable()
	{
		m_mapElements = new Dictionary<int, XingShiFuMoElement>();
		m_emptyItem = new XingShiFuMoElement();
		m_vecAllElements = new List<XingShiFuMoElement>();
	}
	private Dictionary<int, XingShiFuMoElement> m_mapElements = null;
	private List<XingShiFuMoElement>	m_vecAllElements = null;
	private XingShiFuMoElement m_emptyItem = null;
	private static XingShiFuMoTable sInstance = null;

	public static XingShiFuMoTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new XingShiFuMoTable();
			return sInstance;
		}
	}

	public XingShiFuMoElement GetElement(int key)
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

  public List<XingShiFuMoElement> GetAllElement(Predicate<XingShiFuMoElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("XingShiFuMo.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("XingShiFuMo.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[XingShiFuMo.bin]未找到");
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
			Debug.Log("XingShiFuMo.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="LV"){Debug.Log("XingShiFuMo.csv中字段[LV]位置不对应"); return false; }
		if(vecLine[1]!="Exp"){Debug.Log("XingShiFuMo.csv中字段[Exp]位置不对应"); return false; }
		if(vecLine[2]!="Money"){Debug.Log("XingShiFuMo.csv中字段[Money]位置不对应"); return false; }
		if(vecLine[3]!="Dem"){Debug.Log("XingShiFuMo.csv中字段[Dem]位置不对应"); return false; }
		if(vecLine[4]!="Pattack"){Debug.Log("XingShiFuMo.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[5]!="Mattack"){Debug.Log("XingShiFuMo.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[6]!="PDefense"){Debug.Log("XingShiFuMo.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[7]!="MDefense"){Debug.Log("XingShiFuMo.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[8]!="HP"){Debug.Log("XingShiFuMo.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[9]!="Baoji"){Debug.Log("XingShiFuMo.csv中字段[Baoji]位置不对应"); return false; }
		if(vecLine[10]!="Bisha"){Debug.Log("XingShiFuMo.csv中字段[Bisha]位置不对应"); return false; }
		if(vecLine[11]!="MP"){Debug.Log("XingShiFuMo.csv中字段[MP]位置不对应"); return false; }
		if(vecLine[12]!="MpHuifu"){Debug.Log("XingShiFuMo.csv中字段[MpHuifu]位置不对应"); return false; }
		if(vecLine[13]!="Renxing"){Debug.Log("XingShiFuMo.csv中字段[Renxing]位置不对应"); return false; }
		if(vecLine[14]!="Shouhu"){Debug.Log("XingShiFuMo.csv中字段[Shouhu]位置不对应"); return false; }
		if(vecLine[15]!="HpHuifu"){Debug.Log("XingShiFuMo.csv中字段[HpHuifu]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			XingShiFuMoElement member = new XingShiFuMoElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.LV );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Exp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Money );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Dem );
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

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.LV] = member;
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
			Debug.Log("XingShiFuMo.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="LV"){Debug.Log("XingShiFuMo.csv中字段[LV]位置不对应"); return false; }
		if(vecLine[1]!="Exp"){Debug.Log("XingShiFuMo.csv中字段[Exp]位置不对应"); return false; }
		if(vecLine[2]!="Money"){Debug.Log("XingShiFuMo.csv中字段[Money]位置不对应"); return false; }
		if(vecLine[3]!="Dem"){Debug.Log("XingShiFuMo.csv中字段[Dem]位置不对应"); return false; }
		if(vecLine[4]!="Pattack"){Debug.Log("XingShiFuMo.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[5]!="Mattack"){Debug.Log("XingShiFuMo.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[6]!="PDefense"){Debug.Log("XingShiFuMo.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[7]!="MDefense"){Debug.Log("XingShiFuMo.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[8]!="HP"){Debug.Log("XingShiFuMo.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[9]!="Baoji"){Debug.Log("XingShiFuMo.csv中字段[Baoji]位置不对应"); return false; }
		if(vecLine[10]!="Bisha"){Debug.Log("XingShiFuMo.csv中字段[Bisha]位置不对应"); return false; }
		if(vecLine[11]!="MP"){Debug.Log("XingShiFuMo.csv中字段[MP]位置不对应"); return false; }
		if(vecLine[12]!="MpHuifu"){Debug.Log("XingShiFuMo.csv中字段[MpHuifu]位置不对应"); return false; }
		if(vecLine[13]!="Renxing"){Debug.Log("XingShiFuMo.csv中字段[Renxing]位置不对应"); return false; }
		if(vecLine[14]!="Shouhu"){Debug.Log("XingShiFuMo.csv中字段[Shouhu]位置不对应"); return false; }
		if(vecLine[15]!="HpHuifu"){Debug.Log("XingShiFuMo.csv中字段[HpHuifu]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)16)
			{
				return false;
			}
			XingShiFuMoElement member = new XingShiFuMoElement();
			member.LV=Convert.ToInt32(vecLine[0]);
			member.Exp=Convert.ToInt32(vecLine[1]);
			member.Money=Convert.ToInt32(vecLine[2]);
			member.Dem=Convert.ToInt32(vecLine[3]);
			member.Pattack=Convert.ToInt32(vecLine[4]);
			member.Mattack=Convert.ToInt32(vecLine[5]);
			member.PDefense=Convert.ToInt32(vecLine[6]);
			member.MDefense=Convert.ToInt32(vecLine[7]);
			member.HP=Convert.ToInt32(vecLine[8]);
			member.Baoji=Convert.ToInt32(vecLine[9]);
			member.Bisha=Convert.ToInt32(vecLine[10]);
			member.MP=Convert.ToInt32(vecLine[11]);
			member.MpHuifu=Convert.ToInt32(vecLine[12]);
			member.Renxing=Convert.ToInt32(vecLine[13]);
			member.Shouhu=Convert.ToInt32(vecLine[14]);
			member.HpHuifu=Convert.ToInt32(vecLine[15]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.LV] = member;
		}
		return true;
	}
};
