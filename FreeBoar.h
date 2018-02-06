#pragma once
#include "PieceDecorator.hpp"
class FreeBoar :
	public PieceDecorator
{
public:
	FreeBoar(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();

	~FreeBoar() {};
};

