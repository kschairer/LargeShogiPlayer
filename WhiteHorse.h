#pragma once
#include "PieceDecorator.hpp"
class WhiteHorse :
	public PieceDecorator
{
public:
	WhiteHorse(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~WhiteHorse() {};
};

