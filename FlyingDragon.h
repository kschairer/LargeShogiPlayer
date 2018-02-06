#pragma once
#include "PieceDecorator.hpp"
class FlyingDragon :
	public PieceDecorator
{
public:
	FlyingDragon(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~FlyingDragon() {};
};

