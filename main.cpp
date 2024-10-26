#include <iostream>
#include "include/game.h"

/**
 * @file main.cpp
 * @brief Program entry point
 */
int main() {
    try {
        system("chcp 65001");
        Game game;
        game.startMenu();
    }
    catch(const logic_error& e) {
        if(string(e.what()) == "exit") {
            return EXIT_SUCCESS;
        } else {
            cerr << "Caught logic_error exception: " << e.what() << '\n';
        }
    }
    catch(const exception& e) {
            cerr << "Caught an exception of type " << typeid(e).name() << ": " << e.what() << '\n';
    }
    return 0;
}
