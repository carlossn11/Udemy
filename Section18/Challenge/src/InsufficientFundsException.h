#ifndef INSUFFICIENT_FUNDS_EXCEPTION_H_
#define INSUFFICIENT_FUNDS_EXCEPTION_H_
#include <exception>

class InsufficientFundsException : public std::exception {
 public:
  InsufficientFundsException() noexcept {}
  ~InsufficientFundsException() {}
  virtual const char* what() const noexcept override {
    return "Withdraw larger than account balance";
  }
};

#endif // INSUFFICIENT_FUNDS_EXCEPTION_H_