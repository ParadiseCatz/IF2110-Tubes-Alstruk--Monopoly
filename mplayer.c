#include "ADT/header/player.h"
#include "ADT/header/petak.h"
#include "ADT/header/load_save.h"
#include "globalvariable.h"
#include "ADT/header/gamesystem.h"
int main(){
	ListPlayer L;
	ListPetak P;
	NewGame(4);
	//print elemen player
	PrintElmtPlayer(Info(global.currentPlayer));
	
	//maju sebanyak N langkah berdasar roll dadu
	MajuNLangkah(&Info(global.currentPlayer),global.listOfPetak,4);
	PrintBoard(global.listOfPetak,global.listOfPlayer);
	
	//lompat ke suatu petak
	AddressOfPetak Pt = SearchPetakByID(global.listOfPetak,6);
	LompatKe(&Info(global.currentPlayer),Pt);
	PrintBoard(global.listOfPetak,global.listOfPlayer);
	
	//menambahkan kota
	AddKota(&Info(global.currentPlayer),Nama_Petak(Info(global.currentPlayer).posisi));
	PrintPetak(Nama_Petak(Info(global.currentPlayer).posisi));
	
	//Maju 3 langkah menuju ke penjara
	MajuNLangkah(&Info(global.currentPlayer),global.listOfPetak,3);
	PrintBoard(global.listOfPetak,global.listOfPlayer);
	
	//Mengecek apakah player ada di penjara
	if (IsPenjara(Info(global.currentPlayer)))
		printf("sedang dipenjara\n");
		
	//Menghitung harta player
	printf("banyak harta player %c adalah : ",Info(global.currentPlayer).nama);
	printf("%d\n",HitungHartaPlayer(Info(global.currentPlayer)));
	
	//Menghitung banyaknya player
	printf("Banyak player : %d\n",NbElmtPlayer(global.listOfPlayer));
	
	//Mengubah giliran pemain
	global.currentPlayer=Next(global.currentPlayer);
	PrintElmtPlayer(Info(global.currentPlayer));
	
	//Mengecek apakah tourism monopoly
	MajuNLangkah(&Info(global.currentPlayer),global.listOfPetak,4);
	AddKota(&Info(global.currentPlayer),Nama_Petak(Info(global.currentPlayer).posisi));
	MajuNLangkah(&Info(global.currentPlayer),global.listOfPetak,10);
	AddKota(&Info(global.currentPlayer),Nama_Petak(Info(global.currentPlayer).posisi));
	MajuNLangkah(&Info(global.currentPlayer),global.listOfPetak,4);
	AddKota(&Info(global.currentPlayer),Nama_Petak(Info(global.currentPlayer).posisi));
	MajuNLangkah(&Info(global.currentPlayer),global.listOfPetak,7);
	AddKota(&Info(global.currentPlayer),Nama_Petak(Info(global.currentPlayer).posisi));
	PrintElmtPlayer(Info(global.currentPlayer));
	if (IsTourismMonopoly(Info(global.currentPlayer)))
		printf("Tourism Monopoly\n");
		
	Del(&global.listOfPlayer,&Info(global.currentPlayer),Info(global.currentPlayer).id);
	CreateEmptyS(&global.stackOfDefeated);
	Push(&global.stackOfDefeated,Info(global.currentPlayer));
	return 0;
}
