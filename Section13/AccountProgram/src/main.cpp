#include <iostream>
#include <string>

class Account 
{
private:
    std::string AccountName;
    int balance;
    double PayRate;
public:
    Account() 
    {
        AccountName = " ";
        balance = 0;
        PayRate = 0;
    }
    int GetBalance() {return balance;}
    void withdraw(double WithdrawAmount)
    {
        if(WithdrawAmount > balance)
            std::cout << "Insufficient Funds!\n";
        else {
            balance -= WithdrawAmount;
        }
    }
    void PayCheck(int HoursWorked)
    {
        balance += PayRate * HoursWorked;
    } 
    void PayCheck(int HoursWorked, double Pay)
    {
        PayRate = Pay;
        balance += PayRate * HoursWorked;
    } 
};

char menu()
{
    char selection {};
    // Menu selection
    std::cout << "Account Program\n";
    std::cout << "Choose from the following options:\n";
    std::cout << "1. Create Bank Account\n";
    std::cout << "2. Check Balance\n";
    std::cout << "3. Deposit Paycheck\n";
    std::cout << "4. Withdraw\n";
    std::cout << "Q to quit program\nEnter selection: ";
    std::cin >> selection;

    return selection;
}

int main()
{
    char choice {};
    Account *ptrAccount {nullptr};
    double pay {0};


    do
    {
        std::cout << "------------------------\n";
        choice = menu();
        //Switch statement to handle directing the users choice
        switch (choice)
        {
        case '1':
        {
            std::string name;
            std::cout << "Enter name of the account: ";
            std::cin >> name;
            std::cout << "Creating Account under: " << name << "\n";
            Account *account {new Account}; //creating class on the heap
            ptrAccount = account; //this block is going out of scope so passing control over of that memory
            break;
        }
        case '2':
        {
            if(ptrAccount == nullptr) // execption handling so if user trys to access account before account is created
                continue;
            std::cout << "Your account balance is: " << (*ptrAccount).GetBalance() << "\n";
            break;
        }
        case '3':
        {
            if(ptrAccount == nullptr) // refer to case 2
                continue;
            int hours {0};

            if(pay == 0)
            {
                std::cout << "How much do you get an hour: ";
                std::cin >> pay;

                std::cout << "How many hours did you work this week: ";
                std::cin >> hours;
                (*ptrAccount).PayCheck(hours, pay);
            }else {
                std::cout << "How many hours did you work this week: ";
                std::cin >> hours;
                (*ptrAccount).PayCheck(hours);
            }
            std::cout << "Your Balance is: " << (*ptrAccount).GetBalance() << "\n";
            break;
        }
        case '4':
        {
            double amount {0};
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            (*ptrAccount).withdraw(amount);
            std::cout << "Your Balance is: " << (*ptrAccount).GetBalance() << "\n";
            break;
        }
        case 'Q': case 'q':
        {
            std::cout << "Thank you!\n";
            break;
        }
        default:
        {
            std::cout << "Invalid selection!\n";
            break;
        }
        }
    } while (choice != 'Q' && choice != 'q');

    delete ptrAccount;
}