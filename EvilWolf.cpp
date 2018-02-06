#include "EvilWolf.h"

void EvilWolf::SetPieceMovement()
{
	stepMoves = " FR F FL R L ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = "  ";
	name = "Evil Wolf";
	abrName2 = "E";
	abrName = "W";
	isPromotable = true;


	TextureSetup();
}