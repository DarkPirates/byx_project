#include "commodity.h"

Commodity::Commodity(int price,std::string name)
{
    m_price = price;
    m_name = name;
}

int Commodity::GetPrice(Commodity a)
{
    int price = m_price;
    return price;
}

std::string Commodity::GetName(Commodity a)
{
    std::string name = m_name;
    return name;
}

Commodity_Fruit::Commodity_Fruit(int exp,int manufacture)
{
    m_exp = exp;
    m_manufacture = manufacture;
}

int Commodity_Fruit::GetExp(Commodity_Fruit a)
{
    int exp = m_exp;
    return exp;
}

int Commodity_Fruit::GetManufacture(Commodity_Fruit a)
{
    int manufacture = m_manufacture;
    return manufacture;
}

Commodity_Vegetables::Commodity_Vegetables(int weight)
{
   m_weight = weight; 
}

int Commodity_Vegetables::GetWeight(Commodity_Vegetables a)
{
    int weight = m_weight;
    return weight;
}

Commodity_Furniture::Commodity_Furniture(int height,std::string material)
{
    m_height = height;
    m_material = material;
}

int Commodity_Furniture::GetHeight(Commodity_Furniture a)
{
    int height = m_height;
    return height;
}

std::string Commodity_Furniture::GetMaterial(Commodity_Furniture a)
{
    std::string material = m_material;
    return material;
}

Commodity_Clothes::Commodity_Clothes(std::string eason)
{
    m_eason = eason;
}

std::string Commodity_Clothes::GetEason(Commodity_Clothes a)
{
    std::string eason = m_eason;
    return eason;
}