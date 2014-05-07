#pragma once

#include <allegro5\allegro5.h>
#include "GameObject.h"

//#include "Background.hpp"
//#include "Camera.h"

//using namespace background;
namespace nPlayer{
	class Player : public GameObject
	{
	private:
		int lives;
		int score;
		int animationRow;
		boolean flip;
		float velocityX;
		float velocityY;
		//float posX;
		//float posY;
	public:
		Player();
		~Player();

		void Init(ALLEGRO_BITMAP *image, float vX, float vY);
		void Update();
		void Render();

		void SetVelocityX(float vX);
		void SetVelocityY(float vY);

		void MoveUp();
		void MoveDown();
		bool MoveLeft();
		bool MoveRight();
		void Jump();
		void Dash(int dX, int vX);
		void Shoot();

		//void SetPosX(float pY);
		//void SetPosY(float pX);

		float GetVelocityX();
		float GetVelocityY();
		int GetX();
		int GetY();
		int GetPosX();
		int GetPosY();


		void ResetAnimation(int position);

		int GetLives();
		int GetScore();

		void LoseLife();
		void AddPoint();

		void Collided(int objectID);

	
	};
}