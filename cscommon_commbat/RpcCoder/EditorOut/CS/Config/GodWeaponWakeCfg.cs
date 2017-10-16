using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//神器觉醒配置数据类
public class GodWeaponWakeElement
{
	public int ID;               	//编号	神器ID
	public int ShenQiID;         	//神器ID	神器ID
	public int PinZhi;           	//神器品质	神器品质（1绿色2蓝色3红色4紫色5橙色）
	public int HP;               	//最大生命	最大生命
	public int Pattack;          	//物理攻击	物理攻击
	public int Mattack;          	//法术攻击	法术攻击
	public int PDefense;         	//物理防御	物理防御
	public int MDefense;         	//法术防御	法术防御
	public int Baoji;            	//暴击等级	暴击等级
	public int Bisha;            	//必杀等级	必杀等级
	public int MP;               	//魔法上限	魔法上限
	public int MpHuifu;          	//魔法恢复	魔法恢复
	public int Renxing;          	//韧性等级	韧性等级
	public int Shouhu;           	//守护等级	守护等级
	public int HpHuifu;          	//生命恢复	生命恢复
	public int JueXing;          	//觉醒所需道具	觉醒所需道具
	public int Num;              	//所需道具数量	所需道具数量

	public bool IsValidate = false;
	public GodWeaponWakeElement()
	{
		ID = -1;
	}
};

//神器觉醒配置封装类
public class GodWeaponWakeTable
{

	private GodWeaponWakeTable()
	{
		m_mapElements = new Dictionary<int, GodWeaponWakeElement>();
		m_emptyItem = new GodWeaponWakeElement();
		m_vecAllElements = new List<GodWeaponWakeElement>();
	}
	private Dictionary<int, GodWeaponWakeElement> m_mapElements = null;
	private List<GodWeaponWakeElement>	m_vecAllElements = null;
	private GodWeaponWakeElement m_emptyItem = null;
	private static GodWeaponWakeTable sInstance = null;

