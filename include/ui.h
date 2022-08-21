#ifndef UI_H
#define UI_H
#include "surfaces.h"

typedef struct{
    TextSurface *surface;
    char *userinput;
    int active;
}UserInputSurface;

typedef struct{
    TextSurface *surface;
}Button;

UserInputSurface *createUserInput(char *text, int posx, int posy);
#endif