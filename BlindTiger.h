#pragma once
#include "PieceDecorator.hpp"
class BlindTiger :
	public PieceDecorator
{
public:
	BlindTiger(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~BlindTiger() {};
};