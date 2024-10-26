#include "../include/queen.h"
#include "../include/colors.h"
#include <algorithm>
#include <iostream>

Queen::Queen(const Color color) : Piece(color) {
    for(int i = 1; i <= 7; i++) {
        moves.emplace_back(i, i);
        moves.emplace_back(-i, i);
        moves.emplace_back(i, -i);
        moves.emplace_back(-i, -i);
        moves.emplace_back(i, 0);
        moves.emplace_back(0, i);
        moves.emplace_back(-i, 0);
        moves.emplace_back(0, -i);
    }
}

void Queen::print() const {
    cout << (getColor() == Color::White ? colorText(type, WHITE) : colorText(type, BLACK));
}

vector<pair<int, int>> Queen::getMoves() const {
    return moves;
}

string Queen::getName() const {
    return name;
}