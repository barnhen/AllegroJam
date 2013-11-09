#pragma once

#include <allegro5\allegro5.h>
#include "GameObject.h"
class Player : public GameObject
{
private:
	int lives;
	int score;
	int animationRow;
public:
	Player();
	~Player();

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

	
};

