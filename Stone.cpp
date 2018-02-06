#include "Stone.h"

void Stone::SetPieceMovement()
{
	stepMoves = " FL FR ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = "  ";
	name = "Stone General";
	abrName2 = "";
	abrName = "St";
	isPromotable = true;


	TextureSetup();
}