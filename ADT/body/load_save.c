#include "../header/load_save.h"
#include "../../globalvariable.h"
#include "../../constant.h"

void InitDataKartu()
{
	STARTKATA("data/dataKartu.txt");
	int id = 0;
	while(!EndKata)
	{
		InfoKartu X;
		X.cardID = id;
		X.cardName = CKata; ADVKATA();
		X.cardDescription = CKata; ADVKATA();
		
		global.arrayOfCards.TabCards[id] = X;
		
		id++;
	}
}

/* ===================================== PRINT SOMETHING TO FILE ===================================== */

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
	fprintf(fp, "Jenis_Petak: "); PrintKataToFile(fp, X.jenis_petak); fprintf(fp, "\n");
	fprintf(fp, "Nama_Petak: "); PrintKataToFile(fp, X.nama_petak); fprintf(fp, "\n");
	fprintf(fp, "Harga_Dasar: "); fprintf(fp,"%d", X.harga_dasar); fprintf(fp, "\n");
	fprintf(fp, "Harga_Jual: "); fprintf(fp,"%d", X.harga_jual); fprintf(fp, "\n");
	fprintf(fp, "Biaya_Sewa: "); fprintf(fp,"%d", X.biaya_sewa); fprintf(fp, "\n");
	fprintf(fp, "Biaya_Upgrade: "); fprintf(fp,"%d", X.biaya_upgrade); fprintf(fp, "\n");
	fprintf(fp, "Level: "); fprintf(fp,"%d", X.level); fprintf(fp, "\n");
	fprintf(fp, "Multiplier_Sewa: "); fprintf(fp,"%.4lf", X.multiplier_sewa); fprintf(fp, "\n");
	fprintf(fp, "Pemilik: "); fprintf(fp,"%d", X.pemilik); fprintf(fp, "\n");
	fprintf(fp, "Blok: "); fprintf(fp,"%c", X.blok); fprintf(fp, "\n");
	fprintf(fp, "Blackout: "); fprintf(fp, "%d", blackout); fprintf(fp, "\n\n");
}

void PrintPlayerToFile(FILE *fp, InfoPlayer X)
{
	int playerLocationIdx, isInPenjara, jumlahKartu, jumlahKota, i;

	AddressOfPetak playerLocation = X.posisi;
	playerLocationIdx = playerLocation -> info.id_petak;
	isInPenjara = (X.penjara)?1:0;
	jumlahKartu = X.idKartu.Neff;
	jumlahKota = X.kota.Neff;
	
	fprintf(fp, "===== "); fprintf(fp, "%d", X.id); fprintf(fp, " =====\n");
	fprintf(fp, "Nama_Player: "); PrintKataToFile(fp, X.nama); fprintf(fp, "\n");
	fprintf(fp, "Lokasi_Player: "); fprintf(fp, "%d", playerLocationIdx); fprintf(fp, "\n");
	fprintf(fp, "Uang: "); fprintf(fp, "%d", X.uang); fprintf(fp, "\n");
	fprintf(fp, "Status_Penjara: "); fprintf(fp, "%d", isInPenjara); fprintf(fp, "\n");
	
	fprintf(fp, "Kartu_Yang_Dimiliki: "); fprintf(fp, "%d", jumlahKartu);
	for(i=1; i<=jumlahKartu; i++) fprintf(fp," %d", X.idKartu.T[i]);
	fprintf(fp, "\n");
	
	fprintf(fp, "Petak_Yang_Dimiliki: "); fprintf(fp, "%d", jumlahKota);
	for(i=1; i<=jumlahKota; i++)
	{
		fprintf(fp," "); PrintKataToFile(fp, X.kota.T[i]);
	}
	fprintf(fp, "\n\n");
}

/* ===================================== AKUISISI OBJECT ===================================== */

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
	CreateEmptyAOI(&Xtmp.idKartu);
	ADVKATA();
	for(i=0; i<numOfCardsOwned; i++)
	{
		AddAOI(&Xtmp.idKartu, KataToInt(CKata));
		ADVKATA();
	}

	ADVKATA();
	int numOfPetakOwned = KataToInt(CKata);
	CreateEmptyAOK(&Xtmp.kota);
	ADVKATA();
	for(i=0; i<numOfPetakOwned; i++)
	{
		AddAOK(&Xtmp.kota, CKata);
		ADVKATA();
	}

	*X = Xtmp;
}

