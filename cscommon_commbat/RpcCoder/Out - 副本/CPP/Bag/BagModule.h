/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleBag.h
* Author:       甘业清
* Description:  背包类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
*               ★服务器后台RPC函数
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __MODULE_BAG_H
#define __MODULE_BAG_H


#include "ModuleBase.h"
#include "BagRpcWraper.h"
#include "BagV1Data.h"
#include "BagV1DataWraper.h"




//背包实现类
class ModuleBag : public ModuleBase
{
	DECLARE_INSTANCE(ModuleBag);
public:
	friend class			ModuleMgr;

public:
	//背包实现类构造函数
	ModuleBag();
	
	//背包实现类析构函数
	virtual					~ModuleBag();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//获取模块同步(保存)数据版本及类名
	virtual map<INT32,TStr>	GetModuleDataVersionName();
	
	//模块数据保存类型
	virtual SavedDataTypeE	GetSavedDataType();

	//获取初始化顺序
	virtual int				GetInitializeOrder();
	
	//获取结束退出顺序
	virtual int				GetFinalizeOrder();
	
	//初始化
	virtual bool			Initialize();
	
	//结束退出
	virtual void			Finalize();

	//毫秒级Tick回调
	virtual void			OnTick( INT64 currentMiliSecond );
	
	//秒级Tick回调
	virtual void			OnSecondTick( time_t currentSecond );
	
	//分钟改变回调
	virtual void			OnMinuteChange( time_t currentSecond);
	
	//小时改变回调
	virtual void			OnHourChange( time_t currentSecond );
	
	//天改变回调
	virtual void			OnDayChange( time_t currentSecond );

	//创建用户回调
	virtual void			OnUserCreate( INT64 userId, const TStr& userName );
	
	//用户上线回调
	virtual void			OnUserOnline( INT64 userId, time_t lastLogoutTime );
	
	//用户下线回调
	virtual void			OnUserOffline( INT64 userId );

	//是否要同步数据到客户端
	virtual bool			NotSyncToClient( UINT16 usSyncId );
	
	//同步数据修改后回调
	virtual void			NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex=-1);

