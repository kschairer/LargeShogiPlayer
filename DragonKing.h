#pragma once
#include "PieceDecorator.hpp"
class DragonKing :
	public PieceDecorator
{
public:
	DragonKing(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~DragonKing() {};
};

