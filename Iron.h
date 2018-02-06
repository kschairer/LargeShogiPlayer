#pragma once
#include "PieceDecorator.hpp"
class Iron :
	public PieceDecorator
{
public:
	Iron(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~Iron() {};
};

