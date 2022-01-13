#!/usr/bin/python3
#-*-UTF-8-*-

import json

LOGIN_ERROR = -1
LOGIN_OUT = 0
PASSWORD_COUNT = 0
GO_ON = 1
LOGIN_SUCCESS = 1
NEED = 1

#这是我自己的输入函数
def obtainInput():
    return input()

#这是我自己的输出函数
def myPrint(output_information):
    print(output_information)

def myPrint(output_information):
    print(output_information)
    
#这是一个将帐号密码取出来的函数
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



#基类 书 有的属性:书名,离馆时间,归还时间,书籍编号
class Book:
    def __init__(self, book_name, leave_time, return_time, book_number, mark, root_change):
        self.book_name = book_name
        self.leave_time = leave_time
        self.return_time = return_time
        self.book_number = book_number
        self.root_change = []
        self.mark = mark
        self.book_stock = len(book_number)
        self.root_change = []

    def getBookName(self):
        return self.book_name

    def getLeaveTime(self):
        return self.leave_time

    def getReturnTime(self):
        return self.return_time

    def getBookNumber(self):
        return self.book_number

    def getBorrowTIme(self):
        return (self.return_time - self.leave_time)

    def getRootChange(self):
        return self.root_change

    def getMark(self):
        return self.mark
    
    def setRootChange(self, a_book_number, name, leave_time, return_time):
        user_borrow_time = self.getBorrowTIme()
        user_borrow = [{a_book_number : [name, leave_time, return_time, return_time - leave_time]}]
        self.root_change.extend(user_borrow)

    def setBookName(self,book_name):
        self.book_name = book_name

    def setMartk(self,mark):
        self.mark = mark
        
    def setLeaveTime(self,leave_time):
        self.leave_time = leave_time

    def setReturnTime(self,return_time):
        self.return_time = return_time

    def setBookNumber(self,book_number):
        self.book_number = book_number


class Member:
    def __init__(account, password):
        self.account = account
        self.password = password
    def loginIn():
        pass


class User(Member):
    def __init__(self, account, password, user_id):
        Member.__init__(account,password)
        self._user_id = user_id

    def loginIn():                                                          #登陆
        storage_account = takeOutAccount()
        if input_user_name not in storage_account:
            myPrint("没有找到该用户,继续请扣1,否则退出该程序")
            user_input = int(obtainInput())
            if user_input == GO_ON:
                return LOGIN_OUT
        elif storage_account[input_user_name] != input_user_password:
            if PASSWORD_COUNT < 3:
                PASSWORD_COUNT += 1
                continue
            else:
                PASSWORD_COUNT = 0
                return LOGIN_ERROR
        else:
            return LOGIN_SUCCESS

    def registerAccounts():
        storage_account = takeOutAccount()
        user_name = self.account            
        if user_name in storage_account:
            print("已经有了该用户名")
            return LOGIN_ERROR                                                  
        user_password = self.password                  
        account_information[user_name] = user_password
        user_account_json = json.dumps(account_information)                     #这里是将用户的输入存入刚刚取出的字典中
        fileUser = open('./用户数据','r+')                                       #这一行打开这个文件,并给予读写权限
        fileUser.seek(0)                                                        #移动光标到首字节,以便覆盖掉以前的,防止有多个字典,然后读取出错
        fileUser.write(user_account_json)                                       #写入文件中
        fileUser.close()                                                        #最后不要忘了关闭这个文件
