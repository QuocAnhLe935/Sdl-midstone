#ifndef SCENE0_H
#define SCENE0_H
#include <vector>
#include <fstream>
#include "base.h"
#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "player.h"
#include "Body.h"
#include "Collision.h"
#include "Ball.h"
using namespace MATH;
//on this side you will find class "test.map" 1 is green block try it around 0 is nothing -------->>>>
//scroll all the way down
class Scene0 : public Scene{
protected:
	//Scott's stuff
	SDL_Window *window;
	SDL_Rect camera;
	SDL_Rect imgLoc;
	SDL_Rect Loc;
	SDL_Rect relcoord;
	SDL_Rect blockrect;
	SDL_Rect dstrect;
	int n, m;
	//A vector inside a vector idk put, it related to our map
	std::vector<std::vector<int> > test;
	player* player1;
	bool b[2] = { 0,0 };
	
	SDL_Surface* backgroundImage,* image,* land,* block;
	
	//USE "s" key and "d" key to move try to move away from the platform see magic and move back b4 he go down 
	//to void
	int speed = 10;

	Matrix4 projection;
	
public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	SDL_Event u;
	bool OnCreate();
	void loadmap(const char* filename);
	void start();
	void showmap();
	bool collisionnew(SDL_Rect* rec1, SDL_Rect* rec2);
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(SDL_Event sdlEvent);
};

#endif

