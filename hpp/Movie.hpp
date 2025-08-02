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
    int public_score;

public:
    Movie();
    Movie(string _name, string _director, string _cast, string _genre, int _imdb);
    string get_name();
    string get_director();
    int get_imdb();
    void print_info();
    int get_public_score();
    void set_public_score(int _public_score);
};

#endif