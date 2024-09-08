#pragma once
#include <iostream>
#include "Piece.h"
#include "Player.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "NullPiece.h"

#define BOARD_SIZE 8

using namespace std;

class Player;
class Piece;

class Board
{
public:
	Board(Player*, Player*);
	~Board();
	void print() const;
	void getString(char res[]) const;
	bool isPieceOfPlayer(int row, int col, Player* pl) const;
	bool tryMove(int srcRow, int srcCol, int dstRow, int dstCol) const;
	Piece** getBoard() const;
	void Move(int srcRow, int srcCol, int dstRow, int dstCol) ;
	void undoLastMove();

private:
	Piece* _brd[BOARD_SIZE][BOARD_SIZE];

	int _lastSrcRow;
	int _lastSrcCol;
	int _lastDstRow;
	int _lastDstCol;
	Piece* _lastPiece;
};