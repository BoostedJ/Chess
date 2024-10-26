#ifndef GAME_H
#define GAME_H


#include <utility>

#include "board.h"

class Game {
public:
    Game();
    void startMenu();
    void beginGame();
    static void helpMenu();
    static void tipsMenu();
    void newBoard();
    static pair<pair<int, int>,pair<int, int>> parseChessCoordinates(string&);
    bool isPathBlocked(const pair<int, int>&, const pair<int, int>&);
    void validateMove(const pair<pair<int, int>, pair<int, int>>&);
private:
    Board board;
    string status = "";
};


#endif //GAME_H