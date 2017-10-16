/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperAction.h
* Author:       甘业清
* Description:  Action同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_ACTION_H
#define __SYNC_WRAPER_ACTION_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "ActionV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//V3封装类
class ActionV3WraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	ActionV3WraperV1()
	{
		
		m_X = 0;
		m_Y = 0;
		m_Z = 0;

	}
	//赋值构造函数
	ActionV3WraperV1(const ActionV3V1& v){ Init(v); }
	//等号重载函数
	void operator = (const ActionV3V1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActionV3V1 ToPB() const
	{
		ActionV3V1 v;
		v.set_x( m_X );
		v.set_y( m_Y );
		v.set_z( m_Z );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ActionV3V1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>X(X) [float]</li>\r\n";
		htmlBuff += "<li>Y(Y) [float]</li>\r\n";
		htmlBuff += "<li>Z(Z) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Y：%.2ff</li>\r\n",m_Y);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Z：%.2ff</li>\r\n",m_Z);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActionV3V1& v)
	{
		m_X = v.x();
		m_Y = v.y();
		m_Z = v.z();

	}

private:
	//X
	float m_X;
public:
	void SetX( float v)
	{
		m_X=v;
	}
	float GetX()
	{
		return m_X;
	}
	float GetX() const
	{
		return m_X;
	}
private:
	//Y
	float m_Y;
public:
	void SetY( float v)
	{
		m_Y=v;
	}
	float GetY()
	{
		return m_Y;
	}
	float GetY() const
	{
		return m_Y;
	}
private:
	//Z
	float m_Z;
public:
	void SetZ( float v)
	{
		m_Z=v;
	}
	float GetZ()
	{
		return m_Z;
	}
	float GetZ() const
	{
		return m_Z;
	}

};
//Range封装类
class ActionRangeWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	ActionRangeWraperV1()
	{
		
		m_MinValue = 0;
		m_MaxValue = 0;

	}
	//赋值构造函数
	ActionRangeWraperV1(const ActionRangeV1& v){ Init(v); }
	//等号重载函数
	void operator = (const ActionRangeV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActionRangeV1 ToPB() const
	{
		ActionRangeV1 v;
		v.set_minvalue( m_MinValue );
		v.set_maxvalue( m_MaxValue );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ActionRangeV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>MinValue(最小数) [float]</li>\r\n";
		htmlBuff += "<li>MaxValue(最大数) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>MinValue：%.2ff</li>\r\n",m_MinValue);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>MaxValue：%.2ff</li>\r\n",m_MaxValue);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActionRangeV1& v)
	{
		m_MinValue = v.minvalue();
		m_MaxValue = v.maxvalue();

	}

private:
	//最小数
	float m_MinValue;
public:
	void SetMinValue( float v)
	{
		m_MinValue=v;
	}
	float GetMinValue()
	{
		return m_MinValue;
	}
	float GetMinValue() const
	{
		return m_MinValue;
	}
private:
	//最大数
	float m_MaxValue;
public:
	void SetMaxValue( float v)
	{
		m_MaxValue=v;
	}
	float GetMaxValue()
	{
		return m_MaxValue;
	}
	float GetMaxValue() const
	{
		return m_MaxValue;
	}

};
//CommandInfo封装类
class ActionCommandInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	ActionCommandInfoWraperV1()
	{
		
		m_CommandType = -1;
		m_StartTime = 0;
		m_DurationTime = 0;
		m_AnimationTriggerCondition = 0;
		m_EffectName = "";
		m_EffectBoneHook = 0;
		m_EffectPositionOffset = ActionV3WraperV1();
		m_EffectStayInLocalSpace = false;
		m_EffectControlObjectId = 0;
		m_TranslateControlId = 0;
		m_TranslateOffset = ActionV3WraperV1();
		m_TranslateEase = 1;
		m_AttackShowHitEffect = false;
		m_AttackHitEffectName = "";
		m_AttackHitEffectDuration = 1.6;
		m_AttackFragmentCount = 1;
		m_AttackFragmentIntervalTime = 0;
		m_AttackDamageRadio = 1;
		m_BuffSelfActive = false;
		m_BuffTargetActive = false;
		m_AttackBehaviourBackDistance = 0;
		m_AttackBehaviourAirHeight = 0;
		m_EffectRotationOffset = ActionV3WraperV1();
		m_FlashControlObjectId = 0;
		m_AttackStiffTime = 0;
		m_AttackShake = false;
		m_AttackFlash = false;
		m_AttackBehaviourBackSpeed = 1;
		m_AttackBehaviourAirSpeed = 1;
		m_AttackBehaviourBack = false;
		m_AttackBehaviourAir = false;
		m_AttackBehaviourZoom = false;
		m_SoundName = "";
		m_Trigger = false;
		m_TriggerIndex = 1;
		m_AttackHitDummy = 0;
		m_AttackHitSound = "";
		m_HitShakeCameraXRange = 0;
		m_HitShakeCameraYRange = 0;
		m_HitShakeCameraCount = 1;
		m_HitShakeCameraDurationTime = 0.1;
		m_HiddenWeaponMode = 0;
		m_NextActionName = "";
		m_TranslateWrapMode = 0;
		m_IsTriggerSecondAttack = false;
		m_IsHitGround = false;
		m_SkillActionName = "";
		m_WarningRes1 = "";
		m_WarningRes2 = "";
		m_WarningMaxScale = ActionV3WraperV1();
		m_WarningScaleMode = 0;
		m_WarningLockAxle = 0;
		m_WarningPositionOffset = ActionV3WraperV1();
		m_IsEffectFollow = false;
		m_IsWarningTarget = false;
		m_AttackBehaviourAirDurationTime = 0;
		m_IsColliderDestroy = false;
		m_IsAttackRangeFollow = false;
		m_IsAnimationLoop = false;
		m_TranslateAngle = 0;
		m_IsAttackRangeShade = false;
		m_AttackInterval = 0;
		m_IsShowAttackRect = false;
		m_EffectBulletLaunchAngle = 0;
		m_EffectBulletSpeed = 0;
		m_EffectBulletLaunchTimeIntervalRange = ActionRangeWraperV1();
		m_EffectBulletMaxCout = 0;
		m_EffectBulletLifeTimeInteralRange = ActionRangeWraperV1();
		m_EffectBulletType = 0;
		m_EffectBulletLaunchMaxCount = 0;
		m_EffectBulletIsFollow = false;
		m_AttackBehaviourAirDownSpeed = 0;
		m_EffectDirectionLockType = 0;
		m_IsIrregularityEffect = false;
		m_EffectSize = ActionV3WraperV1();
		m_AttackRangePostion = ActionV3WraperV1();
		m_AttackRangeSize = ActionV3WraperV1();
		m_AttackShape = 0;
		m_AttackCircleOrigin = ActionV3WraperV1();
		m_AttackCircleRadius = 0;
		m_AttackCircleAngle = 0;

	}
	//赋值构造函数
	ActionCommandInfoWraperV1(const ActionCommandInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const ActionCommandInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActionCommandInfoV1 ToPB() const
	{
		ActionCommandInfoV1 v;
		v.set_commandtype( m_CommandType );
		v.set_starttime( m_StartTime );
		v.set_durationtime( m_DurationTime );
		v.set_animationtriggercondition( m_AnimationTriggerCondition );
		v.set_effectname( m_EffectName );
		v.set_effectbonehook( m_EffectBoneHook );
		*v.mutable_effectpositionoffset()= m_EffectPositionOffset.ToPB();
		v.set_effectstayinlocalspace( m_EffectStayInLocalSpace );
		v.set_effectcontrolobjectid( m_EffectControlObjectId );
		v.set_translatecontrolid( m_TranslateControlId );
		*v.mutable_translateoffset()= m_TranslateOffset.ToPB();
		v.mutable_actorattackpart()->Reserve(m_ActorAttackPart.size());
		for (int i=0; i<(int)m_ActorAttackPart.size(); i++)
		{
			v.add_actorattackpart(m_ActorAttackPart[i]);
		}
		v.set_translateease( m_TranslateEase );
		v.set_attackshowhiteffect( m_AttackShowHitEffect );
		v.set_attackhiteffectname( m_AttackHitEffectName );
		v.set_attackhiteffectduration( m_AttackHitEffectDuration );
		v.set_attackfragmentcount( m_AttackFragmentCount );
		v.set_attackfragmentintervaltime( m_AttackFragmentIntervalTime );
		v.set_attackdamageradio( m_AttackDamageRadio );
		v.set_buffselfactive( m_BuffSelfActive );
		v.set_bufftargetactive( m_BuffTargetActive );
		v.set_attackbehaviourbackdistance( m_AttackBehaviourBackDistance );
		v.set_attackbehaviourairheight( m_AttackBehaviourAirHeight );
		*v.mutable_effectrotationoffset()= m_EffectRotationOffset.ToPB();
		v.set_flashcontrolobjectid( m_FlashControlObjectId );
		v.set_attackstifftime( m_AttackStiffTime );
		v.set_attackshake( m_AttackShake );
		v.set_attackflash( m_AttackFlash );
		v.set_attackbehaviourbackspeed( m_AttackBehaviourBackSpeed );
		v.set_attackbehaviourairspeed( m_AttackBehaviourAirSpeed );
		v.set_attackbehaviourback( m_AttackBehaviourBack );
		v.set_attackbehaviourair( m_AttackBehaviourAir );
		v.set_attackbehaviourzoom( m_AttackBehaviourZoom );
		v.set_soundname( m_SoundName );
		v.set_trigger( m_Trigger );
		v.set_triggerindex( m_TriggerIndex );
		v.set_attackhitdummy( m_AttackHitDummy );
		v.set_attackhitsound( m_AttackHitSound );
		v.set_hitshakecameraxrange( m_HitShakeCameraXRange );
		v.set_hitshakecamerayrange( m_HitShakeCameraYRange );
		v.set_hitshakecameracount( m_HitShakeCameraCount );
		v.set_hitshakecameradurationtime( m_HitShakeCameraDurationTime );
		v.set_hiddenweaponmode( m_HiddenWeaponMode );
		v.set_nextactionname( m_NextActionName );
		v.set_translatewrapmode( m_TranslateWrapMode );
		v.set_istriggersecondattack( m_IsTriggerSecondAttack );
		v.set_ishitground( m_IsHitGround );
		v.set_skillactionname( m_SkillActionName );
		v.set_warningres1( m_WarningRes1 );
		v.set_warningres2( m_WarningRes2 );
		*v.mutable_warningmaxscale()= m_WarningMaxScale.ToPB();
		v.set_warningscalemode( m_WarningScaleMode );
		v.set_warninglockaxle( m_WarningLockAxle );
		*v.mutable_warningpositionoffset()= m_WarningPositionOffset.ToPB();
		v.set_iseffectfollow( m_IsEffectFollow );
		v.set_iswarningtarget( m_IsWarningTarget );
		v.set_attackbehaviourairdurationtime( m_AttackBehaviourAirDurationTime );
		v.set_iscolliderdestroy( m_IsColliderDestroy );
		v.set_isattackrangefollow( m_IsAttackRangeFollow );
		v.set_isanimationloop( m_IsAnimationLoop );
		v.set_translateangle( m_TranslateAngle );
		v.set_isattackrangeshade( m_IsAttackRangeShade );
		v.set_attackinterval( m_AttackInterval );
		v.set_isshowattackrect( m_IsShowAttackRect );
		v.set_effectbulletlaunchangle( m_EffectBulletLaunchAngle );
		v.set_effectbulletspeed( m_EffectBulletSpeed );
		*v.mutable_effectbulletlaunchtimeintervalrange()= m_EffectBulletLaunchTimeIntervalRange.ToPB();
		v.set_effectbulletmaxcout( m_EffectBulletMaxCout );
		*v.mutable_effectbulletlifetimeinteralrange()= m_EffectBulletLifeTimeInteralRange.ToPB();
		v.set_effectbullettype( m_EffectBulletType );
		v.mutable_effectbulletinitposlist()->Reserve(m_EffectBulletInitPosList.size());
		for (int i=0; i<(int)m_EffectBulletInitPosList.size(); i++)
		{
			*v.add_effectbulletinitposlist() = m_EffectBulletInitPosList[i].ToPB();
		}
		v.set_effectbulletlaunchmaxcount( m_EffectBulletLaunchMaxCount );
		v.set_effectbulletisfollow( m_EffectBulletIsFollow );
		v.set_attackbehaviourairdownspeed( m_AttackBehaviourAirDownSpeed );
		v.set_effectdirectionlocktype( m_EffectDirectionLockType );
		v.set_isirregularityeffect( m_IsIrregularityEffect );
		*v.mutable_effectsize()= m_EffectSize.ToPB();
		*v.mutable_attackrangepostion()= m_AttackRangePostion.ToPB();
		*v.mutable_attackrangesize()= m_AttackRangeSize.ToPB();
		v.set_attackshape( m_AttackShape );
		*v.mutable_attackcircleorigin()= m_AttackCircleOrigin.ToPB();
		v.set_attackcircleradius( m_AttackCircleRadius );
		v.set_attackcircleangle( m_AttackCircleAngle );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ActionCommandInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>CommandType(CommandType) [sint32]</li>\r\n";
		htmlBuff += "<li>StartTime(StartTime) [float]</li>\r\n";
		htmlBuff += "<li>DurationTime(DurationTime) [float]</li>\r\n";
		htmlBuff += "<li>AnimationTriggerCondition(AnimationTriggerCondition) [sint32]</li>\r\n";
		htmlBuff += "<li>EffectName(EffectName) [string]</li>\r\n";
		htmlBuff += "<li>EffectBoneHook(EffectBoneHook) [sint32]</li>\r\n";
		htmlBuff += "<li>EffectPositionOffset(EffectPositionOffset) [V3]</li>\r\n";
		htmlBuff += "<li>EffectStayInLocalSpace(EffectStayInLocalSpace) [bool]</li>\r\n";
		htmlBuff += "<li>EffectControlObjectId(EffectControlObjectId) [sint32]</li>\r\n";
		htmlBuff += "<li>TranslateControlId(TranslateControlId) [sint32]</li>\r\n";
		htmlBuff += "<li>TranslateOffset(TranslateOffset) [V3]</li>\r\n";
		htmlBuff += "<li>ActorAttackPart(ActorAttackPart) [sint32] Array</li>\r\n";
		htmlBuff += "<li>TranslateEase(TranslateEase) [sint32]</li>\r\n";
		htmlBuff += "<li>AttackShowHitEffect(AttackShowHitEffect) [bool]</li>\r\n";
		htmlBuff += "<li>AttackHitEffectName(AttackHitEffectName) [string]</li>\r\n";
		htmlBuff += "<li>AttackHitEffectDuration(AttackHitEffectDuration) [float]</li>\r\n";
		htmlBuff += "<li>AttackFragmentCount(AttackFragmentCount) [sint32]</li>\r\n";
		htmlBuff += "<li>AttackFragmentIntervalTime(AttackFragmentIntervalTime) [float]</li>\r\n";
		htmlBuff += "<li>AttackDamageRadio(AttackDamageRadio) [float]</li>\r\n";
		htmlBuff += "<li>BuffSelfActive(BuffSelfActive) [bool]</li>\r\n";
		htmlBuff += "<li>BuffTargetActive(BuffTargetActive) [bool]</li>\r\n";
		htmlBuff += "<li>AttackBehaviourBackDistance(AttackBehaviourBackDistance) [float]</li>\r\n";
		htmlBuff += "<li>AttackBehaviourAirHeight(AttackBehaviourAirHeight) [float]</li>\r\n";
		htmlBuff += "<li>EffectRotationOffset(EffectRotationOffset) [V3]</li>\r\n";
		htmlBuff += "<li>FlashControlObjectId(FlashControlObjectId) [sint32]</li>\r\n";
		htmlBuff += "<li>AttackStiffTime(AttackStiffTime) [float]</li>\r\n";
		htmlBuff += "<li>AttackShake(AttackShake) [bool]</li>\r\n";
		htmlBuff += "<li>AttackFlash(AttackFlash) [bool]</li>\r\n";
		htmlBuff += "<li>AttackBehaviourBackSpeed(AttackBehaviourBackSpeed) [float]</li>\r\n";
		htmlBuff += "<li>AttackBehaviourAirSpeed(AttackBehaviourAirSpped) [float]</li>\r\n";
		htmlBuff += "<li>AttackBehaviourBack(AttackBehaviourBack) [bool]</li>\r\n";
		htmlBuff += "<li>AttackBehaviourAir(AttackBehaviourAir) [bool]</li>\r\n";
		htmlBuff += "<li>AttackBehaviourZoom(AttackBehaviourZoom) [bool]</li>\r\n";
		htmlBuff += "<li>SoundName(SoundName) [string]</li>\r\n";
		htmlBuff += "<li>Trigger(Trigger) [bool]</li>\r\n";
		htmlBuff += "<li>TriggerIndex(TriggerIndex) [sint32]</li>\r\n";
		htmlBuff += "<li>AttackHitDummy(受击挂载点 1原点 2头 3 胸) [sint32]</li>\r\n";
		htmlBuff += "<li>AttackHitSound(受击音效) [string]</li>\r\n";
		htmlBuff += "<li>HitShakeCameraXRange(受击震动X范围) [float]</li>\r\n";
		htmlBuff += "<li>HitShakeCameraYRange(受击震动Y范围) [float]</li>\r\n";
		htmlBuff += "<li>HitShakeCameraCount(震屏次数) [sint32]</li>\r\n";
		htmlBuff += "<li>HitShakeCameraDurationTime(震屏时长) [float]</li>\r\n";
		htmlBuff += "<li>HiddenWeaponMode(隐藏武器) [sint32]</li>\r\n";
		htmlBuff += "<li>NextActionName(下个技能名字) [string]</li>\r\n";
		htmlBuff += "<li>TranslateWrapMode(位移类型) [sint32]</li>\r\n";
		htmlBuff += "<li>IsTriggerSecondAttack(是否触发触发器) [bool]</li>\r\n";
		htmlBuff += "<li>IsHitGround(受击是否倒地) [bool]</li>\r\n";
		htmlBuff += "<li>SkillActionName(技能编辑文件名字) [string]</li>\r\n";
		htmlBuff += "<li>WarningRes1(预警资源1) [string]</li>\r\n";
		htmlBuff += "<li>WarningRes2(预警资源2) [string]</li>\r\n";
		htmlBuff += "<li>WarningMaxScale(预警最大缩放) [V3]</li>\r\n";
		htmlBuff += "<li>WarningScaleMode(预警缩放模式) [sint32]</li>\r\n";
		htmlBuff += "<li>WarningLockAxle(锁定轴向) [sint32]</li>\r\n";
		htmlBuff += "<li>WarningPositionOffset(预警偏移) [V3]</li>\r\n";
		htmlBuff += "<li>IsEffectFollow(是否跟随旋转) [bool]</li>\r\n";
		htmlBuff += "<li>IsWarningTarget(预警是否需要目标) [bool]</li>\r\n";
		htmlBuff += "<li>AttackBehaviourAirDurationTime(浮空 空中持续时间) [float]</li>\r\n";
		htmlBuff += "<li>IsColliderDestroy(特效碰撞之后是否删除) [bool]</li>\r\n";
		htmlBuff += "<li>IsAttackRangeFollow(攻击范围是否跟随移动) [bool]</li>\r\n";
		htmlBuff += "<li>IsAnimationLoop(动画是否循环) [bool]</li>\r\n";
		htmlBuff += "<li>TranslateAngle(运动角度（0-360）) [float]</li>\r\n";
		htmlBuff += "<li>IsAttackRangeShade(是否是遮罩范围) [bool]</li>\r\n";
		htmlBuff += "<li>AttackInterval(攻击间隔时间) [float]</li>\r\n";
		htmlBuff += "<li>IsShowAttackRect(是否显示攻击矩形) [bool]</li>\r\n";
		htmlBuff += "<li>EffectBulletLaunchAngle(子弹发射角度) [float]</li>\r\n";
		htmlBuff += "<li>EffectBulletSpeed(子弹速度) [float]</li>\r\n";
		htmlBuff += "<li>EffectBulletLaunchTimeIntervalRange(每个弹道子弹发射时间间隔) [Range]</li>\r\n";
		htmlBuff += "<li>EffectBulletMaxCout(子弹总数量) [sint32]</li>\r\n";
		htmlBuff += "<li>EffectBulletLifeTimeInteralRange(子弹存活时间间隔) [Range]</li>\r\n";
		htmlBuff += "<li>EffectBulletType(子弹类型) [sint32]</li>\r\n";
		htmlBuff += "<li>EffectBulletInitPosList(子弹初始位置) [V3] Array</li>\r\n";
		htmlBuff += "<li>EffectBulletLaunchMaxCount(单个弹道发射最大数量) [sint32]</li>\r\n";
		htmlBuff += "<li>EffectBulletIsFollow(子弹是否跟随人物方向转向) [bool]</li>\r\n";
		htmlBuff += "<li>AttackBehaviourAirDownSpeed(浮空降落速度) [float]</li>\r\n";
		htmlBuff += "<li>EffectDirectionLockType(特效方向锁定类型) [sint32]</li>\r\n";
		htmlBuff += "<li>IsIrregularityEffect(是否是不规则特效) [bool]</li>\r\n";
		htmlBuff += "<li>EffectSize(特效size) [V3]</li>\r\n";
		htmlBuff += "<li>AttackRangePostion(攻击范围起点(右上点)) [V3]</li>\r\n";
		htmlBuff += "<li>AttackRangeSize(攻击范围的宽高) [V3]</li>\r\n";
		htmlBuff += "<li>AttackShape(攻击形状) [sint32]</li>\r\n";
		htmlBuff += "<li>AttackCircleOrigin(圆形攻击形状原点) [V3]</li>\r\n";
		htmlBuff += "<li>AttackCircleRadius(半径) [float]</li>\r\n";
		htmlBuff += "<li>AttackCircleAngle(角度) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>CommandType：%di</li>\r\n",m_CommandType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>StartTime：%.2ff</li>\r\n",m_StartTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DurationTime：%.2ff</li>\r\n",m_DurationTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AnimationTriggerCondition：%di</li>\r\n",m_AnimationTriggerCondition);
		htmlBuff += tmpLine;
		htmlBuff += "<li>EffectName：\""+m_EffectName+"\"</li>\r\n";
		tmpLine.Fmt("<li>EffectBoneHook：%di</li>\r\n",m_EffectBoneHook);
		htmlBuff += tmpLine;
		htmlBuff += "<li>EffectPositionOffset：</li>\r\n";
		htmlBuff += m_EffectPositionOffset.HtmlDescHeader();
		htmlBuff += m_EffectPositionOffset.ToHtml();
		tmpLine.Fmt("<li>EffectStayInLocalSpace：%di</li>\r\n",m_EffectStayInLocalSpace);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EffectControlObjectId：%di</li>\r\n",m_EffectControlObjectId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TranslateControlId：%di</li>\r\n",m_TranslateControlId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>TranslateOffset：</li>\r\n";
		htmlBuff += m_TranslateOffset.HtmlDescHeader();
		htmlBuff += m_TranslateOffset.ToHtml();
		htmlBuff += "<li>ActorAttackPart：</li>\r\n";
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n<tr>\r\n";
		for( int i=0; i<(int)m_ActorAttackPart.size(); i++){
			tmpLine.Fmt("<td>%di</td>\r\n",m_ActorAttackPart[i]);
			htmlBuff += tmpLine;
			if((i+1)%10==0) htmlBuff += "</tr>\r\n<tr>";
		}
		if( (m_ActorAttackPart.size() +1)%10 != 0 ) htmlBuff += "</tr>";
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>TranslateEase：%di</li>\r\n",m_TranslateEase);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackShowHitEffect：%di</li>\r\n",m_AttackShowHitEffect);
		htmlBuff += tmpLine;
		htmlBuff += "<li>AttackHitEffectName：\""+m_AttackHitEffectName+"\"</li>\r\n";
		tmpLine.Fmt("<li>AttackHitEffectDuration：%.2ff</li>\r\n",m_AttackHitEffectDuration);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackFragmentCount：%di</li>\r\n",m_AttackFragmentCount);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackFragmentIntervalTime：%.2ff</li>\r\n",m_AttackFragmentIntervalTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackDamageRadio：%.2ff</li>\r\n",m_AttackDamageRadio);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BuffSelfActive：%di</li>\r\n",m_BuffSelfActive);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>BuffTargetActive：%di</li>\r\n",m_BuffTargetActive);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackBehaviourBackDistance：%.2ff</li>\r\n",m_AttackBehaviourBackDistance);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackBehaviourAirHeight：%.2ff</li>\r\n",m_AttackBehaviourAirHeight);
		htmlBuff += tmpLine;
		htmlBuff += "<li>EffectRotationOffset：</li>\r\n";
		htmlBuff += m_EffectRotationOffset.HtmlDescHeader();
		htmlBuff += m_EffectRotationOffset.ToHtml();
		tmpLine.Fmt("<li>FlashControlObjectId：%di</li>\r\n",m_FlashControlObjectId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackStiffTime：%.2ff</li>\r\n",m_AttackStiffTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackShake：%di</li>\r\n",m_AttackShake);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackFlash：%di</li>\r\n",m_AttackFlash);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackBehaviourBackSpeed：%.2ff</li>\r\n",m_AttackBehaviourBackSpeed);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackBehaviourAirSpeed：%.2ff</li>\r\n",m_AttackBehaviourAirSpeed);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackBehaviourBack：%di</li>\r\n",m_AttackBehaviourBack);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackBehaviourAir：%di</li>\r\n",m_AttackBehaviourAir);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackBehaviourZoom：%di</li>\r\n",m_AttackBehaviourZoom);
		htmlBuff += tmpLine;
		htmlBuff += "<li>SoundName：\""+m_SoundName+"\"</li>\r\n";
		tmpLine.Fmt("<li>Trigger：%di</li>\r\n",m_Trigger);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TriggerIndex：%di</li>\r\n",m_TriggerIndex);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackHitDummy：%di</li>\r\n",m_AttackHitDummy);
		htmlBuff += tmpLine;
		htmlBuff += "<li>AttackHitSound：\""+m_AttackHitSound+"\"</li>\r\n";
		tmpLine.Fmt("<li>HitShakeCameraXRange：%.2ff</li>\r\n",m_HitShakeCameraXRange);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>HitShakeCameraYRange：%.2ff</li>\r\n",m_HitShakeCameraYRange);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>HitShakeCameraCount：%di</li>\r\n",m_HitShakeCameraCount);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>HitShakeCameraDurationTime：%.2ff</li>\r\n",m_HitShakeCameraDurationTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>HiddenWeaponMode：%di</li>\r\n",m_HiddenWeaponMode);
		htmlBuff += tmpLine;
		htmlBuff += "<li>NextActionName：\""+m_NextActionName+"\"</li>\r\n";
		tmpLine.Fmt("<li>TranslateWrapMode：%di</li>\r\n",m_TranslateWrapMode);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsTriggerSecondAttack：%di</li>\r\n",m_IsTriggerSecondAttack);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsHitGround：%di</li>\r\n",m_IsHitGround);
		htmlBuff += tmpLine;
		htmlBuff += "<li>SkillActionName：\""+m_SkillActionName+"\"</li>\r\n";
		htmlBuff += "<li>WarningRes1：\""+m_WarningRes1+"\"</li>\r\n";
		htmlBuff += "<li>WarningRes2：\""+m_WarningRes2+"\"</li>\r\n";
		htmlBuff += "<li>WarningMaxScale：</li>\r\n";
		htmlBuff += m_WarningMaxScale.HtmlDescHeader();
		htmlBuff += m_WarningMaxScale.ToHtml();
		tmpLine.Fmt("<li>WarningScaleMode：%di</li>\r\n",m_WarningScaleMode);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>WarningLockAxle：%di</li>\r\n",m_WarningLockAxle);
		htmlBuff += tmpLine;
		htmlBuff += "<li>WarningPositionOffset：</li>\r\n";
		htmlBuff += m_WarningPositionOffset.HtmlDescHeader();
		htmlBuff += m_WarningPositionOffset.ToHtml();
		tmpLine.Fmt("<li>IsEffectFollow：%di</li>\r\n",m_IsEffectFollow);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsWarningTarget：%di</li>\r\n",m_IsWarningTarget);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackBehaviourAirDurationTime：%.2ff</li>\r\n",m_AttackBehaviourAirDurationTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsColliderDestroy：%di</li>\r\n",m_IsColliderDestroy);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsAttackRangeFollow：%di</li>\r\n",m_IsAttackRangeFollow);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsAnimationLoop：%di</li>\r\n",m_IsAnimationLoop);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TranslateAngle：%.2ff</li>\r\n",m_TranslateAngle);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsAttackRangeShade：%di</li>\r\n",m_IsAttackRangeShade);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackInterval：%.2ff</li>\r\n",m_AttackInterval);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsShowAttackRect：%di</li>\r\n",m_IsShowAttackRect);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EffectBulletLaunchAngle：%.2ff</li>\r\n",m_EffectBulletLaunchAngle);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EffectBulletSpeed：%.2ff</li>\r\n",m_EffectBulletSpeed);
		htmlBuff += tmpLine;
		htmlBuff += "<li>EffectBulletLaunchTimeIntervalRange：</li>\r\n";
		htmlBuff += m_EffectBulletLaunchTimeIntervalRange.HtmlDescHeader();
		htmlBuff += m_EffectBulletLaunchTimeIntervalRange.ToHtml();
		tmpLine.Fmt("<li>EffectBulletMaxCout：%di</li>\r\n",m_EffectBulletMaxCout);
		htmlBuff += tmpLine;
		htmlBuff += "<li>EffectBulletLifeTimeInteralRange：</li>\r\n";
		htmlBuff += m_EffectBulletLifeTimeInteralRange.HtmlDescHeader();
		htmlBuff += m_EffectBulletLifeTimeInteralRange.ToHtml();
		tmpLine.Fmt("<li>EffectBulletType：%di</li>\r\n",m_EffectBulletType);
		htmlBuff += tmpLine;
		htmlBuff += "<li>EffectBulletInitPosList：</li>\r\n";
		if( m_EffectBulletInitPosList.size()>0) htmlBuff += m_EffectBulletInitPosList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_EffectBulletInitPosList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_EffectBulletInitPosList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>EffectBulletLaunchMaxCount：%di</li>\r\n",m_EffectBulletLaunchMaxCount);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EffectBulletIsFollow：%di</li>\r\n",m_EffectBulletIsFollow);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackBehaviourAirDownSpeed：%.2ff</li>\r\n",m_AttackBehaviourAirDownSpeed);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>EffectDirectionLockType：%di</li>\r\n",m_EffectDirectionLockType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsIrregularityEffect：%di</li>\r\n",m_IsIrregularityEffect);
		htmlBuff += tmpLine;
		htmlBuff += "<li>EffectSize：</li>\r\n";
		htmlBuff += m_EffectSize.HtmlDescHeader();
		htmlBuff += m_EffectSize.ToHtml();
		htmlBuff += "<li>AttackRangePostion：</li>\r\n";
		htmlBuff += m_AttackRangePostion.HtmlDescHeader();
		htmlBuff += m_AttackRangePostion.ToHtml();
		htmlBuff += "<li>AttackRangeSize：</li>\r\n";
		htmlBuff += m_AttackRangeSize.HtmlDescHeader();
		htmlBuff += m_AttackRangeSize.ToHtml();
		tmpLine.Fmt("<li>AttackShape：%di</li>\r\n",m_AttackShape);
		htmlBuff += tmpLine;
		htmlBuff += "<li>AttackCircleOrigin：</li>\r\n";
		htmlBuff += m_AttackCircleOrigin.HtmlDescHeader();
		htmlBuff += m_AttackCircleOrigin.ToHtml();
		tmpLine.Fmt("<li>AttackCircleRadius：%.2ff</li>\r\n",m_AttackCircleRadius);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>AttackCircleAngle：%.2ff</li>\r\n",m_AttackCircleAngle);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActionCommandInfoV1& v)
	{
		m_CommandType = v.commandtype();
		m_StartTime = v.starttime();
		m_DurationTime = v.durationtime();
		m_AnimationTriggerCondition = v.animationtriggercondition();
		m_EffectName = v.effectname();
		m_EffectBoneHook = v.effectbonehook();
		m_EffectPositionOffset = v.effectpositionoffset();
		m_EffectStayInLocalSpace = v.effectstayinlocalspace();
		m_EffectControlObjectId = v.effectcontrolobjectid();
		m_TranslateControlId = v.translatecontrolid();
		m_TranslateOffset = v.translateoffset();
		m_ActorAttackPart.clear();
		m_ActorAttackPart.reserve(v.actorattackpart_size());
		for( int i=0; i<v.actorattackpart_size(); i++)
			m_ActorAttackPart.push_back(v.actorattackpart(i));
		m_TranslateEase = v.translateease();
		m_AttackShowHitEffect = v.attackshowhiteffect();
		m_AttackHitEffectName = v.attackhiteffectname();
		m_AttackHitEffectDuration = v.attackhiteffectduration();
		m_AttackFragmentCount = v.attackfragmentcount();
		m_AttackFragmentIntervalTime = v.attackfragmentintervaltime();
		m_AttackDamageRadio = v.attackdamageradio();
		m_BuffSelfActive = v.buffselfactive();
		m_BuffTargetActive = v.bufftargetactive();
		m_AttackBehaviourBackDistance = v.attackbehaviourbackdistance();
		m_AttackBehaviourAirHeight = v.attackbehaviourairheight();
		m_EffectRotationOffset = v.effectrotationoffset();
		m_FlashControlObjectId = v.flashcontrolobjectid();
		m_AttackStiffTime = v.attackstifftime();
		m_AttackShake = v.attackshake();
		m_AttackFlash = v.attackflash();
		m_AttackBehaviourBackSpeed = v.attackbehaviourbackspeed();
		m_AttackBehaviourAirSpeed = v.attackbehaviourairspeed();
		m_AttackBehaviourBack = v.attackbehaviourback();
		m_AttackBehaviourAir = v.attackbehaviourair();
		m_AttackBehaviourZoom = v.attackbehaviourzoom();
		m_SoundName = v.soundname();
		m_Trigger = v.trigger();
		m_TriggerIndex = v.triggerindex();
		m_AttackHitDummy = v.attackhitdummy();
		m_AttackHitSound = v.attackhitsound();
		m_HitShakeCameraXRange = v.hitshakecameraxrange();
		m_HitShakeCameraYRange = v.hitshakecamerayrange();
		m_HitShakeCameraCount = v.hitshakecameracount();
		m_HitShakeCameraDurationTime = v.hitshakecameradurationtime();
		m_HiddenWeaponMode = v.hiddenweaponmode();
		m_NextActionName = v.nextactionname();
		m_TranslateWrapMode = v.translatewrapmode();
		m_IsTriggerSecondAttack = v.istriggersecondattack();
		m_IsHitGround = v.ishitground();
		m_SkillActionName = v.skillactionname();
		m_WarningRes1 = v.warningres1();
		m_WarningRes2 = v.warningres2();
		m_WarningMaxScale = v.warningmaxscale();
		m_WarningScaleMode = v.warningscalemode();
		m_WarningLockAxle = v.warninglockaxle();
		m_WarningPositionOffset = v.warningpositionoffset();
		m_IsEffectFollow = v.iseffectfollow();
		m_IsWarningTarget = v.iswarningtarget();
		m_AttackBehaviourAirDurationTime = v.attackbehaviourairdurationtime();
		m_IsColliderDestroy = v.iscolliderdestroy();
		m_IsAttackRangeFollow = v.isattackrangefollow();
		m_IsAnimationLoop = v.isanimationloop();
		m_TranslateAngle = v.translateangle();
		m_IsAttackRangeShade = v.isattackrangeshade();
		m_AttackInterval = v.attackinterval();
		m_IsShowAttackRect = v.isshowattackrect();
		m_EffectBulletLaunchAngle = v.effectbulletlaunchangle();
		m_EffectBulletSpeed = v.effectbulletspeed();
		m_EffectBulletLaunchTimeIntervalRange = v.effectbulletlaunchtimeintervalrange();
		m_EffectBulletMaxCout = v.effectbulletmaxcout();
		m_EffectBulletLifeTimeInteralRange = v.effectbulletlifetimeinteralrange();
		m_EffectBulletType = v.effectbullettype();
		m_EffectBulletInitPosList.clear();
		m_EffectBulletInitPosList.reserve(v.effectbulletinitposlist_size());
		for( int i=0; i<v.effectbulletinitposlist_size(); i++)
			m_EffectBulletInitPosList.push_back(v.effectbulletinitposlist(i));
		m_EffectBulletLaunchMaxCount = v.effectbulletlaunchmaxcount();
		m_EffectBulletIsFollow = v.effectbulletisfollow();
		m_AttackBehaviourAirDownSpeed = v.attackbehaviourairdownspeed();
		m_EffectDirectionLockType = v.effectdirectionlocktype();
		m_IsIrregularityEffect = v.isirregularityeffect();
		m_EffectSize = v.effectsize();
		m_AttackRangePostion = v.attackrangepostion();
		m_AttackRangeSize = v.attackrangesize();
		m_AttackShape = v.attackshape();
		m_AttackCircleOrigin = v.attackcircleorigin();
		m_AttackCircleRadius = v.attackcircleradius();
		m_AttackCircleAngle = v.attackcircleangle();

	}

