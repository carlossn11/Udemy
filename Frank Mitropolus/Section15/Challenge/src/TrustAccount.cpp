#include "../include/TrustAccount.h"

bool TrustAccount::deposit(double amount) {
  if (amount >= 5000.00)
    amount += 50.00;
  return Savings_Account::deposit(amount);
}

bool TrustAccount::withdraw(double amount) {
  if (currWithdrawNum < 4) {
    ++this->currWithdrawNum;
    return Savings_Account::withdraw(amount);
  }else {
    std::cout << "OUT FOR THE YEAR SORRY\n";
  }
  return false;
}