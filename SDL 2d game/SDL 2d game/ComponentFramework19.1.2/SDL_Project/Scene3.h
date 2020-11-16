#ifndef SCENE3_H
#define SCENE3_H
#include <vector>
#include <fstream>
#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Collision.h"
#include "JetSki.h"
#include "GameManager.h"
#include "Map2.h"
#include "realPlayer.h"
#include "Ball.h"
using namespace MATH;

class Scene3 : public Scene {
protected:
	SDL_Window *window;
	SDL_Rect camera;
	SDL_Surface* jetimage;
	SDL_Surface* image;
	SDL_Surface* playerimage;
	Matrix4 projection;
	JetSki* jetSki;
	realPlayer* player;
	SDL_Rect frame;
	//SDL_Surface* baseLayer = SDL_CreateRGBSurface(0, 640, 640, 16, 0, 0, 0, 0);
	Map2 draw;

public:
	Scene3(SDL_Window* sdlWindow);
	~Scene3();
	
	
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(SDL_Event sdlEvent);

	
};

#endif