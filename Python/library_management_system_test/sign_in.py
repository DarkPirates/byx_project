#!/usr/bin/python3
#-*-UTF-8-*-

'''
这个文件暂时废弃,被member类替代
'''

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
# @param output_information表示要输出的内容
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

'''
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
'''

#这个是用户登陆模块
def signIn():
    myPrint("是否需要注册账户")
    if int(obtainInput()) == NEED:
        registerAccounts()
    myPrint("开始登陆?")
    if int(obtainInput()) != NEED:
        return LOGIN_OUT
    storage_account = takeOutAccount()
    while True:
        myPrint("输入帐号密码")
        input_user_name = obtainInput()
        input_user_password = obtainInput()
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
                return LOGIN_ERROR
        else:
            return LOGIN_SUCCESS


#管理员登陆,因为管理员权限比较大,所以登陆检查应该更严格,图书馆的管理员一个应该就够了
def administratorsSign():
    myPrint("输入帐号和密码")
    input_user_name = obtainInput()
    while True:
        input_user_password = obtainInput()
        if input_user_name != "baiyixin":
            myPrint("帐号错误")
            return LOGIN_ERROR
        elif input_user_password != "helloword":
            myPrint("密码错误,是否继续")
            if obtainInput() != '继续':
                return LOGIN_ERROR
        else:
            return LOGIN_SUCCESS

#a = administratorsSign()
#myPrint(a)



