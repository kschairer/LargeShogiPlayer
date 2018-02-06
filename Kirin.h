#pragma once
#include "PieceDecorator.hpp"
class Kirin :
	public PieceDecorator
{
public:
	Kirin(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~Kirin() {};
};

