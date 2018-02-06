#include"Game.h"
#include <fstream>

#include"Piece.h"
#include"Board.h"
#include"ChuShoBoard.h"
#include"EmptyPiece.h"

Game::Game()
{
//window setup
	//seed random
	srand((unsigned int)time(NULL));
	textures = new TextureModule();

	windowSizeX = 660;
	windowSizeY = 720;
	framerate = 80;

	//generate a window and limit the frames per second
	window = new RenderWindow(VideoMode((unsigned int)windowSizeX, (unsigned int)windowSizeY), "Large Shogi Player", Style::Close | Style::Titlebar | Style::Resize);
	window->setFramerateLimit(framerate);

//basic visual parts setup
	//hide the desktop mouse cursor to prevent confusion with relative window positions
	window->setMouseCursorVisible(false);

	//set up a view for holding background objects
	viewBackground.setCenter(windowSizeX / 2.0f, windowSizeY / 2.0f);
	viewBackground.setSize(windowSizeX, windowSizeY);
	viewBackground.setViewport(FloatRect(0, 0, 1, 1));
	window->setView(viewBackground);

	//and a view for the board
	viewBoard.setSize(windowSizeX, windowSizeX);
	viewBoard.setViewport(FloatRect(0, float(abs(windowSizeX - windowSizeY)/ windowSizeY), 1, 1));

	//Mouse Cursor
	mouseCursorBackground.setSize(Vector2f(10, 10));
	mouseCursorBackground.setOutlineColor(Color::Green);
	mouseCursorBackground.setOutlineThickness(-2);
	mouseCursorBackground.setFillColor(Color::Cyan);

	mouseCursorBoard.setSize(Vector2f(10, 10));
	mouseCursorBoard.setOutlineColor(Color::Cyan);
	mouseCursorBoard.setOutlineThickness(-2);
	mouseCursorBoard.setFillColor(Color::Black);

	

//first text to appear
	txtStart.setFont(textures->fontArialI);
	txtStart.setString("Large Shogi Player\n\n\tProgrammed by:\n\t\tKeith Schairer");
	txtStart.setCharacterSize(50);
	txtStart.setFillColor(Color(255, 59, 0, 255));
	txtStart.setPosition(windowSizeX / 2 - 300, 200);

//win screen
	txtBlackWin.setFont(*textures->fontSelection);
	txtBlackWin.setString("Congratulations!\nBlack Wins!");
	txtBlackWin.setCharacterSize(50);
	txtBlackWin.setFillColor(Color(255, 59, 0, 255));
	txtBlackWin.setPosition(windowSizeX / 2 - 300, 200);

	txtWhiteWin.setFont(*textures->fontSelection);
	txtWhiteWin.setString("Congratulations!\nWhite Wins!");
	txtWhiteWin.setCharacterSize(50);
	txtWhiteWin.setFillColor(Color(255, 59, 0, 255));
	txtWhiteWin.setPosition(windowSizeX / 2 - 300, 200);

////things for the game select menu:
	txtGameSelectMenu.setFont(textures->fontArial);
	txtGameSelectMenu.setString("Choose a game type to begin a new board or \nselect Load Game to continue an old game");
	txtGameSelectMenu.setCharacterSize(25);
	txtGameSelectMenu.setFillColor(Color(189, 161, 40));
	txtGameSelectMenu.setPosition(30, 50);

	btnChuStart = new KButton(textures, "Chu Shogi", Vector2f(100,150), Vector2f(105,30), Color(255, 128, 0, 255));
	btnChuStart->SetCharSize(20);
	vectStartBtns.push_back(btnChuStart);

	btnChuShoStart = new KButton(textures, "Little Chu Shogi", Vector2f(100, 200), Vector2f(165, 30), Color(255, 128, 0, 255));
	btnChuShoStart->SetCharSize(20);
	vectStartBtns.push_back(btnChuShoStart);

	btnDaiStart = new KButton(textures, "Dai Shogi", Vector2f(100, 250), Vector2f(105, 30), Color(255, 128, 0, 255));
	btnDaiStart->SetCharSize(20);
	vectStartBtns.push_back(btnDaiStart);

	btnLoadAuto = new KButton(textures, "Load Auto Save", Vector2f(400, 300), Vector2f(160, 30), Color(0, 255, 170, 255));
	btnLoadAuto->SetCharSize(20);
	vectStartBtns.push_back(btnLoadAuto);
	vectMenuBtns.push_back(btnLoadAuto);
////in game hud
	btnUndo = new KButton(textures, "Undo", Vector2f(15, 15), Vector2f(65, 30), Color(207, 31, 31, 255));
	btnUndo->SetCharSize(20);
	vectGameBtns.push_back(btnUndo);

	btnRedo = new KButton(textures, "Redo", Vector2f(windowSizeX - 15*2 - 65*2, 15), Vector2f(65, 30), Color(207, 31, 31, 255));
	btnRedo->SetCharSize(20);
	vectGameBtns.push_back(btnRedo);

	btnMenu = new KButton(textures, "Menu", Vector2f(windowSizeX - 15 - 65, 15), Vector2f(65, 30), Color(0, 191, 255, 255));
	btnMenu->SetCharSize(20);
	vectGameBtns.push_back(btnMenu);

	txtTurn.setFont(textures->fontArial);
	txtTurn.setString("Black's Turn");
	txtTurn.setCharacterSize(25);
	txtTurn.setFillColor(Color::White);
	txtTurn.setPosition(100, 15);

	txtPieceInfo.setFont(textures->fontArial);
	txtPieceInfo.setString("");
	txtPieceInfo.setCharacterSize(25);
	txtPieceInfo.setFillColor(Color::White);
	txtPieceInfo.setPosition(windowSizeX - 300, 15);

//Pause menu hud
	txtMenuTitle.setFont(*textures->fontSelection);
	txtMenuTitle.setString("Pause Menu");
	txtMenuTitle.setCharacterSize(25);
	txtMenuTitle.setFillColor(Color::White);
	txtMenuTitle.setPosition(windowSizeX/2 - 100, 15);

	btnMenuBack = new KButton(textures, "Back", Vector2f(15, 15), Vector2f(65, 30), Color(0, 191, 255, 255));
	btnMenuBack->SetCharSize(20);
	vectMenuBtns.push_back(btnMenuBack);

	btnLoad1 = new KButton(textures, "Load 1", Vector2f(400, 150), Vector2f(70, 30), Color(0, 255, 170, 255));
	btnLoad1->SetCharSize(20);
	vectMenuBtns.push_back(btnLoad1);
	vectStartBtns.push_back(btnLoad1);

	btnLoad2 = new KButton(textures, "Load 2", Vector2f(400, 200), Vector2f(70, 30), Color(0, 255, 170, 255));
	btnLoad2->SetCharSize(20);
	vectMenuBtns.push_back(btnLoad2);
	vectStartBtns.push_back(btnLoad2);

	btnLoad3 = new KButton(textures, "Load 3", Vector2f(400, 250), Vector2f(70, 30), Color(0, 255, 170, 255));
	btnLoad3->SetCharSize(20);
	vectMenuBtns.push_back(btnLoad3);
	vectStartBtns.push_back(btnLoad3);

	btnSave1 = new KButton(textures, "Save 1", Vector2f(100, 150), Vector2f(70, 30), Color(255, 128, 0, 255));
	btnSave1->SetCharSize(20);
	vectMenuBtns.push_back(btnSave1);

	btnSave2 = new KButton(textures, "Save 2", Vector2f(100, 200), Vector2f(70, 30), Color(255, 128, 0, 255));
	btnSave2->SetCharSize(20);
	vectMenuBtns.push_back(btnSave2);

	btnSave3 = new KButton(textures, "Save 3", Vector2f(100, 250), Vector2f(70, 30), Color(255, 128, 0, 255));
	btnSave3->SetCharSize(20);
	vectMenuBtns.push_back(btnSave3);

	btnSettings = new KButton(textures, "Settings", Vector2f(windowSizeX - 95 - 15, 15), Vector2f(95, 30), Color(0, 191, 255, 255));
	btnSettings->SetCharSize(20);
	vectMenuBtns.push_back(btnSettings);
	vectStartBtns.push_back(btnSettings);

	btnNewGame = new KButton(textures, "Quit", Vector2f(300, 450), Vector2f(65, 30), Color(207, 31, 31, 255));
	btnNewGame->SetCharSize(20);
	vectMenuBtns.push_back(btnNewGame);

//Settings Menu
	txtSettingsTitle.setFont(*textures->fontSelection);
	txtSettingsTitle.setString("Settings");
	txtSettingsTitle.setCharacterSize(25);
	txtSettingsTitle.setFillColor(Color::White);
	txtSettingsTitle.setPosition(windowSizeX / 2 - 100, 15);

	txtBackgroundOption.setFont(*textures->fontSelection);
	txtBackgroundOption.setString("Select the board wood type");
	txtBackgroundOption.setCharacterSize(25);
	txtBackgroundOption.setFillColor(Color::White);
	txtBackgroundOption.setPosition(15, 100);

	

	txtPieceOption.setFont(*textures->fontSelection);
	txtPieceOption.setString("Select the piece texture type");
	txtPieceOption.setCharacterSize(25);
	txtPieceOption.setFillColor(Color::White);
	txtPieceOption.setPosition(15, 200);

	txtFontOption.setFont(*textures->fontSelection);
	txtFontOption.setString("Select the font type");
	txtFontOption.setCharacterSize(25);
	txtFontOption.setFillColor(Color::White);
	txtFontOption.setPosition(15, 300);

	btnSettingsBack = new KButton(textures, "Back", Vector2f(15, 15), Vector2f(65, 30), Color(0, 191, 255, 255));
	btnSettingsBack->SetCharSize(20);
	vectSettingsBtns.push_back(btnSettingsBack);

	float spacing = 50;
	btnBGOptionBeech = new KButton(textures, "Beech", Vector2f(spacing, 150), Vector2f(85, 30), Color(255, 234, 0, 255));
	btnBGOptionBeech->SetCharSize(20);
	vectSettingsBtns.push_back(btnBGOptionBeech);
	
	btnBGOptionCherry = new KButton(textures, "Cherry", Vector2f(spacing +85+ spacing, 150), Vector2f(85, 30), Color(255, 234, 0, 255));
	btnBGOptionCherry->SetCharSize(20);
	vectSettingsBtns.push_back(btnBGOptionCherry);

	btnBGOptionPoplar = new KButton(textures, "Poplar", Vector2f(spacing +85+ spacing +85+ spacing, 150), Vector2f(85, 30), Color(255, 234, 0, 255));
	btnBGOptionPoplar->SetCharSize(20);
	vectSettingsBtns.push_back(btnBGOptionPoplar);

	txtrSampleBoard.setTexture(*textures->bgSelection);
	txtrSampleBoard.setScale(Vector2f(.1f,.1f));
	txtrSampleBoard.setPosition(spacing * 3 + 85 * 3 + 25 , 100);

	btnShapeOptionPlain = new KButton(textures, "Plain", Vector2f(spacing, 250), Vector2f(85, 30), Color(255, 234, 0, 255));
	btnShapeOptionPlain->SetCharSize(20);
	vectSettingsBtns.push_back(btnShapeOptionPlain);

	btnShapeOptionDarker = new KButton(textures, "Portal", Vector2f(spacing + 85 + spacing, 250), Vector2f(85, 30), Color(255, 234, 0, 255));
	btnShapeOptionDarker->SetCharSize(20);
	vectSettingsBtns.push_back(btnShapeOptionDarker);

	btnShapeOptionPattern = new KButton(textures, "Pattern", Vector2f(spacing + 85 + spacing + 85 + spacing, 250), Vector2f(85, 30), Color(255, 234, 0, 255));
	btnShapeOptionPattern->SetCharSize(20);
	vectSettingsBtns.push_back(btnShapeOptionPattern);

	txtrSamplePiece.setTexture(*textures->baseShapeSelection);
	//txtrSamplePiece.setScale(Vector2f(2, 2));
	txtrSamplePiece.setPosition(spacing * 3 + 85 * 4, 250);

	btnFontOptionBuxton = new KButton(textures, "Buxton Sketch", Vector2f(spacing, 350), Vector2f(150, 30), Color(255, 234, 0, 255));
	btnFontOptionBuxton->SetCharSize(20);
	vectSettingsBtns.push_back(btnFontOptionBuxton);

	btnFontOptionSegoe = new KButton(textures, "Segoe Script", Vector2f(spacing + 150 + spacing, 350), Vector2f(150, 30), Color(255, 234, 0, 255));
	btnFontOptionSegoe->SetCharSize(20);
	vectSettingsBtns.push_back(btnFontOptionSegoe);

	btnFontOptionCardinal = new KButton(textures, "Cardinal", Vector2f(spacing + 150 + spacing + 150 + spacing, 350), Vector2f(85, 30), Color(255, 234, 0, 255));
	btnFontOptionCardinal->SetCharSize(20);
	vectSettingsBtns.push_back(btnFontOptionCardinal);

//general game vars setup
	gameState = "start";
	selectionState = "piece";
	isBlacksTurn = true;
	numOfRounds = 0;
	selectedPieceIndex = -1;

	background.setTexture(*textures->bgSelection);
	background.setScale(Vector2f(0.35f, 0.35f));
	
	LoadSettings();
	
}

