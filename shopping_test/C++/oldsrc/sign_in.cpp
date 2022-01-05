#include "sign_in.h"

const int ZERO      =   0;
const int ONE       =   1;
const int TWO       =   2;
const int THREE     =   3;
const int FOUR      =   4;
const int ONE_      =  -1;

int Sign_In(std::map<std::string,std::string> &b_user,std::map<std::string,std::string> &b_seller)
{
    std::string user_name;
    std::string user_password;

    int msg;
    std::cout << "商户还是客户呢？"  << std::endl;
    std::cin >> msg ;

    std::cout << "Please enter your user name and password " << std::endl;
    if(msg == TWO)
    {
        //输入用户名和密码
        std::cin >> user_name;
        if(user_name == "#")
        {
            return ZERO;
        }
        std::cin >> user_password;

        std::cout << "Do you need to register users" << std::endl;
        //flag是一个标志，如果输入是#那么直接exit，后面flag还有用来计数
        int flag;  
        std::cin >> flag; 
        if(flag)
        {        
            b_user.insert(std::pair<std::string,std::string>(user_name,user_password));    
            std::cout << "login was successful,Do you need to log in directly" << std::endl;
            std::cin >> flag;
            if(flag)
            {
                return ONE;
            }
            else
                return ZERO;

        }
        else
        {
            //找到用户名所对应的键值对
            std::map<std::string,std::string>::iterator iter;
            iter = b_user.find(user_name);
            if(iter != b_user.end())
            {
                if(iter ->second == user_password)
                {
                    std::cout << "Login successful" << std::endl;
                    return ONE;
                }
                else
                {                
                    for(flag = ZERO;flag < THREE;flag++)
                    {
                        //错误的时候应该是有给机会的。。
                        //经历3次循环，然后不行就直接结束程序
                        std::cout << "Password error" << std::endl;
                        std::cin >> user_name;
                        std::cin >> user_password;
                        iter = b_user.find(user_name);
                        if(iter != b_user.end())
                        {
                            if(iter ->second == user_password)
                            {
                                std::cout << "Login successful" << std::endl;
                                return ONE;
                            }
                        }
                    }
                    std::cout << "..."<< std::endl;
                    return ZERO;
                }
            }
            else//没找到
            {
                std::cout << "user error" << std::endl;
                return ZERO; 

            }
        }

    }
    else if(msg == ONE)
    {
        //输入用户名和密码
        std::string seller_name,seller_password;
        std::cin >> seller_name;
        if(user_name == "#")
        {
            return ZERO;
        }
        std::cin >> seller_password;

        std::cout << "Do you need to register users" << std::endl;
        //flag是一个标志，如果输入是#那么直接exit，后面flag还有用来计数
        int flag;  
        std::cin >> flag; 
        if(flag)
        {        
            b_seller.insert(std::pair<std::string,std::string>(seller_name,seller_password));    
            std::cout << "login was successful,Do you need to log in directly" << std::endl;
            std::cin >> flag;
            if(flag)
            {
                return TWO;
            }
            else
                return ZERO;

        }
        else
        {
            //找到用户名所对应的键值对
            std::map<std::string,std::string>::iterator iter;
            iter = b_seller.find(seller_name);
            if(iter != b_seller.end())
            {
                if(iter ->second == seller_password)
                {
                    std::cout << "Login successful" << std::endl;
                    return TWO;
                }
                else
                {                
                    for(flag = ZERO;flag < THREE;flag++)
                    {
                        //错误的时候应该是有给机会的。。
                        //经历3次循环，然后不行就直接结束程序
                        std::cout << "Password error" << std::endl;
                        std::cin >> seller_name;
                        std::cin >> seller_password;
                        iter = b_seller.find(user_name);
                        if(iter != b_seller.end())
                        {
                            if(iter ->second == seller_password)
                            {
                                std::cout << "Login successful" << std::endl;
                                return TWO;
                            }
                        }
                    }
                    std::cout << "..."<< std::endl;
                    return ZERO;
                }
            }
            else//没找到
            {
                std::cout << "seller error" << std::endl;
                return ZERO; 
            }
        }
    }
    else
        return ZERO;
    
}
