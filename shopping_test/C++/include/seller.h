#pragma once

#include "shopping.h"
#include "commodity.h"
#include "shopping_cart.h"
#include "sign_in.h"
#include <vector>
#include <string>

int InitSe( 
            std::vector<Commodity_Fruit> &b_FU,
            std::vector<Commodity_Vegetables> &b_VT,
            std::vector<Commodity_Furniture> &b_FI,
            std::vector<Commodity_Clothes> &b_CT
            );