#include "../include/CheckingAccount.h"

bool CheckingAccount::withdraw(double amount) {
  const double fee = 1.50;
  amount += fee;
  return Account::withdraw(amount);
}
std::ostream &operator<<(std::ostream &os, const CheckingAccount &checkingAccount) {
  os << "[Checking Account: " << checkingAccount.name << ": ";
  os << checkingAccount.balance << "]";
  return os;
}