#ifndef BALL_H
#define BALL_H
#include "GameObject.h"

#include "Body.h"
#include <SDL.h>
class Ball : public Body
	//public Body
{
public:
	Ball();
	Ball(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_);
	~Ball();
	
};

#endif