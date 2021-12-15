#include "sign_in.h"


int Sign_In(std::map<std::string,std::string> &b_user)
{
    std::string user_name;
    std::string user_password;

    std::cout << "Please enter your user name and password " << std::endl;

    //输入用户名和密码
    std::cin >> user_name;
    if(user_name == "#")
    {
        return 0;
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
            return 1;
        }
        else
            return 0;

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
                return 1;
            }
            else
            {                
                for(flag = 0;flag < 3;flag++)
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
                            return 1;
                        }
                    }
                }
                std::cout << "..."<< std::endl;
                return 250;
            }
        }
        else//没找到
        {
            std::cout << "user error" << std::endl;
            return 0; 

        }
    }

}
