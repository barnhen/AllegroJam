#include "Background.hpp"


/*
Background::Background(void)
{
}
*/

Background::~Background(void)
{
}

Background::Background(ALLEGRO_BITMAP *image, float velX)
{
	GameObject::Init(0, 0, velX, 0, -1, 0, 0, 0);

	SetID(MISC);
	SetCollidable(false);

	Background::image = image;
	frameWidth = al_get_bitmap_width(image);

	xOffset = 0;
	yOffset = 0;

	Background::SetMap(10,100,128);

}

void Background::Update()
{
	std::cout<<"background x is "<<x<<std::endl;
	std::cout<<"background frameWidth is "<<frameWidth<<std::endl;
	std::cout<<"WIDTH is "<<WIDTH<<std::endl;
	GameObject::Update();
	if(x + frameWidth <= 0)
		x = 0;
}

void Background::Render()
{
	GameObject::Render();

	al_draw_bitmap(image, x, y, 0);

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