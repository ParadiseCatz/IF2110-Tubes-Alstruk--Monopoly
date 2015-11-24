/* 
*	NIM/Nama	: 13511001/Thea Olivia
*	Nama file	: queue.h
*	Topik		: ADT Queue
*	Tanggal		: Selasa, 6 Oktober 2015
*	Deskripsi 	: Header queue.c
*/

#ifndef CARDS_H
#define CARDS_H
#include "boolean.h"
#include "arrayofkata.h"
#include "arrayofint.h"
#include "kata.h"
#include "../../globalvariable.h"
#include "player.h"
#include <stdlib.h>
#include <stdio.h>


/*
	Buatlah ADT Queue yang diimplementasikan dengan tabel kontigu dengan alokasi dinamik dalam bahasa C dengan representasi 
	alternatif III yaitu dengan HEAD dan TAIL yang “berputar”mengelilingi indeks tabel (lihat kembali diktat “Struktur Data”). 
	Jika queue kosong, HEAD dan TAIL menunjuk indeks 0. 

	Elemen tabel efektif dimulai pada indeks ke-1,
	Dari pernyataan ini berarti elemen yang digunakan berada pada indeks dari 1..MaxEl, dan yang harus dialokasi adalah sebanyak MaxEl+1
*/

#define Nil 0
typedef int Address;
typedef struct {
	InfoKartu 	card;
	Address		head;
	Address		tail;	
	int			maxCard;
} Deck;

typedef struct {
	int cardID;
	Kata cardName;
	Kata cardDescription;
} InfoKartu;

typedef struct Deck *Hand;

//selektor
#define GetTail(Q) (Q).tail
#define	GetMax(Q) (Q).maxCard
#define GetHead(Q) (Q).head
#define GetCard(Q) (Q).card
#define	InfoHead(Q) (Q).T[GetHead(Q)]
#define	InfoTail(Q) (Q).T[GetTail(Q)]

#define GetID(C) (C).cardID
#define GetName(C) (C).cardName
#define GetDesc(C) (C).cardDescription

//pemeriksaan kondisi queue
boolean IsEmpty(Queue Q);
/*	Mengirim true jika Q kosong yaitu HEAD dan TAIL sama dengan nil */

boolean IsFull(Queue Q);
/*	Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung MaxEl elemen */

int NbElmt(Queue Q);
/*	Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */


//konstruktor
void CreateEmpty(Queue *Q, int max);
/*	I.S. Max terdefinisi
	F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb :
	Jika alokasi berhasil, tabel memori dialokasi berukuran Max
	atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0
	Proses : Melakukan alokasi memori dan membuat sebuah Q kosong
*/

//destruktor
void Dealokasi(Queue *Q);
/*	Proses : Mengembalikan memori Q
	I.S. Q pernah dialokasi
	F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) juga diset 0
		Head dan Tail diset menjadi Nil
		Jangan lupa untuk membebaskan (free) memori yang telah dialokasikan untuk tabel
*/

//operator-operator dasar queue
void Add(Queue *Q, InfoKartu C);
/*	Proses : Menambahkan X pada Q dengan aturan FIFO
	I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh
	F.S. X menjadi TAIL yang baru, TAIL "maju".
	Jika TAIL baru = MaxEl + 1, maka TAIL diset = 1.
*/

void Del(Queue *Q, InfoKartu *C);
/*	Proses : Menghapus elemen pertama pada Q dengan aturan FIFO
	I.S. Q tidak kosong
	F.S. X = nilai elemen HEAD pada I.S.,
	Jika Queue masih isi : HEAD "maju".
	Jika HEAD baru menjadi MaxEl + 1, maka HEAD diset = 1;
	Jika Queue menjadi kosong, HEAD = TAIL = Nil.
*/

void FreeTax(InfoKartu C, Queue Q);

void FreePrison(InfoKartu C, Queue Q);

void GetPrison(InfoKartu C);

void GoToRandomPetak(InfoKartu C);

int Bday(InfoKartu C);

int DoubledMove(InfoKartu C);

void BlackOut(InfoKartu C);

void ProtFromBlackOut(InfoKartu C);

void Shuffle(Queue *Q, InfoKartu C);

void Draw(Queue *Q);

#endif
