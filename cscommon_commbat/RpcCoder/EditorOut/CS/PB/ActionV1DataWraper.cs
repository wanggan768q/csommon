
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperSyncPBAction.cs
Author:
Description:
Version:      1.0
History:
  <author>  <time>   <version >   <desc>

***********************************************************/
using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//SkillInfo封装类
[System.Serializable]
public class ActionSkillInfoWraperV1
{

	//构造函数
	public ActionSkillInfoWraperV1()
	{
		 m_Name = "";
		m_CommandList = new List<ActionCommandInfoWraperV1>();
		 m_TotalTime = (float)0;
		 m_IsSing = false;
		 m_SingTime = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Name = "";
		m_CommandList = new List<ActionCommandInfoWraperV1>();
		 m_TotalTime = (float)0;
		 m_IsSing = false;
		 m_SingTime = (float)0;

	}

 	//转化成Protobuffer类型函数
	public ActionSkillInfoV1 ToPB()
	{
		ActionSkillInfoV1 v = new ActionSkillInfoV1();
		v.Name = m_Name;
		for (int i=0; i<(int)m_CommandList.Count; i++)
			v.CommandList.Add( m_CommandList[i].ToPB());
		v.TotalTime = m_TotalTime;
		v.IsSing = m_IsSing;
		v.SingTime = m_SingTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActionSkillInfoV1 v)
	{
        if (v == null)
            return;
		m_Name = v.Name;
		m_CommandList.Clear();
		for( int i=0; i<v.CommandList.Count; i++)
			m_CommandList.Add( new ActionCommandInfoWraperV1());
		for( int i=0; i<v.CommandList.Count; i++)
			m_CommandList[i].FromPB(v.CommandList[i]);
		m_TotalTime = v.TotalTime;
		m_IsSing = v.IsSing;
		m_SingTime = v.SingTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActionSkillInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActionSkillInfoV1 pb = ProtoBuf.Serializer.Deserialize<ActionSkillInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//Name
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}
	//CommandList
	public List<ActionCommandInfoWraperV1> m_CommandList;
	public int SizeCommandList()
	{
		return m_CommandList.Count;
	}
	public List<ActionCommandInfoWraperV1> GetCommandList()
	{
		return m_CommandList;
	}
	public ActionCommandInfoWraperV1 GetCommandList(int Index)
	{
		if(Index<0 || Index>=(int)m_CommandList.Count)
			return new ActionCommandInfoWraperV1();
		return m_CommandList[Index];
	}
	public void SetCommandList( List<ActionCommandInfoWraperV1> v )
	{
		m_CommandList=v;
	}
	public void SetCommandList( int Index, ActionCommandInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_CommandList.Count)
			return;
		m_CommandList[Index] = v;
	}
	public void AddCommandList( ActionCommandInfoWraperV1 v )
	{
		m_CommandList.Add(v);
	}
	public void ClearCommandList( )
	{
		m_CommandList.Clear();
	}
	//TotalTime
	public float m_TotalTime;
	public float TotalTime
	{
		get { return m_TotalTime;}
		set { m_TotalTime = value; }
	}
	//IsSing
	public bool m_IsSing;
	public bool IsSing
	{
		get { return m_IsSing;}
		set { m_IsSing = value; }
	}
	//SingTime
	public float m_SingTime;
	public float SingTime
	{
		get { return m_SingTime;}
		set { m_SingTime = value; }
	}


};
//CommandInfo封装类
[System.Serializable]
public class ActionCommandInfoWraperV1
{

