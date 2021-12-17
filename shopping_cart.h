#ifndef __SHOPPING_CART_H__
#define __SHOPPING_CART_H__

/*
    首先，这是一个购物车
    然后呢，他需要去储存一个物品的名字
    再来一个就是储存物品的价格
    再去实现一个存储物品的增删改查
    随时都能去访问这个购物车
    所以说，map就是一个很好的选择！
    很棒，还不用自己去写方法
    垃圾链表，容器才是真神
*/
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "commodity.h"

//增加一个物品
void Increase(std::map<std::string,int> &something,Commodity_Fruit a);
void Increase(std::map<std::string,int> &something,Commodity_Clothes a);
void Increase(std::map<std::string,int> &something,Commodity_Furniture a);
void Increase(std::map<std::string,int> &something,Commodity_Vegetables a);

//删除一个物品
int Reduce(std::map<std::string,int> &something);

//改？改个屁，不准改，重新去选择
//查?没啥好查的啊。。。。那就把结算一起写了好了
int Settlement(std::map<std::string,int> &something);



#endif