#ifndef Game_hpp
#define Game_hpp
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "gameObject.hpp"
#include "map.hpp"


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
    int vRes = 640;
    bool running; //Se il gioco sta girando o no.
    SDL_Window *window; //Finestra del gioco
    const int startX = 4;
    const int startY = 3;
    const int endX = 19;
    const int endY = 3;
    AStarSearch<MapSearchNode> astarsearch;
};

#endif /* Game_hpp */
