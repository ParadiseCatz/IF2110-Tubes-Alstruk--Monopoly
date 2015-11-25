/* 
*	NIM/Nama	: 13511001/Thea Olivia
*	Nama file	: queue.c
*	Topik		: ADT Queue
*	Tanggal		: Selasa, 6 Oktober 2015
*	Deskripsi 	: Implementasi ADT Queue
*/

#include "ADT/header/cards.h"
#include "ADT/header/petak.h"
#include "ADT/header/player.h"
#include "ADT/header/arrayofint.h"
#include "ADT/header/arrayofkata.h"
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

	if(i == 0)
	{
		FreeTax();
	} 
	else if (i == 1)
	{
		FreePrison();
	}
	else if (i == 2)
	{
		GetPrison();
	}
	else if (i == 3)
	{
		MajuRandLangkah();
	}
	else if (i == 4)
	{
		Bday();
	}
	else if (i == 5)
	{
		DoubledMove();
	}
	else if (i == 6)
	{
		BlackOut();
	}
	else if (i == 7)
	{
		ProtFromBlackOut();
	}
	else 
	{
		printf("Tunggu sebentar!!\n");
	}
}

void PrintCard (InfoKartu C){
	printf("Card ID : %d\n", C.cardID);
	printf("Nama Kartu: "); PrintKata(C.cardName); printf("\n");
	printf("Deskripsi Kartu: "); PrintKata(C.cardDescription); printf("\n");
}

void FreeTax(){
/* I.S. : cardID = 1, not IsEmpty
 * F.S. : freetax
 * Proses :
 */	
	AddAOI(global.(*currentPlayer).idKartu,1);
}

void FreePrison(){
	AddAOI(global.(*currentPlayer).idKartu,2);
}

void GetPrison(){

	MasukPenjara(global.(*currentPlayer).penjara);
}

void MajuRandLangkah(){

	N = rand() % 15; 
	N++;
		MajuNLangkah(&global.(*currentPlayer), global.listOfPetak, N);
}

void Bday(){
	int i;
	AddressOfPlayer P;

		global.(*currentPlayer).uang += gift * NbElmt(global.listOfPlayer);
		P = First(global.listOfPlayer);

		while (P != Nil){
			P.uang = P.uang - gift; 
			P = Next(P);
	}
}

void DoubledMove(){
	
	AddAOI(global.(*currentPlayer),6);
}

void BlackOut(){

	AddAOI(global.(*currentPlayer),7);
}

void ProtFromBlackOut(){

	AddAOI(global.currentPlayer),8);
}

