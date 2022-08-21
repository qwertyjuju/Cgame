#ifndef MAIN_H
#define MAIN_H
#define STARTING_HEALTH 100
#define STARTING_MONEY 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "engine.h"



typedef enum {
    WARRIOR=1,
    SORCERER=2,
    THIEFT=3
}PlayerClass;

typedef struct Player{
    char *name;
    int health;
    int money;
    PlayerClass plclass;
}Player;
#endif