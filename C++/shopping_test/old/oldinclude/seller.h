#ifndef __SELLER_H__
#define __SELLER_H__

#include "shopping.h"
#include "commodity.h"
#include "shopping_cart_2.h"
#include "sign_in.h"
#include <vector>
#include <string>

int InitSe( 
            std::vector<Commodity_Fruit> &b_FU,
            std::vector<Commodity_Vegetables> &b_VT,
            std::vector<Commodity_Furniture> &b_FI,
            std::vector<Commodity_Clothes> &b_CT
            );

int Business(   std::vector<Commodity_Fruit> &fruit_item,
                std::vector<Commodity_Vegetables> &vegetables_item,
                std::vector<Commodity_Furniture> &furniture_item,
                std::vector<Commodity_Clothes> &clothes_item);

#endif