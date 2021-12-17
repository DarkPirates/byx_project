#include "shopping_cart.h"


//增加一个物品
void Increase(std::map<std::string,int> &something,Commodity_Fruit a)
{
    something.insert(std::pair<std::string,int>(a.GetName(a),a.GetPrice(a)));
}

void Increase(std::map<std::string,int> &something,Commodity_Clothes a)
{
    something.insert(std::pair<std::string,int>(a.GetName(a),a.GetPrice(a)));
}

void Increase(std::map<std::string,int> &something,Commodity_Furniture a)
{
    something.insert(std::pair<std::string,int>(a.GetName(a),a.GetPrice(a)));
}

void Increase(std::map<std::string,int> &something,Commodity_Vegetables a)
{
    something.insert(std::pair<std::string,int>(a.GetName(a),a.GetPrice(a)));
}

//删除一个物品
int Reduce(std::map<std::string,int> &something,std::string name)
{
    std::map<std::string,int>::iterator iter;
    iter = something.find(name);
    something.erase(iter);
}

//改？改个屁，不准改，重新选择
//查?没啥好查的啊。。。。那就把结算一起写了好了
//好像也没啥好写的，那就遍历一遍吧
/*
    如果是想做到那个选择多个购物车中的物品的话
    就得再弄一个map去储存选中的那一些商品，这样的话
    比较麻烦（主要是我懒得写），那就要么全买
    要么呢，就当场结账，不佳入购物车
*/
int Settlement(std::map<std::string,int> &something)
{
    for(std::map<std::string,int>::iterator iter = something.begin();iter != something.end();++iter)
    {
        std::cout << iter ->first << " " << iter ->second << std::endl;
    }
}