void Game::Run()
{
	//core program driver
	while (window->isOpen())
	{

		// get the current mouse position in the window
		Vector2i pixelPos = Mouse::getPosition(*window);

		// convert it to world coordinates
		Vector2f worldPos = window->mapPixelToCoords(pixelPos, viewBoard);

		mouseCursorBoard.setPosition(worldPos);

		// convert it to world coordinates
		 worldPos = window->mapPixelToCoords(pixelPos, viewBackground);

		mouseCursorBackground.setPosition(worldPos);


		CheckEvents();
		UpdateObjects();

		Draw();

	}
}

//run through all the events (mouse, keyboard, gamepad)
void Game::CheckEvents()
{
	Event event;
	while (window->pollEvent(event))
	{
		//clicking the x on the window
		if (event.type == sf::Event::Closed)
		{
			window->close();
			SaveGame(-1);
		}

		//any button moves the program to the start menu
		if (gameState == "start")
		{
			if ((event.type == sf::Event::KeyPressed) || event.type == sf::Event::MouseButtonPressed)
			{
				gameState = "game select menu";
			}
		}
		
		
		else if (gameState == "chu game")
		{
			//passes control to helping function with collision logic
			if (event.type == sf::Event::MouseButtonPressed)
			{
				CheckBtnCollisions(false);
			}
			if ((event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(Mouse::Left)))
			{
				CheckSpaceCollisions();				
			}
			if (( sf::Mouse::isButtonPressed(Mouse::Right)))
			{
				viewBoard.setCenter((float)Mouse::getPosition(*window).x, (float)Mouse::getPosition(*window).y);
			}
			if (( sf::Mouse::isButtonPressed(Mouse::Middle)))
			{
				viewBoard.setCenter(windowSizeX/1.5f, windowSizeY/1.5f);
			}
			if (event.type == sf::Event::MouseWheelScrolled)
			{
				if (event.mouseWheelScroll.delta < 0)
					viewBoard.zoom(0.97f);
				else
					viewBoard.zoom(1.03f);
			}
		}
		else if (gameState == "black win")
		{
			if ((event.type == sf::Event::KeyPressed) || event.type == sf::Event::MouseButtonPressed)
			{
				gameState = "game select menu";
			}
		}
		else if (gameState == "white win")
		{
			if ((event.type == sf::Event::KeyPressed) || event.type == sf::Event::MouseButtonPressed)
			{
				gameState = "game select menu";
			}
		}
		else 
		{
			//passes control to helping function with collision logic
			if (event.type == sf::Event::MouseButtonPressed)
			{
				CheckBtnCollisions(false);
			}

		}
	}
}

