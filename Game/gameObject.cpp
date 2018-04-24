//
//  gameObject.cpp
//  Game
//
//  Created by Federico Chiesa on 24/04/2018.
//  Copyright © 2018 Federico Chiesa. All rights reserved.
//

#include "gameObject.hpp"
#include "textureManager.hpp"
gameObject::gameObject(const char* texturesheet, int x, int y)
{
    objectTexture = textureManager::loadTexture(texturesheet);
    
    xpos = x;
    ypos = y;
}

void gameObject::update()
{
    
    xpos++;
    ypos++;
    srcRect.h = 16;
    srcRect.w = 16;
    srcRect.x = 160;
    srcRect.y = 240;
    
    dstRect.x = xpos;
    dstRect.y = ypos;
    dstRect.h = 64;
    dstRect.w = 64;
}

void gameObject::render()
{
    SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &dstRect);
}

