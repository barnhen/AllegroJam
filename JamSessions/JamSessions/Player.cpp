#include "Player.h"
//#include<allegro5\allegro_font.h>
//#include<allegro5\allegro_ttf.h>

//using namespace camera;
using namespace nPlayer;

Player::Player()
{
}


Player::~Player()
{
}


void Player::Init(ALLEGRO_BITMAP *image = NULL, float vX = NULL, float vY = NULL)
{
	Player::SetVelocityX(vX) ;
	Player::SetVelocityY(vY);
	//GameObject::Init(20/*20*/, 200, 6, 6, 0, 0, 10, 12);
	GameObject::Init(BORDER_TILESET+20/*20*/, 200, vX, vY, 0, 0, 10, 12);

	SetID(PLAYER);
	SetAlive(true);

	lives = 3;
	score = 0;

	maxFrame = 14; // old 3
	curFrame = 0;
	frameWidth = 88; //old 31.6
	frameHeight = 88; //old 32
	animationColumns = 29; //old 3
	animationDirection = 1;

	animationRow = 2;
	flip = false;

	//Player::posX = GameObject::GetX();

	if(image != NULL)
		Player::image = image;


}
void Player::Update()
{
	GameObject::Update();
	//Player::posX = GameObject::GetX();
	//SetPosX(posX);
	std::cout<<"PosX is "<<posX<<std::endl;
	if(x < 0)
		x = 0;
	else if(x > (WIDTH-BORDER_TILESET)) // 86 my number to draw the entire picture at the border right of screen
		x = WIDTH-BORDER_TILESET;

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

	//std::cout<<"curFrame is "<<curFrame<<std::endl;
	//std::cout<<"animationColumns is "<<animationColumns<<std::endl;
	//std::cout<<"animationRow is "<<animationRow<<std::endl;
	//std::cout<<"frameHeight is "<<frameHeight<<std::endl;
	//if (animationRow == 2)
	//	int fx = (curFrame % animationColumns) * frameWidth;
	//else
	int fx = (curFrame) * frameWidth;
	int fy = animationRow * frameHeight;

	//SetPosX(posX);
	//SetPosY(posY);

	
	if (flip){
		/*
		if (animationRow == 6 && curFrame == 15)
		{
			curFrame = 0;
		}
		else if (animationRow == 2)
		{
			 if (curFrame >= 4)
			curFrame = 0;
		}
		*/
		/*
		al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight,
					x - frameWidth / 2, y - frameHeight / 2, ALLEGRO_FLIP_HORIZONTAL);	
		*/
		al_draw_scaled_bitmap(image, fx, fy, frameWidth, frameHeight, 
			x - frameWidth / 2, y - frameHeight / 2, frameWidth * 2, frameHeight * 2,ALLEGRO_FLIP_HORIZONTAL);
		std::cout<<"Flipping"<<std::endl;
	}

	else
	{
		/*
		if (animationRow == 6 && curFrame == 15)
		{
			curFrame = 0;
		}
		else if (animationRow == 2 && curFrame > 4)
		{
			curFrame = 0;
		}
		*/
		/*
		al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight,
			x - frameWidth / 2, y - frameHeight / 2, 0);
		*/
		al_draw_scaled_bitmap(image, fx, fy, frameWidth, frameHeight, 
			x - frameWidth / 2, y - frameHeight / 2, frameWidth * 2, frameHeight * 2,0);
	}
	
	/*
	//for (curFrame = 0; curFrame  < 4 ; curFrame++)
	{
		al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight,
			x - frameWidth / 2, y - frameHeight / 2, 0);
		//al_draw_bitmap_region(image, curFrame * frameWidth,0, frameWidth, frameHeight, x,y,0);
	}
	//curFrame = 0;
	*/
		
}

