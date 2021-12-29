#include "sign_in.h"

static const int sign_merchant          =   0;
static const int sign_user              =   1; 
static const int success_sign           =   1;
static const int fail_sign              =   0;
static const int suspension_sign        =  -1;

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
    std::cout << "是商人还是用户呢?" << std::endl;
    if(input_flag == sign_merchant)
        return sign_merchant;
    if(input_flag == sign_user)
        return sign_user;
}

//检查帐号密码
int login_check(std::map<std::string,std::string> &seller_sign,std::string name,std::string password)
{
    std::map<std::string,std::string>::iterator iter = seller_sign.find(name);
    if (iter != seller_sign.end())
    {
        if(iter ->second == password)
        {
            std::cout << "登陆成功" << std::endl;
            return success_sign;
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
    int sign =  Merchant_Or_User();
    std::string name = input_Accounts();
    std::string password = input_Password();
    if(sign == sign_merchant)
        login_check(seller_sign,name,password);
}

//这是登陆接口
int sign_In(std::map<std::string,std::string> &user_sign,
            std::map<std::string,std::string> &seller_sign)
{
    

}