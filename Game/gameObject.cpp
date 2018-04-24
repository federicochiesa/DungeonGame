//
//  gameObject.cpp
//  Game
//
//  Created by Federico Chiesa on 24/04/2018.
//  Copyright © 2018 Federico Chiesa. All rights reserved.
//

#include "gameObject.hpp"
#include "textureManager.hpp"
gameObject::gameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
    renderer = ren;
    objectTexture = textureManager::loadTexture(texturesheet, ren);
    
    xpos = x;
    ypos = y;
}

void gameObject::update()
{
    
    xpos++;
    ypos++;
    srcRect.h = 300;
    srcRect.w = 186;
    srcRect.x = 0;
    srcRect.y = 0;
    
    dstRect.x = xpos;
    dstRect.y = ypos;
    dstRect.h = 75;
    dstRect.w = 46.5;
}

void gameObject::render()
{
    SDL_RenderCopy(renderer, objectTexture, &srcRect, &dstRect);
}

