#pragma once
#include "PieceDecorator.hpp"
class HornedFalcon:public PieceDecorator
{
public:
	HornedFalcon(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~HornedFalcon() {};
};

