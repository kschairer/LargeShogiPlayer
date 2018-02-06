#include "Whale.h"

void Whale::SetPieceMovement()
{
	stepMoves = "  ";
	lionMoves = "  ";
	rangeMoves = " F BR B BL ";
	jumpMoves = " ";
	name = "Whale";
	abrName2 = "";
	abrName = "W";
	isPromotable = false;


	TextureSetup();
}
