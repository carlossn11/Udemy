#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

int main() {
    try {
        std::unique_ptr<Account> ptr_acc = std::make_unique<Checking_Account>("Name", 100.00f);
        ptr_acc->withdraw(100.00f);
        std::cout << *ptr_acc << std::endl;
    }
    catch (const IllegalBalanceException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (const InsufficientFundsException &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

