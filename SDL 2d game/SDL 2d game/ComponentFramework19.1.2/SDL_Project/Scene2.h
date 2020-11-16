#ifndef SCENE2_H
#define SCENE2_H
#include <vector>
#include <fstream>
#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Collision.h"
#include "JetSki.h"
#include "Ball.h"
using namespace MATH;

class Scene2 : public Scene {
protected:
	SDL_Window *window;
	SDL_Rect camera;
	JetSki * jetSki2;
	SDL_Surface* jetSkiImage2;
	Matrix4 projection;

public:
	Scene2(SDL_Window* sdlWindow);
	~Scene2();

	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(SDL_Event sdlEvent);
};

#endif

