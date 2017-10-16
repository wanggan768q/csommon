using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//触发器表配置数据类
public class TriggerElement
{
	public int TriggerID;        	//陷阱ID	编号
	public int TriggerType;      	//触发器类型	触发器的类型（1.当前血量小于等于某个数额 2.当前血量低于总血量的某个百分比 3.当怪物所在的地图内的玩家挂有某个任务的时候 4.当怪物警戒范围内的玩家使用某个技能的时候 5.当怪物警戒范围内的玩家在聊天窗中打出某几个字的时候 6.当玩家与怪物的距离低于多少米的时候 7.当同屏范围的怪物使用某个技能的时候 8.当怪物的战斗时间长于多少秒后 9.当当前节点进行到多少秒后 10.当玩家血量低于总血量的某个百分比）
	public string TriggerParameter;	//触发器参数	触发器的参数，由类型确定参数

	public bool IsValidate = false;
	public TriggerElement()
	{
		TriggerID = -1;
	}
};

//触发器表配置封装类
public class TriggerTable
{

	private TriggerTable()
	{
		m_mapElements = new Dictionary<int, TriggerElement>();
		m_emptyItem = new TriggerElement();
		m_vecAllElements = new List<TriggerElement>();
	}
	private Dictionary<int, TriggerElement> m_mapElements = null;
	private List<TriggerElement>	m_vecAllElements = null;
	private TriggerElement m_emptyItem = null;
	private static TriggerTable sInstance = null;

	public static TriggerTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new TriggerTable();
			return sInstance;
		}
	}

	public TriggerElement GetElement(int key)
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

  public List<TriggerElement> GetAllElement(Predicate<TriggerElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Trigger.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Trigger.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[Trigger.bin]未找到");
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
		if(vecLine.Count != 3)
		{
			Debug.Log("Trigger.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="TriggerID"){Debug.Log("Trigger.csv中字段[TriggerID]位置不对应"); return false; }
		if(vecLine[1]!="TriggerType"){Debug.Log("Trigger.csv中字段[TriggerType]位置不对应"); return false; }
		if(vecLine[2]!="TriggerParameter"){Debug.Log("Trigger.csv中字段[TriggerParameter]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			TriggerElement member = new TriggerElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.TriggerID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.TriggerType );
			readPos += GameAssist.ReadString( binContent, readPos, out member.TriggerParameter);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.TriggerID] = member;
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
		if(vecLine.Count != 3)
		{
			Debug.Log("Trigger.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="TriggerID"){Debug.Log("Trigger.csv中字段[TriggerID]位置不对应"); return false; }
		if(vecLine[1]!="TriggerType"){Debug.Log("Trigger.csv中字段[TriggerType]位置不对应"); return false; }
		if(vecLine[2]!="TriggerParameter"){Debug.Log("Trigger.csv中字段[TriggerParameter]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)3)
			{
				return false;
			}
			TriggerElement member = new TriggerElement();
			member.TriggerID=Convert.ToInt32(vecLine[0]);
			member.TriggerType=Convert.ToInt32(vecLine[1]);
			member.TriggerParameter=vecLine[2];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.TriggerID] = member;
		}
		return true;
	}
};
