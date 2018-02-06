#pragma once
#include "PieceDecorator.hpp"
class CatSword :
	public PieceDecorator
{
public:
	CatSword(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	}
	void SetPieceMovement();
	~CatSword() {};
};

