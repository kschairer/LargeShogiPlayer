#pragma once
#include "PieceDecorator.hpp"
class Pheonix :
	public PieceDecorator
{
public:
	Pheonix(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~Pheonix() {};
};

