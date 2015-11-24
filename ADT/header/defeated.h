#ifndef	DEFEATED_H
#define DEFEATED_H
#include "boolean.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>


/* Definisi Type Stack */
typedef struct {
    AddressOfPlayer     top;
} StackOfPlayer;

#define Top(S) (S).top
#define Next(P) (P)->next
#define Info(P) (P)->info
#define InfoTop(S) Info(Top(S))
void CreateEmptyS (StackOfPlayer *S);
void Push (StackOfPlayer *S, InfoPlayer X);
void Pop (StackOfPlayer *S, InfoPlayer *X);
#endif
