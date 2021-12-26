#include <iostream>
#include <vector>

int main()
{
    std::vector <int> lst {};
    char selection {};

    do 
    {
        std::cout << "-------------------------------" << "\nP - Print numbers\n" << "A - Add a number\n" << "M - Display mean of the numbers\n" << "S - Display the smallest number\n";
        std::cout << "L - Display the largest number\n" << "Q - Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> selection;

        switch (selection)
        {
        case 'P': {
            if (lst.size() > 0)
            {
                std::cout << "\n[ ";
                for (auto val : lst)
                {
                    std::cout << val << " ";
                }
                std::cout << "]\n";
            }else {
                std::cout << "\n[] - the list is empty\n";
            }
            break;
        }
        case 'A': {
            int integer;
            std::cout << "Enter an integer you would like to add: ";
            std::cin >> integer;

            lst.push_back(integer);
            std::cout << integer << " was added.\n";
            break;
        }
        case 'M': {
            if (lst.size() > 0)
            {
                int Average {0};
                for (auto val : lst)
                {
                    Average += val;
                }
                std::cout << "The mean is: " << Average/lst.size() << "\n";
            }else {
                std::cout << "Unable to calculate the mean - no data\n";
            }
            break;
        }
        case 'S': {
            if (lst.size() > 0)
            {
                for (size_t i {0}; i < lst.size(); i++)
                {
                    for (size_t j {i + 1}; j < lst.size(); j++)
                    {
                        if (lst.at(i) > lst.at(j))
                        {
                            int temp {0};
                            temp = lst.at(i);
                            lst.at(i) = lst.at(j);
                            lst.at(j) = temp;
                        }
                    }
                }
                int SmallestValue {lst.at(0)};
                std::cout << "The smallest number is: " << SmallestValue << "\n";
            }else {
                std::cout << "Unable to determine the smallest number - list is empty.\n";
            }
            break;
        }
        case 'L': {
            if (lst.size() > 0)
            {
                for (size_t i {0}; i < lst.size(); i++)
                {
                    for (size_t j {i + 1}; j < lst.size(); j++)
                    {
                        if (lst.at(i) < lst.at(j))
                        {
                            int temp {0};
                            temp = lst.at(i);
                            lst.at(i) = lst.at(j);
                            lst.at(j) = temp;
                        }
                    }
                }
                int LargestValue {lst.at(0)};
                std::cout << "The largest number is: " << LargestValue << "\n";
            }else {
                std::cout << "Unable to determine the largest number - list is empty.\n";
            }
            break;
        } 
        default: {
            std::cout << "Invalid Input!!!\n";
            break;
        }
        }
    } while (selection != 'Q' && selection != 'q');
}