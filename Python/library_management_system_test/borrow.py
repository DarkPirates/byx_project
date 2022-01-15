#!/usr/bin/python3
#-*-UTF-8-*-

import administrators

import yaml

import time

import copy

from book import Book

LOOP = 0
NULL = 0
EMPTYSCHOOLBAG = 0
DEFAULTTIME = 0

##
# @brief 遍历列表
##
def ergodicFile():
    list_book_information = administrators.readFile()
    #while循环遍历列表, i是用来满足遍历的条件
    i = LOOP
    while i < len(list_book_information):
        print(list_book_information[i].getBookNumber(), list_book_information[i].getBookName())
        i += 1
    administrators.writeFile(list_book_information)
##
# @brief 遍历特定类别的书
#
# @param typeBook 是传入的书籍类型,本剧此变量来筛选书本
##
def ergodicFileType(tyoeBook):
    list_book_information = administrators.readFile()
    #while循环遍历列表, i是用来满足遍历的条件
    i = LOOP
    while i < len(list_book_information):
        if list_book_information[i].mark == tyoeBook:
            print(list_book_information[i].getBookNumber(), list_book_information[i].getBookName())
        i += 1
    administrators.writeFile(list_book_information)

##
# @brief 写入借出信息
#
# @param list_book_infhormation<list> 传入一个列表然后将此列表写入到文件
##
def writeBorrow(list_book_information):
    with open('./借出数据.yaml', 'w',encoding='UTF-8') as file:
        yaml.dump(list_book_information, file, encoding='UTF-8', allow_unicode='True')

##
# @brief 读取借出信息
#
# @retval list_book_information<list> 读取到的书本信息列表,将此列表返回
##
def readBorrow():
    with open('./借出数据.yaml', 'r',encoding='UTF-8') as read:
        list_book_information = yaml.load(read)
        return list_book_information

##
# @brief 结算,如果条件是结算应该怎么做
#
# @param list_book_information[i]<Book> 传入一个book类型的变量用于结算,对借出和书本信息进行修改
# @param a_book_number<str> 具体的书本编号
#
# @revalue list_book_information[i] 返回一个Book类型,将要借出的那本书的编号去除之后,应该将此书返回回来
##
def liquidationABook(a_book,a_book_number):
    print(type(a_book))
    borrow_information = readBorrow()
    borrow_number = len(borrow_information)
    if borrow_number == NULL:
        a_book.getBookNumber().remove(a_book_number)
        a_book_flag = copy.deepcopy(a_book)
        print(type(a_book_flag))
        a_book.getBookNumber().clear()                                                              
        a_book.getBookNumber().append(a_book_number)
        a_book_flag.setLeaveTime(int(time.time()))                                                 #设置图书离馆时间
        print('输入你的名字')         
        name = input()      
        a_book_flag.setRootChange(a_book_number, name, int(time.time()), DEFAULTTIME)                        #设置图书借的人的信息
        writeBorrow(a_book)
        print("结算成功")
        return a_book_flag
    while borrow_number:
        print("while")
        if borrow_information[borrow_number - 1].getBookMark() == a_book.getBookMark():
            if borrow_information[borrow_number - 1].getBookName() == a_book.getBookName():         #这是找到了输入的书本编号
                a_book.setLeaveTime(int(time.time()))                                                 #设置图书离馆时间
                print('输入你的名字')         
                name = input()      
                a_book.setRootChange(a_book_number, name, setLeaveTime, DEFAULTTIME)                        #设置图书借的人的信息
                borrow_information[borrow_number - 1].append(a_book_number)
                a_book.getBookNumber().remove(a_book_number)
                writeBorrow(borrow_information)
                return a_book

