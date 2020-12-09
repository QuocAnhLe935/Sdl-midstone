#include "Scene3.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Collision.h"
#include "GameManager.h"
Scene3::Scene3(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
}

Scene3::~Scene3() {
}




bool Scene3::OnCreate() {
	bool success;
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0, 30.0, 0.0, 20.0, 0.0, 1.0);//30 20
	projection = ndc * ortho;

	player = new realPlayer(Vec3(15.0f, 10.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 0.0f);
	
	
	
	playerimage = IMG_Load("enemy.bmp");
	if (!playerimage) {
		std::cout << "Failed to load enemy.bmp!" << std::endl;
	}

	image = IMG_Load("tile33.PNG");
	if (!image) {
		std::cout << "Failed to load TileSheet_01.png!" << std::endl;
	}
	
	//create baselayer
	

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		//std::cout << "SDL_image could not initialize!" << std::endl;
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		success = false;
	}
	//draw.Draw(image, 1);
	//draw.Draw(image, 2);

	return true;

	
}




void Scene3::OnDestroy() {

	delete image, playerimage;

}

void Scene3::Update(const float time) {
	
	player->Update(time);

	
	
	
}


void Scene3::Render() {
	Vec3 pos = player->GetPos();
	Vec3 screenPos = projection * pos;
	SDL_Rect dstrect;
	

	dstrect.x = static_cast<int>(screenPos.x);
	dstrect.y = static_cast<int>(screenPos.y);
	

	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));

	//SDL_BlitSurface(jetimage, nullptr, screenSurface, &dstrect);
	draw.Draw(image, 1,screenSurface);
	draw.Draw(image, 2, screenSurface);

	SDL_BlitSurface(playerimage, nullptr, screenSurface, &dstrect);//&dstrect
	//draw.Draw2(image, screenSurface);
	//SDL_BlitSurface(baseLayer, NULL, screenSurface, NULL);
	
	SDL_UpdateWindowSurface(window);
	SDL_Delay(1);
}

	

//Map movement using SDI key event
void Scene3::HandleEvents(SDL_Event e) {

	player->HandleEvents(e);

}




