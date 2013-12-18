#pragma once

#include <allegro5\allegro5.h>
#include<allegro5\allegro_font.h>
#include<allegro5\allegro_ttf.h>
#include<allegro5\allegro_image.h>
#include "GameObject.hpp"


class Player : public GameObject
{
private:
	int lives;
	int score;
	int animationRow;
	ALLEGRO_BITMAP *image;
	
public:
	Player();
	~Player();

	void Destroy();
	void Init(ALLEGRO_BITMAP *image);
	void Update();
	void Render();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Jump();

	void ResetAnimation(int position);

	int GetLives();
	int GetScore();

	void LoseLife();
	void AddPoint();

	void Collided(int objectID);

	void ChangeStance(int &stance2, int newStance, ALLEGRO_BITMAP *image);

	
};

