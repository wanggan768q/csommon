#ifndef __ACTION_H
#define __ACTION_H
#include "BASE.h"
#include "FightRpcWraper.h"
#include "Position.h"
#include "EnumDefine.h"

//战斗核心动作枚举
enum KernelActionE
{
	ACTION_NOOP_TICK = 0,          //TICK驱动(服务器输入)
        ACTION_USESKILL, //使用技能动作
        ACTION_BUFF, //BUFF操作动作类
        ACTION_CHARHIT, //攻击动作
        ACTION_OFFLINE, //断线动作
        ACTION_STATE, //状态机动作
        ACTION_CHARDEAD, //角色死亡动作
        ACTION_CHARREVIVE, //角色复活动作
        ACTION_COMBOSKILL, //连击技能动作
        ACTION_ENDSKILL, //结束技能动作
        ACTION_CITY, //主城状态同步
        ACTION_SNIPE, //狙击动作
        ACTION_HURT, //伤害动作
        ACTION_DODGE, //闪避动作
        ACTION_REMOVEOBJ, //删除对像
        ACTION_STORMBASE, //暴风基地信息
        ACTION_STORMRES, //暴风资源信息
        ACTION_STORMFLAG, //暴风旗信息
        ACTION_STORMCAMP, //暴风阵营信息
        ACTION_STORMRESULT, //暴风战斗结果信息
        ACTION_CREATE, //创建对像动作
        ACTION_QUICKFINISH, //快速杀怪动作
        ACTION_FINISHLEVEL, //节点或副本结束
        ACTION_TOWERLOCK, //塔锁定对象动作
        ACTION_STORMSTART, //暴风战斗开始
        ACTION_ESCAPESTART, //大逃杀开始
        ACTION_ESCAPERESULT, //大逃杀结果
        ACTION_GMADDHP, //GM加减血量
        ACTION_TRANDSKILL, //所有人随机放技能
        ACTION_GUILDDBEGIN, //帮会副本开始
        ACTION_GUILDDEND, //帮会副本结束
        ACTION_TRANSFER, //场景间传送
        ACTION_HEROFIGHTINFO, //英雄战斗信息
        ACTION_GUILDFIGHTBEGIN, //帮会战开始
        ACTION_GUILDFIGHTEND, //帮会战结束
        ACTION_GUILDFIGHTHP, //帮会战阵营血量信息
        ACTION_EFFECTTRANSLATE, //移动控制动作
        ACTION_COLLECT, //采集
        ACTION_COLLECTIONSHOWEFFECT, //采集物是否播特效
        ACTION_AUTOFIGHT, //自动战斗
        ACTION_USEITEM, //使用道具
        ACTION_STORMKILLEFFECT, //五行旗杀人特效
        ACTION_ONEVSONESTART, //1V1开始
        ACTION_ONEVSONERESULT, //1V1结果
        ACTION_SIGHT, //视野变化
        ACTION_EVENTTRIGGER, //事件触发
        ACTION_QUIT, //QuitAction
        ACTION_PRODUCT, //生产
        ACTION_STARTEND, //开始结束

};


//动作基类
class Action
{
public:
	//构造函数
	Action()
	{
		ActionType = ACTION_NOOP_TICK;
	}
	virtual ~Action()
	{

	}
	virtual Action* Clone()
	{
		return nullptr; 
	}
	//序列化
	virtual int Serialize(MemStream& ms)
	{

		ms.SetPos(0);
		MemStream tmpStream;
		INT16 Len = 0;
		tmpStream.Write(&Len, 2);
		tmpStream.Write(&ActionType, 1);
		tmpStream.Write(&OccurTime, 4);
		string dataArr = GetWraperString();
		tmpStream.Write(dataArr.c_str(), dataArr.length());
		Len = (INT16)tmpStream.GetSize();
		tmpStream.SetPos(0);
		tmpStream.Write(&Len, 2);
		ms.Write(tmpStream.GetBuffer(), tmpStream.GetSize());

		return Len;
	}

