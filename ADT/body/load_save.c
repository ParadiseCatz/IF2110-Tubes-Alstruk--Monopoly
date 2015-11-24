#include "../header/load_save.h"
#include "../../globalvariable.h"
#include "../../constant.h"

void PrintKataToFile(FILE *fp, Kata K)
{
	int i;
	for(i=0; i<K.Length; i++)
	{
		fprintf(fp, "%c", K.TabKata[i]);
	}
}

void PrintPetakToFile(FILE *fp, InfoPetak X)
{
	int blackout = (X.blackout)?1:0;
	fprintf(fp, "===== "); PrintKataToFile(fp, X.nama_petak); fprintf(fp, " =====\n");
	fprintf(fp, "Jenis_Petak: "); PrintKataToFile(fp, X.nama_petak); fprintf(fp, "\n");
	fprintf(fp, "Nama_Petak: "); PrintKataToFile(fp, X.nama_petak); fprintf(fp, "\n");
	fprintf(fp, "Harga_Dasar: "); fprintf(fp,"%d", X.harga_dasar); fprintf(fp, "\n");
	fprintf(fp, "Harga_Jual: "); fprintf(fp,"%d", X.harga_jual); fprintf(fp, "\n");
	fprintf(fp, "Biaya_Sewa: "); fprintf(fp,"%d", X.biaya_sewa); fprintf(fp, "\n");
	fprintf(fp, "Biaya_Upgrade: "); fprintf(fp,"%d", X.biaya_upgrade); fprintf(fp, "\n");
	fprintf(fp, "Level: "); fprintf(fp,"%d", X.level); fprintf(fp, "\n");
	fprintf(fp, "Multiplier_Sewa: "); fprintf(fp,"%.4lf", X.multiplier_sewa); fprintf(fp, "\n");
	fprintf(fp, "Pemilik: "); fprintf(fp,"%d", X.pemilik); fprintf(fp, "\n");
	fprintf(fp, "Blok: "); fprintf(fp,"%c", X.blok); fprintf(fp, "\n");
	fprintf(fp, "Blackout: "); fprintf(fp, "%d", blackout); fprintf(fp, "\n");
}

void PrintPlayerToFile(FILE *fp, InfoPlayer X)
{
	int playerLocationIdx, isInPenjara, jumlahKartu, jumlahKota, i;
	
	fprintf(fp, "===== "); printf("%d", X.id); fprintf(fp, " =====\n");
	fprintf(fp, "Nama_Player: "); PrintKataToFile(fp, X.nama); fprintf(fp, "\n");
	fprintf(fp, "Lokasi_Player: "); fprintf(fp, "%d", playerLocationIdx); fprintf(fp, "\n");
	fprintf(fp, "Uang: "); fprintf(fp, "%d", X.uang); fprintf(fp, "\n");
	fprintf(fp, "Status_Penjara: "); fprintf(fp, "%d", isInPenjara); fprintf(fp, "\n");
	
	fprintf(fp, "Kartu_Yang_Dimiliki: "); fprintf(fp, "%d", jumlahKartu);
	for(i=0; i<jumlahKartu; i++) fprintf(fp," %d", X.idKartu.T[i]);
	fprintf(fp, "\n");
	
	fprintf(fp, "Petak_Yang_Dimiliki: "); fprintf(fp, "%d", jumlahKota);
	for(i=0; i<jumlahKota; i++)
	{
		fprintf(fp," "); PrintKataToFile(fp, X.kota.T[i]);
	}
	fprintf(fp, "\n");
}

