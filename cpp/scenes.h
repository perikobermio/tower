#ifndef scenes_h
#define scenes_h

class scenes {
	private:
		int SCREEN_W = 1500, SCREEN_H = 800;
	
		SDL_Window *screen;
		
		struct sScenes {
			SDL_Texture* img;
			
		} currentScene;
	
	public:
		SDL_Renderer *ren;
		
		void loadScene(std::string scene) {
			std::string _img = "../img/main.jpg";
			SDL_Surface *img = IMG_Load(_img.c_str());
            SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, img);
            SDL_FreeSurface(img);
            
            currentScene.img = texture;
		}
	
		void createWindow() {
			screen = SDL_CreateWindow("TD", 200, 200, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
            ren = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		}
		
		void renderScene(scenes _scenes, std::string scene) {
			if(scene == "main") _scenes.renderMain(_scenes);	
		}
		
		void destroyRender(scenes _scenes) {
            SDL_DestroyRenderer(_scenes.ren);
            SDL_DestroyWindow(_scenes.screen);

            IMG_Quit();
            SDL_Quit();
        }
		
	private:
		void renderMain(scenes _scenes) {
			TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 48);
			SDL_Color White = {255, 255, 255};
			SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White);
			SDL_Texture* Message = SDL_CreateTextureFromSurface(_scenes.ren, surfaceMessage);
			
			SDL_Rect Message_rect;
			Message_rect.x = 100;
			Message_rect.y = 100;
			Message_rect.w = 100;
			Message_rect.h = 100;
			
			
			
			SDL_Rect spr = {0,0,7251,4018};
			SDL_Rect dst = {0,0,_scenes.SCREEN_W,_scenes.SCREEN_H};
			SDL_RenderCopy(_scenes.ren, _scenes.currentScene.img, &spr, &dst);
			
			SDL_RenderCopy(_scenes.ren, Message, NULL, &Message_rect);
		}
	
};

#endif
