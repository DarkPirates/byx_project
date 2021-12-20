#include "sign_in.h"
#include "commodity.h"
#include "shopping_cart.h"
#include "shopping.h"


int main()
{
    std::map<std::string,std::string> b_user;
    b_user.insert(std::pair<std::string,std::string>("root","helloword"));
    std::map<std::string,int> my_shoppint_cart;
    int a  = Sign_In(b_user);
    if(a == 250 || a == 0)
    {
        return 0;
    }
    int b = Shopping(my_shoppint_cart);
   /* while(1)
    {
            
    } */ 
}