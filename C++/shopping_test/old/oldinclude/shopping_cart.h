#ifndef __SHOPPING_CART_H__
#define __SHOPPING_CART_H__

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

//遍历函数
int Settlement(std::map<std::string,int> &something);



#endif