#include <iostream>
#include <string>

int main()
{
    size_t selection {};

    do
    {
        std::cout << "\n---------------------------\n";
        std::cout << "1. Create Letter Pyramid\n" << "2. Quit\n";
        std::cout << "Enter Selection: ";
        std::cin >> selection;

        switch(selection)
        {
            case 1:
            {
                std::string str {};
                std::cout << "Enter string literal: ";
                std::cin >> str;
                size_t strLength {str.length()};                

                for(int i {0}; i < str.length(); i++)
                {

                    for(size_t x {0}; x < strLength; x++)
                        std::cout << " ";

                    for(size_t j {0}; j < i; j++)
                    {
                        std::cout << str.at(j);
                    }
                    std::cout << str.at(i);
                    for(int k {i - 1}; k > -1; k--)
                    {
                        std::cout << str.at(k);
                    }
                    std::cout << std::endl;
                    strLength--;
                }     

                break;
            }
            case 2:
            {
                std::cout << "Thanks!\n";
                break;
            }
            default:
                break;
        }
    } while (selection != 2);
    
}