/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     BaseAttrDBCache.h
* Author:       甘业清
* Description:  战队基础数据数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __DATA_BASEATTR_H
#define __DATA_BASEATTR_H


#include "ModuleData.h"
#include "BaseAttrV1DataWraper.h"


//同步数据相关枚举量定义
enum DataWraperItemIdE
{
	MODULE_ID_BASEATTR = 13,
 	SYNCID_BASEATTR_HEADID                      = 1301,  //头像id
 	SYNCID_BASEATTR_EXP                         = 1302,  //经验
 	SYNCID_BASEATTR_CREATETIME                  = 1303,  //创建时间
 	SYNCID_BASEATTR_LASTLOGINTIME               = 1304,  //最后登录时间
 	SYNCID_BASEATTR_LAST2LOGINDATE              = 1305,  //倒数第二登录日期
 	SYNCID_BASEATTR_LASTLOGOUTTIME              = 1306,  //最后登出时间
 	SYNCID_BASEATTR_MONEY                       = 1307,  //游戏币
 	SYNCID_BASEATTR_DIAMOND                     = 1308,  //钻石
 	SYNCID_BASEATTR_STRENGTH                    = 1310,  //体力
 	SYNCID_BASEATTR_FEATS                       = 1311,  //功勋
 	SYNCID_BASEATTR_GOTRANKREWARDTIME           = 1312,  //领取官阶奖励时间
 	SYNCID_BASEATTR_MAXMILITARY                 = 1314,  //历史最大战力
 	SYNCID_BASEATTR_MASTERATTRS                 = 1315,  //主公基础属性
 	SYNCID_BASEATTR_CURMILITARY                 = 1318,  //当前玩家战力
 	SYNCID_BASEATTR_USERNAME                    = 1319,  //玩家名字
 	SYNCID_BASEATTR_USERID                      = 1320,  //用户ID
 	SYNCID_BASEATTR_PLATNAME                    = 1321,  //游戏中心账号名
 	SYNCID_BASEATTR_ACCOUNTID                   = 1322,  //游戏中心账号ID
 	SYNCID_BASEATTR_LEVEL                       = 1323,  //玩家等级
 	SYNCID_BASEATTR_RANK                        = 1324,  //官阶
 	SYNCID_BASEATTR_FIGHTPOWER                  = 1325,  //战力
 	SYNCID_BASEATTR_SEC                         = 1326,  //用户累加的数据
 	SYNCID_BASEATTR_MILITARY                    = 1327,  //当前战力
 	SYNCID_BASEATTR_TEAMID                      = 1328,  //队伍Id
 	SYNCID_BASEATTR_PROF                        = 1329,  //职业
 	SYNCID_BASEATTR_DUNGEONREMAINCOUNT          = 1330,  //副本剩余次数
 	SYNCID_BASEATTR_MAPID                       = 1331,  //地图Id
 	SYNCID_BASEATTR_POSX                        = 1332,  //X坐标
 	SYNCID_BASEATTR_POSY                        = 1333,  //Y坐标
 	SYNCID_BASEATTR_POSZ                        = 1334,  //Z坐标
 	SYNCID_BASEATTR_RY                          = 1335,  //位置方向
 	SYNCID_BASEATTR_SKILLCDARR                  = 1336,  //技能CD列表
 	SYNCID_BASEATTR_BUFFCDARR                   = 1337,  //BuffCD列表
 	SYNCID_BASEATTR_CURRENTSCENE                = 1338,  //当前所在场景
 	SYNCID_BASEATTR_GUILDID                     = 1339,  //帮会Id
 	SYNCID_BASEATTR_EXITGUILDTIME               = 1340,  //退出帮会时间
 	SYNCID_BASEATTR_APPLYGUILDID                = 1341,  //申请过的帮会
 	SYNCID_BASEATTR_CURGUILDCONTRIBUTION        = 1342,  //当前帮贡
 	SYNCID_BASEATTR_MAXGUILDCONTRIBUTION        = 1343,  //最大帮贡
 	SYNCID_BASEATTR_BINDMONEY                   = 1344,  //绑银
 	SYNCID_BASEATTR_GEM                         = 1345,  //宝石
 	SYNCID_BASEATTR_SERVERTIME                  = 1347,  //服务器时间
 	SYNCID_BASEATTR_NEWBIEGUIDE                 = 1348,  //新手引导
 	SYNCID_BASEATTR_THIEFREWARDNUM              = 1349,  //江洋大盗奖励次数
 	SYNCID_BASEATTR_SUBDUEMONSTERREWARDNUM      = 1350,  //降妖奖励次数
 	SYNCID_BASEATTR_WORLDBOSSREMAINTIMES        = 1351,  //世界Boss剩余次数
 	SYNCID_BASEATTR_WORLDBOSSHURT               = 1352,  //世界Boss伤害
 	SYNCID_BASEATTR_FUNCTIONOPENLIST            = 1354,  //功能开启列表
 	SYNCID_BASEATTR_TOTALENERGYVALUE            = 1355,  //总活力值
 	SYNCID_BASEATTR_ENERGYARRAY                 = 1357,  //活力值信息容器
 	SYNCID_BASEATTR_PKSTATE                     = 1358,  //PK状态
 	SYNCID_BASEATTR_PKPROTECT                   = 1359,  //PK保护列表
 	SYNCID_BASEATTR_GUILDSCIENARRAY             = 1360,  //帮会修炼
 	SYNCID_BASEATTR_SCIENCETOTALMONEY           = 1361,  //修炼升级消耗总金币

};


//战队基础数据数据类
class DataBaseAttr : public ModuleData
{
	DECLARE_INSTANCE(DataBaseAttr);
public:
	friend class			ModuleDataMgr;

public:
	//战队基础数据实现类构造函数
	DataBaseAttr();
	
	//战队基础数据实现类析构函数
	virtual					~DataBaseAttr();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//获取模块同步(保存)数据版本及类名
	virtual map<INT32,TStr>	GetDataWraperVersionName();
	
	//模块数据保存类型
	virtual SavedDataTypeE	GetSavedDataType();

	//是否保存数据到数据库中
	virtual bool			IsSaveModuleDataToDB();

	//模块同步(保存)数据升级函数
	virtual bool			UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur );
	
	//增量更新通知
	virtual bool			OnIncrementUpdate( INT64 key, int syncId, int IndexPos, const char* pBuffer, int dataLen );


private:
	 map<INT32,TStr>		m_mapDataWraperVersionName;
};

#endif