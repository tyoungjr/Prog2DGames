#pragma once
#ifndef _DISCORDIA_H            // Prevent multiple definitions if this 
#define _DISCORDIA_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <string>
#include <sstream>
#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "textDX.h"
#include "player.h"
#include "ground.h"
#include "goblin.h"

namespace discordiaNS
{

}

class Discordia :public Game
{
private:
	// game items
	TextureManager menuTexture;	 // textures
	TextureManager playerTexture; 
	TextureManager groundTexture;
	TextureManager goblinTexture;

	Player player;				 // player object
	Image   menu;                // menu image
	Ground	ground;				 // ground entity
	Goblin goblin;
	TextDX  *dxFont;             // DirectX font
	std::string  message;
	float messageY;
	bool menuOn = false;

public:
	Discordia();
	~Discordia();
	// Initialize the game
	void initialize(HWND hwnd);
	void update();      // must override pure virtual from Game
	void ai();          // "
	void collisions();  // "
	void render();      // "
	void releaseAll();
	void resetAll();
	void startLevel();
};

#endif