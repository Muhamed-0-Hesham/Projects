#include <iostream>
#include <algorithm>   
#include <string>     
#include <vector> 
#include <queue>
#include <iomanip>
#include <fstream>
#include "Account.h"
using namespace std;
void menuu ()
  {
    cout << "\n===== Bank System =====\n";
    cout << "1. Create Account\n";
    cout << "2. Delete Account\n";
    cout << "3. Deposit\n";
    cout << "4. Withdraw\n";
    cout << "5. Transfer\n";
    cout << "6. Get info\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
  }
int main()
{
    vector<Account> vv;
    int choice,id,to_id;
    string name,pin;
    double money;
    bool op=true;

    while(op)
    {
      menuu();
      cin>>choice;
      switch (choice)
      {
       case 1:
        cout<<"Write your name : \n"; cin.ignore(10000, '\n'); getline(cin,name);
        cout<<"How much money do you want to deposit in your account : \n"; cin>>money;
        cout<<"What is your pin : \n";  cin>>pin;
        if (money < 0)
       {
        cout << "Invalid amount\n";
        break;                      
       }
         vv.push_back( Account(name,money,pin));
        cout << "Account created. Your id is : " << vv.back().getId() << "\n";
        break;
        case 2:
        cout<<"Write your Id : \n";  cin>>id;
        cout<<"What is your pin : \n";   cin>>pin;
          Account::deleteAccount(vv, id, pin);
        break;
        case 3:
        cout<<"Write your Id : \n";    cin>>id;
        cout<<"What is your pin : \n"; cin>>pin;
        cout<<"How much money do you want to deposit in your account \n";cin>>money;
        Account::Deposit(vv,money,pin,id);
        break;
        case 4:
        cout<<"Write your Id : \n";    cin>>id;
        cout<<"What is your pin : \n"; cin>>pin;
        cout<<"How much money do you want to Withdraw from your account \n";cin>>money;
        Account::Withdraw(vv,money,pin,id);
        break;
        case 5:
        cout<<"Write your Id : \n";    cin>>id;
        cout<<"What is your pin : \n"; cin>>pin;
        cout<<"How much money do you want to transfer from your account \n";cin>>money;
        cout<<"Write Receiver account Id : \n";    cin>>to_id;
        Account::Transfer(vv,money,pin,id,to_id);
        break;
        case 6:
        cout<<"Write your Id : \n";    cin>>id;
        cout<<"What is your pin : \n"; cin>>pin;
        Account::display(vv,pin, id);
        break;
        case 0:
        op=false;
        break;
        default:
        cout << "Invalid choice\n";
        break;
      }
    }
}
