#pragma once
#include "PieceDecorator.hpp"
class ViolentOx :
	public PieceDecorator
{
public:
	ViolentOx(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~ViolentOx() {};
};

