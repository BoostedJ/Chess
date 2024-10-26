#include "../include/rook.h"
#include "../include/colors.h"
#include <iostream>

Rook::Rook(const Color color) : Piece(color) {
    for(int i = 1; i <= 7; i++) {
        moves.emplace_back(i, 0);
        moves.emplace_back(0, i);
        moves.emplace_back(0, -i);
        moves.emplace_back(-i, 0);
    }
}

void Rook::print() const {
    cout << (getColor() == Color::White ? colorText(type, WHITE) : colorText(type, BLACK));
}

vector<pair<int, int>> Rook::getMoves() const {
    return moves;
}

string Rook::getName() const {
    return name;
}