#ifndef  REALPLAYER_H
#define REALPLAYER_H
#include "Body.h"
#include <SDL.h>

class realPlayer : public Body
{
public:
	realPlayer();
	~realPlayer();
	realPlayer(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_);
	void HandleEvents(const SDL_Event& c);
};

#endif // ! REALPLAYER_H