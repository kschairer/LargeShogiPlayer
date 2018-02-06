#pragma once
#include "PieceDecorator.hpp"
class FlyingStag :
	public PieceDecorator
{
public:
	FlyingStag(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~FlyingStag() {};
};

