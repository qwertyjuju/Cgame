#ifndef SURFACES_H
#define SURFACES_H
#include <string.h>
#include "display.h"

typedef struct TextSurface{
    BlitObject *blitObject;
    char *text;
}TextSurface;

/* returns a text surface
the text parameter is the text to print on surface
*/
TextSurface *createTextSurface(char *text, int posx, int posy);
int updateTextSurface(TextSurface *textSurface, char*text);
int appendTextSurface(TextSurface *textSurface, char*text);
int initSurfaces();
#include "ui.h"
#endif