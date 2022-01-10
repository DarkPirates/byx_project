#!/usr/bin/python3
#-*-UTF-8-*-

'''
这个文件是写管理员管理的...
'''
import pickle

import json

import time

from class_ import Book

from class_ import TeachingAidsBook

from class_ import ScienceBook

from class_ import PopularScienceBook

from class_ import NovelBook

from class_ import LifeBook

def test():
    fileUser = open('./书籍数据','rb+') 
    file_read = pickle.load(fileUser)   
    #TeachingAidsBook math_ = ctypes.cast(address, ctypes.file_read).value
    print(file_read)
test()