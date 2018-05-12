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
    wall = textureManager::loadTexture("Game/assets/brick.png");
    grass = textureManager::loadTexture("Game/assets/grass.png");
    water = textureManager::loadTexture("Game/assets/water.png");
    
    loadMap(lvlMap);
    
    src.x = src.y = 0;
    src.w = src.h = 16;
    dst.w = dst.h = 32;
    
    dst.x = dst.y = 0;
}

void map::loadMap(int arr[mapHeight][mapWidth])
{
    for (int row = 0; row < mapWidth; row++) {
        for (int col = 0; col < mapHeight; col++) {
            lvlMap[row][col] = arr[row][col];
        }
    }
}

void map::drawMap()
{
    int type = 0;
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col<25; col++) {
            type = lvlMap[row][col];
            
            dst.x = col * 32;
            dst.y = row * 32;
            
            switch (type) {
                case 0:
                    textureManager::Draw(water, src, dst);
                    break;
                case 1:
                    textureManager::Draw(grass, src, dst);
                    break;
                case 9:
                     textureManager::Draw(wall, src, dst);
                    break;
                    
            }
        }
    }
}

int* map::getMap()
{
    return *lvlMap;
}
