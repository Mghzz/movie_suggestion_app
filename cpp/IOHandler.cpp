#include "../hpp/IOHandler.hpp"

IOHandler::IOHandler(App *_app)
{
    app = _app;
}

void IOHandler::handle_commands()
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        std::string command;
        std::vector<std::string> args;

        iss >> command;
        std::string arg;
        while (iss >> std::ws)
        {
            if (iss.peek() == '"')
            {
                iss.get();
                std::getline(iss, arg, '"');
                args.push_back(arg);
            }
            else
            {
                iss >> arg;
                args.push_back(arg);
            }
        }

        std::vector<std::shared_ptr<Movie>> movies;
        if (command == GENRE_REC)
        {
            if (args.size() == 2)
            {
                movies = app->genre_rec_public(args[0]);
            }
            else if (args.size() == 3)
            {
                // movies = app->genre_rec_private(args[0], args[1]);
            }
            print_movies(movies);
        }
        else if (command == CAST_REC)
        {
            if (args.size() == 2)
            {
                // movies = app->cast_rec_public(args[0]);
            }
            else if (args.size() == 3)
            {
                // movies = app->cast_rec_private(args[0], args[1]);
            }
            print_movies(movies);
        }
        else
        {
            std::cout << "INVALID COMMAND" << std::endl;
        }
    }
}

void IOHandler::print_movies(vector<shared_ptr<Movie>> movies)
{
    if (movies.size() > 0)
    {
        for (int i = 0; i < movies.size(); i++)
        {
            cout << to_string(i + 1) + ". " + movies[i]->get_name() + ": " + movies[i]->get_director() + " (" + to_string(movies[i]->get_imdb()) + ")" << endl;
        }
    }
}