#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::Init(ALLEGRO_BITMAP *image = NULL)
{
	GameObject::Init(20, 200, 6, 6, 0, 0, 10, 12);

	SetID(PLAYER);
	SetAlive(true);

	lives = 3;
	score = 0;

	maxFrame = 3; // old 3
	curFrame = 0;
	frameWidth = 31.6; //old 31.6
	frameHeight = 32; //old 32
	animationColumns = 3; //old 3
	animationDirection = 1;

	animationRow = 2;

	if(image != NULL)
		Player::image = image;
}
void Player::Update()
{
	GameObject::Update();
	if(x < 0)
		x = 0;
	else if(x > WIDTH)
		x = WIDTH;

	if(y < 0)
		y = 0;
	else if(y > HEIGHT)
		y = HEIGHT;

	if(++frameCount >= frameDelay){
		if(++curFrame >= maxFrame){
			curFrame = 0;

		}
		frameCount=0;
	}
}
void Player::Render()
{
	GameObject::Render();

	std::cout<<"curFrame is "<<curFrame<<std::endl;
	std::cout<<"animationColumns is "<<animationColumns<<std::endl;
	std::cout<<"animationRow is "<<animationRow<<std::endl;
	std::cout<<"frameHeight is "<<frameHeight<<std::endl;
	int fx = (curFrame % animationColumns) * frameWidth;
	int fy = animationRow * frameHeight;

	al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight,
		x - frameWidth / 2, y - frameHeight / 2, 0);
}

void Player::MoveUp()
{
	animationRow = 3;
	dirY = -1;
	dirX=0;
}
void Player::MoveDown()
{
	animationRow = 0;
	dirY = 1;
	dirX=0;
}
void Player::MoveLeft()
{
	animationRow = 1;
	//curFrame = 2;
	//curFrame =+ curFrame;
	dirX = -1;
	dirY=0;
}
void Player::MoveRight()

{
	animationRow = 2;
	//curFrame = 2;
	dirX = 1;
	dirY=0;
	
}

void Player::Jump()
{

}

void Player::ResetAnimation(int position)
{
	if(position == 1)
	{
		
		//animationRow = 2;
		//curFrame=0;
		dirY = 0;
		dirX = 0;
	}
	else if (position == 2)
	{
		//animationRow = 2;
		dirY = 0;
		dirX = 0;
	}
	else if (position == 3)
	{
		//animationRow = 3;
		dirX = 0;
		dirY = 0;
	}
	else if (position == 0)
	{

		
		dirX = 0;
		dirY = 0;
		curFrame = 0;
	}
}

int Player::GetLives() {return lives;}
int Player::GetScore() {return score;}

void Player::LoseLife() {lives--;}
void Player::AddPoint() {score++;}

void Player::Collided(int objectID)
{
	if(objectID == ENEMY)
		lives--;
}
