#ifndef __SHOPPING_H__
#define __SHOPPING_H__

#include "commodity.h"
#include "shopping_cart.h"
#include "sign_in.h"
#include "seller.h"
#include <vector>
#include <string>

int Shopping(
            std::vector<Commodity_Fruit> &b_FU,
            std::vector<Commodity_Vegetables> &b_VT,
            std::vector<Commodity_Furniture> &b_FI,
            std::vector<Commodity_Clothes> &b_CT,
            std::map<std::string,int> &my_shoppint_cart
    );


#endif
