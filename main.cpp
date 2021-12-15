#include "sign_in.h"
#include "commodity.h"
#include "shopping_cart.h"


int main()
{
    std::map<std::string,std::string> b_user;
    b_user.insert(std::pair<std::string,std::string>("root","helloword"));

    int a  = Sign_In(b_user);
    if(a == 250 || a == 0)
    {
        return 0;
    }
   /* while(1)
    {
            
    } */ 
}