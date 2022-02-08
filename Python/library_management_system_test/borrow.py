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
FRIST = 0
EXIT = 1
CHECK_OUT = 1
ADD = 2
DELETE = 2
CHECK_OUT_BAG = 3

##
# @brief 遍历列表
##
def ergodicFile():
    list_book_information = administrators.readFile()
    #while循环遍历列表, i是用来满足遍历的条件
    i = LOOP
    while i < len(list_book_information):
        print(list_book_information[i].getBookName(), list_book_information[i].getBookNumber(),  list_book_information[i].getMark())
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
# @brief 写入借出信息从头开始写
#
# @param list_book_infhormation<list> 传入一个列表然后将此列表写入到文件
##
def writeBorrow(list_book_information):
    with open('./借出数据.yaml', 'w',encoding='UTF-8') as file:
        yaml.dump(list_book_information, file, encoding='UTF-8', allow_unicode='True')

##
# @brief 写入借出信息从尾部开始加入
#
# @param list_book_infhormation<list> 传入一个列表然后将此列表写入到文件
##
def writeBorrow_a(list_book_information):
    with open('./借出数据.yaml', 'a',encoding='UTF-8') as file:
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
    borrow_information = readBorrow()
    borrow_number = len(borrow_information)
    #if borrow_number == NULL:
    a_book.getBookNumber().remove(a_book_number)
    a_book_flag = copy.deepcopy(a_book)
    a_book.getBookNumber().clear()                                                              
    a_book.getBookNumber().append(a_book_number)
    a_book_flag.setLeaveTime(int(time.time()))                                                 #设置图书离馆时间
    print('输入你的名字')         
    name = input()    
    print(name)  
    a_book_flag.setRootChange(a_book_number, name, int(time.time()), DEFAULTTIME)                        #设置图书借的人的信息
    borrow_information.append(a_book)
    writeBorrow(borrow_information)
    print("结算成功")
    return a_book_flag

        
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
                findNumber = list_book_information[i - 1].getBookNumber()           #将书本编号列表提取出来
                operation_number = len(findNumber)      
                while operation_number:                               
                    if findNumber[operation_number - 1] == a_book_number:         #找到该编号的书本
                        if condition == str(CHECK_OUT):
                            list_book_information[i - 1] = liquidationABook(list_book_information[i - 1], a_book_number)       #对该书本进行结算
                            list_book_information[i - 1].book_stock = len(list_book_information[i - 1].getBookNumber()) 
                            administrators.writeFile(list_book_information)
                            return book_bag
                        elif condition == str(ADD):
                            new_book_number = [a_book_number]
                            new_book = Book(list_book_information[i - 1].getBookName(), list_book_information[i - 1].getLeaveTime(), 
                                            list_book_information[i - 1].getReturnTime(), new_book_number, list_book_information[i - 1].getMark(), 
                                            list_book_information[i - 1].getRootChange())
                            book_bag.append(new_book)
                            list_book_information[i - 1].getBookNumber().remove(a_book_number)
                            list_book_information[i - 1].book_stock = len(list_book_information[i - 1].getBookNumber())
                            administrators.writeFile(list_book_information)
                            return book_bag    
                        else:
                            return book_bag
                    operation_number -= 1                     
        i -= 1                                  
                            


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
        ergodicFile()
        print('输入你要看得书名, 书本编号, 类别')
        book_name = input()
        input_book_number = input()
        book_mark = input()
        print('1.结算 还是 2.加入备选')
        conclusion = input()
        this_book = borrowBookStep(book_name, input_book_number, book_mark, conclusion, book_bag)
        print('输入 1 退出借书环节,对备选书进行管理')
        if input() == str(EXIT):
            if len(book_bag) != NULL:
                bookBag(book_bag)
            return 

##
# @brief 对备选清单进行结算
#
# @param book_bag<list> 
##
def clearBookBag(book_bag):
    bookBagErgodic(book_bag)
    list_book_information = readBorrow()
    print('输入你的帐号')
    name = input()
    i = LOOP
    while i < len(book_bag):
        book_bag_number = book_bag[i].getBookNumber()
        book_bag[i].setRootChange(book_bag_number[i], name, int(time.time()), book_bag[i].getReturnTime())                        #设置图书借的人的信息
        list_book_information.append(book_bag[i])
        addBorrow = len(list_book_information)
        while addBorrow:
            if list_book_information[addBorrow - 1].getBookName() == book_bag[i].getMark():
                if(list_book_information[addBorrow - 1].getBookMark() == book_bag[i].getBookMark()):
                    list_book_information[addBorrow - 1].getBookNumber().extend(book_bag[i].getBookNumber())
                    book_bag.remove(book_bag[i])
            addBorrow -= 1
        book_bag.remove(book_bag[i])
        writeBorrow(list_book_information)
        #writeBorrow_a(book_bag)

