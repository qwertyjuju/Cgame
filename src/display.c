#include "display.h"

int initDisplay(char *title, int screenwidth, int screenheight){
    ENGINE->display= malloc(sizeof(Display));
    ENGINE->display->window=NULL;
    ENGINE->display->screenSurface=NULL;
    ENGINE->display->blitList.next=NULL;
    ENGINE->display->window= SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenwidth, screenheight, SDL_WINDOW_SHOWN);
    if(ENGINE->display->window==NULL){
        SDL_Log("SDL window note created, SDL error: %s", SDL_GetError());
        return -1;
    }
    else{
        ENGINE->display->screenSurface= SDL_GetWindowSurface(ENGINE->display->window);
        ENGINE->display->backgroundColor=SDL_MapRGB(ENGINE->display->screenSurface->format, 0x00, 0x00, 0x00);
    }
    return 0;
}




int addBlitobject(BlitObject *blitobject){
    BlitListNode *node=malloc(sizeof(BlitListNode));
    node->blitobject=blitobject;
    node->next=ENGINE->display->blitList.next;
    ENGINE->display->blitList.next= node;
    return 0;
}



int clearBlitList(){
    
}

int renderDisplay(){
    BlitListNode *node= ENGINE->display->blitList.next;
    while(node!=NULL){
        if (SDL_BlitSurface(node->blitobject->surface,NULL,ENGINE->display->screenSurface,node->blitobject->pos)!=0){
            return -1;
        }
        else{
            node = node->next;
        }
    }
    return 0;
}

int updateDisplay(){
    SDL_FillRect(ENGINE->display->screenSurface,NULL, ENGINE->display->backgroundColor);
    renderDisplay();
    SDL_UpdateWindowSurface(ENGINE->display->window);
    return 0;
}

void freeBlitObject(BlitObject *blitobject){
    free(blitobject->pos);
    SDL_FreeSurface(blitobject->surface);
}

void freeBlitList(BlitList blitlist){
    BlitListNode *node = blitlist.next;
    BlitListNode *temp =NULL;
    while(node!=NULL){
        temp=node;
        node=node->next;
        freeBlitObject(temp->blitobject);
        free(temp);
    }
}

void freeDisplay(Display *display){
    SDL_FreeSurface(display->screenSurface);
    SDL_DestroyWindow(display->window);
    freeBlitList(display->blitList);
    free(display);
}

void quitDisplay(){
    freeDisplay(ENGINE->display);
}