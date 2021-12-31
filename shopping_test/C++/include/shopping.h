#ifndef __SHOPPING_H__
#define __SHOPPING_H__

#include "commodity.h"
#include "shopping_cart_2.h"
#include "sign_in.h"
#include "seller.h"
#include <vector>
#include <string>

int Shopping(
            std::vector<Commodity_Fruit> &fruit_item,
            std::vector<Commodity_Vegetables> &vegetables_item,
            std::vector<Commodity_Furniture> &furniture_item,
            std::vector<Commodity_Clothes> &clothes_item,
            Shopping_cart_ my_shoppint_cart
    );


#endif
