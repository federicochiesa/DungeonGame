//
//  text.cpp
//  Game
//
//  Created by Federico Chiesa on 16/05/2018.
//  Copyright © 2018 Federico Chiesa. All rights reserved.
//

#include "textOverlay.hpp"

static int messagesDisplayed;

text::text(int xpos, int ypos, char* text) : xpos(xpos), ypos(ypos), textToDisplay(text)
{
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, textToDisplay, color); //Creiamo una surface con il messaggio da scrivere.
    
    SDL_Texture* Message = SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage); //Creiamo una texture renderizzabile dalla surface creata.
    
    messagesDisplayed++;
    
    timeCreated = time(NULL);
}

void text::update()
{
    Message_rect.x = xpos;
    Message_rect.y = ypos+(messagesDisplayed*height); // Facciamo in modo che i messaggi non si sovrappongano
    Message_rect.w = width;
    Message_rect.h = height;
    if (timeCreated>=(timeCreated+timeToBeDisplayed)) {
        delete this;
    }
}

void text::render()
{
    SDL_RenderCopy(Game::renderer, Message, NULL, &Message_rect);
}

text::~text()
{
    messagesDisplayed--;
}
