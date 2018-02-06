#pragma once
#include "PieceDecorator.hpp"
class Pawn :
	public PieceDecorator
{
public:
	Pawn(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~Pawn() {};
};

