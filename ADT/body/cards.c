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

void DrawCards(InfoKartu C, ArrayOfCards Card){
	int i;

	for(i=0; i<MaxCards; i++){
		Card.TabCards[i] = rand() %100 + 1;
	}

}

void PrintCard (InfoKartu C){
	printf("%c\n"GetName(C));
	ReadDesc();
	printf("%c\n",GetDesc(C));
}

void FreeTax(InfoKartu C, AddressOfPetak *P, ArrayOfCards Card, GlobalVariable G){
/* I.S. : cardID = 1, not IsEmpty
 * F.S. : freetax
 * Proses :
 */	

		AddAOI(G.(*currentPlayer).idKartu,GetID());
}

void FreePrison(InfoKartu C, AddressOfPetak *P, ArrayOfCards Card, GlobalVariable G){
		IsPenjara(G.(*currentPlayer));
		KeluarPenjara(G.(*currentPlayer));
}

void GetPrison(InfoKartu C, InfoPlayer *X, ArrayOfCards Card, GlobalVariable G){

		IsPenjara(G.(*currentPlayer));
		MasukPenjara(G.(*currentPlayer).penjara);
}

void GoToRandomPetak(InfoKartu C, AddressOfPetak P, ArrayOfCards Card, GlobalVariable G){

		if (N <= 15){
			MajuNLangkah(G.(*currentPlayer), G.listOfPetak, N);
		}
}

int Bday(InfoKartu C, GlobalVariable G, ArrayOfCards Card){
	int i;

		for (i=0; i<NbElmt(G.listOfPlayer); i++){
			G.(*currentPlayer).uang += gift * i;
			G.listOfPlayer.Next(P).info.uang = G.listOfPlayer.Next(P).info.uang - gift;
}

void DoubledMove(InfoKartu C, InfoPlayer *X){
	int N, temp;

		temp = N * 2;
		MajuNLangkah(G.(*currentPlayer),G.listOfPetak,temp);

}

void BlackOut(InfoKartu C, AddressOfPetak P, GlobalVariable G){

		G.(*currentWorldCup).Blackout(P);
}

void ProtFromBlackOut(int K, GlobalVariable G){

		AddAOI(G.(*currentPlayer),K);
}

void ReadDesc(){
	switch(GetID(C)){
		case 1 :
			printf("Kartu ini membebaskan Anda dari pajak. Anda dapat memakai langsung kartu ini atau simpan untuk giliran yang akan datang!\n");
			break;
		case 2 :
			printf("Selamat, Anda bebas dari penjara! Simpan atau langsung dipakai, Anda yang memilih!\n");
			break;
		case 3 :
			printf("Uh-Oh, Anda masuk penjara :( Cepat lakukan sesuatu!\n");
			break;
		case 4 :
			printf("Dengan menggunakan kartu ini, Anda akan mengunjungi tempat yang tak pernah Anda bayangkan sebelumnya!\n");
			break;
		case 5 :
			printf("Selamat ulang tahun! Terimalah hadiah sebesar 100000 dollar dari setiap pemain! :)\n");
			break;
		case 6 :
			printf("Maju dua kali lipat angka dadu!!\n");
			break;
		case 7 :
			printf("Mati lampu! Aduh gelapnya! Gelap-gelapan jadinya seperti siluman!!\n");
			break;
		case 8 :
			printf("Aku takut mati lampu, mati pula cintamu. Teranglah, wahai cintaku! Musnahlah, wahai kegelapan!!!\n");
			
		default:
			printf("hanya ada 8 jenis kartu!\n");

	}

}
