//
//  textureManager.cpp
//  Game
//
//  Created by Federico Chiesa on 20/04/2018.
//  Copyright © 2018 Federico Chiesa. All rights reserved.
//

#include "textureManager.hpp"

SDL_Texture* textureManager::loadTexture(const char* texture)
{
    SDL_Surface* tmpSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;
}

void textureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst)
{
    SDL_RenderCopy(Game::renderer, tex, &src, &dst);
}
