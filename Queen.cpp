#include "Queen.h"

Queen::Queen(Player *p, int row, int col, Board *brd)
    : Piece(p, 'Q', col, row, brd) {}



//a Queen moves like rook and bishop combined, so i need to check if the move is either
//a valid move for bishop or a valid move for rook.
bool Queen::isLegalMove(int dstRow, int dstCol) const {
    int rowDiff = abs(dstRow - this->_row);
    int colDiff = abs(dstCol - this->_col);

    bool isRookMove = (this->_row == dstRow || this->_col == dstCol);
    bool isBishopMove = (rowDiff == colDiff);

    if (!isRookMove && !isBishopMove) {
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
