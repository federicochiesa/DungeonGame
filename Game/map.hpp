//
//  map.hpp
//  Game
//
//  Created by Federico Chiesa on 24/04/2018.
//  Copyright © 2018 Federico Chiesa. All rights reserved.
//

#ifndef map_hpp
#define map_hpp

#include "Game.hpp"

class map
{
public:
    map();
    ~map();
    
    void loadMap(int arr[20][25]);
    void drawMap();
private:
    SDL_Rect src, dst;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;
    
    int Map[20][25];
};

#endif /* map_hpp */
