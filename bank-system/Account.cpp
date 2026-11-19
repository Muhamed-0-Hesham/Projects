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
    pin="";
    
}

Account::Account(string n , double money ,string pass)
{
    name = n;
    balance = money ;
    pin = pass;
    creatId(); 
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
int Account::findAccount(vector<Account> &vv,int id)
{
      for (int i = 0; i < vv.size(); i++)
        {
           if(vv[i].getId()==id)
               return i; 
        }
         cout<<"Wrong ID"<<"\n";
         return -1;
}
void Account::Deposit(vector<Account>&vv,double num , string pass,int id)
{
    if (num <= 0) 
  { 
    cout << "Invalid amount\n";
     return ;
  }
      int index=findAccount(vv,id);
        if(index>=0)
        {
            if(vv[index].checkpin(pass))
            {
             vv[index].balance+=num;
               cout << "Done\n"<<"Your current balance is : "<<vv[index].balance<<'\n';
            }
      }
               
}
bool Account::Withdraw(vector<Account>&vv, double num , string pass,int id)
{
  if (num <= 0) 
  { 
    cout << "Invalid amount\n";
     return false;
  }
      int index=findAccount(vv,id);
        if(index>=0)
        if(vv[index].checkpin(pass))
        {
              if( vv[index].balance >= num)
                {
                vv[index].balance-=num;
                cout << "We took from your account : "<<num<<"\n"<<" Now your current balance is : "<<vv[index].balance<<"\n";
                return true;
                }
              else
               cout<<"Insufficient balance. Your current balance is : "<<vv[index].balance<<"\n";
               return false;
        }
        return false;
}


void Account::showInfo()
{
    cout<<"Your account name : "<<getName()<<'\n';
    cout<<"Your account id : "<<getId()<<'\n';
    cout<<"Your account balance : "<<getBalance()<<'\n';
    cout<<"Your account pin : "<<getPin()<<'\n';
   
}



void Account :: deleteAccount(vector<Account> &vv ,int id,string pass )
{

      int index=findAccount(vv,id);
        if(index>=0)
        {
          if(vv[index].checkpin(pass))
          {
          vv.erase(vv.begin() + index);
          cout<<"Your Account has been deleted \n";
          }
       } 
}

bool Account::checkpin (string pass)
{
     if(pass==pin)
     return true;
      cout << "Wrong pin\n";
        return false;
}
void Account::display(vector<Account> &vv,string pass,int id)
{
  int index=findAccount(vv,id);
  if(index>=0)
    if(vv[index].checkpin(pass))
       vv[index].showInfo();
       
}
bool Account::Transfer(vector<Account>& vv,double num , string pass, int from_id, int to_id)
{
    if (num <= 0 || from_id == to_id)
    {
        cout << "Invalid transfer\n";
        return false;
    }
      int to_index=findAccount(vv,to_id);
        if(to_index>=0)
   if( Withdraw(vv,num,pass,from_id))
   {
          vv[to_index].balance+=num;
           cout << "Transfer done\n";
           return true;
   }
   return false;
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