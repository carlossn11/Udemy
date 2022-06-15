#include "Header.hpp"

int func1(std::vector <int>& vec)
{
    int SizeOfVector = vec.size();
    int counter = 0;

    for (int i = 0; i < SizeOfVector; i++)
    {
        for (int j = i + 1; j < SizeOfVector; j++)
        {
            if (vec.at(i) == vec.at(j))
                counter++;
        }
    }
    return counter;
}