#!/usr/bin/env python
#coding=utf-8

import os
import re
from utils import xls
from utils import env
from utils import xlsMgr
from utils.xlsMgr import XlsFileMgr
from utils.xls import XlsFile
from utils import log

def exportConfig():
    xlsMgr = XlsFileMgr()
    xlsMgr.readConfig()
    xlsMgr.exportConfig()
