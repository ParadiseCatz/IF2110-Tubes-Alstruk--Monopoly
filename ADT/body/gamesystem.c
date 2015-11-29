#include "../header/gamesystem.h"
#include "../header/reader.h"
#include "../header/player.h"
#include "../header/boolean.h"
#include "../../constant.h"
#include "../header/petak.h"
#include "../header/kata.h"
#include "../header/load_save.h"
#include "time.h"

#ifndef PRINTF
#define PRINTF(x) printf("\x1B[32m" x "\x1B[0m")
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
	srand((unsigned int)time(NULL));
	gamesystem_print_giliran_player();
	do {
		int pilihan;
		UserAction userAction;
		Kata parameter;
		read_user_input(&userAction, &parameter);
		gamesystem_do_action(userAction, parameter);
	} while (true);
}

void swapInt(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void swapKata(Kata *a, Kata *b)
{
	Kata tmp = *a;
	*a = *b;
	*b = tmp;
}

void gamesystem_show_defeated()
{
	printf("List of Defeated Player:\n");
	StackOfPlayer tmp;
	tmp = global.stackOfDefeated;
	int i = 1;
	while (Top(tmp) != Nil)
	{
		printf("%d. ", i++);
		PrintKata(Info(Top(tmp)).nama);
		printf("\n");
	}
}

void gamesystem_show_leaderboard(ListPlayer L)
{
	if (First(L) == Nil)
	{
		gamesystem_show_defeated();
		return;
	}
	ArrayOfInt playerWealthArray;
	CreateEmptyAOI(&playerWealthArray);

	ArrayOfKata playerNameArray;
	CreateEmptyAOK(&playerNameArray);

	AddressOfPlayer Last=First(L);
    while (Next(Last)!=First(L))
    {
    	AddAOI(&playerWealthArray, HitungHartaPlayer(Info(Last)));
    	AddAOK(&playerNameArray, Info(Last).nama);
        Last=Next(Last);
    }
    AddAOI(&playerWealthArray, HitungHartaPlayer(Info(Last)));
    AddAOK(&playerNameArray, Info(Last).nama);

    int n = NbElmtAOK(playerNameArray);
    int i;
    for (i = 1; i <= n - 1; ++i)
    {
    	int j;
    	for (j = i+1; j <= n; ++j)
    	{
    		if (playerWealthArray.T[i] < playerWealthArray.T[j])
    		{
    			swapInt(&playerWealthArray.T[i], &playerWealthArray.T[j]);
    			swapKata(&playerNameArray.T[i], &playerNameArray.T[j]);
    		}
    	}
    }

    printf("Leaderboard:\n");
    for (i = 1; i <= n; ++i)
    {
    	printf("%d. Player: ", i);
    	PrintKata(playerNameArray.T[i]);
    	printf("\n");

    	printf("   Wealth: %d\n", playerWealthArray.T[i]);
    }
    gamesystem_show_defeated();
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
	printf("17. Memakai kartu mati lampu\n");
	printf("    Input command:\n");
	PRINTF("    > off <nama kota/tempat rekreasi>\n");
	printf("\n");
	printf("18. Memakai kartu perlindungan\n");
	printf("    Input command:\n");
	PRINTF("    > protect <nama kota/tempat rekreasi>\n");
	printf("\n");
	printf("19. Memakai kartu langkah dobel\n");
	printf("    Input command:\n");
	PRINTF("    > double move\n");
	printf("\n");
	printf("20. Menampilkan help ini\n");
	printf("    Input command:\n");
	PRINTF("    > help\n");
	printf("\n");
	printf("21. Keluar dari permainan\n");
	printf("    Input command:\n");
	PRINTF("    > exit\n");
}

boolean gamesystem_check_losing_condition()
{
	if (Info(global.currentPlayer).uang <= 0)
	{
		AddressOfPlayer P = global.currentPlayer;
		global.currentPlayer = Next(global.currentPlayer);

		InfoPlayer X;
		Del (&(global.listOfPlayer), &X, Info(P).id);
		return true;
	}
	return false;
}

void gamesystem_make_champion(InfoPlayer x)
{
	printf("\n\n");
	printf("#################\n");
	printf("#### WE HAVE ####\n");
	printf("####### A #######\n");
	printf("#### WINNER! ####\n");
	printf("#################\n");
	printf("Champion: \n");
	printf("   Player ");
	PrintKata(x.nama);
	printf("\n");
}

void gamesystem_next_player()
{
	if (!global.rolldice)
	{
		printf("Anda belum roll dice\n");
		return;
	}
	global.rolldice = global.alreadyUpgrade = false;
	printf("Ending Turn...\n");

	if (IsTourismMonopoly(Info(global.currentPlayer)) || IsTripleMonopoly(Info(global.currentPlayer)))
	{
		gamesystem_make_champion(Info(global.currentPlayer));
	}

	if (gamesystem_check_losing_condition())
	{
		printf("Maaf Player ");
		PrintKata(Info(global.currentPlayer).nama);
		printf(" kalah\n");
	}
	else
		global.currentPlayer = Next(global.currentPlayer);
	// Tinggal 1 Player
	if (global.currentPlayer == Next(global.currentPlayer))
	{
		gamesystem_make_champion(Info(global.currentPlayer));
	}
	gamesystem_print_giliran_player();
}

void gamesystem_do_action(UserAction userAction, Kata parameter)
{
	switch (userAction)
	{
		case ROLL_DICE: 
			if (!global.rolldice)
			{
				global.diceRollResult = gamesystem_roll_dice(2);
				printf("Anda melangkah sebayak %d langkah\n", global.diceRollResult);
				MajuNLangkah(&Info(global.currentPlayer), global.listOfPetak, global.diceRollResult);
				if (isKota(Info(global.currentPlayer).posisi) || isTempatWisata(Info(global.currentPlayer).posisi))
				{
					printf("Saat ini anda berada di:\n");
					PrintPetak(Info(Info(global.currentPlayer).posisi).nama_petak);
				}
				
			}
			else
			{
				if (!IsPenjara(Info(global.currentPlayer)))
				{
					printf("Udah pernah roll dice!\n");
				}
				else
				{
					printf("Lagi di penjara bos\n");
				}
			}
		break;

		case INFO: PrintPetak(parameter);
		break;

		case BUY: 
		if (isKota(Info(global.currentPlayer).posisi) || isTempatWisata(Info(global.currentPlayer).posisi))
		{
			Buy();
		}
		else
		{
			printf("Anda tidak sedang berada di kota\n");
		}
		break;

		case SELL: SalePetak(parameter);
		break;

		case SELL_BANK: JualKeBank(parameter);
		break;

		case SHOW_OFFERED: PrintSale();
		break;

		case BUY_OFFERED: BeliSale(parameter);
		break;

		case UPGRADE: 
			if (!global.alreadyUpgrade)
			{
				if (LevelUp())
					global.alreadyUpgrade = true;
			}
			else
			{
				printf("Anda sudah pernah upgrade\n");
			}
			
		break;

		case BOARD: PrintBoard(global.listOfPetak, global.listOfPlayer);
		break;

		case LEADERBOARD: gamesystem_show_leaderboard(global.listOfPlayer);
		break;

		case HOST: AppointWorldCup(parameter);
		break;

		case TRAVEL: WorldTravel(parameter);
		break;

		case END_TURN: gamesystem_next_player();
		break;

		case SAVE: SaveGame(parameter);
		break;

		case LOAD: LoadGame(parameter);
		break;

		case FREE_ME: 
			if (isMemberAOI(Info(global.currentPlayer).idKartu, 1) && IsPenjara(Info(global.currentPlayer)))
			{
				DeleteAOI(&Info(global.currentPlayer).idKartu, 1);
				KeluarPenjara(&Info(global.currentPlayer));
			}
			else
			{
				printf("Anda tidak bisa melakukan bebas penjara\n");
			}
		break;

		case OFF: 
			if (isMemberAOI(Info(global.currentPlayer).idKartu, 6) && SearchPetak(global.listOfPetak, parameter))
			{
				Info(SearchPetak(global.listOfPetak, parameter)).blackout = true;
			}
			else
			{
				printf("Anda tidak bisa melakukan blackout\n");
			}
		break;

		case PROTECT: 
			if (isMemberAOI(Info(global.currentPlayer).idKartu, 7) && SearchPetak(global.listOfPetak, parameter))
			{
				Info(SearchPetak(global.listOfPetak, parameter)).blackout = true;
			}
			else
			{
				printf("Anda tidak bisa melakukan protection\n");
			}
		break;

		case DOUBLE_MOVE:
			if (isMemberAOI(Info(global.currentPlayer).idKartu, 5) && global.rolldice && !IsPenjara(Info(global.currentPlayer)))
			{
				printf("Anda melangkah lagi sebanyak %d\n", global.diceRollResult);
				MajuNLangkah(&Info(global.currentPlayer), global.listOfPetak, global.diceRollResult);
				if (isKota(Info(global.currentPlayer).posisi) || isTempatWisata(Info(global.currentPlayer).posisi))
				{
					printf("Saat ini anda berada di:\n");
					PrintPetak(Info(Info(global.currentPlayer).posisi).nama_petak);
				}
				global.diceRollResult = global.diceRollResult << 1;
			}
			else
			{
				printf("Anda tidak bisa melakukan double move\n");
			}
		break;

		case HELP: gamesystem_show_help();
		break;

		case EXIT: exit(0);
		break;

		default: printf("ERROR USER ACTION");
		break;
	}
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
