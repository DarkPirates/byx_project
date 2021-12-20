#include "commodity.h"

/*************************************************************************
 * 
 *             基类
 * 
 * 
 * 
 * **********************************************************************/
Commodity::Commodity()
{

}

Commodity::Commodity(int price,std::string name)
{
    m_price = price;
    m_name = name;
}

Commodity::~Commodity()
{
}


int Commodity::GetPrice(Commodity &a)
{
    return a.m_price;
}

int Commodity::SetPrice(int b)
{
    std::cout << "1" << std::endl;
    m_price = b;
}

std::string Commodity::GetName(Commodity &a)
{
    return a.m_name;
}

std::string Commodity::SetName(const std::string b)
{
    m_name = b;
}

/*************************************************************************
 * 
 *             
 * fruit
 * 
 * 
 * **********************************************************************/


Commodity_Fruit::Commodity_Fruit(std::string exp,int manufacture)
{
    //P_N();
    m_exp = exp;
    m_manufacture = manufacture;
    std::cout << "Commodity_Fruit::Commodity_Fruit" << std::endl;
}

Commodity_Fruit::~Commodity_Fruit()
{
}

std::string Commodity_Fruit::GetExp(Commodity_Fruit a)
{
    return m_exp;
}

int Commodity_Fruit::GetPrice_()
{
    return m_price;
}

std::string Commodity_Fruit::GetName_()
{
    return m_name;
}

int Commodity_Fruit::SetPrice_(int a)
{ 
    this ->m_price = a;
}

void Commodity_Fruit::SetNmae_(const std::string name)
{
    SetNmae_One(name);
}

int Commodity_Fruit::GetManufacture(Commodity_Fruit a)
{
    return m_manufacture;
}

/*************************************************************************
 * 
 *  
 * Vegetables
 * 
 * 
 * **********************************************************************/

Commodity_Vegetables::Commodity_Vegetables(int weight)
{
    m_weight = weight; 
}

Commodity_Vegetables::~Commodity_Vegetables()
{
}

int Commodity_Vegetables::GetPrice_()
{
    return m_price;
}

std::string Commodity_Vegetables::GetName_()
{
    return m_name;
}

int Commodity_Vegetables::SetPrice_(int a)
{ 
    this ->m_price = a;
}

void Commodity_Vegetables::SetNmae_(const std::string name)
{
    SetNmae_One(name);
}

int Commodity_Vegetables::GetWeight(Commodity_Vegetables &a)
{
    return m_weight;
}


/*************************************************************************
 * 
 *  
 * 
 * 
 * 
 * **********************************************************************/

Commodity_Furniture::Commodity_Furniture(int height,std::string material)
{
    m_height = height;
    m_material = material;
}

int Commodity_Furniture::GetPrice_()
{
    return m_price;
}

std::string Commodity_Furniture::GetName_()
{
    return m_name;
}

int Commodity_Furniture::SetPrice_(int a)
{ 
    this ->m_price = a;
}

void Commodity_Furniture::SetNmae_(const std::string name)
{
    Commodity_Furniture::SetNmae_One(name);
}

int Commodity_Furniture::GetHeight(Commodity_Furniture a)
{
    return m_height;
}

std::string Commodity_Furniture::GetMaterial(Commodity_Furniture &a)
{
    return m_material;
}

/*************************************************************************
 * 
 *  
 * 
 * 
 * 
 * **********************************************************************/


Commodity_Clothes::Commodity_Clothes(std::string eason)
{
    std::cout << "Commodity_Clothes" << std::endl;
    m_eason = eason;
}
int Commodity_Clothes::GetPrice_()
{
    return m_price;
}

std::string Commodity_Clothes::GetName_()
{
    return m_name;
}

int Commodity_Clothes::SetPrice_(int a)
{ 
    this ->m_price = a;
}

void Commodity_Clothes::SetNmae_(const std::string name)
{
    SetNmae_One(name);
}
std::string Commodity_Clothes::GetEason(Commodity_Clothes &a)
{
    return m_eason;
}
