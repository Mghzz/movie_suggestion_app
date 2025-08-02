#ifndef USER_HPP
#define USER_HPP
#include "include.hpp"
#include "Movie.hpp"

class User
{
private:
    string name;
    vector<pair<shared_ptr<Movie>, string>> movies;

public:
    User();
    User(string _name, vector<pair<shared_ptr<Movie>, string>> _movies);
    ~User();
};

#endif