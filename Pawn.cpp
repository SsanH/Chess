#include "Pawn.h"

Pawn::Pawn(Player *p, int row, int col, Board *brd)
    : Piece(p, 'P', row, col, brd) {}

bool Pawn::isLegalMove(int dstRow, int dstCol) const {

    int rowDiff = dstRow - this->_row;
    int colDiff = abs(dstCol - this->_col);

    int direction = (this->_player->isWhite()) ? 1 : -1;

    if (colDiff == 0) {
        if (rowDiff == direction && _brd->isPieceOfPlayer(dstRow, dstCol, nullptr)) {  // No piece should be in the destination
            return true;
        }

        if (rowDiff == 2 * direction && this->_row == this->_startRow && isWayFree(dstRow, dstCol) && _brd->isPieceOfPlayer(dstRow, dstCol, nullptr)) {
            return true;
        }
    }

    if (colDiff == 1 && rowDiff == direction) {
        if (!_brd->isPieceOfPlayer(dstRow, dstCol, this->_player) && !_brd->isPieceOfPlayer(dstRow, dstCol, nullptr)) {
            return true;
        }
    }

    return false; 
}
