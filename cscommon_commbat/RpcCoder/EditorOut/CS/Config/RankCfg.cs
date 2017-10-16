using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//官阶配置数据类
public class RankElement
{
	public int RankID;           	//编号	物品ID
	public string Name;          	//官阶名称	官阶名称
	public string SourceID;      	//Rank的资源id	Rank的资源id
	public int WantRank;         	//功勋	升级所需功勋
	public int NEXT;             	//下一级官阶	下一级官阶ID
	public int RewardMoney;      	//奖励	官阶奖励游戏币
	public int HP;               	//最大生命	最大生命
	public int Pattack;          	//物理攻击	物理攻击
	public int Mattack;          	//法术攻击	法术攻击
	public int PDefense;         	//物理防御	物理防御
	public int MDefense;         	//法术防御	法术防御

	public bool IsValidate = false;
	public RankElement()
	{
		RankID = -1;
	}
};

//官阶配置封装类
public class RankTable
{

	private RankTable()
	{
		m_mapElements = new Dictionary<int, RankElement>();
		m_emptyItem = new RankElement();
		m_vecAllElements = new List<RankElement>();
	}
	private Dictionary<int, RankElement> m_mapElements = null;
	private List<RankElement>	m_vecAllElements = null;
	private RankElement m_emptyItem = null;
	private static RankTable sInstance = null;

	public static RankTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new RankTable();
			return sInstance;
		}
	}

	public RankElement GetElement(int key)
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

  public List<RankElement> GetAllElement(Predicate<RankElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Rank.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Rank.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[Rank.bin]未找到");
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
			Debug.Log("Rank.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="RankID"){Debug.Log("Rank.csv中字段[RankID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("Rank.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="SourceID"){Debug.Log("Rank.csv中字段[SourceID]位置不对应"); return false; }
		if(vecLine[3]!="WantRank"){Debug.Log("Rank.csv中字段[WantRank]位置不对应"); return false; }
		if(vecLine[4]!="NEXT"){Debug.Log("Rank.csv中字段[NEXT]位置不对应"); return false; }
		if(vecLine[5]!="RewardMoney"){Debug.Log("Rank.csv中字段[RewardMoney]位置不对应"); return false; }
		if(vecLine[6]!="HP"){Debug.Log("Rank.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[7]!="Pattack"){Debug.Log("Rank.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[8]!="Mattack"){Debug.Log("Rank.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[9]!="PDefense"){Debug.Log("Rank.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[10]!="MDefense"){Debug.Log("Rank.csv中字段[MDefense]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			RankElement member = new RankElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.RankID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.SourceID);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.WantRank );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.NEXT );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.RewardMoney );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HP );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Pattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Mattack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.PDefense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.MDefense );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.RankID] = member;
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
			Debug.Log("Rank.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="RankID"){Debug.Log("Rank.csv中字段[RankID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("Rank.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="SourceID"){Debug.Log("Rank.csv中字段[SourceID]位置不对应"); return false; }
		if(vecLine[3]!="WantRank"){Debug.Log("Rank.csv中字段[WantRank]位置不对应"); return false; }
		if(vecLine[4]!="NEXT"){Debug.Log("Rank.csv中字段[NEXT]位置不对应"); return false; }
		if(vecLine[5]!="RewardMoney"){Debug.Log("Rank.csv中字段[RewardMoney]位置不对应"); return false; }
		if(vecLine[6]!="HP"){Debug.Log("Rank.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[7]!="Pattack"){Debug.Log("Rank.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[8]!="Mattack"){Debug.Log("Rank.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[9]!="PDefense"){Debug.Log("Rank.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[10]!="MDefense"){Debug.Log("Rank.csv中字段[MDefense]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)11)
			{
				return false;
			}
			RankElement member = new RankElement();
			member.RankID=Convert.ToInt32(vecLine[0]);
			member.Name=vecLine[1];
			member.SourceID=vecLine[2];
			member.WantRank=Convert.ToInt32(vecLine[3]);
			member.NEXT=Convert.ToInt32(vecLine[4]);
			member.RewardMoney=Convert.ToInt32(vecLine[5]);
			member.HP=Convert.ToInt32(vecLine[6]);
			member.Pattack=Convert.ToInt32(vecLine[7]);
			member.Mattack=Convert.ToInt32(vecLine[8]);
			member.PDefense=Convert.ToInt32(vecLine[9]);
			member.MDefense=Convert.ToInt32(vecLine[10]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.RankID] = member;
		}
		return true;
	}
};
