#include "Space.h"

Space::Space()
{
	Initialize();
	pos.x = 0;
	pos.y = 0;
	loc.x = 0;
	loc.y = 0;
}

Space::Space(int x, int y, int gridx, int gridy)
{
	Initialize();
	pos.x = x;
	pos.y = y;
	loc.x = gridx;
	loc.y = gridy;
	frame.setPosition(Vector2f(x , y));
}

void Space::Draw(RenderWindow * window)
{
	window->draw(frame);
	if (isOccupied)
		occupant->Draw(window);
}

void Space::Update()
{
	if (isHighlightedBlack)
		frame.setFillColor(Color(0, 0, 0, 100));
	else if (isHighlightedWhite)
		frame.setFillColor(Color(255, 255, 255, 150));
	else if (isHighlightedGreen)
		frame.setFillColor(Color(40, 184, 0, 100));
	else
		frame.setFillColor(Color::Transparent);

	if (isHighlightedRed)
	{
		frame.setOutlineColor(Color::Red);
	}
	else
		frame.setOutlineColor(Color::Black);

	if (isOccupied)
	{
		occupant->SetPosition(pos);
		occupant->Update();
	}
}

void Space::Capture(Piece * newOccupant)
{
	delete occupant;
	occupant = newOccupant;
	occupant->SetPosition(frame.getPosition());
}

void Space::Occupy(Piece * newOccupant)
{
	isOccupied = true;
	occupant = newOccupant;
	occupant->SetPosition(frame.getPosition());
}

void Space::HighlightGreen(bool highlighted, string direction)
{
	isHighlightedGreen = highlighted;
	if(direction != "")
		greenDirection = direction;
}

void Space::Initialize()
{
	frame.setSize(Vector2f(50, 50));
	frame.setOrigin(Vector2f(50 / 2, 50 / 2));
	frame.setPosition(Vector2f(0, 0));
	frame.setFillColor(Color::Transparent);
	frame.setOutlineThickness(-2);
	frame.setOutlineColor(Color::Black);

	isHighlightedBlack = false;
	isHighlightedWhite = false;
	isHighlightedGreen = false;
	isHighlightedRed = false;
	isOccupied = false;
}