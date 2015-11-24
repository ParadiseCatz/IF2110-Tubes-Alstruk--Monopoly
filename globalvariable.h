#ifndef GLOBAL_H
#define GLOBAL_H

#include "ADT/header/player.h"
#include "ADT/header/petak.h"
#include "ADT/header/cards.h"

typedef struct {
	ListPlayer listOfPlayer;
	ListPetak listOfPetak;
	InfoPlayer *currentPlayer;
	InfoPetak *currentWorldCup;
	Deck queueOfKartu;
	StackOfPlayer stackOfDefeated;
} GlobalVariable;

GlobalVariable global;

#endif