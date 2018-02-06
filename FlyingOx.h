#pragma once
#include "PieceDecorator.hpp"
class FlyingOx :
	public PieceDecorator
{
public:
	FlyingOx(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~FlyingOx() {};
};

