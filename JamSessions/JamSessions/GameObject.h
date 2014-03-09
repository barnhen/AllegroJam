#pragma once

#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include "Globals.h"

class GameObject
{
private:
	int ID;
	bool alive;
	bool collidable;

protected:
	float x;
	float y;

	float posX;
	float posY;

	float velX;
	float velY;

	int dirX;
	int dirY;

	int boundX;
	int boundY;

	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	//int frameWidth;
	//int frameHeight;
	float frameWidth;
	float frameHeight;
	int animationColumns;
	int animationDirection;

	ALLEGRO_BITMAP *image;

public:
	GameObject();
	~GameObject();
	void Init(float x, float y, float velX, float velY, int dirX, int dirY, int boundX, int boundY);
	
	//float getX();
	//float getY();


	void virtual Update();
	void virtual Render();

	float GetX();
	float GetY();
	float GetPosX();
	float GetPosY();

	//int SetDirX();
	//float SetVelx();
	//int SetDirY();
	//float SetVelY();

	void SetX(float x);
	void SetY(float y);

	void SetPosX(float pX);
	void SetPosY(float pY);

	int GetBoundX() {return boundX;}
	int GetBoundY() {return boundY;}

	int GetID() {return ID;}
	void SetID(int ID) {GameObject::ID = ID;}

	bool GetAlive() {return alive;}
	void SetAlive(bool alive) {GameObject::alive = alive;}

	bool GetCollidable() {return collidable;}
	void SetCollidable(bool collidable) {GameObject::collidable = collidable;}

	bool CheckCollisions(GameObject *otherObject);
	void virtual Collided(int objectID);
	bool Collidable();
};

