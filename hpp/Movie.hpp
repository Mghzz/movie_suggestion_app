#ifndef MOVIE_HPP
#define MOVIE_HPP
#include "include.hpp"

class Movie
{
private:
    string name;
    string director;
    string cast;
    string genre;
    int imdb;

public:
    Movie();
    Movie(string _name, string _director, string _cast, string _genre, int _imdb);
    string get_name();
    int get_imdb();
    void print_info();
};

#endif