#pragma once
#include "PieceDecorator.hpp"
class Copper :
	public PieceDecorator
{
public:
	Copper(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~Copper() {};
};

