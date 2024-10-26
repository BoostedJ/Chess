#ifndef KING_H
#define KING_H


#include "piece.h"

class King : public Piece {
public:
    King(Color);
    string type = "K";
    void print() const override;
    string getName() const override;
    [[nodiscard]] vector<pair<int, int>> getMoves() const override;
private:
    vector<pair<int, int>> moves;
    string name = "king";
};


#endif //KING_H
