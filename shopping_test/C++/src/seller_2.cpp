#include "seller.h"

static const int go_on                 =   1; //继续
static const int don_t_continue        =   0;//不继续
static const int dead_cycle            =   1;//死循环
static const int fruit_type            =   1;//水果类型
static const int vegetables_type       =   2;//蔬菜类型
static const int furniture_type        =   3;//家具类型
static const int clothes_type          =   4;//衣服类型
static const int increase_commodity    =   1;//增加商品
static const int delete_commodity      =   0;//减少商品
static const int sign_out              =   0;//登陆失败

//出错函数
void error_In()
{
    std::cout << "输入错误!" << std::endl;
}


//这个呢,就是一个简单的根据用户输入来判断是否继续的程序
//继续就返回true,不继续就返回false
int go_On()
{
    int go_on_flag;
    std::cin >> go_on_flag;
    while(dead_cycle)
    {
        if(go_on_flag == go_on)
            return 1;
        else if(go_on_flag==don_t_continue)
            return 0;
        else
            error_In();
    }
}

//获取商户需要的商品名
std::string obtain_Commodity_Name()
{
    std::string name;
    std::cout << "输入你要删除的商品名" << std::endl;
    std::cin >> name;
    return name;
}

//这是一个插入水果的函数
void type_Fruit(std::vector<Commodity_Fruit> &fruit_item)
{
    int price,number,manufacture;
    std::string name,exp;
    std::cin >> price >> number >> manufacture >> name >> exp;
    Commodity_Fruit new_fruit(exp,manufacture);
    new_fruit.SetNmae_(name);
    new_fruit.SetPrice_(price);
    new_fruit.SetQuantity(number);
    fruit_item.push_back(new_fruit);
}

//这是一个插入蔬菜的函数
void type_Vegetables(std::vector<Commodity_Vegetables> &vegetables_item)
{
    int price,number,weight;
    std::string name;
    std::cin >> price >> number >> weight >> name;
    Commodity_Vegetables new_vegetables(weight);
    new_vegetables.SetNmae_(name);
    new_vegetables.SetPrice_(price);
    new_vegetables.SetQuantity(number);
    vegetables_item.push_back(new_vegetables);
}

//这是一个插入家具的函数
void type_Furniture(std::vector<Commodity_Furniture> &furniture_item)
{
    int price,number,height;
    std::string name,material;
    std::cin >> price >> number >> height >> name >> material;
    Commodity_Furniture new_furniture(height,material);
    new_furniture.SetNmae_(name);
    new_furniture.SetPrice_(price);
    new_furniture.SetQuantity(number);
    furniture_item.push_back(new_furniture);
}

//插入衣服函数
void type_Clothes(std::vector<Commodity_Clothes> &clothes_item)
{
    int price,number;
    std::string name,eason;
    std::cin >> price >> number >> name >> eason;
    Commodity_Clothes new_clothes(eason);
    new_clothes.SetNmae_(name);
    new_clothes.SetPrice_(price);
    new_clothes.SetQuantity(number);
    clothes_item.push_back(new_clothes);
}

//调用函数,调用所有的插入商品函数
int insert_Item(std::vector<Commodity_Fruit> &fruit_item,
                std::vector<Commodity_Vegetables> &vegetables_item,
                std::vector<Commodity_Furniture> &furniture_item,
                std::vector<Commodity_Clothes> &clothes_item)
{
    int commodity_type;
    while(dead_cycle)
    {
        std::cin >> commodity_type;
        if(commodity_type == fruit_type)
            type_Fruit(fruit_item);
        else if(commodity_type == vegetables_type)
            type_Vegetables(vegetables_item);
        else if(commodity_type == furniture_type)
            type_Furniture(furniture_item);
        else if(commodity_type == clothes_type)
            type_Clothes(clothes_item);
        else if(commodity_type == don_t_continue)
            break;
        else
            error_In();
    }
}

