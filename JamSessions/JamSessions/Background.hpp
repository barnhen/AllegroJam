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
		//int map[];
	public: 
		Background(void);
		~Background(void);
		//Background(ALLEGRO_BITMAP *image, float velX);
		Background(ALLEGRO_BITMAP *image);

		void SetDirX(int &dX);
		void SetVelx(float &vX);
		void SetDirY(int &dY);
		void SetVelY(float &vY);

		int GetDirX();
		float GetVelX();
		int GetDirY();
		float GetVelY();

		float getX(); //to build tile collision
		float getY(); //to build tile collision
		int GetXOffset();
		int GetYOffset();
		int GetFrameWidth();

		int GetMap();
		//int getBoundX(const GameObject gameObject); //to build tile collision
		//int getBoundY(const GameObject gameObject); //to build tile collision


		int tileSize;

		void Update();
		void Render();

		//zero will be grass and 1 will be stone
		void SetMap(int mColumns, int mSize, int mTileSize);
		void DrawMap();

		//void Scroll(float velX);
	};

}