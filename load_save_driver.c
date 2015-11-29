/* KHUSUS UNTUK DRIVER INI, UNTUK MELAKUKAN TEST PERLU DIPINDAH KE DIRECTORY UTAMA*/
#include "ADT/header/load_save.h"
#include "ADT/header/player.h"
#include "ADT/header/petak.h"

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
		PrintPetak(namaPetak); puts("/=========================/");

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

	return 0;
}
