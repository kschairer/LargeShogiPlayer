#include "SideMover.h"

void SideMover::SetPieceMovement()
{
	stepMoves = " F B ";
	lionMoves = "";
	rangeMoves = " L R ";
	jumpMoves = " ";
	name = "Side Mover";
	abrName2 = "S";
	abrName = "M";
	isPromotable = true;


	TextureSetup();
}