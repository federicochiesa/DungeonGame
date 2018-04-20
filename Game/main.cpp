#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char *args[])
{
    const int fps = 60;
    const int frameDelay = 1000/fps; //Tempo per renderizzare un frame
    
    Uint32 frameStart;
    int frameTime;
    
    game= new Game();
    
    game->init("Titolo Finestra", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, game->gethRes(), game->getvRes(), false);
    
    while (game->isRunning()) //Game loop
    {
        
        frameStart = SDL_GetTicks(); //Tempo in ms dall'esecuzione del programma in cui il frame inizia a essere renderizzato
        
        game->handleEvents();
        game->update();
        game->render();
    
        frameTime = SDL_GetTicks() - frameStart; //Calcolo quanti millisecondi impiego a renderizzare un frame
        
        if(frameDelay>frameTime) //Se ci metto meno del tempo prestabilito a renderizzare un frame...
        {
            SDL_Delay(frameDelay-frameTime); //... aggiungo un ritardo in modo che combaci con frameDelay.
        }
    }
    
    game->clean();
    return 0;
}
