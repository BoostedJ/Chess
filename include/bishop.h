#ifndef BISHOP_H
#define BISHOP_H


#include "piece.h"

class Bishop : public Piece {
public:
    explicit Bishop(Color);
    string type = "B";
    void print() const override;
    string getName() const override;
    [[nodiscard]] vector<pair<int, int>> getMoves() const override;
private:
    vector<pair<int, int>> moves;
    string name = "bishop";
};


#endif //BISHOP_H
