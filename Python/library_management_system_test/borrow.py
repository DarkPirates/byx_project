#!/usr/bin/python3
#-*-UTF-8-*-

import administrators

import yaml

import time

LOOP = 0
NULL = 0

#遍历列表
def ergodicFile():
    list_book_information = administrators.readFile()
    #while循环遍历列表, i是用来满足遍历的条件
    i = LOOP
    while i < len(list_book_information):
        print(list_book_information[i].getBookNumber(), list_book_information[i].getBookName())
        i += 1
    administrators.writeFile(list_book_information)

#遍历特定类别的书
def ergodicFileType(tyoeBook):
    list_book_information = administrators.readFile()
    #while循环遍历列表, i是用来满足遍历的条件
    i = LOOP
    while i < len(list_book_information):
        if list_book_information[i].mark == tyoeBook:
            print(list_book_information[i].getBookNumber(), list_book_information[i].getBookName())
        i += 1
    administrators.writeFile(list_book_information)

#写入借出信息
def writeBorrow(list_book_information):
    with open('./借出数据.yaml', 'w',encoding='UTF-8') as file:
        yaml.dump(list_book_information, file, encoding='UTF-8', allow_unicode='True')


#读取借出信息
def readBorrow():
    with open('./借出数据.yaml', 'r',encoding='UTF-8') as read:
        list_book_information = yaml.load(read)
        return list_book_information

#结算
def liquidationBook(book_number,conclusion):    
    list_book_information = administrators.readFile()                           #读取文件
    this_book = 'NULL'
    i = LOOP                                                                          
    while i < len(list_book_information):        
        print(i)                                 
        if list_book_information[i].getBookNumber() == book_number:                 
            list_book_information[i].setLeaveTime(int(time.time()))             #设置图书离馆时间
            print('输入你的名字')         
            name = input()      
            list_book_information[i].setRootChange(name)                        #设置图书借的人的信息
            this_book = list_book_information[i]                                #要返回这个书
            list_book_information.remove(list_book_information[i])              #将图书移出图书馆
            administrators.writeFile(list_book_information)
            if conclusion == '结算':
                list_book_information = readBorrow()
                list_book_information.append(this_book)
                print(list_book_information)
                writeBorrow(list_book_information)
                return NULL
            else:
                return this_book
        i += 1

#借书
def borrowBook():
    book_bag = []
    while True:
        print('输入你要看得类别')
        ergodicFileType(input())
        print('输入你要操作书的编号')
        input_book_number = input()
        print('结算还是加入书包')
        conclusion = input()
        this_book = liquidationBook(input_book_number,conclusion)
        if conclusion != '结算':
            book_bag.append(this_book)
        print('是否退出借书环节')
        if input() == '是':
            return book_bag

#g归还遍历
def giveBackErgodic(book_number):
    list_book_information = readBorrow()
    i = LOOP
    this_book = 'NULL'   
    while i < len(list_book_information):
        if list_book_information[i].getBookNumber() == book_number:
            list_book_information[i].setReturnTime(int(time.time()))
            this_book = list_book_information[i]
            list_book_information.remove(list_book_information[i])
            writeBorrow(list_book_information)
        i += 1
    list_book_information = administrators.readFile()
    list_book_information.append(this_book)
    administrators.writeFile(list_book_information)
        
#还书
def giveBack():
    print('输入你要归还的书籍编号')
    book_number = input()
    giveBackErgodic(book_number)





def test():
    pass

borrowBook()