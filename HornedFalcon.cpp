#include "HornedFalcon.h"

void HornedFalcon::SetPieceMovement()
{
	stepMoves = "  ";
	lionMoves = " F ";
	rangeMoves = " FR R BR B BL L FL ";
	jumpMoves = " ";
	name = "Horned Falcon";
	abrName2 = "H";
	abrName = "F";
	isPromotable = false;


	TextureSetup();
}