/* ===================================== INIT BOARD = INIT URUTAN + INIT DATA AWAL ===================================== */

void InitUrutanBoard()
{
	STARTKATA("data/urutanPetak.txt");
	CreateListPetak(&(global.listOfPetak));

	int i = 1;

	while(!EndKata)
	{
		AddressOfPetak P;
		InfoPetak X;
		X.nama_petak = CKata;
		X.jenis_petak = CKata;
		X.id_petak = i; i++;
		P = AlokasiPetak(X);
		AddLastPetak(&global.listOfPetak, P);
		ADVKATA();
	}	
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

    	Info(P).jenis_petak = X.jenis_petak;
    	Info(P).nama_petak = X.nama_petak;
    	Info(P).biaya_sewa = X.biaya_sewa;
    	Info(P).harga_dasar = X.harga_dasar;
    	Info(P).biaya_upgrade = X.biaya_upgrade;
    	Info(P).level = X.level;
    	Info(P).multiplier_sewa = X.multiplier_sewa;
    	Info(P).pemilik = X.pemilik;
    	Info(P).blok = X.blok;
    	Info(P).blackout = X.blackout;
    	Info(P).harga_jual = X.harga_jual;
	}
}

void InitBoardAwal()
{
	InitUrutanBoard();
	InitDataAwalBoard();
}

/* ===================================== INIT PLAYERS ===================================== */

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

		Kata namaPlayer;
		namaPlayer.TabKata[0] = 'A'+i-1;
		namaPlayer.Length = 1;
		X.nama = namaPlayer;

		CreateEmptyAOK(&X.kota);
		X.posisi = FirstPetak(global.listOfPetak);
		X.penjara = false;
		
		P = Alokasi(X);
		InsertLast(&global.listOfPlayer, P);
	}
}

/* ===================================== NEW GAME ===================================== */

void NewGame(int numOfPlayers)
{
	InitBoardAwal(); InitDataKartu();
	InitPlayers(numOfPlayers);
	global.currentPlayer = First(global.listOfPlayer);
	global.currentWorldCup = NULL;
	global.diceRollResult = 0;
	global.rolldice = false;
	global.alreadyUpgrade = false;
	CreateEmptyS(&global.stackOfDefeated);
}

/* ===================================== LOAD GAME ===================================== */

void LoadGlobalVariables(char *directory)
{
	// Kamus Lokal
	int id_currentPlayer, id_currentWorldCup, jumlahKartu, bool_diceroll, bool_AlrdyUp, i;
	ArrayOfInt currentIDKartu;

	// Algoritma
	STARTKATA(directory);
	if(!FILE_NOT_FOUND())
	{
		ADVKATA();

		id_currentPlayer = KataToInt(CKata);
		global.currentPlayer = SearchidPlayer(global.listOfPlayer, id_currentPlayer);
		ADVKATA(); ADVKATA();

		id_currentWorldCup = KataToInt(CKata);
		if(id_currentWorldCup == -1) global.currentWorldCup = NULL;
		else global.currentWorldCup = SearchPetakByID(global.listOfPetak, id_currentWorldCup);
		ADVKATA(); ADVKATA();

		global.diceRollResult = KataToInt(CKata);
		ADVKATA(); ADVKATA();

		bool_diceroll = KataToInt(CKata);
		if(bool_diceroll == 1) global.rolldice = true;
		else global.rolldice = false;
		ADVKATA(); ADVKATA();

		bool_AlrdyUp = KataToInt(CKata);
		if(bool_AlrdyUp == 1) global.alreadyUpgrade = true;
		else global.alreadyUpgrade = false;
		ADVKATA();

		ADVKATA();
		CreateEmptyS(&global.stackOfDefeated);
		while(!EndKata)
		{
			InfoPlayer X;
			AkuisisiPlayer(&X);
			Push(&global.stackOfDefeated, X);
		}
	}
	else puts("File GlobalVar.txt is missing!");
	

}

