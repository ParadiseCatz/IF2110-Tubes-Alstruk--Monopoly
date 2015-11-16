#include "../header/load_save.h"
#include "../../globalvariable.h"
#include "../../constant.h"

void InitUrutanBoard()
{
	STARTKATA("data/urutanPetak.txt");
	while(!EndKata)
	{
		AddressOfPetak P;
		InfoPetak X;

		X.nama_petak = CKata;
		P = AlokasiPetak(X);

		AddLastLPetak(&global_listOfPetak, P);
		ADVKATA();
	}	
}

void AkuisisiPetak(InfoPetak *X)
{
	InfoPetak Xtmp;

	ADVKATA();

	Xtmp.nama_petak = CKata; 
	ADVKATA(); ADVKATA(); ADVKATA();

	Xtmp.jenis_petak = CKata;
	ADVKATA(); ADVKATA();

	// Xtmp.nama_petak = Ckata; siapa tahu nanti ada fitur kalau player bisa kasih nama kota yg dipunyai
	ADVKATA(); ADVKATA();

	Xtmp.harga_dasar = KataToInt(CKata);
	ADVKATA(); ADVKATA();

	Xtmp.harga_jual = KataToInt(CKata);
	ADVKATA(); ADVKATA();

	Xtmp.biaya_sewa = KataToInt(CKata);
	ADVKATA(); ADVKATA();

	Xtmp.biaya_ambil_alih = KataToInt(CKata);
	ADVKATA(); ADVKATA();

	Xtmp.biaya_upgrade = KataToInt(CKata);
	ADVKATA(); ADVKATA();

	Xtmp.level = KataToInt(CKata);
	ADVKATA(); ADVKATA();

	Xtmp.multiplier_sewa = KataToDouble(CKata);
	ADVKATA(); ADVKATA();

	Xtmp.pemilik = KataToInt(CKata);
	ADVKATA(); ADVKATA();

	Xtmp.blok = KataToChar(CKata);
	ADVKATA(); ADVKATA();

	int isBlackout = KataToInt(CKata);
	if(isBlackout == 0) Xtmp.blackout = false;
	else Xtmp.blackout = true;
	ADVKATA();

	*X = Xtmp;
}

void InitDataAwalBoard()
{
	// Kamus Lokal
	InfoPetak X;
	AddressOfPetak P;

	// Algoritma
	STARTKATA("data/dataPetak.txt");
	while(!EndKata)
	{
		AkuisisiPetak(&X);
		P = SearchPetak(global_listOfPetak, X.nama_petak);
		InfoPetak(P) = X;
	}	
}

void InitBoardAwal()
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
	CreateEmptyLPlayer(&global_listOfPlayer);
	for(i=1; i<=numOfPlayers; i++)
	{
		X.id = i;
		X.uang = STARTING_MONEY;
		CreateEmptyAOI(&X.idKartu);
		printf("Masukan nama untuk player %d : ", i); BacaKata(&X.nama);
		CreateEmptyAOK(&X.kota);
		X.posisi = First(global_listOfPlayer);
		X.penjara = false;
		
		P = AlokasiPlayer(X);
		AddPlayer(&global_listOfPlayer, P);
	}
}

void NewGame(int numOfPlayers)
{
	InitBoardAwal();
	InitPlayers(numOfPlayers);
}

void AkuisisiPlayer(InfoPlayer *X)
{
	InfoPlayer Xtmp;
	int i;

/*
Contoh format :
====== 1 =======
Nama_Player: Ngiong
Lokasi_Player: 1
Uang: 500000
Status_Penjara: 0
Kartu_Yang_Dimiliki: 5 1 2 3 4 5
Petak_Yang_Dimiliki: 3 Jakarta New_Delhi Mesir
*/

	ADVKATA();

	Xtmp.id = KataToInt(CKata);
	ADVKATA(); ADVKATA(); ADVKATA();

	Xtmp.nama = CKata;
	ADVKATA(); ADVKATA();

	int playerLocation = KataToInt(CKata);
	AddressOfPetak playerPosition = SearchPetakByID(global_listOfPetak, playerLocation);
	Xtmp.posisi = playerPosition;
	ADVKATA(); ADVKATA();

	Xtmp.uang = KataToInt(CKata):
	ADVKATA(); ADVKATA();

	int isInPenjara = KataToInt(CKata);
	if(isInPenjara == 1) Xtmp.penjara = true;
	else Xtmp.penjara = false;
	ADVKATA(); ADVKATA();

	int numOfCardsOwned = KataToInt(CKata);
	ADVKATA();
	for(i=0; i<numOfCardsOwned; i++)
	{
		AddAOI(&Xtmp.idKartu, KataToInt(CKata));
		ADVKATA();
	}
	ADVKATA();

	int numOfPetakOwned = KataToInt(CKata);
	ADVKATA();
	for(i=0; i<numOfPetakOwned; i++)
	{
		AddAOK(&Xtmp.kota, CKata);
		ADVKATA();
	}

	*X = Xtmp;
}

