#include "../include/knight.h"
#include "../include/colors.h"
#include <iostream>

Knight::Knight(const Color color) : Piece(color) {
    for(int i = -1; i <= 1; i++) {
        if(i != 0) {
            moves.emplace_back(i+i, i); // (-2, -1), (2, 1)
            moves.emplace_back(i, i+i); // (-1, -2), (1, 2)
            moves.emplace_back(i+i, -i); // (-2, 1), (2, -1)
            moves.emplace_back(-i, i+i); // (1, -2), (-1, 2)
        }
    }
}

void Knight::print() const {
    cout << (getColor() == Color::White ? colorText(type, WHITE) : colorText(type, BLACK));
}

vector<pair<int, int>> Knight::getMoves() const {
    return moves;
}

string Knight::getName() const {
    return name;
}