#ifndef account
#define account
#include<iostream>
#include<fstream>

using namespace std;

class loggingIn
{
    private:
        string username, password, user, pass;
    public:
        bool login()
        {
            cout<<"enter username: "; cin>> username;
            cout<<"enter password: "; cin>> password;

            ifstream read(username + ".txt");
            getline(read, user);
            getline(read, pass);
            
            if (user == username && pass == password)
            {
                return true;
            }
            else
            {
                return false;
                
            }
        }
};
#endif
