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
    IOHandler(App *app);
    void handle_commands();
};

#endif