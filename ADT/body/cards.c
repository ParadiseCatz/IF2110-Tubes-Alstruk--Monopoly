/* 
*	NIM/Nama	: 13511001/Thea Olivia
*	Nama file	: queue.c
*	Topik		: ADT Queue
*	Tanggal		: Selasa, 6 Oktober 2015
*	Deskripsi 	: Implementasi ADT Queue
*/

#include "../header/cards.h"
#include "../header/petak.h"
#include "../header/player.h"
#include "../header/arrayofint.h"
#include "../header/arrayofkata.h"
#include "../../globalvariable.h"

//pemeriksaan kondisi queue
/* void CreateEmptyHand(ArrayOfCards *T){
	// menciptakan array kosong di tangan
	GetNeff(*T) = 0;
}

int NbElmtHand(ArrayOfCards T){
	return GetNeff(T);
}

boolean isMemberHand(ArrayOfCards T, int K){
	// kamus lokal
	int i;
	boolean Found;
	// algoritma
	i = 1;
	Found = false;
	while(i<=NbElmtHand(T) && !Found)
	{
		if(T.TabCards[i] == K) 
			Found = true;
		else
			i++;
	}
	if(Found)
		return true;
	else
		return false;
}

int SearchIdxCard(ArrayOfCards T, int K){
	// kamus lokal
	int i;
	boolean Found;
	// algoritma
	i = 1;
	Found=false;
	while(i<=NbElmtHand(T) && !Found)
	{
		if(T.TabCards[i] == K) 
			Found = true;
		else
			i++;
	}
	if(Found)
		return i;
	else
		return -1;
}

void AddHand(ArrayOfCards *T, int K){

	GetNeff(*T)++;
	(*T).TabCards[NbElmtHand(*T)] = K;
}

void DeleteHand(ArrayOfCards *T, int K){
	// kamus lokal
	int i;
	// algoritma
	i = SearchIdxCard(*T,K);
	for(;i<NbElmtHand(*T); i++){
		(*T).TabCards[i] = (*T).TabCards[i+1];
	}
	GetNeff(*T)--;
}
*/

void DrawCards(){
	int i;

	i = rand() % 8;
	printf("Anda sampai ke Petak Chance\n");
	printf("Anda mengambil sebuah kartu dari tumpukan kartu\n");
	printf("---\n");
	printf("Anda mendapatkan kartu berikut ini :\n");
	InfoKartu X = global.arrayOfCards.TabCards[i];
	PrintCard(X);

	if(i == 0) FreeTax();
	else if (i == 1) FreePrison();
	else if (i == 2) GetPrison();
	else if (i == 3) MajuRandLangkah();
	else if (i == 4) Bday();
	else if (i == 5) DoubledMove();
	else if (i == 6) BlackOut();
	else if (i == 7) ProtFromBlackOut();
	else printf("Datang lagi lain waktu!\n");
}

void PrintCard (InfoKartu C){
	printf(" =============== "); PrintKata(C.cardName); printf(" ===============\n");
	printf("Card ID\t\t: %d\n", C.cardID);
	printf("Nama Kartu\t: "); PrintKata(C.cardName); printf("\n");
	printf("Deskripsi Kartu\t: "); PrintKata(C.cardDescription); printf("\n");
}

void FreeTax(){
/* I.S. : cardID = 1, not IsEmpty
 * F.S. : freetax
 * Proses :
 */	
	AddAOI(&Info(global.currentPlayer).idKartu, 1);
}

void FreePrison(){
	AddAOI(&Info(global.currentPlayer).idKartu, 2);
}

void GetPrison(){

	MasukPenjara(&Info(global.currentPlayer), global.listOfPetak);
}

void MajuRandLangkah(){

	int N = rand() % 15; N++;
	printf("Anda perlu maju %d langkah\n", N);
	MajuNLangkah(&Info(global.currentPlayer), global.listOfPetak, N);
}

void Bday(){
	int i;
	AddressOfPlayer P;

	Info(global.currentPlayer).uang += (GIFT * NbElmtPlayer(global.listOfPlayer));
	
	P = First(global.listOfPlayer);
	do
	{
		Info(P).uang = Info(P).uang - GIFT; 
		P = Next(P);

	} while(P != First(global.listOfPlayer));
}

void DoubledMove(){
	
	AddAOI(&Info(global.currentPlayer).idKartu, 6);
}

void BlackOut(){

	AddAOI(&Info(global.currentPlayer).idKartu, 7);
}

void ProtFromBlackOut(){

	AddAOI(&Info(global.currentPlayer).idKartu, 8);
}

