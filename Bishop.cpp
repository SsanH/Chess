#include "Bishop.h"

Bishop::Bishop(Player *pl, int row, int col, Board *brd) 
    : Piece(pl, 'B', row, col, brd) {}

bool Bishop::isLegalMove(int dstRow, int dstCol) const {
    int rowDiff = abs(dstRow - this->_row);
    int colDiff = abs(dstCol - this->_col);

    if (rowDiff != colDiff) {
        return false; 
    }

    if (!isWayFree(dstRow, dstCol)) {
        return false; 
    }

    if (_brd->isPieceOfPlayer(dstRow, dstCol, this->_player)) {
        return false;
    }
    return true;
}
