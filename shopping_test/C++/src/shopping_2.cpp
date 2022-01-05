#include "shopping.h"

//这里定义的数字大多用于返回值,或者是用于区分用户输入,以便给出相应的动作
const static int PROGRAM_INTERRUPT     =  -1;
const static int NO_HAVE               =   0;	//没有了
const static int DON_T_CONTINUE        =   0;	//不跳过
const static int IN_SHOPPING_CART      =   1; 	//加入购物车
const static int NEWLY_ADDED           =   1;   //新增地址
const static int GO_ON                 =   1;	//继续
const static int DEAD_CYLUE            =   1;	//死循环
const static int FRUIT_TYPE            =   1;	//水果类
const static int MODE_1_FRUIT          =   1; 	//水果模式
const static int DELETE_ADDRSS         =   2;   //删除地址
const static int MODE_2_VEGETABLES     =   2;	//蔬菜模式
const static int VEGETABLES_TYPE       =   2;	//蔬菜类
const static int SETTLEMENT            =   2;	//商户
const static int FURNITURE_TYPE        =   3;	//家具类
const static int MODE_3_FURNITURE      =   3;	//家具模式
const static int CLOTHES_TYPE          =   4;	//衣服类
const static int MODE_4_CLOTHES        =   4;	//衣服模式



//输出函数
void std_cout(std::string in_a_word)
{
    std::cout << in_a_word << std::endl;
}
 

//这个容器用来保存用户的地址
std::vector<std::string> user_addrss;

//新增地址
void newly_Added(std::vector<std::string> &user_addrss)
{
    std::string addrss_input = "";
    std_cout("输入地址:");
    std::cin >> addrss_input;
    user_addrss.push_back(addrss_input);
}

void delete_Addrss(std::vector<std::string> &user_addrss)
{
    int addrss_input = -2;
    std_cout("删除第几个呢");
    std::cin >> addrss_input;
    std::vector<std::string>::iterator it = user_addrss.begin() + addrss_input;
    user_addrss.erase(it);
}

//选择配送地址
int distribution_Address(std::vector<std::string> &user_addrss)
{
    int choice = -2;
    for(int i = 0;i < user_addrss.size();i++)
        std::cout << user_addrss[i] << std::endl;
    std::cin >> choice;
    if(choice == NO_HAVE)
    {
        std_cout("选择第几个地址?");
        std::cin >> choice;
        if(choice == NEWLY_ADDED)
            newly_Added(user_addrss);
        else if(choice == DELETE_ADDRSS)
            delete_Addrss(user_addrss);
    }
    std::cout << "地址选择完成" <<std::endl;
}

//构造一个购物车的类
Shopping_cart_ use_shopping_cart;

int InspectNum_R(Commodity_Fruit &fruit)
{
    return fruit.GetQuantity();
}

int InspectNum(Commodity_Vegetables &vegetable)
{
    return vegetable.GetQuantity();
}

int InspectNum_F(Commodity_Furniture &furniture)
{
    return furniture.GetQuantity();
}

int InspectNum_C(Commodity_Clothes &clothes)
{
    return clothes.GetQuantity();
}

//蔬菜购买
int Inspect(std::map<std::string,int> &shoppint_cart,Commodity_Vegetables &vegetables_in,int user_input_signal)
{  
    int surplus = InspectNum(vegetables_in);
    if(surplus == NO_HAVE)
    {
        std_cout("没货了");
        return PROGRAM_INTERRUPT;
    }
    if(user_input_signal == SETTLEMENT)
    {
        distribution_Address(user_addrss);
        std_cout("操作成功");
        //这里-1是因为被购买了一件,所以需要把数量-1
        vegetables_in.SetQuantity(surplus - 1); 
    }
    else if(user_input_signal == IN_SHOPPING_CART)
    {
        distribution_Address(user_addrss);
        use_shopping_cart.Increase_Vegetables(shoppint_cart,vegetables_in);
        //这里-1是因为被购买了一件,所以需要把数量-1
        vegetables_in.SetQuantity(surplus - 1); 
    }
}

