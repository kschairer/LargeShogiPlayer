#include "SoaringEagle.h"

void SoaringEagle::SetPieceMovement()
{
	stepMoves = "  ";
	lionMoves = " FR FL ";
	rangeMoves = " F R BR B BL L ";
	jumpMoves = " ";
	name = "Soaring Eagle";
	abrName2 = "S";
	abrName = "E";
	isPromotable = false;


	TextureSetup();
}