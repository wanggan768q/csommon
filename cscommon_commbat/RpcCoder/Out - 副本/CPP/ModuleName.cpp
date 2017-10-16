#include "ModuleName.h"
map<int, string> ModuleValue;
void InitModuleValue()
{
	ModuleValue[2]="成就";
	ModuleValue[31]="活动 大逃杀";
	ModuleValue[38]="活动玩法";
	ModuleValue[32]="活动日常";
	ModuleValue[30]="活动 风暴";
	ModuleValue[14]="背包";
	ModuleValue[13]="战队基础数据";
	ModuleValue[36]="聊天";
	ModuleValue[1]="配置管理";
	ModuleValue[35]="掉落物";
	ModuleValue[12]="进出副本模块";
	ModuleValue[9]="战斗";
	ModuleValue[33]="好友";
	ModuleValue[17]="GM指令";
	ModuleValue[34]="帮派";
	ModuleValue[5]="登录模块";
	ModuleValue[44]="邮件";
	ModuleValue[41]="一v一";
	ModuleValue[42]="排行榜";
	ModuleValue[28]="在线数据";
	ModuleValue[10]="常驻内存属性模块";
	ModuleValue[39]="刷新数据";
	ModuleValue[22]="商城";
	ModuleValue[29]="技能";
	ModuleValue[43]="剧情副本";
	ModuleValue[18]="法宝";
	ModuleValue[24]="任务";
	ModuleValue[26]="组队";
	ModuleValue[40]="货运";

}
string GetModuleValue(int id)
{
	map<int, string>::iterator iter = ModuleValue.find(id);
	if (iter != ModuleValue.end())
	{
		return iter->second;
	}
	return "未知";
}
