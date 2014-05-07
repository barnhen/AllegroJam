#include "Camera.h"

using namespace camera;


/*Don't forget that the camera velocity is the key to make the char speed looks like it's running really fast or not. 
Not the player veloicity itself. No matter the velocity you char has. The camera must follow it otherwise it will properly
calculate x char position from scenario
*/
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
	al_init_primitives_addon(); //to draw a rectangle to perform as the camera view
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
	al_draw_rectangle(200, 300, 400, 500, al_map_rgba(.6, 0, .6, .6), 1);

	if (dX == 1) //moving left and scrolling right
	{
		//this will center de char into the middle of screen when running backwards
		//if (dX == 1 && player.GetPosX() <= PLAYER_POSITION_CENTER )
		//if (dX == 1 && player.GetPosX() <= bg.GetBgSize()- bg.GetBgSize() * 0.1 )
		if ((player.GetPosX() >= PLAYER_POSITION_CENTER && player.GetPosX() <= 848))
		{
			scrollable = true;
		}
		else 
		{
			scrollable = false;
		}

		// the most left margin limit minus the player center position on screen
		//else if(dX == 1 && player.GetPosX() <= (3266))
		//else if(dX == 1 && player.GetPosX() <= bg.GetBgSize() - (bg.GetBgSize() - bg.GetBgSize() * 0.1 ))
		//if(player.GetX() == PLAYER_POSITION_CENTER && player.GetPosX() <= 848) //848
		//{
		//	scrollable = true;
		//	//if (player.GetX() <= PLAYER_POSITION_CENTER && scrollable == true)
		//	//{
		//	//	player.SetX(PLAYER_POSITION_CENTER);
		//	//}

		//}
		/*else 
		{
			scrollable = false;
		}*/
 
		if (player.GetX() <= PLAYER_POSITION_CENTER && scrollable)
		{
			player.SetX(PLAYER_POSITION_CENTER);
		}

		//if (player.GetX() <= 0)
		//{
		//	player.SetX(0);
		//}
		// posX will never be less thaan zero since zero is the starting point of stage
		//if (player.GetPosX() <= 0)
		//{
		//	player.SetPosX(0);
		//}
		
	}
	else if (dX == -1) //moving right scrolling left
	{
			//this will center de char into the middle of screen when running forward
		//if (dX == -1 && player.GetPosX() <= PLAYER_POSITION_CENTER ) //old 4444
		//if (dX == -1 && player.GetPosX() <= bg.GetBgSize() - bg.GetBgSize() * 0.1 ) //old 4444
		
		if (player.GetPosX() >= 848)
		{
			
			scrollable = false;
		}
		// this value is the end of stage tileset - my choice of value
		//else if(dX == -1 && player.GetPosX() >= 3266)
		//else if(dX == -1 && player.GetPosX() >= bg.GetBgSize() - (bg.GetBgSize() - bg.GetBgSize() * 0.1 ))
		//else if(player.GetPosX() >= 848 ) //848
		//{
		//	scrollable = false;
		//}
		//else 
		//{
		//	if (dX == -1 && (player.GetPosX() <= PLAYER_POSITION_CENTER /*&& player.GetX() <= PLAYER_POSITION_CENTER*/) ) //old 4444
		//	{
		//		scrollable = false;
		//	}
		//	else
		//	{
		//		scrollable = true;
		//	}
		//	//if (player.GetX() >= PLAYER_POSITION_CENTER && scrollable == true)
		//	//{
		//	//	player.SetX(PLAYER_POSITION_CENTER);
		//	//}
		//}

		else 
		{
			if ((player.GetPosX() <= PLAYER_POSITION_CENTER /*&& player.GetX() <= PLAYER_POSITION_CENTER*/) ) //old 4444
			{
				scrollable = false;
			}
			else
			{
				scrollable = true;
			}
			//if (player.GetX() >= PLAYER_POSITION_CENTER && scrollable == true)
			//{
			//	player.SetX(PLAYER_POSITION_CENTER);
			//}
		}

		if (player.GetPosX() > PLAYER_POSITION_CENTER && scrollable)
		{
			player.SetX(PLAYER_POSITION_CENTER);
		}

		//if (player.GetX() <= 0)
		//{
		//	player.SetX(0);
		//}
		//3632 is my own left border limit
		//if (player.GetPosX() >= bg.GetBgSize()) 
		if (player.GetPosX() >= 1244) 
		{
			//player.SetPosX(bg.GetBgSize());
			player.SetPosX(1244);
		}
		//if (player.GetPosX() <= 0)
		//{
		//	player.SetPosX(0);
		//}

	}
	else if (dX == 0)
	{
		scrollable =false;
	}
	// if player X is > than middle of screen
	//if((WIDTH - player.GetX() >= 444) && scrollable == true) //old 444
	//scrollable = true;//just for test
	if ((dX == 1 || dX == -1 || dX == 0 ) && player.GetX() <= 0)
	{
		player.SetX(0);
	}

	// posX will never be less thaan zero since zero is the starting point of stage
	if ((dX == 1 || dX == -1 || dX == 0 ) && player.GetPosX() <= 0)
	{
		player.SetPosX(0);
	}

	// posX will never be less thaan zero since zero is the starting point of stage
	if ((dX == 1 || dX == -1 || dX == 0 ) && player.GetPosX() >= 1244)
	{
		player.SetPosX(1244);
	}

	//std::cout<<"scrollable at dX=0->"<<scrollable<<std::endl;
	//when stop running to x+ direction make sure it's always in center untill it's not
	if (dX == 0 && player.GetX() >= PLAYER_POSITION_CENTER && player.GetPosX() <= 848)
	{
			std::cout<<"Setting default position at dX positive=0->"<<scrollable<<std::endl;
			player.SetX(PLAYER_POSITION_CENTER);
	}
	//else if (dX == 0 && player.GetPosX() >= PLAYER_POSITION_CENTER && player.GetPosX() <= 848)
	//{
	//		std::cout<<"Setting default position at dX negative =0->"<<scrollable<<std::endl;
	//		player.SetX(PLAYER_POSITION_CENTER);
	//}

	//if (dX == 0 && player.GetPosX() >= PLAYER_POSITION_CENTER && scrollable)
	//{
	//		player.SetX(PLAYER_POSITION_CENTER);
	//}

	if(scrollable) //old 444
	{
		//if (dX == -1 && player.GetPosX )
		//{
	bg.SetDirX(dX);
	bg.SetVelx(player.GetVelocityX());
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
		//bg.SetDirX(dX);
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