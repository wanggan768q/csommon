using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//扩展AI配置数据类
public class ExpandAIElement
{
	public int expendAiId;       	//扩展AIID	扩展AIID
	public string Comment;       	//AI说明	AI具体描述(策划用字段，不会导出)
	public int aiGroup;          	//AI组	AI组，一个怪用一组扩展AI
	public int TriggerID;        	//触发器ID	索引触发器表
	public int seqTrigger;       	//顺序触发	顺序触发(-1非顺序，1顺序触发)
	public int times;            	//触发次数	触发次数(-1无限次数）
	public float eventRange;     	//事件范围	事件范围（表示逃跑距离、召唤半径）
	public int dialogId;         	//对话ID	对话ID
	public int HelpScope;        	//呼叫援护范围	呼叫援护的范围，以发出援护请求的目标点为中心，配置数据为半径做的圆
	public string HelpMonster;   	//呼叫援护对象	索引MonsterTable,填入的是MonsterID，可以填入多个，逗号分隔
	public int Order;            	//呼援是否为强制	1是，0否.如果为否，则目标只有处于待机状态下才会相应援护
	public int UseSkill;         	//触发指定技能	触发指定的技能
	public int JumpAI;           	//跳转AI	跳转到新的基础AIID上
	public int JumpNPC;          	//跳转NPC	转换为新的NPC
	public string SpecialEvent;  	//触发特殊事件	特殊事件直接写入接口名称
	public int EventProbability; 	//触发特殊事件概率	触发该特殊事件概率
	public int FleeSpeed;        	//逃跑速度	逃跑时的速度，单位m/s

	public bool IsValidate = false;
	public ExpandAIElement()
	{
		expendAiId = -1;
	}
};

//扩展AI配置封装类
public class ExpandAITable
{

	private ExpandAITable()
	{
		m_mapElements = new Dictionary<int, ExpandAIElement>();
		m_emptyItem = new ExpandAIElement();
		m_vecAllElements = new List<ExpandAIElement>();
	}
	private Dictionary<int, ExpandAIElement> m_mapElements = null;
	private List<ExpandAIElement>	m_vecAllElements = null;
	private ExpandAIElement m_emptyItem = null;
	private static ExpandAITable sInstance = null;

