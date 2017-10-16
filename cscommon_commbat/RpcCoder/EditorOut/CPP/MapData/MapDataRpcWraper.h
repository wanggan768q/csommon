/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperMapData.h
* Author:       甘业清
* Description:  场景数据RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_MAPDATA_H
#define __RPC_WRAPER_MAPDATA_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "MapDataRpc.pb.h"



//场景数据类的枚举定义
enum ConstMapDataE
{
	MODULE_ID_MAPDATA                            = 20,	//场景数据模块ID


};



template<typename T> struct MessageIdT;


#endif
