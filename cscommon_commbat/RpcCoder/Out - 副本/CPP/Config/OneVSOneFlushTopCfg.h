#ifndef __ONEVSONEFLUSHTOP_CONFIG_H
#define __ONEVSONEFLUSHTOP_CONFIG_H

#ifdef CONFIG_JSON
#else
#include "ConfigUtil.h"
#enif
#define printf_message(_argg) printf(_argg)

//刷新排名的规则脜盲脰脙脢媒戮脻陆谩鹿鹿
struct OneVSOneFlushTopElement
{
	friend class OneVSOneFlushTopTable;
	int ID;                      	//编号	等级
	int StartTop;                	//起始排名段	起始排名段
	int EndTop;                  	//结束排名段	结束排名段
	int Type;                    	//类型	1随机（随机的话就是自己名次到自己名次减去StartFront里随机）0固定（固定的话 就只能是区间寻找给与客户端）
	int StartFront;              	//前面的起始段	前面的起始段
	int EndFront;                	//前面的结束段	前面的结束段
	int StartBack;               	//后面的起始段	后面的起始段
	int Endback;                 	//后面的结束段	后面的结束段

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
	OneVSOneFlushTopElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//刷新排名的规则脜盲脰脙路芒脳掳脌脿
class OneVSOneFlushTopTable
{
	friend class TableData;
private:
	OneVSOneFlushTopTable(){}
	~OneVSOneFlushTopTable(){}
	map<int, OneVSOneFlushTopElement>	m_mapElements;
	vector<OneVSOneFlushTopElement>	m_vecAllElements;
	OneVSOneFlushTopElement m_emptyItem;
public:
	static OneVSOneFlushTopTable& Instance()
	{
		static OneVSOneFlushTopTable sInstance;
		return sInstance;
	}

	OneVSOneFlushTopElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<OneVSOneFlushTopElement>&	GetAllElement()
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
		return LoadJson("OneVSOneFlushTop.json");
		#else
		string strTableContent;
		if( LoadConfigContent("OneVSOneFlushTop.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("OneVSOneFlushTop.bin", strTableContent ) )
		{
			printf_message("脜盲脰脙脦脛录镁[OneVSOneFlushTop.bin]脦麓脮脪碌陆");
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

				if(vecLine[0]!="ID"){printf_message("OneVSOneFlushTop.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="StartTop"){printf_message("OneVSOneFlushTop.csv中字段[StartTop]位置不对应");assert(false); return false; }
		if(vecLine[2]!="EndTop"){printf_message("OneVSOneFlushTop.csv中字段[EndTop]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("OneVSOneFlushTop.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="StartFront"){printf_message("OneVSOneFlushTop.csv中字段[StartFront]位置不对应");assert(false); return false; }
		if(vecLine[5]!="EndFront"){printf_message("OneVSOneFlushTop.csv中字段[EndFront]位置不对应");assert(false); return false; }
		if(vecLine[6]!="StartBack"){printf_message("OneVSOneFlushTop.csv中字段[StartBack]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Endback"){printf_message("OneVSOneFlushTop.csv中字段[Endback]位置不对应");assert(false); return false; }


		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			OneVSOneFlushTopElement	member;

						member.ID=atoi(vecLine[0].c_str());
			member.StartTop=atoi(vecLine[1].c_str());
			member.EndTop=atoi(vecLine[2].c_str());
			member.Type=atoi(vecLine[3].c_str());
			member.StartFront=atoi(vecLine[4].c_str());
			member.EndFront=atoi(vecLine[5].c_str());
			member.StartBack=atoi(vecLine[6].c_str());
			member.Endback=atoi(vecLine[7].c_str());


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
		if(vecLine.size() != 8)
		{
			printf_message("OneVSOneFlushTop.csv脰脨脕脨脢媒脕驴脫毛脡煤鲁脡碌脛麓煤脗毛虏禄脝楼脜盲!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("OneVSOneFlushTop.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="StartTop"){printf_message("OneVSOneFlushTop.csv中字段[StartTop]位置不对应");assert(false); return false; }
		if(vecLine[2]!="EndTop"){printf_message("OneVSOneFlushTop.csv中字段[EndTop]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Type"){printf_message("OneVSOneFlushTop.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[4]!="StartFront"){printf_message("OneVSOneFlushTop.csv中字段[StartFront]位置不对应");assert(false); return false; }
		if(vecLine[5]!="EndFront"){printf_message("OneVSOneFlushTop.csv中字段[EndFront]位置不对应");assert(false); return false; }
		if(vecLine[6]!="StartBack"){printf_message("OneVSOneFlushTop.csv中字段[StartBack]位置不对应");assert(false); return false; }
		if(vecLine[7]!="Endback"){printf_message("OneVSOneFlushTop.csv中字段[Endback]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)8)
			{
				assert(false);
				return false;
			}
			OneVSOneFlushTopElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.StartTop=atoi(vecLine[1].c_str());
			member.EndTop=atoi(vecLine[2].c_str());
			member.Type=atoi(vecLine[3].c_str());
			member.StartFront=atoi(vecLine[4].c_str());
			member.EndFront=atoi(vecLine[5].c_str());
			member.StartBack=atoi(vecLine[6].c_str());
			member.Endback=atoi(vecLine[7].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
