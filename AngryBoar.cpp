#include "AngryBoar.h"

void AngryBoar::SetPieceMovement()
{
	//set specifics of the piece
	stepMoves = " F R B L ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = "  ";
	name = "Angry Boar";
	abrName2 = "A";
	abrName = "B";
	isPromotable = true;


	TextureSetup();
}