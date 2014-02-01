#pragma once

#include "Background.hpp"
#include "Player.h"
using namespace background;

namespace camera{
	class Camera : public GameObject
	{
	public:
		Camera(void);
		~Camera(void);
		void SetCameraPosition(int dX, int dY, float vX, float vY);
		float GetCameraPosition();
		void ScrollCamera(int dX, int dY, float vX, float vY);
	private:

	};
}

