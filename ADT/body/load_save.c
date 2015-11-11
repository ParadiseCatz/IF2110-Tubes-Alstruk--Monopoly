#include "../header/load_save.h"
#include "../header/mesinkata.h"

void InitBoard()
{
	
}

void LoadDataBoard();

void LoadPlayers(int numOfPlayers);

void LoadDataPlayers();

void NewGame(int numOfPlayers)
{
	LoadBoard();
	LoadDataBoard();
	LoadPlayers(numOfPlayers);
	LoadDataPlayers();
}

void LoadGame(int slot);

void SaveGame(int slot);
