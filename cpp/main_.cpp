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
		
		TTF_Init();
		_scenes.createWindow();
		_scenes.loadScene(scene);

		while(running) {
			frametime = SDL_GetTicks();
			while(SDL_PollEvent(&event)) {
				if(event.type == SDL_QUIT) running  = false;
			}
			
			SDL_RenderClear(_scenes.ren);
			_scenes.renderScene(_scenes, scene);
			SDL_RenderPresent(_scenes.ren);
			
			
			frametime = SDL_GetTicks() - frametime;
            if(frametime < 10)SDL_Delay(Uint32(10-frametime));
		}
		
		return 0;
	}
