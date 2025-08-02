#ifndef IOHANDLER_HPP
#define IOHANDLER_HPP
#include "include.hpp"
#include "App.hpp"
class App;
class IOHandler
{
private:
    App *app;

public:
    IOHandler(App *_app);
    void handle_commands();
    void print_movies(vector<shared_ptr<Movie>> movies);
};

#endif