//水果购买
int Inspect_R(std::map<std::string,int> &shoppint_cart,Commodity_Fruit &fruit_in,int user_input_signal)
{  
    int surplus = InspectNum_R(fruit_in);
    if(surplus == NO_HAVE)
    {
        std_cout("没货了");
        return PROGRAM_INTERRUPT;
    }
    if(user_input_signal == SETTLEMENT)
    {
        distribution_Address(user_addrss);
        std_cout("操作成功");
        //这里-1是因为被购买了一件,所以需要把数量-1
        fruit_in.SetQuantity(surplus - 1); 
    }
    else if(user_input_signal == IN_SHOPPING_CART)
    {
        distribution_Address(user_addrss);
        use_shopping_cart.Increase_Fruit(shoppint_cart,fruit_in);
        //这里-1是因为被购买了一件,所以需要把数量-1
        fruit_in.SetQuantity(surplus - 1);
    }
}

//家具购买
int Inspect_F(std::map<std::string,int> &shoppint_cart,Commodity_Furniture &furniture_in,int user_input_signal)
{  
    int surplus = InspectNum_F(furniture_in);
    if(surplus == NO_HAVE)
    {
        std_cout("没货了");
        return PROGRAM_INTERRUPT;
    }
    if(user_input_signal == SETTLEMENT)
    {
        distribution_Address(user_addrss);
        std_cout("操作成功");
        //这里-1是因为被购买了一件,所以需要把数量-1
        furniture_in.SetQuantity(surplus - 1); 
    }
    else if(user_input_signal == IN_SHOPPING_CART)
    {
        distribution_Address(user_addrss);
        use_shopping_cart.Increase_Furniture(shoppint_cart,furniture_in);
        //这里-1是因为被购买了一件,所以需要把数量-1
        furniture_in.SetQuantity(surplus - 1);
    }
}

//衣服购买
int Inspect_C(std::map<std::string,int> &shoppint_cart,Commodity_Clothes &clothes_in,int user_input_signal)
{  
    int surplus = InspectNum_C(clothes_in);
    if(surplus == NO_HAVE)
    {
        std_cout("没货了");
        return PROGRAM_INTERRUPT;
    }
    if(user_input_signal == SETTLEMENT)
    {
        distribution_Address(user_addrss);
        std_cout("操作成功");
        //这里-1是因为被购买了一件,所以需要把数量-1
        clothes_in.SetQuantity(surplus - 1); 
    }
    else if(user_input_signal == IN_SHOPPING_CART)
    {
        distribution_Address(user_addrss);
        use_shopping_cart.Increase_Clothes(shoppint_cart,clothes_in);
        //这里-1是因为被购买了一件,所以需要把数量-1
        clothes_in.SetQuantity(surplus - 1);
    }
}
/*************************************
 * 
 * 
 * 
 * 
 * 
 * ***********************************/
//出错函数
void error_In()
{
    std_cout("输入出错");
}

/**************************************
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * *////////////////////////////////

//获得用户输入,用于选择类型
int user_In_Mode()
{
    int user_in = -2;
    std_cout("选择商品类,水果,蔬菜,家具,衣服");
    std::cin >> user_in;
    if(user_in == MODE_1_FRUIT)
        return MODE_1_FRUIT;
    else if(user_in == MODE_2_VEGETABLES)
        return MODE_2_VEGETABLES;
    else if(user_in == MODE_3_FURNITURE)
        return MODE_3_FURNITURE;
    else if(user_in == MODE_4_CLOTHES)
        return MODE_4_CLOTHES;
    else
        error_In();
}

//一个遍历(水果)vector容器的函数
void ergodic_Vector_Fruit(std::vector<Commodity_Fruit> &commodity_item)
{
    for(int i = 0;i < commodity_item.size();++i)
    {
        std::cout << commodity_item[i].GetName_() << "  " << commodity_item[i].GetPrice_() << std::endl;
    }
}

//一个遍历(蔬菜)vector容器的函数
void ergodic_Vector_Vegetables(std::vector<Commodity_Vegetables> &commodity_item)
{
    for(int i = 0;i < commodity_item.size();++i)
    {
        std::cout << commodity_item[i].GetName_() << "  " << commodity_item[i].GetPrice_() << std::endl;
    }
}