void InitUrutanBoard()
{
	STARTKATA("data/urutanPetak.txt");
	while(!EndKata)
	{
		AddressOfPetak P;
		InfoPetak X;

		X.nama_petak = CKata;
		X.jenis_petak = CKata;
		P = AlokasiPetak(X);

		AddLastLPetak(&global.listOfPetak, P);
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
		P = SearchPetak(global.listOfPetak, X.nama_petak);
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
	CreateEmptyLPlayer(&global.listOfPlayer);
	for(i=1; i<=numOfPlayers; i++)
	{
		X.id = i;
		X.uang = STARTING_MONEY;
		CreateEmptyAOI(&X.idKartu);
		printf("Masukan nama untuk player %d : ", i); BacaKata(&X.nama);
		CreateEmptyAOK(&X.kota);
		X.posisi = FirstPetak(global.listOfPlayer);
		X.penjara = false;
		
		P = AlokasiPlayer(X);
		AddPlayer(&global.listOfPlayer, P);
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

	ADVKATA();

	Xtmp.id = KataToInt(CKata);
	ADVKATA(); ADVKATA(); ADVKATA();

	Xtmp.nama = CKata;
	ADVKATA(); ADVKATA();

	int playerLocation = KataToInt(CKata);
	AddressOfPetak playerPosition = SearchPetakByID(global.listOfPetak, playerLocation);
	Xtmp.posisi = playerPosition;
	ADVKATA(); ADVKATA();

	Xtmp.uang = KataToInt(CKata);
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
	// Kamus Lokal
	int id_currentPlayer, id_currentWorldCup, jumlahKartu, i;
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
		// Masukin X ke StackOfDefeatedPlayer
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
		P = SearchPetak(global.listOfPetak, X.nama_petak);
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
		AddLPlayer(&global.listOfPlayer, P);
	}
}

void LoadGame(int slot)
{
	char *dirDataPlayer, *dirDataPetak, *dirGlobalVar;

	if(slot == 1)
	{
		dirDataPlayer = "savegame/savegame1/dataPlayer.txt";
		dirDataPetak = "savegame/savegame1/dataPetak.txt";
		dirGlobalVar = "savegame/savegame1/dataGlobalVariables.txt";
	}
	else
	{
		dirDataPlayer = "savegame/savegame2/dataPlayer.txt";
		dirDataPetak = "savegame/savegame2/dataPetak.txt";
		dirGlobalVar = "savegame/savegame2/dataGlobalVariables.txt";
	}

	InitUrutanBoard();
	LoadGlobalVariables(dirGlobalVar); LoadDataPetak(dirDataPetak); LoadDataPlayers(dirDataPlayer); 
}

void SaveDataGlobalVariables(char *directory)
// Menyimpan currentPlayer, currentWorldCup, queueKartu, dan stackDefeated
{
	/*
	Current_Player: 3
	Current_WorldCup: 5
	Queue_kartu: 5 1 2 3 4 5
	Stack_defeated_players:
	====== 1 ======
	...
	...
	====== 2 ======
	...
	...
	#
	*/
	FILE *fp;
	fp = fopen(directory, "w");
	
	InfoPlayer P = global.currentPlayer;
	fprintf(fp, "Current_Player: %d\n", P.id);
	
	InfoPetak WC = global.currentWorldCup;
	fprintf(fp, "Current_WorldCup: %d\n", WC.id_petak);
	
	fprintf(fp, "Queue_kartu:\n");
	// Print indeks dari Q.head sampai Q.tail
	
	fprintf(fp, "Stack_defeated_players:\n");
	// For ... PrintPlayerToFile(fp, InfoPlayer);
	
	fprintf(fp, "#\n");
	fclose(fp);
}

void SaveDataPlayer(char *directory)
{
	FILE *fp;
	fp = fopen(directory, "w");
	
	int numOfPlayers = NbElmtLPlayer(global.listOfPlayer);
	int i;
	InfoPlayer X;
	AddressOfPlayer P;

	P = FirstLPlayer(global.listOfPlayer);
	for(i=0; i<numOfPlayers; i++)
	{
		X = InfoPlayer(P);
		PrintPlayerToFile(fp, X);
		P = NextPlayer(P);
	}
	
	fprintf(fp, "#\n");
	fclose(fp);
}

void SaveDataPetak(char *directory)
{
	FILE *fp;
	fp = fopen(directory, "w");
	
	// KONSTANTA
	Kata KOTA, TEMPAT_WISATA;
	KOTA.TabKata[0] = 'K'; KOTA.TabKata[1] = 'o'; KOTA.TabKata[2] = 't'; KOTA.TabKata[3] = 'a'; KOTA.Length = 4;
	TEMPAT_WISATA.TabKata[0] = 'T'; TEMPAT_WISATA.TabKata[1] = 'e'; TEMPAT_WISATA.TabKata[2] = 'm'; TEMPAT_WISATA.TabKata[3] = 'p'; 
	TEMPAT_WISATA.TabKata[4] = 'a'; TEMPAT_WISATA.TabKata[5] = 't'; TEMPAT_WISATA.TabKata[6] = '_'; TEMPAT_WISATA.TabKata[7] = 'W';
	TEMPAT_WISATA.TabKata[8] = 'i'; TEMPAT_WISATA.TabKata[9] = 's'; TEMPAT_WISATA.TabKata[10] = 'a'; TEMPAT_WISATA.TabKata[11] = 't'; 
	TEMPAT_WISATA.TabKata[12] = 'a';  TEMPAT_WISATA.Length = 13;

	int numOfPetak = NbElmtLPetak(global.listOfPetak);
	int i;
	InfoPetak X;
	AddressOfPetak P;

	P = FirstLPetak(global.listOfPetak);
	do
	{
		X = InfoPetak(P);

		if(IsKataSama(X.jenis_petak, KOTA) || IsKataSama(X.jenis_petak, TEMPAT_WISATA))
		{
			PrintPetakToFile(fp, X);
		}
					
		P = NextPetak(P);
	} while(P != FirstLPetak(global.listOfPetak));
	
	fprintf(fp, "#\n");
	fclose(fp);
}

void SaveGame(int slot)
{
	char *dirDataPlayer, *dirDataPetak, *dirGlobalVar;

	if(slot == 1)
	{
		dirDataPlayer = "savegame/savegame1/dataPlayer.txt";
		dirDataPetak = "savegame/savegame1/dataPetak.txt";
		dirGlobalVar = "savegame/savegame1/dataGlobalVariables.txt";
	}
	else
	{
		dirDataPlayer = "savegame/savegame2/dataPlayer.txt";
		dirDataPetak = "savegame/savegame2/dataPetak.txt";
		dirGlobalVar = "savegame/savegame2/dataGlobalVariables.txt";
	}

	SaveDataGlobalVariables(dirGlobalVar);
	SaveDataPlayer(dirDataPlayer);
	SaveDataPetak(dirDataPetak);
}
