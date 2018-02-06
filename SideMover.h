#pragma once
#include "PieceDecorator.hpp"
class SideMover :
	public PieceDecorator
{
public:
	SideMover(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~SideMover() {};
};

