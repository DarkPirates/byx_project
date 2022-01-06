#!/usr/bin/python3
#-*-UTF-8-*-

import json

#这是我自己的输入函数
def obtainInput():
    return input()

#这是我自己的输出函数
def myPrint(output_information):
    print(output_information)

#这是注册函数
def registerAccounts():
    fileUser = open('./用户数据','r+')                                       #这一行打开这个文件,并给予读写权限
    file_read = fileUser.read()                                             #file_read是表示读取出来的数据,此时是json类型
    json_read_dictionaries = json.loads(file_read)                          #这一行是将读取出来的json类型转换成字典
    myPrint("输入帐号,密码,用回车隔开")                                        #这里三行是对帐号注册时的名字与密码输入问题    
    user_name = obtainInput()                                                                  
    user_password = obtainInput()                  
    json_read_dictionaries[user_name] = user_password
    user_account_json = json.dumps(json_read_dictionaries)                  #这里是将用户的输入存入刚刚取出的字典中
    fileUser.seek(0)                                                        #移动光标到首字节,以便覆盖掉以前的,防止有多个字典,然后读取出错
    fileUser.write(user_account_json)                                       #写入文件中
    fileUser.close()                                                        #最后不要忘了关闭这个文件
    
def longinChoice():    

registerAccounts()

