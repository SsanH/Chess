#include "Knight.h"



Knight::Knight(Player* p, int row, int col, Board* brd) 
: Piece(p, 'N', row, col, brd) {}

bool Knight::isLegalMove(int dstRow, int dstCol) const {
    int rowDiff = abs(dstRow - this->_row);
    int colDiff = abs(dstCol - this->_col);

    return ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2));
}
