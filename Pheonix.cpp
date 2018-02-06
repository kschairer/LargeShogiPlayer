#include "Pheonix.h"

void Pheonix::SetPieceMovement()
{
	stepMoves = " F L R B ";
	lionMoves = "";
	rangeMoves = "";
	jumpMoves = " FR FL BR BL ";
	name = "Pheonix";
	abrName2 = "";
	abrName = "Ph";
	isPromotable = true;

	TextureSetup();
}