#ifndef __SYNC_DATA_BASEATTR_V1_H
#define __SYNC_DATA_BASEATTR_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "BaseAttrV1DataWraper.h"


//同步数据相关枚举量定义
enum BaseAttrSyncDataItemIdE
{
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


//主同步数据操作类
class SyncDataBaseAttrV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataBaseAttrV1>
{
public:
			SyncDataBaseAttrV1();
	virtual	~SyncDataBaseAttrV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataUserData.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataUserData.HtmlDescHeader(); }
public:
	//头像id
	void SetHeadID( const INT32& v );
	INT32 GetHeadID();
	void SendHeadID(bool OnlyToClient=true);
public:
	//经验
	void SetExp( const INT32& v );
	INT32 GetExp();
	void SendExp(bool OnlyToClient=true);
public:
	//创建时间
	void SetCreateTime( const INT32& v );
	INT32 GetCreateTime();
	void SendCreateTime(bool OnlyToClient=true);
public:
	//最后登录时间
	void SetLastLoginTime( const INT32& v );
	INT32 GetLastLoginTime();
	void SendLastLoginTime(bool OnlyToClient=true);
public:
	//倒数第二登录日期
	void SetLast2LoginDate( const INT32& v );
	INT32 GetLast2LoginDate();
	void SendLast2LoginDate(bool OnlyToClient=true);
public:
	//最后登出时间
	void SetLastLogoutTime( const INT32& v );
	INT32 GetLastLogoutTime();
	void SendLastLogoutTime(bool OnlyToClient=true);
public:
	//游戏币
	void SetMoney( const INT32& v );
	INT32 GetMoney();
	void SendMoney(bool OnlyToClient=true);
public:
	//钻石
	void SetDiamond( const INT32& v );
	INT32 GetDiamond();
	void SendDiamond(bool OnlyToClient=true);
public:
	//体力
	void SetStrength( const INT32& v );
	INT32 GetStrength();
	void SendStrength(bool OnlyToClient=true);
public:
	//功勋
	void SetFeats( const INT32& v );
	INT32 GetFeats();
	void SendFeats(bool OnlyToClient=true);
public:
	//领取官阶奖励时间
	void SetGotRankRewardTime( const INT32& v );
	INT32 GetGotRankRewardTime();
	void SendGotRankRewardTime(bool OnlyToClient=true);
public:
	//历史最大战力
	void SetMaxMilitary( const INT32& v );
	INT32 GetMaxMilitary();
	void SendMaxMilitary(bool OnlyToClient=true);
public:
	//主公基础属性
	void SetMasterAttrs( const vector<INT32>& v );
	void SetMasterAttrs( int Index, const INT32& v );
	vector<INT32> GetMasterAttrs();
	INT32 GetMasterAttrs( int Index );
	void AddMasterAttrs( INT32 v=-1 );
	void SendMasterAttrs( int Index,bool OnlyToClient=true );
	void SendMasterAttrs(bool OnlyToClient=true);
	int  SizeMasterAttrs(){ return m_syncDataUserData.SizeMasterAttrs(); }
public:
	//当前玩家战力
	void SetCurMilitary( const INT32& v );
	INT32 GetCurMilitary();
	void SendCurMilitary(bool OnlyToClient=true);
public:
	//玩家名字
	void SetUserName( const string& v );
	string GetUserName();
	void SendUserName(bool OnlyToClient=true);
public:
	//用户ID
	void SetUserId( const INT64& v );
	INT64 GetUserId();
	void SendUserId(bool OnlyToClient=true);
public:
	//游戏中心账号名
	void SetPlatName( const string& v );
	string GetPlatName();
	void SendPlatName(bool OnlyToClient=true);
public:
	//游戏中心账号ID
	void SetAccountId( const INT64& v );
	INT64 GetAccountId();
	void SendAccountId(bool OnlyToClient=true);
public:
	//玩家等级
	void SetLevel( const INT32& v );
	INT32 GetLevel();
	void SendLevel(bool OnlyToClient=true);
public:
	//官阶
	void SetRank( const INT32& v );
	INT32 GetRank();
	void SendRank(bool OnlyToClient=true);
public:
	//战力
	void SetFightPower( const INT32& v );
	INT32 GetFightPower();
	void SendFightPower(bool OnlyToClient=true);
public:
	//用户累加的数据
	void SetSec( const INT32& v );
	INT32 GetSec();
	void SendSec(bool OnlyToClient=true);
public:
	//当前战力
	void SetMilitary( const INT32& v );
	INT32 GetMilitary();
	void SendMilitary(bool OnlyToClient=true);
public:
	//队伍Id
	void SetTeamId( const INT32& v );
	INT32 GetTeamId();
	void SendTeamId(bool OnlyToClient=true);
public:
	//职业
	void SetProf( const INT32& v );
	INT32 GetProf();
	void SendProf(bool OnlyToClient=true);
public:
	//副本剩余次数
	void SetDungeonRemainCount( const INT32& v );
	INT32 GetDungeonRemainCount();
	void SendDungeonRemainCount(bool OnlyToClient=true);
public:
	//地图Id
	void SetMapId( const INT32& v );
	INT32 GetMapId();
	void SendMapId(bool OnlyToClient=true);
public:
	//X坐标
	void SetPosX( const float& v );
	float GetPosX();
	void SendPosX(bool OnlyToClient=true);
public:
	//Y坐标
	void SetPosY( const float& v );
	float GetPosY();
	void SendPosY(bool OnlyToClient=true);
public:
	//Z坐标
	void SetPosZ( const float& v );
	float GetPosZ();
	void SendPosZ(bool OnlyToClient=true);
public:
	//位置方向
	void SetRy( const INT32& v );
	INT32 GetRy();
	void SendRy(bool OnlyToClient=true);
public:
	//技能CD列表
	void SetSkillCdArr( const vector<BaseAttrSkillCdInfoWraperV1>& v );
	void SetSkillCdArr( int Index, const BaseAttrSkillCdInfoWraperV1& v );
	vector<BaseAttrSkillCdInfoWraperV1> GetSkillCdArr();
	BaseAttrSkillCdInfoWraperV1 GetSkillCdArr( int Index );
	void AddSkillCdArr( const BaseAttrSkillCdInfoWraperV1& v);
	void SendSkillCdArr( int Index,bool OnlyToClient=true );
	void SendSkillCdArr(bool OnlyToClient=true);
	int  SizeSkillCdArr(){ return m_syncDataUserData.SizeSkillCdArr(); }
public:
	//BuffCD列表
	void SetBuffCdArr( const vector<BaseAttrBuffCdInfoWraperV1>& v );
	void SetBuffCdArr( int Index, const BaseAttrBuffCdInfoWraperV1& v );
	vector<BaseAttrBuffCdInfoWraperV1> GetBuffCdArr();
	BaseAttrBuffCdInfoWraperV1 GetBuffCdArr( int Index );
	void AddBuffCdArr( const BaseAttrBuffCdInfoWraperV1& v);
	void SendBuffCdArr( int Index,bool OnlyToClient=true );
	void SendBuffCdArr(bool OnlyToClient=true);
	int  SizeBuffCdArr(){ return m_syncDataUserData.SizeBuffCdArr(); }
public:
	//当前所在场景
	void SetCurrentScene( const BaseAttrSceneInfoWraperV1& v );
	BaseAttrSceneInfoWraperV1 GetCurrentScene();
	void SendCurrentScene(bool OnlyToClient=true);
public:
	//帮会Id
	void SetGuildId( const INT32& v );
	INT32 GetGuildId();
	void SendGuildId(bool OnlyToClient=true);
public:
	//退出帮会时间
	void SetExitGuildTime( const INT32& v );
	INT32 GetExitGuildTime();
	void SendExitGuildTime(bool OnlyToClient=true);
public:
	//申请过的帮会
	void SetApplyGuildId( const vector<INT32>& v );
	void SetApplyGuildId( int Index, const INT32& v );
	vector<INT32> GetApplyGuildId();
	INT32 GetApplyGuildId( int Index );
	void AddApplyGuildId( INT32 v=-1 );
	void SendApplyGuildId( int Index,bool OnlyToClient=true );
	void SendApplyGuildId(bool OnlyToClient=true);
	int  SizeApplyGuildId(){ return m_syncDataUserData.SizeApplyGuildId(); }
public:
	//当前帮贡
	void SetCurGuildContribution( const INT32& v );
	INT32 GetCurGuildContribution();
	void SendCurGuildContribution(bool OnlyToClient=true);
public:
	//最大帮贡
	void SetMaxGuildContribution( const INT32& v );
	INT32 GetMaxGuildContribution();
	void SendMaxGuildContribution(bool OnlyToClient=true);
public:
	//绑银
	void SetBindMoney( const INT32& v );
	INT32 GetBindMoney();
	void SendBindMoney(bool OnlyToClient=true);
public:
	//宝石
	void SetGem( const INT32& v );
	INT32 GetGem();
	void SendGem(bool OnlyToClient=true);
public:
	//服务器时间
	void SetServerTime( const INT32& v );
	INT32 GetServerTime();
	void SendServerTime(bool OnlyToClient=true);
public:
	//新手引导
	void SetNewbieGuide( const vector<KeyValue2IntIntWraper>& v );
	void SetNewbieGuide( int Index, const KeyValue2IntIntWraper& v );
	vector<KeyValue2IntIntWraper> GetNewbieGuide();
	KeyValue2IntIntWraper GetNewbieGuide( int Index );
	void AddNewbieGuide( const KeyValue2IntIntWraper& v);
	void SendNewbieGuide( int Index,bool OnlyToClient=true );
	void SendNewbieGuide(bool OnlyToClient=true);
	int  SizeNewbieGuide(){ return m_syncDataUserData.SizeNewbieGuide(); }
public:
	//江洋大盗奖励次数
	void SetThiefRewardNum( const INT32& v );
	INT32 GetThiefRewardNum();
	void SendThiefRewardNum(bool OnlyToClient=true);
public:
	//降妖奖励次数
	void SetSubdueMonsterRewardNum( const INT32& v );
	INT32 GetSubdueMonsterRewardNum();
	void SendSubdueMonsterRewardNum(bool OnlyToClient=true);
public:
	//世界Boss剩余次数
	void SetWorldBossRemainTimes( const INT32& v );
	INT32 GetWorldBossRemainTimes();
	void SendWorldBossRemainTimes(bool OnlyToClient=true);
public:
	//世界Boss伤害
	void SetWorldBossHurt( const INT32& v );
	INT32 GetWorldBossHurt();
	void SendWorldBossHurt(bool OnlyToClient=true);
public:
	//功能开启列表
	void SetFunctionOpenList( const vector<BaseAttrIconOpenInfoWraperV1>& v );
	void SetFunctionOpenList( int Index, const BaseAttrIconOpenInfoWraperV1& v );
	vector<BaseAttrIconOpenInfoWraperV1> GetFunctionOpenList();
	BaseAttrIconOpenInfoWraperV1 GetFunctionOpenList( int Index );
	void AddFunctionOpenList( const BaseAttrIconOpenInfoWraperV1& v);
	void SendFunctionOpenList( int Index,bool OnlyToClient=true );
	void SendFunctionOpenList(bool OnlyToClient=true);
	int  SizeFunctionOpenList(){ return m_syncDataUserData.SizeFunctionOpenList(); }
public:
	//总活力值
	void SetTotalEnergyValue( const INT32& v );
	INT32 GetTotalEnergyValue();
	void SendTotalEnergyValue(bool OnlyToClient=true);
public:
	//活力值信息容器
	void SetEnergyArray( const vector<BaseAttrEnergyInfoWraperV1>& v );
	void SetEnergyArray( int Index, const BaseAttrEnergyInfoWraperV1& v );
	vector<BaseAttrEnergyInfoWraperV1> GetEnergyArray();
	BaseAttrEnergyInfoWraperV1 GetEnergyArray( int Index );
	void AddEnergyArray( const BaseAttrEnergyInfoWraperV1& v);
	void SendEnergyArray( int Index,bool OnlyToClient=true );
	void SendEnergyArray(bool OnlyToClient=true);
	int  SizeEnergyArray(){ return m_syncDataUserData.SizeEnergyArray(); }
public:
	//PK状态
	void SetPKState( const INT32& v );
	INT32 GetPKState();
	void SendPKState(bool OnlyToClient=true);
public:
	//PK保护列表
	void SetPKProtect( const vector<KeyValue2IntBoolWraper>& v );
	void SetPKProtect( int Index, const KeyValue2IntBoolWraper& v );
	vector<KeyValue2IntBoolWraper> GetPKProtect();
	KeyValue2IntBoolWraper GetPKProtect( int Index );
	void AddPKProtect( const KeyValue2IntBoolWraper& v);
	void SendPKProtect( int Index,bool OnlyToClient=true );
	void SendPKProtect(bool OnlyToClient=true);
	int  SizePKProtect(){ return m_syncDataUserData.SizePKProtect(); }
public:
	//帮会修炼
	void SetGuildScienArray( const vector<BaseAttrScienceInfoWraperV1>& v );
	void SetGuildScienArray( int Index, const BaseAttrScienceInfoWraperV1& v );
	vector<BaseAttrScienceInfoWraperV1> GetGuildScienArray();
	BaseAttrScienceInfoWraperV1 GetGuildScienArray( int Index );
	void AddGuildScienArray( const BaseAttrScienceInfoWraperV1& v);
	void SendGuildScienArray( int Index,bool OnlyToClient=true );
	void SendGuildScienArray(bool OnlyToClient=true);
	int  SizeGuildScienArray(){ return m_syncDataUserData.SizeGuildScienArray(); }
public:
	//修炼升级消耗总金币
	void SetScienceTotalMoney( const INT32& v );
	INT32 GetScienceTotalMoney();
	void SendScienceTotalMoney(bool OnlyToClient=true);


private:
	BaseAttrUserDataWraperV1 m_syncDataUserData;

};



#endif
