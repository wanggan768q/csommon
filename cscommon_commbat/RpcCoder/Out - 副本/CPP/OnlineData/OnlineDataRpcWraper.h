/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperOnlineData.h
* Author:       甘业清
* Description:  在线数据RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_ONLINEDATA_H
#define __RPC_WRAPER_ONLINEDATA_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "OnlineDataRpc.pb.h"



//在线数据类的枚举定义
enum ConstOnlineDataE
{
	MODULE_ID_ONLINEDATA                         = 28,	//在线数据模块ID


};



template<typename T> struct MessageIdT;


#endif
