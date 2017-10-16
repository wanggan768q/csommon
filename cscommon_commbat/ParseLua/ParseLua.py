#!/usr/bin/python
import json
import sys
import os
import re
import platform
import codecs

outputLines = []

def isWindowsSystem():
    return 'Windows' in platform.system()

def isLinuxSystem():
    return 'Linux' in platform.system()

def isMacSystem():
    return 'Darwin' in platform.system()

functionList = []    
def srchFunc(luaContent,reg):
    global functionList
    pa = re.compile(reg)
    matchs = pa.findall(luaContent)
    for it in matchs:
        it = it.strip(" ()")
        functionList.append(it)
    
def parseLuaFile(fn, luaFileName ):
    global functionList
    fn = fn.split(".")[0]
    if fn.find("Layer")>0:
        return
    functionList = []
    luaFile = file(luaFileName)
    luaContent = luaFile.read()
    luaFile.close
    srchFunc( luaContent, '(?m)^function ([\w]*)\(' )
    srchFunc( luaContent, '(?m)^function .*:([\w]*)\(' )
    srchFunc( luaContent, '(?m)^function .*\.([\w]*)\(' )
    print fn,"functions:"
    for f in functionList:
        print " ",f

    pa = re.compile('(?m)self\.([\w_]*)')
    matchs = pa.findall(luaContent)
    matchs.sort()

    print fn,"attributes:"
    lastItem = ""
    for it in matchs:
        if it != lastItem and  (it not in functionList) :
            print " ",it
        lastItem = it
    print ""

if len(sys.argv) < 2 :
    print  "Syntax error, EG. %s ./"%(sys.argv[0]) 
    exit()

configDir = sys.argv[1]
if isWindowsSystem():
    configDir = configDir.decode("utf-8").encode("gb2312")
for root,dirs,files in os.walk(configDir):
    for i in files:
        if re.match(r'\b.*.lua$', i):
            luaFilename = '%s/%s' %(root, i)
            parseLuaFile(i, luaFilename )



print "OK"
