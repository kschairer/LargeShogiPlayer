#pragma once
#include "PieceDecorator.hpp"
class AngryBoar :
	public PieceDecorator
{
public:
	//calls super and implements the virtual function.
	AngryBoar(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~AngryBoar() {};
};

