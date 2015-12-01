/* KHUSUS UNTUK DRIVER INI, UNTUK MELAKUKAN TEST PERLU DIPINDAH KE DIRECTORY UTAMA*/
#include "ADT/header/load_save.h"
#include "ADT/header/player.h"
#include "ADT/header/petak.h"
#include "ADT/header/gamesystem.h"
#include "ADT/header/cards.h"

int main()
{
	NewGame(4);
	AddressOfPetak P;
	AddressOfPlayer Pl;

	/* ======================== Testing untuk NewGame ======================== */
	// Testing untuk InitBoardAwal
	P = FirstPetak(global.listOfPetak); 
	do
	{
		InfoPetak X;
		X = InfoPetak(P);
		Kata namaPetak = X.nama_petak;
		PrintPetak(namaPetak);

		P = NextPetak(P);

	}while(P!=FirstPetak(global.listOfPetak));

	puts("Testing InitBoardAwal Done!\n *** ============ oOOo ============ *** ");

	Pl = First(global.listOfPlayer);
	do
	{
		InfoPlayer X;
		X = Info(Pl);
		PrintElmtPlayer(X);

		Pl = Next(Pl);

	} while(Pl != First(global.listOfPlayer));

	puts("Testing InitPlayerAwal Done!\n *** ============ oOOo ============ *** ");


	int i;
	for (i=0; i<8; i++)
	{
		InfoKartu X = global.arrayOfCards.TabCards[i];
		PrintCard(X);
	}
	/* ======================== Testing untuk SaveGame ======================== */

	Kata namaFile;
	printf("Masukan kata kunci untuk penyimpanan file : "); BacaKata(&namaFile);
	SaveGame(namaFile);

	puts("Testing SaveGame Done!\n *** ============ oOOo ============ *** ");

	/* ======================== Testing untuk LoadGame ======================== */

	printf("Masukan kata kunci untuk load game : "); BacaKata(&namaFile);
	if(LoadGame(namaFile))
	{
		P = FirstPetak(global.listOfPetak); 
		do
		{
			InfoPetak X;
			X = InfoPetak(P);
			Kata namaPetak = X.nama_petak;
			PrintPetak(namaPetak);

			P = NextPetak(P);

		}while(P!=FirstPetak(global.listOfPetak));

		Pl = First(global.listOfPlayer);
		do
		{
			InfoPlayer X;
			X = Info(Pl);
			PrintElmtPlayer(X);

			Pl = Next(Pl);

		} while(Pl != First(global.listOfPlayer));

		puts("\n\nCURRENT PLAYER:");
		PrintElmtPlayer(Info(global.currentPlayer));

		puts("\n\nCURRENT WORLDCUP:");
		if(global.currentWorldCup == NULL) puts("NULL");
		else PrintPetak(Info(global.currentWorldCup).nama_petak);

		printf("rollDiceResult : %d\n", global.diceRollResult);
		if(global.rolldice) puts("ROLL DICE");
		else puts("NO ROLL DICE");

		puts("\n\nStackOfDefeated:");
		while(Top(global.stackOfDefeated) != NULL)
		{
			InfoPlayer X;
			Pop(&global.stackOfDefeated, &X);
			PrintElmtPlayer(X);
		}
	}
	else puts("Load Game Gagal");

	puts("Testing LoadGame Done!\n *** ============ oOOo ============ *** ");
	

	return 0;
}
