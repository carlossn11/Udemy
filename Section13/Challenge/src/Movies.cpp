/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.hpp"

 /*************************************************************************
    Movies no-args constructor
**************************************************************************/
Movies::Movies() 
: vecPtr (nullptr) {
    vecPtr = &movies;

}
Movies::Movies(const Movies &src)
{
    
}

Movies::~Movies() {
}

  /*************************************************************************
    add_movie expects the name of the move, rating and watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    
    If it does then return false since the movie already exists
    Otherwise, create a movie object from the provided information
    and add that movie object to the movies vector and return true
    *********************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched) 
{
    if((*vecPtr).size() == 0)
    {
        Movie movie(name, rating, watched);
        (*vecPtr).push_back(movie);
        return true;
    }else {
        size_t i {0};
        for(auto &movie : *vecPtr)
        {
            if(movie.GetName() == name)
                return false;
            else if(i == ((*vecPtr).size() - 1))
            {
                Movie movie(name, rating, watched);
                (*vecPtr).push_back(movie);
                return true;
            }
            ++i;
        }
    }
}

 /*************************************************************************
    increment_watched expects the name of the move to increment the
    watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    If it does then increment that objects watched by 1 and return true.

    Otherwise, return false since then no movies object with the movie name
    provided exists to increment
    *********************************************************************/
bool Movies::increment_watched(std::string name) 
{
    size_t i {0};
    for(auto &movie : *vecPtr)
    {
        if(movie.GetName() == name)
        {
            movie.incerementWatched();
            return true;
        }else if(i == ((*vecPtr).size() - 1))
            return false;
        ++i;
    }
}

/*************************************************************************
    display
    
    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    *********************************************************************/
void Movies::display() const 
{
    if((*vecPtr).size() == 0)
        std::cout << "No Movies to display\n";
    for(const auto &movie : *vecPtr)
    {
        std::cout << movie.GetName() << "\n";
    }
}