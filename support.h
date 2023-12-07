#ifndef support
#define support
#include <iostream>
#include <fstream>
#include <windows.h>

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
            try
            {
                cout << "select a choice!\n1 : register\n2 : Login\n your choice: "; cin >> choice;
                throw choice;
            }
            catch (...)
            {
                cout<<"Vui long nhap lai !!!";
            }
            if (choice == 1)
            {
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

class student
{
    private:
        int id;
        string address, classroom, majors;
    public:
        
};

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;  
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };  
    SetConsoleCursorPosition(h,c);
}
#endif
