#include<iostream>
#include<string>

using namespace std;

class teacher
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
            // Kiểm tra trùng tên tài khoản ở cơ sơ dữ liệu
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

void filter(teacher tc)
{
    int chon, chonlr;
    cout<<"Bạn là ..."<<endl;
    cout<<"           SinhVien(1)       GiangVien(2)"<<endl;
    cout<<"->"; cin>>chon;
    switch (chon)
    {
    case 1:
        break;
    case 2:
        cout<<"(1)Login"<<endl;
        cout<<"(2)Register";
        cin>>chonlr;
        switch (chonlr)
        {
            case 1:
                tc.login();
                break;
            case 2:
                tc.reg();
                break;
            default:
                cout<<"Vui long ban nhap lai"<<endl;
                break;
        }
    default:
        cout<<"Vui long ban nhap lai"<<endl;
        break;
    }
}

int main()
{
    teacher tc;
    filter(tc);
}