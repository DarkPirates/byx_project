#!/usr/bin/python3
#-*-UTF-8-*-

'''
这个文件是写管理员管理的...
'''
import pickle

import json

import time

import yaml

from book import Book

NO_FIND = -1
INPUTERROR = -1
LOOP = 0
TIME_INIT = 0
NONE = 0
EXISTENCE = 0
TEACH = 1
GOON = 1
SCIENCE = 2
POPULAR = 3
NOVEL = 4
LIFE = 5

##
# @brief 用来取出图书馆内存的书籍
# 
# @retval 返回的是取出的书本 file_read<list>
##
def takeOutBOOK():
    fileUser = open('./书籍数据','rb+')                                       #这一行打开这个文件,并给予读权限
    file_read = pickle.load(fileUser)                                       #file_read是表示读取出来的数据,此时是列表 
    #json_read_dictionaries = pickle.load(file_read)                        #这一行是读取出来的json类型转换     
    fileUser.close()                                                        #用了要关上,没啥好说的
    return file_read

##
# @brief 查找该编号书籍在不在列表中
# 
# @param book_name<str> 书本名
# @param a_book_number<str> 一个书本编号
# 
# @retval EXISTENCE 返回不存在该书
##
def checkBook(book_name, a_book_number):
    print(book_name)
    list_book_information = readFile()
    check_book = len(list_book_information)
    return_value_book = []
    while check_book:
        if list_book_information[check_book - 1].getBookName() == book_name:
            print(list_book_information[check_book - 1].getBookName())
            book_number = list_book_information[check_book - 1].getBookNumber()
            check_number = len(book_number)
            while check_number:
                if book_number[check_number - 1] == a_book_number:
                    return_value_book.append(check_book - 1)
                    return_value_book.append(check_number - 1)
                    print("已经存在该编号, 1.继续 ,其他输入为忽略")
                    if int(input()) == GOON:
                        return return_value_book
                    else:
                        return EXISTENCE
                check_number -= 1
        check_book -= 1
    return NO_FIND

##
# @brief 对书籍信息进行输入
#
# @retval new_book 将添加好的书本返回
##
def inputBookInformation():
    new_book = NONE
    print("输入书名")
    book_name = input()
    list_book_information = readFile()
    i = LOOP
    while i < len(list_book_information):
        if list_book_information[i].getBookName() == book_name:
            print("书名存在,请去添加书本添加内容喔")
            return
        i += 1
    leave_time = TIME_INIT
    return_time = TIME_INIT
    book_number = []
    root_change = []
    while True:
        print("输入书籍编号, # 为停止")
        in_book_number = input()
        check_number = checkBook(book_name, in_book_number)
        if check_number == EXISTENCE:
            continue
        if in_book_number == "#":
            break
        if in_book_number == "":
            print("输入错误")
            continue
        book_number.append(in_book_number)
    print("输入书本所属类别")
    mark = input()
    print(book_name, leave_time, return_time, book_number, mark, root_change)
    new_book = Book(book_name, leave_time, return_time, book_number, mark, root_change)
    return new_book

##
# @brief 读取文件
#
# @retval 返回读取到的文件
##
def readFile():
    with open('./书籍数据.yaml', 'r',encoding='UTF-8') as read:
        list_book_information = yaml.load(read)
        return list_book_information

##
# @brief 写入文件
##
def writeFile(list_book_information):
    with open('./书籍数据.yaml', 'w',encoding='UTF-8') as file:
        yaml.dump(list_book_information, file, encoding='UTF-8', allow_unicode='True')

##
# @brief 遍历列表
#
# @param list_book_information<list> 这是书本的列表
##
def ergodicFile(list_book_information):
    #while循环遍历列表, i是用来满足遍历的条件
    i = LOOP
    while i < len(list_book_information):
        print(len(list_book_information),i,list_book_information[i].getMark(), list_book_information[i].getBookName())
        i += 1

