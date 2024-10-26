#ifndef KNIGHT_H
#define KNIGHT_H


#include "piece.h"

class Knight : public Piece {
public:
    explicit Knight(Color);
    string type = "N";
    void print() const override;
    string getName() const override;
    [[nodiscard]] vector<pair<int, int>> getMoves() const override;
private:
    vector<pair<int, int>> moves;
    string name = "knight";
};


#endif //KNIGHT_H
