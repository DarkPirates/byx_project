#!/usr/bin/python3
#-*-UTF-8-*-

'''
这个文件是写管理员管理的...
'''
import pickle

import json

import time

import yaml

from class_ import Book

from class_ import TeachingAidsBook

from class_ import ScienceBook

from class_ import PopularScienceBook

from class_ import NovelBook

from class_ import LifeBook

INPUTERROR = -1
LOOP = 0
TIME_INIT = 0
NONE = 0
TEACH = 1
SCIENCE = 2
POPULAR = 3
NOVEL = 4
LIFE = 5

def takeOutBOOK():
    fileUser = open('./书籍数据','rb+')                                       #这一行打开这个文件,并给予读权限
    file_read = pickle.load(fileUser)                                       #file_read是表示读取出来的数据,此时是列表 
    #json_read_dictionaries = pickle.load(file_read)                        #这一行是读取出来的json类型转换     
    fileUser.close()                                                        #用了要关上,没啥好说的
    return file_read

#对书籍信息进行输入
def inputBookInformation(user_input):
    print(user_input)
    new_book = NONE
    private_parameter = input()
    book_name = input()
    leave_time = TIME_INIT
    return_time = TIME_INIT
    book_number = input()
    if user_input == TEACH:
        new_book = TeachingAidsBook(private_parameter, book_name, leave_time, return_time, book_number)
    elif user_input == SCIENCE:
        new_book = ScienceBook(private_parameter, book_name, leave_time, return_time, book_number)
    elif user_input == POPULAR:
        new_book = PopularScienceBook(private_parameter, book_name, leave_time, return_time, book_number)
    elif user_input == NOVEL:
        new_book = NovelBook(private_parameter, book_name, leave_time, return_time, book_number)
    elif user_input == LIFE:
        new_book = LifeBook(private_parameter, book_name, leave_time, return_time, book_number)
    else:
        print("输入错误")
        return INPUTERROR
    return new_book

#读取文件
def readFile():
    with open('./书籍数据.yaml', 'r',encoding='UTF-8') as read:
        list_book_information = yaml.load(read)
        return list_book_information

#写入文件
def writeFile(list_book_information):
    with open('./书籍数据.yaml', 'w',encoding='UTF-8') as file:
        yaml.dump(list_book_information, file, encoding='UTF-8', allow_unicode='True')

#遍历列表
def ergodicFile(list_book_information):
    #while循环遍历列表, i是用来满足遍历的条件
    i = LOOP
    while i < len(list_book_information):
        print(list_book_information[i].getBookNumber(), list_book_information[i].getBookName())
        i += 1

#增加书籍
def addBook():
    print("输入你要加入的书籍.1教辅, 2科学, 3科普, 4小说, 5生活")
    book_information = inputBookInformation(int(input()))
    list_book_information = readFile()
    #list_book_information = []
    list_book_information.append(book_information)
    writeFile(list_book_information)

#减少书籍
def deleteBook():
    list_book_information = readFile()
    ergodicFile(list_book_information)
    print('输入你要删除的书的编号')
    inputBookNumber = input()
    i = LOOP
    while i < len(list_book_information):
        if list_book_information[i].getBookNumber() == inputBookNumber:
            list_book_information.remove(list_book_information[i])
        i += 1
    writeFile(list_book_information)

#更改书籍信息
def changeBook():
    list_book_information = readFile()
    ergodicFile(list_book_information)
    print('输入你要更改的书的编号,按照私有属性,名字,编号来输入')
    inputBookNumber = input()
    i = LOOP
    while i < len(list_book_information):
        if list_book_information[i].getBookNumber() == inputBookNumber:
            list_book_information[i].setPrivate(input())
            list_book_information[i].setBookName(input())
            list_book_information[i].setBookNumber(input())
        i += 1
    writeFile(list_book_information)

#addBook()