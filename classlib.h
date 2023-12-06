#ifndef classlib
#define classlib
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class account
{
    private:
        string username, password, user, pass;
    public:
        bool check()
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

        bool login()
        {
            int choice;
            cout << "select a choice!\n1 : register\n2 : Login\n your choice: "; cin >> choice;
            if (choice == 1){
                string username, password;

                cout<<"select a username: "; cin>>username;
                cout<<"select a password: "; cin>>password;

                ofstream file;
                file.open(username + ".txt");
                file << username << endl << password;
                file.close();
                
                login();
            }
            else if (choice == 2)
            {
                bool status = check();
                if(!status)
                {
                    cout<<"incorrect information, try again!"<<endl;
                    system("pause");
                    return 0;
                }
                else
                {
                    cout<<"login successful!"<<endl;
                    system("cls");
                    return 1;
                }
            }
        }
};
#endif