	//构造函数
	public ActionCommandInfoWraperV1()
	{
		 m_CommandType = -1;
		 m_StartTime = (float)0;
		 m_DurationTime = (float)0;
		 m_AnimationTriggerCondition = 0;
		 m_EffectName = "";
		 m_EffectBoneHook = 0;
		 m_EffectPositionOffset = new ActionV3WraperV1();
		 m_EffectStayInLocalSpace = false;
		 m_EffectControlObjectId = 0;
		 m_TranslateControlId = 0;
		 m_TranslateOffset = new ActionV3WraperV1();
		m_ActorAttackPart = new List<int>();
		 m_TranslateEase = 1;
		 m_AttackShowHitEffect = false;
		 m_AttackHitEffectName = "";
		 m_AttackHitEffectDuration = (float)1.6;
		 m_AttackFragmentCount = 1;
		 m_AttackFragmentIntervalTime = (float)0;
		 m_AttackDamageRadio = (float)1;
		 m_BuffSelfActive = false;
		 m_BuffTargetActive = false;
		 m_AttackBehaviourBackDistance = (float)0;
		 m_AttackBehaviourAirHeight = (float)0;
		 m_EffectRotationOffset = new ActionV3WraperV1();
		 m_FlashControlObjectId = 0;
		 m_AttackStiffTime = (float)0;
		 m_AttackShake = false;
		 m_AttackFlash = false;
		 m_AttackBehaviourBackSpeed = (float)1;
		 m_AttackBehaviourAirSpeed = (float)1;
		 m_AttackBehaviourBack = false;
		 m_AttackBehaviourAir = false;
		 m_AttackBehaviourZoom = false;
		 m_SoundName = "";
		 m_Trigger = false;
		 m_TriggerIndex = 1;
		 m_AttackHitDummy = 0;
		 m_AttackHitSound = "";
		 m_HitShakeCameraXRange = (float)0;
		 m_HitShakeCameraYRange = (float)0;
		 m_HitShakeCameraCount = 1;
		 m_HitShakeCameraDurationTime = (float)0.1;
		 m_HiddenWeaponMode = 0;
		 m_NextActionName = "";
		 m_TranslateWrapMode = 0;
		 m_IsTriggerSecondAttack = false;
		 m_IsHitGround = false;
		 m_SkillActionName = "";
		 m_WarningRes1 = "";
		 m_WarningRes2 = "";
		 m_WarningMaxScale = new ActionV3WraperV1();
		 m_WarningScaleMode = 0;
		 m_WarningLockAxle = 0;
		 m_WarningPositionOffset = new ActionV3WraperV1();
		 m_IsEffectFollow = false;
		 m_IsWarningTarget = false;
		 m_AttackBehaviourAirDurationTime = (float)0;
		 m_IsColliderDestroy = false;
		 m_IsAttackRangeFollow = false;
		 m_IsAnimationLoop = false;
		 m_TranslateAngle = (float)0;
		 m_IsAttackRangeShade = false;
		 m_AttackInterval = (float)0;
		 m_IsShowAttackRect = false;
		 m_EffectBulletLaunchAngle = (float)0;
		 m_EffectBulletSpeed = (float)0;
		 m_EffectBulletLaunchTimeIntervalRange = new ActionRangeWraperV1();
		 m_EffectBulletMaxCout = 0;
		 m_EffectBulletLifeTimeInteralRange = new ActionRangeWraperV1();
		 m_EffectBulletType = 0;
		m_EffectBulletInitPosList = new List<ActionV3WraperV1>();
		 m_EffectBulletLaunchMaxCount = 0;
		 m_EffectBulletIsFollow = false;
		 m_AttackBehaviourAirDownSpeed = (float)0;
		 m_EffectDirectionLockType = 0;
		 m_IsIrregularityEffect = false;
		 m_EffectSize = new ActionV3WraperV1();
		 m_AttackRangePostion = new ActionV3WraperV1();
		 m_AttackRangeSize = new ActionV3WraperV1();
		 m_AttackShape = 0;
		 m_AttackCircleOrigin = new ActionV3WraperV1();
		 m_AttackCircleRadius = (float)0;
		 m_AttackCircleAngle = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_CommandType = -1;
		 m_StartTime = (float)0;
		 m_DurationTime = (float)0;
		 m_AnimationTriggerCondition = 0;
		 m_EffectName = "";
		 m_EffectBoneHook = 0;
		 m_EffectPositionOffset = new ActionV3WraperV1();
		 m_EffectStayInLocalSpace = false;
		 m_EffectControlObjectId = 0;
		 m_TranslateControlId = 0;
		 m_TranslateOffset = new ActionV3WraperV1();
		m_ActorAttackPart = new List<int>();
		 m_TranslateEase = 1;
		 m_AttackShowHitEffect = false;
		 m_AttackHitEffectName = "";
		 m_AttackHitEffectDuration = (float)1.6;
		 m_AttackFragmentCount = 1;
		 m_AttackFragmentIntervalTime = (float)0;
		 m_AttackDamageRadio = (float)1;
		 m_BuffSelfActive = false;
		 m_BuffTargetActive = false;
		 m_AttackBehaviourBackDistance = (float)0;
		 m_AttackBehaviourAirHeight = (float)0;
		 m_EffectRotationOffset = new ActionV3WraperV1();
		 m_FlashControlObjectId = 0;
		 m_AttackStiffTime = (float)0;
		 m_AttackShake = false;
		 m_AttackFlash = false;
		 m_AttackBehaviourBackSpeed = (float)1;
		 m_AttackBehaviourAirSpeed = (float)1;
		 m_AttackBehaviourBack = false;
		 m_AttackBehaviourAir = false;
		 m_AttackBehaviourZoom = false;
		 m_SoundName = "";
		 m_Trigger = false;
		 m_TriggerIndex = 1;
		 m_AttackHitDummy = 0;
		 m_AttackHitSound = "";
		 m_HitShakeCameraXRange = (float)0;
		 m_HitShakeCameraYRange = (float)0;
		 m_HitShakeCameraCount = 1;
		 m_HitShakeCameraDurationTime = (float)0.1;
		 m_HiddenWeaponMode = 0;
		 m_NextActionName = "";
		 m_TranslateWrapMode = 0;
		 m_IsTriggerSecondAttack = false;
		 m_IsHitGround = false;
		 m_SkillActionName = "";
		 m_WarningRes1 = "";
		 m_WarningRes2 = "";
		 m_WarningMaxScale = new ActionV3WraperV1();
		 m_WarningScaleMode = 0;
		 m_WarningLockAxle = 0;
		 m_WarningPositionOffset = new ActionV3WraperV1();
		 m_IsEffectFollow = false;
		 m_IsWarningTarget = false;
		 m_AttackBehaviourAirDurationTime = (float)0;
		 m_IsColliderDestroy = false;
		 m_IsAttackRangeFollow = false;
		 m_IsAnimationLoop = false;
		 m_TranslateAngle = (float)0;
		 m_IsAttackRangeShade = false;
		 m_AttackInterval = (float)0;
		 m_IsShowAttackRect = false;
		 m_EffectBulletLaunchAngle = (float)0;
		 m_EffectBulletSpeed = (float)0;
		 m_EffectBulletLaunchTimeIntervalRange = new ActionRangeWraperV1();
		 m_EffectBulletMaxCout = 0;
		 m_EffectBulletLifeTimeInteralRange = new ActionRangeWraperV1();
		 m_EffectBulletType = 0;
		m_EffectBulletInitPosList = new List<ActionV3WraperV1>();
		 m_EffectBulletLaunchMaxCount = 0;
		 m_EffectBulletIsFollow = false;
		 m_AttackBehaviourAirDownSpeed = (float)0;
		 m_EffectDirectionLockType = 0;
		 m_IsIrregularityEffect = false;
		 m_EffectSize = new ActionV3WraperV1();
		 m_AttackRangePostion = new ActionV3WraperV1();
		 m_AttackRangeSize = new ActionV3WraperV1();
		 m_AttackShape = 0;
		 m_AttackCircleOrigin = new ActionV3WraperV1();
		 m_AttackCircleRadius = (float)0;
		 m_AttackCircleAngle = (float)0;

	}