void Game::Draw()
{
	//erase previous frame
	window->clear();
	//set the view to draw things to
	window->setView(viewBackground);


	////draw objects based on game state
	if (gameState == "start")
		window->draw(txtStart);

	if (gameState == "white win")
		window->draw(txtWhiteWin);
	if (gameState == "black win")
		window->draw(txtBlackWin);

	if (gameState == "game select menu")
	{
		window->draw(txtGameSelectMenu);
		for (unsigned int i = 0; i < vectStartBtns.size(); i++)
		{
			vectStartBtns[i]->Draw(window);
		}
	}

	if (gameState == "menu")
	{
		window->draw(txtMenuTitle);
		for (unsigned int i = 0; i < vectMenuBtns.size(); i++)
		{
			vectMenuBtns[i]->Draw(window);
		}
	}

	if (gameState.find("settings") != string::npos)
	{
		window->draw(txtrSampleBoard);
		window->draw(txtSettingsTitle);
		window->draw(txtBackgroundOption);
		window->draw(txtPieceOption);
		window->draw(txtFontOption);
		window->draw(txtrSamplePiece);

		for (unsigned int i = 0; i < vectSettingsBtns.size(); i++)
		{
			vectSettingsBtns[i]->Draw(window);
		}
	}

	window->draw(mouseCursorBackground);

	if (gameState == "chu game")
	{
		for (unsigned int i = 0; i < vectGameBtns.size(); i++)
		{
			vectGameBtns[i]->Draw(window);
		}
		window->draw(txtPieceInfo);
		window->draw(txtTurn);
		window->draw(mouseCursorBackground);


		window->setView(viewBoard);
		window->draw(background);
		gameBoard->Draw(window);

		window->draw(mouseCursorBoard);
	}

	//update the screen to show changes
	window->display();
}

