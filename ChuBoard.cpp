#include "ChuBoard.h"
#include "EmptyPiece.h"
#include "Piece.h"
#include "Bishop.h" 
#include "Rook.h"
#include "Pawn.h"
#include "AngryBoar.h"
#include "BlindTiger.h"
#include "CatSword.h"
#include "Copper.h"
#include "DragonHorse.h"
#include "DragonKing.h"
#include "DrunkElephant.h"
#include "EvilWolf.h"
#include "FerociousLeopard.h"
#include "FlyingDragon.h"
#include "FlyingOx.h"
#include "FlyingStag.h"
#include "FreeBoar.h"
#include "Gold.h"
#include "GoBetween.h"
#include "HornedFalcon.h"
#include "Iron.h"
#include "King.h"
#include "Kirin.h"
#include "Knight.h"
#include "Lance.h"
#include "Lion.h"
#include "Pheonix.h"
#include "Piece.h"
#include "Queen.h"
#include"ReverseChariot.h"
#include "Silver.h"
#include "SideMover.h"
#include "SoaringEagle.h"
#include "Stone.h"
#include "VerticalMover.h"
#include "ViolentOx.h"
#include"Whale.h"
#include"WhiteHorse.h"
#include "PieceFactory.h"

ChuBoard::ChuBoard()
{
	Board();
	width = 12;
	height = 12;
	size = 144;
	name = "Chu";

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			board.push_back(Space(j * 50 + 225, i * 50 + 197, j, i));
		}
	}
}

