#include "Game.hpp"
#include "textureManager.hpp"
#include "gameObject.hpp"

gameObject* player;
gameObject* enemy;

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
    player = new gameObject("Game/assets/Person.png", renderer, 0, 0);
    enemy = new gameObject("Game/assets/Person2.png", renderer, 20, 50);
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
    player->update();
    enemy->update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    player->render();
    enemy->render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Gioco chiuso" << std::endl;
}
