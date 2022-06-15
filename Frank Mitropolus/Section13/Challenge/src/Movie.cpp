#include "Movie.hpp"
#include <string>

Movie::Movie(std::string name, std::string rating, int watched)
{
    this -> name = name;
    this -> rating = rating;
    this -> watched = watched;
}