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
PERSONAR = 1
GOON = 1
ROOT = 1
QUERY = 1
REGISTER = 1
RETURN_START = 1
LOGIN_SUCCESS_STUDENT = 1
ADDTYPE = 1
ADDBOOK = 1
DELETEBOOK = 2
DELETETYPE = 2
BORROW = 2
BOOKNAME = 2
LOGIN_SUCCESS_ROOT = 2
STUDENT = 2
CHANGETYPE = 3
BOOKTYPE = 3
CHANGEBOOK = 3
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
# @brief 对书籍以及书本的管理(增删改)
#
##
def choiceBookOrType():
    print("你要怎么操作书?增删改书籍(3.书籍 / 2.书本)?其他输入表示退出本层")
    while True:
        print("当前在选择更改目录(3.书籍 / 2.书本)")
        root_input = int(input())
        if root_input == BOOKTYPE:
            while True:
                print("当前在书籍类型目录,1.增加 / 2.减少 / 3.更改 / 其他输入返回上一层")
                root_input = int(input())
                if root_input == ADDTYPE:
                    while True:
                        administrators.addBookType()
                        print("继续增加输入 1 ,否则返回上一层")
                        if int(input()) != GOON:
                            break
                elif root_input == DELETETYPE:
                    while True:
                        administrators.deleteBookType()
                        print("继续删除输入 1 ,否则返回上一层")
                        if int(input()) != GOON:
                            break
                elif root_input == CHANGETYPE:
                    while True:
                        administrators.changeBookType()
                        print("继续修改输入 1 ,否则返回上一层")
                        if int(input()) != GOON:
                            break
                else:
                    break
        elif root_input == BOOKNAME:
            while True:
                print("当前在书本目录")
                root_input = int(input())
                if root_input == ADDBOOK:
                    while True:
                        administrators.addBook()
                        print("继续增加输入 1 ,否则返回上一层")
                        if int(input()) != GOON:
                            break
                elif root_input == DELETEBOOK:
                    while True:
                        administrators.deleteBook()
                        print("继续增加输入 1 ,否则返回上一层")
                        if int(input()) != GOON:
                            break
                elif root_input == CHANGEBOOK:
                    while True:
                        administrators.changeBook()
                        print("继续增加输入 1 ,否则返回上一层")
                        if int(input()) != GOON:
                            break
                else:
                    break
        else:
            break

    
##
# @brief 管理员函数
#
##
def rootJurisdiction():
    print("查询借阅记录(1.个人 / 2.书本)还是对 3.图书 进行管理,其他输入表示退出本层")   
    while True:
        root_input = input()
        if int(root_input) == BOOKNAME:
            print("你要查询哪一本书的借阅记录,输入书名")
            input_book_name = input()
            borrow.seeAllQuery(input_book_name)
        elif int(root_input) == PERSONAR:
            print("输入你要看得学生的用户名")
            borrow.seeQuery()
        elif int(root_input) == BOOKTYPE:
            choiceBookOrType()
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
        print("当前在选择层 1.查询 / 2.借阅 / 3.归还 / 4.退出")
        student_input = input()
        if student_input == str(QUERY):
            borrow.seeQuery()
            print("1.回到顶层 其他输入将会退出")
            student_input = input()
            if student_input == str(RETURN_START):
                continue
            else:
                break
        elif student_input == str(BORROW):
            borrow.borrowBook()
        elif student_input == str(RETURN):
            while True:
                borrow.giveBack()
                print("是否要继续归还书本? 1.继续 其他输入默认退出归还")
                input_giveback_goon = input()
                if input_giveback_goon != GOON:
                    break
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