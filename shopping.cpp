#include "shopping.h"
#include <vector>
//这里定义的数字大多用于返回值,或者是用于区分用户输入,以便给出相应的动作
const int ZERO      =       0;
const int ONE       =       1;
const int TWO       =       2;
const int THREE     =       3;
const int FOUR      =       4;
const int ONE_      =      -1;
const int LT        =   10010;
const int YD        =   10086;


//这个容器用来保存用户的地址,一个用户分配6个位置吧,用完就没了
//std::vector<std::string> b_addrss;


int InspectNum_R(Commodity_Fruit &a)
{
    return a.GetQuantity();
}

int InspectNum(Commodity_Vegetables &a)
{
    return a.GetQuantity();
}

int InspectNum_F(Commodity_Furniture &a)
{
    return a.GetQuantity();
}

int InspectNum_C(Commodity_Clothes &a)
{
    return a.GetQuantity();
}

int Inspect(std::map<std::string,int> &my_shoppint_cart,Commodity_Vegetables &a,int c)
{
    int b = InspectNum(a);
    if(b == ZERO)
    {
        std::cout << "卖完了" << std::endl;
        return ONE_;
    }
    if(c == TWO)
    {
        std::cout << "操作成功" << std::endl;
        a.SetQuantity(b - ONE); 
    }
    else if(c == ONE)
    {
        Increase(my_shoppint_cart,a);
        a.SetQuantity(b - ONE); 
    }
}

int Inspect_R(std::map<std::string,int> &my_shoppint_cart,Commodity_Fruit &a,int c)
{
    int b = InspectNum_R(a);
    if(b == ZERO)
    {
        std::cout << "卖完了" << std::endl;
        return ONE_;
    }
    if(c == TWO)
    {
        std::cout << "操作成功" << std::endl;
        a.SetQuantity(b - ONE); 
    }
    else if(c == ONE)
    {
        Increase(my_shoppint_cart,a);
        a.SetQuantity(b - ONE);
    }
}

int Inspect_F(std::map<std::string,int> &my_shoppint_cart,Commodity_Furniture &a,int c)
{
    int b = InspectNum_F(a);
    if(b == ZERO)
    {
        std::cout << "卖完了" << std::endl;
        return ONE_;
    }
    if(c == TWO)
    {
        std::cout << "操作成功" << std::endl;
        a.SetQuantity(b - ONE); 
    }
    else if(c == ONE)
    {
        Increase(my_shoppint_cart,a);
        a.SetQuantity(b - ONE);
    }
}

int Inspect_C(std::map<std::string,int> &my_shoppint_cart,Commodity_Clothes &a,int c)
{
    int b = InspectNum_C(a);
    if(b == ZERO)
    {
        std::cout << "卖完了" << std::endl;
        return ONE_;
    }
    if(c == TWO)
    {
        std::cout << "操作成功" << std::endl;
        a.SetQuantity(b - ONE); 
    }
    else if(c == ONE)
    {
        Increase(my_shoppint_cart,a);
        a.SetQuantity(b - ONE);
    }
}

