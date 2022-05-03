// Simple Account 
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>
#include "Printable.h"

class Account : public I_Printable {
private:   
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    virtual void print(std::ostream &os) const override {
        os << "[Account: " << name << ": " << balance << "]";
    }
    // Default values if none are passed in then these take its place
    Account(std::string name = def_name, double balance = def_balance);
    // Account(std::string name = "Unamed Account", double balance = 0.0);
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
    virtual double get_balance() const;
    virtual ~Account(){}
};
#endif