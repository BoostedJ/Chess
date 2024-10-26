#include "../include/game.h"

#include <limits>
#include <utility>
#include <algorithm>

/**
 * Default constructor for the Game class.
 * It calls the startMenu() function to display the menu options.
 */
Game::Game() {
    startMenu();
}

/**
 * @brief Creates a new board in the game.
 *
 * This function initializes the game board by creating a new instance of the `Board` class.
 *
 * @note The existing board will be replaced by the new one.
 *
 * @see Board
 */
void Game::newBoard() {
    board = Board();
}

/**
 * @brief Displays the start menu of the game and handles user input.
 *
 * The start menu displays a list of options and prompts the user to choose one.
 * The user can start the game, view the help menu, view the tips and tricks menu,
 * or exit the game. The function continuously loops until the user chooses to exit.
 *
 * @return None.
 */
void Game::startMenu() {
    while(true) {
        cout << "1. Start game\n";
        cout << "2. Help/Instructions\n";
        cout << "3. Tips/Tricks\n";
        cout << "4. Exit\n";
        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number between 1-4. \n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                newBoard();
                beginGame();
                break;
            case 2:
                helpMenu();
                break;
            case 3:
                tipsMenu();
                break;
            case 4:
                throw logic_error("exit");
            default:
                cout << "Please enter a number between 1-4.\n";
                choice = -1;
                break;
        }
    }
}

/**
 * Displays the help menu for the game.
 *
 * This function prints the basic rules and controls for the game. It provides information about the coordinate system,
 * game rules, game objective, and menu options
 */
void Game::helpMenu() {
    cout << "\n\nWelcome to Chess!\n"
            "Outlined below are the basic rules and controls for the game:\n"
            "=============================" << endl <<
            "          CONTROLS" << endl <<
            "=============================" << endl <<
            "1. Coordinate System:\n"
            "   - Chess uses coordinate notation for all of the moves.\n"
            "   - Ranks are labeled 1-8 and files are labeled A-H.\n"
            "   - To move a piece, enter the coordinate that it is in and where it should go\n"
            "     - (e.g. e7e4 moves the e7 pawn to e4 on the initialized chessboard.\n\n"
            "=============================" << endl <<
            "            RULES" << endl <<
            "=============================" << endl <<
            "2. Game Rules:\n"
            "   - Each piece type has it's own rules of movement:\n"
            "       - Pawn: Before a pawn has moved, it has the option to move 1 or 2 squares forward.\n"
            "               Once it has moved, it may only move one square forward, and can capture one square diagonally\n"
            "               infront of it.\n"
            "       - Knight: A knight moves two squares in two squares in one direction, then one square\n"
            "                 perpendicular. (e.g. up 2, right 1/ right 2, up 1)\n"
            "       - Bishop: A bishop moves anywhere on a diagonal line starting from it's square.\n"
            "       - Rook: A rook moves anywhere on a straight line starting from it's square.\n"
            "       - Queen: A queen moves like a bishop and a rook simultaneously.\n"
            "       - King: A king can move in any square in the 3x3 grid around it.\n"
            "4. Game Objective:\n"
            "   - Chess is a game played until resignation or checkmate.\n"
            "   - A checkmate is when one player's king is under attack by the other player's piece, and the king has"
            " no escape squares.\n"
            "   - Take turns strategically moving and capturing pieces.\n\n"
            "=============================" << endl <<
            "         MENU OPTIONS" << endl <<
            "=============================" << endl <<
            "5. Menu Options:\n"
            "   - In-game menu options include starting a new game, viewing the rules, tips and tricks, and quitting.\n\n"
            "6. Good Luck and Have Fun!\n"
            "   - May the best strategist win! Enjoy the game and have fun playing Chess!\n"
            "=============================" << endl;
    cout << "Please press Enter or any key to continue..." << endl;
    string io;
    getline(cin, io);
}

