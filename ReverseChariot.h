#pragma once
#include "PieceDecorator.hpp"
class ReverseChariot :
	public PieceDecorator
{
public:
	ReverseChariot(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~ReverseChariot() {};
};

