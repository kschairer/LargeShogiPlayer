#pragma once
#include "PieceDecorator.hpp"
class Silver :
	public PieceDecorator
{
public:
	Silver(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~Silver() {};
};

