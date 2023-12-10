#ifndef support
#define support
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace std;

//Function
void gotoxy(short ix, short iy)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = {ix, iy};
  SetConsoleCursorPosition(h,c);
}

void box(int x, int y, int w, int h, string note)
{
    if(h <= 1 || w <= 1)
        return;

    for(int i = x; i <= x + w; i++)
    {
        gotoxy(i, y); cout << char(196);
        gotoxy(i, y + h); cout << char(196);
    }

    for(int i = y; i <= y + h; i++)
    {
        gotoxy(x, i); cout << char(179);
        gotoxy(x + w, i); cout << char(179);
    }

    gotoxy(x,y); cout << char(218);
    gotoxy(x + w, y); cout << char(191);
    gotoxy(x, y + h); cout << char(192);
    gotoxy(x + w, y + h); cout << char(217);
    gotoxy(x + w/2 - note.length()/2, y + 1); cout << note;
}

bool control(int x, int y, int w, int h)
{
    gotoxy(x + w - 1, y + 1);
    while(true)
    {
        char input;
        input = _getch();
        if(GetAsyncKeyState(VK_DOWN))
        {
            gotoxy(x + w - 2, y + 4);
        }
        else if(GetAsyncKeyState(VK_UP))
        {
            gotoxy(x + w - 2, y + 1);
        }
        if(static_cast<int>(input) == 13)
        {
            break;
            
        }
    }
    
}

void title()
{
    string x = "QUAN LY SINH VIEN";
    gotoxy(60 - x.length()/2,2);
    cout << x;
    box(50, 3, 20, 2, "Login");
    box(50, 6, 20, 2, "Register");
}

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
            title();
            control(50, 3, 20, 2);
            int choice;
            cin >> choice;
            if (choice == 4)
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
            else if (choice == 6)
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

#endif