 	//转化成Protobuffer类型函数
	public ActionCommandInfoV1 ToPB()
	{
		ActionCommandInfoV1 v = new ActionCommandInfoV1();
		v.CommandType = m_CommandType;
		v.StartTime = m_StartTime;
		v.DurationTime = m_DurationTime;
		v.AnimationTriggerCondition = m_AnimationTriggerCondition;
		v.EffectName = m_EffectName;
		v.EffectBoneHook = m_EffectBoneHook;
		v.EffectPositionOffset = m_EffectPositionOffset.ToPB();
		v.EffectStayInLocalSpace = m_EffectStayInLocalSpace;
		v.EffectControlObjectId = m_EffectControlObjectId;
		v.TranslateControlId = m_TranslateControlId;
		v.TranslateOffset = m_TranslateOffset.ToPB();
		for (int i=0; i<(int)m_ActorAttackPart.Count; i++)
			v.ActorAttackPart.Add( m_ActorAttackPart[i]);
		v.TranslateEase = m_TranslateEase;
		v.AttackShowHitEffect = m_AttackShowHitEffect;
		v.AttackHitEffectName = m_AttackHitEffectName;
		v.AttackHitEffectDuration = m_AttackHitEffectDuration;
		v.AttackFragmentCount = m_AttackFragmentCount;
		v.AttackFragmentIntervalTime = m_AttackFragmentIntervalTime;
		v.AttackDamageRadio = m_AttackDamageRadio;
		v.BuffSelfActive = m_BuffSelfActive;
		v.BuffTargetActive = m_BuffTargetActive;
		v.AttackBehaviourBackDistance = m_AttackBehaviourBackDistance;
		v.AttackBehaviourAirHeight = m_AttackBehaviourAirHeight;
		v.EffectRotationOffset = m_EffectRotationOffset.ToPB();
		v.FlashControlObjectId = m_FlashControlObjectId;
		v.AttackStiffTime = m_AttackStiffTime;
		v.AttackShake = m_AttackShake;
		v.AttackFlash = m_AttackFlash;
		v.AttackBehaviourBackSpeed = m_AttackBehaviourBackSpeed;
		v.AttackBehaviourAirSpeed = m_AttackBehaviourAirSpeed;
		v.AttackBehaviourBack = m_AttackBehaviourBack;
		v.AttackBehaviourAir = m_AttackBehaviourAir;
		v.AttackBehaviourZoom = m_AttackBehaviourZoom;
		v.SoundName = m_SoundName;
		v.Trigger = m_Trigger;
		v.TriggerIndex = m_TriggerIndex;
		v.AttackHitDummy = m_AttackHitDummy;
		v.AttackHitSound = m_AttackHitSound;
		v.HitShakeCameraXRange = m_HitShakeCameraXRange;
		v.HitShakeCameraYRange = m_HitShakeCameraYRange;
		v.HitShakeCameraCount = m_HitShakeCameraCount;
		v.HitShakeCameraDurationTime = m_HitShakeCameraDurationTime;
		v.HiddenWeaponMode = m_HiddenWeaponMode;
		v.NextActionName = m_NextActionName;
		v.TranslateWrapMode = m_TranslateWrapMode;
		v.IsTriggerSecondAttack = m_IsTriggerSecondAttack;
		v.IsHitGround = m_IsHitGround;
		v.SkillActionName = m_SkillActionName;
		v.WarningRes1 = m_WarningRes1;
		v.WarningRes2 = m_WarningRes2;
		v.WarningMaxScale = m_WarningMaxScale.ToPB();
		v.WarningScaleMode = m_WarningScaleMode;
		v.WarningLockAxle = m_WarningLockAxle;
		v.WarningPositionOffset = m_WarningPositionOffset.ToPB();
		v.IsEffectFollow = m_IsEffectFollow;
		v.IsWarningTarget = m_IsWarningTarget;
		v.AttackBehaviourAirDurationTime = m_AttackBehaviourAirDurationTime;
		v.IsColliderDestroy = m_IsColliderDestroy;
		v.IsAttackRangeFollow = m_IsAttackRangeFollow;
		v.IsAnimationLoop = m_IsAnimationLoop;
		v.TranslateAngle = m_TranslateAngle;
		v.IsAttackRangeShade = m_IsAttackRangeShade;
		v.AttackInterval = m_AttackInterval;
		v.IsShowAttackRect = m_IsShowAttackRect;
		v.EffectBulletLaunchAngle = m_EffectBulletLaunchAngle;
		v.EffectBulletSpeed = m_EffectBulletSpeed;
		v.EffectBulletLaunchTimeIntervalRange = m_EffectBulletLaunchTimeIntervalRange.ToPB();
		v.EffectBulletMaxCout = m_EffectBulletMaxCout;
		v.EffectBulletLifeTimeInteralRange = m_EffectBulletLifeTimeInteralRange.ToPB();
		v.EffectBulletType = m_EffectBulletType;
		for (int i=0; i<(int)m_EffectBulletInitPosList.Count; i++)
			v.EffectBulletInitPosList.Add( m_EffectBulletInitPosList[i].ToPB());
		v.EffectBulletLaunchMaxCount = m_EffectBulletLaunchMaxCount;
		v.EffectBulletIsFollow = m_EffectBulletIsFollow;
		v.AttackBehaviourAirDownSpeed = m_AttackBehaviourAirDownSpeed;
		v.EffectDirectionLockType = m_EffectDirectionLockType;
		v.IsIrregularityEffect = m_IsIrregularityEffect;
		v.EffectSize = m_EffectSize.ToPB();
		v.AttackRangePostion = m_AttackRangePostion.ToPB();
		v.AttackRangeSize = m_AttackRangeSize.ToPB();
		v.AttackShape = m_AttackShape;
		v.AttackCircleOrigin = m_AttackCircleOrigin.ToPB();
		v.AttackCircleRadius = m_AttackCircleRadius;
		v.AttackCircleAngle = m_AttackCircleAngle;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActionCommandInfoV1 v)
	{
        if (v == null)
            return;
		m_CommandType = v.CommandType;
		m_StartTime = v.StartTime;
		m_DurationTime = v.DurationTime;
		m_AnimationTriggerCondition = v.AnimationTriggerCondition;
		m_EffectName = v.EffectName;
		m_EffectBoneHook = v.EffectBoneHook;
		m_EffectPositionOffset.FromPB(v.EffectPositionOffset);
		m_EffectStayInLocalSpace = v.EffectStayInLocalSpace;
		m_EffectControlObjectId = v.EffectControlObjectId;
		m_TranslateControlId = v.TranslateControlId;
		m_TranslateOffset.FromPB(v.TranslateOffset);
		m_ActorAttackPart.Clear();
		for( int i=0; i<v.ActorAttackPart.Count; i++)
			m_ActorAttackPart.Add(v.ActorAttackPart[i]);
		m_TranslateEase = v.TranslateEase;
		m_AttackShowHitEffect = v.AttackShowHitEffect;
		m_AttackHitEffectName = v.AttackHitEffectName;
		m_AttackHitEffectDuration = v.AttackHitEffectDuration;
		m_AttackFragmentCount = v.AttackFragmentCount;
		m_AttackFragmentIntervalTime = v.AttackFragmentIntervalTime;
		m_AttackDamageRadio = v.AttackDamageRadio;
		m_BuffSelfActive = v.BuffSelfActive;
		m_BuffTargetActive = v.BuffTargetActive;
		m_AttackBehaviourBackDistance = v.AttackBehaviourBackDistance;
		m_AttackBehaviourAirHeight = v.AttackBehaviourAirHeight;
		m_EffectRotationOffset.FromPB(v.EffectRotationOffset);
		m_FlashControlObjectId = v.FlashControlObjectId;
		m_AttackStiffTime = v.AttackStiffTime;
		m_AttackShake = v.AttackShake;
		m_AttackFlash = v.AttackFlash;
		m_AttackBehaviourBackSpeed = v.AttackBehaviourBackSpeed;
		m_AttackBehaviourAirSpeed = v.AttackBehaviourAirSpeed;
		m_AttackBehaviourBack = v.AttackBehaviourBack;
		m_AttackBehaviourAir = v.AttackBehaviourAir;
		m_AttackBehaviourZoom = v.AttackBehaviourZoom;
		m_SoundName = v.SoundName;
		m_Trigger = v.Trigger;
		m_TriggerIndex = v.TriggerIndex;
		m_AttackHitDummy = v.AttackHitDummy;
		m_AttackHitSound = v.AttackHitSound;
		m_HitShakeCameraXRange = v.HitShakeCameraXRange;
		m_HitShakeCameraYRange = v.HitShakeCameraYRange;
		m_HitShakeCameraCount = v.HitShakeCameraCount;
		m_HitShakeCameraDurationTime = v.HitShakeCameraDurationTime;
		m_HiddenWeaponMode = v.HiddenWeaponMode;
		m_NextActionName = v.NextActionName;
		m_TranslateWrapMode = v.TranslateWrapMode;
		m_IsTriggerSecondAttack = v.IsTriggerSecondAttack;
		m_IsHitGround = v.IsHitGround;
		m_SkillActionName = v.SkillActionName;
		m_WarningRes1 = v.WarningRes1;
		m_WarningRes2 = v.WarningRes2;
		m_WarningMaxScale.FromPB(v.WarningMaxScale);
		m_WarningScaleMode = v.WarningScaleMode;
		m_WarningLockAxle = v.WarningLockAxle;
		m_WarningPositionOffset.FromPB(v.WarningPositionOffset);
		m_IsEffectFollow = v.IsEffectFollow;
		m_IsWarningTarget = v.IsWarningTarget;
		m_AttackBehaviourAirDurationTime = v.AttackBehaviourAirDurationTime;
		m_IsColliderDestroy = v.IsColliderDestroy;
		m_IsAttackRangeFollow = v.IsAttackRangeFollow;
		m_IsAnimationLoop = v.IsAnimationLoop;
		m_TranslateAngle = v.TranslateAngle;
		m_IsAttackRangeShade = v.IsAttackRangeShade;
		m_AttackInterval = v.AttackInterval;
		m_IsShowAttackRect = v.IsShowAttackRect;
		m_EffectBulletLaunchAngle = v.EffectBulletLaunchAngle;
		m_EffectBulletSpeed = v.EffectBulletSpeed;
		m_EffectBulletLaunchTimeIntervalRange.FromPB(v.EffectBulletLaunchTimeIntervalRange);
		m_EffectBulletMaxCout = v.EffectBulletMaxCout;
		m_EffectBulletLifeTimeInteralRange.FromPB(v.EffectBulletLifeTimeInteralRange);
		m_EffectBulletType = v.EffectBulletType;
		m_EffectBulletInitPosList.Clear();
		for( int i=0; i<v.EffectBulletInitPosList.Count; i++)
			m_EffectBulletInitPosList.Add( new ActionV3WraperV1());
		for( int i=0; i<v.EffectBulletInitPosList.Count; i++)
			m_EffectBulletInitPosList[i].FromPB(v.EffectBulletInitPosList[i]);
		m_EffectBulletLaunchMaxCount = v.EffectBulletLaunchMaxCount;
		m_EffectBulletIsFollow = v.EffectBulletIsFollow;
		m_AttackBehaviourAirDownSpeed = v.AttackBehaviourAirDownSpeed;
		m_EffectDirectionLockType = v.EffectDirectionLockType;
		m_IsIrregularityEffect = v.IsIrregularityEffect;
		m_EffectSize.FromPB(v.EffectSize);
		m_AttackRangePostion.FromPB(v.AttackRangePostion);
		m_AttackRangeSize.FromPB(v.AttackRangeSize);
		m_AttackShape = v.AttackShape;
		m_AttackCircleOrigin.FromPB(v.AttackCircleOrigin);
		m_AttackCircleRadius = v.AttackCircleRadius;
		m_AttackCircleAngle = v.AttackCircleAngle;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActionCommandInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActionCommandInfoV1 pb = ProtoBuf.Serializer.Deserialize<ActionCommandInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//CommandType
	public int m_CommandType;
	public int CommandType
	{
		get { return m_CommandType;}
		set { m_CommandType = value; }
	}
	//StartTime
	public float m_StartTime;
	public float StartTime
	{
		get { return m_StartTime;}
		set { m_StartTime = value; }
	}
	//DurationTime
	public float m_DurationTime;
	public float DurationTime
	{
		get { return m_DurationTime;}
		set { m_DurationTime = value; }
	}
	//AnimationTriggerCondition
	public int m_AnimationTriggerCondition;
	public int AnimationTriggerCondition
	{
		get { return m_AnimationTriggerCondition;}
		set { m_AnimationTriggerCondition = value; }
	}
	//EffectName
	public string m_EffectName;
	public string EffectName
	{
		get { return m_EffectName;}
		set { m_EffectName = value; }
	}
	//EffectBoneHook
	public int m_EffectBoneHook;
	public int EffectBoneHook
	{
		get { return m_EffectBoneHook;}
		set { m_EffectBoneHook = value; }
	}
	//EffectPositionOffset
	public ActionV3WraperV1 m_EffectPositionOffset;
	public ActionV3WraperV1 EffectPositionOffset
	{
		get { return m_EffectPositionOffset;}
		set { m_EffectPositionOffset = value; }
	}
	//EffectStayInLocalSpace
	public bool m_EffectStayInLocalSpace;
	public bool EffectStayInLocalSpace
	{
		get { return m_EffectStayInLocalSpace;}
		set { m_EffectStayInLocalSpace = value; }
	}
	//EffectControlObjectId
	public int m_EffectControlObjectId;
	public int EffectControlObjectId
	{
		get { return m_EffectControlObjectId;}
		set { m_EffectControlObjectId = value; }
	}
	//TranslateControlId
	public int m_TranslateControlId;
	public int TranslateControlId
	{
		get { return m_TranslateControlId;}
		set { m_TranslateControlId = value; }
	}
	//TranslateOffset
	public ActionV3WraperV1 m_TranslateOffset;
	public ActionV3WraperV1 TranslateOffset
	{
		get { return m_TranslateOffset;}
		set { m_TranslateOffset = value; }
	}
	//ActorAttackPart
	public List<int> m_ActorAttackPart;
	public int SizeActorAttackPart()
	{
		return m_ActorAttackPart.Count;
	}
	public List<int> GetActorAttackPart()
	{
		return m_ActorAttackPart;
	}
	public int GetActorAttackPart(int Index)
	{
		if(Index<0 || Index>=(int)m_ActorAttackPart.Count)
			return 0;
		return m_ActorAttackPart[Index];
	}
	public void SetActorAttackPart( List<int> v )
	{
		m_ActorAttackPart=v;
	}
	public void SetActorAttackPart( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_ActorAttackPart.Count)
			return;
		m_ActorAttackPart[Index] = v;
	}
	public void AddActorAttackPart( int v=0 )
	{
		m_ActorAttackPart.Add(v);
	}
	public void ClearActorAttackPart( )
	{
		m_ActorAttackPart.Clear();
	}
	//TranslateEase
	public int m_TranslateEase;
	public int TranslateEase
	{
		get { return m_TranslateEase;}
		set { m_TranslateEase = value; }
	}
	//AttackShowHitEffect
	public bool m_AttackShowHitEffect;
	public bool AttackShowHitEffect
	{
		get { return m_AttackShowHitEffect;}
		set { m_AttackShowHitEffect = value; }
	}
	//AttackHitEffectName
	public string m_AttackHitEffectName;
	public string AttackHitEffectName
	{
		get { return m_AttackHitEffectName;}
		set { m_AttackHitEffectName = value; }
	}
	//AttackHitEffectDuration
	public float m_AttackHitEffectDuration;
	public float AttackHitEffectDuration
	{
		get { return m_AttackHitEffectDuration;}
		set { m_AttackHitEffectDuration = value; }
	}
	//AttackFragmentCount
	public int m_AttackFragmentCount;
	public int AttackFragmentCount
	{
		get { return m_AttackFragmentCount;}
		set { m_AttackFragmentCount = value; }
	}
	//AttackFragmentIntervalTime
	public float m_AttackFragmentIntervalTime;
	public float AttackFragmentIntervalTime
	{
		get { return m_AttackFragmentIntervalTime;}
		set { m_AttackFragmentIntervalTime = value; }
	}
	//AttackDamageRadio
	public float m_AttackDamageRadio;
	public float AttackDamageRadio
	{
		get { return m_AttackDamageRadio;}
		set { m_AttackDamageRadio = value; }
	}
	//BuffSelfActive
	public bool m_BuffSelfActive;
	public bool BuffSelfActive
	{
		get { return m_BuffSelfActive;}
		set { m_BuffSelfActive = value; }
	}
	//BuffTargetActive
	public bool m_BuffTargetActive;
	public bool BuffTargetActive
	{
		get { return m_BuffTargetActive;}
		set { m_BuffTargetActive = value; }
	}
	//AttackBehaviourBackDistance
	public float m_AttackBehaviourBackDistance;
	public float AttackBehaviourBackDistance
	{
		get { return m_AttackBehaviourBackDistance;}
		set { m_AttackBehaviourBackDistance = value; }
	}
	//AttackBehaviourAirHeight
	public float m_AttackBehaviourAirHeight;
	public float AttackBehaviourAirHeight
	{
		get { return m_AttackBehaviourAirHeight;}
		set { m_AttackBehaviourAirHeight = value; }
	}
	//EffectRotationOffset
	public ActionV3WraperV1 m_EffectRotationOffset;
	public ActionV3WraperV1 EffectRotationOffset
	{
		get { return m_EffectRotationOffset;}
		set { m_EffectRotationOffset = value; }
	}
	//FlashControlObjectId
	public int m_FlashControlObjectId;
	public int FlashControlObjectId
	{
		get { return m_FlashControlObjectId;}
		set { m_FlashControlObjectId = value; }
	}
	//AttackStiffTime
	public float m_AttackStiffTime;
	public float AttackStiffTime
	{
		get { return m_AttackStiffTime;}
		set { m_AttackStiffTime = value; }
	}
	//AttackShake
	public bool m_AttackShake;
	public bool AttackShake
	{
		get { return m_AttackShake;}
		set { m_AttackShake = value; }
	}
	//AttackFlash
	public bool m_AttackFlash;
	public bool AttackFlash
	{
		get { return m_AttackFlash;}
		set { m_AttackFlash = value; }
	}
	//AttackBehaviourBackSpeed
	public float m_AttackBehaviourBackSpeed;
	public float AttackBehaviourBackSpeed
	{
		get { return m_AttackBehaviourBackSpeed;}
		set { m_AttackBehaviourBackSpeed = value; }
	}
	//AttackBehaviourAirSpped
	public float m_AttackBehaviourAirSpeed;
	public float AttackBehaviourAirSpeed
	{
		get { return m_AttackBehaviourAirSpeed;}
		set { m_AttackBehaviourAirSpeed = value; }
	}
	//AttackBehaviourBack
	public bool m_AttackBehaviourBack;
	public bool AttackBehaviourBack
	{
		get { return m_AttackBehaviourBack;}
		set { m_AttackBehaviourBack = value; }
	}
	//AttackBehaviourAir
	public bool m_AttackBehaviourAir;
	public bool AttackBehaviourAir
	{
		get { return m_AttackBehaviourAir;}
		set { m_AttackBehaviourAir = value; }
	}
	//AttackBehaviourZoom
	public bool m_AttackBehaviourZoom;
	public bool AttackBehaviourZoom
	{
		get { return m_AttackBehaviourZoom;}
		set { m_AttackBehaviourZoom = value; }
	}
	//SoundName
	public string m_SoundName;
	public string SoundName
	{
		get { return m_SoundName;}
		set { m_SoundName = value; }
	}
	//Trigger
	public bool m_Trigger;
	public bool Trigger
	{
		get { return m_Trigger;}
		set { m_Trigger = value; }
	}
	//TriggerIndex
	public int m_TriggerIndex;
	public int TriggerIndex
	{
		get { return m_TriggerIndex;}
		set { m_TriggerIndex = value; }
	}
	//受击挂载点 1原点 2头 3 胸
	public int m_AttackHitDummy;
	public int AttackHitDummy
	{
		get { return m_AttackHitDummy;}
		set { m_AttackHitDummy = value; }
	}
	//受击音效
	public string m_AttackHitSound;
	public string AttackHitSound
	{
		get { return m_AttackHitSound;}
		set { m_AttackHitSound = value; }
	}
	//受击震动X范围
	public float m_HitShakeCameraXRange;
	public float HitShakeCameraXRange
	{
		get { return m_HitShakeCameraXRange;}
		set { m_HitShakeCameraXRange = value; }
	}
	//受击震动Y范围
	public float m_HitShakeCameraYRange;
	public float HitShakeCameraYRange
	{
		get { return m_HitShakeCameraYRange;}
		set { m_HitShakeCameraYRange = value; }
	}
	//震屏次数
	public int m_HitShakeCameraCount;
	public int HitShakeCameraCount
	{
		get { return m_HitShakeCameraCount;}
		set { m_HitShakeCameraCount = value; }
	}
	//震屏时长
	public float m_HitShakeCameraDurationTime;
	public float HitShakeCameraDurationTime
	{
		get { return m_HitShakeCameraDurationTime;}
		set { m_HitShakeCameraDurationTime = value; }
	}
	//隐藏武器
	public int m_HiddenWeaponMode;
	public int HiddenWeaponMode
	{
		get { return m_HiddenWeaponMode;}
		set { m_HiddenWeaponMode = value; }
	}
	//下个技能名字
	public string m_NextActionName;
	public string NextActionName
	{
		get { return m_NextActionName;}
		set { m_NextActionName = value; }
	}
	//位移类型
	public int m_TranslateWrapMode;
	public int TranslateWrapMode
	{
		get { return m_TranslateWrapMode;}
		set { m_TranslateWrapMode = value; }
	}
	//是否触发触发器
	public bool m_IsTriggerSecondAttack;
	public bool IsTriggerSecondAttack
	{
		get { return m_IsTriggerSecondAttack;}
		set { m_IsTriggerSecondAttack = value; }
	}
	//受击是否倒地
	public bool m_IsHitGround;
	public bool IsHitGround
	{
		get { return m_IsHitGround;}
		set { m_IsHitGround = value; }
	}
	//技能编辑文件名字
	public string m_SkillActionName;
	public string SkillActionName
	{
		get { return m_SkillActionName;}
		set { m_SkillActionName = value; }
	}
	//预警资源1
	public string m_WarningRes1;
	public string WarningRes1
	{
		get { return m_WarningRes1;}
		set { m_WarningRes1 = value; }
	}
	//预警资源2
	public string m_WarningRes2;
	public string WarningRes2
	{
		get { return m_WarningRes2;}
		set { m_WarningRes2 = value; }
	}
	//预警最大缩放
	public ActionV3WraperV1 m_WarningMaxScale;
	public ActionV3WraperV1 WarningMaxScale
	{
		get { return m_WarningMaxScale;}
		set { m_WarningMaxScale = value; }
	}
	//预警缩放模式
	public int m_WarningScaleMode;
	public int WarningScaleMode
	{
		get { return m_WarningScaleMode;}
		set { m_WarningScaleMode = value; }
	}
	//锁定轴向
	public int m_WarningLockAxle;
	public int WarningLockAxle
	{
		get { return m_WarningLockAxle;}
		set { m_WarningLockAxle = value; }
	}
	//预警偏移
	public ActionV3WraperV1 m_WarningPositionOffset;
	public ActionV3WraperV1 WarningPositionOffset
	{
		get { return m_WarningPositionOffset;}
		set { m_WarningPositionOffset = value; }
	}
	//是否跟随旋转
	public bool m_IsEffectFollow;
	public bool IsEffectFollow
	{
		get { return m_IsEffectFollow;}
		set { m_IsEffectFollow = value; }
	}
	//预警是否需要目标
	public bool m_IsWarningTarget;
	public bool IsWarningTarget
	{
		get { return m_IsWarningTarget;}
		set { m_IsWarningTarget = value; }
	}
	//浮空 空中持续时间
	public float m_AttackBehaviourAirDurationTime;
	public float AttackBehaviourAirDurationTime
	{
		get { return m_AttackBehaviourAirDurationTime;}
		set { m_AttackBehaviourAirDurationTime = value; }
	}
	//特效碰撞之后是否删除
	public bool m_IsColliderDestroy;
	public bool IsColliderDestroy
	{
		get { return m_IsColliderDestroy;}
		set { m_IsColliderDestroy = value; }
	}
	//攻击范围是否跟随移动
	public bool m_IsAttackRangeFollow;
	public bool IsAttackRangeFollow
	{
		get { return m_IsAttackRangeFollow;}
		set { m_IsAttackRangeFollow = value; }
	}
	//动画是否循环
	public bool m_IsAnimationLoop;
	public bool IsAnimationLoop
	{
		get { return m_IsAnimationLoop;}
		set { m_IsAnimationLoop = value; }
	}
	//运动角度（0-360）
	public float m_TranslateAngle;
	public float TranslateAngle
	{
		get { return m_TranslateAngle;}
		set { m_TranslateAngle = value; }
	}
	//是否是遮罩范围
	public bool m_IsAttackRangeShade;
	public bool IsAttackRangeShade
	{
		get { return m_IsAttackRangeShade;}
		set { m_IsAttackRangeShade = value; }
	}
	//攻击间隔时间
	public float m_AttackInterval;
	public float AttackInterval
	{
		get { return m_AttackInterval;}
		set { m_AttackInterval = value; }
	}
	//是否显示攻击矩形
	public bool m_IsShowAttackRect;
	public bool IsShowAttackRect
	{
		get { return m_IsShowAttackRect;}
		set { m_IsShowAttackRect = value; }
	}
	//子弹发射角度
	public float m_EffectBulletLaunchAngle;
	public float EffectBulletLaunchAngle
	{
		get { return m_EffectBulletLaunchAngle;}
		set { m_EffectBulletLaunchAngle = value; }
	}
	//子弹速度
	public float m_EffectBulletSpeed;
	public float EffectBulletSpeed
	{
		get { return m_EffectBulletSpeed;}
		set { m_EffectBulletSpeed = value; }
	}
	//每个弹道子弹发射时间间隔
	public ActionRangeWraperV1 m_EffectBulletLaunchTimeIntervalRange;
	public ActionRangeWraperV1 EffectBulletLaunchTimeIntervalRange
	{
		get { return m_EffectBulletLaunchTimeIntervalRange;}
		set { m_EffectBulletLaunchTimeIntervalRange = value; }
	}
	//子弹总数量
	public int m_EffectBulletMaxCout;
	public int EffectBulletMaxCout
	{
		get { return m_EffectBulletMaxCout;}
		set { m_EffectBulletMaxCout = value; }
	}
	//子弹存活时间间隔
	public ActionRangeWraperV1 m_EffectBulletLifeTimeInteralRange;
	public ActionRangeWraperV1 EffectBulletLifeTimeInteralRange
	{
		get { return m_EffectBulletLifeTimeInteralRange;}
		set { m_EffectBulletLifeTimeInteralRange = value; }
	}
	//子弹类型
	public int m_EffectBulletType;
	public int EffectBulletType
	{
		get { return m_EffectBulletType;}
		set { m_EffectBulletType = value; }
	}
	//子弹初始位置
	public List<ActionV3WraperV1> m_EffectBulletInitPosList;
	public int SizeEffectBulletInitPosList()
	{
		return m_EffectBulletInitPosList.Count;
	}
	public List<ActionV3WraperV1> GetEffectBulletInitPosList()
	{
		return m_EffectBulletInitPosList;
	}
	public ActionV3WraperV1 GetEffectBulletInitPosList(int Index)
	{
		if(Index<0 || Index>=(int)m_EffectBulletInitPosList.Count)
			return new ActionV3WraperV1();
		return m_EffectBulletInitPosList[Index];
	}
	public void SetEffectBulletInitPosList( List<ActionV3WraperV1> v )
	{
		m_EffectBulletInitPosList=v;
	}
	public void SetEffectBulletInitPosList( int Index, ActionV3WraperV1 v )
	{
		if(Index<0 || Index>=(int)m_EffectBulletInitPosList.Count)
			return;
		m_EffectBulletInitPosList[Index] = v;
	}
	public void AddEffectBulletInitPosList( ActionV3WraperV1 v )
	{
		m_EffectBulletInitPosList.Add(v);
	}
	public void ClearEffectBulletInitPosList( )
	{
		m_EffectBulletInitPosList.Clear();
	}
	//单个弹道发射最大数量
	public int m_EffectBulletLaunchMaxCount;
	public int EffectBulletLaunchMaxCount
	{
		get { return m_EffectBulletLaunchMaxCount;}
		set { m_EffectBulletLaunchMaxCount = value; }
	}
	//子弹是否跟随人物方向转向
	public bool m_EffectBulletIsFollow;
	public bool EffectBulletIsFollow
	{
		get { return m_EffectBulletIsFollow;}
		set { m_EffectBulletIsFollow = value; }
	}
	//浮空降落速度
	public float m_AttackBehaviourAirDownSpeed;
	public float AttackBehaviourAirDownSpeed
	{
		get { return m_AttackBehaviourAirDownSpeed;}
		set { m_AttackBehaviourAirDownSpeed = value; }
	}
	//特效方向锁定类型
	public int m_EffectDirectionLockType;
	public int EffectDirectionLockType
	{
		get { return m_EffectDirectionLockType;}
		set { m_EffectDirectionLockType = value; }
	}
	//是否是不规则特效
	public bool m_IsIrregularityEffect;
	public bool IsIrregularityEffect
	{
		get { return m_IsIrregularityEffect;}
		set { m_IsIrregularityEffect = value; }
	}
	//特效size
	public ActionV3WraperV1 m_EffectSize;
	public ActionV3WraperV1 EffectSize
	{
		get { return m_EffectSize;}
		set { m_EffectSize = value; }
	}
	//攻击范围起点(右上点)
	public ActionV3WraperV1 m_AttackRangePostion;
	public ActionV3WraperV1 AttackRangePostion
	{
		get { return m_AttackRangePostion;}
		set { m_AttackRangePostion = value; }
	}
	//攻击范围的宽高
	public ActionV3WraperV1 m_AttackRangeSize;
	public ActionV3WraperV1 AttackRangeSize
	{
		get { return m_AttackRangeSize;}
		set { m_AttackRangeSize = value; }
	}
	//攻击形状
	public int m_AttackShape;
	public int AttackShape
	{
		get { return m_AttackShape;}
		set { m_AttackShape = value; }
	}
	//圆形攻击形状原点
	public ActionV3WraperV1 m_AttackCircleOrigin;
	public ActionV3WraperV1 AttackCircleOrigin
	{
		get { return m_AttackCircleOrigin;}
		set { m_AttackCircleOrigin = value; }
	}
	//半径
	public float m_AttackCircleRadius;
	public float AttackCircleRadius
	{
		get { return m_AttackCircleRadius;}
		set { m_AttackCircleRadius = value; }
	}
	//角度
	public float m_AttackCircleAngle;
	public float AttackCircleAngle
	{
		get { return m_AttackCircleAngle;}
		set { m_AttackCircleAngle = value; }
	}


};
//V2封装类
[System.Serializable]
public class ActionV2WraperV1
{

