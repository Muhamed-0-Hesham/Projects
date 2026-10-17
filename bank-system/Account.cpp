#include "Account.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int Account::nextid = 1;

Account::Account()
{
    id = 0;
    name = "unknown";
    balance = 0.0;
    
}

Account::Account(string n , double b ,string pass)
{
    name = n;
    balance = b ;
    pin = pass;
}

void Account::Deposit(double num , string pass)
{
   balance+=num;   
}

void Account::Withdraw(double num , string pass)
{
    balance-=num;     
}

bool Account::Transfer()
{
  
}

double Account::getBalance() 
{
    return balance;

}

int Account::getId()
{
    return id;
}
string Account::getPin()
{
    return pin;
}

string Account::getName()
{
    return name;
}

void Account::display()
{
    cout<<"Your account name : "<<getName()<<'\n';
    cout<<"Your account id : "<<getId()<<'\n';
    cout<<"Your account balance : "<<getBalance()<<'\n';
    cout<<"Your account pin : "<<getPin()<<'\n';
   
}

void Account::createAccount()
{
      id=nextid++;
    ofstream file("data.txt", ios::app);
    file << getName()  << '\n';
    file <<  id << '\n';
    file << getBalance() << '\n';
    file << "-----------------------"<<'\n';
    file.close();

}

void Account :: deleteAccount(string n, string pass)

{

    if(checkpin(pass))
    {
    ifstream file ("data.txt");
    ofstream tem ("temp.txt");
    string line;

    while(getline( file, line) )
    {
        if(line == n)
        {
            getline(file, line);
            getline(file, line);
            getline(file, line);
        }
        else
        tem << line <<'\n';
    }
    file.close();
    tem.close();
    remove("data.txt");
    rename("temp.txt","data.txt");
  } 
  else
  cout<<"Wrong pin";


}
bool Account::checkpin (string pass)
{
    int x=3;
    
    while(x>0)
    {
        if(pass==pin)
        return true;
        else
        {
            cout<<"Wrong pin you have "<<x<<"try\n";
            cin>>pass;
        }
    }

}