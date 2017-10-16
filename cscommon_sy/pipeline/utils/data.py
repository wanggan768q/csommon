#!/usr/bin/python
#coding=utf-8
import log
#单例，保存各个配置表的主键，做外键关联检测
class DataMgr(object):
    priKeys = {}

    def __new__(cls, *args, **kw):  
        if not hasattr(cls, '_instance'):  
            orig = super(DataMgr, cls)  
            cls._instance = orig.__new__(cls, *args, **kw)  
        return cls._instance 
    
    def addObj(self,name,priKey):
        #print priKey
        self.checkPrikey(name, priKey)
        self.priKeys[name] = priKey

    #检查主键是否重复
    def checkPrikey(self, name, priKey):
        all = []
        for x in priKey:
            if x in all:
                log.Log("%s 主键重复:%d" %(name, x))
                continue
            all.append(x)