void LoadGlobalVariables(char *directory)
{
	FILE *fp;
	fp = fopen(directory, "w");
	
	InfoPlayer P = global_currentPlayer->info;
	fprintf(fp, "Current_Player: %d\n", P.id);
	
	InfoPetak WC = global_currentWorldCup->info;
	fprintf(fp, "Current_WorldCup: %d\n", WC.indeks);
	
	//fprintf(fp, "Jumlah_antrian_kartu: %d\n", Size(global_QueueOfKartu));
	fprintf(fp, "Queue_kartu:\n");
	// Print indeks dari Q.head sampai Q.tail
	
	fprintf(fp, "Stack_defeated_players:\n");
	// For ... PrintPlayerToFile(fp, InfoPlayer);
	
	fclose(fp);
	// Kamus Lokal
	int id_currentPlayer, id_currentWorldCup, jumlahKartu;
	ArrayOfInt currentIDKartu;

	// Algoritma
	STARTKATA(directory);
	ADVKATA();

	id_currentPlayer = KataToInt(CKata);
	ADVKATA(); ADVKATA();

	id_currentWorldCup = KataToInt(CKata);
	ADVKATA(); ADVKATA();

	jumlahKartu = KataToInt(CKata);
	ADVKATA(); ADVKATA();

	for(i=0; i<jumlahKartu; i++)
	{
		int tmpIDKartu = KataToInt(CKata);
		AddAOI(&currentIDKartu, tmpIDKartu);
		ADVKATA();
	}

	ADVKATA();
	while(!EndKata)
	{
		InfoPlayer X;
		AkuisisiPlayer(&X);
		// Masukin X ke Stack
	}

}

void LoadDataPetak(char *directory)
{
	// Kamus Lokal
	InfoPetak X;
	AddressOfPetak P;

	// Algoritma
	STARTKATA(directory);
	while(!EndKata)
	{
		AkuisisiPetak(&X);
		P = SearchPetak(global_listOfPetak, X.nama_petak);
		InfoPetak(P) = X;
	}	
}

void LoadDataPlayers(char *directory)
{
	// Kamus Lokal
	InfoPlayer X;
	AddressOfPlayer P;

	// ALgoritma
	STARTKATA(directory);
	while(!EndKata)
	{
		AkuisisiPlayer(&X);
		P = AlokasiPlayer(X);
		AddLPlayer(&global_listOfPlayer, P);
	}
}

void LoadGame(int slot)
{
	char *dirDataPlayer, *dirDataPetak, *dirGlobalVar;

	if(slot == 1)
	{
		dirDataPlayer = "savegame/savegame1/dataPlayer.txt";
		dirDataPetak = "savegame/savegame1/dataPetak.txt";
		dirGlobalVar = "savegame/savegame1/dataGlobalVariables.txt"
	}
	else
	{
		dirDataPlayer = "savegame/savegame2/dataPlayer.txt";
		dirDataPetak = "savegame/savegame2/dataPetak.txt";
		dirGlobalVar = "savegame/savegame2/dataGlobalVariables.txt"
	}

	InitUrutanBoard();
	LoadGlobalVariables(dirGlobalVar); LoadDataPetak(dirDataPetak); LoadDataPlayers(dirDataPlayer); 
}

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
	
	int numOfPlayers = NbElmtLPlayer(global_listOfPlayer);
	int i;
	InfoPlayer X;
	AddressOfPlayer P;

	P = FirstLPlayer(global_listOfPlayer);
	for(i=0; i<numOfPlayers; i++)
	{
		X = InfoPlayer(P);
		PrintPlayerToFile(fp, X);
		P = NextPlayer(P);
	}
	
	fclose(fp);
}

void SaveDataPetak(char *directory)
{
	FILE *fp;
	fp = fopen(directory, "w");

	int numOfPetak = NbElmtLPetak(global_listOfPetak);
	int i;
	InfoPetak X;
	AddressOfPetak P;

	P = FirstLPetak(global_listOfPetak);
	for(i=0; i<numOfPetak; i++)
	{
		X = InfoPetak(P);

		// if (X adalah Kota / Tempat_Wisata)
		// {
				PrintPetakToFile(fp, X);
		// }
					
		P = NextPetak(P);
	}

	fclose(fp);
}

void SaveGame(int slot)
{
	char *dirDataPlayer, *dirDataPetak, *dirGlobalVar;

	if(slot == 1)
	{
		dirDataPlayer = "savegame/savegame1/dataPlayer.txt";
		dirDataPetak = "savegame/savegame1/dataPetak.txt";
		dirGlobalVar = "savegame/savegame1/dataGlobalVariables.txt"
	}
	else
	{
		dirDataPlayer = "savegame/savegame2/dataPlayer.txt";
		dirDataPetak = "savegame/savegame2/dataPetak.txt";
		dirGlobalVar = "savegame/savegame2/dataGlobalVariables.txt"
	}

	SaveDataGlobalVariables(dirGlobalVar);
	SaveDataPlayer(dirDataPlayer);
	SaveDataPetak(dirDataPetak);
}
