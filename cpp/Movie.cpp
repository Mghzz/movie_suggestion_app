#include "../hpp/Movie.hpp"

Movie::Movie(string _name, string _director, string _cast, string _genre, int _imdb)
{
    name = _name;
    director = _director;
    cast = _cast;
    genre = _genre;
    imdb = _imdb;
}