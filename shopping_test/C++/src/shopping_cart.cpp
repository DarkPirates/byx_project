#include "shopping_cart.h"
#include "shopping_cart_2.h"

//这个要改.得在类中增加一个map容器,不然不好写....

//增加一个物品,分别对应的是水果,蔬菜,家具,衣服
void Shopping_cart_::Increase(std::map<std::string,int> &shopping_cart,Commodity_Fruit new_fruit)
{
    shopping_cart.insert(std::pair<std::string,int>(new_fruit.GetName(new_fruit),new_fruit.GetPrice(new_fruit)));
}

void Shopping_cart_::Increase(std::map<std::string,int> &shopping_cart,Commodity_Vegetables new_vegetables)
{
    shopping_cart.insert(std::pair<std::string,int>(new_vegetables.GetName(new_vegetables),new_vegetables.GetPrice(new_vegetables)));
}

void Shopping_cart_::Increase(std::map<std::string,int> &shopping_cart,Commodity_Furniture new_furniture)
{
    shopping_cart.insert(std::pair<std::string,int>(new_furniture.GetName(new_furniture),new_furniture.GetPrice(new_furniture)));
}

void Shopping_cart_::Increase(std::map<std::string,int> &shopping_cart,Commodity_Clothes new_clothes)
{
    shopping_cart.insert(std::pair<std::string,int>(new_clothes.GetName(new_clothes),new_clothes.GetPrice(new_clothes)));
}


//删除一个物品从map容器中
int Shopping_cart_::Reduce(std::map<std::string,int> &shopping_cart,std::string name)
{
    std::map<std::string,int>::iterator iter;
    iter = shopping_cart.find(name);
    shopping_cart.erase(iter);
}

//这边是一个遍历函数,将传入的map容器遍历
int Shopping_cart_::Settlement(std::map<std::string,int> &shopping_cart)
{
    std::map<std::string,int>::iterator  it;
    for (it = shopping_cart.begin(); it != shopping_cart.end(); ++it)
    {
        std::cout  << it->first  << " ";
        std::cout  << it->second << std::endl;
    }
}