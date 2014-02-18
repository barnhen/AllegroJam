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

//void Camera::ScrollCamera(const int *&dX,const  int *&dY,const  float *&vX, const float *&vY)
//void Camera::ScrollCamera(const int dX,const  int dY,const  float vX, const float vY)
//void Camera::ScrollCamera(Background& bg, int dX)

//will receive background object as reference because we want to change that
//setting Dir and vel the game object update will do the rest
void Camera::ScrollCamera(Background& bg, Player& player, int dX)
{ 
	//float x = 0;
	//float y = 0;
	//if (player.GetX()==0)
	//{
	//}
	//Player player;

	
	//if (player.GetX() == 400)
	//{
	//	std::cout<<"Hi";
	//}
	//if (dX == 1){

	if (dX == 1)
	{
		//this will center de char into the middle of screen
		if (player.GetX() == PLAYER_POSITION_CENTER)
		{
			player.SetX(PLAYER_POSITION_CENTER);
		}
	}
	else if (dX == -1)
	{
			//this will center de char into the middle of screen
		if (player.GetX() > PLAYER_POSITION_CENTER)
		{
			player.SetX(PLAYER_POSITION_CENTER);
		}
	}

		if(WIDTH - player.GetX() == 444)
		{
			bg.SetDirX(dX);
			bg.SetVelx(1);
		}
	//}
	//else if(dX == -1){
	//	if(WIDTH - player.GetX() == 444)
	//	{
	//		bg.SetDirX(dX);
	//		bg.SetVelx(1);
	//	}
	//}
	//bg.SetDirX(dX);
	//bg.SetVelx(1);
}