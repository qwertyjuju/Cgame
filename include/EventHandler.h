#ifndef LISTENER_H
#define LISTENER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct{
    void (*func)();   
    void **params;
}EventListener;

/* Event listeners Nodes */

/* Node for click event listeners */
typedef struct ClickEventNode ClickEventNode;

struct ClickEventNode{
    ClickEventNode *nextClickListener;
    SDL_Rect *rect;
    EventListener *eventlistener;
};

typedef struct TextInputEventListener{
    EventListener *eventlistener;
    int active;
}TextInputEventListener;

/* Main event handler struct */
typedef struct EventHandler{
    ClickEventNode *nextClickListener;
    TextInputEventListener *textInputListener;
}EventHandler;

int initEventHandler();
int addClickListener(void *func, void **params, SDL_Rect *rect);
void runEventHandler();
void startTextInputListener(void *func,  void **params);
void stopTextInputListener();
int quitEventHandler();

#include "engine.h"

#endif