#!/usr/bin/env python
#coding=utf-8

import os
import re
import sys
import platform
from utils import env

#检查模块是否已经安装
def checkModule(mod):
    try:
        __import__(mod)
    except:
        pass    
    #print(sys.modules)
    rr = r"%s"%mod
    for i in sys.modules:
        if re.search(rr, i):
            return True
    return False

#安装所有模块
def installModule():
    installXlrd()
    installParamiko()
    installScpclient()
    installMenu()
    installPexpect()
    installChardet()

    
def installXlrd():
    if checkModule("xlrd"):
        print("xlrd has installed.")
        return

    startInstall("xlrd")

    path = "%s/tools/xlrd-0.9.3" %(env.BUILD_PATH)
    os.chdir(path)

    if env.isWindowsSystem():
        cmd = "python setup.py install"
    else:
        cmd = "sudo python setup.py install"
    os.system(cmd)

    endInstall("xlrd")


def installChardet():
    if checkModule("chardet"):
        print("chardet has installed.")
        return

    startInstall("chardet")

    path = "%s/tools/chardet-2.3.0" %(env.BUILD_PATH)
    os.chdir(path)

    if env.isWindowsSystem():
        cmd = "python setup.py install"
    else:
        cmd = "sudo python setup.py install"
    os.system(cmd)

    endInstall("chardet")

def installParamiko():
    if checkModule("paramiko"):
        print("paramiko has installed.")
        return

    startInstall("paramiko")

    path = "%s/tools/paramiko-1.15.2" %(env.BUILD_PATH)
    os.chdir(path)

    if env.isWindowsSystem():
        cmd = "python setup.py install"
    else:
        cmd = "sudo python setup.py install"
    os.system(cmd)

    endInstall("paramiko")

def installScpclient():
    if checkModule("scpclient"):
        print("scpclient has installed.")
        return

    startInstall("scpclient")

    path = "%s/tools/scpclient-0.5" %(env.BUILD_PATH)
    os.chdir(path)

    if env.isWindowsSystem():
        cmd = "python setup.py install"
    else:
        cmd = "sudo python setup.py install"
    os.system(cmd)

    endInstall("scpclient")

def installMenu():
    if checkModule("Menu"):
        print("Menu has installed.")
        return

    startInstall("Menu")

    path = "%s/tools/Menu-1.4" %(env.BUILD_PATH)
    os.chdir(path)

    if env.isWindowsSystem():
        cmd = "python setup.py install"
    else:
        cmd = "sudo python setup.py install"
    os.system(cmd)

    endInstall("Menu")
	
def installPexpect():
    if checkModule("Pexpect"):
        print("Pexpect has installed.")
        return
    startInstall("Pexpect")
    path = "%s/tools/pexpect-2.3" % (env.BUILD_PATH)	
    os.chdir(path)
    
    if env.isWindowsSystem():
        cmd = "python setup.py install"
    else:
        cmd = "sudo python setup.py install"
    os.system(cmd)

    endInstall("Pexpect")
	
def startInstall(mod):
    print("install %s begin" %mod)
    
def endInstall(mod):
    print("install %s success" %mod)
