#pragma once
#include "GameObject.h"
namespace background{
	extern int map[]; // with this 'extern' the complier won't be complaining about the var being undefined
	class Background : public GameObject
	{
	private:
		int mapColumns;
		int mapSize;	
		int xOffset;
		int yOffset;
		int bgSize;
		//int map[];
	public: 
		Background(void);
		~Background(void);
		//Background(ALLEGRO_BITMAP *image, float velX);
		Background(ALLEGRO_BITMAP *image);

		void SetDirX(int dX);
		void SetVelx(float vX);
		void SetDirY(int dY);
		void SetVelY(float vY);
		void SetBgSize(int tileSize, int colQty);

		int GetDirX();
		float GetVelX();
		int GetDirY();
		float GetVelY();

		float GetX(); //to build tile collision
		float GetY(); //to build tile collision


		//float getX(); //to build tile collision
		//float getY(); //to build tile collision
		int GetXOffset();
		int GetYOffset();
		int GetFrameWidth();

		int GetMap();
		int GetBgSize();
		//int getBoundX(const GameObject gameObject); //to build tile collision
		//int getBoundY(const GameObject gameObject); //to build tile collision


		int tileSize;

		void Init(float X, float Y, float velX, float velY, int dirX, int DirY, int boundX, int BoundY);

		void Update();
		void Render();

		//zero will be grass and 1 will be stone
		void SetMap(int mColumns, int mSize, int mTileSize);
		void DrawMap();

		//void Scroll(float velX);
	};

}