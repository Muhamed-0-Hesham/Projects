#include "Account.h"
#include <iostream>
#include <algorithm>   
#include <string>     
#include <vector> 
#include <queue>
#include <iomanip>
#include <fstream>
#include "Account.h"
using namespace std;

int Account::nextid = 1;
int Account::tempid = 0;

Account::Account()
{
    id = 0;
    name = "unknown";
    balance = 0.0;
    
}

Account::Account(string n , double money ,string pass)
{
    name = n;
    balance = money ;
    pin = pass;
    creatId();
    
}

void Account::Deposit(vector<Account>&vv,double num , string pass,int id)
{
       bool found=false;
       bool wrong_pin=false;
       
        for (int i = 0; i < vv.size(); i++)
        {
           if(vv[i].getId()==id)
           {
             if( vv[i].checkpin(pass))
             {
               found=true;
               vv[i].balance+=num;
              break;
             }
              else
              {
               wrong_pin=true;
               break;
              }
           }
         }
         if(!found)
         cout<<"Wrong ID";
         else
         if(wrong_pin)
         cout<<"Wrong pin";   
}

void Account::Withdraw(vector<Account>&vv, double num , string pass,int id)
{
       bool found=false;
       bool wrong_pin=false;
       
        for (int i = 0; i < vv.size(); i++)
        {
           if(vv[i].getId()==id)
           {
             if( vv[i].checkpin(pass))
             {
               found=true;
               if( vv[i].balance > num)
               vv[i].balance-=num;
               else
               cout<<"your current balance is : "<<vv[i].balance<<"\n";
              break;
             }
              else
              {
               wrong_pin=true;
               break;
              }
           }
         }
         if(!found)
         cout<<"Wrong ID";
         else
         if(wrong_pin)
         cout<<"Wrong pin";   
}

bool Account::Transfer(vector<Account>&vv)
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

void Account :: deleteAccount(vector<Account> &vv ,int id,string pass )
{
       bool found=false;
       bool wrong_pin=false;
       
        for (int i = 0; i < vv.size(); i++)
        {
           if(vv[i].getId()==id)
           {
             if( vv[i].checkpin(pass))
             {
               found=true;
              vv.erase(vv.begin() + i);
              break;
             }
              else
              {
               wrong_pin=true;
               break;
              }
           }
         }
         if(!found)
         cout<<"Wrong ID";
         else
         if(wrong_pin)
         cout<<"Wrong pin";
    
}

bool Account::checkpin (string pass)
{
     if(pass==pin)
     return true;
    return false;
}
double display(vector<Account> &vv,string pass,int id)
{
           bool found=false;
       bool wrong_pin=false;
       
        for (int i = 0; i < vv.size(); i++)
        {
           if(vv[i].getId()==id)
           {
             if( vv[i].checkpin(pass))
             {
               found=true;
              vv[i].display();
              break;
             }
              else
              {
               wrong_pin=true;
               break;
              }
           }
         }
         if(!found)
         cout<<"Wrong ID";
         else
         if(wrong_pin)
         cout<<"Wrong pin";
}