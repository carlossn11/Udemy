#ifndef CHECKINGACCOUNT_H_
#define CHECKINGACCOUNT_H_
#include "Account.h"

class CheckingAccount : public Account {
  friend std::ostream &operator<<(std::ostream &os, 
                                  const CheckingAccount &checkingAccount);
 public:
  CheckingAccount(const std::string &name = def_name ,
                  const double &balance = def_balance)
      : Account(name, balance) {}
  bool withdraw(double balance);
 private:
  static constexpr const char* def_name = "Unnamed Checkings";
  static constexpr double def_balance = 0.0f;
};

#endif // CHECKINGACCOUNT_H_