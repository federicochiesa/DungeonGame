//
//  map.cpp
//  Game
//
//  Created by Federico Chiesa on 24/04/2018.
//  Copyright © 2018 Federico Chiesa. All rights reserved.
//

#include "map.hpp"
#include "textureManager.hpp"

map::map()
{
    terrain = textureManager::loadTexture("Game/assets/terrain.png");

    water.h = water.w = grass.h = grass.w = gravel.h = gravel.w = brick.h = brick.w = water.h = water.w = sand.h = sand.w = 16;
    water.x = 208;
    water.y = 192;
    grass.x = 64;
    grass.y = 80;
    gravel.x = 48;
    gravel.y = 16;
    brick.x = 112;
    brick.y = 0;
    sand.x = 32;
    sand.y = 16;
    dst.w = dst.h = 32;
    dst.x = dst.y = 0;
}

void map::drawMap()
{
    int type = 0;
    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col<25; col++)
        {
            type = lvlMap[row][col];
            
            dst.x = col * 32;
            dst.y = row * 32;
            
            switch (type)
            {
                case 1:
                    textureManager::Draw(terrain, grass, dst);
                    break;
                case 2:
                    textureManager::Draw(terrain, gravel, dst);
                    break;
                case 3:
                    textureManager::Draw(terrain, sand, dst);
                    break;
                case 4:
                    textureManager::Draw(terrain, water, dst);
                    break;
                case 9:
                     textureManager::Draw(terrain, brick, dst);
                    break;
            }
        }
    }
}

int map::getMap( int x, int y )
{
    if( x < 0 || x >= mapWidth || y < 0 || y >= mapHeight) return 9;    
    return lvlMap[x][y];
}
