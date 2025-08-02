#include "../hpp/User.hpp"

User::User(string _name, vector<pair<shared_ptr<Movie>, string>> _movies)
{
    name = _name;
    movies = _movies;
}

string User::get_name()
{
    return name;
}

vector<pair<shared_ptr<Movie>, string>> &User::get_movies()
{
    return movies;
}