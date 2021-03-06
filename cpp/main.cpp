    #include <iostream>
    #include <vector>
    #include <math.h>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include "render.h"

	int main() {
		bool running = true;
		int frametime;
		SDL_Event event;
		render _render;
		int level = 0;
		
		_render.createWindow();

		while(running) {
			frametime = SDL_GetTicks();
			while(SDL_PollEvent(&event)) {
				if(event.type == SDL_QUIT) running  = false;
			}
			
			SDL_RenderClear(_render.ren);
			_render.renderLevel(_render, level);
			SDL_RenderPresent(_render.ren);
			
			
			frametime = SDL_GetTicks() - frametime;
            if(frametime < 10)SDL_Delay(Uint32(10-frametime));
		}
		
		return 0;
	}