	virtual string GetWraperString() const
	{
		return string();
	}

	virtual void SetWraperString(const char* pBuf, int size)
	{
	}

	virtual string strSerialize()
	{
		MemStream tmpStream;
		INT16 Len = 0;
		tmpStream.Write(&Len, 2);
		tmpStream.Write(&ActionType, 1);
		tmpStream.Write(&OccurTime, 4);
		string dataArr = GetWraperString();
		tmpStream.Write(dataArr.c_str(), dataArr.length());
		Len = (INT16)tmpStream.GetSize();
		tmpStream.SetPos(0);
		tmpStream.Write(&Len, 2);
		return string(tmpStream.GetBuffer(), tmpStream.GetSize());
	}

	virtual void Create(const string& buf)
	{
		const char* pBuff = buf.c_str();
		OccurTime = *((int*)(pBuff + 1));
		SetWraperString(pBuff + 5, buf.length() - 5);
	}

	//反序列化
	static Action* Deserialize(const string& buf);

	//动作类型
	INT32 OccurTime = 0;
	KernelActionE ActionType = ACTION_NOOP_TICK;
	INT64 UId = 0;
	bool IsServerFeed = false;
	int SenderObjId = -1;

};


#define DEFINE_ACTION( _ActionName, _WraperName,_ACT ) \
class _ActionName : public Action, public _WraperName \
{\
public:\
	_ActionName(){ActionType = _ACT;}\
	virtual ~_ActionName(){}\
	virtual string GetWraperString()const { return SerializeAsString(); } \
	virtual void SetWraperString(const char* pBuf, int size){ ParseFromArray(pBuf, size); }\
	virtual Action* Clone(){\
		_ActionName* pNew = new _ActionName();\
		pNew->OccurTime = OccurTime;\
		pNew->ActionType = ActionType;\
		pNew->UId = UId;\
		pNew->SenderObjId=SenderObjId;\
		pNew->IsServerFeed = IsServerFeed;\
		string ss = GetWraperString();\
		pNew->SetWraperString(ss.c_str(), ss.length());\
		return pNew;\
	}\
};

