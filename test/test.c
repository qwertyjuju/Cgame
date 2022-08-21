#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int func(int a, int b){
  return a+b;
}

int main(int argc, char *argv[]){
  int res=0;
  int (*ptr)(int, int)=func; // création du pointeur vers la fonction func
  res= ptr(13, 14); // appelle de la fonction callback
  printf("%d", res); // resultat: 27
  return 0;
}
*/
/*
typedef struct{
  void *func;
}TestStruct;

int  test(int a, int b){
    printf("%d %d\n", a, b);
    return a+b;
}

int callback(void *func){
  int res=0; 
  int(*call)(int,int)=func;
  res=call(12, 10);
  printf("%d", res);
}

int main(){
  TestStruct idk;
  idk.func=&test;
  callback(idk.func);
  return 0;
}
*/