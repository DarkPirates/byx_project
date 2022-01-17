#!/usr/bin/python3
#-*-UTF-8-*-

import json

import sign_in

LOOP = 0
NULL = 0
EMPTYSCHOOLBAG = 0
DEFAULTTIME = 0
LOGIN_ERROR = -1
LOGIN_OUT = 0
GO_ON = 1
LOGIN_SUCCESS_STUDENT = 1
NEED = 1
LOGIN_SUCCESS_ROOT = 2

class Member:
    ##
    # @brief 初始化函数,对member对象进行初始化
    # @param account<str> 帐号,member成员应该有的成员变量
    # @param password<str> 密码,member成员中account帐号对应的密码
    ##
    def __init__(self, account):
        self.account = account
    
    ##
    # @brief 登陆接口,但是呢,一般都用派生类自己的登陆接口,如果写了就是有空就写了,没写就是没时间来补充了
    #
    ##
    def loginIn():
        pass


class User(Member):

    ##
    # @brief 初始化学生这个类
    # @account<str> 这是输入的帐号
    # @password<str> 输入的密码
    # @user_id<str> 这是学生私有的学号
    ##
    def __init__(self, account, user_id):
        Member.__init__(self, account)
        self._user_id = user_id

    ##
    # @brief 设置自己的密码,是指输入的密码
    #
    # @param password<str> 输入的新密码
    ##
    def setPassword(self, password):
        self.password = password

    ##
    # @brief 设置自己的帐号,是指输入的帐号
    #
    # @param account<str> 输入的新帐号
    ##
    def setAccount(self, account):
        self.account = account

    ##
    # @brief 这是登陆函数,学生类的
    # @retval 返回 LOGIN_OUT 表示登陆失败,学生主动退出,返回 LOGIN_ERROR 表示登陆失败,失败次数过多,被动结束程序,返回 LOGIN_SUCCESS 表示登陆成功,继续程序运行
    ##
    
    def loginIn(self):                                                          #登陆
        set_pass_flag = 0
        while True:
            storage_account = sign_in.takeOutAccount()
            if self.account not in storage_account:
                sign_in.myPrint("没有找到该用户,继续请扣1,否则退出该程序")
                user_input = int(sign_in.obtainInput())
                if user_input != GO_ON:
                    return LOGIN_OUT
                else:
                    self.setAccount(input())
            print("输入密码")
            self.setPassword(input())
            if storage_account[self.account] != self.password:
                if set_pass_flag < 3:
                    set_pass_flag += 1
                    self.setPassword(input())
                else:
                    return LOGIN_ERROR
            else:
                return LOGIN_SUCCESS_STUDENT

    ##
    # @brief 这是注册函数
    # @retval 返回 LOGIN_ERROR 表示注册失败,用户名已存在
    ##
    def registerAccounts(self):
        account_information = sign_in.takeOutAccount()
        user_name = self.account
        while True:            
            if user_name in account_information:
                sign_in.myPrint("已经有了该用户名,是否重新来?")
                user_input = input()
                if user_input == 'no':
                    return LOGIN_ERROR
                else:
                    print("重新输入你的帐号")
                    user_name = self.setAccount(input())
            else:
                break
        print("输入密码")
        user_password = self.setPassword(input())                
        account_information[user_name] = user_password
        user_account_json = json.dumps(account_information)                     #这里是将用户的输入存入刚刚取出的字典中
        fileUser = open('./用户数据','r+')                                       #这一行打开这个文件,并给予读写权限
        fileUser.seek(0)                                                        #移动光标到首字节,以便覆盖掉以前的,防止有多个字典,然后读取出错
        fileUser.write(user_account_json)                                       #写入文件中
        fileUser.close()                                                        #最后不要忘了关闭这个文件


class administratorsClass(Member):
    
    ##
    # @brief 设置自己的密码,是指输入的密码
    #
    # @param password<str> 输入的新密码
    ##
    def setPassword(self, password):
        self.password = password

    ##
    # @brief 这是管理员的登陆函数
    #
    # @retval 返回 LOGIN_ERROR 即登陆失败,返回 LOGIN_OUT 即主动退出登陆,返回 LOGIN_SUCCESS 即登陆成功
    ##
    def loginIn(self):
        root_account = self.account 
        if root_account != 'root':
            return LOGIN_ERROR
        while True:
            print("输入密码")
            password = input()
            self.setPassword(password)
            root_password = self.password
            if root_password != 'helloword':
                sign_in.myPrint("密码错误,重新输入请输入 1 ,否则视为终止登陆")
                signal = input()
                if signal != '1':
                    return LOGIN_OUT
                else:
                    self.setPassword(input())
            else:
                return LOGIN_SUCCESS_ROOT