//一个遍历(家具)vector容器的函数
void ergodic_Vector_Furniture(std::vector<Commodity_Furniture> &commodity_item)
{
    for(int i = 0;i < commodity_item.size();++i)
    {
        std::cout << commodity_item[i].GetName_() << "  " << commodity_item[i].GetPrice_() << std::endl;
    }
}

//一个遍历(衣服)vector容器的函数
void ergodic_Vector_Clothes(std::vector<Commodity_Clothes> &commodity_item)
{
    for(int i = 0;i < commodity_item.size();++i)
    {
        std::cout << commodity_item[i].GetName_() << "  " << commodity_item[i].GetPrice_() << std::endl;
    }
}

//这是一个选择第几个的函数
int user_Choice_Commodity()
{
    std_cout("需要第几个");
    int user_in = -2;
    std::cin >> user_in;
    return user_in;
}

//这是一个选择结算还是加入购物车的函数
int user_Choice_Settlement()
{
    int user_in = -2;
    std::cin >> user_in;
    if(user_in != SETTLEMENT && user_in != IN_SHOPPING_CART)
    {
        error_In();
        return PROGRAM_INTERRUPT;
    }
    return user_in;
}

//选择是否继续
int keep_On()
{
    int in_user = -2;
    std::cin >> in_user;
    return in_user;
}

//模式1.是选择了水果
void mode_Fruit(std::vector<Commodity_Fruit> &fruit_item,std::map<std::string,int> &shoppint_cart)
{
    while(DEAD_CYLUE)
    {
        ergodic_Vector_Fruit(fruit_item);
        Inspect_R(shoppint_cart,fruit_item[user_Choice_Commodity()],user_Choice_Settlement()); 
        int keep_on_flag = keep_On();
        if(!keep_on_flag)
        {
            break;
        }
    }
}

//模式2.是选择了蔬菜
void mode_Vegetables(std::vector<Commodity_Vegetables> &vegetables_item,std::map<std::string,int> &shoppint_cart)
{
    while(DEAD_CYLUE)
    {
        ergodic_Vector_Vegetables(vegetables_item);
        Inspect(shoppint_cart,vegetables_item[user_Choice_Commodity()],user_Choice_Settlement()); 
        int keep_on_flag = keep_On();
        if(!keep_on_flag)
        {
            break;
        }
    }
    
}

//模式3.是选择了家具
void mode_Furniture(std::vector<Commodity_Furniture> &furniture_item,std::map<std::string,int> &shoppint_cart)
{
    while(DEAD_CYLUE)
    {
        ergodic_Vector_Furniture(furniture_item);
        Inspect_F(shoppint_cart,furniture_item[user_Choice_Commodity()],user_Choice_Settlement());
        int keep_on_flag = keep_On();
        if(!keep_on_flag)
        {
            break;
        }
    }
}

//模式4.是选择了衣服
void mode_Clothes(std::vector<Commodity_Clothes> &clothes_item,std::map<std::string,int> &shoppint_cart)
{
    while(DEAD_CYLUE)
    {
        ergodic_Vector_Clothes(clothes_item);
        Inspect_C(shoppint_cart,clothes_item[user_Choice_Commodity()],user_Choice_Settlement());
        int keep_on_flag = keep_On();
        if(!keep_on_flag)
        {
            break;
        }
    }
}

int Shopping(
                std::vector<Commodity_Fruit> &fruit_item,
                std::vector<Commodity_Vegetables> &vegetables_item,
                std::vector<Commodity_Furniture> &furniture_item,
                std::vector<Commodity_Clothes> &clothes_item,
                std::map<std::string,int> &shoppint_cart
            )
{      
    user_addrss.push_back("=-=");
    while(DEAD_CYLUE)
    {
        int mode_choice = user_In_Mode();
        if (mode_choice == MODE_1_FRUIT)
            mode_Fruit(fruit_item,shoppint_cart);
        else if(mode_choice == MODE_2_VEGETABLES)
            mode_Vegetables(vegetables_item,shoppint_cart);
        else if(mode_choice == MODE_3_FURNITURE)
            mode_Furniture(furniture_item,shoppint_cart);
        else if(mode_choice == MODE_4_CLOTHES)
            mode_Clothes(clothes_item,shoppint_cart);
        else
        {
           error_In();
           break; 
        }
    }
}
