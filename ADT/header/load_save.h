#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H
#include "mesinkata.h"
#include "player.h"
#include "petak.h"
#include <stdio.h>

void InitDataKartu();

void InitUrutanBoard();

void AkuisisiPetak(InfoPetak *X);

void InitDataAwalBoard();

void InitBoardAwal();

void InitPlayers(int numOfPlayers);

void NewGame(int numOfPlayers);

void AkuisisiPlayer(InfoPlayer *X);

void LoadGlobalVariables(char *directory);

void LoadDataPetak(char *directory);

void LoadDataPlayers(char *directory);

void LoadGame(Kata namaSaveGame);

void SaveDataGlobalVariables(char *directory);

void SaveDataPlayer(char *directory);

void SaveDataPetak(char *directory);

void SaveGame(Kata namaSaveGame);

#endif
