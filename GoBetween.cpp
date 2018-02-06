#include "GoBetween.h"

void GoBetween::SetPieceMovement()
{
	stepMoves = " F B ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = "";
	name = "Go Between";
	abrName2 = "G";
	abrName = "B";
	isPromotable = true;

	TextureSetup();
}
