#include "Game.hpp"
#include "textureManager.hpp"
#include "gameObject.hpp"
#include "map.hpp"
#include "textOverlay.hpp"
#include "MapSearchNode.hpp"

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
    
    player = new gameObject("Game/assets/Tileset.png", hRes/2-32, vRes/2-16);
    Map = new map();
    //Start A* block
    AStarSearch<MapSearchNode> astarsearch;
    unsigned int SearchCount = 0;
    const unsigned int NumSearches = 1;
    while(SearchCount < NumSearches)
    {
        MapSearchNode nodeStart;
        nodeStart.x = 7;
        nodeStart.y = 9;
        MapSearchNode nodeEnd;
        nodeEnd.x = 13;
        nodeEnd.y = 18;
        
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
            cout << "Search found goal state\n";
            MapSearchNode *node = astarsearch.GetSolutionStart();
            int steps = 0;
            node->PrintNodeInfo();
            for( ;; )
            {
                node = astarsearch.GetSolutionNext();
                if( !node ) break;
                node->PrintNodeInfo();
                steps ++;
            };
            cout << "Solution steps: " << steps << endl;
            astarsearch.FreeSolutionNodes();
        }
        else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED ) cerr << "Search terminated. Did not find goal state\n";
        cout << "SearchSteps : " << SearchSteps << "\n";
        SearchCount ++;
        astarsearch.EnsureMemoryFreed();
    }
    //End A* block
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
