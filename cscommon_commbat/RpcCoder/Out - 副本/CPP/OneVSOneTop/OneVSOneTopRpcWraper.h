/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperOneVSOneTop.h
* Author:       甘业清
* Description:  排行榜RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_ONEVSONETOP_H
#define __RPC_WRAPER_ONEVSONETOP_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "OneVSOneTopRpc.pb.h"



//排行榜类的枚举定义
enum ConstOneVSOneTopE
{
	MODULE_ID_ONEVSONETOP                        = 42,	//排行榜模块ID


};



template<typename T> struct MessageIdT;


#endif
