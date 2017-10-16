using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//战力参数配置数据类
public class MilitaryElement
{
	public int ID;               	//编号	ID
	public float Pattack;        	//物理攻击	物理攻击
	public float Mattack;        	//法术攻击	法术攻击
	public float PDefense;       	//物理防御	物理防御
	public float MDefense;       	//法术防御	法术防御
	public float HP;             	//最大生命	最大生命
	public float Baoji;          	//暴击等级	暴击等级
	public float Bisha;          	//必杀等级	必杀等级
	public float MP;             	//魔法上限	魔法上限
	public float MpHuifu;        	//魔法恢复	魔法恢复
	public float Renxing;        	//韧性等级	韧性等级
	public float Shouhu;         	//守护等级	守护等级
	public float HpHuifu;        	//生命恢复	生命恢复
	public float Skilllevel;     	//技能等级	技能等级

	public bool IsValidate = false;
	public MilitaryElement()
	{
		ID = -1;
	}
};

//战力参数配置封装类
public class MilitaryTable
{

	private MilitaryTable()
	{
		m_mapElements = new Dictionary<int, MilitaryElement>();
		m_emptyItem = new MilitaryElement();
		m_vecAllElements = new List<MilitaryElement>();
	}
	private Dictionary<int, MilitaryElement> m_mapElements = null;
	private List<MilitaryElement>	m_vecAllElements = null;
	private MilitaryElement m_emptyItem = null;
	private static MilitaryTable sInstance = null;

	public static MilitaryTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new MilitaryTable();
			return sInstance;
		}
	}

	public MilitaryElement GetElement(int key)
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

  public List<MilitaryElement> GetAllElement(Predicate<MilitaryElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Military.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Military.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[Military.bin]未找到");
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
			Debug.Log("Military.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("Military.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="Pattack"){Debug.Log("Military.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[2]!="Mattack"){Debug.Log("Military.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[3]!="PDefense"){Debug.Log("Military.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[4]!="MDefense"){Debug.Log("Military.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[5]!="HP"){Debug.Log("Military.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[6]!="Baoji"){Debug.Log("Military.csv中字段[Baoji]位置不对应"); return false; }
		if(vecLine[7]!="Bisha"){Debug.Log("Military.csv中字段[Bisha]位置不对应"); return false; }
		if(vecLine[8]!="MP"){Debug.Log("Military.csv中字段[MP]位置不对应"); return false; }
		if(vecLine[9]!="MpHuifu"){Debug.Log("Military.csv中字段[MpHuifu]位置不对应"); return false; }
		if(vecLine[10]!="Renxing"){Debug.Log("Military.csv中字段[Renxing]位置不对应"); return false; }
		if(vecLine[11]!="Shouhu"){Debug.Log("Military.csv中字段[Shouhu]位置不对应"); return false; }
		if(vecLine[12]!="HpHuifu"){Debug.Log("Military.csv中字段[HpHuifu]位置不对应"); return false; }
		if(vecLine[13]!="Skilllevel"){Debug.Log("Military.csv中字段[Skilllevel]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			MilitaryElement member = new MilitaryElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.Pattack);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.Mattack);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.PDefense);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.MDefense);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.HP);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.Baoji);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.Bisha);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.MP);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.MpHuifu);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.Renxing);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.Shouhu);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.HpHuifu);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.Skilllevel);

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
			Debug.Log("Military.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Debug.Log("Military.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="Pattack"){Debug.Log("Military.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[2]!="Mattack"){Debug.Log("Military.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[3]!="PDefense"){Debug.Log("Military.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[4]!="MDefense"){Debug.Log("Military.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[5]!="HP"){Debug.Log("Military.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[6]!="Baoji"){Debug.Log("Military.csv中字段[Baoji]位置不对应"); return false; }
		if(vecLine[7]!="Bisha"){Debug.Log("Military.csv中字段[Bisha]位置不对应"); return false; }
		if(vecLine[8]!="MP"){Debug.Log("Military.csv中字段[MP]位置不对应"); return false; }
		if(vecLine[9]!="MpHuifu"){Debug.Log("Military.csv中字段[MpHuifu]位置不对应"); return false; }
		if(vecLine[10]!="Renxing"){Debug.Log("Military.csv中字段[Renxing]位置不对应"); return false; }
		if(vecLine[11]!="Shouhu"){Debug.Log("Military.csv中字段[Shouhu]位置不对应"); return false; }
		if(vecLine[12]!="HpHuifu"){Debug.Log("Military.csv中字段[HpHuifu]位置不对应"); return false; }
		if(vecLine[13]!="Skilllevel"){Debug.Log("Military.csv中字段[Skilllevel]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)14)
			{
				return false;
			}
			MilitaryElement member = new MilitaryElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.Pattack=Convert.ToSingle(vecLine[1]);
			member.Mattack=Convert.ToSingle(vecLine[2]);
			member.PDefense=Convert.ToSingle(vecLine[3]);
			member.MDefense=Convert.ToSingle(vecLine[4]);
			member.HP=Convert.ToSingle(vecLine[5]);
			member.Baoji=Convert.ToSingle(vecLine[6]);
			member.Bisha=Convert.ToSingle(vecLine[7]);
			member.MP=Convert.ToSingle(vecLine[8]);
			member.MpHuifu=Convert.ToSingle(vecLine[9]);
			member.Renxing=Convert.ToSingle(vecLine[10]);
			member.Shouhu=Convert.ToSingle(vecLine[11]);
			member.HpHuifu=Convert.ToSingle(vecLine[12]);
			member.Skilllevel=Convert.ToSingle(vecLine[13]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
