#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H
#include "mesinkata.h"
#include "player.h"
#include "petak.h"
#include <stdio.h>

void InitUrutanBoard();

void InitDataAwalBoard();

void InitBoard();

void InitPlayers(int numOfPlayers);

void LoadDataPlayers();

void NewGame(int numOfPlayers);

void LoadGame(int slot);

void SaveDataGlobalVariables(char *directory);

void SaveDataPlayer(char *directory);

void SaveDataPetak(char *directory);

void SaveGame(int slot);

#endif