void LoadDataPetak(char *directory)
{
	// Kamus Lokal
	InfoPetak X;
	AddressOfPetak P;

	// Algoritma
	STARTKATA(directory);
	if(!FILE_NOT_FOUND())
	{
		while(!EndKata)
		{
			AkuisisiPetak(&X);
			P = SearchPetak(global.listOfPetak, X.nama_petak);
			
			Info(P).jenis_petak = X.jenis_petak;
	    	Info(P).nama_petak = X.nama_petak;
	    	Info(P).biaya_sewa = X.biaya_sewa;
	    	Info(P).harga_dasar = X.harga_dasar;
	    	Info(P).biaya_upgrade = X.biaya_upgrade;
	    	Info(P).level = X.level;
	    	Info(P).multiplier_sewa = X.multiplier_sewa;
	    	Info(P).pemilik = X.pemilik;
	    	Info(P).blok = X.blok;
	    	Info(P).blackout = X.blackout;
	    	Info(P).harga_jual = X.harga_jual;
		}	
	}
	else puts("File DataPetak.txt is missing!");
	
}

void LoadDataPlayers(char *directory)
{
	// Kamus Lokal
	InfoPlayer X;
	AddressOfPlayer P;

	// ALgoritma
	STARTKATA(directory);
	if(!FILE_NOT_FOUND())
	{
		CreateEmptyLPlayer(&global.listOfPlayer);
		while(!EndKata)
		{
			AkuisisiPlayer(&X);
			P = Alokasi(X);
			InsertLast(&global.listOfPlayer, P);
		}
	}
}

boolean LoadGame(Kata namaSaveGame)
{
	Kata dirDataPlayer, dirDataPetak, dirGlobalVar;
	CreateEmptyKata(&dirDataPlayer); CreateEmptyKata(&dirDataPetak); CreateEmptyKata(&dirGlobalVar);

	char *savegame = "savegame/";
	int i;
	for (i=0; i<strlen(savegame); i++)
	{
		dirDataPlayer.TabKata[i] = dirDataPetak.TabKata[i] = dirGlobalVar.TabKata[i] = *(savegame+i);
		dirDataPlayer.Length++; dirDataPetak.Length++; dirGlobalVar.Length++; 
	}

	dirDataPlayer = ConcatKata(dirDataPlayer, namaSaveGame); dirDataPetak = ConcatKata(dirDataPetak, namaSaveGame); 
	dirGlobalVar = ConcatKata(dirGlobalVar, namaSaveGame); 

	Kata dataPlayerTXT, dataPetakTXT, dataGlobalVarTXT;
	dataPlayerTXT.TabKata[0] = '_'; dataPetakTXT.TabKata[0] = '_'; dataGlobalVarTXT.TabKata[0] = '_';
	dataPlayerTXT.TabKata[1] = 'd'; dataPetakTXT.TabKata[1] = 'd'; dataGlobalVarTXT.TabKata[1] = 'd';
	dataPlayerTXT.TabKata[2] = 'a'; dataPetakTXT.TabKata[2] = 'a'; dataGlobalVarTXT.TabKata[2] = 'a';
	dataPlayerTXT.TabKata[3] = 't'; dataPetakTXT.TabKata[3] = 't'; dataGlobalVarTXT.TabKata[3] = 't';
	dataPlayerTXT.TabKata[4] = 'a'; dataPetakTXT.TabKata[4] = 'a'; dataGlobalVarTXT.TabKata[4] = 'a';
	dataPlayerTXT.TabKata[5] = 'P'; dataPetakTXT.TabKata[5] = 'P'; dataGlobalVarTXT.TabKata[5] = 'G';
	dataPlayerTXT.TabKata[6] = 'l'; dataPetakTXT.TabKata[6] = 'e'; dataGlobalVarTXT.TabKata[6] = 'l';
	dataPlayerTXT.TabKata[7] = 'a'; dataPetakTXT.TabKata[7] = 't'; dataGlobalVarTXT.TabKata[7] = 'o';
	dataPlayerTXT.TabKata[8] = 'y'; dataPetakTXT.TabKata[8] = 'a'; dataGlobalVarTXT.TabKata[8] = 'b';
	dataPlayerTXT.TabKata[9] = 'e'; dataPetakTXT.TabKata[9] = 'k'; dataGlobalVarTXT.TabKata[9] = 'a';
	dataPlayerTXT.TabKata[10] = 'r'; dataPetakTXT.TabKata[10] = '.'; dataGlobalVarTXT.TabKata[10] = 'l';
	dataPlayerTXT.TabKata[11] = '.'; dataPetakTXT.TabKata[11] = 't'; dataGlobalVarTXT.TabKata[11] = 'V';
	dataPlayerTXT.TabKata[12] = 't'; dataPetakTXT.TabKata[12] = 'x'; dataGlobalVarTXT.TabKata[12] = 'a';
	dataPlayerTXT.TabKata[13] = 'x'; dataPetakTXT.TabKata[13] = 't'; dataGlobalVarTXT.TabKata[13] = 'r';
	dataPlayerTXT.TabKata[14] = 't'; 								 dataGlobalVarTXT.TabKata[14] = '.';
																	 dataGlobalVarTXT.TabKata[15] = 't';
																	 dataGlobalVarTXT.TabKata[16] = 'x';
																	 dataGlobalVarTXT.TabKata[17] = 't';
	dataPlayerTXT.Length = 15; dataPetakTXT.Length = 14; dataGlobalVarTXT.Length = 18;

	dirDataPlayer = ConcatKata(dirDataPlayer, dataPlayerTXT); dirDataPetak = ConcatKata(dirDataPetak, dataPetakTXT); 
	dirGlobalVar = ConcatKata(dirGlobalVar, dataGlobalVarTXT); 

	FILE *fileTest;
	fileTest = fopen(dirDataPlayer.TabKata, "r");
	if(fileTest == NULL) 
	{
		puts("File tidak ditemukan");
		return false;
	}
	else
	{
		if(FirstPetak(global.listOfPetak) == NULL)
		{
			InitUrutanBoard(); InitDataKartu();
		}
		LoadDataPlayers(dirDataPlayer.TabKata); puts("Player Loaded");
		LoadDataPetak(dirDataPetak.TabKata); puts("Petak Loaded");
		LoadGlobalVariables(dirGlobalVar.TabKata); puts("GlobalVariable Loaded");
		return true;
	}
	
}

