/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperMMOMapData.h
* Author:       甘业清
* Description:  45度MMO地图数据RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_MMOMAPDATA_H
#define __RPC_WRAPER_MMOMAPDATA_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "MMOMapDataRpc.pb.h"



//45度MMO地图数据类的枚举定义
enum ConstMMOMapDataE
{
	MODULE_ID_MMOMAPDATA                         = 21,	//45度MMO地图数据模块ID


};



template<typename T> struct MessageIdT;


#endif
