#include "../header/gamesystem.h"
#include "../header/gamesystem.h"
#include "../header/boolean.h"
#include "../../constant.h"
#include "../header/petak.h"
#include "../header/kata.h"

#ifndef PRINTF
#define PRINTF(x) printf("\x1B[32m" x "\x1B[0m \n")
#endif

void gamesystem_print_giliran_player()
{
	printf("Giliran Player: ");
	PrintKata(Info(global.currentPlayer).nama);
	printf("\n");
	if (IsPenjara(Info(global.currentPlayer)))
	{
		printf("Anda sedang dipenjara\n");
		global.rolldice = true;
	}
}

void gamesystem_start()
{
	gamesystem_print_giliran_player();
	do {
		int pilihan;
		UserAction userAction;
		Kata parameter;
		read_user_input(&userAction, &parameter);
		gamesystem_do_action(userAction, parameter);
	} while (true);
}

void gamesystem_show_help()
{
	printf("Help:\n");
	printf("1.  Melempar dadu\n");
	printf("    Input command:\n");
	PRINTF("    > roll dice  \n");
	printf("\n");
	printf("2.  Melihat harga jual petak / properti\n");
	printf("    Input command:\n");
	PRINTF("    > info <nama petak>\n");
	printf("\n");
	printf("3.  Membeli petak yang sedang ditempati\n");
	printf("    Input command:\n");
	PRINTF("    > buy\n");
	printf("\n");
	printf("4.  Menawarkan petak yang dimiliki untuk dijual\n");
	printf("    Input command:\n");
	PRINTF("    > sell <nama petak>\n");
	printf("\n");
	printf("5.  Menjual petak ke bank\n");
	printf("    Input command:\n");
	PRINTF("    > sell bank <nama petak>\n");
	printf("\n");
	printf("6.  Menampilkan daftar petak yang ditawarkan di list offered.\n");
	printf("    Input command:\n");
	PRINTF("    > show offered\n");
	printf("\n");
	printf("7.  Membeli petak dari list offered\n");
	printf("    Input command:\n");
	PRINTF("    > buy offered <nama petak>\n");
	printf("\n");
	printf("8.  Meng‐upgrade level bangunan yang sedang ditempati\n");
	printf("    Input command:\n");
	PRINTF("    > upgrade\n");
	printf("\n");
	printf("9.  Menampilkan board\n");
	printf("    Input command:\n");
	PRINTF("    > board\n");
	printf("\n");
	printf("10. Menampilkan Leaderboard\n");
	printf("    Input command:\n");
	PRINTF("    > leaderboard\n");
	printf("\n");
	printf("11. Player yang tiba di petak World Cup dapat memilih kota yang akan menjadi host World Cup.\n");
	printf("    Input command:\n");
	PRINTF("    > host <nama kota>\n");
	printf("\n");
	printf("12. Player yang tiba di petak World Travel dapat memilih petak yang ingin dikunjungi.\n");
	printf("    Input command:\n");
	PRINTF("    > travel <nama kota>\n");
	printf("\n");
	printf("13. Mengakhiri giliran\n");
	printf("    Input command:\n");
	PRINTF("    > end turn\n");
	printf("\n");
	printf("14. Menyimpan permainan\n");
	printf("    Input command:\n");
	PRINTF("    > save <nama file>\n");
	printf("\n");
	printf("15. Me‐load permainan\n");
	printf("    Input command:\n");
	PRINTF("    > load <nama file>\n");
	printf("\n");
	printf("16. Memakai kartu bebas dari penjara\n");
	printf("    Input command:\n");
	PRINTF("    > free me\n");
	printf("\n");
	printf("17. Memakai kartu bebas pajak\n");
	printf("    Input command:\n");
	PRINTF("    > free tax\n");
	printf("\n");
	printf("18. Memakai kartu mati lampu\n");
	printf("    Input command:\n");
	PRINTF("    > off <nama kota/tempat rekreasi>\n");
	printf("\n");
	printf("19. Memakai Kartu perlindungan\n");
	printf("    Input command:\n");
	PRINTF("    > protect <nama kota/tempat rekreasi>");
}


void gamesystem_next_player()
{
	if (!global.rolldice)
	{
		printf("Anda belum roll dice\n");
		return;
	}
	global.rolldice = false;
	printf("End Turn\n");
	global.currentPlayer = Next(global.currentPlayer);
	gamesystem_print_giliran_player();
}

void gamesystem_do_action(UserAction userAction, Kata parameter)
{
	switch (userAction)
	{
		case ROLL_DICE: 
			if (!global.rolldice)
			{
				int numOfStep = gamesystem_roll_dice(2);
				MajuNLangkah(global.currentPlayer, global.listOfPetak, numOfStep);
				printf("Anda melangkah sebayak %d langkah\n", numOfStep);
			}
			else
			{
				if (!IsPenjara(Info(global.currentPlayer)))
				{
					printf("Udah pernah roll dice!\n");
				}
			}
		break;

		case INFO: PrintPetak(parameter);
		break;

		case BUY: 
		break;

		case SELL: 
		break;

		case SELL_BANK: 
		break;

		case SHOW_OFFERED: 
		break;

		case BUY_OFFERED: 
		break;

		case UPGRADE: 
		break;

		case BOARD: PrintBoard(global.listOfPetak, global.listOfPlayer);
		break;

		case LEADERBOARD: 
		break;

		case HOST: 
		break;

		case TRAVEL: 
		break;

		case END_TURN: gamesystem_next_player();
		break;

		case SAVE: 
		break;

		case LOAD:
		break;

		case FREE_ME:
		break;

		case FREE_TAX:
		break;

		case OFF:
		break;

		case PROTECT:
		break;

		case HELP: gamesystem_show_help();
		break;

		case EXIT: exit(0);
		break;

		default: printf("ERROR USER ACTION");
		break;
	}
	printf("Press Enter to continue.\n");
	char dum;
	scanf("%c", &dum);
	scanf("%c", &dum);
	printf("\n\n\n\n");
}

int gamesystem_roll_dice(int diceCount)
{
	srand((unsigned int)time(NULL));
	global.rolldice = true;
	int cnt = 0;
	int i;
	for (i = 0; i < diceCount; ++i)
	{
		int r = (rand()%6)+1;
		printf("Dice %d: %d\n", i+1, r);
		if (r == cnt)
		{
			printf("Selamat Anda mendapatkan Re-roll\n");
			global.rolldice = false;
		}
		cnt += r;
	}
	return cnt;
}
