#pragma once
#include "PieceDecorator.hpp"
class DrunkElephant :
	public PieceDecorator
{
public:
	DrunkElephant(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~DrunkElephant() {};
};

