#!/usr/bin/env python
#coding=utf-8

import os
import re
import env
import log
import data
from data import DataMgr
from xlsConfigMgr import xlsConfigMgr
import xls
from xls import XlsFile
from xlsConfigMgr import xlsConfigMgr

#文件管理类
class XlsFileMgr(object):
    "excel文件操作管理类"
    xfiles = []

        
    def __new__(cls, *args, **kw):  
        if not hasattr(cls, '_instance'):  
            orig = super(XlsFileMgr, cls)  
            cls._instance = orig.__new__(cls, *args, **kw)  
        return cls._instance 
    
    def readConfig(self):
        log.initLog()

        data = DataMgr()
        configDir = "%s/" %(env.CONFIG_PATH)
        print(configDir)

        xls_config = xlsConfigMgr()
        xls_config.read_config(configDir + 'config.yaml')
        xls_config.read_compile_config(configDir + 'compile.yaml')

        if env.isWindowsSystem():
            configDir = configDir.decode("utf-8").encode("gb2312")
        for root,dirs,files in os.walk(configDir):
            for i in files:
                if re.match(r'\b.*.xls$', i) or re.match(r'\b.*.xlsx$', i):
                    print('_' + i)
                    excelFile = '%s/%s' %(root, i)
                    xFile = XlsFile(excelFile)
                    if not xls_config.is_compile_xls(xFile.tabName):
                        continue
                    xFile.read()
                    data.addObj(xFile.tabName,xFile.primaryKey)
                    self.xfiles.append(xFile)
        
    def exportConfig(self):
        xls_config = xlsConfigMgr()

        for xFile in self.xfiles:
            if xls_config.get_compile_xls_count() == 0 or xls_config.is_compile_xls(xFile.tabName):
                if not xFile.check():
                    continue
            if not xls_config.is_compile_xls(xFile.tabName):
                continue
            #xFile.saveServer(env.SERVER_CONFIG_PATH)
            #xFile.saveServer(env.CLIENT_CONFIG_PATH)
            #xFile.saveClient(env.CLIENT_CONFIG_PATH)
            xFile.saveJson(env.SERVER_CONFIG_PATH)
            #xFile.saveLua(env.CLIENT_CONFIG_PATH)
            xFile.saveLuaOptimize(env.CLIENT_CONFIG_PATH)
            #xFile.saveCsFile(env.I18N_MESSAGE_PATH)






