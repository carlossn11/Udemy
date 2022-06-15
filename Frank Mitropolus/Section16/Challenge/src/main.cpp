// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "../include/Account.h"
#include "../include/Savings_Account.h"
#include "../include/Checking_Account.h"
#include "../include/Trust_Account.h"
#include "../include/Account_Util.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
   
    vector<Account*> accounts;
    accounts.push_back(new Savings_Account {} );
    accounts.push_back(new Savings_Account {"Superman"} );
    accounts.push_back(new Savings_Account {"Batman", 2000} );
    accounts.push_back(new Savings_Account {"Wonderwoman", 5000, 5.0} );

    accounts.push_back(new Checking_Account {} );
    accounts.push_back(new Checking_Account {"Kirk"} );
    accounts.push_back(new Checking_Account {"Spock", 2000} );
    accounts.push_back(new Checking_Account {"Bones", 5000} );

    accounts.push_back(new Trust_Account {} );
    accounts.push_back(new Trust_Account {"Athos", 10000, 5.0} );
    accounts.push_back(new Trust_Account {"Porthos", 20000, 4.0} );
    accounts.push_back(new Trust_Account {"Aramis", 30000} );

    display(accounts);
    return 0;
}

