//
//  text.hpp
//  Game
//
//  Created by Federico Chiesa on 16/05/2018.
//  Copyright © 2018 Federico Chiesa. All rights reserved.
//

#ifndef text_hpp
#define text_hpp

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "Game.hpp"
#include <ctime>

class text
{
public:
    text(int xpos, int ypos, char* text);
    ~text();
    void update();
    void render();
    void deleteText();
private:
    int xpos;
    int ypos;
    int width = 640; //!how to make it have game's hres?
    int height= 100;
    TTF_Font* Sans = TTF_OpenFont("Game/assets/minecraftia.ttf", 24);
    SDL_Color color = {255,255,255};
    char* textToDisplay;
    SDL_Texture* Message;
    SDL_Rect Message_rect;
    int timeToBeDisplayed = 5;
    long int timeCreated;
};

#endif /* text_hpp */
