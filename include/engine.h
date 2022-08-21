#ifndef ENGINE_H
#define ENGINE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "EventHandler.h"
#include "display.h"
#include "surfaces.h"

typedef struct{
    Display *display;
    EventHandler *eventHandler;
    SDL_bool run;
}Engine;

extern Engine *ENGINE;

int initEngine(char *gametitile, int swidth, int sheight);
void runEngine();
int quitEngine();
#endif