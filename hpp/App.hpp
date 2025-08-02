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
    vector<shared_ptr<Movie>> sci_fi_public_favorites;
    vector<shared_ptr<Movie>> action_public_favorites;
    vector<shared_ptr<Movie>> comedy_public_favorites;
    vector<shared_ptr<Movie>> drama_public_favorites;
    vector<shared_ptr<Movie>> horror_public_favorites;

public:
    App(char *files[]);
    void read_movies_file(char *file_address);
    void read_users_file(char *file_address);
    shared_ptr<Movie> find_movie(string name);
    void find_public_favorites();
    vector<shared_ptr<Movie>> find_public_favorites_for_genre(vector<shared_ptr<Movie>> movies);
    vector<shared_ptr<Movie>> find_private_favorites_for_genre(vector<shared_ptr<Movie>> movies, shared_ptr<User> user);
    vector<shared_ptr<Movie>> genre_rec_public(string genre);
    vector<shared_ptr<Movie>> genre_rec_private(string genre);

    void input_test();
};

#endif