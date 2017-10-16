using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//物品配置数据类
public class ItemElement
{
	public int ItemID;           	//编号	物品ID
	public string Name;          	//物品名称	物品名称
	public int Bag;              	//所属背包	物品类型（1星石2碎片3消耗品）
	public string Type;          	//物品类别	物品类别
	public string SourceID;      	//Item的资源id	Item的资源id
	public int IsAdd;            	//是否可以累加	1可以 0不可以
	public int IsDel;            	//是否可以丢弃	1可以 0不可以
	public int IsSell;           	//是否可以买卖	0不可以 否则就是卖出的价钱
	public int IsBind;           	//是否绑定	1绑定0不绑定
	public int AddNum;           	//累加上限	累加上限
	public int Decompose;        	//分解	是否可分解
	public int DecomposeID;      	//分解道具	分解出的道具
	public int Nummin;           	//分解道具数量下限	分解道具数量下限
	public int Nummax;           	//分解道具数上下限	分解道具数量上限
	public int Price;            	//价格	分解价格
	public int Efect;            	//使用效果	使用效果
	public string Description;   	//物品描述	物品描述
	public int FuMoExp;          	//是否可附魔	是否可附魔
	public int Get1;             	//获取途径1(1、打副本2、充值3、钻石购买)	获取途径2
	public string GetNum1;       	//获取途径1参数	获取途径2参数
	public int Get2;             	//获取途径2	获取途径3
	public string GetNum2;       	//获取途径1参数	获取途径2参数
	public int Get3;             	//获取途径3	获取途径4
	public string GetNum3;       	//获取途径1参数	获取途径2参数

	public bool IsValidate = false;
	public ItemElement()
	{
		ItemID = -1;
	}
};

//物品配置封装类
public class ItemTable
{

	private ItemTable()
	{
		m_mapElements = new Dictionary<int, ItemElement>();
		m_emptyItem = new ItemElement();
		m_vecAllElements = new List<ItemElement>();
	}
	private Dictionary<int, ItemElement> m_mapElements = null;
	private List<ItemElement>	m_vecAllElements = null;
	private ItemElement m_emptyItem = null;
	private static ItemTable sInstance = null;

	public static ItemTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ItemTable();
			return sInstance;
		}
	}

	public ItemElement GetElement(int key)
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

  public List<ItemElement> GetAllElement(Predicate<ItemElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Item.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Item.bin", out binTableContent ) )
		{
			Debug.Log("配置文件[Item.bin]未找到");
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
		if(vecLine.Count != 24)
		{
			Debug.Log("Item.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ItemID"){Debug.Log("Item.csv中字段[ItemID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("Item.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="Bag"){Debug.Log("Item.csv中字段[Bag]位置不对应"); return false; }
		if(vecLine[3]!="Type"){Debug.Log("Item.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[4]!="SourceID"){Debug.Log("Item.csv中字段[SourceID]位置不对应"); return false; }
		if(vecLine[5]!="IsAdd"){Debug.Log("Item.csv中字段[IsAdd]位置不对应"); return false; }
		if(vecLine[6]!="IsDel"){Debug.Log("Item.csv中字段[IsDel]位置不对应"); return false; }
		if(vecLine[7]!="IsSell"){Debug.Log("Item.csv中字段[IsSell]位置不对应"); return false; }
		if(vecLine[8]!="IsBind"){Debug.Log("Item.csv中字段[IsBind]位置不对应"); return false; }
		if(vecLine[9]!="AddNum"){Debug.Log("Item.csv中字段[AddNum]位置不对应"); return false; }
		if(vecLine[10]!="Decompose"){Debug.Log("Item.csv中字段[Decompose]位置不对应"); return false; }
		if(vecLine[11]!="DecomposeID"){Debug.Log("Item.csv中字段[DecomposeID]位置不对应"); return false; }
		if(vecLine[12]!="Nummin"){Debug.Log("Item.csv中字段[Nummin]位置不对应"); return false; }
		if(vecLine[13]!="Nummax"){Debug.Log("Item.csv中字段[Nummax]位置不对应"); return false; }
		if(vecLine[14]!="Price"){Debug.Log("Item.csv中字段[Price]位置不对应"); return false; }
		if(vecLine[15]!="Efect"){Debug.Log("Item.csv中字段[Efect]位置不对应"); return false; }
		if(vecLine[16]!="Description"){Debug.Log("Item.csv中字段[Description]位置不对应"); return false; }
		if(vecLine[17]!="FuMoExp"){Debug.Log("Item.csv中字段[FuMoExp]位置不对应"); return false; }
		if(vecLine[18]!="Get1"){Debug.Log("Item.csv中字段[Get1]位置不对应"); return false; }
		if(vecLine[19]!="GetNum1"){Debug.Log("Item.csv中字段[GetNum1]位置不对应"); return false; }
		if(vecLine[20]!="Get2"){Debug.Log("Item.csv中字段[Get2]位置不对应"); return false; }
		if(vecLine[21]!="GetNum2"){Debug.Log("Item.csv中字段[GetNum2]位置不对应"); return false; }
		if(vecLine[22]!="Get3"){Debug.Log("Item.csv中字段[Get3]位置不对应"); return false; }
		if(vecLine[23]!="GetNum3"){Debug.Log("Item.csv中字段[GetNum3]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ItemElement member = new ItemElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ItemID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Name);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Bag );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Type);
			readPos += GameAssist.ReadString( binContent, readPos, out member.SourceID);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.IsAdd );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.IsDel );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.IsSell );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.IsBind );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.AddNum );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Decompose );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.DecomposeID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Nummin );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Nummax );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Price );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Efect );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Description);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.FuMoExp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Get1 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.GetNum1);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Get2 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.GetNum2);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Get3 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.GetNum3);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ItemID] = member;
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
		if(vecLine.Count != 24)
		{
			Debug.Log("Item.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ItemID"){Debug.Log("Item.csv中字段[ItemID]位置不对应"); return false; }
		if(vecLine[1]!="Name"){Debug.Log("Item.csv中字段[Name]位置不对应"); return false; }
		if(vecLine[2]!="Bag"){Debug.Log("Item.csv中字段[Bag]位置不对应"); return false; }
		if(vecLine[3]!="Type"){Debug.Log("Item.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[4]!="SourceID"){Debug.Log("Item.csv中字段[SourceID]位置不对应"); return false; }
		if(vecLine[5]!="IsAdd"){Debug.Log("Item.csv中字段[IsAdd]位置不对应"); return false; }
		if(vecLine[6]!="IsDel"){Debug.Log("Item.csv中字段[IsDel]位置不对应"); return false; }
		if(vecLine[7]!="IsSell"){Debug.Log("Item.csv中字段[IsSell]位置不对应"); return false; }
		if(vecLine[8]!="IsBind"){Debug.Log("Item.csv中字段[IsBind]位置不对应"); return false; }
		if(vecLine[9]!="AddNum"){Debug.Log("Item.csv中字段[AddNum]位置不对应"); return false; }
		if(vecLine[10]!="Decompose"){Debug.Log("Item.csv中字段[Decompose]位置不对应"); return false; }
		if(vecLine[11]!="DecomposeID"){Debug.Log("Item.csv中字段[DecomposeID]位置不对应"); return false; }
		if(vecLine[12]!="Nummin"){Debug.Log("Item.csv中字段[Nummin]位置不对应"); return false; }
		if(vecLine[13]!="Nummax"){Debug.Log("Item.csv中字段[Nummax]位置不对应"); return false; }
		if(vecLine[14]!="Price"){Debug.Log("Item.csv中字段[Price]位置不对应"); return false; }
		if(vecLine[15]!="Efect"){Debug.Log("Item.csv中字段[Efect]位置不对应"); return false; }
		if(vecLine[16]!="Description"){Debug.Log("Item.csv中字段[Description]位置不对应"); return false; }
		if(vecLine[17]!="FuMoExp"){Debug.Log("Item.csv中字段[FuMoExp]位置不对应"); return false; }
		if(vecLine[18]!="Get1"){Debug.Log("Item.csv中字段[Get1]位置不对应"); return false; }
		if(vecLine[19]!="GetNum1"){Debug.Log("Item.csv中字段[GetNum1]位置不对应"); return false; }
		if(vecLine[20]!="Get2"){Debug.Log("Item.csv中字段[Get2]位置不对应"); return false; }
		if(vecLine[21]!="GetNum2"){Debug.Log("Item.csv中字段[GetNum2]位置不对应"); return false; }
		if(vecLine[22]!="Get3"){Debug.Log("Item.csv中字段[Get3]位置不对应"); return false; }
		if(vecLine[23]!="GetNum3"){Debug.Log("Item.csv中字段[GetNum3]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)24)
			{
				return false;
			}
			ItemElement member = new ItemElement();
			member.ItemID=Convert.ToInt32(vecLine[0]);
			member.Name=vecLine[1];
			member.Bag=Convert.ToInt32(vecLine[2]);
			member.Type=vecLine[3];
			member.SourceID=vecLine[4];
			member.IsAdd=Convert.ToInt32(vecLine[5]);
			member.IsDel=Convert.ToInt32(vecLine[6]);
			member.IsSell=Convert.ToInt32(vecLine[7]);
			member.IsBind=Convert.ToInt32(vecLine[8]);
			member.AddNum=Convert.ToInt32(vecLine[9]);
			member.Decompose=Convert.ToInt32(vecLine[10]);
			member.DecomposeID=Convert.ToInt32(vecLine[11]);
			member.Nummin=Convert.ToInt32(vecLine[12]);
			member.Nummax=Convert.ToInt32(vecLine[13]);
			member.Price=Convert.ToInt32(vecLine[14]);
			member.Efect=Convert.ToInt32(vecLine[15]);
			member.Description=vecLine[16];
			member.FuMoExp=Convert.ToInt32(vecLine[17]);
			member.Get1=Convert.ToInt32(vecLine[18]);
			member.GetNum1=vecLine[19];
			member.Get2=Convert.ToInt32(vecLine[20]);
			member.GetNum2=vecLine[21];
			member.Get3=Convert.ToInt32(vecLine[22]);
			member.GetNum3=vecLine[23];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ItemID] = member;
		}
		return true;
	}
};
