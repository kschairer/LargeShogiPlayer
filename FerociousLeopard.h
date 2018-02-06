#pragma once
#include "PieceDecorator.hpp"
class FerociousLeopard :
	public PieceDecorator
{
public:
	FerociousLeopard(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~FerociousLeopard() {};
};

