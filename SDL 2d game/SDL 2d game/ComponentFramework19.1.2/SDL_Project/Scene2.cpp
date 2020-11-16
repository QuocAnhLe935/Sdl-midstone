#include "Scene2.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Collision.h"
Scene2::Scene2(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
}

Scene2::~Scene2() {
}


bool Scene2::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0, 20.0, 0.0, 10.0, 0.0, 1.0);//30 20
	projection = ndc * ortho;



	jetSki2 = new JetSki();
	jetSkiImage2 = IMG_Load("player.bmp");

	return true;


}




void Scene2::OnDestroy() {

	delete jetSkiImage2;

}


void Scene2::Update(const float time) {
	jetSki2->Update(time);


}


void Scene2::Render() {
	Vec3 pos = jetSki2->GetPos();
	Vec3 screenPos2 = projection * pos;
	SDL_Rect dstrect2;
	dstrect2.x = static_cast<int>(screenPos2.x);
	dstrect2.y = static_cast<int>(screenPos2.y);
	SDL_Surface *screenSurface2 = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface2, nullptr, SDL_MapRGB(screenSurface2->format, 0xff, 0xff, 0xff));


	SDL_BlitSurface(jetSkiImage2, nullptr, screenSurface2, &dstrect2);

	SDL_UpdateWindowSurface(window);

}

//Map movement using SDI key event
void Scene2::HandleEvents(SDL_Event e) {



}