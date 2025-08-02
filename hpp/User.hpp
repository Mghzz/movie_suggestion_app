#ifndef USER_HPP
#define USER_HPP
#include "include.hpp"
#include "Movie.hpp"

class User
{
private:
    string name;
    int favorite_genre;
    vector<pair<shared_ptr<Movie>, string>> movies;

public:
    User();
    User(string _name, vector<pair<shared_ptr<Movie>, string>> _movies);
    string get_name();
    vector<pair<shared_ptr<Movie>, string>> &get_movies();
    int find_movie_by_director(string _director);
    int find_movie_by_cast(string _cast);
    bool seen_movie(shared_ptr<Movie> movie);
    int get_favorite_genre();
};

#endif