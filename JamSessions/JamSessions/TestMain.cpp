#include<allegro5\allegro.h>
#include<allegro5\allegro_image.h>
#include<allegro5\allegro_font.h>
#include<allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include<iostream>
#include<list>
#include <math.h>

#include "GameObject.h"
#include "Player.h"
#include "Globals.h"
#include "InputManager.h"
#include "Background.hpp"
#include "Camera.h"

using namespace background;
using namespace nPlayer;
using namespace camera;

bool keys[] = {false, false, false, false, false, false,false};
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE, C,E};
Player *player;
InputManager *input;
Camera *cam;
std::list<GameObject *> objects;
std::list<GameObject *>::iterator iter;
std::list<GameObject *>::iterator iter2;

//enum PLAYER_ANIMATION{UP,DOWN,LEFT,RIGHT,JUMP};
int main(){
	// don't forget to put allegro-5.0.10-monolith-md-debug.lib
	//==============================================
	//SHELL VARIABLES
	//==============================================
	bool done = false;
	bool render = false;
	bool bound = false; // to draw colision box
	bool moveRight = false;
	bool moveLeft = false;

	float gameTime = 0;
	int frames = 0;
	int gameFPS = 0;

	//int camDx, camDy;
	//int *camDx, *camDy;
	//float camVelX, camVelY;
	//float *camVelX, *camVelY;

	//int width = 640;
	//int height = 480;

	//int x = width/2;
	//int y = height/2;
	
	//const int maxFrame = 3; // 8 frames animation
	//int curFrame = 0;
	//int frameCount = 0;
	//int frameDelay = 5;

	//int frameWidth = 31; // refers the size of my spritesheet
	//int frameHeight = 30; // refers the size of my spritesheet

	//==============================================
	//PROJECT VARIABLES
	//==============================================
	player = new Player();
	input = new InputManager();

	//==============================================
	//ALLEGRO VARIABLES
	//==============================================
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_BITMAP *image = NULL;
	ALLEGRO_FONT *font18 = NULL;
	//ALLEGRO_BITMAP *bgImage = NULL;
	ALLEGRO_BITMAP *bgSheet=NULL;
	
	//==============================================
	//ALLEGRO INIT FUNCTIONS
	//==============================================
	//check if allegro is initialised <allegro_native_dialog.h>
	if(!al_init()){ 
		return -1;
	}

	display = al_create_display(WIDTH,HEIGHT);
	

	//check if display was created
	if(!display){
		return -1;
	}

	//==============================================
	//ADDON INSTALL
	//==============================================
	al_install_keyboard();// will initialize keyboard events
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon(); //for bound collision

	//==============================================
	//PROJECT INIT
	//==============================================
	font18 = al_load_font("arial.ttf", 18, 0);

	
	//bgImage = al_load_bitmap("tile_stage1_bottom.png");
	bgSheet = al_load_bitmap("TileStage.png");//background.png
	//by makinge 'new' they are different bg in memory
	//Background *bg = new Background(bgImage, 1);
	
	//by makinge 'new' they are different bg in memory
	//Background *bg = new Background(bgSheet, 1);
	Background *bg = new Background(bgSheet);
	objects.push_back(bg);

	//image = al_load_bitmap("player.png");
	image = al_load_bitmap("mmx_x4_x_sheet_v1.png");
	if(!image){
		std::cout<<"Couldn't load player image"<<std::endl;
		return -1;
	}
	al_convert_mask_to_alpha(image, al_map_rgb(255,255,255));
	player->Init(image, 12, 12);
	objects.push_back(player);

	//std::cout<<"from main the tilesize is"<<bg->tileSize<<std::endl;

	eventQueue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_register_event_source(eventQueue, al_get_keyboard_event_source());

	al_start_timer(timer);


	while(!done){
		ALLEGRO_EVENT ev;
		al_wait_for_event(eventQueue, &ev); // tells the eventQueue wait for an input
		
		/*
		if(input->IsKeyPressed(ev, ALLEGRO_EVENT_KEY_DOWN))
		{
			switch(ev.keyboard.keycode){
			case ALLEGRO_KEY_ESCAPE: 
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT]=true;;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT]=true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN]=true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP]=true;
				break;
			
			}
				
		}		
		else if (input->IsKeyPressed(ev, ALLEGRO_EVENT_KEY_UP))
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;
			}
		}
		*/
		
		if (ev.type==ALLEGRO_EVENT_KEY_DOWN){
			switch(ev.keyboard.keycode){
			case ALLEGRO_KEY_ESCAPE: 
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT]=true;;
				//x -=5;
				//player->ResetAnimation(0);
				break;
			case ALLEGRO_KEY_RIGHT:
				//x +=5;
				keys[RIGHT]=true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN]=true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP]=true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE]=true;
				break;
			case ALLEGRO_KEY_E:
				keys[E] = true;
				break;
			//for drawing collision boxes
			case ALLEGRO_KEY_C:
				keys[C] = true;
				break;
			}
			
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;
			case ALLEGRO_KEY_E:
				keys[E] = false;
				break;
			//for drawing collision boxes
			case ALLEGRO_KEY_C:
				keys[C] = false;
				break;
			}
		}
		
		//==============================================
		//GAME UPDATE
		//==============================================		
		else if (ev.type == ALLEGRO_EVENT_TIMER){
			render=true;

			//UPDATE FPS===========
			frames++;
			if(al_current_time() - gameTime >= 1)
			{
				gameTime = al_current_time();
				gameFPS = frames;
				frames = 0;
			}
			//=====================
			/*
			if (keys[UP]){
				x -= 5;
			}
			else if (keys[DOWN]){
				x += 5;
			}

			if (keys[LEFT]){
				x -= 5;
			}
			else if (keys[RIGHT]) {
				x += 5;
			}
			*/

			if(keys[UP])
			{
				
				for(iter = objects.begin(); iter != objects.end(); ++iter)
				(*iter)->Update();
				

				player->MoveUp();
				//keys[DOWN]=false;
				//keys[LEFT]=false;
				//keys[RIGHT]=false;
			}
			else if(keys[DOWN])
			{
				
				for(iter = objects.begin(); iter != objects.end(); ++iter)
				(*iter)->Update();
				

				player->MoveDown();
				//keys[UP]=false;
				//keys[LEFT]=false;
				//keys[RIGHT]=false;
			}
			else if(keys[LEFT])
			{
				moveRight = false;
				
				for(iter = objects.begin(); iter != objects.end(); ++iter)
				(*iter)->Update();
				

				moveLeft = player->MoveLeft();
				cam->ScrollCamera(*bg, *player,1);

				
				if (keys[E]){player->Dash(-1, 12);}
				//if ((WIDTH - player->GetX()) == 400 && (WIDTH - player->GetX()) > 0)
				//{
					// will pass the background object to scroll the camera. It will be recceived as reference by the camera
					cam->ScrollCamera(*bg, *player,1);
					//cam->ScrollCamera(*bg, 1,1);
					//cam->ScrollCamera(*bg, 1);
				//}
				//keys[DOWN]=false;
				//keys[UP]=false;
				//keys[RIGHT]=false;
			}
			else if(keys[RIGHT])
			{
				moveLeft = false;
				for(iter = objects.begin(); iter != objects.end(); ++iter)
				(*iter)->Update();

				moveRight = player->MoveRight();
				cam->ScrollCamera(*bg, *player,-1);

				if (keys[E]){player->Dash(1, 12);}
				//camDx = 1;
				//camDy = 0;
				//camVelX = -1;
				//camVelY = 1;
				//*camDx = &camDx;
				
				//// will pass the background object to scroll the camera. It will be recceived as reference by the camera
				//cam->ScrollCamera(*bg, *player,-1);
				//cam->ScrollCamera(*bg, -1,-1);
				//if ((WIDTH - player->GetX()) == 400 && (WIDTH - player->GetX()) > 0)
				//{
					// will pass the background object to scroll the camera. It will be recceived as reference by the camera
					cam->ScrollCamera(*bg, *player,-1);
				//}

				//bg->SetDirX(0);

				
				//keys[DOWN]=false;
				//keys[LEFT]=false;
				//keys[UP]=false;
			}
			else if(keys[SPACE])
			{
				player->Jump();
			}
			else if(keys[E])
			{
				for(iter = objects.begin(); iter != objects.end(); ++iter)
				{
					
					(*iter)->Update();
					//if (keys[RIGHT]){player->Dash(1, 12);}
					if (moveRight)
					{
						moveLeft = false;
						player->Dash(1, 12);
						cam->ScrollCamera(*bg, *player,-1);
					}
					//if (keys[LEFT]){player->Dash(-1, 12);}
					if (moveLeft)
					{
						moveRight = false;
						player->Dash(-1, 12);
						cam->ScrollCamera(*bg, *player,1);
					}
				}
				
			}
			else
			{
				
			/*
				if(keys[UP])
					player->MoveUp(); //old 1
				else if (keys[DOWN])
					player->MoveDown(); //old 1
				else if (keys[LEFT])
					player->MoveLeft(); //old 1
				else if (keys[RIGHT])
					player->MoveRight(); //old 1
				else
					player->ResetAnimation(0);
				//player->ResetAnimation(0);// old 0
			*/
/*
				for(iter = objects.begin(); iter != objects.end(); ++iter)
				(*iter)->Update();
*/
				//player->ResetAnimation(0);
				player->Update();
				player->ResetAnimation(0);
				cam->ScrollCamera(*bg, *player,0);

				
				/*
				if(keys[UP])
					player->MoveUp();
				else if(keys[DOWN])
					player->MoveDown();
				else
					player->ResetAnimation(1);

				if(keys[LEFT])
					player->MoveLeft();
				else if(keys[RIGHT])
					player->MoveRight();
				else
					player->ResetAnimation(0);
				*/
			}
			//for drawing collision boxes
			if(keys[C])
				bound = true;
			else
				bound = false;

			//update
			
			//for(iter = objects.begin(); iter != objects.end(); ++iter)
			//	(*iter)->Update();
			
			/*
			if(++player->frameCount >= frameDelay){
				if(++curFrame >= maxFrame)
				{
					curFrame = 0;

				}
				frameCount=0;
			}
			/*
			//x -=5;
			
			if(x <= 0 - frameWidth){
				x = width;
			}
			*/
		}
		 
		//make sure when exiting the program exit with esc button
		/* 	
		else if (ev.type == ALLEGRO_EVENT_KEY_UP){
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				done = true;
				break;
			}
		}

		*/
		
		/*
			the below will create the sprite sheet
			image = the sprite sheet
			sx = the size x starting point of sprite sheet i.3 0 to 128 pixels, so that's why we're multipliyng it by curFrame which will add ++ each frame
			sy = the size y starting point of sprite sheet
			sw = how width is the image
			sh = how tall is the image
			dx = where it is gonna put x
			dy = where it is gonna put y
		*/
		//==============================================
		//RENDER
		//==============================================
		if(render && al_is_event_queue_empty(eventQueue))
		{
			render = false;
			//al_draw_textf(font18, al_map_rgb(255, 0, 255), 5, 5, 0, "FPS: %i", gameFPS); // display game FPS on screen

			

			for(iter = objects.begin(); iter != objects.end(); ++iter)
					(*iter)->Render();
			//al_draw_bitmap_region(image, curFrame * frameWidth,0, frameWidth, frameHeight, x,y,0);


			if(bound)
			{
				//std::cout<<"bound"<<std::endl;
				al_draw_filled_rectangle(bg->GetX(), bg->GetY(), bg->tileSize, bg->tileSize, al_map_rgba_f(.6, 0, .6, .6));
				//al_draw_filled_rectangle(bg->tileSize, bg->tileSize, bg->tileSize, bg->tileSize, al_map_rgba_f(.6, 0, .6, .6));
				//al_draw_filled_rectangle(64, 400, 400, 128, al_map_rgba_f(.6, 0, .6, .6));
				//al_draw_filled_rectangle(0, 128, 128, 128, al_map_rgba_f(.6, 0, .6, .6));
			}

			al_draw_textf(font18, al_map_rgb(255, 255, 0), 5, 5, 0, "FPS: %i", gameFPS); // display game FPS on screen
			al_draw_textf(font18, al_map_rgb(255, 255, 0), 75, 5, 0, "player X: %i", player->GetX());
			al_draw_textf(font18, al_map_rgb(255, 255, 0), 195, 5, 0, "player Y: %i", player->GetY());
			al_draw_textf(font18, al_map_rgb(255, 255, 0), 325, 5, 0, "Player Pos+: %i", WIDTH - player->GetX());
			al_draw_textf(font18, al_map_rgb(255, 255, 0), 495, 5, 0, "Player Centre: %2f", PLAYER_POSITION_CENTER);
			al_draw_textf(font18, al_map_rgb(255, 255, 0), 5, 25, 0, "Background FrameWidth: %i", bg->GetFrameWidth());
			al_draw_textf(font18, al_map_rgb(255, 255, 0), 5, 50, 0, "player posX: %i", player->GetPosX());
			al_draw_textf(font18, al_map_rgb(255, 255, 0), 185, 50, 0, "BG Size: %i", bg->GetBgSize());
			al_draw_textf(font18, al_map_rgb(255, 255, 0), 445, 50, 0, "Player VelX: %i", player->GetVelX());

			al_draw_textf(font18, al_map_rgb(255, 255, 0), 645, 50, 0, "Player DirX: %i", player->GetDirX());

			
			
			al_flip_display();

		
			al_clear_to_color(al_map_rgb(0,0,0)); //that prevents the filled rectangle draw imga just like snake style

		}
	}

	//al_rest(5.0);
	/*
	for (int i = 0; i < maxFrame; i++)
	{
		al_destroy_bitmap(image[i]);
	}
	*/
	//==============================================
	//DESTROY ALLEGRO OBJECTS
	//==============================================
	for(iter = objects.begin(); iter != objects.end(); )
	{
		//(*iter)->Destroy();
		delete (*iter);
		iter = objects.erase(iter);
	}

	al_destroy_bitmap(image);
	//al_destroy_bitmap(bgImage);
	al_destroy_bitmap(bgSheet);
	al_destroy_font(font18);
	al_destroy_event_queue(eventQueue);
	al_destroy_display(display);
	al_destroy_timer(timer);
	delete input;


//hey

return 0;
}