#ifndef __MODELBASE_CONFIG_H
#define __MODELBASE_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//模型基础表脜盲脰脙脢媒戮脻陆谩鹿鹿
struct ModelBaseElement
{
	friend class ModelBaseTable;
	int ModelID;                 	//ID	ID
	string Res;                  	//模型资源	模型资源
	float Height;                	//身高	身高
	int ModelR;                  	//模型半径	模型半径/单位：cm
	string BanShen;              	//半身像	半身像资源
	string QuanShen;             	//全身像	全身像
	string Blood;                	//血条	血条
	string Progress;             	//吟唱&引导&被控	吟唱&引导&被控
	string Damage;               	//伤害数字	伤害数字
	string Exp;                  	//经验	经验
	string Tips;                 	//增益&减益	增益&减益
	string Nickname;             	//昵称	昵称
	int NicknameSize;            	//昵称字号、掉落道具字号	昵称字号、掉落道具字号
	string Title;                	//称号	称号
	int TitleSize;               	//称号字号	称号字号
	string CityNickname;         	//主城昵称	主城昵称
	int CityNicknameSize;        	//主城昵称字号	主城昵称字号

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
	ModelBaseElement()
	{
		ModelID = -1;
		m_bIsValidate=false;
	}
};

//模型基础表脜盲脰脙路芒脳掳脌脿
class ModelBaseTable
{
	friend class TableData;
private:
	ModelBaseTable(){}
	~ModelBaseTable(){}
	map<int, ModelBaseElement>	m_mapElements;
	vector<ModelBaseElement>	m_vecAllElements;
	ModelBaseElement m_emptyItem;
public:
	static ModelBaseTable& Instance()
	{
		static ModelBaseTable sInstance;
		return sInstance;
	}

	ModelBaseElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ModelBaseElement>&	GetAllElement()
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
		return LoadJson("ModelBase.json");
		#else
		string strTableContent;
		if( LoadConfigContent("ModelBase.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ModelBase.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[ModelBase.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ModelID"){printf_message("ModelBase.csv中字段[ModelID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Res"){printf_message("ModelBase.csv中字段[Res]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Height"){printf_message("ModelBase.csv中字段[Height]位置不对应");assert(false); return false; }
		if(vecLine[3]!="ModelR"){printf_message("ModelBase.csv中字段[ModelR]位置不对应");assert(false); return false; }
		if(vecLine[4]!="BanShen"){printf_message("ModelBase.csv中字段[BanShen]位置不对应");assert(false); return false; }
		if(vecLine[5]!="QuanShen"){printf_message("ModelBase.csv中字段[QuanShen]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Blood"){printf_message("ModelBase.csv中字段[Blood]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Progress"){printf_message("ModelBase.csv中字段[Progress]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Damage"){printf_message("ModelBase.csv中字段[Damage]位置不对应");assert(false); return false; }
		if(vecLine[9]!="Exp"){printf_message("ModelBase.csv中字段[Exp]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Tips"){printf_message("ModelBase.csv中字段[Tips]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Nickname"){printf_message("ModelBase.csv中字段[Nickname]位置不对应");assert(false); return false; }
		if(vecLine[12]!="NicknameSize"){printf_message("ModelBase.csv中字段[NicknameSize]位置不对应");assert(false); return false; }
		if(vecLine[13]!="Title"){printf_message("ModelBase.csv中字段[Title]位置不对应");assert(false); return false; }
		if(vecLine[14]!="TitleSize"){printf_message("ModelBase.csv中字段[TitleSize]位置不对应");assert(false); return false; }
		if(vecLine[15]!="CityNickname"){printf_message("ModelBase.csv中字段[CityNickname]位置不对应");assert(false); return false; }
		if(vecLine[16]!="CityNicknameSize"){printf_message("ModelBase.csv中字段[CityNicknameSize]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			ModelBaseElement	member;

						member.ModelID=atoi(vecLine[0].c_str());
			member.Res=vecLine[1];
			member.Height=atof(vecLine[2].c_str());
			member.ModelR=atoi(vecLine[3].c_str());
			member.BanShen=vecLine[4];
			member.QuanShen=vecLine[5];
			member.Blood=vecLine[6];
			member.Progress=vecLine[7];
			member.Damage=vecLine[8];
			member.Exp=vecLine[9];
			member.Tips=vecLine[10];
			member.Nickname=vecLine[11];
			member.NicknameSize=atoi(vecLine[12].c_str());
			member.Title=vecLine[13];
			member.TitleSize=atoi(vecLine[14].c_str());
			member.CityNickname=vecLine[15];
			member.CityNicknameSize=atoi(vecLine[16].c_str());


			$ReadJsonValue$

			member.SetIsValidate(true);
			m_mapElements[member.ModelID] = member;
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
		if(vecLine.size() != 17)
		{
			printf_message("ModelBase.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ModelID"){printf_message("ModelBase.csv中字段[ModelID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Res"){printf_message("ModelBase.csv中字段[Res]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Height"){printf_message("ModelBase.csv中字段[Height]位置不对应");assert(false); return false; }
		if(vecLine[3]!="ModelR"){printf_message("ModelBase.csv中字段[ModelR]位置不对应");assert(false); return false; }
		if(vecLine[4]!="BanShen"){printf_message("ModelBase.csv中字段[BanShen]位置不对应");assert(false); return false; }
		if(vecLine[5]!="QuanShen"){printf_message("ModelBase.csv中字段[QuanShen]位置不对应");assert(false); return false; }
		if(vecLine[6]!="Blood"){printf_message("ModelBase.csv中字段[Blood]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Progress"){printf_message("ModelBase.csv中字段[Progress]位置不对应");assert(false); return false; }
		if(vecLine[8]!="Damage"){printf_message("ModelBase.csv中字段[Damage]位置不对应");assert(false); return false; }
		if(vecLine[9]!="Exp"){printf_message("ModelBase.csv中字段[Exp]位置不对应");assert(false); return false; }
		if(vecLine[10]!="Tips"){printf_message("ModelBase.csv中字段[Tips]位置不对应");assert(false); return false; }
		if(vecLine[11]!="Nickname"){printf_message("ModelBase.csv中字段[Nickname]位置不对应");assert(false); return false; }
		if(vecLine[12]!="NicknameSize"){printf_message("ModelBase.csv中字段[NicknameSize]位置不对应");assert(false); return false; }
		if(vecLine[13]!="Title"){printf_message("ModelBase.csv中字段[Title]位置不对应");assert(false); return false; }
		if(vecLine[14]!="TitleSize"){printf_message("ModelBase.csv中字段[TitleSize]位置不对应");assert(false); return false; }
		if(vecLine[15]!="CityNickname"){printf_message("ModelBase.csv中字段[CityNickname]位置不对应");assert(false); return false; }
		if(vecLine[16]!="CityNicknameSize"){printf_message("ModelBase.csv中字段[CityNicknameSize]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)17)
			{
				assert(false);
				return false;
			}
			ModelBaseElement	member;
			member.ModelID=atoi(vecLine[0].c_str());
			member.Res=vecLine[1];
			member.Height=atof(vecLine[2].c_str());
			member.ModelR=atoi(vecLine[3].c_str());
			member.BanShen=vecLine[4];
			member.QuanShen=vecLine[5];
			member.Blood=vecLine[6];
			member.Progress=vecLine[7];
			member.Damage=vecLine[8];
			member.Exp=vecLine[9];
			member.Tips=vecLine[10];
			member.Nickname=vecLine[11];
			member.NicknameSize=atoi(vecLine[12].c_str());
			member.Title=vecLine[13];
			member.TitleSize=atoi(vecLine[14].c_str());
			member.CityNickname=vecLine[15];
			member.CityNicknameSize=atoi(vecLine[16].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ModelID] = member;
		}
		return true;
	}
};

#endif
