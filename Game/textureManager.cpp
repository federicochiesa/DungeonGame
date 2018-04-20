//
//  textureManager.cpp
//  Game
//
//  Created by Federico Chiesa on 20/04/2018.
//  Copyright © 2018 Federico Chiesa. All rights reserved.
//

#include "textureManager.hpp"

SDL_Texture* textureManager::loadTexture(const char* texture, SDL_Renderer* ren)
{
    SDL_Surface* tmpSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;
}
