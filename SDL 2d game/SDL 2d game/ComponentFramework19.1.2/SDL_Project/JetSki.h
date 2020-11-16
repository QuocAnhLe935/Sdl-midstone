#ifndef JETSKI_H
#define JETSKI_H
#include "Body.h"
#include <SDL.h>
class JetSki : public Body {
public:
	
	JetSki();
	void jump(float vel_);
	void stop(float vel_);
	//void move(float vel_, pos_);
	~JetSki();
	JetSki(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_);

	void HandleEvents(const SDL_Event& c);
};
#endif // !JETSKI_H
