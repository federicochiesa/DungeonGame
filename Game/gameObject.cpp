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
    bool hasReceivedDirections = false;
}

void gameObject::update()
{
    srcRect.h = 16;
    srcRect.w = 16;
    srcRect.x = 160;
    srcRect.y = 240;
    
    dstRect.h = 32;
    dstRect.w = 32;
    if(hasReceivedDirections){
        it = directions.begin();
        playerMoves = true;
        hasReceivedDirections = false;
        for (MapSearchNode* point : directions) {
            point -> PrintNodeInfo();
        }
    }

    if (it==directions.end())
    {
        dstRect.x = (*directions.end())->x;
        dstRect.y = (*directions.end())->y;
    }
    else if (playerMoves)
    {
        dstRect.y = ((*it) -> x)*32;
        dstRect.x = ((*it) -> y)*32;
        it++;
        SDL_Delay(500);
    }
    else
    {
        dstRect.x = xpos*32;
        dstRect.y = ypos*32;
        SDL_Delay(2000);
    }
}

void gameObject::render()
{
    SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &dstRect);
}

