#pragma once

#include "Background.hpp"
#include "Player.h"
using namespace background;
using namespace nPlayer;

namespace camera{
	class Camera
	{
	public:
		Camera(void);
		~Camera(void);
		void SetCameraPosition(int dX, int dY, float vX, float vY);
		float GetCameraPosition();
		//void ScrollCamera(const int *&dX, const int *&dY, const float *&vX, const float *&vY);
		//void ScrollCamera(const int dX,const  int dY,const  float vX, const float vY);
		
		void ScrollCamera(Background& bg, Player& player, int dX);
		//void ScrollCamera(Background& bg,int dX);

	private:

	};
}

