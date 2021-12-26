#include "Header.hpp"

void VecInput(std::vector <int>& vec)
{
    std::string str = "loop";
    int InputVal;

    while (str != "End!")
    {
        std::cin >> InputVal;
        std::cout << "Input (End!) to stop inputs, or just press enter for next Value: ";
        std::cin >> str;

        if (str != "End!")
            std::cout << ": ";
        vec.push_back(InputVal);
        
    }
}