##
# @ brief 增加书籍
##
def addBookType():
    print("输入你要加入的书籍")
    book_information = inputBookInformation()
    list_book_information = readFile()
    #list_book_information = []
    list_book_information.append(book_information)
    writeFile(list_book_information)

##
# @brief 减少书籍
##
def deleteBookType():
    find_flag = 0
    list_book_information = readFile()
    ergodicFile(list_book_information)
    print('输入你要删除的书籍类别')
    inputBookMark = input()
    i = len(list_book_information)
    while i:
        if list_book_information[i - 1].getMark() == inputBookMark:
            list_book_information.remove(list_book_information[i - 1])
            find_flag = 1
        i -= 1
    if find_flag == 0:
        print("没找到喔=-=")
    else:
        print("删除成功")
    writeFile(list_book_information)

##
# @brief 更改书籍信息
##
def changeBookType():
    find_flag = 0
    list_book_information = readFile()
    ergodicFile(list_book_information)
    print('输入你要更改的书名')
    inputBookName = input()
    i = LOOP
    while i < len(list_book_information):
        print(list_book_information[i].getBookName())
        if list_book_information[i].getBookName() == inputBookName:
            print("输入新的书名")
            list_book_information[i].setBookName(input())
            print("输入新的类型名")
            list_book_information[i].setMartk(input())
            find_flag = 1
        i += 1
    if find_flag == 0:
        print("没找到喔=-=")
    else:
        print("修改成功")
    writeFile(list_book_information)

##
# @brief 增加书本
##
def addBook():
    list_book_information = readFile()
    ergodicFile(list_book_information)
    print("输入要增加的书本名, 以及书本类型")
    book_name = input()
    book_mark = input()
    i = NONE
    while i < len(list_book_information):
        if list_book_information[i].getBookName() == book_name:
            if list_book_information[i].getMark() == book_mark:
                while True:
                    print("输入增加书本的书本编号, # 表示输入完毕")
                    a_book_number = input()
                    check_number = checkBook(book_name, a_book_number)
                    if a_book_number == "#":
                        break
                    if check_number == EXISTENCE:
                        print("该编号已存在")
                        continue
                    else:
                        list_book_information[i].getBookNumber().append(a_book_number)
                        list_book_information[i].book_stock = len(list_book_information[i].getBookNumber())
        list_book_information[i].book_stock = len(list_book_information[i].getBookNumber())
        i += 1
    writeFile(list_book_information)
    if i == len(list_book_information):
        print("没找到=-=")
        return 

##
# @brief 减少书本
#
##
def deleteBook():
    while True:
        list_book_information = readFile()
        print("输入你要删除的书名和编号, # 表示结束")
        book_name = input()
        if book_name == '#':
            break
        a_book_number = input()
        subscript = checkBook(book_name,a_book_number)
        list_book = subscript[0]
        list_book_number = subscript[1]
        if subscript == NO_FIND:
            print("没找到")
            continue
        else:
            list_book_information_number = list_book_information[list_book].getBookNumber()
            list_book_information_number.remove(list_book_information_number[list_book_number])
            writeFile(list_book_information)

##
# @brief 更改书本
#
##
def changeBook():
    while True:
        list_book_information = readFile()
        print("输入你要更改的书名和编号, # 表示结束")
        book_name = input()
        if book_name == '#':
            break
        a_book_number = input()
        print("输入新的书名和编号")
        new_book_name = input()
        new_a_book_number = input()
        subscript = checkBook(book_name,a_book_number)
        if subscript == NO_FIND:
            print("没找到")
            continue
        else:
            list_book_information[subscript[0]].setBookName(new_book_name)
            list_book_information[subscript[0]].getBookNumber().remove(a_book_number)
            list_book_information[subscript[0]].getBookNumber().append(new_a_book_number)
            list_book_information[subscript[0]].book_stock = len(list_book_information[subscript[0]].getBookNumber())
            writeFile(list_book_information)
        