void Game::UpdateObjects()
{
	background.setTexture(*textures->bgSelection);
	txtrSampleBoard.setTexture(*textures->bgSelection);
	txtrSamplePiece.setTexture(*textures->baseShapeSelection);

	if (gameState == "game select menu")
	{
		//update buttons
		for (unsigned int i = 0; i < vectStartBtns.size(); i++)
			vectStartBtns[i]->Update();


	}
	if (gameState == "menu")
	{
		//update buttons
		for (unsigned int i = 0; i < vectMenuBtns.size(); i++)
			vectMenuBtns[i]->Update();


	}
	if (gameState.find("settings") != string::npos)
	{
		//update buttons
		for (unsigned int i = 0; i < vectSettingsBtns.size(); i++)
			vectSettingsBtns[i]->Update();

		txtMenuTitle.setFont(*textures->fontSelection);
		txtSettingsTitle.setFont(*textures->fontSelection);
		txtBackgroundOption.setFont(*textures->fontSelection);
		txtFontOption.setFont(*textures->fontSelection);
		txtPieceOption.setFont(*textures->fontSelection);

	}
	if (gameState == "chu game")
	{
		gameBoard->Update();
		//update buttons
		for (unsigned int i = 0; i < vectGameBtns.size(); i++)
			vectGameBtns[i]->Update();

		if (isBlacksTurn)
		{
			txtTurn.setString("Black's Turn");
			mouseCursorBoard.setFillColor(Color::Black);
		}
		else
		{
			txtTurn.setString("White's Turn");
			mouseCursorBoard.setFillColor(Color::White);

		}

		if (selectedPieceIndex >= 0)
		{
			if (gameBoard->board[selectedPieceIndex].isOccupied)
				txtPieceInfo.setString(gameBoard->board[selectedPieceIndex].occupant->name);
			else
				txtPieceInfo.setString("");
		}

		if(selectionState == "piece")
			txtPieceInfo.setString("");

		txtPieceInfo.setPosition(windowSizeX / 2 - txtPieceInfo.getGlobalBounds().width / 2 + 20, 15);
	}
}

