/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperRefreshData.h
* Author:       甘业清
* Description:  刷新数据RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_REFRESHDATA_H
#define __RPC_WRAPER_REFRESHDATA_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "RefreshDataRpc.pb.h"



//刷新数据类的枚举定义
enum ConstRefreshDataE
{
	MODULE_ID_REFRESHDATA                        = 39,	//刷新数据模块ID


};



template<typename T> struct MessageIdT;


#endif
