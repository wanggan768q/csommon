#!/usr/bin/env python
#coding=utf-8

import os
#import codecs

def initLog():
    logfile = "error.log"
    if os.path.exists(logfile):
        os.remove(logfile)

def Log(str):
    logfile = "error.log"
#    if type(str) == type(u'') or type(str) == type(''):
#        str = str.decode('gb2312')
#        print(str)
    log = open(logfile, "ab")
    log.write("%s\r\n"%str)

    log.close()

