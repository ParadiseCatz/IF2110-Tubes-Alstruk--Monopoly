#include "ADT/header/player.h"
#include "ADT/header/petak.h"

typedef struct {
	ListOfPlayer listOfPlayer;
	ListOfPetak listOfPetak;
	InfoPlayer *currentPlayer;
	InfpPetak *currentWorldCup;
	QueueOfKartu queueOfKartu;
	StackOfPlayer stackOfDefeated;
} GlobalVariable;

GlobalVariable global;
