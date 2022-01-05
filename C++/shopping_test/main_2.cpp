#include "sign_in.h"
#include "commodity.h"
#include "shopping_cart_2.h"
#include "shopping.h"
#include <vector>

const static int DON_T_GO_TO          =   0;
const static int DEAD_CYCLE           =   1;
const static int SELLER_RETURN        =   1;
const static int USER_RETURN          =   2;

//获取键盘输入决定是否继续
int go_On()
{
    int goon;
    std::cin >> goon;
    return goon;
}

int main()
{
    //这个是用户和商家用来保存帐号和密码的
    std::map<std::string,std::string> user_sign;
    std::map<std::string,std::string> seller_sign;

    //这个是用来存放商品的容器
    std::vector<Commodity_Fruit> fruit_item;
    std::vector<Commodity_Vegetables> vegetables_item;
    std::vector<Commodity_Furniture> furniture_item;
    std::vector<Commodity_Clothes> clothes_item;
    std::map<std::string,int> shoppint_cart_;

    user_sign.insert(std::pair<std::string,std::string>("root","helloword"));
    seller_sign.insert(std::pair<std::string,std::string>("root","helloword"));
    
    int return_value;

    while(DEAD_CYCLE)
    {
        int sign_in_return = sign_In(user_sign,seller_sign);
        if(sign_in_return == USER_RETURN)
        {
            return_value = Shopping(fruit_item,vegetables_item,furniture_item,clothes_item,shoppint_cart_);
        }
        else if(sign_in_return == SELLER_RETURN)
        {
            return_value = Business(fruit_item,vegetables_item,furniture_item,clothes_item);
        }
        int goon = go_On();
        if(!goon)
            break;
    }

}