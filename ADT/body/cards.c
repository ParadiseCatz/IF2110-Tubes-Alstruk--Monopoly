/* 
*	NIM/Nama	: 13511001/Thea Olivia
*	Nama file	: queue.c
*	Topik		: ADT Queue
*	Tanggal		: Selasa, 6 Oktober 2015
*	Deskripsi 	: Implementasi ADT Queue
*/

#include "cards.h"
#include "petak.h"
#include "player.h"
#include "arrayofint.h"
#include "arrayofkata.h"
#include "../../globalvariable.h"

//pemeriksaan kondisi queue
void CreateEmptyHand(ArrayOfCards *T){
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

void FreeTax(InfoKartu C, Deck Q, AddressOfPetak *P){
/* I.S. : cardID = 1, not IsEmpty
 * F.S. : freetax
 * Proses :
 */	
 	int K;
 	ArrayOfInt *A;

	if (GetID(C) == 1) {
		AddAOI(A,K);
	}
}

void FreePrison(InfoKartu C, Deck Q, AddressOfPetak *P){
	int K;
	ArrayOfInt *A;

	if (GetID(C) == 2) {
		AddAOI(&A,K);
	}
}

void GetPrison(InfoKartu C, InfoPlayer *X){
	AddressOfPetak P;

	if (GetID(C) == 3){
		AddAOI(&A,K);
	}
}

void GoToRandomPetak(InfoKartu C, AddressOfPetak P){
	if (GetID(C) == 4){
		SearchPetakByID(L,rand(id));
	}
}

int Bday(InfoKartu C, InfoPlayer P InfoPlayer *X){
	if (GetID(C) == 5){
			Next(Infouang(*X)) -= 100000;
			Infouang(*X) += 300000; 
	}
}

void DoubledMove(InfoKartu C, InfoPlayer *X){
	int N, temp;
	ListPetak L;

	if (GetID(C) == 6){
		temp = N * 2;
		MajuNLangkah(*X,L,temp);
	}
}

boolean BlackOut(InfoKartu C, AddressOfPetak P){
	ListPetak L;
	int id;

	if (GetID(C) == 7){
		SearchPetakByID(L,id);
	}
}

void ProtFromBlackOut(InfoKartu C, AddressOfPetak P){
	int K;
	ArrayOfInt *A;

	if (GetID(C) == 8){
		AddAOI(&A,K);
	}
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
			printf("Dengan menggunakan kartu ini, Anda dapat bebas memilih destinasi berikutnya!\n");
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
