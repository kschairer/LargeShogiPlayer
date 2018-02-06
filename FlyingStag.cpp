#include "FlyingStag.h"

void FlyingStag::SetPieceMovement()
{
	stepMoves = " K ";
	lionMoves = "";
	rangeMoves = " F B ";
	jumpMoves = "";
	name = "Flying Stag";
	abrName = "S";
	abrName2 = "F";
	isPromotable = false;


	TextureSetup();
}
