#ifndef TRUSTACCOUNT_H_
#define TRUSTACCOUNT_H_
#include "Savings_Account.h"

class TrustAccount : public Savings_Account {
 public:
  TrustAccount(std::string name = def_name, double balance = def_balance,
               double interestRate = def_int_rate)
      : Savings_Account(name, balance, interestRate), currWithdrawNum(1) {}
  bool deposit(double amount);
  bool withdraw(double amount);
 private:
  int currWithdrawNum;
  static constexpr const char* def_name = "Unnamed Trust";
  static constexpr double def_balance = 0.0;
  static constexpr double def_int_rate = 0.0;

};

#endif // TRUSTACCOUNT_H_