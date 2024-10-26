#include "../include/pawn.h"
#include "../include/colors.h"
#include <iostream>


Pawn::Pawn(const Color color) : Piece(color), hasMoved(false), color_mod(color == Color::White ? 1 : -1) {
    moves.emplace_back(0, color_mod*1);
}

void Pawn::print() const {
    cout << (getColor() == Color::White ? colorText(type, WHITE) : colorText(type, BLACK));
}

vector<pair<int, int>> Pawn::getMoves() const {
    vector<pair<int, int>> tempMoves = moves;
    if (!hasMoved) {
        tempMoves.emplace_back(0, color_mod*2);
    }
    return tempMoves;
}

string Pawn::getName() const {
    return name;
}

void Pawn::setHasMoved(bool moved) {
    hasMoved = moved;
}