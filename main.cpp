#include "sign_in.h"
#include "commodity.h"
#include "shopping_cart.h"
#include "shopping.h"
#include <vector>

const int ZERO      =   0;
const int ONE       =   1;
const int TWO       =   2;
const int THREE     =   3;
const int FOUR      =   4;
const int ONE_      =  -1;

int main()
{
    std::map<std::string,std::string> b_user;
    b_user.insert(std::pair<std::string,std::string>("root","helloword"));
    std::map<std::string,std::string> b_seller;
    b_seller.insert(std::pair<std::string,std::string>("byx","zhendehenshuai"));
    std::map<std::string,int> my_shoppint_cart;

    std::vector<Commodity_Fruit> b_FU;
    std::vector<Commodity_Vegetables> b_VT;
    std::vector<Commodity_Furniture> b_FI;
    std::vector<Commodity_Clothes> b_CT;

    int a  = Sign_In(b_user,b_seller);
    std::cout << a << std::endl;
    if(a == ZERO)
    {
        return ZERO;
    }
    if(a == TWO)
    {
        InitSe( 
            b_FU,b_VT,b_FI,b_CT
            );
    }
    else
        int b = Shopping(b_FU,b_VT,b_FI,b_CT,my_shoppint_cart);
   /* while(1)
    {
            
    } */ 
}