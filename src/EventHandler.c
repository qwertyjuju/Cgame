#include "EventHandler.h"

int initTextInputListener(){
    ENGINE->eventHandler->textInputListener=malloc(sizeof(TextInputEventListener));
    ENGINE->eventHandler->textInputListener->eventlistener=calloc(1, sizeof(EventListener));
    ENGINE->eventHandler->textInputListener->active=0;
}

int initEventHandler(){
    ENGINE->eventHandler= malloc(sizeof(EventHandler));
    ENGINE->eventHandler->nextClickListener=NULL;
    initTextInputListener();
    return 0;
}



/* Add event listeners */

/* Add click event event listener. with ClickEventNode. if the rect parameter is not NULL,
The function will be called only if the mouse pointer is in the rect */
int addClickListener(void *func,  void **params, SDL_Rect *rect){
    ClickEventNode *nextClickListener = malloc(sizeof(ClickEventNode));
    nextClickListener->rect=rect;
    nextClickListener->eventlistener=malloc(sizeof(EventListener));
    nextClickListener->eventlistener->func=func;
    nextClickListener->eventlistener->params=params;
    nextClickListener->nextClickListener = ENGINE->eventHandler->nextClickListener;
    ENGINE->eventHandler->nextClickListener=nextClickListener;
    return 0;
}


void startTextInputListener(void *func,  void **params){
    if(func !=NULL){
        ENGINE->eventHandler->textInputListener->eventlistener->func=func;
        ENGINE->eventHandler->textInputListener->eventlistener->params=params;
    }
    ENGINE->eventHandler->textInputListener->active=1;
    SDL_StartTextInput();
}

void stopTextInputListener(){
    ENGINE->eventHandler->textInputListener->active=0;
    SDL_StopTextInput();
}

void runEventListener(SDL_Event event, EventListener *eventlistener){
    eventlistener->func(event, eventlistener->params);
}

/* Event listeners activation */

/**/
void activateClickEventListeners(SDL_Event event){
    ClickEventNode *nextClickListener=ENGINE->eventHandler->nextClickListener;
    for(nextClickListener; nextClickListener!=NULL; nextClickListener=nextClickListener->nextClickListener){
        if (nextClickListener->rect!=NULL){
            if (event.button.x>nextClickListener->rect->x && event.button.x<(nextClickListener->rect->x)+(nextClickListener->rect->w)){
                if (event.button.y>nextClickListener->rect->y && event.button.y<(nextClickListener->rect->y)+(nextClickListener->rect->h)){
                    runEventListener(event, nextClickListener->eventlistener);
                }
            }
        }
        else{
            runEventListener(event, nextClickListener->eventlistener);
        }
    }
}

void activateTextInputEventListeners(SDL_Event event){
    runEventListener(event,ENGINE->eventHandler->textInputListener->eventlistener);
}



void runEventHandler(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                ENGINE->run=SDL_FALSE;    
                break;
            case SDL_KEYUP:
                //if (e.keysym.sym==
                break;
            case SDL_MOUSEBUTTONDOWN:
                activateClickEventListeners(event);
                break;
            case SDL_TEXTINPUT:
                activateTextInputEventListeners(event);
        }
    }
}

/* free memory funcs */
void freeEventListener(EventListener *listener){
        free(listener->params);
        free(listener);
}

void freeInputTextListener(){
    freeEventListener(ENGINE->eventHandler->textInputListener->eventlistener);
    free(ENGINE->eventHandler->textInputListener);
}

void freeClickEventNode(ClickEventNode *clickEventNode){
    freeEventListener(clickEventNode->eventlistener);
    free(clickEventNode->rect);
}

void freeClickEventListeners(){
    ClickEventNode *nextClickListener=ENGINE->eventHandler->nextClickListener;
    ClickEventNode *temp=NULL;
    while(nextClickListener!=NULL){
        temp=nextClickListener;
        nextClickListener=nextClickListener->nextClickListener;
        freeEventListener(temp->eventlistener);
        //free(temp->rect);
        free(temp);
    }
}

int quitEventHandler(){
    freeInputTextListener();
    freeClickEventListeners();
}


/* 
case SDL_QUIT:
    quit=SDL_TRUE;
    break;
case SDL_KEYUP:
    //if (e.keysym.sym==
    break;
case SDL_MOUSEBUTTONDOWN:
    if(e.button.button==SDL_BUTTON_LEFT){
        if (e.button.x>0 && e.button.x<500){
            if (e.button.y>32 && e.button.y<64){
                SDL_StartTextInput();
                SDL_Log("start text input");
            }
        }
        else{
            SDL_StopTextInput();
            SDL_Log("stop text input. text: %s", test);
        }
    }
    break;
case SDL_TEXTINPUT:
    updateTextSurface(test,e.text.text);
    SDL_Log("%s", e.text.text);
    break;
*/

