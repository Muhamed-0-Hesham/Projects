#pragma once
#include <iostream>
#include <algorithm>   
#include <string>     
#include <vector> 
#include <queue>
#include <iomanip>
#include <fstream>
#include "Account.h"
using namespace std;

class Account
{
 private:
    static int nextid,tempid;
    int id;
    string name,pin; 
    double balance;
   void creatId( );
 public:
    Account();
    Account(string n, double b, string p);
  
    static void deleteAccount(vector<Account>& vv ,int id,string pin);
    static void Deposit      (vector<Account>& vv, double num , string pass,int id);
    static void Withdraw     (vector<Account>& vv, double num , string pass,int id);
    static void  display   (vector<Account> &vv,string pass,int id);

    bool Transfer(vector<Account>& vv);
    bool checkpin(string pass);

    double getBalance();
       
    int getId();
    
    string getPin();
    string getName();

    void display();
};
