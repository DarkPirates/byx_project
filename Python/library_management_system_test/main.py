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
LOGIN_SUCCESS_STUDENT = 1
LOGIN_SUCCESS_ROOT = 2

def sign_Login():
    print("是否需要注册")
    sign_flag = input()
    return_value = DEFAULT
    if sign_flag == '是':
        print("输入帐号, id")
        user_sign = User(input(), input())
        return_value = user_sign.registerAccounts()
    print("是否需要登陆(管理员 / 学生)")
    sign_flag = input()
    if sign_flag == '管理员':
        print("输入帐号密码")
        root_sign = administratorsClass(input())
        return_value = root_sign.loginIn()
    elif sign_flag == '学生':
        print("输入帐号, id")
        user_sign = User(input(), input())
        return_value = user_sign.loginIn()
    return return_value

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
    print("需要做什么?查询 / 借阅 / 归还")
    while True:
        student_input = input()
        if student_input == '查询':
            borrow.seeQuery()
            print("回到顶层?")
            student_input = input()
            if student_input == '回到顶层':
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
    print(sign_return)

if __name__ == '__main__':
    main()