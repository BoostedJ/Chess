#ifndef QUEEN_H
#define QUEEN_H


#include "piece.h"

class Queen : public Piece {
public:
    explicit Queen(Color);
    string type = "Q";
    void print() const override;
    string getName() const override;
    [[nodiscard]] vector<pair<int, int>> getMoves() const override;
private:
    vector<pair<int, int>> moves;
    string name = "queen";
};


#endif //QUEEN_H
