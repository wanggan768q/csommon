#!/usr/bin/env python
#coding=utf-8

import os
import struct
import log
import re
import xlrd
import env
import data
import time
import codecs
from data import DataMgr

# import sys

# reload(sys)
# sys.setdefaultencoding('utf8')


class XlsFile(object):
    "excel文件操作类"
    #带路径的文件名
    fname = ""
    #文件名
    fname1 = ""
    #outname
    tabName = ""
    frows = 0
    fcols = 0

    allKey = []
    primaryKey = []
    table = []
    content = []
    #['max','min','defa','set','chk','svr','des','len','i18n']
    checkItems = {}
    csvContent = []
    colType = {}

    #文本
    csText = []

    def __init__(self, fileName):
        self.fname = fileName

        #utf8编码格式的文件名
        self.fname1 = ""
        names = os.path.split(self.fname)
        if len(names) > 1:
            self.fname1 = names[1]
            #mac os默认utf-8编码，不需要转换
            if env.isMacSystem():
                pass
                #self.fname1 = self.fname1.encode("utf-8")
            else:
                if isinstance(self.fname1, str):
                    self.fname1 = self.fname1.decode("gb2312").encode("utf-8")
                elif isinstance(self.fname1, unicode):
                    self.fname1 = self.fname1.encode("utf-8")

        #导出的文件名,也是外键关联指定的外键名
        self.tabName = os.path.split(self.fname)[1]
        if len(self.tabName.split("_")) < 2:
            log.Log("%s 文件名格式错误" % self.fname1)
        self.tabName = self.tabName.split("_")[0]

        self.isLanguage = False
        if self.tabName.find("String") == 0:
            self.isLanguage = True

        self.primaryKey = []
        self.table = []
        self.content = []
        self.checkItems = {}
        self.csvContent = []
        self.frows = 0
        self.fcols = 0
        self.csText = []
        self.allKey = []

    def __new__(cls, *args, **kwargs):
        return super(XlsFile, cls).__new__(cls, *args, **kwargs)


    def read(self):
        book = xlrd.open_workbook(self.fname)
        self.table = book.sheet_by_index(0)
        #self.content = []
        self.frows = self.table.nrows
        self.fcols = self.table.ncols

        for r in range(self.frows):
            for c in range(self.fcols):
                str = self.table.cell(r,c).value
                if type(str)== type(u'') or type(str)== type(''):
                    #str = str.encode('utf-8')
                    str = str.encode('utf-8')
                if type(str) == type(1.0):
                    str = int(str)
                self.content.append(str)
                if self.skipRow(r):
                    continue
                self.csvContent.append(str)
                if c != (self.fcols - 1):
                    self.csvContent.append(",")
            if self.skipRow(r):
                continue
            self.csvContent.append("\r\n")
            #主键
            if r < 5:
                continue
            str = self.table.cell(r,0).value
            if type(str) != type(1.0):
                log.Log("%s 文件第%d行 1列有非整数类型的主键"%(self.fname1, r+1))
                continue
            str = int(str)
            self.primaryKey.append(str)

    def getIntItem(self,item,str,col):
        ret = re.findall(item, str)
        if ret != []:
            if len(ret) != 1:
                log.Log("%s 文件第2行 %d列有不符合规则的字符串:%s"%(self.fname1, col+1, item))
                return None
            ret = int(ret[0])
        else:
            ret = None
        return ret
        #print(ret)

    def getStrItem(self,item,str,col):
        ret = re.findall(item, str)
        if ret != []:
            if len(ret) != 1:
                log.Log("%s 文件第2行 %d列有不符合规则的字符串:%s"%(self.fname1, col+1, item))
                return None
            ret = ret[0]
        else:
            ret = None
        return ret

    def searchItem(self,item,str):
        ret = re.search(item, str)
        if ret:
            return True
        return False


    def check(self):
        if self.frows < 5:
            log.Log("%s 文件行数小于5"%self.fname1)
            return False
        if len(self.fname1.split("_")) < 2:
            log.Log("%s 文件名格式错误" % self.fname1)
            return False
        for c in range(self.fcols):
            #所有字段名
            str = self.table.cell(2,c).value
            if str in self.allKey:
                log.Log("%s 文件第%d列有重复的字段名"%(self.fname1, c+1))
                continue
            self.allKey.append(str)
        #获取规则
        for i in range(self.fcols):
            str = self.table.cell(1,i).value
            try:
                items = {}

                max = self.getIntItem(r'<max=(.*?)>', str, i)
                #print(max)

                min = self.getIntItem(r'<min=(.*?)>', str, i)
                #print(min)

                defa = self.getStrItem(r'<def=(.*?)>', str, i)
                #print(defa)

                leng = self.getIntItem(r'<len=(.*?)>', str, i)
                #print(leng)

                set = self.getStrItem(r'<set=(.*?)>', str, i)
                if set:
                    set = set.split(',')
                #print(set)

                chk = self.getStrItem(r'<chk=(.*?)>', str, i)
                if chk:
                    chk = chk.split(',')
                #print(chk)

                svr = self.searchItem(r'<svr>', str)
                #print(svr)

                des = self.searchItem(r'<des>', str)
                #print(des)

                i18n = self.searchItem(r'<i18n>', str)
                #print(i18n)

                items['max'] = max
                items['min'] = min
                items['def'] = defa
                items['set'] = set
                items['chk'] = chk
                items['svr'] = svr
                items['des'] = des
                items['len'] = leng
                items['i18n'] = i18n

                self.checkItems[i]=items
                #print(self.checkItems[i])
            except:
                log.Log("%s 文件第2行 %d列有不符合规则的字符串"%(self.fname1, i+1))
                print("##except")
        #获取数据类型
        for i in range(self.fcols):
            str = self.table.cell(0,i).value
            #print(str)
            if str == 'INT':
                self.colType[i] = 'INT'
            elif str == 'FLOAT':
                self.colType[i] = 'FLOAT'
            elif str == 'STRING':
                self.colType[i] = 'STRING'
            elif str == 'LS':
                self.colType[i] = 'LS'
                #print 'LS'
            elif str == 'LI':
                self.colType[i] = 'LI'
                #print 'LI'
            elif str == 'LF':
                self.colType[i] = 'LF'
                #print 'LF'
            else:
                self.colType[i] = None
                log.Log("%s 文件第%d行 %d列有不符合规则的数据类型" % (self.fname1, 1,i+1))
        #检查规则, 第五行开始
        for i in range(5,self.frows):
            for j in range(self.fcols):
                if not self.checkTableItem(i,j):
                    log.Log("%s 文件第%d行 %d列有不符合规则的数值" % (self.fname1, i+1,j+1))
        return True

    #规则检查
    def checkTableItem(self, row, col):
        return self.checkValue(row,col)

    def checkValue(self, row, col):
        if self.skipRow(row):
            return True
        val = self.table.cell(row,col).value

        #print type(val)
        self.checkChkItem(val,row,col)
        if (type(val)== type(u'') or type(val)== type('')) and self.colType[col] == 'STRING':
            return self.checkStrValue(val, col)
        elif self.colType[col] == 'INT':
            if type(val) == type(1.0):
                val = int(val)
            elif val == '':
                val = '-1'
            return self.checkIntValue(val, col)
        elif self.colType[col] == 'FLOAT':
            if val == '':
                val = '-1'
            elif type(val) != type(1.0) :
                log.Log("%s 文件第%d行 %d列数值和类型不匹配 %s" % (self.fname1, row+1,col+1,self.colType[col]))
                return False
            return True
        elif type(val) == type(1.0) and self.colType[col] == 'STRING':
        		return self.checkStrValue(val, col)
        elif self.colType[col] == 'LI':

            return True
        elif self.colType[col] == 'LS' or self.colType[col] == 'LF':
            return True
        else:
            log.Log("%s 文件第%d行 %d列数值和类型不匹配 %s" % (self.fname1, row+1,col+1,self.colType[col]))
        return True

    #检查外键
    def checkChkItem(self, val, row, col):
        if self.colType[col] == 'LI':
            val = str(val)
            if isinstance(val, unicode):
                val = val.encode('utf-8')
            valArray = val.split('|')
            valArraySize = len(valArray)
            for i in range(0, valArraySize):
                if valArray[i] == '':
                    continue
                try:
                    if self.checkChkItemVal(float(valArray[i]), row, col) == False:
                        return False
                except Exception as e:
                    log.Log("%s 文件第%d行 %d列使用 数据类型错误" % (self.fname1, row, col))
                    print("%s 文件第%d行 %d列使用 数据类型错误" % (self.fname1,row, col))
            return True
        return self.checkChkItemVal(val,row,col)

    def checkChkItemVal(self,val, row, col):
        data = DataMgr()
        data = DataMgr()
        chk = self.checkItems[col]['chk']
        if chk == None:
            return True
        findKey = False
        findVal = False
        if str(val) == '':
            return True
        if type(val) != type(1.0):
            log.Log("%s 文件第%d行 %d列使用外键关联，外键值类型错误%s --- %s " % (self.fname1, row + 1, col + 1, type(val), val.__str__()))
            return False
        # 默认-1除外
        if int(val) == -1:
            return True
        for key in chk:
            if data.priKeys.has_key(key):
                findKey = True
                if val in data.priKeys[key]:
                    findVal = True
        if not findKey:
            log.Log("%s 文件第%d行 %d列使用外键关联，关联名错误" % (self.fname1, row + 1, col + 1))
            return False

        if not findVal:
            log.Log("%s 文件第%d行 %d列使用外键关联，外键值错误" % (self.fname1, row + 1, col + 1))
            return False
        return True


    def checkStrValue(self, val, col):
        if self.checkItems[col]['max'] != None or self.checkItems[col]['min'] != None:
            return False
        leng = self.checkItems[col]['len']
        if leng != None:
            #一个汉字占两个字节，计算utf-8的字节长度
            length = len(val)
            utf8_length = len(val.encode('utf-8'))
            length = (utf8_length - length)/2 + length
            #print(length)
            if length > leng:
                return False
        return True

    def checkIntValue(self, val, col):
        max = self.checkItems[col]['max']
        min = self.checkItems[col]['min']
        defa = self.checkItems[col]['def']
        set = self.checkItems[col]['set']
        #print(defa)
        #print(val)

        if set != None:
            for i in set:
                if val == int(i):
                    return True
            return False
        if defa != None:
            if val == defa:
                return True
        if max != None:
            if val > max:
                return False
        if min != None:
            if val < min:
                return False
        return True

    def saveServer(self, path):
        name = os.path.split(self.fname)[1]
        if len(name.split("_")) < 2:
            log.Log("%s 文件名格式错误" % self.fname1)
            return
        csv = "%s/%s.csv"%(path, name.split("_")[0])
        if not os.path.exists(os.path.dirname(csv)):
            os.makedirs(os.path.dirname(csv))
        outfile = open(csv,"wb")

        for r in range(self.frows):
            if self.skipRow(r):
                continue
            for c in range(self.fcols):
                if self.skipServer(c):
                    continue
                val = self.getCellData(r,c)
                outfile.write(val)

                if c != self.fcols - 1:
                    if self.skipServer(self.fcols - 1) and c == self.fcols - 2:
                        continue
                    outfile.write(',')
            outfile.write('\r\n')
            #outfile.write(struct.pack('i',i))
        outfile.close()

    def getCellData(self,r,c):
        val = self.table.cell(r,c).value
        if self.colType[c] == 'LS':
            val = str(val)
            if isinstance(val, unicode):
                val = val.encode('utf-8')
            val = val.replace('\r','\\r').replace('\n','\\n')
            val = val.replace('"','\\"');

            valArray = val.split('|')
            valArraySize = len(valArray)
            strArray = "["
            for i in range(0,valArraySize):
                if valArray[i] == '':
                    continue
                strArray += "\"" + valArray[i] + "\""
                if i < valArraySize - 1:
                    strArray += ","
            strArray += "]"
            #print strArray
            val = '%s'%strArray

        elif self.colType[c] == 'LI':
            val = str(val)
            if isinstance(val, unicode):
                val = val.encode('utf-8')
            valArray = val.split('|')
            valArraySize = len(valArray)
            strArray = "["
            for i in range(0,valArraySize):
                if valArray[i] == '':
                    continue
                try:
                    valArray[i] = "%d" % int(round(float(valArray[i])))
                except Exception as e:
                    log.Log("%s 文件第%d行 %d列使用 数据类型错误" % (self.fname1, r+1,c+1))
                    print("%s 文件第%d行 %d列使用 数据类型错误" % (self.fname1, r+1,c+1))
                valArray[i] = "%d" % int(round(float(valArray[i])))
                if valArray[i].find('.') != -1:
                     log.Log("%s 文件第%d行 %d列使用 数据类型错误" % (self.fname1, r+1,c+1))
                #self.checkChkItem(float(valArray[i]),r,c)
                strArray += valArray[i]
                if i < valArraySize - 1:
                    strArray += ","
            strArray += "]"
            #print strArray
            val = '%s'%strArray
        elif self.colType[c] == 'LF':
            val = str(val)
            if isinstance(val, unicode):
                val = val.encode('utf-8')
            valArray = val.split('|')
            valArraySize = len(valArray)
            strArray = "["
            for i in range(0,valArraySize):
                #print valArray[i]

                strArray += valArray[i]
                if i < valArraySize - 1:
                    strArray += ","
            strArray += "]"
            #print strArray
            val = '%s'%strArray

        elif self.colType[c] == 'STRING':
            unicodeVar = val
            if type(val) == type(u'') or type(val) == type('')  :
                if isinstance(val, unicode):
                    val = val.encode('utf-8')
            val = str(val)
            val = val.replace('\r','\\r').replace('\n','\\n')
            val = val.replace('"','\\"')
            # val = ('"%s"' + "") % val
            if val.endswith(".0"):
                val = val.replace(".0","")
            val = '\"' + val + '\"'
            #val = '[=[%s]=]'%val
        elif self.colType[c] == 'FLOAT':
            if val == '':
                val = '-1'
            val = float(val)
            val = ("%.2f"%val)
        else :
            if val == '':
                val = '-1'
            val = int(val)
            val = ("%d"%val)
        return val


    def getCellDataLua(self,r,c):
        val = self.table.cell(r,c).value
        if self.colType[c] == 'LS':
            val = str(val)
            if isinstance(val, unicode):
                val = val.encode('utf-8')
            val = val.replace('\r','\\r').replace('\n','\\n')

            valArray = val.split('|')
            valArraySize = len(valArray)
            strArray = "{"
            for i in range(0,valArraySize):
                if valArray[i] == '':
                    continue
                strArray += "\"" + valArray[i] + "\""
                if i < valArraySize - 1:
                    strArray += ","
            strArray += "}"
            #print strArray
            val = '%s'%strArray

        elif self.colType[c] == 'LI':
            val = str(val)
            if isinstance(val, unicode):
                val = val.encode('utf-8')
            valArray = val.split('|')
            valArraySize = len(valArray)
            strArray = "{"
            for i in range(0,valArraySize):
                if valArray[i] == '':
                    continue
                valArray[i] = "%d" % int(round(float(valArray[i])))
                if valArray[i].find('.') != -1:
                     log.Log("%s 文件第%d行 %d列使用 数据类型错误" % (self.fname1, r+1,c+1))
                strArray += valArray[i]
                if i < valArraySize - 1:
                    strArray += ","
                    #self.checkChkItem(valArray[i],r,c)
            strArray += "}"
            #print strArray
            val = '%s'%strArray
        elif self.colType[c] == 'LF':
            val = str(val)
            valArray = val.split('|')
            valArraySize = len(valArray)
            strArray = "{"
            for i in range(0,valArraySize):
                #print valArray[i]
                strArray += valArray[i]
                if i < valArraySize - 1:
                    strArray += ","
            strArray += "}"
            #print strArray
            val = '%s'%strArray
            pass

        elif self.colType[c] == 'STRING':
            if type(val) == type(u'') or type(val) == type('')  :
                if isinstance(val, unicode):
                    val = val.encode('utf-8')
            val = str(val)
            val = val.replace('\r','\\r').replace('\n','\\n')
            val = val.replace('"','\\"');
            #val = '"%s"'%val
            if val.endswith(".0"):
                val = val.replace(".0","")
            val = '\"' + val + '\"'
        elif self.colType[c] == 'FLOAT':
            if val == '':
                val = '-1'
            val = float(val)
            val = ("%.2f"%val)
        else :
            if val == '':
                val = '-1'
            val = int(val)
            val = ("%d"%val)
        return val

    def saveClient(self, path):
        name = os.path.split(self.fname)[1]
        if len(name.split("_")) < 2:
            log.Log("%s 文件名格式错误" % self.fname1)
        csv = "%s/%s.lua"%(path,name.split("_")[0])
        print csv
        if not os.path.exists(os.path.dirname(csv)):
            os.makedirs(os.path.dirname(csv))
        outfile = open(csv,"wb")
        outfile.write(codecs.BOM_UTF8)

        outfile.write( "--File Create Time:" + time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())) + "\r\n--[[\r\n" )

        for c in range(self.fcols):
            Name = self.table.cell(2,c).value
            CName = self.table.cell(3,c).value
            CDesc = self.table.cell(4,c).value
            if isinstance(CName, unicode):
                CName = CName.encode('utf-8')
            if isinstance(CDesc, unicode):
                CDesc = CDesc.encode('utf-8')
            if isinstance(Name, unicode):
                Name = Name.encode('utf-8')
            outfile.write( Name+':'+CName+' '+CDesc.replace('\r',' ').replace('\n',' ')+'\r\n')
        outfile.write("--]]\r\n")
        outfile.write( 'local %s={\r\n'%self.tabName)


        for r in range(self.frows):
            if r < 5:
                continue
            if self.skipRow(r):
                continue
            val = self.getCellData( r, 0 )
            fileLine = "[%s]={"%val
            for c in range(self.fcols):
                Name = self.table.cell(2,c).value
                if isinstance(Name, unicode):
                    Name = Name.encode('utf-8')
                val = self.getCellData( r, c )
                line ="%s=%s"%(Name,val)

                if c < self.fcols-1:
                    line += ","
                fileLine += line
            fileLine += '}'
            if r<self.frows-1:
                fileLine += ','
            fileLine += "\r\n"
            outfile.write(fileLine)

        outfile.write( '}\r\nreturn %s\r\n'%self.tabName)
        outfile.close()

    def saveLua(self, path):
        name = os.path.split(self.fname)[1]
        if len(name.split("_")) < 2:
            log.Log("%s 文件名格式错误" % self.fname1)
        tableNmae = name.split("_")[0]
        lua = "%s/%s.lua"%(path,name.split("_")[0])
        print lua
        if not os.path.exists(os.path.dirname(lua)):
            os.makedirs(os.path.dirname(lua))
        outfile = open(lua,"wb")
        #outfile.write(codecs.BOM_UTF8)

        if self.isLanguage == True:
            #outfile.write("require('Common/ConstDefine')\r\n")
            outfile.write("local ConstDefine = ConstDefine\r\n")
        outfile.write("local log = Log.Create('%s')\r\n" % (tableNmae))
        outfile.write("module(...)\r\n")
        outfile.write("%s={}\r\n"%(tableNmae))

        outfile.write( "\r\n" )
        outfile.write( "\r\n" )

        outfile.write( "function Get(id)\r\n" )
        outfile.write( "\tlocal data = %s[id]\r\n"%(tableNmae) )
        outfile.write( "\tif data ~= nil then\r\n" )
        if self.isLanguage == True:
            outfile.write( "\t\treturn data[ConstDefine.C_LANGUAGE]\r\n" )
        else:
            outfile.write( "\t\treturn data\r\n" )
        outfile.write( "\telse\r\n" )
        #outfile.write( "\t\tprint( '不存在ID => ' .. id)\r\n" )
        outfile.write( "\t\tlog:Error( '不存在ID => ' , id)\r\n" )
        outfile.write( "\tend\r\n" )
        outfile.write( "end\r\n" )

        outfile.write( "\r\n" )
        outfile.write( "\r\n" )

        for r in range(self.frows):
            if r < 5:
                continue
            if self.skipRow(r):
                continue
            val = self.getCellData( r, 0 )

            key = val

            fileLine = "{"

            for c in range(self.fcols):
            	if self.skipClient(c):
            		continue
                Name = self.table.cell(2,c).value
                if isinstance(Name, unicode):
                    Name = Name.encode('utf-8')
                val = self.getCellDataLua( r, c )
                #line ='"%s"=%s'%(Name,val)
                line ='%s=%s'%(Name,val)
                if c < self.fcols-1:
                    line += ","
                if isinstance(line, unicode):
                    line = line.encode('utf-8')
                fileLine += line

            fileLine += '}'
            fileLine += "\r\n"
            outfile.write("%s[%s] = %s" % (tableNmae,key,fileLine))
            #outfile.write(fileLine)
        outfile.close()

    def saveLuaOptimize(self, path):
        name = os.path.split(self.fname)[1]
        if len(name.split("_")) < 2:
            log.Log("%s 文件名格式错误" % self.fname1)
        tableNmae = name.split("_")[0]
        lua = "%s/%s.lua"%(path,name.split("_")[0])
        print lua
        if not os.path.exists(os.path.dirname(lua)):
            os.makedirs(os.path.dirname(lua))
        outfile = open(lua,"wb")
        #outfile.write(codecs.BOM_UTF8)

        if self.isLanguage == True:
            #outfile.write("require('Common/ConstDefine')\r\n")
            outfile.write("local ConstDefine = ConstDefine\r\n")
        #outfile.write("local print = print\r\n")
        outfile.write("local log = Log.Create('%s')\r\n" % (tableNmae))
        outfile.write("local setmetatable = setmetatable\r\n")
        outfile.write("module(...)\r\n")
        outfile.write("%s = {}\r\n"%(tableNmae))
        outfile.write("local __KEYS__ = {}\r\n")
        outfile.write("local __IDS__ = {}\r\n")

        outfile.write( "\r\n" )
        outfile.write( "\r\n" )

        outfile.write( "local base = {\r\n" )
        outfile.write( "\t__index = function ( t,k )\r\n" )
        outfile.write( "\t\tif k == '__base' then\r\n" )
        outfile.write( "\t\t\treturn __base\r\n" )
        outfile.write( "\t\tend\r\n" )
        outfile.write( "\t\tlocal key = __KEYS__[k]\r\n" )
        outfile.write( "\t\tif key == nil then\r\n" )
        outfile.write( "\t\t\tlog:Error('配置表没有此 Key => ' .. k)\r\n" )
        outfile.write( "\t\t\treturn nil\r\n" )
        outfile.write( "\t\tend\r\n" )
        outfile.write( "\t\treturn t[key]\r\n" )
        outfile.write( "\tend,\r\n" )
        outfile.write( "\t__newindex = function ( t,k )\r\n" )
        outfile.write( "\t\tlog:Error('配置表数据禁止修改')\r\n" )
        outfile.write( "\tend,\r\n" )
        #outfile.write( "\t__metatable = false,\r\n" )
        outfile.write( "\t__base = true,\r\n" )
        outfile.write( "}\r\n\r\n" )

        outfile.write( "function Get(id)\r\n" )
        outfile.write( "\tif id == -1 or id == nil then\r\n" )
        outfile.write( "\t\treturn nil\r\n" )
        outfile.write( "\tend\r\n" )
        outfile.write( "\tlocal data = %s[id]\r\n" % (tableNmae) )
        outfile.write( "\tif data ~= nil then\r\n" )
        outfile.write( "\t\tif not data.__base then\r\n" )
        #outfile.write( "\t\t\tdata.__base = true,\r\n" )
        outfile.write( "\t\t\tsetmetatable( data, base )\r\n" )
        outfile.write( "\t\tend\r\n" )
        if self.isLanguage == True:
            outfile.write( "\t\treturn data[ConstDefine.C_LANGUAGE]\r\n" )
        else:
            outfile.write( "\t\treturn data\r\n" )
        outfile.write( "\telse\r\n" )
        #outfile.write( "\t\tprint( '不存在ID => ' .. id)\r\n" )
        outfile.write( "\t\tlog:Error( '不存在ID => ' , id)\r\n" )
        outfile.write( "\tend\r\n" )
        outfile.write( "end\r\n" )
        outfile.write( "\r\n" )

        outfile.write( "function All()\r\n" )
        outfile.write( "\tif not __All then\r\n")
        outfile.write( "\t\t__All = {}\r\n")
        outfile.write( "\t\tfor i = 1, #__IDS__ do\r\n")
        outfile.write( "\t\t\tlocal id = __IDS__[i]\r\n" )
        outfile.write( "\t\t\t__All[id] = Get(id)\r\n" )
        outfile.write( "\t\tend\r\n" )
        outfile.write( "\tend\r\n" )
        outfile.write( "\treturn __All\r\n" )
        outfile.write( "end\r\n" )
        outfile.write( "\r\n" )

        outfile.write( "function Size()\r\n" )
        outfile.write( "\treturn #__IDS__\r\n" )
        outfile.write( "end\r\n" )


        outfile.write( "\r\n" )
        outfile.write( "\r\n" )

        Names = []
        Ids = []
        IsAddName = True

        for r in range(self.frows):
            if r < 5:
                continue
            if self.skipRow(r):
                continue
            val = self.getCellData( r, 0 )

            key = val
            Ids.append(key)


            fileLine = "{"

            for c in range(self.fcols):
                if self.skipClient(c):
                    continue
                Name = self.table.cell(2,c).value
                if isinstance(Name, unicode):
                    Name = Name.encode('utf-8')
                val = self.getCellDataLua( r, c )
                if IsAddName == True:
                    Names.append(Name)
                line = '%s' % (val)
                if c < self.fcols-1:
                    line += ","
                if isinstance(line, unicode):
                    line = line.encode('utf-8')
                fileLine += line

            IsAddName = False
            fileLine += '}'
            fileLine += "\r\n"
            outfile.write("%s[%s] = %s" % (tableNmae,key,fileLine))
            #outfile.write(fileLine)

        keyLine = '{'
        for k,v in enumerate(Names):
            keyLine += '%s=%d,' % (v, k + 1)
        keyLine += '}\r\n'
        outfile.write("__KEYS__ = %s" % (keyLine))

        idLine = '{'
        for k,v in enumerate(Ids):
            idLine += '%s,' % (v)
        idLine += '}'
        outfile.write("__IDS__ = %s" % (idLine))

        outfile.close()


    def saveJson(self, path):
        name = os.path.split(self.fname)[1]
        if len(name.split("_")) < 2:
            log.Log("%s 文件名格式错误" % self.fname1)
        csv = "%s/%s.json"%(path,name.split("_")[0])
        print csv
        if not os.path.exists(os.path.dirname(csv)):
            os.makedirs(os.path.dirname(csv))
        outfile = open(csv,"wb")
        #outfile.write(codecs.BOM_UTF8)

        outfile.write( "[\r\n" )


        for r in range(self.frows):
            if r < 5:
                continue
            if self.skipRow(r):
                continue
            val = self.getCellData( r, 0 )
            fileLine = "{"
            for c in range(self.fcols):
            	if self.skipServer(c):
            		continue
                Name = self.table.cell(2,c).value
                if isinstance(Name, unicode):
                    Name = Name.encode('utf-8')
                val = self.getCellData( r, c )
                line ='"%s":%s'%(Name,val)
                if c < self.fcols-1:
                    line += ","
                fileLine += line
            fileLine += '}'
            if r<self.frows-1:
                fileLine += ','
            fileLine += "\r\n"
            outfile.write(fileLine)

        outfile.write( ']\r\n')
        outfile.close()

        #saveLua(self,path)

    def saveCsFile(self, path):
        name = os.path.split(self.fname)[1]
        if len(name.split("_")) < 2:
            log.Log("%s 文件名格式错误" % self.fname1)
        csFile = "%s/%s.cs"%(path,name.split("_")[0])
        contextName = name.split("_")[1].split(".")[0]
        if not os.path.exists(os.path.dirname(csFile)):
            os.makedirs(os.path.dirname(csFile))
        outfile = open(csFile,"wb")

        for r in range(self.frows):
            if self.skipRow(r):
                continue
            for c in range(self.fcols):
                if self.skipCsv(c):
                    continue
                val = self.table.cell(r,c).value
                if type(val) == type(u'') or type(val) == type(''):
                    if isinstance(val, unicode):
                        val = val.encode('utf-8')
                    #包含回车换行的用引号括起来
                    #if val.find("\n") != -1:
                    #字符串用引号括起来
                    val = '"%s"' % val
                    val = 'GetParticularString("%s", "%s")\r\n'%(val,contextName)
                    outfile.write(val)
        outfile.close()

    #注释行
    def skipRow(self,row):
        if row == 0 or row == 1 or row == 3 or row == 4:
            return True
        val = self.table.cell(row,0).value
        if type(val) == type(u'') or type(val) == type(''):
            if isinstance(val, unicode):
                val = val.encode('utf-8')
                if self.searchItem(r'^\s{2,}#',val) or self.searchItem(r'^#',val):
                    return True
        return False

    def skipClient(self, col):
        if self.checkItems[col]['svr']:
            return True
        if self.checkItems[col]['des']:
            return True
        return False

    def skipServer(self, col):
        if self.checkItems[col]['des']:
            return True
        return False

    def skipCsv(self, col):
        if not self.checkItems[col]['i18n']:
            return True
        return False