void Game::CheckBtnCollisions(bool isBtnHeld)
{
	
	if (gameState == "game select menu")
	{
		for (unsigned int i = 0; i < vectStartBtns.size(); i++)
		{
			//if mousecursor intersects the rectangle of the button
			if (mouseCursorBackground.getGlobalBounds().intersects(vectStartBtns[i]->btnBounds.getGlobalBounds()))
			{
				vectStartBtns[i]->Select();
				StartBtnLogic();
			}
		}
	}
	if (gameState == "menu")
	{
		for (unsigned int i = 0; i < vectMenuBtns.size(); i++)
		{
			//if mousecursor intersects the rectangle of the button
			if (mouseCursorBackground.getGlobalBounds().intersects(vectMenuBtns[i]->btnBounds.getGlobalBounds()))
			{
				vectMenuBtns[i]->Select();
				MenuBtnLogic();
			}
		}
	}
	if (gameState.find("settings") != string::npos)
	{
		for (unsigned int i = 0; i < vectSettingsBtns.size(); i++)
		{
			//if mousecursor intersects the rectangle of the button
			if (mouseCursorBackground.getGlobalBounds().intersects(vectSettingsBtns[i]->btnBounds.getGlobalBounds()))
			{
				vectSettingsBtns[i]->Select();
				SettingsBtnLogic(vectSettingsBtns[i]);
			}
		}
	}
	if (gameState == "chu game")
	{
		for (unsigned int i = 0; i < vectGameBtns.size(); i++)
		{
			//if mousecursor intersects the rectangle of the button
			if (mouseCursorBackground.getGlobalBounds().intersects(vectGameBtns[i]->btnBounds.getGlobalBounds()))
			{
				vectGameBtns[i]->Select();
				GameBtnLogic();
			}
		}
	}
}

void Game::StartBtnLogic()
{
	isBlacksTurn = true;
	if (btnChuStart->IsSelected())
	{
		
		gameBoard = new ChuBoard();

		btnChuStart->Deselect();
		//progress game state
		gameState = "chu game";
		gameType = "Chu";

		//generate a Chu board
		gameBoard->SetupPieces(textures);
		gameBoard->RedDehighlight();

		viewBoard.zoom(1);

		vectRedoHistory.clear();
		vectHistory.clear();
	}
	if (btnChuShoStart->IsSelected())
	{
		gameBoard = new ChuShoBoard();
		
		btnChuShoStart->Deselect();
		//progress game state
		gameState = "chu game";
		gameType = "ChuSho";

		//generate a Chu Sho board
		gameBoard->SetupPieces(textures);
		gameBoard->RedDehighlight();

		viewBoard.zoom(0.9f);

		vectRedoHistory.clear();
		vectHistory.clear();
	}

	if (btnDaiStart->IsSelected())
	{
		gameBoard = new DaiBoard();
		
		btnDaiStart->Deselect();
		//progress game state
		gameState = "chu game";
		gameType = "Dai";

		//generate a Chu Sho board
		gameBoard->SetupPieces(textures);
		gameBoard->RedDehighlight();

		viewBoard.zoom(1.3f);
		viewBoard.setCenter(600,450);

		vectRedoHistory.clear();
		vectHistory.clear();
	}

	LoadLogic();
	if (btnSettings->IsSelected())
	{
		btnSettings->Deselect();
		gameState = "settings ";

	}
}

void Game::LoadLogic()
{
	
	if (btnLoadAuto->IsSelected())
	{
		btnLoadAuto->Deselect();


		LoadGame(-1);
	}

	if (btnLoad1->IsSelected())
	{
		btnLoad1->Deselect();


		LoadGame(1);
	}

	if (btnLoad2->IsSelected())
	{
		btnLoad2->Deselect();


		LoadGame(2);

	}

	if (btnLoad3->IsSelected())
	{
		btnLoad3->Deselect();


		LoadGame(3);
	}
}

void Game::GameBtnLogic()
{
	if (btnUndo->IsSelected())
	{
		btnUndo->Deselect();
		Undo();
	}

	if (btnRedo->IsSelected())
	{
		btnRedo->Deselect();
		Redo();

	}

	if (btnMenu->IsSelected())
	{
		btnMenu->Deselect();
		gameState = "menu";

	}
}

void Game::MenuBtnLogic()
{
	if (btnMenuBack->IsSelected())
	{
		btnMenuBack->Deselect();
		gameState = "chu game";

	}
	if (btnSettings->IsSelected())
	{
		btnSettings->Deselect();
		gameState = "settings 1";

	}
	LoadLogic();

	if (btnSave1->IsSelected())
	{
		btnSave1->Deselect();
		SaveGame(1);
		gameState = "chu game";

	}

	if (btnSave2->IsSelected())
	{
		btnSave2->Deselect();
		SaveGame(2);
		gameState = "chu game";

	}

	if (btnSave3->IsSelected())
	{
		btnSave3->Deselect();
		SaveGame(3);
		gameState = "chu game";

	}

	if (btnNewGame->IsSelected())
	{
		btnNewGame->Deselect();
		SaveGame(-1);
		viewBoard.zoom(1);
		gameState = "game select menu";
		

	}
}

