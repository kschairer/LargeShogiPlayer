#pragma once
#include "PieceDecorator.hpp"
class Gold :
	public PieceDecorator
{
public:
	Gold(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~Gold() {};
};

