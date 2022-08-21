#include "ui.h"
#define USER_INPUT_MAX_LEN 255

void updateUserInput(SDL_Event event, void **params){
    SDL_Log("%s",event.text.text);
    appendTextSurface(((UserInputSurface*)*params)->surface, event.text.text);
}

void toggleUserInput(SDL_Event event, void **params){
    if (!((UserInputSurface*)*params)->active){
        ((UserInputSurface*)*params)->active=1;
        SDL_Log("User Input activated");
        startTextInputListener(&updateUserInput, params);
    }
    else{
        ((UserInputSurface*)*params)->active=0;
        stopTextInputListener();
    }
}

UserInputSurface *createUserInput(char *text, int posx, int posy){
    UserInputSurface *userInput=malloc(sizeof(UserInputSurface));
    void **params=malloc(sizeof(UserInputSurface*));
    userInput->userinput=malloc(USER_INPUT_MAX_LEN*sizeof(char));
    userInput->active=0;
    userInput->surface =createTextSurface(text, posx, posy);
    *params=userInput;
    addClickListener(&toggleUserInput, params, userInput->surface->blitObject->pos);
    return userInput;
}

Button *createButton(char *text,  int posx, int posy){
    
}
