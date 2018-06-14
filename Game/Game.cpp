#include "Game.hpp"

gameObject* player = nullptr;
gameObject* enemy = nullptr;
map* Map = nullptr;
SDL_Renderer* Game::renderer = nullptr;

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
    
    if(!SDL_Init(SDL_INIT_EVERYTHING))//Se l'inizializzazione ha successo...0
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
    
    player = new gameObject("Game/assets/Tileset.png", startX*32-32, startY*32-32);
    Map = new map();
    //Start A* block

    unsigned int SearchCount = 0;
    const unsigned int NumSearches = 1;
    while(SearchCount < NumSearches)
    {
        MapSearchNode nodeStart;
        nodeStart.x = startX;
        nodeStart.y = startY;
        MapSearchNode nodeEnd;
        nodeEnd.x = endX;
        nodeEnd.y = endY;
        
        astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );
        unsigned int SearchState;
        unsigned int SearchSteps = 0;
        do
        {
            SearchState = astarsearch.SearchStep();
            SearchSteps++;
        }
        while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );
        if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED )
        {
            cout << "Traguardo Trovato! Visualizzo percorso...\n";
            MapSearchNode *node = astarsearch.GetSolutionStart();
            int steps = 0;
            player->directions.push_back(node);
            for( ;; )
            {
                node = astarsearch.GetSolutionNext();
                if( !node ) break;
                player->directions.push_back(node);
                steps ++;
            };
            cout << "Passi al traguardo: " << steps << endl;
            astarsearch.FreeSolutionNodes();
        }
        else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED )
        {
            cerr << "ERRORE: Traguardo non trovato! Termino programma...";
            SDL_Delay(1000);
            astarsearch.EnsureMemoryFreed();
            running = false;
        }
        cout << "Passi Ricerca : " << SearchSteps << "\n";
        SearchCount ++;
        astarsearch.EnsureMemoryFreed();
    }
    player->hasReceivedDirections = true;
    //End A* block
}

void Game::handleEvents()
{
    SDL_Event event;
    
    SDL_PollEvent(&event);
    switch (event.type)
    {
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
}

void Game::render()
{
    SDL_RenderClear(renderer);
    Map->drawMap();
    player->render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Gioco chiuso" << std::endl;
}