private:
	//CommandType
	INT32 m_CommandType;
public:
	void SetCommandType( INT32 v)
	{
		m_CommandType=v;
	}
	INT32 GetCommandType()
	{
		return m_CommandType;
	}
	INT32 GetCommandType() const
	{
		return m_CommandType;
	}
private:
	//StartTime
	float m_StartTime;
public:
	void SetStartTime( float v)
	{
		m_StartTime=v;
	}
	float GetStartTime()
	{
		return m_StartTime;
	}
	float GetStartTime() const
	{
		return m_StartTime;
	}
private:
	//DurationTime
	float m_DurationTime;
public:
	void SetDurationTime( float v)
	{
		m_DurationTime=v;
	}
	float GetDurationTime()
	{
		return m_DurationTime;
	}
	float GetDurationTime() const
	{
		return m_DurationTime;
	}
private:
	//AnimationTriggerCondition
	INT32 m_AnimationTriggerCondition;
public:
	void SetAnimationTriggerCondition( INT32 v)
	{
		m_AnimationTriggerCondition=v;
	}
	INT32 GetAnimationTriggerCondition()
	{
		return m_AnimationTriggerCondition;
	}
	INT32 GetAnimationTriggerCondition() const
	{
		return m_AnimationTriggerCondition;
	}
