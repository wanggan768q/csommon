/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperDramaModule.h
* Author:       甘业清
* Description:  剧情模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_DRAMAMODULE_H
#define __RPC_WRAPER_DRAMAMODULE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "DramaModuleRpc.pb.h"



//剧情模块类的枚举定义
enum ConstDramaModuleE
{
	MODULE_ID_DRAMAMODULE                        = 999,	//剧情模块模块ID


};



template<typename T> struct MessageIdT;


#endif
