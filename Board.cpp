#include "Board.h"

Board::Board(Player* p1, Player* p2) {
    // all board to null piece
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            _brd[i][j] = new NullPiece(i, j);
        }
    }

    //pawns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        delete _brd[1][i]; 
        delete _brd[6][i];
        _brd[6][i] = new Pawn(p2, 6, i, this);
    }

    //rooks
    _brd[0][0] = new Rook(p1, 0, 0, this); 
    _brd[0][7] = new Rook(p1, 0, 7, this); 
    _brd[7][0] = new Rook(p2, 7, 0, this); 
    _brd[7][7] = new Rook(p2, 7, 7, this); 

    //knights
    _brd[0][1] = new Knight(p1, 0, 1, this);
    _brd[0][6] = new Knight(p1, 0, 6, this);
    _brd[7][1] = new Knight(p2, 7, 1, this);
    _brd[7][6] = new Knight(p2, 7, 1, this);

    //bishops
    _brd[0][2] = new Bishop(p1, 0, 2, this);
    _brd[0][5] = new Bishop(p1, 0, 5, this);
    _brd[7][2] = new Bishop(p2, 7, 2, this);
    _brd[7][5] = new Bishop(p2, 7, 5, this);

    //royalty
    _brd[0][3] = new Queen(p1, 0, 3, this);    
    _brd[0][4] = new King(p1, 0, 4, this);     

    _brd[7][3] = new Queen(p2, 7, 3, this);   
    _brd[7][4] = new King(p2, 7, 4, this);    


}
Piece **Board::getBoard() const
{
    return (Piece**) _brd;
}


Board::~Board() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            delete _brd[i][j];  // Delete each piece if it exists
        }
    }
}

void Board::print() const {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (_brd[i][j] != nullptr) {
                cout << _brd[i][j]->getSign() << " ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}


void Board::getString(char res[]) const {
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (_brd[i][j] != nullptr) {
                res[index++] = _brd[i][j]->getSign();
            } else {
                res[index++] = '#';
            }
        }
    }
    res[index++] = '0';
    res[index] = 0;
}

bool Board::tryMove(int srcRow, int srcCol, int dstRow, int dstCol) const {
    if (_brd[srcRow][srcCol] != nullptr && _brd[srcRow][srcCol]->isLegalMove(dstRow, dstCol)) {
        if (!isPieceOfPlayer(dstRow, dstCol, _brd[srcRow][srcCol]->getPlayer())) {
            return true;  //can Move
        }
    }
    return false;
}


bool Board::isPieceOfPlayer(int row, int col, Player *pl) const
{
    Piece* piece = _brd[row][col];
    return piece != nullptr && piece->getPlayer() == pl;
}


void Board::Move(int srcRow, int srcCol, int dstRow, int dstCol) {
    if (tryMove(srcRow, srcCol, dstRow, dstCol)) {
        _lastSrcRow = srcRow;
        _lastSrcCol = srcCol;
        _lastDstRow = dstRow;
        _lastDstCol = dstCol;
        _lastPiece = _brd[dstRow][dstCol]; 

        _brd[dstRow][dstCol] = _brd[srcRow][srcCol];
        _brd[srcRow][srcCol] = nullptr;

        _brd[dstRow][dstCol]->setPosition(dstRow, dstCol);
    }
}


//a single move will affect at most 2 pieces, therefore this will reverse the last move
void Board::undoLastMove() {
    _brd[_lastSrcRow][_lastSrcCol] = _brd[_lastDstRow][_lastDstCol];
    _brd[_lastSrcRow][_lastSrcCol]->setPosition(_lastSrcRow, _lastSrcCol);

    _brd[_lastDstRow][_lastDstCol] = _lastPiece;
}