private:
	//EffectName
	string m_EffectName;
public:
	void SetEffectName( const string& v)
	{
		m_EffectName=v;
	}
	string GetEffectName()
	{
		return m_EffectName;
	}
	string GetEffectName() const
	{
		return m_EffectName;
	}
private:
	//EffectBoneHook
	INT32 m_EffectBoneHook;
public:
	void SetEffectBoneHook( INT32 v)
	{
		m_EffectBoneHook=v;
	}
	INT32 GetEffectBoneHook()
	{
		return m_EffectBoneHook;
	}
	INT32 GetEffectBoneHook() const
	{
		return m_EffectBoneHook;
	}
private:
	//EffectPositionOffset
	ActionV3WraperV1 m_EffectPositionOffset;
public:
	void SetEffectPositionOffset( const ActionV3WraperV1& v)
	{
		m_EffectPositionOffset=v;
	}
	ActionV3WraperV1 GetEffectPositionOffset()
	{
		return m_EffectPositionOffset;
	}
	ActionV3WraperV1 GetEffectPositionOffset() const
	{
		return m_EffectPositionOffset;
	}
private:
	//EffectStayInLocalSpace
	bool m_EffectStayInLocalSpace;
public:
	void SetEffectStayInLocalSpace( bool v)
	{
		m_EffectStayInLocalSpace=v;
	}
	bool GetEffectStayInLocalSpace()
	{
		return m_EffectStayInLocalSpace;
	}
	bool GetEffectStayInLocalSpace() const
	{
		return m_EffectStayInLocalSpace;
	}
