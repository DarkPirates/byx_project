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

/*
    简单的遍历函数,用来把那个容器遍历一边,方便用户去管理
*/
int Settlement(std::map<std::string,int> &something)
{
    std::map<std::string,int>::iterator  it;
    for (it = something.begin(); it != something.end(); ++it)
    {
        std::cout  << it->first  << " ";
        std::cout  << it->second << std::endl;
    }
}