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

//pemeriksaan kondisi queue
boolean IsEmpty(Deck Q)
/*	Mengirim true jika Q kosong yaitu head dan tail sama dengan nil */
{
	if (GetHead(Q) == Nil && GetTail(Q) == Nil)
		return true;
	else
		return false;
}

boolean IsFull(Deck Q)
/*	Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung maxEl elemen */
{
	if (NbElmt(Q) == GetMax(Q))
		return true;
	else
		return false;
}

int NbElmt(Deck Q)
/*	Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	if (IsEmpty(Q))
	{
		return 0;
	}
	else
	{
		if(GetTail(Q) >= GetHead(Q))
		{
			return (GetTail(Q) - GetHead(Q) + 1);
		}
		else
		{
			return (GetMax(Q) - (GetHead(Q) - GetTail(Q)) + 1);
		} 
	}
}


//konstruktor
void CreateEmpty(Deck *Q, int max)
/*	I.S. Max terdefinisi
	F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb :
	Jika alokasi berhasil, tabel memori dialokasi berukuran Max
	atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0
	Proses : Melakukan alokasi memori dan membuat sebuah Q kosong
*/
{
	(*Q).T = (Infotype*) malloc (max * sizeof (Infotype));
	GetMax(*Q) = max - 1;
	if ((*Q).T == NULL)
	{
		(*Q).T = (Infotype*) malloc (1 * sizeof (Infotype));
		GetMax(*Q) = 1;
	}
	GetHead(*Q) = Nil;
	GetTail(*Q) = Nil;
}


//destruktor
void Dealokasi(Deck *Q)
/*	Proses : Mengembalikan memori Q
	I.S. Q pernah dialokasi
	F.S. Q menjadi tidak terdefinisi lagi, maxEl(Q) juga diset 0
		head dan tail diset menjadi Nil
		Jangan lupa untuk membebaskan (free) memori yang telah dialokasikan untuk tabel
*/
{
	free((*Q).T);
}


//operator-operator dasar queue
void Add(Deck *Q, InfoKartu C)
/*	Proses : Menambahkan X pada Q dengan aturan FIFO
	I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh
	F.S. X menjadi tail yang baru, tail "maju".
	Jika tail baru = maxEl + 1, maka tail diset = 1.
*/
{
	if (IsEmpty(*Q))
	{
		GetHead(*Q) = 1;
		GetTail(*Q) = 1;
	}
	else
	{
		GetTail(*Q) += 1;
		if (GetTail(*Q) > GetMax(*Q))
			GetTail(*Q) = 1;
	}
	InfoTail(*Q) = C;
}

void Del(Deck *Q, InfoKartu *C)
/*	Proses : Menghapus elemen pertama pada Q dengan aturan FIFO
	I.S. Q tidak kosong
	F.S. X = nilai elemen head pada I.S.,
	Jika Queue masih isi : head "maju".
	Jika head baru menjadi maxEl + 1, maka head diset = 1;
	Jika Queue menjadi kosong, head = tail = Nil.
*/
{
	(*C) = InfoHead(*Q);
	if (GetHead(*Q)+1 > GetMax(*Q))
		GetHead(*Q) = 1;
	else
	{
		if (GetHead(*Q) == GetTail(*Q))
		{
			GetTail(*Q) = Nil;
			GetHead(*Q) = Nil;
		}
		else
		{
			GetHead(*Q) += 1;
		}
	}
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
		P = alokasi(C);
		return (ID_Petak(P) == 9); // id petak penjara
	}
}

void GoToRandomPetak(InfoKartu C, AddressOfPetak P){
	if (GetID(C) == 4){
		SearchPetakByID(L,rand(id));
	}
}

int Bday(InfoKartu C, InfoPlayer P InfoPlayer *X){
	if (GetID(C) == 5){
		for(){

		}
	}
}

void DoubledMove(InfoKartu C, InfoPlayer *X){
	int N, temp;
	ListPetak L;

	if (GetID(C) == 6){

		temp = N * N;
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
	switch(){

	}
}