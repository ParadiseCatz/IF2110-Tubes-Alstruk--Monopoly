typedef struct {
	ListOfPlayer listOfPLayer;
	ListOfPetak listOfPetak;
	Player *currentPlayer;
	Petak *currentWorldCup;
	QueueOfKartu queueOfKartu;
} GlobalVariable;

GlobalVariable global;