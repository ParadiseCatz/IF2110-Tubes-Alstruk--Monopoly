#include "ADT/header/player.h"
#include "ADT/header/petak.h"

typedef struct {
	ListPlayer listPlayer;
	ListPetak listPetak;
	InfoPlayer *currentPlayer;
	InfoPetak *currentWorldCup;
	QueueOfKartu queueOfKartu;
	StackOfPlayer stackOfDefeated;
} GlobalVariable;

GlobalVariable global;