//感觉好像没什么用,下次看到记得测试,如果没用就删掉
int InitSe(std::vector<Commodity_Fruit> &fruit_item,
           std::vector<Commodity_Vegetables> &vegetables_item,
           std::vector<Commodity_Furniture> &furniture_item,
           std::vector<Commodity_Clothes> &clothes_item)
           {
               insert_Item(fruit_item,vegetables_item,furniture_item,clothes_item);
           }

//完了增加,就开始做删除函数

//首先应该是做小的模块
//删除水果
void delete_Fruit(std::vector<Commodity_Fruit> &fruit_item)
{
    std::string input_name = obtain_Commodity_Name();
    for(int i = 0;i < fruit_item.size();++i)
    {       
        if(fruit_item[i].GetName_() == input_name)
        {
            fruit_item.erase(fruit_item.begin() + i);
        }
    }   
}

//删除蔬菜
void delete_Vegetables(std::vector<Commodity_Vegetables> &vegetables_item)
{
    std::string input_name = obtain_Commodity_Name();
    for(int i = 0;i < vegetables_item.size();++i)
    {       
        if(vegetables_item[i].GetName_() == input_name)
        {
            vegetables_item.erase(vegetables_item.begin() + i);
        }
    }   
}

//删除家具
void delete_Furniture(std::vector<Commodity_Furniture> &furniture_item)
{
    std::string input_name = obtain_Commodity_Name();
    for(int i = 0;i < furniture_item.size();++i)
    {       
        if(furniture_item[i].GetName_() == input_name)
        {
            furniture_item.erase(furniture_item.begin() + i);
        }
    }   
}

//删除衣服
void delete_Clothes(std::vector<Commodity_Clothes> &clothes_item)
{
    std::string input_name = obtain_Commodity_Name();
    for(int i = 0;i < clothes_item.size();++i)
    {       
        if(clothes_item[i].GetName_() == input_name)
        {
            clothes_item.erase(clothes_item.begin() + i);
        }
    }   
}

//删除要用到的模块写完了,开始写总体
void delete_Choice( std::vector<Commodity_Fruit> &fruit_item,
                    std::vector<Commodity_Vegetables> &vegetables_item,
                    std::vector<Commodity_Furniture> &furniture_item,
                    std::vector<Commodity_Clothes> &clothes_item)
{
    int commodity_type;
    while (dead_cycle)
    {
        std::cin >> commodity_type;
        if(commodity_type == fruit_type)
            delete_Fruit(fruit_item);
        else if(commodity_type == vegetables_type)
            delete_Vegetables(vegetables_item);
        else if(commodity_type == furniture_type)
            delete_Furniture(furniture_item);
        else if(commodity_type == clothes_type)
            delete_Clothes(clothes_item);
        else if(commodity_type == don_t_continue)
            break;
        else
            error_In();  
    }
    
}

//商家选择怎么操作,是增加还是删除
int increase_Or_Delete()
{
    int user_input_flag;
    
    std::cin >> user_input_flag;
    if(user_input_flag == increase_commodity)
        return increase_commodity;
    else if(user_input_flag == delete_commodity)
        return delete_commodity;
    else
        error_In();
        return sign_out;
    
}

//然后就是商家要用的总流程
int Business(   std::vector<Commodity_Fruit> &fruit_item,
                std::vector<Commodity_Vegetables> &vegetables_item,
                std::vector<Commodity_Furniture> &furniture_item,
                std::vector<Commodity_Clothes> &clothes_item)
{
    while(dead_cycle)
    {
        int user_input_flag = increase_Or_Delete();
        if (user_input_flag == increase_commodity)
            insert_Item(fruit_item,vegetables_item,furniture_item,clothes_item);
        if (user_input_flag == delete_commodity)
            delete_Choice(fruit_item,vegetables_item,furniture_item,clothes_item);
        if(user_input_flag == sign_out)
            return sign_out;
    }
}
