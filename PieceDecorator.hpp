#pragma once
#include "Piece.h"

//super class 
//I beleive this is where I get the issue
class PieceDecorator :
	public Piece
{
public:
	Piece *temp;

	virtual void SetPieceMovement() {};
	PieceDecorator(Piece *piece, bool white1black0, TextureModule * t);
	~PieceDecorator() {};
};

