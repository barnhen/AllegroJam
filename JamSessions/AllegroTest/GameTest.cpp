#include "GameTest.hpp"


/*

		Allegro 5 Shell Application v1.1
			by Mike Geig

		This code is provided for education purposes and comes with no warantee
		either implicit or explicit.

		This code is free to use however you see fit.
*/

bool keys[] = {false, false, false, false, false};
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE};


GameTest::GameTest(void)
{
	//==============================================
	//PROJECT VARIABLES
	//==============================================
	done = false;
	render = false;

	bound = false;
	collision = false;


	ball1.x = 0;
	ball1.y = 0;

	ball2.x = WIDTH  / 2;
	ball2.y = HEIGHT / 2;

};
GameTest::~GameTest(void){};


void GameTest::start()
{
	////==============================================
	////PROJECT VARIABLES
	////==============================================
	//bool done = false;
	//bool render = false;

	//bool bound = false;
	//bool collision = false;
	//Sprite ball1;
	//Sprite ball2;

	//ball1.x = 0;
	//ball1.y = 0;

	//ball2.x = WIDTH  / 2;
	//ball2.y = HEIGHT / 2;

	
	//==============================================
	//ALLEGRO VARIABLES
	//==============================================
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_FONT *font18 = NULL;
	
	//==============================================
	//ALLEGRO INIT FUNCTIONS
	//==============================================
	if(!al_init())										//initialize Allegro
		std::cout<<"Could not init display"<<std::endl;

	display = al_create_display(WIDTH, HEIGHT);			//create our display object

	if(!display)										//test display object
		std::cout<<"Could not create display"<<std::endl;

	//==============================================
	//ADDON INSTALL
	//==============================================
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();


	//==============================================
	//PROJECT INIT
	//==============================================
	font18 = al_load_font("arial.ttf", 18, 0);

	ball1.image = al_load_bitmap("orb.png");
	ball2.image = al_load_bitmap("orb.png");

	ball1.w = al_get_bitmap_width(ball1.image);
	ball1.h = al_get_bitmap_height(ball1.image);

	ball2.w = al_get_bitmap_width(ball2.image);
	ball2.h = al_get_bitmap_height(ball2.image);

	ball1.bx = ball1.w / 2 - 10;
	ball1.by = ball1.h / 2 - 20;

	ball2.bx = ball2.w / 2 - 10;
	ball2.by = ball2.h / 2 - 20;
	
	//==============================================
	//TIMER INIT AND STARTUP
	//==============================================
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);
	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//==============================================
		//INPUT
		//==============================================
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
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
			}
		}
		//==============================================
		//GAME UPDATE
		//==============================================
		else if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			render = true;

			//if(keys[UP])
			//	ball1.y -= 5;
			//else if(keys[DOWN])
			//	ball1.y += 5;

			//if(keys[LEFT])
			//	ball1.x -= 5;
			//else if(keys[RIGHT])
			//	ball1.x += 5;

			//if(keys[SPACE])
			//	bound = true;
			//else
			//	bound = false;


			//if( ball1.x + ball1.bx > ball2.x - ball2.bx &&
			//	ball1.x - ball1.bx < ball2.x + ball2.bx &&
			//	ball1.y + ball1.by > ball2.y - ball2.by &&
			//	ball1.y - ball1.by < ball2.y + ball2.by)
			//{
			//	collision = true;
			//}
			//else
			//	collision = false;

		}

		//==============================================
		//RENDER
		//==============================================
		if(render && al_is_event_queue_empty(event_queue))
		{
			render = false;

			al_draw_bitmap(ball2.image, ball2.x - ball2.w / 2, ball2.y - ball2.h / 2, 0);
			al_draw_bitmap(ball1.image, ball1.x - ball1.w / 2, ball1.y - ball1.h / 2, 0);

			//if(bound)
			//{
			//	al_draw_filled_rectangle(ball1.x - ball1.bx, ball1.y - ball1.by, ball1.x + ball1.bx, ball1.y + ball1.by, al_map_rgba_f(.6, 0, .6, .6));
			//	al_draw_filled_rectangle(ball2.x - ball2.bx, ball2.y - ball2.by, ball2.x + ball2.bx, ball2.y + ball2.by, al_map_rgba_f(.6, 0, .6, .6));
			//}

			//if(collision)
			//	al_draw_text(font18, al_map_rgb(255, 255, 255), WIDTH / 2, 20, ALLEGRO_ALIGN_CENTRE, "Collision!");

			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
	}

	//==============================================
	//DESTROY ALLEGRO OBJECTS
	//==============================================
	al_destroy_bitmap(ball1.image);
	al_destroy_bitmap(ball2.image);

	al_destroy_font(font18);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);

	//return 0;
}


