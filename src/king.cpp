#include "../include/king.h"
#include "../include/colors.h"
#include <iostream>

King::King(const Color color) : Piece(color) {
    for(int x = -1; x <= 1; x++) {

        for(int y = -1; y <= 1; y++) {

            if(x != 0 && y != 0) {
                moves.emplace_back(x, y);
            }
        }
    }
}

void King::print() const {
    cout << (getColor() == Color::White ? colorText(type, WHITE) : colorText(type, BLACK));
}

vector<pair<int, int>> King::getMoves() const {
    return moves;
}

string King::getName() const {
    return name;
}