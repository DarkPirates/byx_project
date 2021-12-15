#ifndef __COMMODITY_H__
#define __COMMODITY_H__

#include <iostream>

class Commodity
{
    public:
        Commodity();
        Commodity(int price,std::string name);
        int GetPrice(Commodity a);
        std::string GetName(Commodity a);
    private:
        int m_price;
        std::string m_name;
};

class Commodity_Fruit : public Commodity
{   
    public:
        Commodity_Fruit(int exp,int manufacture);
        int GetExp(Commodity_Fruit a);
        int GetManufacture(Commodity_Fruit a);
    private:
        int m_exp;
        int m_manufacture;
};

class Commodity_Vegetables : public Commodity
{
    public:
        Commodity_Vegetables(int weight);
        int GetWeight(Commodity_Vegetables a);
    private:
        int m_weight;
};

class Commodity_Furniture : public Commodity
{
    public:
        Commodity_Furniture(int height,std::string material);
        int GetHeight(Commodity_Furniture a);
        std::string GetMaterial(Commodity_Furniture a);
    private:
        int m_height;
        std::string m_material;
};

class Commodity_Clothes : public Commodity
{
    public:
        Commodity_Clothes(std::string eason);
        std::string GetEason(Commodity_Clothes a);
    private:
        std::string m_eason;
};

#endif