	//构造函数
	public ActionV2WraperV1()
	{
		 m_X = (float)0;
		 m_Y = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_X = (float)0;
		 m_Y = (float)0;

	}

 	//转化成Protobuffer类型函数
	public ActionV2V1 ToPB()
	{
		ActionV2V1 v = new ActionV2V1();
		v.X = m_X;
		v.Y = m_Y;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActionV2V1 v)
	{
        if (v == null)
            return;
		m_X = v.X;
		m_Y = v.Y;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActionV2V1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActionV2V1 pb = ProtoBuf.Serializer.Deserialize<ActionV2V1>(protoMS);
		FromPB(pb);
		return true;
	}

	//X
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//Y
	public float m_Y;
	public float Y
	{
		get { return m_Y;}
		set { m_Y = value; }
	}


};
//V3封装类
[System.Serializable]
public class ActionV3WraperV1
{

	//构造函数
	public ActionV3WraperV1()
	{
		 m_X = (float)0;
		 m_Y = (float)0;
		 m_Z = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_X = (float)0;
		 m_Y = (float)0;
		 m_Z = (float)0;

	}

 	//转化成Protobuffer类型函数
	public ActionV3V1 ToPB()
	{
		ActionV3V1 v = new ActionV3V1();
		v.X = m_X;
		v.Y = m_Y;
		v.Z = m_Z;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActionV3V1 v)
	{
        if (v == null)
            return;
		m_X = v.X;
		m_Y = v.Y;
		m_Z = v.Z;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActionV3V1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActionV3V1 pb = ProtoBuf.Serializer.Deserialize<ActionV3V1>(protoMS);
		FromPB(pb);
		return true;
	}

	//X
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//Y
	public float m_Y;
	public float Y
	{
		get { return m_Y;}
		set { m_Y = value; }
	}
	//Z
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}


};
//Range封装类
[System.Serializable]
public class ActionRangeWraperV1
{

	//构造函数
	public ActionRangeWraperV1()
	{
		 m_MinValue = (float)0;
		 m_MaxValue = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MinValue = (float)0;
		 m_MaxValue = (float)0;

	}

 	//转化成Protobuffer类型函数
	public ActionRangeV1 ToPB()
	{
		ActionRangeV1 v = new ActionRangeV1();
		v.MinValue = m_MinValue;
		v.MaxValue = m_MaxValue;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActionRangeV1 v)
	{
        if (v == null)
            return;
		m_MinValue = v.MinValue;
		m_MaxValue = v.MaxValue;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActionRangeV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActionRangeV1 pb = ProtoBuf.Serializer.Deserialize<ActionRangeV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//最小数
	public float m_MinValue;
	public float MinValue
	{
		get { return m_MinValue;}
		set { m_MinValue = value; }
	}
	//最大数
	public float m_MaxValue;
	public float MaxValue
	{
		get { return m_MaxValue;}
		set { m_MaxValue = value; }
	}


};
