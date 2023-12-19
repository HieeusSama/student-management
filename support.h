#ifndef support
#define support
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <iomanip>
#include <utility>
#include <dirent.h>
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
            unsigned long int id;
            string phone;
            string name;
            string class_of;
            string dateOfBirth;
            string address_of;
        public:
            student()
            {
                int stt = stt_start++;
                long int id;
                name = "Unknown";
                class_of = "Unknown";
                dateOfBirth = "Unknown";
                address_of = "Unknown";
                phone = "Unknown";
            }

            int control_in(int x, int y, int w, int h)
            {
                gotoxy(x + w - 2, y + 1);
                int i = 1;
                while(true)
                {
                    char input;
                    input = getch();
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
                gotoxy(5, 3); cout << "Xin chao " << getUsername();
                box(5, 4, 15, 2, 0, "Them");
                box(25, 4, 15, 2, 0, "Chinh sua");
                gotoxy(50, 5);


                //Hien thi danh sach sinh vien
                string x = "Danh sach sinh vien";
                gotoxy(60 - x.length() / 2, 8);
                cout << x << endl;

                string folderPath = "E:/student-management/student/";
                DIR* directory = opendir(folderPath.c_str());
                struct dirent* entry;
                cout << endl;
                string id, name, phone, address, dateOfBirth;
                while ((entry = readdir(directory)) != nullptr) {
                    string fileName = entry->d_name;
                    if (fileName != "." && fileName != "..") 
                    {
                        string filePath = folderPath + "/" + fileName;
                        fileName.erase(fileName.length() - 4);
                        ifstream file(filePath);
                        getline(file, id);
                        getline(file, name);
                        getline(file, address);
                        getline(file, dateOfBirth);
                        getline(file, phone);
                        cout << id << setw(20) << char(179);
                        cout << name << setw(20) << char(179);
                        cout << address << setw(20) << char(179);
                        cout << dateOfBirth << setw(20) << char(179);
                        cout << phone << setw(20) << char(179);
                        cout << endl;
                        file.close();
                    }
                }
                closedir(directory);
            }

            //Kiem tra ma sinh vien
            bool checkid(unsigned long int id)
            {
                ifstream file;
                string path = "E:/student-management/student/";
                path += to_string(id) + ".txt";
                file.open(path.c_str());

                if (file.is_open())
                {
                    file.close();
                    return true;
                }
                else
                {
                    return false;
                }
            }

            //Nhập thông tin sinh viên
            void import()
            {
                menu_in();
                if(control_in(5, 4, 15, 2) == 0)
                {
                    system("cls");
                    string x = "Them sinh vien";
                    gotoxy(60 - x.length()/2,2);
                    cout << x;

                    gotoxy(15, 7); cout<<"Ho va ten: ";
                    box(50, 6, 30, 2, 1, "  ");

                    gotoxy(15, 10); cout << "Dia chi: ";
                    box(50, 9, 30, 2, 1, "  ");

                    gotoxy(15, 13); cout << "Ngay sinh: ";
                    box(50, 12, 30, 2, 1, "  ");

                    gotoxy(15, 16); cout<<"So dien thoai: ";
                    box(50, 15, 30, 2, 1, "  ");

                    gotoxy(15, 4); cout << "Ma sinh vien: ";
                    box(50, 3, 30, 2, 1, " ");
                    cin >> id;
                    stt;
                    gotoxy(52, 7); cin.ignore(); getline(cin,name);
                    gotoxy(52, 10); getline(cin, address_of);
                    gotoxy(52, 13); getline(cin, dateOfBirth);
                    gotoxy(52, 16); getline(cin, phone);

                    pair<unsigned long int, int> mPair(id, stt);
                    
                    ofstream file;
                    string path = "E:/student-management/student/";
                    path += to_string(id);
                    file.open((path + ".txt").c_str());
                    file << id << endl << name << endl << address_of << endl << dateOfBirth << endl << phone;
                    file.close();

                    system("cls");
                    import();
                }

                //Chinh sua thong tin cua sinh vien trong file
                else if (control_in(5, 4, 15, 2) == 1) 
                {
                    system("cls");
                    string x = "Chinh sua thong tin";
                    gotoxy(60 - x.length()/2,2);
                    cout << x << endl;

                    //Nhap ma sinh vien can chinh sua
                    unsigned long int id;
                    gotoxy(15, 4); cout << "Nhap ma sinh vien can chinh sua:";
                    box(50, 3, 30, 2, 1, " ");
                    cin>>id;

                    //Kiem tra ma sinh vien can chinh sua
                    if(checkid(id))
                    {

                        //Cho phep thay doi thong tin moi
                        string newPhone;
                        string newName, newClassOf, newAdress_of, newDateOfBirth;  
                        gotoxy(15, 7); cout<<"Ho va ten: ";
                        box(50, 6, 30, 2, 1, "  ");

                        gotoxy(15, 10); cout << "Dia chi: ";
                        box(50, 9, 30, 2, 1, "  ");

                        gotoxy(15, 13); cout << "Ngay sinh: ";
                        box(50, 12, 30, 2, 1, "  ");

                        gotoxy(15, 16); cout<<"So dien thoai: ";
                        box(50, 15, 30, 2, 1, "  ");
                        
                        gotoxy(52, 7);cin.ignore(); getline(cin, newName);
                        gotoxy(52, 10); getline(cin, newAdress_of);
                        gotoxy(52, 13); getline(cin, newDateOfBirth);
                        gotoxy(52, 16); getline(cin, newPhone);

                        //Luu thong tin moi sua
                        ofstream file;
                        string path = "E:/student-management/student/";
                        path += to_string(id);
                        file.open((path + ".txt").c_str());
                        file << newName << endl << newAdress_of << endl << newDateOfBirth << endl << newPhone;
                        file.close();

                        cout << "Thong tin sinh vien da duoc cap nhat!" << endl;
                        _getch();
                        system("cls");
                        import();
                    }
                    
                    //Khong tim thay ma sinh vien
                    else
                    {
                        gotoxy(50, 10); cout << "Sinh vien khong ton tai!" << endl;
                        _getch();
                        system("cls");
                        import();
                    }
                        

                }

                
            }

            int getstt()
            {
                return stt;
            }
    };

int student::stt_start = 0;

#endif