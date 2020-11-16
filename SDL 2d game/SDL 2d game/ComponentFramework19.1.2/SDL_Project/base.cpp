#include "base.h"

bool base::collisionbase(SDL_Rect * rec1, SDL_Rect * rec2)
{

		if (rec1->y >= rec2->y + rec2->h)
			return 0;
		if (rec1->x >= rec2->x + rec2->w)
			return 0;
		if (rec1->y >= rec2->h + rec2->y)
			return 0;
		if (rec1->x >= rec2->w + rec2->x)
			return 0;
		return 1;
	}



//#include <iostream>
//#include <string>
//#include <SDL.h>
//#include <SDL_image.h>
//
////Screen dimension constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 640;
////The window we'll be rendering to
//SDL_Window* window = NULL;
////The surface contained by the window
//SDL_Surface* screenSurface = NULL;
////Holds built base layer of tilemap.
//SDL_Surface* baseLayer = NULL;
////Map Data array
//char mapLayerOne[20][20] = {
//{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4    },
//{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4    },
//{4,4,4,6,6,6,6,6,6,4,4,4,4,4,4,4,4,4,4,4    },
//{4,4,4,6,8,8,6,6,6,6,6,6,6,4,4,4,4,4,4,4    },
//{4,4,4,6,8,8,6,6,6,6,6,6,6,4,4,4,4,4,4,4    },
//{4,4,4,6,6,8,6,6,6,6,6,6,6,4,4,4,4,4,4,4    },
//{4,4,4,6,6,8,8,8,8,6,6,6,6,6,4,4,4,4,4,4    },
//{4,4,4,6,6,6,6,6,8,6,6,6,6,6,6,4,4,4,4,4    },
//{4,4,4,6,6,14,6,6,8,8,6,6,6,6,6,4,4,4,4,4   },
//{4,4,4,6,14,16,14,6,6,8,6,6,6,6,6,4,4,4,4,4 },
//{4,4,4,14,16,16,16,12,8,8,8,8,6,6,6,4,4,4,4,4   },
//{4,4,4,6,16,16,16,6,6,6,6,8,8,8,6,4,4,4,4,4 },
//{4,4,4,6,6,16,6,6,6,6,6,6,6,8,6,4,4,4,4,4   },
//{4,4,13,6,6,6,6,6,6,6,6,6,6,8,6,4,4,4,4,4   },
//{4,4,4,14,14,14,14,14,14,14,14,14,14,14,14,15,4,4,4,4   },
//{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4    },
//{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4    },
//{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4    },
//{4,4,4,4,4,4,4,4,4,4,4,4,6,6,6,6,4,4,4,4    },
//{4,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,4,4,4,4    }
//};
//char mapLayerTwo[20][20] = {
//{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//{ 0,0,1,2,2,2,2,2,3,0,0,0,0,0,0,0,0,0,0,0 },
//{ 0,0,5,0,0,0,0,0,0,2,2,2,2,3,0,0,0,0,0,0 },
//{ 0,0,5,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0 },
//{ 0,0,5,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0 },
//{ 0,0,5,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0 },
//{ 0,0,5,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0 },
//{ 0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0 },
//{ 0,0,5,0,0,10,0,0,0,0,0,0,0,0,0,7,0,0,0,0 },
//{ 0,0,5,0,11,18,9,0,0,0,0,0,0,0,0,7,0,0,0,0 },
//{ 0,0,5,7,19,0,12,12,0,0,0,0,0,0,0,7,0,0,0,0 },
//{ 0,0,5,0,3,0,1,0,0,0,0,0,0,0,0,7,0,0,0,0 },
//{ 0,0,5,0,0,2,0,0,0,0,0,0,0,0,0,7,0,0,0,0 },
//{ 0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0 },
//{ 0,0,17,9,10,10,10,10,10,10,10,10,10,12,10,11,0,0,0,0 },
//{ 0,0,0,17,18,18,18,18,18,18,18,18,18,12,18,19,0,0,0,0 },
//{ 0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0 },
//{ 0,0,0,0,0,0,0,0,0,0,0,1,2,12,2,3,0,0,0,0 },
//{ 0,0,0,0,0,0,0,0,0,0,0,5,0,8,0,0,3,0,0,0 },
//{ 0,0,0,0,0,0,0,0,0,0,1,0,0,8,0,0,7,0,0,0 }
//};
//bool init();
//void DrawTiles(SDL_Surface* image, char mapLayer);
//
//int main(int argc, char* args[])
//{
//    //Main loop flag
//    bool quit = false;
//    //Event handler
//    SDL_Event e;
//
//    if (init())
//    {
//        //Load images
//        SDL_Surface* image = IMG_Load("Images/TileSheet_01.png");
//        if (!image)
//            std::cout << "Failed to load TileSheet_01.png!" << std::endl;
//        //Create BaseLayers of map
//        DrawTiles(image, 1);
//        DrawTiles(image, 2);
//
//        //While application is running
//        while (!quit)
//        {
//            //Handle events on queue
//            while (SDL_PollEvent(&e) != 0)
//            {
//                //User requests quit
//                if (e.type == SDL_QUIT)
//                    quit = true;
//            }
//            //Get window surface
//            screenSurface = SDL_GetWindowSurface(window);
//
//            //Blit base layer of map to screenSurface
//            SDL_BlitSurface(baseLayer, NULL, screenSurface, NULL);
//            //Update the surface
//            SDL_UpdateWindowSurface(window);
//            //Delay in milliseconds to improve performance
//            SDL_Delay(1);
//        }
//    }
//    //Destroy window
//    SDL_DestroyWindow(window);
//    //Quit SDL subsystems
//    SDL_Quit();
//    return 0;
//}
//
//void DrawTiles(SDL_Surface* image, char mapLayer)
//{
//    SDL_Rect baseTile[20];
//    int tileX = 0;
//    int tileY = 0;
//    for (int i = 1; i < 20; i++)
//    {
//        baseTile[i].h = 32;
//        baseTile[i].w = 32;
//        baseTile[i].x = tileX;
//        baseTile[i].y = tileY;
//        tileX += 32;
//        if (tileX == 128) { tileY += 32; tileX = 0; }
//    }
//    //Fill the surface
//    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 150, 50, 50));
//    SDL_Rect tileLoc;
//    tileLoc.x = 0;
//    tileLoc.y = 0;
//    // Draw tiles
//    for (int i = 0; i < 20; i++)
//    {
//        for (int j = 0; j < 20; j++)
//        {
//            if (mapLayer == 1 && mapLayerOne[i][j] != 0)
//                SDL_BlitSurface(image, &baseTile[mapLayerOne[i][j]], baseLayer, &tileLoc);
//            else if (mapLayer == 2 && mapLayerTwo[i][j] != 0)
//                SDL_BlitSurface(image, &baseTile[mapLayerTwo[i][j]], baseLayer, &tileLoc);
//            tileLoc.x += 32;
//            if (tileLoc.x == 640)
//            {
//                tileLoc.x = 0;
//                tileLoc.y += 32;
//            }
//        }
//    }
//}
//
//bool init()
//{
//    //Initialization flag
//    bool success = true;
//
//    //Initialize SDL
//    if (SDL_Init(SDL_INIT_VIDEO) < 0)
//    {
//        std::cout << "SDL could not initialize!" << std::endl;
//        success = false;
//    }
//    else
//    {
//        //Create window
//        window = SDL_CreateWindow("My SDL TileMap", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//        if (window == NULL)
//        {
//            std::cout << "Window could not be created!" << std::endl;
//            success = false;
//        }
//        else
//        {
//            //Initialize PNG loading
//            int imgFlags = IMG_INIT_PNG;
//            if (!(IMG_Init(imgFlags) & imgFlags))
//            {
//                //std::cout << "SDL_image could not initialize!" << std::endl;
//                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
//                success = false;
//            }
//            else
//            {
//                //Get window surface
//                screenSurface = SDL_GetWindowSurface(window);
//                //Surface to hold baselayer of map.
//                baseLayer = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 16, 0, 0, 0, 0);
//            }
//        }
//    }
//    SDL_Delay(300);
//    return success;
//}