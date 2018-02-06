#pragma once
#include "PieceDecorator.hpp"
class Whale :
	public PieceDecorator
{
public:
	Whale(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~Whale() {};
};

