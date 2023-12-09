#ifndef support
#define support
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace std;

//Class
class account
{
    private:
        string username, password, user, pass;

    public:
        //Ham kiem tra tai khoan
        bool check()
        {
            cout << "enter username: "; cin >> username;
            cout << "enter password: "; cin >> password;

            ifstream read(username + ".txt");
            getline(read, user);
            getline(read, pass);
            
            if(user == username && pass == password)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        //Ham dang nhap
        bool login()
        {
            int choice;
            try
            {
                cout << endl;
                cout << "select !\n1 : register\n2 : Login\n your choice: "; cin >> choice;
                throw choice;
            }
            catch (...)
            {
                cout << "Vui long nhap lai !!!";
            }
            if (choice == 1)
            {
                string username, password;

                cout << "select a username: "; cin >> username;
                cout << "select a password: "; cin >> password;

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
                    cout << "incorrect information, try again!" << endl;
                    system("pause");
                    return 0;
                }
                else
                {
                    cout << "login successful!" << endl;
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

//Function
void gotoxy(short ix, short iy)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = {ix, iy};
  SetConsoleCursorPosition(h,c);
}

void box(int x, int y, int w, int h)
{
    if(h <= 1 || w <= 1)
        return;
    for(int i = x; i <= x + w; i++)
    {
        gotoxy(i, y);
        cout << char(4);
        gotoxy(i, y + h);
        cout << char(4);
    }
    for(int i = y; i <= y + h; i++)
    {
        gotoxy(x, i);
        cout << char(4);
        gotoxy(x + w, i);
        cout << char(4);
    }
}

void title()
{
    string x = "QUAN LY SINH VIEN";
    string y = "Login";
    string z = "Register";
    gotoxy(60 - x.length()/2,2);
    cout << x;
    gotoxy(60 - y.length()/2,4);
    cout << y;
    gotoxy(60 - z.length()/2,7);
    cout << z;
}

#endif
