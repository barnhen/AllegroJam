#pragma once
#include "GameObject.h"

class Background : public GameObject
{
private:
	int mapColumns;
	int mapSize;
	int tileSize;
	int xOffset;
	int yOffset;
	//int map[];
public: 
	Background(void);
	~Background(void);
	Background(ALLEGRO_BITMAP *image, float velX);

	void Update();
	void Render();

	//zero will be grass and 1 will be stone
	void SetMap(int mColumns, int mSize, int mTileSize);
	void DrawMap();
};

