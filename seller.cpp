#include "seller.h"

/*
    这几个const的整形，就是去避免使用魔幻数，大多用来作为返回值，以及
    手动输入的参数，分开来表示各种情况。
*/
const int ZERO      =   0;
const int ONE       =   1;
const int TWO       =   2;
const int THREE     =   3;
const int FOUR      =   4;
const int ONE_      =  -1;

//我需要初始化一个容器，来存放我上架好的东西，然后去把这个容器给到shopping
//这里就需要去写一个初始化的函数
int InitSe( 
            std::vector<Commodity_Fruit> &b_FU,
            std::vector<Commodity_Vegetables> &b_VT,
            std::vector<Commodity_Furniture> &b_FI,
            std::vector<Commodity_Clothes> &b_CT
            )
{
    while(ONE)
    {
        int u_price;
        int quantity;
        std::string u_name;
        std::cin >> u_name;
        std::cin >> u_price;
        //传进来空的容器，然后就应该去判断，要上架什么类型的产品，然后去弄相应的容器保存
        std::cout << "你想上架的是一个什么类型的产品呢？1,2,3,4对应水果，蔬菜，家具，服饰" << std::endl;
        int flag;//用来辨识商户输入，然后进行判断要存入哪一个容器
        std::cin >> flag;
        //首先就是这个水果，那么水果的就是，名字，价格，数量，日期,还有个参数忘了注释，不记得是啥了。
        if(flag == ONE)
        {
        std::cout << "输入参数，先生产日期，再重量？=-=,再来个数量" << std::endl;
        std::string m_exp;
        int m_manufacture;      
        std::cin >> m_exp;
        std::cin >> m_manufacture;
        std::cin >> quantity;
        Commodity_Fruit a(m_exp,m_manufacture);
        a.SetNmae_(u_name);
        a.SetPrice_(u_price);
        a.SetQuantity(quantity);
        b_FU.push_back(a);
        }
        //然后呢。。。就是蔬菜，蔬菜有重量。数量，名字，价格。
        else if(flag == TWO)
        {
            std::cout << "输入参数，重量和数量" << std::endl;
            int height;
            std::cin >> height;
            std::cin >> quantity;
            Commodity_Vegetables a(height);
            a.SetQuantity(quantity);
            a.SetPrice_(u_price);
            a.SetNmae_(u_name);
            b_VT.push_back(a);
        }
        //这是。。。家具，家具呢就写了一个高度，还有一个材质，大概就是做这样子。
        else if(flag == THREE)
        {
            std::cout << "输入参数：高度和材质" << std::endl;
            int height;
            std::string m_material;
            std::cin >> height >> m_material >> quantity;
            Commodity_Furniture a(height,m_material);
            a.SetQuantity(quantity);
            a.SetPrice_(u_price);
            a.SetNmae_(u_name);
            b_FI.push_back(a);
        }
        //这是服饰，衣服应该是只分季节吧，大概的话。。。
        else if(flag == FOUR)
        {
            std::cout << "输入参数：季节" << std::endl;
            std::string m_eason;
            std::cin >> m_eason >> quantity;
            Commodity_Clothes a(m_eason);
            a.SetQuantity(quantity);
            a.SetPrice_(u_price);
            a.SetNmae_(u_name);
            b_CT.push_back(a);
        }
        std::cout << "还有吗" << std::endl;
        std::cin >> flag;
        if(flag == ZERO)
        {
            break;
        }
    }
    

}