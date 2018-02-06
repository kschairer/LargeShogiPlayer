#pragma once
#include "PieceDecorator.hpp"
class VerticalMover :
	public PieceDecorator
{
public:
	VerticalMover(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~VerticalMover() {};
};

