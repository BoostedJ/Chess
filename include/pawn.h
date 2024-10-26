#ifndef PAWN_H
#define PAWN_H


#include "piece.h"

class Pawn : public Piece {
public:
    explicit Pawn(Color);
    bool hasMoved;
    string type = "p";
    void print() const override;
    string getName() const override;
    [[nodiscard]] vector<pair<int, int>> getMoves() const override;
    void setHasMoved(bool);
private:
    vector<pair<int, int>> moves;
    string name = "pawn";
    int color_mod;
};


#endif //PAWN_H
