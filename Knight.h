#pragma once
#include "PieceDecorator.hpp"
class Knight :
	public PieceDecorator
{
public:
	Knight(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~Knight() {};
};