/**
*
*/
void Game::tipsMenu() {
    cout << "\n\nWelcome to the chess tips and tricks menu!\n"
            "Outlined below are some basic tips for playing better in the game:\n"
            "=============================" << endl <<
            "            TIPS" << endl <<
            "=============================" << endl <<
            "   Having reached 1400 ELO in Chess rapid and 1900 in puzzles, I understand that of course, there any many\n"
            "different ways to play, and play effectively. Many people will suggest beginners start out with explosive\n"
            "openings, getting pieces off of the board early. Most will rightfully suggest solid openings that are\n"
            "easy to replicate, and hard to counter within the first couple of moves. For some of my personal\n"
            "recommendations that have worked out, see the London System for white, Caro Kann for black the Scotch\n"
            "Game for white, or the King's Indian for black. I believe these openings give a good starting position\n"
            "for either side."
            "   For some more basic and straight-to-the-point tips:\n"
            "       - Try to gain early control of the center of the board\n"
            "       - Don't let your queen out of her starting spot too early, you can blunder her easily\n"
            "       - Every time a piece is moved, think about how the dynamic of the position has changed\n"
            "=============================" << endl <<
            "           TRICKS" << endl <<
            "=============================" << endl <<
            "   Some tricks some people may not know, as they are either ignored or simply not known include:\n"
            "       - en passant: this move allows you to capture a pawn with a pawn if the opponent has made the\n"
            "         initial two-square advance, landing it on one of your pawns' adjacent file and equal rank.\n"
            "       - castling: one of the most important moves in chess; it gets your king out of the center\n"
            "         of the board, and into safety. If the king nor rook has been moved yet, all squares between\n"
            "         the rook and the king are empty, and the king is not in check, nor would the king move through\n"
            "         a square that would put him in check, you can move the king two pieces towards the rook, and\n"
            "         place the rook on the other side.\n"
            "       - pawn promotion: If a pawn manages to get to the other side of the board (e.g. e2 pawn to e8);\n"
            "         you can promote it to any piece (including a queen.)\n";
    cout << "=============================" << endl;
    cout << "Please press Enter or any key to continue..." << endl;
    string io;
    getline(cin, io);
}

/**
 * @brief Parse chess coordinates from a string.
 *
 * This function takes a string representing chess coordinates and returns two pairs of integers.
 * The first pair represents the starting coordinates and the second pair represents the ending coordinates.
 * The string must be exactly 4 characters long and the characters must be valid chess coordinates.
 * Valid coordinates consist of a lowercase letter between 'a' and 'h' (inclusive) representing the file
 * and a digit between '1' and '8' (inclusive) representing the rank.
 *
 * @param coords The string containing the chess coordinates.
 * @return A pair of pairs of integers representing the starting and ending coordinates.
 *
 * @throws std::invalid_argument if the format of the coordinates is invalid.
 */
pair<pair<int, int>, pair<int, int>> Game::parseChessCoordinates(string&coords) {
    coords[0] = tolower(coords[0]);
    coords[2] = tolower(coords[2]);

    if (coords.length() != 4 ||
        coords[0] < 'a' || coords[0] > 'h' ||
        coords[1] < '1' || coords[1] > '8' ||
        coords[2] < 'a' || coords[2] > 'h' ||
        coords[3] < '1' || coords[3] > '8') {
        throw invalid_argument("\nInvalid move format!");
    }

    int startFile = coords[0] - 'a';
    int startRank = 8 - (coords[1] - '0');

    pair<int, int> startPair = make_pair<int, int>(move(startFile), move(startRank));

    int endFile = coords[2] - 'a';
    int endRank = 8 - (coords[3] - '0');

    pair<int, int> endPair = make_pair<int, int>(move(endFile), move(endRank));

    pair<pair<int, int>, pair<int, int>> finalPair =
            make_pair<pair<int, int>, pair<int, int>>(std::move(startPair), std::move(endPair));

    return finalPair;
}

/**
 * Check if there is a blocked path between two positions on the game board.
 * A path can be blocked if there is a piece on any of the positions in between.
 *
 * @param startPos The starting position (pair of integers) on the board.
 * @param endPos The ending position (pair of integers) on the board.
 * @return true if there is a blocked path between startPos and endPos, false otherwise.
 */
