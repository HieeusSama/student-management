#ifndef student
#define student
#include<iostream>
using namespace std;

class student
{
    private:
        char username[10], username1[10];
        int password, password1;
        
    public:
        void reg()
        {
            cout<<"-------Register-------"<<endl;
            cout<<"Username: "; cin>>username;
            cout<<"Password: "; cin>>password;
            cout<<"----------------------";
            // Ki?m tra tr�ng t�n t�i kho?n ? co so d? li?u
        }
        void login()
        {
            do
            {
                cout<<"-------Login-------"<<endl;
                cout<<"Username: "; cin>>username1;
                cout<<"Password: "; cin>>password1;
            }while(username1 != username and password1 != password);
        }
};
#endif;