private:
	//EffectControlObjectId
	INT32 m_EffectControlObjectId;
public:
	void SetEffectControlObjectId( INT32 v)
	{
		m_EffectControlObjectId=v;
	}
	INT32 GetEffectControlObjectId()
	{
		return m_EffectControlObjectId;
	}
	INT32 GetEffectControlObjectId() const
	{
		return m_EffectControlObjectId;
	}
private:
	//TranslateControlId
	INT32 m_TranslateControlId;
public:
	void SetTranslateControlId( INT32 v)
	{
		m_TranslateControlId=v;
	}
	INT32 GetTranslateControlId()
	{
		return m_TranslateControlId;
	}
	INT32 GetTranslateControlId() const
	{
		return m_TranslateControlId;
	}
private:
	//TranslateOffset
	ActionV3WraperV1 m_TranslateOffset;
public:
	void SetTranslateOffset( const ActionV3WraperV1& v)
	{
		m_TranslateOffset=v;
	}
	ActionV3WraperV1 GetTranslateOffset()
	{
		return m_TranslateOffset;
	}
	ActionV3WraperV1 GetTranslateOffset() const
	{
		return m_TranslateOffset;
	}
private:
	//ActorAttackPart
	vector<INT32> m_ActorAttackPart;
public:
	int SizeActorAttackPart()
	{
		return m_ActorAttackPart.size();
	}
	const vector<INT32>& GetActorAttackPart() const
	{
		return m_ActorAttackPart;
	}
	INT32 GetActorAttackPart(int Index) const
	{
		if(Index<0 || Index>=(int)m_ActorAttackPart.size())
		{
			assert(false);
			return INT32();
		}
		return m_ActorAttackPart[Index];
	}
	void SetActorAttackPart( const vector<INT32>& v )
	{
		m_ActorAttackPart=v;
	}
	void ClearActorAttackPart( )
	{
		m_ActorAttackPart.clear();
	}
	void SetActorAttackPart( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_ActorAttackPart.size())
		{
			assert(false);
			return;
		}
		m_ActorAttackPart[Index] = v;
	}
	void AddActorAttackPart( INT32 v = 0 )
	{
		m_ActorAttackPart.push_back(v);
	}
