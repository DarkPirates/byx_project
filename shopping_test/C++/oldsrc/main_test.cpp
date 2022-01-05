
#include "shopping.h"
#include <vector>

const int ZERO      =   0;
const int ONE       =   1;
const int TWO       =   2;
const int THREE     =   3;
const int FOUR      =   4;
const int ONE_      =  -1;

//遍历vector容器的函数
void print_vector_fruit(std::vector<Commodity_Fruit> fruit_item)
{
    for(int i = 0;i < fruit_item.size();++i)
    {
        std::cout << fruit_item[i].GetName_() << std::endl;
    }
}

void print_vector_vegetables(std::vector<Commodity_Vegetables> vegetables_item)
{
    for(int i = 0;i < vegetables_item.size();++i)
    {
        std::cout << vegetables_item[i].GetName_() << std::endl;
    }
}

void print_vector_furniture(std::vector<Commodity_Furniture> furniture_item)
{
    for(int i = 0;i < furniture_item.size();++i)
    {
        std::cout << furniture_item[i].GetName_() << std::endl;
    }
}

void print_vector_clothes(std::vector<Commodity_Clothes> clothes_item)
{
    for(int i = 0;i < clothes_item.size();++i)
    {
        std::cout << clothes_item[i].GetName_() << std::endl;
    }
}

int main()
{
    std::vector<Commodity_Fruit> fruit_item;
    std::vector<Commodity_Vegetables> vegetables_item;
    std::vector<Commodity_Furniture> furniture_item;
    std::vector<Commodity_Clothes> clothes_item;
    InitSe(fruit_item,vegetables_item,furniture_item,clothes_item);
    print_vector_fruit(fruit_item);
    print_vector_vegetables(vegetables_item);
    print_vector_furniture(furniture_item);
    print_vector_clothes(clothes_item);
}