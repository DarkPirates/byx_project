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
static const int find_error            =  -1;//没找到
static const int success               =   1;//操作成功
static const int change_commodity      =   3;//改动商品

//出错函数
static void error_In()
{
    std::cout << "输入错误!" << std::endl;
}


//这个呢,就是一个简单的根据用户输入来判断是否继续的程序
//继续就返回true,不继续就返回false
static int go_On()
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
int delete_Fruit(std::vector<Commodity_Fruit> &fruit_item)
{
    std::string input_name = obtain_Commodity_Name();
    int i = 0;
    for(i;i < fruit_item.size();++i)
    {       
        if(fruit_item[i].GetName_() == input_name)
        {
            fruit_item.erase(fruit_item.begin() + i);
        }
    } 
    if(fruit_item[i].GetName_() != input_name)  
    {
        return find_error;
    }  
}

//删除蔬菜
int delete_Vegetables(std::vector<Commodity_Vegetables> &vegetables_item)
{
    std::string input_name = obtain_Commodity_Name();
    int i = 0;
    for(i;i < vegetables_item.size();++i)
    {       
        if(vegetables_item[i].GetName_() == input_name)
        {
            vegetables_item.erase(vegetables_item.begin() + i);
        }
    }  
    if(vegetables_item[i].GetName_() != input_name)  
    {
        return find_error;
    } 
}

//删除家具
int delete_Furniture(std::vector<Commodity_Furniture> &furniture_item)
{
    std::string input_name = obtain_Commodity_Name();
    int i = 0;
    for(i;i < furniture_item.size();++i)
    {       
        if(furniture_item[i].GetName_() == input_name)
        {
            furniture_item.erase(furniture_item.begin() + i);
        }
    }   
    if(furniture_item[i].GetName_() != input_name)  
    {
        return find_error;
    }
}

//删除衣服
int delete_Clothes(std::vector<Commodity_Clothes> &clothes_item)
{
    std::string input_name = obtain_Commodity_Name();
    int i = 0;
    for(i;i < clothes_item.size();++i)
    {       
        if(clothes_item[i].GetName_() == input_name)
        {
            clothes_item.erase(clothes_item.begin() + i);
        }
    } 
    if(clothes_item[i].GetName_() != input_name)  
    {
        return find_error;
    }
}

//删除要用到的模块写完了,开始写总体
int delete_Choice( std::vector<Commodity_Fruit> &fruit_item,
                    std::vector<Commodity_Vegetables> &vegetables_item,
                    std::vector<Commodity_Furniture> &furniture_item,
                    std::vector<Commodity_Clothes> &clothes_item)
{
    int commodity_type,input_go_on,return_value;
    while (dead_cycle)
    {
        std::cin >> commodity_type;
        if(commodity_type == fruit_type)
            return_value = delete_Fruit(fruit_item);
        else if(commodity_type == vegetables_type)
            return_value = delete_Vegetables(vegetables_item);
        else if(commodity_type == furniture_type)
            return_value = delete_Furniture(furniture_item);
        else if(commodity_type == clothes_type)
            return_value = delete_Clothes(clothes_item);
        else if(commodity_type == don_t_continue)
            break;
        else
            error_In();  
        if(return_value == find_error)
        {
            std::cout << "没找到你所需要的商品,是否继续?" << std::endl;
            std::cin >> input_go_on;
            if(input_go_on == don_t_continue)
                return don_t_continue;
        }
        else
        {
            std::cout << "是否继续?" << std::endl;
            std::cin >> input_go_on;
            if(input_go_on == don_t_continue)
                return don_t_continue;
        }
    }
    
}

//改变水果类
int change_Fruit(std::vector<Commodity_Fruit> &fruit_item,std::string name,
                  int price,int number)
{
    int i = 0;//遍历中循环要用的变量
    for(i = 0;i < fruit_item.size();++i)
    {       
        if(fruit_item[i].GetName_() == name)
        {
            fruit_item[i].SetPrice_(price);
            fruit_item[i].SetQuantity(number);
            return success;
        }
    }
    if(fruit_item[i].GetName_() != name)
    {
        return find_error;
    }
}

//改变蔬菜类
int change_Vegetable(std::vector<Commodity_Vegetables> &vegetables_item,std::string name,
                  int price,int number)
{
    int i = 0;
    for(i;i < vegetables_item.size();++i)
    {       
        if(vegetables_item[i].GetName_() == name)
        {
            vegetables_item[i].SetPrice_(price);
            vegetables_item[i].SetQuantity(number);
            return success;
        }
    }
    if(vegetables_item[i].GetName_() != name)
    {
        return find_error;
    }
}

//改变家具类
int change_Furniture(std::vector<Commodity_Furniture> &furniture_item,std::string name,
                  int price,int number)
{
    int i = 0;
    for(i;i < furniture_item.size();++i)
    {       
        if(furniture_item[i].GetName_() == name)
        {
            furniture_item[i].SetPrice_(price);
            furniture_item[i].SetQuantity(number);
            return success;
        }
    }
    if(furniture_item[i].GetName_() != name)
    {
        return find_error;
    }
}

//改变衣服类
int change_Clothes(std::vector<Commodity_Clothes> &clothes_item,std::string name,
                  int price,int number)
{
    int i = 0;
    for(i;i < clothes_item.size();++i)
    {       
        if(clothes_item[i].GetName_() == name)
        {
            clothes_item[i].SetPrice_(price);
            clothes_item[i].SetQuantity(number);
            return success;
        }
    }
    if(clothes_item[i].GetName_() != name)
    {
        return find_error;
    }
}

int change_Commodity(std::vector<Commodity_Fruit> &fruit_item,
                      std::vector<Commodity_Vegetables> &vegetables_item,
                      std::vector<Commodity_Furniture> &furniture_item,
                      std::vector<Commodity_Clothes> &clothes_item)
{
    int input_type,price,number,input_go_on;
    std::string name;
    int return_value;
    while(dead_cycle)
    {
        std::cin >> input_type >> name >> price >> number;
        if(input_type == fruit_type)
            return_value = change_Fruit(fruit_item,name,price,number);
        else if(input_type == vegetables_type)
            return_value = change_Vegetable(vegetables_item,name,price,number);
        else if(input_type == furniture_type)
            return_value = change_Furniture(furniture_item,name,price,number);
        else if(input_type == clothes_type)
            return_value = change_Clothes(clothes_item,name,price,number);
        else
            error_In();
        if(return_value == find_error)
        {
            std::cout << "没找到你所需要的商品,是否继续?" << std::endl;
            std::cin >> input_go_on;
            if(input_go_on == don_t_continue)
                return don_t_continue;
        }
        else
        {
            std::cout << "是否继续?" << std::endl;
            std::cin >> input_go_on;
            if(input_go_on == don_t_continue)
                return don_t_continue;
        }
    }
}

//商家选择怎么操作,是增加还是删除还是对已有的商品进行改动
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
        std::cout << "选做要做的操作,1增加,2删除,3更改" << std::endl;
        int user_input_flag = increase_Or_Delete();
        if(user_input_flag == increase_commodity)
            insert_Item(fruit_item,vegetables_item,furniture_item,clothes_item);
        if(user_input_flag == delete_commodity)
            delete_Choice(fruit_item,vegetables_item,furniture_item,clothes_item);
        if(user_input_flag == change_commodity)
            change_Commodity(fruit_item,vegetables_item,furniture_item,clothes_item);
        if(user_input_flag == sign_out)
            return sign_out;
    }
}
