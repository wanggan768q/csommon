#ifndef __GUIDESTEPS_CONFIG_H
#define __GUIDESTEPS_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//引导步骤脜盲脰脙脢媒戮脻陆谩鹿鹿
struct GuideStepsElement
{
	friend class GuideStepsTable;
	int ID;                      	//指引步骤id	指引步骤id
	string Name;                 	// 名字	名字
	string GuideRule;            	//指引条件	指引条件 ? 指引类型 1：按钮，2：摇杆，3列表 ? View界面的名字 ? 下级的名字 按钮和摇杆为按钮名字，列表为列表名字 ? 列表的按钮 ? 如果是列表类型[1位置,0位置编号] 按钮的另外一种例子：[1,"Normal/UIBattle(Clone)","MenuAndSkill/RightBottomSkill/ExpandButton",1] 最后的1代表如果当前按钮没有显示，直接跳到下个流程
	string GuideAnimation;       	//指引动画	播放动画 ? 播放位置[X,Y]相对于控件的位置 ? 播放方式：1-单次，2-循环 [[200,0],2,0,1,30,"","看这里有惊喜",[240,150]]  只有文字的 [[200,0],2,0,1,30,"UIStar","",[0,0]]  只有特效的 [[200,0],2,0,1,30,"UIStar","看这里有惊喜",[230,150],[200,-100]]  文字和特效都有的 ? 播放次数：X次数(类型为单次时，此项无效，0为无限次) ？1 不翻转 2 翻转 3 左右镜像 4上下镜像 ？旋转角度，例如：30 表示逆时针旋转30° ? 资源路径：XXX\XXXX\XXX ? 字的内容：字符串 ? 预留坐标[X,Y]相对于控件的位置 可以不加加了之后 如果有动画和文本，文本走这个坐标

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
	GuideStepsElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//引导步骤脜盲脰脙路芒脳掳脌脿
class GuideStepsTable
{
	friend class TableData;
private:
	GuideStepsTable(){}
	~GuideStepsTable(){}
	map<int, GuideStepsElement>	m_mapElements;
	vector<GuideStepsElement>	m_vecAllElements;
	GuideStepsElement m_emptyItem;
public:
	static GuideStepsTable& Instance()
	{
		static GuideStepsTable sInstance;
		return sInstance;
	}

	GuideStepsElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<GuideStepsElement>&	GetAllElement()
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
		return LoadJson("GuideSteps.json");
		#else
		string strTableContent;
		if( LoadConfigContent("GuideSteps.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("GuideSteps.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[GuideSteps.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("GuideSteps.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("GuideSteps.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="GuideRule"){printf_message("GuideSteps.csv中字段[GuideRule]位置不对应");assert(false); return false; }
		if(vecLine[3]!="GuideAnimation"){printf_message("GuideSteps.csv中字段[GuideAnimation]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			GuideStepsElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.GuideRule=vecLine[2];
			member.GuideAnimation=vecLine[3];


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
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
		if(vecLine.size() != 4)
		{
			printf_message("GuideSteps.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("GuideSteps.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Name"){printf_message("GuideSteps.csv中字段[Name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="GuideRule"){printf_message("GuideSteps.csv中字段[GuideRule]位置不对应");assert(false); return false; }
		if(vecLine[3]!="GuideAnimation"){printf_message("GuideSteps.csv中字段[GuideAnimation]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)4)
			{
				assert(false);
				return false;
			}
			GuideStepsElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Name=vecLine[1];
			member.GuideRule=vecLine[2];
			member.GuideAnimation=vecLine[3];

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
