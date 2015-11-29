#include "stdio.h"
#include "ADT/header/reader.h"
#include "constant.h"
#include "ADT/header/kata.h"
#include "ADT/header/gamesystem.h"
#include "ADT/header/load_save.h"

void welcome_screen()
{
	printf("Halo\n");
}

void start_menu()
{
	printf("Menu:\n");
	printf("1. New Game\n");
	printf("2. Load Game:\n");
	printf("Pilihan: ");
	int pilihan;
	read_with_limit(1, 2, &pilihan);
	if (pilihan == 1)
	{
		printf("Num of Player? ");
		read_with_limit(1, PLAYER_MAX, &pilihan);
		NewGame(pilihan);
		gamesystem_start();
	}
	else
	{
		Kata input;
		BacaKata(&input);
		LoadGame(input);
		gamesystem_start();
	}
}

int main(int argc, char const *argv[])
{
	welcome_screen();
	start_menu();
	return 0;
}
