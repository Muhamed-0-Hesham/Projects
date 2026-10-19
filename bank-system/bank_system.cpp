#include <iostream>
#include <algorithm>   
#include <string>     
#include <vector> 
#include <queue>
#include <iomanip>
#include <fstream>
#include "Account.h"
using namespace std;
int main()
{
   vector<Account> vv;
    int x,y,id;
    string name,pin;
    double b;
    bool found,wrong_pin;
    cout<<"How many Transaction do you want to do";
    cin>>x;
    while(x--)
   {  
      cout<<"if you want to createAccount press: 1 \n";
      cout<<"if you want to deleteAccount press: 2 \n";
      cout<<"if you want to deposit press: 3 \n";
      cout<<"if you want to withdraw press: 4 \n";
      cout<<"if you want to transfer press: 5 \n";
      cout<<"if you want to getBalance press: 6 \n";
      cin>>y;
   
      switch (y)
      {
       case 1:
        cout<<"Write your name : "; cin>>name;
        cout<<"How much money do you want to deposit in your account : "; cin>>b;
        cout<<"What is your pin : ";  cin>>pin;
         vv.push_back( Account(name,b,pin));
        break;
        
        case 2:
        cout<<"Write your name : ";  cin>>name;
        cout<<"Write your Id : ";  cin>>id;
        cout<<"What is your pin : ";   cin>>pin;
        found=false;
        wrong_pin=false;
        for (int i = 0; i < vv.size(); i++)
        {
           if(vv[i].getId()==id)
           {
             if( vv[i].checkpin(pin))
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
        break;

        case 3:
        cout<<"Write your name : ";  cin>>name;
        cout<<"Write your Id : ";  cin>>id;
        cout<<"What is your pin : ";   cin>>pin;
        
        break;
        case 4:
        break;
        case 5:
        break;
        case 6:
        break;
       default:
        break;
      }
   }
}
