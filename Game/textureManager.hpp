//
//  textureManager.hpp
//  Game
//
//  Created by Federico Chiesa on 20/04/2018.
//  Copyright © 2018 Federico Chiesa. All rights reserved.
//

#ifndef textureManager_hpp
#define textureManager_hpp
#include "Game.hpp"

class textureManager
{
public:
    static SDL_Texture* loadTexture(const char* fileName, SDL_Renderer* ren);
};

#endif /* textureManager_hpp */
