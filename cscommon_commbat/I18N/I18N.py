#!/usr/bin/python
import json
import sys
import os
import re
import platform
import codecs
import chardet


outputLines = []

def isWindowsSystem():
    return 'Windows' in platform.system()

def isLinuxSystem():
    return 'Linux' in platform.system()

def isMacSystem():
    return 'Darwin' in platform.system()

def getAttr( attrs, attrName ):
    for a in attrs:
        if cmp( a[0:len(attrName)], attrName ) == 0:
            return a.split('"')[1]
    return None

def toParseSubCsd( eleName, fileName ):
    global pathDir

    fName = pathDir + os.path.split(fileName)[1]
    if (fName.split(".")[-1]).lower() != "csd":
        return
    toParseCsdXML( fName )

    

def toParseCsdXML( xmlFname ):
    xmlContent = file(xmlFname)
    while 1:
        li = xmlContent.readline()
        if not li:
            break
        line = li.strip(" \r\n")
        if cmp(line[0:18],"<AbstractNodeData " ) == 0:
            attrs = line.split(' ')
            itemType = getAttr(attrs,'ctype')
            textValue = getAttr(attrs,"LabelText")
            if textValue == None:
                textValue = getAttr(attrs,"ButtonText")
            if textValue == None:
                textValue = getAttr(attrs,"PlaceHolderText")
            if textValue != None:
                if isinstance(textValue, unicode):
                    textValue = textValue.encode("utf-8")
                outputLines.append(textValue)
            if itemType == "ProjectNodeObjectData" :
                while 1:
                    li = xmlContent.readline()
                    if not li:
                        break
                    line = li.strip(" \r\n")
                    if cmp(line[0:10],"<FileData " ) == 0:
                        attrs = line.split(' ')
                        Path = getAttr(attrs,"Path")
                        if Path != None:
                            toParseSubCsd( itemName, Path )
                        break
                    if cmp(line[0:19],"</AbstractNodeData>" ) == 0:
                        break
    xmlContent.close
    

def checkIsString( str ):
    sQ = -1
    dQ = -1    
    if str[0] == '"':
        dQ = 0
    elif str[0] == "'":
        sQ = 0
    if sQ<0 and dQ<0:
        return 0

    remains = 0
    skip = 0
    for ch in str :
        if sQ>=2 or dQ>=2:
            remains = remains+1
        if skip == 1 :
            skip = 0
            continue
        if ch == '"' and dQ>=0:
            dQ = dQ+1
        elif ch == "'" and sQ>=0:
            sQ = sQ + 1
        elif ch == '\\':
            skip = 1
    if remains==0 and ( sQ==2 or dQ==2 ):
        return 1
    return 0

    
def parseScriptFile( scriptFileName ):
    scriptFile = file(scriptFileName)
    scriptContent = luaFile.read()
    scriptFile.close
    pa = re.compile('(?m)I18N\((.*)\)')
    matchs = pa.findall(scriptContent)
    for it in matchs:
        it = it.strip("()")
        if it[0] == '"' or it[0] =="'":
            if checkIsString(it)==0:
                print "I18N(%s) function only contain string, in file[%s]"%(it,scriptFileName)
                exit()
            it = it.strip("'\"")
            if isinstance(it, unicode):
                it = it.encode("utf-8")
            outputLines.append(it)

if len(sys.argv) < 2 :
    print  "Syntax error, EG. %s ./"%(sys.argv[0]) 
    exit()

configDir = sys.argv[1]
if isWindowsSystem():
    configDir = configDir.decode("utf-8").encode("gb2312")
for root,dirs,files in os.walk(configDir):
    for i in files:
        if re.match(r'\b.*.lua$', i) or re.match(r'\b.*.coffee$',i):
            scriptFilename = '%s/%s' %(root, i)
            parseScriptFile( scriptFilename )
            #print scriptFilename
        if re.match(r'\b.*.csd$', i):
            xmlFilename = '%s/%s' %(root, i)
            toParseCsdXML( xmlFilename )
            print xmlFilename


outputLines.sort()
lastItem = ""
outputItems = []
for it in outputLines:
    print it
    if it != lastItem:
        outputItems.append(it)
    lastItem = it


f = file("lang.csv", "w")
f.write(codecs.BOM_UTF8)

for it in outputItems:
    f.write(it)
    f.write("\n")
f.close()


print "OK"
