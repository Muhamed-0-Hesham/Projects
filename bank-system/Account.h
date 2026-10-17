#pragma once
#include <string>
#include <fstream>
using namespace std;

class Account
{
 private:
    static int nextid;
    int id;
    string name,pin;
    double balance;
    

 public:
    Account();
    Account(string n, double b, string p);

    void createAccount( );
    void deleteAccount(string n, string pass);

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
