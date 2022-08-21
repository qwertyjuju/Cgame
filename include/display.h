#ifndef DISPLAY_H
#define DISPLAY_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <errno.h>

typedef struct BlitObject{
    SDL_Surface *surface;
    SDL_Rect *pos;
}BlitObject;

typedef struct BlitListNode BlitListNode;

struct BlitListNode{
    BlitObject *blitobject;
    BlitListNode *next;
};

// blitlist 
typedef struct{
    BlitListNode *next;
}BlitList;

// main display with sdl window
typedef struct{
    SDL_Window *window;
    SDL_Surface *screenSurface;
    BlitList blitList;
    Uint32 backgroundColor;
}Display;

// inits a display
int initDisplay(char *title, int screenwidth, int screenheight);

// update full display
int updateDisplay();
int renderDisplay();

// 
int addBlitobject(BlitObject *BlitObject);

void quitDisplay();
#include "engine.h"


#endif