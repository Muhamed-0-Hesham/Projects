#pragma once
#include <string>
using namespace std;

class Account
{
 private:
    int id;
    string name;
    double balance;

 public:
    Account();
    Account(int i,string n);
    void deposit( );
    void withdraw( );
    bool transfer();
    double getBalance();
    void display();
    void display();
    void createAccount( );
    int getId();
    string getName();
};

class date
{
 private:
    int secound,minute,hour,day,month,year;
 public:
   date(int s,int mi,int h,int d,int mo,int y);
   
};