#include "Camera.h"

using namespace camera;


Camera::Camera(void)
{
}


Camera::~Camera(void)
{
}

void Camera::SetCameraPosition(int dX, int dY, float vX, float vY)
{

}
float Camera::GetCameraPosition()
{
	return 0.0;
}

void Camera::ScrollCamera(int dX, int dY, float vX, float vY)
{ 
	float x = 0;
	float y = 0;
	Background *bg = new Background();
	Player *player = new Player();
	bg->SetDirX(dX);
	bg->SetDirY(dY);
	bg->SetVelx(vX);
	bg->SetVelY(vY);

	

	//x += vX * dX;
	//y += vY * dY;
	//bg->Update();
	//bg->SetX(x);
	//bg->SetY(y);

	//if()
}