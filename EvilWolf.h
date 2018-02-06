#pragma once
#include "PieceDecorator.hpp"
class EvilWolf :
	public PieceDecorator
{
public:
	EvilWolf(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~EvilWolf() {};
};