	public static GodWeaponWakeTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new GodWeaponWakeTable();
			return sInstance;
		}
	}

	public GodWeaponWakeElement GetElement(int key)
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

  public List<GodWeaponWakeElement> GetAllElement(Predicate<GodWeaponWakeElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("GodWeaponWake.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("GodWeaponWake.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[GodWeaponWake.bin]未找到");
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
		if(vecLine.Count != 17)
		{
			Debug.Log("GodWeaponWake.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("GodWeaponWake.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="ShenQiID"){Debug.Log("GodWeaponWake.csv中字段[ShenQiID]位置不对应"); return false; }
		if(vecLine[2]!="PinZhi"){Debug.Log("GodWeaponWake.csv中字段[PinZhi]位置不对应"); return false; }
		if(vecLine[3]!="HP"){Debug.Log("GodWeaponWake.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[4]!="Pattack"){Debug.Log("GodWeaponWake.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[5]!="Mattack"){Debug.Log("GodWeaponWake.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[6]!="PDefense"){Debug.Log("GodWeaponWake.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[7]!="MDefense"){Debug.Log("GodWeaponWake.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[8]!="Baoji"){Debug.Log("GodWeaponWake.csv中字段[Baoji]位置不对应"); return false; }
		if(vecLine[9]!="Bisha"){Debug.Log("GodWeaponWake.csv中字段[Bisha]位置不对应"); return false; }
		if(vecLine[10]!="MP"){Debug.Log("GodWeaponWake.csv中字段[MP]位置不对应"); return false; }
		if(vecLine[11]!="MpHuifu"){Debug.Log("GodWeaponWake.csv中字段[MpHuifu]位置不对应"); return false; }
		if(vecLine[12]!="Renxing"){Debug.Log("GodWeaponWake.csv中字段[Renxing]位置不对应"); return false; }
		if(vecLine[13]!="Shouhu"){Debug.Log("GodWeaponWake.csv中字段[Shouhu]位置不对应"); return false; }
		if(vecLine[14]!="HpHuifu"){Debug.Log("GodWeaponWake.csv中字段[HpHuifu]位置不对应"); return false; }
		if(vecLine[15]!="JueXing"){Debug.Log("GodWeaponWake.csv中字段[JueXing]位置不对应"); return false; }
		if(vecLine[16]!="Num"){Debug.Log("GodWeaponWake.csv中字段[Num]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			GodWeaponWakeElement member = new GodWeaponWakeElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ShenQiID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.PinZhi );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HP );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Pattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Mattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.PDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Baoji );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Bisha );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MP );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MpHuifu );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Renxing );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Shouhu );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HpHuifu );
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
		if(vecLine.Count != 17)
		{
			Debug.Log("GodWeaponWake.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("GodWeaponWake.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="ShenQiID"){Debug.Log("GodWeaponWake.csv中字段[ShenQiID]位置不对应"); return false; }
		if(vecLine[2]!="PinZhi"){Debug.Log("GodWeaponWake.csv中字段[PinZhi]位置不对应"); return false; }
		if(vecLine[3]!="HP"){Debug.Log("GodWeaponWake.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[4]!="Pattack"){Debug.Log("GodWeaponWake.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[5]!="Mattack"){Debug.Log("GodWeaponWake.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[6]!="PDefense"){Debug.Log("GodWeaponWake.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[7]!="MDefense"){Debug.Log("GodWeaponWake.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[8]!="Baoji"){Debug.Log("GodWeaponWake.csv中字段[Baoji]位置不对应"); return false; }
		if(vecLine[9]!="Bisha"){Debug.Log("GodWeaponWake.csv中字段[Bisha]位置不对应"); return false; }
		if(vecLine[10]!="MP"){Debug.Log("GodWeaponWake.csv中字段[MP]位置不对应"); return false; }
		if(vecLine[11]!="MpHuifu"){Debug.Log("GodWeaponWake.csv中字段[MpHuifu]位置不对应"); return false; }
		if(vecLine[12]!="Renxing"){Debug.Log("GodWeaponWake.csv中字段[Renxing]位置不对应"); return false; }
		if(vecLine[13]!="Shouhu"){Debug.Log("GodWeaponWake.csv中字段[Shouhu]位置不对应"); return false; }
		if(vecLine[14]!="HpHuifu"){Debug.Log("GodWeaponWake.csv中字段[HpHuifu]位置不对应"); return false; }
		if(vecLine[15]!="JueXing"){Debug.Log("GodWeaponWake.csv中字段[JueXing]位置不对应"); return false; }
		if(vecLine[16]!="Num"){Debug.Log("GodWeaponWake.csv中字段[Num]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)17)
			{
				return false;
			}
			GodWeaponWakeElement member = new GodWeaponWakeElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.ShenQiID=Convert.ToInt32(vecLine[1]);
			member.PinZhi=Convert.ToInt32(vecLine[2]);
			member.HP=Convert.ToInt32(vecLine[3]);
			member.Pattack=Convert.ToInt32(vecLine[4]);
			member.Mattack=Convert.ToInt32(vecLine[5]);
			member.PDefense=Convert.ToInt32(vecLine[6]);
			member.MDefense=Convert.ToInt32(vecLine[7]);
			member.Baoji=Convert.ToInt32(vecLine[8]);
			member.Bisha=Convert.ToInt32(vecLine[9]);
			member.MP=Convert.ToInt32(vecLine[10]);
			member.MpHuifu=Convert.ToInt32(vecLine[11]);
			member.Renxing=Convert.ToInt32(vecLine[12]);
			member.Shouhu=Convert.ToInt32(vecLine[13]);
			member.HpHuifu=Convert.ToInt32(vecLine[14]);
			member.JueXing=Convert.ToInt32(vecLine[15]);
			member.Num=Convert.ToInt32(vecLine[16]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