private:
	//TranslateEase
	INT32 m_TranslateEase;
public:
	void SetTranslateEase( INT32 v)
	{
		m_TranslateEase=v;
	}
	INT32 GetTranslateEase()
	{
		return m_TranslateEase;
	}
	INT32 GetTranslateEase() const
	{
		return m_TranslateEase;
	}
private:
	//AttackShowHitEffect
	bool m_AttackShowHitEffect;
public:
	void SetAttackShowHitEffect( bool v)
	{
		m_AttackShowHitEffect=v;
	}
	bool GetAttackShowHitEffect()
	{
		return m_AttackShowHitEffect;
	}
	bool GetAttackShowHitEffect() const
	{
		return m_AttackShowHitEffect;
	}
private:
	//AttackHitEffectName
	string m_AttackHitEffectName;
public:
	void SetAttackHitEffectName( const string& v)
	{
		m_AttackHitEffectName=v;
	}
	string GetAttackHitEffectName()
	{
		return m_AttackHitEffectName;
	}
	string GetAttackHitEffectName() const
	{
		return m_AttackHitEffectName;
	}
private:
	//AttackHitEffectDuration
	float m_AttackHitEffectDuration;
public:
	void SetAttackHitEffectDuration( float v)
	{
		m_AttackHitEffectDuration=v;
	}
	float GetAttackHitEffectDuration()
	{
		return m_AttackHitEffectDuration;
	}
	float GetAttackHitEffectDuration() const
	{
		return m_AttackHitEffectDuration;
	}
private:
	//AttackFragmentCount
	INT32 m_AttackFragmentCount;
public:
	void SetAttackFragmentCount( INT32 v)
	{
		m_AttackFragmentCount=v;
	}
	INT32 GetAttackFragmentCount()
	{
		return m_AttackFragmentCount;
	}
	INT32 GetAttackFragmentCount() const
	{
		return m_AttackFragmentCount;
	}
private:
	//AttackFragmentIntervalTime
	float m_AttackFragmentIntervalTime;
public:
	void SetAttackFragmentIntervalTime( float v)
	{
		m_AttackFragmentIntervalTime=v;
	}
	float GetAttackFragmentIntervalTime()
	{
		return m_AttackFragmentIntervalTime;
	}
	float GetAttackFragmentIntervalTime() const
	{
		return m_AttackFragmentIntervalTime;
	}
private:
	//AttackDamageRadio
	float m_AttackDamageRadio;
public:
	void SetAttackDamageRadio( float v)
	{
		m_AttackDamageRadio=v;
	}
	float GetAttackDamageRadio()
	{
		return m_AttackDamageRadio;
	}
	float GetAttackDamageRadio() const
	{
		return m_AttackDamageRadio;
	}
private:
	//BuffSelfActive
	bool m_BuffSelfActive;
public:
	void SetBuffSelfActive( bool v)
	{
		m_BuffSelfActive=v;
	}
	bool GetBuffSelfActive()
	{
		return m_BuffSelfActive;
	}
	bool GetBuffSelfActive() const
	{
		return m_BuffSelfActive;
	}
private:
	//BuffTargetActive
	bool m_BuffTargetActive;
public:
	void SetBuffTargetActive( bool v)
	{
		m_BuffTargetActive=v;
	}
	bool GetBuffTargetActive()
	{
		return m_BuffTargetActive;
	}
	bool GetBuffTargetActive() const
	{
		return m_BuffTargetActive;
	}
private:
	//AttackBehaviourBackDistance
	float m_AttackBehaviourBackDistance;
public:
	void SetAttackBehaviourBackDistance( float v)
	{
		m_AttackBehaviourBackDistance=v;
	}
	float GetAttackBehaviourBackDistance()
	{
		return m_AttackBehaviourBackDistance;
	}
	float GetAttackBehaviourBackDistance() const
	{
		return m_AttackBehaviourBackDistance;
	}
private:
	//AttackBehaviourAirHeight
	float m_AttackBehaviourAirHeight;
public:
	void SetAttackBehaviourAirHeight( float v)
	{
		m_AttackBehaviourAirHeight=v;
	}
	float GetAttackBehaviourAirHeight()
	{
		return m_AttackBehaviourAirHeight;
	}
	float GetAttackBehaviourAirHeight() const
	{
		return m_AttackBehaviourAirHeight;
	}
private:
	//EffectRotationOffset
	ActionV3WraperV1 m_EffectRotationOffset;
public:
	void SetEffectRotationOffset( const ActionV3WraperV1& v)
	{
		m_EffectRotationOffset=v;
	}
	ActionV3WraperV1 GetEffectRotationOffset()
	{
		return m_EffectRotationOffset;
	}
	ActionV3WraperV1 GetEffectRotationOffset() const
	{
		return m_EffectRotationOffset;
	}
private:
	//FlashControlObjectId
	INT32 m_FlashControlObjectId;
public:
	void SetFlashControlObjectId( INT32 v)
	{
		m_FlashControlObjectId=v;
	}
	INT32 GetFlashControlObjectId()
	{
		return m_FlashControlObjectId;
	}
	INT32 GetFlashControlObjectId() const
	{
		return m_FlashControlObjectId;
	}
private:
	//AttackStiffTime
	float m_AttackStiffTime;
