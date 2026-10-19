#include "Account.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int Account::nextid = 1;
int Account::tempid = 0;

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
    creatId();
    
}

void Account::Deposit(double num , string pass)
{
  if(checkpin(pass))
   balance+=num;   
}

void Account::Withdraw(double num , string pass)
{
   if(checkpin(pass))
   {

   }
}

bool Account::Transfer()
{
    return true;
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

void Account::creatId()
{
      if(tempid>0)
      {
       id=tempid;
       tempid=0;
      }
      else
      id=nextid++;

 
}

void Account :: deleteAccount(string n, string pass , int d)
{
    
    if(checkpin(pass))
    {
  
    } 
}

bool Account::checkpin (string pass)
{
     if(pass==pin)
     return true;
    return false;
}