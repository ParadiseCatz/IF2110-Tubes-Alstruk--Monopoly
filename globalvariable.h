#include "ADT/header/player.h"
#include "ADT/header/petak.h"

typedef struct {
	ListPlayer listOfPlayer;
	ListPetak listOfPetak;
	InfoPlayer *currentPlayer;
	InfoPetak *currentWorldCup;
	QueueOfKartu queueOfKartu;
	StackOfPlayer stackOfDefeated;
} GlobalVariable;

GlobalVariable global;
