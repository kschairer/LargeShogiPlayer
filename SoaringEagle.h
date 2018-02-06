#pragma once
#include "PieceDecorator.hpp"
class SoaringEagle :
	public PieceDecorator
{
public:
	SoaringEagle(Piece *piece, bool white1black0, TextureModule * t) :PieceDecorator(piece, white1black0, t) {

	};
	void SetPieceMovement();
	~SoaringEagle() {};
};

