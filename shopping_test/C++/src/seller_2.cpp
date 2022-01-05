#include "seller.h"

const static int FIND_ERROR            =  -1;//没找到
const static int DELETE_COMMODITY      =   0;//减少商品
const static int SIGN_OUT              =   0;//登陆失败
const static int DON_T_CONTINUE        =   0;//不继续
const static int GO_ON                 =   1; //继续
const static int INCREASE_COMMODITY    =   1;//增加商品
const static int DEAD_CYCLE            =   1;//死循环
const static int FRUIT_TYPE            =   1;//水果类型
const static int SUCCESS               =   1;//操作成功
const static int VEGETABLES_TYPE       =   2;//蔬菜类型
const static int FURNITURE_TYPE        =   3;//家具类型
const static int CHANGE_COMMODITY      =   3;//改动商品
const static int CLOTHES_TYPE          =   4;//衣服类型

//输出函数
void std_cout(std::string in_a_word)
{
    std::cout << in_a_word << std::endl;
}

//出错函数
static void error_In()
{
    std_cout("输入出错");
}

//这个呢,就是一个简单的根据用户输入来判断是否继续的程序
//继续就返回true,不继续就返回false
static int go_On()
{
    int go_on_flag;
    std::cin >> go_on_flag;
    while(DEAD_CYCLE)
    {
        if(go_on_flag == GO_ON)
            return GO_ON;
        else if(go_on_flag==DON_T_CONTINUE)
            return DON_T_CONTINUE;
        else
            error_In();
    }
}

//获取商户需要的商品名
std::string obtain_Commodity_Name()
{
    std::string name;
    std_cout("输入商品名");
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
    while(DEAD_CYCLE)
    {
        std::cin >> commodity_type;
        if(commodity_type == FRUIT_TYPE)
            type_Fruit(fruit_item);
        else if(commodity_type == VEGETABLES_TYPE)
            type_Vegetables(vegetables_item);
        else if(commodity_type == FURNITURE_TYPE)
            type_Furniture(furniture_item);
        else if(commodity_type == CLOTHES_TYPE)
            type_Clothes(clothes_item);
        else if(commodity_type == DON_T_CONTINUE)
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
        return FIND_ERROR;
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
        return FIND_ERROR;
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
        return FIND_ERROR;
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
        return FIND_ERROR;
    }
}

//删除要用到的模块写完了,开始写总体
int delete_Choice( std::vector<Commodity_Fruit> &fruit_item,
                    std::vector<Commodity_Vegetables> &vegetables_item,
                    std::vector<Commodity_Furniture> &furniture_item,
                    std::vector<Commodity_Clothes> &clothes_item)
{
    int commodity_type,input_go_on,return_value;
    while (DEAD_CYCLE)
    {
        std::cin >> commodity_type;
        if(commodity_type == FRUIT_TYPE)
            return_value = delete_Fruit(fruit_item);
        else if(commodity_type == VEGETABLES_TYPE)
            return_value = delete_Vegetables(vegetables_item);
        else if(commodity_type == FURNITURE_TYPE)
            return_value = delete_Furniture(furniture_item);
        else if(commodity_type == CLOTHES_TYPE)
            return_value = delete_Clothes(clothes_item);
        else if(commodity_type == DON_T_CONTINUE)
            break;
        else
            error_In();  
        if(return_value == FIND_ERROR)
        {
            std_cout("没找到,是否继续");
            std::cin >> input_go_on;
            if(input_go_on == DON_T_CONTINUE)
                return DON_T_CONTINUE;
        }
        else
        {
            std_cout("是否继续");
            std::cin >> input_go_on;
            if(input_go_on == DON_T_CONTINUE)
            {
                return DON_T_CONTINUE;
            }
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
            return SUCCESS;
        }
    }
    if(fruit_item[i].GetName_() != name)
    {
        return FIND_ERROR;
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
            return SUCCESS;
        }
    }
    if(vegetables_item[i].GetName_() != name)
    {
        return FIND_ERROR;
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
            return SUCCESS;
        }
    }
    if(furniture_item[i].GetName_() != name)
    {
        return FIND_ERROR;
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
            return SUCCESS;
        }
    }
    if(clothes_item[i].GetName_() != name)
    {
        return FIND_ERROR;
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
    while(DEAD_CYCLE)
    {
        std::cin >> input_type >> name >> price >> number;
        if(input_type == FRUIT_TYPE)
            return_value = change_Fruit(fruit_item,name,price,number);
        else if(input_type == VEGETABLES_TYPE)
            return_value = change_Vegetable(vegetables_item,name,price,number);
        else if(input_type == FURNITURE_TYPE)
            return_value = change_Furniture(furniture_item,name,price,number);
        else if(input_type == CLOTHES_TYPE)
            return_value = change_Clothes(clothes_item,name,price,number);
        else
            error_In();
        if(return_value == FIND_ERROR)
        {
            std_cout("没找到,是否继续");
            std::cin >> input_go_on;
            if(input_go_on == DON_T_CONTINUE)
                return DON_T_CONTINUE;
        }
        else
        {
            std_cout("是否继续");
            std::cin >> input_go_on;
            if(input_go_on == DON_T_CONTINUE)
                return DON_T_CONTINUE;
        }
    }
}

//商家选择怎么操作,是增加还是删除还是对已有的商品进行改动
int increase_Or_Delete()
{
    int user_input_flag;
    
    std::cin >> user_input_flag;
    if(user_input_flag == INCREASE_COMMODITY)
        return INCREASE_COMMODITY;
    else if(user_input_flag == DELETE_COMMODITY)
        return DELETE_COMMODITY;
    
    else
        error_In();
        return SIGN_OUT;
    
}

//然后就是商家要用的总流程
int Business(   std::vector<Commodity_Fruit> &fruit_item,
                std::vector<Commodity_Vegetables> &vegetables_item,
                std::vector<Commodity_Furniture> &furniture_item,
                std::vector<Commodity_Clothes> &clothes_item)
{
    while(DEAD_CYCLE)
    {
        std_cout("输入:1,增加;2,删除;3,更改");
        int user_input_flag = increase_Or_Delete();
        if(user_input_flag == INCREASE_COMMODITY)
            insert_Item(fruit_item,vegetables_item,furniture_item,clothes_item);
        if(user_input_flag == DELETE_COMMODITY)
            delete_Choice(fruit_item,vegetables_item,furniture_item,clothes_item);
        if(user_input_flag == CHANGE_COMMODITY)
            change_Commodity(fruit_item,vegetables_item,furniture_item,clothes_item);
        if(user_input_flag == SIGN_OUT)
            return SIGN_OUT;
    }
}
