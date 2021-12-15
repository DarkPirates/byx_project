#include "sign_in.h"

using namespace std;

int Sign_In(map<string,string> &b_user)
{
    string user_name;
    string user_password;

    std::cout << "Please enter your user name and password " << endl;

    //输入用户名和密码
    cin >> user_name;
    if(user_name == "#")
    {
        exit(1);
    }
    cin >> user_password;

    std::cout << "Do you need to register users" << endl;
    //flag是一个标志，如果输入是#那么直接exit，后面flag还有用来计数
    int flag;  
    cin >> flag; 
    if(flag)
    {        
        b_user.insert(pair<string,string>(user_name,user_password));    
        std::cout << "login was successful,Do you need to log in directly" << endl;
        cin >> flag;
        if(flag)
        {
            return 1;
        }
        else
            exit(1);

    }
    else
    {
        //找到用户名所对应的键值对
        map<string,string>::iterator iter;
        iter = b_user.find(user_name);
        if(iter != b_user.end())
        {
            if(iter ->second == user_password)
            {
                std::cout << "Login successful" << endl;
                return 1;
            }
            else
            {                
                for(flag = 0;flag < 3;flag++)
                {
                    //错误的时候应该是有给机会的。。
                    //来一手goto吧
                    std::cout << "Password error" << endl;
                    cin >> user_name;
                    cin >> user_password;
                    iter = b_user.find(user_name);
                    if(iter != b_user.end())
                    {
                        if(iter ->second == user_password)
                        {
                            std::cout << "Login successful" << endl;
                            return 1;
                        }
                    }
                }
                std::cout << "..."<<endl;
                exit(250);
            }
        }
    }

}