##
# @brief 对借的书籍进行管理,存入备选或者从图书馆取出.
#
# @param book_name<str>书名,由自己去定义
# @param a_book_name<str> 具体到哪个书本的编号
# @param mark<str> 书籍类别
# @param condition<str> 选择,学生对书本的操作,通过输入来传入,根据这个变量去决定运行哪一段的代码
# @para book_bag<list> 输入的一个备选清单,如果没选择结算就将这个编号的书本加入这个备选清单
##
def borrowBookStep(book_name, a_book_number, mark, condition, book_bag):
    list_book_information = administrators.readFile()                           #这是读取图书馆的书本
    i = len(list_book_information)                                                                    #这个I是用来循环的,找到要操作的具体书本
    while i:
        if list_book_information[i - 1].getMark() == mark:                          #根据类别进行筛选
            if list_book_information[i - 1].getBookName() == book_name:             #根据书名进行筛选
                print(book_name)
                findNumber = list_book_information[i - 1].getBookNumber()           #将书本编号列表提取出来
                operation_number = len(findNumber)      
                while operation_number:                                 
                    if findNumber[operation_number - 1] == a_book_number:         #找到该编号的书本
                        if condition == "结算":
                            list_book_information[i - 1] = liquidationABook(list_book_information[i - 1], a_book_number)       #对该书本进行结算
                            print(list_book_information[i - 1].getBookNumber())
                            administrators.writeFile(list_book_information)
                            return book_bag
                        elif condition == "加入":
                            book_bag.append(list_book_information[i - 1])           #加入备选的话,应该只加入选到的编号书本,其他的就不应该参杂进去所以这里应该再筛选一次
                            list_book_information[i - 1].getBookNumber().clear()    #先清空列表
                            list_book_information[i - 1].getBookNumber().append(findNumber[operation_number - 1]) #将要加入备选的书的编号加入这个即将加入借出书籍的list
                            writeBorrow(list_book_information[i - 1])               #现在这个里面便只剩下了findnumber中需要的那个编号
                            return book_bag    
                        else:
                            return book_bag
                    operation_number -= 1                     
        i -= 1                                  
                            
'''

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
'''

##
# @brief 借书
# 
# @ retval book_bag<list> 里面存储的是备选的书籍,这个备选书籍,既不存在于图书馆内,也不在这个借出列表内 
##
def borrowBook():
    book_bag = []
    while True:
        if len(book_bag) > 5:
            print('已经达到上限,自动退出选书环节')
            return book_bag
        print('输入你要看得书名, 书本编号, 类别')
        book_name = input()
        input_book_number = input()
        book_mark = input()
        print('结算还是加入书包')
        conclusion = input()
        this_book = borrowBookStep(book_name, input_book_number, book_mark, conclusion, book_bag)
        print('是否退出借书环节')
        if input() == '是':
            return book_bag

##
# @brief 对备选清单进行结算
#
# @param book_bag<list> 
##
def clearBookBag(book_bag):
    list_book_information = readBorrow()
    print('输入你的帐号')
    name = input()
    i = LOOP
    while i < len(book_bag):
        book_bag[i].setRootChange(name)                        #设置图书借的人的信息
        list_book_information.append(book_bag[i])
        book_bag.remove(book_bag[i])

##
# @brief 对书包进行管理遍历
#
# @param book_bag<list> 对这个列表进行遍历
##
def bookBagErgodic(book_bag):
    i = LOOP
    while i < len(book_bag):
        print(book_bag[i].getgetBookNumber(), book_bag[i].getBookName())
        i += 1

##
# @brief 对备选书籍(书包)进行管理
#
# @param book_bag<list> 在结算前需要去对备选进行清理,看看是否需要删改
#
# @retval EMPTYSCHOOLBAG这个值表示书包为空不能进行操作
##
def bookBag(book_bag):
    while True:
        bookBagErgodic(book_bag)
        list_book_information = readBorrow()
        print('结算?还是删除')
        if input() == '结算':
            clearBookBag(book_bag)
        else:
            print('输入你要删除的书的编号')
            inputBookNumber = input()
            i = LOOP
            while i < len(book_bag):
                if book_bag[i].getBookNumber() == inputBookNumber:
                    book_bag.remove(book_bag[i])
                i += 1
        if len(book_bag) == EMPTYSCHOOLBAG:
            print('书包为空')
            return EMPTYSCHOOLBAG

##
# @brief 归还遍历
#
# @param book_number<list>
##
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

##       
# @brief 还书
##
def giveBack():
    print('输入你要归还的书籍编号')
    book_number = input()
    giveBackErgodic(book_number)

## 
# @brief 查看本人的借阅记录
##
def seeQuery():
    administrators.myPrint("输入你的帐号")
    acount = input()
    list_book_infhormation = administrators.readFile()
    borrow_information = readBorrow()
    i = NULL
    while i < len(list_book_infhormation):
        lib_information =  list_book_infhormation[i].getRootChange()
        if lib_information[i].keys() == acount:
            administrators.myPrint(lib_information[i])
    i = NULL
    while i < len(borrow_information):
        lib_information = borrow_information[i].getRootChange()
        if lib_information[i].keys() == acount:
            administrators.myPrint(borrow_information[i])
            
##
# @brief 查看所有的借阅记录 all in
##
def seeAllQuery():
    list_book_infhormation = administrators.readFile()
    borrow_information = readBorrow()
    i = NULL
    while i < len(list_book_infhormation):
        lib_information =  list_book_infhormation[i].getRootChange()
        administrators.myPrint(lib_information[i])
    i = NULL
    while i < len(borrow_information):
        lib_information = borrow_information[i].getRootChange()
        administrators.myPrint(borrow_information[i])

def test():
    pass

borrowBook()