public:
	void SetAttackStiffTime( float v)
	{
		m_AttackStiffTime=v;
	}
	float GetAttackStiffTime()
	{
		return m_AttackStiffTime;
	}
	float GetAttackStiffTime() const
	{
		return m_AttackStiffTime;
	}
private:
	//AttackShake
	bool m_AttackShake;
public:
	void SetAttackShake( bool v)
	{
		m_AttackShake=v;
	}
	bool GetAttackShake()
	{
		return m_AttackShake;
	}
	bool GetAttackShake() const
	{
		return m_AttackShake;
	}
private:
	//AttackFlash
	bool m_AttackFlash;
public:
	void SetAttackFlash( bool v)
	{
		m_AttackFlash=v;
	}
	bool GetAttackFlash()
	{
		return m_AttackFlash;
	}
	bool GetAttackFlash() const
	{
		return m_AttackFlash;
	}
private:
	//AttackBehaviourBackSpeed
	float m_AttackBehaviourBackSpeed;
public:
	void SetAttackBehaviourBackSpeed( float v)
	{
		m_AttackBehaviourBackSpeed=v;
	}
	float GetAttackBehaviourBackSpeed()
	{
		return m_AttackBehaviourBackSpeed;
	}
	float GetAttackBehaviourBackSpeed() const
	{
		return m_AttackBehaviourBackSpeed;
	}
private:
	//AttackBehaviourAirSpped
	float m_AttackBehaviourAirSpeed;
public:
	void SetAttackBehaviourAirSpeed( float v)
	{
		m_AttackBehaviourAirSpeed=v;
	}
	float GetAttackBehaviourAirSpeed()
	{
		return m_AttackBehaviourAirSpeed;
	}
	float GetAttackBehaviourAirSpeed() const
	{
		return m_AttackBehaviourAirSpeed;
	}
private:
	//AttackBehaviourBack
	bool m_AttackBehaviourBack;
public:
	void SetAttackBehaviourBack( bool v)
	{
		m_AttackBehaviourBack=v;
	}
	bool GetAttackBehaviourBack()
	{
		return m_AttackBehaviourBack;
	}
	bool GetAttackBehaviourBack() const
	{
		return m_AttackBehaviourBack;
	}
private:
	//AttackBehaviourAir
	bool m_AttackBehaviourAir;
public:
	void SetAttackBehaviourAir( bool v)
	{
		m_AttackBehaviourAir=v;
	}
	bool GetAttackBehaviourAir()
	{
		return m_AttackBehaviourAir;
	}
	bool GetAttackBehaviourAir() const
	{
		return m_AttackBehaviourAir;
	}
private:
	//AttackBehaviourZoom
	bool m_AttackBehaviourZoom;
public:
	void SetAttackBehaviourZoom( bool v)
	{
		m_AttackBehaviourZoom=v;
	}
	bool GetAttackBehaviourZoom()
	{
		return m_AttackBehaviourZoom;
	}
	bool GetAttackBehaviourZoom() const
	{
		return m_AttackBehaviourZoom;
	}
private:
	//SoundName
	string m_SoundName;
public:
	void SetSoundName( const string& v)
	{
		m_SoundName=v;
	}
	string GetSoundName()
	{
		return m_SoundName;
	}
	string GetSoundName() const
	{
		return m_SoundName;
	}
private:
	//Trigger
	bool m_Trigger;
public:
	void SetTrigger( bool v)
	{
		m_Trigger=v;
	}
	bool GetTrigger()
	{
		return m_Trigger;
	}
	bool GetTrigger() const
	{
		return m_Trigger;
	}
private:
	//TriggerIndex
	INT32 m_TriggerIndex;
public:
	void SetTriggerIndex( INT32 v)
	{
		m_TriggerIndex=v;
	}
	INT32 GetTriggerIndex()
	{
		return m_TriggerIndex;
	}
	INT32 GetTriggerIndex() const
	{
		return m_TriggerIndex;
	}
private:
	//受击挂载点 1原点 2头 3 胸
	INT32 m_AttackHitDummy;
public:
	void SetAttackHitDummy( INT32 v)
	{
		m_AttackHitDummy=v;
	}
	INT32 GetAttackHitDummy()
	{
		return m_AttackHitDummy;
	}
	INT32 GetAttackHitDummy() const
	{
		return m_AttackHitDummy;
	}
private:
	//受击音效
	string m_AttackHitSound;
public:
	void SetAttackHitSound( const string& v)
	{
		m_AttackHitSound=v;
	}
	string GetAttackHitSound()
	{
		return m_AttackHitSound;
	}
	string GetAttackHitSound() const
	{
		return m_AttackHitSound;
	}
private:
	//受击震动X范围
	float m_HitShakeCameraXRange;
public:
	void SetHitShakeCameraXRange( float v)
	{
		m_HitShakeCameraXRange=v;
	}
	float GetHitShakeCameraXRange()
	{
		return m_HitShakeCameraXRange;
	}
	float GetHitShakeCameraXRange() const
	{
		return m_HitShakeCameraXRange;
	}
private:
	//受击震动Y范围
	float m_HitShakeCameraYRange;
public:
	void SetHitShakeCameraYRange( float v)
	{
		m_HitShakeCameraYRange=v;
	}
	float GetHitShakeCameraYRange()
	{
		return m_HitShakeCameraYRange;
	}
	float GetHitShakeCameraYRange() const
	{
		return m_HitShakeCameraYRange;
	}
private:
	//震屏次数
	INT32 m_HitShakeCameraCount;
public:
	void SetHitShakeCameraCount( INT32 v)
	{
		m_HitShakeCameraCount=v;
	}
	INT32 GetHitShakeCameraCount()
	{
		return m_HitShakeCameraCount;
	}
	INT32 GetHitShakeCameraCount() const
	{
		return m_HitShakeCameraCount;
	}
private:
	//震屏时长
	float m_HitShakeCameraDurationTime;
public:
	void SetHitShakeCameraDurationTime( float v)
	{
		m_HitShakeCameraDurationTime=v;
	}
	float GetHitShakeCameraDurationTime()
	{
		return m_HitShakeCameraDurationTime;
	}
	float GetHitShakeCameraDurationTime() const
	{
		return m_HitShakeCameraDurationTime;
	}
private:
	//隐藏武器
	INT32 m_HiddenWeaponMode;
public:
	void SetHiddenWeaponMode( INT32 v)
	{
		m_HiddenWeaponMode=v;
	}
	INT32 GetHiddenWeaponMode()
	{
		return m_HiddenWeaponMode;
	}
	INT32 GetHiddenWeaponMode() const
	{
		return m_HiddenWeaponMode;
	}
private:
	//下个技能名字
	string m_NextActionName;
public:
	void SetNextActionName( const string& v)
	{
		m_NextActionName=v;
	}
	string GetNextActionName()
	{
		return m_NextActionName;
	}
	string GetNextActionName() const
	{
		return m_NextActionName;
	}
private:
	//位移类型
	INT32 m_TranslateWrapMode;
public:
	void SetTranslateWrapMode( INT32 v)
	{
		m_TranslateWrapMode=v;
	}
	INT32 GetTranslateWrapMode()
	{
		return m_TranslateWrapMode;
	}
	INT32 GetTranslateWrapMode() const
	{
		return m_TranslateWrapMode;
	}
private:
	//是否触发触发器
	bool m_IsTriggerSecondAttack;
public:
	void SetIsTriggerSecondAttack( bool v)
	{
		m_IsTriggerSecondAttack=v;
	}
	bool GetIsTriggerSecondAttack()
	{
		return m_IsTriggerSecondAttack;
	}
	bool GetIsTriggerSecondAttack() const
	{
		return m_IsTriggerSecondAttack;
	}
private:
	//受击是否倒地
	bool m_IsHitGround;
public:
	void SetIsHitGround( bool v)
	{
		m_IsHitGround=v;
	}
	bool GetIsHitGround()
	{
		return m_IsHitGround;
	}
	bool GetIsHitGround() const
	{
		return m_IsHitGround;
	}
private:
	//技能编辑文件名字
	string m_SkillActionName;
public:
	void SetSkillActionName( const string& v)
	{
		m_SkillActionName=v;
	}
	string GetSkillActionName()
	{
		return m_SkillActionName;
	}
	string GetSkillActionName() const
	{
		return m_SkillActionName;
	}
private:
	//预警资源1
	string m_WarningRes1;
public:
	void SetWarningRes1( const string& v)
	{
		m_WarningRes1=v;
	}
	string GetWarningRes1()
	{
		return m_WarningRes1;
	}
	string GetWarningRes1() const
	{
		return m_WarningRes1;
	}
private:
	//预警资源2
	string m_WarningRes2;
public:
	void SetWarningRes2( const string& v)
	{
		m_WarningRes2=v;
	}
	string GetWarningRes2()
	{
		return m_WarningRes2;
	}
	string GetWarningRes2() const
	{
		return m_WarningRes2;
	}
private:
	//预警最大缩放
	ActionV3WraperV1 m_WarningMaxScale;
public:
	void SetWarningMaxScale( const ActionV3WraperV1& v)
	{
		m_WarningMaxScale=v;
	}
	ActionV3WraperV1 GetWarningMaxScale()
	{
		return m_WarningMaxScale;
	}
	ActionV3WraperV1 GetWarningMaxScale() const
	{
		return m_WarningMaxScale;
	}
private:
	//预警缩放模式
	INT32 m_WarningScaleMode;
public:
	void SetWarningScaleMode( INT32 v)
	{
		m_WarningScaleMode=v;
	}
	INT32 GetWarningScaleMode()
	{
		return m_WarningScaleMode;
	}
	INT32 GetWarningScaleMode() const
	{
		return m_WarningScaleMode;
	}
