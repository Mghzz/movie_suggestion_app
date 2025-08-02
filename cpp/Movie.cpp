#include "../hpp/Movie.hpp"

Movie::Movie(string _name, string _director, string _cast, string _genre, int _imdb)
{
    name = _name;
    director = _director;
    cast = _cast;
    genre = _genre;
    imdb = _imdb;
}

string Movie::get_name()
{
    return name;
}

int Movie::get_imdb()
{
    return imdb;
}

void Movie::print_info()
{
    std::cout << "Name: " << name << "\n"
              << "Director: " << director << "\n"
              << "Cast: " << cast << "\n"
              << "Genre: " << genre << "\n"
              << "IMDb: " << imdb << "\n";
}

int Movie::get_public_score()
{
    return public_score;
}
void Movie::set_public_score(int _public_score)
{
    public_score = _public_score;
}

string Movie::get_director()
{
    return director;
}