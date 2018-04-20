
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
    
    
private:
    int hRes = 800;
    int vRes = 600;
    bool running; //Se il gioco sta girando o no.
    SDL_Window *window; //Finestra del gioco
    SDL_Renderer *renderer; //Renderer di default
};

#endif /* Game_hpp */
