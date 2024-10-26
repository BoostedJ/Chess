#ifndef BOARD_H
#define BOARD_H


#include <iostream>
#include <vector>
#include <memory>
#include "piece.h"
#include "pieces.h"

class Board {
public:
    Board();

    static constexpr int SIZE = 8;
    vector<vector<shared_ptr<Piece>>> board;

    void printBoard() const;
    shared_ptr<Piece> pieceAtCoordinate(pair<int, int>);
    void makeMove(pair<int, int>, pair<int, int>);
};
/*
 * board represented in code
 * 0[ ][ ][ ][ ][ ][ ][ ][ ]
 * 1[ ][ ][ ][ ][ ][ ][ ][ ]
 * 2[ ][ ][ ][ ][ ][ ][ ][ ]
 * 3[ ][ ][ ][ ][ ][ ][ ][ ]
 * 4[ ][ ][ ][ ][ ][ ][ ][ ]
 * 5[ ][ ][ ][ ][ ][ ][ ][ ]
 * 6[ ][ ][ ][ ][ ][ ][ ][ ]
 * 7[ ][ ][ ][ ][ ][ ][ ][ ]
 *   0  1  2  3  4  5  6  7
 */


#endif //BOARD_H