public:
	/********************************************************************************************
	* Function:       RpcSyncData
	* Description:    背包-->同步背包数据同步调用操作函数
	* Input:          BagRpcSyncDataAskWraper& Ask 同步背包数据请求
	* Output:         BagRpcSyncDataReplyWraper& Reply 同步背包数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSyncData( INT64 UserId, BagRpcSyncDataAskWraper& Ask, BagRpcSyncDataReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcSell
	* Description:    背包-->物品出售同步调用操作函数
	* Input:          BagRpcSellAskWraper& Ask 出售请求
	* Output:         BagRpcSellReplyWraper& Reply 出售回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSell( INT64 UserId, BagRpcSellAskWraper& Ask, BagRpcSellReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcDecompose
	* Description:    背包-->物品分解同步调用操作函数
	* Input:          BagRpcDecomposeAskWraper& Ask 分解请求
	* Output:         BagRpcDecomposeReplyWraper& Reply 分解回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcDecompose( INT64 UserId, BagRpcDecomposeAskWraper& Ask, BagRpcDecomposeReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcUse
	* Description:    背包-->物品使用同步调用操作函数
	* Input:          BagRpcUseAskWraper& Ask 物品使用请求
	* Output:         BagRpcUseReplyWraper& Reply 物品使用回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcUse( INT64 UserId, BagRpcUseAskWraper& Ask, BagRpcUseReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcEquipWear
	* Description:    背包-->装备穿戴同步调用操作函数
	* Input:          BagRpcEquipWearAskWraper& Ask 装备穿戴请求
	* Output:         BagRpcEquipWearReplyWraper& Reply 装备穿戴回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcEquipWear( INT64 UserId, BagRpcEquipWearAskWraper& Ask, BagRpcEquipWearReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcEquipUndress
	* Description:    背包-->装备脱下同步调用操作函数
	* Input:          BagRpcEquipUndressAskWraper& Ask 装备脱下请求
	* Output:         BagRpcEquipUndressReplyWraper& Reply 装备脱下回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcEquipUndress( INT64 UserId, BagRpcEquipUndressAskWraper& Ask, BagRpcEquipUndressReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcEquipEnhance
	* Description:    背包-->装备强化同步调用操作函数
	* Input:          BagRpcEquipEnhanceAskWraper& Ask 装备强化请求
	* Output:         BagRpcEquipEnhanceReplyWraper& Reply 装备强化回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcEquipEnhance( INT64 UserId, BagRpcEquipEnhanceAskWraper& Ask, BagRpcEquipEnhanceReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcEquipPolished
	* Description:    背包-->装备洗炼同步调用操作函数
	* Input:          BagRpcEquipPolishedAskWraper& Ask 装备洗炼请求
	* Output:         BagRpcEquipPolishedReplyWraper& Reply 装备洗炼回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcEquipPolished( INT64 UserId, BagRpcEquipPolishedAskWraper& Ask, BagRpcEquipPolishedReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcEquipPolishedReplace
	* Description:    背包-->装备洗炼属性替换同步调用操作函数
	* Input:          BagRpcEquipPolishedReplaceAskWraper& Ask 装备洗炼属性替换请求
	* Output:         BagRpcEquipPolishedReplaceReplyWraper& Reply 装备洗炼属性替换回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcEquipPolishedReplace( INT64 UserId, BagRpcEquipPolishedReplaceAskWraper& Ask, BagRpcEquipPolishedReplaceReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcBagTidy
	* Description:    背包-->背包整理同步调用操作函数
	* Input:          BagRpcBagTidyAskWraper& Ask 背包整理请求
	* Output:         BagRpcBagTidyReplyWraper& Reply 背包整理回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcBagTidy( INT64 UserId, BagRpcBagTidyAskWraper& Ask, BagRpcBagTidyReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcBagRecycleSell
	* Description:    背包-->装备回收出售同步调用操作函数
	* Input:          BagRpcBagRecycleSellAskWraper& Ask 装备回收出售请求
	* Output:         BagRpcBagRecycleSellReplyWraper& Reply 装备回收出售回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcBagRecycleSell( INT64 UserId, BagRpcBagRecycleSellAskWraper& Ask, BagRpcBagRecycleSellReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcBagRecycleBuy
	* Description:    背包-->物品回收，购回同步调用操作函数
	* Input:          BagRpcBagRecycleBuyAskWraper& Ask 物品回收，购回请求
	* Output:         BagRpcBagRecycleBuyReplyWraper& Reply 物品回收，购回回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcBagRecycleBuy( INT64 UserId, BagRpcBagRecycleBuyAskWraper& Ask, BagRpcBagRecycleBuyReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcUnlockGrid
	* Description:    背包-->开启格子同步调用操作函数
	* Input:          BagRpcUnlockGridAskWraper& Ask 开启格子请求
	* Output:         BagRpcUnlockGridReplyWraper& Reply 开启格子回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcUnlockGrid( INT64 UserId, BagRpcUnlockGridAskWraper& Ask, BagRpcUnlockGridReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcSplit
	* Description:    背包-->物品拆分同步调用操作函数
	* Input:          BagRpcSplitAskWraper& Ask 物品拆分请求
	* Output:         BagRpcSplitReplyWraper& Reply 物品拆分回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSplit( INT64 UserId, BagRpcSplitAskWraper& Ask, BagRpcSplitReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcEquipBaseAttrPlished
	* Description:    背包-->装备基础属性洗炼同步调用操作函数
	* Input:          BagRpcEquipBaseAttrPlishedAskWraper& Ask 装备基础属性洗炼请求
	* Output:         BagRpcEquipBaseAttrPlishedReplyWraper& Reply 装备基础属性洗炼回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcEquipBaseAttrPlished( INT64 UserId, BagRpcEquipBaseAttrPlishedAskWraper& Ask, BagRpcEquipBaseAttrPlishedReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcEquipBaseAttrPolishedReplace
	* Description:    背包-->装备基础属性洗炼替换同步调用操作函数
	* Input:          BagRpcEquipBaseAttrPolishedReplaceAskWraper& Ask 装备基础属性洗炼替换请求
	* Output:         BagRpcEquipBaseAttrPolishedReplaceReplyWraper& Reply 装备基础属性洗炼替换回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcEquipBaseAttrPolishedReplace( INT64 UserId, BagRpcEquipBaseAttrPolishedReplaceAskWraper& Ask, BagRpcEquipBaseAttrPolishedReplaceReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcEquipExAttrModify
	* Description:    背包-->装备改造同步调用操作函数
	* Input:          BagRpcEquipExAttrModifyAskWraper& Ask 装备改造请求
	* Output:         BagRpcEquipExAttrModifyReplyWraper& Reply 装备改造回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcEquipExAttrModify( INT64 UserId, BagRpcEquipExAttrModifyAskWraper& Ask, BagRpcEquipExAttrModifyReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcEquipInlayGem
	* Description:    背包-->宝石镶嵌同步调用操作函数
	* Input:          BagRpcEquipInlayGemAskWraper& Ask 宝石镶嵌请求
	* Output:         BagRpcEquipInlayGemReplyWraper& Reply 宝石镶嵌回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcEquipInlayGem( INT64 UserId, BagRpcEquipInlayGemAskWraper& Ask, BagRpcEquipInlayGemReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcEquipGemSlotUnlock
	* Description:    背包-->装备宝石槽位打孔同步调用操作函数
	* Input:          BagRpcEquipGemSlotUnlockAskWraper& Ask 装备宝石槽位打孔请求
	* Output:         BagRpcEquipGemSlotUnlockReplyWraper& Reply 装备宝石槽位打孔回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcEquipGemSlotUnlock( INT64 UserId, BagRpcEquipGemSlotUnlockAskWraper& Ask, BagRpcEquipGemSlotUnlockReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcEquipEnhanceSwap
	* Description:    背包-->装备强化转移同步调用操作函数
	* Input:          BagRpcEquipEnhanceSwapAskWraper& Ask 装备强化转移请求
	* Output:         BagRpcEquipEnhanceSwapReplyWraper& Reply 装备强化转移回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcEquipEnhanceSwap( INT64 UserId, BagRpcEquipEnhanceSwapAskWraper& Ask, BagRpcEquipEnhanceSwapReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcEquipGemRemove
	* Description:    背包-->装备宝石移除同步调用操作函数
	* Input:          BagRpcEquipGemRemoveAskWraper& Ask 装备宝石移除请求
	* Output:         BagRpcEquipGemRemoveReplyWraper& Reply 装备宝石移除回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcEquipGemRemove( INT64 UserId, BagRpcEquipGemRemoveAskWraper& Ask, BagRpcEquipGemRemoveReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcBagPutInStorage
	* Description:    背包-->存入仓库同步调用操作函数
	* Input:          BagRpcBagPutInStorageAskWraper& Ask 存入仓库请求
	* Output:         BagRpcBagPutInStorageReplyWraper& Reply 存入仓库回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcBagPutInStorage( INT64 UserId, BagRpcBagPutInStorageAskWraper& Ask, BagRpcBagPutInStorageReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcBagFetchFromStorage
	* Description:    背包-->从仓库取出同步调用操作函数
	* Input:          BagRpcBagFetchFromStorageAskWraper& Ask 从仓库取出请求
	* Output:         BagRpcBagFetchFromStorageReplyWraper& Reply 从仓库取出回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcBagFetchFromStorage( INT64 UserId, BagRpcBagFetchFromStorageAskWraper& Ask, BagRpcBagFetchFromStorageReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcBagStorageSaveMoney
	* Description:    背包-->仓库存钱同步调用操作函数
	* Input:          BagRpcBagStorageSaveMoneyAskWraper& Ask 仓库存钱请求
	* Output:         BagRpcBagStorageSaveMoneyReplyWraper& Reply 仓库存钱回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcBagStorageSaveMoney( INT64 UserId, BagRpcBagStorageSaveMoneyAskWraper& Ask, BagRpcBagStorageSaveMoneyReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcBagStorageDrawMoney
	* Description:    背包-->仓库取钱同步调用操作函数
	* Input:          BagRpcBagStorageDrawMoneyAskWraper& Ask 仓库取钱请求
	* Output:         BagRpcBagStorageDrawMoneyReplyWraper& Reply 仓库取钱回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcBagStorageDrawMoney( INT64 UserId, BagRpcBagStorageDrawMoneyAskWraper& Ask, BagRpcBagStorageDrawMoneyReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcStorageTidy
	* Description:    背包-->仓库整理同步调用操作函数
	* Input:          BagRpcStorageTidyAskWraper& Ask 仓库整理请求
	* Output:         BagRpcStorageTidyReplyWraper& Reply 仓库整理回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcStorageTidy( INT64 UserId, BagRpcStorageTidyAskWraper& Ask, BagRpcStorageTidyReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcTalismanLvup
	* Description:    背包-->法宝铸炼同步调用操作函数
	* Input:          BagRpcTalismanLvupAskWraper& Ask 法宝铸炼请求
	* Output:         BagRpcTalismanLvupReplyWraper& Reply 法宝铸炼回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcTalismanLvup( INT64 UserId, BagRpcTalismanLvupAskWraper& Ask, BagRpcTalismanLvupReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcTalismanInherit
	* Description:    背包-->法宝传承同步调用操作函数
	* Input:          BagRpcTalismanInheritAskWraper& Ask 法宝传承请求
	* Output:         BagRpcTalismanInheritReplyWraper& Reply 法宝传承回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcTalismanInherit( INT64 UserId, BagRpcTalismanInheritAskWraper& Ask, BagRpcTalismanInheritReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientBagAddNewItem
	* Description:    背包-->背包获得新物品异步通知操作函数
	* Input:          BagRpcBagAddNewItemNotifyWraper& Notify 背包获得新物品通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientBagAddNewItem( INT64 UserId, BagRpcBagAddNewItemNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcBagSetAutoPickup
	* Description:    背包-->设置自动拾取同步调用操作函数
	* Input:          BagRpcBagSetAutoPickupAskWraper& Ask 设置自动拾取请求
	* Output:         BagRpcBagSetAutoPickupReplyWraper& Reply 设置自动拾取回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcBagSetAutoPickup( INT64 UserId, BagRpcBagSetAutoPickupAskWraper& Ask, BagRpcBagSetAutoPickupReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientGetNewItem
	* Description:    背包-->获得新物品异步通知操作函数
	* Input:          BagRpcGetNewItemNotifyWraper& Notify 获得新物品通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientGetNewItem( INT64 UserId, BagRpcGetNewItemNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientBagError
	* Description:    背包-->背包错误异步通知操作函数
	* Input:          BagRpcBagErrorNotifyWraper& Notify 背包错误通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientBagError( INT64 UserId, BagRpcBagErrorNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcTalismanRefindStar
	* Description:    背包-->炼星同步调用操作函数
	* Input:          BagRpcTalismanRefindStarAskWraper& Ask 炼星请求
	* Output:         BagRpcTalismanRefindStarReplyWraper& Reply 炼星回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcTalismanRefindStar( INT64 UserId, BagRpcTalismanRefindStarAskWraper& Ask, BagRpcTalismanRefindStarReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcTalismanUpSlotSkillLevel
	* Description:    背包-->升级聚灵槽位技能同步调用操作函数
	* Input:          BagRpcTalismanUpSlotSkillLevelAskWraper& Ask 升级聚灵槽位技能请求
	* Output:         BagRpcTalismanUpSlotSkillLevelReplyWraper& Reply 升级聚灵槽位技能回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcTalismanUpSlotSkillLevel( INT64 UserId, BagRpcTalismanUpSlotSkillLevelAskWraper& Ask, BagRpcTalismanUpSlotSkillLevelReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientTalismanAttrChange
	* Description:    背包-->属性变化通知异步通知操作函数
	* Input:          BagRpcTalismanAttrChangeNotifyWraper& Notify 属性变化通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientTalismanAttrChange( INT64 UserId, BagRpcTalismanAttrChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcTalismanGatherSprite
	* Description:    背包-->宝石聚灵同步调用操作函数
	* Input:          BagRpcTalismanGatherSpriteAskWraper& Ask 宝石聚灵请求
	* Output:         BagRpcTalismanGatherSpriteReplyWraper& Reply 宝石聚灵回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcTalismanGatherSprite( INT64 UserId, BagRpcTalismanGatherSpriteAskWraper& Ask, BagRpcTalismanGatherSpriteReplyWraper& Reply );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif