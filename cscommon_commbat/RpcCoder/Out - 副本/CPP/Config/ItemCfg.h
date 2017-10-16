#ifndef __ITEM_CONFIG_H
#define __ITEM_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//物品脜盲脰脙脢媒戮脻陆谩鹿鹿
struct ItemElement
{
	friend class ItemTable;
	int ItemID;                  	//编号	物品ID
	string Name;                 	//物品名称	物品名称
	string Type;                 	//物品类别	物品类别
	int FenLei;                  	//物品细分类别	0无细分需求、1技能书2、副本增加次数3回复药4状态药5召唤帮主6偷窃帮会资金7帮会破坏8多开礼包9单开礼包99货币
	string FenLeiParameter;      	//参数	使用后的效果，对应前面分类，技能书对应技能ID，使用后可增加次数填写数字
	int Cishu;                   	//使用次数限制	使用次数限制
	int Time;                    	//使用时间	单位毫秒
	int Timeliness;              	//时效性	道具使用次数限制的时间0无限制1天2周
	string SourceID;             	//Item的资源id	Item的资源id
	int LV;                      	//等级	等级
	int Colour;                  	//初始品质	初始品质（1白色2绿色3蓝色4紫色5橙色6红色7真）
	int ShiYong;                 	//是否可使用	是否可使用
	int HeCheng;                 	//是否可合成	是否可合成
	int IsSell;                  	//是否可以买卖	0不可以 否则就是卖出的价钱
	int ZiDong;                  	//是否可自动使用	是否可自动使用
	int IsBind;                  	//是否绑定	1绑定0不绑定
	int IsAdd;                   	//是否可以累加	1可以 0不可以
	int AddNum;                  	//累加上限	累加上限
	int Price;                   	//价格	分解价格
	int IsDel;                   	//是否可以回收	1可以 0不可以
	int DelPrice;                	//回收价格	回收价格
	int BuyPrick;                	//取回价格	取回价格
	string MiaoShu;              	//物品描述	物品描述
	string BeiZhu;               	//物品备注	物品备注
	int  Valuabl;                	//是否为珍贵物品	是否为珍贵物品
	int ModelId;                 	//模型ID	模型ID
	string EffectID;             	//模型动画	模型动画
	int Mission;                 	//关联任务ID	关联任务ID
	int Skill;                   	//动作ID	动作ID
	float ItenR;                 	//触发半径	触发半径

private:
	bool m_bIsValidate;
	void SetIsValidate(bool isValid)
	{
		m_bIsValidate=isValid;
	}
public:
	bool IsValidate()
	{
		return m_bIsValidate;
	}
	ItemElement()
	{
		ItemID = -1;
		m_bIsValidate=false;
	}
};

//物品脜盲脰脙路芒脳掳脌脿
class ItemTable
{
	friend class TableData;
private:
	ItemTable(){}
	~ItemTable(){}
	map<int, ItemElement>	m_mapElements;
	vector<ItemElement>	m_vecAllElements;
	ItemElement m_emptyItem;
public:
	static ItemTable& Instance()
	{
		static ItemTable sInstance;
		return sInstance;
	}

	ItemElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ItemElement>&	GetAllElement()
	{
		if(!m_vecAllElements.empty()) 
			return m_vecAllElements;
		m_vecAllElements.reserve(m_mapElements.size());
		for(auto iter=m_mapElements.begin(); iter != m_mapElements.end(); ++iter)
		{
			if(iter->second.IsValidate()) 
				m_vecAllElements.push_back(iter->second);
		}
		return m_vecAllElements;
	}
	bool Load()
	{
		#ifdef CONFIG_JSON
		return LoadJson("Item.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Item.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Item.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Item.bin]脦麓脮脪碌陆");
			assert(false);
			return false;
		}
		return LoadBin(strTableContent);
		#endif

		
	}

	bool LoadJson(const std::string& jsonFile)
	{
		boost::property_tree::ptree parse;
		boost::property_tree::json_parser::read_json(std::string(CONFIG_PATH) + jsonFile, parse);
		boost::property_tree::ptree sms_array = parse.get_child("data");

		vector<string> vecLine;

				if(vecLine[0]!="ItemID"){printf_message("Item.csv中字段[ItemID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Item.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Type"){printf_message("Item.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[3]!="FenLei"){printf_message("Item.csv中字段[FenLei]位置不对应");assert(false); return false; }
		if(vecLine[4]!="FenLeiParameter"){printf_message("Item.csv中字段[FenLeiParameter]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Cishu"){printf_message("Item.csv中字段[Cishu]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Time"){printf_message("Item.csv中字段[Time]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Timeliness"){printf_message("Item.csv中字段[Timeliness]位置不对应");assert(false); return false; }
		if(vecLine[8]!="SourceID"){printf_message("Item.csv中字段[SourceID]位置不对应");assert(false); return false; }
		if(vecLine[9]!="LV"){printf_message("Item.csv中字段[LV]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Colour"){printf_message("Item.csv中字段[Colour]位置不对应");assert(false); return false; }
		if(vecLine[11]!="ShiYong"){printf_message("Item.csv中字段[ShiYong]位置不对应");assert(false); return false; }
		if(vecLine[12]!="HeCheng"){printf_message("Item.csv中字段[HeCheng]位置不对应");assert(false); return false; }
		if(vecLine[13]!="IsSell"){printf_message("Item.csv中字段[IsSell]位置不对应");assert(false); return false; }
		if(vecLine[14]!="ZiDong"){printf_message("Item.csv中字段[ZiDong]位置不对应");assert(false); return false; }
		if(vecLine[15]!="IsBind"){printf_message("Item.csv中字段[IsBind]位置不对应");assert(false); return false; }
		if(vecLine[16]!="IsAdd"){printf_message("Item.csv中字段[IsAdd]位置不对应");assert(false); return false; }
		if(vecLine[17]!="AddNum"){printf_message("Item.csv中字段[AddNum]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Price"){printf_message("Item.csv中字段[Price]位置不对应");assert(false); return false; }
		if(vecLine[19]!="IsDel"){printf_message("Item.csv中字段[IsDel]位置不对应");assert(false); return false; }
		if(vecLine[20]!="DelPrice"){printf_message("Item.csv中字段[DelPrice]位置不对应");assert(false); return false; }
		if(vecLine[21]!="BuyPrick"){printf_message("Item.csv中字段[BuyPrick]位置不对应");assert(false); return false; }
		if(vecLine[22]!="MiaoShu"){printf_message("Item.csv中字段[MiaoShu]位置不对应");assert(false); return false; }
		if(vecLine[23]!="BeiZhu"){printf_message("Item.csv中字段[BeiZhu]位置不对应");assert(false); return false; }
		if(vecLine[24]!=" Valuabl"){printf_message("Item.csv中字段[ Valuabl]位置不对应");assert(false); return false; }
		if(vecLine[25]!="ModelId"){printf_message("Item.csv中字段[ModelId]位置不对应");assert(false); return false; }
		if(vecLine[26]!="EffectID"){printf_message("Item.csv中字段[EffectID]位置不对应");assert(false); return false; }
		if(vecLine[27]!="Mission"){printf_message("Item.csv中字段[Mission]位置不对应");assert(false); return false; }
		if(vecLine[28]!="Skill"){printf_message("Item.csv中字段[Skill]位置不对应");assert(false); return false; }
		if(vecLine[29]!="ItenR"){printf_message("Item.csv中字段[ItenR]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			ItemElement	member;

						member.ItemID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Type=vecLine[2];
			member.FenLei=atoi(vecLine[3].c_str());
			member.FenLeiParameter=vecLine[4];
			member.Cishu=atoi(vecLine[5].c_str());
			member.Time=atoi(vecLine[6].c_str());
			member.Timeliness=atoi(vecLine[7].c_str());
			member.SourceID=vecLine[8];
			member.LV=atoi(vecLine[9].c_str());
			member.Colour=atoi(vecLine[10].c_str());
			member.ShiYong=atoi(vecLine[11].c_str());
			member.HeCheng=atoi(vecLine[12].c_str());
			member.IsSell=atoi(vecLine[13].c_str());
			member.ZiDong=atoi(vecLine[14].c_str());
			member.IsBind=atoi(vecLine[15].c_str());
			member.IsAdd=atoi(vecLine[16].c_str());
			member.AddNum=atoi(vecLine[17].c_str());
			member.Price=atoi(vecLine[18].c_str());
			member.IsDel=atoi(vecLine[19].c_str());
			member.DelPrice=atoi(vecLine[20].c_str());
			member.BuyPrick=atoi(vecLine[21].c_str());
			member.MiaoShu=vecLine[22];
			member.BeiZhu=vecLine[23];
			member. Valuabl=atoi(vecLine[24].c_str());
			member.ModelId=atoi(vecLine[25].c_str());
			member.EffectID=vecLine[26];
			member.Mission=atoi(vecLine[27].c_str());
			member.Skill=atoi(vecLine[28].c_str());
			member.ItenR=atof(vecLine[29].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.ItemID] = member;
		}

		return true;
	}

	bool LoadCsv(string strContent)
	{
		m_vecAllElements.clear();
		m_mapElements.clear();
		int contentOffset = 0;
		vector<string> vecLine;
		vecLine = ReadCsvLine( strContent, contentOffset );
		if(vecLine.size() != 30)
		{
			printf_message("Item.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ItemID"){printf_message("Item.csv中字段[ItemID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Item.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Type"){printf_message("Item.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[3]!="FenLei"){printf_message("Item.csv中字段[FenLei]位置不对应");assert(false); return false; }
		if(vecLine[4]!="FenLeiParameter"){printf_message("Item.csv中字段[FenLeiParameter]位置不对应");assert(false); return false; }
		if(vecLine[5]!="Cishu"){printf_message("Item.csv中字段[Cishu]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Time"){printf_message("Item.csv中字段[Time]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Timeliness"){printf_message("Item.csv中字段[Timeliness]位置不对应");assert(false); return false; }
		if(vecLine[8]!="SourceID"){printf_message("Item.csv中字段[SourceID]位置不对应");assert(false); return false; }
		if(vecLine[9]!="LV"){printf_message("Item.csv中字段[LV]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Colour"){printf_message("Item.csv中字段[Colour]位置不对应");assert(false); return false; }
		if(vecLine[11]!="ShiYong"){printf_message("Item.csv中字段[ShiYong]位置不对应");assert(false); return false; }
		if(vecLine[12]!="HeCheng"){printf_message("Item.csv中字段[HeCheng]位置不对应");assert(false); return false; }
		if(vecLine[13]!="IsSell"){printf_message("Item.csv中字段[IsSell]位置不对应");assert(false); return false; }
		if(vecLine[14]!="ZiDong"){printf_message("Item.csv中字段[ZiDong]位置不对应");assert(false); return false; }
		if(vecLine[15]!="IsBind"){printf_message("Item.csv中字段[IsBind]位置不对应");assert(false); return false; }
		if(vecLine[16]!="IsAdd"){printf_message("Item.csv中字段[IsAdd]位置不对应");assert(false); return false; }
		if(vecLine[17]!="AddNum"){printf_message("Item.csv中字段[AddNum]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Price"){printf_message("Item.csv中字段[Price]位置不对应");assert(false); return false; }
		if(vecLine[19]!="IsDel"){printf_message("Item.csv中字段[IsDel]位置不对应");assert(false); return false; }
		if(vecLine[20]!="DelPrice"){printf_message("Item.csv中字段[DelPrice]位置不对应");assert(false); return false; }
		if(vecLine[21]!="BuyPrick"){printf_message("Item.csv中字段[BuyPrick]位置不对应");assert(false); return false; }
		if(vecLine[22]!="MiaoShu"){printf_message("Item.csv中字段[MiaoShu]位置不对应");assert(false); return false; }
		if(vecLine[23]!="BeiZhu"){printf_message("Item.csv中字段[BeiZhu]位置不对应");assert(false); return false; }
		if(vecLine[24]!=" Valuabl"){printf_message("Item.csv中字段[ Valuabl]位置不对应");assert(false); return false; }
		if(vecLine[25]!="ModelId"){printf_message("Item.csv中字段[ModelId]位置不对应");assert(false); return false; }
		if(vecLine[26]!="EffectID"){printf_message("Item.csv中字段[EffectID]位置不对应");assert(false); return false; }
		if(vecLine[27]!="Mission"){printf_message("Item.csv中字段[Mission]位置不对应");assert(false); return false; }
		if(vecLine[28]!="Skill"){printf_message("Item.csv中字段[Skill]位置不对应");assert(false); return false; }
		if(vecLine[29]!="ItenR"){printf_message("Item.csv中字段[ItenR]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)30)
			{
				assert(false);
				return false;
			}
			ItemElement	member;
			member.ItemID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Type=vecLine[2];
			member.FenLei=atoi(vecLine[3].c_str());
			member.FenLeiParameter=vecLine[4];
			member.Cishu=atoi(vecLine[5].c_str());
			member.Time=atoi(vecLine[6].c_str());
			member.Timeliness=atoi(vecLine[7].c_str());
			member.SourceID=vecLine[8];
			member.LV=atoi(vecLine[9].c_str());
			member.Colour=atoi(vecLine[10].c_str());
			member.ShiYong=atoi(vecLine[11].c_str());
			member.HeCheng=atoi(vecLine[12].c_str());
			member.IsSell=atoi(vecLine[13].c_str());
			member.ZiDong=atoi(vecLine[14].c_str());
			member.IsBind=atoi(vecLine[15].c_str());
			member.IsAdd=atoi(vecLine[16].c_str());
			member.AddNum=atoi(vecLine[17].c_str());
			member.Price=atoi(vecLine[18].c_str());
			member.IsDel=atoi(vecLine[19].c_str());
			member.DelPrice=atoi(vecLine[20].c_str());
			member.BuyPrick=atoi(vecLine[21].c_str());
			member.MiaoShu=vecLine[22];
			member.BeiZhu=vecLine[23];
			member. Valuabl=atoi(vecLine[24].c_str());
			member.ModelId=atoi(vecLine[25].c_str());
			member.EffectID=vecLine[26];
			member.Mission=atoi(vecLine[27].c_str());
			member.Skill=atoi(vecLine[28].c_str());
			member.ItenR=atof(vecLine[29].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ItemID] = member;
		}
		return true;
	}
};

#endif
