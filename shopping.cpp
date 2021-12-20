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
        
        apple.SetNmae_("apple");
        apple.SetPrice_(3);

        Commodity_Fruit banana("21.12.1",1);
        banana.SetNmae_("Banana");
        banana.SetPrice_(2);
        
        Commodity_Fruit orange("22.1.1",1);
        orange.SetNmae_("orange");
        orange.SetPrice_(1);
        
        Commodity_Fruit durian("21.12.3",20);
        durian.SetNmae_("Durian");      
        durian.SetPrice_(100);  
        
        Commodity_Vegetables pepper(4);
        pepper.SetNmae_("pepper");
        pepper.SetPrice_(4);
        
        Commodity_Vegetables potato(5);
        potato.SetNmae_("potato");
        potato.SetPrice_(2);

        Commodity_Vegetables tomato(3);
        tomato.SetNmae_("tomato");
        tomato.SetPrice_(3);

        Commodity_Vegetables eggplant(6);
        eggplant.SetNmae_("eggplant");
        eggplant.SetPrice_(10);  

        Commodity_Furniture refrigerator(1,"nothing");
        refrigerator.SetNmae_("refrigerator");
        refrigerator.SetPrice_(5000);

        Commodity_Furniture washing_machine(2,"nothing");
        washing_machine.SetNmae_("washing_machine");
        washing_machine.SetPrice_(1000);

        Commodity_Furniture dishwasher(1,"nothing");
        dishwasher.SetNmae_("dishwasher");
        dishwasher.SetPrice_(1000);

        Commodity_Furniture bookshelf(2,"wood");
        bookshelf.SetNmae_("bookshelf");
        bookshelf.SetPrice_(300);

        Commodity_Clothes t_shirt("summer");
        t_shirt.SetNmae_("t_shirt");
        t_shirt.SetPrice_(30);

        Commodity_Clothes peaked_cap("all");
        peaked_cap.SetNmae_("peaked_cap");
        peaked_cap.SetPrice_(40);

        Commodity_Clothes sweater("all");
        sweater.SetNmae_("sweater");
        sweater.SetPrice_(50);

        Commodity_Clothes coat("=-=");
        coat.SetNmae_("coat");
        coat.SetPrice_(100);
        
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
                    Settlement(my_shoppint_cart);
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
            top:
            sert:
            std::cout << "结算（1）,返回上层（2），返回类别（3）" << std::endl;
            std::cin >> flag;
            if(flag == 1)
            {
                my_shoppint_cart.erase(my_shoppint_cart.begin(),my_shoppint_cart.end());
                std::cout << "确定么，需要删除就输入2？我也忘了" << std::endl;
                std::cin >> flag;
                if(flag == 1)
                {
                    Settlement(my_shoppint_cart);
                }
                else if(flag == 2)
                {
                    std::cout << "输入你要删除的名字" << std::endl;;
                    std::string _name;
                    std::cin >> _name;
                    Reduce(my_shoppint_cart,_name);
                    Settlement(my_shoppint_cart);
                    goto sert;
                }
                else
                {
                    goto top;
                }
                
            }
            else if(flag == 2)
            {
                goto loop;
            }  
            else if(flag == 3)
            {
                continue;
            }          
        }
        else if(flag == 2)
        {
          loop_:
            std::cout << "1.辣椒" << " " << "2.土豆" << " " << "3.西红柿" << std::endl;
            std::cout << "4.茄子" << " " << "nothing" << " " << "nothing"<< std::endl;
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
                    std::cout << "获得辣椒一个" << std::endl;
                    break;
                case 2:
                    std::cout << "获得土豆一个" << std::endl;
                    break;
                case 3:
                    std::cout << "获得西红柿一个" << std::endl;
                    break;
                case 4:
                    std::cout << "获得番茄一个" << std::endl;
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
                    Settlement(my_shoppint_cart);
                    Increase(my_shoppint_cart,pepper);
                    break;
                case 2:
                    Increase(my_shoppint_cart,potato);
                    break;
                case 3:
                    Increase(my_shoppint_cart,tomato);
                    break;
                case 4:
                    Increase(my_shoppint_cart,eggplant);
                    break;
                default:
                    break;
                }
            }
            top_:
            sert_:
            std::cout << "结算（1）,返回上层（2），返回类别（3）" << std::endl;
            std::cin >> flag;
            if(flag == 1)
            {
                Settlement(my_shoppint_cart);
                std::cout << "确定么，需要删除就输入2？我也忘了" << std::endl;
                std::cin >> flag;
                if(flag == 1)
                {
                    Settlement(my_shoppint_cart);
                }
                else if(flag == 2)
                {
                    std::cout << "输入你要删除的名字" << std::endl;;
                    std::string _name;
                    std::cin >> _name;
                    Reduce(my_shoppint_cart,_name);
                    Settlement(my_shoppint_cart);
                    goto sert_;
                }
                else
                {
                    goto top_;
                }
                
            }
            else if(flag == 2)
            {
                goto loop_;
            }  
            else if(flag == 3)
            {
                continue;
            }            
        }
        else if(flag == 3)
        {
            loop_one:
            std::cout << "1.冰箱" << " " << "2.洗衣机" << " " << "3.洗碗机" << std::endl;
            std::cout << "4.书架" << " " << "nothing" << " " << "nothing"<< std::endl;
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
                    std::cout << "获得冰箱一个" << std::endl;
                    break;
                case 2:
                    std::cout << "获得洗衣机一个" << std::endl;
                    break;
                case 3:
                    std::cout << "获得洗碗机一个" << std::endl;
                    break;
                case 4:
                    std::cout << "获得书架一个" << std::endl;
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
                    Settlement(my_shoppint_cart);
                    Increase(my_shoppint_cart,refrigerator);
                    break;
                case 2:
                    Increase(my_shoppint_cart,washing_machine);
                    break;
                case 3:
                    Increase(my_shoppint_cart,dishwasher);
                    break;
                case 4:
                    Increase(my_shoppint_cart,bookshelf);
                    break;
                default:
                    break;
                }
            }
            top_one:
            sert_one:
            std::cout << "结算（1）,返回上层（2），返回类别（3）" << std::endl;
            std::cin >> flag;
            if(flag == 1)
            {
                Settlement(my_shoppint_cart);
                std::cout << "确定么，需要删除就输入2？我也忘了" << std::endl;
                std::cin >> flag;
                if(flag == 1)
                {
                    Settlement(my_shoppint_cart);
                }
                else if(flag == 2)
                {
                    std::cout << "输入你要删除的名字" << std::endl;;
                    std::string _name;
                    std::cin >> _name;
                    Reduce(my_shoppint_cart,_name);
                    Settlement(my_shoppint_cart);
                    goto sert_one;
                }
                else
                {
                    goto top_one;
                }
                
            }
            else if(flag == 2)
            {
                goto loop_one;
            }  
            else if(flag == 3)
            {
                continue;
            }            
        }

        else if(flag == 4)
        {
            loop_two:
            std::cout << "1.T恤" << " " << "2.鸭舌帽" << " " << "3.卫衣" << std::endl;
            std::cout << "4.外套" << " " << "nothing" << " " << "nothing"<< std::endl;
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
                    std::cout << "获得T恤一个" << std::endl;
                    break;
                case 2:
                    std::cout << "获得鸭舌帽一个" << std::endl;
                    break;
                case 3:
                    std::cout << "获得卫衣一个" << std::endl;
                    break;
                case 4:
                    std::cout << "获得外套一个" << std::endl;
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
                    Settlement(my_shoppint_cart);
                    Increase(my_shoppint_cart,t_shirt);
                    break;
                case 2:
                    Increase(my_shoppint_cart,peaked_cap);
                    break;
                case 3:
                    Increase(my_shoppint_cart,sweater);
                    break;
                case 4:
                    Increase(my_shoppint_cart,coat);
                    break;
                default:
                    break;
                }
            }
            top_two:
            sert_two:
            std::cout << "结算（1）,返回上层（2），返回类别（3）" << std::endl;
            std::cin >> flag;
            if(flag == 1)
            {
                Settlement(my_shoppint_cart);
                std::cout << "确定么，需要删除就输入2？我也忘了" << std::endl;
                std::cin >> flag;
                if(flag == 1)
                {
                    Settlement(my_shoppint_cart);
                }
                else if(flag == 2)
                {
                    std::cout << "输入你要删除的名字" << std::endl;;
                    std::string _name;
                    std::cin >> _name;
                    Reduce(my_shoppint_cart,_name);
                    Settlement(my_shoppint_cart);
                    goto sert_two;
                }
                else
                {
                    goto top_two;
                }
                
            }
            else if(flag == 2)
            {
                goto loop_two;
            }  
            else if(flag == 3)
            {
                continue;
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