#include "Background.hpp"

using namespace background;

Background::Background(void)
{
}


Background::~Background(void)
{
}

//Background::Background(ALLEGRO_BITMAP *image, float velX)
Background::Background(ALLEGRO_BITMAP *image)
{
	//GameObject::Init(0, 0, velX, 0, 0, 0, 0, 0);

	SetID(MISC);
	SetCollidable(false);

	Background::image = image;
	frameWidth = al_get_bitmap_width(image);

	xOffset = 0;
	yOffset = 0;

	//columns, size tilesize
	Background::SetMap(40,400,64); //old 10,100,128

}

float Background::GetX()
{
	return Background::x;
}

float Background::GetY()
{
	return Background::y;
}


void Background::SetDirX(int dX)
{
	Background::dirX = dX;
}

void Background::SetVelx(float vX)
{
	Background::velX = vX;
}

void Background::SetDirY(int dY)
{
	Background::dirY = dY;
}

void Background::SetVelY(float vY)
{
	Background::velY = vY;
}

int Background::GetDirX()
{
	return Background::dirX;
}

float Background::GetVelX()
{
	return GameObject::velX;
}

int Background::GetDirY()
{
	return Background::velY;
}

float Background::GetVelY()
{
	return Background::velY;
}


//to build tile collision
//float Background::getX()
//{
//	return Background::x;
//} 
//
//
//float Background::getY()
//{
//	return Background::y;
//}

int Background::GetXOffset()
{
	return Background::xOffset;
}

int Background::GetYOffset()
{
	return Background::yOffset;
}



int Background::GetFrameWidth()
{
	return Background::frameWidth;
}

//int getBoundX(const GameObject gameObject); //to build tile collision
//int getBoundY(const GameObject gameObject); //to build tile collision

void Background::Init(float X, float Y, float velX, float velY, int dirX, int DirY, int boundX, int BoundY)
{
	//GameObject::Init(0, 0, velX, 0, 0, 0, dirX, 0);
	GameObject::Init(X, Y, velX, velY, dirX, dirY, boundX, BoundY);

}

void Background::Update()
{
	//std::cout<<"background x is "<<x<<std::endl;
	//std::cout<<"background frameWidth is "<<frameWidth<<std::endl;
	//std::cout<<"background velX is "<<velX<<std::endl;
	//std::cout<<"background dirX is "<<dirX<<std::endl;
	std::cout<<"WIDTH is "<<WIDTH<<std::endl;
	
	GameObject::Update();
	//if(Background::x < 0)
	//	x = 0;
	//else if(Background::x > WIDTH)
	//	x = WIDTH;

	//if(Background::y < 0)
	//	y = 0;
	//else if(Background::y > HEIGHT)
	//	y = HEIGHT;

//	If ()

	//Background::x += Background::velX * Background::dirX;
	std::cout<<"Background::x is "<<Background::x<<std::endl;

	if(Background::x + Background::frameWidth <= 0)
		x = 0;
}

void Background::Render()
{
	GameObject::Render();

	//al_draw_bitmap(image, x, y, 0);

	/*
	if(x + frameWidth < WIDTH)
	{
		//al_draw_bitmap(image, x + frameWidth, y, 0); //barnhen original
		//al_draw_bitmap(image, frameWidth, y, 0);
		
		al_draw_scaled_bitmap(image, x + frameWidth, y + frameHeight, frameWidth, frameHeight, 
			x - frameWidth / 2, y - frameHeight / 2, frameWidth * 2, frameHeight * 2,0);
			
	}	

	*/
	//zero will be grass and 1 will be stone
	//int map[] = {0,0,1,2,3,4,5,1,0,0,
	//			 0,1,0,0,1,1,0,0,1,0,
	//			 1,0,0,0,1,1,0,0,0,1,
	//			 0,1,0,0,1,2,3,4,6,0,
	//			 0,0,1,1,0,0,1,1,0,0,
	//			 0,0,1,1,0,0,1,1,0,0,
	//			 0,1,0,0,1,1,0,0,1,0,
	//			 0,0,1,1,0,0,1,1,0,0};

		int map[] = {0,0,1,2,3,4,5,1,0,0,0,0,1,2,3,4,5,1,0,0,0,0,1,2,3,4,5,1,0,0,0,0,1,2,3,4,5,1,0,0,
				 0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,
				 1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,
				 0,1,0,0,1,2,3,4,6,0,0,1,0,0,1,2,3,4,6,0,0,1,0,0,1,2,3,4,6,0,0,1,0,0,1,2,3,4,6,0,
				 0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,
				 0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,
				 0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,
				 0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0};


	if(x + frameWidth < WIDTH)
	{
		for (int i = 0; i < mapSize; i++)
		{
			al_draw_bitmap_region(image, tileSize * map[i],0,tileSize, tileSize,
				x + tileSize * (i % mapColumns), y + tileSize * (i/mapColumns),0);
		}
		//al_draw_bitmap(image, x + frameWidth, y, 0);

	}

	//if(x + frameWidth < WIDTH)
	//{
	//	for (int i = 0; i < mapSize; i++)
	//	{
	//		al_draw_bitmap_region(image, tileSize * map[i],0,tileSize, tileSize,
	//			xOffset + tileSize * (i % mapColumns) +frameWidth, yOffset + tileSize * (i/mapColumns),0);
	//	}
	//	//al_draw_bitmap(image, x + frameWidth, y, 0);
	//}
}

void Background::SetMap(int mColumns, int mSize, int mTileSize)
{
	mapColumns =mColumns;
	mapSize = mSize;
	tileSize = mTileSize;
		
}

void Background::DrawMap()
{
	/*
	//zero will be grass and 1 will be stone
	int map[] = {0,0,1,1,0,0,1,1,0,0,
				0,1,0,0,1,1,0,0,1,0,
				1,0,0,0,1,1,0,0,0,1,
				0,1,0,0,1,1,0,0,1,0,
				0,0,1,1,0,0,1,1,0,0,
				0,0,1,1,0,0,1,1,0,0,
				0,1,0,0,1,1,0,0,1,0,
				0,0,1,1,0,0,1,1,0,0};

	for (int i = 0; i < mapSize; i++)
	{
		al_draw_bitmap_region(image, tileSize * map[i],0,tileSize, tileSize,
			xOffset + tileSize * (i % mapColumns), yOffset + tileSize * (i/mapColumns),0);
	}
	*/
}

//void Background::Scroll(float velX)
//{
//	Background::x = Background::x + velX;
//}