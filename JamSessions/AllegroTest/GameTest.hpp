#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;


struct Sprite
{
	float x;
	float y;
	float velX;
	float velY;
	int dirX;
	int dirY;

	int bx;
	int by;
	int w;
	int h;

	ALLEGRO_BITMAP *image;
};

class GameTest
{
public:

	GameTest(void);
	~GameTest(void);
	void start();
};

