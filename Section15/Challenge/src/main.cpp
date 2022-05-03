// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "../include/Savings_Account.h"
#include "../include/Account_Util.h"
#include "../include/CheckingAccount.h"

int main() {
    std::cout.precision(2);
    std::cout << std::fixed;
   
    // Accounts
    std::vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 

    std::vector<Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    std::vector<Account> checkingAccounts;
    checkingAccounts.push_back({});
    checkingAccounts.push_back({"Carlos"});
    checkingAccounts.push_back({"LOSSS", 10000});

    display(checkingAccounts);
    deposit(checkingAccounts, 1000);
    withdraw(checkingAccounts, 2000);

    Account* ptr1 = new Savings_Account();


    display(checkingAccounts);
    deposit(checkingAccounts, 1000);
    withdraw(checkingAccounts, 2000);

    return 0;
}

