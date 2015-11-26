#include "../header/gamesystem.h"
#include "../../globalvariable.h"
#include "../header/gamesystem.h"
#include "../header/boolean.h"
#include "../../constant.h"
#include "../header/petak.h"

void gamesystem_start()
{
	boolean finish = false;
	do {
		gamesystem_show_menu();
		int pilihan;
		read_with_limit(1, MENU_MAX, &pilihan);
		gamesystem_do_action(pilihan);
	} while (!finish);
}

void gamesystem_show_menu()
{
	printf("Menu:\n");
	printf("1. Roll Dice\n");
	printf("2. Beli Petak\n");
	printf("3. Info Player\n");
	printf("4. Info Board\n");
	printf("5. Info Petak\n");
	printf("6. Jual Properti\n");
	printf("7. Level up\n");
	printf("8. Show Leaderboard\n");
	printf("9. End Turn\n");
}

void gamesystem_do_action(int pilihan)
{
	switch (pilihan)
	{
		case 1: MajuNLangkah(global.currentPlayer, global.listOfPetak, gamesystem_roll_dice(2));
		break;
		//Roll Dice

		case 2: Buy();
		break;
		//Beli Petak

		case 3: PrintElmtPlayer(*global.currentPlayer);
		break;
		//Info player

		case 4: PrintBoard();
		break;
		//Info board

		case 5: 
		break;
		//info petak

		case 6: 
		break;
		//jual properti

		case 7: LevelUp();
		break;
		//level up

		case 8: 
		break;
		//show leaderboard

		case 9: 
		break;
		//end turn
	}
}

int gamesystem_roll_dice(int diceCount)
{
	srand((unsigned int)time(NULL));
	int cnt = 0;
	int i;
	for (i = 0; i < diceCount; ++i)
	{
		cnt += (rand()%6)+1;
	}
	return cnt;
}