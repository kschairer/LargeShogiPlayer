#include "FlyingDragon.h"

void FlyingDragon::SetPieceMovement()
{
	stepMoves = " 2 FL FR BR BL ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = "  ";
	name = "Flying Dragon";
	abrName2 = "F";
	abrName = "D";
	isPromotable = false;


	TextureSetup();
}