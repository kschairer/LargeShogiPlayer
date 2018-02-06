#pragma once
#include "PieceDecorator.hpp"
class DragonHorse :
	public PieceDecorator
{
public:
	DragonHorse(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~DragonHorse() {};
};

