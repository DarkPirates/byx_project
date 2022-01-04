#include "sign_in.h"

static const int sign_merchant          =   2;
static const int sign_user              =   1; 
static const int success_sign           =   1;
static const int fail_sign              =   0;
static const int suspension_sign        =  -1;
static const int need                   =   1;
static const int needn_t                =   0;
static const int login_successful       =   1;
static const int login_faile            =  -1;
static const int login_successful_user  =   1;
static const int login_successful_seller=   2;
//这是接收输入的帐号
std::string input_Accounts()
{
    std::string name;
    std::cout << "输入你的帐号" << std::endl;
    std::cin >> name;
    return name;
}

//这是接受输入的密码
std::string input_Password()
{
    std::string password;
    std::cout << "输入你的密码" << std::endl;
    std::cin >> password;
    return password;
}

//选择是商户还是用户登陆
int Merchant_Or_User()
{
    int input_flag;
    std::cout << "是用户还是商人呢?" << std::endl;
    std::cin >> input_flag;
    if(input_flag == sign_merchant)
        return sign_merchant;
    if(input_flag == sign_user)
        return sign_user;
}

//注册帐号
int register_Accounts( std::map<std::string,std::string> &user_sign,
                        std::map<std::string,std::string> &seller_sign)
{
    for(int i = 0;i < 3;++i)//当用户输入出错时,有3次机会..
    {
        std::cout << "输入帐号密码" << std::endl;
        std::string name,password;
        name = input_Accounts();
        password = input_Password();
        int registered_user = Merchant_Or_User();
        if(registered_user == sign_merchant)
        {
            seller_sign.insert(std::pair<std::string,std::string>(name,password));
            std::cout << "success" << std::endl;
            break;
        }
        else if(registered_user == sign_user)
        {
            user_sign.insert(std::pair<std::string,std::string>(name,password));
            break;
        }
        else
        {
            std::cout << "error input" << std::endl;
            std::cout << "success" << std::endl;
            return fail_sign;
        }
    }
}

//检查商人帐号密码
int login_check_seller(std::map<std::string,std::string> &seller_sign,
                std::string name,std::string password)
{
    std::map<std::string,std::string>::iterator iter = seller_sign.find(name);
    if (iter != seller_sign.end())
    {
        if(iter ->second == password)
        {
            std::cout << "登陆成功" << std::endl;
            return login_successful_seller;
        }
        else
        {
            std::cout << "密码错误" << std::endl;
            return fail_sign;
        }
    }
    else
    {
        std::cout << "没找到用户名" << std::endl;
        return suspension_sign;
    }
}

//检查用户帐号密码
int login_check_user(std::map<std::string,std::string> &user_sign,
                std::string name,std::string password)
{
    std::map<std::string,std::string>::iterator iter = user_sign.find(name);
    if (iter != user_sign.end())
    {
        if(iter ->second == password)
        {
            std::cout << "登陆成功" << std::endl;
            return login_successful_user;
        }
        else
        {
            std::cout << "密码错误" << std::endl;
            return fail_sign;
        }
    }
    else
    {
        std::cout << "没找到用户名" << std::endl;
        return suspension_sign;
    }
}

//检查登陆操作
int logging_in( std::map<std::string,std::string> &user_sign,
                std::map<std::string,std::string> &seller_sign)
{
    int return_value;
    int sign =  Merchant_Or_User();
    for(int i = 0;i < 3;++i)
    {
        std::string name = input_Accounts();
        std::string password = input_Password();
        if(sign == sign_merchant)
        {
            return_value = login_check_seller(seller_sign,name,password);
            return return_value;
        }
        else if(sign == sign_user)
        {
            return_value = login_check_user(user_sign,name,password);
            return return_value;
        }
        else
            std::cout << sign << std::endl;
            std::cout << "error input" << std::endl;
    }
    return login_faile;
}

//这是登陆接口
int sign_In(std::map<std::string,std::string> &user_sign,
            std::map<std::string,std::string> &seller_sign)
{
    int user_input_register,return_value;
    std::cout << "是否需要注册用户?" << std::endl;
    std::cin >> user_input_register;
    if(user_input_register == need)
        register_Accounts(user_sign,seller_sign);
    return_value = logging_in(user_sign,seller_sign);
    std::cout << return_value << std::endl;
    return return_value;
}