#pragma once
#include "PieceDecorator.hpp"
class King :
	public PieceDecorator
{
public:
	King(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~King() {};
};

