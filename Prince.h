#pragma once
#include "PieceDecorator.hpp"
class Prince :
	public PieceDecorator
{
public:
	Prince(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~Prince() {};
};

