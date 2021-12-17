#include "shopping.h"

int Shopping(std::map<std::string,int> &my_shoppint_cart)
{
    while(1)
    {
        int flag = 0;
        int choice = 0;
        std::cout << "选择你需要的种类" << std::endl;
        std::cout << "1.水果类" << " " << "2.蔬菜类" << " " << "3.家具类" << " " << "4.衣服类" << std::endl;
        std::cin >> flag;
        if(flag == 0)
        {
            return 0;
        }
        //冗长的构造商品的代码。。。。
        Commodity_Fruit apple("21.12.1",1);              
        apple.SetPrice(3);
        apple.SetName("apple");

        Commodity_Fruit banana("21.12.1",1);
        banana.SetName("Banana");
        banana.SetPrice(2);
        
        Commodity_Fruit orange("22.1.1",1);
        orange.SetName("orange");
        orange.SetPrice(1);
        
        Commodity_Fruit durian("21.12.3",20);
        durian.SetName("Durian");      
        durian.SetPrice(100);        
        
        std::cout << "此分类有以下商品" << std::endl;
        if(flag == 1)
        {
            loop:
            std::cout << "1.苹果" << " " << "2.香蕉" << " " << "3.橘子" << std::endl;
            std::cout << "4.榴莲" << " " << "nothing" << " " << "nothing"<< std::endl;
            std::cout << "输入你想要选择的编号" << std::endl;
            std::cin >> flag;
            if(flag > 4)
            {
                while(1)
                {
                    std::cout << "输入错误，重来" << std::endl;
                    std::cin >> flag;
                }
            }
            std::cout << "加入购物车（1）？还是立即购买呢（2）？" << std::endl;
            std::cin >> choice;
            if(choice == 2)
            {
                switch (flag)
                {
                case 1:
                    std::cout << "获得苹果一个" << std::endl;
                    break;
                case 2:
                    std::cout << "获得香蕉一个" << std::endl;
                    break;
                case 3:
                    std::cout << "获得橘子一个" << std::endl;
                    break;
                case 4:
                    std::cout << "获得榴莲一个" << std::endl;
                    break;
                default:
                   return 0;
                }
            }
            else if(choice == 1)
            {
                switch (flag)
                {
                case 1:
                    Increase(my_shoppint_cart,apple);
                    break;
                case 2:
                    Increase(my_shoppint_cart,banana);
                    break;
                case 3:
                    Increase(my_shoppint_cart,orange);
                    break;
                case 4:
                    Increase(my_shoppint_cart,durian);
                    break;
                default:
                    break;
                }
            }
            std::cout << "结算（1）,返回上层（2），返回类别（3）" << std::endl;
            std::cin >> flag;
            if(flag == 1)
            {
                Settlement(my_shoppint_cart);
                my_shoppint_cart.erase(my_shoppint_cart.begin(),my_shoppint_cart.end());
            }
            else if(flag == 2)
            {
                goto loop;
            }  
            else if(flag == 3)
            {
                return 3;
            }          
        }
        /*
        switch (flag)
        {
        case 1: 
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        }*/
    }
}