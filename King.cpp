#include "King.h"

King::King(Player* p, int row, int col, Board* brd)
    : Piece(p, 'K', row, col, brd) {}

bool King::isLegalMove(int dstRow, int dstCol) const {
    int rowDiff = abs(dstRow - this->_row);
    int colDiff = abs(dstCol - this->_col);
    if (rowDiff == 0 && colDiff == 0) {
        return false;
    }
  
    if (rowDiff > 1 || colDiff > 1) {
        return false;
    }

    if (_brd->isPieceOfPlayer(dstRow, dstCol, this->_player)) {
        return false;
    }

    return true;
}
