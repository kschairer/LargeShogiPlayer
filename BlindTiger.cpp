#include "BlindTiger.h"

void BlindTiger::SetPieceMovement()
{
	stepMoves = " FR FL L R BR BL B ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = "";
	name = "Blind Tiger";
	abrName = "T";
	abrName2 = "B";
	isPromotable = true;

	TextureSetup();
}