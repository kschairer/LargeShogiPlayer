#include "PieceFactory.h"

Piece * PieceFactory::createPiece(PieceType pieceType, Piece * basePiece)

	{

		//create piece based on selection
		switch (pieceType)
		{
		case BISHOP:
			basePiece = new Bishop(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case ROOK:
			basePiece = new Rook(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case PAWN:
			basePiece = new Pawn(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case BLINDTIGER:
			basePiece = new BlindTiger(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case ANGRYBOAR:
			basePiece = new AngryBoar(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case CATSWORD:
			basePiece = new CatSword(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case COPPER:
			basePiece = new Copper(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case DRUNKELEPHANT:
			basePiece = new DrunkElephant(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case DRAGONKING:
			basePiece = new DragonKing(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case DRAGONHORSE:
			basePiece = new DragonHorse(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case EVILWOLF:
			basePiece = new EvilWolf(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case FEROCIOUSLEOPARD:
			basePiece = new FerociousLeopard(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case FLYINGDRAGON:
			basePiece = new FlyingDragon(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case FLYINGOX:
			basePiece = new FlyingOx(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case FLYINGSTAG:
			basePiece = new FlyingStag(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case FREEBOAR:
			basePiece = new FreeBoar(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case GOLD:
			basePiece = new Gold(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case GOBETWEEN:
			basePiece = new GoBetween(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case HORNEDFALCON:
			basePiece = new HornedFalcon(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case IRON:
			basePiece = new Iron(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case KING:
			basePiece = new King(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case KIRIN:
			basePiece = new Kirin(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case KNIGHT:
			basePiece = new Knight(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case LANCE:
			basePiece = new Lance(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case LION:
			basePiece = new Lion(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case PHEONIX:
			basePiece = new Pheonix(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case PRINCE:
			basePiece = new Prince(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case QUEEN:
			basePiece = new Queen(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case REVERSECHARIOT:
			basePiece = new ReverseChariot(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case SILVER:
			basePiece = new Silver(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case SIDEMOVER:
			basePiece = new SideMover(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case SOARINGEAGLE:
			basePiece = new SoaringEagle(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case STONE:
			basePiece = new Stone(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case VERTICALMOVER:
			basePiece = new VerticalMover(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case VIOLENTOX:
			basePiece = new ViolentOx(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case WHITEHORSE:
			basePiece = new WhiteHorse(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		case WHALE:
			basePiece = new Whale(basePiece, basePiece->isWhite, basePiece->textures);
			break;
		}
		//throw "invalid topping type";

		return basePiece;
	}
