#pragma once
#include "PieceDecorator.hpp"
class Queen :
	public PieceDecorator
{
public:
	Queen(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();

	~Queen() {};
};