##
# @brief 对书包进行管理遍历
#
# @param book_bag<list> 对这个列表进行遍历
##
def bookBagErgodic(book_bag):
    i = LOOP
    while i < len(book_bag):
        print(book_bag[i].getBookNumber(), book_bag[i].getBookName())
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
        if len(book_bag) == EMPTYSCHOOLBAG:
            print('书包为空')
            return EMPTYSCHOOLBAG
        list_book_information = readBorrow()
        while True:
            print('1.结算 还是 2.删除 3.退出')
            check = input()
            if check == str(CHECK_OUT):
                clearBookBag(book_bag)
                return
            elif check == str(DELETE):
                print('输入你要删除的书的编号')
                bookBagErgodic(book_bag)
                inputBookNumber = input()
                i = LOOP
                while i < len(book_bag):
                    if (book_bag[i].getBookNumber())[i] == inputBookNumber:
                        list_book_information_flag = administrators.readFile()
                        list_book_information_number = len(list_book_information_flag)
                        while list_book_information_number:
                            if list_book_information_flag[list_book_information_number - 1].getBookName() == book_bag[i].getBookName():
                                if list_book_information_flag[list_book_information_number - 1].getMark() == book_bag[i].getMark():
                                    list_book_information_flag[list_book_information_number - 1].getBookNumber().extend(book_bag[i].getBookNumber())
                                    administrators.writeFile(list_book_information_flag)
                            list_book_information_number -= 1
                        book_bag.remove(book_bag[i])
                    i += 1
            elif check == str(CHECK_OUT_BAG):
                list_book_information_flag = administrators.readFile()
                list_book_information_number = len(list_book_information_flag)
                i = LOOP
                while i < len(book_bag):
                    while list_book_information_number:
                        if list_book_information_flag[list_book_information_number - 1].getBookName() == book_bag[i].getBookName():
                            if list_book_information_flag[list_book_information_number - 1].getMark() == book_bag[i].getMark():
                                list_book_information_flag[list_book_information_number - 1].getBookNumber().extend(book_bag[i].getBookNumber())
                        list_book_information_number -= 1
                    book_bag.remove(book_bag[i])
                    i += 1
                administrators.writeFile(list_book_information_flag)    
                return 
            else:
                print("输入错误,重试")

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
        list_book_number = list_book_information[i].getBookNumber()
        if list_book_number[FRIST] == book_number:
            list_book_information[i].setReturnTime(int(time.time()))
            list_book_information[i].setRootChange(book_number, list_book_information[i].getBookName(), list_book_information[i].getLeaveTime(), int(time.time()))
            print(list_book_information[i].getBookNumber())
            this_book = copy.deepcopy(list_book_information[i])
            print(this_book.getBookNumber())
            list_book_information.remove(list_book_information[i])
            writeBorrow(list_book_information)
        i += 1
    list_book_information = administrators.readFile()
    book_type_number = len(list_book_information)
    while book_type_number:     
        if list_book_information[book_type_number - 1].getMark() == this_book.getMark():
            if list_book_information[book_type_number - 1].getBookName() == this_book.getBookName():
                list_book_information[book_type_number - 1].getBookNumber().extend(this_book.getBookNumber())
                list_book_information[book_type_number - 1].getRootChange().extend(this_book.getRootChange())
                list_book_information[book_type_number - 1].book_stock = len(list_book_information[book_type_number - 1].getBookNumber())
        book_type_number -= 1   
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
    print("输入你的帐号")
    acount = input()
    list_book_infhormation = administrators.readFile()
    borrow_information = readBorrow()
    i = NULL
    while i < len(list_book_infhormation):
        lib_information = list_book_infhormation[i].getRootChange()
        lib_information_number = len(lib_information)
        if lib_information_number != 0:
            while lib_information_number:
                names = [v[0] for v in lib_information[lib_information_number - 1].values()]
                if names[0] == acount:
                    print(lib_information[lib_information_number - 1].keys(), lib_information[lib_information_number - 1].values())
                lib_information_number -= 1
        i += 1
    i = NULL
    while i < len(borrow_information):
        lib_information = borrow_information[i].getRootChange()
        lib_information_number = len(lib_information)
        if lib_information_number != 0:
            while lib_information_number:
                names = [v[0] for v in lib_information[lib_information_number - 1].values()]
                if names[0] == acount:
                    print(lib_information[lib_information_number - 1].keys(), lib_information[lib_information_number - 1].values())
                lib_information_number -= 1
        i += 1

'''
            if lib_values[1] == acount
                print(lib_information[lib_information_number - 1].values())
            lib_information_number -= 1
            
        i += 1
    i = NULL
    while i < len(borrow_information):
        lib_information = borrow_information[i].getRootChange()
        lib_information_number = len(lib_information)
        while lib_information_number:
            if lib_information[lib_information_number - 1].keys() == acount:
                print(lib_information[lib_information_number - 1].values())
            lib_information_number -= 1
        i += 1
'''  


##
# @brief 查看所有的借阅记录 all in
##
def seeAllQuery(input_book_name):
    list_book_infhormation = administrators.readFile()
    borrow_information = readBorrow()
    i = NULL
    while i < len(list_book_infhormation):
        if list_book_infhormation[i].getBookName() == input_book_name:
            lib_information = list_book_infhormation[i].getRootChange()
            if len(lib_information) != 0:
                print(lib_information)
        i += 1
    i = NULL
    while i < len(borrow_information):
        if list_book_infhormation[i].getBookName() == input_book_name:
            lib_information = borrow_information[i].getRootChange()
            if len(lib_information) != 0:
                print(lib_information)
        i += 1
def test():
    pass
