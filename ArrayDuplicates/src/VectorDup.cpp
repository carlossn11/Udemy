#include "Header.hpp"

int main()
{
    std::vector <int> vec;
    std::cout << "Input array: ";

    VecInput(vec);
    int Output = {func1(vec)};

    std::cout << "\nThe number of Duplicates in this vector is: " << Output << "\n\n";

}