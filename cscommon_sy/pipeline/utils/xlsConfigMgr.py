#!/usr/bin/env python
#coding=utf-8

import yaml
import os

class xlsConfigMgr(object):
    xls_page = {}
    compile_dic = {}

    def __new__(cls, *args, **kw):
        if not hasattr(cls, '_instance'):
            orig = super(xlsConfigMgr, cls)
            cls._instance = orig.__new__(cls, *args, **kw)
        return cls._instance

    def read_config(self, yaml_config_filename):
        try:
            file = open(yaml_config_filename)
            file_data = file.read()
            file.close()

            self.xls_page = yaml.load(file_data)
            if self.xls_page is None:
                self.xls_page = {}
        except Exception as e:
            print e.message

    def read_compile_config(self, yaml_compile_config):
        try:
            file = open(yaml_compile_config)
            file_data = file.read()
            file.close()

            self.compile_dic = yaml.load(file_data)
            if self.compile_dic is None:
                self.compile_dic = {}
        except Exception as e:
            print e.message

    def get_lua_page_count(self, xls_filename):
        return self.xls_page.has_key(xls_filename)

    def is_compile_xls(self, xls_filename):
        return self.get_compile_xls_count() == 0 or self.compile_dic.has_key(xls_filename)

    def get_compile_xls_count(self):
        return len(self.compile_dic)



#a = xlsConfigMgr()

#a.read_config(r'F:\Work\Project\ice_cehua\trunk\Config\config.yaml')
#a.read_compile_config(r'F:\Work\Project\ice_cehua\trunk\Config\compile.yaml')

#print(a.get_compile_xls_count())