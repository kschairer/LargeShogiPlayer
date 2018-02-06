#include "DragonHorse.h"

void DragonHorse::SetPieceMovement()
{
	stepMoves = " K ";
	lionMoves = "";
	rangeMoves = " FR FL BR BL ";
	jumpMoves = "";
	name = "Dragon Horse";
	abrName = "H";
	abrName2 = "D";
	isPromotable = true;

	TextureSetup();
}