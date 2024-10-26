#ifndef ROOK_H
#define ROOK_H


#include "piece.h"

class Rook : public Piece {
public:
    explicit Rook(Color);
    string type = "R";

    void print() const override;
    string getName() const override;
    [[nodiscard]] vector<pair<int, int>> getMoves() const override;
private:
    vector<pair<int, int>> moves;
    string name = "rook";
};


#endif //ROOK_H