	public static ExpandAITable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ExpandAITable();
			return sInstance;
		}
	}

	public ExpandAIElement GetElement(int key)
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

  public List<ExpandAIElement> GetAllElement(Predicate<ExpandAIElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ExpandAI.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ExpandAI.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[ExpandAI.bin]未找到");
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
			Debug.Log("ExpandAI.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="expendAiId"){Debug.Log("ExpandAI.csv中字段[expendAiId]位置不对应"); return false; }
		if(vecLine[1]!="Comment"){Debug.Log("ExpandAI.csv中字段[Comment]位置不对应"); return false; }
		if(vecLine[2]!="aiGroup"){Debug.Log("ExpandAI.csv中字段[aiGroup]位置不对应"); return false; }
		if(vecLine[3]!="TriggerID"){Debug.Log("ExpandAI.csv中字段[TriggerID]位置不对应"); return false; }
		if(vecLine[4]!="seqTrigger"){Debug.Log("ExpandAI.csv中字段[seqTrigger]位置不对应"); return false; }
		if(vecLine[5]!="times"){Debug.Log("ExpandAI.csv中字段[times]位置不对应"); return false; }
		if(vecLine[6]!="eventRange"){Debug.Log("ExpandAI.csv中字段[eventRange]位置不对应"); return false; }
		if(vecLine[7]!="dialogId"){Debug.Log("ExpandAI.csv中字段[dialogId]位置不对应"); return false; }
		if(vecLine[8]!="HelpScope"){Debug.Log("ExpandAI.csv中字段[HelpScope]位置不对应"); return false; }
		if(vecLine[9]!="HelpMonster"){Debug.Log("ExpandAI.csv中字段[HelpMonster]位置不对应"); return false; }
		if(vecLine[10]!="Order"){Debug.Log("ExpandAI.csv中字段[Order]位置不对应"); return false; }
		if(vecLine[11]!="UseSkill"){Debug.Log("ExpandAI.csv中字段[UseSkill]位置不对应"); return false; }
		if(vecLine[12]!="JumpAI"){Debug.Log("ExpandAI.csv中字段[JumpAI]位置不对应"); return false; }
		if(vecLine[13]!="JumpNPC"){Debug.Log("ExpandAI.csv中字段[JumpNPC]位置不对应"); return false; }
		if(vecLine[14]!="SpecialEvent"){Debug.Log("ExpandAI.csv中字段[SpecialEvent]位置不对应"); return false; }
		if(vecLine[15]!="EventProbability"){Debug.Log("ExpandAI.csv中字段[EventProbability]位置不对应"); return false; }
		if(vecLine[16]!="FleeSpeed"){Debug.Log("ExpandAI.csv中字段[FleeSpeed]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ExpandAIElement member = new ExpandAIElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.expendAiId );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.aiGroup );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.TriggerID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.seqTrigger );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.times );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.eventRange);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dialogId );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HelpScope );
			readPos += GameAssist.ReadString( binContent, readPos, out member.HelpMonster);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Order );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.UseSkill );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.JumpAI );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.JumpNPC );
			readPos += GameAssist.ReadString( binContent, readPos, out member.SpecialEvent);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.EventProbability );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.FleeSpeed );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.expendAiId] = member;
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
			Debug.Log("ExpandAI.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="expendAiId"){Debug.Log("ExpandAI.csv中字段[expendAiId]位置不对应"); return false; }
		if(vecLine[1]!="Comment"){Debug.Log("ExpandAI.csv中字段[Comment]位置不对应"); return false; }
		if(vecLine[2]!="aiGroup"){Debug.Log("ExpandAI.csv中字段[aiGroup]位置不对应"); return false; }
		if(vecLine[3]!="TriggerID"){Debug.Log("ExpandAI.csv中字段[TriggerID]位置不对应"); return false; }
		if(vecLine[4]!="seqTrigger"){Debug.Log("ExpandAI.csv中字段[seqTrigger]位置不对应"); return false; }
		if(vecLine[5]!="times"){Debug.Log("ExpandAI.csv中字段[times]位置不对应"); return false; }
		if(vecLine[6]!="eventRange"){Debug.Log("ExpandAI.csv中字段[eventRange]位置不对应"); return false; }
		if(vecLine[7]!="dialogId"){Debug.Log("ExpandAI.csv中字段[dialogId]位置不对应"); return false; }
		if(vecLine[8]!="HelpScope"){Debug.Log("ExpandAI.csv中字段[HelpScope]位置不对应"); return false; }
		if(vecLine[9]!="HelpMonster"){Debug.Log("ExpandAI.csv中字段[HelpMonster]位置不对应"); return false; }
		if(vecLine[10]!="Order"){Debug.Log("ExpandAI.csv中字段[Order]位置不对应"); return false; }
		if(vecLine[11]!="UseSkill"){Debug.Log("ExpandAI.csv中字段[UseSkill]位置不对应"); return false; }
		if(vecLine[12]!="JumpAI"){Debug.Log("ExpandAI.csv中字段[JumpAI]位置不对应"); return false; }
		if(vecLine[13]!="JumpNPC"){Debug.Log("ExpandAI.csv中字段[JumpNPC]位置不对应"); return false; }
		if(vecLine[14]!="SpecialEvent"){Debug.Log("ExpandAI.csv中字段[SpecialEvent]位置不对应"); return false; }
		if(vecLine[15]!="EventProbability"){Debug.Log("ExpandAI.csv中字段[EventProbability]位置不对应"); return false; }
		if(vecLine[16]!="FleeSpeed"){Debug.Log("ExpandAI.csv中字段[FleeSpeed]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)17)
			{
				return false;
			}
			ExpandAIElement member = new ExpandAIElement();
			member.expendAiId=Convert.ToInt32(vecLine[0]);
			member.Comment=vecLine[1];
			member.aiGroup=Convert.ToInt32(vecLine[2]);
			member.TriggerID=Convert.ToInt32(vecLine[3]);
			member.seqTrigger=Convert.ToInt32(vecLine[4]);
			member.times=Convert.ToInt32(vecLine[5]);
			member.eventRange=Convert.ToSingle(vecLine[6]);
			member.dialogId=Convert.ToInt32(vecLine[7]);
			member.HelpScope=Convert.ToInt32(vecLine[8]);
			member.HelpMonster=vecLine[9];
			member.Order=Convert.ToInt32(vecLine[10]);
			member.UseSkill=Convert.ToInt32(vecLine[11]);
			member.JumpAI=Convert.ToInt32(vecLine[12]);
			member.JumpNPC=Convert.ToInt32(vecLine[13]);
			member.SpecialEvent=vecLine[14];
			member.EventProbability=Convert.ToInt32(vecLine[15]);
			member.FleeSpeed=Convert.ToInt32(vecLine[16]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.expendAiId] = member;
		}
		return true;
	}
};