bool Game::isPathBlocked(const pair<int, int>& startPos, const pair<int, int>& endPos) {
    int dx = endPos.first - startPos.first;
    int dy = endPos.second - startPos.second;

    if (abs(dx) == abs(dy)) {
        // must be diagonal
        int xDir = dx != 0 ? dx / abs(dy) : 0; // determine positive or negative directions
        int yDir = dy != 0 ? dy / abs(dy) : 0;
        for(int i = 1; i < abs(dx); i++) {
            if (board.pieceAtCoordinate({startPos.first + i * xDir, startPos.second + i * yDir}) != nullptr) {
                return true;
            }
        }
    } else if (dy == 0) {
        int xDir = dx != 0 ? dx / abs(dx) : 0;
        for (int x = 1; x < abs(dx); x++) {
            if (board.pieceAtCoordinate({startPos.first + x * xDir, startPos.second}) != nullptr) {
                return true;
            }
        }
    } else if (dx == 0) {
        int yDir = dy != 0 ? dy / abs(dy) : 0;
        for (int y = 1; y < abs(dy); y++) {
            if (board.pieceAtCoordinate({startPos.first, startPos.second + y * yDir})) {
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Validates a move on the game board.
 *
 * This function validates a move by checking if the piece at the start position can move to the end position.
 * It checks if the move is valid based on the possible relative moves of the piece.
 * It also checks if the path from the start position to the end position is blocked by any other pieces.
 * If the move is valid and the path is not blocked, it makes the move on the game board.
 * Otherwise, it updates the status message with an error message.
 *
 * @param coordinates - The coordinates of the start and end positions of the move.
 */
void Game::validateMove(const pair<pair<int, int>, pair<int, int>>&coordinates) {
    const pair<int, int> startPos = coordinates.first;
    const pair<int, int> endPos = coordinates.second;
    auto piece = board.pieceAtCoordinate(startPos);
    if(piece) {
        const vector<pair<int, int>> possibleRelativeMoves = piece->getMoves();
        bool isValid = false;
        for (const auto& relativeMove: possibleRelativeMoves) {
            const pair<int, int> absoluteMove = make_pair(startPos.first - relativeMove.first,
                                                    startPos.second - relativeMove.second);
            if (endPos.first == absoluteMove.first && endPos.second == absoluteMove.second) {
                auto tempPiece = board.pieceAtCoordinate(endPos);
                if (tempPiece) {
                    if (piece->getColor() == tempPiece->getColor()) {
                        break;
                    }
                }
                isValid = true;
                break;
            }
        }
        if (isValid && !isPathBlocked(startPos, endPos)) {
            board.makeMove(startPos, endPos);
        } else {
            status = "Invalid move for the " + piece->getName() + " at (" +
                 to_string(startPos.first) + ", " + to_string(startPos.second) + ")\n";
        }
    } else {
        status = "There is no piece on (" + to_string(startPos.first) + ", " +
             to_string(startPos.second) + ")\n";
    }
}

/**
 * @brief Begin the game and handle player moves
 *
 * This function starts the game and allows the player to make moves. It continuously prompts the player for a move
 * until the player enters -1 to exit the game. It displays the current state of the game board and the status message.
 * It parses the player's input for coordinates and validates the move by checking if it is a valid position and if the
 * piece at the start position can make the specified move. If the move is valid, it updates the game board
 * accordingly. If the move is invalid, it updates the status message with an appropriate error message.
 */
void Game::beginGame() {
    while (true) {
        string input;
        board.printBoard();
        cout << status;
        cout << "Enter a move in coordinate notation (e.g. e7e4) or -1 to exit: ";
        getline(cin, input);
        if (input == "-1") {
            return;
        }
        try {
            pair<pair<int, int>, pair<int, int>> coordinates = parseChessCoordinates(input);

            validateMove(coordinates);
        }
        catch (const exception&e) {
            cerr << "\nInvalid move. Please try again." << endl;
        }
    }
}