private:
	//锁定轴向
	INT32 m_WarningLockAxle;
public:
	void SetWarningLockAxle( INT32 v)
	{
		m_WarningLockAxle=v;
	}
	INT32 GetWarningLockAxle()
	{
		return m_WarningLockAxle;
	}
	INT32 GetWarningLockAxle() const
	{
		return m_WarningLockAxle;
	}
private:
	//预警偏移
	ActionV3WraperV1 m_WarningPositionOffset;
public:
	void SetWarningPositionOffset( const ActionV3WraperV1& v)
	{
		m_WarningPositionOffset=v;
	}
	ActionV3WraperV1 GetWarningPositionOffset()
	{
		return m_WarningPositionOffset;
	}
	ActionV3WraperV1 GetWarningPositionOffset() const
	{
		return m_WarningPositionOffset;
	}
private:
	//是否跟随旋转
	bool m_IsEffectFollow;
public:
	void SetIsEffectFollow( bool v)
	{
		m_IsEffectFollow=v;
	}
	bool GetIsEffectFollow()
	{
		return m_IsEffectFollow;
	}
	bool GetIsEffectFollow() const
	{
		return m_IsEffectFollow;
	}
private:
	//预警是否需要目标
	bool m_IsWarningTarget;
public:
	void SetIsWarningTarget( bool v)
	{
		m_IsWarningTarget=v;
	}
	bool GetIsWarningTarget()
	{
		return m_IsWarningTarget;
	}
	bool GetIsWarningTarget() const
	{
		return m_IsWarningTarget;
	}
private:
	//浮空 空中持续时间
	float m_AttackBehaviourAirDurationTime;
public:
	void SetAttackBehaviourAirDurationTime( float v)
	{
		m_AttackBehaviourAirDurationTime=v;
	}
	float GetAttackBehaviourAirDurationTime()
	{
		return m_AttackBehaviourAirDurationTime;
	}
	float GetAttackBehaviourAirDurationTime() const
	{
		return m_AttackBehaviourAirDurationTime;
	}
private:
	//特效碰撞之后是否删除
	bool m_IsColliderDestroy;
public:
	void SetIsColliderDestroy( bool v)
	{
		m_IsColliderDestroy=v;
	}
	bool GetIsColliderDestroy()
	{
		return m_IsColliderDestroy;
	}
	bool GetIsColliderDestroy() const
	{
		return m_IsColliderDestroy;
	}
private:
	//攻击范围是否跟随移动
	bool m_IsAttackRangeFollow;
public:
	void SetIsAttackRangeFollow( bool v)
	{
		m_IsAttackRangeFollow=v;
	}
	bool GetIsAttackRangeFollow()
	{
		return m_IsAttackRangeFollow;
	}
	bool GetIsAttackRangeFollow() const
	{
		return m_IsAttackRangeFollow;
	}
private:
	//动画是否循环
	bool m_IsAnimationLoop;
public:
	void SetIsAnimationLoop( bool v)
	{
		m_IsAnimationLoop=v;
	}
	bool GetIsAnimationLoop()
	{
		return m_IsAnimationLoop;
	}
	bool GetIsAnimationLoop() const
	{
		return m_IsAnimationLoop;
	}
private:
	//运动角度（0-360）
	float m_TranslateAngle;
public:
	void SetTranslateAngle( float v)
	{
		m_TranslateAngle=v;
	}
	float GetTranslateAngle()
	{
		return m_TranslateAngle;
	}
	float GetTranslateAngle() const
	{
		return m_TranslateAngle;
	}
private:
	//是否是遮罩范围
	bool m_IsAttackRangeShade;
public:
	void SetIsAttackRangeShade( bool v)
	{
		m_IsAttackRangeShade=v;
	}
	bool GetIsAttackRangeShade()
	{
		return m_IsAttackRangeShade;
	}
	bool GetIsAttackRangeShade() const
	{
		return m_IsAttackRangeShade;
	}
private:
	//攻击间隔时间
	float m_AttackInterval;
public:
	void SetAttackInterval( float v)
	{
		m_AttackInterval=v;
	}
	float GetAttackInterval()
	{
		return m_AttackInterval;
	}
	float GetAttackInterval() const
	{
		return m_AttackInterval;
	}
private:
	//是否显示攻击矩形
	bool m_IsShowAttackRect;
public:
	void SetIsShowAttackRect( bool v)
	{
		m_IsShowAttackRect=v;
	}
	bool GetIsShowAttackRect()
	{
		return m_IsShowAttackRect;
	}
	bool GetIsShowAttackRect() const
	{
		return m_IsShowAttackRect;
	}
private:
	//子弹发射角度
	float m_EffectBulletLaunchAngle;
public:
	void SetEffectBulletLaunchAngle( float v)
	{
		m_EffectBulletLaunchAngle=v;
	}
	float GetEffectBulletLaunchAngle()
	{
		return m_EffectBulletLaunchAngle;
	}
	float GetEffectBulletLaunchAngle() const
	{
		return m_EffectBulletLaunchAngle;
	}
private:
	//子弹速度
	float m_EffectBulletSpeed;
public:
	void SetEffectBulletSpeed( float v)
	{
		m_EffectBulletSpeed=v;
	}
	float GetEffectBulletSpeed()
	{
		return m_EffectBulletSpeed;
	}
	float GetEffectBulletSpeed() const
	{
		return m_EffectBulletSpeed;
	}
private:
	//每个弹道子弹发射时间间隔
	ActionRangeWraperV1 m_EffectBulletLaunchTimeIntervalRange;
public:
	void SetEffectBulletLaunchTimeIntervalRange( const ActionRangeWraperV1& v)
	{
		m_EffectBulletLaunchTimeIntervalRange=v;
	}
	ActionRangeWraperV1 GetEffectBulletLaunchTimeIntervalRange()
	{
		return m_EffectBulletLaunchTimeIntervalRange;
	}
	ActionRangeWraperV1 GetEffectBulletLaunchTimeIntervalRange() const
	{
		return m_EffectBulletLaunchTimeIntervalRange;
	}
private:
	//子弹总数量
	INT32 m_EffectBulletMaxCout;
public:
	void SetEffectBulletMaxCout( INT32 v)
	{
		m_EffectBulletMaxCout=v;
	}
	INT32 GetEffectBulletMaxCout()
	{
		return m_EffectBulletMaxCout;
	}
	INT32 GetEffectBulletMaxCout() const
	{
		return m_EffectBulletMaxCout;
	}
private:
	//子弹存活时间间隔
	ActionRangeWraperV1 m_EffectBulletLifeTimeInteralRange;
public:
	void SetEffectBulletLifeTimeInteralRange( const ActionRangeWraperV1& v)
	{
		m_EffectBulletLifeTimeInteralRange=v;
	}
	ActionRangeWraperV1 GetEffectBulletLifeTimeInteralRange()
	{
		return m_EffectBulletLifeTimeInteralRange;
	}
	ActionRangeWraperV1 GetEffectBulletLifeTimeInteralRange() const
	{
		return m_EffectBulletLifeTimeInteralRange;
	}
private:
	//子弹类型
	INT32 m_EffectBulletType;
public:
	void SetEffectBulletType( INT32 v)
	{
		m_EffectBulletType=v;
	}
	INT32 GetEffectBulletType()
	{
		return m_EffectBulletType;
	}
	INT32 GetEffectBulletType() const
	{
		return m_EffectBulletType;
	}
private:
	//子弹初始位置
	vector<ActionV3WraperV1> m_EffectBulletInitPosList;
public:
	int SizeEffectBulletInitPosList()
	{
		return m_EffectBulletInitPosList.size();
	}
	const vector<ActionV3WraperV1>& GetEffectBulletInitPosList() const
	{
		return m_EffectBulletInitPosList;
	}
	ActionV3WraperV1 GetEffectBulletInitPosList(int Index) const
	{
		if(Index<0 || Index>=(int)m_EffectBulletInitPosList.size())
		{
			assert(false);
			return ActionV3WraperV1();
		}
		return m_EffectBulletInitPosList[Index];
	}
	void SetEffectBulletInitPosList( const vector<ActionV3WraperV1>& v )
	{
		m_EffectBulletInitPosList=v;
	}
	void ClearEffectBulletInitPosList( )
	{
		m_EffectBulletInitPosList.clear();
	}
	void SetEffectBulletInitPosList( int Index, const ActionV3WraperV1& v )
	{
		if(Index<0 || Index>=(int)m_EffectBulletInitPosList.size())
		{
			assert(false);
			return;
		}
		m_EffectBulletInitPosList[Index] = v;
	}
	void AddEffectBulletInitPosList( const ActionV3WraperV1& v )
	{
		m_EffectBulletInitPosList.push_back(v);
	}
private:
	//单个弹道发射最大数量
	INT32 m_EffectBulletLaunchMaxCount;
public:
	void SetEffectBulletLaunchMaxCount( INT32 v)
	{
		m_EffectBulletLaunchMaxCount=v;
	}
	INT32 GetEffectBulletLaunchMaxCount()
	{
		return m_EffectBulletLaunchMaxCount;
	}
	INT32 GetEffectBulletLaunchMaxCount() const
	{
		return m_EffectBulletLaunchMaxCount;
	}
private:
	//子弹是否跟随人物方向转向
	bool m_EffectBulletIsFollow;
public:
	void SetEffectBulletIsFollow( bool v)
	{
		m_EffectBulletIsFollow=v;
	}
	bool GetEffectBulletIsFollow()
	{
		return m_EffectBulletIsFollow;
	}
	bool GetEffectBulletIsFollow() const
	{
		return m_EffectBulletIsFollow;
	}
private:
	//浮空降落速度
	float m_AttackBehaviourAirDownSpeed;
