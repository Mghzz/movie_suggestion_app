#include "../hpp/User.hpp"

User::User(string _name, vector<pair<shared_ptr<Movie>, string>> _movies)
{
    name = _name;
    movies = _movies;

    vector<int> genre_repeats(5, 0);

    for (int i = 0; i < movies.size(); i++)
    {
        int genre_num = genres[movies[i].first->get_genre()];
        genre_repeats[genre_num]++;
    }

    favorite_genre = 0;
    for (int i = 1; i < genre_repeats.size(); i++)
    {
        if (genre_repeats[i] > genre_repeats[favorite_genre])
            favorite_genre = i;
    }
}

string User::get_name()
{
    return name;
}

int User::get_favorite_genre()
{
    return favorite_genre;
}

vector<pair<shared_ptr<Movie>, string>> &User::get_movies()
{
    return movies;
}

int User::find_movie_by_director(string _director)
{
    for (int i = 0; i < movies.size(); i++)
    {
        if (movies[i].first->get_director() == _director)
        {
            if (movies[i].second == PERFECT)
            {
                return 10;
            }
            else if (movies[i].second == AVERAGE)
            {
                return 5;
            }
            else if (movies[i].second == POOR)
            {
                return -1;
            }
        }
    }
    return 0;
}

int User::find_movie_by_cast(string _cast)
{
    for (int i = 0; i < movies.size(); i++)
    {
        if (movies[i].first->get_cast() == _cast)
        {
            if (movies[i].second == PERFECT)
            {
                return 7;
            }
            else if (movies[i].second == AVERAGE)
            {
                return 4;
            }
            else if (movies[i].second == POOR)
            {
                return -2;
            }
        }
    }
    return 0;
}

bool User::seen_movie(shared_ptr<Movie> movie)
{
    for (int i = 0; i < movies.size(); i++)
    {
        if (movies[i].first->get_name() == movie->get_name())
        {
            return true;
        }
    }
    return false;
}