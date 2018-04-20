#include "Game.hpp"

SDL_Texture* playerTexture;
SDL_Rect playerRect;


Game::Game()
{}
Game::~Game()
{}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags=0;
    if(fullscreen)
    {
        flags=SDL_WINDOW_FULLSCREEN;
    }
    
    if(!SDL_Init(SDL_INIT_EVERYTHING))//Se l'inizializzazione ha successo...
    {
        std::cout << "SDL Inizializzato" << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);//...creiamo la finestra di gioco...
        
        if(window)
        {
            std::cout << "Finestra creata" << std::endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0); //...e il renderer
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer Creato" << std::endl;
        }
        
        running = true;//Fatto ciò facciamo partire il game loop
    }
    else
    {
        running = false;//Se l'inizializzazione non ha successo non facciamo partire il game loop
    }
    
    SDL_Surface* tmpSurface = IMG_Load("Game/assets/Person.png");
    playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents()
{
    SDL_Event event;
    
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        default:
            break;
    }
    
}

void Game::update()
{
    
    playerRect.h = 75;
    playerRect.w = 46.5;
    playerRect.x = (hRes/2)-playerRect.w/2; //Personaggio al centro dello schermo.
    playerRect.y = (vRes/2)-playerRect.h/2;
    
    const Uint8* tastiera = SDL_GetKeyboardState(NULL);
    if(tastiera[SDL_SCANCODE_UP])
    {
        playerRect.y = playerRect.y - 1;
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Gioco chiuso" << std::endl;
}
