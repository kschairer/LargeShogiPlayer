#pragma once
#include "PieceDecorator.hpp"
class GoBetween :
	public PieceDecorator
{
public:
	GoBetween(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~GoBetween() {};
};

