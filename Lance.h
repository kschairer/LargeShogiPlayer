#pragma once
#include "PieceDecorator.hpp"
class Lance :
	public PieceDecorator
{
public:
	Lance(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~Lance() {};
};

