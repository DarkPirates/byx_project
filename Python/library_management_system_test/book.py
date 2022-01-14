#!/usr/bin/python3
#-*-UTF-8-*-

import json

LOGIN_ERROR = -1
LOGIN_OUT = 0
PASSWORD_COUNT = 0
GO_ON = 1
LOGIN_SUCCESS = 1
NEED = 1


##
# @brief 这是我自己的输入函数,接收输入
#   
# @retval 返回输入的内容
##
def obtainInput():
    return input()

##
# @brief 这是我自己的输出函数
# @param output_information<str> 表示要输出的内容
##
def myPrint(output_information):
    print(output_information)

##
# @brief 这是一个将帐号密码取出来的函数
# @retval 返回从json文件中读取的内容
##
def takeOutAccount():
    fileUser = open('./用户数据','r+')                                       #这一行打开这个文件,并给予读权限
    file_read = fileUser.read()                                            #file_read是表示读取出来的数据,此时是json类型
    json_read_dictionaries = json.loads(file_read)                          #这一行是将读取出来的json类型转换成字典
    fileUser.close()                                                        #用了要关上,没啥好说的
    return json_read_dictionaries

#这是注册函数
def registerAccounts():
    account_information =  takeOutAccount() 
    myPrint("输入帐号,密码,用回车隔开")                                        #这里三行是对帐号注册时的名字与密码输入问题    
    user_name = obtainInput()                                                                  
    user_password = obtainInput()                  
    account_information[user_name] = user_password
    user_account_json = json.dumps(account_information)                     #这里是将用户的输入存入刚刚取出的字典中
    fileUser = open('./用户数据','r+')                                       #这一行打开这个文件,并给予读写权限
    fileUser.seek(0)                                                        #移动光标到首字节,以便覆盖掉以前的,防止有多个字典,然后读取出错
    fileUser.write(user_account_json)                                       #写入文件中
    fileUser.close()                                                        #最后不要忘了关闭这个文件


##
# @brief 基类 书 有的属性:书名,离馆时间,归还时间,书籍编号,书籍类别,借阅信息
# 
##
class Book:
    ##
    # @brief 初始化这个类 
    # @param book_name<str> 输入的书本名 
    # @param leave_time<int> 输入的离馆时间, 默认为0
    # @param return_time<int> 输入的归还时间, 默认为0
    # @param book_number<list> 输入的书本编号, 是一个list
    # @param mark<str> 输入的书籍类别
    # @param root_change<list> 输入的借阅信息,默认为[]
    ##
    def __init__(self, book_name, leave_time, return_time, book_number, mark, root_change):
        self.book_name = book_name
        self.leave_time = leave_time
        self.return_time = return_time
        self.book_number = book_number
        self.root_change = []
        self.mark = mark
        self.book_stock = len(book_number)
        self.root_change = []
    
    ##
    # @brief 获取书名
    # @retval 返回得到的书名
    ##
    def getBookName(self):
        return self.book_name
    ##
    # @brief 获取离馆时间   
    # @retval 返回离馆时间
    ##
    def getLeaveTime(self):
        return self.leave_time

    ##
    # @brief 获取归还时间
    #
    # @retval 返回归还时间
    ##
    def getReturnTime(self):
        return self.return_time

    ##
    # @brief 获取书本编号
    #
    # @retval 返回获得的书本编号,类型为list
    ##
    def getBookNumber(self):
        return self.book_number

    ##
    # @brief 获取接触时间
    #
    # @retval 返回归还时间和离馆时间的差值
    ##
    def getBorrowTIme(self):
        return (self.return_time - self.leave_time)

    ##
    # @brief 获取借阅信息
    #
    # @retval 返回借阅信息
    ##
    def getRootChange(self):
        return self.root_change

    ##
    # @brief 获取书籍类别
    #
    # @retval 返回书籍类别
    ##
    def getMark(self):
        return self.mark
    
    ##
    # @brief 设置借阅信息
    #
    # @param a_book_number<list> 是具体的一个书本编号,从book_number这个列表中查找到的具体编号
    # @param name<str> 是书本名字
    # @param leave_time<int> 是离馆时间
    # @param return_time<int> 是归还时间
    ##
    def setRootChange(self, a_book_number, name, leave_time, return_time):
        user_borrow_time = self.getBorrowTIme()
        user_borrow = [{a_book_number : [name, leave_time, return_time, return_time - leave_time]}]
        self.root_change.extend(user_borrow)

    ##
    # @brief 设置书名
    #
    # @param book_name<str> 是传入的书名
    ##
    def setBookName(self,book_name):
        self.book_name = book_name

    ##
    # @brief 设置书籍类别
    #
    # @retval mark<str> 是输入的书籍类别
    ##
    def setMartk(self,mark):
        self.mark = mark

    ##
    # @brief 设置离馆时间 
    #
    # @param leave_time<int> 输入的离馆时间
    ##    
    def setLeaveTime(self,leave_time):
        self.leave_time = leave_time

    ##
    # @brief 设置归还时间
    #
    # @param return_time<int> 输入的归还时间
    ##
    def setReturnTime(self,return_time):
        self.return_time = return_time

    ##
    # @brief 设置书本编号 类型为list
    #
    # @param book_number<list> 为输入的书本编号,默认为[]
    ##
    def setBookNumber(self,book_number):
        self.book_number = book_number

