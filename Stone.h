#pragma once
#include "PieceDecorator.hpp"
class Stone :
	public PieceDecorator
{
public:
	Stone(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~Stone() {};
};