int Shopping(
            std::vector<Commodity_Fruit> &b_FU,
            std::vector<Commodity_Vegetables> &b_VT,
            std::vector<Commodity_Furniture> &b_FI,
            std::vector<Commodity_Clothes> &b_CT,
            std::map<std::string,int> &my_shoppint_cart
            )
{
    while(ONE)
    {
        int flag = 0;
        int choice = 0;
        std::cout << "选择你需要的种类,输入10010有特别选项" << std::endl;
        std::cout << "1.水果类" << " " << "2.蔬菜类" << " " << "3.家具类" << " " << "4.衣服类" << std::endl;
        std::cin >> flag;
        if(flag == ZERO)
        {
            return ZERO;
        }
        //冗长的构造商品的代码。。。。
        Commodity_Fruit apple("21.12.1",1);                
        apple.SetNmae_("apple");
        apple.SetPrice_(3);
        apple.SetQuantity(2);

        Commodity_Fruit banana("21.12.1",1);
        banana.SetNmae_("Banana");
        banana.SetPrice_(2);
        banana.SetQuantity(1);

        Commodity_Fruit orange("22.1.1",1);
        orange.SetNmae_("orange");
        orange.SetPrice_(1);
        orange.SetQuantity(0);
        
        Commodity_Fruit durian("21.12.3",20);
        durian.SetNmae_("Durian");      
        durian.SetPrice_(100);  
        durian.SetQuantity(0);

        Commodity_Vegetables pepper(4);
        pepper.SetNmae_("pepper");
        pepper.SetPrice_(4);
        pepper.SetQuantity(6);

        Commodity_Vegetables potato(5);
        potato.SetNmae_("potato");
        potato.SetPrice_(2);
        potato.SetQuantity(1);

        Commodity_Vegetables tomato(3);
        tomato.SetNmae_("tomato");
        tomato.SetPrice_(3);
        tomato.SetQuantity(0);

        Commodity_Vegetables eggplant(6);
        eggplant.SetNmae_("eggplant");
        eggplant.SetPrice_(10);  
        eggplant.SetQuantity(0);

        Commodity_Furniture refrigerator(1,"nothing");
        refrigerator.SetNmae_("refrigerator");
        refrigerator.SetPrice_(5000);
        refrigerator.SetQuantity(0);

        Commodity_Furniture washing_machine(2,"nothing");
        washing_machine.SetNmae_("washing_machine");
        washing_machine.SetPrice_(1000);
        washing_machine.SetQuantity(1);

        Commodity_Furniture dishwasher(1,"nothing");
        dishwasher.SetNmae_("dishwasher");
        dishwasher.SetPrice_(1000);
        dishwasher.SetQuantity(9);

        Commodity_Furniture bookshelf(2,"wood");
        bookshelf.SetNmae_("bookshelf");
        bookshelf.SetPrice_(300);
        bookshelf.SetQuantity(2);

        Commodity_Clothes t_shirt("summer");
        t_shirt.SetNmae_("t_shirt");
        t_shirt.SetPrice_(30);
        t_shirt.SetQuantity(5);

        Commodity_Clothes peaked_cap("all");
        peaked_cap.SetNmae_("peaked_cap");
        peaked_cap.SetPrice_(40);
        peaked_cap.SetQuantity(0);

        Commodity_Clothes sweater("all");
        sweater.SetNmae_("sweater");
        sweater.SetPrice_(50);
        sweater.SetQuantity(0);

        Commodity_Clothes coat("=-=");
        coat.SetNmae_("coat");
        coat.SetPrice_(100);
        coat.SetQuantity(100000000);

        std::cout << "此分类有以下商品" << std::endl;
        if(flag == ONE)
        {
            loop:
            std::cout << "1.苹果" << " " << "2.香蕉" << " " << "3.橘子" << std::endl;
            std::cout << "4.榴莲" << " " << "nothing" << " " << "nothing"<< std::endl;
            std::cout << "输入你想要选择的编号" << std::endl;
            std::cin >> flag;
            if(flag > FOUR)
            {
                while(ONE)
                {
                    std::cout << "输入错误，重来" << std::endl;
                    std::cin >> flag;
                }
            }
            std::cout << "加入购物车（1）？还是立即购买呢（2）？" << std::endl;
            std::cin >> choice;
            if(choice > TWO || choice < ONE)
            {
                return ZERO;
            }
            if(choice == TWO)
            {
                switch (flag)
                {
                case ONE:
                    Inspect_R(my_shoppint_cart,apple,choice);
                    break;
                case TWO:
                    Inspect_R(my_shoppint_cart,banana,choice);
                    break;
                case THREE:
                    Inspect_R(my_shoppint_cart,orange,choice);
                    break;
                case FOUR:
                    Inspect_R(my_shoppint_cart,durian,choice);
                    break;
                default:
                   return ZERO;
                }
            }
            else if(choice == ONE)
            {
                switch (flag)
                {
                case ONE:
                    Inspect_R(my_shoppint_cart,apple,choice);
                    break;
                case TWO:
                    Inspect_R(my_shoppint_cart,banana,choice);
                    break;
                case THREE:
                    Inspect_R(my_shoppint_cart,orange,choice);
                    break;
                case FOUR:
                    Inspect_R(my_shoppint_cart,durian,choice);
                    break;
                default:
                    return ZERO;
                }
            }
            top:
            sert:
            std::cout << "结算（1）,返回上层（2），返回类别（3）" << std::endl;
            std::cin >> flag;
            if(flag == ONE)
            {
                my_shoppint_cart.erase(my_shoppint_cart.begin(),my_shoppint_cart.end());
                std::cout << "确定么，需要删除就输入2" << std::endl;
                std::cin >> flag;
                if(flag == ONE)
                {
                    Settlement(my_shoppint_cart);
                }
                else if(flag == TWO)
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
            else if(flag == TWO)
            {
                goto loop;
            }  
            else if(flag == THREE)
            {
                continue;
            }          
        }
        else if(flag == TWO)
        {
          loop_:
            std::cout << "1.辣椒" << " " << "2.土豆" << " " << "3.西红柿" << std::endl;
            std::cout << "4.茄子" << " " << "nothing" << " " << "nothing"<< std::endl;
            std::cout << "输入你想要选择的编号" << std::endl;
            std::cin >> flag;
            if(flag > FOUR)
            {
                while(ONE)
                {
                    std::cout << "输入错误，重来" << std::endl;
                    std::cin >> flag;
                }
            }
            std::cout << "加入购物车（1）？还是立即购买呢（2）？" << std::endl;
            std::cin >> choice;
            if(choice > TWO || choice < ONE)
            {
                return ZERO;
            }
            if(choice == TWO)
            {
                switch (flag)
                {
                case ONE:
                    Inspect(my_shoppint_cart,pepper,choice);
                    break;
                case TWO:
                    Inspect(my_shoppint_cart,potato,choice);
                    break;
                case THREE:
                    Inspect(my_shoppint_cart,tomato,choice);
                    break;
                case FOUR:
                    Inspect(my_shoppint_cart,eggplant,choice);
                    break;
                default:
                   return ZERO;
                }
            }
            else if(choice == ONE)
            {
                switch (flag)
                {
                case ONE:
                    Inspect(my_shoppint_cart,pepper,choice);
                    break;
                case TWO:
                    Inspect(my_shoppint_cart,potato,choice);
                    break;
                case THREE:
                    Inspect(my_shoppint_cart,tomato,choice);
                    break;
                case FOUR:
                    Inspect(my_shoppint_cart,eggplant,choice);
                    break;
                default:
                    break;
                }
            }
            top_:
            sert_:
            std::cout << "结算（1）,返回上层（2），返回类别（3）" << std::endl;
            std::cin >> flag;
            if(flag == ONE)
            {
                Settlement(my_shoppint_cart);
                std::cout << "确定么，需要删除就输入2" << std::endl;
                std::cin >> flag;
                if(flag == ONE)
                {
                    Settlement(my_shoppint_cart);
                    /*if(b_addrss.size() == ZERO)
                    {
                        std::cout << "没地址.请输入你的地址捏" << std::endl;
                        std::string m_addrss;
                        std::cin >> m_addrss;
                        b_addrss.push_back(m_addrss);
                    }
                    for(int i = ZERO;i < b_addrss.size();++i)
                        std::cout << b_addrss[i] << std::endl;
                    while(ONE)
                    {
                        std::cout << "是哪个呢?,需要增加(10010)或者删除(10086)吗?" << std::endl;
                        std::cin >> flag;
                        if(flag == LT)
                        {
                            std::cout << "请输入你的地址捏" << std::endl;
                            std::string m_addrss;
                            std::cin >> m_addrss;
                            b_addrss.push_back(m_addrss);
                        }
                        if(flag == YD)
                        {
                            std::cout << "请输入地址捏" << std::endl;
                            std::string m_addrss;
                            std::cin >> m_addrss;
                            for(int i = ZERO;i < b_addrss.size();++i)
                            {
                                if(b_addrss[i] == m_addrss)
                                {
                                    b_addrss.erase(b_addrss.begin() + i);
                                }
                            }
                        }
                        if(flag >= ZERO && flag <= FOUR)
                        {
                            std::cout << "ok" << std::endl;
                            break;
                        }
                    }*/
                    
                }
                else if(flag == TWO)
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
            else if(flag == TWO)
            {
                goto loop_;
            }  
            else if(flag == TWO)
            {
                continue;
            }            
        }
        else if(flag == THREE)
        {
            loop_one:
            std::cout << "1.冰箱" << " " << "2.洗衣机" << " " << "3.洗碗机" << std::endl;
            std::cout << "4.书架" << " " << "nothing" << " " << "nothing"<< std::endl;
            std::cout << "输入你想要选择的编号" << std::endl;
            std::cin >> flag;
            if(flag > FOUR)
            {
                while(ONE)
                {
                    std::cout << "输入错误，重来" << std::endl;
                    std::cin >> flag;
                }
            }
            std::cout << "加入购物车（1）？还是立即购买呢（2）？" << std::endl;
            std::cin >> choice;
            if(choice > TWO || choice < ONE)
            {
                return ZERO;
            }
            if(choice == TWO)
            {
                switch (flag)
                {
                case ONE:
                    Inspect_F(my_shoppint_cart,refrigerator,choice);
                    break;
                case TWO:
                    Inspect_F(my_shoppint_cart,washing_machine,choice);
                    break;
                case THREE:
                    Inspect_F(my_shoppint_cart,dishwasher,choice);
                    break;
                case FOUR:
                    Inspect_F(my_shoppint_cart,bookshelf,choice);
                    break;
                default:
                   return ZERO;
                }
            }
            else if(choice == ONE)
            {
                switch (flag)
                {
                case ONE:
                    Inspect_F(my_shoppint_cart,refrigerator,choice);
                    break;
                case TWO:
                    Inspect_F(my_shoppint_cart,washing_machine,choice);
                    break;
                case THREE:
                    Inspect_F(my_shoppint_cart,dishwasher,choice);
                    break;
                case FOUR:
                    Inspect_F(my_shoppint_cart,bookshelf,choice);
                    break;
                default:
                    return ZERO;
                }
            }
            top_one:
            sert_one:
            std::cout << "结算（1）,返回上层（2），返回类别（3）" << std::endl;
            std::cin >> flag;
            if(flag == ONE)
            {
                Settlement(my_shoppint_cart);
                std::cout << "确定么，需要删除就输入2" << std::endl;
                std::cin >> flag;
                if(flag == ONE)
                {
                    Settlement(my_shoppint_cart);
                    /*if(b_addrss.size() == ZERO)
                    {
                        std::cout << "没地址.请输入你的地址捏" << std::endl;
                        std::string m_addrss;
                        std::cin >> m_addrss;
                        b_addrss.push_back(m_addrss);
                    }
                    for(int i = ZERO;i < b_addrss.size();++i)
                        std::cout << b_addrss[i] << std::endl;
                    while(ONE)
                    {
                        std::cout << "是哪个呢?,需要增加(10010)或者删除(10086)吗?" << std::endl;
                        std::cin >> flag;
                        if(flag == LT)
                        {
                            std::cout << "请输入你的地址捏" << std::endl;
                            std::string m_addrss;
                            std::cin >> m_addrss;
                            b_addrss.push_back(m_addrss);
                        }
                        if(flag == YD)
                        {
                            std::cout << "请输入地址捏" << std::endl;
                            std::string m_addrss;
                            std::cin >> m_addrss;
                            for(int i = ZERO;i < b_addrss.size();++i)
                            {
                                if(b_addrss[i] == m_addrss)
                                {
                                    b_addrss.erase(b_addrss.begin() + i);
                                }
                            }
                        }
                        if(flag >= ZERO && flag <= FOUR)
                        {
                            std::cout << "ok" << std::endl;
                            break;
                        }
                    }
                    
                }*/
            }
            else if(flag == TWO)
            {
                goto loop_one;
            }  
            else if(flag == THREE)
            {
                continue;
            }            
        }

        else if(flag == FOUR)
        {
            loop_two:
            std::cout << "1.T恤" << " " << "2.鸭舌帽" << " " << "3.卫衣" << std::endl;
            std::cout << "4.外套" << " " << "nothing" << " " << "nothing"<< std::endl;
            std::cout << "输入你想要选择的编号" << std::endl;
            std::cin >> flag;
            if(flag > FOUR)
            {
                while(ONE)
                {
                    std::cout << "输入错误，重来" << std::endl;
                    std::cin >> flag;
                }
            }
            std::cout << "加入购物车（1）？还是立即购买呢（2）？" << std::endl;
            std::cin >> choice;
            if(choice > TWO || choice < ONE)
            {
                return ZERO;
            }
            if(choice == TWO)
            {
                switch (flag)
                {
                case ONE:
                    Inspect_C(my_shoppint_cart,t_shirt,choice);
                    break;
                case TWO:
                    Inspect_C(my_shoppint_cart,peaked_cap,choice);
                    break;
                case THREE:
                    Inspect_C(my_shoppint_cart,sweater,choice);
                    break;
                case FOUR:
                    Inspect_C(my_shoppint_cart,coat,choice);
                    break;
                default:
                   return ZERO;
                }
            }
            else if(choice == ONE)
            {
                switch (flag)
                {
                case ONE:
                    Inspect_C(my_shoppint_cart,t_shirt,choice);
                    break;
                case TWO:
                    Inspect_C(my_shoppint_cart,peaked_cap,choice);
                    break;
                case THREE:
                    Inspect_C(my_shoppint_cart,sweater,choice);
                    break;
                case FOUR:
                    Inspect_C(my_shoppint_cart,coat,choice);
                    break;
                default:
                    return ZERO;
                }
            }
            top_two:
            sert_two:
            std::cout << "结算（1）,返回上层（2），返回类别（3）" << std::endl;
            std::cin >> flag;
            if(flag == ONE)
            {
               Settlement(my_shoppint_cart);
                std::cout << "确定么，需要删除就输入2" << std::endl;
                std::cin >> flag;
                if(flag == ONE)
                {
                    Settlement(my_shoppint_cart);
                    /*if(b_addrss.size() == ZERO)
                    {
                        std::cout << "没地址.请输入你的地址捏" << std::endl;
                        std::string m_addrss;
                        std::cin >> m_addrss;
                        b_addrss.push_back(m_addrss);
                    }
                    for(int i = ZERO;i < b_addrss.size();++i)
                        std::cout << b_addrss[i] << std::endl;
                    while(ONE)
                    {
                        std::cout << "是哪个呢?,需要增加(10010)或者删除(10086)吗?" << std::endl;
                        std::cin >> flag;
                        if(flag == LT)
                        {
                            std::cout << "请输入你的地址捏" << std::endl;
                            std::string m_addrss;
                            std::cin >> m_addrss;
                            b_addrss.push_back(m_addrss);
                        }
                        if(flag == YD)
                        {
                            std::cout << "请输入地址捏" << std::endl;
                            std::string m_addrss;
                            std::cin >> m_addrss;
                            for(int i = ZERO;i < b_addrss.size();++i)
                            {
                                if(b_addrss[i] == m_addrss)
                                {
                                    b_addrss.erase(b_addrss.begin() + i);
                                }
                            }
                        }
                        if(flag >= ZERO && flag <= FOUR)
                        {
                            std::cout << "ok" << std::endl;
                            break;
                        }
                    }
                    
                }*/
                
            }
            else if(flag == TWO)
            {
                goto loop_two;
            }  
            else if(flag == THREE)
            {
                continue;
            }            
        }
        else if(flag == LT)
        {
            loop_three:
            //一个一个读取容器里边，如果都没有，那就退出
            //需要哪种就去对应种类的容器里面看.
            if((b_CT.size() == ZERO) && 
               (b_FI.size() == ZERO) &&
               (b_FU.size() == ZERO) &&
               (b_VT.size() == ZERO))
            {
                return ONE_;
            }
            else
            {
                std::cout << "1,2,3,4?" << std::endl;
                int flag;
                std::cin >> flag;
                if(flag == ONE)
                {
                    for(int i = ZERO;i < b_FU.size();++i)
                    {
                        std::cout << b_FU[i].GetName_() << "  " << b_FU[i].GetPrice_() << std::endl;
                    }
                    std::cout << "你要哪个呢=-=" << std::endl;
                    std::cin >> flag;
                    std::cout << "加入购物车?还是结算呢" << std::endl;
                    std::cin >> choice;
                    if(choice > TWO || choice < ONE)
                    {
                        return ZERO;
                    }
                    Inspect_R(my_shoppint_cart,b_FU[flag - 1],choice);
                    
                }
                if(flag == TWO)
                {
                    for(int i = ZERO;i < b_VT.size();++i)
                    {
                        std::cout << b_VT[i].GetName_() << "  " << b_VT[i].GetPrice_() << std::endl;
                    } 
                    std::cout << "你要哪个呢=-=" << std::endl;
                    std::cin >> flag;
                    std::cout << "加入购物车?还是结算呢" << std::endl;
                    std::cin >> choice;
                    if(choice > TWO || choice < ONE)
                    {
                        return ZERO;
                    }
                    Inspect(my_shoppint_cart,b_VT[flag - 1],choice);
                }
                if(flag == THREE)
                {
                    for(int i = ZERO;i < b_FI.size();++i)
                    {
                        std::cout << b_FI[i].GetName_() << "  " << b_FI[i].GetPrice_() << std::endl;
                    }
                    std::cout << "你要哪个呢=-=" << std::endl;
                    std::cin >> flag;
                    std::cout << "加入购物车?还是结算呢" << std::endl;
                    std::cin >> choice;
                    if(choice > TWO || choice < ONE)
                    {
                        return ZERO;
                    }
                    Inspect_F(my_shoppint_cart,b_FI[flag - 1],choice);
                }
                if(flag == FOUR)
                {
                    for(int i = ZERO;i < b_CT.size();++i)
                    {
                        std::cout << b_CT[i].GetName_() << "  " << b_CT[i].GetPrice_() << std::endl;
                    }
                    std::cout << "你要哪个呢=-=" << std::endl;
                    std::cin >> flag;
                    std::cout << "加入购物车?还是结算呢" << std::endl;
                    std::cin >> choice;
                    if(choice > TWO || choice < ONE)
                    {
                        return ZERO;
                    }
                    Inspect_C(my_shoppint_cart,b_CT[flag - 1],choice);
                }
                top_three:
                sert_three:
                std::cout << "结算（1）,返回上层（2），返回类别（3）" << std::endl;
                std::cin >> flag;
                if(flag == ONE)
                {
                   Settlement(my_shoppint_cart);
                    std::cout << "确定么，需要删除就输入2" << std::endl;
                    std::cin >> flag;
                    if(flag == ONE)
                    {
                        Settlement(my_shoppint_cart);
                       /* if(b_addrss.size() == ZERO)
                        {
                            std::cout << "没地址.请输入你的地址捏" << std::endl;
                            std::string m_addrss;
                            std::cin >> m_addrss;
                            b_addrss.push_back(m_addrss);
                        }
                        for(int i = ZERO;i < b_addrss.size();++i)
                            std::cout << b_addrss[i] << std::endl;
                        while(ONE)
                        {
                            std::cout << "是哪个呢?,需要增加(10010)或者删除(10086)吗?" << std::endl;
                            std::cin >> flag;
                            if(flag == LT)
                            {
                                std::cout << "请输入你的地址捏" << std::endl;
                                std::string m_addrss;
                                std::cin >> m_addrss;
                                b_addrss.push_back(m_addrss);
                            }
                            if(flag == YD)
                            {
                                std::cout << "请输入地址捏" << std::endl;
                                std::string m_addrss;
                                std::cin >> m_addrss;
                                for(int i = ZERO;i < b_addrss.size();++i)
                                {
                                    if(b_addrss[i] == m_addrss)
                                    {
                                        b_addrss.erase(b_addrss.begin() + i);
                                    }
                                }
                            }
                            if(flag >= ZERO && flag <= FOUR)
                            {
                                std::cout << "ok" << std::endl;
                                break;
                            }
                        }
                        
                    }*/
                }
                else if(flag == TWO)
                {
                    goto loop_three;
                }  
                else if(flag == THREE)
                {
                    continue;
                }    
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
    }
    }
}