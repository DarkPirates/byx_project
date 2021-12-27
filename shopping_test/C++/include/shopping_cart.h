#ifndef __SHOPPING_CART_H__
#define __SHOPPING_CART_H__

/*
   应为容器哭比较好用,适合这一次的test
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
int Reduce(std::map<std::string,int> &something,std::string name);

//这里呢,是一个遍历函数,遍历map中的成员,也就是那个购物车
int Settlement(std::map<std::string,int> &something);



#endif