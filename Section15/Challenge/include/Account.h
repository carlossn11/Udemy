// Simple Account 
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

class Account {
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
private:   
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    // Default values if none are passed in then these take its place
    Account(std::string name = def_name, double balance = def_balance);
    // Account(std::string name = "Unamed Account", double balance = 0.0);
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
    virtual double get_balance() const;
    virtual ~Account(){}
};
#endif