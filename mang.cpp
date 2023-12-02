#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool loggingIn(){
    string username, password, user, pass;

    cout<<"enter username: "; cin>> username;
    cout<<"enter password: "; cin>> password;

    ifstream read(username + ".txt");
    getline(read, user);
    getline(read, pass);
    
    if (user == username && pass == password){
        return true;
    }
    else{
        return false;
        
    }
}




int main()
{
    int choice;
    cout<< "select a choice!\n1 : register\n2 : Login\n your choice: ";
    cin>> choice;
    if (choice == 1){
        string username, password;

        cout<<"select a username: "; cin>>username;
        cout<<"select a password: "; cin>>password;

        ofstream file;
        file.open(username + ".txt");
        file << username << endl << password;
        file.close();
        
        main();

    }
    else if (choice == 2){
        bool status = loggingIn();
        if(!status){
            cout<<"incorrect information, try agian!"<<endl;
            system("pause");
            return 0;

        }
        else{
            cout<<"login successful!"<<endl;
            system("pause");
            return 1;

        }
    }
}
