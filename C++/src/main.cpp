#include "sign_in.h"
#include "commodity.h"
#include "shopping_cart.h"
#include "shopping.h"


int main()
{
    std::map<std::string,std::string> b_user;
    b_user.insert(std::pair<std::string,std::string>("root","helloword"));
    std::map<std::string,std::string> b_seller;
    b_user.insert(std::pair<std::string,std::string>("byx","zhendehenshuai"));
    std::map<std::string,int> my_shoppint_cart;
    int a  = Sign_In(b_user,b_seller);
    if(a == 250 || a == 0)
    {
        return 0;
    }
    if(a == 2)
    {
        
    }
    else
        int b = Shopping(my_shoppint_cart);
   /* while(1)
    {
            
    } */ 
}