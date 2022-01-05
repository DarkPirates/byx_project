#include "sign_in.h"

const static int LOGIN_FAILE                =  -1;
const static int SUSPENSION_SIGN            =  -1;
const static int NO_NEED                    =   0;
const static int FAIL_SIGN                  =   0;
const static int SIGN_USER                  =   1; 
const static int SUCCESS_SIGN               =   1;
const static int NEED                       =   1;
const static int LOGIN_SUCCESSFUL           =   1;
const static int LOGIN_SUCCESSFUL_USER      =   1;
const static int LOGIN_SUCCESSFUL_SELLER    =   2;
const static int SIGN_MERCHANT              =   2;

//用于输出std::cout
void std_cout(std::string in_a_word)
{
    std::cout << in_a_word <<std::endl;
}

//这是接收输入的帐号
std::string input_Accounts()
{
    std::string name = "";
    std_cout("输入你的帐号:");
    std::cin >> name;
    return name;
}

//这是接受输入的密码
std::string input_Password()
{
    std::string password = "";
    std_cout("输入你的密码:");
    std::cin >> password;
    return password;
}

//选择是商户还是用户登陆
int Merchant_Or_User()
{
    int input_flag = 0;
    std_cout("是用户还是商人呢?");
    std::cin >> input_flag;
    if(input_flag == SIGN_MERCHANT)
    {
        return SIGN_MERCHANT;
    }
    if(input_flag == SIGN_USER)
    {
        return SIGN_USER;
    }
}

//注册帐号
int register_Accounts( std::map<std::string,std::string> &user_sign,
                        std::map<std::string,std::string> &seller_sign)
{
    for(int i = 0;i < 3;++i)//当用户输入出错时,有3次机会..
    {
        std_cout("输入你的帐号密码:");
        std::string name = "",password = "";
        name = input_Accounts();
        password = input_Password();
        int registered_user = Merchant_Or_User();
        if(registered_user == SIGN_MERCHANT)
        {
            seller_sign.insert(std::pair<std::string,std::string>(name,password));
            std_cout("成功");
            break;
        }
        else if(registered_user == SIGN_USER)
        {
            user_sign.insert(std::pair<std::string,std::string>(name,password));
            break;
        }
        else
        {
            std_cout("输入错误");
            return FAIL_SIGN;
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
            std_cout("成功");
            return LOGIN_SUCCESSFUL_SELLER;
        }
        else
        {
            std_cout("密码错误");
            return FAIL_SIGN;
        }
    }
    else
    {
        std_cout("用户名错误");
        return SUSPENSION_SIGN;
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
            std_cout("登陆成功");
            return LOGIN_SUCCESSFUL_USER;
        }
        else
        {
            std_cout("密码错误");
            return FAIL_SIGN;
        }
    }
    else
    {
        std_cout("用户名错误");
        return SUSPENSION_SIGN;
    }
}

//检查登陆操作
int logging_in( std::map<std::string,std::string> &user_sign,
                std::map<std::string,std::string> &seller_sign)
{
    int return_value = 0;
    int sign =  Merchant_Or_User();
    for(int i = 0;i < 3;++i)
    {
        std::string name = input_Accounts();
        std::string password = input_Password();
        if(sign == SIGN_MERCHANT)
        {
            return_value = login_check_seller(seller_sign,name,password);
            return return_value;
        }
        else if(sign == SIGN_USER)
        {
            return_value = login_check_user(user_sign,name,password);
            return return_value;
        }
        else
        {
            std_cout("输入出错");
        }
    }
    return LOGIN_FAILE;
}

//这是登陆接口
int sign_In(std::map<std::string,std::string> &user_sign,
            std::map<std::string,std::string> &seller_sign)
{
    int user_input_register = 0,return_value = 0;
    std_cout("是否需要注册用户");
    std::cin >> user_input_register;
    if(user_input_register == NEED)
        register_Accounts(user_sign,seller_sign);
    return_value = logging_in(user_sign,seller_sign);
    std::cout << return_value << std::endl;
    return return_value;
}