void Game::SettingsBtnLogic(KButton *clicked)
{
	if (btnSettingsBack->IsSelected())
	{
		btnSettingsBack->Deselect();

		if (gameState == "settings 1")
			gameState = "menu";
		else
			gameState = "game select menu";

		SaveSettings();

	}
	
	if (btnBGOptionBeech->IsSelected() && clicked == btnBGOptionBeech)
	{
		btnBGOptionPoplar->Deselect();
		btnBGOptionCherry->Deselect();
		textures->bgSelection = &textures->bgBeech;
	}
	if (btnBGOptionPoplar->IsSelected() && clicked == btnBGOptionPoplar)
	{
		btnBGOptionBeech->Deselect();
		btnBGOptionCherry->Deselect();
		textures->bgSelection = &textures->bgPoplar;
	}
	if (btnBGOptionCherry->IsSelected() && clicked == btnBGOptionCherry)
	{
		btnBGOptionPoplar->Deselect();
		btnBGOptionBeech->Deselect();
		textures->bgSelection = &textures->bgCherry;
	}

	if (btnShapeOptionPlain->IsSelected() && clicked == btnShapeOptionPlain)
	{
		btnShapeOptionDarker->Deselect();
		btnShapeOptionPattern->Deselect();
		textures->baseShapeSelection = &textures->baseShape;
	}
	if (btnShapeOptionDarker->IsSelected() && clicked == btnShapeOptionDarker)
	{
		btnShapeOptionPattern->Deselect();
		btnShapeOptionPlain->Deselect();
		textures->baseShapeSelection = &textures->baseShapeDarker;
	}
	if (btnShapeOptionPattern->IsSelected() && clicked == btnShapeOptionPattern)
	{
		btnShapeOptionPlain->Deselect();
		btnShapeOptionDarker->Deselect();
		textures->baseShapeSelection = &textures->baseShapePattern;
	}

	if (btnFontOptionBuxton->IsSelected() && clicked == btnFontOptionBuxton)
	{
		btnFontOptionCardinal->Deselect();
		btnFontOptionSegoe->Deselect();
		textures->fontSelection = &textures->fontBuxtonSketch;
	}

	if (btnFontOptionSegoe->IsSelected() && clicked == btnFontOptionSegoe)
	{
		btnFontOptionCardinal->Deselect();
		btnFontOptionBuxton->Deselect();
		textures->fontSelection = &textures->segoesc;
	}

	if (btnFontOptionCardinal->IsSelected() && clicked == btnFontOptionCardinal)
	{
		btnFontOptionBuxton->Deselect();
		btnFontOptionSegoe->Deselect();
		textures->fontSelection = &textures->fontCardinal;
	}
}

void Game::CheckSpaceCollisions()
{

	bool win = false;
	for (int i = 0; i < gameBoard->size; i++)
	{
		// if mousecusorBoard intersects a space
		if (mouseCursorBoard.getGlobalBounds().intersects(gameBoard->board[i].GetFrame().getGlobalBounds()))
		{
			//Check selection state and perform different logic

			//no piece selected
			if (selectionState == "piece")
			{
				//if space has a piece
				if (gameBoard->board[i].isOccupied)
				{
					HighlightSpaces(i, false);
					selectionState = "highlight";
				}
				else
					DehighlightSpaces();
			}
			//piece selected, now spaces are highlighted
			else if (selectionState == "highlight")
			{
				//any invalid click will deselect the piece
				selectionState = "piece";
				
				//black highlights(blacks turn)
				if (gameBoard->board[i].isHighlightedBlack && isBlacksTurn)
				{
					isBlacksTurn = false;
					//if highlighted space is occupied
					if (gameBoard->board[i].isOccupied)
					{
						win = LogCapture(i, selectedPieceIndex, 1);
						if (win)
							gameState = "black win";
					}
					else
					{
						LogMove(i, selectedPieceIndex, 1);

					}
					//once a space is selected, then it is safe to dehighlight
					DehighlightSpaces();
				}

				//white highlights(whites turn)
				else if (gameBoard->board[i].isHighlightedWhite && !isBlacksTurn)
				{
					isBlacksTurn = true;
					if (gameBoard->board[i].isOccupied)
					{
						win = LogCapture(i, selectedPieceIndex, 1);

						if (win)
							gameState = "white win";
					}
					else
					{
						LogMove(i, selectedPieceIndex, 1);
					}
					DehighlightSpaces();
				}
				//lion special moves(green highlight)(white)
				else if (gameBoard->board[i].IsHighlightedGreen() && !isBlacksTurn && gameBoard->board[selectedPieceIndex].occupant->isWhite)
				{
					//isBlacksTurn = true;
					if (gameBoard->board[i].isOccupied && !gameBoard->board[i].occupant->isWhite)
					{
						win = LogCapture(i, selectedPieceIndex, 0);

						
						if (win)
							gameState = "white win";

						selectionState = "lion highlight";
						HighlightSpaces(i, true);
					}
					else if (!gameBoard->board[i].isOccupied)
					{
						LogMove(i, selectedPieceIndex, 0);

						selectionState = "lion highlight";
						HighlightSpaces(i, true);
					}
					
				}
				//lion special moves(green highlight)(black)
				else if (gameBoard->board[i].IsHighlightedGreen() && isBlacksTurn && !gameBoard->board[selectedPieceIndex].occupant->isWhite)
				{
					//isBlacksTurn = false;
					if (gameBoard->board[i].isOccupied && gameBoard->board[i].occupant->isWhite)
					{
						win = LogCapture(i, selectedPieceIndex, 0);
						if (win)
							gameState = "black win";

						selectionState = "lion highlight";
						HighlightSpaces(i, true);
					}
					else if(!gameBoard->board[i].isOccupied)
					{
						LogMove(i, selectedPieceIndex, 0);

						selectionState = "lion highlight";
						HighlightSpaces(i, true);
					}
					
				}
				else if(gameBoard->board[i].isOccupied)
				{
					DehighlightSpaces();
					HighlightSpaces(i, false);
					selectionState = "highlight";
				}
				else
					DehighlightSpaces();
			}
			//lion move second turn(after green highlight was selected)
			else if (selectionState == "lion highlight")
			{
				
				//Black
				if (gameBoard->board[i].isHighlightedBlack && isBlacksTurn)
				{
					isBlacksTurn = false;
					if (gameBoard->board[i].isOccupied && gameBoard->board[i].occupant->isWhite)
					{
						win = LogCapture(i, selectedPieceIndex, 2);
						if (win)
							gameState = "black win";
					}
					else if (!gameBoard->board[i].isOccupied)
					{
						LogMove(i, selectedPieceIndex, 2);

					}
					else
						LogMove(i, selectedPieceIndex, 2);
					selectionState = "piece";
					DehighlightSpaces();
				}
				//White
				else if (gameBoard->board[i].isHighlightedWhite && !isBlacksTurn)
				{
					isBlacksTurn = true;
					if (gameBoard->board[i].isOccupied && !gameBoard->board[i].occupant->isWhite)
					{
						win = LogCapture(i, selectedPieceIndex, 2);
						if (win)
							gameState = "white win";
					}
					else if(!gameBoard->board[i].isOccupied)
					{
						LogMove(i, selectedPieceIndex, 2);
					}
					else
						LogMove(i, selectedPieceIndex, 2);
					selectionState = "piece";
					DehighlightSpaces();
				}

			}

			break;
		}
	}
	
}

