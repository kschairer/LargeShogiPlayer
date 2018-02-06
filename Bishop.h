#pragma once
#include "PieceDecorator.hpp"
class Bishop :
	public PieceDecorator
{
public:
	Bishop(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {
		
	};
	void SetPieceMovement();
	~Bishop() {};
};

