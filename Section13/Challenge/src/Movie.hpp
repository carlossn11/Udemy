#pragma once
#include <string>

class Movie
{
    std::string name;
    std::string rating;
    int watched;
public:
    Movie(std::string name, std::string rating, int watched);
    std::string GetName() { return name; }

};