void Game::HighlightSpaces(int occupantIndex, bool lion)
{
	DehighlightSpaces();
	if (!lion)
		gameBoard->Highlight(occupantIndex);
	else
		gameBoard->HighlightLion(occupantIndex);
	selectedPieceIndex = occupantIndex;
}

void Game::DehighlightSpaces()
{
	gameBoard->Dehighlight();
}
void Game::Undo()
{
	if (vectHistory.size() > 0)
	{
		DehighlightSpaces();
		selectionState = "piece";
		string moveRecord = vectHistory.back();

		vector<string> splitRecord = split(moveRecord, '_');

		int moveType = stoi(splitRecord.back());
		if (moveType == 1|| moveType == 2)
			isBlacksTurn = !isBlacksTurn;
		int newIndex = stoi(splitRecord[4]);
		int oldIndex = stoi(splitRecord[0]);
		int isWhite = stoi(splitRecord[2]);

		gameBoard->Occupy(oldIndex, newIndex);
		

		if (splitRecord.size() > 6)
		{
			bool isOpponentWhite = stoi(splitRecord[6]);
			bool isOpponentPromoted = stoi(splitRecord[7]);

			string pieceName = splitRecord[5];
			Piece* newPiece = new EmptyPiece(isOpponentWhite, textures);
			newPiece->DeterminePieceType(pieceName, isOpponentPromoted);
			gameBoard->board[newIndex].Occupy(newPiece);

			bool isPromoted = stoi(splitRecord[3]);
			gameBoard->board[oldIndex].occupant->DeterminePieceType(splitRecord[1], isPromoted);
		}
		else
		{
			bool isPromoted = stoi(splitRecord[3]);

			gameBoard->board[oldIndex].occupant->DeterminePieceType(splitRecord[1], isPromoted);
		}

		if (moveType == 2)
		{
			selectionState = "lion highlight";
			HighlightSpaces(oldIndex, true);
		}

		vectRedoHistory.push_back(moveRecord);
		vectHistory.pop_back();
	}
	
}

void Game::Redo()
{
	if (vectRedoHistory.size() > 0)
	{
		DehighlightSpaces();
		selectionState = "piece";
		string moveRecord = vectRedoHistory.back();

		vector<string> splitRecord = split(moveRecord, '_');

		if (splitRecord.size() >= 6)
		{
			int moveType = stoi(splitRecord.back());
			if (moveType == 1 || moveType == 2)
				isBlacksTurn = !isBlacksTurn;
			int newIndex = stoi(splitRecord[4]);
			int oldIndex = stoi(splitRecord[0]);
			bool isWhite = stoi(splitRecord[2]);

			if (splitRecord.size() > 6)
			{
				gameBoard->Capture(newIndex, oldIndex);
			}
			else
				gameBoard->Occupy(newIndex, oldIndex);

			if (moveType == 0)
			{
				selectionState = "lion highlight";
				HighlightSpaces(newIndex, true);
			}
			vectHistory.push_back(moveRecord);
		}

		vectRedoHistory.pop_back();
	}

}

void Game::SaveGame(int fileSlot)
{
	string filename;
	if (fileSlot == 1)
		filename = "save_game1.shogi";
	else if (fileSlot == 2)
		filename = "save_game2.shogi";
	else if (fileSlot == 3)
		filename = "save_game3.shogi";
	else if (fileSlot == -1)
		filename = "autosave.shogi";

	ofstream fout;
	fout.open(filename);
	fout << gameType << endl;

	for (unsigned int i = 0; i < vectHistory.size(); i++)
	{
		fout << vectHistory[i] << endl;
	}
	fout.close();

}

