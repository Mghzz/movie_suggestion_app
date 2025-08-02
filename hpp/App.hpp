#ifndef APP_HPP
#define APP_HPP
#include "include.hpp"
#include "Movie.hpp"
#include "User.hpp"

class App
{
private:
    vector<shared_ptr<Movie>> movies;
    vector<shared_ptr<User>> users;
    vector<shared_ptr<Movie>> sci_fi_movies;
    vector<shared_ptr<Movie>> action_movies;
    vector<shared_ptr<Movie>> comedy_movies;
    vector<shared_ptr<Movie>> drama_movies;
    vector<shared_ptr<Movie>> horror_movies;

public:
    App(char *files[]);
};

#endif