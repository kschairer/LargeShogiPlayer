#include "ReverseChariot.h"

void ReverseChariot::SetPieceMovement()
{
	stepMoves = "  ";
	lionMoves = "";
	rangeMoves = " F B ";
	jumpMoves = "  ";
	name = "Reverse Chariot";
	abrName2 = "R";
	abrName = "C";
	isPromotable = true;

	TextureSetup();
}