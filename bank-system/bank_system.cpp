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
    int choice,x=1,id;
    string name,pin;
    double money;

    do{
      Account acc;
      menuu();
      cin>>choice;
      switch (choice)
      {
       case 1:
        cout<<"Write your name : \n"; cin>>name;
        cout<<"How much money do you want to deposit in your account : \n"; cin>>money;
        cout<<"What is your pin : \n";  cin>>pin;
         vv.push_back( Account(name,money,pin));
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
        break;
        case 6:
        cout<<"Write your Id : \n";    cin>>id;
        cout<<"What is your pin : \n"; cin>>pin;
        Account::display(vv,pin, id);
        break;
       default:
        x=0;
        break;
      }
      
    }while(x!=0);
}