void Game::LoadGame(int fileSlot)
{
	isBlacksTurn = true;
	vectRedoHistory.clear();
	vectHistory.clear();
	string filename;
	if (fileSlot == 1)
		filename = "save_game1.shogi";
	else if (fileSlot == 2)
		filename = "save_game2.shogi";
	else if (fileSlot == 3)
		filename = "save_game3.shogi";
	else if (fileSlot == -1)
		filename = "autosave.shogi";

	ifstream fin(filename);

	gameBoard = new ChuBoard();
	viewBoard.zoom(1);

	//check for empty file
	if (!fin.fail())
	{
		getline(fin, gameType);

		if (gameType == "Chu")
		{
			gameState = "chu game";
			delete gameBoard;
			gameBoard = new ChuBoard();
			gameBoard->Reset(textures);
			viewBoard.zoom(1);

		}
		else if (gameType == "ChuSho")
		{
			gameState = "chu game";
			delete gameBoard;
			gameBoard = new ChuShoBoard();
			gameBoard->Reset(textures);
			viewBoard.zoom(0.9f);


		}
		else if (gameType == "Dai")
		{
			gameState = "chu game";
			delete gameBoard;
			gameBoard = new DaiBoard();
			gameBoard->Reset(textures);
			viewBoard.zoom(1.2f);


		}
		else
		{
			gameType = "Chu";
			gameState = "chu game";
			delete gameBoard;
			gameBoard = new ChuBoard();
			gameBoard->Reset(textures);
			viewBoard.zoom(1);
		}

		string record;
		while (!fin.eof())
		{
			getline(fin, record);
			vectRedoHistory.push_back(record);
			Redo();
		}
	}
	else
	{
		gameType = "Chu";
		gameState = "chu game";
		delete gameBoard;
		gameBoard = new ChuBoard();
		gameBoard->Reset(textures);
		viewBoard.zoom(1);
	}
	
	fin.close();
}

bool Game::LogCapture(int newIndex, int oldIndex, int moveType)
{
	stringstream moveRecord;
	moveRecord << oldIndex << "_" << gameBoard->board[oldIndex].occupant->name << "_" << gameBoard->board[oldIndex].occupant->isWhite << "_"<< gameBoard->board[oldIndex].occupant->IsPromoted()
		<< "_" << newIndex << "_" << gameBoard->board[newIndex].occupant->name << "_" << gameBoard->board[newIndex].occupant->isWhite << "_" << gameBoard->board[newIndex].occupant->IsPromoted();
	
	bool win = gameBoard->Capture(newIndex, oldIndex);

	moveRecord << "_" << moveType;

	vectHistory.push_back(moveRecord.str());
	vectRedoHistory.clear();
	return win;
}

void Game::LogMove(int newIndex, int oldIndex, int moveType)
{
	stringstream moveRecord;
	moveRecord << oldIndex << "_" << gameBoard->board[oldIndex].occupant->name << "_" << gameBoard->board[oldIndex].occupant->isWhite << "_" << gameBoard->board[oldIndex].occupant->IsPromoted() << "_" << newIndex;
	
	gameBoard->Occupy(newIndex, oldIndex);

	moveRecord << "_" << moveType;

	
	vectHistory.push_back(moveRecord.str());
	vectRedoHistory.clear();
}

void Game::SaveSettings()
{
	ofstream fout;
	fout.open("settings.defaults");
	if (textures->fontSelection == &textures->fontBuxtonSketch)
	{
		fout << "Buxton" << endl;
	}
	if (textures->fontSelection == &textures->fontCardinal)
	{
		fout << "Cardinal" << endl;
	}
	if (textures->fontSelection == &textures->segoesc)
	{
		fout << "Segoesc" << endl;
	}

	if (textures->bgSelection == &textures->bgBeech)
	{
		fout << "Beech" << endl;
	}
	if (textures->bgSelection == &textures->bgCherry)
	{
		fout << "Cherry" << endl;
	}
	if (textures->bgSelection == &textures->bgPoplar)
	{
		fout << "Poplar" << endl;
	}

	if (textures->baseShapeSelection == &textures->baseShape)
	{
		fout << "Plain" << endl;
	}
	if (textures->baseShapeSelection == &textures->baseShapeDarker)
	{
		fout << "Portal" << endl;
	}
	if (textures->baseShapeSelection == &textures->baseShapePattern)
	{
		fout << "Pattern" << endl;
	}
	
	fout.close();
}

void Game::LoadSettings()
{
	ifstream fin;
	fin.open("settings.defaults");
	if (!fin.fail())
	{
		string setting;
		fin >> setting;
		if (setting == "Buxton")
			textures->fontSelection = &textures->fontBuxtonSketch;

		if (setting == "Cardinal")
			textures->fontSelection = &textures->fontCardinal;

		if (setting == "Segoesc")
			textures->fontSelection = &textures->segoesc;

		fin >> setting;
		if (setting == "Beech")
			textures->bgSelection = &textures->bgBeech;

		if (setting == "Cherry")
			textures->bgSelection = &textures->bgCherry;

		if (setting == "Poplar")
			textures->bgSelection = &textures->bgPoplar;

		fin >> setting;
		if (setting == "Plain")
			textures->baseShapeSelection = &textures->baseShape;

		if (setting == "Portal")
			textures->baseShapeSelection = &textures->baseShapeDarker;

		if (setting == "Pattern")
			textures->baseShapeSelection = &textures->baseShapePattern;
	}

	fin.close();
}




