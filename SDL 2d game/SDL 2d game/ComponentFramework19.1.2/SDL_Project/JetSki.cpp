#include "JetSki.h"
#include <iostream>


JetSki::JetSki() 
{
printf("HellO jetski contruct");


}

void JetSki::jump( float vel_)
{
	int jumpc=0;
	
	if (jumpc < 2) {
		jumpc++;
		vel.y = vel_;
	}
	
}

void JetSki::stop(float vel_)
{
	vel.y = vel_;
}



//bool isGrounded;


JetSki::~JetSki()
{
}

JetSki::JetSki(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_)
{
	pos.x = pos_.x;
	pos.y = pos_.y;
	pos.z = pos_.z;

	vel.x = vel_.x;
	vel.y = vel_.y;
	vel.z = vel_.z;

	accel.x = accel_.x;
	accel.y = accel_.y;
	accel.z = accel_.z;

	mass = mass_;
	
	

}








void JetSki::HandleEvents(const SDL_Event& c) {
	/*if (c.type == SDL_KEYDOWN) {
		switch (c.key.keysym.sym) {
		case SDLK_LEFT:
			vel.x = -10.0;
			break;
		case SDLK_RIGHT:
			vel.x = 10.0;
			break;
		case SDLK_UP:
			
			JetSki::jump(10.0);
			break;
			

		}
		
	}

	if (c.type == SDL_KEYUP) {
		switch (c.key.keysym.sym) {
		case SDLK_LEFT:
			vel.x = 0.0;
			break;
		case SDLK_RIGHT:
				vel.x = 0.0;
				break;
		case SDLK_UP:
			vel.y = -10.0;
			break;
		}
	}*/
}