#include "stdio.h"
#include "ADT/header/reader.h"
#include "constant.h"
#include "ADT/header/kata.h"
#include "ADT/header/gamesystem.h"
#include "ADT/header/load_save.h"

void welcome_screen()
{
	printf("   ======================================================================\n");
	printf("  ========================================================================\n");
	printf("||  TTTTTTTTTTTTT       AAAAA          JJJJJJJJJJ    IIIIIII   RRRRRRRR   ||\n");
	printf("|| TTTTTTTTTTTTTTT     AAAAAAA        JJJJJJJJJJJJ  IIIIIIIII  RRRRRRRRR  ||\n");
	printf("||       TTT          AAA   AAA           JJJJJ        III     RRR    RRR ||\n");
	printf("||       TTT         AAA     AAA          JJJJJ        III     RRR   RRR  ||\n");
	printf("||       TTT        AAAAAAAAAAAAA         JJJJJ        III     RRRRRRR    ||\n");
	printf("||       TTT       AAAAAAAAAAAAAAA        JJJJJ        III     RRR RRRRR  ||\n");
	printf("||       TTT      AAA           AAA  JJJJJJJJJ      IIIIIIIII  RRR  RRRRR ||\n");
	printf("||       TTT     AAAA           AAAA JJJJJJJJ        IIIIIII   RRR   RRRRR||\n");
	printf("||                                                                        ||\n");
	printf("||                                                       $$$$             ||\n");
	printf("||  EEEEEEEEEEEE   UUU         UUU  YYY     YYY        $$$$$$$$           ||\n");
	printf("|| EEEEEEEEEEEEEE  UUU         UUU   YYY   YYY        $$$$$$$$$$          ||\n");
	printf("|| EEEE            UUU         UUU    YYY YYY        $$$$ $$  $$$         ||\n");
	printf("|| EEEE            UUU         UUU     YYYYY           $$$$               ||\n");
	printf("|| EEEEEEEEEEEEEE  UUU         UUU      YYY              $$$$             ||\n");
	printf("|| EEEEEEEEEEEEEE  UUU         UUU      YYY                $$$$           ||\n");
	printf("|| EEEE            UUU         UUU      YYY               $$ $$$$         ||\n");
	printf("|| EEEE            UUU         UUU      YYY               $$  $$$$        ||\n");
	printf("|| EEEEEEEEEEEEEE   UUUUUUUUUUUUU       YYY           $$$$$  $$$$$        ||\n");
	printf("||  EEEEEEEEEEEE     UUUUUUUUUUU        YYY            $$$$$$$$$$         ||\n");
	printf("||                                                        $$$$            ||\n");
	printf("  ========================================================================\n");
	printf("   ======================================================================\n");
	printf("       Rasakan sensasi kepuasan tersendiri menjadi orang tajir!!!\n");
	printf("\n");
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
