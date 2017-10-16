using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//英雄配置数据类
public class HeroElement
{
	public int Hero;             	//编号	编号
	public string Name;          	//名称	名称
	public string Res;           	//	
	public int Type;             	//英雄类型（1力量2敏捷3智力4耐力5辅助）	英雄类型（1力量2敏捷3智力4耐力6辅助）
	public int Colour;           	//初始颜色	初始颜色（1白2绿3蓝4紫5橙6红）
	public int Star;             	//初始星级	初始星级
	public int Suipian;          	//升星碎片	升星碎片
	public int Num;              	//合成所需碎片数量	合成所需碎片数量
	public int Skill1;           	//普通攻击1	普通攻击1
	public int Skill2;           	//普通攻击2	普通攻击2
	public int Skill3;           	//普通攻击3	普通攻击3
	public int Skill4;           	//小技能1	小技能1
	public int Skill5;           	//小技能2	小技能2
	public int Skill6;           	//大技能	大技能
	public int Skill7;           	//大技能觉醒	大技能觉醒
	public int Skill8;           	//合体技	合体技
	public int Skill9;           	//被动	被动
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
	public HeroElement()
	{
		Hero = -1;
	}
};

//英雄配置封装类
public class HeroTable
{

	private HeroTable()
	{
		m_mapElements = new Dictionary<int, HeroElement>();
		m_emptyItem = new HeroElement();
		m_vecAllElements = new List<HeroElement>();
	}
	private Dictionary<int, HeroElement> m_mapElements = null;
	private List<HeroElement>	m_vecAllElements = null;
	private HeroElement m_emptyItem = null;
	private static HeroTable sInstance = null;

