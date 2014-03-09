#include "Camera.h"

using namespace camera;



//posX -> is the relative position of player to the backgroung width
//player::x -> is the relative position to the screen width. Used to center the char on screen when scrolling background
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

	bool scrollable = false;
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
		//this will center de char into the middle of screen when running backwards
		if (dX == 1 && player.GetPosX() <= PLAYER_POSITION_CENTER )
		{
			scrollable = false;
		}
		// the most left margin limit minus the player center position on screen
		else if(dX == 1 && player.GetPosX() <= (3266))
		{
			scrollable = true;
		}
		else 
		{
			scrollable = false;
		}
 
		if (player.GetX() <= PLAYER_POSITION_CENTER && scrollable == true)
		{
			player.SetX(PLAYER_POSITION_CENTER);
		}

		else if (player.GetX() <= 0)
		{
			player.SetX(0);
		}
		// posX will never be less thaan zero since zero is the starting point of stage
		if (player.GetPosX() <= 0)
		{
			player.SetPosX(0);
		}
		
	}
	else if (dX == -1)
	{
			//this will center de char into the middle of screen when running forward
		if (dX == -1 && player.GetPosX() <= PLAYER_POSITION_CENTER ) //old 4444
		{
			scrollable = false;
		}
		// this value is the end of stage tileset - my choice of value
		else if(dX == -1 && player.GetPosX() >= 3266)
		{
			scrollable = false;
		}
		else 
		{
			scrollable = true;
		}

		if (player.GetX() >= PLAYER_POSITION_CENTER && scrollable == true)
		{
			player.SetX(PLAYER_POSITION_CENTER);
		}

		/*else if (player.GetX() <= 0)
		{
			player.SetX(0);
		}*/
		//3632 is my own left border limit 
		if (player.GetPosX() >= 3632)
		{
			player.SetPosX(3632);
		}
		//if (player.GetPosX() <= 0)
		//{
		//	//player.SetPosX(0);
		//}

	}

	// if player X is > than middle of screen
	//if((WIDTH - player.GetX() >= 444) && scrollable == true) //old 444
	if(scrollable) //old 444
	{
		//if (dX == -1 && player.GetPosX )
		//{
	bg.SetDirX(dX);
	bg.SetVelx(1);
		//}
		//else
		//{
		//	bg.SetDirX(dX);
		//	bg.SetVelx(1);
		//}
	}
	else
	{
		bg.SetDirX(0);
		bg.SetVelx(0);
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