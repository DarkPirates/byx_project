#ifndef __SHOPPING_CART_H__
#define __SHOPPING_CART_H__

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "commodity.h"
//#include "shopping_cart.h"
#include "sign_in.h"
#include "seller.h"
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "commodity.h"

class Shopping_cart_
{
    public:
        Shopping_cart_();
        void Increase_Fruit(std::map<std::string,int> &shopping_cart,Commodity_Fruit new_fruit);
        void Increase_Vegetables(std::map<std::string,int> &shopping_cart,Commodity_Vegetables new_vegetables);
        void Increase_Furniture(std::map<std::string,int> &shopping_cart,Commodity_Furniture new_furniture);
        void Increase_Clothes(std::map<std::string,int> &shopping_cart,Commodity_Clothes new_clothes);
        int Reduce(std::map<std::string,int> &shopping_cart,std::string name);
        int Settlement(std::map<std::string,int> &shopping_cart);
        
};

/*
    Increase函数是给对应的类别增加成员没有返回值.直接加入了对应的容器

    Reduce是一个删除函数,将对应容器中的成员删除

    Settlement是将这个容器遍历一边,在清算购物车时能用上
*/

#endif