void ChuBoard::SetupPieces(TextureModule *t)
{
	Piece* newPiece;

	//Bishop

	////replace this
	//newPiece = new Piece(1, t);
	//newPiece->SetBishop();
	////with this
	newPiece = PieceFactory::createPiece(PieceFactory::BISHOP, new EmptyPiece(1,t));

	board[Index(2, 1)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::BISHOP, new EmptyPiece(1, t));
	board[Index(9, 1)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::BISHOP, new EmptyPiece(0, t));
	board[Index(2, 10)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::BISHOP, new EmptyPiece(0, t));
	board[Index(9, 10)].Occupy(newPiece);

	//Blind Tiger
	newPiece = PieceFactory::createPiece(PieceFactory::BLINDTIGER, new EmptyPiece(1, t));

	board[Index(4, 1)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::BLINDTIGER, new EmptyPiece(1, t));
	board[Index(7, 1)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::BLINDTIGER, new EmptyPiece(0, t));
	board[Index(4, 10)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::BLINDTIGER, new EmptyPiece(0, t));
	board[Index(7, 10)].Occupy(newPiece);



	//Copper General 
	newPiece = PieceFactory::createPiece(PieceFactory::COPPER, new EmptyPiece(1, t));
	board[Index(2, 0)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::COPPER, new EmptyPiece(1, t));
	board[Index(9, 0)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::COPPER, new EmptyPiece(0, t));
	board[Index(2, 11)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::COPPER, new EmptyPiece(0, t));
	board[Index(9, 11)].Occupy(newPiece);

	//Drunk Elephant
	newPiece = PieceFactory::createPiece(PieceFactory::DRUNKELEPHANT, new EmptyPiece(1, t));
	board[Index(5, 0)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::DRUNKELEPHANT, new EmptyPiece(0, t));
	board[Index(6, 11)].Occupy(newPiece);

	//Dragon Horse 
	newPiece = PieceFactory::createPiece(PieceFactory::DRAGONHORSE, new EmptyPiece(1, t));
	board[Index(3, 2)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::DRAGONHORSE, new EmptyPiece(1, t));
	board[Index(8, 2)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::DRAGONHORSE, new EmptyPiece(0, t));
	board[Index(3, 9)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::DRAGONHORSE, new EmptyPiece(0, t));
	board[Index(8, 9)].Occupy(newPiece);

	//Dragon King 
	newPiece = PieceFactory::createPiece(PieceFactory::DRAGONKING, new EmptyPiece(1, t));
	board[Index(4, 2)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::DRAGONKING, new EmptyPiece(1, t));
	board[Index(7, 2)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::DRAGONKING, new EmptyPiece(0, t));
	board[Index(4, 9)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::DRAGONKING, new EmptyPiece(0, t));
	board[Index(7, 9)].Occupy(newPiece);

	//Ferocious Leopard
	newPiece = PieceFactory::createPiece(PieceFactory::FEROCIOUSLEOPARD, new EmptyPiece(1, t));
	board[Index(1, 0)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::FEROCIOUSLEOPARD, new EmptyPiece(1, t));
	board[Index(10, 0)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::FEROCIOUSLEOPARD, new EmptyPiece(0, t));
	board[Index(1, 11)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::FEROCIOUSLEOPARD, new EmptyPiece(0, t));
	board[Index(10, 11)].Occupy(newPiece);

	//Gold General
	newPiece = PieceFactory::createPiece(PieceFactory::GOLD, new EmptyPiece(1, t));
	board[Index(4, 0)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::GOLD, new EmptyPiece(1, t));
	board[Index(7, 0)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::GOLD, new EmptyPiece(0, t));
	board[Index(4, 11)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::GOLD, new EmptyPiece(0, t));
	board[Index(7, 11)].Occupy(newPiece);

	//Go between
	newPiece = PieceFactory::createPiece(PieceFactory::GOBETWEEN, new EmptyPiece(1, t));
	board[Index(3, 4)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::GOBETWEEN, new EmptyPiece(1, t));
	board[Index(8, 4)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::GOBETWEEN, new EmptyPiece(0, t));
	board[Index(3, 7)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::GOBETWEEN, new EmptyPiece(0, t));
	board[Index(8, 7)].Occupy(newPiece);


	//King
	newPiece = PieceFactory::createPiece(PieceFactory::KING, new EmptyPiece(1, t));
	board[Index(6, 0)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::KING, new EmptyPiece(0, t));
	board[Index(5, 11)].Occupy(newPiece);

	//Kirin
	newPiece = PieceFactory::createPiece(PieceFactory::KIRIN, new EmptyPiece(1, t));
	board[Index(6, 1)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::KIRIN, new EmptyPiece(0, t));
	board[Index(5, 10)].Occupy(newPiece);

	//Lance
	newPiece = PieceFactory::createPiece(PieceFactory::LANCE, new EmptyPiece(1, t));
	board[Index(0, 0)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::LANCE, new EmptyPiece(1, t));
	board[Index(11, 0)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::LANCE, new EmptyPiece(0, t));
	board[Index(0, 11)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::LANCE, new EmptyPiece(0, t));
	board[Index(11, 11)].Occupy(newPiece);

	//Lion
	newPiece = PieceFactory::createPiece(PieceFactory::LION, new EmptyPiece(1, t));
	board[Index(6, 2)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::LION, new EmptyPiece(0, t));
	board[Index(5, 9)].Occupy(newPiece);

	//Pheonix
	newPiece = PieceFactory::createPiece(PieceFactory::PHEONIX, new EmptyPiece(1, t));
	board[Index(5, 1)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::PHEONIX, new EmptyPiece(0, t));
	board[Index(6, 10)].Occupy(newPiece);

	//Queen
	newPiece = PieceFactory::createPiece(PieceFactory::QUEEN, new EmptyPiece(1, t));
	board[Index(5, 2)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::QUEEN, new EmptyPiece(0, t));
	board[Index(6, 9)].Occupy(newPiece);

	//Rook
	newPiece = PieceFactory::createPiece(PieceFactory::ROOK, new EmptyPiece(1, t));
	board[Index(2, 2)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::ROOK, new EmptyPiece(1, t));
	board[Index(9, 2)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::ROOK, new EmptyPiece(0, t));
	board[Index(2, 9)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::ROOK, new EmptyPiece(0, t));
	board[Index(9, 9)].Occupy(newPiece);

	//Reverse Chariot
	newPiece = PieceFactory::createPiece(PieceFactory::REVERSECHARIOT, new EmptyPiece(1, t));
	board[Index(0, 1)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::REVERSECHARIOT, new EmptyPiece(1, t));
	board[Index(11, 1)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::REVERSECHARIOT, new EmptyPiece(0, t));
	board[Index(0, 10)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::REVERSECHARIOT, new EmptyPiece(0, t));
	board[Index(11, 10)].Occupy(newPiece);

	//Silver
	newPiece = PieceFactory::createPiece(PieceFactory::SILVER, new EmptyPiece(1, t));
	board[Index(3, 0)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::SILVER, new EmptyPiece(1, t));
	board[Index(8, 0)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::SILVER, new EmptyPiece(0, t));
	board[Index(3, 11)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::SILVER, new EmptyPiece(0, t));
	board[Index(8, 11)].Occupy(newPiece);

	//Side Mover
	newPiece = PieceFactory::createPiece(PieceFactory::SIDEMOVER, new EmptyPiece(1, t));
	board[Index(1, 2)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::SIDEMOVER, new EmptyPiece(1, t));
	board[Index(10, 2)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::SIDEMOVER, new EmptyPiece(0, t));
	board[Index(1, 9)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::SIDEMOVER, new EmptyPiece(0, t));
	board[Index(10, 9)].Occupy(newPiece);

	//Vertical Mover
	newPiece = PieceFactory::createPiece(PieceFactory::VERTICALMOVER, new EmptyPiece(1, t));
	board[Index(0, 2)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::VERTICALMOVER, new EmptyPiece(1, t));
	board[Index(11, 2)].Occupy(newPiece);

	newPiece = PieceFactory::createPiece(PieceFactory::VERTICALMOVER, new EmptyPiece(0, t));
	board[Index(0, 9)].Occupy(newPiece);

	 newPiece = PieceFactory::createPiece(PieceFactory::VERTICALMOVER, new EmptyPiece(0, t));
	board[Index(11, 9)].Occupy(newPiece);

	//Pawns
	for (int i = 0; i < width; i++)
	{
		 newPiece = PieceFactory::createPiece(PieceFactory::PAWN, new EmptyPiece(1, t));
		board[Index(i, 3)].Occupy(newPiece);

		newPiece = PieceFactory::createPiece(PieceFactory::PAWN, new EmptyPiece(0, t));
		board[Index(i, 8)].Occupy(newPiece);
	}
}

