    #include <iostream>
    #include <vector>
    #include <math.h>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>
    #include "scenes.h"

	int main() {
		bool running = true;
		int frametime;
		SDL_Event event;
		scenes _scenes;
		std::string scene = "main";
		
		_scenes.createWindow();
		_scenes.loadScene(scene);
		
		TTF_Init();
		TTF_Font* Sans = NULL;
		if(!Sans)
			Sans = TTF_OpenFont("example.ttf", 24);
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Color White = {255, 255, 255};
		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White);
		SDL_Texture* Message = SDL_CreateTextureFromSurface(_scenes.ren, surfaceMessage);
		
		SDL_Rect Message_rect;
		Message_rect.x = 100;
		Message_rect.y = 100;
		Message_rect.w = 100;
		Message_rect.h = 100;

		while(running) {
			frametime = SDL_GetTicks();
			while(SDL_PollEvent(&event)) {
				if(event.type == SDL_QUIT) running  = false;
			}
			
			SDL_RenderClear(_scenes.ren);
			_scenes.renderScene(_scenes, scene);
			SDL_RenderCopy(_scenes.ren, Message, NULL, &Message_rect);
			SDL_RenderPresent(_scenes.ren);
			
			
			frametime = SDL_GetTicks() - frametime;
            if(frametime < 10)SDL_Delay(Uint32(10-frametime));
		}
		
		return 0;
	}
