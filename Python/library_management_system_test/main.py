#!/usr/bin/python3
#-*-UTF-8-*-

import sign_in

import borrow

import administrators

from book import Book

from member import User

from member import administratorsClass

LOGIN_ERROR = -1
LOGIN_OUT = 0
DEFAULT = 0
END = 0
ROOT = 1
QUERY = 1
REGISTER = 1
RETURN_START = 1
LOGIN_SUCCESS_STUDENT = 1
BORROW = 2
LOGIN_SUCCESS_ROOT = 2
STUDENT = 2
RETURN = 3

def sign_Login():
    print("是否需要注册(1:注册,其他任意数字:退出)")
    sign_flag = input()
    return_value = DEFAULT
    if sign_flag == str(REGISTER):
        print("输入帐号")
        user_sign = User(input())
        return_value = user_sign.registerAccounts()
        if return_value == LOGIN_OUT:
            return END
    while True:
        print("是否需要登陆(选择 1.管理员 或者 2.学生)")
        sign_flag = input()
        if sign_flag == str(ROOT):
            print("输入管理员的帐号密码")
            root_sign = administratorsClass(input())
            return_value = root_sign.loginIn()
            return return_value
        elif sign_flag == str(STUDENT):
            print("输入学生的帐号")
            user_sign = User(input())
            return_value = user_sign.loginIn()
            return return_value
        else:
            print("你的选择输入错误,退出")
            return LOGIN_ERROR
    
##
#@brief 管理员函数
#
##
def rootJurisdiction():
    print("查询借阅记录(个人还是总体)还是对图书进行管理")   
    while True:
        root_input = input()
        if root_input == '总体':
            borrow.seeAllQuery()
        elif root_input == '个人':
            print("输入你要看得学生的用户名")
            borrow.seeQuery()
        elif root_input == '图书':
            print("你要怎么操作书?增删改书籍(书籍或者书本)?其他输入表示退出本层")
            while True:
                print("当前在选择更改目录")
                root_input = input()
                if root_input == '书籍':
                    while True:
                        print("当前在书籍类型目录")
                        root_input = input()
                        if root_input == '增加类型':
                            administrators.addBookType()
                        elif root_input == '减少类型':
                            administrators.deleteBookType()
                        elif root_input == '更改类型':
                            administrators.changeBookType()
                        else:
                            break
                elif root_input == '书本':
                    while True:
                        print("当前在书本目录")
                        root_input = input()
                        if root_input == '增加书本':
                            administrators.addBook()
                        elif root_input == '减少书本':
                            administrators.deleteBook()
                        elif root_input == '更改书本':
                            administrators.changeBook()
                        else:
                            break
                else:
                    break
        else:
            break

##
# @brief 这是学生的操作函数
#
#
##
def student():
    print("需要做什么? 1.查询 / 2.借阅 / 3.归还")
    while True:
        student_input = input()
        if student_input == str(QUERY):
            borrow.seeQuery()
            print("1.回到顶层 其他输入将会退出")
            student_input = input()
            if student_input == str(RETURN_START):
                continue
            else:
                break
        elif student_input == '归还':
            borrow.giveBack()
        elif student_input == '借阅':
            borrow.borrowBook()
        else:
            break      

##
# @brief 主函数
# 
# 
## 
def main():
    sign_return = sign_Login()
    if sign_return == LOGIN_SUCCESS_STUDENT:
        student()
    elif sign_return == LOGIN_SUCCESS_ROOT:
        rootJurisdiction()

if __name__ == '__main__':
    main()