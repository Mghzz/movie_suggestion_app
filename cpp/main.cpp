#include "../hpp/include.hpp"
#include "../hpp/App.hpp"
#include "../hpp/IOHandler.hpp"

int main(int argc, char *argv[])
{
    App *ChiBebinam = new App(argv);
    // ChiBebinam->input_test();
    IOHandler handler(ChiBebinam);
    handler.handle_commands();
}