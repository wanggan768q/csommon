#ifndef __BUFF_CONFIG_H
#define __BUFF_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//技能效果表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct BuffElement
{
	friend class BuffTable;
	int BuffID;                  	//BuffID	编号
	string Name;                 	//名字	BUFF的名字，主要策划识别用
	string Describe;             	//描述	BUFF描述
	int IconShow;                	//是否显示ICON	1显示2不显示
	string IconName;             	//Icon	Icon路径配置
	int EffectType;              	//BUFF效果类型	1增益，2减益
	int DieEfficient;            	//死亡是否存续	Buff在角色死亡后能否继续存在（1是0否）
	int TriggerPos;              	//触发位置	状态触发时播放特效的位置
	string TriggerEffects;       	//触发特效	状态触发时播放的特效
	int SustainPos;              	//持续位置	状态持续时播放特效的位置1.原点2.头3.胸
	string SustainEffects;       	//持续特效	状态持续时播放的特效
	int MaterialType;            	//特效材质	特效材质变化
	string AblityID;             	//动作文件	动作的索引目录
	int Type;                    	//BUFF类	定义的类别（同类覆盖，不同共存）
	int Priority;                	//优先级	同类的BUFF按照优先级覆盖，数字越大优先级越高，高能覆盖低，低不能覆盖高，同优先级的后一个BUFF覆盖前一个BUFF，-1为最低优先级
	string ImmuneType;           	//抵抗的类	免疫该类的BUFF,可多项，逗号隔开
	int Duration;                	//持续时间	BUFF的持续时间，-100为当前段，-200为当前技能时长
	int Interval;                	//作用间隔	BUFF的作用间隔
	int Steer;                   	//摇杆操作效果	1相反，-1正常，0无效
	int Target;                  	//技能伤害目标	1敌，2友，3全,-1无效
	int UseSkill;                	//能否释放技能	不能进行任何攻击为1，不能进行技能释放为0，不限制为-1
	string Attribute1Type;       	//属性1类型 1000以下是特殊BUFF功能，1000以上是角色属性	增加的属性类型 1 附加伤害 2 添加BUFF 3 由普攻触发加伤害 4 由普攻触发加BUFF 5 加百分比生命给攻击者 6 光属性或恢复技能增强百分比 7 受到的部分伤害转化为生命 8 目标生命值大于自身当前生命，则立刻治疗自己，治疗效果为本次伤害的百分比 9 使用技能 10吸血 101 致命链接
	string Attribute1Value;      	//属性1参数	增加的属性具体数值
	int GoBack1;                 	//是否撤回	1撤回，-1不撤回
	string Attribute2Type;       	//属性2类型	增加的属性类型
	string Attribute2Value;      	//属性2参数	增加的属性具体数值
	int GoBack2;                 	//是否撤回	1撤回，-1不撤回
	string Attribute3Type;       	//属性3类型	增加的属性类型
	string Attribute3Value;      	//属性3参数	增加的属性具体数值
	int GoBack3;                 	//是否撤回	1撤回，-1不撤回
	string Attribute4Type;       	//属性4类型	增加的属性类型
	string Attribute4Value;      	//属性4参数	增加的属性具体数值
	int GoBack4;                 	//是否撤回	1撤回，-1不撤回
	int MarkType;                	//标记类型	1破甲2死亡3隐身4无敌5霸体6引燃7禁食8护甲转移攻击9无法打断吟唱技能10自动复活11忽略MISS计算
	int SpecialTrigger;          	//BUFF触发结束条件	1能量盾，2次数盾，3受击次数触发，4下一击附加行为，5死亡触发，6结束触发技能
	string DispelType;           	//驱散的类	调用Type字段

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
	BuffElement()
	{
		BuffID = -1;
		m_bIsValidate=false;
	}
};

//技能效果表脜盲脰脙路芒脳掳脌脿
class BuffTable
{
	friend class TableData;
private:
	BuffTable(){}
	~BuffTable(){}
	map<int, BuffElement>	m_mapElements;
	vector<BuffElement>	m_vecAllElements;
	BuffElement m_emptyItem;
public:
	static BuffTable& Instance()
	{
		static BuffTable sInstance;
		return sInstance;
	}

	BuffElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BuffElement>&	GetAllElement()
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
		return LoadJson("Buff.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Buff.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Buff.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[Buff.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="BuffID"){printf_message("Buff.csv中字段[BuffID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Buff.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Describe"){printf_message("Buff.csv中字段[Describe]位置不对应");assert(false); return false; }
		if(vecLine[3]!="IconShow"){printf_message("Buff.csv中字段[IconShow]位置不对应");assert(false); return false; }
		if(vecLine[4]!="IconName"){printf_message("Buff.csv中字段[IconName]位置不对应");assert(false); return false; }
		if(vecLine[5]!="EffectType"){printf_message("Buff.csv中字段[EffectType]位置不对应");assert(false); return false; }
		if(vecLine[6]!="DieEfficient"){printf_message("Buff.csv中字段[DieEfficient]位置不对应");assert(false); return false; }
		if(vecLine[7]!="TriggerPos"){printf_message("Buff.csv中字段[TriggerPos]位置不对应");assert(false); return false; }
		if(vecLine[8]!="TriggerEffects"){printf_message("Buff.csv中字段[TriggerEffects]位置不对应");assert(false); return false; }
		if(vecLine[9]!="SustainPos"){printf_message("Buff.csv中字段[SustainPos]位置不对应");assert(false); return false; }
		if(vecLine[10]!="SustainEffects"){printf_message("Buff.csv中字段[SustainEffects]位置不对应");assert(false); return false; }
		if(vecLine[11]!="MaterialType"){printf_message("Buff.csv中字段[MaterialType]位置不对应");assert(false); return false; }
		if(vecLine[12]!="AblityID"){printf_message("Buff.csv中字段[AblityID]位置不对应");assert(false); return false; }
		if(vecLine[13]!="Type"){printf_message("Buff.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[14]!="Priority"){printf_message("Buff.csv中字段[Priority]位置不对应");assert(false); return false; }
		if(vecLine[15]!="ImmuneType"){printf_message("Buff.csv中字段[ImmuneType]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Duration"){printf_message("Buff.csv中字段[Duration]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Interval"){printf_message("Buff.csv中字段[Interval]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Steer"){printf_message("Buff.csv中字段[Steer]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Target"){printf_message("Buff.csv中字段[Target]位置不对应");assert(false); return false; }
		if(vecLine[20]!="UseSkill"){printf_message("Buff.csv中字段[UseSkill]位置不对应");assert(false); return false; }
		if(vecLine[21]!="Attribute1Type"){printf_message("Buff.csv中字段[Attribute1Type]位置不对应");assert(false); return false; }
		if(vecLine[22]!="Attribute1Value"){printf_message("Buff.csv中字段[Attribute1Value]位置不对应");assert(false); return false; }
		if(vecLine[23]!="GoBack1"){printf_message("Buff.csv中字段[GoBack1]位置不对应");assert(false); return false; }
		if(vecLine[24]!="Attribute2Type"){printf_message("Buff.csv中字段[Attribute2Type]位置不对应");assert(false); return false; }
		if(vecLine[25]!="Attribute2Value"){printf_message("Buff.csv中字段[Attribute2Value]位置不对应");assert(false); return false; }
		if(vecLine[26]!="GoBack2"){printf_message("Buff.csv中字段[GoBack2]位置不对应");assert(false); return false; }
		if(vecLine[27]!="Attribute3Type"){printf_message("Buff.csv中字段[Attribute3Type]位置不对应");assert(false); return false; }
		if(vecLine[28]!="Attribute3Value"){printf_message("Buff.csv中字段[Attribute3Value]位置不对应");assert(false); return false; }
		if(vecLine[29]!="GoBack3"){printf_message("Buff.csv中字段[GoBack3]位置不对应");assert(false); return false; }
		if(vecLine[30]!="Attribute4Type"){printf_message("Buff.csv中字段[Attribute4Type]位置不对应");assert(false); return false; }
		if(vecLine[31]!="Attribute4Value"){printf_message("Buff.csv中字段[Attribute4Value]位置不对应");assert(false); return false; }
		if(vecLine[32]!="GoBack4"){printf_message("Buff.csv中字段[GoBack4]位置不对应");assert(false); return false; }
		if(vecLine[33]!="MarkType"){printf_message("Buff.csv中字段[MarkType]位置不对应");assert(false); return false; }
		if(vecLine[34]!="SpecialTrigger"){printf_message("Buff.csv中字段[SpecialTrigger]位置不对应");assert(false); return false; }
		if(vecLine[35]!="DispelType"){printf_message("Buff.csv中字段[DispelType]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			BuffElement	member;

						member.BuffID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Describe=vecLine[2];
			member.IconShow=atoi(vecLine[3].c_str());
			member.IconName=vecLine[4];
			member.EffectType=atoi(vecLine[5].c_str());
			member.DieEfficient=atoi(vecLine[6].c_str());
			member.TriggerPos=atoi(vecLine[7].c_str());
			member.TriggerEffects=vecLine[8];
			member.SustainPos=atoi(vecLine[9].c_str());
			member.SustainEffects=vecLine[10];
			member.MaterialType=atoi(vecLine[11].c_str());
			member.AblityID=vecLine[12];
			member.Type=atoi(vecLine[13].c_str());
			member.Priority=atoi(vecLine[14].c_str());
			member.ImmuneType=vecLine[15];
			member.Duration=atoi(vecLine[16].c_str());
			member.Interval=atoi(vecLine[17].c_str());
			member.Steer=atoi(vecLine[18].c_str());
			member.Target=atoi(vecLine[19].c_str());
			member.UseSkill=atoi(vecLine[20].c_str());
			member.Attribute1Type=vecLine[21];
			member.Attribute1Value=vecLine[22];
			member.GoBack1=atoi(vecLine[23].c_str());
			member.Attribute2Type=vecLine[24];
			member.Attribute2Value=vecLine[25];
			member.GoBack2=atoi(vecLine[26].c_str());
			member.Attribute3Type=vecLine[27];
			member.Attribute3Value=vecLine[28];
			member.GoBack3=atoi(vecLine[29].c_str());
			member.Attribute4Type=vecLine[30];
			member.Attribute4Value=vecLine[31];
			member.GoBack4=atoi(vecLine[32].c_str());
			member.MarkType=atoi(vecLine[33].c_str());
			member.SpecialTrigger=atoi(vecLine[34].c_str());
			member.DispelType=vecLine[35];


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.BuffID] = member;
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
		if(vecLine.size() != 36)
		{
			printf_message("Buff.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="BuffID"){printf_message("Buff.csv中字段[BuffID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("Buff.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Describe"){printf_message("Buff.csv中字段[Describe]位置不对应");assert(false); return false; }
		if(vecLine[3]!="IconShow"){printf_message("Buff.csv中字段[IconShow]位置不对应");assert(false); return false; }
		if(vecLine[4]!="IconName"){printf_message("Buff.csv中字段[IconName]位置不对应");assert(false); return false; }
		if(vecLine[5]!="EffectType"){printf_message("Buff.csv中字段[EffectType]位置不对应");assert(false); return false; }
		if(vecLine[6]!="DieEfficient"){printf_message("Buff.csv中字段[DieEfficient]位置不对应");assert(false); return false; }
		if(vecLine[7]!="TriggerPos"){printf_message("Buff.csv中字段[TriggerPos]位置不对应");assert(false); return false; }
		if(vecLine[8]!="TriggerEffects"){printf_message("Buff.csv中字段[TriggerEffects]位置不对应");assert(false); return false; }
		if(vecLine[9]!="SustainPos"){printf_message("Buff.csv中字段[SustainPos]位置不对应");assert(false); return false; }
		if(vecLine[10]!="SustainEffects"){printf_message("Buff.csv中字段[SustainEffects]位置不对应");assert(false); return false; }
		if(vecLine[11]!="MaterialType"){printf_message("Buff.csv中字段[MaterialType]位置不对应");assert(false); return false; }
		if(vecLine[12]!="AblityID"){printf_message("Buff.csv中字段[AblityID]位置不对应");assert(false); return false; }
		if(vecLine[13]!="Type"){printf_message("Buff.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[14]!="Priority"){printf_message("Buff.csv中字段[Priority]位置不对应");assert(false); return false; }
		if(vecLine[15]!="ImmuneType"){printf_message("Buff.csv中字段[ImmuneType]位置不对应");assert(false); return false; }
		if(vecLine[16]!="Duration"){printf_message("Buff.csv中字段[Duration]位置不对应");assert(false); return false; }
		if(vecLine[17]!="Interval"){printf_message("Buff.csv中字段[Interval]位置不对应");assert(false); return false; }
		if(vecLine[18]!="Steer"){printf_message("Buff.csv中字段[Steer]位置不对应");assert(false); return false; }
		if(vecLine[19]!="Target"){printf_message("Buff.csv中字段[Target]位置不对应");assert(false); return false; }
		if(vecLine[20]!="UseSkill"){printf_message("Buff.csv中字段[UseSkill]位置不对应");assert(false); return false; }
		if(vecLine[21]!="Attribute1Type"){printf_message("Buff.csv中字段[Attribute1Type]位置不对应");assert(false); return false; }
		if(vecLine[22]!="Attribute1Value"){printf_message("Buff.csv中字段[Attribute1Value]位置不对应");assert(false); return false; }
		if(vecLine[23]!="GoBack1"){printf_message("Buff.csv中字段[GoBack1]位置不对应");assert(false); return false; }
		if(vecLine[24]!="Attribute2Type"){printf_message("Buff.csv中字段[Attribute2Type]位置不对应");assert(false); return false; }
		if(vecLine[25]!="Attribute2Value"){printf_message("Buff.csv中字段[Attribute2Value]位置不对应");assert(false); return false; }
		if(vecLine[26]!="GoBack2"){printf_message("Buff.csv中字段[GoBack2]位置不对应");assert(false); return false; }
		if(vecLine[27]!="Attribute3Type"){printf_message("Buff.csv中字段[Attribute3Type]位置不对应");assert(false); return false; }
		if(vecLine[28]!="Attribute3Value"){printf_message("Buff.csv中字段[Attribute3Value]位置不对应");assert(false); return false; }
		if(vecLine[29]!="GoBack3"){printf_message("Buff.csv中字段[GoBack3]位置不对应");assert(false); return false; }
		if(vecLine[30]!="Attribute4Type"){printf_message("Buff.csv中字段[Attribute4Type]位置不对应");assert(false); return false; }
		if(vecLine[31]!="Attribute4Value"){printf_message("Buff.csv中字段[Attribute4Value]位置不对应");assert(false); return false; }
		if(vecLine[32]!="GoBack4"){printf_message("Buff.csv中字段[GoBack4]位置不对应");assert(false); return false; }
		if(vecLine[33]!="MarkType"){printf_message("Buff.csv中字段[MarkType]位置不对应");assert(false); return false; }
		if(vecLine[34]!="SpecialTrigger"){printf_message("Buff.csv中字段[SpecialTrigger]位置不对应");assert(false); return false; }
		if(vecLine[35]!="DispelType"){printf_message("Buff.csv中字段[DispelType]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)36)
			{
				assert(false);
				return false;
			}
			BuffElement	member;
			member.BuffID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.Describe=vecLine[2];
			member.IconShow=atoi(vecLine[3].c_str());
			member.IconName=vecLine[4];
			member.EffectType=atoi(vecLine[5].c_str());
			member.DieEfficient=atoi(vecLine[6].c_str());
			member.TriggerPos=atoi(vecLine[7].c_str());
			member.TriggerEffects=vecLine[8];
			member.SustainPos=atoi(vecLine[9].c_str());
			member.SustainEffects=vecLine[10];
			member.MaterialType=atoi(vecLine[11].c_str());
			member.AblityID=vecLine[12];
			member.Type=atoi(vecLine[13].c_str());
			member.Priority=atoi(vecLine[14].c_str());
			member.ImmuneType=vecLine[15];
			member.Duration=atoi(vecLine[16].c_str());
			member.Interval=atoi(vecLine[17].c_str());
			member.Steer=atoi(vecLine[18].c_str());
			member.Target=atoi(vecLine[19].c_str());
			member.UseSkill=atoi(vecLine[20].c_str());
			member.Attribute1Type=vecLine[21];
			member.Attribute1Value=vecLine[22];
			member.GoBack1=atoi(vecLine[23].c_str());
			member.Attribute2Type=vecLine[24];
			member.Attribute2Value=vecLine[25];
			member.GoBack2=atoi(vecLine[26].c_str());
			member.Attribute3Type=vecLine[27];
			member.Attribute3Value=vecLine[28];
			member.GoBack3=atoi(vecLine[29].c_str());
			member.Attribute4Type=vecLine[30];
			member.Attribute4Value=vecLine[31];
			member.GoBack4=atoi(vecLine[32].c_str());
			member.MarkType=atoi(vecLine[33].c_str());
			member.SpecialTrigger=atoi(vecLine[34].c_str());
			member.DispelType=vecLine[35];

			member.SetIsValidate(true);
			m_mapElements[member.BuffID] = member;
		}
		return true;
	}
};

#endif
