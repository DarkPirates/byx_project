#!/usr/bin/python3
# -*- coding:UTF-8 -*-
'''
def fib(n):
    a,b = 0,1
    while a < n:
        print(a,end=' ')
        a,b = b,a+b
    print()
c = int(input())
fib(c)




import sys
 
def fibonacci(n): # 生成器函数 - 斐波那契
    a, b, counter = 0, 1, 0
    while True:
        if (counter > n): 
            return
        yield a
        a, b = b, a + b
        counter += 1
f = fibonacci(10) # f 是一个迭代器，由生成器返回生成
 
while True:
    try:
        print (next(f), end=" ") # 为什么会直接运行a, b = b, a + b这一段,不是很明白....
    except StopIteration:
        sys.exit()





#问题大了...不理解生成器部分
import sys

def aggregate_test():
    test_a = {11, 21, 31}
    test_a.add(4);
    yield 1
    test_a.remove(11)
    print(test_a)
        
test_b = aggregate_test()
while True:
    try:
        print (next(test_b), end=" ")
    except StopIteration:
        sys.exit()
    




#函数部分:测试代码
def print_hello(x, *):
    print(x)

print_hello(1)





# pop列表输出最后一位,append在列表最后加元素,popleft出最开始的元素
# 通过以上语句可以用列表实现栈和队列

squares = [x**2 for x in range(10)]
print(squares)






print('We are the {} who say "{}!"'.format('knights', 'Ni'))

'''




'''

for x in range(1, 11):
    print(repr(x).rjust(2), repr(x*x).rjust(3), end=' ')
    # Note use of 'end' on previous line
    print(repr(x*x*x).rjust(4))


'''
a = "23"
print(int(a))
