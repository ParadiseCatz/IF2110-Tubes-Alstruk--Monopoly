#include "../header/load_save.h"
#include "../../globalvariable.h"
#include "../../constant.h"

void InitUrutanBoard()
{
	STARTKATA("data/urutanPetak.txt");
	while(!EndKata)
	{
		InfoPetak P;
		ADVKATA();
	}	
}

void InitDataAwalBoard()
{
	
}

void InitBoard()
{
	InitUrutanBoard();
	InitDataPetakAwal();
}

void InitPlayers(int numOfPlayers)
{
	// Kamus Lokal
	int i;
	AddressOfPlayer P;
	InfoPlayer X;
	// Algoritma
	CreateEmptyLPlayer(&global_ListOfPlayer);
	for(i=1; i<=numOfPlayers; i++)
	{
		X.id = i;
		X.uang = STARTING_MONEY;
		CreateEmptyAOI(&X.idKartu);
		printf("Masukan nama untuk player %d : ", i); BacaKata(&X.nama);
		CreateEmptyAOK(&X.kota);
		X.posisi = First(global_ListOfPlayer);
		X.penjara = false;
		
		P = AlokasiPlayer(X);
		AddPlayer(&global_ListOfPlayer, P);
	}
}

void LoadDataPlayers();

void NewGame(int numOfPlayers)
{
	InitBoard();
	InitPlayers(numOfPlayers);
}

void LoadGame(int slot);

void SaveDataGlobalVariables(char *directory)
// Menyimpan currentPlayer, currentWorldCup, queueKartu, dan stackDefeated
{
	FILE *fp;
	fp = fopen(directory, "w");
	
	InfoPlayer P = global_currentPlayer->info;
	fprintf(fp, "Current_Player: %d\n", P.id);
	
	InfoPetak WC = global_currentWorldCup->info;
	fprintf(fp, "Current_WorldCup: %d\n", WC.indeks);
	
	fprintf(fp, "Queue_kartu:\n");
	// Print indeks dari Q.head sampai Q.tail
	
	fprintf(fp, "Stack_defeated_players:\n");
	// For ... PrintPlayerToFile(fp, InfoPlayer);
	
	fclose(fp);
}

void SaveDataPlayer(char *directory)
{
	FILE *fp;
	fp = fopen(directory, "w");
	
	
	
	fclose(fp);
}

void SaveDataPetak(char *directory);

void SaveGame(int slot)
{
	char *dirDataPlayer, *dirDataPetak, *dirGlobalVar;
	// Assign pointer di atas dengan directory DEPEND ON 'slot'
	SaveDataGlobalVariables(dirGlobalVar);
	SaveDataPlayer(dirDataPlayer);
	SaveDataPetak(dirDataPetak);
	
}
