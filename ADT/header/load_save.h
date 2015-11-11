#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H
#include "mesinkata.h"
#include <stdio.h>

void InitBoard();

void LoadBoardData();

void LoadPlayers(int numOfPlayers);

void LoadDataPlayers();

void NewGame();

void LoadGame(int slot);

void SaveGame(int slot);

#endif
