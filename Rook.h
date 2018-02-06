#pragma once
#include "PieceDecorator.hpp"
class Rook :
	public PieceDecorator
{
public:
	Rook(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~Rook() {};
};

