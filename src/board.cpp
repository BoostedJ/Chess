#include "../include/board.h"

/**
 * @brief Default constructor for the Board class.
 *
 * This constructor initializes the board with a size of 8x8 and sets all elements to nullptr.
 * It then sets up the initial positions of the pieces on the board, with black pawns in the second row,
 * white pawns in the seventh row, and the remaining pieces in the first and eighth rows.
 *
 */
Board::Board() {
    // initialize board with nullptr
    board.resize(SIZE, vector<shared_ptr<Piece>>(SIZE, nullptr));

    for (int i = 0; i < SIZE; i++) {
        board[1][i] = make_shared<Pawn>(Color::Black);
        board[6][i] = make_shared<Pawn>(Color::White);
        if (i == 0 || i == 7) {
            board[0][i] = make_shared<Rook>(Color::Black);
            board[7][i] = make_shared<Rook>(Color::White);
        } else if (i == 1 || i == 6) {
            board[0][i] = make_shared<Knight>(Color::Black);
            board[7][i] = make_shared<Knight>(Color::White);
        } else if (i == 2 || i == 5) {
            board[0][i] = make_shared<Bishop>(Color::Black);
            board[7][i] = make_shared<Bishop>(Color::White);
        } else if (i == 3) {
            board[0][i] = make_shared<Queen>(Color::Black);
            board[7][i] = make_shared<Queen>(Color::White);
        } else if (i == 4) {
            board[0][i] = make_shared<King>(Color::Black);
            board[7][i] = make_shared<King>(Color::White);
        }
    }
}

/**
 * @brief Prints the current state of the board.
 *
 * This function prints the board, including the pieces and the borders.
 * It uses Unicode characters to create a visually appealing representation of the board.
 *
 * @note The function itself does not return any value.
 */
void Board::printBoard() const {
    // print top border of board first
    cout << "\n  ┍";
    for (int col = 0; col < SIZE; col++) {
        cout << "───";
        cout << (col < SIZE - 1 ? "┬" : "┑");
    }
    cout << endl;

    // print each row
    string letter = "A";
    for (int row = 0; row < SIZE; row++) {
        cout << 8 - row << " │";
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col]) {
                cout << " ";
                board[row][col]->print();
                cout << " ";
            } else {
                cout << "   ";
            }
            cout << "│";
        }
        cout << endl;

        if (row < SIZE - 1) {
            cout << "  ├";
            for (int col = 0; col < SIZE; col++) {
                cout << "───";
                cout << (col < SIZE - 1 ? "┼" : "┤");
            }
            cout << endl;
        }
    }

    cout << "  ┕";
    for (int col = 0; col < SIZE; col++) {
        cout << "───";
        cout << (col < SIZE - 1 ? "┴" : "┙");
    }

    cout << endl << "    A   B   C   D   E   F   G   H" << endl;
}

/**
 * @brief Retrieves the piece at the given coordinate on the board.
 *
 * This function returns a shared pointer to the piece located at the specified
 * coordinate on the board. If the coordinate is out of bounds, this function
 * returns a null pointer.
 *
 * @param coordinate The coordinate of the piece to retrieve.
 * @return A shared pointer to the piece at the specified coordinate, or nullptr
 * if the coordinate is out of bounds.
 */
shared_ptr<Piece> Board::pieceAtCoordinate(pair<int, int> coordinate) {
    if (coordinate.first >= 0 && coordinate.first < SIZE && coordinate.second >= 0 && coordinate.second < SIZE) {
        return board[coordinate.second][coordinate.first];
    } else {
        return nullptr;
    }
}

/**
 * @brief Moves a piece on the board from one position to another.
 *
 * This function moves a piece on the board from the start position to the new position.
 * It first gets the piece at the start position, sets the start position to nullptr,
 * and then sets the new position with the moved piece.
 *
 * If the piece is a Pawn, it sets the hasMoved flag to true.
 *
 * @param startPos The starting position of the piece to move.
 * @param newPos The new position to move the piece to.
 */
void Board::makeMove(pair<int, int> startPos, pair<int, int> newPos) {
    auto piece = board[startPos.second][startPos.first];
    board[startPos.second][startPos.first] = nullptr;
    board[newPos.second][newPos.first] = std::move(piece);

    Pawn* pawn = dynamic_cast<Pawn*>(board[newPos.second][newPos.first].get());
    if(pawn) {
        pawn->setHasMoved(true);
    }
}