#ifndef	DEFEATED_H
#define DEFEATED_H
#include "../../globalvariable.h"


/* Definisi Type Stack */

#define Top(S) (S).top
#define Next(P) (P)->next
#define Info(P) (P)->info
#define InfoTop(S) Info(Top(S))
void CreateEmptyS (StackOfPlayer *S);
void Push (StackOfPlayer *S, InfoPlayer X);
void Pop (StackOfPlayer *S, InfoPlayer *X);
#endif
