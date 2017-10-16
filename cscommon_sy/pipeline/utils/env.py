#!/usr/bin/env python
#coding=utf-8

import re
import os
import platform

# 该模块用于定位整个游戏项目需要的所有环境.
# 包括了工程相关的目录, 三方软件所在目录的全部管理.
# 其他模块都必须从这里来引用相对路径，而不允许自己来搜索拼目录.

# 系统的判断检查
def isWindowsSystem():
    return 'Windows' in platform.system()

def isLinuxSystem():
    return 'Linux' in platform.system()

def isMacSystem():
    return 'Darwin' in platform.system()

# 工程相关的路径
SCRIPT_PATH = os.path.dirname(os.path.realpath(__file__))
ROOT_PATH = os.path.realpath("%s/../../../../../" %(SCRIPT_PATH))

BUILD_PATH = "%s/ice_client/common/Build/" %(ROOT_PATH)
CLIENT_PATH = "%s/ice_client/" %(ROOT_PATH)
CONFIG_PATH = "%s/ice_cehua/trunk/Config/" %(ROOT_PATH)
COMMON_PATH = "%s/ice_client/common/" %(ROOT_PATH)
FOUNDATION_PATH = "%s/foundation/" %(ROOT_PATH)
SERVER_PATH = "%s/ice_server/" %(ROOT_PATH)

GAMEPROJ_PATH = "%s/client/GameProj" %(ROOT_PATH)
I18N_MESSAGE_PATH = "%s/client/I18N/data_msg" %(ROOT_PATH)
CLIENT_CONFIG_PATH = "%s/ice_client/common/Config/Lua/" %(ROOT_PATH)
SERVER_CONFIG_PATH = "%s/ice_client/common/Config/Json/" %(ROOT_PATH)

# 系统相关的工具路径
UNITY_PATH = '/Applications/Unity/Unity.app/Contents/MacOS/Unity'

# 上传服务器的地址和账户
UPLOAD_ASSETBUNDLE_URL    = '117.121.25.155'
UPLOAD_ASSETBUNDLE_DIR    = 'BlingARPG/AssetBundles/'
UPLOAD_ASSETBUNDLE_USER   = 'h5'
UPLOAD_ASSETBUNDLE_PASSWD = 'Bling_h5'

UPLOAD_PACKAGE_URL    = '192.168.0.240'
UPLOAD_PACKAGE_DIR    = '/home/assert/'
UPLOAD_PACKAGE_USER   = 'root'
UPLOAD_PACKAGE_PASSWD = 'bling&*('

#240服务器的用户名和密码
IP_240 = '10.6.0.240'
PORT_240 = 22
USR_240 = 'root'
PWD_240 = 'bling&*('
PATH_240 = '/home/jiangwang/server/trunk/bin/'
#客户端场景配置路径
CLIENT_LEVELCONFIG_PATH = '%s/client/GameProj/Assets/Resources/BlingARPG/Scenes/LevelConfig' %(ROOT_PATH)
