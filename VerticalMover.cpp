#include "VerticalMover.h"

void VerticalMover::SetPieceMovement()

	{
		stepMoves = " L R ";
		lionMoves = "";
		rangeMoves = " F B ";
		jumpMoves = " ";
		name = "Vertical Mover";
		abrName2 = "V";
		abrName = "M";
		isPromotable = true;


		TextureSetup();
	
}
