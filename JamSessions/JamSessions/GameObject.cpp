#include "GameObject.h"


GameObject::GameObject()
{
	x = 0;
	y = 0;

	velX = 0;
	velY = 0;

	dirX = 0;
	dirY = 0;

	boundX = 0;
	boundY = 0;

	maxFrame = 0;
	curFrame = 0;
	frameCount = 0;
	frameDelay = 3;
	frameWidth = 0;
	frameHeight = 0;
	animationColumns = 0;
	animationDirection = 0;

	image = NULL;

	alive = true;
	collidable = true;
}


GameObject::~GameObject()
{
}

void GameObject::Init(float x, float y, float velX, float velY, int dirX, int dirY, int boundX, int boundY)
{
	GameObject::x = x;
	GameObject::y = y;

	GameObject::velX = velX;
	GameObject::velY = velY;

	GameObject::dirX = dirX;
	GameObject::dirY = dirY;

	GameObject::boundX = boundX;
	GameObject::boundY = boundY;

	GameObject::posX = x; // rember 20 is the starting point
}

void GameObject::SetX(float x) {GameObject::x = x;}
void GameObject::SetY(float y) {GameObject::y = y;}
void GameObject::SetPosX(float pX) {GameObject::posX = pX;}
void GameObject::SetPosY(float pY) {GameObject::posY = pY;}


float GameObject::GetX() 
{
	return GameObject::x;
}
	
float GameObject::GetY() 
{
	return GameObject::y;
}

float GameObject::GetPosX()
{
	return GameObject::posX;
}

float GameObject::GetPosY()
{
	return GameObject::posY;
}

//int SetDirX()
//{
//	
//}
//
//float SetVelx()
//{
//
//}
//
//int SetDirY()
//{
//
//}
//
//float SetVelY()
//{
//
//}

void GameObject::Update()
{
	x += velX * dirX;
	y += velY * dirY;

	posX += velX * dirX;
	posY += velY * dirY;
	//if (dirX == -1)
	//{
	//	posX-=1;
	//	//posX = 0;
	//	//posX += velX * dirX;
	//}
	//else if(dirX == 1)
	//{
	//	posX+=1;
	//	//posX = 0;
	//	//posX += velX * dirX;
	//}
	//if (dirY == 1)
	//{
	//	posY ++;
	//}
	//else if(dirX == -1)
	//{
	//	posX--;
	//}

	GameObject::SetX(x);
	GameObject::SetY(y);
	GameObject::SetPosX(posX);
	GameObject::SetPosY(posY);
}

void GameObject::Render()
{}

bool GameObject::CheckCollisions(GameObject *otherObject)
{
	float oX = otherObject->GetX();
	float oY = otherObject->GetY();

	int obX = otherObject->GetBoundX();
	int obY = otherObject->GetBoundY();

	if( x + boundX > oX - obX &&
		x - boundX < oX + obX &&
		y + boundY > oY - obY &&
		y - boundY < oY + obY)
		return true;
	else
		return false;
}

void GameObject::Collided(int objectID)
{}

bool GameObject::Collidable()
{
	return alive && collidable;
}
