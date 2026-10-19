#pragma once
#include <string>
#include <fstream>
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
  
    void deleteAccount(string n, string pass,int d);
    void display();
    void Deposit(double num ,string pass);
    void Withdraw( double num , string pass);
    bool Transfer();
    bool checkpin(string pass);
   double getBalance();
    int getId();
    string getPin();
    string getName();

};
