#include "ADT/header/player.h"
#include "ADT/header/petak.h"

typedef struct {
	ListOfPlayer listOfPlayer;
	ListOfPetak listOfPetak;
	Player *currentPlayer;
	Petak *currentWorldCup;
	QueueOfKartu queueOfKartu;
	StackOfPlayer stackOfDefeated;
} GlobalVariable;

GlobalVariable global;