/* ===================================== SAVE GAME ===================================== */

void SaveDataGlobalVariables(char *directory)
// Menyimpan currentPlayer, currentWorldCup, queueKartu, dan stackDefeated
{
	FILE *fp;
	fp = fopen(directory, "w");
	
	fprintf(fp, "Current_Player: %d\n", Info(global.currentPlayer).id);
	
	AddressOfPetak WC = global.currentWorldCup;
	if(WC != NULL) fprintf(fp, "Current_WorldCup: %d\n", Info(WC).id_petak);
	else fprintf(fp, "Current_WorldCup: -1\n");

	fprintf(fp, "diceRollResult: %d\n", global.diceRollResult);

	int valRollDice = (global.rolldice)?1:0;
	fprintf(fp, "rolldice: %d\n", valRollDice);

	int valAldyUp = (global.alreadyUpgrade)?1:0;
	fprintf(fp, "alreadyUpgrade: %d\n", valAldyUp);
	
	fprintf(fp, "Stack_defeated_players:\n");
	while(Top(global.stackOfDefeated) != Nil)
	{
		InfoPlayer X;
		Pop(&global.stackOfDefeated, &X);
		PrintPlayerToFile(fp, X);
	}
	fprintf(fp, "\n#\n");
	fclose(fp);
}

void SaveDataPlayer(char *directory)
{
	FILE *fp;
	fp = fopen(directory, "w");
	
	int numOfPlayers = NbElmtPlayer(global.listOfPlayer);
	int i;
	InfoPlayer X;
	AddressOfPlayer P;

	P = First(global.listOfPlayer);
	for(i=0; i<numOfPlayers; i++)
	{
		X = Info(P);
		PrintPlayerToFile(fp, X);
		P = Next(P);
	}
	
	fprintf(fp, "\n#\n");
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

	int i;
	InfoPetak X;
	AddressOfPetak P;

	P = FirstPetak(global.listOfPetak);
	do
	{
		X = InfoPetak(P);

		if(IsKataSama(X.jenis_petak, KOTA) || IsKataSama(X.jenis_petak, TEMPAT_WISATA))
		{
			PrintPetakToFile(fp, X);
		}
					
		P = NextPetak(P);
	} while(P != FirstPetak(global.listOfPetak));
	
	fprintf(fp, "\n#\n");
	fclose(fp);
}