void Player::MoveUp()
{
	animationRow = 3;
	flip = false;
	dirY = -1;
	dirX=0;
	Player::frameDelay =3;
}
void Player::MoveDown()
{
	animationRow = 0;
	flip = false;
	dirY = 1;
	dirX=0;
	Player::frameDelay =3;
}
bool Player::MoveLeft()
{
	animationRow = 6; //old 1
	flip = true;
	Player::velX = Player::velocityX;
	//curFrame = 2;
	//curFrame =+ curFrame;
	dirX = -1;
	dirY=0;
	Player::frameDelay =4;
	
	//prevents the sprite to loop more than its drawing on the sheet for the current row
	if (animationRow == 6 && curFrame == 15)
	{
		curFrame = 0;
	}

	//this will center de char into the middle of screen
	//if (Player::x = PLAYER_POSITION_CENTER)
	//{
	//	Player::x = PLAYER_POSITION_CENTER;
	//}

	//Camera *cam = new Camera();
	//	cam->ScrollCamera(1,0,2,0);
	return true;
}
bool Player::MoveRight()
{
	animationRow = 6;
	flip = false;
	Player::velX = Player::velocityX;
	//curFrame = 2;
	dirX = 1;
	dirY=0;
	//Background bg;
	Player::frameDelay =4;
	//Player::x += 4;
	
	//prevents the sprite to loop more than its drawing on the sheet for the current row
	if (animationRow == 6 && curFrame == 15)
	{
		curFrame = 0;
	}

	//if (Player::x > 20)
	//{
		//Camera *cam = new Camera();
		//cam->ScrollCamera(-1,0,2,0);
		//background::Background *bg = new Background();
		//bg->Scroll(1);
	//}
	return true;
}

void Player::Jump()
{
	Player::frameDelay =3;
}

void Player::Dash(int dX, int vX)
{
	animationRow = 7;
	//flip = false;
	Player::frameDelay = 3;
	Player::dirX = dX;
	Player::velX = vX;
	dirY=0;
	if(Player::dirX == 1)
	{
		Player::flip = false;
	}
	else if (Player::dirX == -1)
	{
		Player::flip = true;
	}

	//prevents the sprite to loop more than its drawing on the sheet for the current row
	if (animationRow == 7 && curFrame == 7)
	{
		//curFrame = 0;
		Player::ResetAnimation(0);
	}
}

void Player::Shoot()
{
	Player::frameDelay = 3;
}

void Player::ResetAnimation(int position)
{
	if(position == 1)
	{
		
		//animationRow = 2;
		//curFrame=0;
		dirY = 0;
		dirX = 0;
		Player::frameDelay =3;
	}
	else if (position == 2)
	{
		//animationRow = 2;
		dirY = 0;
		dirX = 0;
		Player::frameDelay =3;
	}
	else if (position == 3)
	{
		//animationRow = 3;
		dirX = 0;
		dirY = 0;
		Player::frameDelay =3;
	}
	else if (position == 0)
	{
		/*
		if (animationRow == 6 && flip ==  true)
		{
			flip = true;
		}
		*/

		dirX = 0;
		dirY = 0;
		//curFrame = 0;
		animationRow = 2;
		Player::frameDelay =38;
		//prevents the sprite to loop more than its drawing on the sheet for the current row
		if (animationRow == 2 && curFrame > 4)
		{
			curFrame = 0;
		}
		
	}
}

//void Player::SetPosX(float pX)
//{
//	Player::posX = pX;
//}
//
//void Player::SetPosY(float pY)
//{
//	Player::posX = pY;
//}

int Player::GetPosX()
{
	return Player::posX;
}

int Player::GetPosY()
{
	return Player::posY;
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


int Player::GetX()
{
	return Player::x;
}

int Player::GetY()
{
	return Player::y;
}

void Player::SetVelocityX(float vX)
{
	Player::velocityX = vX;
}

void Player::SetVelocityY(float vY)
{
	Player::velocityY = vY;
}

float Player::GetVelocityX(){return Player::velocityX;}
float Player::GetVelocityY(){return Player::velocityY;}