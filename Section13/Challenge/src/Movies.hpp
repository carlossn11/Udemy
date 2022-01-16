/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movie as a std::vector
 *  implement these methods in Movies.cpp
 *
 * ***************************************************************/

#pragma once
#include <vector>
#include <string>
#include "Movie.hpp"

class Movies
{
private:
    std::vector<Movie> movies;
public:
    Movies();             // Constructor
    ~Movies();          // Destructor
    bool add_movie(std::string name, std::string rating, int watched);
    bool increment_watched(std::string name);
    void display() const;
};