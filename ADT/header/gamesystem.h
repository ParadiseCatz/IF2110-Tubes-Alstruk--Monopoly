#ifndef GAME_H
#define GAME_H
#include "../../globalvariable.h"
void gamesystem_start();
void gamesystem_show_help();
void gamesystem_do_action(UserAction userAction, Kata parameter);
int gamesystem_roll_dice(int diceCount);
#endif