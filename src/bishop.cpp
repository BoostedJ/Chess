#include "../include/bishop.h"
#include "../include/colors.h"
#include <iostream>

Bishop::Bishop(const Color color) : Piece(color) {
    for(int i = 1; i <= 7; i++) {
        moves.emplace_back(i, i);
        moves.emplace_back(-i, i);
        moves.emplace_back(i, -i);
        moves.emplace_back(-i, -i);
    }
}
void Bishop::print() const {
    cout << (getColor() == Color::White ? colorText(type, WHITE) : colorText(type, BLACK));
}

vector<pair<int, int>> Bishop::getMoves() const {
    return moves;
}

string Bishop::getName() const {
    return name;
}