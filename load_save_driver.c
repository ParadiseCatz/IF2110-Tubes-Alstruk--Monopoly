/* KHUSUS UNTUK DRIVER INI, UNTUK MELAKUKAN TEST PERLU DIPINDAH KE DIRECTORY UTAMA*/
#include "ADT/header/load_save.h"
#include "ADT/header/player.h"
#include "ADT/header/petak.h"

int main()
{
	NewGame(3);
	AddressOfPetak P;
	P = FirstPetak(global.listOfPetak); 
	do
	{
		InfoPetak X;
		X = InfoPetak(P);
		Kata namaPetak = X.nama_petak;
		PrintPetak(namaPetak); puts("/=========================/");

		P = NextPetak(P);

	}while(P!=FirstPetak(global.listOfPetak));
	return 0;
}
