#include "surfaces.h"

TTF_Font *FONT=NULL;

int setFont(char *fontpath, int fontsize){
    TTF_CloseFont(FONT);
    if (fontpath==NULL)
        fontpath = "../data/fonts/CloisterBlack.ttf";
    if (fontsize==0)
        fontsize=32;
    FONT = TTF_OpenFont(fontpath, fontsize);
    if (FONT==NULL){
        SDL_Log("font not openened: %s\n", TTF_GetError());
        return -1;
    }
    return 0;
}


TextSurface *createTextSurface(char *text, int posx, int posy){
    SDL_Color white={255,255,255};
    TextSurface *textSurface=malloc(sizeof(TextSurface));
    SDL_Rect *pos=malloc(sizeof(SDL_Rect));
    textSurface->blitObject=malloc(sizeof(BlitObject));
    textSurface->text=malloc((strlen(text)+1)*sizeof(char));
    pos->x=posx;
    pos->y=posy;
    strcpy(textSurface->text, text);
    textSurface->blitObject->surface=TTF_RenderText_Blended_Wrapped(FONT,textSurface->text, white, 1920);
    pos->w = textSurface->blitObject->surface->w;
    pos->h = textSurface->blitObject->surface->h;
    textSurface->blitObject->pos=pos;
    addBlitobject(textSurface->blitObject);
    if (textSurface==NULL){
        SDL_Log("error creating surface: %s\n", TTF_GetError());
    }
    return textSurface;
}

int updateTextSurface(TextSurface *textSurface, char*text){
    SDL_Color white={255,255,255};
    free(textSurface->text);
    textSurface->text=malloc((strlen(text)+1)*sizeof(char));
    strcpy(textSurface->text, text);
    SDL_FreeSurface(textSurface->blitObject->surface);
    textSurface->blitObject->surface = TTF_RenderText_Blended_Wrapped(FONT,textSurface->text, white, 1920);
    textSurface->blitObject->pos->w = textSurface->blitObject->surface->w;
    textSurface->blitObject->pos->h = textSurface->blitObject->surface->h;
    return 0;
}

int appendTextSurface(TextSurface *textSurface, char*text){
    SDL_Color white={255,255,255};
    int textsize = strlen(textSurface->text)+strlen(text)+1;
    textSurface->text = realloc(textSurface->text,textsize);
    strcat(textSurface->text, text);
    SDL_FreeSurface(textSurface->blitObject->surface);
    textSurface->blitObject->surface = TTF_RenderText_Blended_Wrapped(FONT,textSurface->text, white, 1920);
    textSurface->blitObject->pos->w = textSurface->blitObject->surface->w;
    textSurface->blitObject->pos->h = textSurface->blitObject->surface->h;
    return 0;
}

int initSurfaces(){
    TTF_Init();
    setFont(NULL,0);
    return 0;
}