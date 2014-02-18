#pragma once

const int WIDTH = 800;
const int HEIGHT = 600;

const float PLAYER_POSITION_CENTER = float(WIDTH/2) - 44; //44 is the half char frame width

enum ID{PLAYER, ENEMY, BULLET, BORDER, MISC, EXPLOSION};
enum STATE{TITLE, PLAYING, LOST};