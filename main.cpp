#include<iostream>
#include<string>
#include<vector>

using namespace std;

class sinhvien
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

class teacher
{
    public:
        vector<sinhvien> teacher;
};



void filter(sinhvien sv)
{
    int chon, chonlr;
    cout<<"Ban la ..."<<endl;
    cout<<"           SinhVien(1)       GiangVien(2)"<<endl;
    cout<<"->"; cin>>chon;
    switch (chon)
    {
    case 1:
        cout<<"(1)Login"<<endl;
        cout<<"(2)Register"<<endl;
        cin>>chonlr;
        switch (chonlr)
        {
            case 1:
                sv.login();
                break;
            case 2:
                sv.reg();
                break;
            default:
                cout<<"Vui long ban nhap lai"<<endl;
                break;
        }
    case 2:
        break;
    default:
        cout<<"Vui long ban nhap lai"<<endl;
        break;
    }
}

int main()
{
    sinhvien sv;
    filter(sv);
}
