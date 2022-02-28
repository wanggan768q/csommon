#!/usr/bin/env python
#coding=utf-8

import os
import xlwt




































class I18n(object):

    def __init__(self, file_name):
        self.file_name = file_name
        self.work_book = self.__open_i18n(file_name)


    def __open_i18n(self,file_name):
        book = None
        if not os.path.exists(file_name):
            book = xlwt.Workbook(encoding='utf-8')
            self.work_sheet = book.add_sheet('sheet')

    def write(self, dict):
        '''

        :param dict:
        :return:
        '''

        keys = dict.keys()
        col = 0

        for key in keys:
            self.work_sheet.write(0, col, key)
            col += 1

            for labels in dict[key]:
                row = 0
                for index in range(len(labels)) :
                    self.work_sheet.write(row, col, labels[index])
                    row += 1

        self.work_book.save(self.file_name)


a = I18n('i18n.xlsx')
dic = {
    'sn': [u"阿萨德12sadadas1",u"阿萨德12sadadas2"],
    'tw': [u"@@@@阿萨德12sadadas1",u"@@@@阿萨德12sadadas2"]
}
a.write(dic)