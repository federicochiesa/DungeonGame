//
//  gameObject.hpp
//  Game
//
//  Created by Federico Chiesa on 24/04/2018.
//  Copyright © 2018 Federico Chiesa. All rights reserved.
//

#ifndef gameObject_hpp
#define gameObject_hpp

#include "Game.hpp"

class gameObject
{
public:
    gameObject(const char* texturesheet, int x, int y);
    ~gameObject();
    void update();
    void render();
    
private:
    int xpos;
    int ypos;
    SDL_Texture* objectTexture;
    SDL_Rect srcRect, dstRect;
    SDL_Renderer* renderer;
};

#endif /* gameObject_hpp */
