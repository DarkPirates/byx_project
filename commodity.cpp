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
    std::cout << "Commodity::Commodity" << std::endl;
}

Commodity::Commodity(int price,std::string name)
{
    std::cout << "Commodity::Commodity" << std::endl;
    m_price = price;
    m_name = name;
}

Commodity::~Commodity()
{
    std::cout << "free Commodity" << std::endl;
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
 * shuiguo
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
    std::cout << "free Commodity_Fruit" << std::endl;
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
 * 
 * 
 * 
 * **********************************************************************/

Commodity_Vegetables::Commodity_Vegetables(int weight)
{
    std::cout << "Commodity_Vegetables" << std::endl;
    m_weight = weight; 
}

int Commodity_Vegetables::GetWeight(Commodity_Vegetables &a)
{
    return m_weight;
}

Commodity_Furniture::Commodity_Furniture(int height,std::string material)
{
    std::cout << "Commodity_Furniture" << std::endl;
    m_height = height;
    m_material = material;
}

int Commodity_Furniture::GetHeight(Commodity_Furniture a)
{
    return m_height;
}

std::string Commodity_Furniture::GetMaterial(Commodity_Furniture &a)
{
    return m_material;
}

Commodity_Clothes::Commodity_Clothes(std::string eason)
{
    std::cout << "Commodity_Clothes" << std::endl;
    m_eason = eason;
}

std::string Commodity_Clothes::GetEason(Commodity_Clothes &a)
{
    return m_eason;
}


int main()
{
    Commodity_Fruit a("1",2);
    std::cout << a.GetPrice_() << std::endl;
    a.SetPrice_(2);
    std::cout << a.GetPrice_() << std::endl;
    a.SetNmae_("apple");
    std::cout << a.GetName_() << std::endl;
    //a.SetName_2("apple");

    //int b = a.GetPrice_2();
    //std::cout << b << std::endl;  
    //std::string c = a.GetName_2();       
    //std::cout << c << std::endl;
    
    //Commodity_Fruit d("2",2);
    // b.SetPrice(1);
    // std::cout << "123123" << std::endl;
   
    // b.SetName("ja");       
    // std::cout << b.GetPrice(b) << std::endl;
}