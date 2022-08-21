#include "engine.h"

Engine *ENGINE=NULL;
int initEngine(char *gametitile, int swidth, int sheight){
    ENGINE=malloc(sizeof(Engine));
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        SDL_Log("SDL not initialised! SDL error: %s\n", SDL_GetError());
        return -1;
    }
    else{
        ENGINE->run=0;
        initDisplay(gametitile, swidth, sheight);
        initEventHandler();
        initSurfaces();
    }

}

void runEngine(){
    ENGINE->run=SDL_TRUE;
    while(ENGINE->run){
        runEventHandler();
        updateDisplay();
    }
    quitEngine();
}

int quitEngine(){
    quitEventHandler();
    quitDisplay();
    SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
    SDL_Quit();
}