#ifndef render_h
#define render_h

class render {
	private:
		int SCREEN_W = 900, SCREEN_H = 800;
	
		SDL_Window *screen;
		
		struct levels {
			SDL_Texture* img;
			SDL_Texture* map;
		} level;
	
	public:
		SDL_Renderer *ren;
	
		void createWindow() {
			screen = SDL_CreateWindow("Commandos", 200, 200, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
            ren = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            
            loadLevel();
		}
		
		void loadLevel() {
			int w,h;
			std::string _img = "../img/level1.jpg";
			SDL_Surface *img = IMG_Load(_img.c_str());
			SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, img);
			
			SDL_Texture *map = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_W, SCREEN_H);
			void * pixels;
			int pitch;
			SDL_LockTexture(texture, NULL, &pixels, &pitch);
			
            SDL_QueryTexture(texture, NULL, NULL, &w, &h);
            SDL_FreeSurface(img);
            level.img = texture;
		}
		
		void renderLevel(render _render, int i) {
			SDL_Rect spr = {0,0,_render.SCREEN_W,_render.SCREEN_H};
			SDL_Rect dst = {0,0,_render.SCREEN_W,_render.SCREEN_H};
			SDL_RenderCopy(_render.ren, _render.level.img, &spr, &dst);
		}
		
		void destroyRender(render _render) {
            SDL_DestroyRenderer(_render.ren);
            SDL_DestroyWindow(_render.screen);

            IMG_Quit();
            SDL_Quit();
        }
       
};

#endif