public:
	void SetAttackBehaviourAirDownSpeed( float v)
	{
		m_AttackBehaviourAirDownSpeed=v;
	}
	float GetAttackBehaviourAirDownSpeed()
	{
		return m_AttackBehaviourAirDownSpeed;
	}
	float GetAttackBehaviourAirDownSpeed() const
	{
		return m_AttackBehaviourAirDownSpeed;
	}
private:
	//特效方向锁定类型
	INT32 m_EffectDirectionLockType;
public:
	void SetEffectDirectionLockType( INT32 v)
	{
		m_EffectDirectionLockType=v;
	}
	INT32 GetEffectDirectionLockType()
	{
		return m_EffectDirectionLockType;
	}
	INT32 GetEffectDirectionLockType() const
	{
		return m_EffectDirectionLockType;
	}
private:
	//是否是不规则特效
	bool m_IsIrregularityEffect;
public:
	void SetIsIrregularityEffect( bool v)
	{
		m_IsIrregularityEffect=v;
	}
	bool GetIsIrregularityEffect()
	{
		return m_IsIrregularityEffect;
	}
	bool GetIsIrregularityEffect() const
	{
		return m_IsIrregularityEffect;
	}
private:
	//特效size
	ActionV3WraperV1 m_EffectSize;
public:
	void SetEffectSize( const ActionV3WraperV1& v)
	{
		m_EffectSize=v;
	}
	ActionV3WraperV1 GetEffectSize()
	{
		return m_EffectSize;
	}
	ActionV3WraperV1 GetEffectSize() const
	{
		return m_EffectSize;
	}
private:
	//攻击范围起点(右上点)
	ActionV3WraperV1 m_AttackRangePostion;
public:
	void SetAttackRangePostion( const ActionV3WraperV1& v)
	{
		m_AttackRangePostion=v;
	}
	ActionV3WraperV1 GetAttackRangePostion()
	{
		return m_AttackRangePostion;
	}
	ActionV3WraperV1 GetAttackRangePostion() const
	{
		return m_AttackRangePostion;
	}
private:
	//攻击范围的宽高
	ActionV3WraperV1 m_AttackRangeSize;
public:
	void SetAttackRangeSize( const ActionV3WraperV1& v)
	{
		m_AttackRangeSize=v;
	}
	ActionV3WraperV1 GetAttackRangeSize()
	{
		return m_AttackRangeSize;
	}
	ActionV3WraperV1 GetAttackRangeSize() const
	{
		return m_AttackRangeSize;
	}
private:
	//攻击形状
	INT32 m_AttackShape;
public:
	void SetAttackShape( INT32 v)
	{
		m_AttackShape=v;
	}
	INT32 GetAttackShape()
	{
		return m_AttackShape;
	}
	INT32 GetAttackShape() const
	{
		return m_AttackShape;
	}
private:
	//圆形攻击形状原点
	ActionV3WraperV1 m_AttackCircleOrigin;
public:
	void SetAttackCircleOrigin( const ActionV3WraperV1& v)
	{
		m_AttackCircleOrigin=v;
	}
	ActionV3WraperV1 GetAttackCircleOrigin()
	{
		return m_AttackCircleOrigin;
	}
	ActionV3WraperV1 GetAttackCircleOrigin() const
	{
		return m_AttackCircleOrigin;
	}
private:
	//半径
	float m_AttackCircleRadius;
public:
	void SetAttackCircleRadius( float v)
	{
		m_AttackCircleRadius=v;
	}
	float GetAttackCircleRadius()
	{
		return m_AttackCircleRadius;
	}
	float GetAttackCircleRadius() const
	{
		return m_AttackCircleRadius;
	}
private:
	//角度
	float m_AttackCircleAngle;
public:
	void SetAttackCircleAngle( float v)
	{
		m_AttackCircleAngle=v;
	}
	float GetAttackCircleAngle()
	{
		return m_AttackCircleAngle;
	}
	float GetAttackCircleAngle() const
	{
		return m_AttackCircleAngle;
	}

};
//SkillInfo封装类
class ActionSkillInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	ActionSkillInfoWraperV1()
	{
		
		m_Name = "";
		m_TotalTime = 0;
		m_IsSing = false;
		m_SingTime = 0;

	}
	//赋值构造函数
	ActionSkillInfoWraperV1(const ActionSkillInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const ActionSkillInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActionSkillInfoV1 ToPB() const
	{
		ActionSkillInfoV1 v;
		v.set_name( m_Name );
		v.mutable_commandlist()->Reserve(m_CommandList.size());
		for (int i=0; i<(int)m_CommandList.size(); i++)
		{
			*v.add_commandlist() = m_CommandList[i].ToPB();
		}
		v.set_totaltime( m_TotalTime );
		v.set_issing( m_IsSing );
		v.set_singtime( m_SingTime );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ActionSkillInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Name(Name) [string]</li>\r\n";
		htmlBuff += "<li>CommandList(CommandList) [CommandInfo] Array</li>\r\n";
		htmlBuff += "<li>TotalTime(TotalTime) [float]</li>\r\n";
		htmlBuff += "<li>IsSing(IsSing) [bool]</li>\r\n";
		htmlBuff += "<li>SingTime(SingTime) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>Name：\""+m_Name+"\"</li>\r\n";
		htmlBuff += "<li>CommandList：</li>\r\n";
		if( m_CommandList.size()>0) htmlBuff += m_CommandList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_CommandList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_CommandList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>TotalTime：%.2ff</li>\r\n",m_TotalTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsSing：%di</li>\r\n",m_IsSing);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SingTime：%.2ff</li>\r\n",m_SingTime);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActionSkillInfoV1& v)
	{
		m_Name = v.name();
		m_CommandList.clear();
		m_CommandList.reserve(v.commandlist_size());
		for( int i=0; i<v.commandlist_size(); i++)
			m_CommandList.push_back(v.commandlist(i));
		m_TotalTime = v.totaltime();
		m_IsSing = v.issing();
		m_SingTime = v.singtime();

	}

private:
	//Name
	string m_Name;
public:
	void SetName( const string& v)
	{
		m_Name=v;
	}
	string GetName()
	{
		return m_Name;
	}
	string GetName() const
	{
		return m_Name;
	}
private:
	//CommandList
	vector<ActionCommandInfoWraperV1> m_CommandList;
public:
	int SizeCommandList()
	{
		return m_CommandList.size();
	}
	const vector<ActionCommandInfoWraperV1>& GetCommandList() const
	{
		return m_CommandList;
	}
	ActionCommandInfoWraperV1 GetCommandList(int Index) const
	{
		if(Index<0 || Index>=(int)m_CommandList.size())
		{
			assert(false);
			return ActionCommandInfoWraperV1();
		}
		return m_CommandList[Index];
	}
	void SetCommandList( const vector<ActionCommandInfoWraperV1>& v )
	{
		m_CommandList=v;
	}
	void ClearCommandList( )
	{
		m_CommandList.clear();
	}
	void SetCommandList( int Index, const ActionCommandInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_CommandList.size())
		{
			assert(false);
			return;
		}
		m_CommandList[Index] = v;
	}
	void AddCommandList( const ActionCommandInfoWraperV1& v )
	{
		m_CommandList.push_back(v);
	}
private:
	//TotalTime
	float m_TotalTime;
public:
	void SetTotalTime( float v)
	{
		m_TotalTime=v;
	}
	float GetTotalTime()
	{
		return m_TotalTime;
	}
	float GetTotalTime() const
	{
		return m_TotalTime;
	}
private:
	//IsSing
	bool m_IsSing;
public:
	void SetIsSing( bool v)
	{
		m_IsSing=v;
	}
	bool GetIsSing()
	{
		return m_IsSing;
	}
	bool GetIsSing() const
	{
		return m_IsSing;
	}
private:
	//SingTime
	float m_SingTime;
public:
	void SetSingTime( float v)
	{
		m_SingTime=v;
	}
	float GetSingTime()
	{
		return m_SingTime;
	}
	float GetSingTime() const
	{
		return m_SingTime;
	}

};
//V2封装类
class ActionV2WraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	ActionV2WraperV1()
	{
		
		m_X = 0;
		m_Y = 0;

	}
	//赋值构造函数
	ActionV2WraperV1(const ActionV2V1& v){ Init(v); }
	//等号重载函数
	void operator = (const ActionV2V1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActionV2V1 ToPB() const
	{
		ActionV2V1 v;
		v.set_x( m_X );
		v.set_y( m_Y );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ActionV2V1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>X(X) [float]</li>\r\n";
		htmlBuff += "<li>Y(Y) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Y：%.2ff</li>\r\n",m_Y);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActionV2V1& v)
	{
		m_X = v.x();
		m_Y = v.y();

	}

private:
	//X
	float m_X;
public:
	void SetX( float v)
	{
		m_X=v;
	}
	float GetX()
	{
		return m_X;
	}
	float GetX() const
	{
		return m_X;
	}
private:
	//Y
	float m_Y;
public:
	void SetY( float v)
	{
		m_Y=v;
	}
	float GetY()
	{
		return m_Y;
	}
	float GetY() const
	{
		return m_Y;
	}

};
//Useless封装类
class ActionUselessWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<ActionUselessWraperV1>
{
public:
	//构造函数
	ActionUselessWraperV1()
	{
		SetDataWraper( this );


	}
	//赋值构造函数
	ActionUselessWraperV1(const ActionUselessV1& v){ Init(v); }
	//等号重载函数
	void operator = (const ActionUselessV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActionUselessV1 ToPB() const
	{
		ActionUselessV1 v;

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ActionUselessV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActionUselessV1& v)
	{

	}


};

#endif