DEFINE_ACTION(UseSkillAction, FightUseSkillActionWraper,ACTION_USESKILL);
DEFINE_ACTION(BuffAction, FightBuffActionWraper,ACTION_BUFF);
DEFINE_ACTION(CharHitAction, FightCharHitActionWraper,ACTION_CHARHIT);
DEFINE_ACTION(OfflineAction, FightOfflineActionWraper,ACTION_OFFLINE);
DEFINE_ACTION(StateAction, FightStateActionWraper,ACTION_STATE);
DEFINE_ACTION(CharDeadAction, FightCharDeadActionWraper,ACTION_CHARDEAD);
DEFINE_ACTION(CharReviveAction, FightCharReviveActionWraper,ACTION_CHARREVIVE);
DEFINE_ACTION(ComboSkillAction, FightComboSkillActionWraper,ACTION_COMBOSKILL);
DEFINE_ACTION(EndSkillAction, FightEndSkillActionWraper,ACTION_ENDSKILL);
DEFINE_ACTION(CityAction, FightCityActionWraper,ACTION_CITY);
DEFINE_ACTION(SnipeAction, FightSnipeActionWraper,ACTION_SNIPE);
DEFINE_ACTION(HurtAction, FightHurtActionWraper,ACTION_HURT);
DEFINE_ACTION(DodgeAction, FightDodgeActionWraper,ACTION_DODGE);
DEFINE_ACTION(RemoveObjAction, FightRemoveObjActionWraper,ACTION_REMOVEOBJ);
DEFINE_ACTION(StormBaseAction, FightStormBaseActionWraper,ACTION_STORMBASE);
DEFINE_ACTION(StormResAction, FightStormResActionWraper,ACTION_STORMRES);
DEFINE_ACTION(StormFlagAction, FightStormFlagActionWraper,ACTION_STORMFLAG);
DEFINE_ACTION(StormCampAction, FightStormCampActionWraper,ACTION_STORMCAMP);
DEFINE_ACTION(StormResultAction, FightStormResultActionWraper,ACTION_STORMRESULT);
DEFINE_ACTION(CreateAction, FightCreateActionWraper,ACTION_CREATE);
DEFINE_ACTION(QuickFinishAction, FightQuickFinishActionWraper,ACTION_QUICKFINISH);
DEFINE_ACTION(FinishLevelAction, FightFinishLevelActionWraper,ACTION_FINISHLEVEL);
DEFINE_ACTION(TowerLockAction, FightTowerLockActionWraper,ACTION_TOWERLOCK);
DEFINE_ACTION(StormStartAction, FightStormStartActionWraper,ACTION_STORMSTART);
DEFINE_ACTION(EscapeStartAction, FightEscapeStartActionWraper,ACTION_ESCAPESTART);
DEFINE_ACTION(EscapeResultAction, FightEscapeResultActionWraper,ACTION_ESCAPERESULT);
DEFINE_ACTION(GMAddHpAction, FightGMAddHpActionWraper,ACTION_GMADDHP);
DEFINE_ACTION(TRandSkillAction, FightTRandSkillActionWraper,ACTION_TRANDSKILL);
DEFINE_ACTION(GuildDBeginAction, FightGuildDBeginActionWraper,ACTION_GUILDDBEGIN);
DEFINE_ACTION(GuildDEndAction, FightGuildDEndActionWraper,ACTION_GUILDDEND);
DEFINE_ACTION(TransferAction, FightTransferActionWraper,ACTION_TRANSFER);
DEFINE_ACTION(HeroFightInfoAction, FightHeroFightInfoActionWraper,ACTION_HEROFIGHTINFO);
DEFINE_ACTION(GuildFightBeginAction, FightGuildFightBeginActionWraper,ACTION_GUILDFIGHTBEGIN);
DEFINE_ACTION(GuildFightEndAction, FightGuildFightEndActionWraper,ACTION_GUILDFIGHTEND);
DEFINE_ACTION(GuildFightHpAction, FightGuildFightHpActionWraper,ACTION_GUILDFIGHTHP);
DEFINE_ACTION(EffectTranslateAction, FightEffectTranslateActionWraper,ACTION_EFFECTTRANSLATE);
DEFINE_ACTION(CollectAction, FightCollectActionWraper,ACTION_COLLECT);
DEFINE_ACTION(CollectionShowEffectAction, FightCollectionShowEffectActionWraper,ACTION_COLLECTIONSHOWEFFECT);
DEFINE_ACTION(AutoFightAction, FightAutoFightActionWraper,ACTION_AUTOFIGHT);
DEFINE_ACTION(UseItemAction, FightUseItemActionWraper,ACTION_USEITEM);
DEFINE_ACTION(StormKillEffectAction, FightStormKillEffectActionWraper,ACTION_STORMKILLEFFECT);
DEFINE_ACTION(OneVSOneStartAction, FightOneVSOneStartActionWraper,ACTION_ONEVSONESTART);
DEFINE_ACTION(OneVSOneResultAction, FightOneVSOneResultActionWraper,ACTION_ONEVSONERESULT);
DEFINE_ACTION(SightAction, FightSightActionWraper,ACTION_SIGHT);
DEFINE_ACTION(EventTriggerAction, FightEventTriggerActionWraper,ACTION_EVENTTRIGGER);
DEFINE_ACTION(QuitAction, FightQuitActionWraper,ACTION_QUIT);
DEFINE_ACTION(ProductAction, FightProductActionWraper,ACTION_PRODUCT);
DEFINE_ACTION(StartEndAction, FightStartEndActionWraper,ACTION_STARTEND);



#endif // !__ACTION_H
