#include "main.h"

Player *initPlayer(){
    Player *player=malloc(sizeof(Player));
    return player;
}

int main(int argc, char *argv[]){
    SDL_bool quit=0;
    SDL_Event e;
    initEngine("game", 1500, 900);
    createTextSurface("Character creation",0,0);
    UserInputSurface *playerName=createUserInput("choose youre character name:",0,32);
    TextSurface *playerClass=createTextSurface("choose character class:\n\
        1. Warrior\n\
        2. Sorcerer\n\
        3. Thief\n",0,64);
    TextSurface *test=createTextSurface("test",0,200);
    runEngine();
    return 0;
}

/*
char *getClassName(const Player *player)
{
    char *classes[]={"warrior", "sorcerer", "thief"};
    return classes[(*player).plclass-1];
}

void initPlayer(Player *player)
{
    int class;
    printf("##################################################################################################################\n\
Character creation\n\
##################################################################################################################\n");
    printf("choose youre character name:\n");
    scanf("%s", &(*player).name);
    do{
        printf("choose character class:\n\
        1. Warrior\n\
        2. Sorcerer\n\
        3. Thief\n");
        scanf("%d", &class);
    }while(class>3 || class<1);
    (*player).plclass = class;
    (*player).health = STARTING_HEALTH;
    (*player).money = STARTING_MONEY;
}

void renderPlayerInfo(const Player *player)
{
    printf("Character %s:\nhealth: %d\nmoney: %d\nclass: %s",(*player).name,(*player).health, (*player).money, getClassName(player));
}


int main(int argc, char *argv[])
{
    Player player={0};
    initPlayer(&player);
    renderPlayerInfo(&player);
    return 0;
}
*/