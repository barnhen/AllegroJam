#pragma once
#include<allegro5\allegro5.h>
#include<vector>

// X engine
class InputManager
{
private:
	ALLEGRO_KEYBOARD_STATE keystate;
	//ALLEGRO_KEYBOARD_ keystate;
public:
	InputManager(void);
	~InputManager(void);

	bool IsKeyPressed(ALLEGRO_EVENT ev, int key);
	bool IsKeyPressed(ALLEGRO_EVENT ev, std::vector<int> keys);

	bool IsKeyReleased(ALLEGRO_EVENT ev, int key);
	bool IsKeyReleased(ALLEGRO_EVENT ev, std::vector<int> keys);
};

