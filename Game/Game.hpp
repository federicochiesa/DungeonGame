#ifndef Game_hpp
#define Game_hpp
#include "SDL2/SDL.h"
#include <iostream>
#include "SDL2_image/SDL_image.h"

class Game{
public:
    Game();
    ~Game();
    
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();
    int gethRes(){return hRes;};
    int getvRes(){return vRes;};
    bool isRunning(){return running;};
    static SDL_Renderer* renderer;
    
private:
    int hRes = 640;
    int vRes = 480;
    bool running; //Se il gioco sta girando o no.
    SDL_Window *window; //Finestra del gioco
};

#endif /* Game_hpp */