void SaveGame(Kata namaSaveGame)
{
	Kata dirDataPlayer, dirDataPetak, dirGlobalVar;
	CreateEmptyKata(&dirDataPlayer); CreateEmptyKata(&dirDataPetak); CreateEmptyKata(&dirGlobalVar);

	char *savegame = "savegame/";
	int i;
	for (i=0; i<strlen(savegame); i++)
	{
		dirDataPlayer.TabKata[i] = dirDataPetak.TabKata[i] = dirGlobalVar.TabKata[i] = *(savegame+i);
		dirDataPlayer.Length++; dirDataPetak.Length++; dirGlobalVar.Length++; 
	}

	dirDataPlayer = ConcatKata(dirDataPlayer, namaSaveGame); dirDataPetak = ConcatKata(dirDataPetak, namaSaveGame); 
	dirGlobalVar = ConcatKata(dirGlobalVar, namaSaveGame); 

	Kata dataPlayerTXT, dataPetakTXT, dataGlobalVarTXT;
	dataPlayerTXT.TabKata[0] = '_'; dataPetakTXT.TabKata[0] = '_'; dataGlobalVarTXT.TabKata[0] = '_';
	dataPlayerTXT.TabKata[1] = 'd'; dataPetakTXT.TabKata[1] = 'd'; dataGlobalVarTXT.TabKata[1] = 'd';
	dataPlayerTXT.TabKata[2] = 'a'; dataPetakTXT.TabKata[2] = 'a'; dataGlobalVarTXT.TabKata[2] = 'a';
	dataPlayerTXT.TabKata[3] = 't'; dataPetakTXT.TabKata[3] = 't'; dataGlobalVarTXT.TabKata[3] = 't';
	dataPlayerTXT.TabKata[4] = 'a'; dataPetakTXT.TabKata[4] = 'a'; dataGlobalVarTXT.TabKata[4] = 'a';
	dataPlayerTXT.TabKata[5] = 'P'; dataPetakTXT.TabKata[5] = 'P'; dataGlobalVarTXT.TabKata[5] = 'G';
	dataPlayerTXT.TabKata[6] = 'l'; dataPetakTXT.TabKata[6] = 'e'; dataGlobalVarTXT.TabKata[6] = 'l';
	dataPlayerTXT.TabKata[7] = 'a'; dataPetakTXT.TabKata[7] = 't'; dataGlobalVarTXT.TabKata[7] = 'o';
	dataPlayerTXT.TabKata[8] = 'y'; dataPetakTXT.TabKata[8] = 'a'; dataGlobalVarTXT.TabKata[8] = 'b';
	dataPlayerTXT.TabKata[9] = 'e'; dataPetakTXT.TabKata[9] = 'k'; dataGlobalVarTXT.TabKata[9] = 'a';
	dataPlayerTXT.TabKata[10] = 'r'; dataPetakTXT.TabKata[10] = '.'; dataGlobalVarTXT.TabKata[10] = 'l';
	dataPlayerTXT.TabKata[11] = '.'; dataPetakTXT.TabKata[11] = 't'; dataGlobalVarTXT.TabKata[11] = 'V';
	dataPlayerTXT.TabKata[12] = 't'; dataPetakTXT.TabKata[12] = 'x'; dataGlobalVarTXT.TabKata[12] = 'a';
	dataPlayerTXT.TabKata[13] = 'x'; dataPetakTXT.TabKata[13] = 't'; dataGlobalVarTXT.TabKata[13] = 'r';
	dataPlayerTXT.TabKata[14] = 't'; 								 dataGlobalVarTXT.TabKata[14] = '.';
																	 dataGlobalVarTXT.TabKata[15] = 't';
																	 dataGlobalVarTXT.TabKata[16] = 'x';
																	 dataGlobalVarTXT.TabKata[17] = 't';
	dataPlayerTXT.Length = 15; dataPetakTXT.Length = 14; dataGlobalVarTXT.Length = 18;

	dirDataPlayer = ConcatKata(dirDataPlayer, dataPlayerTXT); dirDataPetak = ConcatKata(dirDataPetak, dataPetakTXT); 
	dirGlobalVar = ConcatKata(dirGlobalVar, dataGlobalVarTXT); 


	SaveDataGlobalVariables(dirGlobalVar.TabKata); puts("GlobalVariable Saved");
	SaveDataPlayer(dirDataPlayer.TabKata); puts("Player Saved");
	SaveDataPetak(dirDataPetak.TabKata);  puts("Petak Saved");
}
