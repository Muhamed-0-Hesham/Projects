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
    Account account;
    int x,y;
    string n;
    double b;
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
        break;
        case 2:
        break;
        case 3:
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