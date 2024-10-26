#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include <array>
using namespace std;

enum class Color {
    White, Black
};

class Piece {
public:
    explicit Piece(const Color color) : color(color) {}
    virtual ~Piece() = default;
    virtual void print() const = 0;
    virtual string getName() const = 0;
    string type;
    [[nodiscard]] Color getColor() const { return color; }
    [[nodiscard]] virtual vector<pair<int, int>> getMoves() const = 0;
private:
    Color color;
    string name;
};


#endif //PIECE_H
