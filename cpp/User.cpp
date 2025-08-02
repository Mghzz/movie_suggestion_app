#include "../hpp/User.hpp"

User::User(string _name, vector<pair<Movie, string>> _movies)
{
    name = _name;
    movies = _movies;
}