	public static HeroTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new HeroTable();
			return sInstance;
		}
	}

	public HeroElement GetElement(int key)
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

  public List<HeroElement> GetAllElement(Predicate<HeroElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Hero.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Hero.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[Hero.bin]未找到");
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
		if(vecLine.Count != 29)
		{
			Debug.Log("Hero.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="Hero"){Debug.Log("Hero.csv中字段[Hero]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("Hero.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="Res"){Debug.Log("Hero.csv中字段[Res]位置不对应"); return false; }
		if(vecLine[3]!="Type"){Debug.Log("Hero.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[4]!="Colour"){Debug.Log("Hero.csv中字段[Colour]位置不对应"); return false; }
		if(vecLine[5]!="Star"){Debug.Log("Hero.csv中字段[Star]位置不对应"); return false; }
		if(vecLine[6]!="Suipian"){Debug.Log("Hero.csv中字段[Suipian]位置不对应"); return false; }
		if(vecLine[7]!="Num"){Debug.Log("Hero.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[8]!="Skill1"){Debug.Log("Hero.csv中字段[Skill1]位置不对应"); return false; }
		if(vecLine[9]!="Skill2"){Debug.Log("Hero.csv中字段[Skill2]位置不对应"); return false; }
		if(vecLine[10]!="Skill3"){Debug.Log("Hero.csv中字段[Skill3]位置不对应"); return false; }
		if(vecLine[11]!="Skill4"){Debug.Log("Hero.csv中字段[Skill4]位置不对应"); return false; }
		if(vecLine[12]!="Skill5"){Debug.Log("Hero.csv中字段[Skill5]位置不对应"); return false; }
		if(vecLine[13]!="Skill6"){Debug.Log("Hero.csv中字段[Skill6]位置不对应"); return false; }
		if(vecLine[14]!="Skill7"){Debug.Log("Hero.csv中字段[Skill7]位置不对应"); return false; }
		if(vecLine[15]!="Skill8"){Debug.Log("Hero.csv中字段[Skill8]位置不对应"); return false; }
		if(vecLine[16]!="Skill9"){Debug.Log("Hero.csv中字段[Skill9]位置不对应"); return false; }
		if(vecLine[17]!="Pattack"){Debug.Log("Hero.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[18]!="Mattack"){Debug.Log("Hero.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[19]!="PDefense"){Debug.Log("Hero.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[20]!="MDefense"){Debug.Log("Hero.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[21]!="HP"){Debug.Log("Hero.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[22]!="Baoji"){Debug.Log("Hero.csv中字段[Baoji]位置不对应"); return false; }
		if(vecLine[23]!="Bisha"){Debug.Log("Hero.csv中字段[Bisha]位置不对应"); return false; }
		if(vecLine[24]!="MP"){Debug.Log("Hero.csv中字段[MP]位置不对应"); return false; }
		if(vecLine[25]!="MpHuifu"){Debug.Log("Hero.csv中字段[MpHuifu]位置不对应"); return false; }
		if(vecLine[26]!="Renxing"){Debug.Log("Hero.csv中字段[Renxing]位置不对应"); return false; }
		if(vecLine[27]!="Shouhu"){Debug.Log("Hero.csv中字段[Shouhu]位置不对应"); return false; }
		if(vecLine[28]!="HpHuifu"){Debug.Log("Hero.csv中字段[HpHuifu]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			HeroElement member = new HeroElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Hero );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.Res);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Colour );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Star );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Suipian );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill5 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill6 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill7 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill8 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Skill9 );
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
			m_mapElements[member.Hero] = member;
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
		if(vecLine.Count != 29)
		{
			Debug.Log("Hero.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="Hero"){Debug.Log("Hero.csv中字段[Hero]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("Hero.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="Res"){Debug.Log("Hero.csv中字段[Res]位置不对应"); return false; }
		if(vecLine[3]!="Type"){Debug.Log("Hero.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[4]!="Colour"){Debug.Log("Hero.csv中字段[Colour]位置不对应"); return false; }
		if(vecLine[5]!="Star"){Debug.Log("Hero.csv中字段[Star]位置不对应"); return false; }
		if(vecLine[6]!="Suipian"){Debug.Log("Hero.csv中字段[Suipian]位置不对应"); return false; }
		if(vecLine[7]!="Num"){Debug.Log("Hero.csv中字段[Num]位置不对应"); return false; }
		if(vecLine[8]!="Skill1"){Debug.Log("Hero.csv中字段[Skill1]位置不对应"); return false; }
		if(vecLine[9]!="Skill2"){Debug.Log("Hero.csv中字段[Skill2]位置不对应"); return false; }
		if(vecLine[10]!="Skill3"){Debug.Log("Hero.csv中字段[Skill3]位置不对应"); return false; }
		if(vecLine[11]!="Skill4"){Debug.Log("Hero.csv中字段[Skill4]位置不对应"); return false; }
		if(vecLine[12]!="Skill5"){Debug.Log("Hero.csv中字段[Skill5]位置不对应"); return false; }
		if(vecLine[13]!="Skill6"){Debug.Log("Hero.csv中字段[Skill6]位置不对应"); return false; }
		if(vecLine[14]!="Skill7"){Debug.Log("Hero.csv中字段[Skill7]位置不对应"); return false; }
		if(vecLine[15]!="Skill8"){Debug.Log("Hero.csv中字段[Skill8]位置不对应"); return false; }
		if(vecLine[16]!="Skill9"){Debug.Log("Hero.csv中字段[Skill9]位置不对应"); return false; }
		if(vecLine[17]!="Pattack"){Debug.Log("Hero.csv中字段[Pattack]位置不对应"); return false; }
		if(vecLine[18]!="Mattack"){Debug.Log("Hero.csv中字段[Mattack]位置不对应"); return false; }
		if(vecLine[19]!="PDefense"){Debug.Log("Hero.csv中字段[PDefense]位置不对应"); return false; }
		if(vecLine[20]!="MDefense"){Debug.Log("Hero.csv中字段[MDefense]位置不对应"); return false; }
		if(vecLine[21]!="HP"){Debug.Log("Hero.csv中字段[HP]位置不对应"); return false; }
		if(vecLine[22]!="Baoji"){Debug.Log("Hero.csv中字段[Baoji]位置不对应"); return false; }
		if(vecLine[23]!="Bisha"){Debug.Log("Hero.csv中字段[Bisha]位置不对应"); return false; }
		if(vecLine[24]!="MP"){Debug.Log("Hero.csv中字段[MP]位置不对应"); return false; }
		if(vecLine[25]!="MpHuifu"){Debug.Log("Hero.csv中字段[MpHuifu]位置不对应"); return false; }
		if(vecLine[26]!="Renxing"){Debug.Log("Hero.csv中字段[Renxing]位置不对应"); return false; }
		if(vecLine[27]!="Shouhu"){Debug.Log("Hero.csv中字段[Shouhu]位置不对应"); return false; }
		if(vecLine[28]!="HpHuifu"){Debug.Log("Hero.csv中字段[HpHuifu]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)29)
			{
				return false;
			}
			HeroElement member = new HeroElement();
			member.Hero=Convert.ToInt32(vecLine[0]);
			member.Name=vecLine[1];
			member.Res=vecLine[2];
			member.Type=Convert.ToInt32(vecLine[3]);
			member.Colour=Convert.ToInt32(vecLine[4]);
			member.Star=Convert.ToInt32(vecLine[5]);
			member.Suipian=Convert.ToInt32(vecLine[6]);
			member.Num=Convert.ToInt32(vecLine[7]);
			member.Skill1=Convert.ToInt32(vecLine[8]);
			member.Skill2=Convert.ToInt32(vecLine[9]);
			member.Skill3=Convert.ToInt32(vecLine[10]);
			member.Skill4=Convert.ToInt32(vecLine[11]);
			member.Skill5=Convert.ToInt32(vecLine[12]);
			member.Skill6=Convert.ToInt32(vecLine[13]);
			member.Skill7=Convert.ToInt32(vecLine[14]);
			member.Skill8=Convert.ToInt32(vecLine[15]);
			member.Skill9=Convert.ToInt32(vecLine[16]);
			member.Pattack=Convert.ToInt32(vecLine[17]);
			member.Mattack=Convert.ToInt32(vecLine[18]);
			member.PDefense=Convert.ToInt32(vecLine[19]);
			member.MDefense=Convert.ToInt32(vecLine[20]);
			member.HP=Convert.ToInt32(vecLine[21]);
			member.Baoji=Convert.ToInt32(vecLine[22]);
			member.Bisha=Convert.ToInt32(vecLine[23]);
			member.MP=Convert.ToInt32(vecLine[24]);
			member.MpHuifu=Convert.ToInt32(vecLine[25]);
			member.Renxing=Convert.ToInt32(vecLine[26]);
			member.Shouhu=Convert.ToInt32(vecLine[27]);
			member.HpHuifu=Convert.ToInt32(vecLine[28]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.Hero] = member;
		}
		return true;
	}
};
