#include "account.h"
#include <string>

int main()
{
    loggingIn log;
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
        
        main();
    }
    else if (choice == 2){
        bool status = log.login();
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