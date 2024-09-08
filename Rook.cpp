#include "Rook.h"

Rook::Rook(Player* p, int row, int col, Board* brd)
    : Piece(p, 'R', row, col, brd) {}

bool Rook::isLegalMove(int dstRow, int dstCol) const {
    if (this->_row != dstRow && this->_col != dstCol) {
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
