#include "Scene0.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Collision.h"
Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;
}

Scene0::~Scene0(){
}
SDL_Rect base::coord;


bool Scene0::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0, 10.0, 0.0, 5.0, 0.0, 1.0);//30 20
	projection = ndc * ortho;
	n = 10;
	m = 20;
	

	player1 = new player(IMG_Load("player.bmp"));
	//
	base::coord.x = camera.x = 0;
	base::coord.y = camera.y = 0;
	base::coord.w = camera.w = 640;
	base::coord.h = camera.h = 480;
	//1914 is the length of the picture (background) 
	//it would be great if you change the background to 2000x50 so it can fill the white gap
	//then change 1914 to 2000
	imgLoc = { 1914, 0, 50, 100 };//1914.0.50.100//2000.0.50.100


	//LOAD THE IMAGES
	backgroundImage = IMG_Load("land3.png");//land3 png//endless.bmp
	block = IMG_Load("blocks.bmp");
	image = IMG_Load("jetSki.png");
	land = IMG_Load("land5.png");
	


//	player1->move(test);

	return true;
	
	
}
//LOAD THE MAP
//THIS YOU DONT NEED TO WORRY CUZ IM DUMB I cannot explain
//heyhey dont laugh just focus on collision ^.^
void Scene0::loadmap(const char * filename)
{

	std::ifstream in(filename);
	if (!in.is_open())
	{
		std::cout << "problems with loading the file" << std::endl;
		return;
	}
	int width, height; //of the map
	in >> width;
	in >> height;
	int current;
	for (int i = 0; i < height; i++) {
		std::vector<int> vec;
		for (int j = 0; j < width; j++) {
			if (in.eof())
			{
				std::cout << "File end reached too soon" << std::endl;
				return;
			}
			in >> current;
			if (current >= 0 && current <= 1)
			{
				vec.push_back(current);
			}
			else {
				vec.push_back(0);
			}
				
		}

			test.push_back(vec);
	//		player1->move(test);
	}
	in.close();
	//player1->move(test);
}


//WE MIGHT NEED THIS ********************
//COLLISION PART
//bool Scene0::collisionnew(SDL_Rect * rec1, SDL_Rect * rec2)
//{
//	if (rec1->y >= rec2->y + rec2->h)
//		return 0;
//		if (rec1->x >= rec2->x + rec2->w)
//			return 0;
//			if (rec1->y >= rec2->h + rec2->y)
//				return 0;
//				if (rec1->x >= rec2->w + rec2->x)
//					return 0;
//	return 1;
//}

//***************************************

void Scene0::OnDestroy() {
	//Free memory
	delete image, backgroundImage, land, block;

}

//Make the background move when button is pressed
void Scene0::Update(const float time) {
	//Update camera speed just like you update jetski velocity
	//the speed here is the velocity of scroll movements you can change it around
	//change the speed if you like it's in header file
	if (b[0]) {
		n += speed;
		camera.x +=speed;
		base::coord.x+=speed;
		//if it reach too far reset back to orginal pic(location) 
		if (camera.x >= 1914 - 640) {//1914-640 2000-640
			camera.x = 0;
		}
	}
	else if (b[1]) {
				n-= speed;
				camera.x -=speed;
				base::coord.x-=speed;
				//if it reach too far back reset back to orginal pic(location) 
				if (camera.x <= 0) {
					camera.x = 1914 - 640;
				}
	}
	//this is the size of window
	Loc = { n,m, 640, 480 };
	relcoord = { imgLoc.x-n,Loc.y - m };

	//player1->move(test); nah

	
}

//JUST RENDER the stuffs  nothing MUCH!!!!!!!!!!
void Scene0::Render() {
	loadmap("test.map");
	
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	
		//Show background
		SDL_BlitSurface(backgroundImage, &camera, screenSurface, NULL);
		//Show player TADA!!!!!!!!!
		player1->show(screenSurface);
		//Show amp blocks
		int start = (base::coord.x - (base::coord.x % base::TILE_SIZE)) / base::TILE_SIZE;
		int end = (base::coord.x + base::coord.w + (base::TILE_SIZE - (base::coord.x + base::coord.w) % base::TILE_SIZE)) / 50;
		if (start < 0)
			start = 0;
		if (end > test[0].size())
			end = test[0].size();
		for (int i = 0; i < test.size(); i++) {
			for (int j = 0; j < end; j++) {
				if (test[i][j] != 0)
				{
					SDL_Rect blockrect = { (test[i][j] - 1) * base::TILE_SIZE,0, base::TILE_SIZE,base::TILE_SIZE };
					SDL_Rect destrect = { j*(base::TILE_SIZE) - (base::coord.x),i * 50 };
					SDL_BlitSurface(block, &blockrect, screenSurface, &destrect);
				}

			}

		}
		
		//showmap();
		
		/*if (collisionnew(&Loc, &imgLoc)) {
			SDL_BlitSurface(image, NULL, screenSurface, &relcoord);
			
		}*/
		//player collision
		player1->move(test);
	SDL_UpdateWindowSurface(window);
	//player1->move(test);
}

//Map movement using SDI key event
void Scene0::HandleEvents(SDL_Event e) {

	//scroll map sdlevent
	//press keys to move the map
	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym) {
		case SDLK_s:
		
			b[0] = 1;
			break;
		case SDLK_d:
			b[1] = 1;
		}
	}

	if (e.type == SDL_KEYUP) {
		switch (e.key.keysym.sym) {
		case SDLK_s:
			b[0] = 0;
			break;
		case SDLK_d:
			b[1] = 0;
		}
	}
}

	
	

	


	
