#ifndef support
#define support
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <iomanip>
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

void box(int x, int y, int w, int h,int type, string note)
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
    if(type == 0)
    {
        gotoxy(x + w/2 - note.length()/2, y + 1); cout << note;
    }
    else if(type == 1)
    {
        gotoxy(x + 1, y + 1); cout << note;
    }
}

//Class
class account
{
    private:
        string username, password, user, pass;

    public:
        int control(int x, int y, int w, int h)
        {
            gotoxy(x + w - 2, y + 1);
            int i = 1;
            while(true)
            {
                char input;
                input = _getch();
                if(GetAsyncKeyState(VK_DOWN))
                {
                    gotoxy(x + w - 2, y + 4);
                    i = 0;
                }
                else if(GetAsyncKeyState(VK_UP))
                {
                    gotoxy(x + w - 2, y + 1);
                    i = 1;
                }
                else if(static_cast<int>(input) == 13)
                {
                    return i;
                }
            }
        }

        void menu()
        {
            string x = "QUAN LY SINH VIEN";
            gotoxy(60 - x.length()/2,2);
            cout << x;
            box(50, 3, 20, 2, 0, "Login");
            box(50, 6, 20, 2, 0, "Register");
        }
    
        //Ham kiem tra tai khoan
        bool check()
        {
            string username, password;
            string x = "Login";
            gotoxy(60 - x.length()/2,2);
            cout << x;
            box(50, 6, 20, 2, 1, "Password: ");
            box(50, 3, 20, 2, 1, "Username: ");
            cin >> username;
            gotoxy(61, 7); cin >> password;

            string path = "E:/student-management/teacher/";
            path += username;
            ifstream read((path + ".txt").c_str());
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
            menu();
            if(control(50, 3, 20, 2) == 0)
            {
                system("cls");
                string username, password;
                string x = "Register";
                gotoxy(60 - x.length()/2,2);
                cout << x;
                box(50, 6, 20, 2, 1, "Password: ");
                box(50, 3, 20, 2, 1, "Username: ");
                cin >> username;
                gotoxy(61, 7); cin >> password;

                ofstream file;
                string path = "E:/student-management/teacher/";
                path += username;
                file.open((path + ".txt").c_str());
                file << username << endl << password;
                file.close();

                system("cls");
                login();
            }
            else if(control(50, 3, 20, 2) == 1)
            {
                system("cls");
                bool status = check();
                system("cls");
                if(!status)
                {
                    cout << "incorrect information, try again!" << endl;
                    _getch();
                    system("cls");
                    login();
                }
                else
                {
                    cout << "login successful!" << endl;
                    _getch();
                }
            }
        }

        string getUsername()
        {
            return username;
        }
    };

    class student : public account
    {
        private:
            static int stt_start;
            int stt;
            int id, phone;
            string name;
            string class_of;
            string dateOfBirth;
            string address_of;
        public:
            student()
            {
                int stt = stt_start++;
                int id, phone;
                name = "Unknown";
                class_of = "Unknown";
                dateOfBirth = "Unknown";
                address_of = "Unknown";
            }

            int control_in(int x, int y, int w, int h)
            {
                gotoxy(x + w - 2, y + 1);
                int i = 1;
                while(true)
                {
                    char input;
                    input = _getch();
                    if(GetAsyncKeyState(VK_LEFT))
                    {
                        gotoxy(x + w - 2, y + 1);
                        i = 0;
                    }
                    else if(GetAsyncKeyState(VK_RIGHT))
                    {
                        gotoxy(x + 20 + w - 2, y + 1);
                        i = 1;
                    }
                    else if(static_cast<int>(input) == 13)
                    {
                        return i;
                    }
                }
            }

            void menu_in()
            {
                account user;
                system("cls");
                gotoxy(5, 3); cout << "Xin chao ";
                box(5, 4, 15, 2, 0, "Them");
                box(25, 4, 15, 2, 0, "Chinh sua");
                gotoxy(19, 5);
            }

            void import()
            {
                menu_in();
                if(control_in(5, 4, 15, 2) == 0)
                {
                    system("cls");
                    string x = "Them sinh vien";
                    gotoxy(60 - x.length()/2,2);
                    cout << x;

                    box(50, 6, 20, 2, 1, "Ho va ten: ");
                    box(50, 9, 20, 2, 1, "Dia chi: ");
                    box(50, 12, 20, 2, 1, "Ngay sinh: ");
                    box(50, 15, 20, 2, 1, "So dien thoai: ");
                    box(50, 3, 20, 2, 1, "Ma sinh vien: ");
                    cin >> id;
                    gotoxy(61, 7); cin.ignore(); getline(cin,name);
                    gotoxy(61, 10); getline(cin, address_of);
                    gotoxy(61, 13); getline(cin, dateOfBirth);
                    gotoxy(61, 16);
                    cin >> phone;
                    
                    ofstream file;
                    string path = "E:/student-management/student/";
                    path += to_string(id);
                    file.open((path + ".txt").c_str());
                    file << id << endl << name << endl << address_of << endl << dateOfBirth << endl << phone;
                    file.close();

                    system("cls");
                    menu_in();
                }

                //Chinh sua thong tin trong file
                else if (control_in(5, 4, 15, 2) == 1) //sai
                {
                    system("cls");
                    string x = "Chinh sua thong tin";
                    gotoxy(60 - x.length()/2,2);
                    cout << x;

                    //check if the file exists
                    ifstream infile;
                    string path = "E:/student-management/student/" + to_string(id) + ".txt";
                    infile.open(path.c_str());
                    if(infile)
                    {
                        //Hien thi thong tin hien tai
                        
                        gotoxy(50, 6); cout << "Ho va ten: "<< name; //phai co lenh ìf else check íd + "txt" == true 
                        gotoxy(50, 3); cout << "Ma sinh vien: "<<id;
                        gotoxy(50, 9); cout << "Dia chi: "<< address_of;
                        gotoxy(50, 12); cout << "Ngay sinh: " << dateOfBirth;
                        gotoxy(50, 15); cout << "So dien thoai: " << phone;
                        infile >> id >> name >> address_of >> dateOfBirth >> phone;

                        infile.close();

                        //Cho phep thay doi thong tin moi
                        int newId, newPhone;
                        string newName, newClassOf, newAdress_of, newDateOfBirth;  

                        box(50, 6, 20, 2, 1, "New Ho va ten: ");
                        box(50, 9, 20, 2, 1, "New Dia chi: ");
                        box(50, 12, 20, 2, 1, "New Ngay sinh: ");
                        box(50, 15, 20, 2, 1, "New So dien thoai: ");
                        box(50, 3, 20, 2, 1, "New Ma sinh vien: ");

                        cin >> newId;
                        gotoxy(61, 7);cin.ignore(); getline(cin, newName);
                        gotoxy(61, 10); getline(cin, newAdress_of);
                        gotoxy(61, 13); getline(cin, newDateOfBirth);
                        gotoxy(61, 16); cin >> newPhone;

                        //Luu thong tin moi sua
                        ofstream file;
                        string path = "E:/student-management/student/";
                        path += to_string(id);
                        file.open((path + ".txt").c_str());
                        file << id << endl << name << endl << address_of << endl << dateOfBirth << endl << phone;
                        file.close();

                        cout << "Thong tin sinh vien da duoc cap nhat!" << endl;
                        _getch();

                        system("cls");
                        menu_in();
                    }
                    
                    else
                    {
                        cout << "Sinh vien khong ton tai!" << endl;
                        _getch();
                        system("cls");
                        menu_in();
                    }
                        

                }
            }
    };

int student::stt_start = 0;

#endif
