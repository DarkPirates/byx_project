#ifndef __COMMODITY_H__
#define __COMMODITY_H__

#include <iostream>

class Commodity
{
    public:
        Commodity();
        ~Commodity();
        Commodity(int price,std::string commodity_name);
        int GetPrice();
        int GetQuantity();
        std::string GetName();
        virtual int SetQuantity(int new_quantity);
        virtual int SetPrice(int new_price);
        virtual std::string SetName(const std::string new_name);
    protected:
        int m_quantity;
        int m_price;
        std::string m_name;
};
        
class Commodity_Fruit : public Commodity
{   
    public:
        ~Commodity_Fruit();
        Commodity_Fruit(std::string exp,int manufacture);       
        
        int GetManufacture();
        int GetPrice_();
        int GetQuantity();
        int SetQuantity(int quantity);
	int SetPrice_(int price); 
	std::string GetExp();
        std::string GetName_();
        void SetNmae_(const std::string name);    
    protected:
        void SetNmae_One(const std::string name)
        {
            this ->m_name = name;
        }
    private:
        std::string m_exp;
        int m_manufacture;
};

class Commodity_Vegetables : public Commodity
{
    public:
        ~Commodity_Vegetables();
        Commodity_Vegetables(int weight);
        int GetWeight();
        int GetPrice_();        
        int GetQuantity();
        int SetQuantity(int quantity);
        int SetPrice_(int price); 
	std::string GetName_();
        void SetNmae_(const std::string name);
    protected:
        void SetNmae_One(const std::string name)
        {
            this ->m_name = name;
        }
    private:
        int m_weight;
};

class Commodity_Furniture : public Commodity
{
    public:
        Commodity_Furniture(int height,std::string material);
        int GetHeight();
        int GetPrice_();
        int GetQuantity();
        int SetQuantity(int quantity);
        int SetPrice_(int price); 
	std::string GetMaterial();
        std::string GetName_();
        void SetNmae_(const std::string name);    
    protected:
        void SetNmae_One(const std::string name)
        {
            this ->m_name = name;
        }
    private:
        int m_height;
        std::string m_material;
};

class Commodity_Clothes : public Commodity
{
    public:
        Commodity_Clothes(std::string eason);
        int GetPrice_();
        int GetQuantity();
        int SetQuantity(int quantity);
        int SetPrice_(int price);
	std::string GetName_();
	std::string GetEason(); 
        void SetNmae_(const std::string name);    
    protected:
        void SetNmae_One(const std::string name)
        {
            this ->m_name = name;
        }
    private:
        std::string m_eason;
};

#endif
