#ifndef SCENE1_H
#define SCENE1_H
#include <vector>
#include <fstream>
#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Collision.h"
#include "JetSki.h"
#include "Ball.h"
using namespace MATH;

class Scene1 : public Scene {
protected:
	SDL_Window *window;
	SDL_Rect camera;
	JetSki * jetSki;
	SDL_Surface* jetSkiImage;
	Matrix4 projection;

public:
	Scene1(SDL_Window* sdlWindow);
	~Scene1();

	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(SDL_Event sdlEvent);
};

#endif

