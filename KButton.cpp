#include "KButton.h"



KButton::KButton()
{
	font.loadFromFile("comic.ttf");
	//font.loadFromFile(resourcePath() + "comic.ttf");

	isSelected = false;
	pos.x = 0;
	pos.y = 0;
	size.x = 0;
	size.y = 0;
	boundsColor = Color::White;
}

KButton::KButton(TextureModule *t, string titl, Vector2f p, Vector2f siz, Color col)
{
	//font = t->fontComic;
	txtTitle.setFont(t->fontComic);
	txtTitle.setString(titl);
	isSelected = false;
	pos = p;
	size = siz;
	boundsColor = col;
	btnBounds.setOutlineColor(boundsColor);
	btnBounds.setFillColor(Color::Transparent);
	btnBounds.setOutlineThickness(5);
	txtTitle.setPosition(pos.x + 5, pos.y + 5);
	btnBounds.setSize(size);
	btnBounds.setPosition(pos);

	//Vector2f middleChar = txtTitle.findCharacterPos(titl.size() / 2);
	//txtTitle.setPosition( size.x/2 - middleChar.x, size.y/2 - middleChar.y);
	

}

void KButton::Update()
{
	if (isSelected)
	{
		btnBounds.setOutlineColor(Color(128, 128, 128, 255));
		//btnBounds.setFillColor(boundsColor);
	}
	else
	{
		btnBounds.setOutlineColor(boundsColor);
		btnBounds.setFillColor(Color::Transparent);
	}
}

void KButton::Draw(RenderWindow *window)
{
	window->draw(btnBounds);
	window->draw(txtTitle);
}


