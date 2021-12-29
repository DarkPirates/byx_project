#include "shopping.h"
#include <vector>

//这里定义的数字大多用于返回值,或者是用于区分用户输入,以便给出相应的动作
static const int ZERO      =       0;
static const int ONE       =       1;
static const int TWO       =       2;
static const int THREE     =       3;
static const int FOUR      =       4;
static const int ONE_      =      -1;
static const int LT        =   10010;
static const int YD        =   10086;
static const int in_shopping_cart      =   1; 	//加入购物车
static const int settlement            =   2;	//商户
static const int no_have               =   0;	//没有了
static const int program_interrupt     =  -1;	//程序中断
static const int go_on                 =   1;	//继续
static const int don_t_continue        =   0;	//不跳过
static const int dead_cycle            =   1;	//死循环
static const int fruit_type            =   1;	//水果类
static const int vegetables_type       =   2;	//蔬菜类
static const int furniture_type        =   3;	//家具类
static const int clothes_type          =   4;	//衣服类
static const int mode_1_fruit          =   1; 	//水果模式
static const int mode_2_vegetables     =   2;	//蔬菜模式
static const int mode_3_furniture      =   3;	//家具模式
static const int mode_4_clothes        =   4;	//衣服模式


//这个容器用来保存用户的地址,一个用户分配6个位置吧,用完就没了
std::vector<std::string> user_addrss;


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
    if(surplus == no_have)
    {
        std::cout << "卖完了" << std::endl;
        return program_interrupt;
    }
    if(user_input_signal == settlement)
    {
        std::cout << "操作成功" << std::endl;
        //这里-1是因为被购买了一件,所以需要把数量-1
        vegetables_in.SetQuantity(surplus - 1); 
    }
    else if(user_input_signal == in_shopping_cart)
    {
        Increase(shoppint_cart,vegetables_in);
        //这里-1是因为被购买了一件,所以需要把数量-1
        vegetables_in.SetQuantity(surplus - 1); 
    }
}

//水果购买
int Inspect_R(std::map<std::string,int> &shoppint_cart,Commodity_Fruit &fruit_in,int user_input_signal)
{
    int surplus = InspectNum_R(fruit_in);
    if(surplus == no_have)
    {
        std::cout << "卖完了" << std::endl;
        return program_interrupt;
    }
    if(user_input_signal == settlement)
    {
        std::cout << "操作成功" << std::endl;
        //这里-1是因为被购买了一件,所以需要把数量-1
        fruit_in.SetQuantity(surplus - 1); 
    }
    else if(user_input_signal == in_shopping_cart)
    {
        Increase(shoppint_cart,fruit_in);
        //这里-1是因为被购买了一件,所以需要把数量-1
        fruit_in.SetQuantity(surplus - 1);
    }
}

//家具购买
int Inspect_F(std::map<std::string,int> &shoppint_cart,Commodity_Furniture &furniture_in,int user_input_signal)
{
    int surplus = InspectNum_F(furniture_in);
    if(surplus == no_have)
    {
        std::cout << "卖完了" << std::endl;
        return program_interrupt;
    }
    if(user_input_signal == settlement)
    {
        std::cout << "操作成功" << std::endl;
        //这里-1是因为被购买了一件,所以需要把数量-1
        furniture_in.SetQuantity(surplus - 1); 
    }
    else if(user_input_signal == in_shopping_cart)
    {
        Increase(shoppint_cart,furniture_in);
        //这里-1是因为被购买了一件,所以需要把数量-1
        furniture_in.SetQuantity(surplus - 1);
    }
}

//衣服购买
int Inspect_C(std::map<std::string,int> &shoppint_cart,Commodity_Clothes &clothes_in,int user_input_signal)
{
    int surplus = InspectNum_C(clothes_in);
    if(surplus == ZERO)
    {
        std::cout << "卖完了" << std::endl;
        return program_interrupt;
    }
    if(user_input_signal == settlement)
    {
        std::cout << "操作成功" << std::endl;
        //这里-1是因为被购买了一件,所以需要把数量-1
        clothes_in.SetQuantity(surplus - 1); 
    }
    else if(user_input_signal == in_shopping_cart)
    {
        Increase(shoppint_cart,clothes_in);
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
    std::cout << "输入错误!" << std::endl;
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
    int user_in;
    std::cout << "输入你要什么类型,1水果,2蔬菜,3家具,4衣服" << std::endl;
    std::cin >> user_in;
    if(user_in == mode_1_fruit)
        return mode_1_fruit;
    else if(user_in == mode_2_vegetables)
        return mode_2_vegetables;
    else if(user_in == mode_3_furniture)
        return mode_3_furniture;
    else if(user_in == mode_4_clothes)
        return mode_4_clothes;
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
    std::cout << "你要第几个?" << std::endl;
    int user_in;
    std::cin >> user_in;
    return user_in;
}

//这是一个选择结算还是加入购物车的函数
int user_Choice_Settlement()
{
    int user_in;
    std::cin >> user_in;
    if(user_in != settlement && user_in != in_shopping_cart)
    {
        error_In();
        return program_interrupt;
    }
    return user_in;
}

//选择是否继续
int keep_On()
{
    int in_user;
    std::cin >> in_user;
    return in_user;
}

//模式1.是选择了水果
void mode_Fruit(std::vector<Commodity_Fruit> &fruit_item,std::map<std::string,int> &shoppint_cart)
{
    while(dead_cycle)
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
    while(dead_cycle)
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
    while(dead_cycle)
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
    while(dead_cycle)
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
    while(dead_cycle)
    {
        int mode_choice = user_In_Mode();
        if (mode_choice == mode_1_fruit)
            mode_Fruit(fruit_item,shoppint_cart);
        else if(mode_choice == mode_2_vegetables)
            mode_Vegetables(vegetables_item,shoppint_cart);
        else if(mode_choice == mode_3_furniture)
            mode_Furniture(furniture_item,shoppint_cart);
        else if(mode_choice == mode_4_clothes)
            mode_Clothes(clothes_item,shoppint_cart);
        else
        {
           error_In();
           break; 
        }
    }
}
