#pragma once
#include "PieceDecorator.hpp"

//Since piece is abstract this allows for the decoration to take place from a base state
class EmptyPiece :
	public Piece
{
public:
	EmptyPiece(bool white1black0, TextureModule * t):Piece(white1black0, t) {
		//Initialize(white1black0, t);
	}

	 void SetPieceMovement()
	{
		stepMoves = "  ";
		lionMoves = "";
		rangeMoves = " ";
		jumpMoves = "";
		name = "";
		abrName = "";
		abrName2 = "";
		isPromotable = false;

		TextureSetup();
	}
	~EmptyPiece() {};
};

