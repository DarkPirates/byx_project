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

int Commodity::GetPrice()
{
    return m_price;
}

int Commodity::GetQuantity()
{
    return m_quantity;
}

int Commodity::SetPrice(int new_price)
{
    m_price = new_price;
}

int Commodity::SetQuantity(int new_quantity)
{
    m_quantity = new_quantity;
}

std::string Commodity::GetName()
{
    return m_name;
}

std::string Commodity::SetName(const std::string new_name)
{
    m_name = new_name;
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


int Commodity_Fruit::GetPrice_()
{
    return m_price;
}



int Commodity_Fruit::GetQuantity()
{
    return m_quantity;
}

int Commodity_Fruit::SetQuantity(int quantity)
{
    m_quantity = quantity;
}

int Commodity_Fruit::SetPrice_(int price)
{ 
    this ->m_price = price;
}

int Commodity_Fruit::GetManufacture()
{
    return m_manufacture;
}

std::string Commodity_Fruit::GetExp()
{
    return m_exp;
}

std::string Commodity_Fruit::GetName_()
{
    return m_name;
}

void Commodity_Fruit::SetNmae_(const std::string name)
{
    SetNmae_One(name);
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



int Commodity_Vegetables::GetQuantity()
{
    return m_quantity;
}

int Commodity_Vegetables::SetQuantity(int quantity)
{
    m_quantity = quantity;
}

int Commodity_Vegetables::SetPrice_(int price)
{ 
    this ->m_price = price;
}

int Commodity_Vegetables::GetWeight()
{
    return m_weight;
}

std::string Commodity_Vegetables::GetName_()
{
    return m_name;
}

void Commodity_Vegetables::SetNmae_(const std::string name)
{
    SetNmae_One(name);
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

int Commodity_Furniture::SetPrice_(int price)
{ 
    m_price = price;
}

int Commodity_Furniture::GetQuantity()
{
    return m_quantity;
}

int Commodity_Furniture::SetQuantity(int quantity)
{
    m_quantity = quantity;
}

int Commodity_Furniture::GetHeight()
{
    return m_height;
}

std::string Commodity_Furniture::GetMaterial()
{
    return m_material;
}

std::string Commodity_Furniture::GetName_()
{
    return m_name;
}

void Commodity_Furniture::SetNmae_(const std::string name)
{
    Commodity_Furniture::SetNmae_One(name);
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

int Commodity_Clothes::GetQuantity()
{
    return m_quantity;
}

int Commodity_Clothes::SetQuantity(int quantity)
{
    m_quantity = quantity;
}

int Commodity_Clothes::SetPrice_(int price)
{ 
    this ->m_price = price;
}

std::string Commodity_Clothes::GetEason()
{
    return m_eason;
}

void Commodity_Clothes::SetNmae_(const std::string name)
{
    SetNmae_One(name);
}
